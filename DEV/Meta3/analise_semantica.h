#ifndef ANALISE_SEMANTICA_H
#define ANALISE_SEMANTICA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Tree.h"
#include <math.h>

// O formato das linhas é:
// <Name>/<t[paramTypes]/tType[/param]

typedef struct line
{
	char *name;
	char *paramTypes;
	char *type;
	char *param;

	struct line *brother;

} symtab_line;

typedef struct header
{
	char *type;
	char *name;
	char *params;

	struct header *brother;
	symtab_line *son;

} symtab_header;

void createClass(AST *node);
symtab_line *createMethodLineAndHeader(AST *node);
void createGlobalVariable(AST *node);
void addParametros(AST *node, symtab_line *line);
void addLocalVariable(AST *node, symtab_line *line);
char *getParamTypes(AST *params);
char *convertType(char *type);
bool verifyGlobalVariable(char *name);
bool verifyLocalVariable(char *name, symtab_line *line);
bool verifyMethod(char *name, char *paramTypes);
char *checkMethod(char *name, char *paramTypes);
char *checkSymbol(AST *node, symtab_line *method);
void checkCall(AST *node, symtab_line *method);
void checkMethodParams(AST *node, char *params_call);
char *getReturnType(AST *node);
symtab_line *getMethodTable(int k);
char *checkNumber(char *number);
char *scat(char *s, char *t);
void printSymbolTable();

void check_program(AST *tree);
void createMethod(AST *node);
void recursiveMethod(AST *node, symtab_line *method, bool isCall);
char *getToken(char *name);

bool check_number_bounds(char *number_strings);
int count_occurrences_string(char *string);

double Pow(double a, double b);
#endif // ANALISE_SEMANTICA_H