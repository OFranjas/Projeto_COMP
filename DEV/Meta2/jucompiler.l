/* Autores */
/* Gonçalo Gameiro Neves number: 2020239361 */
/* Gonçalo Franja Ferreira number 2020226867 */



%{
    #include "y.tab.h"
    int coluna = 1;
    int linha_aux = 0;
    int coluna_aux = 0;
    int linha_aux_2 = 0;
    char buffer[1024];

    int flag = 1;
    int error = 0;

%}

ID  ([A-Za-z]|[_$])([0-9]|[_$]|[A-Za-z])*
digitos  [0-9]+
nonzeros [1-9]
expoentes   ((E|e)[+-]?{digitos}([0-9]|_)*)
reservadas "switch"|"assert"|"default"|"package"|"finally"|"float"|"implements"|"import"|"instanceof"|"interface"|"long"|"native"|"new"|"synchronized"|"do"|"goto"|"private"|"break"|"++"|"--"|"null"|"Integer"|"System"|"for"|"abstract"|"continue"|"byte"|"case"|"catch"|"char"|"const"|"enum"|"extends"|"final"|"protected"|"short"|"strictfp"|"transient"|"try"|"volatile"|"super"|"this"|"throw"|"throws"
REALLIT (({digitos}*("_"*{digitos})+"."?{expoentes})|({digitos}"."{digitos}?{expoentes}?)|("."{digitos}{expoentes}?)|({digitos}{expoentes})|({digitos}*("_"*{digitos}){expoentes}))|(({digitos}*("_"*{digitos})*"."("_"*{digitos})+({expoentes})?)|({digitos}*("_"*{digitos})+"."))                      
INTLIT {nonzeros}(("_"|{digitos})*{digitos})?|"0"
SPACE " "
NEWLINE "\n"|"\r"|"\r\n"

%X COMMENT STRLIT SINGLE_LINE_COMMENT

%%  

{reservadas}                {if(flag == 1){printf("RESERVED(%s)\n", yytext);}else if(flag == 2){return RESERVED;}coluna += yyleng;}

"true"|"false"              {if(flag == 1){printf("BOOLLIT(%s)\n", yytext);}coluna += yyleng;return(BOOLLIT);}
"&&"                        {if(flag == 1){printf("AND\n");}coluna += yyleng;return(AND);}
"="                         {if(flag == 1){printf("ASSIGN\n");}coluna += yyleng;return(ASSIGN);}
"*"                         {if(flag == 1){printf("STAR\n");}coluna += yyleng;return(STAR);}
","                         {if(flag == 1){printf("COMMA\n");}coluna += yyleng;return(COMMA);}
"/"                         {if(flag == 1){printf("DIV\n");}coluna += yyleng;return(DIV);}
"=="                        {if(flag == 1){printf("EQ\n");}coluna += yyleng;return(EQ);}
">="                        {if(flag == 1){printf("GE\n");}coluna += yyleng;return(GE);}
">"                         {if(flag == 1){printf("GT\n");}coluna += yyleng;return(GT);}
"{"                         {if(flag == 1){printf("LBRACE\n");}coluna += yyleng;return(LBRACE);}
"<="                        {if(flag == 1){printf("LE\n");}coluna += yyleng;return(LE);}
"("                         {if(flag == 1){printf("LPAR\n");}coluna += yyleng;return(LPAR);}
"["                         {if(flag == 1){printf("LSQ\n");}coluna += yyleng;return(LSQ);}
"<"                         {if(flag == 1){printf("LT\n");}coluna += yyleng;return(LT);}
"-"                         {if(flag == 1){printf("MINUS\n");}coluna += yyleng;return(MINUS);}
"%"                         {if(flag == 1){printf("MOD\n");}coluna += yyleng;return(MOD);}
"!="                        {if(flag == 1){printf("NE\n");}coluna += yyleng;return(NE);}
"!"                         {if(flag == 1){printf("NOT\n");}coluna += yyleng;return(NOT);}
"||"                        {if(flag == 1){printf("OR\n");}coluna += yyleng;return(OR);}
"+"                         {if(flag == 1){printf("PLUS\n");}coluna += yyleng;return(PLUS);}
"}"                         {if(flag == 1){printf("RBRACE\n");}coluna += yyleng;return(RBRACE);}
")"                         {if(flag == 1){printf("RPAR\n");}coluna += yyleng;return(RPAR);}
"]"                         {if(flag == 1){printf("RSQ\n");}coluna += yyleng;return(RSQ);}
";"                         {if(flag == 1){printf("SEMICOLON\n");}coluna += yyleng;return(SEMICOLON);}
"->"                        {if(flag == 1){printf("ARROW\n");}coluna += yyleng;return(ARROW);}
"<<"                        {if(flag == 1){printf("LSHIFT\n");}coluna += yyleng;return(LSHIFT);}
">>"                        {if(flag == 1){printf("RSHIFT\n");}coluna += yyleng;return(RSHIFT);}
"^"                         {if(flag == 1){printf("XOR\n");}coluna += yyleng;return(XOR);}
"boolean"                   {if(flag == 1){printf("BOOL\n");}coluna += yyleng;return(BOOL);}
"class"                     {if(flag == 1){printf("CLASS\n");}coluna += yyleng;return(CLASS);}
".length"                   {if(flag == 1){printf("DOTLENGTH\n");}coluna += yyleng;return(DOTLENGTH);}
"double"                    {if(flag == 1){printf("DOUBLE\n");}coluna += yyleng;return(DOUBLE);}
"else"                      {if(flag == 1){printf("ELSE\n");}coluna += yyleng;return(ELSE);}
"if"                        {if(flag == 1){printf("IF\n");}coluna += yyleng;return(IF);}
"int"                       {if(flag == 1){printf("INT\n");}coluna += yyleng;return(INT);}
"System.out.print"          {if(flag == 1){printf("PRINT\n");}coluna += yyleng;return(PRINT);}
"Integer.parseInt"          {if(flag == 1){printf("PARSEINT\n");}coluna += yyleng;return(PARSEINT);}
"public"                    {if(flag == 1){printf("PUBLIC\n");}coluna += yyleng;return(PUBLIC);}
"return"                    {if(flag == 1){printf("RETURN\n");}coluna += yyleng;return(RETURN);}
"static"                    {if(flag == 1){printf("STATIC\n");}coluna += yyleng;return(STATIC);}
"String"                    {if(flag == 1){printf("STRING\n");}coluna += yyleng;return(STRING);}
"void"                      {if(flag == 1){printf("VOID\n");}coluna += yyleng;return(VOID);}
"while"                     {if(flag == 1){printf("WHILE\n");}coluna += yyleng;return(WHILE);}


