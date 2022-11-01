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
#include "Tree.c"


#define NSYMS 100

symtab tab[NSYMS];

symtab *symlook(char *varname);
int yylex (void);
void yyerror(char* s);
%}

%union{
int intlit;
float reallit;
char* id;
struct AST* node;
char* stringValue;
}

/* TOKENS */
%token STRLIT
%token INTLIT
%token REALLIT
%token ID
%token CLASS PUBLIC STATIC
%token STRING VOID INT DOUBLE BOOL
%token SEMICOLON COMMA LBRACE RBRACE LPAR RPAR LSQ RSQ ASSIGN
%token PLUS MINUS STAR DIV MOD
%token XOR OR AND BOOLLIT EQ NE LE GE LT GT NOT
%token WHILE IF ELSE RETURN RESERVED
%token ARROW LSHIFT RSHIFT DOTLENGTH PRINT PARSEINT

/* Precedências */
%left COMMA
%right ASSIGN
%left OR
%left AND
%left XOR
%left EQ NE
%left LT LE GT GE
%left PLUS MINUS
%left STAR DIV MOD
%right NOT 
%left LPAR RPAR
%nonassoc ELSE


%%


PROGRAM: CLASS ID LBRACE ClassBody RBRACE                                           {;}
       ;

ClassBody: ClassBody                                                                {;}  
           | MethodDecl ClassBody                                                   {;}
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

MethodHeader: MethodHeaderAux ID LPAR FormalParams RPAR                             {;}
            | MethodHeaderAux ID LPAR RPAR                                          {;}
            ;

MethodHeaderAux: Type                                                               {;}
               | VOID                                                               {;}
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
                   | Expr COMMA Expr MethodInvocationAux                            {;}
                   | Expr COMMA Expr                                                {;}
                   ;

Assignment: ID ASSIGN Expr                                                          {;}
          ;

ParseArgs: PARSEINT LPAR ID LSQ Expr RSQ RPAR                                       {;}
         ;

Expr:
     Expr PLUS Expr                                                                {
                                                                                    $$ = AST_new("Add","");
                                                                                    AST_add_son($$, $1);
                                                                                    AST_add_son($$, $3);
                                                                                    }
                                                                                    
    | Expr MINUS Expr                                                               {
                                                                                    $$ = AST_new("Sub","");
                                                                                    AST_add_son($$, $1);
                                                                                    AST_add_son($$, $3);
                                                                                    }

    | Expr STAR Expr                                                                {
                                                                                    $$ = AST_new("Mult","");
                                                                                    AST_add_son($$, $1);
                                                                                    AST_add_son($$, $3);  
                                                                                    }

    | Expr DIV Expr                                                                 {$$ = AST_new("Div","");
                                                                                    AST_add_son($$, $1);
                                                                                    AST_add_son($$, $3);
                                                                                    }

    | Expr MOD Expr                                                                 {$$ = AST_new("Mod","");
                                                                                    AST_add_son($$, $1);
                                                                                    AST_add_son($$, $3);  
                                                                                    }

    | Expr OR Expr                                                                  {$$ = AST_new("Or","");
                                                                                    AST_add_son($$, $1);
                                                                                    AST_add_son($$, $3);  
                                                                                    }

    | Expr XOR Expr                                                                 {$$ = AST_new("Xor","");
                                                                                    AST_add_son($$, $1);
                                                                                    AST_add_son($$, $3);  
                                                                                    }

    | Expr AND Expr                                                                 {$$ = AST_new("And","");
                                                                                    AST_add_son($$, $1);
                                                                                    AST_add_son($$, $3);  
                                                                                    }

    | Expr LSHIFT Expr                                                              {;}
    | Expr RSHIFT Expr                                                              {;}

    | Expr EQ Expr                                                                  {
                                                                                    $$ = AST_new("Eq","");
                                                                                    AST_add_son($$, $1);
                                                                                    AST_add_son($$, $3);  
                                                                                    }

    | Expr NE Expr                                                                  {
                                                                                    $$ = AST_new("Ne","");
                                                                                    AST_add_son($$, $1);
                                                                                    AST_add_son($$, $3);
                                                                                    }

    | Expr LT Expr                                                                  {
                                                                                    $$ = AST_new("Lt","");
                                                                                    AST_add_son($$, $1);
                                                                                    AST_add_son($$, $3);
                                                                                    }

    | Expr GT Expr                                                                  {
                                                                                    $$ = AST_new("Gt","");
                                                                                    AST_add_son($$, $1);
                                                                                    AST_add_son($$, $3);
                                                                                    }

    | Expr LE Expr                                                                  {
                                                                                    $$ = AST_new("Le","");
                                                                                    AST_add_son($$, $1);
                                                                                    AST_add_son($$, $3);  
                                                                                    }

    | Expr GE Expr                                                                  {
                                                                                    $$ = AST_new("Ge", "");
                                                                                    AST_add_son($$, $1);
                                                                                    AST_add_son($$, $3);
                                                                                    }

    | MINUS Expr                                                                    {$$ = - $2;} 
    | NOT Expr                                                                      {$$ = ! $2;}
    | PLUS Expr                                                                     {$$ = +$2;}
    | LPAR Expr RPAR                                                                {$$ = $2;}
    | MethodInvocation                                                              {;}
    | Assignment                                                                    {;}
    | ParseArgs                                                                     {;}
    | ID                                                                            {$$ = AST_new("ID", $1);}
    | ID DOTLENGTH                                                                  {$$ = AST_new("ID Dotlength", $1);}
    | INTLIT                                                                        {$$ = AST_new("Intlit", $1);}
    | REALLIT                                                                       {$$ = AST_new("Reallit", $1);} 
    | BOOLLIT                                                                       {$$ = AST_new("Boollit", $1);}
    ;

%%

symtab *symlook(char *varname)
{
    int i;
  
    for(i=0; i<NSYMS; i++)
    {
        if(tab[i].name && strcmp(varname, tab[i].name)==0)   
            return &tab[i];
        if(!tab[i].name)
        {
            tab[i].name=varname;
            return &tab[i];
        }
    }
    yyerror("variaveis a mais...");
    exit(1);
}

