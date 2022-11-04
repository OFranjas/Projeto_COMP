
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Tree.h"



/* Create a new node */
AST *AST_newNode(char *type, char *value)
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
        AST* temp = brother;
        while (temp->brother != NULL)
        {
            temp = temp->brother;
        }
        temp->brother = new;
    }
    new->father = brother->father;
    
}

/* Function to print the AST tree */
void AST_print(AST* AST,int n_pontos)
{
    //printf("estou aqui \n");
    if (AST == NULL)
    {
        printf("A RAIZ ESTA A NULL\n");
    }
    for (int i = 0; i < n_pontos; i++)
        printf(".");
    
    printf("%s", AST->type);
    if (strcmp(AST->value, "") != 0)
    {
        printf("(%s)\n", AST->value);
    }else{
        printf("\n");
    }

    if(AST->brother != NULL){
        AST_print(AST->brother,n_pontos);
    }
    if(AST->son != NULL){
        AST_print(AST->son,n_pontos+=2);
    }
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

void AST_getNumberOfSons(AST* AST, int* count)
{
    if (AST == NULL)
    {
        return;
    }
    if (AST->son != NULL)
    {
        *count += 1;
    }
    AST_getNumberOfSons(AST->brother, count);
    AST_getNumberOfSons(AST->son, count);
}