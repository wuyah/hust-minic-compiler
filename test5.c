int main()
{
    int a=0;
    float b=0;
    a = a || b;
    return 0;
}

VarDec:  ID          {$$=mknode(0,ID,yylineno);strcpy($$->type_id,$1);}   //ID结点，标识符符号串存放结点的type_id
		| ID ArrayDec {$$=mknode(1,ARRAY_DF,yylineno,$2);strcpy($$->type_id,$1);}   //数组
		;

//补充数组声明
ArrayDec: LB Exp RB {$$ = $2;/*$$=mknode(1,ARRAY_DEC,yylineno,$2);strcpy($$->type_id,"ARRAY_DEC");*/}
          | LB Exp RB ArrayDec {$$=mknode(2,ARRAY_DEC,yylineno,$2,$4);strcpy($$->type_id,"ARRAY_DEC");}
		  | error RB {$$=NULL;printf("\t define array error \t\n");}
		  ;
