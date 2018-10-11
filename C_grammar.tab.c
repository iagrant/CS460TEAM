/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     IDENTIFIER = 258,
     INTEGER_CONSTANT = 259,
     FLOATING_CONSTANT = 260,
     CHARACTER_CONSTANT = 261,
     ENUMERATION_CONSTANT = 262,
     STRING_LITERAL = 263,
     SIZEOF = 264,
     INC_OP = 265,
     DEC_OP = 266,
     LEFT_OP = 267,
     RIGHT_OP = 268,
     LE_OP = 269,
     GE_OP = 270,
     EQ_OP = 271,
     NE_OP = 272,
     AND_OP = 273,
     OR_OP = 274,
     MUL_ASSIGN = 275,
     DIV_ASSIGN = 276,
     MOD_ASSIGN = 277,
     ADD_ASSIGN = 278,
     SUB_ASSIGN = 279,
     LEFT_ASSIGN = 280,
     RIGHT_ASSIGN = 281,
     AND_ASSIGN = 282,
     XOR_ASSIGN = 283,
     OR_ASSIGN = 284,
     TYPEDEF_NAME = 285,
     SEMI = 286,
     COLON = 287,
     CURLYOPEN = 288,
     CURLYCLOSE = 289,
     BRACKETOPEN = 290,
     BRACKETCLOSE = 291,
     COMMA = 292,
     PERIOD = 293,
     EQUALS = 294,
     OPEN = 295,
     CLOSE = 296,
     STAR = 297,
     QUESTION = 298,
     BAR = 299,
     CARROT = 300,
     AMP = 301,
     LESS_OP = 302,
     GREAT_OP = 303,
     PLUS = 304,
     MINUS = 305,
     FORSLASH = 306,
     PERCENT = 307,
     BANG = 308,
     TILDA = 309,
     TYPEDEF = 310,
     EXTERN = 311,
     STATIC = 312,
     AUTO = 313,
     REGISTER = 314,
     CHAR = 315,
     SHORT = 316,
     INT = 317,
     LONG = 318,
     SIGNED = 319,
     UNSIGNED = 320,
     FLOAT = 321,
     DOUBLE = 322,
     CONST = 323,
     VOLATILE = 324,
     VOID = 325,
     STRUCT = 326,
     UNION = 327,
     ENUM = 328,
     ELIPSIS = 329,
     RANGE = 330,
     CASE = 331,
     DEFAULT = 332,
     IF = 333,
     ELSE = 334,
     SWITCH = 335,
     WHILE = 336,
     DO = 337,
     FOR = 338,
     GOTO = 339,
     CONTINUE = 340,
     BREAK = 341,
     RETURN = 342,
     ERROR = 343,
     DEBUG = 344,
     MAIN = 345
   };
#endif
/* Tokens.  */
#define IDENTIFIER 258
#define INTEGER_CONSTANT 259
#define FLOATING_CONSTANT 260
#define CHARACTER_CONSTANT 261
#define ENUMERATION_CONSTANT 262
#define STRING_LITERAL 263
#define SIZEOF 264
#define INC_OP 265
#define DEC_OP 266
#define LEFT_OP 267
#define RIGHT_OP 268
#define LE_OP 269
#define GE_OP 270
#define EQ_OP 271
#define NE_OP 272
#define AND_OP 273
#define OR_OP 274
#define MUL_ASSIGN 275
#define DIV_ASSIGN 276
#define MOD_ASSIGN 277
#define ADD_ASSIGN 278
#define SUB_ASSIGN 279
#define LEFT_ASSIGN 280
#define RIGHT_ASSIGN 281
#define AND_ASSIGN 282
#define XOR_ASSIGN 283
#define OR_ASSIGN 284
#define TYPEDEF_NAME 285
#define SEMI 286
#define COLON 287
#define CURLYOPEN 288
#define CURLYCLOSE 289
#define BRACKETOPEN 290
#define BRACKETCLOSE 291
#define COMMA 292
#define PERIOD 293
#define EQUALS 294
#define OPEN 295
#define CLOSE 296
#define STAR 297
#define QUESTION 298
#define BAR 299
#define CARROT 300
#define AMP 301
#define LESS_OP 302
#define GREAT_OP 303
#define PLUS 304
#define MINUS 305
#define FORSLASH 306
#define PERCENT 307
#define BANG 308
#define TILDA 309
#define TYPEDEF 310
#define EXTERN 311
#define STATIC 312
#define AUTO 313
#define REGISTER 314
#define CHAR 315
#define SHORT 316
#define INT 317
#define LONG 318
#define SIGNED 319
#define UNSIGNED 320
#define FLOAT 321
#define DOUBLE 322
#define CONST 323
#define VOLATILE 324
#define VOID 325
#define STRUCT 326
#define UNION 327
#define ENUM 328
#define ELIPSIS 329
#define RANGE 330
#define CASE 331
#define DEFAULT 332
#define IF 333
#define ELSE 334
#define SWITCH 335
#define WHILE 336
#define DO 337
#define FOR 338
#define GOTO 339
#define CONTINUE 340
#define BREAK 341
#define RETURN 342
#define ERROR 343
#define DEBUG 344
#define MAIN 345




