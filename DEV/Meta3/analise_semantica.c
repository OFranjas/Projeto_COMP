#include "analise_semantica.h"

// ---------------------------------------------- SYMTAB.H ----------------------------------------------

extern symtab_header *symtab;

void createClass(AST *node)
{

    symtab = (symtab_header *)malloc(sizeof(symtab_header));

    symtab->type = "Class";
    symtab->name = node->value;
}

symtab_line *createMethodLineAndHeader(AST *node)
{
    // Localização na grámatica
    char *name = node->son->son->brother->value;
    char *paramTypes = getParamTypes(node->son->son->brother->brother);
    char *type = convertType(node->son->son->type);

    int line = node->son->son->brother->linha;
    int col = node->son->son->brother->coluna;

    if (strcmp(name, "_") == 0)
        printf("Line %d, col %d: Symbol _ is reserved\n", line, col);

    //----------PRIMEIRO VERIFICAR SE O METODO JA EXISTE--------------

    if (verifyMethod(name, paramTypes))
    {

        //---------- CRIA LINHA DO METODO NA TABELA DA CLASS----------------

        symtab_line *class_line = (symtab_line *)malloc(sizeof(symtab_line));

        class_line->name = name;

        class_line->paramTypes = paramTypes;

        class_line->type = type;

        symtab_line *tmp = symtab->son;
        symtab_line *saveTmp;

        if (tmp == NULL)
        {
            symtab->son = class_line;
        }
        else
        {

            while (tmp != NULL)
            {
                saveTmp = tmp;

                tmp = tmp->brother;
            }

            saveTmp->brother = class_line;
        }

        //--------- CRIAR LINHA NA TABELA DO METODO------------

        symtab_line *method_line = (symtab_line *)malloc(sizeof(symtab_line));

        method_line->name = "return";

        method_line->type = type;

        //---------- CRIAR HEADER DA TABELA DO METODO----------

        symtab_header *header = (symtab_header *)malloc(sizeof(symtab_header));

        header->type = "Method";
        header->name = name;
        header->params = paramTypes;
        header->son = method_line;

        symtab_header *tmp_header = symtab->brother;

        symtab_header *saveTmp_header = symtab;

        while (tmp_header != NULL)
        {

            saveTmp_header = tmp_header;
            tmp_header = tmp_header->brother;
        }

        saveTmp_header->brother = header;

        node->valid = true;

        return method_line;
    }
    else
    {

        printf("Line %d, col %d: Symbol %s(%s) already defined\n", line, col, name, paramTypes);
        node->valid = false;
        return NULL;
    }
}

void createGlobalVariable(AST *node)
{

    char *name = node->son->brother->value;
    char *type = convertType(node->son->type); // nao mexer

    int line = node->son->brother->linha;
    int col = node->son->brother->coluna;

    if (strcmp(name, "_") == 0)
    {
        printf("Line %d, col %d: Symbol _ is reserved\n", line, col);
        return;
    }

    if (verifyGlobalVariable(name))
    {

        symtab_line *line = (symtab_line *)malloc(sizeof(symtab_line));

        line->name = name;
        line->type = type;

        symtab_line *tmp = symtab->son;
        symtab_line *saveTmp;

        if (tmp == NULL)
        {
            symtab->son = line;
        }
        else
        {

            while (tmp != NULL)
            {
                saveTmp = tmp;

                tmp = tmp->brother;
            }

            saveTmp->brother = line;
        }
    }
    else
    {

        printf("Line %d, col %d: Symbol %s already defined\n", line, col, name);
    }
}

void addParametros(AST *node, symtab_line *line)
{

    char *name;
    char *type;
    int numLine, col;

    //---------- ADICIONAR PARAMETROS DA FUNCAO---------

    AST *tmp = node->son->son->brother->brother->son;

    if (line == NULL)
    {
        line = (symtab_line *)malloc(sizeof(symtab_line));
    }

    symtab_line *saveTmp = line;

    while (tmp != NULL)
    {

        name = tmp->son->brother->value;
        type = convertType(tmp->son->type);
        numLine = tmp->son->brother->linha;
        col = tmp->son->brother->coluna;

        if (strcmp(name, "_") == 0)
        {
            printf("Line %d, col %d: Symbol _ is reserved\n", numLine, col);
        }
        else
        {
            if (verifyLocalVariable(name, line))
            {
                symtab_line *param_line = (symtab_line *)malloc(sizeof(symtab_line));

                // Atribuir atributos a linha na tabela
                param_line->name = name;
                param_line->type = type;
                param_line->param = "param";

                saveTmp->brother = param_line;

                saveTmp = param_line;
            }
            else
            {

                printf("Line %d, col %d: Symbol %s already defined\n", numLine, col, name);
            }
        }

        tmp = tmp->brother;
    }
}

