/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 3 "parser.y"

        #include "stdio.h"
        #include "math.h"
        #include "string.h"
        #include "def.h"
        extern int yylineno;
        extern char *yytext;
        extern FILE *yyin;
        void yyerror(const char* fmt, ...);
        void display(struct ASTNode *,int);
        int yylex();

#line 84 "parser.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_INT = 3,                        /* INT  */
  YYSYMBOL_ID = 4,                         /* ID  */
  YYSYMBOL_RELOP = 5,                      /* RELOP  */
  YYSYMBOL_TYPE = 6,                       /* TYPE  */
  YYSYMBOL_CHAR = 7,                       /* CHAR  */
  YYSYMBOL_FLOAT = 8,                      /* FLOAT  */
  YYSYMBOL_DPLUS = 9,                      /* DPLUS  */
  YYSYMBOL_DMINUS = 10,                    /* DMINUS  */
  YYSYMBOL_GE = 11,                        /* GE  */
  YYSYMBOL_GT = 12,                        /* GT  */
  YYSYMBOL_LE = 13,                        /* LE  */
  YYSYMBOL_LP = 14,                        /* LP  */
  YYSYMBOL_LT = 15,                        /* LT  */
  YYSYMBOL_NE = 16,                        /* NE  */
  YYSYMBOL_RP = 17,                        /* RP  */
  YYSYMBOL_LB = 18,                        /* LB  */
  YYSYMBOL_RB = 19,                        /* RB  */
  YYSYMBOL_LC = 20,                        /* LC  */
  YYSYMBOL_RC = 21,                        /* RC  */
  YYSYMBOL_LA = 22,                        /* LA  */
  YYSYMBOL_RA = 23,                        /* RA  */
  YYSYMBOL_SEMI = 24,                      /* SEMI  */
  YYSYMBOL_COMMA = 25,                     /* COMMA  */
  YYSYMBOL_PLUS = 26,                      /* PLUS  */
  YYSYMBOL_MINUS = 27,                     /* MINUS  */
  YYSYMBOL_STAR = 28,                      /* STAR  */
  YYSYMBOL_DIV = 29,                       /* DIV  */
  YYSYMBOL_ASSIGNOP = 30,                  /* ASSIGNOP  */
  YYSYMBOL_AND = 31,                       /* AND  */
  YYSYMBOL_OR = 32,                        /* OR  */
  YYSYMBOL_NOT = 33,                       /* NOT  */
  YYSYMBOL_IF = 34,                        /* IF  */
  YYSYMBOL_ELSE = 35,                      /* ELSE  */
  YYSYMBOL_WHILE = 36,                     /* WHILE  */
  YYSYMBOL_RETURN = 37,                    /* RETURN  */
  YYSYMBOL_STRUCT = 38,                    /* STRUCT  */
  YYSYMBOL_FOR = 39,                       /* FOR  */
  YYSYMBOL_SWITCH = 40,                    /* SWITCH  */
  YYSYMBOL_CASE = 41,                      /* CASE  */
  YYSYMBOL_COLON = 42,                     /* COLON  */
  YYSYMBOL_DEFAULT = 43,                   /* DEFAULT  */
  YYSYMBOL_CONTINUE = 44,                  /* CONTINUE  */
  YYSYMBOL_BREAK = 45,                     /* BREAK  */
  YYSYMBOL_EXT_DEF_LIST = 46,              /* EXT_DEF_LIST  */
  YYSYMBOL_EXT_VAR_DEF = 47,               /* EXT_VAR_DEF  */
  YYSYMBOL_FUNC_DEF = 48,                  /* FUNC_DEF  */
  YYSYMBOL_FUNC_DEC = 49,                  /* FUNC_DEC  */
  YYSYMBOL_EXT_DEC_LIST = 50,              /* EXT_DEC_LIST  */
  YYSYMBOL_PARAM_LIST = 51,                /* PARAM_LIST  */
  YYSYMBOL_PARAM_DEC = 52,                 /* PARAM_DEC  */
  YYSYMBOL_VAR_DEF = 53,                   /* VAR_DEF  */
  YYSYMBOL_DEC_LIST = 54,                  /* DEC_LIST  */
  YYSYMBOL_DEF_LIST = 55,                  /* DEF_LIST  */
  YYSYMBOL_COMP_STM = 56,                  /* COMP_STM  */
  YYSYMBOL_STM_LIST = 57,                  /* STM_LIST  */
  YYSYMBOL_EXP_STMT = 58,                  /* EXP_STMT  */
  YYSYMBOL_IF_THEN = 59,                   /* IF_THEN  */
  YYSYMBOL_IF_THEN_ELSE = 60,              /* IF_THEN_ELSE  */
  YYSYMBOL_FUNC_CALL = 61,                 /* FUNC_CALL  */
  YYSYMBOL_ARGS = 62,                      /* ARGS  */
  YYSYMBOL_FUNCTION = 63,                  /* FUNCTION  */
  YYSYMBOL_PARAM = 64,                     /* PARAM  */
  YYSYMBOL_ARG = 65,                       /* ARG  */
  YYSYMBOL_CALL = 66,                      /* CALL  */
  YYSYMBOL_LABEL = 67,                     /* LABEL  */
  YYSYMBOL_GOTO = 68,                      /* GOTO  */
  YYSYMBOL_JLT = 69,                       /* JLT  */
  YYSYMBOL_JLE = 70,                       /* JLE  */
  YYSYMBOL_JGT = 71,                       /* JGT  */
  YYSYMBOL_JGE = 72,                       /* JGE  */
  YYSYMBOL_EQ = 73,                        /* EQ  */
  YYSYMBOL_NEQ = 74,                       /* NEQ  */
  YYSYMBOL_EXP_JLT = 75,                   /* EXP_JLT  */
  YYSYMBOL_EXP_JLE = 76,                   /* EXP_JLE  */
  YYSYMBOL_EXP_JGT = 77,                   /* EXP_JGT  */
  YYSYMBOL_EXP_JGE = 78,                   /* EXP_JGE  */
  YYSYMBOL_EXP_EQ = 79,                    /* EXP_EQ  */
  YYSYMBOL_EXP_NEQ = 80,                   /* EXP_NEQ  */
  YYSYMBOL_ARRAY_CALL = 81,                /* ARRAY_CALL  */
  YYSYMBOL_ARRAY_DEC = 82,                 /* ARRAY_DEC  */
  YYSYMBOL_ANNOTATION = 83,                /* ANNOTATION  */
  YYSYMBOL_ARRAY_POINTER = 84,             /* ARRAY_POINTER  */
  YYSYMBOL_DMINUS_L = 85,                  /* DMINUS_L  */
  YYSYMBOL_DMINUS_R = 86,                  /* DMINUS_R  */
  YYSYMBOL_DPLUS_L = 87,                   /* DPLUS_L  */
  YYSYMBOL_DPLUS_R = 88,                   /* DPLUS_R  */
  YYSYMBOL_UMINUS = 89,                    /* UMINUS  */
  YYSYMBOL_LOWER_THEN_ELSE = 90,           /* LOWER_THEN_ELSE  */
  YYSYMBOL_YYACCEPT = 91,                  /* $accept  */
  YYSYMBOL_program = 92,                   /* program  */
  YYSYMBOL_ExtDefList = 93,                /* ExtDefList  */
  YYSYMBOL_ExtDef = 94,                    /* ExtDef  */
  YYSYMBOL_Specifier = 95,                 /* Specifier  */
  YYSYMBOL_ExtDecList = 96,                /* ExtDecList  */
  YYSYMBOL_FuncDec = 97,                   /* FuncDec  */
  YYSYMBOL_VarList = 98,                   /* VarList  */
  YYSYMBOL_ParamDec = 99,                  /* ParamDec  */
  YYSYMBOL_CompSt = 100,                   /* CompSt  */
  YYSYMBOL_StmList = 101,                  /* StmList  */
  YYSYMBOL_Stm = 102,                      /* Stm  */
  YYSYMBOL_DefList = 103,                  /* DefList  */
  YYSYMBOL_Def = 104,                      /* Def  */
  YYSYMBOL_DecList = 105,                  /* DecList  */
  YYSYMBOL_Dec = 106,                      /* Dec  */
  YYSYMBOL_VarDec = 107,                   /* VarDec  */
  YYSYMBOL_Exp = 108,                      /* Exp  */
  YYSYMBOL_Args = 109                      /* Args  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  8
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   417

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  91
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  19
/* YYNRULES -- Number of rules.  */
#define YYNRULES  61
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  124

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   345


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    62,    62,    66,    67,    70,    72,    75,    77,    81,
      82,    86,    88,    92,    94,    97,   101,   104,   105,   108,
     110,   111,   113,   115,   117,   119,   121,   123,   127,   128,
     130,   132,   135,   137,   140,   141,   145,   148,   154,   157,
     159,   161,   165,   167,   169,   171,   173,   174,   176,   179,
     181,   183,   185,   189,   193,   195,   197,   199,   201,   203,
     206,   209
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "INT", "ID", "RELOP",
  "TYPE", "CHAR", "FLOAT", "DPLUS", "DMINUS", "GE", "GT", "LE", "LP", "LT",
  "NE", "RP", "LB", "RB", "LC", "RC", "LA", "RA", "SEMI", "COMMA", "PLUS",
  "MINUS", "STAR", "DIV", "ASSIGNOP", "AND", "OR", "NOT", "IF", "ELSE",
  "WHILE", "RETURN", "STRUCT", "FOR", "SWITCH", "CASE", "COLON", "DEFAULT",
  "CONTINUE", "BREAK", "EXT_DEF_LIST", "EXT_VAR_DEF", "FUNC_DEF",
  "FUNC_DEC", "EXT_DEC_LIST", "PARAM_LIST", "PARAM_DEC", "VAR_DEF",
  "DEC_LIST", "DEF_LIST", "COMP_STM", "STM_LIST", "EXP_STMT", "IF_THEN",
  "IF_THEN_ELSE", "FUNC_CALL", "ARGS", "FUNCTION", "PARAM", "ARG", "CALL",
  "LABEL", "GOTO", "JLT", "JLE", "JGT", "JGE", "EQ", "NEQ", "EXP_JLT",
  "EXP_JLE", "EXP_JGT", "EXP_JGE", "EXP_EQ", "EXP_NEQ", "ARRAY_CALL",
  "ARRAY_DEC", "ANNOTATION", "ARRAY_POINTER", "DMINUS_L", "DMINUS_R",
  "DPLUS_L", "DPLUS_R", "UMINUS", "LOWER_THEN_ELSE", "$accept", "program",
  "ExtDefList", "ExtDef", "Specifier", "ExtDecList", "FuncDec", "VarList",
  "ParamDec", "CompSt", "StmList", "Stm", "DefList", "Def", "DecList",
  "Dec", "VarDec", "Exp", "Args", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-43)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-29)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     109,    -2,   -43,    11,   -43,   109,     8,   -43,   -43,   -43,
       2,     0,     6,    87,    12,   -43,    47,   -43,    36,    43,
     -43,    43,    35,    46,    49,    43,    86,    47,    41,   -43,
     -43,    57,   -43,    70,   -43,    61,    74,   -13,   -43,    93,
     -43,   -43,    94,    94,    94,    94,    94,    97,   100,    94,
     102,   108,   110,   -43,    96,    86,   119,   -43,   -43,   -43,
     -43,    43,    94,    55,    69,    69,   147,   115,    69,    94,
      94,   162,    94,   -43,   -43,   -43,   -43,    94,   -43,   -43,
      94,   -43,    94,    94,    94,    94,    94,    94,    94,   -43,
     347,   -43,   190,   101,   -43,   218,   246,   -43,   261,   388,
     289,   126,   126,    69,    69,     5,   376,   362,    94,   -43,
      86,    86,    94,   -43,   -43,    91,   -43,   304,    86,    94,
     -43,   332,    86,   -43
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     8,     0,     2,     0,     0,     7,     1,     4,
      36,     0,     0,     9,     0,     5,     0,     6,     0,     0,
      12,     0,     0,    13,     0,     0,    17,     0,     0,    36,
      10,    15,    11,     0,    30,     0,    32,    34,    57,    56,
      59,    58,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    20,     0,    17,     0,    29,    37,    14,
      31,     0,     0,     0,    49,    51,     0,    47,    48,     0,
       0,     0,     0,    27,    26,    16,    18,     0,    50,    52,
       0,    19,     0,     0,     0,     0,     0,     0,     0,    33,
      35,    55,    61,     0,    46,     0,     0,    21,     0,    41,
       0,    42,    43,    44,    45,    38,    39,    40,     0,    54,
       0,     0,     0,    53,    60,    22,    24,     0,     0,     0,
      23,     0,     0,    25
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -43,   -43,   133,   -43,    -8,   120,   -43,   107,   -43,   129,
      98,    48,   134,   -43,    81,   -43,   -12,   -42,    52
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     3,     4,     5,     6,    11,    12,    22,    23,    53,
      54,    55,    26,    27,    35,    36,    13,    56,    93
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      64,    65,    66,    67,    68,    18,    21,    71,    25,    31,
      77,     8,    10,    37,    78,    79,    14,    62,     2,    25,
      90,    92,     7,    80,    15,    21,    16,    95,    96,    20,
      98,    82,    83,    84,    85,    99,    87,    88,   100,    28,
     101,   102,   103,   104,   105,   106,   107,    29,    24,    37,
     -28,   -28,    32,     2,   -28,   -28,   -28,   -28,    38,    39,
      58,   -28,    40,    41,    42,    43,    92,   -28,   -28,    44,
     117,    33,    91,    34,   -28,    18,     2,   121,    78,    79,
     -28,   -28,    45,   -28,   -28,    60,   -28,    80,    46,    38,
      39,   -28,   -28,    40,    41,    42,    43,    38,    39,    61,
      44,    40,    41,    42,    43,    18,    16,    63,    44,    -3,
       1,    69,    19,    45,    70,     2,    72,    75,   109,    46,
      47,    45,    48,    49,    77,    50,   118,    46,    78,    79,
      51,    52,    73,    80,    74,    78,    79,    80,     9,    30,
      59,    17,    89,    81,    80,    82,    83,    84,    85,    86,
      87,    88,    77,    76,    84,    85,    78,    79,   115,   116,
     114,    57,     0,     0,    94,    80,   120,    77,     0,     0,
     123,    78,    79,    82,    83,    84,    85,    86,    87,    88,
      80,     0,     0,     0,     0,     0,    97,     0,    82,    83,
      84,    85,    86,    87,    88,    77,     0,     0,     0,    78,
      79,     0,     0,     0,     0,     0,     0,     0,    80,     0,
       0,     0,     0,     0,     0,   108,    82,    83,    84,    85,
      86,    87,    88,    77,     0,     0,     0,    78,    79,     0,
       0,     0,     0,     0,     0,   110,    80,     0,     0,     0,
       0,     0,     0,     0,    82,    83,    84,    85,    86,    87,
      88,    77,     0,     0,     0,    78,    79,     0,     0,     0,
       0,     0,     0,   111,    80,     0,    77,     0,     0,     0,
      78,    79,    82,    83,    84,    85,    86,    87,    88,    80,
       0,     0,     0,     0,     0,   112,     0,    82,    83,    84,
      85,    86,    87,    88,    77,     0,     0,     0,    78,    79,
       0,     0,     0,     0,     0,     0,     0,    80,   113,    77,
       0,     0,     0,    78,    79,    82,    83,    84,    85,    86,
      87,    88,    80,     0,     0,     0,     0,     0,   119,     0,
      82,    83,    84,    85,    86,    87,    88,    77,     0,     0,
       0,    78,    79,     0,     0,     0,     0,     0,     0,   122,
      80,     0,    77,     0,     0,     0,    78,    79,    82,    83,
      84,    85,    86,    87,    88,    80,     0,    77,     0,     0,
       0,    78,    79,    82,    83,    84,    85,    86,    87,    88,
      80,    77,     0,     0,     0,    78,    79,     0,    82,    83,
      84,    85,     0,    87,    80,     0,     0,    78,    79,     0,
       0,     0,    82,    83,    84,    85,    80,     0,     0,     0,
       0,     0,     0,     0,    82,    83,    84,    85
};

