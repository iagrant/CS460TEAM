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
     PTR_OP = 265,
     INC_OP = 266,
     DEC_OP = 267,
     LEFT_OP = 268,
     RIGHT_OP = 269,
     LE_OP = 270,
     GE_OP = 271,
     EQ_OP = 272,
     NE_OP = 273,
     AND_OP = 274,
     OR_OP = 275,
     MUL_ASSIGN = 276,
     DIV_ASSIGN = 277,
     MOD_ASSIGN = 278,
     ADD_ASSIGN = 279,
     SUB_ASSIGN = 280,
     LEFT_ASSIGN = 281,
     RIGHT_ASSIGN = 282,
     AND_ASSIGN = 283,
     XOR_ASSIGN = 284,
     OR_ASSIGN = 285,
     TYPEDEF_NAME = 286,
     SEMI = 287,
     COLON = 288,
     CURLYOPEN = 289,
     CURLYCLOSE = 290,
     BRACKETOPEN = 291,
     BRACKETCLOSE = 292,
     COMMA = 293,
     PERIOD = 294,
     EQUALS = 295,
     OPEN = 296,
     CLOSE = 297,
     STAR = 298,
     QUESTION = 299,
     BAR = 300,
     CARROT = 301,
     AMP = 302,
     LESS_OP = 303,
     GREAT_OP = 304,
     PLUS = 305,
     MINUS = 306,
     FORSLASH = 307,
     PERCENT = 308,
     BANG = 309,
     TILDA = 310,
     TYPEDEF = 311,
     EXTERN = 312,
     STATIC = 313,
     AUTO = 314,
     REGISTER = 315,
     CHAR = 316,
     SHORT = 317,
     INT = 318,
     LONG = 319,
     SIGNED = 320,
     UNSIGNED = 321,
     FLOAT = 322,
     DOUBLE = 323,
     CONST = 324,
     VOLATILE = 325,
     VOID = 326,
     STRUCT = 327,
     UNION = 328,
     ENUM = 329,
     ELIPSIS = 330,
     RANGE = 331,
     CASE = 332,
     DEFAULT = 333,
     IF = 334,
     ELSE = 335,
     SWITCH = 336,
     WHILE = 337,
     DO = 338,
     FOR = 339,
     GOTO = 340,
     CONTINUE = 341,
     BREAK = 342,
     RETURN = 343
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
#define PTR_OP 265
#define INC_OP 266
#define DEC_OP 267
#define LEFT_OP 268
#define RIGHT_OP 269
#define LE_OP 270
#define GE_OP 271
#define EQ_OP 272
#define NE_OP 273
#define AND_OP 274
#define OR_OP 275
#define MUL_ASSIGN 276
#define DIV_ASSIGN 277
#define MOD_ASSIGN 278
#define ADD_ASSIGN 279
#define SUB_ASSIGN 280
#define LEFT_ASSIGN 281
#define RIGHT_ASSIGN 282
#define AND_ASSIGN 283
#define XOR_ASSIGN 284
#define OR_ASSIGN 285
#define TYPEDEF_NAME 286
#define SEMI 287
#define COLON 288
#define CURLYOPEN 289
#define CURLYCLOSE 290
#define BRACKETOPEN 291
#define BRACKETCLOSE 292
#define COMMA 293
#define PERIOD 294
#define EQUALS 295
#define OPEN 296
#define CLOSE 297
#define STAR 298
#define QUESTION 299
#define BAR 300
#define CARROT 301
#define AMP 302
#define LESS_OP 303
#define GREAT_OP 304
#define PLUS 305
#define MINUS 306
#define FORSLASH 307
#define PERCENT 308
#define BANG 309
#define TILDA 310
#define TYPEDEF 311
#define EXTERN 312
#define STATIC 313
#define AUTO 314
#define REGISTER 315
#define CHAR 316
#define SHORT 317
#define INT 318
#define LONG 319
#define SIGNED 320
#define UNSIGNED 321
#define FLOAT 322
#define DOUBLE 323
#define CONST 324
#define VOLATILE 325
#define VOID 326
#define STRUCT 327
#define UNION 328
#define ENUM 329
#define ELIPSIS 330
#define RANGE 331
#define CASE 332
#define DEFAULT 333
#define IF 334
#define ELSE 335
#define SWITCH 336
#define WHILE 337
#define DO 338
#define FOR 339
#define GOTO 340
#define CONTINUE 341
#define BREAK 342
#define RETURN 343




