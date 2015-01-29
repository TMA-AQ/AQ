/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison implementation for Yacc-like parsers in C
   
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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.5"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 268 of yacc.c  */
#line 2 "aq/parser/SQL92_Grm.y"

// %option bison-bridge
// %option bison-locations
// %option noyywrap

/* define stack type */
#define YYSTYPE aq::tnode*
#define YYPARSE_PARAM ppNode

/* define error & debugging flags */
#define YYERROR_VERBOSE
#define YYDEBUG 1

#include "SQLParser.h"
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>

// Forward Definitions
int yyerror( const char *pszMsg );

int yylex( void );
        
using namespace aq;



/* Line 268 of yacc.c  */
#line 100 "aq/parser/sql92_grm_tab.cpp"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
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


/* Copy the second part of user declarations.  */


/* Line 343 of yacc.c  */
#line 456 "aq/parser/sql92_grm_tab.cpp"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  31
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1987

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  158
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  171
/* YYNRULES -- Number of rules.  */
#define YYNRULES  338
/* YYNRULES -- Number of states.  */
#define YYNSTATES  624

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   412

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
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
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     6,     9,    11,    13,    15,    17,    19,
      21,    23,    28,    32,    34,    36,    38,    39,    41,    43,
      45,    49,    51,    55,    57,    60,    62,    65,    74,    83,
      92,    94,    97,   103,   106,   108,   112,   114,   118,   124,
     127,   130,   134,   137,   141,   144,   148,   150,   153,   154,
     158,   159,   162,   163,   167,   168,   170,   173,   177,   179,
     182,   186,   188,   190,   192,   194,   196,   200,   202,   204,
     208,   211,   213,   215,   217,   218,   220,   222,   224,   226,
     228,   230,   232,   234,   236,   241,   243,   245,   252,   257,
     262,   269,   274,   276,   280,   284,   286,   290,   294,   296,
     299,   301,   303,   305,   307,   309,   311,   313,   315,   317,
     319,   321,   323,   325,   327,   331,   333,   335,   337,   339,
     343,   345,   347,   349,   351,   356,   362,   368,   370,   372,
     374,   376,   378,   380,   382,   388,   393,   395,   398,   403,
     405,   408,   413,   416,   417,   419,   421,   423,   425,   427,
     429,   431,   433,   437,   439,   441,   443,   445,   447,   449,
     451,   453,   455,   459,   461,   465,   468,   470,   475,   479,
     481,   483,   485,   487,   489,   493,   495,   497,   499,   501,
     503,   505,   509,   514,   519,   524,   526,   528,   530,   532,
     534,   536,   543,   549,   554,   558,   562,   564,   566,   570,
     575,   582,   587,   594,   598,   604,   606,   608,   613,   617,
     620,   622,   624,   628,   630,   632,   636,   638,   640,   642,
     644,   648,   652,   654,   656,   658,   664,   666,   668,   670,
     674,   675,   677,   680,   681,   683,   688,   690,   692,   694,
     696,   698,   700,   704,   708,   712,   713,   715,   719,   721,
     723,   726,   727,   729,   731,   733,   735,   738,   740,   743,
     746,   751,   753,   755,   757,   760,   762,   765,   772,   774,
     776,   778,   780,   782,   789,   794,   799,   804,   809,   814,
     819,   821,   825,   832,   841,   843,   845,   847,   849,   851,
     853,   859,   870,   878,   880,   884,   886,   888,   890,   892,
     898,   909,   911,   915,   919,   925,   935,   939,   946,   948,
     950,   954,   956,   960,   964,   966,   968,   972,   976,   981,
     985,   989,   994,  1005,  1007,  1008,  1013,  1014,  1021,  1022,
    1025,  1026,  1034,  1035,  1039,  1041,  1050,  1052,  1056
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     159,     0,    -1,   161,   160,    -1,   302,   160,    -1,   303,
      -1,   306,    -1,   309,    -1,   310,    -1,   317,    -1,   319,
      -1,    23,    -1,    79,   164,   165,   171,    -1,   104,   163,
     105,    -1,   161,    -1,    32,    -1,    48,    -1,    -1,     7,
      -1,   166,    -1,   167,    -1,   166,    22,   167,    -1,   168,
      -1,   207,    21,     7,    -1,   191,    -1,   191,   170,    -1,
     169,    -1,   169,   170,    -1,   111,   104,   169,    22,    26,
      22,    26,   105,    -1,   111,   104,   206,    22,    26,    22,
      26,   105,    -1,   111,   104,    26,    22,    26,    22,    26,
     105,    -1,   186,    -1,    34,   186,    -1,   172,   176,   177,
     178,   179,    -1,    56,   173,    -1,   174,    -1,   173,    22,
     174,    -1,   180,    -1,   174,   175,   180,    -1,   174,   175,
     180,    74,   232,    -1,    61,    66,    -1,    67,    66,    -1,
      67,    76,    66,    -1,    77,    66,    -1,    77,    76,    66,
      -1,    57,    66,    -1,    57,    76,    66,    -1,    66,    -1,
      90,   232,    -1,    -1,    58,    38,   185,    -1,    -1,    59,
     232,    -1,    -1,    75,    38,   187,    -1,    -1,   181,    -1,
     181,   182,    -1,   181,    34,   182,    -1,   183,    -1,   183,
     182,    -1,   183,    34,   182,    -1,   301,    -1,   301,    -1,
     184,    -1,   162,    -1,   206,    -1,   185,    22,   206,    -1,
     301,    -1,   188,    -1,   187,    22,   188,    -1,   189,   190,
      -1,   191,    -1,    35,    -1,    47,    -1,    -1,   199,    -1,
     225,    -1,   192,    -1,   193,    -1,   194,    -1,   195,    -1,
     205,    -1,   196,    -1,    27,    -1,    42,   104,   192,   105,
      -1,   197,    -1,   135,    -1,    95,   104,   225,    22,    26,
     105,    -1,    95,   104,   225,   105,    -1,    96,   104,   199,
     105,    -1,    96,   104,   199,    22,    26,   105,    -1,    95,
     104,   192,   105,    -1,   200,    -1,   199,     5,   200,    -1,
     199,     6,   200,    -1,   201,    -1,   200,     7,   201,    -1,
     200,     8,   201,    -1,   203,    -1,   202,   203,    -1,     6,
      -1,   205,    -1,   204,    -1,    24,    -1,    25,    -1,   290,
      -1,   291,    -1,   292,    -1,   293,    -1,   294,    -1,   295,
      -1,   206,    -1,   208,    -1,   212,    -1,   104,   191,   105,
      -1,   285,    -1,   255,    -1,   289,    -1,   311,    -1,   207,
      21,   186,    -1,   186,    -1,   181,    -1,   209,    -1,   210,
      -1,    41,   104,     7,   105,    -1,    41,   104,   164,   191,
     105,    -1,   211,   104,   164,   191,   105,    -1,    36,    -1,
      69,    -1,    70,    -1,    82,    -1,   213,    -1,   214,    -1,
     215,    -1,    39,   221,   216,   220,    50,    -1,    39,   218,
     220,    50,    -1,   217,    -1,   217,   216,    -1,    89,   222,
      84,   223,    -1,   219,    -1,   218,   219,    -1,    89,   232,
      84,   223,    -1,    49,   223,    -1,    -1,   191,    -1,   191,
      -1,   224,    -1,    73,    -1,   191,    -1,   226,    -1,   227,
      -1,   229,    -1,   226,   228,   229,    -1,    16,    -1,     5,
      -1,   230,    -1,    26,    -1,   205,    -1,   231,    -1,   297,
      -1,   198,    -1,   233,    -1,   232,     4,   233,    -1,   234,
      -1,   233,     3,   234,    -1,    15,   235,    -1,   235,    -1,
     237,    65,    15,   236,    -1,   237,    65,   236,    -1,   237,
      -1,    29,    -1,    30,    -1,    31,    -1,   238,    -1,   104,
     232,   105,    -1,   239,    -1,   241,    -1,   242,    -1,   245,
      -1,   248,    -1,   249,    -1,   251,   240,   251,    -1,   251,
     240,    32,   250,    -1,   251,   240,    33,   250,    -1,   251,
     240,   110,   250,    -1,     9,    -1,    12,    -1,    10,    -1,
      11,    -1,    13,    -1,    14,    -1,   251,    15,    37,   251,
       3,   251,    -1,   251,    37,   251,     3,   251,    -1,   251,
      15,    60,   243,    -1,   251,    60,   243,    -1,   104,   244,
     105,    -1,   184,    -1,   191,    -1,   191,    22,   244,    -1,
     251,    15,    68,   247,    -1,   251,    15,    68,   247,    53,
      26,    -1,   246,    15,    68,   247,    -1,   246,    15,    68,
     247,    53,    26,    -1,   246,    68,   247,    -1,   246,    68,
     247,    53,    26,    -1,   226,    -1,   226,    -1,   251,    65,
      15,    73,    -1,   251,    65,    73,    -1,    51,   184,    -1,
     162,    -1,   253,    -1,   104,   252,   105,    -1,   250,    -1,
     253,    -1,   252,    22,   253,    -1,   191,    -1,    73,    -1,
      44,    -1,   208,    -1,   256,   117,   266,    -1,   138,   104,
     105,    -1,   254,    -1,   257,    -1,   264,    -1,   258,   104,
     259,   260,   105,    -1,   115,    -1,   116,    -1,   191,    -1,
      22,   261,   262,    -1,    -1,    24,    -1,    22,   263,    -1,
      -1,   191,    -1,   265,   104,   191,   105,    -1,   113,    -1,
     114,    -1,   268,    -1,   267,    -1,   269,    -1,   301,    -1,
     104,   270,   105,    -1,   271,   274,   275,    -1,   118,    38,
     272,    -1,    -1,   273,    -1,   272,    22,   273,    -1,   191,
      -1,   179,    -1,   276,   277,    -1,    -1,   122,    -1,   123,
      -1,   278,    -1,   280,    -1,   126,   124,    -1,   279,    -1,
     127,   128,    -1,    24,   124,    -1,    37,   281,     3,   282,
      -1,   283,    -1,   283,    -1,   278,    -1,   126,   125,    -1,
     284,    -1,    24,   125,    -1,   129,   104,   286,    34,   287,
     105,    -1,   191,    -1,   288,    -1,   130,    -1,   131,    -1,
     132,    -1,   136,   104,   191,    22,   191,   105,    -1,   119,
     104,   199,   105,    -1,   120,   104,   199,   105,    -1,    92,
     104,   192,   105,    -1,    71,   104,   192,   105,    -1,    43,
     104,   192,   105,    -1,    93,   104,   296,   105,    -1,   191,
      -1,   191,    22,   296,    -1,    81,   104,   300,    22,   298,
     105,    -1,    81,   104,   300,    22,   298,    22,   299,   105,
      -1,   199,    -1,   199,    -1,   205,    -1,   231,    -1,    26,
      -1,    28,    -1,   133,    83,   181,    34,   161,    -1,    62,
      64,   181,   104,   185,   105,    88,   104,   304,   105,    -1,
      62,    64,   181,   104,   185,   105,   161,    -1,   305,    -1,
     304,    22,   305,    -1,    24,    -1,    25,    -1,    26,    -1,
      27,    -1,    87,   181,    80,   307,   176,    -1,    87,   181,
      80,   307,    90,   104,   185,   105,    60,   162,    -1,   308,
      -1,   307,    22,   308,    -1,   186,     9,   305,    -1,    46,
      56,   181,    90,   307,    -1,    46,    56,   181,    90,   104,
     185,   105,    60,   162,    -1,   139,    83,   181,    -1,   140,
     104,   191,    22,   312,   105,    -1,   313,    -1,   314,    -1,
     314,    22,   316,    -1,   315,    -1,   314,    22,   315,    -1,
     305,    22,   305,    -1,   305,    -1,   318,    -1,   163,    86,
     163,    -1,   163,   150,   163,    -1,   163,    86,    32,   163,
      -1,   318,    86,   163,    -1,   318,   150,   163,    -1,   318,
      86,    32,   163,    -1,   152,   320,   180,   154,   180,    74,
     232,   321,   322,   324,    -1,    64,    -1,    -1,    89,   153,
      84,   325,    -1,    -1,    89,    15,   153,   323,    84,   326,
      -1,    -1,    38,   157,    -1,    -1,    89,    15,   153,    38,
     101,    84,   325,    -1,    -1,    87,    80,   327,    -1,    46,
      -1,    62,   104,   185,   105,    88,   104,   185,   105,    -1,
     328,    -1,   327,    22,   328,    -1,   206,     9,   206,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    89,    89,    93,    97,   101,   105,   109,   113,   117,
     123,   129,   145,   148,   152,   153,   154,   157,   158,   161,
     162,   171,   172,   179,   180,   188,   189,   199,   206,   213,
     222,   238,   260,   288,   294,   295,   302,   303,   310,   322,
     326,   330,   335,   339,   344,   348,   353,   356,   360,   363,
     367,   370,   374,   377,   381,   385,   386,   394,   399,   400,
     408,   415,   418,   421,   424,   427,   428,   435,   438,   439,
     446,   456,   475,   476,   477,   480,   481,   482,   488,   494,
     495,   496,   497,   498,   500,   504,   505,   509,   514,   520,
     524,   530,   537,   538,   543,   550,   551,   556,   563,   564,
     571,   574,   575,   576,   577,   580,   581,   582,   583,   584,
     585,   588,   592,   596,   597,   600,   601,   602,   603,   606,
     612,   618,   623,   624,   627,   632,   643,   658,   659,   660,
     661,   667,   673,   674,   687,   712,   727,   728,   734,   742,
     743,   749,   757,   761,   764,   767,   770,   771,   774,   778,
     784,   785,   788,   795,   796,   799,   802,   803,   804,   807,
     808,   811,   812,   819,   820,   827,   831,   834,   840,   845,
     848,   849,   850,   853,   854,   857,   858,   859,   860,   861,
     865,   874,   912,   918,   924,   932,   933,   934,   935,   936,
     937,   941,   950,   961,   967,   974,   975,   978,   979,   987,
     994,  1002,  1009,  1017,  1023,  1032,  1035,  1044,  1050,  1057,
    1063,  1066,  1067,  1070,  1073,  1074,  1081,  1082,  1083,  1087,
    1093,  1101,  1102,  1106,  1109,  1123,  1141,  1141,  1144,  1147,
    1161,  1164,  1167,  1170,  1173,  1180,  1188,  1188,  1192,  1193,
    1196,  1198,  1201,  1205,  1237,  1242,  1245,  1246,  1254,  1258,
    1262,  1269,  1271,  1272,  1274,  1275,  1277,  1281,  1282,  1285,
    1290,  1295,  1296,  1297,  1298,  1302,  1305,  1318,  1323,  1327,
    1329,  1330,  1331,  1333,  1341,  1347,  1353,  1359,  1365,  1371,
    1377,  1378,  1386,  1393,  1404,  1407,  1410,  1411,  1412,  1415,
    1419,  1426,  1436,  1448,  1449,  1456,  1457,  1458,  1459,  1463,
    1473,  1488,  1489,  1496,  1504,  1510,  1521,  1528,  1536,  1537,
    1540,  1547,  1548,  1555,  1562,  1566,  1568,  1573,  1578,  1584,
    1589,  1594,  1603,  1622,  1623,  1626,  1629,  1632,  1636,  1639,
    1640,  1643,  1647,  1650,  1654,  1657,  1665,  1666,  1673
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "K_AND", "K_OR", "K_PLUS", "K_MINUS",
  "K_MUL", "K_DIV", "K_EQ", "K_LT", "K_GT", "K_NEQ", "K_LEQ", "K_GEQ",
  "K_NOT", "K_CONCAT", "K_STAR", "K_UMINUS", "K_JEQ", "K_JAUTO",
  "K_PERIOD", "K_COMMA", "K_SEMICOLON", "K_INTEGER", "K_REAL", "K_STRING",
  "K_DATE_VALUE", "K_IDENT", "K_TRUE", "K_FALSE", "K_UNKNOWN", "K_ALL",
  "K_ANY", "K_AS", "K_ASC", "K_AVG", "K_BETWEEN", "K_BY", "K_CASE",
  "K_COMMIT", "K_COUNT", "K_DATE", "K_DAY", "K_DEFAULT", "K_DEFERRED",
  "K_DELETE", "K_DESC", "K_DISTINCT", "K_ELSE", "K_END", "K_EXISTS",
  "K_EXTRACT", "K_ESCAPE", "K_IMMEDIATE", "K_FOR", "K_FROM", "K_FULL",
  "K_GROUP", "K_HAVING", "K_IN", "K_INNER", "K_INSERT", "K_INTERVAL",
  "K_INTO", "K_IS", "K_JOIN", "K_LEFT", "K_LIKE", "K_MAX", "K_MIN",
  "K_MONTH", "K_NATURAL", "K_NULL", "K_ON", "K_ORDER", "K_OUTER",
  "K_RIGHT", "K_ROLLBACK", "K_SELECT", "K_SET", "K_SUBSTRING", "K_SUM",
  "K_TABLE", "K_THEN", "K_TRANSACTION", "K_UNION", "K_UPDATE", "K_VALUES",
  "K_WHEN", "K_WHERE", "K_WORK", "K_YEAR", "K_FUNC", "K_TO", "K_TO_DATE",
  "K_TO_CHAR", "K_CALL", "K_COLUMNS", "K_LIST", "K_OUTREF", "K_SOURCE",
  "K_START", "K_COLUMN", "K_LPAREN", "K_RPAREN", "K_LBRACE", "K_RBRACE",
  "K_LBRACKETS", "K_RBRACKETS", "K_SOME", "K_REPLACE", "K_DELETED",
  "K_FIRST_VALUE", "K_LAST_VALUE", "K_LEAD", "K_LAG", "K_OVER",
  "K_PARTITION", "K_SQRT", "K_ABS", "K_FRAME", "K_ROWS", "K_RANGE",
  "K_PRECEDING", "K_FOLLOWING", "K_UNBOUNDED", "K_CURRENT", "K_ROW",
  "K_CAST", "K_STRING_TYPE", "K_REAL_TYPE", "K_INTEGER_TYPE", "K_CREATE",
  "K_INSERT_ARGS", "K_CURRENT_DATE", "K_NVL", "K_UPDATE_ARGS",
  "K_ROW_NUMBER", "K_TRUNCATE", "K_DECODE", "K_NOT_BETWEEN", "K_NOT_LIKE",
  "K_NOT_IN", "K_JNO", "K_JINF", "K_JIEQ", "K_JSEQ", "K_JSUP", "K_JNEQ",
  "K_SEL_MINUS", "K_IN_VALUES", "K_MERGE", "K_MATCHED", "K_USING",
  "K_MERGE_ARGS1", "K_MERGE_ARGS2", "K_TARGET", "$accept", "startsymbol",
  "cmd_term", "select_stmt", "subquery", "query_exp", "set_quantifier",
  "select_list", "select_sublist_rec", "select_sublist", "derived_column",
  "replace_clause", "as_clause", "table_expression", "from_clause",
  "table_reference_list", "joined_table", "joined_type", "where_clause",
  "group_by_clause", "having_clause", "order_by_clause", "table_reference",
  "table_name", "correlation_name", "derived_table", "table_subquery",
  "column_name_list", "column_name", "sort_specification_list",
  "sort_specification", "sort_key", "ordering_specification",
  "value_expression", "datetime_value_expression", "datetime_term",
  "datetime_factor", "datetime_primary", "datetime_value_function",
  "date_conversion", "char_conversion", "numeric_value_expression", "term",
  "factor", "sign", "numeric_primary", "numeric_value_function",
  "value_expression_primary", "column_reference", "qualifier",
  "set_function_specification", "count_all", "general_set_function",
  "set_function_type", "case_expression", "case_specification",
  "simple_case", "searched_case", "simple_when_clause_list",
  "simple_when_clause", "searched_when_clause_list",
  "searched_when_clause", "else_clause", "case_operand", "when_operand",
  "result", "result_expression", "string_value_expression",
  "character_value_expression", "concatenation", "concatenation_operator",
  "character_factor", "character_primary", "string_value_function",
  "search_condition", "boolean_term", "boolean_factor", "boolean_test",
  "truth_value", "boolean_primary", "predicate", "comparison_predicate",
  "comp_op", "between_predicate", "in_predicate", "in_predicate_value",
  "in_value_list", "like_predicate", "match_value", "pattern",
  "null_predicate", "exists_predicate", "row_subquery",
  "row_value_constructor", "row_value_constructor_list",
  "row_value_constructor_element", "aggregate_function", "window_function",
  "window_function_type", "lead_or_lag_function", "lead_or_lag",
  "lead_or_lag_extent", "offset_optional", "offset",
  "default_expression_optional", "default_expression",
  "first_or_last_value_function", "first_or_last_value",
  "window_name_or_specification", "inline_window_specification",
  "window_name", "window_specification", "window_specification_details",
  "window_partition_clause", "window_partition_column_reference_list",
  "window_partition_column_reference", "window_order_clause",
  "window_frame_clause", "window_frame_units", "window_frame_extent",
  "window_frame_start", "window_frame_preceding", "window_frame_between",
  "window_frame_bound_1", "window_frame_bound_2", "window_frame_bound",
  "window_frame_following", "cast_specification", "cast_operand",
  "cast_target", "data_type", "nvl_specification", "square_root",
  "absolute_value_expression", "year_expresssion", "month_expresssion",
  "day_expresssion", "aq_function", "aq_arg_list",
  "binary_substring_function", "start_position", "string_length",
  "binary_primary", "identifier", "create_table_stmt", "insert_stmt",
  "value_list", "value_scalar", "update_stmt", "column_value_list",
  "column_value_pair", "delete_stmt", "truncate_stmt",
  "decode_specification", "search_result_list",
  "search_result_list_with_default", "search_result_list_without_default",
  "search_result_pair", "default_result", "union_minus_stmt",
  "union_minus_list", "merge_stmt", "optional_into", "when_matched",
  "when_not_matched", "optional_by_target", "when_not_matched_by_source",
  "merge_matched", "merge_not_matched", "column_column_list",
  "column_column_pair", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   158,   159,   159,   159,   159,   159,   159,   159,   159,
     160,   161,   162,   163,   164,   164,   164,   165,   165,   166,
     166,   167,   167,   168,   168,   168,   168,   169,   169,   169,
     170,   170,   171,   172,   173,   173,   174,   174,   174,   175,
     175,   175,   175,   175,   175,   175,   175,   176,   176,   177,
     177,   178,   178,   179,   179,   180,   180,   180,   180,   180,
     180,   181,   182,   183,   184,   185,   185,   186,   187,   187,
     188,   189,   190,   190,   190,   191,   191,   191,   192,   193,
     194,   195,   195,   195,   196,   196,   196,   197,   197,   198,
     198,   198,   199,   199,   199,   200,   200,   200,   201,   201,
     202,   203,   203,   203,   203,   204,   204,   204,   204,   204,
     204,   205,   205,   205,   205,   205,   205,   205,   205,   206,
     206,   207,   208,   208,   209,   209,   210,   211,   211,   211,
     211,   212,   213,   213,   214,   215,   216,   216,   217,   218,
     218,   219,   220,   220,   221,   222,   223,   223,   224,   225,
     226,   226,   227,   228,   228,   229,   230,   230,   230,   231,
     231,   232,   232,   233,   233,   234,   234,   235,   235,   235,
     236,   236,   236,   237,   237,   238,   238,   238,   238,   238,
     238,   239,   239,   239,   239,   240,   240,   240,   240,   240,
     240,   241,   241,   242,   242,   243,   243,   244,   244,   245,
     245,   245,   245,   245,   245,   246,   247,   248,   248,   249,
     250,   251,   251,   251,   252,   252,   253,   253,   253,   254,
     255,   256,   256,   256,   256,   257,   258,   258,   259,   260,
     260,   261,   262,   262,   263,   264,   265,   265,   266,   266,
     267,   268,   269,   270,   271,   271,   272,   272,   273,   274,
     275,   275,   276,   276,   277,   277,   278,   278,   278,   279,
     280,   281,   282,   283,   283,   283,   284,   285,   286,   287,
     288,   288,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   296,   297,   297,   298,   299,   300,   300,   300,   301,
     302,   303,   303,   304,   304,   305,   305,   305,   305,   306,
     306,   307,   307,   308,   309,   309,   310,   311,   312,   312,
     313,   314,   314,   315,   316,   317,   318,   318,   318,   318,
     318,   318,   319,   320,   320,   321,   321,   322,   322,   323,
     323,   324,   324,   325,   325,   326,   327,   327,   328
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     2,     1,     1,     1,     1,     1,     1,
       1,     4,     3,     1,     1,     1,     0,     1,     1,     1,
       3,     1,     3,     1,     2,     1,     2,     8,     8,     8,
       1,     2,     5,     2,     1,     3,     1,     3,     5,     2,
       2,     3,     2,     3,     2,     3,     1,     2,     0,     3,
       0,     2,     0,     3,     0,     1,     2,     3,     1,     2,
       3,     1,     1,     1,     1,     1,     3,     1,     1,     3,
       2,     1,     1,     1,     0,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     4,     1,     1,     6,     4,     4,
       6,     4,     1,     3,     3,     1,     3,     3,     1,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     1,     1,     1,     1,     3,
       1,     1,     1,     1,     4,     5,     5,     1,     1,     1,
       1,     1,     1,     1,     5,     4,     1,     2,     4,     1,
       2,     4,     2,     0,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     1,     3,     2,     1,     4,     3,     1,
       1,     1,     1,     1,     3,     1,     1,     1,     1,     1,
       1,     3,     4,     4,     4,     1,     1,     1,     1,     1,
       1,     6,     5,     4,     3,     3,     1,     1,     3,     4,
       6,     4,     6,     3,     5,     1,     1,     4,     3,     2,
       1,     1,     3,     1,     1,     3,     1,     1,     1,     1,
       3,     3,     1,     1,     1,     5,     1,     1,     1,     3,
       0,     1,     2,     0,     1,     4,     1,     1,     1,     1,
       1,     1,     3,     3,     3,     0,     1,     3,     1,     1,
       2,     0,     1,     1,     1,     1,     2,     1,     2,     2,
       4,     1,     1,     1,     2,     1,     2,     6,     1,     1,
       1,     1,     1,     6,     4,     4,     4,     4,     4,     4,
       1,     3,     6,     8,     1,     1,     1,     1,     1,     1,
       5,    10,     7,     1,     3,     1,     1,     1,     1,     5,
      10,     1,     3,     3,     5,     9,     3,     6,     1,     1,
       3,     1,     3,     3,     1,     1,     3,     3,     4,     3,
       3,     4,    10,     1,     0,     4,     0,     6,     0,     2,
       0,     7,     0,     3,     1,     8,     1,     3,     3
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     0,     0,    16,     0,     0,     0,   324,     0,    13,
       0,     0,     4,     5,     6,     7,     8,   315,     9,     0,
       0,    14,    15,     0,   289,     0,    61,     0,     0,   323,
       0,     1,    10,     2,     0,     0,     3,     0,     0,     0,
       0,   100,    17,   103,   104,   156,    83,   127,     0,     0,
       0,     0,   128,   129,     0,     0,   130,     0,     0,     0,
       0,     0,     0,   236,   237,   226,   227,     0,     0,     0,
      86,     0,     0,     0,     0,    18,    19,    21,    25,   121,
     120,    23,    77,    78,    79,    80,    82,    85,   160,    75,
      92,    95,     0,    98,   102,    81,   111,     0,   112,   122,
     123,     0,   113,   131,   132,   133,    76,   149,   150,   151,
     155,   158,   222,   116,     0,   223,     0,   224,     0,   115,
     117,   105,   106,   107,   108,   109,   110,   159,    67,   118,
       0,     0,   306,     0,    64,     0,    55,    58,    63,     0,
      13,   316,   317,     0,   319,   320,     0,     0,     0,   144,
       0,   143,   139,     0,    16,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    11,    48,     0,     0,    26,    30,    67,    24,
       0,     0,     0,     0,    99,   101,     0,    16,   154,   153,
       0,     0,     0,     0,     0,    48,   301,     0,     0,     0,
       0,    56,    62,     0,    59,   318,   321,     0,   304,     0,
      65,     0,   218,     0,   217,     0,   210,   216,   149,     0,
     161,   163,   166,   169,   173,   175,   176,   177,   178,     0,
     179,   180,   213,     0,   211,     0,     0,   140,     0,     0,
     143,   136,     0,     0,     0,     0,    81,     0,     0,   288,
       0,   286,   287,     0,     0,   280,     0,     0,   157,     0,
       0,   114,     0,     0,     0,     0,     0,   268,     0,     0,
     221,     0,    33,    34,    36,     0,    50,    20,    31,    93,
      94,    96,    97,    22,   119,     0,   157,   152,   245,   220,
     239,   238,   240,   241,   228,   230,     0,     0,     0,     0,
     299,   290,    12,     0,    57,    60,     0,     0,     0,   165,
     209,   216,     0,     0,   211,     0,     0,     0,     0,     0,
       0,   185,   187,   188,   186,   189,   190,     0,     0,     0,
       0,     0,   147,   148,   142,   146,   135,   145,     0,     0,
     137,   124,     0,     0,    84,   278,   277,     0,     0,   276,
       0,   279,    91,     0,    88,     0,    89,     0,     0,     0,
     274,   275,     0,     0,     0,     0,     0,     0,    46,     0,
       0,     0,    47,     0,    52,     0,     0,     0,    54,     0,
       0,   235,   295,   296,   297,   298,   303,   302,     0,     0,
       0,    66,     0,   292,   174,     0,   212,   162,   141,   164,
       0,   170,   171,   172,   168,     0,   206,   203,     0,     0,
       0,     0,     0,     0,   196,   194,     0,   208,     0,     0,
       0,   181,     0,   134,   125,   284,     0,   281,     0,     0,
       0,     0,     0,   270,   271,   272,     0,   269,     0,     0,
       0,   308,   309,   311,    35,    44,     0,    39,    40,     0,
      42,     0,    37,     0,     0,    54,   126,     0,   242,     0,
     249,   251,   231,   233,   225,     0,   111,   326,     0,     0,
     215,   167,   201,     0,     0,   193,   199,   214,     0,   197,
       0,   207,   182,   183,   184,   138,     0,   282,    87,    90,
       0,     0,     0,   267,   273,     0,   307,     0,    45,    41,
      43,     0,    49,    51,    32,   248,   244,   246,     0,   252,
     253,   243,     0,     0,   229,     0,     0,   328,   305,     0,
     293,     0,   204,     0,     0,   192,     0,   195,   285,     0,
       0,     0,     0,   313,   314,   312,   310,    38,     0,    53,
      68,    74,    71,     0,     0,     0,     0,   250,   254,   257,
     255,   234,   232,     0,     0,     0,   332,     0,   291,   202,
     191,   200,   198,   283,    29,    27,    28,   247,     0,    72,
      73,    70,   259,     0,     0,   263,     0,   261,   265,   256,
     258,   300,     0,     0,     0,   322,   294,    69,   266,   264,
       0,   334,     0,   325,   330,     0,   260,   262,     0,     0,
       0,     0,     0,   333,   336,   329,     0,     0,     0,     0,
       0,   327,     0,   338,   337,     0,     0,     0,   331,     0,
       0,     0,     0,   335
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     8,    33,   140,   216,   198,    23,    74,    75,    76,
      77,    78,   176,   172,   173,   272,   273,   371,   276,   374,
     455,   460,   274,    79,   201,   137,   138,   209,    80,   539,
     540,   541,   571,   217,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,   150,
      98,    99,   100,   101,   102,   103,   104,   105,   240,   241,
     151,   152,   238,   153,   338,   334,   335,   106,   107,   108,
     190,   109,   110,   111,   312,   220,   221,   222,   404,   223,
     224,   225,   331,   226,   227,   415,   480,   228,   229,   407,
     230,   231,   232,   233,   313,   234,   112,   113,   114,   115,
     116,   295,   380,   463,   514,   552,   117,   118,   289,   290,
     291,   292,   377,   378,   506,   507,   461,   511,   512,   547,
     575,   549,   550,   576,   596,   577,   578,   119,   268,   436,
     437,   120,   121,   122,   123,   124,   125,   126,   256,   127,
     426,   529,   253,   128,    11,    12,   519,   386,    13,   195,
     196,    14,    15,   129,   440,   441,   442,   443,   536,    16,
      17,    18,    30,   517,   556,   600,   585,   593,   611,   603,
     604
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -341
static const yytype_int16 yypact[] =
{
      29,    -7,    -2,   187,    51,    23,    28,    86,   230,   216,
      68,   216,  -341,  -341,  -341,  -341,  -341,    74,  -341,    51,
      51,  -341,  -341,   991,  -341,   164,  -341,    51,    51,  -341,
      18,  -341,  -341,  -341,    40,   168,  -341,    52,   168,   197,
     173,  -341,  -341,  -341,  -341,  -341,  -341,  -341,  1237,   212,
     225,   240,  -341,  -341,   241,   246,  -341,   249,   250,   251,
     255,  1565,   257,  -341,  -341,  -341,  -341,   259,   260,   262,
    -341,   264,   266,   267,   268,   296,  -341,  -341,   224,  -341,
    -341,   224,  -341,  -341,  -341,  -341,  -341,  -341,  -341,   284,
     288,  -341,   287,  -341,  -341,   220,  -341,   331,   245,  -341,
    -341,   270,  -341,  -341,  -341,  -341,  -341,   229,  -341,  -341,
    -341,  -341,  -341,  -341,   265,  -341,   271,  -341,   272,  -341,
    -341,  -341,  -341,  -341,  -341,  -341,  -341,  -341,   356,  -341,
      51,   349,  -341,   168,  -341,   231,   248,   258,  -341,   168,
    -341,  -341,  -341,   168,  -341,  -341,    70,    51,   663,  -341,
     363,    39,  -341,   297,   208,  1847,  1847,  1847,  1725,  1847,
    1565,  1688,  1627,   282,    25,  1627,  1627,  1565,  1565,   289,
    1565,    18,  -341,   299,  1319,    51,  -341,  -341,  -341,  -341,
    1627,  1627,  1627,  1627,  -341,  -341,   222,   187,  -341,  -341,
    1786,   118,  1565,  1565,   383,    82,  -341,   168,   290,    18,
      51,  -341,  -341,    51,  -341,  -341,  -341,    51,   374,     9,
    -341,   827,  -341,   293,  -341,   440,  -341,  -341,   107,    56,
     401,  -341,  -341,   340,  -341,  -341,  -341,  -341,  -341,    41,
    -341,  -341,  -341,   254,  -341,    51,  1401,  -341,   358,  1565,
     360,   297,   307,  1565,   306,   308,  -341,   309,   310,  -341,
     314,  -341,  -341,   397,   315,   399,   317,   319,   321,    22,
      59,  -341,   406,   407,   408,    81,    84,  -341,   398,   409,
    -341,   411,   413,   217,  -341,   663,   378,  -341,  -341,   288,
     288,  -341,  -341,  -341,  -341,  1565,  -341,  -341,   320,  -341,
    -341,  -341,  -341,  -341,  -341,   415,   334,   279,    51,   745,
    -341,  -341,  -341,   367,  -341,  -341,    30,    51,   191,  -341,
    -341,   282,    44,    37,    60,   663,  1401,   663,   242,   375,
    1786,  -341,  -341,  -341,  -341,  -341,  -341,   186,  1073,   338,
     103,   557,  -341,  -341,  -341,  -341,  -341,  -341,   361,   394,
    -341,  -341,   342,  1786,  -341,  -341,  -341,  1847,  1627,  -341,
    1565,  -341,  -341,   422,  -341,   423,  -341,   424,   425,   427,
    -341,  -341,   178,  1565,   279,    18,     0,   388,  -341,   185,
     209,    18,   452,   419,   400,   353,   432,   355,   386,   447,
     368,  -341,  -341,  -341,  -341,  -341,  -341,  -341,   440,   663,
     412,  -341,   370,  -341,  -341,  1155,  -341,   401,  -341,  -341,
     305,  -341,  -341,  -341,  -341,  1786,   229,   433,  1073,   338,
    1786,   909,   474,  1483,  -341,  -341,   405,  -341,   293,   293,
     293,  -341,  1401,  -341,  -341,   284,    75,  -341,   382,   384,
     458,   466,   470,  -341,  -341,  -341,   389,  -341,   390,   471,
     391,  -341,   475,  -341,   217,  -341,   434,  -341,  -341,   435,
    -341,   436,   430,    51,   663,   386,  -341,  1565,  -341,   460,
    -341,   176,  -341,   477,  -341,    77,    78,    24,   293,   279,
    -341,  -341,   453,   479,   504,  -341,   455,  -341,  1073,   490,
     418,  -341,  -341,  -341,  -341,  -341,  1627,  -341,  -341,  -341,
     488,   491,   492,  -341,  -341,   279,  -341,   279,  -341,  -341,
    -341,   663,   494,   452,  -341,  -341,   498,  -341,  1565,  -341,
    -341,  -341,    26,  1565,  -341,   464,   373,   438,  -341,    93,
    -341,   502,  -341,  1073,   503,  -341,  1565,  -341,   284,   426,
     429,   437,   441,  -341,   471,  -341,  -341,   452,  1565,   508,
    -341,   196,  -341,   414,    -1,   416,   420,  -341,  -341,  -341,
    -341,  -341,  -341,   293,   457,   522,   450,   279,  -341,  -341,
    -341,  -341,  -341,  -341,  -341,  -341,  -341,  -341,  1565,  -341,
    -341,  -341,  -341,   207,   214,  -341,   540,  -341,  -341,  -341,
    -341,  -341,   151,   396,   532,  -341,  -341,  -341,  -341,  -341,
      -1,  -341,   472,  -341,   512,   404,  -341,  -341,    51,   410,
     467,   520,   552,   542,  -341,  -341,   500,   465,    51,    51,
     461,  -341,   484,  -341,  -341,    51,   151,    95,  -341,   482,
     468,    51,    98,  -341
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -341,  -341,   560,    17,   -28,    20,    54,  -341,  -341,   403,
    -341,   428,   493,  -341,  -341,  -341,   221,  -341,   392,  -341,
    -341,   124,   -20,     7,    -4,  -341,  -205,  -204,   -45,  -341,
       5,  -341,  -341,   -23,  -114,  -341,  -341,  -341,  -341,  -341,
    -341,  -153,   140,   159,  -341,   496,  -341,   -88,  -146,   -18,
    -341,  -341,  -341,  -341,  -341,  -341,  -341,  -341,   350,  -341,
    -341,   443,   357,  -341,  -341,  -301,  -341,  -122,  -108,  -341,
    -341,   417,  -341,   444,  -141,   280,   286,   393,   205,  -341,
    -341,  -341,  -341,  -341,  -341,   199,    80,  -341,  -341,  -300,
    -341,  -341,   -71,  -312,  -341,  -201,  -341,  -341,  -341,  -341,
    -341,  -341,  -341,  -341,  -341,  -341,  -341,  -341,  -341,  -341,
    -341,  -341,  -341,  -341,  -341,    71,  -341,  -341,  -341,  -341,
      99,  -341,  -341,  -341,  -341,    27,  -341,  -341,  -341,  -341,
    -341,  -341,  -341,  -341,  -341,  -341,  -341,  -341,   263,  -341,
    -341,  -341,  -341,     2,  -341,  -341,  -341,  -340,  -341,   469,
     312,  -341,  -341,  -341,  -341,  -341,  -341,   115,  -341,  -341,
    -341,  -341,  -341,  -341,  -341,  -341,  -341,     3,  -341,  -341,
      11
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -220
static const yytype_int16 yytable[] =
{
      81,   210,   134,   306,   185,    97,    26,   219,   310,   260,
     135,    25,   265,   266,   314,   398,   412,     9,   264,   421,
      10,    26,    26,   573,   439,   149,    39,    40,   315,    26,
      26,   307,    26,   177,   131,   132,   177,   136,   163,   259,
     218,   245,   247,   248,   353,   254,    24,   257,   315,    19,
     543,   262,   307,    24,   141,   142,   319,   144,   145,   395,
     315,   210,    20,   544,   180,   181,   445,   246,   246,   246,
     251,   246,   139,   258,   185,     1,   446,   185,   185,    24,
     178,   355,  -214,   178,   143,   194,   180,   181,   236,   180,
     181,     2,   185,   185,   185,   185,   474,   486,    24,   307,
     -65,   194,   286,   218,   298,   472,    27,   218,     3,   320,
     476,    28,   188,   516,   308,   557,     4,   307,   416,     3,
     307,   485,   133,   189,   414,   574,   546,   354,   148,   520,
     278,     3,   178,   204,   372,   390,    62,   255,   202,   202,
     316,   284,   396,   134,   267,   269,    24,   271,   178,   394,
      29,    81,   545,   546,    34,   533,    97,   534,   372,   205,
      37,   391,     5,   206,   356,  -214,   525,   218,     6,   294,
     296,   134,   299,    26,   207,  -205,   417,   178,   136,   303,
     487,     7,   515,   -65,   465,   134,   360,   314,   178,   361,
     284,   218,   311,   293,   470,   425,   304,   591,   558,   305,
     619,    26,   202,   623,   414,   202,   136,   218,   243,   218,
     477,   560,   406,   333,   301,   242,   337,   586,    35,    21,
     342,   259,   288,   408,    38,  -101,  -101,  -101,  -101,   283,
      31,   569,   286,   257,   188,    22,  -157,   178,   592,    32,
      21,   285,   466,   570,   130,   189,   409,     3,   467,   502,
      24,   448,    24,   194,   410,   286,    22,   400,   175,   246,
     185,   449,   375,   321,   322,   323,   324,   325,   326,   327,
       3,   401,   402,   403,   366,   450,    24,   147,   367,   392,
     218,   218,   200,   368,   369,   451,    24,   146,  -157,   180,
     181,   328,   203,   333,   370,   182,   183,   406,   509,   510,
     178,   134,   406,   382,   383,   384,   385,   210,   433,   434,
     435,    43,    44,   503,   329,    24,   154,   286,   174,   330,
     279,   280,   286,    47,   171,   393,    48,   255,    49,   155,
      51,   572,   588,   528,   401,   402,   403,   134,   579,   589,
     438,   281,   282,   134,   156,   157,   218,   482,   483,   484,
     158,   452,   186,   159,   160,   161,    52,    53,    54,   162,
     537,   164,  -219,   165,   166,   311,   167,    26,   168,    56,
     169,   170,   136,    26,   187,   192,   193,   -61,   136,    57,
      58,   134,   191,   197,   235,   199,   239,   261,   311,   275,
     479,    61,   297,   218,   270,   302,   298,   133,   185,   333,
      63,    64,    65,    66,   317,   318,    67,    68,   336,   236,
     343,   617,   341,   344,   345,   346,    69,   622,   347,   348,
     349,   350,   351,    71,   352,    72,   -81,    73,   357,   358,
     359,   363,   362,   364,   505,   365,   373,   379,   376,   381,
     518,   389,   413,   405,   423,   422,    41,   424,   428,   429,
     430,   431,   602,   432,   447,   211,   315,   453,   456,   454,
     458,   459,   613,   602,    43,    44,    45,    46,    24,   210,
     457,   462,   468,   464,   469,   210,    47,   478,   481,    48,
     490,    49,    50,    51,   212,   542,   473,   488,   491,   489,
     551,   213,   492,   495,   493,   494,   496,   497,   508,   513,
     498,   499,   500,   479,   501,   522,   521,   523,   524,    52,
      53,    54,   526,   214,   530,   505,   307,   531,   532,     3,
     538,    55,    56,   527,   553,   581,   554,   555,   559,   561,
     568,   563,    57,    58,   564,    59,    60,   583,   572,   584,
     579,   582,   565,   590,   215,   542,   566,   595,   580,   594,
     599,   606,   598,    63,    64,    65,    66,   601,   607,    67,
      68,   608,   610,    41,   609,   615,   612,   605,   616,    69,
     620,    36,   621,   587,   179,    70,    71,   277,    72,   504,
      73,    43,    44,    45,    46,    24,   444,   300,   184,   418,
     419,   340,   263,    47,   237,   397,    48,   339,    49,    50,
      51,   212,   252,   399,   309,   471,   562,   287,   475,   567,
     387,   548,   535,   427,     0,   208,     0,   597,     0,   618,
     614,     0,     0,     0,     0,     0,    52,    53,    54,     0,
     214,     0,     0,     0,     0,     0,     0,     0,    55,    56,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    57,
      58,     0,    59,    60,     0,     0,     0,     0,     0,     0,
       0,   411,     0,     0,     0,     0,     0,   420,     0,    41,
      63,    64,    65,    66,     0,     0,    67,    68,   211,     0,
       0,     0,     0,     0,     0,     0,    69,    43,    44,    45,
      46,    24,    70,    71,     0,    72,     0,    73,     0,    47,
       0,     0,    48,     0,    49,    50,    51,   212,     0,     0,
       0,     0,     0,     0,   213,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    52,    53,    54,     0,   214,     0,     0,     0,
       0,     0,     0,     0,    55,    56,     0,     0,     0,     0,
       0,    41,     0,     0,     0,    57,    58,     0,    59,    60,
     211,     0,     0,     0,     0,     0,     0,   215,     0,    43,
      44,    45,    46,    24,     0,     0,    63,    64,    65,    66,
       0,    47,    67,    68,    48,     0,    49,    50,    51,   212,
       0,     0,    69,     0,     0,     0,   213,     0,    70,    71,
       0,    72,     0,    73,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    52,    53,    54,     0,   214,     0,
       0,     0,     0,     0,     0,     0,    55,    56,     0,     0,
       0,     0,     0,    41,     0,     0,     0,    57,    58,     0,
      59,    60,     0,     0,     0,     0,     0,     0,     0,   388,
       0,    43,    44,    45,    46,    24,     0,     0,    63,    64,
      65,    66,     0,    47,    67,    68,    48,     0,    49,    50,
      51,   212,     0,     0,    69,     0,     0,     0,   213,     0,
      70,    71,     0,    72,     0,    73,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    52,    53,    54,     0,
     214,     0,     0,     0,     0,     0,     0,     0,    55,    56,
       0,     0,     0,     0,     0,    41,     0,     0,     0,    57,
      58,     0,    59,    60,     0,     0,     0,     0,     0,     0,
       0,   215,     0,    43,    44,    45,    46,    24,     0,     0,
      63,    64,    65,    66,     0,    47,    67,    68,    48,     0,
      49,    50,    51,   212,     0,     0,    69,     0,     0,     0,
       0,     0,    70,    71,     0,    72,     0,    73,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    52,    53,
      54,     0,   214,     0,     0,     0,     0,     0,     3,     0,
      55,    56,     0,     0,     0,     0,     0,    41,    42,     0,
       0,    57,    58,     0,    59,    60,     0,     0,     0,     0,
       0,     0,     0,    61,     0,    43,    44,    45,    46,    24,
       0,     0,    63,    64,    65,    66,     0,    47,    67,    68,
      48,     0,    49,    50,    51,     0,     0,     0,    69,     0,
       0,     0,     0,     0,    70,    71,     0,    72,     0,    73,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      52,    53,    54,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    55,    56,     0,     0,     0,     0,     0,    41,
       0,     0,     0,    57,    58,     0,    59,    60,     0,     0,
       0,     0,     0,     0,     0,    61,     0,    43,    44,    45,
      46,    24,    62,     0,    63,    64,    65,    66,     0,    47,
      67,    68,    48,     0,    49,    50,    51,   212,     0,     0,
      69,     0,     0,     0,     0,     0,    70,    71,     0,    72,
       0,    73,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    52,    53,    54,     0,   214,     0,     0,     0,
       0,     0,     0,     0,    55,    56,     0,     0,     0,     0,
       0,    41,     0,     0,     0,    57,    58,     0,    59,    60,
       0,     0,     0,     0,     0,     0,     0,   411,     0,    43,
      44,    45,    46,    24,     0,     0,    63,    64,    65,    66,
       0,    47,    67,    68,    48,     0,    49,    50,    51,   212,
       0,     0,    69,     0,     0,     0,     0,     0,    70,    71,
       0,    72,     0,    73,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    52,    53,    54,     0,   214,     0,
       0,     0,     0,     0,     0,     0,    55,    56,     0,     0,
       0,     0,     0,    41,     0,     0,     0,    57,    58,     0,
      59,    60,     0,     0,     0,     0,     0,     0,     0,    61,
       0,    43,    44,    45,    46,    24,     0,     0,    63,    64,
      65,    66,     0,    47,    67,    68,    48,     0,    49,    50,
      51,     0,     0,     0,    69,     0,     0,     0,     0,     0,
      70,    71,     0,    72,     0,    73,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    52,    53,    54,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    55,    56,
       0,     0,     0,     0,     0,    41,   148,     0,     0,    57,
      58,     0,    59,    60,     0,     0,     0,     0,     0,     0,
       0,    61,     0,    43,    44,    45,    46,    24,     0,     0,
      63,    64,    65,    66,     0,    47,    67,    68,    48,     0,
      49,    50,    51,     0,     0,     0,    69,     0,     0,     0,
       0,     0,    70,    71,     0,    72,     0,    73,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    52,    53,
      54,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      55,    56,     0,     0,     0,     0,     0,    41,     0,     0,
       0,    57,    58,     0,    59,    60,     0,     0,     0,     0,
       0,     0,     0,    61,     0,    43,    44,    45,    46,    24,
      62,     0,    63,    64,    65,    66,     0,    47,    67,    68,
      48,     0,    49,    50,    51,     0,     0,     0,    69,     0,
       0,     0,     0,     0,    70,    71,     0,    72,     0,    73,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      52,    53,    54,     0,   332,     0,     0,     0,     0,     0,
       0,     0,    55,    56,     0,     0,     0,     0,     0,    41,
       0,     0,     0,    57,    58,     0,    59,    60,     0,     0,
       0,     0,     0,     0,     0,    61,     0,    43,    44,    45,
      46,    24,     0,     0,    63,    64,    65,    66,     0,    47,
      67,    68,    48,     0,    49,    50,    51,     0,     0,     0,
      69,     0,     0,     0,     0,     0,    70,    71,     0,    72,
       0,    73,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    52,    53,    54,     0,     0,     0,     0,     0,
       0,     0,     3,     0,    55,    56,     0,     0,     0,     0,
       0,    41,     0,     0,     0,    57,    58,     0,    59,    60,
       0,     0,     0,     0,     0,     0,     0,    61,     0,    43,
      44,    45,    46,    24,     0,     0,    63,    64,    65,    66,
       0,    47,    67,    68,    48,     0,    49,    50,    51,     0,
       0,     0,    69,     0,     0,     0,     0,     0,    70,    71,
       0,    72,     0,    73,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    41,    52,    53,    54,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    55,    56,     0,     0,
       0,    43,    44,     0,     0,    24,     0,    57,    58,     0,
      59,    60,     0,    47,     0,     0,    48,     0,    49,    61,
      51,     0,     0,     0,     0,     0,     0,     0,    63,    64,
      65,    66,     0,     0,    67,    68,     0,     0,     0,     0,
       0,     0,     0,     0,    69,     0,    52,    53,    54,     0,
      70,    71,     0,    72,     0,    73,     0,     0,     0,    56,
       0,     0,     0,     0,    45,    46,    24,     0,     0,    57,
      58,     0,     0,     0,    47,     0,     0,    48,     0,    49,
      50,    61,     0,     0,     0,     0,     0,     0,     0,     0,
      63,    64,    65,    66,     0,     0,    67,    68,     0,     0,
       0,   249,     0,    24,     0,     0,    69,    52,    53,     0,
       0,    47,     0,    71,    48,    72,    49,    73,     0,    55,
      56,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    59,    60,     0,     0,     0,     0,     0,
       0,     0,    61,     0,    52,    53,     0,     0,     0,     0,
       0,    63,    64,    65,    66,     0,    55,    56,     0,     0,
       0,     0,    45,     0,    24,     0,     0,    69,     0,     0,
     250,    60,    47,    70,    71,    48,    72,    49,    73,    61,
       0,     0,     0,     0,     0,     0,     0,     0,    63,    64,
      65,    66,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    69,    52,    53,     0,     0,     0,
       0,    71,     0,    72,     0,    73,     0,    55,    56,     0,
       0,     0,     0,     0,    46,    24,     0,     0,     0,     0,
       0,   250,    60,    47,     0,     0,    48,     0,    49,    50,
      61,     0,     0,     0,     0,     0,     0,     0,     0,    63,
      64,    65,    66,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    69,    52,    53,     0,     0,
       0,     0,    71,     0,    72,     0,    73,     0,     0,    56,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   244,     0,     0,     0,     0,     0,     0,     0,
       0,    61,     0,     0,     0,     0,     0,     0,     0,     0,
      63,    64,    65,    66,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    69,     0,     0,     0,
       0,     0,    70,    71,     0,    72,     0,    73
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-341))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      23,   147,    30,   207,    92,    23,     4,   148,   213,   162,
      30,     4,   165,   166,   215,   316,   328,     0,   164,   331,
       0,    19,    20,    24,   364,    48,    19,    20,     4,    27,
      28,    22,    30,    78,    27,    28,    81,    30,    61,   161,
     148,   155,   156,   157,    22,   159,    28,   161,     4,    56,
      24,    26,    22,    28,    34,    35,    15,    37,    38,    22,
       4,   207,    64,    37,     5,     6,    66,   155,   156,   157,
     158,   159,    32,   161,   162,    46,    76,   165,   166,    28,
      78,    22,    22,    81,    32,   130,     5,     6,    49,     5,
       6,    62,   180,   181,   182,   183,   408,    22,    28,    22,
      22,   146,   190,   211,    22,   405,    83,   215,    79,    68,
     410,    83,     5,    89,   105,    22,    87,    22,    15,    79,
      22,   422,   104,    16,   329,   126,   127,   105,    89,   469,
     175,    79,   130,   137,   275,   105,   111,   160,   136,   137,
      84,   186,   105,   171,   167,   168,    28,   170,   146,   105,
      64,   174,   126,   127,    86,   495,   174,   497,   299,   139,
      86,   307,   133,   143,   105,   105,   478,   275,   139,   192,
     193,   199,    90,   171,   104,    68,    73,   175,   171,   199,
     105,   152,   105,   105,   388,   213,   105,   388,   186,   105,
     235,   299,   215,   191,   395,   348,   200,    46,   105,   203,
     105,   199,   200,   105,   409,   203,   199,   315,   154,   317,
     411,   523,   320,   236,   197,     7,   239,   557,   150,    32,
     243,   343,   104,    37,   150,     5,     6,     7,     8,     7,
       0,    35,   320,   347,     5,    48,    16,   235,    87,    23,
      32,   187,   388,    47,    80,    16,    60,    79,   389,   453,
      28,    66,    28,   298,    68,   343,    48,    15,    34,   347,
     348,    76,   285,     9,    10,    11,    12,    13,    14,    15,
      79,    29,    30,    31,    57,    66,    28,   104,    61,    88,
     388,   389,    34,    66,    67,    76,    28,    90,    68,     5,
       6,    37,    34,   316,    77,     7,     8,   405,   122,   123,
     298,   329,   410,    24,    25,    26,    27,   453,   130,   131,
     132,    24,    25,   454,    60,    28,   104,   405,    22,    65,
     180,   181,   410,    36,    56,   308,    39,   350,    41,   104,
      43,   124,   125,   486,    29,    30,    31,   365,   124,   125,
     363,   182,   183,   371,   104,   104,   454,   418,   419,   420,
     104,   371,    21,   104,   104,   104,    69,    70,    71,   104,
     501,   104,   117,   104,   104,   388,   104,   365,   104,    82,
     104,   104,   365,   371,   104,   104,   104,    21,   371,    92,
      93,   409,   117,    34,    21,   154,    89,   105,   411,    90,
     413,   104,     9,   501,   105,   105,    22,   104,   486,   422,
     113,   114,   115,   116,     3,    65,   119,   120,    50,    49,
     104,   615,   105,   105,   105,   105,   129,   621,   104,    22,
     105,    22,   105,   136,   105,   138,   105,   140,    22,    22,
      22,    22,    34,    22,   457,    22,    58,    22,   118,   105,
     468,    74,   104,    68,    50,    84,     6,   105,    26,    26,
      26,    26,   598,    26,    66,    15,     4,    38,   105,    59,
     105,    75,   608,   609,    24,    25,    26,    27,    28,   615,
      38,    24,    60,   105,   104,   621,    36,     3,    73,    39,
      22,    41,    42,    43,    44,   508,    53,   105,    22,   105,
     513,    51,    22,    22,   105,   105,   105,    22,    38,    22,
      66,    66,    66,   526,    74,    26,    53,     3,    53,    69,
      70,    71,    22,    73,    26,   538,    22,    26,    26,    79,
      22,    81,    82,   105,    60,   553,   153,    89,    26,    26,
      22,   105,    92,    93,   105,    95,    96,    15,   124,    89,
     124,    84,   105,     3,   104,   568,   105,    15,   128,   153,
      38,    84,    80,   113,   114,   115,   116,   153,    38,   119,
     120,     9,    62,     6,    22,   104,   101,   157,    84,   129,
      88,    11,   104,   568,    81,   135,   136,   174,   138,   455,
     140,    24,    25,    26,    27,    28,   365,   195,    92,    32,
      33,   241,   164,    36,   151,   315,    39,   240,    41,    42,
      43,    44,   158,   317,   211,   400,   526,   190,   409,   538,
     298,   512,   497,   350,    -1,   146,    -1,   590,    -1,   616,
     609,    -1,    -1,    -1,    -1,    -1,    69,    70,    71,    -1,
      73,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    81,    82,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,
      93,    -1,    95,    96,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   104,    -1,    -1,    -1,    -1,    -1,   110,    -1,     6,
     113,   114,   115,   116,    -1,    -1,   119,   120,    15,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   129,    24,    25,    26,
      27,    28,   135,   136,    -1,   138,    -1,   140,    -1,    36,
      -1,    -1,    39,    -1,    41,    42,    43,    44,    -1,    -1,
      -1,    -1,    -1,    -1,    51,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    69,    70,    71,    -1,    73,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    81,    82,    -1,    -1,    -1,    -1,
      -1,     6,    -1,    -1,    -1,    92,    93,    -1,    95,    96,
      15,    -1,    -1,    -1,    -1,    -1,    -1,   104,    -1,    24,
      25,    26,    27,    28,    -1,    -1,   113,   114,   115,   116,
      -1,    36,   119,   120,    39,    -1,    41,    42,    43,    44,
      -1,    -1,   129,    -1,    -1,    -1,    51,    -1,   135,   136,
      -1,   138,    -1,   140,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    69,    70,    71,    -1,    73,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    81,    82,    -1,    -1,
      -1,    -1,    -1,     6,    -1,    -1,    -1,    92,    93,    -1,
      95,    96,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   104,
      -1,    24,    25,    26,    27,    28,    -1,    -1,   113,   114,
     115,   116,    -1,    36,   119,   120,    39,    -1,    41,    42,
      43,    44,    -1,    -1,   129,    -1,    -1,    -1,    51,    -1,
     135,   136,    -1,   138,    -1,   140,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    69,    70,    71,    -1,
      73,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    81,    82,
      -1,    -1,    -1,    -1,    -1,     6,    -1,    -1,    -1,    92,
      93,    -1,    95,    96,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   104,    -1,    24,    25,    26,    27,    28,    -1,    -1,
     113,   114,   115,   116,    -1,    36,   119,   120,    39,    -1,
      41,    42,    43,    44,    -1,    -1,   129,    -1,    -1,    -1,
      -1,    -1,   135,   136,    -1,   138,    -1,   140,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,    70,
      71,    -1,    73,    -1,    -1,    -1,    -1,    -1,    79,    -1,
      81,    82,    -1,    -1,    -1,    -1,    -1,     6,     7,    -1,
      -1,    92,    93,    -1,    95,    96,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   104,    -1,    24,    25,    26,    27,    28,
      -1,    -1,   113,   114,   115,   116,    -1,    36,   119,   120,
      39,    -1,    41,    42,    43,    -1,    -1,    -1,   129,    -1,
      -1,    -1,    -1,    -1,   135,   136,    -1,   138,    -1,   140,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      69,    70,    71,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    81,    82,    -1,    -1,    -1,    -1,    -1,     6,
      -1,    -1,    -1,    92,    93,    -1,    95,    96,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   104,    -1,    24,    25,    26,
      27,    28,   111,    -1,   113,   114,   115,   116,    -1,    36,
     119,   120,    39,    -1,    41,    42,    43,    44,    -1,    -1,
     129,    -1,    -1,    -1,    -1,    -1,   135,   136,    -1,   138,
      -1,   140,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    69,    70,    71,    -1,    73,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    81,    82,    -1,    -1,    -1,    -1,
      -1,     6,    -1,    -1,    -1,    92,    93,    -1,    95,    96,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   104,    -1,    24,
      25,    26,    27,    28,    -1,    -1,   113,   114,   115,   116,
      -1,    36,   119,   120,    39,    -1,    41,    42,    43,    44,
      -1,    -1,   129,    -1,    -1,    -1,    -1,    -1,   135,   136,
      -1,   138,    -1,   140,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    69,    70,    71,    -1,    73,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    81,    82,    -1,    -1,
      -1,    -1,    -1,     6,    -1,    -1,    -1,    92,    93,    -1,
      95,    96,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   104,
      -1,    24,    25,    26,    27,    28,    -1,    -1,   113,   114,
     115,   116,    -1,    36,   119,   120,    39,    -1,    41,    42,
      43,    -1,    -1,    -1,   129,    -1,    -1,    -1,    -1,    -1,
     135,   136,    -1,   138,    -1,   140,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    69,    70,    71,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    81,    82,
      -1,    -1,    -1,    -1,    -1,     6,    89,    -1,    -1,    92,
      93,    -1,    95,    96,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   104,    -1,    24,    25,    26,    27,    28,    -1,    -1,
     113,   114,   115,   116,    -1,    36,   119,   120,    39,    -1,
      41,    42,    43,    -1,    -1,    -1,   129,    -1,    -1,    -1,
      -1,    -1,   135,   136,    -1,   138,    -1,   140,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,    70,
      71,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      81,    82,    -1,    -1,    -1,    -1,    -1,     6,    -1,    -1,
      -1,    92,    93,    -1,    95,    96,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   104,    -1,    24,    25,    26,    27,    28,
     111,    -1,   113,   114,   115,   116,    -1,    36,   119,   120,
      39,    -1,    41,    42,    43,    -1,    -1,    -1,   129,    -1,
      -1,    -1,    -1,    -1,   135,   136,    -1,   138,    -1,   140,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      69,    70,    71,    -1,    73,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    81,    82,    -1,    -1,    -1,    -1,    -1,     6,
      -1,    -1,    -1,    92,    93,    -1,    95,    96,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   104,    -1,    24,    25,    26,
      27,    28,    -1,    -1,   113,   114,   115,   116,    -1,    36,
     119,   120,    39,    -1,    41,    42,    43,    -1,    -1,    -1,
     129,    -1,    -1,    -1,    -1,    -1,   135,   136,    -1,   138,
      -1,   140,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    69,    70,    71,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    79,    -1,    81,    82,    -1,    -1,    -1,    -1,
      -1,     6,    -1,    -1,    -1,    92,    93,    -1,    95,    96,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   104,    -1,    24,
      25,    26,    27,    28,    -1,    -1,   113,   114,   115,   116,
      -1,    36,   119,   120,    39,    -1,    41,    42,    43,    -1,
      -1,    -1,   129,    -1,    -1,    -1,    -1,    -1,   135,   136,
      -1,   138,    -1,   140,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     6,    69,    70,    71,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    81,    82,    -1,    -1,
      -1,    24,    25,    -1,    -1,    28,    -1,    92,    93,    -1,
      95,    96,    -1,    36,    -1,    -1,    39,    -1,    41,   104,
      43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   113,   114,
     115,   116,    -1,    -1,   119,   120,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   129,    -1,    69,    70,    71,    -1,
     135,   136,    -1,   138,    -1,   140,    -1,    -1,    -1,    82,
      -1,    -1,    -1,    -1,    26,    27,    28,    -1,    -1,    92,
      93,    -1,    -1,    -1,    36,    -1,    -1,    39,    -1,    41,
      42,   104,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     113,   114,   115,   116,    -1,    -1,   119,   120,    -1,    -1,
      -1,    26,    -1,    28,    -1,    -1,   129,    69,    70,    -1,
      -1,    36,    -1,   136,    39,   138,    41,   140,    -1,    81,
      82,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    95,    96,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   104,    -1,    69,    70,    -1,    -1,    -1,    -1,
      -1,   113,   114,   115,   116,    -1,    81,    82,    -1,    -1,
      -1,    -1,    26,    -1,    28,    -1,    -1,   129,    -1,    -1,
      95,    96,    36,   135,   136,    39,   138,    41,   140,   104,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   113,   114,
     115,   116,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   129,    69,    70,    -1,    -1,    -1,
      -1,   136,    -1,   138,    -1,   140,    -1,    81,    82,    -1,
      -1,    -1,    -1,    -1,    27,    28,    -1,    -1,    -1,    -1,
      -1,    95,    96,    36,    -1,    -1,    39,    -1,    41,    42,
     104,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   113,
     114,   115,   116,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   129,    69,    70,    -1,    -1,
      -1,    -1,   136,    -1,   138,    -1,   140,    -1,    -1,    82,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    95,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   104,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     113,   114,   115,   116,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   129,    -1,    -1,    -1,
      -1,    -1,   135,   136,    -1,   138,    -1,   140
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,    46,    62,    79,    87,   133,   139,   152,   159,   161,
     163,   302,   303,   306,   309,   310,   317,   318,   319,    56,
      64,    32,    48,   164,    28,   181,   301,    83,    83,    64,
     320,     0,    23,   160,    86,   150,   160,    86,   150,   181,
     181,     6,     7,    24,    25,    26,    27,    36,    39,    41,
      42,    43,    69,    70,    71,    81,    82,    92,    93,    95,
      96,   104,   111,   113,   114,   115,   116,   119,   120,   129,
     135,   136,   138,   140,   165,   166,   167,   168,   169,   181,
     186,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   225,   226,   227,   229,
     230,   231,   254,   255,   256,   257,   258,   264,   265,   285,
     289,   290,   291,   292,   293,   294,   295,   297,   301,   311,
      80,   181,   181,   104,   162,   180,   181,   183,   184,    32,
     161,   163,   163,    32,   163,   163,    90,   104,    89,   191,
     207,   218,   219,   221,   104,   104,   104,   104,   104,   104,
     104,   104,   104,   191,   104,   104,   104,   104,   104,   104,
     104,    56,   171,   172,    22,    34,   170,   186,   301,   170,
       5,     6,     7,     8,   203,   205,    21,   104,     5,    16,
     228,   117,   104,   104,   186,   307,   308,    34,   163,   154,
      34,   182,   301,    34,   182,   163,   163,   104,   307,   185,
     206,    15,    44,    51,    73,   104,   162,   191,   226,   232,
     233,   234,   235,   237,   238,   239,   241,   242,   245,   246,
     248,   249,   250,   251,   253,    21,    49,   219,   220,    89,
     216,   217,     7,   164,    95,   192,   205,   192,   192,    26,
      95,   205,   231,   300,   192,   191,   296,   192,   205,   225,
     199,   105,    26,   169,   206,   199,   199,   191,   286,   191,
     105,   191,   173,   174,   180,    90,   176,   167,   186,   200,
     200,   201,   201,     7,   186,   164,   205,   229,   104,   266,
     267,   268,   269,   301,   191,   259,   191,     9,    22,    90,
     176,   161,   105,   180,   182,   182,   185,    22,   105,   235,
     184,   191,   232,   252,   253,     4,    84,     3,    65,    15,
      68,     9,    10,    11,    12,    13,    14,    15,    37,    60,
      65,   240,    73,   191,   223,   224,    50,   191,   222,   220,
     216,   105,   191,   104,   105,   105,   105,   104,    22,   105,
      22,   105,   105,    22,   105,    22,   105,    22,    22,    22,
     105,   105,    34,    22,    22,    22,    57,    61,    66,    67,
      77,   175,   232,    58,   177,   191,   118,   270,   271,    22,
     260,   105,    24,    25,    26,    27,   305,   308,   104,    74,
     105,   206,    88,   161,   105,    22,   105,   233,   223,   234,
      15,    29,    30,    31,   236,    68,   226,   247,    37,    60,
      68,   104,   251,   104,   184,   243,    15,    73,    32,    33,
     110,   251,    84,    50,   105,   199,   298,   296,    26,    26,
      26,    26,    26,   130,   131,   132,   287,   288,   191,   305,
     312,   313,   314,   315,   174,    66,    76,    66,    66,    76,
      66,    76,   180,    38,    59,   178,   105,    38,   105,    75,
     179,   274,    24,   261,   105,   185,   206,   232,    60,   104,
     253,   236,   247,    53,   251,   243,   247,   253,     3,   191,
     244,    73,   250,   250,   250,   223,    22,   105,   105,   105,
      22,    22,    22,   105,   105,    22,   105,    22,    66,    66,
      66,    74,   185,   232,   179,   191,   272,   273,    38,   122,
     123,   275,   276,    22,   262,   105,    89,   321,   162,   304,
     305,    53,    26,     3,    53,   251,    22,   105,   199,   299,
      26,    26,    26,   305,   305,   315,   316,   232,    22,   187,
     188,   189,   191,    24,    37,   126,   127,   277,   278,   279,
     280,   191,   263,    60,   153,    89,   322,    22,   105,    26,
     251,    26,   244,   105,   105,   105,   105,   273,    22,    35,
      47,   190,   124,    24,   126,   278,   281,   283,   284,   124,
     128,   162,    84,    15,    89,   324,   305,   188,   125,   125,
       3,    46,    87,   325,   153,    15,   282,   283,    80,    38,
     323,   153,   206,   327,   328,   157,    84,    38,     9,    22,
      62,   326,   101,   206,   328,   104,    84,   185,   325,   105,
      88,   104,   185,   105
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* This macro is provided for backward compatibility. */

