#include <stdio.h>
#include <stdlib.h>

typedef struct AST
{
    char *type;
    char *value;
    struct AST *father;
    struct AST *son;
    struct AST *brother;
}AST;

AST *AST_newNode(char *type, char *value);
void AST_addSon(AST* father, AST* son);
void AST_addBrother(AST* brother, AST* new);
void AST_print(AST* AST,int n_pontos);
void AST_free(AST* AST);