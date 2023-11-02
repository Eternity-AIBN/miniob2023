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
#define YYPURE 2

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 2 "yacc_sql.y"


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

#include "common/log/log.h"
#include "common/lang/string.h"
#include "sql/parser/parse_defs.h"
#include "sql/parser/yacc_sql.hpp"
#include "sql/parser/lex_sql.h"
#include "sql/expr/expression.h"

using namespace std;

typedef struct TableAndCondition {
  std::vector<std::string> table_name;
  std::vector<ConditionSqlNode> condition_name;
} TableAndCondition;

typedef struct AttributeAndExpr {
  std::vector<std::string> attribute_name;
  std::vector<Expression *> exprs;
} AttributeAndExpr;

string token_name(const char *sql_string, YYLTYPE *llocp)
{
  return string(sql_string + llocp->first_column, llocp->last_column - llocp->first_column + 1);
}

int yyerror(YYLTYPE *llocp, const char *sql_string, ParsedSqlResult *sql_result, yyscan_t scanner, const char *msg)
{
  std::unique_ptr<ParsedSqlNode> error_sql_node = std::make_unique<ParsedSqlNode>(SCF_ERROR);
  error_sql_node->error.error_msg = msg;
  error_sql_node->error.line = llocp->first_line;
  error_sql_node->error.column = llocp->first_column;
  sql_result->add_sql_node(std::move(error_sql_node));
  return 0;
}

ArithmeticExpr *create_arithmetic_expression(ArithmeticExpr::Type type,
                                             Expression *left,
                                             Expression *right,
                                             const char *sql_string,
                                             YYLTYPE *llocp)
{
  ArithmeticExpr *expr = new ArithmeticExpr(type, left, right);
  expr->set_name(token_name(sql_string, llocp));
  return expr;
}


#line 125 "yacc_sql.cpp"

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

#include "yacc_sql.hpp"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_SEMICOLON = 3,                  /* SEMICOLON  */
  YYSYMBOL_CREATE = 4,                     /* CREATE  */
  YYSYMBOL_DROP = 5,                       /* DROP  */
  YYSYMBOL_TABLE = 6,                      /* TABLE  */
  YYSYMBOL_TABLES = 7,                     /* TABLES  */
  YYSYMBOL_INDEX = 8,                      /* INDEX  */
  YYSYMBOL_CALC = 9,                       /* CALC  */
  YYSYMBOL_SELECT = 10,                    /* SELECT  */
  YYSYMBOL_MAX = 11,                       /* MAX  */
  YYSYMBOL_MIN = 12,                       /* MIN  */
  YYSYMBOL_IN = 13,                        /* IN  */
  YYSYMBOL_EXISTS = 14,                    /* EXISTS  */
  YYSYMBOL_COUNT = 15,                     /* COUNT  */
  YYSYMBOL_AVG = 16,                       /* AVG  */
  YYSYMBOL_SUM = 17,                       /* SUM  */
  YYSYMBOL_DESC = 18,                      /* DESC  */
  YYSYMBOL_ASC = 19,                       /* ASC  */
  YYSYMBOL_SHOW = 20,                      /* SHOW  */
  YYSYMBOL_SYNC = 21,                      /* SYNC  */
  YYSYMBOL_INSERT = 22,                    /* INSERT  */
  YYSYMBOL_DELETE = 23,                    /* DELETE  */
  YYSYMBOL_UPDATE = 24,                    /* UPDATE  */
  YYSYMBOL_LBRACE = 25,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 26,                    /* RBRACE  */
  YYSYMBOL_COMMA = 27,                     /* COMMA  */
  YYSYMBOL_TRX_BEGIN = 28,                 /* TRX_BEGIN  */
  YYSYMBOL_TRX_COMMIT = 29,                /* TRX_COMMIT  */
  YYSYMBOL_TRX_ROLLBACK = 30,              /* TRX_ROLLBACK  */
  YYSYMBOL_INT_T = 31,                     /* INT_T  */
  YYSYMBOL_STRING_T = 32,                  /* STRING_T  */
  YYSYMBOL_FLOAT_T = 33,                   /* FLOAT_T  */
  YYSYMBOL_DATE_T = 34,                    /* DATE_T  */
  YYSYMBOL_HELP = 35,                      /* HELP  */
  YYSYMBOL_EXIT = 36,                      /* EXIT  */
  YYSYMBOL_UNIQUE = 37,                    /* UNIQUE  */
  YYSYMBOL_ORDER = 38,                     /* ORDER  */
  YYSYMBOL_BY = 39,                        /* BY  */
  YYSYMBOL_DOT = 40,                       /* DOT  */
  YYSYMBOL_INTO = 41,                      /* INTO  */
  YYSYMBOL_VALUES = 42,                    /* VALUES  */
  YYSYMBOL_FROM = 43,                      /* FROM  */
  YYSYMBOL_WHERE = 44,                     /* WHERE  */
  YYSYMBOL_INNER = 45,                     /* INNER  */
  YYSYMBOL_JOIN = 46,                      /* JOIN  */
  YYSYMBOL_AND = 47,                       /* AND  */
  YYSYMBOL_SET = 48,                       /* SET  */
  YYSYMBOL_ON = 49,                        /* ON  */
  YYSYMBOL_LOAD = 50,                      /* LOAD  */
  YYSYMBOL_DATA = 51,                      /* DATA  */
  YYSYMBOL_INFILE = 52,                    /* INFILE  */
  YYSYMBOL_EXPLAIN = 53,                   /* EXPLAIN  */
  YYSYMBOL_LIKE = 54,                      /* LIKE  */
  YYSYMBOL_NOT = 55,                       /* NOT  */
  YYSYMBOL_IS = 56,                        /* IS  */
  YYSYMBOL_NULLABLE = 57,                  /* NULLABLE  */
  YYSYMBOL_EQ = 58,                        /* EQ  */
  YYSYMBOL_LT = 59,                        /* LT  */
  YYSYMBOL_GT = 60,                        /* GT  */
  YYSYMBOL_LE = 61,                        /* LE  */
  YYSYMBOL_GE = 62,                        /* GE  */
  YYSYMBOL_NE = 63,                        /* NE  */
  YYSYMBOL_NUMBER = 64,                    /* NUMBER  */
  YYSYMBOL_FLOAT = 65,                     /* FLOAT  */
  YYSYMBOL_ID = 66,                        /* ID  */
  YYSYMBOL_DATE = 67,                      /* DATE  */
  YYSYMBOL_SSS = 68,                       /* SSS  */
  YYSYMBOL_69_ = 69,                       /* '+'  */
  YYSYMBOL_70_ = 70,                       /* '-'  */
  YYSYMBOL_71_ = 71,                       /* '*'  */
  YYSYMBOL_72_ = 72,                       /* '/'  */
  YYSYMBOL_UMINUS = 73,                    /* UMINUS  */
  YYSYMBOL_YYACCEPT = 74,                  /* $accept  */
  YYSYMBOL_commands = 75,                  /* commands  */
  YYSYMBOL_command_wrapper = 76,           /* command_wrapper  */
  YYSYMBOL_exit_stmt = 77,                 /* exit_stmt  */
  YYSYMBOL_help_stmt = 78,                 /* help_stmt  */
  YYSYMBOL_sync_stmt = 79,                 /* sync_stmt  */
  YYSYMBOL_begin_stmt = 80,                /* begin_stmt  */
  YYSYMBOL_commit_stmt = 81,               /* commit_stmt  */
  YYSYMBOL_rollback_stmt = 82,             /* rollback_stmt  */
  YYSYMBOL_drop_table_stmt = 83,           /* drop_table_stmt  */
  YYSYMBOL_show_tables_stmt = 84,          /* show_tables_stmt  */
  YYSYMBOL_desc_table_stmt = 85,           /* desc_table_stmt  */
  YYSYMBOL_create_index_stmt = 86,         /* create_index_stmt  */
  YYSYMBOL_id_list = 87,                   /* id_list  */
  YYSYMBOL_drop_index_stmt = 88,           /* drop_index_stmt  */
  YYSYMBOL_show_index_stmt = 89,           /* show_index_stmt  */
  YYSYMBOL_create_table_stmt = 90,         /* create_table_stmt  */
  YYSYMBOL_attr_def_list = 91,             /* attr_def_list  */
  YYSYMBOL_attr_def = 92,                  /* attr_def  */
  YYSYMBOL_number = 93,                    /* number  */
  YYSYMBOL_type = 94,                      /* type  */
  YYSYMBOL_insert_stmt = 95,               /* insert_stmt  */
  YYSYMBOL_row_value_list = 96,            /* row_value_list  */
  YYSYMBOL_value_list = 97,                /* value_list  */
  YYSYMBOL_value = 98,                     /* value  */
  YYSYMBOL_delete_stmt = 99,               /* delete_stmt  */
  YYSYMBOL_update_stmt = 100,              /* update_stmt  */
  YYSYMBOL_update_list = 101,              /* update_list  */
  YYSYMBOL_sub_select = 102,               /* sub_select  */
  YYSYMBOL_select_stmt = 103,              /* select_stmt  */
  YYSYMBOL_order_by_unit = 104,            /* order_by_unit  */
  YYSYMBOL_order_by_list = 105,            /* order_by_list  */
  YYSYMBOL_opt_order_by = 106,             /* opt_order_by  */
  YYSYMBOL_calc_stmt = 107,                /* calc_stmt  */
  YYSYMBOL_expression_list = 108,          /* expression_list  */
  YYSYMBOL_expression = 109,               /* expression  */
  YYSYMBOL_select_attr = 110,              /* select_attr  */
  YYSYMBOL_select_agg_attr = 111,          /* select_agg_attr  */
  YYSYMBOL_agg_op = 112,                   /* agg_op  */
  YYSYMBOL_rel_attr = 113,                 /* rel_attr  */
  YYSYMBOL_attr_list = 114,                /* attr_list  */
  YYSYMBOL_agg_rel_attr = 115,             /* agg_rel_attr  */
  YYSYMBOL_agg_attr_list = 116,            /* agg_attr_list  */
  YYSYMBOL_rel_list = 117,                 /* rel_list  */
  YYSYMBOL_rel_list_join = 118,            /* rel_list_join  */
  YYSYMBOL_inner_join_conditions = 119,    /* inner_join_conditions  */
  YYSYMBOL_where = 120,                    /* where  */
  YYSYMBOL_condition_list = 121,           /* condition_list  */
  YYSYMBOL_condition = 122,                /* condition  */
  YYSYMBOL_sub_select_for_in = 123,        /* sub_select_for_in  */
  YYSYMBOL_comp_op = 124,                  /* comp_op  */
  YYSYMBOL_load_data_stmt = 125,           /* load_data_stmt  */
  YYSYMBOL_explain_stmt = 126,             /* explain_stmt  */
  YYSYMBOL_set_variable_stmt = 127,        /* set_variable_stmt  */
  YYSYMBOL_opt_semicolon = 128             /* opt_semicolon  */
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
typedef yytype_int16 yy_state_t;

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

