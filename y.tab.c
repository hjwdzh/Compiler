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
     INTEGER_VAL = 258,
     CHAR_VAL = 259,
     FLOAT_VAL = 260,
     DOUBLE_VAL = 261,
     IDENTIFIER = 262,
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
     TYPE_NAME = 286,
     TYPEDEF = 287,
     EXTERN = 288,
     STATIC = 289,
     AUTO = 290,
     REGISTER = 291,
     CHAR = 292,
     SHORT = 293,
     INT = 294,
     LONG = 295,
     SIGNED = 296,
     UNSIGNED = 297,
     FLOAT = 298,
     DOUBLE = 299,
     CONST = 300,
     VOLATILE = 301,
     VOID = 302,
     STRUCT = 303,
     UNION = 304,
     ENUM = 305,
     ELLIPSIS = 306,
     CASE = 307,
     DEFAULT = 308,
     IF = 309,
     ELSE = 310,
     SWITCH = 311,
     WHILE = 312,
     DO = 313,
     FOR = 314,
     GOTO = 315,
     CONTINUE = 316,
     BREAK = 317,
     RETURN = 318
   };
#endif
/* Tokens.  */
#define INTEGER_VAL 258
#define CHAR_VAL 259
#define FLOAT_VAL 260
#define DOUBLE_VAL 261
#define IDENTIFIER 262
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
#define TYPE_NAME 286
#define TYPEDEF 287
#define EXTERN 288
#define STATIC 289
#define AUTO 290
#define REGISTER 291
#define CHAR 292
#define SHORT 293
#define INT 294
#define LONG 295
#define SIGNED 296
#define UNSIGNED 297
#define FLOAT 298
#define DOUBLE 299
#define CONST 300
#define VOLATILE 301
#define VOID 302
#define STRUCT 303
#define UNION 304
#define ENUM 305
#define ELLIPSIS 306
#define CASE 307
#define DEFAULT 308
#define IF 309
#define ELSE 310
#define SWITCH 311
#define WHILE 312
#define DO 313
#define FOR 314
#define GOTO 315
#define CONTINUE 316
#define BREAK 317
#define RETURN 318