static const yytype_int8 yycheck[] =
{
      42,    43,    44,    45,    46,    18,    14,    49,    16,    21,
       5,     0,     4,    25,     9,    10,    14,    30,     6,    27,
      62,    63,    24,    18,    24,    33,    20,    69,    70,    17,
      72,    26,    27,    28,    29,    77,    31,    32,    80,     3,
      82,    83,    84,    85,    86,    87,    88,     4,     1,    61,
       3,     4,    17,     6,     7,     8,     9,    10,     3,     4,
      19,    14,     7,     8,     9,    10,   108,    20,    21,    14,
     112,    25,    17,    24,    27,    18,     6,   119,     9,    10,
      33,    34,    27,    36,    37,    24,    39,    18,    33,     3,
       4,    44,    45,     7,     8,     9,    10,     3,     4,    25,
      14,     7,     8,     9,    10,    18,    20,    14,    14,     0,
       1,    14,    25,    27,    14,     6,    14,    21,    17,    33,
      34,    27,    36,    37,     5,    39,    35,    33,     9,    10,
      44,    45,    24,    18,    24,     9,    10,    18,     5,    19,
      33,    12,    61,    24,    18,    26,    27,    28,    29,    30,
      31,    32,     5,    55,    28,    29,     9,    10,   110,   111,
     108,    27,    -1,    -1,    17,    18,   118,     5,    -1,    -1,
     122,     9,    10,    26,    27,    28,    29,    30,    31,    32,
      18,    -1,    -1,    -1,    -1,    -1,    24,    -1,    26,    27,
      28,    29,    30,    31,    32,     5,    -1,    -1,    -1,     9,
      10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    18,    -1,
      -1,    -1,    -1,    -1,    -1,    25,    26,    27,    28,    29,
      30,    31,    32,     5,    -1,    -1,    -1,     9,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    17,    18,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    26,    27,    28,    29,    30,    31,
      32,     5,    -1,    -1,    -1,     9,    10,    -1,    -1,    -1,
      -1,    -1,    -1,    17,    18,    -1,     5,    -1,    -1,    -1,
       9,    10,    26,    27,    28,    29,    30,    31,    32,    18,
      -1,    -1,    -1,    -1,    -1,    24,    -1,    26,    27,    28,
      29,    30,    31,    32,     5,    -1,    -1,    -1,     9,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    18,    19,     5,
      -1,    -1,    -1,     9,    10,    26,    27,    28,    29,    30,
      31,    32,    18,    -1,    -1,    -1,    -1,    -1,    24,    -1,
      26,    27,    28,    29,    30,    31,    32,     5,    -1,    -1,
      -1,     9,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,
      18,    -1,     5,    -1,    -1,    -1,     9,    10,    26,    27,
      28,    29,    30,    31,    32,    18,    -1,     5,    -1,    -1,
      -1,     9,    10,    26,    27,    28,    29,    30,    31,    32,
      18,     5,    -1,    -1,    -1,     9,    10,    -1,    26,    27,
      28,    29,    -1,    31,    18,    -1,    -1,     9,    10,    -1,
      -1,    -1,    26,    27,    28,    29,    18,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    26,    27,    28,    29
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,     6,    92,    93,    94,    95,    24,     0,    93,
       4,    96,    97,   107,    14,    24,    20,   100,    18,    25,
      17,    95,    98,    99,     1,    95,   103,   104,     3,     4,
      96,   107,    17,    25,    24,   105,   106,   107,     3,     4,
       7,     8,     9,    10,    14,    27,    33,    34,    36,    37,
      39,    44,    45,   100,   101,   102,   108,   103,    19,    98,
      24,    25,    30,    14,   108,   108,   108,   108,   108,    14,
      14,   108,    14,    24,    24,    21,   101,     5,     9,    10,
      18,    24,    26,    27,    28,    29,    30,    31,    32,   105,
     108,    17,   108,   109,    17,   108,   108,    24,   108,   108,
     108,   108,   108,   108,   108,   108,   108,   108,    25,    17,
      17,    17,    24,    19,   109,   102,   102,   108,    35,    24,
     102,   108,    17,   102
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    91,    92,    93,    93,    94,    94,    94,    95,    96,
      96,    97,    97,    98,    98,    99,   100,   101,   101,   102,
     102,   102,   102,   102,   102,   102,   102,   102,   103,   103,
     103,   104,   105,   105,   106,   106,   107,   107,   108,   108,
     108,   108,   108,   108,   108,   108,   108,   108,   108,   108,
     108,   108,   108,   108,   108,   108,   108,   108,   108,   108,
     109,   109
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     0,     2,     3,     3,     2,     1,     1,
       3,     4,     3,     1,     3,     2,     4,     0,     2,     2,
       1,     3,     5,     7,     5,     9,     2,     2,     0,     2,
       2,     3,     1,     3,     1,     3,     1,     4,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     2,     2,
       2,     2,     2,     4,     4,     3,     1,     1,     1,     1,
       3,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF

/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)


/* YYLOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

# ifndef YYLOCATION_PRINT

#  if defined YY_LOCATION_PRINT

   /* Temporary convenience wrapper in case some people defined the
      undocumented and private YY_LOCATION_PRINT macros.  */
#   define YYLOCATION_PRINT(File, Loc)  YY_LOCATION_PRINT(File, *(Loc))

#  elif defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
}

#   define YYLOCATION_PRINT  yy_location_print_

    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT(File, Loc)  YYLOCATION_PRINT(File, &(Loc))

#  else

#   define YYLOCATION_PRINT(File, Loc) ((void) 0)
    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT  YYLOCATION_PRINT

#  endif
# endif /* !defined YYLOCATION_PRINT */


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (yylocationp);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  YYLOCATION_PRINT (yyo, yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yykind, yyvaluep, yylocationp);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)],
                       &(yylsp[(yyi + 1) - (yynrhs)]));
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YY_USE (yyvaluep);
  YY_USE (yylocationp);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

    /* The location stack: array, bottom, top.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls = yylsa;
    YYLTYPE *yylsp = yyls;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[3];



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  yylsp[0] = yylloc;
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      yyerror_range[1] = yylloc;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* program: ExtDefList  */
#line 62 "parser.y"
                       {display((yyvsp[0].ptr),0);
                        semantic_Analysis0((yyvsp[0].ptr));
                        }
