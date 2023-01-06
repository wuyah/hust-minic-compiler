#include "def.h"
#define DEBUG 1

void ext_var_list(struct ASTNode *T)
{  //处理变量列表
    int rtn;
    switch (T->kind){
        case EXT_DEC_LIST:
            T->Dec->type=T->type;                  //将类型属性向下传递变量结点
            T->Dec->offset=T->offset;              //外部变量的偏移量向下传递
            T->DecList->type=T->type;              //将类型属性向下传递变量结点
            T->DecList->offset=T->offset+T->width; //外部变量的偏移量向下传递
            T->DecList->width=T->width;
            ext_var_list(T->Dec);
            ext_var_list(T->DecList);
            T->num = T->DecList->num+1;
            break;
        case ID:                                     //最后一个变量名
            rtn=fillSymbolTable(T->type_id,newAlias(),LEV,T->type,'V',T->offset);
            if (rtn==-1)
                semantic_error(T->pos,T->type_id, "变量重复定义");
            else 
                T->place=rtn;
            T->num=1;
            break;
        }
}

int  match_param(int i,struct ASTNode *T)
{  //i代表函数名在符号表中的位置
    int j,num=symbolTable.symbols[i].paramnum;
    if (num==0 && T==NULL) return 1;//无参函数
    int type1,type2,pos=T->pos;
    for (j=1;j<=num;j++) {  //比较参数
        if (!T){
            semantic_error(pos,"", "函数调用参数太少!");
            return 0;
        }
        type1=symbolTable.symbols[i+j].type;  //形参类型
        type2=T->Exp1->type;
        if (type1!=type2){
            semantic_error(pos,"", "参数类型不匹配");
            return 0;
        }
        T=T->Args;
    }
    if (T){ //num个参数已经匹配完，还有实参表达式
        semantic_error(pos,"", "函数调用参数太多!");
        return 0;
    }
    return 1;
}

