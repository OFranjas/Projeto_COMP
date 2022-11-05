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
#include "symtab.h"
#include "Tree.h"


struct AST *root;
struct AST *aux;
int flag = 1;
int error = 0;
char *type;
int n_sons;


extern int yylex();
void yyerror (char *s);

#line 90 "y.tab.c"

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
    BOOLLIT = 283,
    EQ = 284,
    NE = 285,
    LE = 286,
    GE = 287,
    LT = 288,
    GT = 289,
    NOT = 290,
    WHILE = 291,
    IF = 292,
    ELSE = 293,
    RETURN = 294,
    ARROW = 295,
    LSHIFT = 296,
    RSHIFT = 297,
    DOTLENGTH = 298,
    PRINT = 299,
    PARSEINT = 300,
    RESERVED = 301,
    REALLIT = 302,
    STRLIT = 303,
    INTLIT = 304,
    ID = 305
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
#define BOOLLIT 283
#define EQ 284
#define NE 285
#define LE 286
#define GE 287
#define LT 288
#define GT 289
#define NOT 290
#define WHILE 291
#define IF 292
#define ELSE 293
#define RETURN 294
#define ARROW 295
#define LSHIFT 296
#define RSHIFT 297
#define DOTLENGTH 298
#define PRINT 299
#define PARSEINT 300
#define RESERVED 301
#define REALLIT 302
#define STRLIT 303
#define INTLIT 304
#define ID 305

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 28 "expr.y"

char* string;
struct AST* ast;

#line 247 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_CLASS = 3,                      /* CLASS  */
  YYSYMBOL_PUBLIC = 4,                     /* PUBLIC  */
  YYSYMBOL_STATIC = 5,                     /* STATIC  */
  YYSYMBOL_STRING = 6,                     /* STRING  */
  YYSYMBOL_VOID = 7,                       /* VOID  */
  YYSYMBOL_INT = 8,                        /* INT  */
  YYSYMBOL_DOUBLE = 9,                     /* DOUBLE  */
  YYSYMBOL_BOOL = 10,                      /* BOOL  */
  YYSYMBOL_SEMICOLON = 11,                 /* SEMICOLON  */
  YYSYMBOL_COMMA = 12,                     /* COMMA  */
  YYSYMBOL_LBRACE = 13,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 14,                    /* RBRACE  */
  YYSYMBOL_LPAR = 15,                      /* LPAR  */
  YYSYMBOL_RPAR = 16,                      /* RPAR  */
  YYSYMBOL_LSQ = 17,                       /* LSQ  */
  YYSYMBOL_RSQ = 18,                       /* RSQ  */
  YYSYMBOL_ASSIGN = 19,                    /* ASSIGN  */
  YYSYMBOL_PLUS = 20,                      /* PLUS  */
  YYSYMBOL_MINUS = 21,                     /* MINUS  */
  YYSYMBOL_STAR = 22,                      /* STAR  */
  YYSYMBOL_DIV = 23,                       /* DIV  */
  YYSYMBOL_MOD = 24,                       /* MOD  */
  YYSYMBOL_XOR = 25,                       /* XOR  */
  YYSYMBOL_OR = 26,                        /* OR  */
  YYSYMBOL_AND = 27,                       /* AND  */
  YYSYMBOL_BOOLLIT = 28,                   /* BOOLLIT  */
  YYSYMBOL_EQ = 29,                        /* EQ  */
  YYSYMBOL_NE = 30,                        /* NE  */
  YYSYMBOL_LE = 31,                        /* LE  */
  YYSYMBOL_GE = 32,                        /* GE  */
  YYSYMBOL_LT = 33,                        /* LT  */
  YYSYMBOL_GT = 34,                        /* GT  */
  YYSYMBOL_NOT = 35,                       /* NOT  */
  YYSYMBOL_WHILE = 36,                     /* WHILE  */
  YYSYMBOL_IF = 37,                        /* IF  */
  YYSYMBOL_ELSE = 38,                      /* ELSE  */
  YYSYMBOL_RETURN = 39,                    /* RETURN  */
  YYSYMBOL_ARROW = 40,                     /* ARROW  */
  YYSYMBOL_LSHIFT = 41,                    /* LSHIFT  */
  YYSYMBOL_RSHIFT = 42,                    /* RSHIFT  */
  YYSYMBOL_DOTLENGTH = 43,                 /* DOTLENGTH  */
  YYSYMBOL_PRINT = 44,                     /* PRINT  */
  YYSYMBOL_PARSEINT = 45,                  /* PARSEINT  */
  YYSYMBOL_RESERVED = 46,                  /* RESERVED  */
  YYSYMBOL_REALLIT = 47,                   /* REALLIT  */
  YYSYMBOL_STRLIT = 48,                    /* STRLIT  */
  YYSYMBOL_INTLIT = 49,                    /* INTLIT  */
  YYSYMBOL_ID = 50,                        /* ID  */
  YYSYMBOL_YYACCEPT = 51,                  /* $accept  */
  YYSYMBOL_Program = 52,                   /* Program  */
  YYSYMBOL_Xona = 53,                      /* Xona  */
  YYSYMBOL_FieldDecl = 54,                 /* FieldDecl  */
  YYSYMBOL_FieldDeclAux = 55,              /* FieldDeclAux  */
  YYSYMBOL_Type = 56,                      /* Type  */
  YYSYMBOL_FormalParams = 57,              /* FormalParams  */
  YYSYMBOL_FormalParamsAux = 58,           /* FormalParamsAux  */
  YYSYMBOL_VarDecl = 59,                   /* VarDecl  */
  YYSYMBOL_VarDeclAux = 60,                /* VarDeclAux  */
  YYSYMBOL_Statement = 61,                 /* Statement  */
  YYSYMBOL_MethodInvocation = 62,          /* MethodInvocation  */
  YYSYMBOL_MethodInvocationaux = 63,       /* MethodInvocationaux  */
  YYSYMBOL_ParseArgs = 64,                 /* ParseArgs  */
  YYSYMBOL_Assignment = 65,                /* Assignment  */
  YYSYMBOL_Expr = 66                       /* Expr  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;



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
typedef yytype_int8 yy_state_t;

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
#define YYLAST   382

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  51
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  16
/* YYNRULES -- Number of rules.  */
#define YYNRULES  62
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  125

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
       0,    66,    66,    75,    76,    77,    78,    79,    80,    81,
      82,    85,    92,    97,    99,   100,   101,   104,   111,   120,
     124,   128,   135,   139,   147,   149,   152,   154,   158,   162,
     163,   164,   168,   176,   183,   188,   191,   199,   207,   214,
     219,   224,   229,   234,   239,   244,   249,   254,   259,   264,
     269,   274,   279,   284,   289,   293,   297,   301,   304,   308,
     312,   315,   319
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "CLASS", "PUBLIC",
  "STATIC", "STRING", "VOID", "INT", "DOUBLE", "BOOL", "SEMICOLON",
  "COMMA", "LBRACE", "RBRACE", "LPAR", "RPAR", "LSQ", "RSQ", "ASSIGN",
  "PLUS", "MINUS", "STAR", "DIV", "MOD", "XOR", "OR", "AND", "BOOLLIT",
  "EQ", "NE", "LE", "GE", "LT", "GT", "NOT", "WHILE", "IF", "ELSE",
  "RETURN", "ARROW", "LSHIFT", "RSHIFT", "DOTLENGTH", "PRINT", "PARSEINT",
  "RESERVED", "REALLIT", "STRLIT", "INTLIT", "ID", "$accept", "Program",
  "Xona", "FieldDecl", "FieldDeclAux", "Type", "FormalParams",
  "FormalParamsAux", "VarDecl", "VarDeclAux", "Statement",
  "MethodInvocation", "MethodInvocationaux", "ParseArgs", "Assignment",
  "Expr", YY_NULLPTR
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