void addLocalVariable(AST *node, symtab_line *line)
{

    char *name = node->son->brother->value;
    char *type = convertType(node->son->type);
    int numLine = node->son->brother->linha;
    int col = node->son->brother->coluna;

    if (strcmp(name, "_") == 0)
    {
        printf("Line %d, col %d: Symbol _ is reserved\n", numLine, col);
        return;
    }

    if (verifyLocalVariable(name, line))
    {

        symtab_line *param_line = (symtab_line *)malloc(sizeof(symtab_line));

        // Atribuir atributos a linha na tabela
        param_line->name = name;
        param_line->type = type;

        symtab_line *saveTmp = line;
        symtab_line *tmp = line->brother;

        while (tmp != NULL)
        {

            saveTmp = tmp;

            tmp = tmp->brother;
        }

        saveTmp->brother = param_line;
    }
    else
    {

        printf("Line %d, col %d: Symbol %s already defined\n", numLine, col, name);
    }
}

char *getParamTypes(AST *params)
{

    char *string = "";
    int i = 0;

    AST *tmp = params->son;

    while (tmp != NULL)
    {

        if (i == 0)
        {

            string = scat(string, convertType(tmp->son->type));
        }
        else
        {
            string = scat(string, ",");
            string = scat(string, convertType(tmp->son->type));
        }

        i++;
        tmp = tmp->brother;
    }

    return string;
}

char *convertType(char *type)
{

    if (strcmp(type, "StringArray") == 0)
    {
        return "String[]";
    }
    else if (strcmp(type, "Bool") == 0)
    {
        return "boolean";
    }
    else
    {
        char *string = (char *)malloc(strlen(type) + 1);
        char *tmp = type;
        int i = 0;
        for (; *tmp; ++tmp)
        {
            string[i] = tolower(*tmp);
            i++;
        }
        return string;
    }
}

bool verifyGlobalVariable(char *name)
{

    symtab_line *tmp = symtab->son;

    while (tmp != NULL)
    {

        if (strcmp(tmp->name, name) == 0 && tmp->paramTypes == NULL)
        {
            return false;
        }

        tmp = tmp->brother;
    }

    return true;
}

bool verifyLocalVariable(char *name, symtab_line *line)
{

    symtab_line *tmp = line->brother;

    while (tmp != NULL)
    {

        if (strcmp(tmp->name, name) == 0)
            return false;

        tmp = tmp->brother;
    }

    return true;
}

bool verifyMethod(char *name, char *paramTypes)
{

    symtab_line *tmp = symtab->son;

    while (tmp != NULL)
    {

        if (strcmp(tmp->name, name) == 0 && tmp->paramTypes != NULL && strcmp(tmp->paramTypes, paramTypes) == 0)
        {
            return false;
        }

        tmp = tmp->brother;
    }

    return true;
}

char *checkMethod(char *name, char *paramTypes)
{

    symtab_header *tmp = symtab;

    while (tmp != NULL)
    {

        if (strcmp(tmp->name, name) == 0 && tmp->params != NULL && strcmp(tmp->params, paramTypes) == 0)
        {
            return tmp->son->paramTypes;
        }

        tmp = tmp->brother;
    }

    return "olaalalla";
}

char *checkSymbol(AST *node, symtab_line *method)
{

    // char* name = node->name;
    char *param = node->value;
    int line = node->linha;
    int col = node->coluna;

    //--------PRIMEIRO VERIFICAR VARIAVEIS LOCAIS DO METODO---------

    symtab_line *tmp = method->brother;

    while (tmp != NULL)
    {

        if (strcmp(tmp->name, param) == 0)
        {
            return tmp->type;
        }
        tmp = tmp->brother;
    }

    //--------AGORA VERIFICAR VARIAVEIS GLOBAIS-------

    tmp = symtab->son;

    while (tmp != NULL)
    {

        if (strcmp(tmp->name, param) == 0 && tmp->paramTypes == NULL)
        {
            return tmp->type;
        }

        tmp = tmp->brother;
    }

    printf("Line %d, col %d: Cannot find symbol %s\n", line, col, param);

    return "undef";
}