void semantic_Analysis(struct ASTNode *T)
{//对抽象语法树的先根遍历,按display的控制结构修改完成符号表管理和语义检查和TAC生成（语句部分）
  int rtn,num,width;
  struct ASTNode *T0;
  struct opn opn1,opn2,result;
  if (T)
	{
	switch (T->kind)
	{
	    case EXT_DEF_LIST:
            if (!T->Def) break;
            T->Def->offset=T->offset;
            semantic_Analysis(T->Def);    //访问外部定义列表中的第一个
            T->code=T->Def->code;
            if (T->DefList){
                T->DefList->offset=T->Def->offset+T->Def->width;
                semantic_Analysis(T->DefList); //访问该外部定义列表中的其它外部定义
                T->code=merge(2,T->code,T->DefList->code);
            }
            break;
	    case EXT_VAR_DEF:   //处理外部说明,将第一个孩子(TYPE结点)中的类型送到第二个孩子的类型域
            T->type=T->DecList->type=!strcmp(T->Specifier->type_id,"int")?INT:FLOAT;
            T->DecList->offset=T->offset;        //这个外部变量的偏移量向下传递
            T->DecList->width=T->type==INT?4:8;  //将一个变量的宽度向下传递
            ext_var_list(T->DecList);            //处理外部变量说明中的标识符序列
            T->width=(T->type==INT?4:8)*T->DecList->num; //计算这个外部变量说明的宽度
            T->code=NULL;                        //这里假定外部变量不支持初始化
            break;
	    case FUNC_DEF:      //填写函数定义信息到符号表
            T->FuncDec->type=!strcmp(T->Specifier->type_id,"int")?INT:FLOAT;//获取函数返回类型送到含函数名、参数的结点
            T->width=0;     //函数的宽度设置为0，不会对外部变量的地址分配产生影响
            T->offset=DX;   //设置局部变量在活动记录中的偏移量初值
            T->FuncDec->offset=DX;
            semantic_Analysis(T->FuncDec); //处理函数名和参数结点部分，这里不考虑用寄存器传递参数
            T->offset+=T->FuncDec->width;   //用形参单元宽度修改函数局部变量的起始偏移量
            T->Body->offset=T->offset;
            strcpy(T->Body->Snext,newLabel());  //函数体语句执行结束后的位置属性
            semantic_Analysis(T->Body);         //处理函数体结点
            //计算活动记录大小,这里offset属性存放的是活动记录大小，不是偏移
            symbolTable.symbols[T->FuncDec->place].offset=T->offset+T->Body->width;
            T->code=merge(3,T->FuncDec->code,T->Body->code,genLabel(T->Body->Snext));          //函数体的代码作为函数的代码
            break;
	    case FUNC_DEC:      //根据返回类型，函数名填写符号表
            rtn=fillSymbolTable(T->type_id,newAlias(),LEV,T->type,'F',0);//函数不在数据区中分配单元，偏移量为0
            if (rtn==-1){
                semantic_error(T->pos,T->type_id, "函数重复定义");
                break;
            }
            else T->place=rtn;
            result.kind=ID;   strcpy(result.id,T->type_id);
            result.offset=rtn;
            T->code=genIR(FUNCTION,opn1,opn2,result);     //生成中间代码：FUNCTION 函数名
            T->offset=DX;   //设置形式参数在活动记录中的偏移量初值
            if (T->ParamList) { //判断是否有参数
                T->ParamList->offset=T->offset;
                semantic_Analysis(T->ParamList);  //处理函数参数列表
                T->width=T->ParamList->width;
                symbolTable.symbols[rtn].paramnum=T->ParamList->num;
                T->code=merge(2,T->code,T->ParamList->code);  //连接函数名和参数代码序列
            }
            else symbolTable.symbols[rtn].paramnum=0,T->width=0;
            break;
	    case PARAM_LIST:    //处理函数形式参数列表
            T->Param->offset=T->offset;
            semantic_Analysis(T->Param);
            if (T->ParamList){
                T->ParamList->offset=T->offset+T->Param->width;
                semantic_Analysis(T->ParamList);
                T->num=T->Param->num+T->ParamList->num;        //统计参数个数
                T->width=T->Param->width+T->ParamList->width;  //累加参数单元宽度
                T->code=merge(2,T->Param->code,T->ParamList->code);  //连接参数代码
            }
            else{
                T->num=T->Param->num;
                T->width=T->Param->width;
                T->code=T->Param->code;
            }
            break;
	    case  PARAM_DEC:
            rtn=fillSymbolTable(T->ID->type_id,newAlias(),1,T->Specifier->type,'P',T->offset);
            if (rtn==-1)
                semantic_error(T->ID->pos,T->ID->type_id, "参数名重复定义");
            else 
                T->ID->place=rtn;
            T->num=1;       //参数个数计算的初始值
            T->width=T->Specifier->type==INT?4:8;  //参数宽度
            result.kind=ID;   strcpy(result.id, symbolTable.symbols[rtn].alias);
            result.offset=T->offset;
            T->code=genIR(PARAM,opn1,opn2,result);     //生成：FUNCTION 函数名
            break;
	    case COMP_STM:
            LEV++;
            //设置层号加1，并且保存该层局部变量在符号表中的起始位置在symbol_scope_TX
            symbol_scope_TX.TX[symbol_scope_TX.top++]=symbolTable.index;
            T->width=0;
            T->code=NULL;
            if (T->DefList) {
                T->DefList->offset=T->offset;
                semantic_Analysis(T->DefList);  //处理该层的局部变量DEF_LIST
                T->width+=T->DefList->width;
                T->code=T->DefList->code;
                }
            if (T->StmList){
                T->StmList->offset=T->offset+T->width;
                strcpy(T->StmList->Snext,T->Snext);  //S.next属性向下传递
                semantic_Analysis(T->StmList);       //处理复合语句的语句序列
                T->width+=T->StmList->width;
                T->code=merge(2,T->code,T->StmList->code);
                }
            #if (DEBUG)
                if (LEV==1)
                    printf("\n第%d行函数的函数体结束前符号表(共2层):\n",T->pos);
                else 
                    printf("\n第%d行复合语句结束前符号表(共%d层):\n",T->pos,LEV+1);
                prn_symbol();       //c在退出一个复合语句前显示的符号表
			//   system("pause");
                getchar();
            #endif
            LEV--;    //出复合语句，层号减1
            symbolTable.index=symbol_scope_TX.TX[--symbol_scope_TX.top]; //删除该作用域中的符号
            break;
        case DEF_LIST:
            T->code=NULL;
            if (T->Def){
                T->Def->offset=T->offset;
                semantic_Analysis(T->Def);   //处理一个局部变量定义
                T->code=T->Def->code;
                T->width=T->Def->width;
            }
            if (T->DefList) {
                T->DefList->offset=T->offset+T->Def->width;
                semantic_Analysis(T->DefList);   //处理剩下的局部变量定义
                T->code=merge(2,T->code,T->DefList->code);
                T->width+=T->DefList->width;
            }
            break;
        case VAR_DEF://处理一个局部变量定义,将第一个孩子(TYPE结点)中的类型送到第二个孩子的类型域
                 //类似于上面的外部变量EXT_VAR_DEF，换了一种处理方法
                T->code=NULL;
                T->DecList->type=!strcmp(T->Specifier->type_id,"int")?INT:FLOAT;  //确定变量序列各变量类型
                T0=T->DecList; //T0为变量名列表子树根指针，对ID、ASSIGNOP类结点在登记到符号表，作为局部变量
                num=0;
                T0->offset=T->offset;
                T->width=0;
                width=T->DecList->type==INT?4:8;  //一个变量宽度
                while (T0)
                {  //处理所以DEC_LIST结点
                    num++;
                    T0->Dec->type=T0->type;  //类型属性向下传递
                    if (T0->DecList) T0->DecList->type=T0->type;
                    T0->Dec->offset=T0->offset;  //类型属性向下传递
                    if (T0->DecList) T0->DecList->offset=T0->offset+width;
                    if (T0->Dec->kind==ID)
                    {
                        rtn=fillSymbolTable(T0->Dec->type_id,newAlias(),LEV,T0->Dec->type,'V',T->offset+T->width);//此处偏移量未计算，暂时为0
                        if (rtn==-1)
                            semantic_error(T0->Dec->pos,T0->Dec->type_id, "变量重复定义");
                        else T0->Dec->place=rtn;
                        T->width+=width;
                    }
                    else if (T0->Dec->kind==ASSIGNOP)
                         {
                            rtn=fillSymbolTable(T0->Dec->Dec->type_id,newAlias(),LEV,T0->Dec->type,'V',T->offset+T->width);//此处偏移量未计算，暂时为0
                            if (rtn==-1)
                                semantic_error(T0->Dec->Dec->pos,T0->Dec->Dec->type_id, "变量重复定义");
                            else
                            {
                                int id_type = symbolTable.symbols[rtn].type;
                                if((!(id_type==FLOAT && T->Exp2->type==INT)) && (id_type != T->Exp2->type))
                                    semantic_error(T0->Dec->Dec->pos,T0->Dec->Dec->type_id, "VarDec Assign Type error!");
                                T0->Dec->place=rtn;
                                T0->Dec->Exp2->offset=T->offset+T->width+width;
                                Exp(T0->Dec->Exp2);
                                opn1.kind=ID;
                                opn1.offset=symbolTable.symbols[T0->Dec->Exp2->place].offset;
                                strcpy(opn1.id,symbolTable.symbols[T0->Dec->Exp2->place].alias);
                                result.kind=ID; strcpy(result.id,symbolTable.symbols[T0->Dec->place].alias);
                                result.offset=symbolTable.symbols[T0->Dec->place].offset;
                                T->code=merge(3,T->code,T0->Dec->Exp2->code,genIR(ASSIGNOP,opn1,opn2,result));
                            }
                            T->width+=width+T0->Dec->Exp2->width;
                         }
                    T0=T0->DecList;
                }
                break;
	    case STM_LIST:
                if (T->StmList) //2条以上语句连接，生成新标号作为第一条语句结束后到达的位置
                    strcpy(T->Stm->Snext,newLabel());
                else     //语句序列仅有一条语句，S.next属性向下传递
                    strcpy(T->Stm->Snext,T->Snext);
                T->Stm->offset=T->offset;
                semantic_Analysis(T->Stm);
                T->code=T->Stm->code;
                T->width=T->Stm->width;
                if (T->StmList)
                {     //2条以上语句连接,S.next属性向下传递
                    strcpy(T->StmList->Snext,T->Snext);
                    T->StmList->offset=T->offset;  //顺序结构共享单元方式
                    semantic_Analysis(T->StmList);
                    //序列中第1条为表达式语句，返回语句，复合语句时，第2条前不需要标号
                    if (T->Stm->kind==RETURN ||T->Stm->kind==EXP_STMT ||T->Stm->kind==COMP_STM)
                        //对返回语句、表达式语句、复合语句，免去和后续语句间的标号
                        T->code=merge(2,T->code,T->StmList->code);
                    else
                        T->code=merge(3,T->code,genLabel(T->Stm->Snext),T->StmList->code);
                    if (T->StmList->width>T->width) //后续语句需要更多单元时，更新这些
                        T->width=T->StmList->width; //顺序语句的单元width，实现共享单元方式
                }
                break;
	    case IF_THEN:
                strcpy(T->Cond->Etrue,newLabel());  //设置条件语句真假转移位置
                strcpy(T->Cond->Efalse,T->Snext);
                T->Cond->offset=T->IfStm->offset=T->offset;
                boolExp(T->Cond);
                T->width=T->Cond->width;
                strcpy(T->IfStm->Snext,T->Snext);
                semantic_Analysis(T->IfStm);      //if子句
                if (T->width<T->IfStm->width) T->width=T->IfStm->width;
                T->code=merge(3,T->Cond->code, genLabel(T->Cond->Etrue),T->IfStm->code);
                break;  //控制语句都还没有处理offset和width属性
	case IF_THEN_ELSE:
                strcpy(T->Cond->Etrue,newLabel());  //设置条件语句真假转移位置
                strcpy(T->Cond->Efalse,newLabel());
                T->Cond->offset=T->IfStm->offset=T->ElseStm->offset=T->offset;
                boolExp(T->Cond);      //条件，要单独按短路代码处理
                T->width=T->Cond->width;
                strcpy(T->IfStm->Snext,T->Snext);
                semantic_Analysis(T->IfStm);      //if子句
                if (T->width<T->IfStm->width) T->width=T->IfStm->width;
                strcpy(T->ElseStm->Snext,T->Snext);
                semantic_Analysis(T->ElseStm);      //else子句
                if (T->width<T->ElseStm->width) T->width=T->ElseStm->width;
                T->code=merge(6,T->Cond->code,genLabel(T->Cond->Etrue),T->IfStm->code,\
                              genGoto(T->Snext),genLabel(T->Cond->Efalse),T->ElseStm->code);
                break;
	case WHILE: 
                strcpy(T->Cond->Etrue,newLabel());  //子结点继承属性的计算
                strcpy(T->Cond->Efalse,T->Snext);
                T->Cond->offset=T->Body->offset=T->offset;
                boolExp(T->Cond);      //循环条件，要单独按短路代码处理
                T->width=T->Cond->width;
                strcpy(T->Body->Snext,newLabel());
                semantic_Analysis(T->Body);      //循环体
                if (T->width < T->Body->width) T->width=T->Body->width;

                T->code=merge(5,genLabel(T->Body->Snext),T->Cond->code, \
                    genLabel(T->Cond->Etrue),T->Body->code,genGoto(T->Body->Snext));
                break;
    case FOR:
                // T->Exp2 is the condition utter
                semantic_Analysis(T->Exp1);
                strcpy(T->Exp2->Etrue,newLabel());  //子结点继承属性的计算
                strcpy(T->Exp2->Efalse,T->Snext);
                T->Exp1->offset=T->Exp3->offset=T->Exp2->offset=T->Body->offset=T->offset;
                boolExp(T->Exp2);
                T->width = T->Exp2->width;
                strcpy(T->Exp3->Snext,newLabel());
                semantic_Analysis(T->Body);
                semantic_Analysis(T->Exp3);
                if (T->width < (T->Body->width + T->Exp3->width)) T->width=T->Body->width + T->Exp3->width;
                
                // Exp1 -> label -> condition(Exp2) -> Goto Next -> Body -> Exp3 ->Exp3 Next
                T->code=merge(7,T->Exp1->code,genLabel(T->Exp3->Snext),T->Exp2->code, \
                    genLabel(T->Exp2->Etrue), T->Body->code, T->Exp3->code, genGoto(T->Exp3->Snext));
                break;
    case EXP_STMT:
                T->Exp1->offset=T->offset;
                semantic_Analysis(T->Exp1);
                T->code=T->Exp1->code;
                T->width=T->Exp1->width;
                break;
	case RETURN:if (T->Exp1){
                    T->Exp1->offset=T->offset;
                    Exp(T->Exp1);
// TODO
				 /*需要判断返回值类型是否匹配*/
                    T->width=T->Exp1->width;
                    result.kind=ID; strcpy(result.id,symbolTable.symbols[T->Exp1->place].alias);
                    result.offset=symbolTable.symbols[T->Exp1->place].offset;
                    T->code=merge(2,T->Exp1->code,genIR(RETURN,opn1,opn2,result));
                }
                else{
                    T->width=0;
                    result.kind=0;
                    T->code=genIR(RETURN,opn1,opn2,result);
                }
                break;
	case ID:
    case INT:
    case FLOAT:
	case ASSIGNOP:
	case AND:
	case OR:
	case RELOP:
	case PLUS:
	case MINUS:
	case STAR:
	case DIV:
	case NOT:
	case UMINUS:
    case FUNC_CALL:
                    Exp(T);          //处理基本表达式
                    break;
    }
    }
}

void semantic_Analysis0(struct ASTNode *T) {
    symbolTable.index=0;
    fillSymbolTable("read","",0,INT,'F',4);
    symbolTable.symbols[0].paramnum=0;//read的形参个数
    fillSymbolTable("write","",0,INT,'F',4);
    symbolTable.symbols[1].paramnum=1;
    fillSymbolTable("x","",1,INT,'P',12);
    symbol_scope_TX.TX[0]=0;  //外部变量在符号表中的起始序号为0
    symbol_scope_TX.top=1;
    T->offset=0;              //外部变量在数据区的偏移量
    semantic_Analysis(T);
    prnIR(T->code);
    objectCode(T->code);
 } 
