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
#line 2 "parser.y" /* yacc.c:339  */

#include <iostream>
#include <cstdio>
#include <string>
#include "ast.hpp"
#include "lexer.hpp"


std::list<Symbol> symbolTable;

#line 77 "parser.cpp" /* yacc.c:339  */

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
   by #include "parser.hpp".  */
#ifndef YY_YY_PARSER_HPP_INCLUDED
# define YY_YY_PARSER_HPP_INCLUDED
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
    T_and = 258,
    T_array = 259,
    T_begin = 260,
    T_bool = 261,
    T_char = 262,
    T_delete = 263,
    T_dim = 264,
    T_do = 265,
    T_done = 266,
    T_downto = 267,
    T_else = 268,
    T_end = 269,
    T_false = 270,
    T_float = 271,
    T_for = 272,
    T_if = 273,
    T_in = 274,
    T_int = 275,
    T_let = 276,
    T_match = 277,
    T_mutable = 278,
    T_new = 279,
    T_of = 280,
    T_rec = 281,
    T_ref = 282,
    T_then = 283,
    T_to = 284,
    T_true = 285,
    T_type = 286,
    T_unit = 287,
    T_while = 288,
    T_with = 289,
    T_plus_dot = 290,
    T_logic_and = 291,
    T_logic_or = 292,
    T_double_star = 293,
    T_assign = 294,
    T_neq = 295,
    T_iseq = 296,
    T_greq = 297,
    T_leq = 298,
    T_legr = 299,
    T_minus_dot = 300,
    T_star_dot = 301,
    T_slash_dot = 302,
    T_arrow = 303,
    T_mod = 304,
    T_not = 305,
    T_id = 306,
    T_Id = 307,
    T_int_const = 308,
    T_float_const = 309,
    T_char_const = 310,
    T_string_literal = 311,
    UPLUS = 312,
    UMINUS = 313,
    UPLUS_DOT = 314,
    UMINUS_DOT = 315,
    FUNCTION_CALL = 316,
    CONSTRUCTOR_CALL = 317
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 93 "parser.y" /* yacc.c:355  */

  Letdef *let;
  Expr *expr;
  ExprList *exprList;
  Def *def;
  DefList *defList;
  Par *par;
  //ParId *parId;
  ParList *parList;
  CommaExprList *commaExprList;
  Type *type;
  TypeList *typeList;
  Typedef *typeDef;
  AndDef *andDef;
  AndTypeDef *andTypeDef;
  char char_const;
  int int_const;
  float float_const;
  Id *id;
  ConstrId *constrId;
  BarConstrs *barConstrs;
  StringLiteral *stringLiteral;

#line 204 "parser.cpp" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 221 "parser.cpp" /* yacc.c:358  */

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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   844

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  79
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  19
/* YYNRULES -- Number of rules.  */
#define YYNRULES  94
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  185

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   317

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    71,     2,     2,     2,     2,     2,     2,
      75,    76,    63,    61,    78,    62,     2,    64,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    74,    57,
      59,    58,    60,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    72,     2,    73,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    77,     2,     2,     2,     2,     2,
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
      55,    56,    65,    66,    67,    68,    69,    70
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   138,   138,   145,   146,   150,   151,   155,   156,   160,
     161,   165,   166,   167,   168,   169,   170,   174,   175,   179,
     180,   185,   189,   190,   194,   200,   201,   206,   207,   211,
     212,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   231,   232,   238,   239,   244,   245,   246,   247,   248,
     249,   250,   251,   253,   254,   255,   256,   257,   258,   260,
     261,   262,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   283,   284,   285,   286,   287,   288,   289,   290,   292,
     294,   295,   296,   297,   298
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "\"and\"", "\"array\"", "\"begin\"",
  "\"bool\"", "\"char\"", "\"delete\"", "\"dim\"", "\"do\"", "\"done\"",
  "\"downto\"", "\"else\"", "\"end\"", "\"false\"", "\"float\"", "\"for\"",
  "\"if\"", "\"in\"", "\"int\"", "\"let\"", "\"match\"", "\"mutable\"",
  "\"new\"", "\"of\"", "\"rec\"", "\"ref\"", "\"then\"", "\"to\"",
  "\"true\"", "\"type\"", "\"unit\"", "\"while\"", "\"with\"", "\"+.\"",
  "\"&&\"", "\"||\"", "\"**\"", "\":=\"", "\"!=\"", "\"==\"", "\">=\"",
  "\"<=\"", "\"<>\"", "\"-.\"", "\"*.\"", "\"/.\"", "\"->\"", "\"mod\"",
  "\"not\"", "T_id", "T_Id", "T_int_const", "T_float_const",
  "T_char_const", "T_string_literal", "';'", "'='", "'<'", "'>'", "'+'",
  "'-'", "'*'", "'/'", "UPLUS", "UMINUS", "UPLUS_DOT", "UMINUS_DOT",
  "FUNCTION_CALL", "CONSTRUCTOR_CALL", "'!'", "'['", "']'", "':'", "'('",
  "')'", "'|'", "','", "$accept", "program", "defList", "defs", "letdef",
  "andDef", "def", "params", "par", "typedef", "andTdef", "tdef",
  "bar_constrs", "constr", "types", "type", "exprs", "commaExprs", "expr", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,    59,    61,    60,
      62,    43,    45,    42,    47,   312,   313,   314,   315,   316,
     317,    33,    91,    93,    58,    40,    41,   124,    44
};
# endif

