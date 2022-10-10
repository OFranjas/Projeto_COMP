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
comment "//".*"\r\n"
erros   ("."|"&"|"?"|"#")
invalidos ("\r"|"\f"|"\r\n"|"\t"|"\0"|"\\"|"\"")

%X COMMENT STRLIT ERRO_STRLIT

%%  

"true"|"false"              {printf("BOOLLIT(%s)\r\n", yytext);coluna += yyleng;}
"&&"                        {printf("AND\r\n");coluna += yyleng;}
"="                         {printf("ASSIGN\r\n");}coluna += yyleng;
"*"                         {printf("STAR\r\n");coluna += yyleng;}
","                         {printf("COMMA\r\n");coluna += yyleng;}
"/"                         {printf("DIV\r\n");coluna += yyleng;}
"=="                        {printf("EQ\r\n");coluna += yyleng;}
">="                        {printf("GE\r\n");coluna += yyleng;}
">"                         {printf("GT\r\n");coluna += yyleng;}
"{"                         {printf("LBRACE\r\n");coluna += yyleng;}
"<="                        {printf("LE\r\n");coluna += yyleng;}
"("                         {printf("LPAR\r\n");coluna += yyleng;}
"["                         {printf("LSQ\r\n");coluna += yyleng;}
"<"                         {printf("LT\r\n");coluna += yyleng;}
"-"                         {printf("MINUS\r\n");coluna += yyleng;}
"%"                         {printf("MOD\r\n");coluna += yyleng;}
"!="                        {printf("NE\r\n");coluna += yyleng;}
"!"                         {printf("NOT\r\n");coluna += yyleng;}
"||"                        {printf("OR\r\n");coluna += yyleng;}
"+"                         {printf("PLUS\r\n");coluna += yyleng;}
"}"                         {printf("RBRACE\r\n");coluna += yyleng;}
")"                         {printf("RPAR\r\n");coluna += yyleng;}
"]"                         {printf("RSQ\r\n");coluna += yyleng;}
";"                         {printf("SEMICOLON\r\n");coluna += yyleng;}
"->"                        {printf("ARROW\r\n");coluna += yyleng;}
"<<"                        {printf("LSHIFT\r\n");coluna += yyleng;}
">>"                        {printf("RSHIFT\r\n");coluna += yyleng;}
"^"                         {printf("XOR\r\n");coluna += yyleng;}
"boolean"                   {printf("BOOL\r\n");coluna += yyleng;}
"class"                     {printf("CLASS\r\n");coluna += yyleng;}
".length"                   {printf("DOTLENGTH\r\n");coluna += yyleng;}
"double"                    {printf("DOUBLE\r\n");coluna += yyleng;}
"else"                      {printf("ELSE\r\n");coluna += yyleng;}
"if"                        {printf("IF\r\n");coluna += yyleng;}
"int"                       {printf("INT\r\n");coluna += yyleng;}
"System.out.print"          {printf("PRINT\r\n");coluna += yyleng;}
"Integer.parseInt"          {printf("PARSEINT\r\n");coluna += yyleng;}
"public"                    {printf("PUBLIC\r\n");coluna += yyleng;}
"return"                    {printf("RETURN\r\n");coluna += yyleng;}
"static"                    {printf("STATIC\r\n");coluna += yyleng;}
"String"                    {printf("STRING\r\n");coluna += yyleng;}
"void"                      {printf("VOID\r\n");coluna += yyleng;}
"while"                     {printf("WHILE\r\n");coluna += yyleng;}

{erros}  {printf("Line %d, col %d: illegal character (%s)\r\n",linha,coluna, yytext);coluna += yyleng;}