#if 1

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
#endif /* 1 */

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
#define YYFINAL  78
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   363

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  74
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  55
/* YYNRULES -- Number of rules.  */
#define YYNRULES  157
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  324

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   324


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
       2,     2,    71,    69,     2,    70,     2,    72,     2,     2,
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
      65,    66,    67,    68,    73
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   231,   231,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   263,   269,   274,   280,   286,   292,
     298,   305,   311,   319,   338,   361,   364,   377,   388,   396,
     415,   418,   431,   440,   449,   458,   467,   476,   487,   490,
     491,   492,   493,   496,   521,   524,   544,   547,   558,   562,
     566,   571,   576,   583,   595,   620,   623,   636,   641,   659,
     680,   705,   725,   748,   756,   767,   777,   787,   799,   813,
     816,   821,   830,   833,   839,   849,   854,   865,   868,   871,
     874,   877,   881,   884,   892,   899,   911,   923,   924,   925,
     926,   927,   931,   936,   947,   950,   963,   970,   976,   988,
     991,  1005,  1008,  1021,  1024,  1037,  1052,  1055,  1061,  1070,
    1073,  1079,  1082,  1087,  1094,  1107,  1120,  1133,  1146,  1159,
    1172,  1185,  1198,  1209,  1220,  1231,  1242,  1253,  1266,  1277,
    1286,  1299,  1312,  1330,  1348,  1370,  1371,  1372,  1373,  1374,
    1375,  1376,  1377,  1381,  1394,  1402,  1412,  1413
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "SEMICOLON", "CREATE",
  "DROP", "TABLE", "TABLES", "INDEX", "CALC", "SELECT", "MAX", "MIN", "IN",
  "EXISTS", "COUNT", "AVG", "SUM", "DESC", "ASC", "SHOW", "SYNC", "INSERT",
  "DELETE", "UPDATE", "LBRACE", "RBRACE", "COMMA", "TRX_BEGIN",
  "TRX_COMMIT", "TRX_ROLLBACK", "INT_T", "STRING_T", "FLOAT_T", "DATE_T",
  "HELP", "EXIT", "UNIQUE", "ORDER", "BY", "DOT", "INTO", "VALUES", "FROM",
  "WHERE", "INNER", "JOIN", "AND", "SET", "ON", "LOAD", "DATA", "INFILE",
  "EXPLAIN", "LIKE", "NOT", "IS", "NULLABLE", "EQ", "LT", "GT", "LE", "GE",
  "NE", "NUMBER", "FLOAT", "ID", "DATE", "SSS", "'+'", "'-'", "'*'", "'/'",
  "UMINUS", "$accept", "commands", "command_wrapper", "exit_stmt",
  "help_stmt", "sync_stmt", "begin_stmt", "commit_stmt", "rollback_stmt",
  "drop_table_stmt", "show_tables_stmt", "desc_table_stmt",
  "create_index_stmt", "id_list", "drop_index_stmt", "show_index_stmt",
  "create_table_stmt", "attr_def_list", "attr_def", "number", "type",
  "insert_stmt", "row_value_list", "value_list", "value", "delete_stmt",
  "update_stmt", "update_list", "sub_select", "select_stmt",
  "order_by_unit", "order_by_list", "opt_order_by", "calc_stmt",
  "expression_list", "expression", "select_attr", "select_agg_attr",
  "agg_op", "rel_attr", "attr_list", "agg_rel_attr", "agg_attr_list",
  "rel_list", "rel_list_join", "inner_join_conditions", "where",
  "condition_list", "condition", "sub_select_for_in", "comp_op",
  "load_data_stmt", "explain_stmt", "set_variable_stmt", "opt_semicolon", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-237)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     186,    28,    95,   162,    -2,   -49,    22,  -237,    11,    47,
      25,  -237,  -237,  -237,  -237,  -237,    44,    43,   186,    62,
      99,  -237,  -237,  -237,  -237,  -237,  -237,  -237,  -237,  -237,
    -237,  -237,  -237,  -237,  -237,  -237,  -237,  -237,  -237,  -237,
    -237,  -237,    45,    50,   111,    57,    69,   162,  -237,  -237,
    -237,  -237,  -237,   162,  -237,  -237,    36,  -237,  -237,  -237,
    -237,  -237,    96,  -237,   100,   115,   129,   138,   139,  -237,
    -237,   126,   113,   116,   135,   128,   146,  -237,  -237,  -237,
    -237,   187,   171,   145,  -237,   175,   -15,  -237,   162,   162,
     162,   162,   162,   165,   167,   172,     4,   174,  -237,   177,
    -237,   179,   195,   184,   180,   216,   182,   181,   185,   203,
     188,  -237,  -237,   -26,   -26,  -237,  -237,  -237,    -6,   226,
      27,   250,   138,   139,  -237,   254,    84,  -237,   224,  -237,
     244,   169,   259,   262,   222,  -237,   223,   245,   184,   184,
    -237,   227,  -237,  -237,  -237,   216,   265,    32,   278,    70,
     101,  -237,   247,   210,   289,  -237,  -237,  -237,  -237,    -7,
     181,   270,   231,   273,   226,   -19,   261,  -237,   274,   275,
      32,     8,   275,   277,   276,  -237,  -237,   114,    60,  -237,
    -237,  -237,  -237,  -237,  -237,   204,   114,    65,   192,    84,
     294,  -237,   279,   239,   243,   251,  -237,   259,  -237,   282,
     246,  -237,   264,    93,   184,   272,  -237,  -237,   216,   287,
     288,   280,   281,   283,  -237,   114,    32,   204,   258,  -237,
    -237,  -237,   198,   260,  -237,    32,  -237,  -237,  -237,    16,
     252,   184,  -237,  -237,   290,  -237,  -237,   253,   295,   282,
     256,    84,    84,   -19,  -237,   263,   275,   293,  -237,   266,
     267,   268,   174,   299,  -237,  -237,  -237,    32,  -237,  -237,
    -237,   301,   285,   292,   284,  -237,   123,   282,  -237,   304,
      93,    93,    93,  -237,    19,   309,  -237,  -237,   306,  -237,
     184,   184,   184,  -237,  -237,   311,  -237,   286,   291,   210,
     296,  -237,  -237,  -237,   -19,  -237,  -237,  -237,  -237,   297,
     263,   216,  -237,  -237,  -237,  -237,   184,   184,   279,  -237,
    -237,    53,  -237,   275,   312,   313,  -237,  -237,  -237,   314,
    -237,  -237,   293,  -237
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,    26,     0,     0,
       0,    27,    28,    29,    25,    24,     0,     0,     0,     0,
     156,    23,    22,    15,    16,    17,    18,     9,    10,    11,
      12,    14,    13,     8,     5,     7,     6,     4,     3,    19,
      20,    21,     0,     0,     0,     0,     0,     0,    62,    58,
      59,    60,    61,     0,    93,    84,    85,    97,    98,    99,
     100,   101,   102,    94,     0,     0,     0,   104,   109,    32,
      31,     0,     0,     0,     0,     0,     0,   154,     1,   157,
       2,     0,     0,     0,    30,     0,     0,    92,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    95,     0,
      96,     0,     0,   119,     0,     0,     0,     0,     0,     0,
       0,    91,    86,    87,    88,    89,    90,   103,   111,   111,
       0,     0,   104,   109,    38,     0,   121,    63,     0,   155,
       0,     0,    40,     0,     0,    37,     0,     0,   119,   119,
     107,     0,   106,   105,   110,     0,     0,     0,     0,     0,
       0,   120,   122,     0,     0,    49,    50,    51,    52,    43,
       0,     0,     0,     0,   111,   113,    82,    71,     0,    56,
       0,     0,    56,     0,     0,   152,   151,     0,     0,   145,
     146,   147,   148,   149,   150,     0,     0,     0,     0,   121,
       0,    67,    65,     0,     0,     0,    46,    40,    39,    35,
       0,   112,     0,   116,   119,     0,    70,   108,     0,     0,
       0,     0,     0,     0,   141,     0,     0,     0,     0,   133,
     125,   127,     0,     0,   132,     0,   124,   126,   123,     0,
       0,   119,   153,    48,     0,    47,    41,     0,     0,    35,
       0,     0,     0,   113,    72,    79,    56,    54,   139,     0,
       0,     0,     0,     0,   129,   131,   135,     0,   128,   130,
     134,     0,     0,     0,     0,    64,    42,    35,    33,     0,
     116,   116,   116,   114,    73,    80,    83,    57,     0,    53,
     119,   119,   119,   137,   140,     0,   136,     0,     0,     0,
       0,    44,    36,    34,   113,   118,   117,    75,    76,     0,
      79,     0,   144,   142,   143,   138,   119,   119,    65,    45,
     115,    74,    81,    56,     0,     0,    66,    77,    78,     0,
      68,    69,    54,    55
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -237,  -237,   323,  -237,  -237,  -237,  -237,  -237,  -237,  -237,
    -237,  -237,  -237,  -227,  -237,  -237,  -237,   147,   183,  -237,
    -237,  -237,    23,  -166,  -104,  -237,  -237,    38,    58,  -237,
    -237,    48,  -237,  -237,   271,   152,  -237,  -237,  -237,    -4,
     228,   -95,   232,  -103,  -236,  -184,  -136,   160,  -164,  -165,
    -142,  -237,  -237,  -237,  -237
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,   238,    31,    32,    33,   161,   132,   234,
     159,    34,   279,   209,    54,    35,    36,   231,   192,    37,
     275,   276,   206,    38,    55,    56,    64,    65,    66,   150,
      98,    68,   100,   138,   204,   243,   127,   151,   152,   173,
     185,    39,    40,    41,    80
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      67,   129,   166,   167,   123,   210,   214,   273,   188,    57,
      58,   111,   269,    59,    60,    61,   139,    69,   194,    57,
      58,   136,   149,    59,    60,    61,   202,    57,    58,    70,
      71,    59,    60,    61,    42,   217,    43,   297,   298,   137,
     292,   169,   171,   172,   222,    91,    92,   203,   195,   191,
     196,   253,    72,   140,    89,    90,    91,    92,   310,   299,
     261,   201,    78,    88,    62,    44,   172,   141,   244,    63,
     120,   317,   318,   252,    62,   121,   213,   271,   272,   211,
     277,   220,    62,   175,   226,   149,   294,   295,   296,    48,
      73,    74,   285,   122,    76,   265,    49,    50,   146,    51,
      52,    45,    79,    46,   246,    89,    90,    91,    92,   147,
      75,    81,   172,   254,   175,   218,    82,   219,   258,    83,
     223,   172,   224,    84,   176,   177,   178,   175,   179,   180,
     181,   182,   183,   184,   263,    85,    93,   149,   149,   148,
     241,    48,   242,    94,   302,   303,   304,   319,    49,    50,
      62,    51,    52,   172,    96,   176,   186,   187,    95,   179,
     180,   181,   182,   183,   184,    97,    99,   212,   176,   101,
     314,   315,   179,   180,   181,   182,   183,   184,   290,   102,
     291,   221,   103,   104,   227,   191,   105,    47,    57,    58,
       1,     2,    59,    60,    61,     3,     4,   313,   106,    86,
     155,   156,   157,   158,     5,    87,     6,     7,     8,     9,
      10,   109,   107,   255,    11,    12,    13,   225,   259,    48,
     108,    14,    15,   257,   110,   262,    49,    50,   126,    51,
      52,   117,    53,   118,    16,   190,    17,   125,   119,    18,
      62,   113,   114,   115,   116,   124,   128,   131,   283,    48,
     130,   133,   134,   136,   135,    48,    49,    50,    62,    51,
      52,    48,    49,    50,    62,    51,    52,    48,    49,    50,
      62,    51,    52,    48,    49,    50,   142,    51,    52,   145,
      49,    50,   153,    51,    52,   154,   160,   162,   163,   164,
     170,   165,   174,   168,   189,   193,   198,   199,   200,   205,
     207,   216,   208,   215,   229,   232,   230,   233,   235,   237,
     240,   245,   239,   247,   248,   256,   266,   260,   264,   267,
     278,   268,   270,   249,   250,   284,   251,   286,   287,   274,
     293,   301,   280,   281,   282,   288,   300,   305,   320,   321,
     322,    77,   289,   197,   236,   323,   316,   308,   312,   228,
     143,     0,   306,   309,     0,   144,     0,   307,     0,   112,
       0,     0,     0,   311
};