#line 1445 "parser.tab.c"
    break;

  case 3: /* ExtDefList: %empty  */
#line 66 "parser.y"
            {(yyval.ptr)=NULL;}
#line 1451 "parser.tab.c"
    break;

  case 4: /* ExtDefList: ExtDef ExtDefList  */
#line 67 "parser.y"
                            {(yyval.ptr)=(ASTNode *)malloc(sizeof(ASTNode)); (yyval.ptr)->kind=EXT_DEF_LIST;
                               (yyval.ptr)->pos=yylineno;   (yyval.ptr)->Def=(yyvsp[-1].ptr);(yyval.ptr)->DefList=(yyvsp[0].ptr);}
#line 1458 "parser.tab.c"
    break;

  case 5: /* ExtDef: Specifier ExtDecList SEMI  */
#line 70 "parser.y"
                                      {(yyval.ptr)=(ASTNode *)malloc(sizeof(ASTNode)); (yyval.ptr)->kind=EXT_VAR_DEF;
                               (yyval.ptr)->pos=yylineno;   (yyval.ptr)->Specifier=(yyvsp[-2].ptr);(yyval.ptr)->DecList=(yyvsp[-1].ptr);}
#line 1465 "parser.tab.c"
    break;

  case 6: /* ExtDef: Specifier FuncDec CompSt  */
#line 72 "parser.y"
                                     {(yyval.ptr)=(ASTNode *)malloc(sizeof(ASTNode)); (yyval.ptr)->kind=FUNC_DEF;  
                                (yyval.ptr)->Specifier=(yyvsp[-2].ptr);(yyval.ptr)->FuncDec=(yyvsp[-1].ptr);(yyval.ptr)->Body=(yyvsp[0].ptr);
		(yyval.ptr)->pos=(yyval.ptr)->Body->pos=(yyval.ptr)->Specifier->pos;  }
#line 1473 "parser.tab.c"
    break;

  case 7: /* ExtDef: error SEMI  */
#line 75 "parser.y"
                       {(yyval.ptr)=NULL;}
#line 1479 "parser.tab.c"
    break;

  case 8: /* Specifier: TYPE  */
