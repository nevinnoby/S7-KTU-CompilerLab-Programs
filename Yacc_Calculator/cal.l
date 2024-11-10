%{
#include<stdio.h>
#include"y.tab.h"
int extern yylval;
%}

%%
[0-9]+ {yylval=atoi(yytext);return NUMBER;}
[a-zA-Z]+ {return ID;}
[\t]+;
. {return yytext[0];}
\n return 0;
%%
