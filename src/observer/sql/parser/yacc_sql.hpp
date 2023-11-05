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

#ifndef YY_YY_YACC_SQL_HPP_INCLUDED
# define YY_YY_YACC_SQL_HPP_INCLUDED
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
    SEMICOLON = 258,               /* SEMICOLON  */
    CREATE = 259,                  /* CREATE  */
    DROP = 260,                    /* DROP  */
    TABLE = 261,                   /* TABLE  */
    TABLES = 262,                  /* TABLES  */
    INDEX = 263,                   /* INDEX  */
    CALC = 264,                    /* CALC  */
    SELECT = 265,                  /* SELECT  */
    MAX = 266,                     /* MAX  */
    MIN = 267,                     /* MIN  */
    IN = 268,                      /* IN  */
    EXISTS = 269,                  /* EXISTS  */
    COUNT = 270,                   /* COUNT  */
    AVG = 271,                     /* AVG  */
    SUM = 272,                     /* SUM  */
    DESC = 273,                    /* DESC  */
    AS = 274,                      /* AS  */
    ASC = 275,                     /* ASC  */
    SHOW = 276,                    /* SHOW  */
    SYNC = 277,                    /* SYNC  */
    INSERT = 278,                  /* INSERT  */
    DELETE = 279,                  /* DELETE  */
    UPDATE = 280,                  /* UPDATE  */
    LBRACE = 281,                  /* LBRACE  */
    RBRACE = 282,                  /* RBRACE  */
    COMMA = 283,                   /* COMMA  */
    TRX_BEGIN = 284,               /* TRX_BEGIN  */
    TRX_COMMIT = 285,              /* TRX_COMMIT  */
    TRX_ROLLBACK = 286,            /* TRX_ROLLBACK  */
    INT_T = 287,                   /* INT_T  */
    STRING_T = 288,                /* STRING_T  */
    FLOAT_T = 289,                 /* FLOAT_T  */
    DATE_T = 290,                  /* DATE_T  */
    HELP = 291,                    /* HELP  */
    EXIT = 292,                    /* EXIT  */
    UNIQUE = 293,                  /* UNIQUE  */
    ORDER = 294,                   /* ORDER  */
    BY = 295,                      /* BY  */
    DOT = 296,                     /* DOT  */
    INTO = 297,                    /* INTO  */
    VALUES = 298,                  /* VALUES  */
    FROM = 299,                    /* FROM  */
    WHERE = 300,                   /* WHERE  */
    INNER = 301,                   /* INNER  */
    JOIN = 302,                    /* JOIN  */
    AND = 303,                     /* AND  */
    SET = 304,                     /* SET  */
    ON = 305,                      /* ON  */
    LOAD = 306,                    /* LOAD  */
    DATA = 307,                    /* DATA  */
    INFILE = 308,                  /* INFILE  */
    EXPLAIN = 309,                 /* EXPLAIN  */
    LIKE = 310,                    /* LIKE  */
    NOT = 311,                     /* NOT  */
    IS = 312,                      /* IS  */
    NULLABLE = 313,                /* NULLABLE  */
    EQ = 314,                      /* EQ  */
    LT = 315,                      /* LT  */
    GT = 316,                      /* GT  */
    LE = 317,                      /* LE  */
    GE = 318,                      /* GE  */
    NE = 319,                      /* NE  */
    NUMBER = 320,                  /* NUMBER  */
    FLOAT = 321,                   /* FLOAT  */
    ID = 322,                      /* ID  */
    DATE = 323,                    /* DATE  */
    SSS = 324,                     /* SSS  */
    UMINUS = 325                   /* UMINUS  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 131 "yacc_sql.y"

  ParsedSqlNode *                   sql_node;
  ConditionSqlNode *                condition;
  OrderByNode *                     order_by_unit;
  Value *                           value;
  enum CompOp                       comp;
  enum AggOp                        agg;
  RelAttrSqlNode *                  rel_attr;
  AggRelAttrSqlNode *               agg_rel_attr;
  std::vector<AttrInfoSqlNode> *    attr_infos;
  AttrInfoSqlNode *                 attr_info;
  Expression *                      expression;
  std::vector<Expression *> *       expression_list;
  std::vector<Value> *              value_list;
  std::vector<std::vector<Value>> * row_value_list;
  std::vector<ConditionSqlNode> *   condition_list;
  std::vector<OrderByNode> *        order_by_list;
  std::vector<RelAttrSqlNode> *     rel_attr_list;
  std::vector<AggRelAttrSqlNode> *  agg_rel_attr_list;
  // std::vector<std::string> *        relation_list;
  std::pair<std::vector<std::string>, std::vector<std::string>> * relation_list;
  std::vector<std::string> *        id_lists;
  struct TableAndCondition *        table_and_condition;
  struct AttributeAndExpr *         attribute_and_expr;
  Expression *                      sub_select;
  Expression *                      sub_select_for_in;
  char *                            string;
  int                               number;
  float                             floats;
  char *                            dates;

#line 166 "yacc_sql.hpp"

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




int yyparse (const char * sql_string, ParsedSqlResult * sql_result, void * scanner);


#endif /* !YY_YY_YACC_SQL_HPP_INCLUDED  */
