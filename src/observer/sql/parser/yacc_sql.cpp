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
  YYSYMBOL_AS = 19,                        /* AS  */
  YYSYMBOL_ASC = 20,                       /* ASC  */
  YYSYMBOL_SHOW = 21,                      /* SHOW  */
  YYSYMBOL_SYNC = 22,                      /* SYNC  */
  YYSYMBOL_INSERT = 23,                    /* INSERT  */
  YYSYMBOL_DELETE = 24,                    /* DELETE  */
  YYSYMBOL_UPDATE = 25,                    /* UPDATE  */
  YYSYMBOL_LBRACE = 26,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 27,                    /* RBRACE  */
  YYSYMBOL_COMMA = 28,                     /* COMMA  */
  YYSYMBOL_TRX_BEGIN = 29,                 /* TRX_BEGIN  */
  YYSYMBOL_TRX_COMMIT = 30,                /* TRX_COMMIT  */
  YYSYMBOL_TRX_ROLLBACK = 31,              /* TRX_ROLLBACK  */
  YYSYMBOL_INT_T = 32,                     /* INT_T  */
  YYSYMBOL_STRING_T = 33,                  /* STRING_T  */
  YYSYMBOL_FLOAT_T = 34,                   /* FLOAT_T  */
  YYSYMBOL_DATE_T = 35,                    /* DATE_T  */
  YYSYMBOL_HELP = 36,                      /* HELP  */
  YYSYMBOL_EXIT = 37,                      /* EXIT  */
  YYSYMBOL_UNIQUE = 38,                    /* UNIQUE  */
  YYSYMBOL_ORDER = 39,                     /* ORDER  */
  YYSYMBOL_BY = 40,                        /* BY  */
  YYSYMBOL_DOT = 41,                       /* DOT  */
  YYSYMBOL_INTO = 42,                      /* INTO  */
  YYSYMBOL_VALUES = 43,                    /* VALUES  */
  YYSYMBOL_FROM = 44,                      /* FROM  */
  YYSYMBOL_WHERE = 45,                     /* WHERE  */
  YYSYMBOL_INNER = 46,                     /* INNER  */
  YYSYMBOL_JOIN = 47,                      /* JOIN  */
  YYSYMBOL_AND = 48,                       /* AND  */
  YYSYMBOL_SET = 49,                       /* SET  */
  YYSYMBOL_ON = 50,                        /* ON  */
  YYSYMBOL_LOAD = 51,                      /* LOAD  */
  YYSYMBOL_DATA = 52,                      /* DATA  */
  YYSYMBOL_INFILE = 53,                    /* INFILE  */
  YYSYMBOL_EXPLAIN = 54,                   /* EXPLAIN  */
  YYSYMBOL_LIKE = 55,                      /* LIKE  */
  YYSYMBOL_NOT = 56,                       /* NOT  */
  YYSYMBOL_IS = 57,                        /* IS  */
  YYSYMBOL_NULLABLE = 58,                  /* NULLABLE  */
  YYSYMBOL_EQ = 59,                        /* EQ  */
  YYSYMBOL_LT = 60,                        /* LT  */
  YYSYMBOL_GT = 61,                        /* GT  */
  YYSYMBOL_LE = 62,                        /* LE  */
  YYSYMBOL_GE = 63,                        /* GE  */
  YYSYMBOL_NE = 64,                        /* NE  */
  YYSYMBOL_NUMBER = 65,                    /* NUMBER  */
  YYSYMBOL_FLOAT = 66,                     /* FLOAT  */
  YYSYMBOL_ID = 67,                        /* ID  */
  YYSYMBOL_DATE = 68,                      /* DATE  */
  YYSYMBOL_SSS = 69,                       /* SSS  */
  YYSYMBOL_70_ = 70,                       /* '+'  */
  YYSYMBOL_71_ = 71,                       /* '-'  */
  YYSYMBOL_72_ = 72,                       /* '*'  */
  YYSYMBOL_73_ = 73,                       /* '/'  */
  YYSYMBOL_UMINUS = 74,                    /* UMINUS  */
  YYSYMBOL_YYACCEPT = 75,                  /* $accept  */
  YYSYMBOL_commands = 76,                  /* commands  */
  YYSYMBOL_command_wrapper = 77,           /* command_wrapper  */
  YYSYMBOL_exit_stmt = 78,                 /* exit_stmt  */
  YYSYMBOL_help_stmt = 79,                 /* help_stmt  */
  YYSYMBOL_sync_stmt = 80,                 /* sync_stmt  */
  YYSYMBOL_begin_stmt = 81,                /* begin_stmt  */
  YYSYMBOL_commit_stmt = 82,               /* commit_stmt  */
  YYSYMBOL_rollback_stmt = 83,             /* rollback_stmt  */
  YYSYMBOL_drop_table_stmt = 84,           /* drop_table_stmt  */
  YYSYMBOL_show_tables_stmt = 85,          /* show_tables_stmt  */
  YYSYMBOL_desc_table_stmt = 86,           /* desc_table_stmt  */
  YYSYMBOL_create_index_stmt = 87,         /* create_index_stmt  */
  YYSYMBOL_id_list = 88,                   /* id_list  */
  YYSYMBOL_drop_index_stmt = 89,           /* drop_index_stmt  */
  YYSYMBOL_show_index_stmt = 90,           /* show_index_stmt  */
  YYSYMBOL_create_table_stmt = 91,         /* create_table_stmt  */
  YYSYMBOL_attr_def_list = 92,             /* attr_def_list  */
  YYSYMBOL_attr_def = 93,                  /* attr_def  */
  YYSYMBOL_number = 94,                    /* number  */
  YYSYMBOL_type = 95,                      /* type  */
  YYSYMBOL_insert_stmt = 96,               /* insert_stmt  */
  YYSYMBOL_row_value_list = 97,            /* row_value_list  */
  YYSYMBOL_value_list = 98,                /* value_list  */
  YYSYMBOL_value = 99,                     /* value  */
  YYSYMBOL_delete_stmt = 100,              /* delete_stmt  */
  YYSYMBOL_update_stmt = 101,              /* update_stmt  */
  YYSYMBOL_update_list = 102,              /* update_list  */
  YYSYMBOL_sub_select = 103,               /* sub_select  */
  YYSYMBOL_select_stmt = 104,              /* select_stmt  */
  YYSYMBOL_order_by_unit = 105,            /* order_by_unit  */
  YYSYMBOL_order_by_list = 106,            /* order_by_list  */
  YYSYMBOL_opt_order_by = 107,             /* opt_order_by  */
  YYSYMBOL_calc_stmt = 108,                /* calc_stmt  */
  YYSYMBOL_expression_list = 109,          /* expression_list  */
  YYSYMBOL_expression = 110,               /* expression  */
  YYSYMBOL_select_attr = 111,              /* select_attr  */
  YYSYMBOL_select_agg_attr = 112,          /* select_agg_attr  */
  YYSYMBOL_agg_op = 113,                   /* agg_op  */
  YYSYMBOL_rel_attr = 114,                 /* rel_attr  */
  YYSYMBOL_attr_list = 115,                /* attr_list  */
  YYSYMBOL_agg_rel_attr = 116,             /* agg_rel_attr  */
  YYSYMBOL_agg_attr_list = 117,            /* agg_attr_list  */
  YYSYMBOL_rel_list = 118,                 /* rel_list  */
  YYSYMBOL_rel_list_join = 119,            /* rel_list_join  */
  YYSYMBOL_inner_join_conditions = 120,    /* inner_join_conditions  */
  YYSYMBOL_where = 121,                    /* where  */
  YYSYMBOL_condition_list = 122,           /* condition_list  */
  YYSYMBOL_condition = 123,                /* condition  */
  YYSYMBOL_sub_select_for_in = 124,        /* sub_select_for_in  */
  YYSYMBOL_comp_op = 125,                  /* comp_op  */
  YYSYMBOL_load_data_stmt = 126,           /* load_data_stmt  */
  YYSYMBOL_explain_stmt = 127,             /* explain_stmt  */
  YYSYMBOL_set_variable_stmt = 128,        /* set_variable_stmt  */
  YYSYMBOL_opt_semicolon = 129             /* opt_semicolon  */
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
#define YYLAST   404

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  75
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  55
/* YYNRULES -- Number of rules.  */
#define YYNRULES  163
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  342

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   325


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
       2,     2,    72,    70,     2,    71,     2,    73,     2,     2,
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
      65,    66,    67,    68,    69,    74
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   233,   233,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   261,   265,   271,   276,   282,   288,   294,
     300,   307,   313,   321,   340,   363,   366,   379,   390,   398,
     417,   420,   433,   442,   451,   460,   469,   478,   489,   492,
     493,   494,   495,   498,   523,   526,   546,   549,   560,   564,
     568,   573,   578,   585,   597,   622,   625,   638,   643,   661,
     682,   711,   731,   752,   782,   814,   822,   833,   843,   853,
     865,   879,   882,   887,   896,   899,   905,   915,   920,   931,
     934,   937,   940,   943,   947,   950,   958,   965,   977,   989,
     990,   991,   992,   993,   997,  1002,  1009,  1023,  1045,  1048,
    1061,  1068,  1074,  1086,  1089,  1103,  1106,  1119,  1131,  1146,
    1149,  1162,  1177,  1180,  1186,  1195,  1198,  1204,  1207,  1212,
    1219,  1232,  1245,  1258,  1271,  1284,  1297,  1310,  1323,  1334,
    1345,  1356,  1367,  1378,  1391,  1402,  1411,  1424,  1437,  1455,
    1473,  1495,  1496,  1497,  1498,  1499,  1500,  1501,  1502,  1506,
    1519,  1527,  1537,  1538
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
  "EXISTS", "COUNT", "AVG", "SUM", "DESC", "AS", "ASC", "SHOW", "SYNC",
  "INSERT", "DELETE", "UPDATE", "LBRACE", "RBRACE", "COMMA", "TRX_BEGIN",
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

