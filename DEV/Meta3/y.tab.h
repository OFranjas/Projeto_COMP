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
    SEMICOLON = 262,
    COMMA = 263,
    LBRACE = 264,
    RBRACE = 265,
    LPAR = 266,
    RPAR = 267,
    LSQ = 268,
    RSQ = 269,
    WHILE = 270,
    IF = 271,
    ELSE = 272,
    ARROW = 273,
    RESERVED = 274,
    VOID = 275,
    ID = 276,
    STRLIT = 277,
    INTLIT = 278,
    REALLIT = 279,
    BOOLLIT = 280,
    BOOL = 281,
    INT = 282,
    DOUBLE = 283,
    PLUS = 284,
    MINUS = 285,
    STAR = 286,
    DIV = 287,
    MOD = 288,
    AND = 289,
    OR = 290,
    XOR = 291,
    LSHIFT = 292,
    RSHIFT = 293,
    EQ = 294,
    GE = 295,
    GT = 296,
    LE = 297,
    LT = 298,
    NE = 299,
    NOT = 300,
    ASSIGN = 301,
    PRINT = 302,
    RETURN = 303,
    PARSEINT = 304,
    DOTLENGTH = 305
  };
#endif
/* Tokens.  */
#define CLASS 258
#define PUBLIC 259
#define STATIC 260
#define STRING 261
#define SEMICOLON 262
#define COMMA 263
#define LBRACE 264
#define RBRACE 265
#define LPAR 266
#define RPAR 267
#define LSQ 268
#define RSQ 269
#define WHILE 270
#define IF 271
#define ELSE 272
#define ARROW 273
#define RESERVED 274
#define VOID 275
#define ID 276
#define STRLIT 277
#define INTLIT 278
#define REALLIT 279
#define BOOLLIT 280
#define BOOL 281
#define INT 282
#define DOUBLE 283
#define PLUS 284
#define MINUS 285
#define STAR 286
#define DIV 287
#define MOD 288
#define AND 289
#define OR 290
#define XOR 291
#define LSHIFT 292
#define RSHIFT 293
#define EQ 294
#define GE 295
#define GT 296
#define LE 297
#define LT 298
#define NE 299
#define NOT 300
#define ASSIGN 301
#define PRINT 302
#define RETURN 303
#define PARSEINT 304
#define DOTLENGTH 305

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 42 "expr.y"

char* string;
struct AST* ast;
struct info_lex *info;

#line 163 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