static const yytype_int16 yycheck[] =
{
       4,   105,   138,   139,    99,   170,   172,   243,   150,    11,
      12,    26,   239,    15,    16,    17,   119,    66,    25,    11,
      12,    27,   126,    15,    16,    17,    45,    11,    12,     7,
       8,    15,    16,    17,     6,   177,     8,    18,    19,    45,
     267,   145,    10,   147,   186,    71,    72,    66,    55,   153,
      57,   216,    41,    26,    69,    70,    71,    72,   294,    40,
     225,   164,     0,    27,    66,    37,   170,    40,   204,    71,
      66,    18,    19,   215,    66,    71,   171,   241,   242,    71,
     246,   185,    66,    13,   188,   189,   270,   271,   272,    57,
      43,    66,   257,    97,    51,   231,    64,    65,    14,    67,
      68,     6,     3,     8,   208,    69,    70,    71,    72,    25,
      66,    66,   216,   217,    13,    55,    66,    57,   222,     8,
      55,   225,    57,    66,    54,    55,    56,    13,    58,    59,
      60,    61,    62,    63,   229,    66,    40,   241,   242,    55,
      47,    57,    49,    43,   280,   281,   282,   313,    64,    65,
      66,    67,    68,   257,    25,    54,    55,    56,    43,    58,
      59,    60,    61,    62,    63,    27,    27,   171,    54,    43,
     306,   307,    58,    59,    60,    61,    62,    63,    55,    66,
      57,   185,    66,    48,   188,   289,    58,    25,    11,    12,
       4,     5,    15,    16,    17,     9,    10,   301,    52,    47,
      31,    32,    33,    34,    18,    53,    20,    21,    22,    23,
      24,    66,    25,   217,    28,    29,    30,    25,   222,    57,
      49,    35,    36,    25,    49,   229,    64,    65,    44,    67,
      68,    66,    70,    66,    48,    25,    50,    42,    66,    53,
      66,    89,    90,    91,    92,    66,    66,    66,   252,    57,
      68,    66,    49,    27,    66,    57,    64,    65,    66,    67,
      68,    57,    64,    65,    66,    67,    68,    57,    64,    65,
      66,    67,    68,    57,    64,    65,    26,    67,    68,    25,
      64,    65,    58,    67,    68,    41,    27,    25,    66,    66,
      25,    46,    14,    66,    47,     6,    26,    66,    25,    38,
      26,    25,    27,    26,    10,    66,    27,    64,    57,    27,
      46,    39,    66,    26,    26,    57,    26,    57,    66,    66,
      27,    26,    66,    43,    43,    26,    43,    26,    43,    66,
      26,    25,    66,    66,    66,    43,    27,    26,    26,    26,
      26,    18,    58,   160,   197,   322,   308,   289,   300,   189,
     122,    -1,    66,    57,    -1,   123,    -1,    66,    -1,    88,
      -1,    -1,    -1,    66
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     4,     5,     9,    10,    18,    20,    21,    22,    23,
      24,    28,    29,    30,    35,    36,    48,    50,    53,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    88,    89,    90,    95,    99,   100,   103,   107,   125,
     126,   127,     6,     8,    37,     6,     8,    25,    57,    64,
      65,    67,    68,    70,    98,   108,   109,    11,    12,    15,
      16,    17,    66,    71,   110,   111,   112,   113,   115,    66,
       7,     8,    41,    43,    66,    66,    51,    76,     0,     3,
     128,    66,    66,     8,    66,    66,   109,   109,    27,    69,
      70,    71,    72,    40,    43,    43,    25,    27,   114,    27,
     116,    43,    66,    66,    48,    58,    52,    25,    49,    66,
      49,    26,   108,   109,   109,   109,   109,    66,    66,    66,
      66,    71,   113,   115,    66,    42,    44,   120,    66,    98,
      68,    66,    92,    66,    49,    66,    27,    45,   117,   117,
      26,    40,    26,   114,   116,    25,    14,    25,    55,    98,
     113,   121,   122,    58,    41,    31,    32,    33,    34,    94,
      27,    91,    25,    66,    66,    46,   120,   120,    66,    98,
      25,    10,    98,   123,    14,    13,    54,    55,    56,    58,
      59,    60,    61,    62,    63,   124,    55,    56,   124,    47,
      25,    98,   102,     6,    25,    55,    57,    92,    26,    66,
      25,   117,    45,    66,   118,    38,   106,    26,    27,    97,
     123,    71,   113,   115,    97,    26,    25,   124,    55,    57,
      98,   113,   124,    55,    57,    25,    98,   113,   121,    10,
      27,   101,    66,    64,    93,    57,    91,    27,    87,    66,
      46,    47,    49,   119,   120,    39,    98,    26,    26,    43,
      43,    43,   124,   123,    98,   113,    57,    25,    98,   113,
      57,   123,   113,   115,    66,   120,    26,    66,    26,    87,
      66,   122,   122,   118,    66,   104,   105,    97,    27,    96,
      66,    66,    66,   113,    26,   123,    26,    43,    43,    58,
      55,    57,    87,    26,   119,   119,   119,    18,    19,    40,
      27,    25,   120,   120,   120,    26,    66,    66,   102,    57,
     118,    66,   105,    98,   120,   120,   101,    18,    19,    97,
      26,    26,    26,    96
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    74,    75,    76,    76,    76,    76,    76,    76,    76,
      76,    76,    76,    76,    76,    76,    76,    76,    76,    76,
      76,    76,    76,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    86,    87,    87,    88,    89,    90,
      91,    91,    92,    92,    92,    92,    92,    92,    93,    94,
      94,    94,    94,    95,    96,    96,    97,    97,    98,    98,
      98,    98,    98,    99,   100,   101,   101,   102,   102,   102,
     103,   103,   103,   104,   104,   104,   104,   104,   104,   105,
     105,   105,   106,   106,   107,   108,   108,   109,   109,   109,
     109,   109,   109,   109,   110,   110,   111,   112,   112,   112,
     112,   112,   113,   113,   114,   114,   115,   115,   115,   116,
     116,   117,   117,   118,   118,   118,   119,   119,   119,   120,
     120,   121,   121,   121,   122,   122,   122,   122,   122,   122,
     122,   122,   122,   122,   122,   122,   122,   122,   122,   122,
     122,   123,   123,   123,   123,   124,   124,   124,   124,   124,
     124,   124,   124,   125,   126,   127,   128,   128
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     2,     2,     9,    10,     0,     3,     5,     4,     7,
       0,     3,     5,     2,     6,     7,     3,     4,     1,     1,
       1,     1,     1,     9,     0,     6,     0,     3,     1,     1,
       1,     1,     1,     4,     8,     0,     5,     1,     7,     7,
       7,     6,     8,     1,     3,     2,     2,     4,     4,     0,
       1,     3,     0,     3,     2,     1,     3,     3,     3,     3,
       3,     3,     2,     1,     1,     2,     2,     1,     1,     1,
       1,     1,     1,     3,     0,     3,     4,     4,     6,     0,
       3,     0,     3,     0,     3,     5,     0,     3,     3,     0,
       2,     0,     1,     3,     3,     3,     3,     3,     4,     4,
       4,     4,     3,     3,     4,     4,     5,     5,     6,     4,
       5,     2,     5,     5,     5,     1,     1,     1,     1,     1,
       1,     1,     1,     7,     2,     4,     0,     1
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
        yyerror (&yylloc, sql_string, sql_result, scanner, YY_("syntax error: cannot back up")); \
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
                  Kind, Value, Location, sql_string, sql_result, scanner); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, const char * sql_string, ParsedSqlResult * sql_result, void * scanner)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (yylocationp);
  YY_USE (sql_string);
  YY_USE (sql_result);
  YY_USE (scanner);
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
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, const char * sql_string, ParsedSqlResult * sql_result, void * scanner)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  YYLOCATION_PRINT (yyo, yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yykind, yyvaluep, yylocationp, sql_string, sql_result, scanner);
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
                 int yyrule, const char * sql_string, ParsedSqlResult * sql_result, void * scanner)
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
                       &(yylsp[(yyi + 1) - (yynrhs)]), sql_string, sql_result, scanner);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule, sql_string, sql_result, scanner); \
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


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
  YYLTYPE *yylloc;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
  if (!yypact_value_is_default (yyn))
    {
      /* Start YYX at -YYN if negative to avoid negative indexes in
         YYCHECK.  In other words, skip the first -YYN actions for
         this state because they are default actions.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;
      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yyx;
      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
# endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;
      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, YYLTYPE *yylocationp, const char * sql_string, ParsedSqlResult * sql_result, void * scanner)
{
  YY_USE (yyvaluep);
  YY_USE (yylocationp);
  YY_USE (sql_string);
  YY_USE (sql_result);
  YY_USE (scanner);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}






/*----------.
| yyparse.  |
`----------*/

int
yyparse (const char * sql_string, ParsedSqlResult * sql_result, void * scanner)
{
/* Lookahead token kind.  */
int yychar;


/* The semantic value of the lookahead symbol.  */
/* Default value used for initialization, for pacifying older GCCs
   or non-GCC compilers.  */
YY_INITIAL_VALUE (static YYSTYPE yyval_default;)
YYSTYPE yylval YY_INITIAL_VALUE (= yyval_default);

/* Location data for the lookahead symbol.  */
static YYLTYPE yyloc_default
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
YYLTYPE yylloc = yyloc_default;

    /* Number of syntax errors so far.  */
    int yynerrs = 0;

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

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

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
      yychar = yylex (&yylval, &yylloc, scanner);
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
  case 2: /* commands: command_wrapper opt_semicolon  */
#line 232 "yacc_sql.y"
  {
    std::unique_ptr<ParsedSqlNode> sql_node = std::unique_ptr<ParsedSqlNode>((yyvsp[-1].sql_node));
    sql_result->add_sql_node(std::move(sql_node));
  }
#line 1880 "yacc_sql.cpp"
    break;

  case 24: /* exit_stmt: EXIT  */
#line 263 "yacc_sql.y"
         {
      (void)yynerrs;  // 这么写为了消除yynerrs未使用的告警。如果你有更好的方法欢迎提PR
      (yyval.sql_node) = new ParsedSqlNode(SCF_EXIT);
    }
#line 1889 "yacc_sql.cpp"
    break;

  case 25: /* help_stmt: HELP  */
#line 269 "yacc_sql.y"
         {
      (yyval.sql_node) = new ParsedSqlNode(SCF_HELP);
    }
#line 1897 "yacc_sql.cpp"
    break;

  case 26: /* sync_stmt: SYNC  */
#line 274 "yacc_sql.y"
         {
      (yyval.sql_node) = new ParsedSqlNode(SCF_SYNC);
    }
#line 1905 "yacc_sql.cpp"
    break;

  case 27: /* begin_stmt: TRX_BEGIN  */
#line 280 "yacc_sql.y"
               {
      (yyval.sql_node) = new ParsedSqlNode(SCF_BEGIN);
    }
#line 1913 "yacc_sql.cpp"
    break;

  case 28: /* commit_stmt: TRX_COMMIT  */
#line 286 "yacc_sql.y"
               {
      (yyval.sql_node) = new ParsedSqlNode(SCF_COMMIT);
    }
#line 1921 "yacc_sql.cpp"
    break;

  case 29: /* rollback_stmt: TRX_ROLLBACK  */
#line 292 "yacc_sql.y"
                  {
      (yyval.sql_node) = new ParsedSqlNode(SCF_ROLLBACK);
    }
#line 1929 "yacc_sql.cpp"
    break;

  case 30: /* drop_table_stmt: DROP TABLE ID  */
#line 298 "yacc_sql.y"
                  {
      (yyval.sql_node) = new ParsedSqlNode(SCF_DROP_TABLE);
      (yyval.sql_node)->drop_table.relation_name = (yyvsp[0].string);
      free((yyvsp[0].string));
    }
#line 1939 "yacc_sql.cpp"
    break;

  case 31: /* show_tables_stmt: SHOW TABLES  */
#line 305 "yacc_sql.y"
                {
      (yyval.sql_node) = new ParsedSqlNode(SCF_SHOW_TABLES);
    }
#line 1947 "yacc_sql.cpp"
    break;

  case 32: /* desc_table_stmt: DESC ID  */
#line 311 "yacc_sql.y"
             {
      (yyval.sql_node) = new ParsedSqlNode(SCF_DESC_TABLE);
      (yyval.sql_node)->desc_table.relation_name = (yyvsp[0].string);
      free((yyvsp[0].string));
    }
#line 1957 "yacc_sql.cpp"
    break;

  case 33: /* create_index_stmt: CREATE INDEX ID ON ID LBRACE ID id_list RBRACE  */
#line 320 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_CREATE_INDEX);
      CreateIndexSqlNode &create_index = (yyval.sql_node)->create_index;
      create_index.index_name = (yyvsp[-6].string);
      create_index.relation_name = (yyvsp[-4].string);
      create_index.unique = false;
      free((yyvsp[-6].string));
      free((yyvsp[-4].string));

      std::vector<std::string> *attr_names = (yyvsp[-1].id_lists);
      if (attr_names != nullptr) {
        create_index.attribute_name.swap(*attr_names);
      }
      create_index.attribute_name.emplace_back((yyvsp[-2].string));
      std::reverse(create_index.attribute_name.begin(), create_index.attribute_name.end());

      free((yyvsp[-2].string));
    }
#line 1980 "yacc_sql.cpp"
    break;

  case 34: /* create_index_stmt: CREATE UNIQUE INDEX ID ON ID LBRACE ID id_list RBRACE  */
#line 339 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_CREATE_INDEX);
      CreateIndexSqlNode &create_index = (yyval.sql_node)->create_index;
      create_index.index_name = (yyvsp[-6].string);
      create_index.relation_name = (yyvsp[-4].string);
      create_index.unique = true;
      free((yyvsp[-6].string));
      free((yyvsp[-4].string));

      std::vector<std::string> *attr_names = (yyvsp[-1].id_lists);
      if (attr_names != nullptr) {
        create_index.attribute_name.swap(*attr_names);
      }
      create_index.attribute_name.emplace_back((yyvsp[-2].string));
      std::reverse(create_index.attribute_name.begin(), create_index.attribute_name.end());

      free((yyvsp[-2].string));
    }
