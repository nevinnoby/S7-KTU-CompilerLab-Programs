%{
#include<stdio.h>
#include<stdlib.h>
#include "y.tab.h"

%}

%%
[0-9]+ {return DIGIT;}
[a-zA-Z][a-zA-Z0-9_]* {return ID;}
\n {return NL;}
; {return NL;}
= {return '=';}
. {return yytext[0];}
%%