#define YYPACT_NINF (-234)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     211,    33,    81,   128,    -2,     2,   105,  -234,    34,    37,
      28,  -234,  -234,  -234,  -234,  -234,    39,    47,   211,    60,
     113,  -234,  -234,  -234,  -234,  -234,  -234,  -234,  -234,  -234,
    -234,  -234,  -234,  -234,  -234,  -234,  -234,  -234,  -234,  -234,
    -234,  -234,    55,    67,   137,    86,   115,   128,  -234,  -234,
    -234,  -234,  -234,   128,  -234,  -234,   138,  -234,  -234,  -234,
    -234,  -234,    -8,  -234,   144,   151,   172,   175,   176,  -234,
    -234,   156,   139,   145,   164,   146,   173,  -234,  -234,  -234,
    -234,   191,   178,   171,  -234,   181,    77,  -234,   128,   128,
     128,   128,   128,   182,   183,   185,   186,   -15,   187,  -234,
     207,  -234,   188,   214,   216,   189,   231,   194,   205,   206,
     208,   209,  -234,  -234,    98,    98,  -234,  -234,  -234,   255,
      15,   247,    -1,   265,   175,   176,  -234,   269,    52,  -234,
     239,  -234,   259,    93,   274,   277,   237,  -234,   238,   240,
     241,   262,   247,   216,   216,  -234,   243,  -234,  -234,  -234,
     231,   280,    32,   297,    80,   117,  -234,   264,   225,   307,
    -234,  -234,  -234,  -234,    -7,   205,   287,   248,   290,  -234,
     247,    16,     8,   216,   278,  -234,   291,   292,    32,     5,
     292,   294,   293,  -234,  -234,   101,    49,  -234,  -234,  -234,
    -234,  -234,  -234,   219,   101,    53,   201,    52,   312,  -234,
     295,   257,   260,   268,  -234,   274,  -234,   299,   261,   216,
     263,   247,  -234,   282,    83,   216,   278,   296,  -234,  -234,
     231,   304,   305,   289,   298,   300,  -234,   101,    32,   219,
     276,  -234,  -234,  -234,   213,   279,  -234,    32,  -234,  -234,
    -234,    13,   271,   216,  -234,  -234,   308,  -234,  -234,   272,
     313,   299,   278,   247,  -234,   281,    52,    52,     8,  -234,
    -234,   283,   292,   315,  -234,   284,   285,   286,   187,   314,
    -234,  -234,  -234,    32,  -234,  -234,  -234,   318,   302,   303,
     301,  -234,   111,   299,  -234,   322,  -234,  -234,    83,    83,
      83,  -234,    18,   326,  -234,  -234,   329,  -234,   216,   216,
     216,  -234,  -234,   330,  -234,   306,   309,   225,   310,  -234,
    -234,  -234,     8,  -234,  -234,  -234,  -234,   311,   283,   231,
    -234,  -234,  -234,  -234,   216,   216,   295,  -234,  -234,   167,
    -234,   292,   331,   332,  -234,  -234,  -234,   334,  -234,  -234,
     315,  -234
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,    26,     0,     0,
       0,    27,    28,    29,    25,    24,     0,     0,     0,     0,
     162,    23,    22,    15,    16,    17,    18,     9,    10,    11,
      12,    14,    13,     8,     5,     7,     6,     4,     3,    19,
      20,    21,     0,     0,     0,     0,     0,     0,    62,    58,
      59,    60,    61,     0,    95,    86,    87,    99,   100,   101,
     102,   103,   104,    96,     0,     0,     0,   108,   113,    32,
      31,     0,     0,     0,     0,     0,     0,   160,     1,   163,
       2,     0,     0,     0,    30,     0,     0,    94,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    97,
       0,    98,     0,     0,   125,     0,     0,     0,     0,     0,
       0,     0,    93,    88,    89,    90,    91,    92,   106,   105,
     115,   115,     0,     0,   108,   113,    38,     0,   127,    63,
       0,   161,     0,     0,    40,     0,     0,    37,     0,     0,
       0,     0,   115,   125,   125,   111,     0,   110,   109,   114,
       0,     0,     0,     0,     0,     0,   126,   128,     0,     0,
      49,    50,    51,    52,    43,     0,     0,     0,     0,   107,
     115,   115,   119,   125,    84,    71,     0,    56,     0,     0,
      56,     0,     0,   158,   157,     0,     0,   151,   152,   153,
     154,   155,   156,     0,     0,     0,     0,   127,     0,    67,
      65,     0,     0,     0,    46,    40,    39,    35,     0,   125,
       0,   115,   116,     0,   122,   125,    84,     0,    70,   112,
       0,     0,     0,     0,     0,     0,   147,     0,     0,     0,
       0,   139,   131,   133,     0,     0,   138,     0,   130,   132,
     129,     0,     0,   125,   159,    48,     0,    47,    41,     0,
       0,    35,    84,   115,   118,     0,     0,     0,   119,    72,
      74,    81,    56,    54,   145,     0,     0,     0,     0,     0,
     135,   137,   141,     0,   134,   136,   140,     0,     0,     0,
       0,    64,    42,    35,    33,     0,    73,   117,   122,   122,
     122,   120,    75,    82,    85,    57,     0,    53,   125,   125,
     125,   143,   146,     0,   142,     0,     0,     0,     0,    44,
      36,    34,   119,   124,   123,    77,    78,     0,    81,     0,
     150,   148,   149,   144,   125,   125,    65,    45,   121,    76,
      83,    56,     0,     0,    66,    79,    80,     0,    68,    69,
      54,    55
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -234,  -234,   338,  -234,  -234,  -234,  -234,  -234,  -234,  -234,
    -234,  -234,  -234,  -233,  -234,  -234,  -234,   157,   198,  -234,
    -234,  -234,    24,  -176,  -105,  -234,  -234,    40,    58,  -234,
    -234,    51,  -204,  -234,   316,   154,  -234,  -234,  -234,    -4,
     246,   -95,   242,  -115,  -227,  -226,  -141,   174,   -66,  -170,
    -148,  -234,  -234,  -234,  -234
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,   250,    31,    32,    33,   166,   134,   246,
     164,    34,   297,   221,    54,    35,    36,   243,   200,    37,
     293,   294,   218,    38,    55,    56,    64,    65,    66,   155,
      99,    68,   101,   143,   215,   258,   129,   156,   157,   181,
     193,    39,    40,    41,    80
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      67,   131,   174,   175,   226,   125,   144,   196,   222,    57,
      58,    93,   260,    59,    60,    61,    57,    58,   285,   202,
      59,    60,    61,   154,    57,    58,   145,   173,    59,    60,
      61,   291,   216,    94,   139,   210,   315,   229,   316,    42,
     146,    43,   179,   140,   140,   177,   234,   180,   286,   203,
     310,   204,   122,   199,   213,   209,   212,   123,   269,   317,
      78,   141,   312,   313,   314,    62,   151,   277,   252,    69,
      63,    44,    62,   180,   259,   214,    72,   223,   152,   268,
      62,    73,   142,   211,   225,   328,   295,    45,   232,    46,
      48,   238,   154,   183,   124,    74,   254,    49,    50,    76,
      51,    52,   281,   303,   112,   230,    75,   231,   153,   235,
      48,   236,    70,    71,   183,   262,    79,    49,    50,    62,
      51,    52,    81,   180,   270,   160,   161,   162,   163,   274,
     183,   256,   180,   257,    82,   184,   185,   186,   287,   187,
     188,   189,   190,   191,   192,    83,   279,    89,    90,    91,
      92,   154,   154,    84,    47,   337,   184,   320,   321,   322,
     187,   188,   189,   190,   191,   192,    88,   308,   180,   309,
      91,    92,   184,   194,   195,   224,   187,   188,   189,   190,
     191,   192,    85,   332,   333,   335,    48,   336,    95,   233,
     289,   290,   239,    49,    50,    96,    51,    52,    97,    53,
     102,    86,   199,    98,   100,   106,   103,    87,    89,    90,
      91,    92,   104,   105,   331,     1,     2,   108,    57,    58,
       3,     4,    59,    60,    61,   271,   107,   237,   109,     5,
     275,   111,     6,     7,     8,     9,    10,   278,   110,   273,
      11,    12,    13,   114,   115,   116,   117,    14,    15,   118,
     119,   198,   120,   121,    62,   126,   130,   127,   136,    48,
      16,   128,    17,   132,   301,    18,    49,    50,    62,    51,
      52,    48,   133,   135,   138,   140,   137,    48,    49,    50,
      62,    51,    52,    48,    49,    50,    62,    51,    52,    48,
      49,    50,   147,    51,    52,   150,    49,    50,   158,    51,
      52,   159,   165,   167,   168,   169,   178,   170,   171,   172,
     176,   182,   197,   201,   206,   207,   208,   217,   219,   228,
     220,   227,   241,   242,   244,   245,   247,   249,   251,   255,
     253,   263,   264,   265,   272,   282,   261,   276,   280,   283,
     284,   302,   266,   296,   267,   304,   305,   306,   288,   311,
     292,   298,   299,   300,   318,   319,    77,   323,   338,   339,
     307,   340,   248,   205,   341,   326,   334,   149,   327,   330,
     148,   240,     0,   324,     0,     0,   325,     0,   329,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   113
};