/* Copy the first part of user declarations.  */
#line 1 "c.y"

    #include "types.h"
    #include "statement.h"
    void* node;


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

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 6 "c.y"
{
    char cValue; //2
    int iValue; //1
    float fValue; //3
    void* nPtr; //0
    double dValue; //4
}
/* Line 193 of yacc.c.  */
#line 236 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 249 "y.tab.c"

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
#define YYFINAL  61
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1319

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  88
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  64
/* YYNRULES -- Number of rules.  */
#define YYNRULES  215
/* YYNRULES -- Number of states.  */
#define YYNSTATES  353

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   318

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    75,     2,     2,     2,    77,    70,     2,
      64,    65,    71,    72,    69,    73,    68,    76,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    83,    85,
      78,    84,    79,    82,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    66,     2,    67,    80,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    86,    81,    87,    74,     2,     2,     2,
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
      55,    56,    57,    58,    59,    60,    61,    62,    63
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,     9,    11,    13,    15,    19,
      21,    26,    30,    35,    39,    43,    46,    49,    51,    55,
      57,    60,    63,    66,    69,    74,    76,    78,    80,    82,
      84,    86,    88,    93,    95,    99,   103,   107,   109,   113,
     117,   119,   123,   127,   129,   133,   137,   141,   145,   147,
     151,   155,   157,   161,   163,   167,   169,   173,   175,   179,
     181,   185,   187,   193,   195,   199,   201,   203,   205,   207,
     209,   211,   213,   215,   217,   219,   221,   223,   227,   229,
     232,   236,   238,   241,   243,   246,   248,   251,   253,   257,
     259,   263,   265,   267,   269,   271,   273,   275,   277,   279,
     281,   283,   285,   287,   289,   291,   293,   295,   297,   303,
     308,   311,   313,   315,   317,   320,   324,   327,   329,   332,
     334,   336,   340,   342,   345,   349,   354,   360,   363,   365,
     369,   371,   375,   377,   379,   382,   384,   386,   390,   395,
     399,   404,   409,   413,   415,   418,   421,   425,   427,   430,
     432,   436,   438,   442,   445,   448,   450,   452,   456,   458,
     461,   463,   465,   468,   472,   475,   479,   483,   488,   491,
     495,   499,   504,   506,   510,   515,   517,   521,   523,   525,
     527,   529,   531,   533,   537,   542,   546,   549,   553,   557,
     562,   564,   567,   569,   572,   574,   577,   583,   591,   597,
     603,   611,   618,   626,   630,   633,   636,   639,   643,   645,
     648,   650,   652,   657,   661,   665
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     149,     0,    -1,     7,    -1,     3,    -1,     4,    -1,     5,
      -1,     6,    -1,     8,    -1,    64,   108,    65,    -1,    89,
      -1,    90,    66,   108,    67,    -1,    90,    64,    65,    -1,
      90,    64,    91,    65,    -1,    90,    68,     7,    -1,    90,
      10,     7,    -1,    90,    11,    -1,    90,    12,    -1,   106,
      -1,    91,    69,   106,    -1,    90,    -1,    11,    92,    -1,
      12,    92,    -1,    93,    94,    -1,     9,    92,    -1,     9,
      64,   135,    65,    -1,    70,    -1,    71,    -1,    72,    -1,
      73,    -1,    74,    -1,    75,    -1,    92,    -1,    64,   135,
      65,    94,    -1,    94,    -1,    95,    71,    94,    -1,    95,
      76,    94,    -1,    95,    77,    94,    -1,    95,    -1,    96,
      72,    95,    -1,    96,    73,    95,    -1,    96,    -1,    97,
      13,    96,    -1,    97,    14,    96,    -1,    97,    -1,    98,
      78,    97,    -1,    98,    79,    97,    -1,    98,    15,    97,
      -1,    98,    16,    97,    -1,    98,    -1,    99,    17,    98,
      -1,    99,    18,    98,    -1,    99,    -1,   100,    70,    99,
      -1,   100,    -1,   101,    80,   100,    -1,   101,    -1,   102,
      81,   101,    -1,   102,    -1,   103,    19,   102,    -1,   103,
      -1,   104,    20,   103,    -1,   104,    -1,   104,    82,   108,
      83,   105,    -1,   105,    -1,    92,   107,   106,    -1,    84,
      -1,    21,    -1,    22,    -1,    23,    -1,    24,    -1,    25,
      -1,    26,    -1,    27,    -1,    28,    -1,    29,    -1,    30,
      -1,   106,    -1,   108,    69,   106,    -1,   105,    -1,   111,
      85,    -1,   111,   112,    85,    -1,   114,    -1,   114,   111,
      -1,   115,    -1,   115,   111,    -1,   126,    -1,   126,   111,
      -1,   113,    -1,   112,    69,   113,    -1,   127,    -1,   127,
      84,   138,    -1,    32,    -1,    33,    -1,    34,    -1,    35,
      -1,    36,    -1,    47,    -1,    37,    -1,    38,    -1,    39,
      -1,    40,    -1,    43,    -1,    44,    -1,    41,    -1,    42,
      -1,   116,    -1,   123,    -1,    31,    -1,   117,     7,    86,
     118,    87,    -1,   117,    86,   118,    87,    -1,   117,     7,
      -1,    48,    -1,    49,    -1,   119,    -1,   118,   119,    -1,
     120,   121,    85,    -1,   115,   120,    -1,   115,    -1,   126,
     120,    -1,   126,    -1,   122,    -1,   121,    69,   122,    -1,
     127,    -1,    83,   109,    -1,   127,    83,   109,    -1,    50,
      86,   124,    87,    -1,    50,     7,    86,   124,    87,    -1,
      50,     7,    -1,   125,    -1,   124,    69,   125,    -1,     7,
      -1,     7,    84,   109,    -1,    45,    -1,    46,    -1,   129,
     128,    -1,   128,    -1,     7,    -1,    64,   127,    65,    -1,
     128,    66,   109,    67,    -1,   128,    66,    67,    -1,   128,
      64,   131,    65,    -1,   128,    64,   134,    65,    -1,   128,
      64,    65,    -1,    71,    -1,    71,   130,    -1,    71,   129,
      -1,    71,   130,   129,    -1,   126,    -1,   130,   126,    -1,
     132,    -1,   132,    69,    51,    -1,   133,    -1,   132,    69,
     133,    -1,   111,   127,    -1,   111,   136,    -1,   111,    -1,
       7,    -1,   134,    69,     7,    -1,   120,    -1,   120,   136,
      -1,   129,    -1,   137,    -1,   129,   137,    -1,    64,   136,
      65,    -1,    66,    67,    -1,    66,   109,    67,    -1,   137,
      66,    67,    -1,   137,    66,   109,    67,    -1,    64,    65,
      -1,    64,   131,    65,    -1,   137,    64,    65,    -1,   137,
      64,   131,    65,    -1,   106,    -1,    86,   139,    87,    -1,
      86,   139,    69,    87,    -1,   138,    -1,   139,    69,   138,
      -1,   141,    -1,   142,    -1,   145,    -1,   146,    -1,   147,
      -1,   148,    -1,     7,    83,   140,    -1,    52,   109,    83,
     140,    -1,    53,    83,   140,    -1,    86,    87,    -1,    86,
     144,    87,    -1,    86,   143,    87,    -1,    86,   143,   144,
      87,    -1,   110,    -1,   143,   110,    -1,   140,    -1,   144,
     140,    -1,    85,    -1,   108,    85,    -1,    54,    64,   108,
      65,   140,    -1,    54,    64,   108,    65,   140,    55,   140,
      -1,    56,    64,   108,    65,   140,    -1,    57,    64,   108,
      65,   140,    -1,    58,   140,    57,    64,   108,    65,    85,
      -1,    59,    64,   145,   145,    65,   140,    -1,    59,    64,
     145,   145,   108,    65,   140,    -1,    60,     7,    85,    -1,
      61,    85,    -1,    62,    85,    -1,    63,    85,    -1,    63,
     108,    85,    -1,   150,    -1,   149,   150,    -1,   151,    -1,
     110,    -1,   111,   127,   143,   142,    -1,   111,   127,   142,
      -1,   127,   143,   142,    -1,   127,   142,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    41,    41,    47,    53,    59,    65,    71,    77,    86,
      92,    99,   105,   112,   119,   126,   132,   141,   147,   157,
     163,   169,   175,   182,   188,   197,   198,   199,   200,   201,
     202,   206,   212,   222,   228,   235,   242,   252,   258,   265,
     275,   281,   288,   298,   304,   311,   318,   325,   335,   341,
     348,   358,   364,   374,   380,   390,   396,   406,   412,   422,
     428,   438,   444,   455,   461,   472,   473,   474,   475,   476,
     477,   478,   479,   480,   481,   482,   486,   492,   502,   511,
     517,   527,   533,   540,   546,   553,   559,   569,   575,   585,
     591,   601,   602,   603,   604,   605,   609,   610,   611,   612,
     613,   614,   615,   616,   617,   618,   619,   620,   624,   627,
     630,   636,   637,   641,   647,   657,   667,   674,   680,   687,
     696,   702,   712,   718,   724,   734,   735,   736,   740,   746,
     756,   757,   761,   762,   766,   773,   782,   788,   794,   801,
     807,   814,   821,   830,   835,   841,   847,   857,   863,   873,
     879,   888,   894,   904,   911,   918,   927,   933,   943,   949,
     959,   965,   971,   981,   987,   992,   998,  1004,  1011,  1016,
    1022,  1028,  1038,  1044,  1050,  1059,  1065,  1075,  1081,  1087,
    1093,  1099,  1105,  1114,  1121,  1128,  1137,  1142,  1148,  1154,
    1164,  1170,  1180,  1186,  1196,  1201,  1210,  1217,  1225,  1235,
    1242,  1249,  1257,  1269,  1275,  1280,  1285,  1290,  1299,  1306,
    1316,  1322,  1331,  1340,  1348,  1355
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INTEGER_VAL", "CHAR_VAL", "FLOAT_VAL",
  "DOUBLE_VAL", "IDENTIFIER", "STRING_LITERAL", "SIZEOF", "PTR_OP",
  "INC_OP", "DEC_OP", "LEFT_OP", "RIGHT_OP", "LE_OP", "GE_OP", "EQ_OP",
  "NE_OP", "AND_OP", "OR_OP", "MUL_ASSIGN", "DIV_ASSIGN", "MOD_ASSIGN",
  "ADD_ASSIGN", "SUB_ASSIGN", "LEFT_ASSIGN", "RIGHT_ASSIGN", "AND_ASSIGN",
  "XOR_ASSIGN", "OR_ASSIGN", "TYPE_NAME", "TYPEDEF", "EXTERN", "STATIC",
  "AUTO", "REGISTER", "CHAR", "SHORT", "INT", "LONG", "SIGNED", "UNSIGNED",
  "FLOAT", "DOUBLE", "CONST", "VOLATILE", "VOID", "STRUCT", "UNION",
  "ENUM", "ELLIPSIS", "CASE", "DEFAULT", "IF", "ELSE", "SWITCH", "WHILE",
  "DO", "FOR", "GOTO", "CONTINUE", "BREAK", "RETURN", "'('", "')'", "'['",
  "']'", "'.'", "','", "'&'", "'*'", "'+'", "'-'", "'~'", "'!'", "'/'",
  "'%'", "'<'", "'>'", "'^'", "'|'", "'?'", "':'", "'='", "';'", "'{'",
  "'}'", "$accept", "primary_expression", "postfix_expression",
  "argument_expression_list", "unary_expression", "unary_operator",
  "cast_expression", "multiplicative_expression", "additive_expression",
  "shift_expression", "relational_expression", "equality_expression",
  "and_expression", "exclusive_or_expression", "inclusive_or_expression",
  "logical_and_expression", "logical_or_expression",
  "conditional_expression", "assignment_expression", "assignment_operator",
  "expression", "constant_expression", "declaration",
  "declaration_specifiers", "init_declarator_list", "init_declarator",
  "storage_class_specifier", "type_specifier", "struct_or_union_specifier",
  "struct_or_union", "struct_declaration_list", "struct_declaration",
  "specifier_qualifier_list", "struct_declarator_list",
  "struct_declarator", "enum_specifier", "enumerator_list", "enumerator",
  "type_qualifier", "declarator", "direct_declarator", "pointer",
  "type_qualifier_list", "parameter_type_list", "parameter_list",
  "parameter_declaration", "identifier_list", "type_name",
  "abstract_declarator", "direct_abstract_declarator", "initializer",
  "initializer_list", "statement", "labeled_statement",
  "compound_statement", "declaration_list", "statement_list",
  "expression_statement", "selection_statement", "iteration_statement",
  "jump_statement", "translation_unit", "external_declaration",
  "function_definition", 0
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
     315,   316,   317,   318,    40,    41,    91,    93,    46,    44,
      38,    42,    43,    45,   126,    33,    47,    37,    60,    62,
      94,   124,    63,    58,    61,    59,   123,   125
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    88,    89,    89,    89,    89,    89,    89,    89,    90,
      90,    90,    90,    90,    90,    90,    90,    91,    91,    92,
      92,    92,    92,    92,    92,    93,    93,    93,    93,    93,
      93,    94,    94,    95,    95,    95,    95,    96,    96,    96,
      97,    97,    97,    98,    98,    98,    98,    98,    99,    99,
      99,   100,   100,   101,   101,   102,   102,   103,   103,   104,
     104,   105,   105,   106,   106,   107,   107,   107,   107,   107,
     107,   107,   107,   107,   107,   107,   108,   108,   109,   110,
     110,   111,   111,   111,   111,   111,   111,   112,   112,   113,
     113,   114,   114,   114,   114,   114,   115,   115,   115,   115,
     115,   115,   115,   115,   115,   115,   115,   115,   116,   116,
     116,   117,   117,   118,   118,   119,   120,   120,   120,   120,
     121,   121,   122,   122,   122,   123,   123,   123,   124,   124,
     125,   125,   126,   126,   127,   127,   128,   128,   128,   128,
     128,   128,   128,   129,   129,   129,   129,   130,   130,   131,
     131,   132,   132,   133,   133,   133,   134,   134,   135,   135,
     136,   136,   136,   137,   137,   137,   137,   137,   137,   137,
     137,   137,   138,   138,   138,   139,   139,   140,   140,   140,
     140,   140,   140,   141,   141,   141,   142,   142,   142,   142,
     143,   143,   144,   144,   145,   145,   146,   146,   146,   147,
     147,   147,   147,   148,   148,   148,   148,   148,   149,   149,
     150,   150,   151,   151,   151,   151
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     1,     3,     1,
       4,     3,     4,     3,     3,     2,     2,     1,     3,     1,
       2,     2,     2,     2,     4,     1,     1,     1,     1,     1,
       1,     1,     4,     1,     3,     3,     3,     1,     3,     3,
       1,     3,     3,     1,     3,     3,     3,     3,     1,     3,
       3,     1,     3,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     5,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     1,     2,
       3,     1,     2,     1,     2,     1,     2,     1,     3,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     5,     4,
       2,     1,     1,     1,     2,     3,     2,     1,     2,     1,
       1,     3,     1,     2,     3,     4,     5,     2,     1,     3,
       1,     3,     1,     1,     2,     1,     1,     3,     4,     3,
       4,     4,     3,     1,     2,     2,     3,     1,     2,     1,
       3,     1,     3,     2,     2,     1,     1,     3,     1,     2,
       1,     1,     2,     3,     2,     3,     3,     4,     2,     3,
       3,     4,     1,     3,     4,     1,     3,     1,     1,     1,
       1,     1,     1,     3,     4,     3,     2,     3,     3,     4,
       1,     2,     1,     2,     1,     2,     5,     7,     5,     5,
       7,     6,     7,     3,     2,     2,     2,     3,     1,     2,
       1,     1,     4,     3,     3,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,   136,   107,    91,    92,    93,    94,    95,    97,    98,
      99,   100,   103,   104,   101,   102,   132,   133,    96,   111,
     112,     0,     0,   143,   211,     0,    81,    83,   105,     0,
     106,    85,     0,   135,     0,     0,   208,   210,   127,     0,
       0,   147,   145,   144,    79,     0,    87,    89,    82,    84,
     110,     0,    86,     0,   190,     0,   215,     0,     0,     0,
     134,     1,   209,     0,   130,     0,   128,   137,   148,   146,
       0,    80,     0,   213,     0,     0,   117,     0,   113,     0,
     119,     3,     4,     5,     6,     2,     7,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    25,    26,    27,    28,    29,    30,   194,   186,
       9,    19,    31,     0,    33,    37,    40,    43,    48,    51,
      53,    55,    57,    59,    61,    63,    76,     0,   192,   177,
     178,     0,     0,   179,   180,   181,   182,    89,   191,   214,
     156,   142,   155,     0,   149,   151,     0,     2,   139,    31,
      78,     0,     0,     0,     0,   125,    88,     0,   172,    90,
     212,     0,   116,   109,   114,     0,     0,   120,   122,   118,
       0,     0,    23,     0,    20,    21,     0,     0,     0,     0,
       0,     0,     0,     0,   204,   205,   206,     0,     0,   158,
       0,     0,    15,    16,     0,     0,     0,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    65,     0,    22,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     195,   188,     0,   187,   193,     0,     0,   153,   160,   154,
     161,   140,     0,   141,     0,   138,   126,   131,   129,   175,
       0,   108,   123,     0,   115,     0,   183,     0,     0,   185,
       0,     0,     0,     0,     0,   203,   207,     8,     0,   160,
     159,     0,    14,    11,     0,    17,     0,    13,    64,    34,
      35,    36,    38,    39,    41,    42,    46,    47,    44,    45,
      49,    50,    52,    54,    56,    58,    60,     0,    77,   189,
     168,     0,     0,   164,     0,   162,     0,     0,   150,   152,
     157,     0,   173,   121,   124,    24,   184,     0,     0,     0,
       0,     0,    32,    12,     0,    10,     0,   169,   163,   165,
     170,     0,   166,     0,   174,   176,   196,   198,   199,     0,
       0,     0,    18,    62,   171,   167,     0,     0,   201,     0,
     197,   200,   202
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,   110,   111,   274,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   208,
     127,   151,    54,    55,    45,    46,    26,    27,    28,    29,
      77,    78,    79,   166,   167,    30,    65,    66,    31,    32,
      33,    34,    43,   301,   144,   145,   146,   190,   302,   240,
     159,   250,   128,   129,   130,    57,   132,   133,   134,   135,
     136,    35,    36,    37
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -219
static const yytype_int16 yypact[] =
{
    1055,  -219,  -219,  -219,  -219,  -219,  -219,  -219,  -219,  -219,
    -219,  -219,  -219,  -219,  -219,  -219,  -219,  -219,  -219,  -219,
    -219,    -1,    40,   -22,  -219,    35,  1269,  1269,  -219,     8,
    -219,  1269,  1116,    46,    15,  1011,  -219,  -219,   -18,    23,
      -5,  -219,  -219,   -22,  -219,   -13,  -219,  1096,  -219,  -219,
      12,  1146,  -219,   292,  -219,    35,  -219,  1116,   446,   746,
      46,  -219,  -219,    23,    29,   -62,  -219,  -219,  -219,  -219,
      40,  -219,   637,  -219,  1116,  1146,  1146,   356,  -219,    64,
    1146,  -219,  -219,  -219,  -219,    49,  -219,   880,   953,   953,
     965,    60,    43,    85,    92,   619,   145,   204,   131,   164,
     656,   759,  -219,  -219,  -219,  -219,  -219,  -219,  -219,  -219,
    -219,   142,   286,   965,  -219,    24,   109,   187,   135,   210,
     184,   175,   177,   240,    -6,  -219,  -219,    -3,  -219,  -219,
    -219,   377,   462,  -219,  -219,  -219,  -219,   176,  -219,  -219,
    -219,  -219,   123,   196,   197,  -219,   119,  -219,  -219,  -219,
    -219,   198,   -28,   965,    23,  -219,  -219,   637,  -219,  -219,
    -219,   944,  -219,  -219,  -219,   965,    34,  -219,   188,  -219,
     619,   759,  -219,   965,  -219,  -219,   189,   619,   965,   965,
     965,   213,   710,   182,  -219,  -219,  -219,    55,   126,    70,
     208,   267,  -219,  -219,   832,   965,   269,  -219,  -219,  -219,
    -219,  -219,  -219,  -219,  -219,  -219,  -219,  -219,   965,  -219,
     965,   965,   965,   965,   965,   965,   965,   965,   965,   965,
     965,   965,   965,   965,   965,   965,   965,   965,   965,   965,
    -219,  -219,   498,  -219,  -219,   568,   844,  -219,    14,  -219,
      80,  -219,  1248,  -219,   270,  -219,  -219,  -219,  -219,  -219,
     -14,  -219,  -219,    64,  -219,   965,  -219,   214,   619,  -219,
     127,   128,   152,   216,   710,  -219,  -219,  -219,  1172,    91,
    -219,   965,  -219,  -219,   153,  -219,   174,  -219,  -219,  -219,
    -219,  -219,    24,    24,   109,   109,   187,   187,   187,   187,
     135,   135,   210,   184,   175,   177,   240,   -16,  -219,  -219,
    -219,   217,   218,  -219,   211,    80,  1213,   856,  -219,  -219,
    -219,   583,  -219,  -219,  -219,  -219,  -219,   619,   619,   619,
     965,   868,  -219,  -219,   965,  -219,   965,  -219,  -219,  -219,
    -219,   219,  -219,   220,  -219,  -219,   226,  -219,  -219,   154,
     619,   160,  -219,  -219,  -219,  -219,   619,   201,  -219,   619,
    -219,  -219,  -219
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -219,  -219,  -219,  -219,   -51,  -219,   -85,    20,    30,    19,
      26,    65,    66,    67,    63,    75,  -219,   -57,   -71,  -219,
     -90,   -56,    17,     0,  -219,   223,  -219,   -32,  -219,  -219,
     230,   -68,   -26,  -219,    68,  -219,   254,   165,    41,    -9,
     -31,   -11,  -219,   -54,  -219,    76,  -219,   149,  -124,  -218,
    -128,  -219,   -55,  -219,   158,    10,   191,  -177,  -219,  -219,
    -219,  -219,   308,  -219
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
      25,   158,   150,    60,   143,   264,    38,   154,   149,   164,
     187,   188,    42,    40,   227,    50,    47,    24,   239,    76,
     305,     1,     1,    16,    17,   155,    48,    49,   209,   249,
      64,    52,    69,   150,   176,    25,   172,   174,   175,   149,
     181,   154,     1,    76,    76,    76,   137,     1,    76,    23,
     162,   305,    24,   229,   169,   311,    70,    74,   142,   246,
      67,   137,   149,   131,    41,   270,   229,   326,    63,    76,
     168,     1,    71,   312,   138,   189,   228,   234,   235,    22,
     236,   188,   230,   188,    68,    39,   158,   321,   260,   261,
     262,   138,    80,   164,    51,   210,   150,   247,    75,    22,
     211,   212,   149,   253,    22,   276,    23,   178,   150,   252,
      58,    23,    59,   153,   149,   256,    80,    80,    80,   254,
      44,    80,   259,   275,   229,   279,   280,   281,    22,    76,
       1,   238,   170,   237,   268,    23,   236,   278,   297,    76,
     266,    23,    80,   177,   306,   189,   307,   165,   138,   179,
     217,   218,   191,   192,   193,   268,   180,   236,   298,   149,
     149,   149,   149,   149,   149,   149,   149,   149,   149,   149,
     149,   149,   149,   149,   149,   149,   149,   234,   269,   150,
     304,   213,   214,   335,   243,   149,   322,   235,   244,   236,
      56,   267,   317,   318,    23,   229,   229,   229,   150,   314,
     215,   216,    80,   316,   149,    73,   194,    60,   195,   182,
     196,   183,    80,   219,   220,   139,   184,   319,   323,   347,
     149,   229,   324,   229,   238,   349,    40,   221,   222,   229,
     339,   341,   160,   282,   283,   142,   286,   287,   288,   289,
     158,   325,   142,   229,   168,   284,   285,   290,   291,   185,
     150,   333,   331,   342,   223,   224,   149,   269,   225,   226,
      72,   241,   336,   337,   338,   245,   242,   265,   142,   343,
     263,   255,   258,   271,   272,   149,   277,   310,   329,   315,
     320,   346,   327,   328,   344,   348,   351,   345,   292,   295,
     293,   350,   294,   156,   352,    81,    82,    83,    84,    85,
      86,    87,   296,    88,    89,   161,   142,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   152,   309,   248,
     257,   313,   232,     2,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    62,    90,    91,    92,     0,    93,    94,
      95,    96,    97,    98,    99,   100,   101,     0,     0,     0,
       0,     0,   102,   103,   104,   105,   106,   107,     0,     0,
     207,     0,     0,     0,     0,     0,     0,   108,    53,   109,
      81,    82,    83,    84,    85,    86,    87,     2,    88,    89,
       0,     0,     0,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,     0,     2,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,     0,    90,
      91,    92,     0,    93,    94,    95,    96,    97,    98,    99,
     100,   101,     0,   163,     0,     0,     0,   102,   103,   104,
     105,   106,   107,   140,     0,     0,     0,     0,     0,     0,
       0,     0,   108,    53,   231,    81,    82,    83,    84,    85,
      86,    87,     0,    88,    89,     0,     0,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,     0,     0,     0,
       0,    81,    82,    83,    84,    85,    86,    87,     0,    88,
      89,   141,     0,     0,    90,    91,    92,     0,    93,    94,
      95,    96,    97,    98,    99,   100,   101,     0,     0,     0,
       0,     0,   102,   103,   104,   105,   106,   107,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   108,    53,   233,
      90,    91,    92,     0,    93,    94,    95,    96,    97,    98,
      99,   100,   101,     0,     0,     0,     0,     0,   102,   103,
     104,   105,   106,   107,     0,     1,     0,     0,     0,     0,
       0,     0,     0,   108,    53,   299,    81,    82,    83,    84,
     147,    86,    87,     0,    88,    89,     0,     0,     0,     2,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,     0,
       0,     0,    81,    82,    83,    84,    85,    86,    87,     0,
      88,    89,   235,   300,   236,     0,     0,     0,     0,    23,
      81,    82,    83,    84,   147,    86,    87,   101,    88,    89,
       0,     0,     0,   102,   103,   104,   105,   106,   107,    81,
      82,    83,    84,   147,    86,    87,     0,    88,    89,   157,
     334,    90,    91,    92,     0,    93,    94,    95,    96,    97,
      98,    99,   100,   101,     0,     0,     0,     0,     0,   102,
     103,   104,   105,   106,   107,     0,     0,     0,     0,     0,
       0,   101,     0,     0,   108,    53,     0,   102,   103,   104,
     105,   106,   107,    81,    82,    83,    84,   147,    86,    87,
     101,    88,    89,   157,     0,     0,   102,   103,   104,   105,
     106,   107,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   186,     0,     0,     0,     0,     0,     0,     0,    81,
      82,    83,    84,   147,    86,    87,     0,    88,    89,     0,
       0,     0,    81,    82,    83,    84,   147,    86,    87,     0,
      88,    89,     0,     0,   101,     0,     0,     0,     0,     0,
     102,   103,   104,   105,   106,   107,     0,     0,     0,     0,
       2,     0,     0,     0,     0,   108,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
     101,     0,     0,   148,     0,     0,   102,   103,   104,   105,
     106,   107,     0,   101,     0,     0,     0,     0,     0,   102,
     103,   104,   105,   106,   107,    81,    82,    83,    84,   147,
      86,    87,     0,    88,    89,     0,     0,    81,    82,    83,
      84,   147,    86,    87,     0,    88,    89,     0,     0,    81,
      82,    83,    84,   147,    86,    87,     0,    88,    89,     0,
       0,    81,    82,    83,    84,   147,    86,    87,     0,    88,
      89,     0,     0,    81,    82,    83,    84,   147,    86,    87,
       0,    88,    89,     0,     0,     0,   101,   273,     0,     0,
       0,     0,   102,   103,   104,   105,   106,   107,   101,     0,
       0,   303,     0,     0,   102,   103,   104,   105,   106,   107,
     101,     0,     0,   332,     0,     0,   102,   103,   104,   105,
     106,   107,   101,   340,     0,     0,     0,     0,   102,   103,
     104,   105,   106,   107,   171,     0,     0,     0,     0,     0,
     102,   103,   104,   105,   106,   107,    81,    82,    83,    84,
     147,    86,    87,     0,    88,    89,     0,     0,    81,    82,
      83,    84,   147,    86,    87,     2,    88,    89,     0,     0,
       0,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    61,     0,     0,     0,     0,     0,   173,     1,     0,
       0,     0,     0,   102,   103,   104,   105,   106,   107,   101,
       0,   251,     0,     0,     0,   102,   103,   104,   105,   106,
     107,     0,     2,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,     1,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    22,     0,     0,     0,     0,
       0,     0,    23,     0,     0,     0,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    22,
       0,     0,     0,     0,     0,     0,    23,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     2,     0,     0,
      72,     0,    53,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,     0,     0,     0,
       0,     0,    53,     2,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   268,   300,   236,     0,
       0,     0,     0,    23,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   330,     2,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,   308,
       2,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21
};