{ID}                        {if(flag == 1){printf("ID(%s)\n", yytext);}coluna += yyleng;return(ID);}

{REALLIT}                   {if(flag == 1){printf("REALLIT(%s)\n", yytext);}coluna += yyleng;return(REALLIT);}

{INTLIT}                    {if(flag == 1){printf("INTLIT(%s)\n", yytext);}coluna += yyleng;return(INTLIT);}             


"//"                           {BEGIN SINGLE_LINE_COMMENT;coluna = 1;yylineno++;}
<SINGLE_LINE_COMMENT>{NEWLINE} {BEGIN 0;}
<SINGLE_LINE_COMMENT><<EOF>>   {BEGIN 0;}
<SINGLE_LINE_COMMENT>.         ;



"/""*"                      {linha_aux = yylineno;coluna_aux=coluna;linha_aux_2 = 0;coluna += 2;BEGIN(COMMENT);}
<COMMENT><<EOF>>            {yylineno += linha_aux_2; printf("Line %d, col %d: unterminated comment\n", linha_aux, coluna_aux); BEGIN(0);coluna += yyleng;}
<COMMENT>"*""/"             {BEGIN(0); yylineno += linha_aux_2; coluna+=2;}
<COMMENT>{NEWLINE}          {linha_aux_2++;coluna = 1;}
<COMMENT>.                  {coluna += yyleng;}

\"                          {coluna_aux = coluna; coluna += 1; linha_aux=yylineno; BEGIN STRLIT; buffer[0] = '\0'; error = 0;}
<STRLIT>[^\\"\r\n]*           {coluna+=yyleng; strcat(buffer, yytext);}
<STRLIT>\\f                 {coluna+=yyleng; strcat(buffer, yytext);}
<STRLIT>\\n                 {coluna+=yyleng; strcat(buffer, yytext);}
<STRLIT>\\t                 {coluna+=yyleng; strcat(buffer, yytext);}
<STRLIT>\\r                 {coluna+=yyleng; strcat(buffer, yytext);}
<STRLIT>\\[\\"]             {coluna+=yyleng; strcat(buffer, yytext);}
<STRLIT>\"                  {coluna+=yyleng; BEGIN 0;
                             if (error!=1){if(flag==1){printf("STRLIT(\"%s\")\n", buffer);}}}
<STRLIT>\\.|\\              {error=1; if (yytext[1] != '\r') {printf("Line %d, col %d: invalid escape sequence (%s)\n", yylineno, coluna, yytext); coluna+=yyleng;} else {printf("Line %d, col %d: invalid escape sequence (\\)\n", yylineno, coluna); coluna+=yyleng;}}
<STRLIT>{NEWLINE}                  {error=1; printf("Line %d, col %d: unterminated string literal\n", linha_aux, coluna_aux); yylineno++; coluna=1; coluna_aux=0; BEGIN 0;}
<STRLIT><<EOF>>             {error=1; printf("Line %d, col %d: unterminated string literal\n", linha_aux, coluna_aux); yylineno++; coluna=1; coluna_aux=0; BEGIN 0;}

"\f"|"\t"                             {coluna += yyleng;}
{SPACE}                               {coluna += yyleng;}
{NEWLINE}                             {yylineno++;coluna = 1;}
.                                     {printf("Line %d, col %d: illegal character (%s)\n",yylineno,coluna, yytext);coluna += yyleng;}


%%

int main(int argc, char *argv[]){
    if(argc > 1){
		if(strcmp(argv[1],"-e1") == 0){
            /* Analise Lexical : Mostra so os erros */
			flag=0;
            yylex();
		}else if(strcmp(argv[1],"-l") == 0){
            /* Analise Lexical : Mostra tudo */
            flag=1;
            yylex();
        }else if(strcmp(argv[1],"-e2") == 0){
            /* Analise Lexical & Sintatica : Mostra so os erros */
            flag = 2;
            yyparse();  
	}else{
            /* Analise Lexical & Sintatica : Mostra tudo */
            flag = 2;
            yyparse();
        }
    }else{
            /* Analise Lexical & Sintatica : Mostra tudo */
            flag = 2;
            yyparse();
        }   
    return 0;
}

int yywrap() {
    return 1;
}

void yyerror(char *s) {
    printf("Line %d, col %d: %s %s\n", yylineno, coluna, s, yytext);
}