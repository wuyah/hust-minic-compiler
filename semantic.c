#include "def.h"
#define DEBUG 1

char *strcat0(char *s1,char *s2){
    static char result[10];
    strcpy(result,s1);
    strcat(result,s2);
    return result;
}

char *newAlias() {
    static int no=1;
    char s[10];
    // itoa(no++,s,10);
    sprintf(s,"%d",no++);
    return strcat0("v",s);
}

char *newLabel() {
    static int no=1;
    char s[10];
    // itoa(no++,s,10);
    sprintf(s,"%d",no++);

    return strcat0("label",s);
}

char *newTemp(){
    static int no=1;
    char s[10];
    // itoa(no++,s,10);
    sprintf(s,"%d",no++);

    return strcat0("temp",s);
}

//生成一条TAC代码的结点组成的双向循环链表，返回头指针
struct codenode *genIR(int op,struct opn opn1,struct opn opn2,struct opn result){
    struct codenode *h=(struct codenode *)malloc(sizeof(struct codenode));
    h->op=op;
    h->opn1=opn1;
    h->opn2=opn2;
    h->result=result;
    h->next=h->prior=h;
    return h;
}

//生成一条标号语句，返回头指针
struct codenode *genLabel(char *label){
    struct codenode *h=(struct codenode *)malloc(sizeof(struct codenode));
    h->op=LABEL;
    strcpy(h->result.id,label);
    h->next=h->prior=h;
    return h;
}

//生成GOTO语句，返回头指针
struct codenode *genGoto(char *label){
    struct codenode *h=(struct codenode *)malloc(sizeof(struct codenode));
    h->op=GOTO;
    strcpy(h->result.id,label);
    h->next=h->prior=h;
    return h;
}

//合并多个中间代码的双向循环链表，首尾相连
struct codenode *merge(int num,...){
    struct codenode *h1,*h2,*t1,*t2;
    va_list ap;
    va_start(ap,num);
    h1=va_arg(ap,struct codenode *);
    while (--num>0) {
        h2=va_arg(ap,struct codenode *);
        if (h1==NULL) h1=h2;
        else if (h2){
            t1=h1->prior;
            t2=h2->prior;
            t1->next=h2;
            t2->next=h1;
            h1->prior=t2;
            h2->prior=t1;
            }
        }
    va_end(ap);
    return h1;
}

//输出中间代码
void prnIR(struct codenode *head)
{
    char opnstr1[32],opnstr2[32],resultstr[32];
    struct codenode *h=head;
    do {
        if (h->opn1.kind==INT)
             sprintf(opnstr1,"#%d",h->opn1.const_int);
        if (h->opn1.kind==FLOAT)
             sprintf(opnstr1,"#%f",h->opn1.const_float);
        if (h->opn1.kind==ID)
             sprintf(opnstr1,"%s",h->opn1.id);
        if (h->opn2.kind==INT)
             sprintf(opnstr2,"#%d",h->opn2.const_int);
        if (h->opn2.kind==FLOAT)
             sprintf(opnstr2,"#%f",h->opn2.const_float);
        if (h->opn2.kind==ID)
             sprintf(opnstr2,"%s",h->opn2.id);
        sprintf(resultstr,"%s",h->result.id);
        switch (h->op)
        {
            case ASSIGNOP:  printf("  %s := %s\n",resultstr,opnstr1);
                            break;
            case PLUS:
            case MINUS:
            case STAR:
            case DIV: printf("  %s := %s %c %s\n",resultstr,opnstr1, \
                      h->op==PLUS?'+':h->op==MINUS?'-':h->op==STAR?'*':'\\',opnstr2);
                      break;
            case FUNCTION: printf("\nFUNCTION %s :\n",h->result.id);
                           break;
            case PARAM:    printf("  PARAM %s\n",h->result.id);
                           break;
            case LABEL:    printf("LABEL %s :\n",h->result.id);
                           break;
            case GOTO:     printf("  GOTO %s\n",h->result.id);
                           break;
            case JLE:      printf("  IF %s <= %s GOTO %s\n",opnstr1,opnstr2,resultstr);
                           break;
            case JLT:      printf("  IF %s < %s GOTO %s\n",opnstr1,opnstr2,resultstr);
                           break;
            case JGE:      printf("  IF %s >= %s GOTO %s\n",opnstr1,opnstr2,resultstr);
                           break;
            case JGT:      printf("  IF %s > %s GOTO %s\n",opnstr1,opnstr2,resultstr);
                           break;
            case EQ:       printf("  IF %s == %s GOTO %s\n",opnstr1,opnstr2,resultstr);
                           break;
            case NEQ:      printf("  IF %s != %s GOTO %s\n",opnstr1,opnstr2,resultstr);
                           break;
            case ARG:      printf("  ARG %s\n",h->result.id);
                           break;
            case CALL:     if (!strcmp(opnstr1,"write"))
                                printf("  CALL  %s\n", opnstr1);
                            else
                                printf("  %s := CALL %s\n",resultstr, opnstr1);
                           break;
            case RETURN:   if (h->result.kind)
                                printf("  RETURN %s\n",resultstr);
                           else
                                printf("  RETURN\n");
                           break;

        }
        h=h->next;
    } while (h!=head);
}
void semantic_error(int line,char *msg1,char *msg2){
    //这里可以只收集错误信息，最后一次显示
    printf("在%d行,%s %s\n",line,msg1,msg2);
}
void prn_symbol(){ //显示符号表
    int i=0;
    printf("%6s %6s %6s  %6s %4s %6s\n","变量名","别 名","层 号","类  型","标记","偏移量");
    for(i=0;i<symbolTable.index;i++)
    {
        printf("%6s %6s %6d  %6s %4c %6d\n",symbolTable.symbols[i].name,\
        symbolTable.symbols[i].alias,symbolTable.symbols[i].level,\
        symbolTable.symbols[i].type==INT?"int":"float",\
        symbolTable.symbols[i].flag,symbolTable.symbols[i].offset);
    }
}

