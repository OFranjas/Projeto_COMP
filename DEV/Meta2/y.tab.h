/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

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
    REALLIT = 301,
    STRLIT = 302,
    INTLIT = 303,
    ID = 304,
    RESERVED = 305
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
#define REALLIT 301
#define STRLIT 302
#define INTLIT 303
#define ID 304
#define RESERVED 305

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 24 "jucompiler.y"

char* string;
struct AST* ast;

#line 162 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
