%{
#include<stdio.h>
#include<stdlib.h>
#define YYSTYPE double
%}

%token NL DIGIT ID
%left '+''-'
%left '*''/'
%token '='

%%
stmt:ID '=' exp NL{printf("Valid expression"); exit(0);};
exp: exp'-'exp|exp'+'exp|exp'*'exp|exp'/'exp|'('exp')'|ID|DIGIT;
%%

int yyerror(char*msg){
printf("Invalid expression");
}
main(){
printf("Enter the expression: ");
yyparse();
}