void checkCall(AST *node, symtab_line *method)
{

    // char* name = node->son->param;

    char *params = "";

    AST *tmp = node->son->brother;

    int i = 0;

    while (tmp != NULL)
    {

        if (i == 0)
        {
            params = scat(params, tmp->type_semantico);
        }
        else
        {
            params = scat(params, ",");
            params = scat(params, tmp->type_semantico);
        }

        i++;

        tmp = tmp->brother;
    }

    checkMethodParams(node, params);
}

void checkMethodParams(AST *node, char *params_call)
{

    char *name = node->son->value;

    char *final_params, *final_type;

    int checkFunc = 0;

    symtab_line *tmp = symtab->son;

    //------- ENCONTRAR A FUNCAO MAIS CORRETA ---------
    while (tmp != NULL && checkFunc < 2)
    {

        char *params_method = tmp->paramTypes;

        if (params_method != NULL && strcmp(tmp->name, name) == 0 && strcmp(tmp->paramTypes, params_call) == 0)
        {

            // node->type = tmp->type;

            checkFunc++;

            final_params = (char *)malloc(strlen(params_call) + 1);
            strcpy(final_params, params_call);

            final_type = (char *)malloc(strlen(tmp->type) + 1);
            strcpy(final_type, tmp->type);

            // return params_call;
        }

        tmp = tmp->brother;
    }

    tmp = symtab->son;

    //----------  CASO PARTICULAR DE INT/DOUBLE ----------
    if (checkFunc == 0)
    {
        while (tmp != NULL && checkFunc < 2)
        {

            char *params_method = tmp->paramTypes;

            if (params_method != NULL && strcmp(tmp->name, name) == 0)
            {

                char *params = "";
                int i = 0;

                char *tmp_call = (char *)malloc(strlen(params_call) + 1);
                strcpy(tmp_call, params_call);

                char *tmp_method = (char *)malloc(strlen(params_method) + 1);
                strcpy(tmp_method, params_method);

                char *rest_call = tmp_call;
                char *rest_method = tmp_method;

                bool check = true;

                char *token_call = strtok_r(rest_call, ",", &rest_call);
                char *token_method = strtok_r(rest_method, ",", &rest_method);

                while (token_call != NULL)
                {

                    if (token_method == NULL)
                    {
                        check = false;
                        break;
                    }

                    if (strcmp(token_call, token_method) != 0 && !(strcmp(token_method, "double") == 0 && strcmp(token_call, "int") == 0))
                    {
                        check = false;
                        break;
                    }

                    if (i == 0)
                    {
                        params = scat(params, token_method);
                    }
                    else
                    {
                        params = scat(params, ",");
                        params = scat(params, token_method);
                    }

                    i++;

                    token_call = strtok_r(rest_call, ",", &rest_call);
                    token_method = strtok_r(rest_method, ",", &rest_method);
                }

                if (check && token_method == NULL)
                {
                    // node->type = tmp->type;

                    checkFunc++;

                    final_params = (char *)malloc(strlen(params_call) + 1);
                    strcpy(final_params, params);

                    final_type = (char *)malloc(strlen(tmp->type) + 1);
                    strcpy(final_type, tmp->type);
                    // return params;
                }
            }

            tmp = tmp->brother;
        }
    }

    if (checkFunc == 1)
    {
        node->type_semantico = final_type;

        node->son->paramTypes = final_params;

        node->son->type_semantico = NULL;
    }
    else if (checkFunc == 0)
    {
        node->type_semantico = "undef";

        node->son->type_semantico = node->type_semantico;

        printf("Line %d, col %d: Cannot find symbol %s(%s)\n", node->son->linha, node->son->coluna, node->son->value, params_call);
    }
    else
    {
        node->type_semantico = "undef";

        node->son->type_semantico = node->type_semantico;

        printf("Line %d, col %d: Reference to method %s(%s) is ambiguous\n", node->son->linha, node->son->coluna, node->son->value, params_call);
    }

    // node->type = "undef";

    return;
}

char *getReturnType(AST *node)
{

    // char* name = node->son->param;
    char *paramTypes = node->son->paramTypes;

    symtab_line *tmp = symtab->son;

    while (tmp != NULL)
    {

        if (tmp->paramTypes != NULL && strcmp(tmp->paramTypes, paramTypes) == 0)
            return tmp->type;

        tmp = tmp->brother;
    }

    return "undef";
}

