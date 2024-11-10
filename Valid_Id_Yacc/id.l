%{
#include<stdio.h>
#include<stdlib.h>
#include "y.tab.h"
%}

%%
[a-zA-Z_][a-zA-Z0-9_]* {return ID;}
\n {return NL;}
. {return yytext[0];}
%%
