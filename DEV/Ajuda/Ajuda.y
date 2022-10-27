%{
	/*
	João Pedro Costa Ferreiro 2014197760
	Guilherme Cardoso Gomes da Silva 2014226354
	*/
	#include <stdio.h>
	#include <stdio.h>
	#include <string.h>
	#include "arvore.h"

	AST_struct root = NULL, aux = NULL, aux2 = NULL;
	int flag = 0, print_flag = 0;
	char* type_spec;
%}

%union{
	char* string;
	struct AST* ast;
}

%token CHAR ELSE WHILE IF SHORT INT DOUBLE RETURN VOID BITWISEOR BITWISEAND BITWISEXOR AND ASSIGN MUL COMMA DIV EQ GE GT LBRACE LE LPAR LT MINUS MOD NE NOT OR PLUS RBRACE RPAR SEMI
%token <string> REALLIT CHRLIT INTLIT ID RESERVED

%type <ast> Program FunctionsAndDeclarations FunctionDefinition FunctionBody DeclarationAndStatements FunctionDeclaration FunctionDeclarator ParameterList ParameterDeclaration Declaration DeclarationAux TypeSpec Declarator Statement StatementAux StatementError Expr ParameterListAux Expr2

%left COMMA
%right ASSIGN
%left OR
%left AND
%left BITWISEOR
%left BITWISEXOR
%left BITWISEAND
%left EQ NE
%left GE GT LT LE
%left PLUS MINUS 
%left MOD DIV MUL
%left SIGNAL
%right NOT
%left LPAR
%nonassoc ELSE_PRIORITY
%nonassoc ELSE

%%

Program:
	FunctionsAndDeclarations 								{
																root = cria_no("Program","");
																adicionar_filho(root,$1);
																$$ = root;
															}
		;

FunctionsAndDeclarations: 
	FunctionsAndDeclarations FunctionDefinition				{
																adicionar_irmao($1,$2);
																$$ = $1;
															}
	| FunctionsAndDeclarations FunctionDeclaration 			{
																adicionar_irmao($1,$2);
																$$ = $1;
															}
	| FunctionsAndDeclarations Declaration 					{
																adicionar_irmao($1,$2);
																$$ = $1;
															}
	| FunctionDefinition 									{
																$$ = $1;
															}
	| FunctionDeclaration 									{
																$$ = $1;
															}
	| Declaration 											{
																$$ = $1;
															}
	;

FunctionDefinition: 
	TypeSpec FunctionDeclarator FunctionBody 				{
																$$ = cria_no("FuncDefinition","");
																adicionar_filho($$,$1);
																adicionar_irmao($1,$2);
																adicionar_irmao($2,$3);
															}
	;

FunctionBody: 
	LBRACE RBRACE											{
																$$ = cria_no("FuncBody","");
															}
	| LBRACE DeclarationAndStatements RBRACE 				{
																$$ = cria_no("FuncBody","");
																adicionar_filho($$,$2);
															}
	;

DeclarationAndStatements: 
	DeclarationAndStatements Statement 						{
																adicionar_irmao($1,$2);
																$$ = $1;
															}
	| DeclarationAndStatements Declaration 					{
																adicionar_irmao($1,$2);
																$$ = $1;
															}
	| Statement 											{
																$$ = $1;
															}
	| Declaration 											{
																$$ = $1;
															}
		;

FunctionDeclaration: 
	TypeSpec FunctionDeclarator SEMI 						{
																$$ = cria_no("FuncDeclaration","");
																adicionar_filho($$,$1);
																adicionar_irmao($1,$2);
															}
	;

FunctionDeclarator: 
	ID LPAR ParameterList RPAR 								{
																$$ = cria_no("Id",$1);
																adicionar_irmao($$,$3);
															}
	;

ParameterList: 
	ParameterDeclaration ParameterListAux					{
																$$ = cria_no("ParamList","");
																adicionar_filho($$,$1);
																adicionar_irmao($1,$2);
															}
	;

	ParameterListAux:
															{
																$$ = NULL;
															}
	| COMMA ParameterDeclaration ParameterListAux			{
																adicionar_filho($$,$2);
																adicionar_irmao($2,$3);
																$$ = $2;
															}
	;

ParameterDeclaration: 
	TypeSpec 												{
																$$ = cria_no("ParamDeclaration","");
																adicionar_filho($$,$1);
															}
	| TypeSpec ID 											{
																$$ = cria_no("ParamDeclaration","");
																aux = cria_no("Id",$2);
																adicionar_filho($$,$1);
																adicionar_irmao($1,aux);

															}
	;