static const yytype_int16 yycheck[] =
{
       4,   106,   143,   144,   180,   100,   121,   155,   178,    11,
      12,    19,   216,    15,    16,    17,    11,    12,   251,    26,
      15,    16,    17,   128,    11,    12,    27,   142,    15,    16,
      17,   258,   173,    41,    19,    19,    18,   185,    20,     6,
      41,     8,    10,    28,    28,   150,   194,   152,   252,    56,
     283,    58,    67,   158,    46,   170,   171,    72,   228,    41,
       0,    46,   288,   289,   290,    67,    14,   237,   209,    67,
      72,    38,    67,   178,   215,    67,    42,    72,    26,   227,
      67,    44,    67,    67,   179,   312,   262,     6,   193,     8,
      58,   196,   197,    13,    98,    67,   211,    65,    66,    52,
      68,    69,   243,   273,    27,    56,    67,    58,    56,    56,
      58,    58,     7,     8,    13,   220,     3,    65,    66,    67,
      68,    69,    67,   228,   229,    32,    33,    34,    35,   234,
      13,    48,   237,    50,    67,    55,    56,    57,   253,    59,
      60,    61,    62,    63,    64,     8,   241,    70,    71,    72,
      73,   256,   257,    67,    26,   331,    55,   298,   299,   300,
      59,    60,    61,    62,    63,    64,    28,    56,   273,    58,
      72,    73,    55,    56,    57,   179,    59,    60,    61,    62,
      63,    64,    67,   324,   325,    18,    58,    20,    44,   193,
     256,   257,   196,    65,    66,    44,    68,    69,    26,    71,
      44,    47,   307,    28,    28,    59,    67,    53,    70,    71,
      72,    73,    67,    49,   319,     4,     5,    26,    11,    12,
       9,    10,    15,    16,    17,   229,    53,    26,    50,    18,
     234,    50,    21,    22,    23,    24,    25,   241,    67,    26,
      29,    30,    31,    89,    90,    91,    92,    36,    37,    67,
      67,    26,    67,    67,    67,    67,    67,    43,    50,    58,
      49,    45,    51,    69,   268,    54,    65,    66,    67,    68,
      69,    58,    67,    67,    19,    28,    67,    58,    65,    66,
      67,    68,    69,    58,    65,    66,    67,    68,    69,    58,
      65,    66,    27,    68,    69,    26,    65,    66,    59,    68,
      69,    42,    28,    26,    67,    67,    26,    67,    67,    47,
      67,    14,    48,     6,    27,    67,    26,    39,    27,    26,
      28,    27,    10,    28,    67,    65,    58,    28,    67,    47,
      67,    27,    27,    44,    58,    27,    40,    58,    67,    67,
      27,    27,    44,    28,    44,    27,    44,    44,    67,    27,
      67,    67,    67,    67,    28,    26,    18,    27,    27,    27,
      59,    27,   205,   165,   340,   307,   326,   125,    58,   318,
     124,   197,    -1,    67,    -1,    -1,    67,    -1,    67,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    88
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     4,     5,     9,    10,    18,    21,    22,    23,    24,
      25,    29,    30,    31,    36,    37,    49,    51,    54,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    89,    90,    91,    96,   100,   101,   104,   108,   126,
     127,   128,     6,     8,    38,     6,     8,    26,    58,    65,
      66,    68,    69,    71,    99,   109,   110,    11,    12,    15,
      16,    17,    67,    72,   111,   112,   113,   114,   116,    67,
       7,     8,    42,    44,    67,    67,    52,    77,     0,     3,
     129,    67,    67,     8,    67,    67,   110,   110,    28,    70,
      71,    72,    73,    19,    41,    44,    44,    26,    28,   115,
      28,   117,    44,    67,    67,    49,    59,    53,    26,    50,
      67,    50,    27,   109,   110,   110,   110,   110,    67,    67,
      67,    67,    67,    72,   114,   116,    67,    43,    45,   121,
      67,    99,    69,    67,    93,    67,    50,    67,    19,    19,
      28,    46,    67,   118,   118,    27,    41,    27,   115,   117,
      26,    14,    26,    56,    99,   114,   122,   123,    59,    42,
      32,    33,    34,    35,    95,    28,    92,    26,    67,    67,
      67,    67,    47,   118,   121,   121,    67,    99,    26,    10,
      99,   124,    14,    13,    55,    56,    57,    59,    60,    61,
      62,    63,    64,   125,    56,    57,   125,    48,    26,    99,
     103,     6,    26,    56,    58,    93,    27,    67,    26,   118,
      19,    67,   118,    46,    67,   119,   121,    39,   107,    27,
      28,    98,   124,    72,   114,   116,    98,    27,    26,   125,
      56,    58,    99,   114,   125,    56,    58,    26,    99,   114,
     122,    10,    28,   102,    67,    65,    94,    58,    92,    28,
      88,    67,   121,    67,   118,    47,    48,    50,   120,   121,
     107,    40,    99,    27,    27,    44,    44,    44,   125,   124,
      99,   114,    58,    26,    99,   114,    58,   124,   114,   116,
      67,   121,    27,    67,    27,    88,   107,   118,    67,   123,
     123,   119,    67,   105,   106,    98,    28,    97,    67,    67,
      67,   114,    27,   124,    27,    44,    44,    59,    56,    58,
      88,    27,   120,   120,   120,    18,    20,    41,    28,    26,
     121,   121,   121,    27,    67,    67,   103,    58,   119,    67,
     106,    99,   121,   121,   102,    18,    20,    98,    27,    27,
      27,    97
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    75,    76,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    87,    88,    88,    89,    90,    91,
      92,    92,    93,    93,    93,    93,    93,    93,    94,    95,
      95,    95,    95,    96,    97,    97,    98,    98,    99,    99,
      99,    99,    99,   100,   101,   102,   102,   103,   103,   103,
     104,   104,   104,   104,   104,   105,   105,   105,   105,   105,
     105,   106,   106,   106,   107,   107,   108,   109,   109,   110,
     110,   110,   110,   110,   110,   110,   111,   111,   112,   113,
     113,   113,   113,   113,   114,   114,   114,   114,   115,   115,
     116,   116,   116,   117,   117,   118,   118,   118,   118,   119,
     119,   119,   120,   120,   120,   121,   121,   122,   122,   122,
     123,   123,   123,   123,   123,   123,   123,   123,   123,   123,
     123,   123,   123,   123,   123,   123,   123,   124,   124,   124,
     124,   125,   125,   125,   125,   125,   125,   125,   125,   126,
     127,   128,   129,   129
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
       7,     6,     8,     9,     8,     1,     3,     2,     2,     4,
       4,     0,     1,     3,     0,     3,     2,     1,     3,     3,
       3,     3,     3,     3,     2,     1,     1,     2,     2,     1,
       1,     1,     1,     1,     1,     3,     3,     5,     0,     3,
       4,     4,     6,     0,     3,     0,     3,     5,     4,     0,
       3,     5,     0,     3,     3,     0,     2,     0,     1,     3,
       3,     3,     3,     3,     4,     4,     4,     4,     3,     3,
       4,     4,     5,     5,     6,     4,     5,     2,     5,     5,
       5,     1,     1,     1,     1,     1,     1,     1,     1,     7,
       2,     4,     0,     1
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
#line 234 "yacc_sql.y"
  {
    std::unique_ptr<ParsedSqlNode> sql_node = std::unique_ptr<ParsedSqlNode>((yyvsp[-1].sql_node));
    sql_result->add_sql_node(std::move(sql_node));
  }
#line 1898 "yacc_sql.cpp"
    break;

  case 24: /* exit_stmt: EXIT  */
#line 265 "yacc_sql.y"
         {
      (void)yynerrs;  // 这么写为了消除yynerrs未使用的告警。如果你有更好的方法欢迎提PR
      (yyval.sql_node) = new ParsedSqlNode(SCF_EXIT);
    }
#line 1907 "yacc_sql.cpp"
    break;

  case 25: /* help_stmt: HELP  */
#line 271 "yacc_sql.y"
         {
      (yyval.sql_node) = new ParsedSqlNode(SCF_HELP);
    }
#line 1915 "yacc_sql.cpp"
    break;

  case 26: /* sync_stmt: SYNC  */
#line 276 "yacc_sql.y"
         {
      (yyval.sql_node) = new ParsedSqlNode(SCF_SYNC);
    }
#line 1923 "yacc_sql.cpp"
    break;

  case 27: /* begin_stmt: TRX_BEGIN  */
#line 282 "yacc_sql.y"
               {
      (yyval.sql_node) = new ParsedSqlNode(SCF_BEGIN);
    }
#line 1931 "yacc_sql.cpp"
    break;

  case 28: /* commit_stmt: TRX_COMMIT  */
#line 288 "yacc_sql.y"
               {
      (yyval.sql_node) = new ParsedSqlNode(SCF_COMMIT);
    }
#line 1939 "yacc_sql.cpp"
    break;

  case 29: /* rollback_stmt: TRX_ROLLBACK  */
#line 294 "yacc_sql.y"
                  {
      (yyval.sql_node) = new ParsedSqlNode(SCF_ROLLBACK);
    }
#line 1947 "yacc_sql.cpp"
    break;

  case 30: /* drop_table_stmt: DROP TABLE ID  */
#line 300 "yacc_sql.y"
                  {
      (yyval.sql_node) = new ParsedSqlNode(SCF_DROP_TABLE);
      (yyval.sql_node)->drop_table.relation_name = (yyvsp[0].string);
      free((yyvsp[0].string));
    }
#line 1957 "yacc_sql.cpp"
    break;

  case 31: /* show_tables_stmt: SHOW TABLES  */
#line 307 "yacc_sql.y"
                {
      (yyval.sql_node) = new ParsedSqlNode(SCF_SHOW_TABLES);
    }
#line 1965 "yacc_sql.cpp"
    break;

  case 32: /* desc_table_stmt: DESC ID  */
#line 313 "yacc_sql.y"
             {
      (yyval.sql_node) = new ParsedSqlNode(SCF_DESC_TABLE);
      (yyval.sql_node)->desc_table.relation_name = (yyvsp[0].string);
      free((yyvsp[0].string));
    }
#line 1975 "yacc_sql.cpp"
    break;

  case 33: /* create_index_stmt: CREATE INDEX ID ON ID LBRACE ID id_list RBRACE  */
#line 322 "yacc_sql.y"
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
#line 1998 "yacc_sql.cpp"
    break;

  case 34: /* create_index_stmt: CREATE UNIQUE INDEX ID ON ID LBRACE ID id_list RBRACE  */
#line 341 "yacc_sql.y"
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
#line 2021 "yacc_sql.cpp"
    break;

  case 35: /* id_list: %empty  */
#line 363 "yacc_sql.y"
    {
      (yyval.id_lists) = nullptr;
    }
#line 2029 "yacc_sql.cpp"
    break;

  case 36: /* id_list: COMMA ID id_list  */
#line 367 "yacc_sql.y"
    {
      if ((yyvsp[0].id_lists) != nullptr) {
        (yyval.id_lists) = (yyvsp[0].id_lists);
      } else {
        (yyval.id_lists) = new std::vector<std::string>;
      }
      (yyval.id_lists)->emplace_back((yyvsp[-1].string));
      delete (yyvsp[-1].string);
    }
#line 2043 "yacc_sql.cpp"
    break;

  case 37: /* drop_index_stmt: DROP INDEX ID ON ID  */
#line 380 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_DROP_INDEX);
      (yyval.sql_node)->drop_index.index_name = (yyvsp[-2].string);
      (yyval.sql_node)->drop_index.relation_name = (yyvsp[0].string);
      free((yyvsp[-2].string));
      free((yyvsp[0].string));
    }
