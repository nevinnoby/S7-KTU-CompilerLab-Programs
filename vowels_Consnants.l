%{
#include<stdio.h>
int c=0;
int v=0;
%}

%%

[aeiouAEIOU] {v++;}
[a-zA-Z] {c++;}

\n {printf("%d Vowels:  \n %d Consnats: ",v,c);exit(0);}
%%

int main(){
printf("Enter the text: ");
yylex();
return 0;
}
int yywrap(){
return 0;
}