symtab_line *getMethodTable(int k)
{

    symtab_header *tmp = symtab;

    int i;
    for (i = 0; i < k; i++)
    {
        if (strcmp(tmp->name, "FieldDecl") == 0)
            i--;

        tmp = tmp->brother;
    }

    return tmp->son;
}

char *checkNumber(char *number)
{

    char *tmp_number = (char *)malloc(strlen(number) + 1);
    strcpy(tmp_number, number);

    char *new_number = "";

    char *token = strtok(tmp_number, "_");

    while (token != NULL)
    {

        new_number = scat(new_number, token);

        token = strtok(NULL, "_");
    }

    return new_number;
}

char *scat(char *s, char *t)
{
    char *p = (char *)malloc(strlen(s) + strlen(t) + 1); /* 3: you will have to reserve memory to hold the copy. */
    int ptr = 0, temp = 0;                               /* 4 initialise some helpers */

    while (s[temp] != '\0')
    { /* 5. use the temp to "walk" over string 1 */
        p[ptr++] = s[temp++];
    }
    temp = 0;
    while (t[temp] != '\0')
    { /* and string two */
        p[ptr++] = t[temp++];
    }
    s = NULL;
    free(s);

    t = NULL;
    free(t);
    return p;
}

void printSymbolTable()
{

    symtab_header *tmp = symtab;

    // printf("aaa\n");

    while (tmp != NULL)
    {

        if (strcmp(tmp->type, "Class") == 0)
            printf("===== %s %s Symbol Table =====\n", tmp->type, tmp->name);
        else
            printf("\n===== %s %s(%s) Symbol Table =====\n", tmp->type, tmp->name, tmp->params);

        symtab_line *tmp_line = tmp->son;

        while (tmp_line != NULL)
        {

            if (strcmp(tmp_line->name, "return") == 0)
            {
                printf("%s\t\t%s\n", tmp_line->name, tmp_line->type);
            }
            else if (tmp_line->param != NULL)
            {
                printf("%s\t\t%s\t%s\n", tmp_line->name, tmp_line->type, tmp_line->param);
            }
            else if (tmp_line->paramTypes == NULL)
            {
                printf("%s\t\t%s\n", tmp_line->name, tmp_line->type);
            }
            else
            {
                printf("%s\t(%s)\t%s\n", tmp_line->name, tmp_line->paramTypes, tmp_line->type);
            }

            tmp_line = tmp_line->brother;
        }

        tmp = tmp->brother;
    }
    printf("\n");
}
// --------------------------------------------------------------------------------- Semantics.h ---------------------------------------------------------------------------------
void check_program(AST *tree)
{

    AST *tmp = tree;
    int i = 0;

    // Fazer os "cabecalhos" de cada tabela
    tmp = tmp->son;
    while (tmp != NULL)
    {

        if (tmp->type != NULL)
        {
            if (i == 0)
            {
                createClass(tmp);
            }
            else if (strcmp(tmp->type, "MethodDecl") == 0)
            {
                createMethod(tmp);
            }
            else if (strcmp(tmp->type, "FieldDecl") == 0)
            {
                createGlobalVariable(tmp);
            }
        }

        tmp = tmp->brother;

        i++;
    }

    tmp = tree->son;
    i = 1;
    while (tmp != NULL)
    {

        if (tmp->type != NULL)
        {
            if (strcmp(tmp->type, "MethodDecl") == 0 && tmp->valid)
            {
                recursiveMethod(tmp->son->brother, getMethodTable(i), false);
                i++;
            }
        }

        tmp = tmp->brother;
    }
}

void createMethod(AST *node)
{

    symtab_line *line = createMethodLineAndHeader(node);

    addParametros(node, line);
}

