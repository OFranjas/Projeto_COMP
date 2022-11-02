/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 8 "./jucompiler.y"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "symtab.h"
#include "Tree.h"


struct AST root = NULL;
int flag = 1;int error = 0;

#line 83 "y.tab.c"

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

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    CLASS = 258,                   /* CLASS  */
    PUBLIC = 259,                  /* PUBLIC  */
    STATIC = 260,                  /* STATIC  */
    STRING = 261,                  /* STRING  */
    VOID = 262,                    /* VOID  */
    INT = 263,                     /* INT  */
    DOUBLE = 264,                  /* DOUBLE  */
    BOOL = 265,                    /* BOOL  */
    SEMICOLON = 266,               /* SEMICOLON  */
    COMMA = 267,                   /* COMMA  */
    LBRACE = 268,                  /* LBRACE  */
    RBRACE = 269,                  /* RBRACE  */
    LPAR = 270,                    /* LPAR  */
    RPAR = 271,                    /* RPAR  */
    LSQ = 272,                     /* LSQ  */
    RSQ = 273,                     /* RSQ  */
    ASSIGN = 274,                  /* ASSIGN  */
    PLUS = 275,                    /* PLUS  */
    MINUS = 276,                   /* MINUS  */
    STAR = 277,                    /* STAR  */
    DIV = 278,                     /* DIV  */
    MOD = 279,                     /* MOD  */
    XOR = 280,                     /* XOR  */
    OR = 281,                      /* OR  */
    AND = 282,                     /* AND  */
    BOOLLIT = 283,                 /* BOOLLIT  */
    EQ = 284,                      /* EQ  */
    NE = 285,                      /* NE  */
    LE = 286,                      /* LE  */
    GE = 287,                      /* GE  */
    LT = 288,                      /* LT  */
    GT = 289,                      /* GT  */
    NOT = 290,                     /* NOT  */
    WHILE = 291,                   /* WHILE  */
    IF = 292,                      /* IF  */
    ELSE = 293,                    /* ELSE  */
    RETURN = 294,                  /* RETURN  */
    ARROW = 295,                   /* ARROW  */
    LSHIFT = 296,                  /* LSHIFT  */
    RSHIFT = 297,                  /* RSHIFT  */
    DOTLENGTH = 298,               /* DOTLENGTH  */
    PRINT = 299,                   /* PRINT  */
    PARSEINT = 300,                /* PARSEINT  */
    REALLIT = 301,                 /* REALLIT  */
    STRLIT = 302,                  /* STRLIT  */
    INTLIT = 303,                  /* INTLIT  */
    ID = 304,                      /* ID  */
    RESERVED = 305                 /* RESERVED  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
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
#define REALLIT 301
#define STRLIT 302
#define INTLIT 303
#define ID 304
#define RESERVED 305

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 20 "./jucompiler.y"

char* string;
struct AST* ast;

#line 241 "y.tab.c"

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
  YYSYMBOL_REALLIT = 46,                   /* REALLIT  */
  YYSYMBOL_STRLIT = 47,                    /* STRLIT  */
  YYSYMBOL_INTLIT = 48,                    /* INTLIT  */
  YYSYMBOL_ID = 49,                        /* ID  */
  YYSYMBOL_RESERVED = 50,                  /* RESERVED  */
  YYSYMBOL_YYACCEPT = 51,                  /* $accept  */
  YYSYMBOL_Program = 52,                   /* Program  */
  YYSYMBOL_ClassBody = 53,                 /* ClassBody  */
  YYSYMBOL_MethodDecl = 54,                /* MethodDecl  */
  YYSYMBOL_FieldDecl = 55,                 /* FieldDecl  */
  YYSYMBOL_FieldDeclCommaAux = 56,         /* FieldDeclCommaAux  */
  YYSYMBOL_Type = 57,                      /* Type  */
  YYSYMBOL_MethodHeader = 58,              /* MethodHeader  */
  YYSYMBOL_FormalParams = 59,              /* FormalParams  */
  YYSYMBOL_FormalParamsAux = 60,           /* FormalParamsAux  */
  YYSYMBOL_MethodBody = 61,                /* MethodBody  */
  YYSYMBOL_MethodBodyAux = 62,             /* MethodBodyAux  */
  YYSYMBOL_VarDecl = 63,                   /* VarDecl  */
  YYSYMBOL_VarDeclAux = 64,                /* VarDeclAux  */
  YYSYMBOL_Statement = 65,                 /* Statement  */
  YYSYMBOL_MethodInvocation = 66,          /* MethodInvocation  */
  YYSYMBOL_MethodInvocationAux = 67,       /* MethodInvocationAux  */
  YYSYMBOL_MethodBodyAux2 = 68,            /* MethodBodyAux2  */
  YYSYMBOL_Assignment = 69,                /* Assignment  */
  YYSYMBOL_ParseArgs = 70,                 /* ParseArgs  */
  YYSYMBOL_Expr = 71                       /* Expr  */
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

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
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
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
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

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

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
#define YYLAST   460

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  51
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  21
/* YYNRULES -- Number of rules.  */
#define YYNRULES  80
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  166

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   305


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

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
static const yytype_uint8 yyrline[] =
{
       0,    58,    58,    65,    66,    67,    68,    69,    70,    73,
      76,    79,    80,    83,    84,    85,    88,    89,    90,    91,
      95,    96,    99,   100,   103,   106,   107,   108,   109,   112,
     115,   116,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   134,   135,   138,   139,   142,
     143,   146,   149,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

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
  "REALLIT", "STRLIT", "INTLIT", "ID", "RESERVED", "$accept", "Program",
  "ClassBody", "MethodDecl", "FieldDecl", "FieldDeclCommaAux", "Type",
  "MethodHeader", "FormalParams", "FormalParamsAux", "MethodBody",
  "MethodBodyAux", "VarDecl", "VarDeclAux", "Statement",
  "MethodInvocation", "MethodInvocationAux", "MethodBodyAux2",
  "Assignment", "ParseArgs", "Expr", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-45)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       0,   -44,    13,     9,   -45,    24,    19,    24,    39,    24,
      24,   148,   -45,   -45,   -45,   -45,    16,   -45,   -45,   -45,
      35,    45,    71,    27,    46,   -45,   181,    38,   186,    78,
     -45,     1,    81,    95,    77,    99,   101,    17,    64,   110,
      46,    46,   116,   117,   118,   114,   -45,    83,   125,   121,
     -45,   130,   -45,   -45,   136,   165,   165,   -45,   165,   165,
     165,   -45,   165,   -45,   -45,    -9,   -45,   -45,   -45,   195,
     124,   102,   133,   165,   150,   -45,   -45,   -45,   -45,   -45,
     -45,   142,   171,   -45,   -45,   -45,   -45,   241,   264,   287,
      84,    84,   -45,   -45,   -45,   165,   165,   165,   165,   165,
     165,   165,   165,   165,   165,   165,   165,   165,   165,   165,
     165,   168,   310,   182,   -45,   172,   218,   358,   149,   190,
     154,   111,   -45,    98,    98,   -45,    84,    84,   -45,   -45,
     -45,   411,   381,   396,   143,   143,    40,    40,    40,    40,
     426,   426,   193,   194,   165,   -45,   165,   -45,   150,   -45,
     -45,   158,   -45,   170,   -45,   -45,   335,   218,   -45,   171,
      98,   196,   -45,   -45,   -45,   -45
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,     0,     8,     0,     4,
       6,     0,     7,     2,     3,     5,     0,    14,    15,    13,
       0,     0,     0,     0,     0,     9,     0,     0,     0,     0,
      42,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      28,    26,     0,     0,     0,     0,    19,     0,     0,    12,
      17,     0,    10,    32,     0,     0,     0,    38,     0,     0,
       0,    80,     0,    79,    78,    76,    73,    74,    75,     0,
       0,     0,     0,     0,     0,    24,    27,    25,    39,    40,
      41,     0,     0,    18,    11,    16,    33,     0,     0,     0,
      71,    69,    70,    77,    37,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    46,     0,    47,    51,     0,     0,
       0,     0,    20,     0,     0,    72,    53,    54,    55,    56,
      57,    59,    58,    60,    63,    64,    67,    68,    65,    66,
      61,    62,     0,     0,     0,    45,     0,    48,    31,    29,
      21,     0,    36,    34,    44,    43,     0,    50,    30,    23,
       0,     0,    49,    22,    35,    52
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -45,   -45,    42,   -45,   -45,   160,    -3,   -45,   203,    73,
     -45,     7,   -45,    75,   -30,   -24,   -45,    76,   -22,   -20,
     -29
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     8,     9,    10,    29,    38,    21,    48,   122,
      25,    39,    40,   119,    41,    66,   115,   147,    67,    68,
      69
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      42,    54,    43,     1,    44,     3,    72,    42,    20,    43,
      73,    44,    30,     4,    31,    53,    42,    42,    43,    43,
      44,    44,     5,    47,    11,    47,    87,    88,     6,    89,
      90,    91,    72,    92,    93,     7,    73,    32,    33,    27,
      34,   112,    28,   116,   117,    35,    36,    76,    77,    12,
      37,    14,    15,    13,    17,    18,    19,    30,    24,    31,
      95,    96,    97,    98,    99,    22,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,    32,    33,    23,    34,    26,    49,    57,    52,
      35,    36,    58,   152,   153,    37,    55,    59,    60,    42,
      42,    43,    43,    44,    44,    61,    97,    98,    99,    30,
      56,    31,    62,    74,    70,   156,    71,   157,   151,    17,
      18,    19,    36,    63,    75,    64,    65,    78,    79,    80,
     164,    81,    82,    27,    32,    33,    42,    34,    43,    58,
      44,    83,    35,    36,    59,    60,    85,    37,    58,   114,
      86,   113,    61,    59,    60,    16,    17,    18,    19,    62,
     120,    61,   118,    95,    96,    97,    98,    99,    62,    36,
      63,   111,    64,    65,   105,   106,   107,   108,    36,    63,
      58,    64,    65,   121,   142,    59,    60,    45,   145,    17,
      18,    19,    45,    61,    17,    18,    19,    46,   148,   144,
      62,   149,    50,   150,   154,   155,    94,   159,   160,    84,
      36,    63,   165,    64,    65,    95,    96,    97,    98,    99,
     100,   101,   102,   158,   103,   104,   105,   106,   107,   108,
     146,    51,   163,   162,     0,     0,   109,   110,    95,    96,
      97,    98,    99,   100,   101,   102,     0,   103,   104,   105,
     106,   107,   108,     0,     0,     0,     0,   123,     0,   109,
     110,    95,    96,    97,    98,    99,   100,   101,   102,     0,
     103,   104,   105,   106,   107,   108,     0,     0,     0,     0,
     124,     0,   109,   110,    95,    96,    97,    98,    99,   100,
     101,   102,     0,   103,   104,   105,   106,   107,   108,     0,
       0,     0,     0,   125,     0,   109,   110,    95,    96,    97,
      98,    99,   100,   101,   102,     0,   103,   104,   105,   106,
     107,   108,     0,     0,     0,     0,   143,     0,   109,   110,
      95,    96,    97,    98,    99,   100,   101,   102,     0,   103,
     104,   105,   106,   107,   108,     0,     0,     0,     0,     0,
       0,   109,   110,   161,     0,    95,    96,    97,    98,    99,
     100,   101,   102,     0,   103,   104,   105,   106,   107,   108,
       0,     0,     0,     0,     0,     0,   109,   110,    95,    96,
      97,    98,    99,   100,   101,   102,     0,   103,   104,   105,
     106,   107,   108,     0,     0,     0,     0,     0,     0,   109,
     110,    95,    96,    97,    98,    99,   100,     0,   102,     0,
     103,   104,   105,   106,   107,   108,    95,    96,    97,    98,
      99,   100,   109,   110,     0,   103,   104,   105,   106,   107,
     108,    95,    96,    97,    98,    99,     0,   109,   110,     0,
     103,   104,   105,   106,   107,   108,    95,    96,    97,    98,
      99,     0,   109,   110,     0,   103,   104,   105,   106,   107,
     108
};