#line 2003 "yacc_sql.cpp"
    break;

  case 35: /* id_list: %empty  */
#line 361 "yacc_sql.y"
    {
      (yyval.id_lists) = nullptr;
    }
#line 2011 "yacc_sql.cpp"
    break;

  case 36: /* id_list: COMMA ID id_list  */
#line 365 "yacc_sql.y"
    {
      if ((yyvsp[0].id_lists) != nullptr) {
        (yyval.id_lists) = (yyvsp[0].id_lists);
      } else {
        (yyval.id_lists) = new std::vector<std::string>;
      }
      (yyval.id_lists)->emplace_back((yyvsp[-1].string));
      delete (yyvsp[-1].string);
    }
#line 2025 "yacc_sql.cpp"
    break;

  case 37: /* drop_index_stmt: DROP INDEX ID ON ID  */
#line 378 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_DROP_INDEX);
      (yyval.sql_node)->drop_index.index_name = (yyvsp[-2].string);
      (yyval.sql_node)->drop_index.relation_name = (yyvsp[0].string);
      free((yyvsp[-2].string));
      free((yyvsp[0].string));
    }
#line 2037 "yacc_sql.cpp"
    break;

  case 38: /* show_index_stmt: SHOW INDEX FROM ID  */
#line 389 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_SHOW_INDEX);
      (yyval.sql_node)->show_index.relation_name = (yyvsp[0].string);
      free((yyvsp[0].string));
    }
#line 2047 "yacc_sql.cpp"
    break;

  case 39: /* create_table_stmt: CREATE TABLE ID LBRACE attr_def attr_def_list RBRACE  */
#line 397 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_CREATE_TABLE);
      CreateTableSqlNode &create_table = (yyval.sql_node)->create_table;
      create_table.relation_name = (yyvsp[-4].string);
      free((yyvsp[-4].string));

      std::vector<AttrInfoSqlNode> *src_attrs = (yyvsp[-1].attr_infos);

      if (src_attrs != nullptr) {
        create_table.attr_infos.swap(*src_attrs);
      }
      create_table.attr_infos.emplace_back(*(yyvsp[-2].attr_info));
      std::reverse(create_table.attr_infos.begin(), create_table.attr_infos.end());
      delete (yyvsp[-2].attr_info);
    }
#line 2067 "yacc_sql.cpp"
    break;

  case 40: /* attr_def_list: %empty  */
#line 415 "yacc_sql.y"
    {
      (yyval.attr_infos) = nullptr;
    }
#line 2075 "yacc_sql.cpp"
    break;

  case 41: /* attr_def_list: COMMA attr_def attr_def_list  */
#line 419 "yacc_sql.y"
    {
      if ((yyvsp[0].attr_infos) != nullptr) {
        (yyval.attr_infos) = (yyvsp[0].attr_infos);
      } else {
        (yyval.attr_infos) = new std::vector<AttrInfoSqlNode>;
      }
      (yyval.attr_infos)->emplace_back(*(yyvsp[-1].attr_info));
      delete (yyvsp[-1].attr_info);
    }
#line 2089 "yacc_sql.cpp"
    break;

  case 42: /* attr_def: ID type LBRACE number RBRACE  */
#line 432 "yacc_sql.y"
    {
      (yyval.attr_info) = new AttrInfoSqlNode;
      (yyval.attr_info)->type = (AttrType)(yyvsp[-3].number);
      (yyval.attr_info)->name = (yyvsp[-4].string);
      (yyval.attr_info)->length = (yyvsp[-1].number);
      (yyval.attr_info)->nullable = true;
      free((yyvsp[-4].string));
    }
#line 2102 "yacc_sql.cpp"
    break;

  case 43: /* attr_def: ID type  */
#line 441 "yacc_sql.y"
    {
      (yyval.attr_info) = new AttrInfoSqlNode;
      (yyval.attr_info)->type = (AttrType)(yyvsp[0].number);
      (yyval.attr_info)->name = (yyvsp[-1].string);
      (yyval.attr_info)->length = 4;
      (yyval.attr_info)->nullable = true;
      free((yyvsp[-1].string));
    }
#line 2115 "yacc_sql.cpp"
    break;

  case 44: /* attr_def: ID type LBRACE number RBRACE NULLABLE  */
#line 450 "yacc_sql.y"
                {
      (yyval.attr_info) = new AttrInfoSqlNode;
      (yyval.attr_info)->type = (AttrType)(yyvsp[-4].number);
      (yyval.attr_info)->name = (yyvsp[-5].string);
      (yyval.attr_info)->length = (yyvsp[-2].number);
      (yyval.attr_info)->nullable = true;
      free((yyvsp[-5].string));
		}
#line 2128 "yacc_sql.cpp"
    break;

  case 45: /* attr_def: ID type LBRACE number RBRACE NOT NULLABLE  */
#line 459 "yacc_sql.y"
                {
      (yyval.attr_info) = new AttrInfoSqlNode;
      (yyval.attr_info)->type = (AttrType)(yyvsp[-5].number);
      (yyval.attr_info)->name = (yyvsp[-6].string);
      (yyval.attr_info)->length = (yyvsp[-3].number);
      (yyval.attr_info)->nullable = false;
      free((yyvsp[-6].string));
		}
#line 2141 "yacc_sql.cpp"
    break;

  case 46: /* attr_def: ID type NULLABLE  */
#line 468 "yacc_sql.y"
                {
			(yyval.attr_info) = new AttrInfoSqlNode;
      (yyval.attr_info)->type = (AttrType)(yyvsp[-1].number);
      (yyval.attr_info)->name = (yyvsp[-2].string);
      (yyval.attr_info)->length = 4;
      (yyval.attr_info)->nullable = true;
      free((yyvsp[-2].string));
		}
#line 2154 "yacc_sql.cpp"
    break;

  case 47: /* attr_def: ID type NOT NULLABLE  */
#line 477 "yacc_sql.y"
                {
			(yyval.attr_info) = new AttrInfoSqlNode;
      (yyval.attr_info)->type = (AttrType)(yyvsp[-2].number);
      (yyval.attr_info)->name = (yyvsp[-3].string);
      (yyval.attr_info)->length = 4;
      (yyval.attr_info)->nullable = false;
      free((yyvsp[-3].string));
		}
#line 2167 "yacc_sql.cpp"
    break;

  case 48: /* number: NUMBER  */
#line 487 "yacc_sql.y"
           {(yyval.number) = (yyvsp[0].number);}
#line 2173 "yacc_sql.cpp"
    break;

  case 49: /* type: INT_T  */
#line 490 "yacc_sql.y"
               { (yyval.number)=INTS; }
#line 2179 "yacc_sql.cpp"
    break;

  case 50: /* type: STRING_T  */
#line 491 "yacc_sql.y"
               { (yyval.number)=CHARS; }
#line 2185 "yacc_sql.cpp"
    break;

  case 51: /* type: FLOAT_T  */
#line 492 "yacc_sql.y"
               { (yyval.number)=FLOATS; }
#line 2191 "yacc_sql.cpp"
    break;

  case 52: /* type: DATE_T  */
#line 493 "yacc_sql.y"
              { (yyval.number)=DATES; }
#line 2197 "yacc_sql.cpp"
    break;

  case 53: /* insert_stmt: INSERT INTO ID VALUES LBRACE value value_list RBRACE row_value_list  */
#line 497 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_INSERT);
      (yyval.sql_node)->insertion.relation_name = (yyvsp[-6].string);
      std::vector<Value> *row_value = new std::vector<Value>;
      if ((yyvsp[-2].value_list) != nullptr) {
        row_value->swap(*(yyvsp[-2].value_list));
      }
      Value *tmp_value = new Value((yyvsp[-3].value)->attr_type(), (yyvsp[-3].value)->get_data(), (yyvsp[-3].value)->length());
      row_value->emplace_back(*tmp_value);
      std::reverse(row_value->begin(), row_value->end());

      if ((yyvsp[0].row_value_list) != nullptr) {
        (yyval.sql_node)->insertion.values.swap(*(yyvsp[0].row_value_list));
      }
      (yyval.sql_node)->insertion.values.emplace_back(*row_value);
      std::reverse((yyval.sql_node)->insertion.values.begin(), (yyval.sql_node)->insertion.values.end());

      delete (yyvsp[-3].value);
      free((yyvsp[-6].string));
    }
#line 2222 "yacc_sql.cpp"
    break;

  case 54: /* row_value_list: %empty  */
#line 521 "yacc_sql.y"
                {
      (yyval.row_value_list) = nullptr;
    }
#line 2230 "yacc_sql.cpp"
    break;

  case 55: /* row_value_list: COMMA LBRACE value value_list RBRACE row_value_list  */
#line 524 "yacc_sql.y"
                                                          {
			if ((yyvsp[0].row_value_list) != nullptr) {
        (yyval.row_value_list) = (yyvsp[0].row_value_list);
      } else {
        (yyval.row_value_list) = new std::vector<std::vector<Value>>;
      }
      std::vector<Value> row_value;
      if ((yyvsp[-2].value_list) != nullptr) {
        row_value.swap(*(yyvsp[-2].value_list));
      }
      row_value.emplace_back(*(yyvsp[-3].value));
      std::reverse(row_value.begin(), row_value.end());
      delete (yyvsp[-3].value);

      (yyval.row_value_list)->emplace_back(row_value);
		}
#line 2251 "yacc_sql.cpp"
    break;

  case 56: /* value_list: %empty  */
#line 544 "yacc_sql.y"
    {
      (yyval.value_list) = nullptr;
    }
#line 2259 "yacc_sql.cpp"
    break;

  case 57: /* value_list: COMMA value value_list  */
#line 547 "yacc_sql.y"
                              { 
      if ((yyvsp[0].value_list) != nullptr) {
        (yyval.value_list) = (yyvsp[0].value_list);
      } else {
        (yyval.value_list) = new std::vector<Value>;
      }
      (yyval.value_list)->emplace_back(*(yyvsp[-1].value));
      delete (yyvsp[-1].value);
    }
#line 2273 "yacc_sql.cpp"
    break;

  case 58: /* value: NUMBER  */
#line 558 "yacc_sql.y"
           {
      (yyval.value) = new Value((int)(yyvsp[0].number));
      (yyloc) = (yylsp[0]);
    }
#line 2282 "yacc_sql.cpp"
    break;

  case 59: /* value: FLOAT  */
