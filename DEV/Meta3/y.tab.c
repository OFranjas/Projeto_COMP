/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 8 "expr.y"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Tree.h"


struct AST *root;
struct AST *methodParams;
struct AST *temp;
char aux[1024];
char aux2[1024];
struct AST *methodParams;
int flag = 1;

char *type;
int n_sons;
int yydebug = 1;
int print_tree = 1;

int yylex(void);
extern int yylineno;
extern int coluna;
extern int yyerror(char *s);


int yydegug = 1;




#line 102 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    CLASS = 258,
    PUBLIC = 259,
    STATIC = 260,
    STRING = 261,
    VOID = 262,
    INT = 263,
    DOUBLE = 264,
    BOOL = 265,
    SEMICOLON = 266,
    COMMA = 267,
    LBRACE = 268,
    RBRACE = 269,
    LPAR = 270,
    RPAR = 271,
    LSQ = 272,
    RSQ = 273,
    ASSIGN = 274,
    PLUS = 275,
    MINUS = 276,
    STAR = 277,
    DIV = 278,
    MOD = 279,
    XOR = 280,
    OR = 281,
    AND = 282,
    EQ = 283,
    NE = 284,
    LE = 285,
    GE = 286,
    LT = 287,
    GT = 288,
    NOT = 289,
    WHILE = 290,
    IF = 291,
    ELSE = 292,
    RETURN = 293,
    ARROW = 294,
    LSHIFT = 295,
    RSHIFT = 296,
    DOTLENGTH = 297,
    PRINT = 298,
    PARSEINT = 299,
    RESERVED = 300,
    REALLIT = 301,
    STRLIT = 302,
    INTLIT = 303,
    ID = 304,
    BOOLLIT = 305
  };
#endif
/* Tokens.  */
#define CLASS 258
#define PUBLIC 259
#define STATIC 260
#define STRING 261
#define VOID 262
#define INT 263
#define DOUBLE 264
#define BOOL 265
#define SEMICOLON 266
#define COMMA 267
#define LBRACE 268
#define RBRACE 269
#define LPAR 270
#define RPAR 271
#define LSQ 272
#define RSQ 273
#define ASSIGN 274
#define PLUS 275
#define MINUS 276
#define STAR 277
#define DIV 278
#define MOD 279
#define XOR 280
#define OR 281
#define AND 282
#define EQ 283
#define NE 284
#define LE 285
#define GE 286
#define LT 287
#define GT 288
#define NOT 289
#define WHILE 290
#define IF 291
#define ELSE 292
#define RETURN 293
#define ARROW 294
#define LSHIFT 295
#define RSHIFT 296
#define DOTLENGTH 297
#define PRINT 298
#define PARSEINT 299
#define RESERVED 300
#define REALLIT 301
#define STRLIT 302
#define INTLIT 303
#define ID 304
#define BOOLLIT 305

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 40 "expr.y"

char* string;
struct AST* ast;

#line 259 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

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
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   384

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  51
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  23
/* YYNRULES -- Number of rules.  */
#define YYNRULES  83
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  179

#define YYUNDEFTOK  2
#define YYMAXUTOK   305


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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
      45,    46,    47,    48,    49,    50
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    78,    78,    82,    83,    84,    85,    88,    92,    93,
      97,    99,   102,   103,   104,   109,   110,   114,   116,   117,
     121,   123,   127,   131,   132,   133,   139,   142,   143,   146,
     170,   172,   187,   205,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   226,   227,   231,   232,   233,   236,   239,
     240,   243,   246,   247,   250,   251,   254,   255,   256,   257,
     258,   259,   260,   261,   262,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "CLASS", "PUBLIC", "STATIC", "STRING",
  "VOID", "INT", "DOUBLE", "BOOL", "SEMICOLON", "COMMA", "LBRACE",
  "RBRACE", "LPAR", "RPAR", "LSQ", "RSQ", "ASSIGN", "PLUS", "MINUS",
  "STAR", "DIV", "MOD", "XOR", "OR", "AND", "EQ", "NE", "LE", "GE", "LT",
  "GT", "NOT", "WHILE", "IF", "ELSE", "RETURN", "ARROW", "LSHIFT",
  "RSHIFT", "DOTLENGTH", "PRINT", "PARSEINT", "RESERVED", "REALLIT",
  "STRLIT", "INTLIT", "ID", "BOOLLIT", "$accept", "Program", "ProgramAux",
  "MethodDecl", "FieldDecl", "FieldDeclAux", "Type", "MethodHeader",
  "FormalParams", "FormalParamsAux", "MethodBody", "MethodBodyAux",
  "VarDecl", "VarDeclAux", "Statement", "StatementAux", "MethodInvocation",
  "MethodInvocationAux", "MethodInvocationAux_2", "Assignment",
  "ParseArgs", "Expr", "ExprAux", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305
};
# endif