static const yytype_int16 yycheck[] =
{
      24,    31,    24,     3,    24,    49,    15,    31,    11,    31,
      19,    31,    11,     0,    13,    14,    40,    41,    40,    41,
      40,    41,    13,    26,     5,    28,    55,    56,     4,    58,
      59,    60,    15,    62,    43,    11,    19,    36,    37,    12,
      39,    70,    15,    72,    73,    44,    45,    40,    41,     7,
      49,     9,    10,    14,     8,     9,    10,    11,    13,    13,
      20,    21,    22,    23,    24,    49,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,    36,    37,    49,    39,    15,    49,    11,    11,
      44,    45,    15,   123,   124,    49,    15,    20,    21,   123,
     124,   123,   124,   123,   124,    28,    22,    23,    24,    11,
      15,    13,    35,    49,    15,   144,    15,   146,   121,     8,
       9,    10,    45,    46,    14,    48,    49,    11,    11,    11,
     160,    17,    49,    12,    36,    37,   160,    39,   160,    15,
     160,    16,    44,    45,    20,    21,    16,    49,    15,    16,
      14,    49,    28,    20,    21,     7,     8,     9,    10,    35,
      18,    28,    12,    20,    21,    22,    23,    24,    35,    45,
      46,    47,    48,    49,    31,    32,    33,    34,    45,    46,
      15,    48,    49,    12,    16,    20,    21,     6,    16,     8,
       9,    10,     6,    28,     8,     9,    10,    16,    49,    17,
      35,    11,    16,    49,    11,    11,    11,    49,    38,    49,
      45,    46,    16,    48,    49,    20,    21,    22,    23,    24,
      25,    26,    27,   148,    29,    30,    31,    32,    33,    34,
      12,    28,   159,   157,    -1,    -1,    41,    42,    20,    21,
      22,    23,    24,    25,    26,    27,    -1,    29,    30,    31,
      32,    33,    34,    -1,    -1,    -1,    -1,    16,    -1,    41,
      42,    20,    21,    22,    23,    24,    25,    26,    27,    -1,
      29,    30,    31,    32,    33,    34,    -1,    -1,    -1,    -1,
      16,    -1,    41,    42,    20,    21,    22,    23,    24,    25,
      26,    27,    -1,    29,    30,    31,    32,    33,    34,    -1,
      -1,    -1,    -1,    16,    -1,    41,    42,    20,    21,    22,
      23,    24,    25,    26,    27,    -1,    29,    30,    31,    32,
      33,    34,    -1,    -1,    -1,    -1,    16,    -1,    41,    42,
      20,    21,    22,    23,    24,    25,    26,    27,    -1,    29,
      30,    31,    32,    33,    34,    -1,    -1,    -1,    -1,    -1,
      -1,    41,    42,    18,    -1,    20,    21,    22,    23,    24,
      25,    26,    27,    -1,    29,    30,    31,    32,    33,    34,
      -1,    -1,    -1,    -1,    -1,    -1,    41,    42,    20,    21,
      22,    23,    24,    25,    26,    27,    -1,    29,    30,    31,
      32,    33,    34,    -1,    -1,    -1,    -1,    -1,    -1,    41,
      42,    20,    21,    22,    23,    24,    25,    -1,    27,    -1,
      29,    30,    31,    32,    33,    34,    20,    21,    22,    23,
      24,    25,    41,    42,    -1,    29,    30,    31,    32,    33,
      34,    20,    21,    22,    23,    24,    -1,    41,    42,    -1,
      29,    30,    31,    32,    33,    34,    20,    21,    22,    23,
      24,    -1,    41,    42,    -1,    29,    30,    31,    32,    33,
      34
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    52,    49,     0,    13,     4,    11,    53,    54,
      55,     5,    53,    14,    53,    53,     7,     8,     9,    10,
      57,    58,    49,    49,    13,    61,    15,    12,    15,    56,
      11,    13,    36,    37,    39,    44,    45,    49,    57,    62,
      63,    65,    66,    69,    70,     6,    16,    57,    59,    49,
      16,    59,    11,    14,    65,    15,    15,    11,    15,    20,
      21,    28,    35,    46,    48,    49,    66,    69,    70,    71,
      15,    15,    15,    19,    49,    14,    62,    62,    11,    11,
      11,    17,    49,    16,    56,    16,    14,    71,    71,    71,
      71,    71,    71,    43,    11,    20,    21,    22,    23,    24,
      25,    26,    27,    29,    30,    31,    32,    33,    34,    41,
      42,    47,    71,    49,    16,    67,    71,    71,    12,    64,
      18,    12,    60,    16,    16,    16,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    16,    16,    17,    16,    12,    68,    49,    11,
      49,    57,    65,    65,    11,    11,    71,    71,    64,    49,
      38,    18,    68,    60,    65,    16
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    51,    52,    53,    53,    53,    53,    53,    53,    54,
      55,    56,    56,    57,    57,    57,    58,    58,    58,    58,
      59,    59,    60,    60,    61,    62,    62,    62,    62,    63,
      64,    64,    65,    65,    65,    65,    65,    65,    65,    65,
      65,    65,    65,    65,    65,    66,    66,    67,    67,    68,
      68,    69,    70,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      71
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     5,     2,     1,     2,     1,     2,     1,     4,
       6,     3,     2,     1,     1,     1,     5,     4,     5,     4,
       3,     4,     4,     3,     3,     2,     1,     2,     1,     4,
       3,     2,     2,     3,     5,     7,     5,     3,     2,     2,
       2,     2,     1,     5,     5,     4,     3,     1,     2,     3,
       2,     3,     7,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       2,     2,     3,     1,     1,     1,     1,     2,     1,     1,
       1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
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
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

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
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
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
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  case 2: /* Program: CLASS ID LBRACE ClassBody RBRACE  */
#line 58 "./jucompiler.y"
                                                                                    {																
																                        root = AST_newNode("Program","");
                                                                                        AST_addSon(root,(yyvsp[-3].string));
																                        (yyval.ast) = root;
                                                                                     }
#line 1464 "y.tab.c"
    break;

  case 3: /* ClassBody: MethodDecl ClassBody  */
#line 65 "./jucompiler.y"
                                                                                    {;}
#line 1470 "y.tab.c"
    break;

  case 4: /* ClassBody: MethodDecl  */
#line 66 "./jucompiler.y"
                                                                                    {;}
#line 1476 "y.tab.c"
    break;

  case 5: /* ClassBody: FieldDecl ClassBody  */
#line 67 "./jucompiler.y"
                                                                                    {;}
#line 1482 "y.tab.c"
    break;

  case 6: /* ClassBody: FieldDecl  */
#line 68 "./jucompiler.y"
                                                                                    {;}
#line 1488 "y.tab.c"
    break;

  case 7: /* ClassBody: SEMICOLON ClassBody  */
#line 69 "./jucompiler.y"
                                                                                    {;}
#line 1494 "y.tab.c"
    break;

  case 8: /* ClassBody: SEMICOLON  */
#line 70 "./jucompiler.y"
                                                                                    {;}
#line 1500 "y.tab.c"
    break;

  case 9: /* MethodDecl: PUBLIC STATIC MethodHeader MethodBody  */
#line 73 "./jucompiler.y"
                                                                                    {;}
#line 1506 "y.tab.c"
    break;

  case 10: /* FieldDecl: PUBLIC STATIC Type ID FieldDeclCommaAux SEMICOLON  */
#line 76 "./jucompiler.y"
                                                                                    {;}
#line 1512 "y.tab.c"
    break;

  case 11: /* FieldDeclCommaAux: COMMA ID FieldDeclCommaAux  */
#line 79 "./jucompiler.y"
                                                                                    {;}
#line 1518 "y.tab.c"
    break;

  case 12: /* FieldDeclCommaAux: COMMA ID  */
#line 80 "./jucompiler.y"
                                                                                    {;}
#line 1524 "y.tab.c"
    break;

  case 13: /* Type: BOOL  */
#line 83 "./jucompiler.y"
                                                                                    {;}
#line 1530 "y.tab.c"
    break;

  case 14: /* Type: INT  */
#line 84 "./jucompiler.y"
                                                                                    {;}
#line 1536 "y.tab.c"
    break;

  case 15: /* Type: DOUBLE  */
#line 85 "./jucompiler.y"
                                                                                    {;}
#line 1542 "y.tab.c"
    break;

  case 16: /* MethodHeader: Type ID LPAR FormalParams RPAR  */
#line 88 "./jucompiler.y"
                                                                                    {;}
#line 1548 "y.tab.c"
    break;

  case 17: /* MethodHeader: Type ID LPAR RPAR  */
#line 89 "./jucompiler.y"
                                                                                    {;}
#line 1554 "y.tab.c"
    break;

  case 18: /* MethodHeader: VOID ID LPAR FormalParams RPAR  */
#line 90 "./jucompiler.y"
                                                                                    {;}
#line 1560 "y.tab.c"
    break;

  case 19: /* MethodHeader: VOID ID LPAR RPAR  */
#line 91 "./jucompiler.y"
                                                                                    {;}
#line 1566 "y.tab.c"
    break;

  case 20: /* FormalParams: Type ID FormalParamsAux  */
#line 95 "./jucompiler.y"
                                                                                    {;}
#line 1572 "y.tab.c"
    break;

  case 21: /* FormalParams: STRING LSQ RSQ ID  */
#line 96 "./jucompiler.y"
                                                                                    {;}
#line 1578 "y.tab.c"
    break;

  case 22: /* FormalParamsAux: COMMA Type ID FormalParamsAux  */
#line 99 "./jucompiler.y"
                                                                                    {;}
#line 1584 "y.tab.c"
    break;

  case 23: /* FormalParamsAux: COMMA Type ID  */
#line 100 "./jucompiler.y"
                                                                                    {;}
#line 1590 "y.tab.c"
    break;

  case 24: /* MethodBody: LBRACE MethodBodyAux RBRACE  */
#line 103 "./jucompiler.y"
                                                                                    {;}
#line 1596 "y.tab.c"
    break;

  case 25: /* MethodBodyAux: Statement MethodBodyAux  */
#line 106 "./jucompiler.y"
                                                                                    {;}
#line 1602 "y.tab.c"
    break;

  case 26: /* MethodBodyAux: Statement  */
#line 107 "./jucompiler.y"
                                                                                    {;}
#line 1608 "y.tab.c"
    break;

  case 27: /* MethodBodyAux: VarDecl MethodBodyAux  */
#line 108 "./jucompiler.y"
                                                                                    {;}
#line 1614 "y.tab.c"
    break;

  case 28: /* MethodBodyAux: VarDecl  */
#line 109 "./jucompiler.y"
                                                                                    {;}
#line 1620 "y.tab.c"
    break;

  case 29: /* VarDecl: Type ID VarDeclAux SEMICOLON  */
#line 112 "./jucompiler.y"
                                                                                    {;}
#line 1626 "y.tab.c"
    break;

  case 30: /* VarDeclAux: COMMA ID VarDeclAux  */
#line 115 "./jucompiler.y"
                                                                                    {;}
#line 1632 "y.tab.c"
    break;

  case 31: /* VarDeclAux: COMMA ID  */
#line 116 "./jucompiler.y"
                                                                                    {;}
#line 1638 "y.tab.c"
    break;

  case 32: /* Statement: LBRACE RBRACE  */
#line 120 "./jucompiler.y"
                                                                                    {;}
#line 1644 "y.tab.c"
    break;

  case 33: /* Statement: LBRACE Statement RBRACE  */
#line 121 "./jucompiler.y"
                                                                                    {;}
#line 1650 "y.tab.c"
    break;

  case 34: /* Statement: IF LPAR Expr RPAR Statement  */
#line 122 "./jucompiler.y"
                                                                                    {;}
#line 1656 "y.tab.c"
    break;

  case 35: /* Statement: IF LPAR Expr RPAR Statement ELSE Statement  */
#line 123 "./jucompiler.y"
                                                                                    {;}
#line 1662 "y.tab.c"
    break;

  case 36: /* Statement: WHILE LPAR Expr RPAR Statement  */
#line 124 "./jucompiler.y"
                                                                                    {;}
#line 1668 "y.tab.c"
    break;

  case 37: /* Statement: RETURN Expr SEMICOLON  */
#line 125 "./jucompiler.y"
                                                                                    {;}
#line 1674 "y.tab.c"
    break;

  case 38: /* Statement: RETURN SEMICOLON  */
#line 126 "./jucompiler.y"
                                                                                    {;}
#line 1680 "y.tab.c"
    break;

  case 39: /* Statement: MethodInvocation SEMICOLON  */
#line 127 "./jucompiler.y"
                                                                                    {;}
#line 1686 "y.tab.c"
    break;

  case 40: /* Statement: Assignment SEMICOLON  */
#line 128 "./jucompiler.y"
                                                                                    {;}
#line 1692 "y.tab.c"
    break;

  case 41: /* Statement: ParseArgs SEMICOLON  */
#line 129 "./jucompiler.y"
                                                                                    {;}
#line 1698 "y.tab.c"
    break;

  case 42: /* Statement: SEMICOLON  */
#line 130 "./jucompiler.y"
                                                                                    {;}
#line 1704 "y.tab.c"
    break;

  case 43: /* Statement: PRINT LPAR Expr RPAR SEMICOLON  */
#line 131 "./jucompiler.y"
                                                                                    {;}
#line 1710 "y.tab.c"
    break;

  case 44: /* Statement: PRINT LPAR STRLIT RPAR SEMICOLON  */
#line 132 "./jucompiler.y"
                                                                                    {;}
#line 1716 "y.tab.c"
    break;

  case 45: /* MethodInvocation: ID LPAR MethodInvocationAux RPAR  */
#line 134 "./jucompiler.y"
                                                                                    {;}
#line 1722 "y.tab.c"
    break;

  case 46: /* MethodInvocation: ID LPAR RPAR  */
#line 135 "./jucompiler.y"
                                                                                    {;}
#line 1728 "y.tab.c"
    break;

  case 47: /* MethodInvocationAux: Expr  */
#line 138 "./jucompiler.y"
                                                                                    {;}
#line 1734 "y.tab.c"
    break;

  case 48: /* MethodInvocationAux: Expr MethodBodyAux2  */
#line 139 "./jucompiler.y"
                                                                                    {;}
#line 1740 "y.tab.c"
    break;

  case 49: /* MethodBodyAux2: COMMA Expr MethodBodyAux2  */
#line 142 "./jucompiler.y"
                                                                                    {;}
#line 1746 "y.tab.c"
    break;

  case 50: /* MethodBodyAux2: COMMA Expr  */
#line 143 "./jucompiler.y"
                                                                                    {;}
#line 1752 "y.tab.c"
    break;

  case 51: /* Assignment: ID ASSIGN Expr  */
#line 146 "./jucompiler.y"
                                                                                    {;}
#line 1758 "y.tab.c"
    break;

  case 52: /* ParseArgs: PARSEINT LPAR ID LSQ Expr RSQ RPAR  */
#line 149 "./jucompiler.y"
                                                                                    {;}
#line 1764 "y.tab.c"
    break;

  case 53: /* Expr: Expr PLUS Expr  */
#line 152 "./jucompiler.y"
                                                                                    {;}
#line 1770 "y.tab.c"
    break;

  case 54: /* Expr: Expr MINUS Expr  */
#line 153 "./jucompiler.y"
                                                                                    {;}
#line 1776 "y.tab.c"
    break;

  case 55: /* Expr: Expr STAR Expr  */
#line 154 "./jucompiler.y"
                                                                                    {;}
#line 1782 "y.tab.c"
    break;

  case 56: /* Expr: Expr DIV Expr  */
#line 155 "./jucompiler.y"
                                                                                    {;}
#line 1788 "y.tab.c"
    break;

  case 57: /* Expr: Expr MOD Expr  */
#line 156 "./jucompiler.y"
                                                                                    {;}
#line 1794 "y.tab.c"
    break;

  case 58: /* Expr: Expr OR Expr  */
#line 157 "./jucompiler.y"
                                                                                    {;}
#line 1800 "y.tab.c"
    break;

  case 59: /* Expr: Expr XOR Expr  */
#line 158 "./jucompiler.y"
                                                                                    {;}
#line 1806 "y.tab.c"
    break;

  case 60: /* Expr: Expr AND Expr  */
#line 159 "./jucompiler.y"
                                                                                    {;}
#line 1812 "y.tab.c"
    break;

  case 61: /* Expr: Expr LSHIFT Expr  */
#line 160 "./jucompiler.y"
                                                                                    {;}
#line 1818 "y.tab.c"
    break;

  case 62: /* Expr: Expr RSHIFT Expr  */
#line 161 "./jucompiler.y"
                                                                                    {;}
#line 1824 "y.tab.c"
    break;

  case 63: /* Expr: Expr EQ Expr  */
#line 162 "./jucompiler.y"
                                                                                    {;}
#line 1830 "y.tab.c"
    break;

  case 64: /* Expr: Expr NE Expr  */
#line 163 "./jucompiler.y"
                                                                                    {;}
#line 1836 "y.tab.c"
    break;

  case 65: /* Expr: Expr LT Expr  */
#line 164 "./jucompiler.y"
                                                                                    {;}
#line 1842 "y.tab.c"
    break;

  case 66: /* Expr: Expr GT Expr  */
#line 165 "./jucompiler.y"
                                                                                    {;}
#line 1848 "y.tab.c"
    break;

  case 67: /* Expr: Expr LE Expr  */
#line 166 "./jucompiler.y"
                                                                                    {;}
#line 1854 "y.tab.c"
    break;

  case 68: /* Expr: Expr GE Expr  */
#line 167 "./jucompiler.y"
                                                                                    {;}
#line 1860 "y.tab.c"
    break;

  case 69: /* Expr: MINUS Expr  */
#line 168 "./jucompiler.y"
                                                                                    {;}
#line 1866 "y.tab.c"
    break;

  case 70: /* Expr: NOT Expr  */
#line 169 "./jucompiler.y"
                                                                                    {;}
#line 1872 "y.tab.c"
    break;

  case 71: /* Expr: PLUS Expr  */
#line 170 "./jucompiler.y"
                                                                                    {;}
#line 1878 "y.tab.c"
    break;

  case 72: /* Expr: LPAR Expr RPAR  */
#line 171 "./jucompiler.y"
                                                                                    {;}
#line 1884 "y.tab.c"
    break;

  case 73: /* Expr: MethodInvocation  */
#line 172 "./jucompiler.y"
                                                                                    {;}
#line 1890 "y.tab.c"
    break;

  case 74: /* Expr: Assignment  */
#line 173 "./jucompiler.y"
                                                                                    {;}
#line 1896 "y.tab.c"
    break;

  case 75: /* Expr: ParseArgs  */
#line 174 "./jucompiler.y"
                                                                                    {;}
#line 1902 "y.tab.c"
    break;

  case 76: /* Expr: ID  */
#line 175 "./jucompiler.y"
                                                                                    {;}
#line 1908 "y.tab.c"
    break;

  case 77: /* Expr: ID DOTLENGTH  */
#line 176 "./jucompiler.y"
                                                                                    {;}
#line 1914 "y.tab.c"
    break;

  case 78: /* Expr: INTLIT  */
#line 177 "./jucompiler.y"
                                                                                    {;}
#line 1920 "y.tab.c"
    break;

  case 79: /* Expr: REALLIT  */
#line 178 "./jucompiler.y"
                                                                                    {;}
#line 1926 "y.tab.c"
    break;

  case 80: /* Expr: BOOLLIT  */
#line 179 "./jucompiler.y"
                                                                                    {;}
#line 1932 "y.tab.c"
    break;


#line 1936 "y.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

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
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 189 "./jucompiler.y"


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
            AST_print();
        }
    }else{
            /* Analise Lexical & Sintatica : Mostra tudo */
            flag = 2;
            yyparse();
            AST_print(root);
        }       
    return 0;
}