#line 2055 "yacc_sql.cpp"
    break;

  case 38: /* show_index_stmt: SHOW INDEX FROM ID  */
#line 391 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_SHOW_INDEX);
      (yyval.sql_node)->show_index.relation_name = (yyvsp[0].string);
      free((yyvsp[0].string));
    }
#line 2065 "yacc_sql.cpp"
    break;

  case 39: /* create_table_stmt: CREATE TABLE ID LBRACE attr_def attr_def_list RBRACE  */
#line 399 "yacc_sql.y"
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
#line 2085 "yacc_sql.cpp"
    break;

  case 40: /* attr_def_list: %empty  */
#line 417 "yacc_sql.y"
    {
      (yyval.attr_infos) = nullptr;
    }
#line 2093 "yacc_sql.cpp"
    break;

  case 41: /* attr_def_list: COMMA attr_def attr_def_list  */
#line 421 "yacc_sql.y"
    {
      if ((yyvsp[0].attr_infos) != nullptr) {
        (yyval.attr_infos) = (yyvsp[0].attr_infos);
      } else {
        (yyval.attr_infos) = new std::vector<AttrInfoSqlNode>;
      }
      (yyval.attr_infos)->emplace_back(*(yyvsp[-1].attr_info));
      delete (yyvsp[-1].attr_info);
    }
#line 2107 "yacc_sql.cpp"
    break;

  case 42: /* attr_def: ID type LBRACE number RBRACE  */
#line 434 "yacc_sql.y"
    {
      (yyval.attr_info) = new AttrInfoSqlNode;
      (yyval.attr_info)->type = (AttrType)(yyvsp[-3].number);
      (yyval.attr_info)->name = (yyvsp[-4].string);
      (yyval.attr_info)->length = (yyvsp[-1].number);
      (yyval.attr_info)->nullable = true;
      free((yyvsp[-4].string));
    }
#line 2120 "yacc_sql.cpp"
    break;

  case 43: /* attr_def: ID type  */
#line 443 "yacc_sql.y"
    {
      (yyval.attr_info) = new AttrInfoSqlNode;
      (yyval.attr_info)->type = (AttrType)(yyvsp[0].number);
      (yyval.attr_info)->name = (yyvsp[-1].string);
      (yyval.attr_info)->length = 4;
      (yyval.attr_info)->nullable = true;
      free((yyvsp[-1].string));
    }
#line 2133 "yacc_sql.cpp"
    break;

  case 44: /* attr_def: ID type LBRACE number RBRACE NULLABLE  */
#line 452 "yacc_sql.y"
                {
      (yyval.attr_info) = new AttrInfoSqlNode;
      (yyval.attr_info)->type = (AttrType)(yyvsp[-4].number);
      (yyval.attr_info)->name = (yyvsp[-5].string);
      (yyval.attr_info)->length = (yyvsp[-2].number);
      (yyval.attr_info)->nullable = true;
      free((yyvsp[-5].string));
		}
#line 2146 "yacc_sql.cpp"
    break;

  case 45: /* attr_def: ID type LBRACE number RBRACE NOT NULLABLE  */
#line 461 "yacc_sql.y"
                {
      (yyval.attr_info) = new AttrInfoSqlNode;
      (yyval.attr_info)->type = (AttrType)(yyvsp[-5].number);
      (yyval.attr_info)->name = (yyvsp[-6].string);
      (yyval.attr_info)->length = (yyvsp[-3].number);
      (yyval.attr_info)->nullable = false;
      free((yyvsp[-6].string));
		}
#line 2159 "yacc_sql.cpp"
    break;

  case 46: /* attr_def: ID type NULLABLE  */
#line 470 "yacc_sql.y"
                {
			(yyval.attr_info) = new AttrInfoSqlNode;
      (yyval.attr_info)->type = (AttrType)(yyvsp[-1].number);
      (yyval.attr_info)->name = (yyvsp[-2].string);
      (yyval.attr_info)->length = 4;
      (yyval.attr_info)->nullable = true;
      free((yyvsp[-2].string));
		}
#line 2172 "yacc_sql.cpp"
    break;

  case 47: /* attr_def: ID type NOT NULLABLE  */
#line 479 "yacc_sql.y"
                {
			(yyval.attr_info) = new AttrInfoSqlNode;
      (yyval.attr_info)->type = (AttrType)(yyvsp[-2].number);
      (yyval.attr_info)->name = (yyvsp[-3].string);
      (yyval.attr_info)->length = 4;
      (yyval.attr_info)->nullable = false;
      free((yyvsp[-3].string));
		}
#line 2185 "yacc_sql.cpp"
    break;

  case 48: /* number: NUMBER  */
#line 489 "yacc_sql.y"
           {(yyval.number) = (yyvsp[0].number);}
#line 2191 "yacc_sql.cpp"
    break;

  case 49: /* type: INT_T  */
#line 492 "yacc_sql.y"
               { (yyval.number)=INTS; }
#line 2197 "yacc_sql.cpp"
    break;

  case 50: /* type: STRING_T  */
#line 493 "yacc_sql.y"
               { (yyval.number)=CHARS; }
#line 2203 "yacc_sql.cpp"
    break;

  case 51: /* type: FLOAT_T  */
#line 494 "yacc_sql.y"
               { (yyval.number)=FLOATS; }
#line 2209 "yacc_sql.cpp"
    break;

  case 52: /* type: DATE_T  */
#line 495 "yacc_sql.y"
              { (yyval.number)=DATES; }
#line 2215 "yacc_sql.cpp"
    break;

  case 53: /* insert_stmt: INSERT INTO ID VALUES LBRACE value value_list RBRACE row_value_list  */
#line 499 "yacc_sql.y"
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
#line 2240 "yacc_sql.cpp"
    break;

  case 54: /* row_value_list: %empty  */
#line 523 "yacc_sql.y"
                {
      (yyval.row_value_list) = nullptr;
    }
#line 2248 "yacc_sql.cpp"
    break;

  case 55: /* row_value_list: COMMA LBRACE value value_list RBRACE row_value_list  */
#line 526 "yacc_sql.y"
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
#line 2269 "yacc_sql.cpp"
    break;

  case 56: /* value_list: %empty  */
#line 546 "yacc_sql.y"
    {
      (yyval.value_list) = nullptr;
    }
#line 2277 "yacc_sql.cpp"
    break;

  case 57: /* value_list: COMMA value value_list  */
