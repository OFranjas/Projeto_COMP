#include "Tree.h"

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