/* Copy the first part of user declarations.  */
#line 1 "C_grammar.y"

  #include <stdio.h> 
  #include <string.h>  
  #include <bool.h>

  extern bool printProductions = true; 


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
#line 9 "C_grammar.y"
{
  int ival;
  char cval;
  string sval;
  double dval;
  float fval;
}
/* Line 193 of yacc.c.  */
#line 288 "C_grammar.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 301 "C_grammar.tab.c"

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
#define YYLAST   1821

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  89
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  67
/* YYNRULES -- Number of rules.  */
#define YYNRULES  224
/* YYNRULES -- Number of states.  */
#define YYNSTATES  378

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   343

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
      85,    86,    87,    88
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
      90,     0,    -1,    91,    -1,    90,    91,    -1,    92,    -1,
      93,    -1,   111,   127,    -1,   111,    94,   127,    -1,    95,
     111,   127,    -1,    95,   111,    94,   127,    -1,    95,    32,
      -1,    95,   102,    32,    -1,    93,    -1,    94,    93,    -1,
      96,    -1,    96,    95,    -1,    97,    -1,    97,    95,    -1,
      98,    -1,    98,    95,    -1,    59,    -1,    60,    -1,    58,
      -1,    57,    -1,    56,    -1,    71,    -1,    61,    -1,    62,
      -1,    63,    -1,    64,    -1,    67,    -1,    68,    -1,    65,
      -1,    66,    -1,    99,    -1,   108,    -1,    31,    -1,    69,
      -1,    70,    -1,   100,   155,    34,   101,    35,    -1,   100,
      34,   101,    35,    -1,   100,   155,    -1,    72,    -1,    73,
      -1,   104,    -1,   101,   104,    -1,   103,    -1,   102,    38,
     103,    -1,   111,    -1,   111,    40,   119,    -1,   105,   106,
      32,    -1,    97,    -1,    97,   105,    -1,    98,    -1,    98,
     105,    -1,   107,    -1,   106,    38,   107,    -1,   111,    -1,
      33,   136,    -1,   111,    33,   136,    -1,    74,    34,   109,
      35,    -1,    74,   155,    34,   109,    35,    -1,    74,   155,
      -1,   110,    -1,   109,    38,   110,    -1,   155,    -1,   155,
      40,   136,    -1,   112,    -1,   113,   112,    -1,   155,    -1,
      41,   111,    42,    -1,   112,    36,    37,    -1,   112,    36,
     136,    37,    -1,   112,    41,    42,    -1,   112,    41,   115,
      42,    -1,   112,    41,   118,    42,    -1,    43,    -1,    43,
     114,    -1,    43,   113,    -1,    43,   114,   113,    -1,    98,
      -1,   114,    98,    -1,   116,    -1,   116,    38,    75,    -1,
     117,    -1,   116,    38,   117,    -1,    95,   111,    -1,    95,
      -1,    95,   122,    -1,   155,    -1,   118,    38,   155,    -1,
     133,    -1,    34,   120,    35,    -1,    34,   120,    38,    35,
      -1,   119,    -1,   120,    38,   119,    -1,   105,    -1,   105,
     122,    -1,   113,    -1,   123,    -1,   113,   123,    -1,    41,
     122,    42,    -1,    36,    37,    -1,    36,   136,    37,    -1,
     123,    36,    37,    -1,   123,    36,   136,    37,    -1,    41,
      42,    -1,    41,   115,    42,    -1,   123,    41,    42,    -1,
     123,    41,   115,    42,    -1,   125,    -1,   127,    -1,   126,
      -1,   129,    -1,   130,    -1,   131,    -1,   155,    33,   124,
      -1,    77,   136,    33,   124,    -1,    78,    33,   124,    -1,
      32,    -1,   132,    32,    -1,    34,    35,    -1,    34,   128,
      35,    -1,    34,    94,    35,    -1,    34,    94,   128,    35,
      -1,   124,    -1,   128,   124,    -1,    79,    41,   132,    42,
     124,    -1,    79,    41,   132,    42,   124,    80,   124,    -1,
      81,    41,   132,    42,   124,    -1,    82,    41,   132,    42,
     124,    -1,    83,   124,    82,    41,   132,    42,    32,    -1,
      84,    41,    32,    32,    42,   124,    -1,    84,    41,    32,
      32,   132,    42,   124,    -1,    84,    41,    32,   132,    32,
      42,   124,    -1,    84,    41,    32,   132,    32,   132,    42,
     124,    -1,    84,    41,   132,    32,    32,    42,   124,    -1,
      84,    41,   132,    32,    32,   132,    42,   124,    -1,    84,
      41,   132,    32,   132,    32,    42,   124,    -1,    84,    41,
     132,    32,   132,    32,   132,    42,   124,    -1,    85,   155,
      32,    -1,    86,    32,    -1,    87,    32,    -1,    88,    32,
      -1,    88,   132,    32,    -1,   133,    -1,   132,    38,   133,
      -1,   135,    -1,   148,   134,   133,    -1,    40,    -1,    21,
      -1,    22,    -1,    23,    -1,    24,    -1,    25,    -1,    26,
      -1,    27,    -1,    28,    -1,    29,    -1,    30,    -1,   137,
      -1,   137,    44,   132,    33,   135,    -1,   135,    -1,   138,
      -1,   137,    20,   138,    -1,   139,    -1,   138,    19,   139,
      -1,   140,    -1,   139,    45,   140,    -1,   141,    -1,   140,
      46,   141,    -1,   142,    -1,   141,    47,   142,    -1,   143,
      -1,   142,    17,   143,    -1,   142,    18,   143,    -1,   144,
      -1,   143,    48,   144,    -1,   143,    49,   144,    -1,   143,
      15,   144,    -1,   143,    16,   144,    -1,   145,    -1,   144,
      13,   145,    -1,   144,    14,   145,    -1,   146,    -1,   145,
      50,   146,    -1,   145,    51,   146,    -1,   147,    -1,   146,
      43,   147,    -1,   146,    52,   147,    -1,   146,    53,   147,
      -1,   148,    -1,    41,   121,    42,   147,    -1,   150,    -1,
      11,   148,    -1,    12,   148,    -1,   149,   147,    -1,     9,
     148,    -1,     9,    41,   121,    42,    -1,    47,    -1,    43,
      -1,    50,    -1,    51,    -1,    55,    -1,    54,    -1,   151,
      -1,   150,    36,   132,    37,    -1,   150,    41,    42,    -1,
     150,    41,   152,    42,    -1,   150,    39,   155,    -1,   150,
      10,   155,    -1,   150,    11,    -1,   150,    12,    -1,   155,
      -1,   153,    -1,   154,    -1,    41,   132,    42,    -1,   133,
      -1,   152,    38,   133,    -1,     4,    -1,     6,    -1,     5,
      -1,     7,    -1,     8,    -1,     3,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    44,    44,    45,    49,    50,    54,    55,    56,    57,
      61,    62,    66,    67,    71,    72,    73,    74,    75,    76,
      80,    81,    82,    83,    84,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   103,   104,   108,
     109,   110,   114,   115,   119,   120,   124,   125,   129,   130,
     134,   138,   139,   140,   141,   145,   146,   150,   151,   152,
     156,   157,   158,   162,   163,   167,   168,   172,   173,   177,
     178,   179,   180,   181,   182,   183,   187,   188,   189,   190,
     194,   195,   199,   200,   204,   205,   209,   210,   211,   215,
     216,   220,   221,   222,   226,   227,   231,   232,   236,   237,
     238,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     254,   255,   256,   257,   258,   259,   263,   264,   265,   269,
     270,   274,   275,   276,   277,   281,   282,   286,   287,   288,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     305,   306,   307,   308,   309,   313,   314,   318,   319,   323,
     324,   325,   326,   327,   328,   329,   330,   331,   332,   333,
     337,   338,   342,   346,   347,   351,   352,   356,   357,   361,
     362,   366,   367,   371,   372,   373,   377,   378,   379,   380,
     381,   385,   386,   387,   391,   392,   393,   397,   398,   399,
     400,   404,   405,   409,   410,   411,   412,   413,   414,   418,
     419,   420,   421,   422,   423,   427,   428,   429,   430,   431,
     432,   433,   434,   438,   439,   440,   441,   445,   446,   450,
     451,   452,   453,   457,   461
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFIER", "INTEGER_CONSTANT",
  "FLOATING_CONSTANT", "CHARACTER_CONSTANT", "ENUMERATION_CONSTANT",
  "STRING_LITERAL", "SIZEOF", "PTR_OP", "INC_OP", "DEC_OP", "LEFT_OP",
  "RIGHT_OP", "LE_OP", "GE_OP", "EQ_OP", "NE_OP", "AND_OP", "OR_OP",
  "MUL_ASSIGN", "DIV_ASSIGN", "MOD_ASSIGN", "ADD_ASSIGN", "SUB_ASSIGN",
  "LEFT_ASSIGN", "RIGHT_ASSIGN", "AND_ASSIGN", "XOR_ASSIGN", "OR_ASSIGN",
  "TYPEDEF_NAME", "SEMI", "COLON", "CURLYOPEN", "CURLYCLOSE",
  "BRACKETOPEN", "BRACKETCLOSE", "COMMA", "PERIOD", "EQUALS", "OPEN",
  "CLOSE", "STAR", "QUESTION", "BAR", "CARROT", "AMP", "LESS_OP",
  "GREAT_OP", "PLUS", "MINUS", "FORSLASH", "PERCENT", "BANG", "TILDA",
  "TYPEDEF", "EXTERN", "STATIC", "AUTO", "REGISTER", "CHAR", "SHORT",
  "INT", "LONG", "SIGNED", "UNSIGNED", "FLOAT", "DOUBLE", "CONST",
  "VOLATILE", "VOID", "STRUCT", "UNION", "ENUM", "ELIPSIS", "RANGE",
  "CASE", "DEFAULT", "IF", "ELSE", "SWITCH", "WHILE", "DO", "FOR", "GOTO",
  "CONTINUE", "BREAK", "RETURN", "$accept", "translation_unit",
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
     335,   336,   337,   338,   339,   340,   341,   342,   343
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    89,    90,    90,    91,    91,    92,    92,    92,    92,
      93,    93,    94,    94,    95,    95,    95,    95,    95,    95,
      96,    96,    96,    96,    96,    97,    97,    97,    97,    97,
      97,    97,    97,    97,    97,    97,    97,    98,    98,    99,
      99,    99,   100,   100,   101,   101,   102,   102,   103,   103,
     104,   105,   105,   105,   105,   106,   106,   107,   107,   107,
     108,   108,   108,   109,   109,   110,   110,   111,   111,   112,
     112,   112,   112,   112,   112,   112,   113,   113,   113,   113,
     114,   114,   115,   115,   116,   116,   117,   117,   117,   118,
     118,   119,   119,   119,   120,   120,   121,   121,   122,   122,
     122,   123,   123,   123,   123,   123,   123,   123,   123,   123,
     124,   124,   124,   124,   124,   124,   125,   125,   125,   126,
     126,   127,   127,   127,   127,   128,   128,   129,   129,   129,
     130,   130,   130,   130,   130,   130,   130,   130,   130,   130,
     131,   131,   131,   131,   131,   132,   132,   133,   133,   134,
     134,   134,   134,   134,   134,   134,   134,   134,   134,   134,
     135,   135,   136,   137,   137,   138,   138,   139,   139,   140,
     140,   141,   141,   142,   142,   142,   143,   143,   143,   143,
     143,   144,   144,   144,   145,   145,   145,   146,   146,   146,
     146,   147,   147,   148,   148,   148,   148,   148,   148,   149,
     149,   149,   149,   149,   149,   150,   150,   150,   150,   150,
     150,   150,   150,   151,   151,   151,   151,   152,   152,   153,
     153,   153,   153,   154,   155
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
     196,     0,   211,   212,     0,     0,     0,     0,    72,     0,
       0,    86,    98,    88,    99,    74,     0,     0,    75,    64,
      66,    61,    94,     0,    58,    50,     0,     0,    39,     0,
       0,    98,    97,     0,   216,     0,   118,     0,     0,     0,
       0,     0,     0,   140,   144,   124,   146,   164,     0,   166,
     168,   170,   172,   174,   175,   179,   180,   177,   178,   182,
     183,   185,   186,   188,   189,   190,   148,   210,     0,   209,
     207,   217,     0,   116,   102,     0,   106,     0,     0,   100,
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
     134,   135,   136,   302,   137,   138,   147
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -169
static const yytype_int16 yypact[] =
{
     871,  -169,  -169,    28,    88,  -169,  -169,  -169,  -169,  -169,
    -169,  -169,  -169,  -169,  -169,  -169,  -169,  -169,  -169,  -169,
    -169,  -169,  -169,    23,   331,  -169,  -169,  -169,    10,  1675,
    1675,  1675,  -169,    63,  -169,  1612,   -22,     9,  -169,   -35,
    -169,  -169,    88,    44,    50,  -169,  -169,  -169,   -16,  -169,
    1593,  -169,  -169,  -169,  1747,    98,   431,  -169,  1612,    10,
    -169,  1009,   915,   -22,  -169,  -169,  -169,   175,  -169,    48,
      44,  -169,    28,  1024,  1612,  -169,  1747,  1747,  1719,  -169,
      35,  1747,  -169,  -169,  -169,  -169,  -169,  1434,  1487,  1487,
    -169,  -169,   782,  -169,  -169,  -169,  -169,  -169,  -169,  1502,
      62,    99,   101,   149,   724,   161,    44,   186,   197,  1077,
     524,  -169,  -169,  -169,  -169,   610,  -169,  -169,  -169,    54,
    -169,  -169,    59,   239,   200,   230,   233,   226,    96,   240,
     213,   116,  -169,   198,  1502,   112,  -169,  -169,  -169,   253,
    -169,  -169,   248,  -169,  -169,   256,  -169,  -169,  -169,    22,
     257,   260,  -169,    83,  -169,  -169,    44,  1502,   201,  -169,
    1024,  -169,  -169,  -169,  -169,  -169,  -169,  -169,  1502,    75,
    -169,   262,  1733,   782,  -169,  1502,  -169,  -169,    -9,   258,
      91,   268,   724,  1502,  1502,  1502,   229,  1093,   280,  -169,
    -169,  -169,   128,  -169,   667,  -169,  -169,  -169,  1502,  1502,
    1502,  1502,  1502,  1502,  1502,  1502,  1502,  1502,  1502,  1502,
    1502,  1502,  1502,  1502,  1502,  1502,  1502,  1502,  -169,  -169,
    -169,  -169,  -169,  -169,  -169,  -169,  -169,  -169,  -169,  1502,
    -169,    44,  -169,  -169,  1502,    44,  1146,   724,  -169,  1161,
     827,  -169,    46,  -169,   151,  -169,  1504,    44,  -169,  -169,
    -169,  -169,  -169,   224,  -169,  -169,    35,  1502,  -169,   271,
    1549,   152,  -169,  1502,  -169,   724,  -169,   157,   158,   159,
     273,  1214,   135,  -169,  -169,  -169,  -169,   239,   141,   200,
     230,   233,   226,    96,    96,   240,   240,   240,   240,   213,
     213,   116,   116,  -169,  -169,  -169,  -169,  -169,   236,  -169,
    -169,  -169,   165,  -169,  -169,   279,  -169,   275,   276,   151,
    1229,  1656,  -169,  -169,  -169,  -169,   956,  -169,  -169,  -169,
    -169,  -169,   724,   724,   724,  1502,  1282,   138,  1298,  1502,
    -169,  1502,  -169,  -169,  -169,  -169,  -169,   282,  -169,   278,
    -169,  -169,   241,  -169,  -169,   166,   724,   167,  1351,  1366,
     143,  -169,  -169,  -169,  -169,   724,   293,  -169,   724,   724,
     173,   724,   174,  1419,  -169,  -169,  -169,  -169,   724,  -169,
     724,   724,   192,  -169,  -169,  -169,   724,  -169
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -169,  -169,   303,  -169,    61,   133,    15,  -169,    60,    13,
    -169,  -169,   247,  -169,   261,   -70,   -56,  -169,    74,  -169,
     259,   176,     1,   -36,     6,  -169,   -51,  -169,    89,  -169,
    -155,  -169,   163,   -95,  -168,   -74,  -169,  -169,   104,   227,
    -169,  -169,  -169,   -57,   -64,  -169,   -59,   -93,  -169,   139,
     140,   137,   142,   136,    73,   100,    71,    76,  -116,   216,
    -169,  -169,  -169,  -169,  -169,  -169,     0
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
      38,    63,   144,    38,    39,   252,   181,    64,   167,   162,
      41,   150,     1,     1,    61,    28,    71,    40,   230,    62,
     164,   165,    72,    44,    38,     1,     1,   239,    38,    50,
     186,     1,   260,    55,     4,   180,   178,    38,     1,    28,
     144,   196,    47,    69,    51,    52,    53,     1,    66,     1,
       3,     3,   192,     4,   243,    65,   139,    43,   239,    38,
     142,    27,   154,   240,   250,     4,     1,    77,   168,     3,
      69,     4,    38,   142,   309,   254,     3,   149,     4,   199,
      38,   171,   239,   262,    70,    27,   197,   240,   157,    77,
      77,    77,   198,   309,    77,   182,   162,    54,   144,   293,
     294,   295,   167,   200,   139,    77,   188,   255,   266,   144,
     139,   207,   208,   256,    76,   139,   180,   178,   180,   140,
     196,   247,   231,   232,   233,   248,   267,   268,   269,   198,
     272,     4,    81,   264,   276,   140,    76,    76,    76,    60,
     183,    76,   184,   278,   209,   210,   305,   320,   234,    38,
     241,   235,    76,   236,    75,   242,    69,    18,    19,   215,
     274,   341,   141,   303,   318,   296,   198,   328,   216,   217,
     348,   140,   301,   198,   329,   363,   198,   298,   163,   198,
     144,   198,   139,    74,   261,    77,    77,   310,   239,   110,
     185,   321,   311,   260,   139,   198,   198,   198,   144,   322,
     323,   324,   187,   331,   198,   198,    63,   332,   356,   358,
     155,   198,   198,   156,   327,   368,   370,   337,   189,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   190,
     198,   297,    76,    76,   376,   299,   251,   139,   228,   156,
      38,    39,    38,   205,   206,   202,   242,   314,   342,   343,
     344,   144,   162,   211,   212,   149,    38,   171,   201,   315,
     339,   149,   316,   213,   214,   139,   261,   352,   345,   347,
     351,   350,   357,   330,   198,   149,   203,   146,   283,   284,
     204,   364,   289,   290,   366,   367,   237,   369,    73,   291,
     292,   360,   362,   238,   373,   257,   374,   375,   246,   245,
     263,   265,   377,   174,   176,   177,   372,   285,   286,   287,
     288,   270,   273,   319,   325,   146,   333,   334,   335,   353,
     354,   355,   139,   139,   139,   365,   149,    46,   172,   158,
     317,    45,   249,   159,     1,   313,   259,   194,   277,   280,
     282,   279,     0,     0,     0,   281,   139,     0,     0,     0,
     146,     0,     0,     0,     0,   139,     0,     0,   139,   139,
       0,   139,     2,     0,     0,     0,     0,     0,   139,     0,
     139,   139,     3,   146,     4,     0,   139,     0,     0,     0,
       0,     0,     0,     0,   146,     0,     0,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   146,     0,   146,   146,   146,
     146,   146,   146,   146,   146,   146,   146,   146,   146,   146,
     146,   146,   146,   146,     1,    82,    83,    84,    85,    86,
      87,     0,    88,    89,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   146,     0,     0,     0,     0,
       0,     0,     2,    90,     0,    56,    91,     0,     0,     0,
       0,     0,    92,   146,    93,     0,     0,     0,    94,   146,
       0,    95,    96,     0,     0,    97,    98,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,     0,     0,    99,   100,
     101,     0,   102,   103,   104,   105,   106,   107,   108,   109,
       0,     0,     0,     0,     0,     0,   146,     1,    82,    83,
      84,    85,    86,    87,     0,    88,    89,     0,     0,     0,
       0,     0,     0,     0,     0,   146,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     2,    90,     0,    56,   193,
       0,     0,     0,     0,     0,    92,     0,    93,     0,     0,
       0,    94,     0,     0,    95,    96,     0,     0,    97,    98,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,     0,
       0,    99,   100,   101,     0,   102,   103,   104,   105,   106,
     107,   108,   109,     1,    82,    83,    84,    85,    86,    87,
       0,    88,    89,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    90,     0,    56,   195,     0,     0,     0,     0,
       0,    92,     0,    93,     0,     0,     0,    94,     0,     0,
      95,    96,     0,     0,    97,    98,     0,     0,     0,     0,
       1,    82,    83,    84,    85,    86,    87,     0,    88,    89,
       0,     0,     0,     0,     0,     0,     0,    99,   100,   101,
       0,   102,   103,   104,   105,   106,   107,   108,   109,    90,
       0,    56,   275,     0,     0,     0,     0,     0,    92,     0,
      93,     0,     0,     0,    94,     0,     0,    95,    96,     0,
       0,    97,    98,     0,     0,     0,     0,     1,    82,    83,
      84,    85,    86,    87,     0,    88,    89,     0,     0,     0,
       0,     0,     0,     0,    99,   100,   101,     0,   102,   103,
     104,   105,   106,   107,   108,   109,    90,     0,    56,     0,
       0,     0,     0,     0,     0,    92,     0,    93,     0,     0,
       0,    94,     0,     0,    95,    96,     0,     0,    97,    98,
       0,     0,     0,     0,     0,     1,    82,    83,    84,    85,
      86,    87,     0,    88,    89,     0,     0,     0,     0,     0,
       0,    99,   100,   101,     0,   102,   103,   104,   105,   106,
     107,   108,   109,     2,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    92,     0,    93,     0,     0,     0,    94,
       1,     0,    95,    96,     0,     0,    97,    98,     0,     0,
       0,     0,     0,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,     0,     2,     0,
       0,     0,     0,   239,     0,     0,     0,     0,   240,   306,
       4,     0,     0,     0,     1,     0,     0,     0,     0,     0,
       0,     0,     0,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,     2,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     3,     0,     4,     0,     0,     0,     1,     0,
       0,     0,     0,     0,     0,     0,     0,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,     2,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   148,     0,     1,
      82,    83,    84,    85,    86,    87,     0,    88,    89,     0,
       0,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
     160,   340,     0,     0,     0,     0,     0,    92,     0,    93,
       0,     0,     0,    94,     0,     0,    95,    96,     0,     0,
      97,    98,     1,    82,    83,    84,    85,    86,    87,     0,
      88,    89,     0,     0,     0,     0,     0,     1,    82,    83,
      84,    85,    86,    87,     0,    88,    89,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   143,     0,     0,     0,
      92,     0,    93,     0,     0,     0,    94,     0,   160,    95,
      96,     0,     0,    97,    98,    92,     0,    93,     0,     0,
       0,    94,     0,     0,    95,    96,     0,     0,    97,    98,
       1,    82,    83,    84,    85,    86,    87,     0,    88,    89,
       0,     0,     0,     0,     0,     0,     1,    82,    83,    84,
      85,    86,    87,     0,    88,    89,     0,     0,     0,   191,
       0,     0,     0,     0,     0,     0,     0,     0,    92,     0,
      93,     0,     0,     0,    94,   271,     0,    95,    96,     0,
       0,    97,    98,     0,    92,     0,    93,     0,     0,     0,
      94,     0,     0,    95,    96,     0,     0,    97,    98,     1,
      82,    83,    84,    85,    86,    87,     0,    88,    89,     0,
       0,     0,     0,     0,     1,    82,    83,    84,    85,    86,
      87,     0,    88,    89,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    92,   300,    93,
       0,     0,     0,    94,     0,     0,    95,    96,   304,     0,
      97,    98,    92,     0,    93,     0,     0,     0,    94,     0,
       0,    95,    96,     0,     0,    97,    98,     1,    82,    83,
      84,    85,    86,    87,     0,    88,    89,     0,     0,     0,
       0,     0,     1,    82,    83,    84,    85,    86,    87,     0,
      88,    89,     0,     0,     0,     0,   326,     0,     0,     0,
       0,     0,     0,     0,     0,    92,     0,    93,     0,     0,
       0,    94,     0,     0,    95,    96,   336,     0,    97,    98,
      92,     0,    93,     0,     0,     0,    94,     0,     0,    95,
      96,     0,     0,    97,    98,     1,    82,    83,    84,    85,
      86,    87,     0,    88,    89,     0,     0,     0,     0,     0,
       0,     1,    82,    83,    84,    85,    86,    87,     0,    88,
      89,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    92,   346,    93,     0,     0,     0,    94,
     349,     0,    95,    96,     0,     0,    97,    98,     0,    92,
       0,    93,     0,     0,     0,    94,     0,     0,    95,    96,
       0,     0,    97,    98,     1,    82,    83,    84,    85,    86,
      87,     0,    88,    89,     0,     0,     0,     0,     0,     1,
      82,    83,    84,    85,    86,    87,     0,    88,    89,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    92,   359,    93,     0,     0,     0,    94,     0,
       0,    95,    96,     0,     0,    97,    98,    92,   361,    93,
       0,     0,     0,    94,     0,     0,    95,    96,     0,     0,
      97,    98,     1,    82,    83,    84,    85,    86,    87,     0,
      88,    89,     0,     0,     0,     0,     0,     1,    82,    83,
      84,    85,    86,    87,     0,    88,    89,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      92,   371,    93,     0,     0,     0,    94,     0,     0,    95,
      96,     0,     0,    97,    98,   173,     0,    93,     0,     0,
       0,    94,     0,     0,    95,    96,     0,     0,    97,    98,
       1,    82,    83,    84,    85,    86,    87,     0,    88,    89,
       0,     0,     0,     0,     0,     1,    82,    83,    84,    85,
      86,    87,     0,    88,    89,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   175,     0,
      93,     0,     0,     0,    94,     2,     0,    95,    96,     0,
       0,    97,    98,    92,     0,    93,     0,     0,     0,    94,
       0,     0,    95,    96,     0,     0,    97,    98,     0,     0,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,   312,
       2,     0,     0,     0,     0,   239,     0,     0,     0,     0,
     260,   306,     4,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,     2,     0,     0,    56,     0,     0,
       0,     0,     0,    73,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     2,     0,     0,    56,     0,     0,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,     2,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   338,     0,
       0,     0,     0,     0,     0,     0,     2,     0,     0,     0,
       0,     0,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
       2,     0,     0,     0,   166,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     2,     0,     0,     0,   258,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     2,     0,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23
};

