/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "ginko.y" /* yacc.c:339  */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "ginkoNode.h"

#define MAX 100

char* vars[MAX];
double vals[MAX];
int numvars;
int numfuncs;
double exec(Node* n);
Node* funcs[MAX];
Node* func_root;
double stack[MAX];
int head;
int tail;
int arg_cnt;
int par_cnt;
    
extern int yylineno;

#line 91 "ginko.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "ginko.tab.h".  */
#ifndef YY_YY_GINKO_TAB_H_INCLUDED
# define YY_YY_GINKO_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    NUMBER = 258,
    ID = 259,
    IF = 260,
    ELSE = 261,
    THEN = 262,
    FUNC = 263,
    PRINT = 264,
    WHILE = 265,
    DO = 266,
    ENDIF = 267,
    SET = 268,
    to = 269,
    ENDWHILE = 270,
    RETURN = 271,
    GREQ_SYM = 272,
    LESQ_SYM = 273,
    EQ_SYM = 274,
    NEQ_SYM = 275
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 26 "ginko.y" /* yacc.c:355  */
 
	double dval; 
	int idx;
	struct Node* node_ptr;

#line 158 "ginko.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_GINKO_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 175 "ginko.tab.c" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
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
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   136

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  34
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  17
/* YYNRULES -- Number of rules.  */
#define YYNRULES  45
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  109

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   275

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    33,     2,     2,     2,     2,     2,     2,
      22,    23,    29,    27,    26,    28,     2,    30,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    21,
      31,     2,    32,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    24,     2,    25,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    45,    45,    49,    53,    59,    62,    65,    66,    67,
      69,    74,    80,    85,    86,    88,    90,    99,   108,   111,
     114,   119,   120,   121,   122,   125,   130,   134,   136,   141,
     147,   152,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NUMBER", "ID", "IF", "ELSE", "THEN",
  "FUNC", "PRINT", "WHILE", "DO", "ENDIF", "SET", "to", "ENDWHILE",
  "RETURN", "GREQ_SYM", "LESQ_SYM", "EQ_SYM", "NEQ_SYM", "';'", "'('",
  "')'", "'{'", "'}'", "','", "'+'", "'-'", "'*'", "'/'", "'<'", "'>'",
  "'!'", "$accept", "program", "stmt_list", "stmt", "assign_stmt",
  "print_stmt", "if_stmt", "while_stmt", "func_decl", "fstmt_list",
  "fstmt", "param_list", "ID_list", "func_call", "arg_list", "expr_list",
  "expr", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,    59,    40,    41,   123,   125,    44,    43,    45,    42,
      47,    60,    62,    33
};
# endif