#line 77 "parser.y"
                    {(yyval.ptr)=(ASTNode *)malloc(sizeof(ASTNode)); (yyval.ptr)->kind=TYPE;             //生成类型结点，目前仅基本类型
	             (yyval.ptr)->pos=yylineno; strcpy((yyval.ptr)->type_id,(yyvsp[0].type_id));(yyval.ptr)->type=!strcmp((yyvsp[0].type_id),"int")?INT:FLOAT;}
#line 1486 "parser.tab.c"
    break;

  case 9: /* ExtDecList: VarDec  */
#line 81 "parser.y"
                         {(yyval.ptr)=(yyvsp[0].ptr);}
#line 1492 "parser.tab.c"
    break;

  case 10: /* ExtDecList: VarDec COMMA ExtDecList  */
#line 82 "parser.y"
                                     {(yyval.ptr)=(ASTNode *)malloc(sizeof(ASTNode)); (yyval.ptr)->kind=EXT_DEC_LIST;
                                                           (yyval.ptr)->pos=yylineno;   (yyval.ptr)->Dec=(yyvsp[-2].ptr);(yyval.ptr)->DecList=(yyvsp[0].ptr);}
#line 1499 "parser.tab.c"
    break;

  case 11: /* FuncDec: ID LP VarList RP  */
#line 86 "parser.y"
                              {(yyval.ptr)=(ASTNode *)malloc(sizeof(ASTNode)); (yyval.ptr)->kind=FUNC_DEC;
                               (yyval.ptr)->pos=yylineno;   strcpy((yyval.ptr)->type_id,(yyvsp[-3].type_id)); (yyval.ptr)->ParamList=(yyvsp[-1].ptr);}
#line 1506 "parser.tab.c"
    break;

  case 12: /* FuncDec: ID LP RP  */
#line 88 "parser.y"
                    {(yyval.ptr)=(ASTNode *)malloc(sizeof(ASTNode)); (yyval.ptr)->kind=FUNC_DEC;
                               (yyval.ptr)->pos=yylineno;   strcpy((yyval.ptr)->type_id,(yyvsp[-2].type_id)); (yyval.ptr)->ParamList=NULL;}
#line 1513 "parser.tab.c"
    break;

  case 13: /* VarList: ParamDec  */
#line 92 "parser.y"
                   {(yyval.ptr)=(ASTNode *)malloc(sizeof(ASTNode)); (yyval.ptr)->kind=PARAM_LIST;
                               (yyval.ptr)->pos=yylineno;   (yyval.ptr)->Param=(yyvsp[0].ptr);(yyval.ptr)->ParamList=NULL;}
#line 1520 "parser.tab.c"
    break;

  case 14: /* VarList: ParamDec COMMA VarList  */
#line 94 "parser.y"
                                   {(yyval.ptr)=(ASTNode *)malloc(sizeof(ASTNode)); (yyval.ptr)->kind=PARAM_LIST;
                               (yyval.ptr)->pos=yylineno;   (yyval.ptr)->Param=(yyvsp[-2].ptr);(yyval.ptr)->ParamList=(yyvsp[0].ptr);}
#line 1527 "parser.tab.c"
    break;

  case 15: /* ParamDec: Specifier VarDec  */
#line 97 "parser.y"
                            {(yyval.ptr)=(ASTNode *)malloc(sizeof(ASTNode)); (yyval.ptr)->kind=PARAM_DEC;
                                                (yyval.ptr)->pos=yylineno;   (yyval.ptr)->Specifier=(yyvsp[-1].ptr);(yyval.ptr)->ID=(yyvsp[0].ptr);}
#line 1534 "parser.tab.c"
    break;

  case 16: /* CompSt: LC DefList StmList RC  */
#line 101 "parser.y"
                                {(yyval.ptr)=(ASTNode *)malloc(sizeof(ASTNode)); (yyval.ptr)->kind=COMP_STM; 
                                                (yyval.ptr)->pos=(yyvsp[-2].ptr)?(yyvsp[-2].ptr)->pos:((yyvsp[-1].ptr)?(yyvsp[-1].ptr)->pos:yylineno);   (yyval.ptr)->DefList=(yyvsp[-2].ptr);(yyval.ptr)->StmList=(yyvsp[-1].ptr);}
#line 1541 "parser.tab.c"
    break;

  case 17: /* StmList: %empty  */
#line 104 "parser.y"
         {(yyval.ptr)=NULL; }
#line 1547 "parser.tab.c"
    break;

  case 18: /* StmList: Stm StmList  */
#line 105 "parser.y"
                         {(yyval.ptr)=(ASTNode *)malloc(sizeof(ASTNode)); (yyval.ptr)->kind=STM_LIST;  
                                      if((yyvsp[-1].ptr)) (yyval.ptr)->pos=(yyvsp[-1].ptr)->pos;else (yyval.ptr)->pos=yylineno;   (yyval.ptr)->Stm=(yyvsp[-1].ptr);(yyval.ptr)->StmList=(yyvsp[0].ptr);}
#line 1554 "parser.tab.c"
    break;

  case 19: /* Stm: Exp SEMI  */
#line 108 "parser.y"
                                        {(yyval.ptr)=(ASTNode *)malloc(sizeof(ASTNode)); (yyval.ptr)->kind=EXP_STMT; 
                                                (yyval.ptr)->pos=yylineno;   (yyval.ptr)->Exp1=(yyvsp[-1].ptr);}
#line 1561 "parser.tab.c"
    break;

  case 20: /* Stm: CompSt  */
#line 110 "parser.y"
                                        {(yyval.ptr)=(yyvsp[0].ptr);   }
#line 1567 "parser.tab.c"
    break;

  case 21: /* Stm: RETURN Exp SEMI  */
#line 111 "parser.y"
                                        {(yyval.ptr)=(ASTNode *)malloc(sizeof(ASTNode)); (yyval.ptr)->kind=RETURN; 
                                                (yyval.ptr)->pos=yylineno;   (yyval.ptr)->Exp1=(yyvsp[-1].ptr);}
#line 1574 "parser.tab.c"
    break;

  case 22: /* Stm: IF LP Exp RP Stm  */
#line 113 "parser.y"
                                                        {(yyval.ptr)=(ASTNode *)malloc(sizeof(ASTNode)); (yyval.ptr)->kind=IF_THEN;
                                                                (yyval.ptr)->pos=(yyvsp[-2].ptr)->pos;   (yyval.ptr)->Cond=(yyvsp[-2].ptr); (yyval.ptr)->IfStm=(yyvsp[0].ptr);}