#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
	    /* Fall through.  */
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

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (0, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  YYSIZE_T yysize1;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = 0;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
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
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
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
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                yysize1 = yysize + yytnamerr (0, yytname[yyx]);
                if (! (yysize <= yysize1
                       && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                  return 2;
                yysize = yysize1;
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  yysize1 = yysize + yystrlen (yyformat);
  if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
    return 2;
  yysize = yysize1;

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
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
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */
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


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1806 of yacc.c  */
#line 89 "aq/parser/SQL92_Grm.y"
    {
												*(aq::tnode**)ppNode = (yyval);
												YYACCEPT;
											}
    break;

  case 3:

/* Line 1806 of yacc.c  */
#line 93 "aq/parser/SQL92_Grm.y"
    {
												*(aq::tnode**)ppNode = (yyval);
												YYACCEPT;
											}
    break;

  case 4:

/* Line 1806 of yacc.c  */
#line 97 "aq/parser/SQL92_Grm.y"
    {
												*(aq::tnode**)ppNode = (yyval);
												YYACCEPT;
											}
    break;

  case 5:

/* Line 1806 of yacc.c  */
#line 101 "aq/parser/SQL92_Grm.y"
    {
												*(aq::tnode**)ppNode = (yyval);
												YYACCEPT;
											}
    break;

  case 6:

/* Line 1806 of yacc.c  */
#line 105 "aq/parser/SQL92_Grm.y"
    {
												*(aq::tnode**)ppNode = (yyval);
												YYACCEPT;
											}
    break;

  case 7:

/* Line 1806 of yacc.c  */
#line 109 "aq/parser/SQL92_Grm.y"
    {
												*(aq::tnode**)ppNode = (yyval);
												YYACCEPT;
											}
    break;

  case 8:

/* Line 1806 of yacc.c  */
#line 113 "aq/parser/SQL92_Grm.y"
    {
												*(aq::tnode**)ppNode = (yyval);
												YYACCEPT;
											}
    break;

  case 9:

/* Line 1806 of yacc.c  */
#line 117 "aq/parser/SQL92_Grm.y"
    {
												*(aq::tnode**)ppNode = (yyval);
												YYACCEPT;
											}
    break;

  case 11:

/* Line 1806 of yacc.c  */
#line 132 "aq/parser/SQL92_Grm.y"
    {	aq::tnode *pNode;
												(yyval) = (yyvsp[(1) - (4)]);
												if ( (yyvsp[(2) - (4)]) != nullptr ) {
													pNode = (yyvsp[(2) - (4)]);
													(yyvsp[(1) - (4)])->left = pNode;
												} else {
													pNode = (yyvsp[(1) - (4)]);
												}
												pNode->left = (yyvsp[(3) - (4)]);
												(yyvsp[(1) - (4)])->next = (yyvsp[(4) - (4)]);
											}
    break;

  case 12:

/* Line 1806 of yacc.c  */
#line 145 "aq/parser/SQL92_Grm.y"
    { (yyval) = (yyvsp[(2) - (3)]); }
    break;

  case 16:

/* Line 1806 of yacc.c  */
#line 154 "aq/parser/SQL92_Grm.y"
    { (yyval) = nullptr; }
    break;

  case 17:

/* Line 1806 of yacc.c  */
#line 157 "aq/parser/SQL92_Grm.y"
    { (yyval) = (yyvsp[(1) - (1)]); (yyval)->setTag(K_STAR); }
    break;

  case 20:

/* Line 1806 of yacc.c  */
#line 162 "aq/parser/SQL92_Grm.y"
    {
														(yyvsp[(2) - (3)])->left		= (yyvsp[(1) - (3)]);
														(yyvsp[(2) - (3)])->right	= (yyvsp[(3) - (3)]);
														(yyval)			= (yyvsp[(2) - (3)]);
														// $1->list.push_back($3);
														// $$ = $1;
													}
    break;

  case 22:

/* Line 1806 of yacc.c  */
#line 172 "aq/parser/SQL92_Grm.y"
    {
														(yyvsp[(2) - (3)])->left		= (yyvsp[(1) - (3)]);
														(yyvsp[(2) - (3)])->right	= (yyvsp[(3) - (3)]);
														(yyval)			= (yyvsp[(2) - (3)]);
													}
    break;

  case 24:

/* Line 1806 of yacc.c  */
#line 180 "aq/parser/SQL92_Grm.y"
    {
														/* $2.tag == K_AS */
														if ( (yyvsp[(2) - (2)])->left != nullptr ) {
															(yyvsp[(2) - (2)])->right = (yyvsp[(2) - (2)])->left;
														}
														(yyvsp[(2) - (2)])->left = (yyvsp[(1) - (2)]);
														(yyval) = (yyvsp[(2) - (2)]);
													}
    break;

  case 26:

/* Line 1806 of yacc.c  */
#line 189 "aq/parser/SQL92_Grm.y"
    {
														/* $2.tag == K_AS */
														if ( (yyvsp[(2) - (2)])->left != nullptr ) {
															(yyvsp[(2) - (2)])->right = (yyvsp[(2) - (2)])->left;
														}
														(yyvsp[(2) - (2)])->left = (yyvsp[(1) - (2)]);
														(yyval) = (yyvsp[(2) - (2)]);
													}
    break;

  case 27:

/* Line 1806 of yacc.c  */
#line 199 "aq/parser/SQL92_Grm.y"
    { 
														(yyvsp[(1) - (8)])->left = (yyvsp[(3) - (8)]);
														(yyvsp[(1) - (8)])->right = (yyvsp[(6) - (8)]);
														(yyvsp[(6) - (8)])->left = (yyvsp[(5) - (8)]);
														(yyvsp[(6) - (8)])->right = (yyvsp[(7) - (8)]);
														(yyval) = (yyvsp[(1) - (8)]);
													}
    break;

  case 28:

/* Line 1806 of yacc.c  */
#line 206 "aq/parser/SQL92_Grm.y"
    { 
														(yyvsp[(1) - (8)])->left = (yyvsp[(3) - (8)]);
														(yyvsp[(1) - (8)])->right = (yyvsp[(6) - (8)]);
														(yyvsp[(6) - (8)])->left = (yyvsp[(5) - (8)]);
														(yyvsp[(6) - (8)])->right = (yyvsp[(7) - (8)]);
														(yyval) = (yyvsp[(1) - (8)]);
													}
    break;

  case 29:

/* Line 1806 of yacc.c  */
#line 213 "aq/parser/SQL92_Grm.y"
    { 
														(yyvsp[(1) - (8)])->left = (yyvsp[(3) - (8)]);
														(yyvsp[(1) - (8)])->right = (yyvsp[(6) - (8)]);
														(yyvsp[(6) - (8)])->left = (yyvsp[(5) - (8)]);
														(yyvsp[(6) - (8)])->right = (yyvsp[(7) - (8)]);
														(yyval) = (yyvsp[(1) - (8)]);
													}
    break;

  case 30:

/* Line 1806 of yacc.c  */
#line 222 "aq/parser/SQL92_Grm.y"
    {
														aq::tnode *pNode = new tnode( K_AS );
														(yyval) = pNode;

														/* Generate Qualified Column Reference */
														#ifdef USE_TSELRESULT_FOR_GENERATED_TABLE
														/* Use for the generated table : TSelResult */
														pNode = new tnode( K_PERIOD );
														(yyval)->left	 = pNode;
														pNode->left  = new tnode( K_IDENT );
														pNode->left->set_string_data( "TSelResult" );
														pNode->right = (yyvsp[(1) - (1)]);
														#else
														(yyval)->right = (yyvsp[(1) - (1)]);
														#endif
													}
    break;

  case 31:

/* Line 1806 of yacc.c  */
#line 238 "aq/parser/SQL92_Grm.y"
    {
														#ifdef USE_TSELRESULT_FOR_GENERATED_TABLE
														aq::tnode *pNode;
														#endif

														(yyval) = (yyvsp[(1) - (2)]);
														/* $1->left = $2; */
														/* Generate Qualified Column Reference */
														#ifdef USE_TSELRESULT_FOR_GENERATED_TABLE
														/* Use for the generated table : TSelResult */
														pNode = new tnode( K_PERIOD );
														(yyval)->left	 = pNode;
														pNode->left  = new tnode( K_IDENT );
														pNode->left->set_string_data( "TSelResult" );
														pNode->right = (yyvsp[(2) - (2)]);
														#else
														(yyvsp[(1) - (2)])->right = (yyvsp[(2) - (2)]);
														#endif

													}
    break;

  case 32:

/* Line 1806 of yacc.c  */
#line 265 "aq/parser/SQL92_Grm.y"
    {
														aq::tnode *pNode;
														(yyval)		= (yyvsp[(1) - (5)]);
														pNode	= (yyvsp[(1) - (5)]);
														if ( (yyvsp[(2) - (5)]) != nullptr ) {
															pNode->next = (yyvsp[(2) - (5)]);
															pNode		= (yyvsp[(2) - (5)]);
														}
														if ( (yyvsp[(3) - (5)]) != nullptr ) {
															pNode->next = (yyvsp[(3) - (5)]);
															pNode		= (yyvsp[(3) - (5)]);
														}
														if ( (yyvsp[(4) - (5)]) != nullptr ) {
															pNode->next = (yyvsp[(4) - (5)]);
															pNode		= (yyvsp[(4) - (5)]);
														}
														if ( (yyvsp[(5) - (5)]) != nullptr ) {
															pNode->next = (yyvsp[(5) - (5)]);
															pNode		= (yyvsp[(5) - (5)]);
														}
													}
    break;

  case 33:

/* Line 1806 of yacc.c  */
#line 288 "aq/parser/SQL92_Grm.y"
    {
														(yyvsp[(1) - (2)])->left = (yyvsp[(2) - (2)]);
														(yyval) = (yyvsp[(1) - (2)]);
													}
    break;

  case 35:

/* Line 1806 of yacc.c  */
#line 295 "aq/parser/SQL92_Grm.y"
    {	/* K_COMMA table_reference */
														(yyvsp[(2) - (3)])->left	= (yyvsp[(1) - (3)]);
														(yyvsp[(2) - (3)])->right	= (yyvsp[(3) - (3)]);
														(yyval)			= (yyvsp[(2) - (3)]);
													}
    break;

  case 37:

/* Line 1806 of yacc.c  */
#line 303 "aq/parser/SQL92_Grm.y"
    {
														aq::tnode *pNode;
														pNode = aq::tnode::get_leftmost_child( (yyvsp[(2) - (3)]) );
														pNode->left	= (yyvsp[(1) - (3)]);
														pNode->right= (yyvsp[(3) - (3)]);
														(yyval)			= (yyvsp[(2) - (3)]);
													}
    break;

  case 38:

/* Line 1806 of yacc.c  */
#line 310 "aq/parser/SQL92_Grm.y"
    {
														aq::tnode *pNode;
														pNode = aq::tnode::get_leftmost_child( (yyvsp[(2) - (5)]) );
														pNode->left	= (yyvsp[(1) - (5)]);
														pNode->right= (yyvsp[(3) - (5)]);
														pNode->next	= (yyvsp[(4) - (5)]);
														(yyvsp[(4) - (5)])->left	= (yyvsp[(5) - (5)]);
														(yyval)			= (yyvsp[(2) - (5)]);
													}
    break;

  case 39:

/* Line 1806 of yacc.c  */
#line 322 "aq/parser/SQL92_Grm.y"
    {	
														(yyvsp[(1) - (2)])->left	= (yyvsp[(2) - (2)]); 
														(yyval)			= (yyvsp[(1) - (2)]);
													}
    break;

  case 40:

/* Line 1806 of yacc.c  */
#line 326 "aq/parser/SQL92_Grm.y"
    {	
														(yyvsp[(1) - (2)])->left	= (yyvsp[(2) - (2)]); 
														(yyval)			= (yyvsp[(1) - (2)]);
													}
    break;

  case 41:

/* Line 1806 of yacc.c  */
#line 330 "aq/parser/SQL92_Grm.y"
    {	
														(yyvsp[(1) - (3)])->left	= (yyvsp[(2) - (3)]); 
														(yyvsp[(2) - (3)])->left	= (yyvsp[(3) - (3)]); 
														(yyval)			= (yyvsp[(1) - (3)]);
													}
    break;

  case 42:

/* Line 1806 of yacc.c  */
#line 335 "aq/parser/SQL92_Grm.y"
    {	
														(yyvsp[(1) - (2)])->left	= (yyvsp[(2) - (2)]); 
														(yyval)			= (yyvsp[(1) - (2)]);
													}
    break;

  case 43:

/* Line 1806 of yacc.c  */
#line 339 "aq/parser/SQL92_Grm.y"
    {	
														(yyvsp[(1) - (3)])->left	= (yyvsp[(2) - (3)]); 
														(yyvsp[(2) - (3)])->left	= (yyvsp[(3) - (3)]); 
														(yyval)			= (yyvsp[(1) - (3)]);
													}
    break;

  case 44:

/* Line 1806 of yacc.c  */
#line 344 "aq/parser/SQL92_Grm.y"
    {	
														(yyvsp[(1) - (2)])->left	= (yyvsp[(2) - (2)]); 
														(yyval)			= (yyvsp[(1) - (2)]);
													}
    break;

  case 45:

/* Line 1806 of yacc.c  */
#line 348 "aq/parser/SQL92_Grm.y"
    {	
														(yyvsp[(1) - (3)])->left	= (yyvsp[(2) - (3)]); 
														(yyvsp[(2) - (3)])->left	= (yyvsp[(3) - (3)]); 
														(yyval)			= (yyvsp[(1) - (3)]);
													}
    break;

  case 47:

/* Line 1806 of yacc.c  */
#line 356 "aq/parser/SQL92_Grm.y"
    {
														(yyvsp[(1) - (2)])->left	= (yyvsp[(2) - (2)]);
														(yyval)			= (yyvsp[(1) - (2)]);
													}
    break;

  case 48:

/* Line 1806 of yacc.c  */
#line 360 "aq/parser/SQL92_Grm.y"
    {	(yyval) = nullptr; }
    break;

  case 49:

/* Line 1806 of yacc.c  */
#line 363 "aq/parser/SQL92_Grm.y"
    {
														(yyvsp[(1) - (3)])->left = (yyvsp[(3) - (3)]);
														(yyval) = (yyvsp[(1) - (3)]);
													}
    break;

  case 50:

/* Line 1806 of yacc.c  */
#line 367 "aq/parser/SQL92_Grm.y"
    {	(yyval) = nullptr; }
    break;

  case 51:

/* Line 1806 of yacc.c  */
#line 370 "aq/parser/SQL92_Grm.y"
    {
														(yyvsp[(1) - (2)])->left = (yyvsp[(2) - (2)]);
														(yyval) = (yyvsp[(1) - (2)]);
													}
    break;

  case 52:

/* Line 1806 of yacc.c  */
#line 374 "aq/parser/SQL92_Grm.y"
    {	(yyval) = nullptr; }
    break;

  case 53:

/* Line 1806 of yacc.c  */
#line 377 "aq/parser/SQL92_Grm.y"
    {
														(yyvsp[(1) - (3)])->left = (yyvsp[(3) - (3)]);
														(yyval) = (yyvsp[(1) - (3)]);
													}
    break;

  case 54:

/* Line 1806 of yacc.c  */
#line 381 "aq/parser/SQL92_Grm.y"
    {	(yyval) = nullptr; }
    break;

  case 56:

/* Line 1806 of yacc.c  */
#line 386 "aq/parser/SQL92_Grm.y"
    {
														aq::tnode *pNode;
														/* Generate K_AS */
														pNode = new tnode( K_AS );
														pNode->left	 = (yyvsp[(1) - (2)]);
														pNode->right = (yyvsp[(2) - (2)]);
														(yyval) = pNode;
													}
    break;

  case 57:

/* Line 1806 of yacc.c  */
#line 394 "aq/parser/SQL92_Grm.y"
    {
														(yyvsp[(2) - (3)])->left = (yyvsp[(1) - (3)]);
														(yyvsp[(2) - (3)])->right = (yyvsp[(3) - (3)]);
														(yyval) = (yyvsp[(2) - (3)]);
													}
    break;

  case 59:

/* Line 1806 of yacc.c  */
#line 400 "aq/parser/SQL92_Grm.y"
    {
														aq::tnode *pNode;
														/* Generate K_AS */
														pNode = new tnode( K_AS );
														pNode->left	 = (yyvsp[(1) - (2)]);
														pNode->right = (yyvsp[(2) - (2)]);
														(yyval) = pNode;
													}
    break;

  case 60:

/* Line 1806 of yacc.c  */
#line 408 "aq/parser/SQL92_Grm.y"
    {
														(yyvsp[(2) - (3)])->left = (yyvsp[(1) - (3)]);
														(yyvsp[(2) - (3)])->right = (yyvsp[(3) - (3)]);
														(yyval) = (yyvsp[(2) - (3)]);
													}
    break;

  case 66:

/* Line 1806 of yacc.c  */
#line 428 "aq/parser/SQL92_Grm.y"
    {
														(yyvsp[(2) - (3)])->left	= (yyvsp[(1) - (3)]);
														(yyvsp[(2) - (3)])->right	= (yyvsp[(3) - (3)]);
														(yyval)			= (yyvsp[(2) - (3)]);
													}
    break;

  case 69:

/* Line 1806 of yacc.c  */
#line 439 "aq/parser/SQL92_Grm.y"
    {
														(yyvsp[(2) - (3)])->left	= (yyvsp[(1) - (3)]);
														(yyvsp[(2) - (3)])->right	= (yyvsp[(3) - (3)]);
														(yyval)			= (yyvsp[(2) - (3)]);
													}
    break;

  case 70:

/* Line 1806 of yacc.c  */
#line 446 "aq/parser/SQL92_Grm.y"
    {
														if ( (yyvsp[(2) - (2)]) != nullptr ) {
															(yyvsp[(2) - (2)])->left = (yyvsp[(1) - (2)]);
															(yyval) = (yyvsp[(2) - (2)]);
														} else {
															(yyval) = (yyvsp[(1) - (2)]);
														}
													}
    break;

  case 71:

/* Line 1806 of yacc.c  */
#line 456 "aq/parser/SQL92_Grm.y"
    {
														#ifdef USE_TSELRESULT_FOR_GENERATED_TABLE
														aq::tnode *pNode;
														#endif

														/* Generate Qualified Column Reference */
														#ifdef USE_TSELRESULT_FOR_GENERATED_TABLE
														/* Use for the generated table : TSelResult */
														pNode		 = new tnode( K_PERIOD );
														(yyval)			 = pNode;
														pNode->left  = new_node( K_IDENT );
														pNode->left->set_string_data( "TSelResult" );
														pNode->right = (yyvsp[(1) - (1)]);
														#else
														(yyval) = (yyvsp[(1) - (1)]);
														#endif
													}
    break;

  case 74:

/* Line 1806 of yacc.c  */
#line 477 "aq/parser/SQL92_Grm.y"
    { (yyval) = nullptr; }
    break;

  case 84:

/* Line 1806 of yacc.c  */
#line 500 "aq/parser/SQL92_Grm.y"
    {
														(yyval) = (yyvsp[(1) - (4)]);
														(yyvsp[(1) - (4)])->left = (yyvsp[(3) - (4)]);
													}
    break;

  case 87:

/* Line 1806 of yacc.c  */
#line 509 "aq/parser/SQL92_Grm.y"
    {
														(yyvsp[(1) - (6)])->left	= (yyvsp[(3) - (6)]);
														(yyvsp[(1) - (6)])->right	= (yyvsp[(5) - (6)]);
														(yyval)			= (yyvsp[(1) - (6)]);
													}
    break;

  case 88:

/* Line 1806 of yacc.c  */
#line 514 "aq/parser/SQL92_Grm.y"
    {
														(yyvsp[(1) - (4)])->left	= (yyvsp[(3) - (4)]);
														(yyval)			= (yyvsp[(1) - (4)]);
													}
    break;

  case 89:

/* Line 1806 of yacc.c  */
#line 520 "aq/parser/SQL92_Grm.y"
    {
														(yyvsp[(1) - (4)])->left	= (yyvsp[(3) - (4)]);
														(yyval)			= (yyvsp[(1) - (4)]);
													}
    break;

  case 90:

/* Line 1806 of yacc.c  */
#line 525 "aq/parser/SQL92_Grm.y"
    {
														(yyvsp[(1) - (6)])->left	= (yyvsp[(3) - (6)]);
														(yyvsp[(1) - (6)])->right	= (yyvsp[(5) - (6)]);
														(yyval)			= (yyvsp[(1) - (6)]);
													}
    break;

  case 91:

/* Line 1806 of yacc.c  */
#line 530 "aq/parser/SQL92_Grm.y"
    {
														(yyvsp[(1) - (4)])->left	= (yyvsp[(3) - (4)]);
														(yyval)			= (yyvsp[(1) - (4)]);
													}
    break;

  case 93:

/* Line 1806 of yacc.c  */
#line 538 "aq/parser/SQL92_Grm.y"
    {
														(yyvsp[(2) - (3)])->left	= (yyvsp[(1) - (3)]);
														(yyvsp[(2) - (3)])->right	= (yyvsp[(3) - (3)]);
														(yyval)			= (yyvsp[(2) - (3)]);
													}
    break;

  case 94:

/* Line 1806 of yacc.c  */
#line 543 "aq/parser/SQL92_Grm.y"
    {
														(yyvsp[(2) - (3)])->left	= (yyvsp[(1) - (3)]);
														(yyvsp[(2) - (3)])->right	= (yyvsp[(3) - (3)]);
														(yyval)			= (yyvsp[(2) - (3)]);
													}
    break;

  case 96:

/* Line 1806 of yacc.c  */
#line 551 "aq/parser/SQL92_Grm.y"
    {
														(yyvsp[(2) - (3)])->left	= (yyvsp[(1) - (3)]);
														(yyvsp[(2) - (3)])->right	= (yyvsp[(3) - (3)]);
														(yyval)			= (yyvsp[(2) - (3)]);
													}
    break;

  case 97:

/* Line 1806 of yacc.c  */
#line 556 "aq/parser/SQL92_Grm.y"
    {
														(yyvsp[(2) - (3)])->left	= (yyvsp[(1) - (3)]);
														(yyvsp[(2) - (3)])->right	= (yyvsp[(3) - (3)]);
														(yyval)			= (yyvsp[(2) - (3)]);
													}
    break;

  case 99:

/* Line 1806 of yacc.c  */
#line 564 "aq/parser/SQL92_Grm.y"
    {	
														(yyvsp[(1) - (2)])->setTag(K_UMINUS);
														(yyvsp[(1) - (2)])->left	= (yyvsp[(2) - (2)]);
														(yyval)			= (yyvsp[(1) - (2)]);
													}
    break;

  case 114:

/* Line 1806 of yacc.c  */
#line 597 "aq/parser/SQL92_Grm.y"
    {
														(yyval) = (yyvsp[(2) - (3)]);
													}
    break;

  case 119:

/* Line 1806 of yacc.c  */
#line 606 "aq/parser/SQL92_Grm.y"
    {
														(yyvsp[(2) - (3)])->left	= (yyvsp[(1) - (3)]);
														(yyvsp[(2) - (3)])->right	= (yyvsp[(3) - (3)]);
														(yyvsp[(3) - (3)])->setTag(K_COLUMN);
														(yyval)			= (yyvsp[(2) - (3)]);
													}
    break;

  case 120:

/* Line 1806 of yacc.c  */
#line 612 "aq/parser/SQL92_Grm.y"
    {
														(yyvsp[(1) - (1)])->setTag(K_COLUMN);
														(yyval)			= (yyvsp[(1) - (1)]);
													}
    break;

  case 124:

/* Line 1806 of yacc.c  */
#line 627 "aq/parser/SQL92_Grm.y"
    {
														(yyvsp[(1) - (4)])->left	= (yyvsp[(3) - (4)]);
														(yyvsp[(3) - (4)])->setTag(K_STAR);
														(yyval)			= (yyvsp[(1) - (4)]);
													}
    break;

  case 125:

/* Line 1806 of yacc.c  */
#line 632 "aq/parser/SQL92_Grm.y"
    {
														if ( (yyvsp[(3) - (5)]) != nullptr ) {
															(yyvsp[(1) - (5)])->left	= (yyvsp[(3) - (5)]);
															(yyvsp[(1) - (5)])->right	= (yyvsp[(4) - (5)]);
														} else {
															(yyvsp[(1) - (5)])->left	= (yyvsp[(4) - (5)]);
														}
														(yyval) = (yyvsp[(1) - (5)]);
													}
    break;

  case 126:

/* Line 1806 of yacc.c  */
#line 647 "aq/parser/SQL92_Grm.y"
    {
														if ( (yyvsp[(3) - (5)]) != nullptr ) {
															(yyvsp[(1) - (5)])->left	= (yyvsp[(3) - (5)]);
															(yyvsp[(1) - (5)])->right	= (yyvsp[(4) - (5)]);
														} else {
															(yyvsp[(1) - (5)])->left	= (yyvsp[(4) - (5)]);
														}
														(yyval) = (yyvsp[(1) - (5)]);
													}
    break;

  case 134:

/* Line 1806 of yacc.c  */
#line 687 "aq/parser/SQL92_Grm.y"
    {
														(yyvsp[(1) - (5)])->left		= (yyvsp[(2) - (5)]);
														(yyvsp[(1) - (5)])->right	= (yyvsp[(3) - (5)]);
														if ( (yyvsp[(4) - (5)]) != nullptr ) {
															aq::tnode *pNode;
															pNode = (yyvsp[(3) - (5)]);
															while ( pNode->next != nullptr )
																pNode = pNode->next;
															pNode->next = (yyvsp[(4) - (5)]);
														}
														delete (yyvsp[(5) - (5)]);
														(yyval)			= (yyvsp[(1) - (5)]);
													}
    break;

  case 135:

/* Line 1806 of yacc.c  */
#line 712 "aq/parser/SQL92_Grm.y"
    {
														(yyvsp[(1) - (4)])->left	= (yyvsp[(2) - (4)]);
														/* $1->right	= $3; */
														if ( (yyvsp[(3) - (4)]) != nullptr ) {
															aq::tnode *pNode;
															pNode = (yyvsp[(2) - (4)]);
															while ( pNode->next != nullptr )
																pNode = pNode->next;
															pNode->next = (yyvsp[(3) - (4)]);
														}
														delete (yyvsp[(4) - (4)]);
														(yyval)			= (yyvsp[(1) - (4)]);
													}
    break;

  case 137:

/* Line 1806 of yacc.c  */
#line 728 "aq/parser/SQL92_Grm.y"
    {
														(yyvsp[(1) - (2)])->next	= (yyvsp[(2) - (2)]);
														(yyval)			= (yyvsp[(1) - (2)]);
													}
    break;

  case 138:

/* Line 1806 of yacc.c  */
#line 734 "aq/parser/SQL92_Grm.y"
    {
														(yyvsp[(1) - (4)])->left	= (yyvsp[(2) - (4)]);
														(yyvsp[(1) - (4)])->right	= (yyvsp[(4) - (4)]);
														delete (yyvsp[(3) - (4)]);
														(yyval)			= (yyvsp[(1) - (4)]);
													}
    break;

  case 140:

/* Line 1806 of yacc.c  */
#line 743 "aq/parser/SQL92_Grm.y"
    {
														(yyvsp[(1) - (2)])->next	= (yyvsp[(2) - (2)]);
														(yyval)			= (yyvsp[(1) - (2)]);
													}
    break;

  case 141:

/* Line 1806 of yacc.c  */
#line 749 "aq/parser/SQL92_Grm.y"
    {
														(yyvsp[(1) - (4)])->left	= (yyvsp[(2) - (4)]);
														(yyvsp[(1) - (4)])->right	= (yyvsp[(3) - (4)]);
														(yyvsp[(3) - (4)])->left	= (yyvsp[(4) - (4)]);
														(yyval)			= (yyvsp[(1) - (4)]);
													}
    break;

  case 142:

/* Line 1806 of yacc.c  */
#line 757 "aq/parser/SQL92_Grm.y"
    {
														(yyvsp[(1) - (2)])->left	= (yyvsp[(2) - (2)]);
														(yyval)			= (yyvsp[(1) - (2)]);
													}
    break;

  case 143:

/* Line 1806 of yacc.c  */
#line 761 "aq/parser/SQL92_Grm.y"
    {	(yyval) = nullptr; }
    break;

  case 152:

/* Line 1806 of yacc.c  */
#line 788 "aq/parser/SQL92_Grm.y"
    {
														(yyvsp[(2) - (3)])->left	= (yyvsp[(1) - (3)]);
														(yyvsp[(2) - (3)])->right	= (yyvsp[(3) - (3)]);
														(yyval)			= (yyvsp[(2) - (3)]);
													}
    break;

  case 162:

/* Line 1806 of yacc.c  */
#line 812 "aq/parser/SQL92_Grm.y"
    {
														(yyvsp[(2) - (3)])->left	= (yyvsp[(1) - (3)]);
														(yyvsp[(2) - (3)])->right	= (yyvsp[(3) - (3)]);
														(yyval)			= (yyvsp[(2) - (3)]);
													}
    break;

  case 164:

/* Line 1806 of yacc.c  */
#line 820 "aq/parser/SQL92_Grm.y"
    {
														(yyvsp[(2) - (3)])->left	= (yyvsp[(1) - (3)]);
														(yyvsp[(2) - (3)])->right	= (yyvsp[(3) - (3)]);
														(yyval)			= (yyvsp[(2) - (3)]);
													}
    break;

  case 165:

/* Line 1806 of yacc.c  */
#line 827 "aq/parser/SQL92_Grm.y"
    {
														(yyvsp[(1) - (2)])->left	= (yyvsp[(2) - (2)]);
														(yyval)			= (yyvsp[(1) - (2)]);
													}
    break;

  case 167:

/* Line 1806 of yacc.c  */
#line 834 "aq/parser/SQL92_Grm.y"
    {
														(yyvsp[(2) - (4)])->left	= (yyvsp[(1) - (4)]);
														(yyvsp[(2) - (4)])->right	= (yyvsp[(3) - (4)]);
														(yyvsp[(3) - (4)])->left	= (yyvsp[(4) - (4)]);
														(yyval)			= (yyvsp[(2) - (4)]);
													}
    break;

  case 168:

/* Line 1806 of yacc.c  */
#line 840 "aq/parser/SQL92_Grm.y"
    {
														(yyvsp[(2) - (3)])->left	= (yyvsp[(1) - (3)]);
														(yyvsp[(2) - (3)])->right	= (yyvsp[(3) - (3)]);
														(yyval)			= (yyvsp[(2) - (3)]);
													}
    break;

  case 174:

/* Line 1806 of yacc.c  */
#line 854 "aq/parser/SQL92_Grm.y"
    { (yyval) = (yyvsp[(2) - (3)]); }
    break;

  case 181:

/* Line 1806 of yacc.c  */
#line 874 "aq/parser/SQL92_Grm.y"
    {
// K_PERIOD
														//#if 0 
														/* Enforce K_JEQ instead of K_EQ ! */
														/* Moved to convert_syntax_tree_to_prefix_form() */
														
														if ( (yyvsp[(1) - (3)])->getTag() == K_IDENT || 
															 (yyvsp[(1) - (3)])->getTag() == K_COLUMN || 
															( (yyvsp[(1) - (3)])->getTag() == K_PERIOD && 
															  (yyvsp[(1) - (3)])->left != nullptr &&
															  (yyvsp[(1) - (3)])->left->getTag() == K_IDENT &&
															  (yyvsp[(1) - (3)])->right != nullptr &&
															  ( (yyvsp[(1) - (3)])->right->getTag() == K_IDENT || 
															    (yyvsp[(1) - (3)])->right->getTag() == K_COLUMN ) ) )
															if ( (yyvsp[(3) - (3)])->getTag() == K_IDENT || 
																 (yyvsp[(3) - (3)])->getTag() == K_COLUMN || 
																( (yyvsp[(3) - (3)])->getTag() == K_PERIOD && 
																  (yyvsp[(3) - (3)])->left != nullptr &&
																  (yyvsp[(3) - (3)])->left->getTag() == K_IDENT &&
																  (yyvsp[(3) - (3)])->right != nullptr &&
																  ( (yyvsp[(3) - (3)])->right->getTag() == K_IDENT ||
																    (yyvsp[(3) - (3)])->right->getTag() == K_COLUMN ) ) )
																    switch( (yyvsp[(2) - (3)])->getTag() )
																    {
																    case K_EQ: (yyvsp[(2) - (3)])->setTag(K_JEQ); break;
																    case K_LT: (yyvsp[(2) - (3)])->setTag(K_JINF); break;
																    case K_LEQ: (yyvsp[(2) - (3)])->setTag(K_JIEQ); break;
																    case K_GT: (yyvsp[(2) - (3)])->setTag(K_JSUP) ; break;
																    case K_GEQ: (yyvsp[(2) - (3)])->setTag(K_JSEQ); break;
																    case K_NEQ: (yyvsp[(2) - (3)])->setTag(K_JNEQ); break;
																    default:;
																    };
														
														//#endif
														(yyvsp[(2) - (3)])->left	= (yyvsp[(1) - (3)]);
														(yyvsp[(2) - (3)])->right	= (yyvsp[(3) - (3)]);
														(yyval)			= (yyvsp[(2) - (3)]);
													}
    break;

  case 182:

/* Line 1806 of yacc.c  */
#line 912 "aq/parser/SQL92_Grm.y"
    {
														(yyvsp[(2) - (4)])->left	= (yyvsp[(1) - (4)]);
														(yyvsp[(2) - (4)])->right	= (yyvsp[(3) - (4)]);
														(yyvsp[(3) - (4)])->left	= (yyvsp[(4) - (4)]);
														(yyval) = (yyvsp[(2) - (4)]);
													}
    break;

  case 183:

/* Line 1806 of yacc.c  */
#line 918 "aq/parser/SQL92_Grm.y"
    {
														(yyvsp[(2) - (4)])->left	= (yyvsp[(1) - (4)]);
														(yyvsp[(2) - (4)])->right	= (yyvsp[(3) - (4)]);
														(yyvsp[(3) - (4)])->left	= (yyvsp[(4) - (4)]);
														(yyval) = (yyvsp[(2) - (4)]);
													}
    break;

  case 184:

/* Line 1806 of yacc.c  */
#line 924 "aq/parser/SQL92_Grm.y"
    {
														(yyvsp[(2) - (4)])->left	= (yyvsp[(1) - (4)]);
														(yyvsp[(2) - (4)])->right	= (yyvsp[(3) - (4)]);
														(yyvsp[(3) - (4)])->left	= (yyvsp[(4) - (4)]);
														(yyval) = (yyvsp[(2) - (4)]);
													}
    break;

  case 191:

/* Line 1806 of yacc.c  */
#line 942 "aq/parser/SQL92_Grm.y"
    {
														(yyvsp[(3) - (6)])->left	 = (yyvsp[(1) - (6)]);
														(yyvsp[(3) - (6)])->tag = K_NOT_BETWEEN;
														(yyvsp[(3) - (6)])->right = (yyvsp[(5) - (6)]);
														(yyvsp[(5) - (6)])->left	= (yyvsp[(4) - (6)]);
														(yyvsp[(5) - (6)])->right = (yyvsp[(6) - (6)]);
														(yyval) = (yyvsp[(3) - (6)]);
													}
    break;

  case 192:

/* Line 1806 of yacc.c  */
#line 951 "aq/parser/SQL92_Grm.y"
    {
														(yyvsp[(2) - (5)])->left	= (yyvsp[(1) - (5)]);
														(yyvsp[(2) - (5)])->right	= (yyvsp[(4) - (5)]);
														(yyvsp[(4) - (5)])->left	= (yyvsp[(3) - (5)]);
														(yyvsp[(4) - (5)])->right	= (yyvsp[(5) - (5)]);
														(yyval)			= (yyvsp[(2) - (5)]);
													}
    break;

  case 193:

/* Line 1806 of yacc.c  */
#line 961 "aq/parser/SQL92_Grm.y"
    {
														(yyvsp[(2) - (4)])->left	= (yyvsp[(3) - (4)]);
														(yyvsp[(3) - (4)])->left	= (yyvsp[(1) - (4)]);
														(yyvsp[(3) - (4)])->right	= (yyvsp[(4) - (4)]);
														(yyval)			= (yyvsp[(2) - (4)]);
													}
    break;

  case 194:

/* Line 1806 of yacc.c  */
#line 967 "aq/parser/SQL92_Grm.y"
    {
														(yyvsp[(2) - (3)])->left	= (yyvsp[(1) - (3)]);
														(yyvsp[(2) - (3)])->right	= (yyvsp[(3) - (3)]);
														(yyval)			= (yyvsp[(2) - (3)]);
													}
    break;

  case 195:

/* Line 1806 of yacc.c  */
#line 974 "aq/parser/SQL92_Grm.y"
    { (yyval) = (yyvsp[(2) - (3)]); }
    break;

  case 198:

/* Line 1806 of yacc.c  */
#line 979 "aq/parser/SQL92_Grm.y"
    {
														(yyvsp[(2) - (3)])->left	= (yyvsp[(1) - (3)]);
														(yyvsp[(2) - (3)])->right	= (yyvsp[(3) - (3)]);
														(yyval)			= (yyvsp[(2) - (3)]);
													}
    break;

  case 199:

/* Line 1806 of yacc.c  */
#line 988 "aq/parser/SQL92_Grm.y"
    {
														(yyvsp[(3) - (4)])->left	 = (yyvsp[(1) - (4)]);
														(yyvsp[(3) - (4)])->tag = K_NOT_LIKE;
														(yyvsp[(3) - (4)])->right = (yyvsp[(4) - (4)]);
														(yyval) = (yyvsp[(3) - (4)]);
													}
    break;

  case 200:

/* Line 1806 of yacc.c  */
#line 994 "aq/parser/SQL92_Grm.y"
    {
														(yyvsp[(3) - (6)])->left	= (yyvsp[(1) - (6)]);
														(yyvsp[(3) - (6)])->tag = K_NOT_LIKE;
														(yyvsp[(3) - (6)])->right = (yyvsp[(5) - (6)]);
														(yyvsp[(5) - (6)])->left	 = (yyvsp[(4) - (6)]);
														(yyvsp[(5) - (6)])->right = (yyvsp[(6) - (6)]);
														(yyval) = (yyvsp[(3) - (6)]);
													}
    break;

  case 201:

/* Line 1806 of yacc.c  */
#line 1003 "aq/parser/SQL92_Grm.y"
    {
														(yyvsp[(3) - (4)])->left	= (yyvsp[(1) - (4)]);
														(yyvsp[(3) - (4)])->tag = K_NOT_LIKE;
														(yyvsp[(3) - (4)])->right = (yyvsp[(4) - (4)]);
														(yyval) = (yyvsp[(3) - (4)]);
													}
    break;

  case 202:

/* Line 1806 of yacc.c  */
#line 1009 "aq/parser/SQL92_Grm.y"
    {
														(yyvsp[(3) - (6)])->left	 = (yyvsp[(1) - (6)]);
														(yyvsp[(3) - (6)])->tag = K_NOT_LIKE;
														(yyvsp[(3) - (6)])->right = (yyvsp[(5) - (6)]);
														(yyvsp[(5) - (6)])->left	 = (yyvsp[(4) - (6)]);
														(yyvsp[(5) - (6)])->right = (yyvsp[(6) - (6)]);
														(yyval) = (yyvsp[(3) - (6)]);
													}
    break;

  case 203:

/* Line 1806 of yacc.c  */
#line 1018 "aq/parser/SQL92_Grm.y"
    {
														(yyvsp[(2) - (3)])->left	= (yyvsp[(1) - (3)]);
														(yyvsp[(2) - (3)])->right	= (yyvsp[(3) - (3)]);
														(yyval)			= (yyvsp[(2) - (3)]);
													}
    break;

  case 204:

/* Line 1806 of yacc.c  */
#line 1023 "aq/parser/SQL92_Grm.y"
    {
														(yyvsp[(2) - (5)])->left	= (yyvsp[(1) - (5)]);
														(yyvsp[(2) - (5)])->right	= (yyvsp[(4) - (5)]);
														(yyvsp[(4) - (5)])->left	= (yyvsp[(3) - (5)]);
														(yyvsp[(4) - (5)])->right	= (yyvsp[(5) - (5)]);
														(yyval)			= (yyvsp[(2) - (5)]);
													}
    break;

  case 207:

/* Line 1806 of yacc.c  */
#line 1044 "aq/parser/SQL92_Grm.y"
    {
														(yyvsp[(2) - (4)])->left	= (yyvsp[(1) - (4)]);
														(yyvsp[(2) - (4)])->right	= (yyvsp[(3) - (4)]);
														(yyvsp[(3) - (4)])->left	= (yyvsp[(4) - (4)]);
														(yyval)			= (yyvsp[(2) - (4)]);
													}
    break;

  case 208:

/* Line 1806 of yacc.c  */
#line 1050 "aq/parser/SQL92_Grm.y"
    {
														(yyvsp[(2) - (3)])->left	= (yyvsp[(1) - (3)]);
														(yyvsp[(2) - (3)])->right	= (yyvsp[(3) - (3)]);
														(yyval)			= (yyvsp[(2) - (3)]);
													}
    break;

  case 209:

/* Line 1806 of yacc.c  */
#line 1057 "aq/parser/SQL92_Grm.y"
    {
														(yyvsp[(1) - (2)])->left = (yyvsp[(2) - (2)]);
														(yyval) = (yyvsp[(1) - (2)]); 
													}
    break;

  case 212:

/* Line 1806 of yacc.c  */
#line 1067 "aq/parser/SQL92_Grm.y"
    {
														(yyval) = (yyvsp[(2) - (3)]);
													}
    break;

  case 215:

/* Line 1806 of yacc.c  */
#line 1074 "aq/parser/SQL92_Grm.y"
    {
														(yyvsp[(2) - (3)])->left	= (yyvsp[(1) - (3)]);
														(yyvsp[(2) - (3)])->right	= (yyvsp[(3) - (3)]);
														(yyval)			= (yyvsp[(2) - (3)]);
													}
    break;

  case 220:

/* Line 1806 of yacc.c  */
#line 1093 "aq/parser/SQL92_Grm.y"
    {
														delete (yyvsp[(2) - (3)]);
														(yyvsp[(1) - (3)])->right	= (yyvsp[(3) - (3)]);
														(yyval)			= (yyvsp[(1) - (3)]);
													}
    break;

  case 222:

/* Line 1806 of yacc.c  */
#line 1102 "aq/parser/SQL92_Grm.y"
    { 
														(yyval)	= (yyvsp[(1) - (1)]);
													}
    break;

  case 223:

/* Line 1806 of yacc.c  */
#line 1106 "aq/parser/SQL92_Grm.y"
    { 
														(yyval)	= (yyvsp[(1) - (1)]); 
													}
    break;

  case 224:

/* Line 1806 of yacc.c  */
#line 1109 "aq/parser/SQL92_Grm.y"
    { 
														(yyval)	= (yyvsp[(1) - (1)]); 
													}
    break;

  case 225:

/* Line 1806 of yacc.c  */
#line 1123 "aq/parser/SQL92_Grm.y"
    {
														if( (yyvsp[(3) - (5)]) != nullptr )
														{
															aq::tnode *pNode;
															pNode			= new tnode( K_COMMA );
															pNode->left		= (yyvsp[(3) - (5)]);
															pNode->right	= (yyvsp[(4) - (5)]);
															(yyvsp[(1) - (5)])->left		= pNode;
														}
														else
														{
															(yyvsp[(1) - (5)])->left	= (yyvsp[(3) - (5)]);
														}
														(yyval)			= (yyvsp[(1) - (5)]);
													}
    break;

  case 229:

/* Line 1806 of yacc.c  */
#line 1147 "aq/parser/SQL92_Grm.y"
    {
														if( (yyvsp[(3) - (3)]) != nullptr )
														{
															aq::tnode *pNode;
															pNode			= new tnode( K_COMMA );
															pNode->left		= (yyvsp[(2) - (3)]);
															pNode->right	= (yyvsp[(3) - (3)]);
															(yyval)				= pNode;
														}
														else
														{
															(yyval)				= (yyvsp[(2) - (3)]);
														}
													}
    break;

  case 230:

/* Line 1806 of yacc.c  */
#line 1161 "aq/parser/SQL92_Grm.y"
    {	(yyval) = nullptr; }
    break;

  case 232:

/* Line 1806 of yacc.c  */
#line 1167 "aq/parser/SQL92_Grm.y"
    {
														(yyval)	= (yyvsp[(2) - (2)]);
													}
    break;

  case 233:

/* Line 1806 of yacc.c  */
#line 1170 "aq/parser/SQL92_Grm.y"
    {	(yyval) = nullptr; }
    break;

  case 235:

/* Line 1806 of yacc.c  */
#line 1181 "aq/parser/SQL92_Grm.y"
    {
														(yyvsp[(1) - (4)])->left	= (yyvsp[(3) - (4)]);
														(yyval)			= (yyvsp[(1) - (4)]);
													}
    break;

  case 238:

/* Line 1806 of yacc.c  */
#line 1192 "aq/parser/SQL92_Grm.y"
    {	(yyval)	= (yyvsp[(1) - (1)]);	}
    break;

  case 242:

/* Line 1806 of yacc.c  */
#line 1201 "aq/parser/SQL92_Grm.y"
    { (yyval) = (yyvsp[(2) - (3)]); }
    break;

  case 243:

/* Line 1806 of yacc.c  */
#line 1207 "aq/parser/SQL92_Grm.y"
    {
														if( (yyvsp[(2) - (3)]) != nullptr )
														{
															if( (yyvsp[(1) - (3)]) != nullptr )
															{
																(yyvsp[(1) - (3)])->right	= (yyvsp[(3) - (3)]);
																(yyvsp[(2) - (3)])->right	= (yyvsp[(1) - (3)]);
															}
															else
																(yyvsp[(2) - (3)])->right	= (yyvsp[(3) - (3)]);
															(yyval)				= (yyvsp[(2) - (3)]);
														}
														else
														{
															if( (yyvsp[(1) - (3)]) != nullptr )
															{
																(yyvsp[(1) - (3)])->right	= (yyvsp[(3) - (3)]);
																(yyval)			= (yyvsp[(1) - (3)]);
															}
															else
																(yyval)			= (yyvsp[(3) - (3)]);
														}
													}
    break;

  case 244:

/* Line 1806 of yacc.c  */
#line 1237 "aq/parser/SQL92_Grm.y"
    {
														(yyvsp[(1) - (3)])->left	= (yyvsp[(2) - (3)]);
														(yyvsp[(2) - (3)])->left	= (yyvsp[(3) - (3)]);
														(yyval)			= (yyvsp[(1) - (3)]);
													}
    break;

  case 245:

/* Line 1806 of yacc.c  */
#line 1242 "aq/parser/SQL92_Grm.y"
    {	(yyval)	= nullptr; }
    break;

  case 247:

/* Line 1806 of yacc.c  */
#line 1247 "aq/parser/SQL92_Grm.y"
    {
														(yyvsp[(2) - (3)])->left	= (yyvsp[(1) - (3)]);
														(yyvsp[(2) - (3)])->right	= (yyvsp[(3) - (3)]);
														(yyval)			= (yyvsp[(2) - (3)]);
													}
    break;

  case 250:

/* Line 1806 of yacc.c  */
#line 1262 "aq/parser/SQL92_Grm.y"
    {
														aq::tnode *pNode;
														pNode			= new tnode( K_FRAME );
														pNode->left		= (yyvsp[(1) - (2)]);
														pNode->right	= (yyvsp[(2) - (2)]);
														(yyval)				= pNode;
													}
    break;

  case 251:

/* Line 1806 of yacc.c  */
#line 1269 "aq/parser/SQL92_Grm.y"
    {	(yyval) = nullptr; }
    break;

  case 256:

/* Line 1806 of yacc.c  */
#line 1277 "aq/parser/SQL92_Grm.y"
    {	
														(yyvsp[(2) - (2)])->left	= (yyvsp[(1) - (2)]);
														(yyval)			= (yyvsp[(2) - (2)]);
													}
    break;

  case 258:

/* Line 1806 of yacc.c  */
#line 1282 "aq/parser/SQL92_Grm.y"
    {	(yyval) = (yyvsp[(1) - (2)]);	}
    break;

  case 259:

/* Line 1806 of yacc.c  */
#line 1285 "aq/parser/SQL92_Grm.y"
    {
														(yyvsp[(2) - (2)])->left	= (yyvsp[(1) - (2)]);
														(yyval)			= (yyvsp[(2) - (2)]);
													}
    break;

  case 260:

/* Line 1806 of yacc.c  */
#line 1290 "aq/parser/SQL92_Grm.y"
    {
														(yyvsp[(3) - (4)])->left	= (yyvsp[(2) - (4)]);
														(yyvsp[(3) - (4)])->right	= (yyvsp[(4) - (4)]);
														(yyval)			= (yyvsp[(3) - (4)]);
													}
    break;

  case 264:

/* Line 1806 of yacc.c  */
#line 1298 "aq/parser/SQL92_Grm.y"
    {
														(yyvsp[(2) - (2)])->left	= (yyvsp[(1) - (2)]);
														(yyval)			= (yyvsp[(2) - (2)]);
													}
    break;

  case 266:

/* Line 1806 of yacc.c  */
#line 1305 "aq/parser/SQL92_Grm.y"
    {
														(yyvsp[(2) - (2)])->left	= (yyvsp[(1) - (2)]);
														(yyval)			= (yyvsp[(2) - (2)]);
													}
    break;

  case 267:

/* Line 1806 of yacc.c  */
#line 1318 "aq/parser/SQL92_Grm.y"
    {
														(yyvsp[(1) - (6)])->left	= (yyvsp[(3) - (6)]);
														(yyvsp[(1) - (6)])->right	= (yyvsp[(5) - (6)]);
														(yyval)			= (yyvsp[(1) - (6)]);
													}
    break;

  case 273:

/* Line 1806 of yacc.c  */
#line 1334 "aq/parser/SQL92_Grm.y"
    {
														(yyvsp[(1) - (6)])->left	= (yyvsp[(3) - (6)]);
														(yyvsp[(1) - (6)])->right	= (yyvsp[(5) - (6)]);
														(yyval)			= (yyvsp[(1) - (6)]);
													}
    break;

  case 274:

/* Line 1806 of yacc.c  */
#line 1341 "aq/parser/SQL92_Grm.y"
    {
														(yyvsp[(1) - (4)])->left	= (yyvsp[(3) - (4)]);
														(yyval)			= (yyvsp[(1) - (4)]);
													}
    break;

  case 275:

/* Line 1806 of yacc.c  */
#line 1347 "aq/parser/SQL92_Grm.y"
    {
														(yyvsp[(1) - (4)])->left	= (yyvsp[(3) - (4)]);
														(yyval)			= (yyvsp[(1) - (4)]);
													}
    break;

  case 276:

/* Line 1806 of yacc.c  */
#line 1353 "aq/parser/SQL92_Grm.y"
    {
														(yyvsp[(1) - (4)])->left	= (yyvsp[(3) - (4)]);
														(yyval)			= (yyvsp[(1) - (4)]);
													}
    break;

  case 277:

/* Line 1806 of yacc.c  */
#line 1359 "aq/parser/SQL92_Grm.y"
    {
														(yyvsp[(1) - (4)])->left	= (yyvsp[(3) - (4)]);
														(yyval)			= (yyvsp[(1) - (4)]);
													}
    break;

  case 278:

/* Line 1806 of yacc.c  */
#line 1365 "aq/parser/SQL92_Grm.y"
    {
														(yyvsp[(1) - (4)])->left	= (yyvsp[(3) - (4)]);
														(yyval)			= (yyvsp[(1) - (4)]);
													}
    break;

  case 279:

/* Line 1806 of yacc.c  */
#line 1371 "aq/parser/SQL92_Grm.y"
    {
														(yyvsp[(1) - (4)])->left	= (yyvsp[(3) - (4)]);
														(yyval)			= (yyvsp[(1) - (4)]);
													}
    break;

  case 281:

/* Line 1806 of yacc.c  */
#line 1378 "aq/parser/SQL92_Grm.y"
    {
														(yyvsp[(2) - (3)])->left	= (yyvsp[(1) - (3)]);
														(yyvsp[(2) - (3)])->right	= (yyvsp[(3) - (3)]);
														(yyval)			= (yyvsp[(2) - (3)]);
													}
    break;

  case 282:

/* Line 1806 of yacc.c  */
#line 1387 "aq/parser/SQL92_Grm.y"
    {
														(yyvsp[(4) - (6)])->left		= (yyvsp[(3) - (6)]);
														(yyvsp[(4) - (6)])->right	= (yyvsp[(5) - (6)]);
														(yyvsp[(1) - (6)])->left		= (yyvsp[(4) - (6)]);
														(yyval)			= (yyvsp[(1) - (6)]);
													}
    break;

  case 283:

/* Line 1806 of yacc.c  */
#line 1394 "aq/parser/SQL92_Grm.y"
    {
														(yyvsp[(4) - (8)])->left			= (yyvsp[(3) - (8)]);
														(yyvsp[(1) - (8)])->left			= (yyvsp[(4) - (8)]);
														(yyvsp[(6) - (8)])->left			= (yyvsp[(5) - (8)]);
														(yyvsp[(6) - (8)])->right		= (yyvsp[(7) - (8)]);
														(yyvsp[(1) - (8)])->left->left	= (yyvsp[(3) - (8)]);
														(yyvsp[(1) - (8)])->left->right	= (yyvsp[(6) - (8)]);
														(yyval)				= (yyvsp[(1) - (8)]);
													}
    break;

  case 290:

/* Line 1806 of yacc.c  */
#line 1419 "aq/parser/SQL92_Grm.y"
    {
														(yyvsp[(1) - (5)])->left	= (yyvsp[(3) - (5)]);
														(yyvsp[(1) - (5)])->right	= (yyvsp[(5) - (5)]);
														(yyval)			= (yyvsp[(1) - (5)]);
													}
    break;

  case 291:

/* Line 1806 of yacc.c  */
#line 1427 "aq/parser/SQL92_Grm.y"
    {
														(yyvsp[(1) - (10)])->left		= (yyvsp[(3) - (10)]);
														aq::tnode *pNode;
														pNode			= new tnode( K_INSERT_ARGS );
														(yyvsp[(1) - (10)])->right		= pNode;
														pNode->left		= (yyvsp[(5) - (10)]);
														pNode->right	= (yyvsp[(9) - (10)]);
														(yyval)				= (yyvsp[(1) - (10)]);
													}
    break;

  case 292:

/* Line 1806 of yacc.c  */
#line 1437 "aq/parser/SQL92_Grm.y"
    {
														(yyvsp[(1) - (7)])->left		= (yyvsp[(3) - (7)]);
														aq::tnode *pNode;
														pNode			= new tnode( K_INSERT_ARGS );
														(yyvsp[(1) - (7)])->right		= pNode;
														pNode->left		= (yyvsp[(5) - (7)]);
														pNode->right	= (yyvsp[(7) - (7)]);
														(yyval)				= (yyvsp[(1) - (7)]);
													}
    break;

  case 294:

/* Line 1806 of yacc.c  */
#line 1449 "aq/parser/SQL92_Grm.y"
    {
														(yyvsp[(2) - (3)])->left	= (yyvsp[(1) - (3)]);
														(yyvsp[(2) - (3)])->right	= (yyvsp[(3) - (3)]);
														(yyval)			= (yyvsp[(2) - (3)]);
													}
    break;

  case 299:

/* Line 1806 of yacc.c  */
#line 1465 "aq/parser/SQL92_Grm.y"
    {
														(yyvsp[(1) - (5)])->left = (yyvsp[(2) - (5)]);
														aq::tnode *pNode;
														pNode = new tnode( K_SET );
														(yyvsp[(1) - (5)])->next	 = pNode;
														pNode->left = (yyvsp[(4) - (5)]);
														pNode->next = (yyvsp[(5) - (5)]);
													}
    break;

  case 300:

/* Line 1806 of yacc.c  */
#line 1475 "aq/parser/SQL92_Grm.y"
    {
														(yyvsp[(1) - (10)])->left		= (yyvsp[(2) - (10)]);
														aq::tnode *pNode;
														pNode			= new tnode( K_SET );
														(yyvsp[(1) - (10)])->right		= pNode;
														pNode->left		= (yyvsp[(4) - (10)]);
														pNode->right	= (yyvsp[(9) - (10)]);
														pNode->right->left	= (yyvsp[(7) - (10)]);
														pNode->right->right	= (yyvsp[(10) - (10)]);
														(yyval)				= (yyvsp[(1) - (10)]);
													}
    break;

  case 302:

/* Line 1806 of yacc.c  */
#line 1489 "aq/parser/SQL92_Grm.y"
    {
														(yyvsp[(2) - (3)])->left	= (yyvsp[(1) - (3)]);
														(yyvsp[(2) - (3)])->right	= (yyvsp[(3) - (3)]);
														(yyval)			= (yyvsp[(2) - (3)]);
													}
    break;

  case 303:

/* Line 1806 of yacc.c  */
#line 1496 "aq/parser/SQL92_Grm.y"
    {
														(yyval)			= (yyvsp[(2) - (3)]);
														(yyvsp[(2) - (3)])->left	= (yyvsp[(1) - (3)]);
														(yyvsp[(2) - (3)])->right	= (yyvsp[(3) - (3)]);
													}
    break;

  case 304:

/* Line 1806 of yacc.c  */
#line 1505 "aq/parser/SQL92_Grm.y"
    {
														(yyvsp[(1) - (5)])->left		= (yyvsp[(3) - (5)]);
														(yyvsp[(1) - (5)])->right		= (yyvsp[(5) - (5)]);
														(yyval)				= (yyvsp[(1) - (5)]);
													}
    break;

  case 305:

/* Line 1806 of yacc.c  */
#line 1511 "aq/parser/SQL92_Grm.y"
    {
														(yyvsp[(1) - (9)])->left		= (yyvsp[(3) - (9)]);
														(yyvsp[(1) - (9)])->right		= (yyvsp[(8) - (9)]);
														(yyvsp[(1) - (9)])->right->left	= (yyvsp[(6) - (9)]);
														(yyvsp[(1) - (9)])->right->right= (yyvsp[(9) - (9)]);
														(yyval)				= (yyvsp[(1) - (9)]);
													}
    break;

  case 306:

/* Line 1806 of yacc.c  */
#line 1521 "aq/parser/SQL92_Grm.y"
    {
														(yyvsp[(1) - (3)])->left		= (yyvsp[(3) - (3)]);
														(yyval)				= (yyvsp[(1) - (3)]);
													}
    break;

  case 307:

/* Line 1806 of yacc.c  */
#line 1529 "aq/parser/SQL92_Grm.y"
    {
														(yyvsp[(1) - (6)])->left	= (yyvsp[(3) - (6)]);
														(yyvsp[(1) - (6)])->right	= (yyvsp[(5) - (6)]);
														(yyval)			= (yyvsp[(1) - (6)]);
													}
    break;

  case 310:

/* Line 1806 of yacc.c  */
#line 1540 "aq/parser/SQL92_Grm.y"
    {
														(yyvsp[(2) - (3)])->left	= (yyvsp[(1) - (3)]);
														(yyvsp[(2) - (3)])->right	= (yyvsp[(3) - (3)]);
														(yyval)			= (yyvsp[(2) - (3)]);
													}
    break;

  case 312:

/* Line 1806 of yacc.c  */
#line 1548 "aq/parser/SQL92_Grm.y"
    {
																		(yyvsp[(2) - (3)])->left	= (yyvsp[(1) - (3)]);
																		(yyvsp[(2) - (3)])->right	= (yyvsp[(3) - (3)]);
																		(yyval)			= (yyvsp[(2) - (3)]);
																	}
    break;

  case 313:

/* Line 1806 of yacc.c  */
#line 1555 "aq/parser/SQL92_Grm.y"
    {
														(yyvsp[(2) - (3)])->left	= (yyvsp[(1) - (3)]);
														(yyvsp[(2) - (3)])->right	= (yyvsp[(3) - (3)]);
														(yyval)			= (yyvsp[(2) - (3)]);
													}
    break;

  case 316:

/* Line 1806 of yacc.c  */
#line 1568 "aq/parser/SQL92_Grm.y"
    {
														(yyvsp[(2) - (3)])->left	= (yyvsp[(1) - (3)]);
														(yyvsp[(2) - (3)])->right	= (yyvsp[(3) - (3)]);
														(yyval)			= (yyvsp[(2) - (3)]);
													}
    break;

  case 317:

/* Line 1806 of yacc.c  */
#line 1573 "aq/parser/SQL92_Grm.y"
    {
														(yyvsp[(2) - (3)])->left	= (yyvsp[(1) - (3)]);
														(yyvsp[(2) - (3)])->right	= (yyvsp[(3) - (3)]);
														(yyval)			= (yyvsp[(2) - (3)]);
													}
    break;

  case 318:

/* Line 1806 of yacc.c  */
#line 1578 "aq/parser/SQL92_Grm.y"
    {
														(yyvsp[(2) - (4)])->left	= (yyvsp[(1) - (4)]);
														(yyvsp[(2) - (4)])->right	= (yyvsp[(3) - (4)]);
														(yyvsp[(3) - (4)])->left	= (yyvsp[(4) - (4)]);
														(yyval)			= (yyvsp[(2) - (4)]);
													}
    break;

  case 319:

/* Line 1806 of yacc.c  */
#line 1584 "aq/parser/SQL92_Grm.y"
    {
														(yyvsp[(2) - (3)])->left	= (yyvsp[(1) - (3)]);
														(yyvsp[(2) - (3)])->right	= (yyvsp[(3) - (3)]);
														(yyval)			= (yyvsp[(2) - (3)]);
													}
    break;

  case 320:

/* Line 1806 of yacc.c  */
#line 1589 "aq/parser/SQL92_Grm.y"
    {
														(yyvsp[(2) - (3)])->left	= (yyvsp[(1) - (3)]);
														(yyvsp[(2) - (3)])->right	= (yyvsp[(3) - (3)]);
														(yyval)			= (yyvsp[(2) - (3)]);
													}
    break;

  case 321:

/* Line 1806 of yacc.c  */
#line 1594 "aq/parser/SQL92_Grm.y"
    {
														(yyvsp[(2) - (4)])->left	= (yyvsp[(1) - (4)]);
														(yyvsp[(2) - (4)])->right	= (yyvsp[(3) - (4)]);
														(yyvsp[(3) - (4)])->left	= (yyvsp[(4) - (4)]);
														(yyval)			= (yyvsp[(2) - (4)]);
													}
    break;

  case 322:

/* Line 1806 of yacc.c  */
#line 1605 "aq/parser/SQL92_Grm.y"
    {
														aq::tnode *pNode1;
														pNode1			= new tnode( K_MERGE_ARGS1 );
														(yyvsp[(1) - (10)])->left		= pNode1;
														pNode1->left	= (yyvsp[(3) - (10)]);
														pNode1->right	= (yyvsp[(5) - (10)]);
														(yyvsp[(1) - (10)])->right		= (yyvsp[(7) - (10)]);
														aq::tnode *pNode2;
														pNode2			= new tnode( K_MERGE_ARGS2 );
														(yyvsp[(1) - (10)])->next		= pNode2;
														pNode2->left	= (yyvsp[(8) - (10)]);
														pNode2->right	= (yyvsp[(9) - (10)]);
														pNode2->next	= (yyvsp[(10) - (10)]);
														(yyval)				= (yyvsp[(1) - (10)]);
													}
    break;

  case 324:

/* Line 1806 of yacc.c  */
#line 1623 "aq/parser/SQL92_Grm.y"
    {	(yyval)	= nullptr; }
    break;

  case 325:

/* Line 1806 of yacc.c  */
#line 1626 "aq/parser/SQL92_Grm.y"
    {
														(yyval)	= (yyvsp[(4) - (4)]);
													}
    break;

  case 326:

/* Line 1806 of yacc.c  */
#line 1629 "aq/parser/SQL92_Grm.y"
    {	(yyval)	= nullptr; }
    break;

  case 327:

/* Line 1806 of yacc.c  */
#line 1633 "aq/parser/SQL92_Grm.y"
    {
														(yyval)	= (yyvsp[(5) - (6)]);
													}
    break;

  case 328:

/* Line 1806 of yacc.c  */
#line 1636 "aq/parser/SQL92_Grm.y"
    {	(yyval)	= nullptr; }
    break;

  case 329:

/* Line 1806 of yacc.c  */
#line 1639 "aq/parser/SQL92_Grm.y"
    {	(yyval)	= nullptr; }
    break;

  case 330:

/* Line 1806 of yacc.c  */
#line 1640 "aq/parser/SQL92_Grm.y"
    {	(yyval)	= nullptr; }
    break;

  case 331:

/* Line 1806 of yacc.c  */
#line 1644 "aq/parser/SQL92_Grm.y"
    {
														(yyval)	= (yyvsp[(7) - (7)]);
													}
    break;

  case 332:

/* Line 1806 of yacc.c  */
#line 1647 "aq/parser/SQL92_Grm.y"
    {	(yyval)	= nullptr; }
    break;

  case 333:

/* Line 1806 of yacc.c  */
#line 1650 "aq/parser/SQL92_Grm.y"
    {
														(yyvsp[(1) - (3)])->left		= (yyvsp[(3) - (3)]);
														(yyval)				= (yyvsp[(1) - (3)]);
													}
    break;

  case 335:

/* Line 1806 of yacc.c  */
#line 1658 "aq/parser/SQL92_Grm.y"
    {
														(yyvsp[(1) - (8)])->left		= (yyvsp[(3) - (8)]);
														(yyvsp[(1) - (8)])->right		= (yyvsp[(7) - (8)]);
														(yyval)				= (yyvsp[(1) - (8)]);
													}
    break;

  case 337:

/* Line 1806 of yacc.c  */
#line 1666 "aq/parser/SQL92_Grm.y"
    {
														(yyvsp[(2) - (3)])->left	= (yyvsp[(1) - (3)]);
														(yyvsp[(2) - (3)])->right	= (yyvsp[(3) - (3)]);
														(yyval)			= (yyvsp[(2) - (3)]);
													}
    break;

  case 338:

/* Line 1806 of yacc.c  */
#line 1673 "aq/parser/SQL92_Grm.y"
    {
														(yyval)			= (yyvsp[(2) - (3)]);
														(yyvsp[(2) - (3)])->left	= (yyvsp[(1) - (3)]);
														(yyvsp[(2) - (3)])->right	= (yyvsp[(3) - (3)]);
													}
    break;



/* Line 1806 of yacc.c  */
#line 4622 "aq/parser/sql92_grm_tab.cpp"
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



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
		      yytoken, &yylval);
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 2067 of yacc.c  */
#line 1680 "aq/parser/SQL92_Grm.y"


//------------------------------------------------------------------------------
#include "lex.yy.cpp"

namespace aq
{

//------------------------------------------------------------------------------
/* Returns 0 on success, 1 on error */
int SQLParse( const char *pszStr, aq::tnode*& pNode ) {
	int rc = 0;
	yy_scan_string( pszStr );
	rc = yyparse( (void*)&pNode );

  // FIXME
#ifndef __FreeBSD__ 
  yylex_destroy();
#endif

	return rc;
}

}

//------------------------------------------------------------------------------
int yywrap( void ) {
	// return 0;		// To allow multi file ( ^Z - EOF )
	return 1;		// To allow only one file ( EOF -> Exit )
}

