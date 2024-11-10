%{
#include<stdio.h>
#include<stdlib.h>
#define YYSTYPE double
%}

%token  NL ID

%%
stmt:ID NL{printf("Valid identifier");exit(0);};
%%

int yyerror(char*msg){
printf("Invalid identifier");
}
main(){
printf("Enter the id: ");
yyparse();
}
