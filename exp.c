#include "def.h"
#include "vector.h"

void arrayExp(ASTNode *T);
void assignExp(ASTNode *T);
void dminusplusExp(ASTNode *T);

void Exp(struct ASTNode *T)
{ // 处理基本表达式，参考文献[2]p82的思想
    int rtn, num, width;
    struct ASTNode *T0;
    struct opn opn1, opn2, result;
    vector *v;
    int op;
    v = (vector *)malloc(sizeof(vector));
    vector_init(v, 1);
    if (T)
    {
        switch (T->kind)
        {
        case ID: // 查符号表，获得符号表中的位置，类型送type
            rtn = searchSymbolTable(T->type_id);
            if (rtn == -1)
                semantic_error(T->pos, T->type_id, "变量未定义");
            else if (symbolTable.symbols[rtn].flag == 'F')
                semantic_error(T->pos, T->type_id, "是函数名，类型不匹配");
            else
            {
                T->place = rtn; // 结点保存变量在符号表中的位置
                // array need use place to calculate the rtn
                T->code = NULL; // 标识符不需要生成TAC
                T->type = symbolTable.symbols[rtn].type;
                T->offset = symbolTable.symbols[rtn].offset;
                T->width = 0; // 未再使用新单元
            }
            break;
        case ARRAY_CALL:
            arrayExp(T);
            break;
        case INT:
            // 为整常量生成一个临时变量，T->place表示临时变量在符号表位置
            T->place = fill_Temp(newTemp(), LEV, T->type, 'T', T->offset);
            T->type = INT;
            T->kind = ID;
            opn1.kind = INT;
            opn1.type = INT;
            opn1.const_int = T->type_int;
            result.kind = ID;
            strcpy(result.id, symbolTable.symbols[T->place].alias);
            result.offset = symbolTable.symbols[T->place].offset;
            T->code = genIR(ASSIGNOP, opn1, opn2, result);
            T->width = 4;
            break;
        case FLOAT: // 为浮点常量生成一个临时变量
            T->place = fill_Temp(newTemp(), LEV, T->type, 'T', T->offset);
            T->type = FLOAT;
            opn1.kind = FLOAT;
            opn1.type = FLOAT;
            opn1.const_float = T->type_float;
            result.kind = ID;
            strcpy(result.id, symbolTable.symbols[T->place].alias);
            result.offset = symbolTable.symbols[T->place].offset;
            T->code = genIR(ASSIGNOP, opn1, opn2, result);
            // float width in qtspim is 4
            T->width = 4;
            break;
        case ASSIGNOP:
            T->Exp1->offset = T->offset;
            Exp(T->Exp1);                // 处理左值，例中仅为变量
            T->offset += T->Exp1->width; // 如果左值是下标变量，width会大于0
            T->Exp2->offset = T->offset;
            Exp(T->Exp2);
            // move to there
            if (T->Exp1->kind != ID && T->Exp1->kind != ARRAY_CALL)
            {
                semantic_error(T->pos, "", "赋值语句需要左值");
            }
            else if (T->Exp1->type == INT && T->Exp2->type == FLOAT)
            {
                // add assign type error
                T->place = rtn;
                semantic_error(T->pos, "", "assign type not match\n");
            }
            else
            {
                if (T->Exp1->kind == ID)
                    rtn = searchSymbolTable(T->Exp1->type_id);
                else
                    rtn = T->Exp1->place;

                int type = symbolTable.symbols[rtn].type;
                if (type == INT && T->Exp2->type == FLOAT)
                {
                    semantic_error(T->pos, "", "assign type not match\n");
                }
                // ask a question
                if (T->Exp1->type == FLOAT || T->Exp2->type == INT)
                {
                    T->type = FLOAT;
                }
                else
                    T->type = T->Exp1->type;

                T->width = T->Exp1->width + T->Exp2->width;
                T->code = merge(2, T->Exp1->code, T->Exp2->code);
                if (T->Exp2->kind == ARRAY_CALL)
                    opn1.kind = ARRAY_POINTER; // 右值一定是个变量或常量生成的临时变量
                else
                    opn1.kind = ID;

                // not add
                opn1.type = T->Exp2->type;
                strcpy(opn1.id, symbolTable.symbols[T->Exp2->place].alias);
                opn1.offset = symbolTable.symbols[T->Exp2->place].offset;

                if (T->Exp1->kind == ARRAY_CALL)
                    result.kind = ARRAY_POINTER;
                else
                    result.kind = ID;
                result.type = T->type;
                strcpy(result.id, symbolTable.symbols[T->Exp1->place].alias);
                result.offset = symbolTable.symbols[T->Exp1->place].offset;
                T->code = merge(2, T->code, genIR(ASSIGNOP, opn1, opn2, result));
            }
            break;
        // TODO this part is used to calculate the boolExp's value
        case AND:
        case OR:
        case RELOP:
            T->type = INT;
            T->Exp1->offset = T->offset;
            T->Exp2->offset = T->offset + T->Exp1->width;
            Exp(T->Exp1);
            Exp(T->Exp2);
            // create Temp Symbol
            T->place = fill_Temp(newTemp(), LEV, T->type, 'T', T->offset + T->Exp1->width + T->Exp2->width);
            if (T->Exp1->kind == ARRAY_CALL)
                opn1.kind = ARRAY_POINTER; // 右值一定是个变量或常量生成的临时变量
            else
                opn1.kind = ID;
            strcpy(opn1.id, symbolTable.symbols[T->Exp1->place].alias);
            opn1.type = T->Exp1->type;
            opn1.offset = symbolTable.symbols[T->Exp1->place].offset;
            if (T->Exp2->kind == ARRAY_CALL)
                opn2.kind = ARRAY_POINTER; // 右值一定是个变量或常量生成的临时变量
            else
                opn2.kind = ID;
            strcpy(opn2.id, symbolTable.symbols[T->Exp2->place].alias);
            opn2.type = T->Exp2->type;
            opn2.offset = symbolTable.symbols[T->Exp2->place].offset;
            // the result is the created temp symbol
            result.kind = ID;
            strcpy(result.id, symbolTable.symbols[T->place].alias);
            result.type = T->type;
            result.offset = symbolTable.symbols[T->place].offset;
            // T->code=merge(3,T->Exp1->code,T->Exp2->code,genIR(T->type_id,opn1,opn2,result));
            // T->width=T->Exp1->width+T->Exp2->width+(T->type==INT?4:8);
            // can't use
            if (strcmp(T->type_id, "<") == 0)
                T->kind = EXP_JLT;
            else if (strcmp(T->type_id, "<=") == 0)
                T->kind = EXP_JLE;
            else if (strcmp(T->type_id, ">") == 0)
                T->kind = EXP_JGT;
            else if (strcmp(T->type_id, ">=") == 0)
                T->kind = EXP_JGE;
            else if (strcmp(T->type_id, "==") == 0)
                T->kind = EXP_EQ;
            else if (strcmp(T->type_id, "!=") == 0)
                T->kind = EXP_NEQ;
            T->code = merge(3, T->Exp1->code, T->Exp2->code, genIR(T->kind, opn1, opn2, result));
            T->width = T->Exp1->width + T->Exp2->width + 4;
            break;
        case PLUS:
        case MINUS:
        case STAR:
        case DIV:
            T->Exp1->offset = T->offset;
            Exp(T->Exp1);
            T->Exp2->offset = T->offset + T->Exp1->width;
            Exp(T->Exp2);
            // 判断T->Exp1，T->Exp2类型是否正确，可能根据运算符生成不同形式的代码，给T的type赋值
            // 下面的类型属性计算，没有考虑错误处理情况
            if (T->Exp1->type == FLOAT || T->Exp2->type == FLOAT)
                T->type = FLOAT, T->width = T->Exp1->width + T->Exp2->width + 2;
            else
                T->type = INT, T->width = T->Exp1->width + T->Exp2->width + 2;
            T->place = fill_Temp(newTemp(), LEV, T->type, 'T', T->offset + T->Exp1->width + T->Exp2->width);

            if (T->Exp1->kind == ARRAY_CALL)
                opn1.kind = ARRAY_POINTER; // 右值一定是个变量或常量生成的临时变量
            else
                opn1.kind = ID;
            opn1.type = T->Exp1->type;
            strcpy(opn1.id, symbolTable.symbols[T->Exp1->place].alias);
            opn1.offset = symbolTable.symbols[T->Exp1->place].offset;

            if (T->Exp2->kind == ARRAY_CALL)
                opn2.kind = ARRAY_POINTER; // 右值一定是个变量或常量生成的临时变量
            else
                opn2.kind = ID;
            opn2.type = T->Exp2->type;
            strcpy(opn2.id, symbolTable.symbols[T->Exp2->place].alias);
            opn2.offset = symbolTable.symbols[T->Exp2->place].offset;
            result.kind = ID;
            result.type = T->type;
            strcpy(result.id, symbolTable.symbols[T->place].alias);
            result.offset = symbolTable.symbols[T->place].offset;
            T->code = merge(3, T->Exp1->code, T->Exp2->code, genIR(T->kind, opn1, opn2, result));
            // T->width = T->Exp1->width + T->Exp2->width + (T->type == INT ? 4 : 8);
            T->width = T->Exp1->width + T->Exp2->width + 4;
            break;
        //  Finished
        case NOT:
            T->Exp1->offset = T->offset;
            T->kind = NOT;
            Exp(T->Exp1);
            T->place = fill_Temp(newTemp(), LEV, T->type, 'T', T->offset + T->Exp1->width);
            if (T->Exp1->kind == ARRAY_CALL)
                opn1.kind = ARRAY_POINTER; // 右值一定是个变量或常量生成的临时变量
            else
                opn1.kind = ID;
            strcpy(opn1.id, symbolTable.symbols[T->Exp1->place].alias);
            opn1.type = T->Exp1->type;
            opn1.offset = symbolTable.symbols[T->Exp1->place].offset;
            strcpy(result.id, symbolTable.symbols[T->place].alias);
            result.kind = ID;
            result.type = T->type;
            result.offset = symbolTable.symbols[T->place].offset;
            T->code = merge(2, T->Exp1->code, genIR(T->kind, opn1, opn2, result));
            T->width = T->Exp1->width + 4;
            break;
        case UMINUS: // 未写完整
            T->Exp1->offset = T->offset;
            T->kind = UMINUS;
            Exp(T->Exp1);
            T->type = T->Exp1->type;
            T->place = fill_Temp(newTemp(), LEV, T->type, 'T', T->offset + T->Exp1->width);
            if (T->Exp1->kind == ARRAY_CALL)
                opn1.kind = ARRAY_POINTER; // 右值一定是个变量或常量生成的临时变量
            else
                opn1.kind = ID;
            strcpy(opn1.id, symbolTable.symbols[T->Exp1->place].alias);
            opn1.type = T->Exp1->type;
            opn1.offset = symbolTable.symbols[T->Exp1->place].offset;
            strcpy(result.id, symbolTable.symbols[T->place].alias);
            result.kind = ID;
            result.type = T->type;
            result.offset = symbolTable.symbols[T->place].offset;
            T->code = merge(2, T->Exp1->code, genIR(T->kind, opn1, opn2, result));
            T->width = T->Exp1->width + 4;
            break;
        case DMINUS_L:
        case DMINUS_R:
        case DPLUS_L:
        case DPLUS_R:
            dminusplusExp(T);
            break;
        case FUNC_CALL: // 根据T->type_id查出函数的定义，如果语言中增加了实验教材的read，write需要单独处理一下
            rtn = searchSymbolTable(T->type_id);
            if (rtn == -1)
            {
                semantic_error(T->pos, T->type_id, "函数未定义");
                break;
            }
            if (symbolTable.symbols[rtn].flag != 'F')
            {
                semantic_error(T->pos, T->type_id, "不是一个函数");
                break;
            }
            T->type = symbolTable.symbols[rtn].type;
            width = T->type == INT ? 4 : 8; // 存放函数返回值的单数字节数
            if (T->Args)
            {
                T->Args->offset = T->offset;
                Exp(T->Args);                      // 处理所有实参表达式求值，及类型
                T->width = T->Args->width + width; // 累加上计算实参使用临时变量的单元数
                T->code = T->Args->code;
            }
            else
            {
                T->width = width;
                T->code = NULL;
            }
            match_param(rtn, T->Args); // 处理所有参数的匹配

            // 处理参数列表的中间代码
            T0 = T->Args;
            while (T0)
            { // 用ARG依次列出实参表达式的值
                if(T0->Exp1->kind==ARRAY_CALL)
                    result.kind = ARRAY_POINTER;
                else
                    result.kind = ID;
                result.type = symbolTable.symbols[T0->Exp1->place].type;
                strcpy(result.id, symbolTable.symbols[T0->Exp1->place].alias);
                result.offset = symbolTable.symbols[T0->Exp1->place].offset;
                T->code = merge(2, T->code, genIR(ARG, opn1, opn2, result));
                T0 = T0->Args;
            }
            T->place = fill_Temp(newTemp(), LEV, T->type, 'T', T->offset + T->width - width);
            opn1.kind = ID;
            strcpy(opn1.id, T->type_id); // 保存函数名
            opn1.offset = rtn;           // 用offset保存函数定义入口,在目标代码生成时，能获取相应信息
            result.kind = ID;
            strcpy(result.id, symbolTable.symbols[T->place].alias);
            result.offset = symbolTable.symbols[T->place].offset;
            T->code = merge(2, T->code, genIR(CALL, opn1, opn2, result)); // 生成函数调用中间代码
            break;
        case ARGS: // 此处仅处理各实参表达式的求值的代码序列，不生成ARG的实参系列
            T->Exp1->offset = T->offset;
            Exp(T->Exp1);
            T->width = T->Exp1->width;
            T->code = T->Exp1->code;
            if (T->Args)
            {
                T->Args->offset = T->offset + T->Exp1->width;
                Exp(T->Args);
                T->width += T->Args->width;
                T->code = merge(2, T->code, T->Args->code);
            }
            break;
        }
    }
}