#define YYPACT_NINF (-33)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-24)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      11,   -32,    29,    26,   -33,    52,    54,    49,   -33,   -33,
     -33,   -33,   132,   132,   132,   -33,   132,    83,    55,    56,
     -33,   -33,    -9,    60,   -33,    18,   -33,   -33,   -33,    58,
      64,    65,   280,     3,    59,    35,   209,   -15,   -15,   -33,
     -33,   163,    92,    31,   101,   132,   -33,   -33,    53,   -33,
     -33,   -33,   132,   132,   132,   132,   132,   132,   132,   132,
     132,   132,   132,   132,   132,   132,   132,   132,    32,    33,
     -33,   -33,    63,   232,    67,   -33,   186,   280,     7,   -33,
      74,   -15,   -15,   -33,   -33,   -33,   333,   303,   318,     4,
       4,    -1,    -1,    -1,    -1,   348,   348,    76,   -33,    75,
      81,   132,   132,    77,    88,    45,   -33,    69,    94,   -33,
     -33,   257,   186,   -33,    73,   -33,    96,    76,   -33,    90,
     -33,     3,   -33,   -33,   -33
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,     0,     0,    14,    15,
      16,    26,     0,     0,     0,    62,     0,     0,     0,     0,
      61,    60,    58,     0,     9,     0,    10,     8,     7,     6,
       5,     4,     3,     0,     0,    58,     0,    56,    54,    55,
      24,     0,     0,     0,     0,     0,    59,     2,    20,    29,
      31,    30,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      57,    25,     0,     0,     0,    33,    35,    37,     0,    17,
       0,    38,    39,    40,    41,    42,    44,    43,    45,    48,
      49,    52,    53,    50,    51,    46,    47,    13,    18,     0,
       0,     0,     0,     0,    23,     0,    21,     0,     0,    28,
      27,     0,    35,    32,     0,    22,    20,    13,    11,     0,
      34,     0,    19,    12,    36
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -33,   -33,   -33,   -33,    -8,    -2,   -33,    -6,   -33,    10,
     -33,   -33,    12,   -33,   -33,   -12
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,    23,    24,   108,   105,    26,    79,    27,    80,
      28,    29,   103,    30,    31,    32
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      36,    37,    38,    25,    39,    41,    44,    54,    55,    56,
      45,     8,     9,    10,     1,     8,     9,    10,     3,    52,
      53,    54,    55,    56,    52,    53,    54,    55,    56,     4,
      73,    68,    76,    77,    46,    62,    63,    64,    65,     5,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,     6,   104,     7,    33,
       8,     9,    10,    11,   -23,    78,    34,    12,    48,    49,
      42,    43,    13,    14,    47,    50,    51,    69,    46,    99,
      15,    74,    97,    98,   101,   106,   109,    16,   107,   111,
     112,    17,   110,   113,    40,   116,    18,    19,    12,    20,
     114,    21,    22,    13,    14,   118,   124,    12,   121,   123,
     122,    15,    13,    14,   115,     0,    12,    75,    16,   117,
      15,    13,    14,   104,   120,     0,     0,    16,     0,    15,
      20,     0,    21,    35,     0,     0,    16,     0,     0,    20,
      72,    21,    35,     0,     0,     0,     0,    12,    20,     0,
      21,    35,    13,    14,     0,     0,     0,     0,     0,     0,
      15,     0,     0,     0,     0,     0,     0,    16,     0,     0,
       0,     0,     0,     0,    71,     0,     0,     0,     0,    20,
       0,    21,    35,    52,    53,    54,    55,    56,    57,    58,
      59,     0,    60,    61,    62,    63,    64,    65,   102,     0,
       0,     0,     0,     0,    66,    67,    52,    53,    54,    55,
      56,    57,    58,    59,     0,    60,    61,    62,    63,    64,
      65,     0,     0,     0,     0,    70,     0,    66,    67,    52,
      53,    54,    55,    56,    57,    58,    59,     0,    60,    61,
      62,    63,    64,    65,     0,     0,     0,     0,   100,     0,
      66,    67,    52,    53,    54,    55,    56,    57,    58,    59,
       0,    60,    61,    62,    63,    64,    65,     0,     0,     0,
       0,     0,     0,    66,    67,   119,     0,    52,    53,    54,
      55,    56,    57,    58,    59,     0,    60,    61,    62,    63,
      64,    65,     0,     0,     0,     0,     0,     0,    66,    67,
      52,    53,    54,    55,    56,    57,    58,    59,     0,    60,
      61,    62,    63,    64,    65,     0,     0,     0,     0,     0,
       0,    66,    67,    52,    53,    54,    55,    56,    57,     0,
      59,     0,    60,    61,    62,    63,    64,    65,    52,    53,
      54,    55,    56,    57,    66,    67,     0,    60,    61,    62,
      63,    64,    65,    52,    53,    54,    55,    56,     0,    66,
      67,     0,    60,    61,    62,    63,    64,    65,    52,    53,
      54,    55,    56,     0,    66,    67,     0,    60,    61,    62,
      63,    64,    65
};