/* Copy the first part of user declarations.  */
#line 1 "C_grammar.y"

	#include <stdio.h>
	#include <string.h>
	#include <stdlib.h>
	#include <iostream>

	extern bool printProductions;
	void  yyerror(char *msg)
	{
	    printf("syntax error - abort 00 %s",msg);
	    exit(1);
	}


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
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

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 14 "C_grammar.y"
{
  int ival;
  char cval;
  char sval[32];
  double dval;
}
/* Line 193 of yacc.c.  */
#line 297 "C_grammar.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 310 "C_grammar.tab.c"

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
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
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
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

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

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  45
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1810

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  91
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  67
/* YYNRULES -- Number of rules.  */
#define YYNRULES  224
/* YYNRULES -- Number of states.  */
#define YYNSTATES  378

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   345

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
      85,    86,    87,    88,    89,    90
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,    10,    12,    15,    19,    23,
      28,    31,    35,    37,    40,    42,    45,    47,    50,    52,
      55,    57,    59,    61,    63,    65,    67,    69,    71,    73,
      75,    77,    79,    81,    83,    85,    87,    89,    91,    93,
      99,   104,   107,   109,   111,   113,   116,   118,   122,   124,
     128,   132,   134,   137,   139,   142,   144,   148,   150,   153,
     157,   162,   168,   171,   173,   177,   179,   183,   185,   188,
     190,   194,   198,   203,   207,   212,   217,   219,   222,   225,
     229,   231,   234,   236,   240,   242,   246,   249,   251,   254,
     256,   260,   262,   266,   271,   273,   277,   279,   282,   284,
     286,   289,   293,   296,   300,   304,   309,   312,   316,   320,
     325,   327,   329,   331,   333,   335,   337,   341,   346,   350,
     352,   355,   358,   362,   366,   371,   373,   376,   382,   390,
     396,   402,   410,   417,   425,   433,   442,   450,   459,   468,
     478,   482,   485,   488,   491,   495,   497,   501,   503,   507,
     509,   511,   513,   515,   517,   519,   521,   523,   525,   527,
     529,   531,   537,   539,   541,   545,   547,   551,   553,   557,
     559,   563,   565,   569,   571,   575,   579,   581,   585,   589,
     593,   597,   599,   603,   607,   609,   613,   617,   619,   623,
     627,   631,   633,   638,   640,   643,   646,   649,   652,   657,
     659,   661,   663,   665,   667,   669,   671,   676,   680,   685,
     689,   693,   696,   699,   701,   703,   705,   709,   711,   715,
     717,   719,   721,   723,   725
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      92,     0,    -1,    93,    -1,    92,    93,    -1,    94,    -1,
      95,    -1,   113,   129,    -1,   113,    96,   129,    -1,    97,
     113,   129,    -1,    97,   113,    96,   129,    -1,    97,    31,
      -1,    97,   104,    31,    -1,    95,    -1,    96,    95,    -1,
      98,    -1,    98,    97,    -1,    99,    -1,    99,    97,    -1,
     100,    -1,   100,    97,    -1,    58,    -1,    59,    -1,    57,
      -1,    56,    -1,    55,    -1,    70,    -1,    60,    -1,    61,
      -1,    62,    -1,    63,    -1,    66,    -1,    67,    -1,    64,
      -1,    65,    -1,   101,    -1,   110,    -1,    30,    -1,    68,
      -1,    69,    -1,   102,   157,    33,   103,    34,    -1,   102,
      33,   103,    34,    -1,   102,   157,    -1,    71,    -1,    72,
      -1,   106,    -1,   103,   106,    -1,   105,    -1,   104,    37,
     105,    -1,   113,    -1,   113,    39,   121,    -1,   107,   108,
      31,    -1,    99,    -1,    99,   107,    -1,   100,    -1,   100,
     107,    -1,   109,    -1,   108,    37,   109,    -1,   113,    -1,
      32,   138,    -1,   113,    32,   138,    -1,    73,    33,   111,
      34,    -1,    73,   157,    33,   111,    34,    -1,    73,   157,
      -1,   112,    -1,   111,    37,   112,    -1,   157,    -1,   157,
      39,   138,    -1,   114,    -1,   115,   114,    -1,   157,    -1,
      40,   113,    41,    -1,   114,    35,    36,    -1,   114,    35,
     138,    36,    -1,   114,    40,    41,    -1,   114,    40,   117,
      41,    -1,   114,    40,   120,    41,    -1,    42,    -1,    42,
     116,    -1,    42,   115,    -1,    42,   116,   115,    -1,   100,
      -1,   116,   100,    -1,   118,    -1,   118,    37,    74,    -1,
     119,    -1,   118,    37,   119,    -1,    97,   113,    -1,    97,
      -1,    97,   124,    -1,   157,    -1,   120,    37,   157,    -1,
     135,    -1,    33,   122,    34,    -1,    33,   122,    37,    34,
      -1,   121,    -1,   122,    37,   121,    -1,   107,    -1,   107,
     124,    -1,   115,    -1,   125,    -1,   115,   125,    -1,    40,
     124,    41,    -1,    35,    36,    -1,    35,   138,    36,    -1,
     125,    35,    36,    -1,   125,    35,   138,    36,    -1,    40,
      41,    -1,    40,   117,    41,    -1,   125,    40,    41,    -1,
     125,    40,   117,    41,    -1,   127,    -1,   129,    -1,   128,
      -1,   131,    -1,   132,    -1,   133,    -1,   157,    32,   126,
      -1,    76,   138,    32,   126,    -1,    77,    32,   126,    -1,
      31,    -1,   134,    31,    -1,    33,    34,    -1,    33,   130,
      34,    -1,    33,    96,    34,    -1,    33,    96,   130,    34,
      -1,   126,    -1,   130,   126,    -1,    78,    40,   134,    41,
     126,    -1,    78,    40,   134,    41,   126,    79,   126,    -1,
      80,    40,   134,    41,   126,    -1,    81,    40,   134,    41,
     126,    -1,    82,   126,    81,    40,   134,    41,    31,    -1,
      83,    40,    31,    31,    41,   126,    -1,    83,    40,    31,
      31,   134,    41,   126,    -1,    83,    40,    31,   134,    31,
      41,   126,    -1,    83,    40,    31,   134,    31,   134,    41,
     126,    -1,    83,    40,   134,    31,    31,    41,   126,    -1,
      83,    40,   134,    31,    31,   134,    41,   126,    -1,    83,
      40,   134,    31,   134,    31,    41,   126,    -1,    83,    40,
     134,    31,   134,    31,   134,    41,   126,    -1,    84,   157,
      31,    -1,    85,    31,    -1,    86,    31,    -1,    87,    31,
      -1,    87,   134,    31,    -1,   135,    -1,   134,    37,   135,
      -1,   137,    -1,   150,   136,   135,    -1,    39,    -1,    20,
      -1,    21,    -1,    22,    -1,    23,    -1,    24,    -1,    25,
      -1,    26,    -1,    27,    -1,    28,    -1,    29,    -1,   139,
      -1,   139,    43,   134,    32,   137,    -1,   137,    -1,   140,
      -1,   139,    19,   140,    -1,   141,    -1,   140,    18,   141,
      -1,   142,    -1,   141,    44,   142,    -1,   143,    -1,   142,
      45,   143,    -1,   144,    -1,   143,    46,   144,    -1,   145,
      -1,   144,    16,   145,    -1,   144,    17,   145,    -1,   146,
      -1,   145,    47,   146,    -1,   145,    48,   146,    -1,   145,
      14,   146,    -1,   145,    15,   146,    -1,   147,    -1,   146,
      12,   147,    -1,   146,    13,   147,    -1,   148,    -1,   147,
      49,   148,    -1,   147,    50,   148,    -1,   149,    -1,   148,
      42,   149,    -1,   148,    51,   149,    -1,   148,    52,   149,
      -1,   150,    -1,    40,   123,    41,   149,    -1,   152,    -1,
      10,   150,    -1,    11,   150,    -1,   151,   149,    -1,     9,
     150,    -1,     9,    40,   123,    41,    -1,    46,    -1,    42,
      -1,    49,    -1,    50,    -1,    54,    -1,    53,    -1,   153,
      -1,   152,    35,   134,    36,    -1,   152,    40,    41,    -1,
     152,    40,   154,    41,    -1,   152,    38,   157,    -1,   152,
      42,   157,    -1,   152,    10,    -1,   152,    11,    -1,   157,
      -1,   155,    -1,   156,    -1,    40,   134,    41,    -1,   135,
      -1,   154,    37,   135,    -1,     4,    -1,     6,    -1,     5,
      -1,     7,    -1,     8,    -1,     3,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    51,    51,    57,    66,    72,    81,    87,    93,    99,
     108,   114,   123,   129,   138,   144,   150,   156,   162,   168,
     177,   183,   189,   195,   201,   210,   216,   222,   228,   234,
     240,   246,   252,   258,   264,   270,   276,   285,   291,   300,
     306,   312,   321,   327,   336,   342,   351,   357,   366,   372,
     381,   390,   396,   402,   408,   417,   423,   432,   438,   444,
     453,   459,   465,   474,   480,   489,   495,   504,   510,   519,
     525,   531,   537,   543,   549,   555,   564,   570,   576,   582,
     591,   597,   606,   612,   621,   627,   636,   642,   648,   657,
     663,   672,   678,   684,   693,   699,   708,   714,   723,   729,
     735,   744,   750,   756,   762,   768,   774,   780,   786,   792,
     801,   807,   813,   819,   825,   831,   840,   846,   852,   861,
     867,   876,   882,   888,   894,   903,   909,   918,   924,   930,
     939,   945,   951,   957,   963,   969,   975,   981,   987,   993,
    1002,  1008,  1014,  1020,  1026,  1035,  1041,  1050,  1056,  1065,
    1071,  1077,  1083,  1089,  1095,  1101,  1107,  1113,  1119,  1125,
    1134,  1140,  1149,  1158,  1164,  1173,  1179,  1188,  1194,  1203,
    1209,  1218,  1224,  1233,  1239,  1245,  1254,  1260,  1266,  1272,
    1278,  1287,  1293,  1299,  1308,  1314,  1320,  1329,  1335,  1341,
    1347,  1356,  1362,  1371,  1377,  1383,  1389,  1395,  1401,  1410,
    1416,  1422,  1428,  1434,  1440,  1449,  1455,  1461,  1467,  1473,
    1479,  1485,  1491,  1500,  1506,  1512,  1518,  1527,  1533,  1542,
    1548,  1554,  1560,  1569,  1578
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFIER", "INTEGER_CONSTANT",
  "FLOATING_CONSTANT", "CHARACTER_CONSTANT", "ENUMERATION_CONSTANT",
  "STRING_LITERAL", "SIZEOF", "INC_OP", "DEC_OP", "LEFT_OP", "RIGHT_OP",
  "LE_OP", "GE_OP", "EQ_OP", "NE_OP", "AND_OP", "OR_OP", "MUL_ASSIGN",
  "DIV_ASSIGN", "MOD_ASSIGN", "ADD_ASSIGN", "SUB_ASSIGN", "LEFT_ASSIGN",
  "RIGHT_ASSIGN", "AND_ASSIGN", "XOR_ASSIGN", "OR_ASSIGN", "TYPEDEF_NAME",
  "SEMI", "COLON", "CURLYOPEN", "CURLYCLOSE", "BRACKETOPEN",
  "BRACKETCLOSE", "COMMA", "PERIOD", "EQUALS", "OPEN", "CLOSE", "STAR",
  "QUESTION", "BAR", "CARROT", "AMP", "LESS_OP", "GREAT_OP", "PLUS",
  "MINUS", "FORSLASH", "PERCENT", "BANG", "TILDA", "TYPEDEF", "EXTERN",
  "STATIC", "AUTO", "REGISTER", "CHAR", "SHORT", "INT", "LONG", "SIGNED",
  "UNSIGNED", "FLOAT", "DOUBLE", "CONST", "VOLATILE", "VOID", "STRUCT",
  "UNION", "ENUM", "ELIPSIS", "RANGE", "CASE", "DEFAULT", "IF", "ELSE",
  "SWITCH", "WHILE", "DO", "FOR", "GOTO", "CONTINUE", "BREAK", "RETURN",
  "ERROR", "DEBUG", "MAIN", "$accept", "translation_unit",
  "external_declaration", "function_definition", "declaration",
  "declaration_list", "declaration_specifiers", "storage_class_specifier",
  "type_specifier", "type_qualifier", "struct_or_union_specifier",
  "struct_or_union", "struct_declaration_list", "init_declarator_list",
  "init_declarator", "struct_declaration", "specifier_qualifier_list",
  "struct_declarator_list", "struct_declarator", "enum_specifier",
  "enumerator_list", "enumerator", "declarator", "direct_declarator",
  "pointer", "type_qualifier_list", "parameter_type_list",
  "parameter_list", "parameter_declaration", "identifier_list",
  "initializer", "initializer_list", "type_name", "abstract_declarator",
  "direct_abstract_declarator", "statement", "labeled_statement",
  "expression_statement", "compound_statement", "statement_list",
  "selection_statement", "iteration_statement", "jump_statement",
  "expression", "assignment_expression", "assignment_operator",
  "conditional_expression", "constant_expression", "logical_or_expression",
  "logical_and_expression", "inclusive_or_expression",
  "exclusive_or_expression", "and_expression", "equality_expression",
  "relational_expression", "shift_expression", "additive_expression",
  "multiplicative_expression", "cast_expression", "unary_expression",
  "unary_operator", "postfix_expression", "primary_expression",
  "argument_expression_list", "constant", "string", "identifier", 0
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
     345
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    91,    92,    92,    93,    93,    94,    94,    94,    94,
      95,    95,    96,    96,    97,    97,    97,    97,    97,    97,
      98,    98,    98,    98,    98,    99,    99,    99,    99,    99,
      99,    99,    99,    99,    99,    99,    99,   100,   100,   101,
     101,   101,   102,   102,   103,   103,   104,   104,   105,   105,
     106,   107,   107,   107,   107,   108,   108,   109,   109,   109,
     110,   110,   110,   111,   111,   112,   112,   113,   113,   114,
     114,   114,   114,   114,   114,   114,   115,   115,   115,   115,
     116,   116,   117,   117,   118,   118,   119,   119,   119,   120,
     120,   121,   121,   121,   122,   122,   123,   123,   124,   124,
     124,   125,   125,   125,   125,   125,   125,   125,   125,   125,
     126,   126,   126,   126,   126,   126,   127,   127,   127,   128,
     128,   129,   129,   129,   129,   130,   130,   131,   131,   131,
     132,   132,   132,   132,   132,   132,   132,   132,   132,   132,
     133,   133,   133,   133,   133,   134,   134,   135,   135,   136,
     136,   136,   136,   136,   136,   136,   136,   136,   136,   136,
     137,   137,   138,   139,   139,   140,   140,   141,   141,   142,
     142,   143,   143,   144,   144,   144,   145,   145,   145,   145,
     145,   146,   146,   146,   147,   147,   147,   148,   148,   148,
     148,   149,   149,   150,   150,   150,   150,   150,   150,   151,
     151,   151,   151,   151,   151,   152,   152,   152,   152,   152,
     152,   152,   152,   153,   153,   153,   153,   154,   154,   155,
     155,   155,   155,   156,   157
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     2,     3,     3,     4,
       2,     3,     1,     2,     1,     2,     1,     2,     1,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     5,
       4,     2,     1,     1,     1,     2,     1,     3,     1,     3,
       3,     1,     2,     1,     2,     1,     3,     1,     2,     3,
       4,     5,     2,     1,     3,     1,     3,     1,     2,     1,
       3,     3,     4,     3,     4,     4,     1,     2,     2,     3,
       1,     2,     1,     3,     1,     3,     2,     1,     2,     1,
       3,     1,     3,     4,     1,     3,     1,     2,     1,     1,
       2,     3,     2,     3,     3,     4,     2,     3,     3,     4,
       1,     1,     1,     1,     1,     1,     3,     4,     3,     1,
       2,     2,     3,     3,     4,     1,     2,     5,     7,     5,
       5,     7,     6,     7,     7,     8,     7,     8,     8,     9,
       3,     2,     2,     2,     3,     1,     3,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     5,     1,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     3,     1,     3,     3,     1,     3,     3,     3,
       3,     1,     3,     3,     1,     3,     3,     1,     3,     3,
       3,     1,     4,     1,     2,     2,     2,     2,     4,     1,
       1,     1,     1,     1,     1,     1,     4,     3,     4,     3,
       3,     2,     2,     1,     1,     1,     3,     1,     3,     1,
       1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,   224,    36,     0,    76,    24,    23,    22,    20,    21,
      26,    27,    28,    29,    32,    33,    30,    31,    37,    38,
      25,    42,    43,     0,     0,     2,     4,     5,     0,    14,
      16,    18,    34,     0,    35,     0,    67,     0,    69,     0,
      80,    78,    77,     0,    62,     1,     3,    10,     0,    46,
      48,    15,    17,    19,     0,    41,     0,    12,     0,     0,
       6,     0,     0,    68,    70,    81,    79,     0,    63,    65,
       0,    11,     0,     0,     0,     8,    51,    53,     0,    44,
       0,     0,   219,   221,   220,   222,   223,     0,     0,     0,
     119,   121,     0,   200,   199,   201,   202,   204,   203,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   125,   110,   112,   111,     0,   113,   114,   115,     0,
     145,   147,   160,   163,   165,   167,   169,   171,   173,   176,
     181,   184,   187,   191,     0,   193,   205,   214,   215,   213,
      13,     7,    48,    71,   162,     0,   191,   213,    73,    87,
       0,    82,    84,     0,    89,    60,     0,     0,     0,    47,
       0,    49,    91,     9,    52,    54,    40,    45,     0,     0,
      55,    57,     0,     0,   197,     0,   194,   195,    96,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   141,
     142,   143,     0,   123,     0,   122,   126,   120,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   149,     0,
     196,   211,   212,     0,     0,     0,     0,     0,    72,     0,
       0,    86,    98,    88,    99,    74,     0,     0,    75,    64,
      66,    61,    94,     0,    58,    50,     0,     0,    39,     0,
       0,    98,    97,     0,   216,     0,   118,     0,     0,     0,
       0,     0,     0,   140,   144,   124,   146,   164,     0,   166,
     168,   170,   172,   174,   175,   179,   180,   177,   178,   182,
     183,   185,   186,   188,   189,   190,   148,     0,   209,   207,
     217,     0,   210,   116,   102,     0,   106,     0,     0,   100,
       0,     0,    83,    85,    90,    92,     0,    56,    59,   198,
     192,   117,     0,     0,     0,     0,     0,     0,     0,     0,
     206,     0,   208,   103,   107,   101,   104,     0,   108,     0,
      93,    95,   127,   129,   130,     0,     0,     0,     0,     0,
       0,   161,   218,   105,   109,     0,     0,   132,     0,     0,
       0,     0,     0,     0,   128,   131,   133,   134,     0,   136,
       0,     0,     0,   135,   137,   138,     0,   139
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    24,    25,    26,    57,    58,    59,    29,    30,    31,
      32,    33,    78,    48,    49,    79,    80,   169,   170,    34,
      67,    68,    35,    36,    37,    42,   307,   151,   152,   153,
     161,   253,   179,   308,   244,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   229,   121,   145,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   301,   137,   138,   147
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -230
static const yytype_int16 yypact[] =
{
     869,  -230,  -230,    79,    55,  -230,  -230,  -230,  -230,  -230,
    -230,  -230,  -230,  -230,  -230,  -230,  -230,  -230,  -230,  -230,
    -230,  -230,  -230,    24,   332,  -230,  -230,  -230,    11,  1665,
    1665,  1665,  -230,    28,  -230,  1602,   118,     9,  -230,   -34,
    -230,  -230,    55,    16,    35,  -230,  -230,  -230,   -15,  -230,
    1583,  -230,  -230,  -230,  1737,    54,   432,  -230,  1602,    11,
    -230,  1006,   913,   118,  -230,  -230,  -230,    32,  -230,    75,
      16,  -230,    79,  1021,  1602,  -230,  1737,  1737,  1709,  -230,
      44,  1737,  -230,  -230,  -230,  -230,  -230,  1425,  1477,  1477,
    -230,  -230,   781,  -230,  -230,  -230,  -230,  -230,  -230,  1492,
      90,   132,   161,   163,   723,   178,    16,   179,   214,  1073,
     524,  -230,  -230,  -230,  -230,   609,  -230,  -230,  -230,    94,
    -230,  -230,    31,   212,   209,   219,   227,   116,    64,   176,
     194,    41,  -230,   199,  1492,   157,  -230,  -230,  -230,   230,
    -230,  -230,   247,  -230,  -230,   240,  -230,  -230,  -230,    23,
     252,   251,  -230,    -3,  -230,  -230,    16,  1492,    51,  -230,
    1021,  -230,  -230,  -230,  -230,  -230,  -230,  -230,  1492,   111,
    -230,   263,  1723,   781,  -230,  1492,  -230,  -230,   117,   266,
      66,   278,   723,  1492,  1492,  1492,   231,  1089,   280,  -230,
    -230,  -230,   129,  -230,   666,  -230,  -230,  -230,  1492,  1492,
    1492,  1492,  1492,  1492,  1492,  1492,  1492,  1492,  1492,  1492,
    1492,  1492,  1492,  1492,  1492,  1492,  1492,  1492,  -230,  -230,
    -230,  -230,  -230,  -230,  -230,  -230,  -230,  -230,  -230,  1492,
    -230,  -230,  -230,  1492,    16,  1141,    16,   723,  -230,  1156,
     825,  -230,   135,  -230,   134,  -230,  1494,    16,  -230,  -230,
    -230,  -230,  -230,   107,  -230,  -230,    44,  1492,  -230,   272,
    1539,   165,  -230,  1492,  -230,   723,  -230,   167,   172,   174,
     274,  1208,   142,  -230,  -230,  -230,  -230,   212,   170,   209,
     219,   227,   116,    64,    64,   176,   176,   176,   176,   194,
     194,    41,    41,  -230,  -230,  -230,  -230,   243,  -230,  -230,
    -230,   175,  -230,  -230,  -230,   281,  -230,   275,   277,   134,
    1223,  1646,  -230,  -230,  -230,  -230,   954,  -230,  -230,  -230,
    -230,  -230,   723,   723,   723,  1492,  1275,   146,  1291,  1492,
    -230,  1492,  -230,  -230,  -230,  -230,  -230,   283,  -230,   279,
    -230,  -230,   242,  -230,  -230,   192,   723,   198,  1343,  1358,
     156,  -230,  -230,  -230,  -230,   723,   294,  -230,   723,   723,
     217,   723,   222,  1410,  -230,  -230,  -230,  -230,   723,  -230,
     723,   723,   237,  -230,  -230,  -230,   723,  -230
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -230,  -230,   303,  -230,    71,   140,    15,  -230,    59,    13,
    -230,  -230,   248,  -230,   256,   -70,   -56,  -230,    74,  -230,
     261,   177,     1,   -36,     6,  -230,   -51,  -230,    88,  -230,
    -155,  -230,   164,  -124,  -229,   -74,  -230,  -230,   104,   226,
    -230,  -230,  -230,   -57,   -64,  -230,   -59,   -93,  -230,   139,
     138,   141,   137,   143,    77,    91,    78,    95,  -116,   216,
    -230,  -230,  -230,  -230,  -230,  -230,     0
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
      38,    63,   144,    38,    39,   252,   181,    64,   167,   162,
      41,   150,     1,   309,     1,    28,    71,    40,   230,     1,
     164,   165,    72,    44,    38,   243,     1,     1,    38,    50,
     186,     1,   309,    55,   247,   180,   178,    38,   248,    28,
     144,   196,    47,    69,    51,    52,    53,     1,    66,     3,
     199,     3,   192,     4,   262,    65,   139,    43,   239,    38,
     142,    54,   154,   240,   250,     4,   155,    77,    70,   156,
      69,    27,    38,   142,   200,   254,   168,   149,   207,   208,
      38,   171,     1,   215,     3,   251,     4,    81,   156,    77,
      77,    77,   216,   217,    77,    27,   162,     4,   144,   293,
     294,   295,   167,   198,   139,    77,   188,   264,   266,   144,
     139,   209,   210,    76,   157,   139,   180,   178,   180,     3,
     196,     4,   182,    18,    19,   197,   267,   268,   269,   140,
     272,   198,   205,   206,   276,    76,    76,    76,     1,    60,
      76,   315,   255,   278,   316,   140,   305,   320,   256,    38,
     241,    76,   239,    61,    75,   242,    69,   260,    62,     4,
     274,   341,   141,   303,   318,   296,   198,   231,   232,   310,
     239,   300,   183,   328,   311,   240,   297,   348,   163,   198,
     144,   140,   139,   198,   261,    77,    77,   363,   211,   212,
      74,   321,   233,   198,   139,   234,   110,   235,   144,   236,
     239,   184,   329,   185,   198,   260,    63,   198,   322,   198,
     189,   198,   331,   323,   327,   324,   332,   337,   187,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   198,
     201,    76,    76,   356,   298,   198,   302,   139,   228,   358,
      38,    39,    38,   213,   214,   190,   242,   314,   342,   343,
     344,   144,   162,   202,   198,   149,    38,   171,   368,   198,
     339,   149,   237,   370,   203,   139,   261,   352,   345,   347,
     351,   350,   357,   204,   198,   149,   238,   146,   376,   330,
     198,   364,   283,   284,   366,   367,    73,   369,   246,   289,
     290,   360,   362,   245,   373,   257,   374,   375,   285,   286,
     287,   288,   377,   174,   176,   177,   372,   263,   291,   292,
     265,   273,   270,   319,   325,   146,   334,   333,   335,   353,
     354,   355,   139,   139,   139,   365,   149,    46,   159,   172,
     317,   158,    45,   249,   313,     1,   194,   259,   277,   279,
     281,     0,     0,   280,     0,     0,   139,   282,     0,     0,
     146,     0,     0,     0,     0,   139,     0,     0,   139,   139,
       0,   139,     2,     0,     0,     0,     0,     0,   139,     0,
     139,   139,     3,   146,     4,     0,   139,     0,     0,     0,
       0,     0,     0,     0,   146,     0,     0,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   146,     0,   146,   146,   146,
     146,   146,   146,   146,   146,   146,   146,   146,   146,   146,
     146,   146,   146,   146,     0,     1,    82,    83,    84,    85,
      86,    87,    88,    89,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   146,     0,     0,     0,     0,
       0,     0,     2,    90,     0,    56,    91,     0,     0,     0,
       0,     0,    92,   146,    93,     0,     0,     0,    94,   146,
       0,    95,    96,     0,     0,    97,    98,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,     0,     0,    99,   100,
     101,     0,   102,   103,   104,   105,   106,   107,   108,   109,
       0,     0,     0,     0,     0,     0,   146,     1,    82,    83,
      84,    85,    86,    87,    88,    89,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   146,     0,     0,     0,     0,
       0,     0,     0,     0,     2,    90,     0,    56,   193,     0,
       0,     0,     0,     0,    92,     0,    93,     0,     0,     0,
      94,     0,     0,    95,    96,     0,     0,    97,    98,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,     0,     0,
      99,   100,   101,     0,   102,   103,   104,   105,   106,   107,
     108,   109,     1,    82,    83,    84,    85,    86,    87,    88,
      89,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      90,     0,    56,   195,     0,     0,     0,     0,     0,    92,
       0,    93,     0,     0,     0,    94,     0,     0,    95,    96,
       0,     0,    97,    98,     0,     0,     0,     0,     0,     1,
      82,    83,    84,    85,    86,    87,    88,    89,     0,     0,
       0,     0,     0,     0,     0,    99,   100,   101,     0,   102,
     103,   104,   105,   106,   107,   108,   109,    90,     0,    56,
     275,     0,     0,     0,     0,     0,    92,     0,    93,     0,
       0,     0,    94,     0,     0,    95,    96,     0,     0,    97,
      98,     0,     0,     0,     0,     0,     1,    82,    83,    84,
      85,    86,    87,    88,    89,     0,     0,     0,     0,     0,
       0,     0,    99,   100,   101,     0,   102,   103,   104,   105,
     106,   107,   108,   109,    90,     0,    56,     0,     0,     0,
       0,     0,     0,    92,     0,    93,     0,     0,     0,    94,
       0,     0,    95,    96,     0,     0,    97,    98,     0,     0,
       0,     0,     0,     0,     1,    82,    83,    84,    85,    86,
      87,    88,    89,     0,     0,     0,     0,     0,     0,    99,
     100,   101,     0,   102,   103,   104,   105,   106,   107,   108,
     109,     2,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    92,     0,    93,     0,     0,     0,    94,     1,     0,
      95,    96,     0,     0,    97,    98,     0,     0,     0,     0,
       0,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,     2,     0,     0,     0,     0,
     239,     0,     0,     0,     0,   240,   306,     4,     0,     0,
       0,     0,     1,     0,     0,     0,     0,     0,     0,     0,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,     2,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     3,
       0,     4,     0,     0,     0,     0,     1,     0,     0,     0,
       0,     0,     0,     0,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,     2,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   148,     0,     0,     1,    82,    83,
      84,    85,    86,    87,    88,    89,     0,     0,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,   160,   340,     0,
       0,     0,     0,     0,    92,     0,    93,     0,     0,     0,
      94,     0,     0,    95,    96,     0,     0,    97,    98,     1,
      82,    83,    84,    85,    86,    87,    88,    89,     0,     0,
       0,     0,     0,     0,     1,    82,    83,    84,    85,    86,
      87,    88,    89,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   143,     0,     0,     0,    92,     0,    93,     0,
       0,     0,    94,     0,   160,    95,    96,     0,     0,    97,
      98,    92,     0,    93,     0,     0,     0,    94,     0,     0,
      95,    96,     0,     0,    97,    98,     1,    82,    83,    84,
      85,    86,    87,    88,    89,     0,     0,     0,     0,     0,
       0,     0,     1,    82,    83,    84,    85,    86,    87,    88,
      89,     0,     0,     0,   191,     0,     0,     0,     0,     0,
       0,     0,     0,    92,     0,    93,     0,     0,     0,    94,
     271,     0,    95,    96,     0,     0,    97,    98,     0,    92,
       0,    93,     0,     0,     0,    94,     0,     0,    95,    96,
       0,     0,    97,    98,     1,    82,    83,    84,    85,    86,
      87,    88,    89,     0,     0,     0,     0,     0,     0,     1,
      82,    83,    84,    85,    86,    87,    88,    89,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    92,   299,    93,     0,     0,     0,    94,     0,     0,
      95,    96,   304,     0,    97,    98,    92,     0,    93,     0,
       0,     0,    94,     0,     0,    95,    96,     0,     0,    97,
      98,     1,    82,    83,    84,    85,    86,    87,    88,    89,
       0,     0,     0,     0,     0,     0,     1,    82,    83,    84,
      85,    86,    87,    88,    89,     0,     0,     0,     0,   326,
       0,     0,     0,     0,     0,     0,     0,     0,    92,     0,
      93,     0,     0,     0,    94,     0,     0,    95,    96,   336,
       0,    97,    98,    92,     0,    93,     0,     0,     0,    94,
       0,     0,    95,    96,     0,     0,    97,    98,     1,    82,
      83,    84,    85,    86,    87,    88,    89,     0,     0,     0,
       0,     0,     0,     0,     1,    82,    83,    84,    85,    86,
      87,    88,    89,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    92,   346,    93,     0,     0,
       0,    94,   349,     0,    95,    96,     0,     0,    97,    98,
       0,    92,     0,    93,     0,     0,     0,    94,     0,     0,
      95,    96,     0,     0,    97,    98,     1,    82,    83,    84,
      85,    86,    87,    88,    89,     0,     0,     0,     0,     0,
       0,     1,    82,    83,    84,    85,    86,    87,    88,    89,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    92,   359,    93,     0,     0,     0,    94,
       0,     0,    95,    96,     0,     0,    97,    98,    92,   361,
      93,     0,     0,     0,    94,     0,     0,    95,    96,     0,
       0,    97,    98,     1,    82,    83,    84,    85,    86,    87,
      88,    89,     0,     0,     0,     0,     0,     0,     1,    82,
      83,    84,    85,    86,    87,    88,    89,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      92,   371,    93,     0,     0,     0,    94,     0,     0,    95,
      96,     0,     0,    97,    98,   173,     0,    93,     0,     0,
       0,    94,     0,     0,    95,    96,     0,     0,    97,    98,
       1,    82,    83,    84,    85,    86,    87,    88,    89,     0,
       0,     0,     0,     0,     0,     1,    82,    83,    84,    85,
      86,    87,    88,    89,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   175,     0,    93,
       0,     0,     0,    94,     2,     0,    95,    96,     0,     0,
      97,    98,    92,     0,    93,     0,     0,     0,    94,     0,
       0,    95,    96,     0,     0,    97,    98,     0,     0,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,   312,     2,
       0,     0,     0,     0,   239,     0,     0,     0,     0,   260,
     306,     4,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,     2,     0,     0,    56,     0,     0,     0,
       0,     0,    73,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     2,     0,     0,    56,     0,     0,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,     2,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   338,     0,     0,
       0,     0,     0,     0,     0,     2,     0,     0,     0,     0,
       0,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,     2,
       0,     0,     0,   166,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     2,     0,     0,     0,   258,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     2,     0,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23
};