#line 562 "yacc_sql.y"
           {
      (yyval.value) = new Value((float)(yyvsp[0].floats));
      (yyloc) = (yylsp[0]);
    }
#line 2291 "yacc_sql.cpp"
    break;

  case 60: /* value: DATE  */
#line 566 "yacc_sql.y"
          {
      char *tmp = common::substr((yyvsp[0].dates),1,strlen((yyvsp[0].dates))-2);
      (yyval.value) = new Value(tmp);
      free(tmp);
    }
#line 2301 "yacc_sql.cpp"
    break;

  case 61: /* value: SSS  */
#line 571 "yacc_sql.y"
         {
      char *tmp = common::substr((yyvsp[0].string),1,strlen((yyvsp[0].string))-2);
      (yyval.value) = new Value(tmp);
      free(tmp);
    }
#line 2311 "yacc_sql.cpp"
    break;

  case 62: /* value: NULLABLE  */
#line 576 "yacc_sql.y"
              {
      (yyval.value) = new Value();
      (yyval.value)->set_type(AttrType::NULLS);
    }
#line 2320 "yacc_sql.cpp"
    break;

  case 63: /* delete_stmt: DELETE FROM ID where  */
#line 584 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_DELETE);
      (yyval.sql_node)->deletion.relation_name = (yyvsp[-1].string);
      if ((yyvsp[0].condition_list) != nullptr) {
        (yyval.sql_node)->deletion.conditions.swap(*(yyvsp[0].condition_list));
        delete (yyvsp[0].condition_list);
      }
      free((yyvsp[-1].string));
    }
#line 2334 "yacc_sql.cpp"
    break;

  case 64: /* update_stmt: UPDATE ID SET ID EQ sub_select update_list where  */
#line 596 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_UPDATE);
      (yyval.sql_node)->update.relation_name = (yyvsp[-6].string);
      if ((yyvsp[-1].attribute_and_expr) != nullptr) {
        (yyval.sql_node)->update.attribute_name.swap((yyvsp[-1].attribute_and_expr)->attribute_name);
        (yyval.sql_node)->update.exprs.swap((yyvsp[-1].attribute_and_expr)->exprs);
        delete (yyvsp[-1].attribute_and_expr);
      }
      (yyval.sql_node)->update.attribute_name.push_back((yyvsp[-4].string));
      std::reverse((yyval.sql_node)->update.attribute_name.begin(), (yyval.sql_node)->update.attribute_name.end());
      (yyval.sql_node)->update.exprs.emplace_back((yyvsp[-2].sub_select));
      std::reverse((yyval.sql_node)->update.exprs.begin(), (yyval.sql_node)->update.exprs.end());

      if ((yyvsp[0].condition_list) != nullptr) {
        (yyval.sql_node)->update.conditions.swap(*(yyvsp[0].condition_list));
        delete (yyvsp[0].condition_list);
      }
      free((yyvsp[-6].string));
      free((yyvsp[-4].string));
    }
#line 2359 "yacc_sql.cpp"
    break;

  case 65: /* update_list: %empty  */
#line 620 "yacc_sql.y"
    {
      (yyval.attribute_and_expr) = nullptr;
    }
#line 2367 "yacc_sql.cpp"
    break;

  case 66: /* update_list: COMMA ID EQ sub_select update_list  */
#line 623 "yacc_sql.y"
                                         {
      if ((yyvsp[0].attribute_and_expr) != nullptr) {
        (yyval.attribute_and_expr) = (yyvsp[0].attribute_and_expr);
      } else {
        (yyval.attribute_and_expr) = new AttributeAndExpr;
      }
      (yyval.attribute_and_expr)->attribute_name.push_back((yyvsp[-3].string));
      (yyval.attribute_and_expr)->exprs.emplace_back((yyvsp[-1].sub_select));
      free((yyvsp[-3].string));
    }
#line 2382 "yacc_sql.cpp"
    break;

  case 67: /* sub_select: value  */
#line 636 "yacc_sql.y"
          {
      (yyval.sub_select) = new ValueExpr(*(yyvsp[0].value));
      (yyval.sub_select)->set_name(token_name(sql_string, &(yyloc)));
      delete (yyvsp[0].value);
    }
#line 2392 "yacc_sql.cpp"
    break;

  case 68: /* sub_select: LBRACE SELECT rel_attr FROM ID where RBRACE  */
#line 642 "yacc_sql.y"
    {
      SelectSqlNode *select_sql_node = new SelectSqlNode();
      if ((yyvsp[-4].rel_attr) != nullptr) {
        std::vector<RelAttrSqlNode> *tmp = new std::vector<RelAttrSqlNode>;
        tmp->emplace_back(*(yyvsp[-4].rel_attr));
        select_sql_node->attributes.swap(*tmp);
        delete (yyvsp[-4].rel_attr);
      }
      select_sql_node->relations.push_back((yyvsp[-2].string));

      if ((yyvsp[-1].condition_list) != nullptr) {
        select_sql_node->conditions.swap(*(yyvsp[-1].condition_list));
        delete (yyvsp[-1].condition_list);
      }
      free((yyvsp[-2].string));
      (yyval.sub_select) = new SubQueryExpression(select_sql_node);
    }
#line 2414 "yacc_sql.cpp"
    break;

  case 69: /* sub_select: LBRACE SELECT agg_rel_attr FROM ID where RBRACE  */
#line 660 "yacc_sql.y"
    {
      SelectAggSqlNode *select_agg_sql_node = new SelectAggSqlNode();
      if ((yyvsp[-4].agg_rel_attr) != nullptr) {
        std::vector<AggRelAttrSqlNode> *tmp = new std::vector<AggRelAttrSqlNode>;
        tmp->emplace_back(*(yyvsp[-4].agg_rel_attr));
        select_agg_sql_node->agg_attributes.swap(*tmp);
        delete (yyvsp[-4].agg_rel_attr);
      }
      select_agg_sql_node->relations.push_back((yyvsp[-2].string));

      if ((yyvsp[-1].condition_list) != nullptr) {
        select_agg_sql_node->conditions.swap(*(yyvsp[-1].condition_list));
        delete (yyvsp[-1].condition_list);
      }
      free((yyvsp[-2].string));
      (yyval.sub_select) = new SubQueryExpression(select_agg_sql_node);
    }
#line 2436 "yacc_sql.cpp"
    break;

  case 70: /* select_stmt: SELECT select_attr FROM ID rel_list where opt_order_by  */
#line 681 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_SELECT);
      if ((yyvsp[-5].rel_attr_list) != nullptr) {
        (yyval.sql_node)->selection.attributes.swap(*(yyvsp[-5].rel_attr_list));
        delete (yyvsp[-5].rel_attr_list);
      }
      if ((yyvsp[-2].relation_list) != nullptr) {
        (yyval.sql_node)->selection.relations.swap(*(yyvsp[-2].relation_list));
        delete (yyvsp[-2].relation_list);
      }
      (yyval.sql_node)->selection.relations.push_back((yyvsp[-3].string));
      std::reverse((yyval.sql_node)->selection.relations.begin(), (yyval.sql_node)->selection.relations.end());

      if ((yyvsp[-1].condition_list) != nullptr) {
        (yyval.sql_node)->selection.conditions.swap(*(yyvsp[-1].condition_list));
        delete (yyvsp[-1].condition_list);
      }
      if ((yyvsp[0].order_by_list) != nullptr) {
        (yyval.sql_node)->selection.orderbys.swap(*(yyvsp[0].order_by_list));
        std::reverse((yyval.sql_node)->selection.orderbys.begin(), (yyval.sql_node)->selection.orderbys.end());
        delete (yyvsp[0].order_by_list);
      }
      free((yyvsp[-3].string));
    }
#line 2465 "yacc_sql.cpp"
    break;

  case 71: /* select_stmt: SELECT select_agg_attr FROM ID rel_list where  */
#line 706 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_SELECT_AGG);
      if ((yyvsp[-4].agg_rel_attr_list) != nullptr) {
        (yyval.sql_node)->selection_agg.agg_attributes.swap(*(yyvsp[-4].agg_rel_attr_list));
        delete (yyvsp[-4].agg_rel_attr_list);
      }
      if ((yyvsp[-1].relation_list) != nullptr) {
        (yyval.sql_node)->selection_agg.relations.swap(*(yyvsp[-1].relation_list));
        delete (yyvsp[-1].relation_list);
      }
      (yyval.sql_node)->selection_agg.relations.push_back((yyvsp[-2].string));
      std::reverse((yyval.sql_node)->selection_agg.relations.begin(), (yyval.sql_node)->selection_agg.relations.end());

      if ((yyvsp[0].condition_list) != nullptr) {
        (yyval.sql_node)->selection_agg.conditions.swap(*(yyvsp[0].condition_list));
        delete (yyvsp[0].condition_list);
      }
      free((yyvsp[-2].string));
    }
#line 2489 "yacc_sql.cpp"
    break;

  case 72: /* select_stmt: SELECT select_attr FROM ID INNER JOIN rel_list_join where  */
#line 726 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_SELECT_JOIN);
      if ((yyvsp[-6].rel_attr_list) != nullptr) {
        (yyval.sql_node)->selection_join.attributes.swap(*(yyvsp[-6].rel_attr_list));
        delete (yyvsp[-6].rel_attr_list);
      }
      if ((yyvsp[-1].table_and_condition) != nullptr) {
        (yyval.sql_node)->selection_join.relations.swap((yyvsp[-1].table_and_condition)->table_name);
        (yyval.sql_node)->selection_join.join_conditions.swap((yyvsp[-1].table_and_condition)->condition_name);
        delete (yyvsp[-1].table_and_condition);
      }
      (yyval.sql_node)->selection_join.relations.push_back((yyvsp[-4].string));
      std::reverse((yyval.sql_node)->selection_join.relations.begin(), (yyval.sql_node)->selection_join.relations.end());

      if ((yyvsp[0].condition_list) != nullptr) {
        (yyval.sql_node)->selection_join.conditions.swap(*(yyvsp[0].condition_list));
        delete (yyvsp[0].condition_list);
      }
      free((yyvsp[-4].string));
    }
#line 2514 "yacc_sql.cpp"
    break;

  case 73: /* order_by_unit: ID  */
#line 748 "yacc_sql.y"
       {
      RelAttrSqlNode *tmp = new RelAttrSqlNode;
      tmp->attribute_name = (yyvsp[0].string);
      free((yyvsp[0].string));
      (yyval.order_by_unit) = new OrderByNode;
      (yyval.order_by_unit)->order_by_attr = *tmp;
      (yyval.order_by_unit)->is_asc = 1;
    }
#line 2527 "yacc_sql.cpp"
    break;

  case 74: /* order_by_unit: ID DOT ID  */
#line 756 "yacc_sql.y"
                {
      RelAttrSqlNode *tmp = new RelAttrSqlNode;
      tmp->relation_name  = (yyvsp[-2].string);
      tmp->attribute_name = (yyvsp[0].string);
      free((yyvsp[-2].string));
      free((yyvsp[0].string));
      (yyval.order_by_unit) = new OrderByNode;
      (yyval.order_by_unit)->order_by_attr = *tmp;
      (yyval.order_by_unit)->is_asc = 1;
    }
#line 2542 "yacc_sql.cpp"
    break;

  case 75: /* order_by_unit: ID DESC  */
#line 768 "yacc_sql.y"
    {
      RelAttrSqlNode *tmp = new RelAttrSqlNode;
      tmp->attribute_name = (yyvsp[-1].string);
      free((yyvsp[-1].string));
      (yyval.order_by_unit) = new OrderByNode;
      (yyval.order_by_unit)->order_by_attr = *tmp;
      (yyval.order_by_unit)->is_asc = 0;
    }
#line 2555 "yacc_sql.cpp"
    break;

  case 76: /* order_by_unit: ID ASC  */