#define YYPACT_NINF -61

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-61)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-1)))

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -61,     1,   -19,   -61,    -6,   -47,   -61,   -61,   -61,   -25,
     -12,   -61,   -61,   -29,   -61,   -34,   -60,   -61,   -15,    45,
       0,    51,   174,   115,   -13,   174,    45,   -61,   174,   115,
      12,   -61,   -12,    39,   -61,   -47,   174,   174,    -7,   -61,
      14,   174,   115,   -61,   174,   174,   174,   174,    -3,   -61,
     -61,   -61,   -61,   -61,   174,   174,   174,   109,    47,   -16,
     630,    46,   -61,   -61,   -61,   -61,   -61,   -61,   115,   -11,
     115,   630,   630,   -17,    -4,   -61,   115,    -1,   -61,   528,
     -61,   -61,    21,    15,   600,   -11,   236,   -61,   -61,   -61,
     188,   188,   -61,   -61,   -61,   -61,   558,   174,   -61,   174,
     174,   174,   174,   174,   174,   174,   174,   174,   174,   174,
     174,   174,   174,   174,   174,   174,   174,   174,   174,   174,
     174,   115,   -20,   -61,   115,   -11,   174,   115,   115,   -11,
       0,   -61,   -61,   174,   174,   174,   630,   -61,   630,     4,
     750,   720,    36,   660,   780,   780,   780,   780,   780,     4,
      36,    36,    36,   690,   780,   780,   780,     4,     4,    36,
      36,   -11,   -61,   -11,   630,   -18,   -11,   -61,   459,   494,
     349,   -61,   174,   174,   174,   -61,   274,   312,   690,   174,
     174,   386,   423,   -61,   -61
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     2,     1,     0,     0,     4,     5,     6,     0,
       0,    17,     9,     0,    22,    13,     0,     9,     0,     7,
       0,    21,     0,     0,    14,     0,     8,    19,     0,     0,
       0,    18,     0,    27,    25,     0,     0,     0,     0,    50,
       0,     0,     0,    49,     0,     0,     0,     0,    41,    41,
      45,    46,    47,    48,     0,     0,     0,     0,     0,     0,
      43,     0,    34,    33,    35,    32,    31,    36,     0,    15,
       0,    44,    11,     0,     0,    10,     0,    24,    23,     0,
      86,    83,     0,     0,     0,    85,     0,    55,    56,    58,
      81,    82,    53,    54,    57,    51,     0,     0,    87,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    39,     0,    16,     0,     0,    28,    29,
       0,    89,    84,     0,     0,     0,    42,    52,    88,    63,
      77,    78,    68,    80,    76,    75,    74,    73,    70,    64,
      65,    66,    67,    79,    69,    71,    72,    59,    60,    61,
      62,    40,    37,    38,    12,     0,    30,    26,     0,    90,
       0,    20,     0,     0,     0,    92,     0,     0,    91,     0,
       0,     0,     0,    94,    93
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -61,   -61,   -61,   -61,    97,    84,    -5,   -61,   -61,   -61,
     -61,    67,   -61,   -14,   -61,   -21,    56,    99,   -22
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,     6,    58,    19,    12,    18,    31,     8,
      21,    14,    77,    34,   128,    69,    90,    59,   136
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      60,     3,     4,    71,    13,    17,    72,   123,    73,   123,
     123,     9,     5,    24,    79,    80,   123,     9,    25,    84,
      10,    85,    86,    87,    88,    89,    15,    75,   124,    20,
     124,   124,    92,    93,    94,    96,    27,   124,    22,    11,
      23,   126,   102,    28,    81,    11,    82,   122,    32,   125,
     110,   111,    33,   112,    35,   129,   162,    98,   171,    29,
      30,    70,    25,    74,    76,    83,    97,   119,   120,    22,
     127,   121,   132,   133,   102,   138,   130,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,     7,
     161,    26,    78,   163,   164,    91,   165,   166,    16,     0,
       0,   168,   169,   170,    36,     0,   167,    37,    38,    61,
       0,    62,    63,     0,    39,     0,    40,    41,     0,     0,
       4,    64,     0,    42,     0,    65,     0,     0,     0,    43,
       0,     0,    44,     0,    45,     0,     0,    66,     0,     0,
     176,   177,   178,     0,    46,     0,     0,   181,   182,    47,
      48,    49,    50,    51,    52,    53,    67,     0,     0,     0,
      54,    55,     0,     0,     0,     0,     0,     0,     0,    36,
      56,     0,    37,    38,    57,    95,     0,     0,     0,    39,
      68,    40,    41,    36,     0,     4,     0,    38,    42,     0,
       0,     0,     0,    39,    43,    40,     0,    44,     0,    45,
       0,     0,    42,     0,     0,     0,     0,     0,    43,    46,
       0,    44,     0,     0,    47,    48,    49,    50,    51,    52,
      53,     0,     0,     0,     0,    54,    55,     0,     0,    48,
      49,    50,    51,    52,    53,    56,   135,     0,     0,    57,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    56,
       0,     0,     0,    57,     0,     0,     0,     0,     0,     0,
       0,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   179,   112,     0,     0,     0,     0,
       0,     0,     0,   113,   114,   115,   116,   117,   118,   119,
     120,     0,     0,     0,     0,     0,     0,     0,     0,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   180,   112,     0,     0,     0,     0,     0,     0,
       0,   113,   114,   115,   116,   117,   118,   119,   120,     0,
       0,     0,     0,     0,     0,     0,     0,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     175,   112,     0,     0,     0,     0,     0,     0,     0,   113,
     114,   115,   116,   117,   118,   119,   120,     0,     0,     0,
       0,     0,     0,     0,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   183,   112,     0,
       0,     0,     0,     0,     0,     0,   113,   114,   115,   116,
     117,   118,   119,   120,     0,     0,     0,     0,     0,     0,
       0,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   184,   112,     0,     0,     0,     0,
       0,     0,     0,   113,   114,   115,   116,   117,   118,   119,
     120,     0,     0,     0,     0,     0,     0,     0,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   172,   112,     0,     0,     0,     0,     0,     0,     0,
     113,   114,   115,   116,   117,   118,   119,   120,   173,     0,
       0,     0,     0,     0,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   174,   112,     0,
       0,     0,     0,     0,     0,     0,   113,   114,   115,   116,
     117,   118,   119,   120,     0,     0,     0,     0,     0,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   131,   112,     0,     0,     0,     0,     0,     0,
       0,     0,   114,   115,   116,   117,   118,   119,   120,     0,
       0,     0,     0,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,     0,   112,     0,     0,
       0,     0,     0,     0,     0,   113,   114,   115,   116,   117,
     118,   119,   120,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,     0,   112,     0,     0,
       0,     0,     0,     0,     0,   113,   114,   115,   116,   117,
     118,   119,   120,     0,     0,     0,     0,     0,   134,     0,
       0,     0,     0,     0,   137,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,     0,   112,
       0,     0,     0,     0,     0,     0,     0,   113,   114,   115,
     116,   117,   118,   119,   120,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,     0,   112,
       0,     0,     0,     0,     0,     0,     0,   113,   114,   115,
     116,   117,   118,   119,   120,    99,   100,   101,   102,    -1,
     104,   105,   106,   107,   108,   109,   110,   111,     0,   112,
       0,     0,     0,     0,     0,     0,     0,     0,   114,   115,
     116,   117,   118,   119,   120,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,     0,   112,
       0,     0,     0,     0,     0,     0,     0,     0,   114,   115,
     116,   117,   118,   119,   120,    99,   100,     0,   102,     0,
     104,   105,   106,   107,   108,   109,   110,   111,     0,   112,
       0,     0,     0,     0,     0,     0,     0,     0,   114,   115,
     116,   117,   118,   119,   120,    99,     0,     0,   102,     0,
     104,   105,   106,   107,   108,   109,   110,   111,     0,   112,
       0,     0,     0,     0,     0,     0,     0,     0,   114,   115,
     116,   117,   118,   119,   120,    99,     0,     0,   102,     0,
      -1,    -1,    -1,    -1,    -1,   109,   110,   111,     0,   112,
       0,     0,     0,     0,     0,     0,     0,     0,    -1,    -1,
      -1,   117,   118,   119,   120
};