#line 1581 "parser.tab.c"
    break;

  case 23: /* Stm: IF LP Exp RP Stm ELSE Stm  */
#line 115 "parser.y"
                                                        {(yyval.ptr)=(ASTNode *)malloc(sizeof(ASTNode)); (yyval.ptr)->kind=IF_THEN_ELSE;
                                                                (yyval.ptr)->pos=(yyvsp[-4].ptr)->pos;   (yyval.ptr)->Cond=(yyvsp[-4].ptr); (yyval.ptr)->IfStm=(yyvsp[-2].ptr);(yyval.ptr)->ElseStm=(yyvsp[0].ptr);}
#line 1588 "parser.tab.c"
    break;

  case 24: /* Stm: WHILE LP Exp RP Stm  */
#line 117 "parser.y"
                                        {(yyval.ptr)=(ASTNode *)malloc(sizeof(ASTNode)); (yyval.ptr)->kind=WHILE;
                                               (yyval.ptr)->pos=(yyvsp[-2].ptr)->pos;   (yyval.ptr)->Cond=(yyvsp[-2].ptr); (yyval.ptr)->Body=(yyvsp[0].ptr);}
#line 1595 "parser.tab.c"
    break;

  case 25: /* Stm: FOR LP Exp SEMI Exp SEMI Exp RP Stm  */
#line 119 "parser.y"
                                                        {(yyval.ptr)=(ASTNode *)malloc(sizeof(ASTNode)); (yyval.ptr)->kind=FOR;
                                                                (yyval.ptr)->pos=(yyvsp[-6].ptr)->pos;   (yyval.ptr)->Exp1=(yyvsp[-6].ptr);(yyval.ptr)->Exp2=(yyvsp[-4].ptr);(yyval.ptr)->Exp3=(yyvsp[-2].ptr);(yyval.ptr)->Body=(yyvsp[0].ptr);}
#line 1602 "parser.tab.c"
    break;

  case 26: /* Stm: BREAK SEMI  */
#line 121 "parser.y"
                                                {(yyval.ptr)=(ASTNode *)malloc(sizeof(ASTNode)); (yyval.ptr)->kind=BREAK;
                                                        (yyval.ptr)->pos=yylineno; }
#line 1609 "parser.tab.c"
    break;

  case 27: /* Stm: CONTINUE SEMI  */
#line 123 "parser.y"
                                                {(yyval.ptr)=(ASTNode *)malloc(sizeof(ASTNode)); (yyval.ptr)->kind=CONTINUE;
                                                        (yyval.ptr)->pos=yylineno; }
#line 1616 "parser.tab.c"
    break;

  case 28: /* DefList: %empty  */
#line 127 "parser.y"
         {(yyval.ptr)=NULL; }
#line 1622 "parser.tab.c"
    break;

  case 29: /* DefList: Def DefList  */
#line 128 "parser.y"
                           {(yyval.ptr)=(ASTNode *)malloc(sizeof(ASTNode)); (yyval.ptr)->kind=DEF_LIST;   
                    if ((yyvsp[-1].ptr)) (yyval.ptr)->pos=(yyvsp[-1].ptr)->pos; else (yyval.ptr)->pos=yylineno;     (yyval.ptr)->Def=(yyvsp[-1].ptr);(yyval.ptr)->DefList=(yyvsp[0].ptr);}
#line 1629 "parser.tab.c"
    break;

  case 30: /* DefList: error SEMI  */
#line 130 "parser.y"
                       {(yyval.ptr)=NULL;}
#line 1635 "parser.tab.c"
    break;

  case 31: /* Def: Specifier DecList SEMI  */
#line 132 "parser.y"
                                {(yyval.ptr)=(ASTNode *)malloc(sizeof(ASTNode)); (yyval.ptr)->kind=VAR_DEF;  
                                          (yyval.ptr)->pos=yylineno;   (yyval.ptr)->Specifier=(yyvsp[-2].ptr);(yyval.ptr)->DecList=(yyvsp[-1].ptr);}
#line 1642 "parser.tab.c"
    break;

  case 32: /* DecList: Dec  */
#line 135 "parser.y"
             {(yyval.ptr)=(ASTNode *)malloc(sizeof(ASTNode)); (yyval.ptr)->kind=DEC_LIST;
                                          (yyval.ptr)->pos=yylineno;   (yyval.ptr)->Dec=(yyvsp[0].ptr);(yyval.ptr)->DecList=NULL;}
#line 1649 "parser.tab.c"
    break;

  case 33: /* DecList: Dec COMMA DecList  */
#line 137 "parser.y"
                              {(yyval.ptr)=(ASTNode *)malloc(sizeof(ASTNode)); (yyval.ptr)->kind=DEC_LIST;
                                          (yyval.ptr)->pos=yylineno;   (yyval.ptr)->Dec=(yyvsp[-2].ptr);(yyval.ptr)->DecList=(yyvsp[0].ptr);}
#line 1656 "parser.tab.c"
    break;

  case 34: /* Dec: VarDec  */
#line 140 "parser.y"
                {(yyval.ptr)=(yyvsp[0].ptr);}
#line 1662 "parser.tab.c"
    break;

  case 35: /* Dec: VarDec ASSIGNOP Exp  */
#line 141 "parser.y"
                               {(yyval.ptr)=(ASTNode *)malloc(sizeof(ASTNode)); (yyval.ptr)->kind=ASSIGNOP;
                                          (yyval.ptr)->pos=yylineno;   (yyval.ptr)->Dec=(yyvsp[-2].ptr);(yyval.ptr)->Exp2=(yyvsp[0].ptr);}
#line 1669 "parser.tab.c"
    break;

  case 36: /* VarDec: ID  */
#line 145 "parser.y"
                    {(yyval.ptr)=(ASTNode *)malloc(sizeof(ASTNode)); (yyval.ptr)->kind=ID;
                        (yyval.ptr)->pos=yylineno; strcpy((yyval.ptr)->type_id,(yyvsp[0].type_id));}
#line 1676 "parser.tab.c"
    break;

  case 37: /* VarDec: VarDec LB INT RB  */
