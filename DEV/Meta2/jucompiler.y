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
struct AST *aux;
int flag = 1;
int error = 0;
char *type;


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
%token RESERVED

%token <string> REALLIT STRLIT INTLIT ID 

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
            
                                                                                    }
       ;

ClassBody:  MethodDecl ClassBody                                                    {
                                                                AST_addBrother($$, $1);
                                                                $$ = $2; 
                                                                                    }
           | MethodDecl                                                             {
                                                                $$ = $1; 
                                                                                    }
           | FieldDecl  ClassBody                                                   {
                                                                AST_addBrother($$, $1);
                                                                $$ = $2; 
                                                                                    }
           | FieldDecl                                                              {
                                                                $$ = $1; 
                                                                                    }
           | SEMICOLON  ClassBody                                                   {
                                                                $$ = $2;
                                                                                    }
           | SEMICOLON                                                              {$$ = NULL;}
           ;

MethodDecl: PUBLIC STATIC MethodHeader MethodBody                                   {
                                                                $$ = AST_newNode("MethodDecl","");
                                                                AST_addSon($$,$3);
                                                                AST_addBrother($3,$4);
                                                                                    }                                             
           ;

FieldDecl: PUBLIC STATIC Type ID FieldDeclCommaAux SEMICOLON                        {
                                                                $$ = AST_newNode("FieldDecl","");
                                                                // Adicionar Type
                                                                // Adicionar ID
                                                                                    }
         ;

FieldDeclCommaAux:  COMMA ID FieldDeclCommaAux                                      {;}
                  | COMMA ID                                                        {;}            
                  ;

Type: BOOL                                                                          {
                                                                $$ = AST_newNode("Bool","");
                                                                type = $$->type;
                                                                                    }
    | INT                                                                           {
                                                                $$ = AST_newNode("Int","");
                                                                type = $$->type;
                                                                                    }
    | DOUBLE                                                                        {
                                                                $$ = AST_newNode("Double","");
                                                                type = $$->type;
                                                                                    }
    | STRING                                                                        {
                                                                $$ = AST_newNode("String","");
                                                                type = $$->type;
                                                                                    }
    ;

MethodHeader: Type ID LPAR FormalParams RPAR                                        {
                                                                $$ = AST_newNode("MethodHeader","");
                                                                // Adicionar Type (filho)
                                                                AST_addBrother($1,$4);
                                                                // Adicionar ID

                                                                                    }
            | Type ID LPAR RPAR                                                     {
                                                                $$ = AST_newNode("MethodHeader","");
                                                                // Adicionar Type (filho)
                                                                // Adicionar ID

                                                                                    }
            | VOID ID LPAR FormalParams RPAR                                        {
                                                                $$ = AST_newNode("MethodHeader","");
                                                                // Adicionar VOID (filho)
                                                                //AST_addBrother($1,$4);
                                                                                    }
            | VOID ID LPAR RPAR                                                     {
                                                                $$ = AST_newNode("MethodHeader","");
                                                                // Adicionar VOID (filho)
                                                                // Adicionar ID
                                                                                    }
        
            ;


FormalParams: Type ID FormalParamsAux                                               {
                                                                $$ = AST_newNode("MethodParams","");
                                                                // Adicionar Type (filho)
                                                                // Adicionar ID
                                                                                    }
            | STRING LSQ RSQ ID                                                     {
                                                                // Adicionar filho
                                                                                    }
            ;

FormalParamsAux: COMMA Type ID FormalParamsAux                                      {
                                                                // Adicionar Type (irmao)
                                                                // Adicionar ID (irmao)
                                                                $$ = $4;
                                                                                    }
               | COMMA Type ID                                                      {
                                                                // Adicionar Type (irmao)
                                                                // Adicionar ID (irmao)
                                                                                    }
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


