#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>

typedef struct AST
{
    char *type;
    char *value;
    struct AST *father;
    struct AST *son;
    struct AST *brother;

    bool valid;

    int linha;
    int coluna;
}AST;

AST *AST_newNode(char *type, char *value);
void AST_addSon(AST* father, AST* son);
void AST_addBrother(AST* brother, AST* new);
void AST_print(AST* AST,int n_pontos);
void AST_free(AST* AST);
void AST_getNumberOfSons(AST* AST, int* count);
int nrChilds (AST* node);
void givetype(AST* no,char* type);