Declaration: 
	TypeSpec Declarator DeclarationAux SEMI 				{
																$$ = cria_no("Declaration","");
																adicionar_filho($$,$1);
																adicionar_irmao($1,$2);
																adicionar_irmao($$,$3);
															}
	| error SEMI											{
																print_flag = 1;
																$$ = NULL;
															}
	;

DeclarationAux:
															{
																$$ = NULL;
															}
	| COMMA Declarator DeclarationAux 						{
																$$ = cria_no("Declaration","");
																aux = cria_no(type_spec,"");
																adicionar_filho($$,aux);
																adicionar_irmao(aux,$2);
																adicionar_irmao($$,$3);
															}
	;

TypeSpec:
	CHAR 													{
																$$ = cria_no("Char","");
																type_spec = $$->tipo;
															}
	| INT 													{
																$$ = cria_no("Int","");
																type_spec = $$->tipo;
															}
	| VOID 													{
																$$ = cria_no("Void","");
																type_spec = $$->tipo;
															}
	| SHORT 												{
																$$ = cria_no("Short","");
																type_spec = $$->tipo;
															}
	| DOUBLE 												{
																$$ = cria_no("Double","");
																type_spec = $$->tipo;
															}
	;

Declarator:
	ID 														{
																$$ = cria_no("Id",$1);
															}
	| ID ASSIGN Expr 										{
																$$ = cria_no("Id",$1);
																adicionar_irmao($$,$3);
															}
	;
StatementAux:
	StatementError 											{
																$$ = $1;
															}
	| StatementError StatementAux 							{
																adicionar_irmao($1,$2);
																if($1!=NULL)
																	$$ = $1;
																else
																	$$ = $2;
															}
	;

StatementError:
	Statement 												{
																$$ = $1;
															}	
	| error SEMI											{
																print_flag = 1;
																$$ = NULL;
															}
	;

Statement:
	SEMI 													{
																$$ = NULL;
															}
	| Expr SEMI												{
																$$ = $1;
															}
	| LBRACE RBRACE											{
																$$ = NULL;
															}
	| LBRACE StatementAux RBRACE 							{
																if($2!=NULL && $2->irmao!=NULL){
																	$$ = cria_no("StatList","");
																	adicionar_filho($$,$2);
																}
																else if($2!=NULL && $2->irmao==NULL){
																	$$ = $2;
																}
																else $$ = NULL;
															}

	| IF LPAR Expr RPAR StatementError %prec ELSE_PRIORITY 	{
																$$ = cria_no("If","");
																aux2 = $3;
																adicionar_filho($$,aux2);
																if($5 != NULL){
																	adicionar_irmao(aux2,$5);
																}
																else{
																	aux = cria_no("Null","");
																	adicionar_irmao(aux2,aux);
																}
																aux = cria_no("Null","");
																adicionar_irmao(aux2,aux);
															}
	| IF LPAR Expr RPAR StatementError ELSE StatementError 	{
																$$ = cria_no("If","");
																aux2 = $3;
																adicionar_filho($$,aux2);
																if($5 != NULL){
																	adicionar_irmao(aux2,$5);
																}
																else{
																	aux = cria_no("Null","");
																	adicionar_irmao(aux2,aux);
																}
																if($7!= NULL){
																	adicionar_irmao(aux2,$7);
																}
																else{
																	aux = cria_no("Null","");
																	adicionar_irmao(aux2,aux);
																}
															}
	| WHILE LPAR Expr RPAR StatementError					{
																$$ = cria_no("While","");
																aux2 = $3;
																adicionar_filho($$,aux2);
																if($5 != NULL){
																	adicionar_irmao(aux2,$5);
																}
																else{
																	aux = cria_no("Null","");
																	adicionar_irmao(aux2,aux);
																}
															}
	| RETURN Expr SEMI 										{
																$$ = cria_no("Return","");
																adicionar_filho($$,$2);
															}
	| RETURN SEMI 											{
																$$ = cria_no("Return","");
																aux = cria_no("Null","");
																adicionar_filho($$,aux);
															}
	| LBRACE error RBRACE 									{
																$$ = NULL;
																print_flag = 1;
															}
	;