void recursiveMethod(AST *node, symtab_line *method, bool isCall)
{

    char *name = node->type; // nao mexer
    // char* param = node->param;
    int line = node->linha;
    int col = node->coluna;

    bool call = false, print = false, returnBool = false, logic = false, comparation = false, length = false, parseArgs = false, maths = false, ifStatement = false, assign = false;

    if (name == NULL)
    {

        if (node->brother != NULL)
        {
            recursiveMethod(node->brother, method, isCall);
        }

        return;
    }

    //--------- INICIAR VARIAVEL LOCAL ----------
    if (strcmp(name, "VarDecl") == 0)
    {

        addLocalVariable(node, method);

        if (node->brother != NULL)
        {
            recursiveMethod(node->brother, method, isCall);
        }

        return;
    }

    //---------- VERIFICAR SE VARIAVEL JA FOI DECLARADA ---------
    else if (strcmp(name, "Id") == 0)
    {
        if (!isCall)
        {
            // Gameiro
            node->type_semantico = checkSymbol(node, method);
        }
    }
    else if (strcmp(name, "DecLit") == 0)
    {
        // Gameiro
        node->type_semantico = "int";

        // printf("%d\n",atoi(node->param));

        char *number = checkNumber(node->value);

        if ((strcmp(number, "2147483648") >= 0 && strlen(number) == strlen("2147483648")) || strlen(number) > strlen("2147483648"))
        {
            printf("Line %d, col %d: Number %s out of bounds\n", line, col, node->value);
        }
    }
    else if (strcmp(name, "RealLit") == 0)
    {
        // Gameiro
        node->type_semantico = "double";

        char *number = node->value;

        if (!check_number_bounds(number))
        {
            printf("Line %d, col %d: Number %s out of bounds\n", line, col, node->value);
        }
    }
    else if (strcmp(name, "BoolLit") == 0)
    {
        // Gameiro
        node->type_semantico = "boolean";
    }
    else if (strcmp(name, "StrLit") == 0)
    {
        // Gameiro
        node->type_semantico = "String";
    }
    //----------- CHAMADA DE FUNCAO ---------
    else if (strcmp(name, "Call") == 0)
    {

        call = true;

        isCall = true;
    }
    else if (strcmp(name, "If") == 0 || strcmp(name, "While") == 0)
    {

        ifStatement = true;
    }
    else if (strcmp(name, "Return") == 0)
    {

        returnBool = true;
    }
    else if (strcmp(name, "Print") == 0)
    {

        print = true;
    }
    else if (strcmp(name, "Length") == 0)
    {

        length = true;
    }
    else if (strcmp(name, "ParseArgs") == 0)
    {

        parseArgs = true;
    }
    else if (strcmp(name, "Lshift") == 0 || strcmp(name, "Rshift") == 0)
    {

        // printf("node->brother->type = %s", node->son->brother->type);
        // printf("node->brother->value = %s\n", node->son->brother->value);

        if (strcmp(node->son->brother->type, "DecLit") == 0)
        {
            node->type_semantico = "int";
            if (node->son != NULL)
                node->son->type_semantico = node->type_semantico;
            if (node->son->brother != NULL)
                node->son->brother->type_semantico = node->type_semantico;
        }
        else
        {
            node->type_semantico = "none";
        }

        if (node->brother != NULL)
        {
            // printf("node->brother->type = %s", node->brother->type);
            recursiveMethod(node->brother, method, isCall);
        }

        check_shift_sons(node->son, method);
        check_shift_sons(node->son->brother, method);
        check_shift(node);

        if (strcmp(node->type_semantico, "none") == 0)
        {
            node->son->type_semantico = "none";
            node->son->brother->type_semantico = "none";
        }

        return;
    }
    else if (strcmp(name, "Assign") == 0)
    {
        // printf("aaa\n");
        assign = true;
    }
    else if (strcmp(name, "And") == 0 || strcmp(name, "Or") == 0 || strcmp(name, "Not") == 0 || strcmp(name, "Xor") == 0)
    {

        logic = true;
    }
    else if (strcmp(name, "Ne") == 0 || strcmp(name, "Lt") == 0 || strcmp(name, "Le") == 0 || strcmp(name, "Gt") == 0 || strcmp(name, "Ge") == 0 || strcmp(name, "Eq") == 0)
    {

        comparation = true;
    }
    else if (strcmp(name, "Mul") == 0 || strcmp(name, "Add") == 0 || strcmp(name, "Sub") == 0 || strcmp(name, "Div") == 0 || strcmp(name, "Mod") == 0 || strcmp(name, "Plus") == 0 || strcmp(name, "Minus") == 0)
    {

        maths = true;
    }

    if (!call)
        isCall = false;

    if (node->son != NULL)
    {
        recursiveMethod(node->son, method, isCall);
    }

    isCall = false;

    if (assign)
    {

        if (strcmp(node->son->type_semantico, node->son->brother->type_semantico) != 0 || (strcmp(node->son->type_semantico, "undef") == 0) || (strcmp(node->son->brother->type_semantico, "undef") == 0 || strcmp(node->son->brother->type_semantico, "none") == 0) || strcmp(node->son->type_semantico, "none") == 0 || (strcmp(node->son->type_semantico, "String[]") == 0) || (strcmp(node->son->brother->type_semantico, "String[]") == 0))
        {
            if (!(strcmp(node->son->type_semantico, "double") == 0 && strcmp(node->son->brother->type_semantico, "int") == 0))
            {
                // Gameiro
                node->type_semantico = node->son->type_semantico;
                printf("Line %d, col %d: Operator %s cannot be applied to types %s, %s\n", line, col, getToken(name), node->son->type_semantico, node->son->brother->type_semantico);
            }
            else
            {
                // Gameiro
                node->type_semantico = node->son->type_semantico;
            }
        }
        else
        {
            // Gameiro
            node->type_semantico = node->son->type_semantico;
        }
    }
    else if (maths)
    {
        if (node->son->brother != NULL)
        {
            if ((strcmp(node->son->type_semantico, "int") != 0 && strcmp(node->son->type_semantico, "double") != 0) || (strcmp(node->son->brother->type_semantico, "int") != 0 && strcmp(node->son->brother->type_semantico, "double") != 0))
            {

                node->type_semantico = "undef";

                printf("Line %d, col %d: Operator %s cannot be applied to types %s, %s\n", line, col, getToken(name), node->son->type_semantico, node->son->brother->type_semantico);
            }
            else
            {

                if (strcmp(node->son->type_semantico, "double") == 0 || strcmp(node->son->brother->type_semantico, "double") == 0)
                    node->type_semantico = "double";
                else
                    node->type_semantico = "int";
            }
        }
        else
        {
            if (strcmp(node->son->type_semantico, "int") != 0 && strcmp(node->son->type_semantico, "double") != 0)
            {

                node->type_semantico = "undef";

                printf("Line %d, col %d: Operator %s cannot be applied to type %s\n", line, col, getToken(name), node->son->type_semantico);
            }
            else
            {

                if (strcmp(node->son->type_semantico, "double") == 0)
                    node->type_semantico = "double";
                else
                    node->type_semantico = "int";
            }
        }
    }
    else if (logic || comparation)
    {
        // TODO: Verificar se o xor é undef, int ou boolean
        //  Por default colocamos o xor a boolean mas temosde verificar os nos que se seguem
        node->type_semantico = "boolean";

        if (node->son->brother != NULL)
        {
            check_xor(node);
            // printf("type = %s\n", node->son->brother->type);
            // printf("value = %s\n", node->son->brother->value);
            // printf("line = %d\n", node->son->brother->linha);
            // printf("col = %d\n", node->son->brother->coluna);
            // printf("type_semantico = %s\n", node->son->brother->type_semantico);

            // // ID
            // printf("type = %s\n", node->son->type);
            // printf("value = %s\n", node->son->value);
            // printf("line = %d\n", node->son->linha);
            // printf("col = %d\n", node->son->coluna);
            // printf("type_semantico = %s\n", node->son->type_semantico);
            // printf("------------------------\n");

            if (strcmp(node->son->type_semantico, node->son->brother->type_semantico) != 0 || (strcmp(node->son->type_semantico, "undef") == 0) || (strcmp(node->son->brother->type_semantico, "undef") == 0) || (strcmp(node->son->type_semantico, "String[]") == 0) || (strcmp(node->son->brother->type_semantico, "String[]") == 0))
            {
                if (!((strcmp(node->son->type_semantico, "int") == 0 && strcmp(node->son->brother->type_semantico, "double") == 0) || (strcmp(node->son->type_semantico, "double") == 0 && strcmp(node->son->brother->type_semantico, "int") == 0)))
                {
                    printf("Line %d, col %d: Operator %s cannot be applied to types %s, %s\n", line, col, getToken(name), node->son->type_semantico, node->son->brother->type_semantico);
                }
            }
            else if ((strcmp(node->son->type_semantico, node->son->brother->type_semantico) == 0) && (strcmp(node->son->type, "Id") == 0) && (strcmp(node->son->brother->type, "BoolLit") == 0) && (strcmp(node->type, "Eq") != 0) && (strcmp(node->type, "Ne") != 0))
            {
                printf("Line %d, col %d: Operator %s cannot be applied to types %s, %s\n", line, col, getToken(name), node->son->type_semantico, node->son->brother->type_semantico);
            }
        }

        else
        {
            if (strcmp(node->son->type_semantico, "boolean") != 0)
            {
                printf("Line %d, col %d: Operator %s cannot be applied to type %s\n", line, col, getToken(name), node->son->type_semantico);
            }
        }
    }
    else if (call)
    {
        checkCall(node, method);
    }
    else if (ifStatement)
    {

        if (strcmp(node->son->type_semantico, "boolean") != 0)
            printf("Line %d, col %d: Incompatible type %s in %s statement\n", node->son->linha, node->son->coluna, node->son->type_semantico, getToken(name));
    }
    else if (print)
    {

        if (node->son != NULL && (strcmp(node->son->type_semantico, "undef") == 0 || strcmp(node->son->type_semantico, "void") == 0 || strcmp(node->son->type_semantico, "String[]") == 0))
            printf("Line %d, col %d: Incompatible type %s in %s statement\n", node->son->linha, node->son->coluna, node->son->type_semantico, getToken(name));
    }
    else if (returnBool)
    {
        if (node->son != NULL)
        {
            if (strcmp(node->son->type_semantico, method->type) != 0 || strcmp(node->son->type_semantico, "undef") == 0 || strcmp(node->son->type_semantico, "void") == 0)
            {

                if (!(strcmp(node->son->type_semantico, "int") == 0 && strcmp(method->type, "double") == 0))
                {
                    // Aqui
                    // printf("node->son->type = %s\n", node->son->type_semantico);
                    printf("Line %d, col %d: Incompatible type %s in %s statement\n", node->son->linha, node->son->coluna, node->son->type_semantico, getToken(name));
                }
            }
        }
        else
        {
            if (strcmp(method->type, "void") != 0)
                printf("Line %d, col %d: Incompatible type void in %s statement\n", node->linha, node->coluna, getToken(name));
        }
    }
    else if (length)
    {
        node->type_semantico = "int";

        if (strcmp(node->son->type_semantico, "String[]") != 0)
            printf("Line %d, col %d: Operator %s cannot be applied to type %s\n", node->linha, node->coluna, getToken(name), node->son->type_semantico);
    }
    else if (parseArgs)
    {
        node->type_semantico = "int";

        if (strcmp(node->son->type_semantico, "String[]") != 0 || strcmp(node->son->brother->type_semantico, "int") != 0)
            printf("Line %d, col %d: Operator %s cannot be applied to types %s, %s\n", node->linha, node->coluna, getToken(name), node->son->type_semantico, node->son->brother->type_semantico);
    }

    if (node->brother != NULL)
        recursiveMethod(node->brother, method, isCall);
}

