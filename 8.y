%{
#include<stdio.h>
#include<stdlib.h>
%}
%token NUMBER NL
%left '+' '-'
%left '*' '/'
%%
stmt:exp NL {printf("value is %d\n",$1);exit(0);}
;
exp:exp '+' exp {$$=$1+$3;}
|exp '-' exp {$$=$1-$3;}
|exp '*' exp {$$=$1*$3;}
|exp '/' exp {if ($3==0)
{printf("divideby zero error\n");
exit(0);
}
else
$$=$1/$3;
}
|'(' exp ')' {$$=$2;}
|NUMBER {$$=$1;}
;
%%
int yyerror(char *msg)
{
printf("invalid\n");
return 0;
}
void main()
{
printf("enter the xpession\n");
yyparse();
}
