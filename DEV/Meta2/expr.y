/*
    Autores:
    Gonçalo Franja Ferreira - 2020226867
    Gonçalo Gameiro Neves - 2020239361

*/

%{
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//#include "symtab.h"
#include "Tree.h"


struct AST *root;
struct AST *aux;
int flag = 1;
int error = 0;
char *type;
int n_sons;


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

%type <ast> Statement Program Expr MethodInvocation Assignment ParseArgs Xona MethodInvocationaux  VarDecl Type VarDeclAux FieldDecl FieldDeclAux FormalParams FormalParamsAux MethodHeader

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

Program: CLASS ID LBRACE Xona RBRACE                           {
                                                                $$ = AST_newNode("Program","");
                                                                aux = AST_newNode("ID", $2); 
                                                                AST_addSon($$, aux);
                                                                AST_addSon($$,$4);
                                                                root = $$;
                                                            }
        ;

Xona: Expr                                                  {$$ = $1;}
    | Assignment                                            {$$ = $1;}
    | ParseArgs                                             {$$ = $1;}
    | MethodInvocation                                      {$$ = $1;}
    | Statement                                             {$$ = $1;}
    | VarDecl                                               {$$ = $1;}
    | FieldDecl                                             {$$ = $1;}
    | FormalParams                                          {$$ = $1;}
    | MethodHeader                                          {$$ = $1;}
    ;

MethodHeader: Type ID LPAR FormalParams RPAR                   {
                                                                $$ = AST_newNode("MethodHeader","");
                                                                AST_addSon($$,$1);
                                                                aux = AST_newNode("ID", $2);
                                                                AST_addBrother($1,aux);
                                                                AST_addBrother(aux,$4);
                                                               }

        | Type ID LPAR RPAR                                    {
                                                                $$ = AST_newNode("MethodHeader","");
                                                                AST_addSon($$,$1);
                                                                aux = AST_newNode("ID", $2);
                                                                AST_addBrother($1,aux);
                                                               }

        | VOID ID LPAR FormalParams RPAR                       {
                                                                $$ = AST_newNode("MethodHeader","");
                                                                aux = AST_newNode("VOID", "");
                                                                AST_addSon($$,aux); 
                                                                AST_addBrother(aux,AST_newNode("ID", $2));
                                                                AST_addBrother(aux,$4);
                                                               }

        | VOID ID LPAR RPAR                                    {
                                                                $$ = AST_newNode("MethodHeader","");
                                                                aux = AST_newNode("VOID", "");
                                                                AST_addSon($$,aux); 
                                                                AST_addBrother(aux,AST_newNode("ID", $2));
                                                               }
        ;

FieldDecl: PUBLIC STATIC Type ID FieldDeclAux SEMICOLON     {
                                                                $$ = AST_newNode("FieldDecl", "");
                                                                AST_addSon($$,$3);
                                                                AST_addBrother($3, AST_newNode("ID", $4));
                                                            }
        ;

FieldDeclAux: COMMA ID FieldDeclAux                         {
                                                                $$ = AST_newNode("ID", $2);
                                                                AST_addBrother($$, $3);
                                                            }

            |                                              {$$ = NULL;}                                                

Type: INT                                                   {$$ = AST_newNode("Int", "");}
    | DOUBLE                                                {$$ = AST_newNode("Double", "");}
    | BOOL                                                  {$$ = AST_newNode("Bool", "");}                
    ;

FormalParams: Type ID FormalParamsAux                                      {$$ = AST_newNode("ParamDecl","");
                                                                            AST_addSon($$,$1);
                                                                            aux = AST_newNode("ID", $2);
                                                                            AST_addSon($$,aux);
                                                                            AST_addSon($$,$3);
                                                                            }
            | STRING LSQ RSQ ID                                            {
                                                                           $$ = AST_newNode("StringArray","");
                                                                           aux =  AST_newNode("ID",$4);
                                                                           AST_addSon($$,aux);
                                                                           aux = AST_newNode("StringArray","");
                                                                           AST_addSon($$,aux);
                                                                           }
            ;                               


FormalParamsAux: COMMA Type ID FormalParamsAux                            { $$ = AST_newNode("ID",$3);
                                                                            AST_addBrother($$,$2);
                                                                            }
                                                                            
                |                                                         {$$ = NULL;}
                ;


VarDecl: Type ID VarDeclAux SEMICOLON                                   {
                                                                $$ = AST_newNode("VarDecl", "");
                                                                AST_addSon($$, $1);
                                                                AST_addBrother($1, AST_newNode("ID", $2));
                                                                        }
        ;

VarDeclAux: COMMA ID VarDeclAux                            {
                                                                $$ = AST_newNode("ID", $2);
                                                                AST_addBrother($$, $3);
                                                            }
        |                                                   {$$ = NULL;}
        ;

Statement: 
           /* | WHILE LPAR Expr RPAR Statement                               {
                                                                            $$ = AST_newNode("While","");
                                                                            AST_addSon($$,$3);
                                                                            AST_addSon($$,$5);
                                                                            } */
            RETURN SEMICOLON                                            {$$ = AST_newNode("Return", "");}

            | RETURN Expr SEMICOLON                                        {$$ = AST_newNode("Return","");
                                                                            AST_addSon($$,$2);
                                                                            }
            | SEMICOLON                                                  {$$ = NULL;}

            | PRINT LPAR Expr RPAR SEMICOLON                             {$$ = AST_newNode("Print","");
                                                                            AST_addSon($$,$3);
                                                                            }   
            | PRINT LPAR STRLIT RPAR SEMICOLON                                         {
                                                                                    $$ = AST_newNode("Print","");
                                                                                    aux = AST_newNode("STRLIT", $3);
                                                                                    AST_addSon($$, aux);
                                                                                    }
            | MethodInvocation SEMICOLON                                               {$$ = $1;}
            | Assignment SEMICOLON                                                     {$$ = $1;}
            | ParseArgs SEMICOLON                                                      {$$ = $1;}
            ;


MethodInvocation: ID LPAR Expr MethodInvocationaux RPAR                 {  
                                                                            $$ = AST_newNode("Call", "");
                                                                            aux = AST_newNode("ID", $1);
                                                                            AST_addSon($$, aux);
                                                                            AST_addBrother(aux, $3);
                                                                            AST_addBrother($3, $4);
                                                                        }
                                                                        
                | ID LPAR RPAR                                          { 
                                                                            $$ = AST_newNode("Call", "");
                                                                            aux = AST_newNode("ID", $1);
                                                                            AST_addSon($$, aux);
                                                                        }                             
                ;

MethodInvocationaux: COMMA Expr MethodInvocationaux                     {
                                                                            $$ = $2;
                                                                            AST_addBrother($$, $3);
                                                                        }

                    |                                                   {$$ = NULL;}                    
                    ;

ParseArgs: PARSEINT LPAR ID LSQ Expr RSQ RPAR              {
                                                                $$ = AST_newNode("ParseArgs","");
                                                                aux = AST_newNode("ID", $3);
                                                                AST_addSon($$, aux);
                                                                AST_addBrother(aux, $5);
                                                            }
        ;

Assignment: ID ASSIGN Expr                                  {
                                                                $$ = AST_newNode("Assign", "");
                                                                aux = AST_newNode("ID", $1);
                                                                AST_addSon($$,$3);
                                                                AST_addBrother($3,aux);
                                                            }
    ;
    
Expr: Expr PLUS Expr                                                                {	
                                                                aux = AST_newNode("ADD","");
                                                                $$ = aux;
																AST_addSon($$,$1);
																AST_addBrother($1,$3);
                                                                
                                                                                    }
    | Expr MINUS Expr                                                               {
                                                                $$ = AST_newNode("SUB","");
																AST_addSon($$,$1);
																AST_addBrother($1,$3);
                                                                                    }
    | Expr STAR Expr                                                                {
                                                                $$ = AST_newNode("MUL","");
																AST_addSon($$,$1);
																AST_addBrother($1,$3);
                                                                                    }
    | Expr DIV Expr                                                                 {
                                                                $$ = AST_newNode("DIV","");
																AST_addSon($$,$1);
																AST_addBrother($1,$3);
                                                                                    }
    | Expr MOD Expr                                                                 {
                                                                $$ = AST_newNode("MOD","");
																AST_addSon($$,$1);
																AST_addBrother($1,$3);
                                                                                    }
    | Expr OR Expr                                                                  {
                                                                $$ = AST_newNode("OR","");
																AST_addSon($$,$1);
																AST_addBrother($1,$3);
                                                                                    }
    | Expr XOR Expr                                                                 {
                                                                $$ = AST_newNode("XOR","");
																AST_addSon($$,$1);
																AST_addBrother($1,$3);
                                                                                    }
    | Expr AND Expr                                                                 {
                                                                $$ = AST_newNode("AND","");
																AST_addSon($$,$1);
																AST_addBrother($1,$3);
                                                                                    }
    | Expr LSHIFT Expr                                                              {
                                                                $$ = AST_newNode("LSHIFT","");
																AST_addSon($$,$1);
																AST_addBrother($1,$3);
                                                                                    } 
    | Expr RSHIFT Expr                                                              {
                                                                $$ = AST_newNode("RSHIFT","");
																AST_addSon($$,$1);
																AST_addBrother($1,$3);
                                                                                    } 
    | Expr EQ Expr                                                                  {
                                                                $$ = AST_newNode("EQ","");
																AST_addSon($$,$1);
																AST_addBrother($1,$3);
                                                                                    }   
    | Expr NE Expr                                                                  {
                                                                $$ = AST_newNode("NE","");
																AST_addSon($$,$1);
																AST_addBrother($1,$3);
                                                                                    }
    | Expr LT Expr                                                                  {
                                                                $$ = AST_newNode("LT","");
																AST_addSon($$,$1);
																AST_addBrother($1,$3);
                                                                                    }
    | Expr GT Expr                                                                  {
                                                                $$ = AST_newNode("GT","");
																AST_addSon($$,$1);
																AST_addBrother($1,$3);
                                                                                    }
    | Expr LE Expr                                                                  {
                                                                $$ = AST_newNode("LE","");
																AST_addSon($$,$1);
																AST_addBrother($1,$3);
                                                                                    }
    | Expr GE Expr                                                                  {
                                                                $$ = AST_newNode("GE","");
																AST_addSon($$,$1);
																AST_addBrother($1,$3);
                                                                                    }
    | MINUS Expr                                                                    {
        														$$ = AST_newNode("MINUS","");
																AST_addSon($$,$2);
                                                                                    } 
    | NOT Expr                                                                      {
                                                                $$ = AST_newNode("NOT","");
                                                                AST_addSon($$,$2);
                                                                                    }
    | PLUS Expr                                                                     {
                                                                $$ = AST_newNode("PLUS","");
                                                                AST_addSon($$,$2);
                                                                                    }
    | LPAR Expr RPAR                                                                {
                                                                $$ = $2;
                                                                                    } 
    | ID                                                                            {
                                                                $$ = AST_newNode("ID",$1);

                                                                                    }
    | ID DOTLENGTH                                                                  {
                                                                $$ = AST_newNode("ID",$1);
                                                                                    }

    | INTLIT                                                                        {
                                                                $$ = AST_newNode("DecLit",$1);
                                                                                    }
    | REALLIT                                                                       {
                                                                $$ = AST_newNode("REALLIT",$1);
                                                                                    } 

    | BOOLLIT                                                                       {
                                                                $$ = AST_newNode("BOOLLIT","");
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
            AST_print(root,0);
        }
    }else{
            /* Analise Lexical & Sintatica : Mostra tudo */
            flag = 2;
            yyparse();
            AST_print(root,0);
        }       
    return 0;
}