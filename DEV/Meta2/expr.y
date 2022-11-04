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

%type <ast> Program Expr MethodInvocation Assignment ParseArgs

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

Program: CLASS LBRACE Expr RBRACE                           {
                                                                printf("Program\n");
                                                                root = AST_newNode("Program","");
                                                                //TODO: COLOCAR O ID 
                                                                //aux = AST_newNode("Expr","");
                                                                AST_addSon(root, aux);
                                                                printf("addson\n");
                                                                $$ = root;
                                                            }


Expr: Expr PLUS Expr                                                                {	
                                                                printf("Expr\n");															
                                                                aux = AST_newNode("PLUS","");
                                                                printf("aux criado\n");
                                                                //printf("PLUS\n");
																AST_addSon($$,$1);
                                                                printf("addson1\n");
                                                                $$ = aux;
                                                                printf("antes addbrothret\n");
																AST_addSon($$,$3);
                                                                printf(" depois addbrother\n");
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
                                                                $$ = AST_newNode("ENTRE PARS","");
                                                                printf("ENTRE PARS\n");
                                                                AST_addSon($$,$2);
                                                                                    } 
    | ID                                                                            {
                                                                AST_newNode("ID",$1);
                                                                                    }

    | INTLIT                                                                        {
                                                                printf("INTLIT\n");
                                                                $$ = AST_newNode("INTLIT",$1);
                                                                                    }
    | REALLIT                                                                       {
                                                                $$ = AST_newNode("REALLIT",$1);
                                                                                    } 
    ;

%%

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