#line 778 "yacc_sql.y"
    {
      RelAttrSqlNode *tmp = new RelAttrSqlNode;
      tmp->attribute_name = (yyvsp[-1].string);
      free((yyvsp[-1].string));
      (yyval.order_by_unit) = new OrderByNode;
      (yyval.order_by_unit)->order_by_attr = *tmp;
      (yyval.order_by_unit)->is_asc = 1;
    }
#line 2568 "yacc_sql.cpp"
    break;

  case 77: /* order_by_unit: ID DOT ID DESC  */
#line 788 "yacc_sql.y"
    {
      RelAttrSqlNode *tmp = new RelAttrSqlNode;
      tmp->relation_name  = (yyvsp[-3].string);
      tmp->attribute_name = (yyvsp[-1].string);
      free((yyvsp[-3].string));
      free((yyvsp[-1].string));
      (yyval.order_by_unit) = new OrderByNode;
      (yyval.order_by_unit)->order_by_attr = *tmp;
      (yyval.order_by_unit)->is_asc = 0;
    }
#line 2583 "yacc_sql.cpp"
    break;

  case 78: /* order_by_unit: ID DOT ID ASC  */
#line 800 "yacc_sql.y"
    {
      RelAttrSqlNode *tmp = new RelAttrSqlNode;
      tmp->relation_name  = (yyvsp[-3].string);
      tmp->attribute_name = (yyvsp[-1].string);
      free((yyvsp[-3].string));
      free((yyvsp[-1].string));
      (yyval.order_by_unit) = new OrderByNode;
      (yyval.order_by_unit)->order_by_attr = *tmp;
      (yyval.order_by_unit)->is_asc = 1;
    }
#line 2598 "yacc_sql.cpp"
    break;

  case 79: /* order_by_list: %empty  */
#line 813 "yacc_sql.y"
    {
      (yyval.order_by_list) = nullptr;
    }
#line 2606 "yacc_sql.cpp"
    break;

  case 80: /* order_by_list: order_by_unit  */
#line 816 "yacc_sql.y"
                    {
      (yyval.order_by_list) = new std::vector<OrderByNode>;
      (yyval.order_by_list)->emplace_back(*(yyvsp[0].order_by_unit));
      delete (yyvsp[0].order_by_unit);
    }
#line 2616 "yacc_sql.cpp"
    break;

  case 81: /* order_by_list: order_by_unit COMMA order_by_list  */
#line 821 "yacc_sql.y"
                                        {
      (yyval.order_by_list) = (yyvsp[0].order_by_list);
      (yyval.order_by_list)->emplace_back(*(yyvsp[-2].order_by_unit));
      delete (yyvsp[-2].order_by_unit);

    }
#line 2627 "yacc_sql.cpp"
    break;

  case 82: /* opt_order_by: %empty  */
#line 830 "yacc_sql.y"
    {
      (yyval.order_by_list) = nullptr;
    }
#line 2635 "yacc_sql.cpp"
    break;

  case 83: /* opt_order_by: ORDER BY order_by_list  */
#line 834 "yacc_sql.y"
    {
        (yyval.order_by_list) = (yyvsp[0].order_by_list);
    }
#line 2643 "yacc_sql.cpp"
    break;

  case 84: /* calc_stmt: CALC expression_list  */
#line 840 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_CALC);
      std::reverse((yyvsp[0].expression_list)->begin(), (yyvsp[0].expression_list)->end());
      (yyval.sql_node)->calc.expressions.swap(*(yyvsp[0].expression_list));
      delete (yyvsp[0].expression_list);
    }
#line 2654 "yacc_sql.cpp"
    break;

  case 85: /* expression_list: expression  */
#line 850 "yacc_sql.y"
    {
      (yyval.expression_list) = new std::vector<Expression*>;
      (yyval.expression_list)->emplace_back((yyvsp[0].expression));
    }
#line 2663 "yacc_sql.cpp"
    break;

  case 86: /* expression_list: expression COMMA expression_list  */
#line 855 "yacc_sql.y"
    {
      if ((yyvsp[0].expression_list) != nullptr) {
        (yyval.expression_list) = (yyvsp[0].expression_list);
      } else {
        (yyval.expression_list) = new std::vector<Expression *>;
      }
      (yyval.expression_list)->emplace_back((yyvsp[-2].expression));
    }
#line 2676 "yacc_sql.cpp"
    break;

  case 87: /* expression: expression '+' expression  */
#line 865 "yacc_sql.y"
                              {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::ADD, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2684 "yacc_sql.cpp"
    break;

  case 88: /* expression: expression '-' expression  */
#line 868 "yacc_sql.y"
                                {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::SUB, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2692 "yacc_sql.cpp"
    break;

  case 89: /* expression: expression '*' expression  */
#line 871 "yacc_sql.y"
                                {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::MUL, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2700 "yacc_sql.cpp"
    break;

  case 90: /* expression: expression '/' expression  */
#line 874 "yacc_sql.y"
                                {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::DIV, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2708 "yacc_sql.cpp"
    break;

  case 91: /* expression: LBRACE expression RBRACE  */
#line 877 "yacc_sql.y"
                               {
      (yyval.expression) = (yyvsp[-1].expression);
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));
    }
#line 2717 "yacc_sql.cpp"
    break;

  case 92: /* expression: '-' expression  */
#line 881 "yacc_sql.y"
                                  {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::NEGATIVE, (yyvsp[0].expression), nullptr, sql_string, &(yyloc));
    }
#line 2725 "yacc_sql.cpp"
    break;

  case 93: /* expression: value  */
#line 884 "yacc_sql.y"
            {
      (yyval.expression) = new ValueExpr(*(yyvsp[0].value));
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));
      delete (yyvsp[0].value);
    }
#line 2735 "yacc_sql.cpp"
    break;

  case 94: /* select_attr: '*'  */
#line 892 "yacc_sql.y"
        {
      (yyval.rel_attr_list) = new std::vector<RelAttrSqlNode>;
      RelAttrSqlNode attr;
      attr.relation_name  = "";
      attr.attribute_name = "*";
      (yyval.rel_attr_list)->emplace_back(attr);
    }
#line 2747 "yacc_sql.cpp"
    break;

  case 95: /* select_attr: rel_attr attr_list  */
#line 899 "yacc_sql.y"
                         {
      if ((yyvsp[0].rel_attr_list) != nullptr) {
        (yyval.rel_attr_list) = (yyvsp[0].rel_attr_list);
      } else {
        (yyval.rel_attr_list) = new std::vector<RelAttrSqlNode>;
      }
      (yyval.rel_attr_list)->emplace_back(*(yyvsp[-1].rel_attr));
      delete (yyvsp[-1].rel_attr);
    }
#line 2761 "yacc_sql.cpp"
    break;

  case 96: /* select_agg_attr: agg_rel_attr agg_attr_list  */
#line 911 "yacc_sql.y"
                               {
      if ((yyvsp[0].agg_rel_attr_list) != nullptr) {
        (yyval.agg_rel_attr_list) = (yyvsp[0].agg_rel_attr_list);
      } else {
        (yyval.agg_rel_attr_list) = new std::vector<AggRelAttrSqlNode>;
      }
      (yyval.agg_rel_attr_list)->emplace_back(*(yyvsp[-1].agg_rel_attr));
      delete (yyvsp[-1].agg_rel_attr);
    }
#line 2775 "yacc_sql.cpp"
    break;

  case 97: /* agg_op: MAX  */
#line 923 "yacc_sql.y"
          { (yyval.agg) = MAX_OP; }
#line 2781 "yacc_sql.cpp"
    break;

  case 98: /* agg_op: MIN  */
#line 924 "yacc_sql.y"
          { (yyval.agg) = MIN_OP; }
#line 2787 "yacc_sql.cpp"
    break;

  case 99: /* agg_op: COUNT  */
#line 925 "yacc_sql.y"
            { (yyval.agg) = COUNT_OP; }
#line 2793 "yacc_sql.cpp"
    break;

  case 100: /* agg_op: AVG  */
#line 926 "yacc_sql.y"
          { (yyval.agg) = AVG_OP; }
#line 2799 "yacc_sql.cpp"
    break;

  case 101: /* agg_op: SUM  */
#line 927 "yacc_sql.y"
          { (yyval.agg) = SUM_OP; }
#line 2805 "yacc_sql.cpp"
    break;

  case 102: /* rel_attr: ID  */
#line 931 "yacc_sql.y"
       {
      (yyval.rel_attr) = new RelAttrSqlNode;
      (yyval.rel_attr)->attribute_name = (yyvsp[0].string);
      free((yyvsp[0].string));
    }
#line 2815 "yacc_sql.cpp"
    break;

  case 103: /* rel_attr: ID DOT ID  */
#line 936 "yacc_sql.y"
                {
      (yyval.rel_attr) = new RelAttrSqlNode;
      (yyval.rel_attr)->relation_name  = (yyvsp[-2].string);
      (yyval.rel_attr)->attribute_name = (yyvsp[0].string);
      free((yyvsp[-2].string));
      free((yyvsp[0].string));
    }
#line 2827 "yacc_sql.cpp"
    break;

  case 104: /* attr_list: %empty  */
#line 947 "yacc_sql.y"
    {
      (yyval.rel_attr_list) = nullptr;
    }
#line 2835 "yacc_sql.cpp"
    break;

  case 105: /* attr_list: COMMA rel_attr attr_list  */
#line 950 "yacc_sql.y"
                               {
      if ((yyvsp[0].rel_attr_list) != nullptr) {
        (yyval.rel_attr_list) = (yyvsp[0].rel_attr_list);
      } else {
        (yyval.rel_attr_list) = new std::vector<RelAttrSqlNode>;
      }

      (yyval.rel_attr_list)->emplace_back(*(yyvsp[-1].rel_attr));
      delete (yyvsp[-1].rel_attr);
    }
#line 2850 "yacc_sql.cpp"
    break;

  case 106: /* agg_rel_attr: agg_op LBRACE '*' RBRACE  */
#line 963 "yacc_sql.y"
                             {
      (yyval.agg_rel_attr) = new AggRelAttrSqlNode;
      AggRelAttrSqlNode attr;
      (yyval.agg_rel_attr)->agg_func = (yyvsp[-3].agg);
      (yyval.agg_rel_attr)->relation_name  = "";
      (yyval.agg_rel_attr)->attribute_name = "*";
    }
#line 2862 "yacc_sql.cpp"
    break;

  case 107: /* agg_rel_attr: agg_op LBRACE ID RBRACE  */
#line 970 "yacc_sql.y"
                              {
      (yyval.agg_rel_attr) = new AggRelAttrSqlNode;
      (yyval.agg_rel_attr)->agg_func = (yyvsp[-3].agg);
      (yyval.agg_rel_attr)->attribute_name = (yyvsp[-1].string);
      free((yyvsp[-1].string));
    }
#line 2873 "yacc_sql.cpp"
    break;

  case 108: /* agg_rel_attr: agg_op LBRACE ID DOT ID RBRACE  */
#line 976 "yacc_sql.y"
                                     {
      (yyval.agg_rel_attr) = new AggRelAttrSqlNode;
      (yyval.agg_rel_attr)->agg_func = (yyvsp[-5].agg);
      (yyval.agg_rel_attr)->relation_name  = (yyvsp[-3].string);
      (yyval.agg_rel_attr)->attribute_name = (yyvsp[-1].string);
      free((yyvsp[-3].string));
      free((yyvsp[-1].string));
    }
#line 2886 "yacc_sql.cpp"
    break;

  case 109: /* agg_attr_list: %empty  */
#line 988 "yacc_sql.y"
    {
      (yyval.agg_rel_attr_list) = nullptr;
    }
#line 2894 "yacc_sql.cpp"
    break;

  case 110: /* agg_attr_list: COMMA agg_rel_attr agg_attr_list  */
#line 991 "yacc_sql.y"
                                       {
      if ((yyvsp[0].agg_rel_attr_list) != nullptr) {
        (yyval.agg_rel_attr_list) = (yyvsp[0].agg_rel_attr_list);
      } else {
        (yyval.agg_rel_attr_list) = new std::vector<AggRelAttrSqlNode>;
      }

      (yyval.agg_rel_attr_list)->emplace_back(*(yyvsp[-1].agg_rel_attr));
      delete (yyvsp[-1].agg_rel_attr);
    }
