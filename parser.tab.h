/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    INT = 258,                     /* INT  */
    ID = 259,                      /* ID  */
    RELOP = 260,                   /* RELOP  */
    TYPE = 261,                    /* TYPE  */
    CHAR = 262,                    /* CHAR  */
    FLOAT = 263,                   /* FLOAT  */
    DPLUS = 264,                   /* DPLUS  */
    DMINUS = 265,                  /* DMINUS  */
    GE = 266,                      /* GE  */
    GT = 267,                      /* GT  */
    LE = 268,                      /* LE  */
    LP = 269,                      /* LP  */
    LT = 270,                      /* LT  */
    NE = 271,                      /* NE  */
    RP = 272,                      /* RP  */
    LB = 273,                      /* LB  */
    RB = 274,                      /* RB  */
    LC = 275,                      /* LC  */
    RC = 276,                      /* RC  */
    LA = 277,                      /* LA  */
    RA = 278,                      /* RA  */
    SEMI = 279,                    /* SEMI  */
    COMMA = 280,                   /* COMMA  */
    PLUS = 281,                    /* PLUS  */
    MINUS = 282,                   /* MINUS  */
    STAR = 283,                    /* STAR  */
    DIV = 284,                     /* DIV  */
    ASSIGNOP = 285,                /* ASSIGNOP  */
    AND = 286,                     /* AND  */
    OR = 287,                      /* OR  */
    NOT = 288,                     /* NOT  */
    IF = 289,                      /* IF  */
    ELSE = 290,                    /* ELSE  */
    WHILE = 291,                   /* WHILE  */
    RETURN = 292,                  /* RETURN  */
    STRUCT = 293,                  /* STRUCT  */
    FOR = 294,                     /* FOR  */
    SWITCH = 295,                  /* SWITCH  */
    CASE = 296,                    /* CASE  */
    COLON = 297,                   /* COLON  */
    DEFAULT = 298,                 /* DEFAULT  */
    CONTINUE = 299,                /* CONTINUE  */
    BREAK = 300,                   /* BREAK  */
    EXT_DEF_LIST = 301,            /* EXT_DEF_LIST  */
    EXT_VAR_DEF = 302,             /* EXT_VAR_DEF  */
    FUNC_DEF = 303,                /* FUNC_DEF  */
    FUNC_DEC = 304,                /* FUNC_DEC  */
    EXT_DEC_LIST = 305,            /* EXT_DEC_LIST  */
    PARAM_LIST = 306,              /* PARAM_LIST  */
    PARAM_DEC = 307,               /* PARAM_DEC  */
    VAR_DEF = 308,                 /* VAR_DEF  */
    DEC_LIST = 309,                /* DEC_LIST  */
    DEF_LIST = 310,                /* DEF_LIST  */
    COMP_STM = 311,                /* COMP_STM  */
    STM_LIST = 312,                /* STM_LIST  */
    EXP_STMT = 313,                /* EXP_STMT  */
    IF_THEN = 314,                 /* IF_THEN  */
    IF_THEN_ELSE = 315,            /* IF_THEN_ELSE  */
    FUNC_CALL = 316,               /* FUNC_CALL  */
    ARGS = 317,                    /* ARGS  */
    FUNCTION = 318,                /* FUNCTION  */
    PARAM = 319,                   /* PARAM  */
    ARG = 320,                     /* ARG  */
    CALL = 321,                    /* CALL  */
    LABEL = 322,                   /* LABEL  */
    GOTO = 323,                    /* GOTO  */
    JLT = 324,                     /* JLT  */
    JLE = 325,                     /* JLE  */
    JGT = 326,                     /* JGT  */
    JGE = 327,                     /* JGE  */
    EQ = 328,                      /* EQ  */
    NEQ = 329,                     /* NEQ  */
    EXP_JLT = 330,                 /* EXP_JLT  */
    EXP_JLE = 331,                 /* EXP_JLE  */
    EXP_JGT = 332,                 /* EXP_JGT  */
    EXP_JGE = 333,                 /* EXP_JGE  */
    EXP_EQ = 334,                  /* EXP_EQ  */
    EXP_NEQ = 335,                 /* EXP_NEQ  */
    ARRAY_CALL = 336,              /* ARRAY_CALL  */
    ARRAY_DEC = 337,               /* ARRAY_DEC  */
    ARRAY_POINTER = 338,           /* ARRAY_POINTER  */
    ARRAY_POINTER_ASSIGN = 339,    /* ARRAY_POINTER_ASSIGN  */
    DMINUS_L = 340,                /* DMINUS_L  */
    DMINUS_R = 341,                /* DMINUS_R  */
    DPLUS_L = 342,                 /* DPLUS_L  */
    DPLUS_R = 343,                 /* DPLUS_R  */
    UMINUS = 344,                  /* UMINUS  */
    LOWER_THEN_ELSE = 345          /* LOWER_THEN_ELSE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 16 "parser.y"

	int    type_int;
	float  type_float;
	char   type_id[32];
        char   type_char[32];
	struct ASTNode *ptr;

#line 162 "parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;

int yyparse (void);


#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