#line 549 "yacc_sql.y"
                              { 
      if ((yyvsp[0].value_list) != nullptr) {
        (yyval.value_list) = (yyvsp[0].value_list);
      } else {
        (yyval.value_list) = new std::vector<Value>;
      }
      (yyval.value_list)->emplace_back(*(yyvsp[-1].value));
      delete (yyvsp[-1].value);
    }
#line 2291 "yacc_sql.cpp"
    break;

  case 58: /* value: NUMBER  */
#line 560 "yacc_sql.y"
           {
      (yyval.value) = new Value((int)(yyvsp[0].number));
      (yyloc) = (yylsp[0]);
    }
#line 2300 "yacc_sql.cpp"
    break;

  case 59: /* value: FLOAT  */
#line 564 "yacc_sql.y"
           {
      (yyval.value) = new Value((float)(yyvsp[0].floats));
      (yyloc) = (yylsp[0]);
    }
#line 2309 "yacc_sql.cpp"
    break;

  case 60: /* value: DATE  */
#line 568 "yacc_sql.y"
          {
      char *tmp = common::substr((yyvsp[0].dates),1,strlen((yyvsp[0].dates))-2);
      (yyval.value) = new Value(tmp);
      free(tmp);
    }
#line 2319 "yacc_sql.cpp"
    break;

  case 61: /* value: SSS  */
#line 573 "yacc_sql.y"
         {
      char *tmp = common::substr((yyvsp[0].string),1,strlen((yyvsp[0].string))-2);
      (yyval.value) = new Value(tmp);
      free(tmp);
    }
#line 2329 "yacc_sql.cpp"
    break;

  case 62: /* value: NULLABLE  */
#line 578 "yacc_sql.y"
              {
      (yyval.value) = new Value();
      (yyval.value)->set_type(AttrType::NULLS);
    }
#line 2338 "yacc_sql.cpp"
    break;

  case 63: /* delete_stmt: DELETE FROM ID where  */
#line 586 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_DELETE);
      (yyval.sql_node)->deletion.relation_name = (yyvsp[-1].string);
      if ((yyvsp[0].condition_list) != nullptr) {
        (yyval.sql_node)->deletion.conditions.swap(*(yyvsp[0].condition_list));
        delete (yyvsp[0].condition_list);
      }
      free((yyvsp[-1].string));
    }
#line 2352 "yacc_sql.cpp"
    break;

  case 64: /* update_stmt: UPDATE ID SET ID EQ sub_select update_list where  */
#line 598 "yacc_sql.y"
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
#line 2377 "yacc_sql.cpp"
    break;

  case 65: /* update_list: %empty  */
#line 622 "yacc_sql.y"
    {
      (yyval.attribute_and_expr) = nullptr;
    }
#line 2385 "yacc_sql.cpp"
    break;

  case 66: /* update_list: COMMA ID EQ sub_select update_list  */
#line 625 "yacc_sql.y"
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
#line 2400 "yacc_sql.cpp"
    break;

  case 67: /* sub_select: value  */
#line 638 "yacc_sql.y"
          {
      (yyval.sub_select) = new ValueExpr(*(yyvsp[0].value));
      (yyval.sub_select)->set_name(token_name(sql_string, &(yyloc)));
      delete (yyvsp[0].value);
    }
#line 2410 "yacc_sql.cpp"
    break;

  case 68: /* sub_select: LBRACE SELECT rel_attr FROM ID where RBRACE  */
#line 644 "yacc_sql.y"
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
#line 2432 "yacc_sql.cpp"
    break;

  case 69: /* sub_select: LBRACE SELECT agg_rel_attr FROM ID where RBRACE  */
#line 662 "yacc_sql.y"
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
#line 2454 "yacc_sql.cpp"
    break;

  case 70: /* select_stmt: SELECT select_attr FROM ID rel_list where opt_order_by  */
#line 683 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_SELECT);
      if ((yyvsp[-5].rel_attr_list) != nullptr) {
        (yyval.sql_node)->selection.attributes.swap(*(yyvsp[-5].rel_attr_list));
        delete (yyvsp[-5].rel_attr_list);
      }
      if ((yyvsp[-2].relation_list) != nullptr) {
        (yyval.sql_node)->selection.relations.swap((yyvsp[-2].relation_list)->first);
        (yyval.sql_node)->selection.alias.swap((yyvsp[-2].relation_list)->second);
        delete (yyvsp[-2].relation_list);
      }
      (yyval.sql_node)->selection.relations.push_back((yyvsp[-3].string));
      std::reverse((yyval.sql_node)->selection.relations.begin(), (yyval.sql_node)->selection.relations.end());

      (yyval.sql_node)->selection.alias.push_back("");
      std::reverse((yyval.sql_node)->selection.alias.begin(), (yyval.sql_node)->selection.alias.end());

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
#line 2487 "yacc_sql.cpp"
    break;

  case 71: /* select_stmt: SELECT select_agg_attr FROM ID rel_list where  */
#line 712 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_SELECT_AGG);
      if ((yyvsp[-4].agg_rel_attr_list) != nullptr) {
        (yyval.sql_node)->selection_agg.agg_attributes.swap(*(yyvsp[-4].agg_rel_attr_list));
        delete (yyvsp[-4].agg_rel_attr_list);
      }
      if ((yyvsp[-1].relation_list) != nullptr) {
        (yyval.sql_node)->selection_agg.relations.swap((yyvsp[-1].relation_list)->first);
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
#line 2511 "yacc_sql.cpp"
    break;

  case 72: /* select_stmt: SELECT select_attr FROM ID INNER JOIN rel_list_join where  */
#line 732 "yacc_sql.y"
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
#line 2536 "yacc_sql.cpp"
    break;

  case 73: /* select_stmt: SELECT select_attr FROM ID AS ID rel_list where opt_order_by  */
#line 753 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_SELECT);
      if ((yyvsp[-7].rel_attr_list) != nullptr) {
        (yyval.sql_node)->selection.attributes.swap(*(yyvsp[-7].rel_attr_list));
        delete (yyvsp[-7].rel_attr_list);
      }
      if ((yyvsp[-2].relation_list) != nullptr) {
        (yyval.sql_node)->selection.relations.swap((yyvsp[-2].relation_list)->first);
        (yyval.sql_node)->selection.alias.swap((yyvsp[-2].relation_list)->second);
        delete (yyvsp[-2].relation_list);
      }
      (yyval.sql_node)->selection.relations.push_back((yyvsp[-5].string));
      std::reverse((yyval.sql_node)->selection.relations.begin(), (yyval.sql_node)->selection.relations.end());

      (yyval.sql_node)->selection.alias.push_back((yyvsp[-3].string));
      std::reverse((yyval.sql_node)->selection.alias.begin(), (yyval.sql_node)->selection.alias.end());

      if ((yyvsp[-1].condition_list) != nullptr) {
        (yyval.sql_node)->selection.conditions.swap(*(yyvsp[-1].condition_list));
        delete (yyvsp[-1].condition_list);
      }
      if ((yyvsp[0].order_by_list) != nullptr) {
        (yyval.sql_node)->selection.orderbys.swap(*(yyvsp[0].order_by_list));
        std::reverse((yyval.sql_node)->selection.orderbys.begin(), (yyval.sql_node)->selection.orderbys.end());
        delete (yyvsp[0].order_by_list);
      }
      free((yyvsp[-5].string));
      free((yyvsp[-3].string));
    }
#line 2570 "yacc_sql.cpp"
    break;

  case 74: /* select_stmt: SELECT select_attr FROM ID ID rel_list where opt_order_by  */
#line 783 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_SELECT);
      if ((yyvsp[-6].rel_attr_list) != nullptr) {
        (yyval.sql_node)->selection.attributes.swap(*(yyvsp[-6].rel_attr_list));
        delete (yyvsp[-6].rel_attr_list);
      }
      if ((yyvsp[-2].relation_list) != nullptr) {
        (yyval.sql_node)->selection.relations.swap((yyvsp[-2].relation_list)->first);
        (yyval.sql_node)->selection.alias.swap((yyvsp[-2].relation_list)->second);
        delete (yyvsp[-2].relation_list);
      }
      (yyval.sql_node)->selection.relations.push_back((yyvsp[-4].string));
      std::reverse((yyval.sql_node)->selection.relations.begin(), (yyval.sql_node)->selection.relations.end());

      (yyval.sql_node)->selection.alias.push_back((yyvsp[-3].string));
      std::reverse((yyval.sql_node)->selection.alias.begin(), (yyval.sql_node)->selection.alias.end());

      if ((yyvsp[-1].condition_list) != nullptr) {
        (yyval.sql_node)->selection.conditions.swap(*(yyvsp[-1].condition_list));
        delete (yyvsp[-1].condition_list);
      }
      if ((yyvsp[0].order_by_list) != nullptr) {
        (yyval.sql_node)->selection.orderbys.swap(*(yyvsp[0].order_by_list));
        std::reverse((yyval.sql_node)->selection.orderbys.begin(), (yyval.sql_node)->selection.orderbys.end());
        delete (yyvsp[0].order_by_list);
      }
      free((yyvsp[-4].string));
      free((yyvsp[-3].string));
    }
#line 2604 "yacc_sql.cpp"
    break;

  case 75: /* order_by_unit: ID  */