int searchSymbolTable(char *name) {
    int i,flag=0;
    for(i=symbolTable.index-1;i>=0;i--){
        if (symbolTable.symbols[i].level==0)
            flag=1;
        if (flag && symbolTable.symbols[i].level==1)
            continue;   //跳过前面函数的形式参数表项
        if (!strcmp(symbolTable.symbols[i].name, name))  return i;
    }
    return -1;
}
int fillSymbolTable(char *name,char *alias,int level,int type,char flag,int offset)
{
    //首先根据name查符号表，不能重复定义 重复定义返回-1
    int i;
    /*符号查重，考虑外部变量声明前有函数定义，
    其形参名还在符号表中，这时的外部变量与前函数的形参重名是允许的*/
    if (name)
        for(i=symbolTable.index-1; i>=0 && (symbolTable.symbols[i].level==level||level==0); i--) {
            if (level==0 && symbolTable.symbols[i].level==1) continue;  //外部变量和形参不必比较重名
            if (!strcmp(symbolTable.symbols[i].name, name))  return -1;
            }
    //填写符号表内容
    strcpy(symbolTable.symbols[symbolTable.index].name,name);
    strcpy(symbolTable.symbols[symbolTable.index].alias,alias);
    symbolTable.symbols[symbolTable.index].level=level;
    symbolTable.symbols[symbolTable.index].type=type;
    symbolTable.symbols[symbolTable.index].flag=flag;
    symbolTable.symbols[symbolTable.index].offset=offset;
    return symbolTable.index++; //返回的是符号在符号表中的位置序号，中间代码生成时可用序号取到符号别名
}

//填写临时变量到符号表，返回临时变量在符号表中的位置
int fill_Temp(char *name,int level,int type,char flag,int offset) {
    strcpy(symbolTable.symbols[symbolTable.index].name,"");
    strcpy(symbolTable.symbols[symbolTable.index].alias,name);
    symbolTable.symbols[symbolTable.index].level=level;
    symbolTable.symbols[symbolTable.index].type=type;
    symbolTable.symbols[symbolTable.index].flag=flag;
    symbolTable.symbols[symbolTable.index].offset=offset;
    return symbolTable.index++; //返回的是临时变量在符号表中的位置序号
}

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
        T->num=T->DecList->num+1;
        break;
    case ID:                                     //最后一个变量名
        rtn=fillSymbolTable(T->type_id,newAlias(),LEV,T->type,'V',T->offset);
        if (rtn==-1)
            semantic_error(T->pos,T->type_id, "变量重复定义");
        else T->place=rtn;
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

