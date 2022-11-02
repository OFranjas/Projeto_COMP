
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Tree.h"



/* Create a new node */
AST AST_newNode(char *type, char *value)
{
    AST* new = (AST*)malloc(sizeof(AST));
    new->type = type;
    new->value = value;
    new->father = NULL;
    new->son = NULL;
    new->brother = NULL;
    return new;
}

/* Add a son to the father node */
void AST_addSon(AST* father, AST* son)
{
    if (son == NULL)
    {
        return;
    }
    if (father->son == NULL)
    {
        father->son = son;
    }
    else
    {
        AST* temp = father->son;
        while (temp->brother != NULL)
        {
            temp = temp->brother;
        }
        temp->brother = son;
    }
    son->father = father;
}

/* Adds a brother */
void AST_addBrother(AST* brother, AST* new)
{

    if (new == NULL)
    {
        return;
    }

    if (brother == NULL)
    {
        return;
    }
    else
    {
        AST* temp = brother->brother;
        while (temp->brother != NULL)
        {
            temp = temp->brother;
        }
        temp->brother = new;
    }
    new->father = brother->father;
}

/* Function to print the AST tree */
void AST_print(AST* AST)
{
    if (AST == NULL)
    {
        return;
    }
    printf("%s ", AST->type);
    if (strcmp(AST->value, "") != 0)
    {
        printf("%s ", AST->value);
    }else{
        printf("\n");
    }
    AST_print(AST->brother);
    AST_print(AST->son);
}

/* Function to free the memory of the tree */
void AST_free(AST* AST)
{
    if (AST == NULL)
    {
        return;
    }
    AST_free(AST->brother);
    AST_free(AST->son);
    free(AST);
}