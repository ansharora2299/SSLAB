%{
#include<stdio.h>
%}
%token DIGIT
%%
S:DIGIT DIGIT exp{printf("Valid\n");}
;
exp:DIGIT exp
|DIGIT
;
%%
void yyerror()
{
printf("invalid\n");
exit(0);
}
void main()
{
printf("enter an integer\n");
yyparse();
}