#define YYPACT_NINF -78

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-78)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
       2,     9,    26,    -1,     8,   -78,    10,    44,    44,    44,
      27,    -1,   -78,   -78,   -78,   -78,   -78,   -78,    29,    44,
     -78,   -78,    44,    44,    44,    44,    44,    44,    44,    44,
      44,    44,    44,    44,    42,    30,    41,    40,   -78,    33,
      37,    59,    57,    44,    44,    44,    44,    61,    44,    44,
      44,    44,    44,    44,   -78,    -1,   -78,    -1,    75,    52,
     -78,    63,   -78,    44,   -78,   -78,   -78,   -78,   -78,   -78,
     -78,   -78,   -78,   -78,   -78,   -78,   106,    76,    10,    77,
      78,    33,   123,    57,    -1,   -78,   -78,   -78,   -78,   -78,
     -78,   -78,   -78,   -78,   104,   -78,   -78,   117,    75,   -78,
     -78,    79,    80,    71,    98,     2,     2,   -78,   -78
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
      18,     0,     0,     0,     0,     1,     0,     0,     0,     0,
       0,     2,     4,     5,     6,     7,     8,     9,     0,     0,
      44,    45,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     3,    27,
       0,     0,    31,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    43,     0,    12,     0,     0,     0,
      25,     0,    28,     0,    29,    40,    39,    41,    42,    32,
      33,    34,    35,    36,    37,    38,     0,     0,    45,     0,
       0,    27,     0,    31,     0,    13,    15,    11,    10,    26,
      21,    22,    23,    24,     0,    20,    30,     0,     0,    19,
      14,     0,     0,     0,     0,    18,    18,    17,    16
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -78,   -78,   -50,    -9,   -55,   -29,   -25,   -24,   -77,   -78,
      31,   -78,    43,   -52,   -78,    48,    -8
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,    11,    12,    13,    14,    15,    16,     3,    94,
      95,    40,    60,    17,    41,    64,    34
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      35,    36,    38,     6,     7,    76,    79,    77,     8,     9,
       1,    42,    10,     4,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,     5,    90,   107,   108,
      18,    37,    19,    39,    97,    65,    66,    67,    68,    90,
      70,    71,    72,    73,    74,    75,   101,    20,    21,    55,
      80,    56,    57,    91,    58,    83,    81,    92,    93,    59,
      61,    22,    23,    24,    25,    91,    26,    38,    38,    92,
      93,    27,    28,    29,    30,    31,    32,    33,    20,    78,
       6,     7,    62,    63,    69,     8,     9,    82,    38,    10,
     102,    86,    22,    23,    24,    25,   105,    26,    87,    88,
     103,   104,    27,    28,    29,    30,    31,    32,    33,     7,
       6,     7,    84,     8,     9,     8,     9,    10,    85,    10,
      98,     6,     7,   106,    89,    99,     8,     9,     7,   100,
      10,    96,     8,     9,     0,     0,    10
};

