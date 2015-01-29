/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison interface for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2011 Free Software Foundation, Inc.
   
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
/* Tokens.  */
#define K_AND 258
#define K_OR 259
#define K_PLUS 260
#define K_MINUS 261
#define K_MUL 262
#define K_DIV 263
#define K_EQ 264
#define K_LT 265
#define K_GT 266
#define K_NEQ 267
#define K_LEQ 268
#define K_GEQ 269
#define K_NOT 270
#define K_CONCAT 271
#define K_STAR 272
#define K_UMINUS 273
#define K_JEQ 274
#define K_JAUTO 275
#define K_PERIOD 276
#define K_COMMA 277
#define K_SEMICOLON 278
#define K_INTEGER 279
#define K_REAL 280
#define K_STRING 281
#define K_DATE_VALUE 282
#define K_IDENT 283
#define K_TRUE 284
#define K_FALSE 285
#define K_UNKNOWN 286
#define K_ALL 287
#define K_ANY 288
#define K_AS 289
#define K_ASC 290
#define K_AVG 291
#define K_BETWEEN 292
#define K_BY 293
#define K_CASE 294
#define K_COMMIT 295
#define K_COUNT 296
#define K_DATE 297
#define K_DAY 298
#define K_DEFAULT 299
#define K_DEFERRED 300
#define K_DELETE 301
#define K_DESC 302
#define K_DISTINCT 303
#define K_ELSE 304
#define K_END 305
#define K_EXISTS 306
#define K_EXTRACT 307
#define K_ESCAPE 308
#define K_IMMEDIATE 309
#define K_FOR 310
#define K_FROM 311
#define K_FULL 312
#define K_GROUP 313
#define K_HAVING 314
#define K_IN 315
#define K_INNER 316
#define K_INSERT 317
#define K_INTERVAL 318
#define K_INTO 319
#define K_IS 320
#define K_JOIN 321
#define K_LEFT 322
#define K_LIKE 323
#define K_MAX 324
#define K_MIN 325
#define K_MONTH 326
#define K_NATURAL 327
#define K_NULL 328
#define K_ON 329
#define K_ORDER 330
#define K_OUTER 331
#define K_RIGHT 332
#define K_ROLLBACK 333
#define K_SELECT 334
#define K_SET 335
#define K_SUBSTRING 336
#define K_SUM 337
#define K_TABLE 338
#define K_THEN 339
#define K_TRANSACTION 340
#define K_UNION 341
#define K_UPDATE 342
#define K_VALUES 343
#define K_WHEN 344
#define K_WHERE 345
#define K_WORK 346
#define K_YEAR 347
#define K_FUNC 348
#define K_TO 349
#define K_TO_DATE 350
#define K_TO_CHAR 351
#define K_CALL 352
#define K_COLUMNS 353
#define K_LIST 354
#define K_OUTREF 355
#define K_SOURCE 356
#define K_START 357
#define K_COLUMN 358
#define K_LPAREN 359
#define K_RPAREN 360
#define K_LBRACE 361
#define K_RBRACE 362
#define K_LBRACKETS 363
#define K_RBRACKETS 364
#define K_SOME 365
#define K_REPLACE 366
#define K_DELETED 367
#define K_FIRST_VALUE 368
#define K_LAST_VALUE 369
#define K_LEAD 370
#define K_LAG 371
#define K_OVER 372
#define K_PARTITION 373
#define K_SQRT 374
#define K_ABS 375
#define K_FRAME 376
#define K_ROWS 377
#define K_RANGE 378
#define K_PRECEDING 379
#define K_FOLLOWING 380
#define K_UNBOUNDED 381
#define K_CURRENT 382
#define K_ROW 383
#define K_CAST 384
#define K_STRING_TYPE 385
#define K_REAL_TYPE 386
#define K_INTEGER_TYPE 387
#define K_CREATE 388
#define K_INSERT_ARGS 389
#define K_CURRENT_DATE 390
#define K_NVL 391
#define K_UPDATE_ARGS 392
#define K_ROW_NUMBER 393
#define K_TRUNCATE 394
#define K_DECODE 395
#define K_NOT_BETWEEN 396
#define K_NOT_LIKE 397
#define K_NOT_IN 398
#define K_JNO 399
#define K_JINF 400
#define K_JIEQ 401
#define K_JSEQ 402
#define K_JSUP 403
#define K_JNEQ 404
#define K_SEL_MINUS 405
#define K_IN_VALUES 406
#define K_MERGE 407
#define K_MATCHED 408
#define K_USING 409
#define K_MERGE_ARGS1 410
#define K_MERGE_ARGS2 411
#define K_TARGET 412




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


