/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison interface for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
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

#ifndef YY_YY_AQ_PARSER_SQL92_GRM_TAB_HPP_INCLUDED
# define YY_YY_AQ_PARSER_SQL92_GRM_TAB_HPP_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     K_AND = 258,
     K_OR = 259,
     K_PLUS = 260,
     K_MINUS = 261,
     K_MUL = 262,
     K_DIV = 263,
     K_EQ = 264,
     K_LT = 265,
     K_GT = 266,
     K_NEQ = 267,
     K_LEQ = 268,
     K_GEQ = 269,
     K_NOT = 270,
     K_CONCAT = 271,
     K_STAR = 272,
     K_UMINUS = 273,
     K_JEQ = 274,
     K_JAUTO = 275,
     K_PERIOD = 276,
     K_COMMA = 277,
     K_SEMICOLON = 278,
     K_INTEGER = 279,
     K_REAL = 280,
     K_STRING = 281,
     K_DATE_VALUE = 282,
     K_IDENT = 283,
     K_TRUE = 284,
     K_FALSE = 285,
     K_UNKNOWN = 286,
     K_ALL = 287,
     K_ANY = 288,
     K_AS = 289,
     K_ASC = 290,
     K_AVG = 291,
     K_BETWEEN = 292,
     K_BY = 293,
     K_CASE = 294,
     K_COMMIT = 295,
     K_COUNT = 296,
     K_DATE = 297,
     K_DAY = 298,
     K_DEFAULT = 299,
     K_DEFERRED = 300,
     K_DELETE = 301,
     K_DESC = 302,
     K_DISTINCT = 303,
     K_ELSE = 304,
     K_END = 305,
     K_EXISTS = 306,
     K_EXTRACT = 307,
     K_ESCAPE = 308,
     K_IMMEDIATE = 309,
     K_FOR = 310,
     K_FROM = 311,
     K_FULL = 312,
     K_GROUP = 313,
     K_HAVING = 314,
     K_IN = 315,
     K_INNER = 316,
     K_INSERT = 317,
     K_INTERVAL = 318,
     K_INTO = 319,
     K_IS = 320,
     K_JOIN = 321,
     K_LEFT = 322,
     K_LIKE = 323,
     K_MAX = 324,
     K_MIN = 325,
     K_MONTH = 326,
     K_NATURAL = 327,
     K_NULL = 328,
     K_ON = 329,
     K_ORDER = 330,
     K_OUTER = 331,
     K_RIGHT = 332,
     K_ROLLBACK = 333,
     K_SELECT = 334,
     K_SET = 335,
     K_SUBSTRING = 336,
     K_SUM = 337,
     K_TABLE = 338,
     K_THEN = 339,
     K_TRANSACTION = 340,
     K_UNION = 341,
     K_UPDATE = 342,
     K_VALUES = 343,
     K_WHEN = 344,
     K_WHERE = 345,
     K_WORK = 346,
     K_YEAR = 347,
     K_FUNC = 348,
     K_TO = 349,
     K_TO_DATE = 350,
     K_TO_CHAR = 351,
     K_CALL = 352,
     K_COLUMNS = 353,
     K_LIST = 354,
     K_OUTREF = 355,
     K_SOURCE = 356,
     K_START = 357,
     K_COLUMN = 358,
     K_LPAREN = 359,
     K_RPAREN = 360,
     K_LBRACE = 361,
     K_RBRACE = 362,
     K_LBRACKETS = 363,
     K_RBRACKETS = 364,
     K_SOME = 365,
     K_REPLACE = 366,
     K_DELETED = 367,
     K_FIRST_VALUE = 368,
     K_LAST_VALUE = 369,
     K_LEAD = 370,
     K_LAG = 371,
     K_OVER = 372,
     K_PARTITION = 373,
     K_SQRT = 374,
     K_ABS = 375,
     K_FRAME = 376,
     K_ROWS = 377,
     K_RANGE = 378,
     K_PRECEDING = 379,
     K_FOLLOWING = 380,
     K_UNBOUNDED = 381,
     K_CURRENT = 382,
     K_ROW = 383,
     K_CAST = 384,
     K_STRING_TYPE = 385,
     K_REAL_TYPE = 386,
     K_INTEGER_TYPE = 387,
     K_CREATE = 388,
     K_INSERT_ARGS = 389,
     K_CURRENT_DATE = 390,
     K_NVL = 391,
     K_UPDATE_ARGS = 392,
     K_ROW_NUMBER = 393,
     K_TRUNCATE = 394,
     K_DECODE = 395,
     K_NOT_BETWEEN = 396,
     K_NOT_LIKE = 397,
     K_NOT_IN = 398,
     K_JNO = 399,
     K_JINF = 400,
     K_JIEQ = 401,
     K_JSEQ = 402,
     K_JSUP = 403,
     K_JNEQ = 404,
     K_SEL_MINUS = 405,
     K_IN_VALUES = 406,
     K_MERGE = 407,
     K_MATCHED = 408,
     K_USING = 409,
     K_MERGE_ARGS1 = 410,
     K_MERGE_ARGS2 = 411,
     K_TARGET = 412
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */

#endif /* !YY_YY_AQ_PARSER_SQL92_GRM_TAB_HPP_INCLUDED  */