#line 148 "parser.y"
                          {(yyval.ptr)=(ASTNode*)malloc(sizeof(ASTNode)); (yyval.ptr)->kind=ARRAY_DEC;
                                (yyval.ptr)->pos=yylineno; (yyval.ptr)->Dec=(yyvsp[-3].ptr); (yyval.ptr)->type_int=(yyvsp[-1].type_int);}
#line 1683 "parser.tab.c"
    break;

  case 38: /* Exp: Exp ASSIGNOP Exp  */
#line 154 "parser.y"
                          {(yyval.ptr)=(ASTNode *)malloc(sizeof(ASTNode)); (yyval.ptr)->kind=ASSIGNOP;
                                             (yyval.ptr)->pos=yylineno;   (yyval.ptr)->Exp1=(yyvsp[-2].ptr);(yyval.ptr)->Exp2=(yyvsp[0].ptr);strcpy((yyval.ptr)->type_id,"ASSIGNOP");}
#line 1690 "parser.tab.c"
    break;

  case 39: /* Exp: Exp AND Exp  */
#line 157 "parser.y"
                        {(yyval.ptr)=(ASTNode *)malloc(sizeof(ASTNode)); (yyval.ptr)->kind=AND;
                                        (yyval.ptr)->pos=yylineno;   (yyval.ptr)->Exp1=(yyvsp[-2].ptr);(yyval.ptr)->Exp2=(yyvsp[0].ptr);strcpy((yyval.ptr)->type_id,"AND");}
#line 1697 "parser.tab.c"
    break;

  case 40: /* Exp: Exp OR Exp  */
#line 159 "parser.y"
                        {(yyval.ptr)=(ASTNode *)malloc(sizeof(ASTNode)); (yyval.ptr)->kind=OR;
                                        (yyval.ptr)->pos=yylineno;   (yyval.ptr)->Exp1=(yyvsp[-2].ptr);(yyval.ptr)->Exp2=(yyvsp[0].ptr);strcpy((yyval.ptr)->type_id,"OR");}
#line 1704 "parser.tab.c"
    break;

  case 41: /* Exp: Exp RELOP Exp  */
#line 161 "parser.y"
                        {(yyval.ptr)=(ASTNode *)malloc(sizeof(ASTNode)); (yyval.ptr)->kind=RELOP;
                                        (yyval.ptr)->pos=yylineno;   (yyval.ptr)->Exp1=(yyvsp[-2].ptr);(yyval.ptr)->Exp2=(yyvsp[0].ptr);
                                        strcpy((yyval.ptr)->type_id,(yyvsp[-1].type_id));}
#line 1712 "parser.tab.c"
    break;

  case 42: /* Exp: Exp PLUS Exp  */
#line 165 "parser.y"
                        {(yyval.ptr)=(ASTNode *)malloc(sizeof(ASTNode)); (yyval.ptr)->kind=PLUS;
                                        (yyval.ptr)->pos=yylineno;   (yyval.ptr)->Exp1=(yyvsp[-2].ptr);(yyval.ptr)->Exp2=(yyvsp[0].ptr);strcpy((yyval.ptr)->type_id,"PLUS");}
#line 1719 "parser.tab.c"
    break;

  case 43: /* Exp: Exp MINUS Exp  */
#line 167 "parser.y"
                        {(yyval.ptr)=(ASTNode *)malloc(sizeof(ASTNode)); (yyval.ptr)->kind=MINUS;
                                        (yyval.ptr)->pos=yylineno;   (yyval.ptr)->Exp1=(yyvsp[-2].ptr);(yyval.ptr)->Exp2=(yyvsp[0].ptr);strcpy((yyval.ptr)->type_id,"MINUS");}
#line 1726 "parser.tab.c"
    break;

  case 44: /* Exp: Exp STAR Exp  */
#line 169 "parser.y"
                        {(yyval.ptr)=(ASTNode *)malloc(sizeof(ASTNode)); (yyval.ptr)->kind=STAR;
                                        (yyval.ptr)->pos=yylineno;   (yyval.ptr)->Exp1=(yyvsp[-2].ptr);(yyval.ptr)->Exp2=(yyvsp[0].ptr);strcpy((yyval.ptr)->type_id,"STAR");}
#line 1733 "parser.tab.c"
    break;

  case 45: /* Exp: Exp DIV Exp  */
#line 171 "parser.y"
                        {(yyval.ptr)=(ASTNode *)malloc(sizeof(ASTNode)); (yyval.ptr)->kind=DIV;
                                        (yyval.ptr)->pos=yylineno;   (yyval.ptr)->Exp1=(yyvsp[-2].ptr);(yyval.ptr)->Exp2=(yyvsp[0].ptr);strcpy((yyval.ptr)->type_id,"DIV");}
#line 1740 "parser.tab.c"
    break;

  case 46: /* Exp: LP Exp RP  */
#line 173 "parser.y"
                        {(yyval.ptr)=(yyvsp[-1].ptr);}
#line 1746 "parser.tab.c"
    break;

  case 47: /* Exp: MINUS Exp  */
#line 174 "parser.y"
                                  {(yyval.ptr)=(ASTNode *)malloc(sizeof(ASTNode)); (yyval.ptr)->kind=UMINUS;
                                        (yyval.ptr)->pos=yylineno;   (yyval.ptr)->Exp1=(yyvsp[0].ptr);strcpy((yyval.ptr)->type_id,"UMINUS");}
#line 1753 "parser.tab.c"
    break;

  case 48: /* Exp: NOT Exp  */
#line 176 "parser.y"
                        {(yyval.ptr)=(ASTNode *)malloc(sizeof(ASTNode)); (yyval.ptr)->kind=NOT;
                                        (yyval.ptr)->pos=yylineno;   (yyval.ptr)->Exp1=(yyvsp[0].ptr);strcpy((yyval.ptr)->type_id,"NOT");}
#line 1760 "parser.tab.c"
    break;

  case 49: /* Exp: DPLUS Exp  */
#line 179 "parser.y"
                                {(yyval.ptr)=(ASTNode *)malloc(sizeof(ASTNode)); (yyval.ptr)->kind=DPLUS_L;strcpy((yyval.ptr)->type_id,"DPLUS_L");
                                        (yyval.ptr)->pos=yylineno;   (yyval.ptr)->Exp1=(yyvsp[0].ptr);}
