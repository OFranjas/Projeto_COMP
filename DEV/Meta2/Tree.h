#include <stdio.h>
#include <stdlib.h>

typedef struct AST *AST_struct;
typedef struct AST
{
    char *type;
    char *value;
    AST_struct father;
    AST_struct son;
    AST_struct brother;
} AST;

// AST
AST_struct AST_new(char *type, char *value);
void AST_add_son(AST_struct father, AST_struct son);
void AST_add_brother(AST_struct brother, AST_struct son);
void AST_print(AST_struct root, int level);
void AST_free(AST_struct root);
int AST_count_brothers(AST_struct AST);

// LEX
int yylex();
int yyparse();
void yyerror(char *s);

