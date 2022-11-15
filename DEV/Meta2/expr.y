/*
    Autores:
    Gonçalo Franja Ferreira - 2020226867
    Gonçalo Gameiro Neves - 2020239361

*/

%{
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Tree.h"


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
int flag_erro = 0;
int flag_erro_string = 0;

int yylex(void);
extern int yylineno;
extern int coluna;
extern int yyerror(char *s);

int flag_while = 0;
int block_assign = 0;

int yydegug = 1;


%}

%union{
char* string;
struct AST* ast;
}

/* TOKENS */
%token CLASS PUBLIC STATIC
%token STRING VOID INT DOUBLE BOOL
%token SEMICOLON COMMA LBRACE RBRACE LPAR RPAR LSQ RSQ ASSIGN
%token PLUS MINUS STAR DIV MOD
%token XOR OR AND EQ NE LE GE LT GT NOT
%token WHILE IF ELSE RETURN 
%token ARROW LSHIFT RSHIFT DOTLENGTH PRINT PARSEINT
%token RESERVED

%token <string> REALLIT STRLIT INTLIT ID BOOLLIT

%type <ast> StatementAux Statement ExprAux MethodDecl MethodBody ProgramAux MethodBodyAux Program Expr MethodInvocation Assignment ParseArgs  MethodInvocationaux  VarDecl Type VarDeclAux FieldDecl FieldDeclAux FormalParams FormalParamsAux MethodHeader

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

Program: CLASS ID LBRACE ProgramAux RBRACE                           {
                                                                $$ = AST_newNode("Program","");       
                                                                AST_addSon($$, AST_newNode("Id", $2));
                                                                AST_addSon($$,$4);
                                                                root = $$;
                                                            }
        | CLASS ID LBRACE error                            {$$ = NULL;flag_erro=1;}
        ;

ProgramAux: MethodDecl ProgramAux                            {
                                                                $$ = $1;
                                                                AST_addBrother($$, $2);
                                                            }
          | FieldDecl ProgramAux                             {                                                           
                                                                $$ = $1;
                                                                
                                                                AST_addBrother($$, $2);
                                                                
                                                            }
          | SEMICOLON ProgramAux                             {
                                                                $$ = $2;
                                                            }
          |                                                   {$$ = NULL;}
          ;

MethodDecl: PUBLIC STATIC MethodHeader MethodBody                                   {
                                                                                    $$ = AST_newNode("MethodDecl","");
                                                                                    AST_addSon($$,$3);
                                                                                    AST_addSon($$,$4);
                                                                                    }                                            
           ;


MethodHeader: Type ID LPAR FormalParams RPAR                   {
                                                                $$ = AST_newNode("MethodHeader","");
                                                                methodParams = AST_newNode("MethodParams","");
                                                                AST_addSon($$,$1); 
                                                                AST_addSon($$,AST_newNode("Id", $2));
                                                                AST_addSon($$, methodParams);
                                                                AST_addSon(methodParams,$4);
                                                               }

        | Type ID LPAR RPAR                                    {
                                                                $$ = AST_newNode("MethodHeader","");
                                                                AST_addSon($$,$1);
                                                                methodParams = AST_newNode("MethodParams","");
                                                                AST_addBrother($1,AST_newNode("Id", $2));
                                                                AST_addSon($$, methodParams);
                                                               }

        | VOID ID LPAR FormalParams RPAR                       {
                                                                $$ = AST_newNode("MethodHeader","");
                                                                methodParams = AST_newNode("MethodParams","");
                                                                AST_addSon($$,AST_newNode("Void", "")); 
                                                                AST_addSon($$,AST_newNode("Id", $2));
                                                                AST_addSon($$, methodParams);
                                                                AST_addSon(methodParams,$4);
                                                               }

        | VOID ID LPAR RPAR                                    {
                                                                $$ = AST_newNode("MethodHeader","");
                                                                methodParams = AST_newNode("MethodParams","");
                                                                AST_addSon($$,AST_newNode("Void", "")); 
                                                                AST_addSon($$,AST_newNode("Id", $2));
                                                                AST_addSon($$, methodParams);
                                                               }
        ;

MethodBody: LBRACE MethodBodyAux RBRACE                                             {$$ = AST_newNode("MethodBody",""); 
                                                                                    AST_addSon($$,$2);
                                                                                    }
          ;


MethodBodyAux: Statement MethodBodyAux                                              {if($1 != NULL){$$ = $1; AST_addBrother($$, $2);}else{$$ = $2;}}
             | VarDecl MethodBodyAux                                                {$$ = $1; AST_addBrother($$, $2);}
             |                                                                      {$$ = NULL;}
             ;

