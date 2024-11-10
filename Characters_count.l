%{
#include<stdio.h>
#include<ctype.h>
int s=0,w=0,l=0,c=0,wo=0;
%}

%%
\n {c++;l++;wo=0;}
[ \t] {c++;s++;wo=0;}
[a-zA-Z0-9_] {c++;if(wo==0){w++;wo=1;}}
. {c++;}
%%

int main(){
yyin=fopen("input.txt","r");
if(!yyin){
printf("error");
return 0;
}
yylex();
fclose(yyin);
printf("%d Spaces: \n%d Lines: \n%d Characters: \n%d Words: ",s,l,c,w);

}
int yywrap(){
return 1;
}
