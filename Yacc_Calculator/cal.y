%{
#include<stdio.h>
%}

%token NUMBER ID
%left '-''+'
%left '*''/'

%%
stmt:exp {printf("Result is :  %d",$$); return 0;}
exp: exp'-'exp{$$=$1-$3;}|exp'+'exp{$$=$1+$3;}|exp'*'exp{$$=$1*$3;}|exp'/'exp{$$=$1/$3;}|NUMBER{$$=$1;}|ID{$$=$1;}|'-'NUMBER{$$=-$2;}|'-'ID{$$=-$2;}|'('exp')'{$$=$2;};
%%

int yyerror(){
printf("Invalid expression");

}
int main(){

printf("Enter an expression: ");
yyparse();
}
