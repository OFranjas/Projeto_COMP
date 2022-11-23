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
#line 42 "expr.y"

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
