#include <stdio.h>
#include <stdlib.h>

struct AST
{
    char *type;
    char *value;
    struct AST *father;
    struct AST *son;
    struct AST *brother;
}


