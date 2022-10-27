%{
	/*
	João Pedro Costa Ferreiro 2014197760
	Guilherme Cardoso Gomes da Silva 2014226354
	*/
	#include <stdio.h>
	#include <string.h>
	#include "arvore.h"
	#include "y.tab.h"

	void imprime(char* msg);
	void imprime_com_conteudo(char* msg, char* conteudo);

	#define LINHA linha++; coluna=1;
	#define COLUNA coluna+=yyleng;

	int flag, coluna = 1, linha = 1, linha_aux = 0, coluna_aux = 0;
%}

%X MULTIPCOM_ST

SINGLECOMMENT					"//"
STARTCOMMENT 					"/*"
FINISHCOMMENT 					"*/"

RESERVED						"++"|"--"|"["|"]"|"auto"|"break"|"case"|"const"|"continue"|"default"|"do"|"enum"|"extern"|"float"|"for"|"goto"|"inline"|"long"|"register"|"restrict"|"signed"|"sizeof"|"static"|"struct"|"switch"|"typedef"|"union"|"unsigned"|"volatile"|"_Bool"|"_Complex"|"_Imaginary"

CHAR 							"char"
ELSE 							"else"
WHILE 							"while"
IF 								"if"
INT 							"int"
SHORT 							"short"
DOUBLE							"double"
RETURN 							"return"
VOID 							"void"
BITWISEAND 						"&"
BITWISEOR 						"|"
BITWISEXOR 						"^"
AND 							"&&"
ASSIGN 							"="
MUL 							"*"
COMMA 							","
DIV 							"/"
EQ 								"=="
GE 								">="
GT 								">"
LBRACE 							"{"
LE 								"<="
LPAR 							"("
LT 								"<"
MINUS 							"-"
MOD 							"%"
NE 								"!="
NOT 							"!"
OR 								"||"
PLUS 							"+"
RBRACE 							"}"
RPAR 							")"
SEMI 							";"

ID								([a-zA-Z]|"_")([a-zA-Z0-9]|"_")*

DOT								"."
EXPONENTIAL						("E"|"e")("+"|"-")?{INTLIT}
ASP								"'"

