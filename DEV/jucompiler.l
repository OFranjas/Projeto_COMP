%{
    int counter = 0;

%}

letras  ([A-Za-z]|[_$])([0-9]|[_$]|[A-Za-z])*
digitos  [0-9]+
nonzeros [1-9]
expoentes   (("E"|"e")[+-]?{digitos}([0-9]|"_")*)
reservadas "switch"|"assert"|"default"|"package"|"finally"|"float"|"implements"|"import"|"instanceof"|"interface"|"long"|"native"|"new"|"synchronized"|"do"|"goto"|"private"|"break"|"++"|"--"|"null"|"Integer"|"System"|"for"|"abstract"|"continue"|"byte"|"case"|"catch"|"char"|"const"|"enum"|"extends"|"final"|"protected"|"short"|"strictfp"|"transient"|"try"|"volatile"|"super"|"this"|"throw"|"throws"
comment "//".*"\n"
erros   (".")
invalidos ("\r"|"\f"|"\n"|"\t"|"\0"|"\\"|"\"")

%X COMMENT STRLIT

%%  

"true"|"false"              {printf("BOOLLIT(%s)\n", yytext);}
"&&"                       {printf("AND\n");}
"="                         {printf("ASSIGN\n");}
"*"                         {printf("STAR\n");}
","                         {printf("COMMA\n");}
"/"                         {printf("DIV\n");}
"=="                        {printf("EQ\n");}
">="                        {printf("GE\n");}
">"                         {printf("GT\n");}
"{"                         {printf("LBRACE\n");}
"<="                        {printf("LE\n");}
"("                         {printf("LPAR\n");}
"["                         {printf("LSQ\n");}
"<"                         {printf("LT\n");}
"-"                         {printf("MINUS\n");}
"%"                         {printf("MOD\n");}
"!="                        {printf("NE\n");}
"!"                         {printf("NOT\n");}
"||"                        {printf("OR\n");}
"+"                         {printf("PLUS\n");}
"}"                         {printf("RBRACE\n");}
")"                         {printf("RPAR\n");}
"]"                         {printf("RSQ\n");}
";"                         {printf("SEMICOLON\n");}
"->"                        {printf("ARROW\n");}
"<<"                        {printf("LSHIFT\n");}
">>"                        {printf("RSHIFT\n");}
"^"                         {printf("XOR\n");}
"boolean"                   {printf("BOOL\n");}
"class"                     {printf("CLASS\n");}
".length"                   {printf("DOTLENGTH\n");}
"double"                    {printf("DOUBLE\n");}
"else"                      {printf("ELSE\n");}
"if"                        {printf("IF\n");}
"int"                       {printf("INT\n");}
"System.out.print"          {printf("PRINT\n");}
"Integer.parseInt"          {printf("PARSEINT\n");}
"public"                    {printf("PUBLIC\n");}
"return"                    {printf("RETURN\n");}
"static"                    {printf("STATIC\n");}
"String"                    {printf("STRING\n");}
"void"                      {printf("VOID\n");}
"while"                     {printf("WHILE\n");}

{erros}  {printf("illegal character (%s)\n", yytext);}

{comment}          ;  

"/*" {BEGIN(COMMENT);}
<COMMENT>"*/" {BEGIN(0);}
<COMMENT>.          ;
<COMMENT>"\n"   ;

"\""                        {BEGIN(STRLIT);printf("STRLIT(\"");}

<STRLIT>"\""                 {BEGIN(0);printf("\")\n");}
<STRLIT>.                    {printf("%c",yytext[0]);}

{reservadas}                {printf("RESERVED(%s)\n", yytext);}

"\""[^"]*"\""                  {printf("STRLIT(%s)\n", yytext);}

{letras}                        {printf("ID(%s)\n", yytext);}

{nonzeros}(("_"|{digitos})*{digitos})?|"0"       {printf("INTLIT(%s)\n", yytext);}                  

(({digitos}"."{digitos}?{expoentes}?)|("."{digitos}{expoentes}?)|({digitos}{expoentes}))   {printf("REALLIT(%s)\n", yytext);}
{digitos}*("_"*{digitos})*"."({digitos}|["_"])*({expoentes})?           {printf("REALLIT(%s)\n", yytext);}

" "                             ;
.                               ;
"\n"                            ;


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