static const yytype_int16 yycheck[] =
{
       0,    37,    61,     3,     3,   160,    99,    42,    78,    73,
       4,    62,     3,     3,    36,     0,    32,     4,   134,    41,
      76,    77,    38,    23,    24,     3,     3,    36,    28,    28,
     104,     3,    41,    33,    43,    92,    92,    37,     3,    24,
      99,   115,    32,    43,    29,    30,    31,     3,    42,     3,
      41,    41,   109,    43,   149,    42,    56,    34,    36,    59,
      59,     0,    62,    41,   157,    43,     3,    54,    33,    41,
      70,    43,    72,    72,   242,   168,    41,    62,    43,    20,
      80,    80,    36,   178,    34,    24,    32,    41,    40,    76,
      77,    78,    38,   261,    81,    33,   160,    34,   157,   215,
     216,   217,   172,    44,   104,    92,   106,    32,   182,   168,
     110,    15,    16,    38,    54,   115,   173,   173,   175,    58,
     194,    38,    10,    11,    12,    42,   183,   184,   185,    38,
     187,    43,    34,    42,   198,    74,    76,    77,    78,    35,
      41,    81,    41,   200,    48,    49,   239,   263,    36,   149,
     149,    39,    92,    41,    50,   149,   156,    69,    70,    43,
      32,   316,    58,   237,   257,   229,    38,    32,    52,    53,
      32,   110,   236,    38,    33,    32,    38,   234,    74,    38,
     239,    38,   182,    50,   178,   172,   173,    36,    36,    56,
      41,   265,    41,    41,   194,    38,    38,    38,   257,    42,
      42,    42,    41,    38,    38,    38,   242,    42,    42,    42,
      35,    38,    38,    38,   271,    42,    42,   310,    32,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    32,
      38,   231,   172,   173,    42,   235,    35,   237,    40,    38,
     240,   240,   242,    17,    18,    45,   240,   247,   322,   323,
     324,   310,   316,    13,    14,   240,   256,   256,    19,    35,
     311,   246,    38,    50,    51,   265,   260,   331,   325,   326,
     329,   328,   346,    37,    38,   260,    46,    61,   205,   206,
      47,   355,   211,   212,   358,   359,    33,   361,    40,   213,
     214,   348,   349,    37,   368,    33,   370,   371,    38,    42,
      42,    33,   376,    87,    88,    89,   363,   207,   208,   209,
     210,    82,    32,    42,    41,    99,    37,    42,    42,    37,
      42,    80,   322,   323,   324,    32,   311,    24,    81,    70,
     256,     0,   156,    72,     3,   246,   173,   110,   199,   202,
     204,   201,    -1,    -1,    -1,   203,   346,    -1,    -1,    -1,
     134,    -1,    -1,    -1,    -1,   355,    -1,    -1,   358,   359,
      -1,   361,    31,    -1,    -1,    -1,    -1,    -1,   368,    -1,
     370,   371,    41,   157,    43,    -1,   376,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   168,    -1,    -1,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   199,    -1,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,     3,     4,     5,     6,     7,     8,
       9,    -1,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   239,    -1,    -1,    -1,    -1,
      -1,    -1,    31,    32,    -1,    34,    35,    -1,    -1,    -1,
      -1,    -1,    41,   257,    43,    -1,    -1,    -1,    47,   263,
      -1,    50,    51,    -1,    -1,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    -1,    -1,    77,    78,
      79,    -1,    81,    82,    83,    84,    85,    86,    87,    88,
      -1,    -1,    -1,    -1,    -1,    -1,   310,     3,     4,     5,
       6,     7,     8,     9,    -1,    11,    12,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   329,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    31,    32,    -1,    34,    35,
      -1,    -1,    -1,    -1,    -1,    41,    -1,    43,    -1,    -1,
      -1,    47,    -1,    -1,    50,    51,    -1,    -1,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    -1,
      -1,    77,    78,    79,    -1,    81,    82,    83,    84,    85,
      86,    87,    88,     3,     4,     5,     6,     7,     8,     9,
      -1,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    32,    -1,    34,    35,    -1,    -1,    -1,    -1,
      -1,    41,    -1,    43,    -1,    -1,    -1,    47,    -1,    -1,
      50,    51,    -1,    -1,    54,    55,    -1,    -1,    -1,    -1,
       3,     4,     5,     6,     7,     8,     9,    -1,    11,    12,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    77,    78,    79,
      -1,    81,    82,    83,    84,    85,    86,    87,    88,    32,
      -1,    34,    35,    -1,    -1,    -1,    -1,    -1,    41,    -1,
      43,    -1,    -1,    -1,    47,    -1,    -1,    50,    51,    -1,
      -1,    54,    55,    -1,    -1,    -1,    -1,     3,     4,     5,
       6,     7,     8,     9,    -1,    11,    12,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    77,    78,    79,    -1,    81,    82,
      83,    84,    85,    86,    87,    88,    32,    -1,    34,    -1,
      -1,    -1,    -1,    -1,    -1,    41,    -1,    43,    -1,    -1,
      -1,    47,    -1,    -1,    50,    51,    -1,    -1,    54,    55,
      -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,
       8,     9,    -1,    11,    12,    -1,    -1,    -1,    -1,    -1,
      -1,    77,    78,    79,    -1,    81,    82,    83,    84,    85,
      86,    87,    88,    31,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    41,    -1,    43,    -1,    -1,    -1,    47,
       3,    -1,    50,    51,    -1,    -1,    54,    55,    -1,    -1,
      -1,    -1,    -1,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    -1,    31,    -1,
      -1,    -1,    -1,    36,    -1,    -1,    -1,    -1,    41,    42,
      43,    -1,    -1,    -1,     3,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    41,    -1,    43,    -1,    -1,    -1,     3,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    31,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,    -1,     3,
       4,     5,     6,     7,     8,     9,    -1,    11,    12,    -1,
      -1,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      34,    35,    -1,    -1,    -1,    -1,    -1,    41,    -1,    43,
      -1,    -1,    -1,    47,    -1,    -1,    50,    51,    -1,    -1,
      54,    55,     3,     4,     5,     6,     7,     8,     9,    -1,
      11,    12,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,
       6,     7,     8,     9,    -1,    11,    12,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    37,    -1,    -1,    -1,
      41,    -1,    43,    -1,    -1,    -1,    47,    -1,    34,    50,
      51,    -1,    -1,    54,    55,    41,    -1,    43,    -1,    -1,
      -1,    47,    -1,    -1,    50,    51,    -1,    -1,    54,    55,
       3,     4,     5,     6,     7,     8,     9,    -1,    11,    12,
      -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,
       7,     8,     9,    -1,    11,    12,    -1,    -1,    -1,    32,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    41,    -1,
      43,    -1,    -1,    -1,    47,    32,    -1,    50,    51,    -1,
      -1,    54,    55,    -1,    41,    -1,    43,    -1,    -1,    -1,
      47,    -1,    -1,    50,    51,    -1,    -1,    54,    55,     3,
       4,     5,     6,     7,     8,     9,    -1,    11,    12,    -1,
      -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,     8,
       9,    -1,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    41,    42,    43,
      -1,    -1,    -1,    47,    -1,    -1,    50,    51,    37,    -1,
      54,    55,    41,    -1,    43,    -1,    -1,    -1,    47,    -1,
      -1,    50,    51,    -1,    -1,    54,    55,     3,     4,     5,
       6,     7,     8,     9,    -1,    11,    12,    -1,    -1,    -1,
      -1,    -1,     3,     4,     5,     6,     7,     8,     9,    -1,
      11,    12,    -1,    -1,    -1,    -1,    32,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    41,    -1,    43,    -1,    -1,
      -1,    47,    -1,    -1,    50,    51,    37,    -1,    54,    55,
      41,    -1,    43,    -1,    -1,    -1,    47,    -1,    -1,    50,
      51,    -1,    -1,    54,    55,     3,     4,     5,     6,     7,
       8,     9,    -1,    11,    12,    -1,    -1,    -1,    -1,    -1,
      -1,     3,     4,     5,     6,     7,     8,     9,    -1,    11,
      12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    41,    42,    43,    -1,    -1,    -1,    47,
      32,    -1,    50,    51,    -1,    -1,    54,    55,    -1,    41,
      -1,    43,    -1,    -1,    -1,    47,    -1,    -1,    50,    51,
      -1,    -1,    54,    55,     3,     4,     5,     6,     7,     8,
       9,    -1,    11,    12,    -1,    -1,    -1,    -1,    -1,     3,
       4,     5,     6,     7,     8,     9,    -1,    11,    12,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    41,    42,    43,    -1,    -1,    -1,    47,    -1,
      -1,    50,    51,    -1,    -1,    54,    55,    41,    42,    43,
      -1,    -1,    -1,    47,    -1,    -1,    50,    51,    -1,    -1,
      54,    55,     3,     4,     5,     6,     7,     8,     9,    -1,
      11,    12,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,
       6,     7,     8,     9,    -1,    11,    12,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      41,    42,    43,    -1,    -1,    -1,    47,    -1,    -1,    50,
      51,    -1,    -1,    54,    55,    41,    -1,    43,    -1,    -1,
      -1,    47,    -1,    -1,    50,    51,    -1,    -1,    54,    55,
       3,     4,     5,     6,     7,     8,     9,    -1,    11,    12,
      -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,
       8,     9,    -1,    11,    12,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    41,    -1,
      43,    -1,    -1,    -1,    47,    31,    -1,    50,    51,    -1,
      -1,    54,    55,    41,    -1,    43,    -1,    -1,    -1,    47,
      -1,    -1,    50,    51,    -1,    -1,    54,    55,    -1,    -1,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      31,    -1,    -1,    -1,    -1,    36,    -1,    -1,    -1,    -1,
      41,    42,    43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    31,    -1,    -1,    34,    -1,    -1,
      -1,    -1,    -1,    40,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    31,    -1,    -1,    34,    -1,    -1,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    31,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    31,    -1,    -1,    -1,
      -1,    -1,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      31,    -1,    -1,    -1,    35,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    31,    -1,    -1,    -1,    35,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,    -1,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    31,    41,    43,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    90,    91,    92,    93,    95,    96,
      97,    98,    99,   100,   108,   111,   112,   113,   155,   111,
      98,   113,   114,    34,   155,     0,    91,    32,   102,   103,
     111,    95,    95,    95,    34,   155,    34,    93,    94,    95,
     127,    36,    41,   112,    42,    98,   113,   109,   110,   155,
      34,    32,    38,    40,    94,   127,    97,    98,   101,   104,
     105,    34,     4,     5,     6,     7,     8,     9,    11,    12,
      32,    35,    41,    43,    47,    50,    51,    54,    55,    77,
      78,    79,    81,    82,    83,    84,    85,    86,    87,    88,
      94,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   135,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   153,   154,   155,
      93,   127,   111,    37,   135,   136,   148,   155,    42,    95,
     115,   116,   117,   118,   155,    35,    38,    40,   109,   103,
      34,   119,   133,   127,   105,   105,    35,   104,    33,   106,
     107,   111,   101,    41,   148,    41,   148,   148,   105,   121,
     132,   136,    33,    41,    41,    41,   124,    41,   155,    32,
      32,    32,   132,    35,   128,    35,   124,    32,    38,    20,
      44,    19,    45,    46,    47,    17,    18,    15,    16,    48,
      49,    13,    14,    50,    51,    43,    52,    53,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    40,   134,
     147,    10,    11,    12,    36,    39,    41,    33,    37,    36,
      41,   111,   113,   122,   123,    42,    38,    38,    42,   110,
     136,    35,   119,   120,   136,    32,    38,    33,    35,   121,
      41,   113,   122,    42,    42,    33,   124,   132,   132,   132,
      82,    32,   132,    32,    32,    35,   133,   138,   132,   139,
     140,   141,   142,   143,   143,   144,   144,   144,   144,   145,
     145,   146,   146,   147,   147,   147,   133,   155,   132,   155,
      42,   133,   152,   124,    37,   136,    42,   115,   122,   123,
      36,    41,    75,   117,   155,    35,    38,   107,   136,    42,
     147,   124,    42,    42,    42,    41,    32,   132,    32,    33,
      37,    38,    42,    37,    42,    42,    37,   136,    42,   115,
      35,   119,   124,   124,   124,   132,    42,   132,    32,    32,
     132,   135,   133,    37,    42,    80,    42,   124,    42,    42,
     132,    42,   132,    32,   124,    32,   124,   124,    42,   124,
      42,    42,   132,   124,   124,   124,    42,   124
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
#line 44 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 3:
#line 45 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 4:
#line 49 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 5:
#line 50 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 6:
#line 54 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 7:
#line 55 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 8:
#line 56 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 9:
#line 57 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 10:
#line 61 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 11:
#line 62 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 12:
#line 66 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 13:
#line 67 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 14:
#line 71 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 15:
#line 72 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 16:
#line 73 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 17:
#line 74 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 18:
#line 75 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 19:
#line 76 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 20:
#line 80 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 21:
#line 81 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 22:
#line 82 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 23:
#line 83 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 24:
#line 84 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 25:
#line 88 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 26:
#line 89 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 27:
#line 90 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 28:
#line 91 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 29:
#line 92 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 30:
#line 93 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 31:
#line 94 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 32:
#line 95 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 33:
#line 96 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 34:
#line 97 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 35:
#line 98 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 36:
#line 99 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 37:
#line 103 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 38:
#line 104 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 39:
#line 108 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 40:
#line 109 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 41:
#line 110 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 42:
#line 114 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 43:
#line 115 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 44:
#line 119 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 45:
#line 120 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 46:
#line 124 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 47:
#line 125 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 48:
#line 129 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 49:
#line 130 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 50:
#line 134 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 51:
#line 138 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 52:
#line 139 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 53:
#line 140 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 54:
#line 141 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 55:
#line 145 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 56:
#line 146 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 57:
#line 150 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 58:
#line 151 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 59:
#line 152 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 60:
#line 156 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 61:
#line 157 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 62:
#line 158 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 63:
#line 162 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 64:
#line 163 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 65:
#line 167 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 66:
#line 168 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 67:
#line 172 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 68:
#line 173 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 69:
#line 177 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 70:
#line 178 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 71:
#line 179 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 72:
#line 180 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 73:
#line 181 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 74:
#line 182 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 75:
#line 183 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 76:
#line 187 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 77:
#line 188 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 78:
#line 189 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 79:
#line 190 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 80:
#line 194 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 81:
#line 195 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 82:
#line 199 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 83:
#line 200 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 84:
#line 204 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 85:
#line 205 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 86:
#line 209 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 87:
#line 210 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 88:
#line 211 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 89:
#line 215 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 90:
#line 216 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 91:
#line 220 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 92:
#line 221 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 93:
#line 222 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 94:
#line 226 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 95:
#line 227 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 96:
#line 231 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 97:
#line 232 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 98:
#line 236 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 99:
#line 237 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 100:
#line 238 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 101:
#line 242 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 102:
#line 243 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 103:
#line 244 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 104:
#line 245 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 105:
#line 246 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 106:
#line 247 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 107:
#line 248 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 108:
#line 249 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 109:
#line 250 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 110:
#line 254 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 111:
#line 255 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 112:
#line 256 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 113:
#line 257 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 114:
#line 258 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 115:
#line 259 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 116:
#line 263 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 117:
#line 264 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 118:
#line 265 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 119:
#line 269 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 120:
#line 270 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 121:
#line 274 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 122:
#line 275 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 123:
#line 276 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 124:
#line 277 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 125:
#line 281 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 126:
#line 282 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 127:
#line 286 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 128:
#line 287 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 129:
#line 288 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 130:
#line 292 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 131:
#line 293 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 132:
#line 294 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 133:
#line 295 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 134:
#line 296 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 135:
#line 297 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 136:
#line 298 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 137:
#line 299 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 138:
#line 300 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 139:
#line 301 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 140:
#line 305 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 141:
#line 306 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 142:
#line 307 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 143:
#line 308 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 144:
#line 309 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 145:
#line 313 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 146:
#line 314 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 147:
#line 318 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 148:
#line 319 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 149:
#line 323 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 150:
#line 324 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 151:
#line 325 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 152:
#line 326 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 153:
#line 327 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 154:
#line 328 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 155:
#line 329 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 156:
#line 330 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 157:
#line 331 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 158:
#line 332 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 159:
#line 333 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 160:
#line 337 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 161:
#line 338 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 162:
#line 342 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 163:
#line 346 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 164:
#line 347 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 165:
#line 351 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 166:
#line 352 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 167:
#line 356 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 168:
#line 357 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 169:
#line 361 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 170:
#line 362 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 171:
#line 366 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 172:
#line 367 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 173:
#line 371 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 174:
#line 372 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 176:
#line 377 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 177:
#line 378 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 178:
#line 379 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 179:
#line 380 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 180:
#line 381 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 181:
#line 385 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 182:
#line 386 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 183:
#line 387 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 184:
#line 391 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 185:
#line 392 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 186:
#line 393 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 187:
#line 397 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 188:
#line 398 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 189:
#line 399 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 190:
#line 400 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 191:
#line 404 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 192:
#line 405 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 193:
#line 409 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 194:
#line 410 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 195:
#line 411 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 196:
#line 412 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 197:
#line 413 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 198:
#line 414 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 199:
#line 418 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 200:
#line 419 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 201:
#line 420 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 202:
#line 421 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 203:
#line 422 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 204:
#line 423 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 205:
#line 427 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 206:
#line 428 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 207:
#line 429 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 208:
#line 430 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 209:
#line 431 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 210:
#line 432 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 211:
#line 433 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 212:
#line 434 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 213:
#line 438 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 214:
#line 439 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 215:
#line 440 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 216:
#line 441 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 217:
#line 445 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 218:
#line 446 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 219:
#line 450 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 220:
#line 451 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 221:
#line 452 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 222:
#line 453 "C_grammar.y"
    {if (printProductions) {printf("");};}
    break;

  case 223:
#line 457 "C_grammar.y"
    {if (printProductions) {printf("string -> %s\n",(yyvsp[(1) - (1)].sval));};}
    break;

  case 224:
#line 461 "C_grammar.y"
    {if (printProductions) {printf("identifier -> %s\n",(yyvsp[(1) - (1)].sval));};}
    break;


/* Line 1267 of yacc.c.  */
#line 3288 "C_grammar.tab.c"
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


#line 463 "C_grammar.y"


#include <stdio.h>

extern char yytext[];
extern int column;

yyerror(s)
char *s;
{
	fflush(stdout);
	printf("\n%*s\n%*s\n", column, "^", column, s);
}


