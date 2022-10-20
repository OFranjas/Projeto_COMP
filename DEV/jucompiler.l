%{
    int coluna = 1;
    int linha_aux = 0;
    int coluna_aux = 0;
    char buffer[1024];

    int flag = 1;

%}

ID  ([A-Za-z]|[_$])([0-9]|[_$]|[A-Za-z])*
digitos  [0-9]+
nonzeros [1-9]
expoentes   ((E|e)[+-]?{digitos}([0-9]|_)*)
reservadas "switch"|"assert"|"default"|"package"|"finally"|"float"|"implements"|"import"|"instanceof"|"interface"|"long"|"native"|"new"|"synchronized"|"do"|"goto"|"private"|"break"|"++"|"--"|"null"|"Integer"|"System"|"for"|"abstract"|"continue"|"byte"|"case"|"catch"|"char"|"const"|"enum"|"extends"|"final"|"protected"|"short"|"strictfp"|"transient"|"try"|"volatile"|"super"|"this"|"throw"|"throws"
REALLIT (({digitos}"."{digitos}?{expoentes}?)|("."{digitos}{expoentes}?)|({digitos}{expoentes}))|(({digitos}*("_"*{digitos})*"."("_"*{digitos})+({expoentes})?)|({digitos}*("_"*{digitos})+"."))                  
INTLIT {nonzeros}(("_"|{digitos})*{digitos})?|"0"
SPACE " "
NEWLINE "\n"|"\r"|"\r\n"

%X COMMENT STRLIT ERRO_STRLIT SINGLE_LINE_COMMENT

%%  

{reservadas}                {if(flag == 1){printf("RESERVED(%s)\n", yytext);}coluna += yyleng;}

"true"|"false"              {if(flag == 1){printf("BOOLLIT(%s)\n", yytext);}coluna += yyleng;}
"&&"                        {if(flag == 1){printf("AND\n");}coluna += yyleng;}
"="                         {if(flag == 1){printf("ASSIGN\n");}coluna += yyleng;}
"*"                         {if(flag == 1){printf("STAR\n");}coluna += yyleng;}
","                         {if(flag == 1){printf("COMMA\n");}coluna += yyleng;}
"/"                         {if(flag == 1){printf("DIV\n");}coluna += yyleng;}
"=="                        {if(flag == 1){printf("EQ\n");}coluna += yyleng;}
">="                        {if(flag == 1){printf("GE\n");}coluna += yyleng;}
">"                         {if(flag == 1){printf("GT\n");}coluna += yyleng;}
"{"                         {if(flag == 1){printf("LBRACE\n");}coluna += yyleng;}
"<="                        {if(flag == 1){printf("LE\n");}coluna += yyleng;}
"("                         {if(flag == 1){printf("LPAR\n");}coluna += yyleng;}
"["                         {if(flag == 1){printf("LSQ\n");}coluna += yyleng;}
"<"                         {if(flag == 1){printf("LT\n");}coluna += yyleng;}
"-"                         {if(flag == 1){printf("MINUS\n");}coluna += yyleng;}
"%"                         {if(flag == 1){printf("MOD\n");}coluna += yyleng;}
"!="                        {if(flag == 1){printf("NE\n");}coluna += yyleng;}
"!"                         {if(flag == 1){printf("NOT\n");}coluna += yyleng;}
"||"                        {if(flag == 1){printf("OR\n");}coluna += yyleng;}
"+"                         {if(flag == 1){printf("PLUS\n");}coluna += yyleng;}
"}"                         {if(flag == 1){printf("RBRACE\n");}coluna += yyleng;}
")"                         {if(flag == 1){printf("RPAR\n");}coluna += yyleng;}
"]"                         {if(flag == 1){printf("RSQ\n");}coluna += yyleng;}
";"                         {if(flag == 1){printf("SEMICOLON\n");}coluna += yyleng;}
"->"                        {if(flag == 1){printf("ARROW\n");}coluna += yyleng;}
"<<"                        {if(flag == 1){printf("LSHIFT\n");}coluna += yyleng;}
">>"                        {if(flag == 1){printf("RSHIFT\n");}coluna += yyleng;}
"^"                         {if(flag == 1){printf("XOR\n");}coluna += yyleng;}
"boolean"                   {if(flag == 1){printf("BOOL\n");}coluna += yyleng;}
"class"                     {if(flag == 1){printf("CLASS\n");}coluna += yyleng;}
".length"                   {if(flag == 1){printf("DOTLENGTH\n");}coluna += yyleng;}
"double"                    {if(flag == 1){printf("DOUBLE\n");}coluna += yyleng;}
"else"                      {if(flag == 1){printf("ELSE\n");}coluna += yyleng;}
"if"                        {if(flag == 1){printf("IF\n");}coluna += yyleng;}
"int"                       {if(flag == 1){printf("INT\n");}coluna += yyleng;}
"System.out.print"          {if(flag == 1){printf("PRINT\n");}coluna += yyleng;}
"Integer.parseInt"          {if(flag == 1){printf("PARSEINT\n");}coluna += yyleng;}
"public"                    {if(flag == 1){printf("PUBLIC\n");}coluna += yyleng;}
"return"                    {if(flag == 1){printf("RETURN\n");}coluna += yyleng;}
"static"                    {if(flag == 1){printf("STATIC\n");}coluna += yyleng;}
"String"                    {if(flag == 1){printf("STRING\n");}coluna += yyleng;}
"void"                      {if(flag == 1){printf("VOID\n");}coluna += yyleng;}
"while"                     {if(flag == 1){printf("WHILE\n");}coluna += yyleng;}