static const yytype_int8 yycheck[] =
{
       8,     9,    11,     4,     5,    55,    58,    57,     9,    10,
       8,    19,    13,     4,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,     0,    82,   105,   106,
      22,     4,    22,     4,    84,    43,    44,    45,    46,    94,
      48,    49,    50,    51,    52,    53,    98,     3,     4,     7,
      58,    21,    11,    82,    14,    63,     4,    82,    82,    26,
      23,    17,    18,    19,    20,    94,    22,    76,    77,    94,
      94,    27,    28,    29,    30,    31,    32,    33,     3,     4,
       4,     5,    23,    26,    23,     9,    10,    24,    97,    13,
      98,    15,    17,    18,    19,    20,    25,    22,    21,    21,
      21,    21,    27,    28,    29,    30,    31,    32,    33,     5,
       4,     5,     6,     9,    10,     9,    10,    13,    12,    13,
      16,     4,     5,    25,    81,    94,     9,    10,     5,    12,
      13,    83,     9,    10,    -1,    -1,    13
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     8,    35,    42,     4,     0,     4,     5,     9,    10,
      13,    36,    37,    38,    39,    40,    41,    47,    22,    22,
       3,     4,    17,    18,    19,    20,    22,    27,    28,    29,
      30,    31,    32,    33,    50,    50,    50,     4,    37,     4,
      45,    48,    50,    50,    50,    50,    50,    50,    50,    50,
      50,    50,    50,    50,    50,     7,    21,    11,    14,    26,
      46,    23,    23,    26,    49,    50,    50,    50,    50,    23,
      50,    50,    50,    50,    50,    50,    36,    36,     4,    47,
      50,     4,    24,    50,     6,    12,    15,    21,    21,    46,
      38,    39,    40,    41,    43,    44,    49,    36,    16,    44,
      12,    47,    50,    21,    21,    25,    25,    42,    42
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    34,    35,    36,    36,    37,    37,    37,    37,    37,
      38,    38,    39,    40,    40,    41,    42,    42,    42,    43,
      43,    44,    44,    44,    44,    45,    46,    46,    47,    48,
      49,    49,    50,    50,    50,    50,    50,    50,    50,    50,
      50,    50,    50,    50,    50,    50
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     2,     1,     1,     1,     1,     1,     1,
       5,     5,     3,     5,     7,     5,    12,    12,     0,     2,
       1,     1,     1,     1,     1,     2,     3,     0,     4,     2,
       3,     0,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     2,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
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
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
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

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

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

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
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
  int yytoken = 0;
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

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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
      yychar = yylex ();
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
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
     '$$ = $1'.

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
#line 45 "ginko.y" /* yacc.c:1646  */
    {
			func_root = (yyvsp[-1].node_ptr);
			exec((yyvsp[0].node_ptr));
		}
#line 1324 "ginko.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 49 "ginko.y" /* yacc.c:1646  */
    { 
				//printf("stmt_list1\n");
				(yyval.node_ptr) = new_node(2, STMT_LIST, 2, (yyvsp[-1].node_ptr), (yyvsp[0].node_ptr)); 
			}
#line 1333 "ginko.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 53 "ginko.y" /* yacc.c:1646  */
    { 
			  //printf("stmt_list2\n");
			  (yyval.node_ptr) = (yyvsp[0].node_ptr);
		  }
#line 1342 "ginko.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 59 "ginko.y" /* yacc.c:1646  */
    { 
		   //printf("a-stmt\n");
		   (yyval.node_ptr) = (yyvsp[0].node_ptr);}
#line 1350 "ginko.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 62 "ginko.y" /* yacc.c:1646  */
    { 
		 //printf("p-stmt\n");
		 (yyval.node_ptr) = (yyvsp[0].node_ptr); }
#line 1358 "ginko.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 65 "ginko.y" /* yacc.c:1646  */
    { (yyval.node_ptr) = (yyvsp[0].node_ptr);}
#line 1364 "ginko.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 66 "ginko.y" /* yacc.c:1646  */
    {(yyval.node_ptr) = (yyvsp[0].node_ptr);}
#line 1370 "ginko.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 67 "ginko.y" /* yacc.c:1646  */
    {(yyval.node_ptr) = (yyvsp[0].node_ptr);}
#line 1376 "ginko.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 69 "ginko.y" /* yacc.c:1646  */
    { 
				 //printf("assign_stmt: SET %s to %lf\n", vars[$2], $4);
				 Node* id_node = new_node_var(1, VAR, (yyvsp[-3].idx));
				 (yyval.node_ptr) = new_node(2, SET_EXPR, 2, id_node, (yyvsp[-1].node_ptr)); 
			  }
#line 1386 "ginko.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 74 "ginko.y" /* yacc.c:1646  */
    {
				//printf("SET\n");
				Node* id_node = new_node_var(1, VAR, (yyvsp[-3].idx));
				(yyval.node_ptr) = new_node(2, SET_FUNC_CALL, 2, id_node, (yyvsp[-1].node_ptr));
			}
#line 1396 "ginko.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 80 "ginko.y" /* yacc.c:1646  */
    { 
				 //printf("print_stmt\n");
				 //printf("yacc print\n"); 
				 (yyval.node_ptr) = new_node(2, PRINTSTMT, 1, (yyvsp[-1].node_ptr)); }
#line 1405 "ginko.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 85 "ginko.y" /* yacc.c:1646  */
    { (yyval.node_ptr) = new_node(2, IFSTMT, 2, (yyvsp[-3].node_ptr), (yyvsp[-1].node_ptr)); }
#line 1411 "ginko.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 86 "ginko.y" /* yacc.c:1646  */
    { (yyval.node_ptr) = new_node(2, IFSTMT, 3, (yyvsp[-5].node_ptr), (yyvsp[-3].node_ptr), (yyvsp[-1].node_ptr));  }
#line 1417 "ginko.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 88 "ginko.y" /* yacc.c:1646  */
    { (yyval.node_ptr) = new_node(2, WHILE, 2, (yyvsp[-3].node_ptr), (yyvsp[-1].node_ptr)); }
#line 1423 "ginko.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 90 "ginko.y" /* yacc.c:1646  */
    {
				//printf("func_decl1\n");
				Node* func_name = new_node_func(2, FUNC_NAME, (yyvsp[-10].idx));
				//pushFunc(func_name);
				//$$ = new_node(2, FUNC_DECL, 5, func_name, $4, $7, $9, $12);
				Node* nn = new_node(2, FUNC_DECL, 5, func_name, (yyvsp[-8].node_ptr), (yyvsp[-5].node_ptr), (yyvsp[-3].node_ptr), (yyvsp[0].node_ptr));
				pushFunc(nn);
				(yyval.node_ptr) = nn;
			}
#line 1437 "ginko.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 99 "ginko.y" /* yacc.c:1646  */
    {
			  //printf("func_decl2\n");
			  Node* func_name = new_node_func(2, FUNC_NAME, (yyvsp[-10].idx));
			  //pushFunc(func_name);
			  //$$ = new_node(2, FUNC_DECL, 5, func_name, $4, $7, $9, $12);
			  Node* nn = new_node(2, FUNC_DECL, 5, func_name, (yyvsp[-8].node_ptr), (yyvsp[-5].node_ptr), (yyvsp[-3].node_ptr), (yyvsp[0].node_ptr));
			  pushFunc(nn);
			  (yyval.node_ptr) = nn;
		  }
#line 1451 "ginko.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 108 "ginko.y" /* yacc.c:1646  */
    {
		  }
#line 1458 "ginko.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 111 "ginko.y" /* yacc.c:1646  */
    {
				(yyval.node_ptr) = new_node(2, FSTMT_LIST, 2, (yyvsp[-1].node_ptr), (yyvsp[0].node_ptr));
			}
#line 1466 "ginko.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 114 "ginko.y" /* yacc.c:1646  */
    {
			   	//$$ = new_node(2, FSTMT_LIST, 1, $1);
			    (yyval.node_ptr) = (yyvsp[0].node_ptr);
		   }
#line 1475 "ginko.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 119 "ginko.y" /* yacc.c:1646  */
    { (yyval.node_ptr) = (yyvsp[0].node_ptr); }
#line 1481 "ginko.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 120 "ginko.y" /* yacc.c:1646  */
    { (yyval.node_ptr) = (yyvsp[0].node_ptr); }
#line 1487 "ginko.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 121 "ginko.y" /* yacc.c:1646  */
    { (yyval.node_ptr) = (yyvsp[0].node_ptr); }
#line 1493 "ginko.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 122 "ginko.y" /* yacc.c:1646  */
    { (yyval.node_ptr) = (yyvsp[0].node_ptr); }
#line 1499 "ginko.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 125 "ginko.y" /* yacc.c:1646  */
    {
				Node* id_node = new_node_var(2,	FUNC_NAME_TMP, (yyvsp[-1].idx)); 
				(yyval.node_ptr) = new_node(2, PARAM_LIST, 2, id_node, (yyvsp[0].node_ptr));
			 }
#line 1508 "ginko.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 130 "ginko.y" /* yacc.c:1646  */
    {
				Node* id_node = new_node_var(2,	FUNC_NAME_TMP, (yyvsp[-1].idx)); 
				(yyval.node_ptr) = new_node(2, ID_LIST, 2, id_node, (yyvsp[0].node_ptr));
			}
#line 1517 "ginko.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 134 "ginko.y" /* yacc.c:1646  */
    { (yyval.node_ptr) = new_node(3, EPSILON, 0); }
#line 1523 "ginko.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 136 "ginko.y" /* yacc.c:1646  */
    {
				Node* id_node = new_node_var(2,	FUNC_NAME_TMP, (yyvsp[-3].idx)); 
				(yyval.node_ptr) = new_node(2, FUNC_CALL, 2, id_node, (yyvsp[-1].node_ptr));
			}
#line 1532 "ginko.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 141 "ginko.y" /* yacc.c:1646  */
    {
			    //Node* list_tmp = new_node(2, EXPR_LIST_TMP, 1, $2);
				//$$ = new_node(2, ARG_LIST, 2, $1, list_tmp);
				(yyval.node_ptr) = new_node(2, ARG_LIST, 2, (yyvsp[-1].node_ptr), (yyvsp[0].node_ptr));
		   }
#line 1542 "ginko.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 147 "ginko.y" /* yacc.c:1646  */
    { 
				//Node* list_tmp = new_node(2, EXPR_LIST_TMP, 1, $3);
				//$$ = new_node(2, EXPR_LIST, 2, $2, list_tmp);
				(yyval.node_ptr) = new_node(2, EXPR_LIST, 2, (yyvsp[-1].node_ptr), (yyvsp[0].node_ptr));
			}
#line 1552 "ginko.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 152 "ginko.y" /* yacc.c:1646  */
    { (yyval.node_ptr) = new_node(3, EPSILON, 0); }
#line 1558 "ginko.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 154 "ginko.y" /* yacc.c:1646  */
    { (yyval.node_ptr) = new_node(2, PAR, 1, (yyvsp[-1].node_ptr)); }
#line 1564 "ginko.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 155 "ginko.y" /* yacc.c:1646  */
    { (yyval.node_ptr) = new_node(2, PLUS, 2, (yyvsp[-1].node_ptr), (yyvsp[0].node_ptr)); }
#line 1570 "ginko.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 156 "ginko.y" /* yacc.c:1646  */
    { (yyval.node_ptr) = new_node(2, MINUS, 2, (yyvsp[-1].node_ptr), (yyvsp[0].node_ptr)); }
#line 1576 "ginko.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 157 "ginko.y" /* yacc.c:1646  */
    { (yyval.node_ptr) = new_node(2, MUL, 2, (yyvsp[-1].node_ptr), (yyvsp[0].node_ptr));  }
#line 1582 "ginko.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 158 "ginko.y" /* yacc.c:1646  */
    { (yyval.node_ptr) = new_node(2, DIV, 2, (yyvsp[-1].node_ptr), (yyvsp[0].node_ptr));}
#line 1588 "ginko.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 159 "ginko.y" /* yacc.c:1646  */
    { (yyval.node_ptr) = new_node(2, LES, 2, (yyvsp[-1].node_ptr), (yyvsp[0].node_ptr)); }
#line 1594 "ginko.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 160 "ginko.y" /* yacc.c:1646  */
    { (yyval.node_ptr) = new_node(2, GRE, 2, (yyvsp[-1].node_ptr), (yyvsp[0].node_ptr)); }
#line 1600 "ginko.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 161 "ginko.y" /* yacc.c:1646  */
    { (yyval.node_ptr) = new_node(2, LESQ, 2, (yyvsp[-1].node_ptr), (yyvsp[0].node_ptr)); }
#line 1606 "ginko.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 162 "ginko.y" /* yacc.c:1646  */
    { (yyval.node_ptr) = new_node(2, GREQ, 2, (yyvsp[-1].node_ptr), (yyvsp[0].node_ptr)); }
#line 1612 "ginko.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 163 "ginko.y" /* yacc.c:1646  */
    { (yyval.node_ptr) = new_node(2, EQ, 2, (yyvsp[-1].node_ptr), (yyvsp[0].node_ptr)); }
#line 1618 "ginko.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 164 "ginko.y" /* yacc.c:1646  */
    { (yyval.node_ptr) = new_node(2, NEQ, 2, (yyvsp[-1].node_ptr), (yyvsp[0].node_ptr)); }
#line 1624 "ginko.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 165 "ginko.y" /* yacc.c:1646  */
    { (yyval.node_ptr) = new_node(2, NEG, 1, (yyvsp[0].node_ptr)); }
#line 1630 "ginko.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 166 "ginko.y" /* yacc.c:1646  */
    { (yyval.node_ptr) = new_node_num(0, NUM, (yyvsp[0].dval)); }
#line 1636 "ginko.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 167 "ginko.y" /* yacc.c:1646  */
    { 
		 //printf("expr ID\n");
		 (yyval.node_ptr) = new_node_var(1, VAR, (yyvsp[0].idx)); }
#line 1644 "ginko.tab.c" /* yacc.c:1646  */
    break;


#line 1648 "ginko.tab.c" /* yacc.c:1646  */
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

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
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

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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

#if !defined yyoverflow || YYERROR_VERBOSE
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
  /* Do not reclaim the symbols of the rule whose action triggered
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
  return yyresult;
}
#line 171 "ginko.y" /* yacc.c:1906  */


yyerror(char* s) {
    extern char* yytext;
    //extern int yylineno;
	printf("Error: %d\n", yylineno);
    //fprintf(stdout, "%s\nLine No: %d\nAt char: %s\n", s, yylineno, yytext);
}


int findindex(char* var) {
	if(numvars == 0) {
		for(int i=0; i<MAX; i++)
			vals[i] = INT_MIN;
	}
	for(int i=0; i<numvars; i++) {
		if(strcmp(var, vars[i])==0)
			return i;
	}
	//printf("new var: %s\n", var);
	vars[numvars] = strdup(var);
	return numvars++;
}

void pushFunc(struct Node* n) {
	//printf("pushFunc cur numfuncs: %d\n", numfuncs);
	funcs[numfuncs++] = n;
}


double exec(Node* n) {
	//printf("exec\n");
	if(!n) {
		printf("n is null return exec\n");
		return 0;
	}
	if(n == NULL)
		printf("n is null!!!\n");
	switch(n->type){
		case 0:
			return n->val;
		case 1: 
			//printf("%s\n", vars[n->var_idx]);
			//printf("%lf\n", vals[n->var_idx]);
			if(vals[n->var_idx] == INT_MIN) {
				printf("Unknown variable: %s\n", vars[n->var_idx]);
				exit(-1);
			}
			return vals[n->var_idx];
		case 2:
			switch(n->op){
				case PROGRAM: return exec(n->next[1]);
				case PAR:
					//stack[top++] = exec(n->next[0]);
					return exec(n->next[0]);
				case NEG:	
					//stack[top++] = exec(n->next[0]);
					return -exec(n->next[0]);
				case PLUS:	
					//stack[top++] = exec(n->next[0]) + exec(n->next[1]);
					return exec(n->next[0]) + exec(n->next[1]);
				case MINUS:	
					//stack[top++] = exec(n->next[0]) - exec(n->next[1]);
					return exec(n->next[0]) - exec(n->next[1]);
				case MUL:	
					//stack[top++] = exec(n->next[0]) * exec(n->next[1]);
					return exec(n->next[0]) * exec(n->next[1]);
				case DIV:	
					//stack[top++] = exec(n->next[0]) / exec(n->next[1]);
					return exec(n->next[0]) / exec(n->next[1]);
				case LES:	
					//stack[top++] = exec(n->next[0]) < exec(n->next[1]);
					return exec(n->next[0]) < exec(n->next[1]);
				case GRE:	
					//stack[top++] = exec(n->next[0]) > exec(n->next[1]);
					return exec(n->next[0]) > exec(n->next[1]);
				case LESQ:	
					//stack[top++] = exec(n->next[0]) <= exec(n->next[1]);
					return exec(n->next[0]) <= exec(n->next[1]);
				case GREQ:	
					//stack[top++] = exec(n->next[0]) >= exec(n->next[1]);
					return exec(n->next[0]) >= exec(n->next[1]);
				case EQ:	
					//stack[top++] = exec(n->next[0]) == exec(n->next[1]);
					return exec(n->next[0]) == exec(n->next[1]);
				case NEQ:	
					//stack[top++] = exec(n->next[0]) != exec(n->next[1]);
					return exec(n->next[0]) != exec(n->next[1]);
				case WHILE:
					while(exec(n->next[0]))
						exec(n->next[1]);
					return 0;
				case SET_EXPR:
					//printf("case SET_EXPR\n");
					return vals[n->next[0]->var_idx] = exec(n->next[1]);
				case SET_FUNC_CALL:
					//printf("case SET_FUNC_CALL\n");
					return vals[n->next[0]->var_idx] = exec(n->next[1]);
				case PRINTSTMT:	
					//printf("case PRINTSTMT\n");
					printf("%lf\n", exec(n->next[0])); 

					//printf("%lf\n", exec(n->next[0])); 
					return 0;
				case IFSTMT:
					//printf("case IFSTMT\n");
					if(exec(n->next[0])) return exec(n->next[1]);
					else if(n->op_cnt == 3) return exec(n->next[2]);
				case FUNC_CALL:
					//printf("case FUNC_CALL\n");
					exec(n->next[1]);	

					for(int i=0; i<numfuncs; i++) {
						if(n->next[0]->var_idx == funcs[i]->next[0]->var_idx) {
							//printf("executing function\n");
							return exec(funcs[i]);
						}
					}
				case ARG_LIST:
					//printf("case ARG_LIST how many args: %d\n", n->op_cnt);
					arg_cnt = 0;
					Node* ccur = n;
					while(ccur->next[1] != NULL) {
						arg_cnt++;
						ccur = ccur->next[1];
						if(ccur == NULL)
							break;
					}
					//printf("arg_cnt: %d\n", arg_cnt);
					//printf("case ARG_LIST exec0: %lf\n", exec(n->next[0]));	// expr
					//printf("case ARG_LIST exec1: %lf\n", exec(n->next[1]->next[0]));	// expr
					printf("");
					//printf("case ARG_LIST exec1: %lf\n", exec(n->next[1]->next[1]));	// expr
					Node* cur = n;
					Node* prev;
					//for(int i=0; i<n->op_cnt; i++) {
					for(int i=0; i<arg_cnt; i++) {
						prev = cur;
						cur = prev->next[0];
						stack[tail++] = exec(cur);
						//printf("enqueue %lf, tail %d\n", stack[tail-1], tail-1);
						cur = prev->next[1];

					}
					//printf("end while\n");
					return;
				case PARAM_LIST:
					//printf("case PARAM_LIST how many pars: %d\n", n->op_cnt);
					par_cnt = 0;
					Node* ccur2 = n;
					exec(n->next[1]);
					
					while(ccur2->next[1] != NULL) {
						par_cnt++;
						ccur2 = ccur2->next[1];
					}
					//printf("par_cnt: %d\n", par_cnt);
					if(par_cnt != arg_cnt){
						printf("Error: %d\n", yylineno);
					}
					//printf("%s\n", vars[n->next[0]->var_idx]);
					//printf("%s\n", vars[n->next[1]->next[0]->var_idx]);
					printf("");
					
					Node* cur2 = n;
					Node* prev2;
					//for(int i=0; i<n->op_cnt; i++) {
					for(int i=0; i<par_cnt; i++) {
						prev2 = cur2;
						cur2 = prev2->next[0];
						vals[cur2->var_idx] = stack[head++];	
						//printf("dequeue %lf, head %d\n", stack[head-1], head - 1);
						cur2 = prev2->next[1];
					}
				case STMT:
					return exec(n->next[0]);
				case STMT_LIST:
					exec(n->next[0]);
					exec(n->next[1]);
					return 0;
				case FUNC_DECL:
					//printf("case FUNC_DECL\n");
					exec(n->next[1]); // param_list
					exec(n->next[2]); // fstmt_list
					return exec(n->next[3]);
				case FSTMT_LIST:
					exec(n->next[0]);
					exec(n->next[1]);
				case ID_LIST:
					//printf("case ID_LIST");
					printf("");
					//printf("case ID_LIST\n");
				case EXPR_LIST:
					printf("");
					//printf("case EXPR_LIST\n");
					//exec(n->next[0]);		// expr
					//printf("case EXPR_LIST-1\n");
					//printf("%d\n", n->next[1]);
					//exec(n->next[1]);		// expr_list:
					//printf("case EXPR_LIST-2\n");


				
			}
	}
	return 0;
}