char *getToken(char *name)
{

    if (strcmp(name, "Assign") == 0)
        return "=";
    else if (strcmp(name, "Add") == 0 || strcmp(name, "Plus") == 0)
        return "+";
    else if (strcmp(name, "Minus") == 0 || strcmp(name, "Sub") == 0)
        return "-";
    else if (strcmp(name, "Mul") == 0)
        return "*";
    else if (strcmp(name, "Mod") == 0)
        return "%";
    else if (strcmp(name, "Div") == 0)
        return "/";
    else if (strcmp(name, "Ne") == 0)
        return "!=";
    else if (strcmp(name, "Lt") == 0)
        return "<";
    else if (strcmp(name, "Le") == 0)
        return "<=";
    else if (strcmp(name, "Gt") == 0)
        return ">";
    else if (strcmp(name, "Ge") == 0)
        return ">=";
    else if (strcmp(name, "Eq") == 0)
        return "==";
    else if (strcmp(name, "And") == 0)
        return "&&";
    else if (strcmp(name, "Or") == 0)
        return "||";
    else if (strcmp(name, "Xor") == 0)
        return "^";
    else if (strcmp(name, "Not") == 0)
        return "!";
    else if (strcmp(name, "Print") == 0)
        return "System.out.print";
    else if (strcmp(name, "If") == 0)
        return "if";
    else if (strcmp(name, "While") == 0)
        return "while";
    else if (strcmp(name, "Return") == 0)
        return "return";
    else if (strcmp(name, "Length") == 0)
        return ".length";
    else if (strcmp(name, "ParseArgs") == 0)
        return "Integer.parseInt";
    else
        return name;
}