static const yytype_int16 yycheck[] =
{
       0,    37,    61,     3,     3,   160,    99,    41,    78,    73,
       4,    62,     3,   242,     3,     0,    31,     4,   134,     3,
      76,    77,    37,    23,    24,   149,     3,     3,    28,    28,
     104,     3,   261,    33,    37,    92,    92,    37,    41,    24,
      99,   115,    31,    43,    29,    30,    31,     3,    42,    40,
      19,    40,   109,    42,   178,    42,    56,    33,    35,    59,
      59,    33,    62,    40,   157,    42,    34,    54,    33,    37,
      70,     0,    72,    72,    43,   168,    32,    62,    14,    15,
      80,    80,     3,    42,    40,    34,    42,    33,    37,    76,
      77,    78,    51,    52,    81,    24,   160,    42,   157,   215,
     216,   217,   172,    37,   104,    92,   106,    41,   182,   168,
     110,    47,    48,    54,    39,   115,   173,   173,   175,    40,
     194,    42,    32,    68,    69,    31,   183,   184,   185,    58,
     187,    37,    16,    17,   198,    76,    77,    78,     3,    35,
      81,    34,    31,   200,    37,    74,   239,   263,    37,   149,
     149,    92,    35,    35,    50,   149,   156,    40,    40,    42,
      31,   316,    58,   237,   257,   229,    37,    10,    11,    35,
      35,   235,    40,    31,    40,    40,   233,    31,    74,    37,
     239,   110,   182,    37,   178,   172,   173,    31,    12,    13,
      50,   265,    35,    37,   194,    38,    56,    40,   257,    42,
      35,    40,    32,    40,    37,    40,   242,    37,    41,    37,
      31,    37,    37,    41,   271,    41,    41,   310,    40,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    37,
      18,   172,   173,    41,   234,    37,   236,   237,    39,    41,
     240,   240,   242,    49,    50,    31,   240,   247,   322,   323,
     324,   310,   316,    44,    37,   240,   256,   256,    41,    37,
     311,   246,    32,    41,    45,   265,   260,   331,   325,   326,
     329,   328,   346,    46,    37,   260,    36,    61,    41,    36,
      37,   355,   205,   206,   358,   359,    39,   361,    37,   211,
     212,   348,   349,    41,   368,    32,   370,   371,   207,   208,
     209,   210,   376,    87,    88,    89,   363,    41,   213,   214,
      32,    31,    81,    41,    40,    99,    41,    36,    41,    36,
      41,    79,   322,   323,   324,    31,   311,    24,    72,    81,
     256,    70,     0,   156,   246,     3,   110,   173,   199,   201,
     203,    -1,    -1,   202,    -1,    -1,   346,   204,    -1,    -1,
     134,    -1,    -1,    -1,    -1,   355,    -1,    -1,   358,   359,
      -1,   361,    30,    -1,    -1,    -1,    -1,    -1,   368,    -1,
     370,   371,    40,   157,    42,    -1,   376,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   168,    -1,    -1,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   199,    -1,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,    -1,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   239,    -1,    -1,    -1,    -1,
      -1,    -1,    30,    31,    -1,    33,    34,    -1,    -1,    -1,
      -1,    -1,    40,   257,    42,    -1,    -1,    -1,    46,   263,
      -1,    49,    50,    -1,    -1,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    -1,    -1,    76,    77,
      78,    -1,    80,    81,    82,    83,    84,    85,    86,    87,
      -1,    -1,    -1,    -1,    -1,    -1,   310,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   329,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    30,    31,    -1,    33,    34,    -1,
      -1,    -1,    -1,    -1,    40,    -1,    42,    -1,    -1,    -1,
      46,    -1,    -1,    49,    50,    -1,    -1,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    -1,    -1,
      76,    77,    78,    -1,    80,    81,    82,    83,    84,    85,
      86,    87,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      31,    -1,    33,    34,    -1,    -1,    -1,    -1,    -1,    40,
      -1,    42,    -1,    -1,    -1,    46,    -1,    -1,    49,    50,
      -1,    -1,    53,    54,    -1,    -1,    -1,    -1,    -1,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    76,    77,    78,    -1,    80,
      81,    82,    83,    84,    85,    86,    87,    31,    -1,    33,
      34,    -1,    -1,    -1,    -1,    -1,    40,    -1,    42,    -1,
      -1,    -1,    46,    -1,    -1,    49,    50,    -1,    -1,    53,
      54,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    76,    77,    78,    -1,    80,    81,    82,    83,
      84,    85,    86,    87,    31,    -1,    33,    -1,    -1,    -1,
      -1,    -1,    -1,    40,    -1,    42,    -1,    -1,    -1,    46,
      -1,    -1,    49,    50,    -1,    -1,    53,    54,    -1,    -1,
      -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    76,
      77,    78,    -1,    80,    81,    82,    83,    84,    85,    86,
      87,    30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    40,    -1,    42,    -1,    -1,    -1,    46,     3,    -1,
      49,    50,    -1,    -1,    53,    54,    -1,    -1,    -1,    -1,
      -1,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    30,    -1,    -1,    -1,    -1,
      35,    -1,    -1,    -1,    -1,    40,    41,    42,    -1,    -1,
      -1,    -1,     3,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    30,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    40,
      -1,    42,    -1,    -1,    -1,    -1,     3,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    30,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    41,    -1,    -1,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    -1,    -1,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    33,    34,    -1,
      -1,    -1,    -1,    -1,    40,    -1,    42,    -1,    -1,    -1,
      46,    -1,    -1,    49,    50,    -1,    -1,    53,    54,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    -1,    -1,
      -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    36,    -1,    -1,    -1,    40,    -1,    42,    -1,
      -1,    -1,    46,    -1,    33,    49,    50,    -1,    -1,    53,
      54,    40,    -1,    42,    -1,    -1,    -1,    46,    -1,    -1,
      49,    50,    -1,    -1,    53,    54,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    -1,    -1,    -1,    31,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    40,    -1,    42,    -1,    -1,    -1,    46,
      31,    -1,    49,    50,    -1,    -1,    53,    54,    -1,    40,
      -1,    42,    -1,    -1,    -1,    46,    -1,    -1,    49,    50,
      -1,    -1,    53,    54,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    40,    41,    42,    -1,    -1,    -1,    46,    -1,    -1,
      49,    50,    36,    -1,    53,    54,    40,    -1,    42,    -1,
      -1,    -1,    46,    -1,    -1,    49,    50,    -1,    -1,    53,
      54,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    -1,    -1,    -1,    -1,    31,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    40,    -1,
      42,    -1,    -1,    -1,    46,    -1,    -1,    49,    50,    36,
      -1,    53,    54,    40,    -1,    42,    -1,    -1,    -1,    46,
      -1,    -1,    49,    50,    -1,    -1,    53,    54,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    40,    41,    42,    -1,    -1,
      -1,    46,    31,    -1,    49,    50,    -1,    -1,    53,    54,
      -1,    40,    -1,    42,    -1,    -1,    -1,    46,    -1,    -1,
      49,    50,    -1,    -1,    53,    54,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    -1,    -1,    -1,    -1,    -1,
      -1,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    40,    41,    42,    -1,    -1,    -1,    46,
      -1,    -1,    49,    50,    -1,    -1,    53,    54,    40,    41,
      42,    -1,    -1,    -1,    46,    -1,    -1,    49,    50,    -1,
      -1,    53,    54,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      40,    41,    42,    -1,    -1,    -1,    46,    -1,    -1,    49,
      50,    -1,    -1,    53,    54,    40,    -1,    42,    -1,    -1,
      -1,    46,    -1,    -1,    49,    50,    -1,    -1,    53,    54,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    -1,
      -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    40,    -1,    42,
      -1,    -1,    -1,    46,    30,    -1,    49,    50,    -1,    -1,
      53,    54,    40,    -1,    42,    -1,    -1,    -1,    46,    -1,
      -1,    49,    50,    -1,    -1,    53,    54,    -1,    -1,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    30,
      -1,    -1,    -1,    -1,    35,    -1,    -1,    -1,    -1,    40,
      41,    42,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    30,    -1,    -1,    33,    -1,    -1,    -1,
      -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    30,    -1,    -1,    33,    -1,    -1,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    30,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    41,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    30,    -1,    -1,    -1,    -1,
      -1,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    30,
      -1,    -1,    -1,    34,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    30,    -1,    -1,    -1,    34,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    -1,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    30,    40,    42,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    92,    93,    94,    95,    97,    98,
      99,   100,   101,   102,   110,   113,   114,   115,   157,   113,
     100,   115,   116,    33,   157,     0,    93,    31,   104,   105,
     113,    97,    97,    97,    33,   157,    33,    95,    96,    97,
     129,    35,    40,   114,    41,   100,   115,   111,   112,   157,
      33,    31,    37,    39,    96,   129,    99,   100,   103,   106,
     107,    33,     4,     5,     6,     7,     8,     9,    10,    11,
      31,    34,    40,    42,    46,    49,    50,    53,    54,    76,
      77,    78,    80,    81,    82,    83,    84,    85,    86,    87,
      96,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   137,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   155,   156,   157,
      95,   129,   113,    36,   137,   138,   150,   157,    41,    97,
     117,   118,   119,   120,   157,    34,    37,    39,   111,   105,
      33,   121,   135,   129,   107,   107,    34,   106,    32,   108,
     109,   113,   103,    40,   150,    40,   150,   150,   107,   123,
     134,   138,    32,    40,    40,    40,   126,    40,   157,    31,
      31,    31,   134,    34,   130,    34,   126,    31,    37,    19,
      43,    18,    44,    45,    46,    16,    17,    14,    15,    47,
      48,    12,    13,    49,    50,    42,    51,    52,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    39,   136,
     149,    10,    11,    35,    38,    40,    42,    32,    36,    35,
      40,   113,   115,   124,   125,    41,    37,    37,    41,   112,
     138,    34,   121,   122,   138,    31,    37,    32,    34,   123,
      40,   115,   124,    41,    41,    32,   126,   134,   134,   134,
      81,    31,   134,    31,    31,    34,   135,   140,   134,   141,
     142,   143,   144,   145,   145,   146,   146,   146,   146,   147,
     147,   148,   148,   149,   149,   149,   135,   134,   157,    41,
     135,   154,   157,   126,    36,   138,    41,   117,   124,   125,
      35,    40,    74,   119,   157,    34,    37,   109,   138,    41,
     149,   126,    41,    41,    41,    40,    31,   134,    31,    32,
      36,    37,    41,    36,    41,    41,    36,   138,    41,   117,
      34,   121,   126,   126,   126,   134,    41,   134,    31,    31,
     134,   137,   135,    36,    41,    79,    41,   126,    41,    41,
     134,    41,   134,    31,   126,    31,   126,   126,    41,   126,
      41,    41,   134,   126,   126,   126,    41,   126
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
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
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


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
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
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
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
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
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



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
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
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

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
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

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

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
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
#line 52 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "translational_unit -> external_declaration" << std::endl;
            }
        ;}
    break;

  case 3:
#line 58 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "translational_unit -> translational_unit external_declaration" << std::endl;
            }
        ;}
    break;

  case 4:
#line 67 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "external_declaration -> function definition" << std::endl;
            }
        ;}
    break;

  case 5:
#line 73 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "external_declaration -> declaration" << std::endl;
            }
        ;}
    break;

  case 6:
#line 82 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "function_definition -> declarator compound_statment" << std::endl;
            }
        ;}
    break;

  case 7:
#line 88 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "function_defintion -> declarator declaration_list compound_statment" << std::endl;
            }
        ;}
    break;

  case 8:
#line 94 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "function_definition -> declaration_specifiers declarator compound_statement" << std::endl;
            }
        ;}
    break;

  case 9:
#line 100 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "function_definition -> declaration_specifiers declarator declaration_list compound_statment" << std::endl;
            }
        ;}
    break;

  case 10:
#line 109 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "declaration -> declaration_specifiers SEMI" << std::endl;
            }
        ;}
    break;

  case 11:
#line 115 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "declaration -> declaration_specifiers init_declarator_list SEMI" << std::endl;
            }
        ;}
    break;

  case 12:
#line 124 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "declaration_list -> declaration" << std::endl;
            }
        ;}
    break;

  case 13:
#line 130 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "declaration_list -> declaration list declaration" << std::endl;
            }
        ;}
    break;

  case 14:
#line 139 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "declaration_specifiers -> storage_class_specifier" << std::endl;
            }
        ;}
    break;

  case 15:
#line 145 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "declaration_specifiers -> storage_class_specifier declaration_specifiers" << std::endl;
            }
        ;}
    break;

  case 16:
#line 150 "C_grammar.y"
    {
        if (printProductions
    )
			{
                std::cout << "declaration_specifiers -> type_specifier" << std::endl;}
            ;}
    break;

  case 17:
#line 157 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "declaration_specifiers -> type_specifier declaration_specifiers" << std::endl;
            }
        ;}
    break;

  case 18:
#line 163 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "declaration_specifiers ->  type_qualifier" << std::endl;
            }
        ;}
    break;

  case 19:
#line 169 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "declaration_specifiers -> type_qualifier declaration_specifiers" << std::endl;
            }
        ;}
    break;

  case 20:
#line 178 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "storage_class_specifier -> AUTO" << std::endl;
            }
        ;}
    break;

  case 21:
#line 184 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "storage_class_specifier -> REGISTER" << std::endl;
            }
        ;}
    break;

  case 22:
#line 190 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "storage_class_specifier -> STATIC" << std::endl;
            }
        ;}
    break;

  case 23:
#line 196 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "storage_class_specifier -> EXTERN" << std::endl;
            }
        ;}
    break;

  case 24:
