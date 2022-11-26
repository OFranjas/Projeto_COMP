/*
    Autores:
    Gonçalo Franja Ferreira - 2020226867
    Gonçalo Gameiro Neves - 2020239361

*/

%{
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "analise_semantica.h"


symtab_header* symtab;

struct AST *root;
struct AST *methodParams;
struct AST *temp;
char aux[1024];
char aux2[1024];
struct AST *methodParams;
int flag = 1;

char *type;
int n_sons;
int yydebug = 1;
int print_tree = 1;

int yylex(void);
extern int yylineno;
extern int coluna;
extern int yyerror(char *s);


int yydegug = 1;



%}

%union{
char* string;
struct AST* ast;
struct info_lex *info;
}

/* TOKENS */
%token CLASS PUBLIC STATIC
%token STRING VOID 
%token SEMICOLON COMMA LBRACE RBRACE LPAR RPAR LSQ RSQ 
%token WHILE IF ELSE  
%token ARROW 
%token RESERVED

%token <info> ID STRLIT INTLIT REALLIT BOOLLIT BOOL INT DOUBLE PLUS MINUS STAR DIV MOD AND OR XOR LSHIFT RSHIFT EQ GE GT LE LT NE NOT ASSIGN PRINT RETURN PARSEINT DOTLENGTH


%type <ast> StatementAux Statement ExprAux MethodDecl MethodBody ProgramAux MethodBodyAux Program Expr MethodInvocation Assignment ParseArgs  MethodInvocationAux MethodInvocationAux_2 VarDecl Type VarDeclAux FieldDecl FieldDeclAux FormalParams FormalParamsAux MethodHeader

/* Precedências */
%left COMMA
%right ASSIGN
%left OR
%left AND
%left XOR
%left LSHIFT RSHIFT
%left EQ NE
%left LT LE GT GE
%left PLUS MINUS
%left STAR DIV MOD
%right NOT 
%left LPAR RPAR
%nonassoc ELSE



%%
// Certo
Program: CLASS ID LBRACE ProgramAux RBRACE                   {root = AST_newNode("Program","",0,0);AST_addSon(root, AST_newNode("Id", $2->name,$2->linha,$2->coluna));AST_addSon(root,$4);$$ = root;}
        ;
        
// Certo +/- ? 
ProgramAux: /*empty*/									     {$$=NULL;}
          | MethodDecl ProgramAux                            {$$ = $1;AST_addBrother($$, $2);}
          | FieldDecl ProgramAux                             {$$ = $1;AST_addBrother($$, $2);}
          | SEMICOLON ProgramAux                             {$$ = $2;}
          
// Certo
MethodDecl: PUBLIC STATIC MethodHeader MethodBody            {$$ = AST_newNode("MethodDecl","",0,0);AST_addSon($$,$3);AST_addSon($$,$4);}   
                                            

// Certo +/- ?
// Linhas e colunas    
FieldDecl: PUBLIC STATIC Type ID FieldDeclAux SEMICOLON      {$$ = AST_newNode("FieldDecl", "",0,0);AST_addSon($$,$3);AST_addSon($$, AST_newNode("Id", $4->name,$4->linha,$4->coluna));givetype($5, $3->type);AST_addBrother($$, $5);}
        | error SEMICOLON                                    {$$ = NULL;print_tree=0;}// nao recupera deste
        

// Certo ?
FieldDeclAux: COMMA ID FieldDeclAux                          {$$ = AST_newNode("FieldDecl","",0,0);AST_addSon($$, AST_newNode("Id", $2->name,$2->linha,$2->coluna));AST_addBrother($$, $3);}

            |                                                {$$ = NULL;}                                     
            
// Certo
Type: INT                                                    {$$ = AST_newNode($1->name,"",$1->linha,$1->coluna);}
    | DOUBLE                                                 {$$ = AST_newNode($1->name,"",$1->linha,$1->coluna);}
    | BOOL                                                   {$$ = AST_newNode($1->name,"",$1->linha,$1->coluna);}             
    


// Certo ? 
MethodHeader: Type ID LPAR FormalParams RPAR                 {$$ = AST_newNode("MethodHeader","",0,0);methodParams = AST_newNode("MethodParams","",0,0);AST_addSon($$,$1);AST_addSon($$,AST_newNode("Id", $2->name,$2->linha,$2->coluna));AST_addSon($$, methodParams);AST_addSon(methodParams,$4);}
        | VOID ID LPAR FormalParams RPAR                     {$$ = AST_newNode("MethodHeader","",0,0);methodParams = AST_newNode("MethodParams","",0,0);AST_addSon($$,AST_newNode("Void", "",0,0));AST_addSon($$,AST_newNode("Id", $2->name,$2->linha,$2->coluna));AST_addSon($$, methodParams);AST_addSon(methodParams,$4);}
                                                               
        
