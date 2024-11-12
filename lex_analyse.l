%{
#include<stdio.h>
int n=0,k=0,i=0,o=0,num=0;
%}

%%
if|else|while|int|for {printf("%s is a keyword\n",yytext);}
[a-zA-Z]* {printf("%s is an identifier \n",yytext);}

"="|"-"|"+"|"*"|"/"|"<"|">" {printf("%s is an operator\n",yytext);}

"#"|"."|"("|")"|"{"|"}"|";" {printf("%s is an special character\n",yytext);}

(.) {}

[ \t]|\n {exit(0);}

%%

int main(){
printf("enter the input");
yylex();
}
int yywrap(){
}