#line 202 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "storage_class_specifier -> TYPEDEF" << std::endl;
            }
        ;}
    break;

  case 25:
#line 211 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "type_specifier -> VOID" << std::endl;
            }
        ;}
    break;

  case 26:
#line 217 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "type_specifier -> CHAR" << std::endl;
            }
        ;}
    break;

  case 27:
#line 223 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "type_specifier -> SHORT" << std::endl;
            }
        ;}
    break;

  case 28:
#line 229 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "type_specifier -> INT" << std::endl;
            }
        ;}
    break;

  case 29:
#line 235 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "type_specifier -> LONG" << std::endl;
            }
        ;}
    break;

  case 30:
#line 241 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "type_specifier -> FLOAT" << std::endl;
            }
        ;}
    break;

  case 31:
#line 247 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "type_specifier -> DOUBLE" << std::endl;
            }
        ;}
    break;

  case 32:
#line 253 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "type_specifier -> SIGNED" << std::endl;
            }
        ;}
    break;

  case 33:
#line 259 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "type_specifier -> UNSIGNED" << std::endl;
            }
        ;}
    break;

  case 34:
#line 265 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "type_specifier -> struct_or_union_specifier" << std::endl;
            }
        ;}
    break;

  case 35:
#line 271 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "type_specifier -> enum_specifier" << std::endl;
            }
        ;}
    break;

  case 36:
#line 277 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "type_specifier ->TYPEDEF_NAME" << std::endl;
            }
        ;}
    break;

  case 37:
#line 286 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "type_qualifier -> CONST" << std::endl;
            }
        ;}
    break;

  case 38:
#line 292 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "type_qualifier -> VOLATILE" << std::endl;
            }
        ;}
    break;

  case 39:
#line 301 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "struct_or_union_specifier -> struct_or_union identifier CURLYOPEN struct_declaration_list CURLYCLOSE " << std::endl;
            }
        ;}
    break;

  case 40:
#line 307 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "struct_or_union_specifier -> struct_or_union CURLYOPEN struct_declaration_list CURLYCLOSE" << std::endl;
            }
        ;}
    break;

  case 41:
#line 313 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "struct_or_union_specifier -> struct_or_union identifier " << std::endl;
            }
        ;}
    break;

  case 42:
#line 322 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "struct_or_union -> STRUCT" << std::endl;
            }
        ;}
    break;

  case 43:
#line 328 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "struct_or_union -> UNION" << std::endl;
            }
        ;}
    break;

  case 44:
#line 337 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "struct_declaration_list -> struct_declaration" << std::endl;
            }
        ;}
    break;

  case 45:
#line 343 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "struct_declaration_list -> struct_declaration_list struct_declaration" << std::endl;
            }
        ;}
    break;

  case 46:
#line 352 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "init_declarator_list -> init_declarator" << std::endl;
            }
        ;}
    break;

  case 47:
#line 358 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "init_declarator_list -> init_declarator_list" << std::endl;
            }
        ;}
    break;

  case 48:
#line 367 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "init_declarator -> declarator" << std::endl;
            }
        ;}
    break;

  case 49:
#line 373 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "init_declarator -> declarator EQUALS initializer" << std::endl;
            }
        ;}
    break;

  case 50:
#line 382 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "struct_declaration -> specifier_qualifier_list struct_declarator_list SEMI" << std::endl;
            }
        ;}
    break;

  case 51:
#line 391 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "specifier_qualifier_list -> type_specifier" << std::endl;
            }
        ;}
    break;

  case 52:
#line 397 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "specifier_qualifier_list -> type_specifier specifier_qualifier_list" << std::endl;
            }
        ;}
    break;

  case 53:
#line 403 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "specifier_qualifier_list -> type_qualifier" << std::endl;
            }
        ;}
    break;

  case 54:
#line 409 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "specifier_qualifier_list -> type_qualifier specifier_qualifier_list" << std::endl;
            }
        ;}
    break;

  case 55:
#line 418 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "struct_declarator_list -> struct_declarator" << std::endl;
            }
        ;}
    break;

  case 56:
#line 424 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "struct_declarator_list -> struct_declarator_list COMMA struct_declarator" << std::endl;
            }
        ;}
    break;

  case 57:
#line 433 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "struct_declarator -> declarator" << std::endl;
            }
        ;}
    break;

  case 58:
#line 439 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "struct_declarator -> COLON constant_expression" << std::endl;
            }
        ;}
    break;

  case 59:
#line 445 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "struct_declarator -> declarator COLON constant_expression" << std::endl;
            }
        ;}
    break;

  case 60:
#line 454 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "enum_specifier -> ENUM CURLYOPEN enumerator_list CURLYCLOSE" << std::endl;
            }
        ;}
    break;

  case 61:
#line 460 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "enum_specifier -> ENUM identifier CURLYOPEN enumerator_list CURLYCLOSE" << std::endl;
            }
        ;}
    break;

  case 62:
#line 466 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "enum_specifier -> ENUM identifier" << std::endl;
            }
        ;}
    break;

  case 63:
#line 475 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "enumerator_list -> enumerator" << std::endl;
            }
        ;}
    break;

  case 64:
#line 481 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "enumerator_list -> enumerator_list COMMA enumerator" << std::endl;
            }
        ;}
    break;

  case 65:
#line 490 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "enumerator -> identifier" << std::endl;
            }
        ;}
    break;

  case 66:
#line 496 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "enumerator -> identifier EQUALS constant_expression" << std::endl;
            }
        ;}
    break;

  case 67:
#line 505 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "declarator -> direct_declarator" << std::endl;
            }
        ;}
    break;

  case 68:
#line 511 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "declarator -> pointer direct_declarator" << std::endl;
            }
        ;}
    break;

  case 69:
#line 520 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "direct_declarator -> identifier" << std::endl;
            }
        ;}
    break;

  case 70:
#line 526 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "direct_declarator -> OPEN declarator CLOSE" << std::endl;
            }
        ;}
    break;

  case 71:
#line 532 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "direct_declarator -> direct_declarator BRACKETOPEN BRACKETCLOSE" << std::endl;
            }
        ;}
    break;

  case 72:
#line 538 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "direct_declarator -> direct_declarator BRACKETOPEN constant_expression BRACKETCLOSE" << std::endl;
            }
        ;}
    break;

  case 73:
#line 544 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "direct_declarator -> direct_declarator OPEN CLOSE" << std::endl;
            }
        ;}
    break;

  case 74:
#line 550 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "direct_declarator -> direct_declarator OPEN parameter_type_list CLOSE" << std::endl;
            }
        ;}
    break;

  case 75:
#line 556 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "direct_declarator ->  direct_declarator OPEN identifier_list CLOSE" << std::endl;
            }
        ;}
    break;

  case 76:
#line 565 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "pointer -> STAR" << std::endl;
            }
        ;}
    break;

  case 77:
#line 571 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "pointer -> STAR type_qualifier_list" << std::endl;
            }
        ;}
    break;

  case 78:
#line 577 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "pointer -> STAR pointer" << std::endl;
            }
        ;}
    break;

  case 79:
#line 583 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "pointer -> STAR type_qualifier_list pointer" << std::endl;
            }
        ;}
    break;

  case 80:
#line 592 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "type_qualifier_list -> type_qualifier" << std::endl;
            }
        ;}
    break;

  case 81:
#line 598 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "type_qualifier_list -> type_qualifier_list type_qualifier" << std::endl;
            }
        ;}
    break;

  case 82:
#line 607 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "parameter_type_list -> parameter_list" << std::endl;
            }
        ;}
    break;

  case 83:
#line 613 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "parameter_type_list -> parameter_list COMMA ELIPSIS" << std::endl;
            }
        ;}
    break;

  case 84:
#line 622 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "parameter_list -> parameter_declaration" << std::endl;
            }
        ;}
    break;

  case 85:
#line 628 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "parameter_list -> parameter_list COMMA parameter_declaration" << std::endl;
            }
        ;}
    break;

  case 86:
#line 637 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "parameter_declaration -> declaration_specifiers declarator" << std::endl;
            }
        ;}
    break;

  case 87:
