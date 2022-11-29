#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Tree.h"

info_lex *createStruct(char *name, int line, int col)
{

    info_lex *tmp = (info_lex *)malloc(sizeof(info_lex));

    tmp->name = name;
    tmp->linha = line;
    tmp->coluna = col;

    return tmp;
}

/* Create a new node */
AST *AST_newNode(char *type, char *value, int l, int c)
{
    AST *new = (AST *)malloc(sizeof(AST));
    new->type = type;
    new->value = value;
    new->linha = l;
    new->coluna = c;
    new->father = NULL;
    new->son = NULL;
    new->brother = NULL;
    return new;
}

/* Add a son to the father node */
void AST_addSon(AST *father, AST *son)
{
    if (son == NULL || father == NULL)
    {
        return;
    }
    if (father->son == NULL)
    {
        father->son = son;
    }
    else
    {
        AST *temp = father->son;
        while (temp->brother != NULL)
        {
            temp = temp->brother;
        }
        temp->brother = son;
    }
    son->father = father;
}

/* Adds a brother */
void AST_addBrother(AST *brother, AST *new)
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
        AST *temp = brother;
        while (temp->brother != NULL)
        {
            temp = temp->brother;
        }
        temp->brother = new;
    }
    new->father = brother->father;
}

/* Function to print the AST tree */
void AST_print(AST *AST, int n_pontos)
{
    // printf("estou aqui \n");
    if (AST == NULL)
    {
        return;
    }
    if (strcmp(AST->type, "Semicolon") != 0)
    {
        for (int i = 0; i < n_pontos; i++)
            printf(".");

        printf("%s", AST->type);
        if (strcmp(AST->value, "") != 0)
        {
            printf("(%s)", AST->value);
        }
        if (AST->type_semantico != NULL && strcmp(AST->type_semantico, "none") != 0)
        {
            printf(" - %s\n", AST->type_semantico);
        }
        else if (AST->paramTypes != NULL)
        {
            printf(" - (%s)\n", AST->paramTypes);
        }
        else
        {
            printf("\n");
        }
    }
    if (AST->son != NULL)
    {
        AST_print(AST->son, n_pontos + 2);
    }
    if (AST->brother != NULL)
    {
        AST_print(AST->brother, n_pontos);
    }
}

/* Function to free the memory of the tree */
void AST_free(AST *AST)
{
    if (AST == NULL)
    {
        return;
    }
    AST_free(AST->brother);
    AST_free(AST->son);
    free(AST);
}

void AST_getNumberOfSons(AST *AST, int *count)
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

void givetype(AST *no, char *type)
{
    AST *auxiliar = NULL;
    for (AST *atual = no; atual; atual = atual->brother)
    {
        auxiliar = AST_newNode(type, "", 0, 0);
        auxiliar->brother = atual->son;
        atual->son = auxiliar;
    }
}