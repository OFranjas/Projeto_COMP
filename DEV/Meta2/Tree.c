
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Tree.h"

// Function: Create a new AST node
// Input: type, value
// Output: a pointer to the new AST node
AST_struct AST_new(char *type, char *value)
{

    AST_struct new = (AST_struct)malloc(sizeof(AST));

    new->type = type;
    new->value = value;

    new->father = NULL;
    new->son = NULL;
    new->brother = NULL;

    return new;
}

// Function: Add a new AST node as the son of another AST node
// Input: father, son
// Output: void
void AST_add_son(AST_struct *father, AST_struct *son)
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
        AST_struct temp = father->son;
        while (temp->brother != NULL)
        {
            temp = temp->brother;
        }
        temp->brother = son;
    }
    son->father = father;
}

// Function: Add a new AST node as the brother of another AST node
// Input: brother, son
// Output: void
void AST_add_brother(AST_struct brother, AST_struct son)
{

    if (son == NULL)
    {
        return;
    }

    if (brother->brother == NULL)
    {
        brother->brother = son;
    }
    else
    {
        AST_struct temp = brother->brother;
        while (temp->brother != NULL)
        {
            temp = temp->brother;
        }
        temp->brother = son;
    }
    son->father = brother->father;
}

// Function: Print the AST
// Input: AST
// Output: void
void AST_print(AST_struct AST)
{

    if (AST == NULL)
    {
        return;
    }

    printf("%s ", AST->type);
    if (AST->value != NULL)
    {
        printf("%s ", AST->value);
    }

    AST_print(AST->son);
    AST_print(AST->brother);
}

// Function: Free the AST
// Input: AST
// Output: void
void AST_free(AST_struct AST)
{

    if (AST == NULL)
    {
        return;
    }

    AST_free(AST->son);
    AST_free(AST->brother);

    free(AST);
}

// Function: Count number of brothers
// Input: AST
// Output: number of brothers
int AST_count_brothers(AST_struct AST)
{

    if (AST == NULL)
    {
        return 0;
    }

    int count = 0;
    AST_struct temp = AST;
    while (temp != NULL)
    {
        count++;
        temp = temp->brother;
    }

    return count;
}


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