{comment}          {linha++; coluna = 1;};  
"/*" {BEGIN(COMMENT);linha_aux = linha;coluna_aux=coluna;coluna += yyleng;}
<COMMENT>"*/"       {BEGIN(0);coluna += yyleng;}
<COMMENT><<EOF>>    {printf("Line %d, col %d: unterminated comment\r\n", linha_aux, coluna_aux); BEGIN(0);coluna += yyleng;}
<COMMENT>.          {coluna += yyleng;}
<COMMENT>"\r\n"|"\n"     {linha++;coluna = 1;};


"\""                                  {BEGIN(STRLIT);sprintf(buffer,"STRLIT(\"");linha_aux=linha;coluna_aux=coluna;coluna++;}

<STRLIT>"\\"[^f|n|r|t|"\\"|\"]      {if (yytext[1] != '\r') {printf("Line %d, col %d: invalid escape sequence (%s)\r\n", linha, coluna, yytext);} else {printf("Line %d, col %d: invalid escape sequence (\\)\r\n", linha, coluna);}BEGIN ERRO_STRLIT;coluna+=yyleng;}
<STRLIT>"\\""\\"                      {strcat(buffer,&yytext[0]);coluna+=yyleng;}
<STRLIT>"\\""\""                      {strcat(buffer,&yytext[0]);coluna+=yyleng;}
<STRLIT>"\""                          {BEGIN(0);printf("%s\")\r\n",buffer);bzero(buffer,sizeof(buffer));coluna+=yyleng;}
<STRLIT>"\r\n"|"\n"                   {printf("Line %d, col %d: unterminated string literal\r\n", linha_aux, coluna_aux); BEGIN(0);bzero(buffer,sizeof(buffer)); linha++; coluna = 1;}
<STRLIT>.                             {strcat(buffer,&yytext[0]);coluna+=yyleng;}
<STRLIT><<EOF>>                     {printf("Line %d, col %d: unterminated string literal\r\n", linha_aux, coluna_aux); BEGIN(0);bzero(buffer,sizeof(buffer)); linha++; coluna = 1;}
<ERRO_STRLIT>"\""                     {BEGIN 0;coluna+=yyleng;coluna+=yyleng;}
<ERRO_STRLIT>"\\""\\"                 {strcat(buffer,&yytext[0]);coluna+=yyleng;}
<ERRO_STRLIT>"\\""\""                 {strcat(buffer,&yytext[0]);coluna+=yyleng;}
<ERRO_STRLIT>"\\"[^f|n|r|t|"\\"|\"] {if (yytext[1] != '\r') {printf("Line %d, col %d: invalid escape sequence (%s)\r\n", linha, coluna, yytext);} else {printf("Line %d, col %d: invalid escape sequence (\\)\r\n", linha, coluna);}BEGIN ERRO_STRLIT;coluna+=yyleng;}
<ERRO_STRLIT>"\r\n"|"\n"              {printf("Line %d, col %d: unterminated string literal\r\n", linha_aux, coluna_aux); BEGIN(0);bzero(buffer,sizeof(buffer)); linha++; coluna = 1;}
<ERRO_STRLIT>.                        {coluna+=yyleng;}

{reservadas}                          {printf("RESERVED(%s)\r\n", yytext);coluna += yyleng;}

{letras}                              {printf("ID(%s)\r\n", yytext);coluna += yyleng;}

{nonzeros}(("_"|{digitos})*{digitos})?|"0"       {printf("INTLIT(%s)\r\n", yytext);coluna += yyleng;}                  

(({digitos}"."{digitos}?{expoentes}?)|("."{digitos}{expoentes}?)|({digitos}{expoentes}))   {printf("REALLIT(%s)\r\n", yytext);coluna += yyleng;}
(({digitos}*("_"*{digitos})*"."({digitos}|[_])+({expoentes})?)|({digitos}*("_"*{digitos})*"."))           {printf("REALLIT(%s)\r\n", yytext);coluna += yyleng;}

" "                             {coluna += yyleng;}
"\r\n"|"\n"|"\r"                {linha++;coluna = 1;}
.                               {coluna += yyleng;}


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