bool check_number_bounds(char *number_strings)
{
    long number = atol(number_strings);
    float expoente, base;
    char temp[1024];

    if (number >= 2147483647 || number <= -2147483648)
    {
        return false;
    }

    // Convert 2.5E-324 to long and check if it is in the bounds

    // Procurar se o numero tem E
    char *e = strchr(number_strings, 'E');
    strcpy(temp, number_strings);

    if ((strchr(number_strings, 'E') != NULL) && (strchr(number_strings, '_') == NULL))
    {
        // Calcular a potencia
        expoente = atof(e + 1);

        base = atof(strtok(temp, "E"));

        if (Pow(base, expoente) >= 2147483647 || Pow(base, expoente) <= -2147483648)
        {
            return false;
        }
    }
    else if ((strchr(number_strings, 'E') != NULL) && (strchr(number_strings, '_') != NULL))
    {
        // Remover todos os _ do numero
        char *aux = strtok(temp, "_");
        char *aux2 = (char *)malloc(sizeof(char) * 1024);

        for (int i = 0; i < count_occurrences_string(temp); i++)
        {
            strcpy(aux2, aux);
            aux = strtok(NULL, "_");
            strcat(aux2, aux);
        }

        // Calcular a potencia
        expoente = atof(e + 1);
        base = atof(strtok(temp, "E"));

        if (Pow(base, expoente) >= 2147483647 || Pow(base, expoente) <= -2147483648)
        {
            return false;
        }
    }

    return true;
}