FieldDecl: PUBLIC STATIC Type ID FieldDeclAux SEMICOLON     {
                                                                $$ = AST_newNode("FieldDecl", "");
                                                                AST_addSon($$,$3);
                                                                AST_addSon($$, AST_newNode("Id", $4));
                                                                givetype($5, $3->type);
                                                                AST_addBrother($$, $5);
                                                                
                                                            }
        | error SEMICOLON                                    {$$ = NULL;flag_erro = 1;}
        ;


FieldDeclAux: COMMA ID FieldDeclAux                         {
                                                                $$ = AST_newNode("FieldDecl","");                                                                
                                                                AST_addSon($$, AST_newNode("Id", $2));
                                                                
                                                                AST_addBrother($$, $3);
                                                                
                                                            }

            |                                              {$$ = NULL;}                                                
            ;

Type: INT                                                   {$$ = AST_newNode("Int", "");}
    | DOUBLE                                                {$$ = AST_newNode("Double", "");}
    | BOOL                                                  {$$ = AST_newNode("Bool", "");}                
    ;

FormalParams: Type ID FormalParamsAux                                      {$$ = AST_newNode("ParamDecl","");
                                                                            AST_addSon($$,$1);
                                                                            AST_addSon($$,AST_newNode("Id", $2));
                                                                            AST_addBrother($$,$3);}
                                                                            
            | STRING LSQ RSQ ID                                            {
                                                                           $$ = AST_newNode("ParamDecl","");
                                                                           AST_addSon($$,AST_newNode("StringArray",""));
                                                                           AST_addSon($$,AST_newNode("Id", $4));
                                                                           }
            ;                               


FormalParamsAux: COMMA Type ID FormalParamsAux                            { $$ = AST_newNode("ParamDecl","");
                                                                            AST_addSon($$,$2);
                                                                            AST_addSon($$,AST_newNode("Id",$3));
                                                                            AST_addBrother($$,$4);
                                                                            }
                                                                            
                |                                                         {$$ = NULL;}
                ;


VarDecl: Type ID VarDeclAux SEMICOLON                                   {
    
                                                                $$ = AST_newNode("VarDecl", "");
                                                                AST_addSon($$, $1);
                                                                AST_addSon($$, AST_newNode("Id", $2));
                                                                givetype($3, $1->type);
                                                                
                                                                AST_addBrother($$, $3);
                                                                
                                                                }
        ;

VarDeclAux: COMMA ID VarDeclAux                            { 
                                                                $$ = AST_newNode("VarDecl","");
                                                                AST_addSon($$, AST_newNode("Id", $2));                                                              
                                                                AST_addBrother($$, $3);
                                                                
                                                            }
        |                                                   {$$ = NULL;}
        ;