void boolExp(struct ASTNode *T)
{  //布尔表达式，参考文献[2]p84的思想
  struct opn opn1,opn2,result;
  int op;
  if (T)
	{
	switch (T->kind) {
        case INT:
                   break;
        case FLOAT:
                   break;
        case ID:
                   break;
        case RELOP: //处理关系运算表达式,2个操作数都按基本表达式处理
                T->Exp1->offset=T->Exp2->offset=T->offset;
                Exp(T->Exp1);
                T->width=T->Exp1->width;
                Exp(T->Exp2);
                if (T->width<T->Exp2->width) T->width=T->Exp2->width;
                opn1.kind=ID; strcpy(opn1.id,symbolTable.symbols[T->Exp1->place].alias);
                opn1.offset=symbolTable.symbols[T->Exp1->place].offset;
                opn2.kind=ID; strcpy(opn2.id,symbolTable.symbols[T->Exp2->place].alias);
                opn2.offset=symbolTable.symbols[T->Exp2->place].offset;
                result.kind=ID; strcpy(result.id,T->Etrue);
                if (strcmp(T->type_id,"<")==0)
                        op=JLT;
                else if (strcmp(T->type_id,"<=")==0)
                        op=JLE;
                else if (strcmp(T->type_id,">")==0)
                        op=JGT;
                else if (strcmp(T->type_id,">=")==0)
                        op=JGE;
                else if (strcmp(T->type_id,"==")==0)
                        op=EQ;
                else if (strcmp(T->type_id,"!=")==0)
                        op=NEQ;
                T->code=genIR(op,opn1,opn2,result);
                T->code=merge(4,T->Exp1->code,T->Exp2->code,T->code,genGoto(T->Efalse));
                break;
        case AND:
        case OR:
                if (T->kind==AND)
                {
                    strcpy(T->Exp1->Etrue,newLabel());
                    strcpy(T->Exp2->Efalse,T->Efalse);
                }
                else
                {
                    strcpy(T->Exp1->Etrue,T->Etrue);
                    strcpy(T->Exp1->Efalse,newLabel());
                }
                strcpy(T->Exp2->Etrue,T->Etrue);
                strcpy(T->Exp2->Efalse,T->Efalse);
                T->Exp1->offset=T->Exp2->offset=T->offset;
                boolExp(T->Exp1);
                T->width=T->Exp1->width;
                boolExp(T->Exp2);
                if (T->width < T->Exp2->width) T->width=T->Exp2->width;
                if (T->kind==AND)
                    T->code=merge(3,T->Exp1->code,genLabel(T->Exp1->Etrue),T->Exp2->code);
                else
                    T->code=merge(3,T->Exp1->code,genLabel(T->Exp1->Efalse),T->Exp2->code);
                break;
        case NOT:
                strcpy(T->Exp1->Etrue,T->Efalse);
                    strcpy(T->Exp1->Efalse,T->Etrue);
                    boolExp(T->Exp1);
                    T->code=T->Exp1->code;
                    break;
        }
	}
}