// Certo
FormalParams: Type ID FormalParamsAux                        {$$ = AST_newNode("ParamDecl","",0,0);AST_addSon($$,$1);AST_addSon($$,AST_newNode("Id", $2->name,$2->linha,$2->coluna));AST_addBrother($$,$3);}
                                                                            
            | STRING LSQ RSQ ID                              {$$ = AST_newNode("ParamDecl","",0,0);AST_addSon($$,AST_newNode("StringArray","",0,0));AST_addSon($$,AST_newNode("Id", $4->name,$4->linha,$4->coluna));}
            |                                                {$$ = NULL;}
            
            
// Certo ? 
FormalParamsAux: COMMA Type ID FormalParamsAux               {$$ = AST_newNode("ParamDecl","",0,0);AST_addSon($$,$2);AST_addSon($$,AST_newNode("Id",$3->name,$3->linha,$3->coluna));AST_addBrother($$,$4);}
                                                                            
                |                                            {$$ = NULL;}
                

// Certo
MethodBody: LBRACE MethodBodyAux RBRACE                      {$$ = AST_newNode("MethodBody","",0,0);AST_addSon($$,$2);}
          

// Certo
MethodBodyAux: Statement MethodBodyAux                       {if($1 != NULL){$$ = $1; AST_addBrother($$, $2);}else{$$ = $2;}}
             | VarDecl MethodBodyAux                         {$$ = $1; AST_addBrother($$, $2);}
             |                                               {$$ = NULL;}
             

                      

// Certo
VarDecl: Type ID VarDeclAux SEMICOLON                        {$$ = AST_newNode("VarDecl", "",0,0);AST_addSon($$, $1);AST_addSon($$, AST_newNode("Id", $2->name,$2->linha,$2->coluna));givetype($3, $1->type);AST_addBrother($$, $3);}
        
// Certo
VarDeclAux: COMMA ID VarDeclAux                              {$$ = AST_newNode("VarDecl","",0,0);AST_addSon($$, AST_newNode("Id", $2->name,$2->linha,$2->coluna));AST_addBrother($$, $3);}
        |                                                    {$$ = NULL;}
        

Statement:  LBRACE Statement StatementAux RBRACE	         {
                                                                int count = 0;
                                                                if($2 != NULL){
                                                                    count++;
                                                                }
                                                                temp = $3;
                                                                while(temp != NULL){
                                                                    if(temp->type != NULL && strcmp(temp->type,"Semicolon")!=0){
                                                                        count++;
                                                                    }

                                                                    temp = temp->brother;
                                                                }
                                                                
                                                                if(count > 1){
                                                                    $$ = AST_newNode("Block","",0,0);
                                                                    AST_addSon($$,$2);
                                                                    AST_addSon($$,$3);
                                                                }
                                                                else {
                                                                    $$ = $2;
                                                                }
                                                            }

		 | LBRACE RBRACE 								     {$$ = NULL;}

		 | IF LPAR Expr RPAR Statement 					     {
                                                                $$ = AST_newNode("If","",0,0);
                                                                AST_addSon($$,$3);
                                                                
                                                                if($5 == NULL || strcmp($5->type,"Semicolon")==0){
                                                                    AST_addSon($$,AST_newNode("Block","",0,0));
                                                                    AST_addSon($$,AST_newNode("Block","",0,0));
                                                                }else{
                                                                    AST_addSon($$,$5);
                                                                    AST_addSon($$,AST_newNode("Block","",0,0));
                                                                }
                                                                
                                                            }


		 | IF LPAR Expr RPAR Statement ELSE Statement 	     {
                                                                $$ = AST_newNode("If","",0,0);
                                                                AST_addSon($$,$3);
                                                                if($5 == NULL || strcmp($5->type,"Semicolon")==0){
                                                                    AST_addSon($$,AST_newNode("Block","",0,0)); // addbrother(3,5)
                                                                }else{
                                                                    AST_addSon($$,$5);
                                                                }
                                                                if($7 == NULL || strcmp($7->type,"Semicolon")==0){
                                                                    AST_addSon($$,AST_newNode("Block","",0,0)); // addbrother(3,7)
                                                                }else{
                                                                    AST_addSon($$,$7);
                                                                }
                                                                
                                                            }
                                                            


		 | WHILE LPAR Expr RPAR Statement 				     {
                                                                $$ = AST_newNode("While","",0,0);
                                                                AST_addSon($$,$3);
                                                                if($5 == NULL || strcmp($5->type,"Semicolon")==0){
                                                                    AST_addSon($$,AST_newNode("Block","",0,0));
                                                                }else{
                                                                    AST_addSon($$,$5);
                                                                }
                                                            }
		 
         | RETURN Expr SEMICOLON  						     {$$ = AST_newNode("Return","",$1->linha,$1->coluna);AST_addSon($$,$2);}
		 | RETURN SEMICOLON								     {$$ = AST_newNode("Return", "",$1->linha,$1->coluna);}
		 | MethodInvocation SEMICOLON 					     {$$ = $1;}
		 | Assignment SEMICOLON 						     {$$ = AST_newNode("Assign","",$1->linha,$1->coluna+3);AST_addSon($$,$1);}
		 | ParseArgs SEMICOLON 							     {$$ = $1;}
		 | SEMICOLON									     {$$ = AST_newNode("Semicolon","",0,0);}		
		 | PRINT LPAR Expr RPAR SEMICOLON 				     {$$ = AST_newNode("Print","",$1->linha,$1->coluna);AST_addSon($$,$3);}
		 | PRINT LPAR STRLIT RPAR SEMICOLON 			     {$$ = AST_newNode("Print","",$1->linha,$1->coluna);AST_addSon($$, AST_newNode("StrLit", $3->name,$3->linha,$3->coluna));}
		 | error SEMICOLON 								     {$$ = NULL;print_tree = 0;}
  