#line 814 "yacc_sql.y"
       {
      RelAttrSqlNode *tmp = new RelAttrSqlNode;
      tmp->attribute_name = (yyvsp[0].string);
      free((yyvsp[0].string));
      (yyval.order_by_unit) = new OrderByNode;
      (yyval.order_by_unit)->order_by_attr = *tmp;
      (yyval.order_by_unit)->is_asc = 1;
    }
#line 2617 "yacc_sql.cpp"
    break;

  case 76: /* order_by_unit: ID DOT ID  */
#line 822 "yacc_sql.y"
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
#line 2632 "yacc_sql.cpp"
    break;

  case 77: /* order_by_unit: ID DESC  */
#line 834 "yacc_sql.y"
    {
      RelAttrSqlNode *tmp = new RelAttrSqlNode;
      tmp->attribute_name = (yyvsp[-1].string);
      free((yyvsp[-1].string));
      (yyval.order_by_unit) = new OrderByNode;
      (yyval.order_by_unit)->order_by_attr = *tmp;
      (yyval.order_by_unit)->is_asc = 0;
    }
#line 2645 "yacc_sql.cpp"
    break;

  case 78: /* order_by_unit: ID ASC  */
#line 844 "yacc_sql.y"
    {
      RelAttrSqlNode *tmp = new RelAttrSqlNode;
      tmp->attribute_name = (yyvsp[-1].string);
      free((yyvsp[-1].string));
      (yyval.order_by_unit) = new OrderByNode;
      (yyval.order_by_unit)->order_by_attr = *tmp;
      (yyval.order_by_unit)->is_asc = 1;
    }
#line 2658 "yacc_sql.cpp"
    break;

  case 79: /* order_by_unit: ID DOT ID DESC  */
#line 854 "yacc_sql.y"
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
#line 2673 "yacc_sql.cpp"
    break;

  case 80: /* order_by_unit: ID DOT ID ASC  */
#line 866 "yacc_sql.y"
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
#line 2688 "yacc_sql.cpp"
    break;

  case 81: /* order_by_list: %empty  */
#line 879 "yacc_sql.y"
    {
      (yyval.order_by_list) = nullptr;
    }
#line 2696 "yacc_sql.cpp"
    break;

  case 82: /* order_by_list: order_by_unit  */
#line 882 "yacc_sql.y"
                    {
      (yyval.order_by_list) = new std::vector<OrderByNode>;
      (yyval.order_by_list)->emplace_back(*(yyvsp[0].order_by_unit));
      delete (yyvsp[0].order_by_unit);
    }
#line 2706 "yacc_sql.cpp"
    break;

  case 83: /* order_by_list: order_by_unit COMMA order_by_list  */
#line 887 "yacc_sql.y"
                                        {
      (yyval.order_by_list) = (yyvsp[0].order_by_list);
      (yyval.order_by_list)->emplace_back(*(yyvsp[-2].order_by_unit));
      delete (yyvsp[-2].order_by_unit);

    }
#line 2717 "yacc_sql.cpp"
    break;

  case 84: /* opt_order_by: %empty  */
#line 896 "yacc_sql.y"
    {
      (yyval.order_by_list) = nullptr;
    }
#line 2725 "yacc_sql.cpp"
    break;

  case 85: /* opt_order_by: ORDER BY order_by_list  */
#line 900 "yacc_sql.y"
    {
        (yyval.order_by_list) = (yyvsp[0].order_by_list);
    }
#line 2733 "yacc_sql.cpp"
    break;

  case 86: /* calc_stmt: CALC expression_list  */
#line 906 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_CALC);
      std::reverse((yyvsp[0].expression_list)->begin(), (yyvsp[0].expression_list)->end());
      (yyval.sql_node)->calc.expressions.swap(*(yyvsp[0].expression_list));
      delete (yyvsp[0].expression_list);
    }
#line 2744 "yacc_sql.cpp"
    break;

  case 87: /* expression_list: expression  */
#line 916 "yacc_sql.y"
    {
      (yyval.expression_list) = new std::vector<Expression*>;
      (yyval.expression_list)->emplace_back((yyvsp[0].expression));
    }
#line 2753 "yacc_sql.cpp"
    break;

  case 88: /* expression_list: expression COMMA expression_list  */
#line 921 "yacc_sql.y"
    {
      if ((yyvsp[0].expression_list) != nullptr) {
        (yyval.expression_list) = (yyvsp[0].expression_list);
      } else {
        (yyval.expression_list) = new std::vector<Expression *>;
      }
      (yyval.expression_list)->emplace_back((yyvsp[-2].expression));
    }
#line 2766 "yacc_sql.cpp"
    break;

  case 89: /* expression: expression '+' expression  */
#line 931 "yacc_sql.y"
                              {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::ADD, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2774 "yacc_sql.cpp"
    break;

  case 90: /* expression: expression '-' expression  */
#line 934 "yacc_sql.y"
                                {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::SUB, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2782 "yacc_sql.cpp"
    break;

  case 91: /* expression: expression '*' expression  */
#line 937 "yacc_sql.y"
                                {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::MUL, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2790 "yacc_sql.cpp"
    break;

  case 92: /* expression: expression '/' expression  */
#line 940 "yacc_sql.y"
                                {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::DIV, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2798 "yacc_sql.cpp"
    break;

  case 93: /* expression: LBRACE expression RBRACE  */
#line 943 "yacc_sql.y"
                               {
      (yyval.expression) = (yyvsp[-1].expression);
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));
    }
#line 2807 "yacc_sql.cpp"
    break;

  case 94: /* expression: '-' expression  */
#line 947 "yacc_sql.y"
                                  {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::NEGATIVE, (yyvsp[0].expression), nullptr, sql_string, &(yyloc));
    }
#line 2815 "yacc_sql.cpp"
    break;

  case 95: /* expression: value  */
#line 950 "yacc_sql.y"
            {
      (yyval.expression) = new ValueExpr(*(yyvsp[0].value));
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));
      delete (yyvsp[0].value);
    }
#line 2825 "yacc_sql.cpp"
    break;

  case 96: /* select_attr: '*'  */
#line 958 "yacc_sql.y"
        {
      (yyval.rel_attr_list) = new std::vector<RelAttrSqlNode>;
      RelAttrSqlNode attr;
      attr.relation_name  = "";
      attr.attribute_name = "*";
      (yyval.rel_attr_list)->emplace_back(attr);
    }
#line 2837 "yacc_sql.cpp"
    break;

  case 97: /* select_attr: rel_attr attr_list  */
#line 965 "yacc_sql.y"
                         {
      if ((yyvsp[0].rel_attr_list) != nullptr) {
        (yyval.rel_attr_list) = (yyvsp[0].rel_attr_list);
      } else {
        (yyval.rel_attr_list) = new std::vector<RelAttrSqlNode>;
      }
      (yyval.rel_attr_list)->emplace_back(*(yyvsp[-1].rel_attr));
      delete (yyvsp[-1].rel_attr);
    }
#line 2851 "yacc_sql.cpp"
    break;

  case 98: /* select_agg_attr: agg_rel_attr agg_attr_list  */
#line 977 "yacc_sql.y"
                               {
      if ((yyvsp[0].agg_rel_attr_list) != nullptr) {
        (yyval.agg_rel_attr_list) = (yyvsp[0].agg_rel_attr_list);
      } else {
        (yyval.agg_rel_attr_list) = new std::vector<AggRelAttrSqlNode>;
      }
      (yyval.agg_rel_attr_list)->emplace_back(*(yyvsp[-1].agg_rel_attr));
      delete (yyvsp[-1].agg_rel_attr);
    }
#line 2865 "yacc_sql.cpp"
    break;

  case 99: /* agg_op: MAX  */
#line 989 "yacc_sql.y"
          { (yyval.agg) = MAX_OP; }
#line 2871 "yacc_sql.cpp"
    break;

  case 100: /* agg_op: MIN  */
#line 990 "yacc_sql.y"
          { (yyval.agg) = MIN_OP; }
#line 2877 "yacc_sql.cpp"
    break;

  case 101: /* agg_op: COUNT  */
#line 991 "yacc_sql.y"
            { (yyval.agg) = COUNT_OP; }
#line 2883 "yacc_sql.cpp"
    break;

  case 102: /* agg_op: AVG  */
#line 992 "yacc_sql.y"
          { (yyval.agg) = AVG_OP; }
#line 2889 "yacc_sql.cpp"
    break;

  case 103: /* agg_op: SUM  */
#line 993 "yacc_sql.y"
          { (yyval.agg) = SUM_OP; }
#line 2895 "yacc_sql.cpp"
    break;

  case 104: /* rel_attr: ID  */
#line 997 "yacc_sql.y"
       {
      (yyval.rel_attr) = new RelAttrSqlNode;
      (yyval.rel_attr)->attribute_name = (yyvsp[0].string);
      free((yyvsp[0].string));
    }
#line 2905 "yacc_sql.cpp"
    break;

  case 105: /* rel_attr: ID DOT ID  */
#line 1002 "yacc_sql.y"
                {
      (yyval.rel_attr) = new RelAttrSqlNode;
      (yyval.rel_attr)->relation_name  = (yyvsp[-2].string);
      (yyval.rel_attr)->attribute_name = (yyvsp[0].string);
      free((yyvsp[-2].string));
      free((yyvsp[0].string));
    }
#line 2917 "yacc_sql.cpp"
    break;

  case 106: /* rel_attr: ID AS ID  */