#define YYPACT_NINF (-41)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-45)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       3,   -40,    21,    14,   -41,    35,    18,    28,    35,    34,
      35,    35,   -41,   110,   -41,   -41,   -41,   -41,     8,   -41,
     -41,   -41,     9,    49,    60,    30,   166,   -41,    68,    15,
      68,    73,    75,   -41,   170,    76,    83,    82,    84,    99,
      -3,    66,   107,   166,   166,   111,   114,   118,   117,    86,
     125,   130,   127,   -41,   -41,   -41,   185,   224,   224,   -41,
      46,   256,   256,   256,   -41,   -41,    -4,   -41,   -41,   -41,
     -41,   133,   287,   217,     2,    39,   224,   134,   -41,   -41,
     -41,   -41,   -41,   -41,   132,   136,   -41,   -41,   -41,   185,
     131,   152,   153,   154,   156,   -11,   -41,   -41,   -41,   -41,
     -41,   256,   256,   256,   256,   256,   256,   256,   256,   256,
     256,   256,   256,   256,   256,   256,   256,   157,   162,   169,
     165,   171,   -41,   172,   177,   -41,   141,   180,   143,    96,
     -41,   -41,   -41,   211,   211,   -41,   -41,   115,   115,   -41,
     -41,   -41,   337,   309,   323,   351,   351,    48,    48,    48,
      48,   263,   263,   182,   183,   -41,   224,   -41,   -41,   224,
     -41,   134,   -41,   -41,   146,   -41,   160,   -41,   -41,   189,
     177,   -41,   136,   211,   184,   -41,   -41,   -41,   -41
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,     0,     0,     0,     0,
       0,     0,     9,     0,     6,     2,     4,     5,     0,    12,
      13,    14,     0,     0,     0,    11,     0,     7,    19,     0,
      19,     0,     0,    39,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    11,     0,     8,    42,    30,     0,     0,     0,    35,
       0,     0,     0,     0,    79,    78,    76,    80,    81,    55,
      82,     0,    54,     0,     0,     0,     0,    28,    22,    24,
      23,    36,    37,    38,     0,    21,    16,    10,    15,     0,
       0,     0,     0,     0,     0,    76,    74,    72,    73,    77,
      34,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    45,     0,    49,    51,     0,     0,     0,     0,
      17,    43,    29,     0,     0,    83,    75,    56,    57,    58,
      59,    60,    62,    61,    63,    66,    67,    70,    71,    68,
      69,    64,    65,     0,     0,    53,     0,    47,    46,     0,
      48,    28,    26,    18,     0,    33,    31,    41,    40,     0,
      49,    27,    21,     0,     0,    50,    20,    32,    52
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -41,   -41,    71,   -41,   -41,   167,    -6,   -41,   173,    44,
     -41,   -30,   -41,    56,   -33,   122,   -26,   -41,    55,   -32,
     -24,   -23,    50
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     9,    10,    11,    31,    41,    23,    50,   130,
      27,    42,    43,   127,    44,    90,    68,   123,   160,    46,
      70,    71,    72
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      45,    56,    47,   119,    75,    69,     1,    22,    45,     3,
      47,    75,    75,    79,    80,    76,    76,    45,    45,    47,
      47,     4,    49,    89,    49,    69,    69,     5,    69,    12,
      45,    99,    47,    13,    91,    92,     6,    94,    99,     7,
     121,    69,    29,    69,    69,    30,     8,    93,    15,    -3,
     118,   120,   124,   125,    60,   122,    89,    24,    25,    61,
      62,    60,    26,    45,    51,    47,    61,    62,   101,   102,
     103,   104,   105,    63,    48,    28,    19,    20,    21,    14,
      63,    16,    17,    39,    53,    64,    54,    65,    66,    67,
      39,    57,    64,    59,    65,    66,    67,    60,    58,    73,
     165,   166,    61,    62,    19,    20,    21,    45,    45,    47,
      47,    96,    97,    98,    74,    77,    63,    18,    19,    20,
      21,    78,    81,   164,    69,    82,    39,    69,    64,    83,
      65,    66,    67,   169,    84,    85,   170,   103,   104,   105,
     177,    86,    29,    88,   100,   132,   126,    45,   129,    47,
     128,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,    32,   133,   134,
     135,    32,   136,   153,    19,    20,    21,    33,   154,    34,
     -25,    33,   156,    34,    55,   155,    32,   157,   158,   159,
     161,   162,   163,   167,   168,   172,    33,   173,    34,   -44,
     178,    35,    36,    52,    37,    35,    36,   174,    37,    38,
      39,   131,    32,    38,    39,    40,   176,   171,    87,    40,
      35,    36,    33,    37,    34,   175,     0,     0,    38,    39,
       0,     0,    60,     0,    40,     0,     0,    61,    62,    60,
       0,     0,     0,     0,    61,    62,    35,    36,     0,    37,
       0,    63,     0,     0,    38,    39,     0,     0,    63,     0,
      40,    39,     0,    64,   117,    65,    66,    67,    39,     0,
      64,    60,    65,    66,    67,     0,    61,    62,     0,     0,
       0,     0,     0,   101,   102,   103,   104,   105,     0,     0,
      63,   109,   110,   111,   112,   113,   114,     0,     0,     0,
      39,     0,    64,     0,    65,    95,    67,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,     0,     0,     0,     0,     0,     0,   115,   116,   101,
     102,   103,   104,   105,   106,     0,   108,   109,   110,   111,
     112,   113,   114,   101,   102,   103,   104,   105,   106,   115,
     116,   109,   110,   111,   112,   113,   114,   101,   102,   103,
     104,   105,     0,   115,   116,   109,   110,   111,   112,   113,
     114,   101,   102,   103,   104,   105,     0,   115,   116,     0,
       0,   111,   112,   113,   114
};