// Certo
StatementAux: Statement StatementAux                         {$$ = $1;AST_addBrother($$,$2);}
            |                                                {$$ = NULL;}
            

// Certo
MethodInvocation:  ID LPAR RPAR 					         {$$ = AST_newNode("Call", "",0,0);AST_addSon($$, AST_newNode("Id", $1->name,$1->linha,$1->coluna));}
				| ID LPAR MethodInvocationAux RPAR 		     {$$ = AST_newNode("Call", "",0,0);AST_addSon($$, AST_newNode("Id", $1->name,$1->linha,$1->coluna));AST_addSon($$,$3);}
				| ID LPAR error RPAR 					     {$$ = NULL;print_tree = 0;} //  nao recupera deste

// Certo
MethodInvocationAux: Expr MethodInvocationAux_2			     {$$ = $1;AST_addBrother($$,$2);}

// Certo
MethodInvocationAux_2: 						                 {$$ = NULL;}
					| COMMA Expr MethodInvocationAux_2       {$$ = $2;AST_addBrother($$,$3);}
     
// Certo
Assignment: ID ASSIGN Expr                                   {$$ = AST_newNode("Id", $1->name,$1->linha,$1->coluna); AST_addBrother($$,$3);}

// Certo
ParseArgs: PARSEINT LPAR ID LSQ Expr RSQ RPAR                {$$ = AST_newNode("ParseArgs","",0,0);AST_addSon($$, AST_newNode("Id", $3->name,$3->linha,$3->coluna));AST_addSon($$, $5);}
        | PARSEINT LPAR error RPAR                           {$$ = NULL;print_tree=0;}
     
// Certo
Expr: ExprAux                                               {$$ = $1;}
    | Assignment                                            {$$ = AST_newNode("Assign","",$1->linha,$1->coluna);AST_addSon($$,$1);}

