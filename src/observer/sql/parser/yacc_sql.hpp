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
    TEXT = 276,                    /* TEXT  */
    SHOW = 277,                    /* SHOW  */
    SYNC = 278,                    /* SYNC  */
    INSERT = 279,                  /* INSERT  */
    DELETE = 280,                  /* DELETE  */
    UPDATE = 281,                  /* UPDATE  */
    LBRACE = 282,                  /* LBRACE  */
    RBRACE = 283,                  /* RBRACE  */
    COMMA = 284,                   /* COMMA  */
    TRX_BEGIN = 285,               /* TRX_BEGIN  */
    TRX_COMMIT = 286,              /* TRX_COMMIT  */
    TRX_ROLLBACK = 287,            /* TRX_ROLLBACK  */
    INT_T = 288,                   /* INT_T  */
    STRING_T = 289,                /* STRING_T  */
    FLOAT_T = 290,                 /* FLOAT_T  */
    DATE_T = 291,                  /* DATE_T  */
    HELP = 292,                    /* HELP  */
    EXIT = 293,                    /* EXIT  */
    UNIQUE = 294,                  /* UNIQUE  */
    ORDER = 295,                   /* ORDER  */
    BY = 296,                      /* BY  */
    DOT = 297,                     /* DOT  */
    INTO = 298,                    /* INTO  */
    VALUES = 299,                  /* VALUES  */
    FROM = 300,                    /* FROM  */
    WHERE = 301,                   /* WHERE  */
    INNER = 302,                   /* INNER  */
    JOIN = 303,                    /* JOIN  */
    AND = 304,                     /* AND  */
    SET = 305,                     /* SET  */
    ON = 306,                      /* ON  */
    LOAD = 307,                    /* LOAD  */
    DATA = 308,                    /* DATA  */
    INFILE = 309,                  /* INFILE  */
    EXPLAIN = 310,                 /* EXPLAIN  */
    LIKE = 311,                    /* LIKE  */
    NOT = 312,                     /* NOT  */
    IS = 313,                      /* IS  */
    NULLABLE = 314,                /* NULLABLE  */
    EQ = 315,                      /* EQ  */
    LT = 316,                      /* LT  */
    GT = 317,                      /* GT  */
    LE = 318,                      /* LE  */
    GE = 319,                      /* GE  */
    NE = 320,                      /* NE  */
    NUMBER = 321,                  /* NUMBER  */
    FLOAT = 322,                   /* FLOAT  */
    ID = 323,                      /* ID  */
    DATE = 324,                    /* DATE  */
    SSS = 325,                     /* SSS  */
    UMINUS = 326                   /* UMINUS  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 132 "yacc_sql.y"

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

#line 167 "yacc_sql.hpp"

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