Statement: LBRACE RBRACE                                                            {$$ = NULL;}
         | LBRACE Statement RBRACE                                                  {
                                                                                    if($2 != NULL && $2->brother != NULL){
                                                                                        $$ = AST_newNode("Statement","");
                                                                                        AST_addSon($$,$2);
                                                                                    }else if($2 != NULL && $2->brother == NULL){
                                                                                        $$ = $2;
                                                                                    }else{
                                                                                        $$ = NULL;
                                                                                    }
                                                                                    }                                                          

         | IF LPAR Expr RPAR Statement                                              {
                                                                                    $$ = AST_newNode("If","");
                                                                                    AST_addSon($$, $3);
                                                                                    if($5 != NULL){
                                                                                        AST_addBrother($3, $5);
                                                                                    }else{
                                                                                        aux = AST_newNode("Null","");
                                                                                        AST_addBrother($3, aux);
                                                                                    }
                                                                                    }

         | IF LPAR Expr RPAR Statement ELSE Statement                               {
                                                                                    $$ = AST_newNode("If","");
                                                                                    AST_addSon($$, $3);
                                                                                    if($5 != NULL){
                                                                                        AST_addBrother($3, $5);
                                                                                    }else{
                                                                                        aux = AST_newNode("Null","");
                                                                                        AST_addBrother($3, aux);
                                                                                    }
                                                                                    if($7 != NULL){
                                                                                        AST_addBrother($3, $7);

                                                                                    }else{
                                                                                        aux = AST_newNode("Null","");
                                                                                        //AST_addBrother($53, aux);
                                                                                    }                                                                               
                                                                                    }

         | WHILE LPAR Expr RPAR Statement                                           {
                                                                                    $$ = AST_newNode("While","");
                                                                                    AST_addSon($$,$3);
                                                                                    if($5 != NULL){
                                                                                        AST_addBrother($3,$5);
                                                                                    }else{
                                                                                        aux = AST_newNode("Null","");
                                                                                        AST_addBrother($3,aux);
                                                                                    }
                                                                                    }
                                                                                    
         | RETURN Expr SEMICOLON                                                    {$$ = AST_newNode("Return","");
                                                                                    AST_addSon($$,$2);
                                                                                    }
         | RETURN SEMICOLON                                                         {$$ = AST_newNode("Return","");
                                                                                    aux = AST_newNode("NULL","");
                                                                                    AST_addSon($$,aux);
                                                                                    }
         | MethodInvocation SEMICOLON                                               {;}
         | Assignment SEMICOLON                                                     {;}
         | ParseArgs SEMICOLON                                                      {;}
         | SEMICOLON                                                                {$$ = NULL;}
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

ParseArgs: PARSEINT LPAR ID LSQ Expr RSQ RPAR                                       {
                                                                $$ = AST_newNode("ParseArgs","");
                                                                printf("ParseArgs\n");
                                                                // Adicionar ID (irmao)
                                                                $$ = $5;
                                                                                    }
         ;