Expr:
	Expr ASSIGN Expr 										{
																$$ = cria_no("Store","");
																adicionar_filho($$,$1);
																adicionar_irmao($1,$3);
															}
	| Expr COMMA Expr 										{
																$$ = cria_no("Comma","");
																adicionar_filho($$,$1);
																adicionar_irmao($1,$3);
															}
	| Expr EQ Expr 											{
																$$ = cria_no("Eq","");
																adicionar_filho($$,$1);
																adicionar_irmao($1,$3);
															}
	| Expr NE Expr 											{
																$$ = cria_no("Ne","");
																adicionar_filho($$,$1);
																adicionar_irmao($1,$3);
															}
	| Expr LE Expr 											{
																$$ = cria_no("Le","");
																adicionar_filho($$,$1);
																adicionar_irmao($1,$3);
															}
	| Expr GE Expr 											{
																$$ = cria_no("Ge","");
																adicionar_filho($$,$1);
																adicionar_irmao($1,$3);
															}
	| Expr LT Expr 											{
																$$ = cria_no("Lt","");
																adicionar_filho($$,$1);
																adicionar_irmao($1,$3);
															}
	| Expr GT Expr 											{
																$$ = cria_no("Gt","");
																adicionar_filho($$,$1);
																adicionar_irmao($1,$3);
															}
	| Expr PLUS Expr 										{
																$$ = cria_no("Add","");
																adicionar_filho($$,$1);
																adicionar_irmao($1,$3);
															}
	| Expr MINUS Expr 										{
																$$ = cria_no("Sub","");
																adicionar_filho($$,$1);
																adicionar_irmao($1,$3);
															}
	| Expr MUL Expr 										{
																$$ = cria_no("Mul","");
																adicionar_filho($$,$1);
																adicionar_irmao($1,$3);
															}
	| Expr DIV Expr 										{
																$$ = cria_no("Div","");
																adicionar_filho($$,$1);
																adicionar_irmao($1,$3);
															}
	| Expr MOD Expr 										{
																$$ = cria_no("Mod","");
																adicionar_filho($$,$1);
																adicionar_irmao($1,$3);
															}
	| Expr OR Expr 											{
																$$ = cria_no("Or","");
																adicionar_filho($$,$1);
																adicionar_irmao($1,$3);
															}
	| Expr AND Expr 										{
																$$ = cria_no("And","");
																adicionar_filho($$,$1);
																adicionar_irmao($1,$3);
															}
	| Expr BITWISEAND Expr 									{
																$$ = cria_no("BitWiseAnd","");
																adicionar_filho($$,$1);
																adicionar_irmao($1,$3);
															}
	| Expr BITWISEOR Expr 									{
																$$ = cria_no("BitWiseOr","");
																adicionar_filho($$,$1);
																adicionar_irmao($1,$3);
															}
	| Expr BITWISEXOR Expr 									{
																$$ = cria_no("BitWiseXor","");
																adicionar_filho($$,$1);
																adicionar_irmao($1,$3);
															}
	| PLUS Expr %prec SIGNAL								{
																$$ = cria_no("Plus","");
																adicionar_filho($$,$2);
															}
	| MINUS Expr %prec SIGNAL								{
																$$ = cria_no("Minus","");
																adicionar_filho($$,$2);
															}
	| NOT Expr 												{
																$$ = cria_no("Not","");
																adicionar_filho($$,$2);
															}
	| ID LPAR RPAR 											{
																$$ = cria_no("Call","");
																aux = cria_no("Id",$1);
																adicionar_filho($$,aux);
															}
	| ID LPAR Expr2 RPAR 									{
																$$ = cria_no("Call","");
																aux = cria_no("Id",$1);
																aux2 = $3;
																adicionar_filho($$,aux);
																adicionar_irmao(aux,$3);
															}
	| ID 													{
																$$ = cria_no("Id",$1);
															}
	| INTLIT 												{
																$$ = cria_no("IntLit",$1);
															}
	| CHRLIT 												{
																$$ = cria_no("ChrLit",$1);
															}
	| REALLIT 												{
																$$ = cria_no("RealLit",$1);
															}
	| LPAR Expr RPAR 										{
																$$ = $2;
															}

	| ID LPAR error RPAR 									{
																$$ = NULL;
																print_flag = 1;
															}
	| LPAR error RPAR 										{
																$$ = NULL;
																print_flag = 1;
															}
	;

