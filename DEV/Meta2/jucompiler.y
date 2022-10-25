%{
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "symtab.h"
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
}

%token <id> ID 
%token <intlit> INTLIT
%token <reallit> REALLIT

%left '+' '-'

%%
statement: expression {printf("%d", $1);};

expression: 
	INTLIT {printf("SUI");}	/*Guarda valor da variavel*/
    | expression '+' expression {$$ = $1 + $3}	/*Guarda valor da variavel*/

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

