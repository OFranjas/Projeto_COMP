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
int flag = 0;
%}

%union{
int intlit;
float reallit;
char* id;
struct AST* node;
}

%token <id> ID 
%token <intlit> INTLIT
%token <reallit> REALLIT


%type <node> expression

%left '+' '-'

%%
expression:
    ID              {$$ = AST_new("ID", $1);}

    | INTLIT         {$$ = AST_new("INTLIT", $1);}

    | REALLIT        {$$ = AST_new("REALLIT", $1);}

    | STRLLIT        {$$ = AST_new("STRLLIT", $1);}

    | expression PLUS expression {$$ = AST_new("Adição","");
                                  AST_add_child($$, $1);
                                  AST_add_brother($1, $3);}

    | expression MINUS expression {$$ = AST_new("Subtração","");
                                   AST_add_child($$, $1);
                                   AST_add_brother($1, $3);}
    
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

