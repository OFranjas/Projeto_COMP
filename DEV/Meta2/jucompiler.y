/*
    Autores:
    Gonçalo Franja Ferreira - 2020226867
    Gonçalo Gameiro Neves - 2020239361

*/

%{
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "symtab.h"
#include "Tree.h"


#define NSYMS 100

symtab tab[NSYMS];

symtab *symlook(char *varname);
int yylex (void);
void yyerror(char* s);
%}

%union{
int intlit;
float reallit;
char* id;
struct AST* node;
char* stringValue;
}

/* TOKENS */
%token STRLIT
%token INTLIT
%token REALLIT
%token ID
%token CLASS PUBLIC STATIC
%token STRING VOID INT DOUBLE BOOL
%token SEMICOLON COMMA LBRACE RBRACE LPAR RPAR LSQ RSQ ASSIGN
%token PLUS MINUS STAR DIV MOD
%token XOR OR AND BOOLLIT EQ NE LE GE LT GT NOT
%token WHILE IF ELSE RETURN RESERVED
%token ARROW LSHIFT RSHIFT DOTLENGTH PRINT PARSEINT

/* Precedências */
%left COMMA
%right ASSIGN
%left OR
%left AND
%left XOR
%left EQ NE
%left LT LE GT GE
%left PLUS MINUS
%left STAR DIV MOD
%right NOT 
%left LPAR RPAR
%nonassoc ELSE


%%


PROGRAM: CLASS ID LBRACE ClassBody RBRACE                                           {;}
       ;

ClassBody: ClassBody                                                                {;}  
           | MethodDecl ClassBody                                                   {;}
           | MethodDecl                                                             {;}
           | FieldDecl  ClassBody                                                   {;}
           | FieldDecl                                                              {;}
           | SEMICOLON  ClassBody                                                   {;}
           | SEMICOLON                                                              {;}
           ;

MethodDecl: PUBLIC STATIC MethodHeader MethodBody                                   {;}                                             
           ;

FieldDecl: PUBLIC STATIC Type ID FieldDeclCommaAux SEMICOLON                        {;}
           ;

FieldDeclCommaAux:  COMMA ID FieldDeclCommaAux                                      {;}
                  | COMMA ID                                                        {;}            
                  ;

Type: BOOL                                                                          {;}
    | INT                                                                           {;}
    | DOUBLE                                                                        {;}
    ;

MethodHeader: MethodHeaderAux ID LPAR FormalParams RPAR                             {;}
            | MethodHeaderAux ID LPAR RPAR                                          {;}
            ;

MethodHeaderAux: Type                                                               {;}
               | VOID                                                               {;}
               ;

FormalParams: Type ID FormalParamsAux                                               {;}
            | STRING LSQ RSQ ID                                                     {;}
            ;

FormalParamsAux: COMMA Type ID FormalParamsAux                                      {;}
               | COMMA Type ID                                                      {;}
               ;

MethodBody: LBRACE MethodBodyAux RBRACE                                             {;}
          ;

MethodBodyAux: Statement MethodBodyAux                                              {;}
             | Statement                                                            {;}
             | VarDecl MethodBodyAux                                                {;}
             | VarDecl                                                              {;}
             ;

VarDecl: Type ID VarDeclAux SEMICOLON                                               {;}
       ;

VarDeclAux: COMMA ID VarDeclAux                                                     {;}
          | COMMA ID                                                                {;}
          ;


Statement: LBRACE RBRACE                                                            {;}
         | LBRACE Statement RBRACE                                                  {;}
         | IF LPAR Expr RPAR Statement                                              {;}
         | IF LPAR Expr RPAR Statement ELSE Statement                               {;}
         | WHILE LPAR Expr RPAR Statement                                           {;}
         | RETURN Expr SEMICOLON                                                    {;}
         | RETURN SEMICOLON                                                         {;}
         | MethodInvocation SEMICOLON                                               {;}
         | Assignment SEMICOLON                                                     {;}
         | ParseArgs SEMICOLON                                                      {;}
         | SEMICOLON                                                                {;}
         | PRINT LPAR Expr RPAR SEMICOLON                                           {;}
         | PRINT LPAR STRLIT RPAR SEMICOLON                                         {;}

MethodInvocation: ID LPAR MethodInvocationAux RPAR                                  {;}
                | ID LPAR RPAR                                                      {;}
                ;

MethodInvocationAux: Expr                                                           {;}
                   | Expr COMMA Expr MethodInvocationAux                            {;}
                   | Expr COMMA Expr                                                {;}
                   ;

Assignment: ID ASSIGN Expr                                                          {;}
          ;

ParseArgs: PARSEINT LPAR ID LSQ Expr RSQ RPAR                                       {;}
         ;

Expr: Expr PLUS Expr                                                                {;}
    | Expr MINUS Expr                                                               {;}
    | Expr STAR Expr                                                                {;}
    | Expr DIV Expr                                                                 {;}
    | Expr MOD Expr                                                                 {;}
    | Expr OR Expr                                                                  {;}
    | Expr XOR Expr                                                                 {;}
    | Expr AND Expr                                                                 {;}
    | Expr LSHIFT Expr                                                              {;}
    | Expr RSHIFT Expr                                                              {;}
    | Expr EQ Expr                                                                  {;}
    | Expr NE Expr                                                                  {;}
    | Expr LT Expr                                                                  {;}
    | Expr GT Expr                                                                  {;}
    | Expr LE Expr                                                                  {;}
    | Expr GE Expr                                                                  {;}
    | MINUS Expr                                                                    {;} 
    | NOT Expr                                                                      {;}
    | PLUS Expr                                                                     {;}
    | LPAR Expr RPAR                                                                {;}
    | MethodInvocation                                                              {;}
    | Assignment                                                                    {;}
    | ParseArgs                                                                     {;}
    | ID                                                                            {;}
    | ID DOTLENGTH                                                                  {;}
    | INTLIT                                                                        {;}
    | REALLIT                                                                       {;}
    | BOOLLIT                                                                       {;}
    ;








%%

symtab *symlook(char *varname)
{
    int i;
  
    for(i=0; i<NSYMS; i++)
    {
        if(tab[i].name && strcmp(varname, tab[i].name)==0)   
            return &tab[i];
        if(!tab[i].name)
        {
            tab[i].name=varname;
            return &tab[i];
        }
    }
    yyerror("variaveis a mais...");
    exit(1);
}

