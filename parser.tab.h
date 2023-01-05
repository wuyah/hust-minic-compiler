/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
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
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    INT = 258,
    ID = 259,
    RELOP = 260,
    TYPE = 261,
    FLOAT = 262,
    DPLUS = 263,
    DMINUS = 264,
    GE = 265,
    GT = 266,
    LE = 267,
    LP = 268,
    LT = 269,
    NE = 270,
    RP = 271,
    LB = 272,
    RB = 273,
    LC = 274,
    RC = 275,
    SEMI = 276,
    COMMA = 277,
    PLUS = 278,
    MINUS = 279,
    STAR = 280,
    DIV = 281,
    ASSIGNOP = 282,
    AND = 283,
    OR = 284,
    NOT = 285,
    IF = 286,
    ELSE = 287,
    WHILE = 288,
    RETURN = 289,
    STRUCT = 290,
    FOR = 291,
    SWITCH = 292,
    CASE = 293,
    COLON = 294,
    DEFAULT = 295,
    EXT_DEF_LIST = 296,
    EXT_VAR_DEF = 297,
    FUNC_DEF = 298,
    FUNC_DEC = 299,
    EXT_DEC_LIST = 300,
    PARAM_LIST = 301,
    PARAM_DEC = 302,
    VAR_DEF = 303,
    DEC_LIST = 304,
    DEF_LIST = 305,
    COMP_STM = 306,
    STM_LIST = 307,
    EXP_STMT = 308,
    IF_THEN = 309,
    IF_THEN_ELSE = 310,
    FUNC_CALL = 311,
    ARGS = 312,
    FUNCTION = 313,
    PARAM = 314,
    ARG = 315,
    CALL = 316,
    LABEL = 317,
    GOTO = 318,
    JLT = 319,
    JLE = 320,
    JGT = 321,
    JGE = 322,
    EQ = 323,
    NEQ = 324,
    EXP_JLT = 325,
    EXP_JLE = 326,
    EXP_JGT = 327,
    EXP_JGE = 328,
    EXP_EQ = 329,
    EXP_NEQ = 330,
    UMINUS = 331,
    LOWER_THEN_ELSE = 332
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 16 "parser.y"

	int    type_int;
	float  type_float;
	char   type_id[32];
	struct ASTNode *ptr;

#line 142 "parser.tab.h"

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