static const yytype_int16 yycheck[] =
{
       0,    72,    59,    34,    58,   182,     7,    69,    59,    77,
     100,   101,    23,    22,    20,     7,    25,     0,   142,    51,
     238,     7,     7,    45,    46,    87,    26,    27,   113,   157,
       7,    31,    43,    90,    90,    35,    87,    88,    89,    90,
      95,    69,     7,    75,    76,    77,    55,     7,    80,    71,
      76,   269,    35,    69,    80,    69,    69,    47,    58,    87,
      65,    70,   113,    53,    23,   189,    69,    83,    86,   101,
      79,     7,    85,    87,    57,   101,    82,   132,    64,    64,
      66,   171,    85,   173,    43,    86,   157,   264,   178,   179,
     180,    74,    51,   161,    86,    71,   153,   153,    86,    64,
      76,    77,   153,    69,    64,   195,    71,    64,   165,   165,
      64,    71,    66,    84,   165,   170,    75,    76,    77,    85,
      85,    80,   177,   194,    69,   210,   211,   212,    64,   161,
       7,   142,    83,   142,    64,    71,    66,   208,   228,   171,
      85,    71,   101,    83,    64,   171,    66,    83,   131,    64,
      15,    16,    10,    11,    12,    64,    64,    66,   229,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   232,   189,   236,
     236,    72,    73,   311,    65,   236,   271,    64,    69,    66,
      32,    65,    65,    65,    71,    69,    69,    69,   255,   255,
      13,    14,   161,   258,   255,    47,    64,   238,    66,    64,
      68,     7,   171,    78,    79,    57,    85,    65,    65,    65,
     271,    69,    69,    69,   235,    65,   235,    17,    18,    69,
     320,   321,    74,   213,   214,   235,   217,   218,   219,   220,
     311,    67,   242,    69,   253,   215,   216,   221,   222,    85,
     307,   307,   306,   324,    70,    80,   307,   268,    81,    19,
      84,    65,   317,   318,   319,    67,    69,    85,   268,   326,
      57,    83,    83,    65,     7,   326,     7,     7,    67,    65,
      64,    55,    65,    65,    65,   340,    85,    67,   223,   226,
     224,   346,   225,    70,   349,     3,     4,     5,     6,     7,
       8,     9,   227,    11,    12,    75,   306,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    63,   242,   154,
     171,   253,   131,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    35,    52,    53,    54,    -1,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    -1,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    -1,    -1,
      84,    -1,    -1,    -1,    -1,    -1,    -1,    85,    86,    87,
       3,     4,     5,     6,     7,     8,     9,    31,    11,    12,
      -1,    -1,    -1,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    -1,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    -1,    52,
      53,    54,    -1,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    -1,    87,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,     7,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    85,    86,    87,     3,     4,     5,     6,     7,
       8,     9,    -1,    11,    12,    -1,    -1,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    -1,    -1,    -1,
      -1,     3,     4,     5,     6,     7,     8,     9,    -1,    11,
      12,    65,    -1,    -1,    52,    53,    54,    -1,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    -1,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    85,    86,    87,
      52,    53,    54,    -1,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    -1,     7,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    85,    86,    87,     3,     4,     5,     6,
       7,     8,     9,    -1,    11,    12,    -1,    -1,    -1,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    -1,
      -1,    -1,     3,     4,     5,     6,     7,     8,     9,    -1,
      11,    12,    64,    65,    66,    -1,    -1,    -1,    -1,    71,
       3,     4,     5,     6,     7,     8,     9,    64,    11,    12,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,     3,
       4,     5,     6,     7,     8,     9,    -1,    11,    12,    86,
      87,    52,    53,    54,    -1,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    -1,    -1,    -1,    -1,    -1,
      -1,    64,    -1,    -1,    85,    86,    -1,    70,    71,    72,
      73,    74,    75,     3,     4,     5,     6,     7,     8,     9,
      64,    11,    12,    86,    -1,    -1,    70,    71,    72,    73,
      74,    75,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    85,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,
       4,     5,     6,     7,     8,     9,    -1,    11,    12,    -1,
      -1,    -1,     3,     4,     5,     6,     7,     8,     9,    -1,
      11,    12,    -1,    -1,    64,    -1,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    -1,    -1,    -1,    -1,
      31,    -1,    -1,    -1,    -1,    85,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      64,    -1,    -1,    67,    -1,    -1,    70,    71,    72,    73,
      74,    75,    -1,    64,    -1,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,     3,     4,     5,     6,     7,
       8,     9,    -1,    11,    12,    -1,    -1,     3,     4,     5,
       6,     7,     8,     9,    -1,    11,    12,    -1,    -1,     3,
       4,     5,     6,     7,     8,     9,    -1,    11,    12,    -1,
      -1,     3,     4,     5,     6,     7,     8,     9,    -1,    11,
      12,    -1,    -1,     3,     4,     5,     6,     7,     8,     9,
      -1,    11,    12,    -1,    -1,    -1,    64,    65,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    64,    -1,
      -1,    67,    -1,    -1,    70,    71,    72,    73,    74,    75,
      64,    -1,    -1,    67,    -1,    -1,    70,    71,    72,    73,
      74,    75,    64,    65,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    64,    -1,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,     3,     4,     5,     6,
       7,     8,     9,    -1,    11,    12,    -1,    -1,     3,     4,
       5,     6,     7,     8,     9,    31,    11,    12,    -1,    -1,
      -1,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     0,    -1,    -1,    -1,    -1,    -1,    64,     7,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    64,
      -1,    87,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    -1,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,     7,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    64,    -1,    -1,    -1,    -1,
      -1,    -1,    71,    -1,    -1,    -1,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    64,
      -1,    -1,    -1,    -1,    -1,    -1,    71,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,    -1,    -1,
      84,    -1,    86,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    -1,    -1,    -1,
      -1,    -1,    86,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    64,    65,    66,    -1,
      -1,    -1,    -1,    71,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    65,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     7,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    64,    71,   110,   111,   114,   115,   116,   117,
     123,   126,   127,   128,   129,   149,   150,   151,     7,    86,
     127,   126,   129,   130,    85,   112,   113,   127,   111,   111,
       7,    86,   111,    86,   110,   111,   142,   143,    64,    66,
     128,     0,   150,    86,     7,   124,   125,    65,   126,   129,
      69,    85,    84,   142,   143,    86,   115,   118,   119,   120,
     126,     3,     4,     5,     6,     7,     8,     9,    11,    12,
      52,    53,    54,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    70,    71,    72,    73,    74,    75,    85,    87,
      89,    90,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   108,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   127,   110,   142,
       7,    65,   111,   131,   132,   133,   134,     7,    67,    92,
     105,   109,   124,    84,    69,    87,   113,    86,   106,   138,
     142,   118,   120,    87,   119,    83,   121,   122,   127,   120,
      83,    64,    92,    64,    92,    92,   109,    83,    64,    64,
      64,   140,    64,     7,    85,    85,    85,   108,   108,   120,
     135,    10,    11,    12,    64,    66,    68,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    84,   107,    94,
      71,    76,    77,    72,    73,    13,    14,    15,    16,    78,
      79,    17,    18,    70,    80,    81,    19,    20,    82,    69,
      85,    87,   144,    87,   140,    64,    66,   127,   129,   136,
     137,    65,    69,    65,    69,    67,    87,   109,   125,   138,
     139,    87,   109,    69,    85,    83,   140,   135,    83,   140,
     108,   108,   108,    57,   145,    85,    85,    65,    64,   129,
     136,    65,     7,    65,    91,   106,   108,     7,   106,    94,
      94,    94,    95,    95,    96,    96,    97,    97,    97,    97,
      98,    98,    99,   100,   101,   102,   103,   108,   106,    87,
      65,   131,   136,    67,   109,   137,    64,    66,    51,   133,
       7,    69,    87,   122,   109,    65,   140,    65,    65,    65,
      64,   145,    94,    65,    69,    67,    83,    65,    65,    67,
      65,   131,    67,   109,    87,   138,   140,   140,   140,   108,
      65,   108,   106,   105,    65,    67,    55,    65,   140,    65,
     140,    85,   140
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
#line 41 "c.y"
    {
    node = malloc(sizeof(struct PrimaryExpression));
    ((struct PrimaryExpression*)node)->type = 0;
    ((struct PrimaryExpression*)node)->identifier = (char*)(yyvsp[(1) - (1)].nPtr);
    (yyval.nPtr) = node;
}
    break;

  case 3:
#line 47 "c.y"
    {
    node = malloc(sizeof(struct PrimaryExpression));
    ((struct PrimaryExpression*)node)->type = 1;
    ((struct PrimaryExpression*)node)->iValue = (int)(yyvsp[(1) - (1)].iValue);
    (yyval.nPtr) = node;
}
    break;

  case 4:
#line 53 "c.y"
    {
    node = malloc(sizeof(struct PrimaryExpression));
    ((struct PrimaryExpression*)node)->type = 2;
    ((struct PrimaryExpression*)node)->cValue = (char)(yyvsp[(1) - (1)].cValue);
    (yyval.nPtr) = node;
}
    break;

  case 5:
#line 59 "c.y"
    {
    node = malloc(sizeof(struct PrimaryExpression));
    ((struct PrimaryExpression*)node)->type = 3;
    ((struct PrimaryExpression*)node)->fValue = (float)(yyvsp[(1) - (1)].fValue);
    (yyval.nPtr) = node;
}
    break;

  case 6:
#line 65 "c.y"
    {
    node = malloc(sizeof(struct PrimaryExpression));
    ((struct PrimaryExpression*)node)->type = 4;
    ((struct PrimaryExpression*)node)->dValue = (double)(yyvsp[(1) - (1)].dValue);
    (yyval.nPtr) = node;
}
    break;

  case 7:
#line 71 "c.y"
    {
    node = malloc(sizeof(struct PrimaryExpression));
    ((struct PrimaryExpression*)node)->type = 5;
    ((struct PrimaryExpression*)node)->literal = (char*)(yyvsp[(1) - (1)].nPtr);
    (yyval.nPtr) = node;
}
    break;

  case 8:
#line 77 "c.y"
    {
    node = malloc(sizeof(struct PrimaryExpression));
    ((struct PrimaryExpression*)node)->type = 6;
    ((struct PrimaryExpression*)node)->expression = (struct Expression*)(yyvsp[(2) - (3)].nPtr);
    (yyval.nPtr) = node;
}
    break;

  case 9:
#line 86 "c.y"
    {
    node = malloc(sizeof(struct PostfixExpression));
    ((struct PostfixExpression*)node)->type = 0;
    ((struct PostfixExpression*)node)->primaryExpression = (struct PrimaryExpression*)(yyvsp[(1) - (1)].nPtr);
    (yyval.nPtr) = node;
}
    break;

  case 10:
#line 92 "c.y"
    {
    node = malloc(sizeof(struct PostfixExpression));
    ((struct PostfixExpression*)node)->type = 1;
    ((struct PostfixExpression*)node)->postfixExpression = (struct PostfixExpression*)(yyvsp[(1) - (4)].nPtr);
    ((struct PostfixExpression*)node)->expression = (struct Expression*)(yyvsp[(3) - (4)].nPtr);
    (yyval.nPtr) = node;
}
    break;

  case 11:
#line 99 "c.y"
    {
    node = malloc(sizeof(struct PostfixExpression));
    ((struct PostfixExpression*)node)->type = 2;
    ((struct PostfixExpression*)node)->postfixExpression = (struct PostfixExpression*)(yyvsp[(1) - (3)].nPtr);
    (yyval.nPtr) = node;
}
    break;

  case 12:
#line 105 "c.y"
    {
    node = malloc(sizeof(struct PostfixExpression));
    ((struct PostfixExpression*)node)->type = 3;
    ((struct PostfixExpression*)node)->postfixExpression = (struct PostfixExpression*)(yyvsp[(1) - (4)].nPtr);
    ((struct PostfixExpression*)node)->argumentExpressionList = (struct ArgumentExpressionList*)(yyvsp[(3) - (4)].nPtr);
    (yyval.nPtr) = node;
}
    break;

  case 13:
#line 112 "c.y"
    {
    node = malloc(sizeof(struct PostfixExpression));
    ((struct PostfixExpression*)node)->type = 4;
    ((struct PostfixExpression*)node)->postfixExpression = (struct PostfixExpression*)(yyvsp[(1) - (3)].nPtr);
    ((struct PostfixExpression*)node)->identifier = (char*)(yyvsp[(3) - (3)].nPtr);
    (yyval.nPtr) = node;
}
    break;

  case 14:
#line 119 "c.y"
    {
    node = malloc(sizeof(struct PostfixExpression));
    ((struct PostfixExpression*)node)->type = 5;
    ((struct PostfixExpression*)node)->postfixExpression = (struct PostfixExpression*)(yyvsp[(1) - (3)].nPtr);
    ((struct PostfixExpression*)node)->identifier = (char*)(yyvsp[(3) - (3)].nPtr);
    (yyval.nPtr) = node;
}
    break;

  case 15:
#line 126 "c.y"
    {
    node = malloc(sizeof(struct PostfixExpression));
    ((struct PostfixExpression*)node)->type = 6;
    ((struct PostfixExpression*)node)->postfixExpression = (struct PostfixExpression*)(yyvsp[(1) - (2)].nPtr);
    (yyval.nPtr) = node;
}
    break;

  case 16:
#line 132 "c.y"
    {
    node = malloc(sizeof(struct PostfixExpression));
    ((struct PostfixExpression*)node)->type = 7;
    ((struct PostfixExpression*)node)->postfixExpression = (struct PostfixExpression*)(yyvsp[(1) - (2)].nPtr);
    (yyval.nPtr) = node;
}
    break;

  case 17:
#line 141 "c.y"
    {
    node = malloc(sizeof(struct ArgumentExpressionList));
    ((struct ArgumentExpressionList*)node)->type = 0;
    ((struct ArgumentExpressionList*)node)->assignmentExpression = (struct AssignmentExpression*)(yyvsp[(1) - (1)].nPtr);
    (yyval.nPtr) = node;
}
    break;

  case 18:
#line 147 "c.y"
    {
    node = malloc(sizeof(struct ArgumentExpressionList));
    ((struct ArgumentExpressionList*)node)->type = 1;
    ((struct ArgumentExpressionList*)node)->argumentExpressionList = (struct ArgumentExpressionList*)(yyvsp[(1) - (3)].nPtr);
    ((struct ArgumentExpressionList*)node)->assignmentExpression = (struct AssignmentExpression*)(yyvsp[(3) - (3)].nPtr);
    (yyval.nPtr) = node;
}
    break;

  case 19:
#line 157 "c.y"
    {
    node = malloc(sizeof(struct UnaryExpression));
    ((struct UnaryExpression*)node)->type = 0;
    ((struct UnaryExpression*)node)->postfixExpression = (struct PostfixExpression*)(yyvsp[(1) - (1)].nPtr);
    (yyval.nPtr) = node;
}
    break;

  case 20:
#line 163 "c.y"
    {
    node = malloc(sizeof(struct UnaryExpression));
    ((struct UnaryExpression*)node)->type = 1;
    ((struct UnaryExpression*)node)->unaryExpression = (struct UnaryExpression*)(yyvsp[(2) - (2)].nPtr);
    (yyval.nPtr) = node;
}
    break;

  case 21:
#line 169 "c.y"
    {
    node = malloc(sizeof(struct UnaryExpression));
    ((struct UnaryExpression*)node)->type = 2;
    ((struct UnaryExpression*)node)->unaryExpression = (struct UnaryExpression*)(yyvsp[(2) - (2)].nPtr);
    (yyval.nPtr) = node;
}
    break;

  case 22:
#line 175 "c.y"
    {
    node = malloc(sizeof(struct UnaryExpression));
    ((struct UnaryExpression*)node)->type = 3;
    ((struct UnaryExpression*)node)->unaryOperator = (char)(yyvsp[(1) - (2)].iValue);
    ((struct UnaryExpression*)node)->castExpression = (struct CastExpression*)(yyvsp[(2) - (2)].nPtr);
    (yyval.nPtr) = node;
}
    break;

  case 23:
#line 182 "c.y"
    {
    node = malloc(sizeof(struct UnaryExpression));
    ((struct UnaryExpression*)node)->type = 4;
    ((struct UnaryExpression*)node)->unaryExpression = (struct UnaryExpression*)(yyvsp[(2) - (2)].nPtr);
    (yyval.nPtr) = node;
}
    break;

  case 24:
#line 188 "c.y"
    {
    node = malloc(sizeof(struct UnaryExpression));
    ((struct UnaryExpression*)node)->type = 5;
    ((struct UnaryExpression*)node)->typeName = (struct TypeName*)(yyvsp[(3) - (4)].nPtr);
    (yyval.nPtr) = node;
}
    break;

  case 25:
#line 197 "c.y"
    { (yyval.iValue) = 1; }
    break;

  case 26:
#line 198 "c.y"
    { (yyval.iValue) = 2; }
    break;

  case 27:
#line 199 "c.y"
    { (yyval.iValue) = 3; }
    break;

  case 28:
#line 200 "c.y"
    { (yyval.iValue) = 4; }
    break;

  case 29:
#line 201 "c.y"
    { (yyval.iValue) = 5; }
    break;

  case 30:
#line 202 "c.y"
    { (yyval.iValue) = 6; }
    break;

  case 31:
#line 206 "c.y"
    {
    node = malloc(sizeof(struct CastExpression));
    ((struct CastExpression*)node)->type = 0;
    ((struct CastExpression*)node)->unaryExpression = (struct UnaryExpression*)(yyvsp[(1) - (1)].nPtr);
    (yyval.nPtr) = node;
}
    break;

  case 32:
#line 212 "c.y"
    {
    node = malloc(sizeof(struct CastExpression));
    ((struct CastExpression*)node)->type = 1;
    ((struct CastExpression*)node)->typeName = (struct TypeName*)(yyvsp[(2) - (4)].nPtr);
    ((struct CastExpression*)node)->castExpression = (struct CastExpression*)(yyvsp[(4) - (4)].nPtr);
    (yyval.nPtr) = node;
}
    break;

  case 33:
#line 222 "c.y"
    {
    node = malloc(sizeof(struct MultiplicativeExpression));
    ((struct MultiplicativeExpression*)node)->type = 0;
    ((struct MultiplicativeExpression*)node)->castExpression = (struct CastExpression*)(yyvsp[(1) - (1)].nPtr);
    (yyval.nPtr) = node;
}
    break;

  case 34:
#line 228 "c.y"
    {
    node = malloc(sizeof(struct MultiplicativeExpression));
    ((struct MultiplicativeExpression*)node)->type = 1;
    ((struct MultiplicativeExpression*)node)->multiplicativeExpression = (struct MultiplicativeExpression*)(yyvsp[(1) - (3)].nPtr);
    ((struct MultiplicativeExpression*)node)->castExpression = (struct CastExpression*)(yyvsp[(3) - (3)].nPtr);
    (yyval.nPtr) = node;
}
    break;

  case 35:
#line 235 "c.y"
    {
    node = malloc(sizeof(struct MultiplicativeExpression));
    ((struct MultiplicativeExpression*)node)->type = 2;
    ((struct MultiplicativeExpression*)node)->multiplicativeExpression = (struct MultiplicativeExpression*)(yyvsp[(1) - (3)].nPtr);
    ((struct MultiplicativeExpression*)node)->castExpression = (struct CastExpression*)(yyvsp[(3) - (3)].nPtr);
    (yyval.nPtr) = node;
}
    break;

  case 36:
#line 242 "c.y"
    {
    node = malloc(sizeof(struct MultiplicativeExpression));
    ((struct MultiplicativeExpression*)node)->type = 3;
    ((struct MultiplicativeExpression*)node)->multiplicativeExpression = (struct MultiplicativeExpression*)(yyvsp[(1) - (3)].nPtr);
    ((struct MultiplicativeExpression*)node)->castExpression = (struct CastExpression*)(yyvsp[(3) - (3)].nPtr);
    (yyval.nPtr) = node;
}
    break;

  case 37:
#line 252 "c.y"
    {
    node = malloc(sizeof(struct AdditiveExpression));
    ((struct AdditiveExpression*)node)->type = 0;
    ((struct AdditiveExpression*)node)->multiplicativeExpression = (struct MultiplicativeExpression*)(yyvsp[(1) - (1)].nPtr);
    (yyval.nPtr) = node;
}
    break;

  case 38:
#line 258 "c.y"
    {
    node = malloc(sizeof(struct AdditiveExpression));
    ((struct AdditiveExpression*)node)->type = 1;
    ((struct AdditiveExpression*)node)->additiveExpression = (struct AdditiveExpression*)(yyvsp[(1) - (3)].nPtr);
    ((struct AdditiveExpression*)node)->multiplicativeExpression = (struct MultiplicativeExpression*)(yyvsp[(3) - (3)].nPtr);
    (yyval.nPtr) = node;
}
    break;

  case 39:
#line 265 "c.y"
    {
    node = malloc(sizeof(struct AdditiveExpression));
    ((struct AdditiveExpression*)node)->type = 2;
    ((struct AdditiveExpression*)node)->additiveExpression = (struct AdditiveExpression*)(yyvsp[(1) - (3)].nPtr);
    ((struct AdditiveExpression*)node)->multiplicativeExpression = (struct MultiplicativeExpression*)(yyvsp[(3) - (3)].nPtr);
    (yyval.nPtr) = node;
}
    break;

  case 40:
#line 275 "c.y"
    {
    node = malloc(sizeof(struct ShiftExpression));
    ((struct ShiftExpression*)node)->type = 0;
    ((struct ShiftExpression*)node)->additiveExpression = (struct AdditiveExpression*)(yyvsp[(1) - (1)].nPtr);
    (yyval.nPtr) = node;
}
    break;

  case 41:
#line 281 "c.y"
    {
    node = malloc(sizeof(struct ShiftExpression));
    ((struct ShiftExpression*)node)->type = 1;
    ((struct ShiftExpression*)node)->shiftExpression = (struct ShiftExpression*)(yyvsp[(1) - (3)].nPtr);
    ((struct ShiftExpression*)node)->additiveExpression = (struct AdditiveExpression*)(yyvsp[(3) - (3)].nPtr);
    (yyval.nPtr) = node;
}
    break;

  case 42:
#line 288 "c.y"
    {
    node = malloc(sizeof(struct ShiftExpression));
    ((struct ShiftExpression*)node)->type = 2;
    ((struct ShiftExpression*)node)->shiftExpression = (struct ShiftExpression*)(yyvsp[(1) - (3)].nPtr);
    ((struct ShiftExpression*)node)->additiveExpression = (struct AdditiveExpression*)(yyvsp[(3) - (3)].nPtr);
    (yyval.nPtr) = node;
}
    break;

  case 43:
#line 298 "c.y"
    {
    node = malloc(sizeof(struct RelationalExpression));
    ((struct RelationalExpression*)node)->type = 0;
    ((struct RelationalExpression*)node)->shiftExpression = (struct ShiftExpression*)(yyvsp[(1) - (1)].nPtr);
    (yyval.nPtr) = node;
}
    break;

  case 44:
#line 304 "c.y"
    {
    node = malloc(sizeof(struct RelationalExpression));
    ((struct RelationalExpression*)node)->type = 1;
    ((struct RelationalExpression*)node)->relationalExpression = (struct RelationalExpression*)(yyvsp[(1) - (3)].nPtr);
    ((struct RelationalExpression*)node)->shiftExpression = (struct ShiftExpression*)(yyvsp[(3) - (3)].nPtr);
    (yyval.nPtr) = node;
}
    break;

  case 45:
#line 311 "c.y"
    {
    node = malloc(sizeof(struct RelationalExpression));
    ((struct RelationalExpression*)node)->type = 2;
    ((struct RelationalExpression*)node)->relationalExpression = (struct RelationalExpression*)(yyvsp[(1) - (3)].nPtr);
    ((struct RelationalExpression*)node)->shiftExpression = (struct ShiftExpression*)(yyvsp[(3) - (3)].nPtr);
    (yyval.nPtr) = node;
}
    break;

  case 46:
#line 318 "c.y"
    {
    node = malloc(sizeof(struct RelationalExpression));
    ((struct RelationalExpression*)node)->type = 3;
    ((struct RelationalExpression*)node)->relationalExpression = (struct RelationalExpression*)(yyvsp[(1) - (3)].nPtr);
    ((struct RelationalExpression*)node)->shiftExpression = (struct ShiftExpression*)(yyvsp[(3) - (3)].nPtr);
    (yyval.nPtr) = node;
}
    break;

  case 47:
#line 325 "c.y"
    {
    node = malloc(sizeof(struct RelationalExpression));
    ((struct RelationalExpression*)node)->type = 4;
    ((struct RelationalExpression*)node)->relationalExpression = (struct RelationalExpression*)(yyvsp[(1) - (3)].nPtr);
    ((struct RelationalExpression*)node)->shiftExpression = (struct ShiftExpression*)(yyvsp[(3) - (3)].nPtr);
    (yyval.nPtr) = node;
}
    break;

  case 48:
#line 335 "c.y"
    {
    node = malloc(sizeof(struct EqualityExpression));
    ((struct EqualityExpression*)node)->type = 0;
    ((struct EqualityExpression*)node)->relationalExpression = (struct RelationalExpression*)(yyvsp[(1) - (1)].nPtr);
    (yyval.nPtr) = node;
}
    break;

  case 49:
#line 341 "c.y"
    {
    node = malloc(sizeof(struct EqualityExpression));
    ((struct EqualityExpression*)node)->type = 1;
    ((struct EqualityExpression*)node)->equalityExpression = (struct EqualityExpression*)(yyvsp[(1) - (3)].nPtr);
    ((struct EqualityExpression*)node)->relationalExpression = (struct RelationalExpression*)(yyvsp[(3) - (3)].nPtr);
    (yyval.nPtr) = node;
}
    break;

  case 50:
#line 348 "c.y"
    {
    node = malloc(sizeof(struct EqualityExpression));
    ((struct EqualityExpression*)node)->type = 2;
    ((struct EqualityExpression*)node)->equalityExpression = (struct EqualityExpression*)(yyvsp[(1) - (3)].nPtr);
    ((struct EqualityExpression*)node)->relationalExpression = (struct RelationalExpression*)(yyvsp[(3) - (3)].nPtr);
    (yyval.nPtr) = node;
}
    break;

  case 51:
#line 358 "c.y"
    {
    node = malloc(sizeof(struct AndExpression));
    ((struct AndExpression*)node)->type = 0;
    ((struct AndExpression*)node)->equalityExpression = (struct EqualityExpression*)(yyvsp[(1) - (1)].nPtr);
    (yyval.nPtr) = node;
}
    break;

  case 52:
#line 364 "c.y"
    {
    node = malloc(sizeof(struct AndExpression));
    ((struct AndExpression*)node)->type = 1;
    ((struct AndExpression*)node)->andExpression = (struct AndExpression*)(yyvsp[(1) - (3)].nPtr);
    ((struct AndExpression*)node)->equalityExpression = (struct EqualityExpression*)(yyvsp[(3) - (3)].nPtr);
    (yyval.nPtr) = node;
}
    break;

  case 53:
#line 374 "c.y"
    {
    node = malloc(sizeof(struct ExclusiveOrExpression));
    ((struct ExclusiveOrExpression*)node)->type = 0;
    ((struct ExclusiveOrExpression*)node)->andExpression = (struct AndExpression*)(yyvsp[(1) - (1)].nPtr);
    (yyval.nPtr) = node;
}
    break;

  case 54:
#line 380 "c.y"
    {
    node = malloc(sizeof(struct ExclusiveOrExpression));
    ((struct ExclusiveOrExpression*)node)->type = 1;
    ((struct ExclusiveOrExpression*)node)->exclusiveOrExpression = (struct ExclusiveOrExpression*)(yyvsp[(1) - (3)].nPtr);
    ((struct ExclusiveOrExpression*)node)->andExpression = (struct AndExpression*)(yyvsp[(3) - (3)].nPtr);
    (yyval.nPtr) = node;
}
    break;

  case 55:
#line 390 "c.y"
    {
    node = malloc(sizeof(struct InclusiveOrExpression));
    ((struct InclusiveOrExpression*)node)->type = 0;
    ((struct InclusiveOrExpression*)node)->exclusiveOrExpression = (struct ExclusiveOrExpression*)(yyvsp[(1) - (1)].nPtr);
    (yyval.nPtr) = node;
}
    break;

  case 56:
#line 396 "c.y"
    {
    node = malloc(sizeof(struct InclusiveOrExpression));
    ((struct InclusiveOrExpression*)node)->type = 1;
    ((struct InclusiveOrExpression*)node)->inclusiveOrExpression = (struct InclusiveOrExpression*)(yyvsp[(1) - (3)].nPtr);
    ((struct InclusiveOrExpression*)node)->exclusiveOrExpression = (struct ExclusiveOrExpression*)(yyvsp[(3) - (3)].nPtr);
    (yyval.nPtr) = node;
}
    break;

  case 57:
#line 406 "c.y"
    {
    node = malloc(sizeof(struct LogicalAndExpression));
    ((struct LogicalAndExpression*)node)->type = 0;
    ((struct LogicalAndExpression*)node)->inclusiveOrExpression = (struct InclusiveOrExpression*)(yyvsp[(1) - (1)].nPtr);
    (yyval.nPtr) = node;
}
    break;

  case 58:
#line 412 "c.y"
    {
    node = malloc(sizeof(struct LogicalAndExpression));
    ((struct LogicalAndExpression*)node)->type = 1;
    ((struct LogicalAndExpression*)node)->logicalAndExpression = (struct LogicalAndExpression*)(yyvsp[(1) - (3)].nPtr);
    ((struct LogicalAndExpression*)node)->inclusiveOrExpression = (struct InclusiveOrExpression*)(yyvsp[(3) - (3)].nPtr);
    (yyval.nPtr) = node;
}
    break;

  case 59:
#line 422 "c.y"
    {
    node = malloc(sizeof(struct LogicalOrExpression));
    ((struct LogicalOrExpression*)node)->type = 0;
    ((struct LogicalOrExpression*)node)->logicalAndExpression = (struct LogicalAndExpression*)(yyvsp[(1) - (1)].nPtr);
    (yyval.nPtr) = node;
}
    break;

  case 60:
#line 428 "c.y"
    {
    node = malloc(sizeof(struct LogicalOrExpression));
    ((struct LogicalOrExpression*)node)->type = 1;
    ((struct LogicalOrExpression*)node)->logicalOrExpression = (struct LogicalOrExpression*)(yyvsp[(1) - (3)].nPtr);
    ((struct LogicalOrExpression*)node)->logicalAndExpression = (struct LogicalAndExpression*)(yyvsp[(3) - (3)].nPtr);
    (yyval.nPtr) = node;
}
    break;

  case 61:
#line 438 "c.y"
    {
    node = malloc(sizeof(struct ConditionalExpression));
    ((struct ConditionalExpression*)node)->type = 0;
    ((struct ConditionalExpression*)node)->logicalOrExpression = (struct LogicalOrExpression*)(yyvsp[(1) - (1)].nPtr);
    (yyval.nPtr) = node;
}
    break;

  case 62:
#line 444 "c.y"
    {
    node = malloc(sizeof(struct ConditionalExpression));
    ((struct ConditionalExpression*)node)->type = 1;
    ((struct ConditionalExpression*)node)->logicalOrExpression = (struct LogicalOrExpression*)(yyvsp[(1) - (5)].nPtr);
    ((struct ConditionalExpression*)node)->expression = (struct Expression*)(yyvsp[(3) - (5)].nPtr);
    ((struct ConditionalExpression*)node)->conditionalExpression = (struct ConditionalExpression*)(yyvsp[(5) - (5)].nPtr);
    (yyval.nPtr) = node;
}
    break;

  case 63:
#line 455 "c.y"
    {
    node = malloc(sizeof(struct AssignmentExpression));
    ((struct AssignmentExpression*)node)->type = 0;
    ((struct AssignmentExpression*)node)->conditionalExpression = (struct ConditionalExpression*)(yyvsp[(1) - (1)].nPtr);
    (yyval.nPtr) = node;
}
    break;

  case 64:
#line 461 "c.y"
    {
    node = malloc(sizeof(struct AssignmentExpression));
    ((struct AssignmentExpression*)node)->type = 1;
    ((struct AssignmentExpression*)node)->unaryExpression = (struct UnaryExpression*)(yyvsp[(1) - (3)].nPtr);
    ((struct AssignmentExpression*)node)->assignmentOperator = (int)(yyvsp[(2) - (3)].iValue);
    ((struct AssignmentExpression*)node)->assignmentExpression = (struct AssignmentExpression*)(yyvsp[(3) - (3)].nPtr);
    (yyval.nPtr) = node;
}
    break;

  case 65:
#line 472 "c.y"
    { (yyval.iValue) = 1; }
    break;

  case 66:
#line 473 "c.y"
    { (yyval.iValue) = 2; }
    break;

  case 67:
#line 474 "c.y"
    { (yyval.iValue) = 3; }
    break;

  case 68:
#line 475 "c.y"
    { (yyval.iValue) = 4; }
    break;

  case 69:
#line 476 "c.y"
    { (yyval.iValue) = 5; }
    break;

  case 70:
#line 477 "c.y"
    { (yyval.iValue) = 6; }
    break;

  case 71:
#line 478 "c.y"
    { (yyval.iValue) = 7; }
    break;

  case 72:
#line 479 "c.y"
    { (yyval.iValue) = 8; }
    break;

  case 73:
#line 480 "c.y"
    { (yyval.iValue) = 9; }
    break;

  case 74:
#line 481 "c.y"
    { (yyval.iValue) = 10; }
    break;

  case 75:
#line 482 "c.y"
    { (yyval.iValue) = 11; }
    break;

  case 76:
#line 486 "c.y"
    {
    node = malloc(sizeof(struct Expression));
    ((struct Expression*)node)->type = 0;
    ((struct Expression*)node)->assignmentExpression = (struct AssignmentExpression*)(yyvsp[(1) - (1)].nPtr);
    (yyval.nPtr) = node;
}
    break;

  case 77:
#line 492 "c.y"
    {
    node = malloc(sizeof(struct Expression));
    ((struct Expression*)node)->type = 1;
    ((struct Expression*)node)->expression = (struct Expression*)(yyvsp[(1) - (3)].nPtr);
    ((struct Expression*)node)->assignmentExpression = (struct AssignmentExpression*)(yyvsp[(3) - (3)].nPtr);
    (yyval.nPtr) = node;
}
    break;

  case 78:
#line 502 "c.y"
    {
    node = malloc(sizeof(struct ConstantExpression));
    ((struct ConstantExpression*)node)->type = 0;
    ((struct ConstantExpression*)node)->conditionalExpression = (struct ConditionalExpression*)(yyvsp[(1) - (1)].nPtr);
    (yyval.nPtr) = node;
}
    break;

  case 79:
#line 511 "c.y"
    {
    node = malloc(sizeof(struct Declaration));
    ((struct Declaration*)node)->type = 0;
    ((struct Declaration*)node)->declarationSpecifiers = (struct DeclarationSpecifiers*)(yyvsp[(1) - (2)].nPtr);
    (yyval.nPtr) = node;
}
    break;

  case 80:
#line 517 "c.y"
    {
    node = malloc(sizeof(struct Declaration));
    ((struct Declaration*)node)->type = 1;
    ((struct Declaration*)node)->declarationSpecifiers = (struct DeclarationSpecifiers*)(yyvsp[(1) - (3)].nPtr);
    ((struct Declaration*)node)->initDeclaratorList = (struct InitDeclaratorList*)(yyvsp[(2) - (3)].nPtr);
    (yyval.nPtr) = node;
}
    break;

  case 81:
#line 527 "c.y"
    {
    node = malloc(sizeof(struct DeclarationSpecifiers));
    ((struct DeclarationSpecifiers*)node)->type = 0;
    ((struct DeclarationSpecifiers*)node)->storageClassSpecifier = (yyvsp[(1) - (1)].iValue);
    (yyval.nPtr) = node;
}
    break;

  case 82:
#line 533 "c.y"
    {
    node = malloc(sizeof(struct DeclarationSpecifiers));
    ((struct DeclarationSpecifiers*)node)->type = 1;
    ((struct DeclarationSpecifiers*)node)->storageClassSpecifier = (yyvsp[(1) - (2)].iValue);
    ((struct DeclarationSpecifiers*)node)->declarationSpecifiers = (struct DeclarationSpecifiers*)(yyvsp[(2) - (2)].nPtr);
    (yyval.nPtr) = node;
}
    break;

  case 83:
#line 540 "c.y"
    {
    node = malloc(sizeof(struct DeclarationSpecifiers));
    ((struct DeclarationSpecifiers*)node)->type = 2;
    ((struct DeclarationSpecifiers*)node)->typeSpecifier = (int)(yyvsp[(1) - (1)].iValue);
    (yyval.nPtr) = node;
}
    break;

  case 84:
#line 546 "c.y"
    {
    node = malloc(sizeof(struct DeclarationSpecifiers));
    ((struct DeclarationSpecifiers*)node)->type = 3;
    ((struct DeclarationSpecifiers*)node)->typeSpecifier = (int)(yyvsp[(1) - (2)].iValue);
    ((struct DeclarationSpecifiers*)node)->declarationSpecifiers = (struct DeclarationSpecifiers*)(yyvsp[(2) - (2)].nPtr);
    (yyval.nPtr) = node;
}
    break;

  case 85:
#line 553 "c.y"
    {
    node = malloc(sizeof(struct DeclarationSpecifiers));
    ((struct DeclarationSpecifiers*)node)->type = 4;
    ((struct DeclarationSpecifiers*)node)->typeQualifier = (int)(yyvsp[(1) - (1)].iValue);
    (yyval.nPtr) = node;
}
    break;

  case 86:
#line 559 "c.y"
    {
    node = malloc(sizeof(struct DeclarationSpecifiers));
    ((struct DeclarationSpecifiers*)node)->type = 5;
    ((struct DeclarationSpecifiers*)node)->typeQualifier = (int)(yyvsp[(1) - (2)].iValue);
    ((struct DeclarationSpecifiers*)node)->declarationSpecifiers = (struct DeclarationSpecifiers*)(yyvsp[(2) - (2)].nPtr);
    (yyval.nPtr) = node;
}
    break;

  case 87:
#line 569 "c.y"
    {
    node = malloc(sizeof(struct InitDeclaratorList));
    ((struct InitDeclaratorList*)node)->type = 0;
    ((struct InitDeclaratorList*)node)->initDeclarator = (struct InitDeclarator*)(yyvsp[(1) - (1)].nPtr);
    (yyval.nPtr) = node;
}
    break;

  case 88:
#line 575 "c.y"
    {
    node = malloc(sizeof(struct InitDeclaratorList));
    ((struct InitDeclaratorList*)node)->type = 1;
    ((struct InitDeclaratorList*)node)->initDeclaratorList = (struct InitDeclaratorList*)(yyvsp[(1) - (3)].nPtr);
    ((struct InitDeclaratorList*)node)->initDeclarator = (struct InitDeclarator*)(yyvsp[(3) - (3)].nPtr);
    (yyval.nPtr) = node;
}
    break;

  case 89:
#line 585 "c.y"
    {
    node = malloc(sizeof(struct InitDeclarator));
    ((struct InitDeclarator*)node)->type = 0;
    ((struct InitDeclarator*)node)->declarator = (struct Declarator*)(yyvsp[(1) - (1)].nPtr);
    (yyval.nPtr) = node;
}
    break;

  case 90:
#line 591 "c.y"
    {
    node = malloc(sizeof(struct InitDeclarator));
    ((struct InitDeclarator*)node)->type = 1;
    ((struct InitDeclarator*)node)->declarator = (struct Declarator*)(yyvsp[(1) - (3)].nPtr);
    ((struct InitDeclarator*)node)->initializer = (struct Initializer*)(yyvsp[(3) - (3)].nPtr);
    (yyval.nPtr) = node;
}
    break;

  case 91:
#line 601 "c.y"
    { (yyval.iValue) = 1; }
    break;

  case 92:
#line 602 "c.y"
    { (yyval.iValue) = 2; }
    break;

  case 93:
#line 603 "c.y"
    { (yyval.iValue) = 3; }
    break;

  case 94:
#line 604 "c.y"
    { (yyval.iValue) = 4; }
    break;

  case 95:
#line 605 "c.y"
    { (yyval.iValue) = 5; }
    break;

  case 96:
#line 609 "c.y"
    { (yyval.iValue) = 1; }
    break;

  case 97:
#line 610 "c.y"
    { (yyval.iValue) = 2; }
    break;

  case 98:
#line 611 "c.y"
    { (yyval.iValue) = 3; }
    break;

  case 99:
#line 612 "c.y"
    { (yyval.iValue) = 4; }
    break;

  case 100:
#line 613 "c.y"
    { (yyval.iValue) = 5; }
    break;

  case 101:
#line 614 "c.y"
    { (yyval.iValue) = 6; }
    break;

  case 102:
#line 615 "c.y"
    { (yyval.iValue) = 7; }
    break;

  case 103:
#line 616 "c.y"
    { (yyval.iValue) = 8; }
    break;

  case 104:
#line 617 "c.y"
    { (yyval.iValue) = 9; }
    break;

  case 105:
#line 618 "c.y"
    { (yyval.iValue) = 10; }
    break;

  case 106:
#line 619 "c.y"
    { (yyval.iValue) = 11; }
    break;

  case 107:
#line 620 "c.y"
    { (yyval.iValue) = 12; }
    break;

  case 108:
#line 624 "c.y"
    {
    
}
    break;

  case 109:
#line 627 "c.y"
    {
    
}
    break;

  case 110:
#line 630 "c.y"
    {
    
}
    break;

  case 111:
#line 636 "c.y"
    { (yyval.iValue) = 1; }
    break;

  case 112:
#line 637 "c.y"
    { (yyval.iValue) = 2; }
    break;

  case 113:
#line 641 "c.y"
    {
    node = malloc(sizeof(struct StructDeclarationList));
    ((struct StructDeclarationList*)node)->type = 0;
    ((struct StructDeclarationList*)node)->structDeclaration = (struct StructDeclaration*)(yyvsp[(1) - (1)].nPtr);
    (yyval.nPtr) = node;
}
    break;

  case 114:
#line 647 "c.y"
    {
    node = malloc(sizeof(struct StructDeclarationList));
    ((struct StructDeclarationList*)node)->type = 1;
    ((struct StructDeclarationList*)node)->structDeclarationList = (struct StructDeclarationList*)(yyvsp[(1) - (2)].nPtr);
    ((struct StructDeclarationList*)node)->structDeclaration = (struct StructDeclaration*)(yyvsp[(2) - (2)].nPtr);
    (yyval.nPtr) = node;
}
    break;

  case 115:
#line 657 "c.y"
    {
    node = malloc(sizeof(struct StructDeclaration));
    ((struct StructDeclaration*)node)->type = 0;
    ((struct StructDeclaration*)node)->specifierQualifierList = (struct SpecifierQualifierList*)(yyvsp[(1) - (3)].nPtr);
    ((struct StructDeclaration*)node)->structDeclaratorList = (struct StructDeclaratorList*)(yyvsp[(2) - (3)].nPtr);
    (yyval.nPtr) = node;
}
    break;

  case 116:
#line 667 "c.y"
    {
    node = malloc(sizeof(struct SpecifierQualifierList));
    ((struct SpecifierQualifierList*)node)->type = 0;
    ((struct SpecifierQualifierList*)node)->typeSpecifier = (int)(yyvsp[(1) - (2)].iValue);
    ((struct SpecifierQualifierList*)node)->specifierQualifierList = (struct SpecifierQualifierList*)(yyvsp[(2) - (2)].nPtr);
    (yyval.nPtr) = node;
}
    break;

  case 117:
#line 674 "c.y"
    {
    node = malloc(sizeof(struct SpecifierQualifierList));
    ((struct SpecifierQualifierList*)node)->type = 1;
    ((struct SpecifierQualifierList*)node)->typeSpecifier = (int)(yyvsp[(1) - (1)].iValue);
    (yyval.nPtr) = node;
}
    break;

  case 118:
#line 680 "c.y"
    {
    node = malloc(sizeof(struct SpecifierQualifierList));
    ((struct SpecifierQualifierList*)node)->type = 2;
    ((struct SpecifierQualifierList*)node)->typeQualifier = (int)(yyvsp[(1) - (2)].iValue);
    ((struct SpecifierQualifierList*)node)->specifierQualifierList = (struct SpecifierQualifierList*)(yyvsp[(2) - (2)].nPtr);
    (yyval.nPtr) = node;
}
    break;

  case 119:
#line 687 "c.y"
    {
    node = malloc(sizeof(struct SpecifierQualifierList));
    ((struct SpecifierQualifierList*)node)->type = 3;
    ((struct SpecifierQualifierList*)node)->typeQualifier = (int)(yyvsp[(1) - (1)].iValue);
    (yyval.nPtr) = node;
}
    break;

  case 120:
#line 696 "c.y"
    {
    node = malloc(sizeof(struct StructDeclaratorList));
    ((struct StructDeclaratorList*)node)->type = 0;
    ((struct StructDeclaratorList*)node)->structDeclarator = (struct StructDeclarator*)(yyvsp[(1) - (1)].nPtr);
    (yyval.nPtr) = node;
}
    break;

  case 121:
#line 702 "c.y"
    {
    node = malloc(sizeof(struct StructDeclaratorList));
    ((struct StructDeclaratorList*)node)->type = 1;
    ((struct StructDeclaratorList*)node)->structDeclaratorList = (struct StructDeclaratorList*)(yyvsp[(1) - (3)].nPtr);
    ((struct StructDeclaratorList*)node)->structDeclarator = (struct StructDeclarator*)(yyvsp[(3) - (3)].nPtr);
    (yyval.nPtr) = node;
}
    break;

  case 122:
#line 712 "c.y"
    {
    node = malloc(sizeof(struct StructDeclarator));
    ((struct StructDeclarator*)node)->type = 0;
    ((struct StructDeclarator*)node)->declarator = (struct Declarator*)(yyvsp[(1) - (1)].nPtr);
    (yyval.nPtr) = node;
}
    break;

  case 123:
#line 718 "c.y"
    {
    node = malloc(sizeof(struct StructDeclarator));
    ((struct StructDeclarator*)node)->type = 1;
    ((struct StructDeclarator*)node)->constantExpression = (struct ConstantExpression*)(yyvsp[(2) - (2)].nPtr);
    (yyval.nPtr) = node;
}
    break;

  case 124:
#line 724 "c.y"
    {
    node = malloc(sizeof(struct StructDeclarator));
    ((struct StructDeclarator*)node)->type = 2;
    ((struct StructDeclarator*)node)->declarator = (struct Declarator*)(yyvsp[(1) - (3)].nPtr);
    ((struct StructDeclarator*)node)->constantExpression = (struct ConstantExpression*)(yyvsp[(3) - (3)].nPtr);
    (yyval.nPtr) = node;
}
    break;

  case 125:
#line 734 "c.y"
    { (yyval.nPtr) = 0; }
    break;

  case 126:
#line 735 "c.y"
    { (yyval.nPtr) = 0; }
    break;

  case 127:
#line 736 "c.y"
    { (yyval.nPtr) = 0; }
    break;

  case 128:
#line 740 "c.y"
    {
    node = malloc(sizeof(struct EnumeratorList));
    ((struct EnumeratorList*)node)->type = 0;
    ((struct EnumeratorList*)node)->enumerator = (struct Enumerator*)(yyvsp[(1) - (1)].nPtr);
    (yyval.nPtr) = node;
}
    break;

  case 129:
#line 746 "c.y"
    {
    node = malloc(sizeof(struct EnumeratorList));
    ((struct EnumeratorList*)node)->type = 1;
    ((struct EnumeratorList*)node)->enumeratorList = (struct EnumeratorList*)(yyvsp[(1) - (3)].nPtr);
    ((struct EnumeratorList*)node)->enumerator = (struct Enumerator*)(yyvsp[(3) - (3)].nPtr);
    (yyval.nPtr) = node;
}
    break;

  case 132:
#line 761 "c.y"
    { (yyval.iValue) = 1; }
    break;

  case 133:
#line 762 "c.y"
    { (yyval.iValue) = 2; }
    break;

  case 134:
#line 766 "c.y"
    {
    node = malloc(sizeof(struct Declarator));
    ((struct Declarator*)node)->type = 0;
    ((struct Declarator*)node)->pointer = (struct Pointer*)(yyvsp[(1) - (2)].nPtr);
    ((struct Declarator*)node)->directDeclarator = (struct DirectDeclarator*)(yyvsp[(2) - (2)].nPtr);
    (yyval.nPtr) = node;
}
    break;

  case 135:
#line 773 "c.y"
    {
    node = malloc(sizeof(struct Declarator));
    ((struct Declarator*)node)->type = 1;
    ((struct Declarator*)node)->directDeclarator = (struct DirectDeclarator*)(yyvsp[(1) - (1)].nPtr);
    (yyval.nPtr) = node;
}
    break;

  case 136:
#line 782 "c.y"
    {
    node = malloc(sizeof(struct DirectDeclarator));
    ((struct DirectDeclarator*)node)->type = 0;
    ((struct DirectDeclarator*)node)->identifier = (char*)(yyvsp[(1) - (1)].nPtr);
    (yyval.nPtr) = node;
}
    break;

  case 137:
#line 788 "c.y"
    {
    node = malloc(sizeof(struct DirectDeclarator));
    ((struct DirectDeclarator*)node)->type = 1;
    ((struct DirectDeclarator*)node)->declarator = (struct Declarator*)(yyvsp[(2) - (3)].nPtr);
    (yyval.nPtr) = node;
}
    break;

  case 138:
#line 794 "c.y"
    {
    node = malloc(sizeof(struct DirectDeclarator));
    ((struct DirectDeclarator*)node)->type = 2;
    ((struct DirectDeclarator*)node)->directDeclarator = (struct DirectDeclarator*)(yyvsp[(1) - (4)].nPtr);
    ((struct DirectDeclarator*)node)->constantExpression = (struct ConstantExpression*)(yyvsp[(3) - (4)].nPtr);
    (yyval.nPtr) = node;
}
    break;

  case 139:
#line 801 "c.y"
    {
    node = malloc(sizeof(struct DirectDeclarator));
    ((struct DirectDeclarator*)node)->type = 3;
    ((struct DirectDeclarator*)node)->directDeclarator = (struct DirectDeclarator*)(yyvsp[(1) - (3)].nPtr);
    (yyval.nPtr) = node;
}
    break;

  case 140:
#line 807 "c.y"
    {
    node = malloc(sizeof(struct DirectDeclarator));
    ((struct DirectDeclarator*)node)->type = 4;
    ((struct DirectDeclarator*)node)->directDeclarator = (struct DirectDeclarator*)(yyvsp[(1) - (4)].nPtr);
    ((struct DirectDeclarator*)node)->parameterTypeList = (struct ParameterTypeList*)(yyvsp[(3) - (4)].nPtr);
    (yyval.nPtr) = node;
}
    break;

  case 141:
#line 814 "c.y"
    {
    node = malloc(sizeof(struct DirectDeclarator));
    ((struct DirectDeclarator*)node)->type = 5;
    ((struct DirectDeclarator*)node)->directDeclarator = (struct DirectDeclarator*)(yyvsp[(1) - (4)].nPtr);
    ((struct DirectDeclarator*)node)->identifierList = (struct IdentifierList*)(yyvsp[(3) - (4)].nPtr);
    (yyval.nPtr) = node;
}
    break;

  case 142:
#line 821 "c.y"
    {
    node = malloc(sizeof(struct DirectDeclarator));
    ((struct DirectDeclarator*)node)->type = 6;
    ((struct DirectDeclarator*)node)->directDeclarator = (struct DirectDeclarator*)(yyvsp[(1) - (3)].nPtr);
    (yyval.nPtr) = node;
}
    break;

  case 143:
#line 830 "c.y"
    {
    node = malloc(sizeof(struct Pointer));
    ((struct Pointer*)node)->type = 0;
    (yyval.nPtr) = node;
}
    break;

  case 144:
#line 835 "c.y"
    {
    node = malloc(sizeof(struct Pointer));
    ((struct Pointer*)node)->type = 1;
    ((struct Pointer*)node)->typeQualifierList = (struct TypeQualifierList*)(yyvsp[(2) - (2)].nPtr);
    (yyval.nPtr) = node;
}
    break;

  case 145:
#line 841 "c.y"
    {
    node = malloc(sizeof(struct Pointer));
    ((struct Pointer*)node)->type = 2;
    ((struct Pointer*)node)->pointer = (struct Pointer*)(yyvsp[(2) - (2)].nPtr);
    (yyval.nPtr) = node;
}
    break;

  case 146:
#line 847 "c.y"
    {
    node = malloc(sizeof(struct Pointer));
    ((struct Pointer*)node)->type = 3;
    ((struct Pointer*)node)->typeQualifierList = (struct TypeQualifierList*)(yyvsp[(2) - (3)].nPtr);
    ((struct Pointer*)node)->pointer = (struct Pointer*)(yyvsp[(3) - (3)].nPtr);
    (yyval.nPtr) = node;
}
    break;

  case 147:
#line 857 "c.y"
    {
    node = malloc(sizeof(struct TypeQualifierList));
    ((struct TypeQualifierList*)node)->type = 0;
    ((struct TypeQualifierList*)node)->typeQualifier = (int)(yyvsp[(1) - (1)].iValue);
    (yyval.nPtr) = node;
}
    break;

  case 148:
#line 863 "c.y"
    {
    node = malloc(sizeof(struct TypeQualifierList));
    ((struct TypeQualifierList*)node)->type = 1;
    ((struct TypeQualifierList*)node)->typeQualifierList = (struct TypeQualifierList*)(yyvsp[(1) - (2)].nPtr);
    ((struct TypeQualifierList*)node)->typeQualifier = (int)(yyvsp[(2) - (2)].iValue);
    (yyval.nPtr) = node;
}
    break;

  case 149:
#line 873 "c.y"
    {
    node = malloc(sizeof(struct ParameterTypeList));
    ((struct ParameterTypeList*)node)->type = 0;
    ((struct ParameterTypeList*)node)->parameterList = (struct ParameterList*)(yyvsp[(1) - (1)].nPtr);
    (yyval.nPtr) = node;
}
    break;

  case 150:
#line 879 "c.y"
    {
    node = malloc(sizeof(struct ParameterTypeList));
    ((struct ParameterTypeList*)node)->type = 1;
    ((struct ParameterTypeList*)node)->parameterList = (struct ParameterList*)(yyvsp[(1) - (3)].nPtr);
    (yyval.nPtr) = node;
}
    break;

  case 151:
#line 888 "c.y"
    {
    node = malloc(sizeof(struct ParameterList));
    ((struct ParameterList*)node)->type = 0;
    ((struct ParameterList*)node)->parameterDeclaration = (struct ParameterDeclaration*)(yyvsp[(1) - (1)].nPtr);
    (yyval.nPtr) = node;
}
    break;

  case 152:
#line 894 "c.y"
    {
    node = malloc(sizeof(struct ParameterList));
    ((struct ParameterList*)node)->type = 1;
    ((struct ParameterList*)node)->parameterList = (struct ParameterList*)(yyvsp[(1) - (3)].nPtr);
    ((struct ParameterList*)node)->parameterDeclaration = (struct ParameterDeclaration*)(yyvsp[(3) - (3)].nPtr);
    (yyval.nPtr) = node;
}
    break;

  case 153:
#line 904 "c.y"
    {
    node = malloc(sizeof(struct ParameterDeclaration));
    ((struct ParameterDeclaration*)node)->type = 0;
    ((struct ParameterDeclaration*)node)->declarationSpecifiers = (struct DeclarationSpecifiers*)(yyvsp[(1) - (2)].nPtr);
    ((struct ParameterDeclaration*)node)->declarator = (struct Declarator*)(yyvsp[(2) - (2)].nPtr);
    (yyval.nPtr) = node;
}
    break;

  case 154:
#line 911 "c.y"
    {
    node = malloc(sizeof(struct ParameterDeclaration));
    ((struct ParameterDeclaration*)node)->type = 1;
    ((struct ParameterDeclaration*)node)->declarationSpecifiers = (struct DeclarationSpecifiers*)(yyvsp[(1) - (2)].nPtr);
    ((struct ParameterDeclaration*)node)->abstractDeclarator = (struct AbstractDeclarator*)(yyvsp[(2) - (2)].nPtr);
    (yyval.nPtr) = node;
}
    break;

  case 155:
#line 918 "c.y"
    {
    node = malloc(sizeof(struct ParameterDeclaration));
    ((struct ParameterDeclaration*)node)->type = 2;
    ((struct ParameterDeclaration*)node)->declarationSpecifiers = (struct DeclarationSpecifiers*)(yyvsp[(1) - (1)].nPtr);
    (yyval.nPtr) = node;
}
    break;

  case 156:
#line 927 "c.y"
    {
    node = malloc(sizeof(struct IdentifierList));
    ((struct IdentifierList*)node)->type = 0;
    ((struct IdentifierList*)node)->identifier = (char*)(yyvsp[(1) - (1)].nPtr);
    (yyval.nPtr) = node;
}
    break;

  case 157:
#line 933 "c.y"
    {
    node = malloc(sizeof(struct IdentifierList));
    ((struct IdentifierList*)node)->type = 1;
    ((struct IdentifierList*)node)->identifierList = (struct IdentifierList*)(yyvsp[(1) - (3)].nPtr);
    ((struct IdentifierList*)node)->identifier = (char*)(yyvsp[(3) - (3)].nPtr);
    (yyval.nPtr) = node;
}
    break;

  case 158:
#line 943 "c.y"
    {
    node = malloc(sizeof(struct TypeName));
    ((struct TypeName*)node)->type = 0;
    ((struct TypeName*)node)->specifierQualifierList = (struct SpecifierQualifierList*)(yyvsp[(1) - (1)].nPtr);
    (yyval.nPtr) = node;
}
    break;

  case 159:
#line 949 "c.y"
    {
    node = malloc(sizeof(struct TypeName));
    ((struct TypeName*)node)->type = 1;
    ((struct TypeName*)node)->specifierQualifierList = (struct SpecifierQualifierList*)(yyvsp[(1) - (2)].nPtr);
    ((struct TypeName*)node)->abstractDeclarator = (struct AbstractDeclarator*)(yyvsp[(2) - (2)].nPtr);
    (yyval.nPtr) = node;
}
    break;

  case 160:
#line 959 "c.y"
    {
    node = malloc(sizeof(struct AbstractDeclarator));
    ((struct AbstractDeclarator*)node)->type = 0;
    ((struct AbstractDeclarator*)node)->pointer = (struct Pointer*)(yyvsp[(1) - (1)].nPtr);
    (yyval.nPtr) = node;
}
    break;

  case 161:
#line 965 "c.y"
    {
    node = malloc(sizeof(struct AbstractDeclarator));
    ((struct AbstractDeclarator*)node)->type = 1;
    ((struct AbstractDeclarator*)node)->directAbstractDeclarator = (struct DirectAbstractDeclarator*)(yyvsp[(1) - (1)].nPtr);
    (yyval.nPtr) = node;
}
    break;

  case 162:
#line 971 "c.y"
    {
    node = malloc(sizeof(struct AbstractDeclarator));
    ((struct AbstractDeclarator*)node)->type = 2;
    ((struct AbstractDeclarator*)node)->pointer = (struct Pointer*)(yyvsp[(1) - (2)].nPtr);
    ((struct AbstractDeclarator*)node)->directAbstractDeclarator = (struct DirectAbstractDeclarator*)(yyvsp[(2) - (2)].nPtr);
    (yyval.nPtr) = node;
}
    break;

  case 163:
#line 981 "c.y"
    {
    node = malloc(sizeof(struct DirectAbstractDeclarator));
    ((struct DirectAbstractDeclarator*)node)->type = 0;
    ((struct DirectAbstractDeclarator*)node)->abstractDeclarator = (struct AbstractDeclarator*)(yyvsp[(2) - (3)].nPtr);
    (yyval.nPtr) = node;
}
    break;

  case 164:
#line 987 "c.y"
    {
    node = malloc(sizeof(struct DirectAbstractDeclarator));
    ((struct DirectAbstractDeclarator*)node)->type = 1;
    (yyval.nPtr) = node;
}
    break;

  case 165:
#line 992 "c.y"
    {
    node = malloc(sizeof(struct DirectAbstractDeclarator));
    ((struct DirectAbstractDeclarator*)node)->type = 2;
    ((struct DirectAbstractDeclarator*)node)->constantExpression = (struct ConstantExpression*)(yyvsp[(2) - (3)].nPtr);
    (yyval.nPtr) = node;
}
    break;

  case 166:
#line 998 "c.y"
    {
    node = malloc(sizeof(struct DirectAbstractDeclarator));
    ((struct DirectAbstractDeclarator*)node)->type = 3;
    ((struct DirectAbstractDeclarator*)node)->directAbstractDeclarator = (struct DirectAbstractDeclarator*)(yyvsp[(1) - (3)].nPtr);
    (yyval.nPtr) = node;
}
    break;

  case 167:
#line 1004 "c.y"
    {
    node = malloc(sizeof(struct DirectAbstractDeclarator));
    ((struct DirectAbstractDeclarator*)node)->type = 4;
    ((struct DirectAbstractDeclarator*)node)->directAbstractDeclarator = (struct DirectAbstractDeclarator*)(yyvsp[(1) - (4)].nPtr);
    ((struct DirectAbstractDeclarator*)node)->constantExpression = (struct ConstantExpression*)(yyvsp[(3) - (4)].nPtr);
    (yyval.nPtr) = node;
}
    break;

  case 168:
#line 1011 "c.y"
    {
    node = malloc(sizeof(struct DirectAbstractDeclarator));
    ((struct DirectAbstractDeclarator*)node)->type = 5;
    (yyval.nPtr) = node;
}
    break;

  case 169:
#line 1016 "c.y"
    {
    node = malloc(sizeof(struct DirectAbstractDeclarator));
    ((struct DirectAbstractDeclarator*)node)->type = 6;
    ((struct DirectAbstractDeclarator*)node)->parameterTypeList = (struct ParameterTypeList*)(yyvsp[(2) - (3)].nPtr);
    (yyval.nPtr) = node;
}
    break;

  case 170:
#line 1022 "c.y"
    {
    node = malloc(sizeof(struct DirectAbstractDeclarator));
    ((struct DirectAbstractDeclarator*)node)->type = 7;
    ((struct DirectAbstractDeclarator*)node)->directAbstractDeclarator = (struct DirectAbstractDeclarator*)(yyvsp[(1) - (3)].nPtr);
    (yyval.nPtr) = node;
}
    break;

  case 171:
#line 1028 "c.y"
    {
    node = malloc(sizeof(struct DirectAbstractDeclarator));
    ((struct DirectAbstractDeclarator*)node)->type = 8;
    ((struct DirectAbstractDeclarator*)node)->directAbstractDeclarator = (struct DirectAbstractDeclarator*)(yyvsp[(1) - (4)].nPtr);
    ((struct DirectAbstractDeclarator*)node)->parameterTypeList = (struct ParameterTypeList*)(yyvsp[(3) - (4)].nPtr);
    (yyval.nPtr) = node;
}
    break;

  case 172:
#line 1038 "c.y"
    {
    node = malloc(sizeof(struct Initializer));
    ((struct Initializer*)node)->type = 0;
    ((struct Initializer*)node)->assignmentExpression = (struct AssignmentExpression*)(yyvsp[(1) - (1)].nPtr);
    (yyval.nPtr) = node;
}
    break;

  case 173:
#line 1044 "c.y"
    {
    node = malloc(sizeof(struct Initializer));
    ((struct Initializer*)node)->type = 1;
    ((struct Initializer*)node)->initializerList = (struct InitializerList*)(yyvsp[(2) - (3)].nPtr);
    (yyval.nPtr) = node;
}
    break;

  case 174:
#line 1050 "c.y"
    {
    node = malloc(sizeof(struct Initializer));
    ((struct Initializer*)node)->type = 2;
    ((struct Initializer*)node)->initializerList = (struct InitializerList*)(yyvsp[(2) - (4)].nPtr);
    (yyval.nPtr) = node;
}
    break;

  case 175:
#line 1059 "c.y"
    {
    node = malloc(sizeof(struct InitializerList));
    ((struct InitializerList*)node)->type = 0;
    ((struct InitializerList*)node)->initializer = (struct Initializer*)(yyvsp[(1) - (1)].nPtr);
    (yyval.nPtr) = node;
}
    break;

  case 176:
#line 1065 "c.y"
    {
    node = malloc(sizeof(struct InitializerList));
    ((struct InitializerList*)node)->type = 1;
    ((struct InitializerList*)node)->initializerList = (struct InitializerList*)(yyvsp[(1) - (3)].nPtr);
    ((struct InitializerList*)node)->initializer = (struct Initializer*)(yyvsp[(3) - (3)].nPtr);
    (yyval.nPtr) = node;
}
    break;

  case 177:
#line 1075 "c.y"
    {
    node = malloc(sizeof(struct Statement));
    ((struct Statement*)node)->type = 0;
    ((struct Statement*)node)->labeledStatement = (struct LabeledStatement*)(yyvsp[(1) - (1)].nPtr);
    (yyval.nPtr) = node;
}
    break;

  case 178:
#line 1081 "c.y"
    {
    node = malloc(sizeof(struct Statement));
    ((struct Statement*)node)->type = 1;
    ((struct Statement*)node)->compoundStatement = (struct CompoundStatement*)(yyvsp[(1) - (1)].nPtr);
    (yyval.nPtr) = node;
}
    break;

  case 179:
#line 1087 "c.y"
    {
    node = malloc(sizeof(struct Statement));
    ((struct Statement*)node)->type = 2;
    ((struct Statement*)node)->expressionStatement = (struct ExpressionStatement*)(yyvsp[(1) - (1)].nPtr);
    (yyval.nPtr) = node;
}
    break;

  case 180:
#line 1093 "c.y"
    {
    node = malloc(sizeof(struct Statement));
    ((struct Statement*)node)->type = 3;
    ((struct Statement*)node)->selectionStatement = (struct SelectionStatement*)(yyvsp[(1) - (1)].nPtr);
    (yyval.nPtr) = node;
}
    break;

  case 181:
#line 1099 "c.y"
    {
    node = malloc(sizeof(struct Statement));
    ((struct Statement*)node)->type = 4;
    ((struct Statement*)node)->iterationStatement = (struct IterationStatement*)(yyvsp[(1) - (1)].nPtr);
    (yyval.nPtr) = node;
}
    break;

  case 182:
#line 1105 "c.y"
    {
    node = malloc(sizeof(struct Statement));
    ((struct Statement*)node)->type = 5;
    ((struct Statement*)node)->jumpStatement = (struct JumpStatement*)(yyvsp[(1) - (1)].nPtr);
    (yyval.nPtr) = node;
}
    break;

  case 183:
#line 1114 "c.y"
    {
    node = malloc(sizeof(struct LabeledStatement));
    ((struct LabeledStatement*)node)->type = 0;
    ((struct LabeledStatement*)node)->identifier = (char*)(yyvsp[(1) - (3)].nPtr);
    ((struct LabeledStatement*)node)->statement = (struct Statement*)(yyvsp[(3) - (3)].nPtr);
    (yyval.nPtr) = node;
}
    break;

  case 184:
#line 1121 "c.y"
    {
    node = malloc(sizeof(struct LabeledStatement));
    ((struct LabeledStatement*)node)->type = 1;
    ((struct LabeledStatement*)node)->constantExpression = (struct ConstantExpression*)(yyvsp[(2) - (4)].nPtr);
    ((struct LabeledStatement*)node)->statement = (struct Statement*)(yyvsp[(4) - (4)].nPtr);
    (yyval.nPtr) = node;
}
    break;

  case 185:
#line 1128 "c.y"
    {
    node = malloc(sizeof(struct LabeledStatement));
    ((struct LabeledStatement*)node)->type = 2;
    ((struct LabeledStatement*)node)->constantExpression = (struct ConstantExpression*)(yyvsp[(3) - (3)].nPtr);
    (yyval.nPtr) = node;
}
    break;

  case 186:
#line 1137 "c.y"
    {
    node = malloc(sizeof(struct CompoundStatement));
    ((struct CompoundStatement*)node)->type = 0;
    (yyval.nPtr) = node;
}
    break;

  case 187:
#line 1142 "c.y"
    {
    node = malloc(sizeof(struct CompoundStatement));
    ((struct CompoundStatement*)node)->type = 1;
    ((struct CompoundStatement*)node)->statementList = (struct StatementList*)(yyvsp[(2) - (3)].nPtr);
    (yyval.nPtr) = node;
}
    break;

  case 188:
#line 1148 "c.y"
    {
    node = malloc(sizeof(struct CompoundStatement));
    ((struct CompoundStatement*)node)->type = 2;
    ((struct CompoundStatement*)node)->declarationList = (struct DeclarationList*)(yyvsp[(2) - (3)].nPtr);
    (yyval.nPtr) = node;
}
    break;

  case 189:
#line 1154 "c.y"
    {
    node = malloc(sizeof(struct CompoundStatement));
    ((struct CompoundStatement*)node)->type = 3;
    ((struct CompoundStatement*)node)->declarationList = (struct DeclarationList*)(yyvsp[(2) - (4)].nPtr);
    ((struct CompoundStatement*)node)->statementList = (struct StatementList*)(yyvsp[(3) - (4)].nPtr);
    (yyval.nPtr) = node;
}
    break;

  case 190:
#line 1164 "c.y"
    {
    node = malloc(sizeof(struct DeclarationList));
    ((struct DeclarationList*)node)->type = 0;
    ((struct DeclarationList*)node)->declaration = (struct Declaration*)(yyvsp[(1) - (1)].nPtr);
    (yyval.nPtr) = node;
}
    break;

  case 191:
#line 1170 "c.y"
    {
    node = malloc(sizeof(struct DeclarationList));
    ((struct DeclarationList*)node)->type = 1;
    ((struct DeclarationList*)node)->declarationList = (struct DeclarationList*)(yyvsp[(1) - (2)].nPtr);
    ((struct DeclarationList*)node)->declaration = (struct Declaration*)(yyvsp[(2) - (2)].nPtr);
    (yyval.nPtr) = node;
}
    break;

  case 192:
#line 1180 "c.y"
    {
    node = malloc(sizeof(struct StatementList));
    ((struct StatementList*)node)->type = 0;
    ((struct StatementList*)node)->statement = (struct Statement*)(yyvsp[(1) - (1)].nPtr);
    (yyval.nPtr) = node;
}
    break;

  case 193:
#line 1186 "c.y"
    {
    node = malloc(sizeof(struct StatementList));
    ((struct StatementList*)node)->type = 1;
    ((struct StatementList*)node)->statementList = (struct StatementList*)(yyvsp[(1) - (2)].nPtr);
    ((struct StatementList*)node)->statement = (struct Statement*)(yyvsp[(2) - (2)].nPtr);
    (yyval.nPtr) = node;
}
    break;

  case 194:
#line 1196 "c.y"
    {
    node = malloc(sizeof(struct ExpressionStatement));
    ((struct ExpressionStatement*)node)->type = 0;
    (yyval.nPtr) = node;
}
    break;

  case 195:
#line 1201 "c.y"
    {
    node = malloc(sizeof(struct ExpressionStatement));
    ((struct ExpressionStatement*)node)->type = 1;
    ((struct ExpressionStatement*)node)->expression = (struct Expression*)(yyvsp[(1) - (2)].nPtr);
    (yyval.nPtr) = node;
}
    break;

  case 196:
#line 1210 "c.y"
    {
    node = malloc(sizeof(struct SelectionStatement));
    ((struct SelectionStatement*)node)->type = 0;
    ((struct SelectionStatement*)node)->expression = (struct Expression*)(yyvsp[(3) - (5)].nPtr);
    ((struct SelectionStatement*)node)->s1 = (struct Statement*)(yyvsp[(5) - (5)].nPtr);
    (yyval.nPtr) = node;
}
    break;

  case 197:
#line 1217 "c.y"
    {
    node = malloc(sizeof(struct SelectionStatement));
    ((struct SelectionStatement*)node)->type = 1;
    ((struct SelectionStatement*)node)->expression = (struct Expression*)(yyvsp[(3) - (7)].nPtr);
    ((struct SelectionStatement*)node)->s1 = (struct Statement*)(yyvsp[(5) - (7)].nPtr);
    ((struct SelectionStatement*)node)->s2 = (struct Statement*)(yyvsp[(7) - (7)].nPtr);
    (yyval.nPtr) = node;
}
    break;

  case 198:
#line 1225 "c.y"
    {
    node = malloc(sizeof(struct SelectionStatement));
    ((struct SelectionStatement*)node)->type = 2;
    ((struct SelectionStatement*)node)->expression = (struct Expression*)(yyvsp[(3) - (5)].nPtr);
    ((struct SelectionStatement*)node)->s1 = (struct Statement*)(yyvsp[(5) - (5)].nPtr);
    (yyval.nPtr) = node;
}
    break;

  case 199:
#line 1235 "c.y"
    {
    node = malloc(sizeof(struct IterationStatement));
    ((struct IterationStatement*)node)->type = 0;
    ((struct IterationStatement*)node)->expression = (struct Expression*)(yyvsp[(3) - (5)].nPtr);
    ((struct IterationStatement*)node)->statement = (struct Statement*)(yyvsp[(5) - (5)].nPtr);
    (yyval.nPtr) = node;
}
    break;

  case 200:
#line 1242 "c.y"
    {
    node = malloc(sizeof(struct IterationStatement));
    ((struct IterationStatement*)node)->type = 1;
    ((struct IterationStatement*)node)->statement = (struct Statement*)(yyvsp[(2) - (7)].nPtr);
    ((struct IterationStatement*)node)->expression = (struct Expression*)(yyvsp[(5) - (7)].nPtr);
    (yyval.nPtr) = node;
}
    break;

  case 201:
#line 1249 "c.y"
    {
    node = malloc(sizeof(struct IterationStatement));
    ((struct IterationStatement*)node)->type = 2;
    ((struct IterationStatement*)node)->s1 = (struct ExpressionStatement*)(yyvsp[(3) - (6)].nPtr);
    ((struct IterationStatement*)node)->s2 = (struct ExpressionStatement*)(yyvsp[(4) - (6)].nPtr);
    ((struct IterationStatement*)node)->statement = (struct Statement*)(yyvsp[(6) - (6)].nPtr);
    (yyval.nPtr) = node;
}
    break;

  case 202:
#line 1257 "c.y"
    {
    node = malloc(sizeof(struct IterationStatement));
    ((struct IterationStatement*)node)->type = 3;
    ((struct IterationStatement*)node)->s1 = (struct ExpressionStatement*)(yyvsp[(3) - (7)].nPtr);
    ((struct IterationStatement*)node)->s2 = (struct ExpressionStatement*)(yyvsp[(4) - (7)].nPtr);
    ((struct IterationStatement*)node)->expression = (struct Expression*)(yyvsp[(5) - (7)].nPtr);
    ((struct IterationStatement*)node)->statement = (struct Statement*)(yyvsp[(7) - (7)].nPtr);
    (yyval.nPtr) = node;
}
    break;

  case 203:
#line 1269 "c.y"
    {
    node = malloc(sizeof(struct JumpStatement));
    ((struct JumpStatement*)node)->type = 0;
    ((struct JumpStatement*)node)->identifier = (char*)(yyvsp[(2) - (3)].nPtr);
    (yyval.nPtr) = node;
}
    break;

  case 204:
#line 1275 "c.y"
    {
    node = malloc(sizeof(struct JumpStatement));
    ((struct JumpStatement*)node)->type = 1;
    (yyval.nPtr) = node;
}
    break;

  case 205:
#line 1280 "c.y"
    {
    node = malloc(sizeof(struct JumpStatement));
    ((struct JumpStatement*)node)->type = 2;
    (yyval.nPtr) = node;
}
    break;

  case 206:
#line 1285 "c.y"
    {
    node = malloc(sizeof(struct JumpStatement));
    ((struct JumpStatement*)node)->type = 3;
    (yyval.nPtr) = node;
}
    break;

  case 207:
#line 1290 "c.y"
    {
    node = malloc(sizeof(struct JumpStatement));
    ((struct JumpStatement*)node)->type = 4;
    ((struct JumpStatement*)node)->expression = (struct Expression*)(yyvsp[(2) - (3)].nPtr);
    (yyval.nPtr) = node;
}
    break;

  case 208:
#line 1299 "c.y"
    {
    node = malloc(sizeof(struct TranslationUnit));
    ((struct TranslationUnit*)node)->type = 0;
    ((struct TranslationUnit*)node)->externalDeclaration = (struct ExternalDeclaration*)(yyvsp[(1) - (1)].nPtr);
    (yyval.nPtr) = node;
    translation_unit_begin(node);
}
    break;

  case 209:
#line 1306 "c.y"
    {
    node = malloc(sizeof(struct TranslationUnit));
    ((struct TranslationUnit*)node)->type = 1;
    ((struct TranslationUnit*)node)->translationUnit = (struct TranslationUnit*)(yyvsp[(1) - (2)].nPtr);
    (yyval.nPtr) = node;
    translation_unit_begin(node);
}
    break;

  case 210:
#line 1316 "c.y"
    {
    node = malloc(sizeof(struct ExternalDeclaration));
    ((struct ExternalDeclaration*)node)->type = 0;
    ((struct ExternalDeclaration*)node)->functionDefinition = (struct FunctionDefinition*)(yyvsp[(1) - (1)].nPtr);
    (yyval.nPtr) = node;
}
    break;

  case 211:
#line 1322 "c.y"
    {
    node = malloc(sizeof(struct ExternalDeclaration));
    ((struct ExternalDeclaration*)node)->type = 1;
    ((struct ExternalDeclaration*)node)->declaration = (struct Declaration*)(yyvsp[(1) - (1)].nPtr);
    (yyval.nPtr) = node;
}
    break;

  case 212:
#line 1331 "c.y"
    {
    node = malloc(sizeof(struct FunctionDefinition));
    ((struct FunctionDefinition*)node)->type = 0;
    ((struct FunctionDefinition*)node)->declarationSpecifiers = (struct DeclarationSpecifiers*)(yyvsp[(1) - (4)].nPtr);
    ((struct FunctionDefinition*)node)->declarator = (struct Declarator*)(yyvsp[(2) - (4)].nPtr);
    ((struct FunctionDefinition*)node)->declarationList = (struct DeclarationList*)(yyvsp[(3) - (4)].nPtr);
    ((struct FunctionDefinition*)node)->compoundStatement = (struct CompoundStatement*)(yyvsp[(4) - (4)].nPtr);
    (yyval.nPtr) = node;
}
    break;

  case 213:
#line 1340 "c.y"
    {
    node = malloc(sizeof(struct FunctionDefinition));
    ((struct FunctionDefinition*)node)->type = 1;
    ((struct FunctionDefinition*)node)->declarationSpecifiers = (struct DeclarationSpecifiers*)(yyvsp[(1) - (3)].nPtr);
    ((struct FunctionDefinition*)node)->declarator = (struct Declarator*)(yyvsp[(2) - (3)].nPtr);
    ((struct FunctionDefinition*)node)->compoundStatement = (struct CompoundStatement*)(yyvsp[(3) - (3)].nPtr);
    (yyval.nPtr) = node;
}
    break;

  case 214:
#line 1348 "c.y"
    {
    node = malloc(sizeof(struct FunctionDefinition));
    ((struct FunctionDefinition*)node)->type = 2;
    ((struct FunctionDefinition*)node)->declarationList = (struct DeclarationList*)(yyvsp[(1) - (3)].nPtr);
    ((struct FunctionDefinition*)node)->compoundStatement = (struct CompoundStatement*)(yyvsp[(2) - (3)].nPtr);
    (yyval.nPtr) = node;
}
    break;

  case 215:
#line 1355 "c.y"
    {
    node = malloc(sizeof(struct FunctionDefinition));
    ((struct FunctionDefinition*)node)->type = 3;
    ((struct FunctionDefinition*)node)->declarator = (struct Declarator*)(yyvsp[(1) - (2)].nPtr);
    ((struct FunctionDefinition*)node)->compoundStatement = (struct CompoundStatement*)(yyvsp[(2) - (2)].nPtr);
    (yyval.nPtr) = node;
}
    break;


/* Line 1267 of yacc.c.  */
#line 3984 "y.tab.c"
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


#line 1364 "c.y"

#include <stdio.h>

extern char yytext[];
extern int column;

yyerror(s)
char *s;
{
	fflush(stdout);
	printf("\n%*s\n%*s\n", column, "^", column, s);
    return 1;
}

int main(void)
{
    freopen("/Users/skyer/Desktop/compiler/test.c", "r" ,stdin);
    yyparse();
    return 0;
}

