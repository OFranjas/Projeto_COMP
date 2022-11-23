#ifndef TREE_H
#define TREE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

typedef struct AST
{
    char *type;
    char *value;
    char *type_semantico;
    char *paramTypes;

    bool valid;

    int linha;
    int coluna;

    struct AST *father;
    struct AST *son;
    struct AST *brother;
} AST;

typedef struct info_lex
{
    int linha;
    int coluna;
    char name;
} info_lex;

AST *AST_newNode(char *type, char *value);
void AST_addSon(AST *father, AST *son);
void AST_addBrother(AST *brother, AST *new);
void AST_print(AST *AST, int n_pontos);
void AST_free(AST *AST);
void AST_getNumberOfSons(AST *AST, int *count);
int nrChilds(AST *node);
void givetype(AST *no, char *type);

#endif // TREE_H