static const yytype_int16 yycheck[] =
{
      26,    34,    26,     1,    15,    37,     3,    13,    34,    49,
      34,    15,    15,    43,    44,    19,    19,    43,    44,    43,
      44,     0,    28,    56,    30,    57,    58,    13,    60,    11,
      56,    42,    56,     5,    57,    58,     1,    60,    42,     4,
       1,    73,    12,    75,    76,    15,    11,     1,    14,    14,
      73,    49,    75,    76,    15,    16,    89,    49,    49,    20,
      21,    15,    13,    89,    49,    89,    20,    21,    20,    21,
      22,    23,    24,    34,     6,    15,     8,     9,    10,     8,
      34,    10,    11,    44,    11,    46,    11,    48,    49,    50,
      44,    15,    46,    11,    48,    49,    50,    15,    15,    15,
     133,   134,    20,    21,     8,     9,    10,   133,   134,   133,
     134,    61,    62,    63,    15,    49,    34,     7,     8,     9,
      10,    14,    11,   129,   156,    11,    44,   159,    46,    11,
      48,    49,    50,   156,    17,    49,   159,    22,    23,    24,
     173,    16,    12,    16,    11,    14,    12,   173,    12,   173,
      18,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,     1,    16,    16,
      16,     1,    16,    16,     8,     9,    10,    11,    16,    13,
      14,    11,    17,    13,    14,    16,     1,    16,    16,    12,
      49,    11,    49,    11,    11,    49,    11,    37,    13,    14,
      16,    35,    36,    30,    38,    35,    36,    18,    38,    43,
      44,    89,     1,    43,    44,    49,   172,   161,    51,    49,
      35,    36,    11,    38,    13,   170,    -1,    -1,    43,    44,
      -1,    -1,    15,    -1,    49,    -1,    -1,    20,    21,    15,
      -1,    -1,    -1,    -1,    20,    21,    35,    36,    -1,    38,
      -1,    34,    -1,    -1,    43,    44,    -1,    -1,    34,    -1,
      49,    44,    -1,    46,    47,    48,    49,    50,    44,    -1,
      46,    15,    48,    49,    50,    -1,    20,    21,    -1,    -1,
      -1,    -1,    -1,    20,    21,    22,    23,    24,    -1,    -1,
      34,    28,    29,    30,    31,    32,    33,    -1,    -1,    -1,
      44,    -1,    46,    -1,    48,    49,    50,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    -1,    -1,    -1,    -1,    -1,    -1,    40,    41,    20,
      21,    22,    23,    24,    25,    -1,    27,    28,    29,    30,
      31,    32,    33,    20,    21,    22,    23,    24,    25,    40,
      41,    28,    29,    30,    31,    32,    33,    20,    21,    22,
      23,    24,    -1,    40,    41,    28,    29,    30,    31,    32,
      33,    20,    21,    22,    23,    24,    -1,    40,    41,    -1,
      -1,    30,    31,    32,    33
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    52,    49,     0,    13,     1,     4,    11,    53,
      54,    55,    11,     5,    53,    14,    53,    53,     7,     8,
       9,    10,    57,    58,    49,    49,    13,    61,    15,    12,
      15,    56,     1,    11,    13,    35,    36,    38,    43,    44,
      49,    57,    62,    63,    65,    67,    70,    71,     6,    57,
      59,    49,    59,    11,    11,    14,    65,    15,    15,    11,
      15,    20,    21,    34,    46,    48,    49,    50,    67,    70,
      71,    72,    73,    15,    15,    15,    19,    49,    14,    62,
      62,    11,    11,    11,    17,    49,    16,    56,    16,    65,
      66,    72,    72,     1,    72,    49,    73,    73,    73,    42,
      11,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    40,    41,    47,    72,     1,
      49,     1,    16,    68,    72,    72,    12,    64,    18,    12,
      60,    66,    14,    16,    16,    16,    16,    73,    73,    73,
      73,    73,    73,    73,    73,    73,    73,    73,    73,    73,
      73,    73,    73,    16,    16,    16,    17,    16,    16,    12,
      69,    49,    11,    49,    57,    65,    65,    11,    11,    72,
      72,    64,    49,    37,    18,    69,    60,    65,    16
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    51,    52,    53,    53,    53,    53,    54,    55,    55,
      56,    56,    57,    57,    57,    58,    58,    59,    59,    59,
      60,    60,    61,    62,    62,    62,    63,    64,    64,    65,
      65,    65,    65,    65,    65,    65,    65,    65,    65,    65,
      65,    65,    65,    66,    66,    67,    67,    67,    68,    69,
      69,    70,    71,    71,    72,    72,    73,    73,    73,    73,
      73,    73,    73,    73,    73,    73,    73,    73,    73,    73,
      73,    73,    73,    73,    73,    73,    73,    73,    73,    73,
      73,    73,    73,    73
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     5,     0,     2,     2,     2,     4,     6,     2,
       3,     0,     1,     1,     1,     5,     5,     3,     4,     0,
       4,     0,     3,     2,     2,     0,     4,     3,     0,     4,
       2,     5,     7,     5,     3,     2,     2,     2,     2,     1,
       5,     5,     2,     2,     0,     3,     4,     4,     2,     0,
       3,     3,     7,     4,     1,     1,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     2,     2,     2,     3,     1,     2,     1,     1,
       1,     1,     1,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
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
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
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
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

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
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
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
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
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
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
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
          ++yyp;
          ++yyformat;
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
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

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
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
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
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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
#line 78 "expr.y"
                                                             {root = AST_newNode("Program","");AST_addSon(root, AST_newNode("Id", (yyvsp[-3].string)));AST_addSon(root,(yyvsp[-1].ast));(yyval.ast) = root;}
#line 1596 "y.tab.c"
    break;

  case 3:
#line 82 "expr.y"
                                                                                             {(yyval.ast)=NULL;}
#line 1602 "y.tab.c"
    break;

  case 4:
#line 83 "expr.y"
                                                             {(yyval.ast) = (yyvsp[-1].ast);AST_addBrother((yyval.ast), (yyvsp[0].ast));}
#line 1608 "y.tab.c"
    break;

  case 5:
#line 84 "expr.y"
                                                             {(yyval.ast) = (yyvsp[-1].ast);AST_addBrother((yyval.ast), (yyvsp[0].ast));}
#line 1614 "y.tab.c"
    break;

  case 6:
#line 85 "expr.y"
                                                             {(yyval.ast) = (yyvsp[0].ast);}
#line 1620 "y.tab.c"
    break;

  case 7:
#line 88 "expr.y"
                                                             {(yyval.ast) = AST_newNode("MethodDecl","");AST_addSon((yyval.ast),(yyvsp[-1].ast));AST_addSon((yyval.ast),(yyvsp[0].ast));}
#line 1626 "y.tab.c"
    break;

  case 8:
#line 92 "expr.y"
                                                             {(yyval.ast) = AST_newNode("FieldDecl", "");AST_addSon((yyval.ast),(yyvsp[-3].ast));AST_addSon((yyval.ast), AST_newNode("Id", (yyvsp[-2].string)));givetype((yyvsp[-1].ast), (yyvsp[-3].ast)->type);AST_addBrother((yyval.ast), (yyvsp[-1].ast));}
#line 1632 "y.tab.c"
    break;

  case 9:
#line 93 "expr.y"
                                                             {(yyval.ast) = NULL;print_tree=0;}
#line 1638 "y.tab.c"
    break;

  case 10:
#line 97 "expr.y"
                                                             {(yyval.ast) = AST_newNode("FieldDecl","");AST_addSon((yyval.ast), AST_newNode("Id", (yyvsp[-1].string)));AST_addBrother((yyval.ast), (yyvsp[0].ast));}
#line 1644 "y.tab.c"
    break;

  case 11:
#line 99 "expr.y"
                                                             {(yyval.ast) = NULL;}
#line 1650 "y.tab.c"
    break;

  case 12:
#line 102 "expr.y"
                                                             {(yyval.ast) = AST_newNode("Int", "");}
#line 1656 "y.tab.c"
    break;

  case 13:
#line 103 "expr.y"
                                                             {(yyval.ast) = AST_newNode("Double", "");}
#line 1662 "y.tab.c"
    break;

  case 14:
#line 104 "expr.y"
                                                             {(yyval.ast) = AST_newNode("Bool", "");}
#line 1668 "y.tab.c"
    break;

  case 15:
#line 109 "expr.y"
                                                             {(yyval.ast) = AST_newNode("MethodHeader","");methodParams = AST_newNode("MethodParams","");AST_addSon((yyval.ast),(yyvsp[-4].ast));AST_addSon((yyval.ast),AST_newNode("Id", (yyvsp[-3].string)));AST_addSon((yyval.ast), methodParams);AST_addSon(methodParams,(yyvsp[-1].ast));}
#line 1674 "y.tab.c"
    break;

  case 16:
#line 110 "expr.y"
                                                             {(yyval.ast) = AST_newNode("MethodHeader","");methodParams = AST_newNode("MethodParams","");AST_addSon((yyval.ast),AST_newNode("Void", ""));AST_addSon((yyval.ast),AST_newNode("Id", (yyvsp[-3].string)));AST_addSon((yyval.ast), methodParams);AST_addSon(methodParams,(yyvsp[-1].ast));}
#line 1680 "y.tab.c"
    break;

  case 17:
#line 114 "expr.y"
                                                             {(yyval.ast) = AST_newNode("ParamDecl","");AST_addSon((yyval.ast),(yyvsp[-2].ast));AST_addSon((yyval.ast),AST_newNode("Id", (yyvsp[-1].string)));AST_addBrother((yyval.ast),(yyvsp[0].ast));}
#line 1686 "y.tab.c"
    break;

  case 18:
#line 116 "expr.y"
                                                             {(yyval.ast) = AST_newNode("ParamDecl","");AST_addSon((yyval.ast),AST_newNode("StringArray",""));AST_addSon((yyval.ast),AST_newNode("Id", (yyvsp[0].string)));}
#line 1692 "y.tab.c"
    break;

  case 19:
#line 117 "expr.y"
                                                             {(yyval.ast) = NULL;}
#line 1698 "y.tab.c"
    break;

  case 20:
#line 121 "expr.y"
                                                             {(yyval.ast) = AST_newNode("ParamDecl","");AST_addSon((yyval.ast),(yyvsp[-2].ast));AST_addSon((yyval.ast),AST_newNode("Id",(yyvsp[-1].string)));AST_addBrother((yyval.ast),(yyvsp[0].ast));}
#line 1704 "y.tab.c"
    break;

  case 21:
#line 123 "expr.y"
                                                             {(yyval.ast) = NULL;}
#line 1710 "y.tab.c"
    break;

  case 22:
#line 127 "expr.y"
                                                             {(yyval.ast) = AST_newNode("MethodBody","");AST_addSon((yyval.ast),(yyvsp[-1].ast));}
#line 1716 "y.tab.c"
    break;

  case 23:
#line 131 "expr.y"
                                                             {if((yyvsp[-1].ast) != NULL){(yyval.ast) = (yyvsp[-1].ast); AST_addBrother((yyval.ast), (yyvsp[0].ast));}else{(yyval.ast) = (yyvsp[0].ast);}}
#line 1722 "y.tab.c"
    break;

  case 24:
#line 132 "expr.y"
                                                             {(yyval.ast) = (yyvsp[-1].ast); AST_addBrother((yyval.ast), (yyvsp[0].ast));}
#line 1728 "y.tab.c"
    break;

  case 25:
#line 133 "expr.y"
                                                             {(yyval.ast) = NULL;}
#line 1734 "y.tab.c"
    break;

  case 26:
#line 139 "expr.y"
                                                             {(yyval.ast) = AST_newNode("VarDecl", "");AST_addSon((yyval.ast), (yyvsp[-3].ast));AST_addSon((yyval.ast), AST_newNode("Id", (yyvsp[-2].string)));givetype((yyvsp[-1].ast), (yyvsp[-3].ast)->type);AST_addBrother((yyval.ast), (yyvsp[-1].ast));}
#line 1740 "y.tab.c"
    break;

  case 27:
#line 142 "expr.y"
                                                             {(yyval.ast) = AST_newNode("VarDecl","");AST_addSon((yyval.ast), AST_newNode("Id", (yyvsp[-1].string)));AST_addBrother((yyval.ast), (yyvsp[0].ast));}
#line 1746 "y.tab.c"
    break;

  case 28:
#line 143 "expr.y"
                                                             {(yyval.ast) = NULL;}
#line 1752 "y.tab.c"
    break;

  case 29:
#line 146 "expr.y"
                                                                 {
                                                                int count = 0;
                                                                if((yyvsp[-2].ast) != NULL){
                                                                    count++;
                                                                }
                                                                temp = (yyvsp[-1].ast);
                                                                while(temp != NULL){
                                                                    if(temp->type != NULL && strcmp(temp->type,"Semicolon")!=0){
                                                                        count++;
                                                                    }

                                                                    temp = temp->brother;
                                                                }
                                                                
                                                                if(count > 1){
                                                                    (yyval.ast) = AST_newNode("Block","");
                                                                    AST_addSon((yyval.ast),(yyvsp[-2].ast));
                                                                    AST_addSon((yyval.ast),(yyvsp[-1].ast));
                                                                }
                                                                else {
                                                                    (yyval.ast) = (yyvsp[-2].ast);
                                                                }
                                                            }
#line 1780 "y.tab.c"
    break;

  case 30:
#line 170 "expr.y"
                                                                                                     {(yyval.ast) = NULL;}
#line 1786 "y.tab.c"
    break;

  case 31:
#line 172 "expr.y"
                                                                                     {
                                                                (yyval.ast) = AST_newNode("If","");
                                                                AST_addSon((yyval.ast),(yyvsp[-2].ast));
                                                                
                                                                if((yyvsp[0].ast) == NULL || strcmp((yyvsp[0].ast)->type,"Semicolon")==0){
                                                                    AST_addSon((yyval.ast),AST_newNode("Block",""));
                                                                    AST_addSon((yyval.ast),AST_newNode("Block",""));
                                                                }else{
                                                                    AST_addSon((yyval.ast),(yyvsp[0].ast));
                                                                    AST_addSon((yyval.ast),AST_newNode("Block",""));
                                                                }
                                                                
                                                            }
#line 1804 "y.tab.c"
    break;

  case 32:
#line 187 "expr.y"
                                                                     {
                                                                (yyval.ast) = AST_newNode("If","");
                                                                AST_addSon((yyval.ast),(yyvsp[-4].ast));
                                                                if((yyvsp[-2].ast) == NULL || strcmp((yyvsp[-2].ast)->type,"Semicolon")==0){
                                                                    AST_addSon((yyval.ast),AST_newNode("Block","")); // addbrother(3,5)
                                                                }else{
                                                                    AST_addSon((yyval.ast),(yyvsp[-2].ast));
                                                                }
                                                                if((yyvsp[0].ast) == NULL || strcmp((yyvsp[0].ast)->type,"Semicolon")==0){
                                                                    AST_addSon((yyval.ast),AST_newNode("Block","")); // addbrother(3,7)
                                                                }else{
                                                                    AST_addSon((yyval.ast),(yyvsp[0].ast));
                                                                }
                                                                
                                                            }
#line 1824 "y.tab.c"
    break;

  case 33:
#line 205 "expr.y"
                                                                                     {
                                                                (yyval.ast) = AST_newNode("While","");
                                                                AST_addSon((yyval.ast),(yyvsp[-2].ast));
                                                                if((yyvsp[0].ast) == NULL || strcmp((yyvsp[0].ast)->type,"Semicolon")==0){
                                                                    AST_addSon((yyval.ast),AST_newNode("Block",""));
                                                                }else{
                                                                    AST_addSon((yyval.ast),(yyvsp[0].ast));
                                                                }
                                                            }
#line 1838 "y.tab.c"
    break;

  case 34:
#line 215 "expr.y"
                                                                                     {(yyval.ast) = AST_newNode("Return","");AST_addSon((yyval.ast),(yyvsp[-1].ast));}
#line 1844 "y.tab.c"
    break;

  case 35:
#line 216 "expr.y"
                                                                                                     {(yyval.ast) = AST_newNode("Return", "");}
#line 1850 "y.tab.c"
    break;

  case 36:
#line 217 "expr.y"
                                                                                     {(yyval.ast) = (yyvsp[-1].ast);}
#line 1856 "y.tab.c"
    break;

  case 37:
#line 218 "expr.y"
                                                                                             {(yyval.ast) = AST_newNode("Assign","");AST_addSon((yyval.ast),(yyvsp[-1].ast));}
#line 1862 "y.tab.c"
    break;

  case 38:
#line 219 "expr.y"
                                                                                             {(yyval.ast) = (yyvsp[-1].ast);}
#line 1868 "y.tab.c"
    break;

  case 39:
#line 220 "expr.y"
                                                                                                     {(yyval.ast) = AST_newNode("Semicolon","");}
#line 1874 "y.tab.c"
    break;

  case 40:
#line 221 "expr.y"
                                                                                     {(yyval.ast) = AST_newNode("Print","");AST_addSon((yyval.ast),(yyvsp[-2].ast));}
#line 1880 "y.tab.c"
    break;

  case 41:
#line 222 "expr.y"
                                                                             {(yyval.ast) = AST_newNode("Print","");AST_addSon((yyval.ast), AST_newNode("StrLit", (yyvsp[-2].string)));}
#line 1886 "y.tab.c"
    break;

  case 42:
#line 223 "expr.y"
                                                                                                     {(yyval.ast) = NULL;print_tree = 0;}
#line 1892 "y.tab.c"
    break;

  case 43:
#line 226 "expr.y"
                                                             {(yyval.ast) = (yyvsp[-1].ast);AST_addBrother((yyval.ast),(yyvsp[0].ast));}
#line 1898 "y.tab.c"
    break;

  case 44:
#line 227 "expr.y"
                                                             {(yyval.ast) = NULL;}
#line 1904 "y.tab.c"
    break;

  case 45:
#line 231 "expr.y"
                                                                                 {(yyval.ast) = AST_newNode("Call", "");AST_addSon((yyval.ast), AST_newNode("Id", (yyvsp[-2].string)));}
#line 1910 "y.tab.c"
    break;

  case 46:
#line 232 "expr.y"
                                                                                     {(yyval.ast) = AST_newNode("Call", "");AST_addSon((yyval.ast), AST_newNode("Id", (yyvsp[-3].string)));AST_addSon((yyval.ast),(yyvsp[-1].ast));}
#line 1916 "y.tab.c"
    break;

  case 47:
#line 233 "expr.y"
                                                                                             {(yyval.ast) = NULL;print_tree = 0;}
#line 1922 "y.tab.c"
    break;

  case 48:
#line 236 "expr.y"
                                                                     {(yyval.ast) = (yyvsp[-1].ast);AST_addBrother((yyval.ast),(yyvsp[0].ast));}
#line 1928 "y.tab.c"
    break;

  case 49:
#line 239 "expr.y"
                                                                                 {(yyval.ast) = NULL;}
#line 1934 "y.tab.c"
    break;

  case 50:
#line 240 "expr.y"
                                                                                 {(yyval.ast) = (yyvsp[-1].ast);AST_addBrother((yyval.ast),(yyvsp[0].ast));}
#line 1940 "y.tab.c"
    break;

  case 51:
#line 243 "expr.y"
                                                             {(yyval.ast) = AST_newNode("Id", (yyvsp[-2].string)); AST_addBrother((yyval.ast),(yyvsp[0].ast));}
#line 1946 "y.tab.c"
    break;

  case 52:
#line 246 "expr.y"
                                                             {(yyval.ast) = AST_newNode("ParseArgs","");AST_addSon((yyval.ast), AST_newNode("Id", (yyvsp[-4].string)));AST_addSon((yyval.ast), (yyvsp[-2].ast));}
#line 1952 "y.tab.c"
    break;

  case 53:
#line 247 "expr.y"
                                                             {(yyval.ast) = NULL;print_tree=0;}
#line 1958 "y.tab.c"
    break;

  case 54:
#line 250 "expr.y"
                                                            {(yyval.ast) = (yyvsp[0].ast);}
#line 1964 "y.tab.c"
    break;

  case 55:
#line 251 "expr.y"
                                                            {(yyval.ast) = AST_newNode("Assign","");AST_addSon((yyval.ast),(yyvsp[0].ast));}
#line 1970 "y.tab.c"
    break;

  case 56:
#line 254 "expr.y"
                                                            {(yyval.ast) = AST_newNode("Add","");AST_addSon((yyval.ast),(yyvsp[-2].ast));AST_addBrother((yyvsp[-2].ast),(yyvsp[0].ast));}
#line 1976 "y.tab.c"
    break;

  case 57:
#line 255 "expr.y"
                                                            {(yyval.ast) = AST_newNode("Sub","");AST_addSon((yyval.ast),(yyvsp[-2].ast));AST_addBrother((yyvsp[-2].ast),(yyvsp[0].ast));}
#line 1982 "y.tab.c"
    break;

  case 58:
#line 256 "expr.y"
                                                            {(yyval.ast) = AST_newNode("Mul","");AST_addSon((yyval.ast),(yyvsp[-2].ast));AST_addBrother((yyvsp[-2].ast),(yyvsp[0].ast));}
#line 1988 "y.tab.c"
    break;

  case 59:
#line 257 "expr.y"
                                                            {(yyval.ast) = AST_newNode("Div","");AST_addSon((yyval.ast),(yyvsp[-2].ast));AST_addBrother((yyvsp[-2].ast),(yyvsp[0].ast));}
#line 1994 "y.tab.c"
    break;

  case 60:
#line 258 "expr.y"
                                                            {(yyval.ast) = AST_newNode("Mod","");AST_addSon((yyval.ast),(yyvsp[-2].ast));AST_addBrother((yyvsp[-2].ast),(yyvsp[0].ast));}
#line 2000 "y.tab.c"
    break;

  case 61:
#line 259 "expr.y"
                                                            {(yyval.ast) = AST_newNode("Or","");AST_addSon((yyval.ast),(yyvsp[-2].ast));AST_addBrother((yyvsp[-2].ast),(yyvsp[0].ast));}
#line 2006 "y.tab.c"
    break;

  case 62:
#line 260 "expr.y"
                                                            {(yyval.ast) = AST_newNode("Xor","");AST_addSon((yyval.ast),(yyvsp[-2].ast));AST_addBrother((yyvsp[-2].ast),(yyvsp[0].ast));}
#line 2012 "y.tab.c"
    break;

  case 63:
#line 261 "expr.y"
                                                            {(yyval.ast) = AST_newNode("And","");AST_addSon((yyval.ast),(yyvsp[-2].ast));AST_addBrother((yyvsp[-2].ast),(yyvsp[0].ast));}
#line 2018 "y.tab.c"
    break;

  case 64:
#line 262 "expr.y"
                                                            {(yyval.ast) = AST_newNode("Lshift","");AST_addSon((yyval.ast),(yyvsp[-2].ast));AST_addBrother((yyvsp[-2].ast),(yyvsp[0].ast));}
#line 2024 "y.tab.c"
    break;

  case 65:
#line 263 "expr.y"
                                                            {(yyval.ast) = AST_newNode("Rshift","");AST_addSon((yyval.ast),(yyvsp[-2].ast));AST_addBrother((yyvsp[-2].ast),(yyvsp[0].ast));}
#line 2030 "y.tab.c"
    break;

  case 66:
#line 264 "expr.y"
                                                            {(yyval.ast) = AST_newNode("Eq","");AST_addSon((yyval.ast),(yyvsp[-2].ast));AST_addBrother((yyvsp[-2].ast),(yyvsp[0].ast));}
#line 2036 "y.tab.c"
    break;

  case 67:
#line 265 "expr.y"
                                                            {(yyval.ast) = AST_newNode("Ne","");AST_addSon((yyval.ast),(yyvsp[-2].ast));AST_addBrother((yyvsp[-2].ast),(yyvsp[0].ast));}
#line 2042 "y.tab.c"
    break;

  case 68:
#line 266 "expr.y"
                                                            {(yyval.ast) = AST_newNode("Lt","");AST_addSon((yyval.ast),(yyvsp[-2].ast));AST_addBrother((yyvsp[-2].ast),(yyvsp[0].ast));}
#line 2048 "y.tab.c"
    break;

  case 69:
#line 267 "expr.y"
                                                            {(yyval.ast) = AST_newNode("Gt","");AST_addSon((yyval.ast),(yyvsp[-2].ast));AST_addBrother((yyvsp[-2].ast),(yyvsp[0].ast));}
#line 2054 "y.tab.c"
    break;

  case 70:
#line 268 "expr.y"
                                                            {(yyval.ast) = AST_newNode("Le","");AST_addSon((yyval.ast),(yyvsp[-2].ast));AST_addBrother((yyvsp[-2].ast),(yyvsp[0].ast));}
#line 2060 "y.tab.c"
    break;

  case 71:
#line 269 "expr.y"
                                                            {(yyval.ast) = AST_newNode("Ge","");AST_addSon((yyval.ast),(yyvsp[-2].ast));AST_addBrother((yyvsp[-2].ast),(yyvsp[0].ast));}
#line 2066 "y.tab.c"
    break;

  case 72:
#line 270 "expr.y"
                                                            {(yyval.ast) = AST_newNode("Minus","");AST_addSon((yyval.ast),(yyvsp[0].ast));}
#line 2072 "y.tab.c"
    break;

  case 73:
#line 271 "expr.y"
                                                            {(yyval.ast) = AST_newNode("Not","");AST_addSon((yyval.ast),(yyvsp[0].ast));}
#line 2078 "y.tab.c"
    break;

  case 74:
#line 272 "expr.y"
                                                            {(yyval.ast) = AST_newNode("Plus","");AST_addSon((yyval.ast),(yyvsp[0].ast));}
#line 2084 "y.tab.c"
    break;

  case 75:
#line 273 "expr.y"
                                                            {(yyval.ast) = (yyvsp[-1].ast);}
#line 2090 "y.tab.c"
    break;

  case 76:
#line 274 "expr.y"
                                                            {(yyval.ast) = AST_newNode("Id",(yyvsp[0].string));}
#line 2096 "y.tab.c"
    break;

  case 77:
#line 275 "expr.y"
                                                            {(yyval.ast) = AST_newNode("Length","");AST_addSon((yyval.ast),AST_newNode("Id",(yyvsp[-1].string)));}
#line 2102 "y.tab.c"
    break;

  case 78:
#line 276 "expr.y"
                                                            {(yyval.ast) = AST_newNode("DecLit",(yyvsp[0].string));}
#line 2108 "y.tab.c"
    break;

  case 79:
#line 277 "expr.y"
                                                            {(yyval.ast) = AST_newNode("RealLit",(yyvsp[0].string));}
#line 2114 "y.tab.c"
    break;

  case 80:
#line 278 "expr.y"
                                                            {(yyval.ast) = AST_newNode("BoolLit",(yyvsp[0].string));}
#line 2120 "y.tab.c"
    break;

  case 81:
#line 279 "expr.y"
                                                            {(yyval.ast) = (yyvsp[0].ast);}
#line 2126 "y.tab.c"
    break;

  case 82:
#line 280 "expr.y"
                                                            {(yyval.ast) = (yyvsp[0].ast);}
#line 2132 "y.tab.c"
    break;

  case 83:
#line 281 "expr.y"
                                                            {(yyval.ast) = NULL;print_tree=0;}
#line 2138 "y.tab.c"
    break;


#line 2142 "y.tab.c"

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
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

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
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

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


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
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
                  yystos[+*yyssp], yyvsp);
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
#line 284 "expr.y"




int main(int argc, char *argv[]){
	if(strcmp(argv[1],"-e1") == 0){
        /* Analise Lexical : Mostra so os erros */
		flag=0;
        yylex();
    }else if(strcmp(argv[1],"-l") == 0){
        /* Analise Lexical : Mostra os erros e os tokens */
        flag=1;
        yylex();
    }
    if(strcmp(argv[1],"-e2") == 0){
        /* Analise Sintatica : Mostra so os erros */
        flag=2;
        yyparse();
    }
    else if(strcmp(argv[1],"-t") == 0){
        /* Analise Sintatica : Mostra os erros e a arvore */
        flag=2;
        yyparse();
        if(print_tree == 1){
            AST_print(root,0);
        }
    }
    AST_free(root);
    return 0;
}