Expr2:
	Expr2 ASSIGN Expr2 										{
																$$ = cria_no("Store","");
																adicionar_filho($$,$1);
																adicionar_irmao($1,$3);
															}
	| Expr2 COMMA Expr 										{
																$$ = $1;
																adicionar_irmao($1,$3);
															}
	| Expr2 EQ Expr2 										{
																$$ = cria_no("Eq","");
																adicionar_filho($$,$1);
																adicionar_irmao($1,$3);
															}
	| Expr2 NE Expr2 										{
																$$ = cria_no("Ne","");
																adicionar_filho($$,$1);
																adicionar_irmao($1,$3);
															}
	| Expr2 LE Expr2 										{
																$$ = cria_no("Le","");
																adicionar_filho($$,$1);
																adicionar_irmao($1,$3);
															}
	| Expr2 GE Expr2 										{
																$$ = cria_no("Ge","");
																adicionar_filho($$,$1);
																adicionar_irmao($1,$3);
															}
	| Expr2 LT Expr2 										{
																$$ = cria_no("Lt","");
																adicionar_filho($$,$1);
																adicionar_irmao($1,$3);
															}
	| Expr2 GT Expr2 										{
																$$ = cria_no("Gt","");
																adicionar_filho($$,$1);
																adicionar_irmao($1,$3);
															}
	| Expr2 PLUS Expr2 										{
																$$ = cria_no("Add","");
																adicionar_filho($$,$1);
																adicionar_irmao($1,$3);
															}
	| Expr2 MINUS Expr2 									{
																$$ = cria_no("Sub","");
																adicionar_filho($$,$1);
																adicionar_irmao($1,$3);
															}
	| Expr2 MUL Expr2 										{
																$$ = cria_no("Mul","");
																adicionar_filho($$,$1);
																adicionar_irmao($1,$3);
															}
	| Expr2 DIV Expr2 										{
																$$ = cria_no("Div","");
																adicionar_filho($$,$1);
																adicionar_irmao($1,$3);
															}
	| Expr2 MOD Expr2 										{
																$$ = cria_no("Mod","");
																adicionar_filho($$,$1);
																adicionar_irmao($1,$3);
															}
	| Expr2 OR Expr2 										{
																$$ = cria_no("Or","");
																adicionar_filho($$,$1);
																adicionar_irmao($1,$3);
															}
	| Expr2 AND Expr2 										{
																$$ = cria_no("And","");
																adicionar_filho($$,$1);
																adicionar_irmao($1,$3);
															}
	| Expr2 BITWISEAND Expr2 								{
																$$ = cria_no("BitWiseAnd","");
																adicionar_filho($$,$1);
																adicionar_irmao($1,$3);
															}
	| Expr2 BITWISEOR Expr2 								{
																$$ = cria_no("BitWiseOr","");
																adicionar_filho($$,$1);
																adicionar_irmao($1,$3);
															}
	| Expr2 BITWISEXOR Expr2 								{
																$$ = cria_no("BitWiseXor","");
																adicionar_filho($$,$1);
																adicionar_irmao($1,$3);
															}

	| PLUS Expr2 %prec SIGNAL								{
																$$ = cria_no("Plus","");
																adicionar_filho($$,$2);
															}
	| MINUS Expr2 %prec SIGNAL								{
																$$ = cria_no("Minus","");
																adicionar_filho($$,$2);
															}
	| NOT Expr2 											{
																$$ = cria_no("Not","");
																adicionar_filho($$,$2);
															}
	| ID LPAR RPAR 											{
																$$ = cria_no("Call","");
																aux = cria_no("Id",$1);
																adicionar_filho($$,aux);
															}
	| ID LPAR Expr2 RPAR 									{
																$$ = cria_no("Call","");
																aux = cria_no("Id",$1);
																adicionar_filho($$,aux);
																adicionar_irmao(aux,$3);
															}
	| ID 													{
																$$ = cria_no("Id",$1);
															}
	| INTLIT 												{
																$$ = cria_no("IntLit",$1);
															}
	| CHRLIT 												{
																$$ = cria_no("ChrLit",$1);
															}
	| REALLIT 												{
																$$ = cria_no("RealLit",$1);
															}
	| LPAR Expr RPAR 										{
																$$ = $2;
															}
	| ID LPAR error RPAR 									{
																$$ = NULL;
																print_flag = 1;
															}
	| LPAR error RPAR 										{
																$$ = NULL;
																print_flag = 1;
															}
	;

%%


int main(int argc, char *argv[]){
	if(argc > 1){
		if(strcmp(argv[1],"-l") == 0){
			flag=1;
			yylex();
		}
		if(strcmp(argv[1],"-t") == 0){
			flag=2;
			yyparse();
			yylex_destroy();
			if(!print_flag)
				imprime_arvore(root,0);

		}
	}
	else{
		flag=2;
		yyparse();
		yylex_destroy();
		return 0;
	}
}