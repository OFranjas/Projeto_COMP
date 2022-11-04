/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

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
    RESERVED = 301,                /* RESERVED  */
    REALLIT = 302,                 /* REALLIT  */
    STRLIT = 303,                  /* STRLIT  */
    INTLIT = 304,                  /* INTLIT  */
    ID = 305                       /* ID  */
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

#line 172 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