void boolExp(struct ASTNode *T)
{ // 布尔表达式，参考文献[2]p84的思想
    struct opn opn1, opn2, result;
    int op;
    if (T)
    {
        switch (T->kind)
        {
        case INT:
            break;
        case FLOAT:
            break;
        case ID:
            break;
        case RELOP: // 处理关系运算表达式,2个操作数都按基本表达式处理
            T->Exp1->offset = T->offset;
            Exp(T->Exp1);
            T->width = T->Exp1->width;
            T->Exp2->offset = T->offset + T->Exp1->width;
            Exp(T->Exp2);
            if (T->width < T->Exp2->width)
                T->width = T->Exp2->width;
                
            if (T->Exp1->kind == ARRAY_CALL)
                opn1.kind = ARRAY_POINTER;
            else
                opn1.kind = ID;
            opn1.type = T->Exp1->type;
            strcpy(opn1.id, symbolTable.symbols[T->Exp1->place].alias);
            opn1.offset = symbolTable.symbols[T->Exp1->place].offset;

            if (T->Exp2->kind == ARRAY_CALL)
                opn2.kind = ARRAY_POINTER;
            else
                opn2.kind = ID;
            opn2.type = T->Exp2->type;
            strcpy(opn2.id, symbolTable.symbols[T->Exp2->place].alias);
            opn2.offset = symbolTable.symbols[T->Exp2->place].offset;
            result.kind = ID;
            strcpy(result.id, T->Etrue);
            if (strcmp(T->type_id, "<") == 0)
                op = JLT;
            else if (strcmp(T->type_id, "<=") == 0)
                op = JLE;
            else if (strcmp(T->type_id, ">") == 0)
                op = JGT;
            else if (strcmp(T->type_id, ">=") == 0)
                op = JGE;
            else if (strcmp(T->type_id, "==") == 0)
                op = EQ;
            else if (strcmp(T->type_id, "!=") == 0)
                op = NEQ;
            T->code = genIR(op, opn1, opn2, result);
            T->code = merge(4, T->Exp1->code, T->Exp2->code, T->code, genGoto(T->Efalse));
            break;
        case AND:
        case OR:
            printf("T->Efalse=%s\n", T->Efalse);
            if (T->kind == AND)
            {
                strcpy(T->Exp1->Etrue, newLabel());
                strcpy(T->Exp1->Efalse, T->Efalse);
            }
            else
            {
                strcpy(T->Exp1->Etrue, T->Etrue);
                strcpy(T->Exp1->Efalse, newLabel());
            }
            strcpy(T->Exp2->Etrue, T->Etrue);
            strcpy(T->Exp2->Efalse, T->Efalse);
            T->Exp1->offset = T->Exp2->offset = T->offset;
            boolExp(T->Exp1);
            T->width = T->Exp1->width;
            boolExp(T->Exp2);
            if (T->width < T->Exp2->width)
                T->width = T->Exp2->width;
            if (T->kind == AND)
                T->code = merge(3, T->Exp1->code, genLabel(T->Exp1->Etrue), T->Exp2->code);
            else
                T->code = merge(3, T->Exp1->code, genLabel(T->Exp1->Efalse), T->Exp2->code);
            break;
        case NOT:
            strcpy(T->Exp1->Etrue, T->Efalse);
            strcpy(T->Exp1->Efalse, T->Etrue);
            boolExp(T->Exp1);
            T->code = T->Exp1->code;
            break;
        }
    }
}

