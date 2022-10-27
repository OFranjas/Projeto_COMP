/*
    João Pedro Costa Ferreiro 2014197760
    Guilherme Cardoso Gomes da Silva 2014226354
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct AST *AST_struct;
typedef struct AST
{
    AST_struct pai;
    AST_struct filho;
    AST_struct irmao;
    char *valor;
    char *tipo;
} AST;

// Lex
int yylex(void);
void yyerror(const char *s);
int yylex_destroy();
int yyparse();

// AST
AST_struct cria_no(char *, char *);
void adicionar_filho(AST_struct, AST_struct);
void adicionar_irmao(AST_struct, AST_struct);
int conta_irmaos(AST_struct);
void imprime_arvore(AST_struct, int);