{ID}                        {if(flag == 1){printf("ID(%s)\n", yytext);}coluna += yyleng;}

{REALLIT}                   {if(flag == 1){printf("REALLIT(%s)\n", yytext);}coluna += yyleng;}

{INTLIT}                    {if(flag == 1){printf("INTLIT(%s)\n", yytext);}coluna += yyleng;}             


"//"                           {BEGIN SINGLE_LINE_COMMENT;coluna += yyleng;}
<SINGLE_LINE_COMMENT>"\r"|"\n" {BEGIN 0;coluna = 1; yylineno++;}
<SINGLE_LINE_COMMENT>.         {;coluna += yyleng;}



"/""*"                      {linha_aux = yylineno;coluna_aux=coluna;coluna += 2;BEGIN(COMMENT);}
<COMMENT>"*""/"             {BEGIN(0);coluna += yyleng;}
<COMMENT>"*"+[^*/\n]        {coluna += yyleng;}
<COMMENT>{NEWLINE}          {yylineno++;coluna = 1;}
<COMMENT><<EOF>>            {printf("Line %d, col %d: unterminated comment\n", linha_aux, coluna_aux); BEGIN(0);coluna += yyleng;}
<COMMENT>.                  {coluna += yyleng;}


"\""                                  {BEGIN(STRLIT);bzero(buffer,sizeof(buffer));linha_aux=yylineno;coluna_aux=coluna;coluna++;}

<STRLIT>"\""                          {if(flag == 1){printf("STRLIT(\"%s\")\n",buffer);}BEGIN(0);bzero(buffer,sizeof(buffer));coluna+=yyleng;}
<STRLIT>"\\"[^f|n|r|"\n"|"r\n"|t|"\\"|\"]  {if ((yytext[1] != '\r') && (yytext[1] != '\n')) {printf("Line %d, col %d: invalid escape sequence (%s)\n", yylineno, coluna, yytext);} else {printf("Line %d, col %d: invalid escape sequence (\\)\n", yylineno, coluna);}BEGIN ERRO_STRLIT;coluna+=yyleng;}
<STRLIT>"\\"["\\"|"\""]               {strcat(buffer,&yytext[0]);coluna+=yyleng;}
<STRLIT>"\\""\n"                      {printf("Line %d, col %d: invalid escape sequence (\\)\n", yylineno, coluna); printf("Line %d, col %d: unterminated string literal\n", linha_aux, coluna_aux);coluna = 1; yylineno++; bzero(buffer,sizeof(buffer)); BEGIN(0);}
<STRLIT>{NEWLINE}                     {printf("Line %d, col %d: unterminated string literal\n", linha_aux, coluna_aux); BEGIN(0);bzero(buffer,sizeof(buffer)); yylineno++; coluna = 1;}
<STRLIT><<EOF>>                       {printf("Line %d, col %d: unterminated string literal\n", linha_aux, coluna_aux); BEGIN(0);bzero(buffer,sizeof(buffer)); yylineno++; coluna = 1;}
<STRLIT>.                             {strcat(buffer,&yytext[0]);coluna+=yyleng;}


<ERRO_STRLIT>"\""                     {BEGIN (0);coluna+=yyleng;coluna+=yyleng;}
<ERRO_STRLIT>"\\"[^f|n|r|"\n"|("r\n")|t|("\\")|(\")]  {if ((yytext[1] != '\r') && (yytext[1] != '\n')) {printf("Line %d, col %d: invalid escape sequence (%s)\n", yylineno, coluna, yytext);} else {printf("Line %d, col %d: invalid escape sequence (\\)\n", yylineno, coluna);}BEGIN ERRO_STRLIT;coluna+=yyleng;}
<ERRO_STRLIT>"\\""\""                 {strcat(buffer,&yytext[0]);coluna+=yyleng;}
<ERRO_STRLIT>"\\"["\\"|"\""]          {strcat(buffer,&yytext[0]);coluna+=yyleng;}
<ERRO_STRLIT>"\n"|"\r\n"|"\r"|"\n\r"  {printf("Line %d, col %d: unterminated string literal\n", linha_aux, coluna_aux); BEGIN(0);bzero(buffer,sizeof(buffer)); yylineno++; coluna = 1;}
<ERRO_STRLIT>.                        {coluna+=yyleng;}
<ERRO_STRLIT><<EOF>>                  {printf("Line %d, col %d: unterminated string literal\n", linha_aux, coluna_aux); BEGIN(0);bzero(buffer,sizeof(buffer)); yylineno++; coluna = 1;}




"\f"|"\t"                             {coluna += yyleng;}
{SPACE}                               {coluna += yyleng;}
{NEWLINE}                             {yylineno++;coluna = 1;}
.                                     {printf("Line %d, col %d: illegal character (%s)\n",yylineno,coluna, yytext);coluna += yyleng;}


%%

int main(int argc, char *argv[]){
    if(argc > 1){
		if(strcmp(argv[1],"-e1") == 0){
			flag=0;
		}
	}   
    yylex();
    return 0;
}

int yywrap() {
    return 1;
}