static const yytype_int16 yycheck[] =
{
      22,     0,    21,    25,    51,    10,    28,    27,    29,    27,
      27,    23,    31,    73,    36,    37,    27,    23,    78,    41,
      26,    42,    44,    45,    46,    47,    51,    32,    48,    58,
      48,    48,    54,    55,    56,    57,    51,    48,    72,    51,
      74,    58,    38,    58,    51,    51,    53,    68,     3,    70,
      46,    47,    52,    49,     3,    76,    76,    73,    76,    74,
      75,    74,    78,    51,    25,    51,    19,    63,    64,    72,
      74,    25,    51,    58,    38,    97,    77,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,     2,
     121,    17,    35,   124,   126,    49,   127,   128,     9,    -1,
      -1,   133,   134,   135,     5,    -1,   130,     8,     9,     4,
      -1,     6,     7,    -1,    15,    -1,    17,    18,    -1,    -1,
      21,    16,    -1,    24,    -1,    20,    -1,    -1,    -1,    30,
      -1,    -1,    33,    -1,    35,    -1,    -1,    32,    -1,    -1,
     172,   173,   174,    -1,    45,    -1,    -1,   179,   180,    50,
      51,    52,    53,    54,    55,    56,    51,    -1,    -1,    -1,
      61,    62,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     5,
      71,    -1,     8,     9,    75,    76,    -1,    -1,    -1,    15,
      75,    17,    18,     5,    -1,    21,    -1,     9,    24,    -1,
      -1,    -1,    -1,    15,    30,    17,    -1,    33,    -1,    35,
      -1,    -1,    24,    -1,    -1,    -1,    -1,    -1,    30,    45,
      -1,    33,    -1,    -1,    50,    51,    52,    53,    54,    55,
      56,    -1,    -1,    -1,    -1,    61,    62,    -1,    -1,    51,
      52,    53,    54,    55,    56,    71,    10,    -1,    -1,    75,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,
      -1,    -1,    -1,    75,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    10,    49,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    57,    58,    59,    60,    61,    62,    63,
      64,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    10,    49,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    57,    58,    59,    60,    61,    62,    63,    64,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      11,    49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    57,
      58,    59,    60,    61,    62,    63,    64,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    11,    49,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    57,    58,    59,    60,
      61,    62,    63,    64,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    11,    49,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    57,    58,    59,    60,    61,    62,    63,
      64,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    12,    49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      57,    58,    59,    60,    61,    62,    63,    64,    29,    -1,
      -1,    -1,    -1,    -1,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    13,    49,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    57,    58,    59,    60,
      61,    62,    63,    64,    -1,    -1,    -1,    -1,    -1,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    14,    49,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    58,    59,    60,    61,    62,    63,    64,    -1,
      -1,    -1,    -1,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    -1,    49,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    57,    58,    59,    60,    61,
      62,    63,    64,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    -1,    49,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    57,    58,    59,    60,    61,
      62,    63,    64,    -1,    -1,    -1,    -1,    -1,    28,    -1,
      -1,    -1,    -1,    -1,    76,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    -1,    49,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    57,    58,    59,
      60,    61,    62,    63,    64,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    -1,    49,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    57,    58,    59,
      60,    61,    62,    63,    64,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    -1,    49,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    58,    59,
      60,    61,    62,    63,    64,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    -1,    49,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    58,    59,
      60,    61,    62,    63,    64,    35,    36,    -1,    38,    -1,
      40,    41,    42,    43,    44,    45,    46,    47,    -1,    49,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    58,    59,
      60,    61,    62,    63,    64,    35,    -1,    -1,    38,    -1,
      40,    41,    42,    43,    44,    45,    46,    47,    -1,    49,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    58,    59,
      60,    61,    62,    63,    64,    35,    -1,    -1,    38,    -1,
      40,    41,    42,    43,    44,    45,    46,    47,    -1,    49,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    58,    59,
      60,    61,    62,    63,    64
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    80,    81,     0,    21,    31,    82,    83,    88,    23,
      26,    51,    85,    51,    90,    51,    96,    85,    86,    84,
      58,    89,    72,    74,    73,    78,    84,    51,    58,    74,
      75,    87,     3,    52,    92,     3,     5,     8,     9,    15,
      17,    18,    24,    30,    33,    35,    45,    50,    51,    52,
      53,    54,    55,    56,    61,    62,    71,    75,    83,    96,
      97,     4,     6,     7,    16,    20,    32,    51,    75,    94,
      74,    97,    97,    94,    51,    85,    25,    91,    90,    97,
      97,    51,    53,    51,    97,    94,    97,    97,    97,    97,
      95,    95,    97,    97,    97,    76,    97,    19,    73,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    49,    57,    58,    59,    60,    61,    62,    63,
      64,    25,    94,    27,    48,    94,    58,    74,    93,    94,
      77,    14,    51,    58,    28,    10,    97,    76,    97,    97,
      97,    97,    97,    97,    97,    97,    97,    97,    97,    97,
      97,    97,    97,    97,    97,    97,    97,    97,    97,    97,
      97,    94,    76,    94,    97,    94,    94,    92,    97,    97,
      97,    76,    12,    29,    13,    11,    97,    97,    97,    10,
      10,    97,    97,    11,    11
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    79,    80,    81,    81,    82,    82,    83,    83,    84,
      84,    85,    85,    85,    85,    85,    85,    86,    86,    87,
      87,    88,    89,    89,    90,    91,    91,    92,    92,    93,
      93,    94,    94,    94,    94,    94,    94,    94,    94,    94,
      94,    95,    95,    96,    96,    97,    97,    97,    97,    97,
      97,    97,    97,    97,    97,    97,    97,    97,    97,    97,
      97,    97,    97,    97,    97,    97,    97,    97,    97,    97,
      97,    97,    97,    97,    97,    97,    97,    97,    97,    97,
      97,    97,    97,    97,    97,    97,    97,    97,    97,    97,
      97,    97,    97,    97,    97
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     2,     1,     1,     3,     4,     0,
       3,     4,     6,     2,     3,     4,     5,     0,     2,     1,
       5,     3,     0,     3,     4,     0,     3,     1,     3,     1,
       2,     1,     1,     1,     1,     1,     1,     3,     3,     2,
       3,     0,     2,     3,     3,     1,     1,     1,     1,     1,
       1,     2,     3,     2,     2,     2,     2,     2,     2,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     2,     2,     2,     3,     2,     2,     2,     3,     3,
       4,     6,     5,     9,     9
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
#line 138 "parser.y" /* yacc.c:1646  */
    {
    std::cout << "AST:\n" << *(yyvsp[0].defList) << std::endl;
    (yyvsp[0].defList)->run(cout, "global");
  }
#line 1566 "parser.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 145 "parser.y" /* yacc.c:1646  */
    { (yyval.defList) = new DefList(); }
#line 1572 "parser.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 146 "parser.y" /* yacc.c:1646  */
    { (yyvsp[-1].defList)->append((yyvsp[0].def)); (yyval.defList) = (yyvsp[-1].defList); }
#line 1578 "parser.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 155 "parser.y" /* yacc.c:1646  */
    { (yyval.def) = (yyvsp[-1].let); if(!(yyvsp[0].andDef)->isEmpty()){(yyvsp[0].andDef)->append((yyvsp[-1].let)); (yyval.def) = (yyvsp[0].andDef);}}
#line 1584 "parser.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 156 "parser.y" /* yacc.c:1646  */
    { (yyval.def) = (yyvsp[-1].let); }
#line 1590 "parser.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 160 "parser.y" /* yacc.c:1646  */
    { (yyval.andDef) = new AndDef(); }
#line 1596 "parser.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 161 "parser.y" /* yacc.c:1646  */
    { (yyvsp[-2].andDef)->append((yyvsp[0].let)); (yyval.andDef) = (yyvsp[-2].andDef); }
#line 1602 "parser.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 165 "parser.y" /* yacc.c:1646  */
    { (yyval.let) = new Letdef(false, (yyvsp[-3].id), (yyvsp[-2].parList), (yyvsp[0].expr));}
#line 1608 "parser.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 166 "parser.y" /* yacc.c:1646  */
    { (yyval.let) = new Letdef(false, (yyvsp[-5].id), (yyvsp[-4].parList), (yyvsp[-2].type), (yyvsp[0].expr)); }
#line 1614 "parser.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 167 "parser.y" /* yacc.c:1646  */
    { (yyval.let) = new Letdef(true, (yyvsp[0].id)); }
#line 1620 "parser.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 168 "parser.y" /* yacc.c:1646  */
    { (yyval.let) = new Letdef(true, (yyvsp[-1].commaExprList)); }
#line 1626 "parser.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 169 "parser.y" /* yacc.c:1646  */
    { (yyval.let) = new Letdef(true, (yyvsp[-2].id), (yyvsp[0].type)); }
#line 1632 "parser.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 170 "parser.y" /* yacc.c:1646  */
    { (yyval.let) = new Letdef(true, (yyvsp[-3].commaExprList), (yyvsp[0].type)); }
#line 1638 "parser.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 174 "parser.y" /* yacc.c:1646  */
    { (yyval.parList) = new ParList(); }
#line 1644 "parser.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 175 "parser.y" /* yacc.c:1646  */
    { (yyvsp[-1].parList)->append((yyvsp[0].par)); (yyval.parList) = (yyvsp[-1].parList); }
#line 1650 "parser.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 179 "parser.y" /* yacc.c:1646  */
    { (yyval.par) = new Par((yyvsp[0].id)); }
#line 1656 "parser.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 180 "parser.y" /* yacc.c:1646  */
    { (yyval.par) = new ParType((yyvsp[-3].id), (yyvsp[-1].type)); }
#line 1662 "parser.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 185 "parser.y" /* yacc.c:1646  */
    { (yyval.def) = (yyvsp[-1].typeDef); if(!(yyvsp[0].andTypeDef)->isEmpty()){(yyvsp[0].andTypeDef)->append((yyvsp[-1].typeDef)); (yyval.def) = (yyvsp[0].andTypeDef);} }
#line 1668 "parser.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 189 "parser.y" /* yacc.c:1646  */
    { (yyval.andTypeDef) = new AndTypeDef(); }
#line 1674 "parser.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 190 "parser.y" /* yacc.c:1646  */
    { (yyvsp[-2].andTypeDef)->append((yyvsp[0].typeDef)); (yyval.andTypeDef) = (yyvsp[-2].andTypeDef); }
#line 1680 "parser.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 194 "parser.y" /* yacc.c:1646  */
    { (yyval.typeDef) = new Typedef((yyvsp[-3].id), (yyvsp[-1].constrId), (yyvsp[0].barConstrs)); }
#line 1686 "parser.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 200 "parser.y" /* yacc.c:1646  */
    { (yyval.barConstrs) = new BarConstrs(); }
#line 1692 "parser.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 201 "parser.y" /* yacc.c:1646  */
    { (yyvsp[-2].barConstrs)->append((yyvsp[0].constrId)); (yyval.barConstrs) = (yyvsp[-2].barConstrs); }
#line 1698 "parser.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 207 "parser.y" /* yacc.c:1646  */
    { (yyval.constrId) = new ConstrOfTypes((yyvsp[-2].constrId), (yyvsp[0].typeList)); }
#line 1704 "parser.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 211 "parser.y" /* yacc.c:1646  */
    { (yyval.typeList) = new TypeList(); (yyval.typeList)->append((yyvsp[0].type)); }
#line 1710 "parser.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 212 "parser.y" /* yacc.c:1646  */
    { (yyvsp[-1].typeList)->append((yyvsp[0].type)); (yyval.typeList) = (yyvsp[-1].typeList); }
#line 1716 "parser.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 217 "parser.y" /* yacc.c:1646  */
    { (yyval.type) = new Type("unit"); }
#line 1722 "parser.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 218 "parser.y" /* yacc.c:1646  */
    { (yyval.type) = new Type("int"); }
#line 1728 "parser.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 219 "parser.y" /* yacc.c:1646  */
    { (yyval.type) = new Type("char"); }
#line 1734 "parser.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 220 "parser.y" /* yacc.c:1646  */
    { (yyval.type) = new Type("bool"); }
#line 1740 "parser.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 221 "parser.y" /* yacc.c:1646  */
    { (yyval.type) = new Type("float"); }
#line 1746 "parser.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 222 "parser.y" /* yacc.c:1646  */
    { (yyval.type) = new Type((yyvsp[0].id)); }
#line 1752 "parser.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 223 "parser.y" /* yacc.c:1646  */
    { (yyval.type) = (yyvsp[-1].type); }
#line 1758 "parser.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 224 "parser.y" /* yacc.c:1646  */
    { (yyval.type) = new TypeToType((yyvsp[-2].type), (yyvsp[0].type)); }
#line 1764 "parser.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 225 "parser.y" /* yacc.c:1646  */
    { (yyval.type) = new TypeRef((yyvsp[-1].type)); }
#line 1770 "parser.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 226 "parser.y" /* yacc.c:1646  */
    { (yyval.type) = new ArrayOfType((yyvsp[0].type)); }
#line 1776 "parser.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 231 "parser.y" /* yacc.c:1646  */
    { (yyval.exprList) = new ExprList(); }
#line 1782 "parser.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 232 "parser.y" /* yacc.c:1646  */
    { (yyvsp[-1].exprList)->append((yyvsp[0].expr)); (yyval.exprList) = (yyvsp[-1].exprList);}
#line 1788 "parser.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 238 "parser.y" /* yacc.c:1646  */
    { (yyval.commaExprList) = new CommaExprList((yyvsp[-2].id)); (yyval.commaExprList)->append((yyvsp[0].expr)); }
#line 1794 "parser.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 239 "parser.y" /* yacc.c:1646  */
    { (yyvsp[-2].commaExprList)->append((yyvsp[0].expr)); (yyval.commaExprList) = (yyvsp[-2].commaExprList); }
#line 1800 "parser.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 244 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new IntConst((yyvsp[0].int_const)); }
#line 1806 "parser.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 245 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new FloatConst((yyvsp[0].float_const)); }
#line 1812 "parser.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 246 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new CharConst((yyvsp[0].char_const)); }
#line 1818 "parser.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 247 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new StringLiteral(*(yyvsp[0].stringLiteral)); }
#line 1824 "parser.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 248 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new BoolConst("true"); }
#line 1830 "parser.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 249 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new BoolConst("false"); }
#line 1836 "parser.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 251 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[-1].expr); }
#line 1842 "parser.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 253 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new UnOp("+", (yyvsp[0].expr)); }
#line 1848 "parser.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 254 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new UnOp("-", (yyvsp[0].expr)); }
#line 1854 "parser.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 255 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new UnOp("+.", (yyvsp[0].expr)); }
#line 1860 "parser.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 256 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new UnOp("-.", (yyvsp[0].expr)); }
#line 1866 "parser.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 257 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new UnOp("!", (yyvsp[0].expr)); }
#line 1872 "parser.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 258 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new UnOp("not", (yyvsp[0].expr)); }
#line 1878 "parser.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 260 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new BinOp((yyvsp[-2].expr), "+", (yyvsp[0].expr)); }
#line 1884 "parser.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 261 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new BinOp((yyvsp[-2].expr), "-", (yyvsp[0].expr)); }
#line 1890 "parser.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 262 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new BinOp((yyvsp[-2].expr), "*", (yyvsp[0].expr)); }
#line 1896 "parser.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 263 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new BinOp((yyvsp[-2].expr), "/", (yyvsp[0].expr)); }
#line 1902 "parser.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 264 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new BinOp((yyvsp[-2].expr), "+.", (yyvsp[0].expr)); }
#line 1908 "parser.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 265 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new BinOp((yyvsp[-2].expr), "-.", (yyvsp[0].expr)); }
#line 1914 "parser.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 266 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new BinOp((yyvsp[-2].expr), "*.", (yyvsp[0].expr)); }
#line 1920 "parser.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 267 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new BinOp((yyvsp[-2].expr), "/.", (yyvsp[0].expr)); }
#line 1926 "parser.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 268 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new BinOp((yyvsp[-2].expr), "mod", (yyvsp[0].expr)); }
#line 1932 "parser.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 269 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new BinOp((yyvsp[-2].expr), "**", (yyvsp[0].expr)); }
#line 1938 "parser.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 270 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new BinOp((yyvsp[-2].expr), "=", (yyvsp[0].expr)); }
#line 1944 "parser.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 271 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new BinOp((yyvsp[-2].expr), "<>", (yyvsp[0].expr)); }
#line 1950 "parser.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 272 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new BinOp((yyvsp[-2].expr), "<", (yyvsp[0].expr)); }
#line 1956 "parser.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 273 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new BinOp((yyvsp[-2].expr), ">", (yyvsp[0].expr));}
#line 1962 "parser.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 274 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new BinOp((yyvsp[-2].expr), "<=", (yyvsp[0].expr)); }
#line 1968 "parser.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 275 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new BinOp((yyvsp[-2].expr), ">=", (yyvsp[0].expr)); }
#line 1974 "parser.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 276 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new BinOp((yyvsp[-2].expr), "==", (yyvsp[0].expr)); }
#line 1980 "parser.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 277 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new BinOp((yyvsp[-2].expr), "!=", (yyvsp[0].expr)); }
#line 1986 "parser.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 278 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new BinOp((yyvsp[-2].expr), "&&", (yyvsp[0].expr)); }
#line 1992 "parser.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 279 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new BinOp((yyvsp[-2].expr), "||", (yyvsp[0].expr)); }
#line 1998 "parser.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 280 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new BinOp((yyvsp[-2].expr), ";", (yyvsp[0].expr)); /*std::cout << *$$ << endl;*/ }
#line 2004 "parser.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 281 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new BinOp((yyvsp[-2].expr), ":=", (yyvsp[0].expr)); }
#line 2010 "parser.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 283 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new Function_call((yyvsp[-1].id), (yyvsp[0].exprList)); }
#line 2016 "parser.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 284 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new Constr_call((yyvsp[-1].constrId), (yyvsp[0].exprList)); }
#line 2022 "parser.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 285 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new Dim((yyvsp[0].id), false); }
#line 2028 "parser.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 286 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new Dim((yyvsp[-1].int_const), (yyvsp[0].id), true); }
#line 2034 "parser.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 287 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new NewType((yyvsp[0].type)); }
#line 2040 "parser.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 288 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new Delete((yyvsp[0].expr)); }
#line 2046 "parser.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 289 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[-1].commaExprList); }
#line 2052 "parser.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 290 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new LetIn((yyvsp[-2].def), (yyvsp[0].expr)); }
#line 2058 "parser.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 292 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new Begin((yyvsp[-1].expr)); }
#line 2064 "parser.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 294 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new If((yyvsp[-2].expr), (yyvsp[0].expr)); /*std::cout << *$$;*/ }
#line 2070 "parser.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 295 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new If((yyvsp[-4].expr), (yyvsp[-2].expr), (yyvsp[0].expr));  }
#line 2076 "parser.cpp" /* yacc.c:1646  */
    break;

  case 92:
#line 296 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new While((yyvsp[-3].expr), (yyvsp[-1].expr)); }
#line 2082 "parser.cpp" /* yacc.c:1646  */
    break;

  case 93:
#line 297 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new For((yyvsp[-7].id), (yyvsp[-5].expr), (yyvsp[-3].expr), (yyvsp[-1].expr), true); }
#line 2088 "parser.cpp" /* yacc.c:1646  */
    break;

  case 94:
#line 298 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new For((yyvsp[-7].id), (yyvsp[-5].expr), (yyvsp[-3].expr), (yyvsp[-1].expr), false); }
#line 2094 "parser.cpp" /* yacc.c:1646  */
    break;


#line 2098 "parser.cpp" /* yacc.c:1646  */
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
#line 335 "parser.y" /* yacc.c:1906  */

int main() {
  int result = yyparse();
  if (result == 0) printf("Success.\n");
  //for (auto it = symbolTable.begin(); it != symbolTable.end(); ++it) cout << " " << (*it).getSymbolName() << (*it).getSymbolType() << (*it).getSymbolScope() << endl;
  return result;
}