#line 1767 "parser.tab.c"
    break;

  case 50: /* Exp: Exp DPLUS  */
#line 181 "parser.y"
                                {(yyval.ptr)=(ASTNode *)malloc(sizeof(ASTNode)); (yyval.ptr)->kind=DPLUS_R;strcpy((yyval.ptr)->type_id,"DPLUS_R");
                                        (yyval.ptr)->pos=yylineno;   (yyval.ptr)->Exp1=(yyvsp[-1].ptr);}
#line 1774 "parser.tab.c"
    break;

  case 51: /* Exp: DMINUS Exp  */
#line 183 "parser.y"
                                {(yyval.ptr)=(ASTNode *)malloc(sizeof(ASTNode)); (yyval.ptr)->kind=DMINUS_L; strcpy((yyval.ptr)->type_id,"DMINUS_L");
                                        (yyval.ptr)->pos=yylineno;  (yyval.ptr)->Exp1=(yyvsp[0].ptr);}
#line 1781 "parser.tab.c"
    break;

  case 52: /* Exp: Exp DMINUS  */
#line 185 "parser.y"
                                {(yyval.ptr)=(ASTNode *)malloc(sizeof(ASTNode)); (yyval.ptr)->kind=DMINUS_R; strcpy((yyval.ptr)->type_id,"DMINUS_R");
                                        (yyval.ptr)->pos=yylineno;  (yyval.ptr)->Exp1=(yyvsp[-1].ptr);}
#line 1788 "parser.tab.c"
    break;

  case 53: /* Exp: Exp LB Exp RB  */
#line 189 "parser.y"
                           {(yyval.ptr)=(ASTNode *)malloc(sizeof(ASTNode)); (yyval.ptr)->kind=ARRAY_CALL;
                                (yyval.ptr)->pos=yylineno;   (yyval.ptr)->Exp1=(yyvsp[-3].ptr);(yyval.ptr)->Exp2=(yyvsp[-1].ptr);}
#line 1795 "parser.tab.c"
    break;

  case 54: /* Exp: ID LP Args RP  */
#line 193 "parser.y"
                                {(yyval.ptr)=(ASTNode *)malloc(sizeof(ASTNode)); (yyval.ptr)->kind=FUNC_CALL;
                                        (yyval.ptr)->pos=yylineno; strcpy((yyval.ptr)->type_id,(yyvsp[-3].type_id));  (yyval.ptr)->Args=(yyvsp[-1].ptr);}
#line 1802 "parser.tab.c"
    break;

  case 55: /* Exp: ID LP RP  */
#line 195 "parser.y"
                                {(yyval.ptr)=(ASTNode *)malloc(sizeof(ASTNode)); (yyval.ptr)->kind=FUNC_CALL;
                                        (yyval.ptr)->pos=yylineno; strcpy((yyval.ptr)->type_id,(yyvsp[-2].type_id));  (yyval.ptr)->Args=NULL;}
#line 1809 "parser.tab.c"
    break;

  case 56: /* Exp: ID  */
#line 197 "parser.y"
                                {(yyval.ptr)=(ASTNode *)malloc(sizeof(ASTNode)); (yyval.ptr)->kind=ID;
                                        (yyval.ptr)->pos=yylineno;  strcpy((yyval.ptr)->type_id,(yyvsp[0].type_id));}
#line 1816 "parser.tab.c"
    break;

  case 57: /* Exp: INT  */
#line 199 "parser.y"
                        {(yyval.ptr)=(ASTNode *)malloc(sizeof(ASTNode)); (yyval.ptr)->kind=INT;
                                (yyval.ptr)->pos=yylineno;  (yyval.ptr)->type=INT;(yyval.ptr)->type_int=(yyvsp[0].type_int);}
#line 1823 "parser.tab.c"
    break;

  case 58: /* Exp: FLOAT  */
#line 201 "parser.y"
                        {(yyval.ptr)=(ASTNode *)malloc(sizeof(ASTNode)); (yyval.ptr)->kind=FLOAT;
                                (yyval.ptr)->pos=yylineno; (yyval.ptr)->type=FLOAT; (yyval.ptr)->type_float=(yyvsp[0].type_float);}
#line 1830 "parser.tab.c"
    break;

  case 59: /* Exp: CHAR  */
#line 203 "parser.y"
                        {(yyval.ptr)=(ASTNode *)malloc(sizeof(ASTNode)); (yyval.ptr)->kind=CHAR;
                                (yyval.ptr)->pos=yylineno; (yyval.ptr)->type=FLOAT; strcpy((yyval.ptr)->type_char, (yyvsp[0].type_id));}
#line 1837 "parser.tab.c"
    break;

  case 60: /* Args: Exp COMMA Args  */
#line 206 "parser.y"
                           {(yyval.ptr)=(ASTNode *)malloc(sizeof(ASTNode)); (yyval.ptr)->kind=ARGS;
                                               (yyval.ptr)->pos=yylineno;  (yyval.ptr)->Exp1=(yyvsp[-2].ptr);(yyval.ptr)->Args=(yyvsp[0].ptr);}
#line 1844 "parser.tab.c"
    break;

  case 61: /* Args: Exp  */
#line 209 "parser.y"
                          {(yyval.ptr)=(ASTNode *)malloc(sizeof(ASTNode)); (yyval.ptr)->kind=ARGS;
                               (yyval.ptr)->pos=yylineno;  (yyval.ptr)->Exp1=(yyvsp[0].ptr);(yyval.ptr)->Args=NULL;}
#line 1851 "parser.tab.c"
    break;


#line 1855 "parser.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  yyerror_range[1] = yylloc;
  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval, &yylloc);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  ++yylsp;
  YYLLOC_DEFAULT (*yylsp, yyerror_range, 2);

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 214 "parser.y"


int main(int argc, char *argv[]){
	yyin=fopen(argv[1],"r");
	if (!yyin) return 0;
        strcpy(filename, argv[1]);
        printf("filename:%s\n", filename);
	yylineno=1;
	yyparse();
	return 0;
}
#include<stdarg.h>
void yyerror(const char* fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    fprintf(stderr, "Grammar Error at Line %d Column %d: ", yylloc.first_line,yylloc.first_column);
    vfprintf(stderr, fmt, ap);
    fprintf(stderr, ".\n");
}