#line 643 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "parameter_declaration -> declaration_specifiers" << std::endl;
            }
        ;}
    break;

  case 88:
#line 649 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "parameter_declaration -> declaration_specifiers abstract_declarator" << std::endl;
            }
        ;}
    break;

  case 89:
#line 658 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "identifier_list -> identifier" << std::endl;
            }
        ;}
    break;

  case 90:
#line 664 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "identifier_list -> identifier_list COMMA identifier" << std::endl;
            }
        ;}
    break;

  case 91:
#line 673 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "initializer -> assignment_expression" << std::endl;
            }
        ;}
    break;

  case 92:
#line 679 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "initializer -> CURLYOPEN initializer_list CURLYCLOSE" << std::endl;
            }
        ;}
    break;

  case 93:
#line 685 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "initializer -> CURLYOPEN initializer_list COMMA CURLYCLOSE" << std::endl;
            }
        ;}
    break;

  case 94:
#line 694 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "initializer_list -> initializer" << std::endl;
            }
        ;}
    break;

  case 95:
#line 700 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "initializer_list -> initializer_list COMMA initializer" << std::endl;
            }
        ;}
    break;

  case 96:
#line 709 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "type_name -> specifier_qualifier_list" << std::endl;
            }
        ;}
    break;

  case 97:
#line 715 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "type_name -> specifier_qualifier_list abstract_declarator" << std::endl;
            }
        ;}
    break;

  case 98:
#line 724 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "abstract_declarator -> pointer" << std::endl;
            }
        ;}
    break;

  case 99:
#line 730 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "abstract_declarator -> direct_abstract_declarator" << std::endl;
            }
        ;}
    break;

  case 100:
#line 736 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "abstract_declarator -> pointer direct_abstract_declarator" << std::endl;
            }
        ;}
    break;

  case 101:
#line 745 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "direct_abstract_declarator -> OPEN abstract_declarator CLOSE" << std::endl;
            }
        ;}
    break;

  case 102:
#line 751 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "direct_abstract_declarator -> BRACKETOPEN BRACKETCLOSE" << std::endl;
            }
        ;}
    break;

  case 103:
#line 757 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "direct_abstract_declarator -> BRACKETOPEN constant_expression BRACKETCLOSE" << std::endl;
            }
        ;}
    break;

  case 104:
#line 763 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "direct_abstract_declarator -> direct_abstract_declarator BRACKETOPEN BRACKETCLOSE" << std::endl;
            }
        ;}
    break;

  case 105:
#line 769 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "direct_abstract_declarator -> direct_abstract_declarator BRACKETOPEN constant_expression BRACKETCLOSE" << std::endl;
            }
        ;}
    break;

  case 106:
#line 775 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "direct_abstract_declarator -> OPEN CLOSE" << std::endl;
            }
        ;}
    break;

  case 107:
#line 781 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "direct_abstract_declarator -> OPEN parameter_type_list CLOSE" << std::endl;
            }
        ;}
    break;

  case 108:
#line 787 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "direct_abstract_declarator -> direct_abstract_declarator OPEN CLOSE" << std::endl;
            }
        ;}
    break;

  case 109:
#line 793 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "direct_abstract_declarator -> direct_abstract_declarator OPEN parameter_type_list CLOSE" << std::endl;
            }
        ;}
    break;

  case 110:
#line 802 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "statement -> labeled_statement" << std::endl;
            }
        ;}
    break;

  case 111:
#line 808 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "statement -> compound_statement" << std::endl;
            }
        ;}
    break;

  case 112:
#line 814 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "statement -> expression_statement" << std::endl;
            }
        ;}
    break;

  case 113:
#line 820 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "statement -> selection_statement" << std::endl;
            }
        ;}
    break;

  case 114:
#line 826 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "statement -> iteration_statement" << std::endl;
            }
        ;}
    break;

  case 115:
#line 832 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "statement -> jump_statement" << std::endl;
            }
        ;}
    break;

  case 116:
#line 841 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "labeled_statement -> identifier COLON statement" << std::endl;
            }
        ;}
    break;

  case 117:
#line 847 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "labeled_statement -> CASE constant_expression COLON statement" << std::endl;
            }
        ;}
    break;

  case 118:
#line 853 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "labeled_statement -> DEFAULT COLON statement" << std::endl;
            }
        ;}
    break;

  case 119:
#line 862 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "expression_statement -> SEMI" << std::endl;
            }
        ;}
    break;

  case 120:
#line 868 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "expression_statement -> expression SEMI" << std::endl;
            }
        ;}
    break;

  case 121:
#line 877 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "compound_statement -> CURLYOPEN CURLYCLOSE" << std::endl;
            }
        ;}
    break;

  case 122:
#line 883 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "compound_statement -> CURLYOPEN statement_list CURLYCLOSE" << std::endl;
            }
        ;}
    break;

  case 123:
#line 889 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "compound_statement -> CURLYOPEN declaration_list CURLYCLOSE" << std::endl;
            }
        ;}
    break;

  case 124:
#line 895 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "compound_statement -> CURLYOPEN declaration_list statement_list CURLYCLOSE" << std::endl;
            }
        ;}
    break;

  case 125:
#line 904 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "statement_list -> statement" << std::endl;
            }
        ;}
    break;

  case 126:
#line 910 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "statement_list -> statement_list statement" << std::endl;
            }
        ;}
    break;

  case 127:
#line 919 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "selection_statement -> IF OPEN expression CLOSE statement" << std::endl;
            }
        ;}
    break;

  case 128:
#line 925 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "selection_statement -> IF OPEN expression CLOSE statement ELSE statement" << std::endl;
            }
        ;}
    break;

  case 129:
#line 931 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "selection_statement -> SWITCH OPEN expression CLOSE statement" << std::endl;
            }
        ;}
    break;

  case 130:
#line 940 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "iteration_statement -> WHILE OPEN expression CLOSE statement" << std::endl;
            }
        ;}
    break;

  case 131:
#line 946 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "iteration_statement -> DO statement WHILE OPEN expression CLOSE SEMI" << std::endl;
            }
        ;}
    break;

  case 132:
#line 952 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "iteration_statement -> FOR OPEN SEMI SEMI CLOSE statement" << std::endl;
            }
        ;}
    break;

  case 133:
#line 958 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "iteration_statement -> FOR OPEN SEMI SEMI expression CLOSE statement" << std::endl;
            }
        ;}
    break;

  case 134:
#line 964 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "iteration_statement -> FOR OPEN SEMI expression SEMI CLOSE statement" << std::endl;
            }
        ;}
    break;

  case 135:
#line 970 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "iteration_statement -> FOR OPEN SEMI expression SEMI expression CLOSE statement" << std::endl;
            }
        ;}
    break;

  case 136:
#line 976 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "iteration_statement -> FOR OPEN expression SEMI SEMI CLOSE statement" << std::endl;
            }
        ;}
    break;

  case 137:
#line 982 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "iteration_statement -> FOR OPEN expression SEMI SEMI expression CLOSE statement" << std::endl;
            }
        ;}
    break;

  case 138:
#line 988 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "iteration_statement -> FOR OPEN expression SEMI expression SEMI CLOSE statement" << std::endl;
            }
        ;}
    break;

  case 139:
#line 994 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "iteration_statement -> FOR OPEN expression SEMI expression SEMI expression CLOSE statement" << std::endl;
            }
        ;}
    break;

  case 140:
#line 1003 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "jump_statement -> GOTO identifier SEMI" << std::endl;
            }
        ;}
    break;

  case 141:
#line 1009 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "jump_statement -> CONTINUE SEMI" << std::endl;
            }
        ;}
    break;

  case 142:
#line 1015 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "jump_statement -> BREAK SEMI" << std::endl;
            }
        ;}
    break;

  case 143:
#line 1021 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "jump_statement -> RETURN SEMI" << std::endl;
            }
        ;}
    break;

  case 144:
#line 1027 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "jump_statement -> RETURN expression SEMI" << std::endl;
            }
        ;}
    break;

  case 145:
#line 1036 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "expression -> assignment_expression" << std::endl;
            }
        ;}
    break;

  case 146:
#line 1042 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "expression -> expression COMMA assignment_expression" << std::endl;
            }
        ;}
    break;

  case 147:
#line 1051 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "assignment_expression -> conditional_expression" << std::endl;
            }
        ;}
    break;

  case 148:
#line 1057 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "assignment_expression -> unary_expression assignment_operator assignment_expression" << std::endl;
            }
        ;}
    break;

  case 149:
#line 1066 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "assignment_operator -> EQUALS" << std::endl;
            }
        ;}
    break;

  case 150:
#line 1072 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "assignment_operator -> MUL_ASSIGN" << std::endl;
            }
        ;}
    break;

  case 151:
#line 1078 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "assignment_operator -> DIV_ASSIGN" << std::endl;
            }
        ;}
    break;

  case 152:
#line 1084 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "assignment_operator -> MOD_ASSIGN" << std::endl;
            }
        ;}
    break;

  case 153:
#line 1090 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "assignment_operator -> ADD_ASSIGN" << std::endl;
            }
        ;}
    break;

  case 154:
#line 1096 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "assignment_operator -> SUB_ASSIGN" << std::endl;
            }
        ;}
    break;

  case 155:
#line 1102 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "assignment_operator -> LEFT_ASSIGN" << std::endl;
            }
        ;}
    break;

  case 156:
#line 1108 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "assignment_operator -> RIGHT_ASSIGN" << std::endl;
            }
        ;}
    break;

  case 157:
#line 1114 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "assignment_operator -> AND_ASSIGN" << std::endl;
            }
        ;}
    break;

  case 158:
#line 1120 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "assignment_operator -> XOR_ASSIGN" << std::endl;
            }
        ;}
    break;

  case 159:
#line 1126 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "assignment_operator -> OR_ASSIGN" << std::endl;
            }
        ;}
    break;

  case 160:
#line 1135 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "conditional_expression -> logical_or_expression" << std::endl;
            }
        ;}
    break;

  case 161:
#line 1141 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "conditional_expression -> logical_or_expression QUESTION expression COLON conditional_expression" << std::endl;
            }
        ;}
    break;

  case 162:
#line 1150 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "constant_expression -> conditional_expression" << std::endl;
            }
        ;}
    break;

  case 163:
#line 1159 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "logical_or_expression -> logical_and_expression" << std::endl;
            }
        ;}
    break;

  case 164:
#line 1165 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "logical_or_expression -> logical_or_expression OR_OP logical_and_expression" << std::endl;
            }
        ;}
    break;

  case 165:
#line 1174 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "logical_and_expression -> inclusive_or_expression" << std::endl;
            }
        ;}
    break;

  case 166:
#line 1180 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "logical_and_expression -> logical_and_expression AND_OP inclusive_or_expression" << std::endl;
            }
        ;}
    break;

  case 167:
#line 1189 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "inclusive_or_expression -> exclusive_or_expression" << std::endl;
            }
        ;}
    break;

  case 168:
#line 1195 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "inclusive_or_expression -> inclusive_or_expression BAR exclusive_or_expression" << std::endl;
            }
        ;}
    break;

  case 169:
#line 1204 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "exclusive_or_expression -> and_expression" << std::endl;
            }
        ;}
    break;

  case 170:
#line 1210 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "exclusive_or_expression -> exclusive_or_expression CARROT and_expression" << std::endl;
            }
        ;}
    break;

  case 171:
#line 1219 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "and_expression -> equality_expression" << std::endl;
            }
        ;}
    break;

  case 172:
#line 1225 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "and_expression -> and_expression AMP equality_expression" << std::endl;
            }
        ;}
    break;

  case 173:
#line 1234 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "equality_expression -> relational_expression" << std::endl;
            }
        ;}
    break;

  case 174:
#line 1240 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "equality_expression -> equality_expression EQ_OP relational_expression" << std::endl;
            }
        ;}
    break;

  case 175:
#line 1246 "C_grammar.y"
    {
			if (printProductions) {
				std::cout << "equality_expression -> equality_expression NE_OP relational_expression" << std::endl;
			}
		;}
    break;

  case 176:
#line 1255 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "relational_expression -> shift_expression" << std::endl;
            }
        ;}
    break;

  case 177:
#line 1261 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "relational_expression -> relational_expression LESS_OP shift_expression" << std::endl;
            }
        ;}
    break;

  case 178:
#line 1267 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "relational_expression -> relational_expression GREAT_OP shift_expression" << std::endl;
            }
        ;}
    break;

  case 179:
#line 1273 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "relational_expression -> relational_expression LE_OP shift_expression" << std::endl;
            }
        ;}
    break;

  case 180:
#line 1279 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "relational_expression -> relational_expression GE_OP shift_expression" << std::endl;
            }
        ;}
    break;

  case 181:
#line 1288 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "shift_expression -> additive_expression" << std::endl;
            }
        ;}
    break;

  case 182:
#line 1294 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "shift_expression -> shift_expression LEFT_OP additive_expression" << std::endl;
            }
        ;}
    break;

  case 183:
#line 1300 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "shift_expression -> shift_expression RIGHT_OP additive_expression" << std::endl;
            }
        ;}
    break;

  case 184:
#line 1309 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "additive_expression -> multiplicative_expression" << std::endl;
            }
        ;}
    break;

  case 185:
#line 1315 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "additive_expression -> additive_expression PLUS multiplicative_expression" << std::endl;
            }
        ;}
    break;

  case 186:
#line 1321 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "additive_expression -> additive_expression MINUS multiplicative_expression" << std::endl;
            }
        ;}
    break;

  case 187:
#line 1330 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "multiplicative_expression -> cast_expression" << std::endl;
            }
        ;}
    break;

  case 188:
#line 1336 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "multiplicative_expression -> multiplicative_expression STAR cast_expression" << std::endl;
            }
        ;}
    break;

  case 189:
#line 1342 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "multiplicative_expression -> multiplicative_expression FORSLASH cast_expression" << std::endl;
            }
        ;}
    break;

  case 190:
#line 1348 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "multiplicative_expression -> multiplicative_expression PERCENT cast_expression" << std::endl;
            }
        ;}
    break;

  case 191:
#line 1357 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "cast_expression -> unary_expression" << std::endl;
            }
        ;}
    break;

  case 192:
#line 1363 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "cast_expression -> OPEN type_name CLOSE cast_expression" << std::endl;
            }
        ;}
    break;

  case 193:
#line 1372 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "unary_expression -> postfix_expression" << std::endl;
            }
        ;}
    break;

  case 194:
#line 1378 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "unary_expression -> INC_OP unary_expression" << std::endl;
            }
        ;}
    break;

  case 195:
#line 1384 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "unary_expression -> DEC_OP unary_expression" << std::endl;
            }
        ;}
    break;

  case 196:
#line 1390 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "unary_expression -> unary_operator cast_expression" << std::endl;
            }
        ;}
    break;

  case 197:
#line 1396 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "unary_expression -> SIZEOF unary_expression" << std::endl;
            }
        ;}
    break;

  case 198:
#line 1402 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "unary_expression -> SIZEOF OPEN type_name CLOSE" << std::endl;
            }
        ;}
    break;

  case 199:
#line 1411 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "unary_operator -> AMP" << std::endl;
            }
        ;}
    break;

  case 200:
#line 1417 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "unary_operator -> STAR" << std::endl;
            }
        ;}
    break;

  case 201:
#line 1423 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "unary_operator -> PLUS" << std::endl;
            }
        ;}
    break;

  case 202:
#line 1429 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "unary_operator -> MINUS" << std::endl;
            }
        ;}
    break;

  case 203:
#line 1435 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "unary_operator -> TILDA" << std::endl;
            }
        ;}
    break;

  case 204:
#line 1441 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "unary_operator -> BANG" << std::endl;
            }
        ;}
    break;

  case 205:
#line 1450 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "postfix_expression -> primary_expression" << std::endl;
            }
        ;}
    break;

  case 206:
#line 1456 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "postfix_expression -> postfix_expression BRACKETOPEN expression BRACKETCLOSE" << std::endl;
            }
        ;}
    break;

  case 207:
#line 1462 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "postfix_expression -> postfix_expression OPEN CLOSE" << std::endl;
            }
        ;}
    break;

  case 208:
#line 1468 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "postfix_expression -> postfix_expression OPEN argument_expression_list CLOSE" << std::endl;
            }
        ;}
    break;

  case 209:
#line 1474 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "postfix_expression -> postfix_expression PERIOD identifier" << std::endl;
            }
        ;}
    break;

  case 210:
#line 1480 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "postfix_expression -> postfix_expression STAR identifier" << std::endl;
            }
        ;}
    break;

  case 211:
#line 1486 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "postfix_expression -> postfix_expression INC_OP" << std::endl;
            }
        ;}
    break;

  case 212:
#line 1492 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "postfix_expression -> postfix_expression DEC_OP" << std::endl;
            }
        ;}
    break;

  case 213:
#line 1501 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "primary_expression -> identifier" << std::endl;
            }
        ;}
    break;

  case 214:
#line 1507 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "primary_expression -> constant" << std::endl;
            }
        ;}
    break;

  case 215:
#line 1513 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "primary_expression -> string" << std::endl;
            }
        ;}
    break;

  case 216:
#line 1519 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "primary_expression -> OPEN expression CLOSE" << std::endl;
            }
        ;}
    break;

  case 217:
#line 1528 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "argument_expression_list -> assignment_expression" << std::endl;
            }
        ;}
    break;

  case 218:
#line 1534 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "argument_expression_list -> argument_expression_list COMMA assignment_expression" << std::endl;
            }
        ;}
    break;

  case 219:
#line 1543 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "constant -> INTEGER_CONSTANT" << std::endl;
            }
        ;}
    break;

  case 220:
#line 1549 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "constant -> CHARACTER_CONSTANT" << std::endl;
            }
        ;}
    break;

  case 221:
#line 1555 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "constant -> FLOATING_CONSTANT" << std::endl;
            }
        ;}
    break;

  case 222:
#line 1561 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "constant -> ENUMERATION_CONSTANT" << std::endl;
            }
        ;}
    break;

  case 223:
#line 1570 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "string -> STRING_LITERAL" << std::endl;
            }
        ;}
    break;

  case 224:
#line 1579 "C_grammar.y"
    {
            if (printProductions) {
                std::cout << "identifier -> IDENTIFIER" << std::endl;
            }
        ;}
    break;


/* Line 1267 of yacc.c.  */
#line 4194 "C_grammar.tab.c"
      default: break;
    }
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
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
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
      if (yyn != YYPACT_NINF)
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

  if (yyn == YYFINAL)
    YYACCEPT;

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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
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


#line 1585 "C_grammar.y"

extern int column;

int main (int argc, char** argv)
{
    std::string tokenFlag = "-dl";
	std::string symbolFlag = "-ds";
	std::string fhFlag = "-fh";
	std::string productionFlag = "-p";
    std::string inputFlag = "-i";
    std::string outputFlag = "-o";
    extern std::string srcFile;
    extern std::string outSrcFile;
    extern std::string buffer;

    // Check command line args for debug symbols
    for (int i = 0; i < argc; i++) {
        if((tokenFlag.compare(argv[i])) == 0)
        {
            printToken = true;
        }
        if((symbolFlag.compare(argv[i])) == 0)
        {
            // Dump the symbol table
        }
        if((fhFlag.compare(argv[i])) == 0)
        {
            // RELEASE THE FH
        }
		if ((productionFlag.compare(argv[i])) == 0)
		{
			printProductions = true;
		}
        if ((inputFlag.compare(argv[i]))==0)
        {
            if (i+1 < argc)
                srcFile = argv[++i];
            else
            {
                std::cout << "ERROR: PLEASE SPECIFIY A SRC CODE FILE AFTER -i" << std::endl;
                return 0;
            }
        }
        if ((outputFlag.compare(argv[i]))==0)
        {
            if (i+1 < argc)
            {
                outSrcFile = argv[++i];
            }
            else
            {
                std::cout << "ERROR: PLEASE SPECIFIY A SRC CODE FILE AFTER -o" << std::endl;
                return 0;
            }
        }
    }
    std::ofstream fileP(outSrcFile);
    fileP << "";
    fileP.close();
	yyparse();
    return 0;
}

