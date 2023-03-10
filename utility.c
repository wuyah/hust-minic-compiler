#include "def.h"

void semantic_error(int line,char *msg1,char *msg2){
    //这里可以只收集错误信息，最后一次显示
    printf("在%d行,%s %s\n",line,msg1,msg2);
    exit(-1);
}

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
    if(!label)
        printf("Label not exist!\n");
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
        else 
            if (h2){
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
    // FILE* fp;    fp = fopen("ir.txt", "w");

    char opnstr1[34],opnstr2[34],resultstr[34];
    struct codenode *h=head;
    do {
        if (h->opn1.kind==INT)
             sprintf(opnstr1,"#%d",h->opn1.const_int);
        if (h->opn1.kind==FLOAT)
             sprintf(opnstr1,"#%f",h->opn1.const_float);
        if (h->opn1.kind==ID)
             sprintf(opnstr1,"%s",h->opn1.id);
        if(h->opn1.kind==ARRAY_POINTER)
            sprintf(opnstr1,"*%s",h->opn1.id);
        if (h->opn2.kind==INT)
             sprintf(opnstr2,"#%d",h->opn2.const_int);
        if (h->opn2.kind==FLOAT)
             sprintf(opnstr2,"#%f",h->opn2.const_float);
        if(h->opn2.kind==ARRAY_POINTER)
            sprintf(opnstr2,"*%s",h->opn2.id);
        if (h->opn2.kind==ID)
             sprintf(opnstr2,"%s",h->opn2.id);
        if (h->result.kind==ID)
            sprintf(resultstr,"%s",h->result.id);
        else
            sprintf(resultstr,"*%s",h->result.id);
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
            case EXP_JLE:
                           printf("  %s := %s <= %s\n",resultstr,opnstr1,opnstr2);
                           break;
            case EXP_JLT:
                           printf("  %s := %s < %s\n",resultstr,opnstr1,opnstr2);
                           break;  
            case EXP_JGE:
                           printf("  %s := %s >= %s\n",resultstr,opnstr1,opnstr2);
                           break;  
            case EXP_JGT:
                           printf("  %s := %s > %s\n",resultstr,opnstr1,opnstr2);
                           break;  
            case EXP_EQ:
                           printf("  %s := %s == %s\n",resultstr,opnstr1,opnstr2);
                           break;
            case EXP_NEQ:
                           printf("  %s := %s != %s\n",resultstr,opnstr1,opnstr2);
                           break;
            case AND:
                           printf("  %s := %s && %s\n",resultstr,opnstr1,opnstr2);
                            break;
            case OR:
                           printf("  %s := %s || %s\n",resultstr,opnstr1,opnstr2);
                            break;
            case NOT:
                            printf("  %s := ! %s\n", resultstr, opnstr1);
                            break;
            case UMINUS:
                            printf("  %s := - %s\n", resultstr, opnstr1);
                            break;
            case DMINUS:
                            printf("  %s--\n",resultstr);
                            break;
            case DPLUS:
                            printf("  %s++\n",resultstr);
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
            case ARRAY_POINTER_ASSIGN:
                            printf("  %s -> %s[%s]\n", resultstr, opnstr1, opnstr2);
                            break;
        }
        h=h->next;
    } while (h!=head);
}

void prn_symbol(){ //显示符号表
    int i=0;
    printf("%6s\t%6s\t%6s\t%6s\t%4s\t%6s\t%6s\t%6s\n","变量名","别 名","层 号","类  型","标记","偏移量", "array_dim","parmamnum");
    for(i=0;i<symbolTable.index;i++)
    {
        char type[16];
        char offset[33];
        sprintf(offset, "%d", symbolTable.symbols[i].offset);
        switch (symbolTable.symbols[i].type)
        {
        case INT:
            /* code */
            strcpy(type, "int");
            break;
        case FLOAT:
            strcpy(type, "float");
            break;
        case INT+ARRAY_DEC:
            strcpy(type, "int_arr");
            break;
        case FLOAT+ARRAY_DEC:
            strcpy(type, "float_arr");
            break;
        case ARRAY_POINTER:
            strcpy(type, "pointer");
            break;
        }
        printf("%6s\t%6s\t%6d\t%6s\t%4c\t%s\t",symbolTable.symbols[i].name,\
        symbolTable.symbols[i].alias,symbolTable.symbols[i].level,\
        type,\
        symbolTable.symbols[i].flag,offset);
        if(symbolTable.symbols[i].arraylen->size > 0)
        {
            for(int j=0;j<symbolTable.symbols[i].arraylen->size;j++)
                printf("%3d ", symbolTable.symbols[i].arraylen->data[j]);
        } else{
            printf("\t");
        }
        printf("\t");
        if(symbolTable.symbols[i].paramnum>=0)
        {
            printf("%d",symbolTable.symbols[i].paramnum);
        }
        printf("\n");
    }
}

// return the index of searched string
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
            if (level==0 && symbolTable.symbols[i].level==1) 
                continue;  //外部变量和形参不必比较重名
            if (!strcmp(symbolTable.symbols[i].name, name))  
                return -1;
        }
    //填写符号表内容
    strcpy(symbolTable.symbols[symbolTable.index].name,name);
    strcpy(symbolTable.symbols[symbolTable.index].alias,alias);
    symbolTable.symbols[symbolTable.index].level=level;
    symbolTable.symbols[symbolTable.index].type=type;
    symbolTable.symbols[symbolTable.index].flag=flag;
    symbolTable.symbols[symbolTable.index].offset=offset;
    symbolTable.symbols[symbolTable.index].arraylen = (vector *)malloc(sizeof(vector));
    vector_init(symbolTable.symbols[symbolTable.index].arraylen, 1);
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
    symbolTable.symbols[symbolTable.index].arraylen = (vector *)malloc(sizeof(vector));
    vector_init(symbolTable.symbols[symbolTable.index].arraylen, 1);
    return symbolTable.index++; //返回的是临时变量在符号表中的位置序号
}

// push back array length
int fill_arr_length(int index, int length)
{
    vector_push_back(symbolTable.symbols[index].arraylen, length);
    return index;
}