void Exp(struct ASTNode *T)
{//处理基本表达式，参考文献[2]p82的思想
int rtn,num,width;
struct ASTNode *T0;
struct opn opn1,opn2,result;
if (T)
{
	switch (T->kind)
	{
	    case ID:    //查符号表，获得符号表中的位置，类型送type
            rtn=searchSymbolTable(T->type_id);
            if (rtn==-1)
                semantic_error(T->pos,T->type_id, "变量未定义");
            else if (symbolTable.symbols[rtn].flag=='F')
                semantic_error(T->pos,T->type_id, "是函数名，类型不匹配");
            else
            {
                T->place=rtn;       //结点保存变量在符号表中的位置
                T->code=NULL;       //标识符不需要生成TAC
                T->type=symbolTable.symbols[rtn].type;
                T->offset=symbolTable.symbols[rtn].offset;
                T->width=0;         //未再使用新单元
            }
            break;
        case INT:
            //为整常量生成一个临时变量，T->place表示临时变量在符号表位置
            T->place=fill_Temp(newTemp(),LEV,T->type,'T',T->offset);
            T->type=INT;
            opn1.kind=INT;
            opn1.const_int=T->type_int;
            result.kind=ID;
            strcpy(result.id,symbolTable.symbols[T->place].alias);
            result.offset=symbolTable.symbols[T->place].offset;
            T->code=genIR(ASSIGNOP,opn1,opn2,result);
            T->width=4;
            break;
        case FLOAT://为浮点常量生成一个临时变量
            T->place=fill_Temp(newTemp(),LEV,T->type,'T',T->offset);
            T->type=FLOAT;
            opn1.kind=FLOAT; opn1.const_float=T->type_float;
            result.kind=ID; strcpy(result.id,symbolTable.symbols[T->place].alias);
            result.offset=symbolTable.symbols[T->place].offset;
            T->code=genIR(ASSIGNOP,opn1,opn2,result);
            T->width=8;
            break;
	    case ASSIGNOP:
            if (T->Exp1->kind!=ID)
            {
                semantic_error(T->pos,"", "赋值语句需要左值");
            }
            else
            {
                T->Exp1->offset=T->offset;
                Exp(T->Exp1);   //处理左值，例中仅为变量
                T->offset+=T->Exp1->width; //如果左值是下标变量，with会大于0
                T->Exp2->offset=T->offset;
                Exp(T->Exp2);
                T->type=T->Exp1->type;
                T->width=T->Exp1->width+T->Exp2->width;
                T->code=merge(2,T->Exp1->code,T->Exp2->code);
                opn1.kind=ID;   //右值一定是个变量或常量生成的临时变量
                strcpy(opn1.id,symbolTable.symbols[T->Exp2->place].alias);
                opn1.offset=symbolTable.symbols[T->Exp2->place].offset;
                result.kind=ID;
                strcpy(result.id,symbolTable.symbols[T->Exp1->place].alias);
                result.offset=symbolTable.symbols[T->Exp1->place].offset;
                T->code=merge(2,T->code,genIR(ASSIGNOP,opn1,opn2,result));
            }
            break;
	case AND:   //按算术表达式方式计算布尔值，未写完
	case OR:    //按算术表达式方式计算布尔值，未写完
	case RELOP: //按算术表达式方式计算布尔值，未写完
            T->type=INT;
            T->Exp1->offset=T->Exp2->offset=T->offset;
            Exp(T->Exp1);
            Exp(T->Exp2);
            break;
	case PLUS:
	case MINUS:
	case STAR:
	case DIV:   T->Exp1->offset=T->offset;
                Exp(T->Exp1);
                T->Exp2->offset=T->offset+T->Exp1->width;
                Exp(T->Exp2);
                //判断T->Exp1，T->Exp2类型是否正确，可能根据运算符生成不同形式的代码，给T的type赋值
                //下面的类型属性计算，没有考虑错误处理情况
                if (T->Exp1->type==FLOAT || T->Exp2->type==FLOAT)
                     T->type=FLOAT,T->width=T->Exp1->width+T->Exp2->width+4;
                else T->type=INT,T->width=T->Exp1->width+T->Exp2->width+2;
                T->place=fill_Temp(newTemp(),LEV,T->type,'T',T->offset+T->Exp1->width+T->Exp2->width);
                opn1.kind=ID; strcpy(opn1.id,symbolTable.symbols[T->Exp1->place].alias);
                opn1.type=T->Exp1->type;
                opn1.offset=symbolTable.symbols[T->Exp1->place].offset;
                opn2.kind=ID;
                strcpy(opn2.id,symbolTable.symbols[T->Exp2->place].alias);
                opn2.type=T->Exp2->type;
                opn2.offset=symbolTable.symbols[T->Exp2->place].offset;
                result.kind=ID;
                strcpy(result.id,symbolTable.symbols[T->place].alias);
                result.type=T->type;
                result.offset=symbolTable.symbols[T->place].offset;
                T->code=merge(3,T->Exp1->code,T->Exp2->code,genIR(T->kind,opn1,opn2,result));
                T->width=T->Exp1->width+T->Exp2->width+(T->type==INT?4:8);
                break;
	case NOT:   //未写完整
                break;
	case UMINUS://未写完整
                break;
    case FUNC_CALL: //根据T->type_id查出函数的定义，如果语言中增加了实验教材的read，write需要单独处理一下
                rtn=searchSymbolTable(T->type_id);
                if (rtn==-1){
                    semantic_error(T->pos,T->type_id, "函数未定义");
                    break;
                    }
                if (symbolTable.symbols[rtn].flag!='F'){
                    semantic_error(T->pos,T->type_id, "不是一个函数");
                     break;
                    }
                T->type=symbolTable.symbols[rtn].type;
                width=T->type==INT?4:8;   //存放函数返回值的单数字节数
                if (T->Args){
                    T->Args->offset=T->offset;
                    Exp(T->Args);       //处理所有实参表达式求值，及类型
                    T->width=T->Args->width+width; //累加上计算实参使用临时变量的单元数
                    T->code=T->Args->code;
                    }
                else {T->width=width; T->code=NULL;}
                match_param(rtn,T->Args);   //处理所有参数的匹配

                    //处理参数列表的中间代码
                T0=T->Args;
                while (T0)
                {  //用ARG依次列出实参表达式的值
                    result.kind=ID;
                    strcpy(result.id,symbolTable.symbols[T0->Exp1->place].alias);
                    result.offset=symbolTable.symbols[T0->Exp1->place].offset;
                    T->code=merge(2,T->code,genIR(ARG,opn1,opn2,result));
                    T0=T0->Args;
                }
                T->place=fill_Temp(newTemp(),LEV,T->type,'T',T->offset+T->width-width);
                opn1.kind=ID;
                strcpy(opn1.id,T->type_id);  //保存函数名
                opn1.offset=rtn;//用offset保存函数定义入口,在目标代码生成时，能获取相应信息
                result.kind=ID;
                strcpy(result.id,symbolTable.symbols[T->place].alias);
                result.offset=symbolTable.symbols[T->place].offset;
                T->code=merge(2,T->code,genIR(CALL,opn1,opn2,result));//生成函数调用中间代码
                break;
    case ARGS:      //此处仅处理各实参表达式的求值的代码序列，不生成ARG的实参系列
                T->Exp1->offset=T->offset;
                Exp(T->Exp1);
                T->width=T->Exp1->width;
                T->code=T->Exp1->code;
                if (T->Args) {
                    T->Args->offset=T->offset+T->Exp1->width;
                    Exp(T->Args);
                    T->width+=T->Args->width;
                    T->code=merge(2,T->code,T->Args->code);
                    }
                break;
         }
      }
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
            if (T->ParamList)
            {
                T->ParamList->offset=T->offset+T->Param->width;
                semantic_Analysis(T->ParamList);
                T->num=T->Param->num+T->ParamList->num;        //统计参数个数
                T->width=T->Param->width+T->ParamList->width;  //累加参数单元宽度
                T->code=merge(2,T->Param->code,T->ParamList->code);  //连接参数代码
            }
            else
            {
                T->num=T->Param->num;
                T->width=T->Param->width;
                T->code=T->Param->code;
            }
            break;
	    case  PARAM_DEC:
            rtn=fillSymbolTable(T->ID->type_id,newAlias(),1,T->Specifier->type,'P',T->offset);
            if (rtn==-1)
                semantic_error(T->ID->pos,T->ID->type_id, "参数名重复定义");
            else T->ID->place=rtn;
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
                     printf("\n第%d行函数的函数体结束前符号表(共2层）：\n",T->pos);
                else printf("\n第%d行复合语句结束前符号表(共%d层)：\n",T->pos,LEV+1);
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
	case WHILE: strcpy(T->Cond->Etrue,newLabel());  //子结点继承属性的计算
                strcpy(T->Cond->Efalse,T->Snext);
                T->Cond->offset=T->Body->offset=T->offset;
                boolExp(T->Cond);      //循环条件，要单独按短路代码处理
                T->width=T->Cond->width;
                strcpy(T->Body->Snext,newLabel());
                semantic_Analysis(T->Body);      //循环体
                if (T->width<T->Body->width) T->width=T->Body->width;
                T->code=merge(5,genLabel(T->Body->Snext),T->Cond->code, \
                genLabel(T->Cond->Etrue),T->Body->code,genGoto(T->Body->Snext));
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
