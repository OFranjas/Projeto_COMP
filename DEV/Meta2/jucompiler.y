/*
    Autores:
    Gonçalo Franja Ferreira - 2020226867
    Gonçalo Gameiro Neves - 2020239361

*/

%{
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "symtab.h"
#include "Tree.h"


struct AST *root;
int flag = 1;
int error = 0;

extern int yylex();
void yyerror (char *s);
%}

%union{
char* string;
struct AST* ast;
}

/* TOKENS */
%token CLASS PUBLIC STATIC
%token STRING VOID INT DOUBLE BOOL
%token SEMICOLON COMMA LBRACE RBRACE LPAR RPAR LSQ RSQ ASSIGN
%token PLUS MINUS STAR DIV MOD
%token XOR OR AND BOOLLIT EQ NE LE GE LT GT NOT
%token WHILE IF ELSE RETURN 
%token ARROW LSHIFT RSHIFT DOTLENGTH PRINT PARSEINT

%token <string> REALLIT STRLIT INTLIT ID RESERVED

%type <ast> Program ClassBody MethodDecl FieldDecl FieldDeclCommaAux Type MethodHeader FormalParams FormalParamsAux MethodBody MethodBodyAux VarDecl VarDeclAux Statement MethodInvocation MethodInvocationAux MethodBodyAux2 Assignment ParseArgs Expr

/* Precedências */
%left COMMA
%right ASSIGN
%left OR
%left AND
%left XOR
%left LSHIFT RSHIFT
%left EQ NE
%left LT LE GT GE
%left PLUS MINUS
%left STAR DIV MOD
%right NOT 
%left LPAR RPAR
%nonassoc ELSE



%%


Program: CLASS ID LBRACE ClassBody RBRACE                                           {																
																                        root = AST_newNode("Program","");
																                        $$ = root;
                                                                                     }
       ;

ClassBody:  MethodDecl ClassBody                                                    {;}
           | MethodDecl                                                             {;}
           | FieldDecl  ClassBody                                                   {;}
           | FieldDecl                                                              {;}
           | SEMICOLON  ClassBody                                                   {;}
           | SEMICOLON                                                              {;}
           ;

MethodDecl: PUBLIC STATIC MethodHeader MethodBody                                   {;}                                             
           ;

FieldDecl: PUBLIC STATIC Type ID FieldDeclCommaAux SEMICOLON                        {;}
         ;

FieldDeclCommaAux:  COMMA ID FieldDeclCommaAux                                      {;}
                  | COMMA ID                                                        {;}            
                  ;

Type: BOOL                                                                          {;}
    | INT                                                                           {;}
    | DOUBLE                                                                        {;}
    ;

MethodHeader: Type ID LPAR FormalParams RPAR                                        {;}
            | Type ID LPAR RPAR                                                     {;}
            | VOID ID LPAR FormalParams RPAR                                        {;}
            | VOID ID LPAR RPAR                                                     {;}
            ;


FormalParams: Type ID FormalParamsAux                                               {;}
            | STRING LSQ RSQ ID                                                     {;}
            ;

FormalParamsAux: COMMA Type ID FormalParamsAux                                      {;}
               | COMMA Type ID                                                      {;}
               ;

MethodBody: LBRACE MethodBodyAux RBRACE                                             {;}
          ;

MethodBodyAux: Statement MethodBodyAux                                              {;}
             | Statement                                                            {;}
             | VarDecl MethodBodyAux                                                {;}
             | VarDecl                                                              {;}
             ;

VarDecl: Type ID VarDeclAux SEMICOLON                                               {;}
       ;

VarDeclAux: COMMA ID VarDeclAux                                                     {;}
          | COMMA ID                                                                {;}
          ;


Statement: LBRACE RBRACE                                                            {;}
         | LBRACE Statement RBRACE                                                  {;}
         | IF LPAR Expr RPAR Statement                                              {;}
         | IF LPAR Expr RPAR Statement ELSE Statement                               {;}
         | WHILE LPAR Expr RPAR Statement                                           {;}
         | RETURN Expr SEMICOLON                                                    {;}
         | RETURN SEMICOLON                                                         {;}
         | MethodInvocation SEMICOLON                                               {;}
         | Assignment SEMICOLON                                                     {;}
         | ParseArgs SEMICOLON                                                      {;}
         | SEMICOLON                                                                {;}
         | PRINT LPAR Expr RPAR SEMICOLON                                           {;}
         | PRINT LPAR STRLIT RPAR SEMICOLON                                         {;}

MethodInvocation: ID LPAR MethodInvocationAux RPAR                                  {;}
                | ID LPAR RPAR                                                      {;}
                ;

MethodInvocationAux: Expr                                                           {;}
                   | Expr MethodBodyAux2                                            {;}
                   ;

MethodBodyAux2: COMMA Expr MethodBodyAux2                                           {;}
              | COMMA Expr                                                          {;}
              ;

Assignment: ID ASSIGN Expr                                                          {;}
          ;

ParseArgs: PARSEINT LPAR ID LSQ Expr RSQ RPAR                                       {;}
         ;

Expr: Expr PLUS Expr                                                                {;}
    | Expr MINUS Expr                                                               {;}
    | Expr STAR Expr                                                                {;}
    | Expr DIV Expr                                                                 {;}
    | Expr MOD Expr                                                                 {;}
    | Expr OR Expr                                                                  {;}
    | Expr XOR Expr                                                                 {;}
    | Expr AND Expr                                                                 {;}
    | Expr LSHIFT Expr                                                              {;} 
    | Expr RSHIFT Expr                                                              {;} 
    | Expr EQ Expr                                                                  {;}
    | Expr NE Expr                                                                  {;}
    | Expr LT Expr                                                                  {;}
    | Expr GT Expr                                                                  {;}
    | Expr LE Expr                                                                  {;}
    | Expr GE Expr                                                                  {;}
    | MINUS Expr                                                                    {;} 
    | NOT Expr                                                                      {;}
    | PLUS Expr                                                                     {;}
    | LPAR Expr RPAR                                                                {;} 
    | MethodInvocation                                                              {;} 
    | Assignment                                                                    {;}
    | ParseArgs                                                                     {;}
    | ID                                                                            {;}
    | ID DOTLENGTH                                                                  {;}
    | INTLIT                                                                        {;}
    | REALLIT                                                                       {;} 
    | BOOLLIT                                                                       {;} 
    ;








%%
/* META2 CORRER:
    lex uccompiler.l
    yacc -d -v uccompiler.y		
    cc -o uccompiler y.tab.c lex.yy.c functions.c
    ./juccompiler
    ./juccompiler -t < INPUT
*/
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
            AST_print(root);
        }
    }else{
            /* Analise Lexical & Sintatica : Mostra tudo */
            flag = 2;
            yyparse();
            AST_print(root);
        }       
    return 0;
}


