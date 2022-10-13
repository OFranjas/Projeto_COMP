%{
    int linha = 1;
    int coluna = 1;
    int linha_aux = 0;
    int coluna_aux = 0;
    char buffer[1024];

%}

letras  ([A-Za-z]|[_$])([0-9]|[_$]|[A-Za-z])*
digitos  [0-9]+
nonzeros [1-9]
expoentes   ((E|e)[+-]?{digitos}([0-9]|_)*)
reservadas "switch"|"assert"|"default"|"package"|"finally"|"float"|"implements"|"import"|"instanceof"|"interface"|"long"|"native"|"new"|"synchronized"|"do"|"goto"|"private"|"break"|"++"|"--"|"null"|"Integer"|"System"|"for"|"abstract"|"continue"|"byte"|"case"|"catch"|"char"|"const"|"enum"|"extends"|"final"|"protected"|"short"|"strictfp"|"transient"|"try"|"volatile"|"super"|"this"|"throw"|"throws"
comment "//".*
erros   [.|?|#|&|:|\\|.|`|']
invalidos ("\r"|"\f"|"\n"|"\t"|"\0"|"\\"|"\"")
OCTAL                                   (0)[0-9]+
HEXA                                    (0x|0X)[a-fA-F0-9]+

%X COMMENT STRLIT ERRO_STRLIT

%%  
{comment}                   ;  


"true"|"false"              {printf("BOOLLIT(%s)\n", yytext);coluna += yyleng;}
"&&"                        {printf("AND\n");coluna += yyleng;}
"="                         {printf("ASSIGN\n");}coluna += yyleng;
"*"                         {printf("STAR\n");coluna += yyleng;}
","                         {printf("COMMA\n");coluna += yyleng;}
"/"                         {printf("DIV\n");coluna += yyleng;}
"=="                        {printf("EQ\n");coluna += yyleng;}
">="                        {printf("GE\n");coluna += yyleng;}
">"                         {printf("GT\n");coluna += yyleng;}
"{"                         {printf("LBRACE\n");coluna += yyleng;}
"<="                        {printf("LE\n");coluna += yyleng;}
"("                         {printf("LPAR\n");coluna += yyleng;}
"["                         {printf("LSQ\n");coluna += yyleng;}
"<"                         {printf("LT\n");coluna += yyleng;}
"-"                         {printf("MINUS\n");coluna += yyleng;}
"%"                         {printf("MOD\n");coluna += yyleng;}
"!="                        {printf("NE\n");coluna += yyleng;}
"!"                         {printf("NOT\n");coluna += yyleng;}
"||"                        {printf("OR\n");coluna += yyleng;}
"+"                         {printf("PLUS\n");coluna += yyleng;}
"}"                         {printf("RBRACE\n");coluna += yyleng;}
")"                         {printf("RPAR\n");coluna += yyleng;}
"]"                         {printf("RSQ\n");coluna += yyleng;}
";"                         {printf("SEMICOLON\n");coluna += yyleng;}
"->"                        {printf("ARROW\n");coluna += yyleng;}
"<<"                        {printf("LSHIFT\n");coluna += yyleng;}
">>"                        {printf("RSHIFT\n");coluna += yyleng;}
"^"                         {printf("XOR\n");coluna += yyleng;}
"boolean"                   {printf("BOOL\n");coluna += yyleng;}
"class"                     {printf("CLASS\n");coluna += yyleng;}
".length"                   {printf("DOTLENGTH\n");coluna += yyleng;}
"double"                    {printf("DOUBLE\n");coluna += yyleng;}
"else"                      {printf("ELSE\n");coluna += yyleng;}
"if"                        {printf("IF\n");coluna += yyleng;}
"int"                       {printf("INT\n");coluna += yyleng;}
"System.out.print"          {printf("PRINT\n");coluna += yyleng;}
"Integer.parseInt"          {printf("PARSEINT\n");coluna += yyleng;}
"public"                    {printf("PUBLIC\n");coluna += yyleng;}
"return"                    {printf("RETURN\n");coluna += yyleng;}
"static"                    {printf("STATIC\n");coluna += yyleng;}
"String"                    {printf("STRING\n");coluna += yyleng;}
"void"                      {printf("VOID\n");coluna += yyleng;}
"while"                     {printf("WHILE\n");coluna += yyleng;}
                    

"/""*"                      {linha_aux = linha;coluna_aux=coluna;coluna += 2;BEGIN(COMMENT);}
<COMMENT>"*""/"             {BEGIN(0);coluna += yyleng;}
<COMMENT>.                  {coluna += yyleng;}
<COMMENT>"*"+[^*/\n]        {coluna += yyleng;}
<COMMENT>[\r|\n|\r\n] {linha++;coluna = 1;}
<COMMENT><<EOF>>            {printf("Line %d, col %d: unterminated comment\n", linha_aux, coluna_aux); BEGIN(0);coluna += yyleng;}



"\""                                  {BEGIN(STRLIT);sprintf(buffer,"STRLIT(\"");linha_aux=linha;coluna_aux=coluna;coluna++;}
<STRLIT>"\""                          {BEGIN(0);printf("%s\")\n",buffer);bzero(buffer,sizeof(buffer));coluna+=yyleng;}
<STRLIT>"\\"[^f|n|r|t|"\\"|\"]        {if (yytext[1] != '\r') {printf("Line %d, col %d: invalid escape sequence (%s)\n", linha, coluna, yytext);} else {printf("Line %d, col %d: invalid escape sequence (\\)\n", linha, coluna);}BEGIN ERRO_STRLIT;coluna+=yyleng;}
<STRLIT>"\\""\\"                      {strcat(buffer,&yytext[0]);coluna+=yyleng;}
<STRLIT>"\\""\""                      {strcat(buffer,&yytext[0]);coluna+=yyleng;}
<STRLIT>"\r\n"|"\n"|"\r"              {printf("Line %d, col %d: unterminated string literal\n", linha_aux, coluna_aux); BEGIN(0);bzero(buffer,sizeof(buffer)); linha++; coluna = 1;}
<STRLIT>.                             {strcat(buffer,&yytext[0]);coluna+=yyleng;}
<STRLIT><<EOF>>                       {printf("Line %d, col %d: unterminated string literal\n", linha_aux, coluna_aux); BEGIN(0);bzero(buffer,sizeof(buffer)); linha++; coluna = 1;}

<ERRO_STRLIT>"\""                     {BEGIN (0);coluna+=yyleng;coluna+=yyleng;}
<ERRO_STRLIT>"\\""\\"                 {strcat(buffer,&yytext[0]);coluna+=yyleng;}
<ERRO_STRLIT>"\\""\""                 {strcat(buffer,&yytext[0]);coluna+=yyleng;}
<ERRO_STRLIT>"\\"[^f|n|r|t|"\\"|\"]   {if (yytext[1] != '\r') {printf("Line %d, col %d: invalid escape sequence (%s)\n", linha, coluna, yytext);} else {printf("Line %d, col %d: invalid escape sequence (\\)\n", linha, coluna);}BEGIN ERRO_STRLIT;coluna+=yyleng;}
<ERRO_STRLIT>"\r\n"|"\n"|"\r"         {printf("Line %d, col %d: unterminated string literal\n", linha_aux, coluna_aux); BEGIN(0);bzero(buffer,sizeof(buffer)); linha++; coluna = 1;}
<ERRO_STRLIT><<EOF>>                  {printf("Line %d, col %d: unterminated string literal\n", linha_aux, coluna_aux); BEGIN(0);bzero(buffer,sizeof(buffer)); linha++; coluna = 1;}
<ERRO_STRLIT>.                        {coluna+=yyleng;}

{reservadas}                          {printf("RESERVED(%s)\n", yytext);coluna += yyleng;}

{letras}                              {printf("ID(%s)\n", yytext);coluna += yyleng;}

{nonzeros}(("_"|{digitos})*{digitos})?|"0"       {printf("INTLIT(%s)\n", yytext);coluna += yyleng;}                  

(({digitos}"."{digitos}?{expoentes}?)|("."{digitos}{expoentes}?)|({digitos}{expoentes}))                  {printf("REALLIT(%s)\n", yytext);coluna += yyleng;}
(({digitos}*("_"*{digitos})*"."("_"*{digitos})+({expoentes})?)|({digitos}*("_"*{digitos})+"."))           {printf("REALLIT(%s)\n", yytext);coluna += yyleng;}

"\f"                            {coluna += yyleng;}
" "                             {coluna += yyleng;}
"\n"|"\r\n"|"\r"                {linha++;coluna = 1;}
"\t"                            {coluna += yyleng;}
.                               {printf("Line %d, col %d: illegal character (%s)\n",linha,coluna, yytext);coluna += yyleng;}


%%

int main(int argc, char *argv[]){
    /* ./compile.sh Project.l juccompiler;./juccompiler < Factorial.java > Output.txt */
    if (argc > 1)
        yyin = fopen(argv[1], "r");
    else
        yyin = stdin;
    yylex();
    return 0;
}

int yywrap() {
    return 1;
}