// Certo
ExprAux: ExprAux PLUS ExprAux                               {$$ = AST_newNode("Add","",$2->linha,$2->coluna);AST_addSon($$,$1);AST_addBrother($1,$3);}
    | ExprAux MINUS ExprAux                                 {$$ = AST_newNode("Sub","",$2->linha,$2->coluna);AST_addSon($$,$1);AST_addBrother($1,$3);}
    | ExprAux STAR ExprAux                                  {$$ = AST_newNode("Mul","",$2->linha,$2->coluna);AST_addSon($$,$1);AST_addBrother($1,$3);}
    | ExprAux DIV ExprAux                                   {$$ = AST_newNode("Div","",$2->linha,$2->coluna);AST_addSon($$,$1);AST_addBrother($1,$3);}
    | ExprAux MOD ExprAux                                   {$$ = AST_newNode("Mod","",$2->linha,$2->coluna);AST_addSon($$,$1);AST_addBrother($1,$3);}
    | ExprAux OR ExprAux                                    {$$ = AST_newNode("Or","",$2->linha,$2->coluna);AST_addSon($$,$1);AST_addBrother($1,$3);}
    | ExprAux XOR ExprAux                                   {$$ = AST_newNode("Xor","",$2->linha,$2->coluna);AST_addSon($$,$1);AST_addBrother($1,$3);}
    | ExprAux AND ExprAux                                   {$$ = AST_newNode("And","",$2->linha,$2->coluna);AST_addSon($$,$1);AST_addBrother($1,$3);}
    | ExprAux LSHIFT ExprAux                                {$$ = AST_newNode("Lshift","",0,0);AST_addSon($$,$1);AST_addBrother($1,$3);}
    | ExprAux RSHIFT ExprAux                                {$$ = AST_newNode("Rshift","",0,0);AST_addSon($$,$1);AST_addBrother($1,$3);}
    | ExprAux EQ ExprAux                                    {$$ = AST_newNode("Eq","",$2->linha,$2->coluna);AST_addSon($$,$1);AST_addBrother($1,$3);}
    | ExprAux NE ExprAux                                    {$$ = AST_newNode("Ne","",$2->linha,$2->coluna);AST_addSon($$,$1);AST_addBrother($1,$3);}
    | ExprAux LT ExprAux                                    {$$ = AST_newNode("Lt","",$2->linha,$2->coluna);AST_addSon($$,$1);AST_addBrother($1,$3);}
    | ExprAux GT ExprAux                                    {$$ = AST_newNode("Gt","",$2->linha,$2->coluna);AST_addSon($$,$1);AST_addBrother($1,$3);}
    | ExprAux LE ExprAux                                    {$$ = AST_newNode("Le","",$2->linha,$2->coluna);AST_addSon($$,$1);AST_addBrother($1,$3);}
    | ExprAux GE ExprAux                                    {$$ = AST_newNode("Ge","",$2->linha,$2->coluna);AST_addSon($$,$1);AST_addBrother($1,$3);}
    | MINUS ExprAux %prec NOT                               {$1->name = "Minus"; $$ = AST_newNode("Minus","",0,0);AST_addSon($$,$2);}
    | NOT ExprAux                                           {$$ = AST_newNode("Not","",0,0);AST_addSon($$,$2);}
    | PLUS ExprAux  %prec NOT                               {$1->name = "Plus" ; $$ = AST_newNode("Plus","",0,0);AST_addSon($$,$2);}
    | LPAR Expr RPAR                                        {$$ = $2;}
    | ID                                                    {$$ = AST_newNode("Id",$1->name,$1->linha,$1->coluna);}
    | ID DOTLENGTH                                          {$$ = AST_newNode("Length","",0,0);AST_addSon($$,AST_newNode("Id",$1->name,$1->linha,$1->coluna));}
    | INTLIT                                                {$$ = AST_newNode("DecLit",$1->name,$1->linha,$1->coluna);}
    | REALLIT                                               {$$ = AST_newNode("RealLit",$1->name,$1->linha,$1->coluna);}
    | BOOLLIT                                               {$$ = AST_newNode("BoolLit",$1->name,$1->linha,$1->coluna);}
    | MethodInvocation                                      {$$ = $1;}
    | ParseArgs                                             {$$ = $1;}
    | LPAR error RPAR                                       {$$ = NULL;print_tree=0;}
    

%%



int main(int argc, char *argv[]){
	if(strcmp(argv[1],"-e1") == 0){
        /* Analise Lexical : Mostra so os erros */
		flag=0;
        yylex();
    }else if(strcmp(argv[1],"-l") == 0){
        /* Analise Lexical : Mostra os erros e os tokens */
        flag=1;
        yylex();
    }
    if(strcmp(argv[1],"-e2") == 0){
        /* Analise Sintatica : Mostra so os erros */
        flag=2;
        yyparse();
    }
    else if(strcmp(argv[1],"-t") == 0){
        /* Analise Sintatica : Mostra os erros e a arvore */
        flag=2;
        yyparse();
        if(print_tree == 1){
            AST_print(root,0);
        }
    }
    if(strcmp(argv[1],"-s") == 0){
        flag=2;
        yyparse();
        check_program(root);
        printSymbolTable();
        if(print_tree == 1){
            AST_print(root,0);
        }
    }

    AST_free(root);
    return 0;
}