int count_occurrences_string(char *string)
{
    int count = 0;
    char *aux = string;

    while ((aux = strchr(aux, '_')) != NULL)
    {
        count++;
        aux++;
    }

    return count;
}

double Pow(double a, double b)
{
    double power = 1;

    // if b is negative
    if (b < 0)
    {
        b = -b;
        a = 1 / a;
    }

    for (int i = 1; i <= b; i++)
    {
        power = power * a;
    }
    // printf("power(%f,%f) = %f\n", a, b, power);
    return power;
}

void check_xor(AST *node)
{
    // Verificar se o xor é undef, boolean ou int
    // Por default o xor é boolean

    // Check if the node->type_semantico is boolean

    if (node == NULL)
        return;

    if (strcmp(node->type, "Xor") != 0)
        return;

    if (node->son->type_semantico != NULL)
    {
        // printf("node->value = %s\n", node->value);
        //  Verificar se é double
        if (strchr(node->son->value, '.') != NULL)
        {
            // É double
            node->type_semantico = "undef";
            printf("Line %d, col %d: Operator %s cannot be applied to types %s, %s\n", node->linha, node->coluna, getToken(node->type), node->son->type_semantico, node->son->brother->type_semantico);
        }
        else
        {
            // Verificar se é int
            if (strcmp(node->son->type_semantico, "int") == 0 && strcmp(node->son->brother->type_semantico, "int") == 0)
            {
                node->type_semantico = "int";
            }
        }

        // printf("son = %s, brother = %s\n", node->son->type_semantico, node->son->brother->type_semantico);
    }
}

// 823

void check_shift_sons(AST *node, symtab_line *method)
{
    // printf("Check shift\n");

    char *name = node->type;

    // Add the type to avery node
    if (node == NULL)
        return;

    if (strcmp(name, "Id") == 0)
    {
        node->type_semantico = checkSymbol(node, method);
    }
    else if (strcmp(name, "RealLit") == 0)
    {
        node->type_semantico = "double";
    }
    else if (strcmp(name, "DecLit") == 0)
    {
        node->type_semantico = "int";
    }
    else if (strcmp(name, "BoolLit") == 0)
    {
        node->type_semantico = "boolean";
    }
    else if (strcmp(name, "StrLit") == 0)
    {
        node->type_semantico = "String";
    }
}

void check_shift(AST *node)
{
    if (node == NULL)
        return;

    if (node->son == NULL || node->son->brother == NULL)
        return;

    if (node->son->type_semantico == NULL || node->son->brother->type_semantico == NULL)
        return;

    if (strcmp(node->son->type_semantico, "int") == 0 && strcmp(node->son->brother->type_semantico, "int") == 0)
    {
        if ((strcmp(node->son->type, "Id") == 0 && strcmp(node->son->brother->type, "Id") == 0))
        {
            node->type_semantico = "none";
        }
        else
        {
            node->type_semantico = "int";
        }
    }
    else
    {
        node->type_semantico = "undef";
        printf("Line %d, col %d: Operator << cannot be applied to types %s, %s\n", node->linha, node->coluna, node->son->type_semantico, node->son->brother->type_semantico);
    }
}