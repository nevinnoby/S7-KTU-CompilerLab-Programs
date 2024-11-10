%{
#include<stdio.h>
#include<string.h>
char str[100];
char rp[3]="abc";
char r[3]="ABC";
%}

%%
abc {strcat(str,"ABC");}
[a-zA-Z] {strcat(str,yytext);}
[ \t] {strcat(str," ");}

\n {printf("%s",str); exit(0);}
%%

int main(){
printf("Enter the input text with abc : ");
yylex();
printf("%s",str);
return 0;
}
int yywrap(){

}
