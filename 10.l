%{
#include "y.tab.h"
%}
%%
[0-9] {return DIGIT;}
. {return yytext[0];}
%%