#line 1009 "yacc_sql.y"
              {
      (yyval.rel_attr) = new RelAttrSqlNode;
      (yyval.rel_attr)->attribute_name = (yyvsp[-2].string);
      (yyval.rel_attr)->alias = (yyvsp[0].string);
      free((yyvsp[-2].string));
      free((yyvsp[0].string));
    }
#line 2929 "yacc_sql.cpp"
    break;

  case 107: /* rel_attr: ID DOT ID AS ID  */
#line 1023 "yacc_sql.y"
                     {
      (yyval.rel_attr) = new RelAttrSqlNode;
      (yyval.rel_attr)->relation_name  = (yyvsp[-4].string);
      (yyval.rel_attr)->attribute_name = (yyvsp[-2].string);
      (yyval.rel_attr)->alias = (yyvsp[0].string);
      free((yyvsp[-4].string));
      free((yyvsp[-2].string));
      free((yyvsp[0].string));
    }
#line 2943 "yacc_sql.cpp"
    break;

  case 108: /* attr_list: %empty  */
#line 1045 "yacc_sql.y"
    {
      (yyval.rel_attr_list) = nullptr;
    }
#line 2951 "yacc_sql.cpp"
    break;

  case 109: /* attr_list: COMMA rel_attr attr_list  */
#line 1048 "yacc_sql.y"
                               {
      if ((yyvsp[0].rel_attr_list) != nullptr) {
        (yyval.rel_attr_list) = (yyvsp[0].rel_attr_list);
      } else {
        (yyval.rel_attr_list) = new std::vector<RelAttrSqlNode>;
      }

      (yyval.rel_attr_list)->emplace_back(*(yyvsp[-1].rel_attr));
      delete (yyvsp[-1].rel_attr);
    }
#line 2966 "yacc_sql.cpp"
    break;

  case 110: /* agg_rel_attr: agg_op LBRACE '*' RBRACE  */
#line 1061 "yacc_sql.y"
                             {
      (yyval.agg_rel_attr) = new AggRelAttrSqlNode;
      AggRelAttrSqlNode attr;
      (yyval.agg_rel_attr)->agg_func = (yyvsp[-3].agg);
      (yyval.agg_rel_attr)->relation_name  = "";
      (yyval.agg_rel_attr)->attribute_name = "*";
    }
#line 2978 "yacc_sql.cpp"
    break;

  case 111: /* agg_rel_attr: agg_op LBRACE ID RBRACE  */
#line 1068 "yacc_sql.y"
                              {
      (yyval.agg_rel_attr) = new AggRelAttrSqlNode;
      (yyval.agg_rel_attr)->agg_func = (yyvsp[-3].agg);
      (yyval.agg_rel_attr)->attribute_name = (yyvsp[-1].string);
      free((yyvsp[-1].string));
    }
#line 2989 "yacc_sql.cpp"
    break;

  case 112: /* agg_rel_attr: agg_op LBRACE ID DOT ID RBRACE  */
#line 1074 "yacc_sql.y"
                                     {
      (yyval.agg_rel_attr) = new AggRelAttrSqlNode;
      (yyval.agg_rel_attr)->agg_func = (yyvsp[-5].agg);
      (yyval.agg_rel_attr)->relation_name  = (yyvsp[-3].string);
      (yyval.agg_rel_attr)->attribute_name = (yyvsp[-1].string);
      free((yyvsp[-3].string));
      free((yyvsp[-1].string));
    }
#line 3002 "yacc_sql.cpp"
    break;

  case 113: /* agg_attr_list: %empty  */
#line 1086 "yacc_sql.y"
    {
      (yyval.agg_rel_attr_list) = nullptr;
    }
#line 3010 "yacc_sql.cpp"
    break;

  case 114: /* agg_attr_list: COMMA agg_rel_attr agg_attr_list  */
#line 1089 "yacc_sql.y"
                                       {
      if ((yyvsp[0].agg_rel_attr_list) != nullptr) {
        (yyval.agg_rel_attr_list) = (yyvsp[0].agg_rel_attr_list);
      } else {
        (yyval.agg_rel_attr_list) = new std::vector<AggRelAttrSqlNode>;
      }

      (yyval.agg_rel_attr_list)->emplace_back(*(yyvsp[-1].agg_rel_attr));
      delete (yyvsp[-1].agg_rel_attr);
    }
#line 3025 "yacc_sql.cpp"
    break;

  case 115: /* rel_list: %empty  */
#line 1103 "yacc_sql.y"
    {
      (yyval.relation_list) = nullptr;
    }
#line 3033 "yacc_sql.cpp"
    break;

  case 116: /* rel_list: COMMA ID rel_list  */
#line 1106 "yacc_sql.y"
                        {
      if ((yyvsp[0].relation_list) != nullptr) {
        (yyval.relation_list) = (yyvsp[0].relation_list);
      } else {
        // $$ = new std::vector<std::string>;
        (yyval.relation_list) = new std::pair<std::vector<std::string>, std::vector<std::string>>;
      }

      // $$->push_back($2);
      (yyval.relation_list)->first.push_back((yyvsp[-1].string));
      (yyval.relation_list)->second.push_back("");
      free((yyvsp[-1].string));
    }
#line 3051 "yacc_sql.cpp"
    break;

  case 117: /* rel_list: COMMA ID AS ID rel_list  */
#line 1119 "yacc_sql.y"
                              {
      if ((yyvsp[0].relation_list) != nullptr) {
        (yyval.relation_list) = (yyvsp[0].relation_list);
      } else {
        (yyval.relation_list) = new std::pair<std::vector<std::string>, std::vector<std::string>>;
      }

      (yyval.relation_list)->first.push_back((yyvsp[-3].string));
      (yyval.relation_list)->second.push_back((yyvsp[-1].string));
      free((yyvsp[-3].string));
      free((yyvsp[-1].string));
    }
#line 3068 "yacc_sql.cpp"
    break;

  case 118: /* rel_list: COMMA ID ID rel_list  */
#line 1131 "yacc_sql.y"
                           {
      if ((yyvsp[0].relation_list) != nullptr) {
        (yyval.relation_list) = (yyvsp[0].relation_list);
      } else {
        (yyval.relation_list) = new std::pair<std::vector<std::string>, std::vector<std::string>>;
      }

      (yyval.relation_list)->first.push_back((yyvsp[-2].string));
      (yyval.relation_list)->second.push_back((yyvsp[-1].string));
      free((yyvsp[-2].string));
      free((yyvsp[-1].string));
    }
#line 3085 "yacc_sql.cpp"
    break;

  case 119: /* rel_list_join: %empty  */
#line 1146 "yacc_sql.y"
    {
      (yyval.table_and_condition) = nullptr;
    }
#line 3093 "yacc_sql.cpp"
    break;

  case 120: /* rel_list_join: ID inner_join_conditions rel_list_join  */
#line 1149 "yacc_sql.y"
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
#line 3111 "yacc_sql.cpp"
    break;

  case 121: /* rel_list_join: INNER JOIN ID inner_join_conditions rel_list_join  */
#line 1162 "yacc_sql.y"
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
#line 3129 "yacc_sql.cpp"
    break;

  case 122: /* inner_join_conditions: %empty  */
#line 1177 "yacc_sql.y"
                {
      (yyval.condition_list) = new std::vector<ConditionSqlNode>;
    }
#line 3137 "yacc_sql.cpp"
    break;

  case 123: /* inner_join_conditions: ON condition inner_join_conditions  */
#line 1180 "yacc_sql.y"
                                        {
      // $$ = new std::vector<ConditionSqlNode>;
      (yyval.condition_list) = (yyvsp[0].condition_list);
      (yyval.condition_list)->emplace_back(*(yyvsp[-1].condition));
      delete (yyvsp[-1].condition);
    }
#line 3148 "yacc_sql.cpp"
    break;

  case 124: /* inner_join_conditions: AND condition inner_join_conditions  */
#line 1186 "yacc_sql.y"
                                         {
      // $$ = new std::vector<ConditionSqlNode>;
      (yyval.condition_list) = (yyvsp[0].condition_list);
      (yyval.condition_list)->emplace_back(*(yyvsp[-1].condition));
      delete (yyvsp[-1].condition);
    }
#line 3159 "yacc_sql.cpp"
    break;

  case 125: /* where: %empty  */
#line 1195 "yacc_sql.y"
    {
      (yyval.condition_list) = nullptr;
    }
#line 3167 "yacc_sql.cpp"
    break;

  case 126: /* where: WHERE condition_list  */
#line 1198 "yacc_sql.y"
                           {
      (yyval.condition_list) = (yyvsp[0].condition_list);  
    }
#line 3175 "yacc_sql.cpp"
    break;

  case 127: /* condition_list: %empty  */
#line 1204 "yacc_sql.y"
    {
      (yyval.condition_list) = nullptr;
    }
#line 3183 "yacc_sql.cpp"
    break;

  case 128: /* condition_list: condition  */
#line 1207 "yacc_sql.y"
                {
      (yyval.condition_list) = new std::vector<ConditionSqlNode>;
      (yyval.condition_list)->emplace_back(*(yyvsp[0].condition));
      delete (yyvsp[0].condition);
    }
#line 3193 "yacc_sql.cpp"
    break;

  case 129: /* condition_list: condition AND condition_list  */