INTLIT							[0-9]+
REALLIT							(({INTLIT}{DOT}{INTLIT}?{EXPONENTIAL}?)|({DOT}{INTLIT}{EXPONENTIAL}?)|({INTLIT}{EXPONENTIAL}))
CHRLIT							[^\n\'\\]|\\n|\\t|\\\\|\\'|\\\"|\\[0-7]{1,3}

SPACE							" "
NEWLINE							"\n"
TAB								"\t"
CARRIAGERETURN		 			"\r"
LINETERMINATOR					"\n"|"\r\n"

%%
{SINGLECOMMENT}.*				;

{STARTCOMMENT}					{BEGIN MULTIPCOM_ST; linha_aux = linha; coluna_aux = coluna; COLUNA;}
<MULTIPCOM_ST>.					{COLUNA;}
<MULTIPCOM_ST>{LINETERMINATOR}	{LINHA;}
<MULTIPCOM_ST><<EOF>>			{BEGIN 0;printf("Line %d, col %d: unterminated comment\n",linha_aux,coluna_aux);COLUNA;}
<MULTIPCOM_ST>{FINISHCOMMENT}	{BEGIN 0;COLUNA;}

{RESERVED}						{imprime_com_conteudo("RESERVED", yytext);COLUNA; return RESERVED;}

{CHAR} 							{imprime("CHAR"); COLUNA; if(flag==2) return CHAR;}
{ELSE} 							{imprime("ELSE"); COLUNA; if(flag==2) return ELSE;}
{WHILE} 						{imprime("WHILE"); COLUNA; if(flag==2) return WHILE;}
{IF} 							{imprime("IF"); COLUNA; if(flag==2) return IF;}
{INT}							{imprime("INT"); COLUNA; if(flag==2) return INT;}
{SHORT} 						{imprime("SHORT"); COLUNA; if(flag==2) return SHORT;}
{DOUBLE}						{imprime("DOUBLE"); COLUNA; if(flag==2) return DOUBLE;}
{RETURN} 						{imprime("RETURN"); COLUNA; if(flag==2) return RETURN;}
{VOID} 							{imprime("VOID"); COLUNA; if(flag==2) return VOID;}
{BITWISEAND} 					{imprime("BITWISEAND"); COLUNA; if(flag==2) return BITWISEAND;}
{BITWISEOR} 					{imprime("BITWISEOR"); COLUNA; if(flag==2) return BITWISEOR;}
{BITWISEXOR} 					{imprime("BITWISEXOR"); COLUNA; if(flag==2) return BITWISEXOR;}
{AND} 							{imprime("AND"); COLUNA; if(flag==2) return AND;}
{ASSIGN} 						{imprime("ASSIGN"); COLUNA; if(flag==2) return ASSIGN;}
{MUL} 							{imprime("MUL"); COLUNA; if(flag==2) return MUL;}
{COMMA} 						{imprime("COMMA"); COLUNA; if(flag==2) return COMMA;}
{DIV} 							{imprime("DIV"); COLUNA; if(flag==2) return DIV;}
{EQ} 							{imprime("EQ"); COLUNA; if(flag==2) return EQ;}
{GE} 							{imprime("GE"); COLUNA; if(flag==2) return GE;}
{GT} 							{imprime("GT"); COLUNA; if(flag==2) return GT;}
{LBRACE} 						{imprime("LBRACE"); COLUNA; if(flag==2) return LBRACE;}
{LE} 							{imprime("LE"); COLUNA; if(flag==2) return LE;}
{LPAR} 							{imprime("LPAR"); COLUNA; if(flag==2) return LPAR;}
{LT} 							{imprime("LT"); COLUNA; if(flag==2) return LT;}
{MINUS} 						{imprime("MINUS"); COLUNA; if(flag==2) return MINUS;}
{MOD} 							{imprime("MOD"); COLUNA; if(flag==2) return MOD;}
{NE} 							{imprime("NE"); COLUNA; if(flag==2) return NE;}
{NOT} 							{imprime("NOT"); COLUNA; if(flag==2) return NOT;}
{OR} 							{imprime("OR"); COLUNA; if(flag==2) return OR;}
{PLUS} 							{imprime("PLUS"); COLUNA; if(flag==2) return PLUS;}
{RBRACE} 						{imprime("RBRACE"); COLUNA; if(flag==2) return RBRACE;}
{RPAR} 							{imprime("RPAR"); COLUNA; if(flag==2) return RPAR;}
{SEMI} 							{imprime("SEMI"); COLUNA; if(flag==2) return SEMI;}

{ID}							{imprime_com_conteudo("ID", yytext);if(flag==2){yylval.string=(char*)strdup(yytext); COLUNA; return ID;}}

{INTLIT}						{imprime_com_conteudo("INTLIT",yytext);if(flag==2){yylval.string=(char*)strdup(yytext); COLUNA; return INTLIT;}}
{REALLIT}						{imprime_com_conteudo("REALLIT",yytext);if(flag==2){yylval.string=(char*)strdup(yytext); COLUNA; return REALLIT;}}
{ASP}{CHRLIT}{ASP}				{imprime_com_conteudo("CHRLIT",yytext);if(flag==2){yylval.string=(char*)strdup(yytext); COLUNA; return CHRLIT;}}
{ASP}({CHRLIT}|\\.)*{ASP} 		{printf("Line %d, col %d: invalid char constant (%s)\n",linha,coluna,yytext);if(flag==2){yylval.string=(char*)strdup(yytext); COLUNA; return CHRLIT;}}
{ASP}({CHRLIT}|\\.)*\\?			{printf("Line %d, col %d: unterminated char constant\n",linha,coluna);}

{SPACE}							{COLUNA;}
{NEWLINE}						{LINHA;}
{TAB}							{COLUNA;}
{CARRIAGERETURN}				{COLUNA;}
{LINETERMINATOR}				{LINHA;}

.								{printf("Line %d, col %d: illegal character (%s)\n",linha,coluna,yytext);COLUNA;}

%%

void imprime(char* msg){
	if(flag == 1){
		printf("%s\n",msg);
	}
}

void imprime_com_conteudo(char* msg, char* conteudo){
	if(flag == 1){
		printf("%s(%s)\n",msg,conteudo);
	}
}


int yywrap(){
	return 1;
}

void yyerror (const char *s) { 
	printf ("Line %d, col %d: %s: %s\n", linha, (int)(coluna-strlen(yytext)), s, yytext);
}