%option  yylineno
%{
#include "parser.tab.h"
#include "string.h"
#include "def.h"

int yycolumn=1;
#define YY_USER_ACTION    \
	yylloc.first_line=yylloc.last_line=yylineno; \
	yylloc.first_column=yycolumn;\
	yylloc.last_column=yycolumn+yyleng-1;\
	yycolumn+=yyleng;
		   	   
		   	   
typedef union {
	int type_int;
	int type_float;
	char type_id[32];
	char type_char;
	// struct ASTNode *ptr;
} YYLVAL;
#define YYSTYPE YYLVAL
int lastToken;

%}

%x comment string

singleLineComment 	"//"[^\n]*
blockCommentStart 		"/"+"*"
blockCommentEnd			"*"+"/"
stringBlock				"\""

id   [A-Za-z][A-Za-z0-9]*  
intconst    [0-9]+
floatconst  [0-9]*\.?[0-9]?([eE][-+]?[0-9]+)?
%%
"int"       {strcpy(yylval.type_id,  yytext);return TYPE;}
"float"     {strcpy(yylval.type_id,  yytext);return TYPE;}
"char"		{strcpy(yylval.type_id,  yytext);return TYPE;}

"continue"	{return CONTINUE;}
"break"		{return BREAK;}
"return"    {return RETURN;}
"if"        {return IF;}
"else"      {return ELSE;}
"while"     {return WHILE;}

"for"       {return FOR;}

{id}        				{strcpy(yylval.type_id,  yytext); return ID;}
";"		  					{return SEMI;}
","		  					{return COMMA;}
">"|"<"|">="|"<="|"=="|"!=" {strcpy(yylval.type_id, yytext);;return RELOP;}
"="							{return ASSIGNOP;}
"++"						{return DPLUS;}
"+"							{return PLUS;}
"--"						{return DMINUS;}
"-"							{return MINUS;}
"*"							{return STAR;}
"/"							{return DIV;}
"&&"         				{return AND;}
"||"           				{return OR;}
"!"							{return NOT;}
"("							{return LP;}
")"							{return RP;}
"{"							{return LC;}
"}"							{return RC;}
"["							{return LB;}
"]"							{return RB;}


{intconst}          {yylval.type_int=atoi(yytext);  return INT;}
{floatconst}        {yylval.type_float=atof(yytext);return FLOAT;}


{singleLineComment}	{}
{blockCommentStart}				{BEGIN(comment);}
<comment>[^\*]					{}
<comment>"\*"+[^/]				{}
<comment>{blockCommentEnd}		{BEGIN(INITIAL);}
<comment><<EOF>>				{printf("%sat line%d: Block Comment miss final synax\n",yytext,yylineno);return 0;}

{stringBlock}					{BEGIN(string);}
<string>[^\"\n]					{}
<string>\n						{printf("%sat line%d: String inline enter\n",yytext,yylineno);return 0;}
<string>{stringBlock}			{BEGIN(INITIAL);}
<string><<EOF>>				{printf("%sat line%d: String miss final synax\n",yytext,yylineno);return 0;}

[ \r\t]             {}   

[\n]                {yycolumn=1;}   
.			        {printf("Error type A :Mysterious character \"%s\"\n\t at Line %d\n",yytext,yylineno);}

%%

/* 和bison联用时，不需要这部分
void main()
{
yylex();
return 0;
}

*/
int yywrap()
{
return 1;
}
