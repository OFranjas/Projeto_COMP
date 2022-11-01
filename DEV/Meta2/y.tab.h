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
    STRLIT = 258,
    INTLIT = 259,
    REALLIT = 260,
    ID = 261,
    CLASS = 262,
    PUBLIC = 263,
    STATIC = 264,
    STRING = 265,
    VOID = 266,
    INT = 267,
    DOUBLE = 268,
    BOOL = 269,
    SEMICOLON = 270,
    COMMA = 271,
    LBRACE = 272,
    RBRACE = 273,
    LPAR = 274,
    RPAR = 275,
    LSQ = 276,
    RSQ = 277,
    ASSIGN = 278,
    PLUS = 279,
    MINUS = 280,
    STAR = 281,
    DIV = 282,
    MOD = 283,
    XOR = 284,
    OR = 285,
    AND = 286,
    BOOLLIT = 287,
    EQ = 288,
    NE = 289,
    LE = 290,
    GE = 291,
    LT = 292,
    GT = 293,
    NOT = 294,
    WHILE = 295,
    IF = 296,
    ELSE = 297,
    RETURN = 298,
    RESERVED = 299,
    ARROW = 300,
    LSHIFT = 301,
    RSHIFT = 302,
    DOTLENGTH = 303,
    PRINT = 304,
    PARSEINT = 305
  };
#endif
/* Tokens.  */
#define STRLIT 258
#define INTLIT 259
#define REALLIT 260
#define ID 261
#define CLASS 262
#define PUBLIC 263
#define STATIC 264
#define STRING 265
#define VOID 266
#define INT 267
#define DOUBLE 268
#define BOOL 269
#define SEMICOLON 270
#define COMMA 271
#define LBRACE 272
#define RBRACE 273
#define LPAR 274
#define RPAR 275
#define LSQ 276
#define RSQ 277
#define ASSIGN 278
#define PLUS 279
#define MINUS 280
#define STAR 281
#define DIV 282
#define MOD 283
#define XOR 284
#define OR 285
#define AND 286
#define BOOLLIT 287
#define EQ 288
#define NE 289
#define LE 290
#define GE 291
#define LT 292
#define GT 293
#define NOT 294
#define WHILE 295
#define IF 296
#define ELSE 297
#define RETURN 298
#define RESERVED 299
#define ARROW 300
#define LSHIFT 301
#define RSHIFT 302
#define DOTLENGTH 303
#define PRINT 304
#define PARSEINT 305

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 25 "jucompiler.y"

int intlit;
float reallit;
char* id;
struct AST* node;
char* stringValue;

#line 165 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