#line 2909 "yacc_sql.cpp"
    break;

  case 111: /* rel_list: %empty  */
#line 1005 "yacc_sql.y"
    {
      (yyval.relation_list) = nullptr;
    }
#line 2917 "yacc_sql.cpp"
    break;

  case 112: /* rel_list: COMMA ID rel_list  */
#line 1008 "yacc_sql.y"
                        {
      if ((yyvsp[0].relation_list) != nullptr) {
        (yyval.relation_list) = (yyvsp[0].relation_list);
      } else {
        (yyval.relation_list) = new std::vector<std::string>;
      }

      (yyval.relation_list)->push_back((yyvsp[-1].string));
      free((yyvsp[-1].string));
    }
#line 2932 "yacc_sql.cpp"
    break;

  case 113: /* rel_list_join: %empty  */
#line 1021 "yacc_sql.y"
    {
      (yyval.table_and_condition) = nullptr;
    }
#line 2940 "yacc_sql.cpp"
    break;

  case 114: /* rel_list_join: ID inner_join_conditions rel_list_join  */
#line 1024 "yacc_sql.y"
                                             {
      if ((yyvsp[0].table_and_condition) != nullptr) {
        (yyval.table_and_condition) = (yyvsp[0].table_and_condition);
      } else {
        // $$ = new std::vector<std::string>;
        (yyval.table_and_condition) = new TableAndCondition;
      }

      // $$->condition_name.push_back($2);
      (yyval.table_and_condition)->condition_name.insert((yyval.table_and_condition)->condition_name.end(),(yyvsp[-1].condition_list)->begin(),(yyvsp[-1].condition_list)->end());
      (yyval.table_and_condition)->table_name.push_back((yyvsp[-2].string));
      free((yyvsp[-2].string));
    }
#line 2958 "yacc_sql.cpp"
    break;

  case 115: /* rel_list_join: INNER JOIN ID inner_join_conditions rel_list_join  */
#line 1037 "yacc_sql.y"
                                                        {
      if ((yyvsp[0].table_and_condition) != nullptr) {
        (yyval.table_and_condition) = (yyvsp[0].table_and_condition);
      } else {
        // $$ = new std::vector<std::string>;
        (yyval.table_and_condition) = new TableAndCondition;
      }

      // $$->condition_name.push_back($4);
      (yyval.table_and_condition)->condition_name.insert((yyval.table_and_condition)->condition_name.end(),(yyvsp[-1].condition_list)->begin(),(yyvsp[-1].condition_list)->end());
      (yyval.table_and_condition)->table_name.push_back((yyvsp[-2].string));
      free((yyvsp[-2].string));
    }
#line 2976 "yacc_sql.cpp"
    break;

  case 116: /* inner_join_conditions: %empty  */
#line 1052 "yacc_sql.y"
                {
      (yyval.condition_list) = new std::vector<ConditionSqlNode>;
    }
#line 2984 "yacc_sql.cpp"
    break;

  case 117: /* inner_join_conditions: ON condition inner_join_conditions  */
#line 1055 "yacc_sql.y"
                                        {
      // $$ = new std::vector<ConditionSqlNode>;
      (yyval.condition_list) = (yyvsp[0].condition_list);
      (yyval.condition_list)->emplace_back(*(yyvsp[-1].condition));
      delete (yyvsp[-1].condition);
    }
#line 2995 "yacc_sql.cpp"
    break;

  case 118: /* inner_join_conditions: AND condition inner_join_conditions  */
#line 1061 "yacc_sql.y"
                                         {
      // $$ = new std::vector<ConditionSqlNode>;
      (yyval.condition_list) = (yyvsp[0].condition_list);
      (yyval.condition_list)->emplace_back(*(yyvsp[-1].condition));
      delete (yyvsp[-1].condition);
    }
#line 3006 "yacc_sql.cpp"
    break;

  case 119: /* where: %empty  */
#line 1070 "yacc_sql.y"
    {
      (yyval.condition_list) = nullptr;
    }
#line 3014 "yacc_sql.cpp"
    break;

  case 120: /* where: WHERE condition_list  */
#line 1073 "yacc_sql.y"
                           {
      (yyval.condition_list) = (yyvsp[0].condition_list);  
    }
#line 3022 "yacc_sql.cpp"
    break;

  case 121: /* condition_list: %empty  */
#line 1079 "yacc_sql.y"
    {
      (yyval.condition_list) = nullptr;
    }
#line 3030 "yacc_sql.cpp"
    break;

  case 122: /* condition_list: condition  */
#line 1082 "yacc_sql.y"
                {
      (yyval.condition_list) = new std::vector<ConditionSqlNode>;
      (yyval.condition_list)->emplace_back(*(yyvsp[0].condition));
      delete (yyvsp[0].condition);
    }
#line 3040 "yacc_sql.cpp"
    break;

  case 123: /* condition_list: condition AND condition_list  */
#line 1087 "yacc_sql.y"
                                   {
      (yyval.condition_list) = (yyvsp[0].condition_list);
      (yyval.condition_list)->emplace_back(*(yyvsp[-2].condition));
      delete (yyvsp[-2].condition);
    }
#line 3050 "yacc_sql.cpp"
    break;

  case 124: /* condition: rel_attr comp_op value  */
#line 1095 "yacc_sql.y"
    {
      (yyval.condition) = new ConditionSqlNode;
      (yyval.condition)->left_is_attr = 1;
      (yyval.condition)->left_attr = *(yyvsp[-2].rel_attr);
      (yyval.condition)->right_is_attr = 0;
      (yyval.condition)->right_value = *(yyvsp[0].value);
      (yyval.condition)->comp = (yyvsp[-1].comp);
      (yyval.condition)->exist_not = 0;

      delete (yyvsp[-2].rel_attr);
      delete (yyvsp[0].value);
    }
#line 3067 "yacc_sql.cpp"
    break;

  case 125: /* condition: value comp_op value  */
#line 1108 "yacc_sql.y"
    {
      (yyval.condition) = new ConditionSqlNode;
      (yyval.condition)->left_is_attr = 0;
      (yyval.condition)->left_value = *(yyvsp[-2].value);
      (yyval.condition)->right_is_attr = 0;
      (yyval.condition)->right_value = *(yyvsp[0].value);
      (yyval.condition)->comp = (yyvsp[-1].comp);
      (yyval.condition)->exist_not = 0;

      delete (yyvsp[-2].value);
      delete (yyvsp[0].value);
    }
#line 3084 "yacc_sql.cpp"
    break;

  case 126: /* condition: rel_attr comp_op rel_attr  */
#line 1121 "yacc_sql.y"
    {
      (yyval.condition) = new ConditionSqlNode;
      (yyval.condition)->left_is_attr = 1;
      (yyval.condition)->left_attr = *(yyvsp[-2].rel_attr);
      (yyval.condition)->right_is_attr = 1;
      (yyval.condition)->right_attr = *(yyvsp[0].rel_attr);
      (yyval.condition)->comp = (yyvsp[-1].comp);
      (yyval.condition)->exist_not = 0;

      delete (yyvsp[-2].rel_attr);
      delete (yyvsp[0].rel_attr);
    }
#line 3101 "yacc_sql.cpp"
    break;

  case 127: /* condition: value comp_op rel_attr  */
#line 1134 "yacc_sql.y"
    {
      (yyval.condition) = new ConditionSqlNode;
      (yyval.condition)->left_is_attr = 0;
      (yyval.condition)->left_value = *(yyvsp[-2].value);
      (yyval.condition)->right_is_attr = 1;
      (yyval.condition)->right_attr = *(yyvsp[0].rel_attr);
      (yyval.condition)->comp = (yyvsp[-1].comp);
      (yyval.condition)->exist_not = 0;

      delete (yyvsp[-2].value);
      delete (yyvsp[0].rel_attr);
    }
#line 3118 "yacc_sql.cpp"
    break;

  case 128: /* condition: rel_attr NOT comp_op value  */
#line 1147 "yacc_sql.y"
    {
      (yyval.condition) = new ConditionSqlNode;
      (yyval.condition)->left_is_attr = 1;
      (yyval.condition)->left_attr = *(yyvsp[-3].rel_attr);
      (yyval.condition)->right_is_attr = 0;
      (yyval.condition)->right_value = *(yyvsp[0].value);
      (yyval.condition)->comp = (yyvsp[-1].comp);
      (yyval.condition)->exist_not = 1;

      delete (yyvsp[-3].rel_attr);
      delete (yyvsp[0].value);
    }
#line 3135 "yacc_sql.cpp"
    break;

  case 129: /* condition: value NOT comp_op value  */
#line 1160 "yacc_sql.y"
    {
      (yyval.condition) = new ConditionSqlNode;
      (yyval.condition)->left_is_attr = 0;
      (yyval.condition)->left_value = *(yyvsp[-3].value);
      (yyval.condition)->right_is_attr = 0;
      (yyval.condition)->right_value = *(yyvsp[0].value);
      (yyval.condition)->comp = (yyvsp[-1].comp);
      (yyval.condition)->exist_not = 1;

      delete (yyvsp[-3].value);
      delete (yyvsp[0].value);
    }
#line 3152 "yacc_sql.cpp"
    break;

  case 130: /* condition: rel_attr NOT comp_op rel_attr  */
#line 1173 "yacc_sql.y"
    {
      (yyval.condition) = new ConditionSqlNode;
      (yyval.condition)->left_is_attr = 1;
      (yyval.condition)->left_attr = *(yyvsp[-3].rel_attr);
      (yyval.condition)->right_is_attr = 1;
      (yyval.condition)->right_attr = *(yyvsp[0].rel_attr);
      (yyval.condition)->comp = (yyvsp[-1].comp);
      (yyval.condition)->exist_not = 1;

      delete (yyvsp[-3].rel_attr);
      delete (yyvsp[0].rel_attr);
    }
#line 3169 "yacc_sql.cpp"
    break;

  case 131: /* condition: value NOT comp_op rel_attr  */
#line 1186 "yacc_sql.y"
    {
      (yyval.condition) = new ConditionSqlNode;
      (yyval.condition)->left_is_attr = 0;
      (yyval.condition)->left_value = *(yyvsp[-3].value);
      (yyval.condition)->right_is_attr = 1;
      (yyval.condition)->right_attr = *(yyvsp[0].rel_attr);
      (yyval.condition)->comp = (yyvsp[-1].comp);
      (yyval.condition)->exist_not = 1;

      delete (yyvsp[-3].value);
      delete (yyvsp[0].rel_attr);
    }
#line 3186 "yacc_sql.cpp"
    break;

  case 132: /* condition: rel_attr IS NULLABLE  */
#line 1199 "yacc_sql.y"
    {
      (yyval.condition) = new ConditionSqlNode;
      (yyval.condition)->left_is_attr = 1;
      (yyval.condition)->left_attr = *(yyvsp[-2].rel_attr);
      // $$->comp = EQ;      // 虽然没用，但还是初始化一个避免后续filter_stmt判断出问题
      (yyval.condition)->is_null = true;
      (yyval.condition)->exist_not = false;

      delete (yyvsp[-2].rel_attr);
    }
#line 3201 "yacc_sql.cpp"
    break;

  case 133: /* condition: value IS NULLABLE  */
#line 1210 "yacc_sql.y"
    {
      (yyval.condition) = new ConditionSqlNode;
      (yyval.condition)->left_is_attr = 0;
      (yyval.condition)->left_value = *(yyvsp[-2].value);
      // $$->comp = EQ;
      (yyval.condition)->is_null = true;
      (yyval.condition)->exist_not = false;

      delete (yyvsp[-2].value);
    }
#line 3216 "yacc_sql.cpp"
    break;

  case 134: /* condition: rel_attr IS NOT NULLABLE  */