Statement:    LBRACE StatementAux RBRACE                                   {
                                                                              if($2 != NULL && $2->brother != NULL){
                                                                                     $$ = AST_newNode("Block","");
                                                                                     AST_addSon($$,$2);

                                                                               }else if($2 != NULL && $2->brother == NULL){
                                                                                        $$ = $2;
                                                                                    }else{$$ = NULL;}     
                                                                            }

            | LBRACE SEMICOLON RBRACE                                        {$$ = AST_newNode("Block","");}



            | IF LPAR Expr RPAR Statement                                   {
                                                                               $$ = AST_newNode("If","");
                                                                               

                                                                               AST_addSon($$,$3);


                                                                               if($5 == NULL){
                                                                                    AST_addSon($$,AST_newNode("Block",""));
                                                                                    AST_addSon($$,AST_newNode("Block",""));
                                                                               }else{
                                                                                    AST_addSon($$,$5);
                                                                                    AST_addSon($$,AST_newNode("Block",""));
                                                                               }
                                                                            }

            | IF LPAR Expr RPAR Statement ELSE Statement                    {
                                                                                $$ = AST_newNode("If","");
                                                                                AST_addSon($$,$3);
                                                                                if($5 == NULL){  //caso o primeiro satatement seja null
                                                                                    AST_addSon($$,AST_newNode("Block",""));}
                                                                                else{
                                                                                    AST_addSon($$,$5);
                                                                                    }
                                                                                if($7 == NULL){ //caso o segundo statement seja null
                                                                                    AST_addSon($$,AST_newNode("Block",""));}
                                                                                else{
                                                                                    AST_addSon($$,$7);
                                                                                    }

                                                                            }
            | WHILE LPAR Expr RPAR Statement                                {
                                                                             //$$ = AST_newNode("Block","");
                                                                             //temp = AST_newNode("While","");
                                                                             //AST_addBrother($$,temp);
                                                                             
                                                                             $$ = AST_newNode("While","");
                                                                             AST_addSon($$,$3);
                                                                             if($5 == NULL){
                                                                                AST_addSon($$,AST_newNode("Block",""));
                                                                                }
                                                                             else {
                                                                                    AST_addBrother($3,$5);
                                                                                }
                                                                             
                                                                             
                                                                            }

            | RETURN SEMICOLON                                             {$$ = AST_newNode("Return", "");}


            | RETURN Expr SEMICOLON                                        {$$ = AST_newNode("Return","");
                                                                            AST_addSon($$,$2);
                                                                            }

            | PRINT LPAR Expr RPAR SEMICOLON                                {$$ = AST_newNode("Print","");
                                                                            AST_addSon($$,$3);
                                                                            }   
            | PRINT LPAR STRLIT RPAR SEMICOLON                                         {
                                                                                    $$ = AST_newNode("Print","");
                                                                                    AST_addSon($$, AST_newNode("StrLit", $3));
                                                                                    }
            | MethodInvocation SEMICOLON                                               {$$ = $1;}
            | Assignment SEMICOLON                                                     {$$ = $1;}
            | ParseArgs SEMICOLON                                                      {$$ = $1;}
            | SEMICOLON                                                                {$$ = NULL;}

            | error SEMICOLON                                                          {$$ = NULL;flag_erro = 1;flag_erro_string = 1;}
            ;

StatementAux: Statement StatementAux                                        {
                                                                                        if($$ != NULL){
                                                                                         $$ = $1; AST_addBrother($1,$2);
                                                                                         }else{
                                                                                             $$ = $2;}
                                                                                        }

            |                                                               {$$ = NULL;}
            ;


MethodInvocation: ID LPAR Expr MethodInvocationaux RPAR                 {  
                                                                            $$ = AST_newNode("Call", "");
                                                                            
                                                                            AST_addSon($$, AST_newNode("Id", $1));
                                                                            AST_addSon($$, $3);
                                                                            AST_addSon($$, $4);
                                                                        }
                                                                        
                | ID LPAR RPAR                                          { 
                                                                            $$ = AST_newNode("Call", "");
                                                                            
                                                                            AST_addSon($$, AST_newNode("Id", $1));
                                                                        }
                | ID LPAR error RPAR                                      {$$ = NULL;flag_erro = 1;}                             
                ;

MethodInvocationaux: COMMA Expr MethodInvocationaux                     {
                                                                            $$ = $2;
                                                                            AST_addBrother($$, $3);
                                                                        }

                    |                                                   {$$ = NULL;}                    
                    ;

ParseArgs: PARSEINT LPAR ID LSQ Expr RSQ RPAR              {
                                                                $$ = AST_newNode("ParseArgs","");
                                                                
                                                                AST_addSon($$, AST_newNode("Id", $3));
                                                                AST_addSon($$, $5);
                                                            }
        | PARSEINT LPAR error RPAR                              {$$ = NULL;flag_erro = 1;}
        ;

Assignment: ID ASSIGN Expr                                  {
                                                                $$ = AST_newNode("Assign", "");
                                                                
                                                                AST_addSon($$,AST_newNode("Id", $1));
                                                                AST_addSon($$,$3);
                                                                
                                                            }
    ;

Expr: ExprAux                                               {$$ = $1;}
    | Assignment                                            {$$ = $1;}