Expr: Expr PLUS Expr                                                                {																
                                                                $$ = AST_newNode("PLUS","");
                                                                printf("PLUS\n");
																AST_addSon($$,$1);
																AST_addBrother($1,$3);
                                                                                    }
    | Expr MINUS Expr                                                               {
                                                                $$ = AST_newNode("MINUS","");
                                                                printf("MINUS\n");
																AST_addSon($$,$1);
																AST_addBrother($1,$3);
                                                                                    }
    | Expr STAR Expr                                                                {
                                                                $$ = AST_newNode("STAR","");
                                                                printf("STAR\n");
																AST_addSon($$,$1);
																AST_addBrother($1,$3);
                                                                                    }
    | Expr DIV Expr                                                                 {
                                                                $$ = AST_newNode("DIV","");
                                                                printf("DIV\n");
																AST_addSon($$,$1);
																AST_addBrother($1,$3);
                                                                                    }
    | Expr MOD Expr                                                                 {
                                                                $$ = AST_newNode("MOD","");
                                                                printf("MOD\n");
																AST_addSon($$,$1);
																AST_addBrother($1,$3);
                                                                                    }
    | Expr OR Expr                                                                  {
                                                                $$ = AST_newNode("OR","");
                                                                printf("OR\n");
																AST_addSon($$,$1);
																AST_addBrother($1,$3);
                                                                                    }
    | Expr XOR Expr                                                                 {
                                                                $$ = AST_newNode("XOR","");
                                                                printf("XOR\n");
																AST_addSon($$,$1);
																AST_addBrother($1,$3);
                                                                                    }
    | Expr AND Expr                                                                 {
                                                                $$ = AST_newNode("AND","");
                                                                printf("AND\n");
																AST_addSon($$,$1);
																AST_addBrother($1,$3);
                                                                                    }
    | Expr LSHIFT Expr                                                              {
                                                                $$ = AST_newNode("LSHIFT","");
                                                                printf("LSHIFT\n");
																AST_addSon($$,$1);
																AST_addBrother($1,$3);
                                                                                    } 
    | Expr RSHIFT Expr                                                              {
                                                                $$ = AST_newNode("RSHIFT","");
                                                                printf("RSHIFT\n");
																AST_addSon($$,$1);
																AST_addBrother($1,$3);
                                                                                    } 
    | Expr EQ Expr                                                                  {
                                                                $$ = AST_newNode("EQ","");
                                                                printf("EQ\n");
																AST_addSon($$,$1);
																AST_addBrother($1,$3);
                                                                                    }   
    | Expr NE Expr                                                                  {
                                                                $$ = AST_newNode("NE","");
                                                                printf("NE\n");
																AST_addSon($$,$1);
																AST_addBrother($1,$3);
                                                                                    }
    | Expr LT Expr                                                                  {
                                                                $$ = AST_newNode("LT","");
                                                                printf("LT\n");
																AST_addSon($$,$1);
																AST_addBrother($1,$3);
                                                                                    }
    | Expr GT Expr                                                                  {
                                                                $$ = AST_newNode("GT","");
                                                                printf("GT\n");
																AST_addSon($$,$1);
																AST_addBrother($1,$3);
                                                                                    }
    | Expr LE Expr                                                                  {
                                                                $$ = AST_newNode("LE","");
                                                                printf("LE\n");
																AST_addSon($$,$1);
																AST_addBrother($1,$3);
                                                                                    }
    | Expr GE Expr                                                                  {
                                                                $$ = AST_newNode("GE","");
                                                                printf("GE\n");
																AST_addSon($$,$1);
																AST_addBrother($1,$3);
                                                                                    }
    | MINUS Expr                                                                    {
        														$$ = AST_newNode("MINUS","");
                                                                printf("MINUS\n");
																AST_addSon($$,$2);
                                                                                    } 
    | NOT Expr                                                                      {
                                                                                    $$ = AST_newNode("NOT","");
                                                                                    printf("NOT\n");
                                                                                    AST_addSon($$,$2);
                                                                                    }
    | PLUS Expr                                                                     {
                                                                                    $$ = AST_newNode("PLUS","");
                                                                                    printf("PLUS\n");
                                                                                    AST_addSon($$,$2);
                                                                                    }
    | LPAR Expr RPAR                                                                {
                                                                                    $$ = $2;
                                                                                    } 
    | MethodInvocation                                                              {;} 
    | Assignment                                                                    {;}
    | ParseArgs                                                                     {;}
    | ID                                                                            {AST_newNode("ID",$1);}
    | ID DOTLENGTH                                                                  {;}
    | INTLIT                                                                        {$$ = AST_newNode("INTLIT",$1);}
    | REALLIT                                                                       {$$ = AST_newNode("REALLIT",$1);} 
    | BOOLLIT                                                                       {;} 
    ;

%%
/* META2 CORRER:
    lex juccompiler.l
    yacc -d -v juccompiler.y		
    cc -o juccompiler y.tab.c lex.yy.c Tree.c
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