static const yytype_int8 yycheck[] =
{
      12,    13,    14,     5,    16,    17,    15,    22,    23,    24,
      19,     8,     9,    10,     3,     8,     9,    10,    50,    20,
      21,    22,    23,    24,    20,    21,    22,    23,    24,     0,
      42,    33,    44,    45,    43,    31,    32,    33,    34,    13,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,     4,    50,     6,     5,
       8,     9,    10,    11,    11,    12,    17,    15,    50,    11,
      15,    15,    20,    21,    14,    11,    11,    18,    43,    16,
      28,    50,    50,    50,    17,    11,    11,    35,    12,   101,
     102,    39,    11,    16,    11,    50,    44,    45,    15,    47,
      12,    49,    50,    20,    21,    11,    16,    15,    12,   117,
     116,    28,    20,    21,   104,    -1,    15,    16,    35,    50,
      28,    20,    21,    50,   112,    -1,    -1,    35,    -1,    28,
      47,    -1,    49,    50,    -1,    -1,    35,    -1,    -1,    47,
      48,    49,    50,    -1,    -1,    -1,    -1,    15,    47,    -1,
      49,    50,    20,    21,    -1,    -1,    -1,    -1,    -1,    -1,
      28,    -1,    -1,    -1,    -1,    -1,    -1,    35,    -1,    -1,
      -1,    -1,    -1,    -1,    11,    -1,    -1,    -1,    -1,    47,
      -1,    49,    50,    20,    21,    22,    23,    24,    25,    26,
      27,    -1,    29,    30,    31,    32,    33,    34,    12,    -1,
      -1,    -1,    -1,    -1,    41,    42,    20,    21,    22,    23,
      24,    25,    26,    27,    -1,    29,    30,    31,    32,    33,
      34,    -1,    -1,    -1,    -1,    16,    -1,    41,    42,    20,
      21,    22,    23,    24,    25,    26,    27,    -1,    29,    30,
      31,    32,    33,    34,    -1,    -1,    -1,    -1,    16,    -1,
      41,    42,    20,    21,    22,    23,    24,    25,    26,    27,
      -1,    29,    30,    31,    32,    33,    34,    -1,    -1,    -1,
      -1,    -1,    -1,    41,    42,    18,    -1,    20,    21,    22,
      23,    24,    25,    26,    27,    -1,    29,    30,    31,    32,
      33,    34,    -1,    -1,    -1,    -1,    -1,    -1,    41,    42,
      20,    21,    22,    23,    24,    25,    26,    27,    -1,    29,
      30,    31,    32,    33,    34,    -1,    -1,    -1,    -1,    -1,
      -1,    41,    42,    20,    21,    22,    23,    24,    25,    -1,
      27,    -1,    29,    30,    31,    32,    33,    34,    20,    21,
      22,    23,    24,    25,    41,    42,    -1,    29,    30,    31,
      32,    33,    34,    20,    21,    22,    23,    24,    -1,    41,
      42,    -1,    29,    30,    31,    32,    33,    34,    20,    21,
      22,    23,    24,    -1,    41,    42,    -1,    29,    30,    31,
      32,    33,    34
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    52,    50,     0,    13,     4,     6,     8,     9,
      10,    11,    15,    20,    21,    28,    35,    39,    44,    45,
      47,    49,    50,    53,    54,    56,    57,    59,    61,    62,
      64,    65,    66,     5,    17,    50,    66,    66,    66,    66,
      11,    66,    15,    15,    15,    19,    43,    14,    50,    11,
      11,    11,    20,    21,    22,    23,    24,    25,    26,    27,
      29,    30,    31,    32,    33,    34,    41,    42,    56,    18,
      16,    11,    48,    66,    50,    16,    66,    66,    12,    58,
      60,    66,    66,    66,    66,    66,    66,    66,    66,    66,
      66,    66,    66,    66,    66,    66,    66,    50,    50,    16,
      16,    17,    12,    63,    50,    56,    11,    12,    55,    11,
      11,    66,    66,    16,    12,    60,    50,    50,    11,    18,
      63,    12,    58,    55,    16
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    51,    52,    53,    53,    53,    53,    53,    53,    53,
      53,    54,    55,    55,    56,    56,    56,    57,    57,    58,
      58,    59,    60,    60,    61,    61,    61,    61,    61,    61,
      61,    61,    62,    62,    63,    63,    64,    65,    66,    66,
      66,    66,    66,    66,    66,    66,    66,    66,    66,    66,
      66,    66,    66,    66,    66,    66,    66,    66,    66,    66,
      66,    66,    66
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     5,     1,     1,     1,     1,     1,     1,     1,
       1,     6,     3,     0,     1,     1,     1,     3,     4,     4,
       0,     4,     3,     0,     2,     3,     1,     5,     5,     2,
       2,     2,     5,     3,     3,     0,     7,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     2,     2,     2,     3,     1,     2,
       1,     1,     1
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
#line 66 "expr.y"
                                                               {
                                                                (yyval.ast) = AST_newNode("Program","");
                                                                aux = AST_newNode("ID", (yyvsp[-3].string)); 
                                                                AST_addSon((yyval.ast), aux);
                                                                AST_addSon((yyval.ast),(yyvsp[-1].ast));
                                                                root = (yyval.ast);
                                                            }
#line 1432 "y.tab.c"
    break;

  case 3:
#line 75 "expr.y"
                                                            {(yyval.ast) = (yyvsp[0].ast);}
#line 1438 "y.tab.c"
    break;

  case 4:
#line 76 "expr.y"
                                                            {(yyval.ast) = (yyvsp[0].ast);}
#line 1444 "y.tab.c"
    break;

  case 5:
#line 77 "expr.y"
                                                            {(yyval.ast) = (yyvsp[0].ast);}
#line 1450 "y.tab.c"
    break;

  case 6:
#line 78 "expr.y"
                                                            {(yyval.ast) = (yyvsp[0].ast);}
#line 1456 "y.tab.c"
    break;

  case 7: /* Xona: Statement  */
#line 79 "expr.y"
                                                            {(yyval.ast) = (yyvsp[0].ast);}
#line 1462 "y.tab.c"
    break;

  case 8: /* Xona: VarDecl  */
#line 80 "expr.y"
                                                            {(yyval.ast) = (yyvsp[0].ast);}
#line 1468 "y.tab.c"
    break;

  case 9: /* Xona: FieldDecl  */
#line 81 "expr.y"
                                                            {(yyval.ast) = (yyvsp[0].ast);}
#line 1474 "y.tab.c"
    break;

  case 10: /* Xona: FormalParams  */
#line 82 "expr.y"
                                                            {(yyval.ast) = (yyvsp[0].ast);}
#line 1480 "y.tab.c"
    break;

  case 11: /* FieldDecl: PUBLIC STATIC Type ID FieldDeclAux SEMICOLON  */
#line 85 "expr.y"
                                                            {
                                                                (yyval.ast) = AST_newNode("FieldDecl", "");
                                                                AST_addSon((yyval.ast),(yyvsp[-3].ast));
                                                                AST_addBrother((yyvsp[-3].ast), AST_newNode("ID", (yyvsp[-2].string)));
                                                            }
#line 1490 "y.tab.c"
    break;

  case 12: /* FieldDeclAux: COMMA ID FieldDeclAux  */
#line 92 "expr.y"
                                                            {
                                                                (yyval.ast) = AST_newNode("ID", (yyvsp[-1].string));
                                                                AST_addBrother((yyval.ast), (yyvsp[0].ast));
                                                            }
#line 1499 "y.tab.c"
    break;

  case 13: /* FieldDeclAux: %empty  */
#line 97 "expr.y"
                                                           {(yyval.ast) = NULL;}
#line 1505 "y.tab.c"
    break;

  case 14: /* Type: INT  */
#line 99 "expr.y"
                                                            {(yyval.ast) = AST_newNode("Int", "");}
#line 1511 "y.tab.c"
    break;

  case 15: /* Type: DOUBLE  */
#line 100 "expr.y"
                                                            {(yyval.ast) = AST_newNode("Double", "");}
#line 1517 "y.tab.c"
    break;

  case 16: /* Type: BOOL  */
#line 101 "expr.y"
                                                            {(yyval.ast) = AST_newNode("Bool", "");}
#line 1523 "y.tab.c"
    break;

  case 17: /* FormalParams: Type ID FormalParamsAux  */
#line 104 "expr.y"
                                                                           {(yyval.ast) = AST_newNode("ParamDecl","");
                                                                            AST_addSon((yyval.ast),(yyvsp[-2].ast));
                                                                            aux = AST_newNode("ID", (yyvsp[-1].string));
                                                                            AST_addSon((yyval.ast),aux);
                                                                            AST_addSon((yyval.ast),(yyvsp[0].ast));
                                                                            }
#line 1534 "y.tab.c"
    break;

  case 18: /* FormalParams: STRING LSQ RSQ ID  */
#line 111 "expr.y"
                                                                           {(yyval.ast) = AST_newNode("ParamDecl","");
                                                                           aux =  AST_newNode("ID",(yyvsp[0].string));
                                                                           AST_addSon((yyval.ast),aux);
                                                                           aux = AST_newNode("StringArray","");
                                                                           AST_addSon((yyval.ast),aux);
                                                                           }
#line 1545 "y.tab.c"
    break;

  case 19: /* FormalParamsAux: COMMA Type ID FormalParamsAux  */
#line 120 "expr.y"
                                                                          { (yyval.ast) = AST_newNode("ID",(yyvsp[-1].string));
                                                                            AST_addBrother((yyval.ast),(yyvsp[-2].ast));
                                                                            }
#line 1553 "y.tab.c"
    break;

  case 20: /* FormalParamsAux: %empty  */
#line 124 "expr.y"
                                                                          {(yyval.ast) = NULL;}
#line 1559 "y.tab.c"
    break;

  case 21: /* VarDecl: Type ID VarDeclAux SEMICOLON  */
#line 128 "expr.y"
                                                                        {
                                                                (yyval.ast) = AST_newNode("VarDecl", "");
                                                                AST_addSon((yyval.ast), (yyvsp[-3].ast));
                                                                AST_addBrother((yyvsp[-3].ast), AST_newNode("ID", (yyvsp[-2].string)));
                                                            }
#line 1569 "y.tab.c"
    break;

  case 22: /* VarDeclAux: COMMA ID VarDeclAux  */
#line 135 "expr.y"
                                                           {
                                                                (yyval.ast) = AST_newNode("ID", (yyvsp[-1].string));
                                                                AST_addBrother((yyval.ast), (yyvsp[0].ast));
                                                            }
#line 1578 "y.tab.c"
    break;

  case 23: /* VarDeclAux: %empty  */
#line 139 "expr.y"
                                                            {(yyval.ast) = NULL;}
#line 1584 "y.tab.c"
    break;

  case 24: /* Statement: RETURN SEMICOLON  */
#line 147 "expr.y"
                                                                        {(yyval.ast) = AST_newNode("Return", "");}
#line 1590 "y.tab.c"
    break;

  case 25: /* Statement: RETURN Expr SEMICOLON  */
#line 149 "expr.y"
                                                                          {(yyval.ast) = AST_newNode("Return","");
                                                                            AST_addSon((yyval.ast),(yyvsp[-1].ast));
                                                                            }
#line 1598 "y.tab.c"
    break;

  case 26: /* Statement: SEMICOLON  */
#line 152 "expr.y"
                                                                         {(yyval.ast) = NULL;}
#line 1604 "y.tab.c"
    break;

  case 27: /* Statement: PRINT LPAR Expr RPAR SEMICOLON  */
#line 154 "expr.y"
                                                                         {(yyval.ast) = AST_newNode("Print","");
                                                                            printf("Print\n");
                                                                            AST_addSon((yyval.ast),(yyvsp[-2].ast));
                                                                            }
#line 1613 "y.tab.c"
    break;

  case 28: /* Statement: PRINT LPAR STRLIT RPAR SEMICOLON  */
#line 158 "expr.y"
                                                                                       {(yyval.ast) = AST_newNode("Print","");
                                                                                    aux = AST_newNode("STRLIT", (yyvsp[-2].string));
                                                                                    AST_addSon((yyval.ast), aux);
                                                                                    }
#line 1622 "y.tab.c"
    break;

  case 29: /* Statement: MethodInvocation SEMICOLON  */
#line 162 "expr.y"
                                                                                       {(yyval.ast) = (yyvsp[-1].ast);}
#line 1628 "y.tab.c"
    break;

  case 30: /* Statement: Assignment SEMICOLON  */
#line 163 "expr.y"
                                                                                       {(yyval.ast) = (yyvsp[-1].ast);}
#line 1634 "y.tab.c"
    break;

  case 31: /* Statement: ParseArgs SEMICOLON  */
#line 164 "expr.y"
                                                                                       {(yyval.ast) = (yyvsp[-1].ast);}
#line 1640 "y.tab.c"
    break;

  case 32: /* MethodInvocation: ID LPAR Expr MethodInvocationaux RPAR  */
#line 168 "expr.y"
                                                                        {  
                                                                            (yyval.ast) = AST_newNode("Call", "");
                                                                            aux = AST_newNode("ID", (yyvsp[-4].string));
                                                                            AST_addSon((yyval.ast), aux);
                                                                            AST_addBrother(aux, (yyvsp[-2].ast));
                                                                            AST_addBrother((yyvsp[-2].ast), (yyvsp[-1].ast));
                                                                        }
#line 1652 "y.tab.c"
    break;

  case 33: /* MethodInvocation: ID LPAR RPAR  */
#line 176 "expr.y"
                                                                        { 
                                                                            (yyval.ast) = AST_newNode("Call", "");
                                                                            aux = AST_newNode("ID", (yyvsp[-2].string));
                                                                            AST_addSon((yyval.ast), aux);
                                                                        }
#line 1662 "y.tab.c"
    break;

  case 34: /* MethodInvocationaux: COMMA Expr MethodInvocationaux  */
#line 183 "expr.y"
                                                                        {
                                                                            (yyval.ast) = (yyvsp[-1].ast);
                                                                            AST_addBrother((yyval.ast), (yyvsp[0].ast));
                                                                        }
#line 1671 "y.tab.c"
    break;

  case 35: /* MethodInvocationaux: %empty  */
#line 188 "expr.y"
                                                                        {(yyval.ast) = NULL;}
#line 1677 "y.tab.c"
    break;

  case 36: /* ParseArgs: PARSEINT LPAR ID LSQ Expr RSQ RPAR  */
#line 191 "expr.y"
                                                           {
                                                                (yyval.ast) = AST_newNode("ParseArgs","");
                                                                aux = AST_newNode("ID", (yyvsp[-4].string));
                                                                AST_addSon((yyval.ast), aux);
                                                                AST_addBrother(aux, (yyvsp[-2].ast));
                                                            }
#line 1688 "y.tab.c"
    break;

  case 37: /* Assignment: ID ASSIGN Expr  */
#line 199 "expr.y"
                                                            {
                                                                (yyval.ast) = AST_newNode("Assign", "");
                                                                aux = AST_newNode("ID", (yyvsp[-2].string));
                                                                AST_addSon((yyval.ast),(yyvsp[0].ast));
                                                                AST_addBrother((yyvsp[0].ast),aux);
                                                            }
#line 1699 "y.tab.c"
    break;

  case 38: /* Expr: Expr PLUS Expr  */
#line 207 "expr.y"
                                                                                    {	
                                                                aux = AST_newNode("ADD","");
                                                                (yyval.ast) = aux;
																AST_addSon((yyval.ast),(yyvsp[-2].ast));
																AST_addBrother((yyvsp[-2].ast),(yyvsp[0].ast));
                                                                
                                                                                    }
#line 1711 "y.tab.c"
    break;

  case 39: /* Expr: Expr MINUS Expr  */
#line 214 "expr.y"
                                                                                    {
                                                                (yyval.ast) = AST_newNode("SUB","");
																AST_addSon((yyval.ast),(yyvsp[-2].ast));
																AST_addBrother((yyvsp[-2].ast),(yyvsp[0].ast));
                                                                                    }
#line 1721 "y.tab.c"
    break;

  case 40: /* Expr: Expr STAR Expr  */
#line 219 "expr.y"
                                                                                    {
                                                                (yyval.ast) = AST_newNode("MUL","");
																AST_addSon((yyval.ast),(yyvsp[-2].ast));
																AST_addBrother((yyvsp[-2].ast),(yyvsp[0].ast));
                                                                                    }
#line 1731 "y.tab.c"
    break;

  case 41: /* Expr: Expr DIV Expr  */
#line 224 "expr.y"
                                                                                    {
                                                                (yyval.ast) = AST_newNode("DIV","");
																AST_addSon((yyval.ast),(yyvsp[-2].ast));
																AST_addBrother((yyvsp[-2].ast),(yyvsp[0].ast));
                                                                                    }
#line 1741 "y.tab.c"
    break;

  case 42: /* Expr: Expr MOD Expr  */
#line 229 "expr.y"
                                                                                    {
                                                                (yyval.ast) = AST_newNode("MOD","");
																AST_addSon((yyval.ast),(yyvsp[-2].ast));
																AST_addBrother((yyvsp[-2].ast),(yyvsp[0].ast));
                                                                                    }
#line 1751 "y.tab.c"
    break;

  case 43: /* Expr: Expr OR Expr  */
#line 234 "expr.y"
                                                                                    {
                                                                (yyval.ast) = AST_newNode("OR","");
																AST_addSon((yyval.ast),(yyvsp[-2].ast));
																AST_addBrother((yyvsp[-2].ast),(yyvsp[0].ast));
                                                                                    }
#line 1761 "y.tab.c"
    break;

  case 44: /* Expr: Expr XOR Expr  */
#line 239 "expr.y"
                                                                                    {
                                                                (yyval.ast) = AST_newNode("XOR","");
																AST_addSon((yyval.ast),(yyvsp[-2].ast));
																AST_addBrother((yyvsp[-2].ast),(yyvsp[0].ast));
                                                                                    }
#line 1771 "y.tab.c"
    break;

  case 45: /* Expr: Expr AND Expr  */
#line 244 "expr.y"
                                                                                    {
                                                                (yyval.ast) = AST_newNode("AND","");
																AST_addSon((yyval.ast),(yyvsp[-2].ast));
																AST_addBrother((yyvsp[-2].ast),(yyvsp[0].ast));
                                                                                    }
#line 1781 "y.tab.c"
    break;

  case 46: /* Expr: Expr LSHIFT Expr  */
#line 249 "expr.y"
                                                                                    {
                                                                (yyval.ast) = AST_newNode("LSHIFT","");
																AST_addSon((yyval.ast),(yyvsp[-2].ast));
																AST_addBrother((yyvsp[-2].ast),(yyvsp[0].ast));
                                                                                    }
#line 1791 "y.tab.c"
    break;

  case 47: /* Expr: Expr RSHIFT Expr  */
#line 254 "expr.y"
                                                                                    {
                                                                (yyval.ast) = AST_newNode("RSHIFT","");
																AST_addSon((yyval.ast),(yyvsp[-2].ast));
																AST_addBrother((yyvsp[-2].ast),(yyvsp[0].ast));
                                                                                    }
#line 1801 "y.tab.c"
    break;

  case 48: /* Expr: Expr EQ Expr  */
#line 259 "expr.y"
                                                                                    {
                                                                (yyval.ast) = AST_newNode("EQ","");
																AST_addSon((yyval.ast),(yyvsp[-2].ast));
																AST_addBrother((yyvsp[-2].ast),(yyvsp[0].ast));
                                                                                    }
#line 1811 "y.tab.c"
    break;

  case 49: /* Expr: Expr NE Expr  */
#line 264 "expr.y"
                                                                                    {
                                                                (yyval.ast) = AST_newNode("NE","");
																AST_addSon((yyval.ast),(yyvsp[-2].ast));
																AST_addBrother((yyvsp[-2].ast),(yyvsp[0].ast));
                                                                                    }
#line 1821 "y.tab.c"
    break;

  case 50: /* Expr: Expr LT Expr  */
#line 269 "expr.y"
                                                                                    {
                                                                (yyval.ast) = AST_newNode("LT","");
																AST_addSon((yyval.ast),(yyvsp[-2].ast));
																AST_addBrother((yyvsp[-2].ast),(yyvsp[0].ast));
                                                                                    }
#line 1831 "y.tab.c"
    break;

  case 51: /* Expr: Expr GT Expr  */
#line 274 "expr.y"
                                                                                    {
                                                                (yyval.ast) = AST_newNode("GT","");
																AST_addSon((yyval.ast),(yyvsp[-2].ast));
																AST_addBrother((yyvsp[-2].ast),(yyvsp[0].ast));
                                                                                    }
#line 1841 "y.tab.c"
    break;

  case 52: /* Expr: Expr LE Expr  */
#line 279 "expr.y"
                                                                                    {
                                                                (yyval.ast) = AST_newNode("LE","");
																AST_addSon((yyval.ast),(yyvsp[-2].ast));
																AST_addBrother((yyvsp[-2].ast),(yyvsp[0].ast));
                                                                                    }
#line 1851 "y.tab.c"
    break;

  case 53: /* Expr: Expr GE Expr  */
#line 284 "expr.y"
                                                                                    {
                                                                (yyval.ast) = AST_newNode("GE","");
																AST_addSon((yyval.ast),(yyvsp[-2].ast));
																AST_addBrother((yyvsp[-2].ast),(yyvsp[0].ast));
                                                                                    }
#line 1861 "y.tab.c"
    break;

  case 54: /* Expr: MINUS Expr  */
#line 289 "expr.y"
                                                                                    {
        														(yyval.ast) = AST_newNode("MINUS","");
																AST_addSon((yyval.ast),(yyvsp[0].ast));
                                                                                    }
#line 1870 "y.tab.c"
    break;

  case 55: /* Expr: NOT Expr  */
#line 293 "expr.y"
                                                                                    {
                                                                (yyval.ast) = AST_newNode("NOT","");
                                                                AST_addSon((yyval.ast),(yyvsp[0].ast));
                                                                                    }
#line 1879 "y.tab.c"
    break;

  case 56: /* Expr: PLUS Expr  */
#line 297 "expr.y"
                                                                                    {
                                                                (yyval.ast) = AST_newNode("PLUS","");
                                                                AST_addSon((yyval.ast),(yyvsp[0].ast));
                                                                                    }
#line 1888 "y.tab.c"
    break;

  case 57: /* Expr: LPAR Expr RPAR  */
#line 301 "expr.y"
                                                                                    {
                                                                (yyval.ast) = (yyvsp[-1].ast);
                                                                                    }
#line 1896 "y.tab.c"
    break;

  case 58: /* Expr: ID  */
#line 304 "expr.y"
                                                                                    {
                                                                (yyval.ast) = AST_newNode("ID",(yyvsp[0].string));

                                                                                    }
#line 1905 "y.tab.c"
    break;

  case 59: /* Expr: ID DOTLENGTH  */
#line 308 "expr.y"
                                                                                    {
                                                                (yyval.ast) = AST_newNode("ID",(yyvsp[-1].string));
                                                                                    }
#line 1913 "y.tab.c"
    break;

  case 60: /* Expr: INTLIT  */
#line 312 "expr.y"
                                                                                    {
                                                                (yyval.ast) = AST_newNode("DecLit",(yyvsp[0].string));
                                                                                    }
#line 1921 "y.tab.c"
    break;

  case 61: /* Expr: REALLIT  */
#line 315 "expr.y"
                                                                                    {
                                                                (yyval.ast) = AST_newNode("REALLIT",(yyvsp[0].string));
                                                                                    }
#line 1929 "y.tab.c"
    break;

  case 62: /* Expr: BOOLLIT  */
#line 319 "expr.y"
                                                                                    {
                                                                (yyval.ast) = AST_newNode("BOOLLIT","");
                                                                                    }
#line 1937 "y.tab.c"
    break;


#line 1941 "y.tab.c"

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
#line 362 "expr.y"

#line 324 "expr.y"

int main(int argc, char *argv[]){
    if(argc > 1){
		if(strcmp(argv[1],"-e1") == 0){
            /* Analise Lexical : Mostra so os erros */
			flag=0;
            yylex();
		}else if(strcmp(argv[1],"-l") == 0){
            /* Analise Lexical : Mostra tudo */
            flag=1;
            yylex();
        }else if(strcmp(argv[1],"-e2") == 0){
            /* Analise Lexical & Sintatica : Mostra so os erros */
            flag = 2;
            yyparse();  
	}else{
            /* Analise Lexical & Sintatica : Mostra tudo */
            flag = 2;
            yyparse();
            AST_print(root,0);
        }
    }else{
            /* Analise Lexical & Sintatica : Mostra tudo */
            flag = 2;
            yyparse();
            AST_print(root,0);
        }       
    return 0;
}