#line 1212 "yacc_sql.y"
                                   {
      (yyval.condition_list) = (yyvsp[0].condition_list);
      (yyval.condition_list)->emplace_back(*(yyvsp[-2].condition));
      delete (yyvsp[-2].condition);
    }
#line 3203 "yacc_sql.cpp"
    break;

  case 130: /* condition: rel_attr comp_op value  */
#line 1220 "yacc_sql.y"
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
#line 3220 "yacc_sql.cpp"
    break;

  case 131: /* condition: value comp_op value  */
#line 1233 "yacc_sql.y"
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
#line 3237 "yacc_sql.cpp"
    break;

  case 132: /* condition: rel_attr comp_op rel_attr  */
#line 1246 "yacc_sql.y"
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
#line 3254 "yacc_sql.cpp"
    break;

  case 133: /* condition: value comp_op rel_attr  */
#line 1259 "yacc_sql.y"
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
#line 3271 "yacc_sql.cpp"
    break;

  case 134: /* condition: rel_attr NOT comp_op value  */
#line 1272 "yacc_sql.y"
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
#line 3288 "yacc_sql.cpp"
    break;

  case 135: /* condition: value NOT comp_op value  */
#line 1285 "yacc_sql.y"
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
#line 3305 "yacc_sql.cpp"
    break;

  case 136: /* condition: rel_attr NOT comp_op rel_attr  */
#line 1298 "yacc_sql.y"
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
#line 3322 "yacc_sql.cpp"
    break;

  case 137: /* condition: value NOT comp_op rel_attr  */
#line 1311 "yacc_sql.y"
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
#line 3339 "yacc_sql.cpp"
    break;

  case 138: /* condition: rel_attr IS NULLABLE  */
#line 1324 "yacc_sql.y"
    {
      (yyval.condition) = new ConditionSqlNode;
      (yyval.condition)->left_is_attr = 1;
      (yyval.condition)->left_attr = *(yyvsp[-2].rel_attr);
      // $$->comp = EQ;      // 虽然没用，但还是初始化一个避免后续filter_stmt判断出问题
      (yyval.condition)->is_null = true;
      (yyval.condition)->exist_not = false;

      delete (yyvsp[-2].rel_attr);
    }
#line 3354 "yacc_sql.cpp"
    break;

  case 139: /* condition: value IS NULLABLE  */
#line 1335 "yacc_sql.y"
    {
      (yyval.condition) = new ConditionSqlNode;
      (yyval.condition)->left_is_attr = 0;
      (yyval.condition)->left_value = *(yyvsp[-2].value);
      // $$->comp = EQ;
      (yyval.condition)->is_null = true;
      (yyval.condition)->exist_not = false;

      delete (yyvsp[-2].value);
    }
#line 3369 "yacc_sql.cpp"
    break;

  case 140: /* condition: rel_attr IS NOT NULLABLE  */
#line 1346 "yacc_sql.y"
    {
      (yyval.condition) = new ConditionSqlNode;
      (yyval.condition)->left_is_attr = 1;
      (yyval.condition)->left_attr = *(yyvsp[-3].rel_attr);
      // $$->comp = EQ;
      (yyval.condition)->is_null = true;
      (yyval.condition)->exist_not = true;

      delete (yyvsp[-3].rel_attr);
    }
#line 3384 "yacc_sql.cpp"
    break;

  case 141: /* condition: value IS NOT NULLABLE  */
#line 1357 "yacc_sql.y"
    {
      (yyval.condition) = new ConditionSqlNode;
      (yyval.condition)->left_is_attr = 0;
      (yyval.condition)->left_value = *(yyvsp[-3].value);
      // $$->comp = EQ;
      (yyval.condition)->is_null = true;
      (yyval.condition)->exist_not = true;

      delete (yyvsp[-3].value);
    }
#line 3399 "yacc_sql.cpp"
    break;

  case 142: /* condition: rel_attr comp_op LBRACE sub_select_for_in RBRACE  */
#line 1368 "yacc_sql.y"
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
#line 3414 "yacc_sql.cpp"
    break;

  case 143: /* condition: LBRACE sub_select_for_in RBRACE comp_op rel_attr  */
#line 1379 "yacc_sql.y"
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
#line 3431 "yacc_sql.cpp"
    break;

  case 144: /* condition: rel_attr NOT comp_op LBRACE sub_select_for_in RBRACE  */
#line 1392 "yacc_sql.y"
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
#line 3446 "yacc_sql.cpp"
    break;

  case 145: /* condition: EXISTS LBRACE sub_select_for_in RBRACE  */
#line 1403 "yacc_sql.y"
    {
      (yyval.condition) = new ConditionSqlNode;
      (yyval.condition)->left_is_attr = 0;
      (yyval.condition)->right_is_attr = 0;    // filter_stmt.cpp 中判断会用到
      (yyval.condition)->comp = CompOp::EXISTS_OP;
      (yyval.condition)->exist_not = false;
      (yyval.condition)->in_exprs = (yyvsp[-1].sub_select_for_in);
    }
#line 3459 "yacc_sql.cpp"
    break;

  case 146: /* condition: NOT EXISTS LBRACE sub_select_for_in RBRACE  */
#line 1412 "yacc_sql.y"
    {
      (yyval.condition) = new ConditionSqlNode;
      (yyval.condition)->left_is_attr = 1;
      (yyval.condition)->right_is_attr = 0;    // filter_stmt.cpp 中判断会用到
      (yyval.condition)->comp = CompOp::EXISTS_OP;
      (yyval.condition)->exist_not = true;
      (yyval.condition)->in_exprs = (yyvsp[-1].sub_select_for_in);
    }
#line 3472 "yacc_sql.cpp"
    break;

  case 147: /* sub_select_for_in: value value_list  */
#line 1424 "yacc_sql.y"
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
#line 3490 "yacc_sql.cpp"
    break;

  case 148: /* sub_select_for_in: SELECT rel_attr FROM ID where  */
#line 1438 "yacc_sql.y"
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
#line 3512 "yacc_sql.cpp"
    break;

  case 149: /* sub_select_for_in: SELECT agg_rel_attr FROM ID where  */
#line 1456 "yacc_sql.y"
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
#line 3534 "yacc_sql.cpp"
    break;

  case 150: /* sub_select_for_in: SELECT '*' FROM ID where  */
#line 1474 "yacc_sql.y"
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
#line 3557 "yacc_sql.cpp"
    break;

  case 151: /* comp_op: EQ  */
#line 1495 "yacc_sql.y"
         { (yyval.comp) = EQUAL_TO; }
#line 3563 "yacc_sql.cpp"
    break;

  case 152: /* comp_op: LT  */
#line 1496 "yacc_sql.y"
         { (yyval.comp) = LESS_THAN; }
#line 3569 "yacc_sql.cpp"
    break;

  case 153: /* comp_op: GT  */
#line 1497 "yacc_sql.y"
         { (yyval.comp) = GREAT_THAN; }
#line 3575 "yacc_sql.cpp"
    break;

  case 154: /* comp_op: LE  */
#line 1498 "yacc_sql.y"
         { (yyval.comp) = LESS_EQUAL; }
#line 3581 "yacc_sql.cpp"
    break;

  case 155: /* comp_op: GE  */
#line 1499 "yacc_sql.y"
         { (yyval.comp) = GREAT_EQUAL; }
#line 3587 "yacc_sql.cpp"
    break;

  case 156: /* comp_op: NE  */
#line 1500 "yacc_sql.y"
         { (yyval.comp) = NOT_EQUAL; }
#line 3593 "yacc_sql.cpp"
    break;

  case 157: /* comp_op: LIKE  */
#line 1501 "yacc_sql.y"
           { (yyval.comp) = LIKE_TO; }
#line 3599 "yacc_sql.cpp"
    break;

  case 158: /* comp_op: IN  */
#line 1502 "yacc_sql.y"
         { (yyval.comp) = IN_OP; }
#line 3605 "yacc_sql.cpp"
    break;

  case 159: /* load_data_stmt: LOAD DATA INFILE SSS INTO TABLE ID  */
#line 1507 "yacc_sql.y"
    {
      char *tmp_file_name = common::substr((yyvsp[-3].string), 1, strlen((yyvsp[-3].string)) - 2);
      
      (yyval.sql_node) = new ParsedSqlNode(SCF_LOAD_DATA);
      (yyval.sql_node)->load_data.relation_name = (yyvsp[0].string);
      (yyval.sql_node)->load_data.file_name = tmp_file_name;
      free((yyvsp[0].string));
      free(tmp_file_name);
    }
#line 3619 "yacc_sql.cpp"
    break;

  case 160: /* explain_stmt: EXPLAIN command_wrapper  */
#line 1520 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_EXPLAIN);
      (yyval.sql_node)->explain.sql_node = std::unique_ptr<ParsedSqlNode>((yyvsp[0].sql_node));
    }
#line 3628 "yacc_sql.cpp"
    break;

  case 161: /* set_variable_stmt: SET ID EQ value  */
#line 1528 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_SET_VARIABLE);
      (yyval.sql_node)->set_variable.name  = (yyvsp[-2].string);
      (yyval.sql_node)->set_variable.value = *(yyvsp[0].value);
      free((yyvsp[-2].string));
      delete (yyvsp[0].value);
    }
#line 3640 "yacc_sql.cpp"
    break;


#line 3644 "yacc_sql.cpp"

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

#line 1540 "yacc_sql.y"

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