ExprAux: ExprAux PLUS ExprAux                                                                {	
                                                                $$ = AST_newNode("Add","");
                                                                
																AST_addSon($$,$1);
																AST_addBrother($1,$3);
                                                                
                                                                                    }
    | ExprAux MINUS ExprAux                                                               {
                                                                $$ = AST_newNode("Sub","");
																AST_addSon($$,$1);
																AST_addBrother($1,$3);
                                                                                    }
    | ExprAux STAR ExprAux                                                                {
                                                                $$ = AST_newNode("Mul","");
																AST_addSon($$,$1);
																AST_addBrother($1,$3);
                                                                                    }
    | ExprAux DIV ExprAux                                                                 {
                                                                $$ = AST_newNode("Div","");
																AST_addSon($$,$1);
																AST_addBrother($1,$3);
                                                                                    }
    | ExprAux MOD ExprAux                                                                 {
                                                                $$ = AST_newNode("Mod","");
																AST_addSon($$,$1);
																AST_addBrother($1,$3);
                                                                                    }
    | ExprAux OR ExprAux                                                                  {
                                                                $$ = AST_newNode("Or","");
																AST_addSon($$,$1);
																AST_addBrother($1,$3);
                                                                                    }
    | ExprAux XOR ExprAux                                                                 {
                                                                $$ = AST_newNode("Xor","");
																AST_addSon($$,$1);
																AST_addBrother($1,$3);
                                                                                    }
    | ExprAux AND ExprAux                                                                 {
                                                                $$ = AST_newNode("And","");
																AST_addSon($$,$1);
																AST_addBrother($1,$3);
                                                                                    }
    | ExprAux LSHIFT ExprAux                                                              {
                                                                $$ = AST_newNode("Lshift","");
																AST_addSon($$,$1);
																AST_addBrother($1,$3);
                                                                                    } 
    | ExprAux RSHIFT ExprAux                                                              {
                                                                $$ = AST_newNode("Rshift","");
																AST_addSon($$,$1);
																AST_addBrother($1,$3);
                                                                                    } 
    | ExprAux EQ ExprAux                                                                  {
                                                                $$ = AST_newNode("Eq","");
																AST_addSon($$,$1);
																AST_addBrother($1,$3);
                                                                                    }   
    | ExprAux NE ExprAux                                                                  {
                                                                $$ = AST_newNode("Ne","");
																AST_addSon($$,$1);
																AST_addBrother($1,$3);
                                                                                    }
    | ExprAux LT ExprAux                                                                  {
                                                                $$ = AST_newNode("Lt","");
																AST_addSon($$,$1);
																AST_addBrother($1,$3);
                                                                                    }
    | ExprAux GT ExprAux                                                                  {
                                                                $$ = AST_newNode("Gt","");
																AST_addSon($$,$1);
																AST_addBrother($1,$3);
                                                                                    }
    | ExprAux LE ExprAux                                                                  {
                                                                $$ = AST_newNode("Le","");
																AST_addSon($$,$1);
																AST_addBrother($1,$3);
                                                                                    }
    | ExprAux GE ExprAux                                                                  {
                                                                $$ = AST_newNode("Ge","");
																AST_addSon($$,$1);
																AST_addBrother($1,$3);
                                                                                    }
    | MINUS ExprAux %prec NOT                                                                   {
        														$$ = AST_newNode("Minus","");
																AST_addSon($$,$2);
                                                                                    } 
    | NOT ExprAux   %prec NOT                                                                   {
                                                                $$ = AST_newNode("Not","");
                                                                AST_addSon($$,$2);
                                                                                    }
    | PLUS ExprAux  %prec NOT                                                                   {
                                                                $$ = AST_newNode("Plus","");
                                                                AST_addSon($$,$2);
                                                                                    }
    | LPAR ExprAux RPAR                                                                {
                                                                $$ = $2;
                                                                                    } 
    | ID                                                                            {
                                                                $$ = AST_newNode("Id",$1);

                                                                                    }
    | ID DOTLENGTH                                                                  {
                                                                $$ = AST_newNode("Length","");
                                                                AST_addSon($$,AST_newNode("Id",$1));
                                                                                    
                                                                                    }

    | INTLIT                                                                        {
                                                                $$ = AST_newNode("DecLit",$1);
                                                                                    }
    | REALLIT                                                                       {
                                                                $$ = AST_newNode("RealLit",$1);
                                                                                    } 

    | BOOLLIT                                                                       {
                                                                $$ = AST_newNode("BoolLit",$1);
                                                                                    }
    | MethodInvocation                                                {$$ = $1;}
    | ParseArgs                                                       {$$ = $1;}

    | LPAR error RPAR                                                 {$$ = NULL;flag_erro = 1;}
    ;

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
        if(flag_erro == 0){
            AST_print(root,0);
        }
    }
    return 0;
}

/*void yyerror(char *s) {
    if(flag_erro == 1 && strlen(buffer) > 1){
        printf("Line %d, col %d: %s: \"%s\"\n", yylineno, coluna_aux + (int) yyleng - 1, s, buffer);
        flag_erro = 0;
        buffer[0] = '\0';
    }else if(flag_erro == 1){
        printf("Line %d, col %d: %s: %s\n", yylineno, coluna - (int) yyleng, s, yytext);
        flag_erro = 0;
    }
}*/