void dminusplusExp(ASTNode *T)
{
    struct opn opn1, opn2, result;
    int rtn;
    T->Exp1->offset = T->offset;
    Exp(T->Exp1);
    rtn = T->Exp1->place;

    if (symbolTable.symbols[rtn].flag != 'V' && symbolTable.symbols[rtn].type != ARRAY_POINTER)
        semantic_error(T->pos, "", "DMINUS/DPLUS must with id");
    T->width = T->Exp1->width;
    if (T->Exp1->type != INT)
        semantic_error(T->pos, "", "DMINUS/DPLUS type must be INT");
    int result_place;

    // L: a=a+1 b=a | R: b=a a=a+1
    if (T->kind == DMINUS_R || T->kind == DPLUS_R) // R
    {
        result_place = fill_Temp(newTemp(), LEV, T->Exp1->type, 'T', T->offset + T->Exp1->width);
        T->width += 4;
        int instruction_kind = (T->kind == DMINUS_R) ? DMINUS : DPLUS;
        // use a temp symbol to save the Exp result as the end;
        if (T->Exp1->kind == ARRAY_CALL)
            opn1.kind = ARRAY_POINTER;
        else
            opn1.kind = ID;
        opn1.type = INT;
        strcpy(opn1.id, symbolTable.symbols[rtn].alias);
        opn1.offset = symbolTable.symbols[rtn].offset;

        result.kind = ID;
        result.type = INT;
        strcpy(result.id, symbolTable.symbols[result_place].alias);
        result.offset = symbolTable.symbols[result_place].offset;
        T->code = merge(2, T->Exp1->code, genIR(ASSIGNOP, opn1, opn2, result));
        T->place = result_place;
        
        if (T->Exp1->kind == ARRAY_CALL)
            opn1.kind = ARRAY_POINTER;
        else
            opn1.kind = ID;
        opn1.type = INT;
        strcpy(opn1.id, symbolTable.symbols[rtn].alias);
        opn1.offset = symbolTable.symbols[rtn].offset;
        result = opn1;
        T->code = merge(2, T->code, genIR(instruction_kind, opn1, opn2, opn1));
    }
    else
    {
        int instruction_kind = T->kind == DMINUS_L ? DMINUS : DPLUS;

        // first a = a +/- 1; (make the rtn symbol ++)
        struct symbol target_symbol = symbolTable.symbols[rtn];
        opn1.offset = target_symbol.offset;
        if (T->Exp1->kind == ARRAY_CALL)
            opn1.kind = ARRAY_POINTER;
        else
            opn1.kind = ID;
        opn1.type = target_symbol.type;
        strcpy(opn1.id, target_symbol.alias);

        result = opn1;
        T->code = merge(2, T->Exp1->code, genIR(instruction_kind, opn1, opn2, result));

        result_place = fill_Temp(newTemp(), LEV, T->Exp1->type, 'T', T->offset + T->Exp1->width);
        T->width += 4;
        // use a temp symbol to save the Exp result as the end;
        if (T->Exp1->kind == ARRAY_CALL)
            opn1.kind = ARRAY_POINTER;
        else
            opn1.kind = ID;
        opn1.type = INT;
        strcpy(opn1.id, symbolTable.symbols[T->Exp1->place].alias);
        opn1.offset = symbolTable.symbols[T->Exp1->place].offset;

        result.kind = ID;
        result.type = INT;
        strcpy(result.id, symbolTable.symbols[result_place].alias);
        result.offset = symbolTable.symbols[result_place].offset;
        T->code = merge(2, T->code, genIR(ASSIGNOP, opn1, opn2, result));
        T->place = result_place;
    }
}