#line 1221 "yacc_sql.y"
    {
      (yyval.condition) = new ConditionSqlNode;
      (yyval.condition)->left_is_attr = 1;
      (yyval.condition)->left_attr = *(yyvsp[-3].rel_attr);
      // $$->comp = EQ;
      (yyval.condition)->is_null = true;
      (yyval.condition)->exist_not = true;

      delete (yyvsp[-3].rel_attr);
    }
#line 3231 "yacc_sql.cpp"
    break;

  case 135: /* condition: value IS NOT NULLABLE  */
#line 1232 "yacc_sql.y"
    {
      (yyval.condition) = new ConditionSqlNode;
      (yyval.condition)->left_is_attr = 0;
      (yyval.condition)->left_value = *(yyvsp[-3].value);
      // $$->comp = EQ;
      (yyval.condition)->is_null = true;
      (yyval.condition)->exist_not = true;

      delete (yyvsp[-3].value);
    }
#line 3246 "yacc_sql.cpp"
    break;

  case 136: /* condition: rel_attr comp_op LBRACE sub_select_for_in RBRACE  */
#line 1243 "yacc_sql.y"
    {
      (yyval.condition) = new ConditionSqlNode;
      (yyval.condition)->left_is_attr = 1;
      (yyval.condition)->left_attr = *(yyvsp[-4].rel_attr);
      (yyval.condition)->right_is_attr = 0;    // filter_stmt.cpp 中判断会用到
      (yyval.condition)->comp = (yyvsp[-3].comp);
      (yyval.condition)->exist_not = false;
      (yyval.condition)->in_exprs = (yyvsp[-1].sub_select_for_in);
      delete (yyvsp[-4].rel_attr);
    }
#line 3261 "yacc_sql.cpp"
    break;

  case 137: /* condition: LBRACE sub_select_for_in RBRACE comp_op rel_attr  */
#line 1254 "yacc_sql.y"
    {
      (yyval.condition) = new ConditionSqlNode;
      (yyval.condition)->left_is_attr = 0;
      
      (yyval.condition)->right_is_attr = 1;    // filter_stmt.cpp 中判断会用到
      (yyval.condition)->right_attr = *(yyvsp[0].rel_attr);

      (yyval.condition)->comp = (yyvsp[-1].comp);
      (yyval.condition)->exist_not = false;
      (yyval.condition)->in_exprs = (yyvsp[-3].sub_select_for_in);
      delete (yyvsp[0].rel_attr);
    }
#line 3278 "yacc_sql.cpp"
    break;

  case 138: /* condition: rel_attr NOT comp_op LBRACE sub_select_for_in RBRACE  */
#line 1267 "yacc_sql.y"
    {
      (yyval.condition) = new ConditionSqlNode;
      (yyval.condition)->left_is_attr = 1;
      (yyval.condition)->left_attr = *(yyvsp[-5].rel_attr);
      (yyval.condition)->right_is_attr = 0;    // filter_stmt.cpp 中判断会用到
      (yyval.condition)->comp = (yyvsp[-3].comp);
      (yyval.condition)->exist_not = true;
      (yyval.condition)->in_exprs = (yyvsp[-1].sub_select_for_in);
      delete (yyvsp[-5].rel_attr);
    }
#line 3293 "yacc_sql.cpp"
    break;

  case 139: /* condition: EXISTS LBRACE sub_select_for_in RBRACE  */
#line 1278 "yacc_sql.y"
    {
      (yyval.condition) = new ConditionSqlNode;
      (yyval.condition)->left_is_attr = 0;
      (yyval.condition)->right_is_attr = 0;    // filter_stmt.cpp 中判断会用到
      (yyval.condition)->comp = CompOp::EXISTS_OP;
      (yyval.condition)->exist_not = false;
      (yyval.condition)->in_exprs = (yyvsp[-1].sub_select_for_in);
    }
#line 3306 "yacc_sql.cpp"
    break;

  case 140: /* condition: NOT EXISTS LBRACE sub_select_for_in RBRACE  */
#line 1287 "yacc_sql.y"
    {
      (yyval.condition) = new ConditionSqlNode;
      (yyval.condition)->left_is_attr = 1;
      (yyval.condition)->right_is_attr = 0;    // filter_stmt.cpp 中判断会用到
      (yyval.condition)->comp = CompOp::EXISTS_OP;
      (yyval.condition)->exist_not = true;
      (yyval.condition)->in_exprs = (yyvsp[-1].sub_select_for_in);
    }
#line 3319 "yacc_sql.cpp"
    break;

  case 141: /* sub_select_for_in: value value_list  */
#line 1299 "yacc_sql.y"
                     {
      std::vector<Value> *multi_value = new std::vector<Value>;
      if ((yyvsp[0].value_list) != nullptr) {
        multi_value->swap(*(yyvsp[0].value_list));
      }
      // Value *tmp_value = new Value($1->attr_type(), $1->get_data(), $1->length());
      multi_value->emplace_back(*(yyvsp[-1].value));
      std::reverse(multi_value->begin(), multi_value->end());

      (yyval.sub_select_for_in) = new ListExpr(*multi_value);
      // $$->set_values(*multi_value);
      delete (yyvsp[-1].value);
    }
#line 3337 "yacc_sql.cpp"
    break;

  case 142: /* sub_select_for_in: SELECT rel_attr FROM ID where  */
#line 1313 "yacc_sql.y"
    {
      SelectSqlNode *select_sql_node = new SelectSqlNode();
      if ((yyvsp[-3].rel_attr) != nullptr) {
        std::vector<RelAttrSqlNode> *tmp = new std::vector<RelAttrSqlNode>;
        tmp->emplace_back(*(yyvsp[-3].rel_attr));
        select_sql_node->attributes.swap(*tmp);
        delete (yyvsp[-3].rel_attr);
      }
      select_sql_node->relations.push_back((yyvsp[-1].string));

      if ((yyvsp[0].condition_list) != nullptr) {
        select_sql_node->conditions.swap(*(yyvsp[0].condition_list));
        delete (yyvsp[0].condition_list);
      }
      free((yyvsp[-1].string));
      (yyval.sub_select_for_in) = new SubQueryExpression(select_sql_node);
    }
#line 3359 "yacc_sql.cpp"
    break;

  case 143: /* sub_select_for_in: SELECT agg_rel_attr FROM ID where  */
#line 1331 "yacc_sql.y"
    {
      SelectAggSqlNode *select_agg_sql_node = new SelectAggSqlNode();
      if ((yyvsp[-3].agg_rel_attr) != nullptr) {
        std::vector<AggRelAttrSqlNode> *tmp = new std::vector<AggRelAttrSqlNode>;
        tmp->emplace_back(*(yyvsp[-3].agg_rel_attr));
        select_agg_sql_node->agg_attributes.swap(*tmp);
        delete (yyvsp[-3].agg_rel_attr);
      }
      select_agg_sql_node->relations.push_back((yyvsp[-1].string));

      if ((yyvsp[0].condition_list) != nullptr) {
        select_agg_sql_node->conditions.swap(*(yyvsp[0].condition_list));
        delete (yyvsp[0].condition_list);
      }
      free((yyvsp[-1].string));
      (yyval.sub_select_for_in) = new SubQueryExpression(select_agg_sql_node);
    }
#line 3381 "yacc_sql.cpp"
    break;

  case 144: /* sub_select_for_in: SELECT '*' FROM ID where  */
#line 1349 "yacc_sql.y"
    {
      SelectSqlNode *select_sql_node = new SelectSqlNode();
      std::vector<RelAttrSqlNode> *tmp = new std::vector<RelAttrSqlNode>;
      RelAttrSqlNode attr;
      attr.relation_name  = "";
      attr.attribute_name = "*";
      tmp->emplace_back(attr);
      select_sql_node->attributes.swap(*tmp);
        
      select_sql_node->relations.push_back((yyvsp[-1].string));

      if ((yyvsp[0].condition_list) != nullptr) {
        select_sql_node->conditions.swap(*(yyvsp[0].condition_list));
        delete (yyvsp[0].condition_list);
      }
      free((yyvsp[-1].string));
      (yyval.sub_select_for_in) = new SubQueryExpression(select_sql_node);
    }
#line 3404 "yacc_sql.cpp"
    break;

  case 145: /* comp_op: EQ  */
#line 1370 "yacc_sql.y"
         { (yyval.comp) = EQUAL_TO; }
#line 3410 "yacc_sql.cpp"
    break;

  case 146: /* comp_op: LT  */
#line 1371 "yacc_sql.y"
         { (yyval.comp) = LESS_THAN; }
#line 3416 "yacc_sql.cpp"
    break;

  case 147: /* comp_op: GT  */
#line 1372 "yacc_sql.y"
         { (yyval.comp) = GREAT_THAN; }
#line 3422 "yacc_sql.cpp"
    break;

  case 148: /* comp_op: LE  */
#line 1373 "yacc_sql.y"
         { (yyval.comp) = LESS_EQUAL; }
#line 3428 "yacc_sql.cpp"
    break;

  case 149: /* comp_op: GE  */
#line 1374 "yacc_sql.y"
         { (yyval.comp) = GREAT_EQUAL; }
#line 3434 "yacc_sql.cpp"
    break;

  case 150: /* comp_op: NE  */
#line 1375 "yacc_sql.y"
         { (yyval.comp) = NOT_EQUAL; }
#line 3440 "yacc_sql.cpp"
    break;

  case 151: /* comp_op: LIKE  */
#line 1376 "yacc_sql.y"
           { (yyval.comp) = LIKE_TO; }
#line 3446 "yacc_sql.cpp"
    break;

  case 152: /* comp_op: IN  */
#line 1377 "yacc_sql.y"
         { (yyval.comp) = IN_OP; }
#line 3452 "yacc_sql.cpp"
    break;

  case 153: /* load_data_stmt: LOAD DATA INFILE SSS INTO TABLE ID  */
#line 1382 "yacc_sql.y"
    {
      char *tmp_file_name = common::substr((yyvsp[-3].string), 1, strlen((yyvsp[-3].string)) - 2);
      
      (yyval.sql_node) = new ParsedSqlNode(SCF_LOAD_DATA);
      (yyval.sql_node)->load_data.relation_name = (yyvsp[0].string);
      (yyval.sql_node)->load_data.file_name = tmp_file_name;
      free((yyvsp[0].string));
      free(tmp_file_name);
    }
#line 3466 "yacc_sql.cpp"
    break;

  case 154: /* explain_stmt: EXPLAIN command_wrapper  */
#line 1395 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_EXPLAIN);
      (yyval.sql_node)->explain.sql_node = std::unique_ptr<ParsedSqlNode>((yyvsp[0].sql_node));
    }
#line 3475 "yacc_sql.cpp"
    break;

  case 155: /* set_variable_stmt: SET ID EQ value  */
#line 1403 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_SET_VARIABLE);
      (yyval.sql_node)->set_variable.name  = (yyvsp[-2].string);
      (yyval.sql_node)->set_variable.value = *(yyvsp[0].value);
      free((yyvsp[-2].string));
      delete (yyvsp[0].value);
    }
#line 3487 "yacc_sql.cpp"
    break;


#line 3491 "yacc_sql.cpp"

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
      {
        yypcontext_t yyctx
          = {yyssp, yytoken, &yylloc};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (&yylloc, sql_string, sql_result, scanner, yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
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
                      yytoken, &yylval, &yylloc, sql_string, sql_result, scanner);
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, yylsp, sql_string, sql_result, scanner);
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
  yyerror (&yylloc, sql_string, sql_result, scanner, YY_("memory exhausted"));
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
                  yytoken, &yylval, &yylloc, sql_string, sql_result, scanner);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, yylsp, sql_string, sql_result, scanner);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 1415 "yacc_sql.y"

//_____________________________________________________________________
extern void scan_string(const char *str, yyscan_t scanner);

int sql_parse(const char *s, ParsedSqlResult *sql_result) {
  yyscan_t scanner;
  yylex_init(&scanner);
  scan_string(s, scanner);
  int result = yyparse(s, sql_result, scanner);
  yylex_destroy(scanner);
  return result;
}
