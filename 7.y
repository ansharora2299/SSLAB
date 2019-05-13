%{
#include<stdio.h>
#include<stdlib.h>
%}
%token LETTER DIGIT NL
%%
stmt:variable NL{printf("valid identifier\n");exit(0);}
;
variable: LETTER alphanumeric
;
alphanumeric: LETTER alphanumeric
|DIGIT alphanumeric
|LETTER
|DIGIT
;
%%
int yyerror(char *msg)
{
printf("invaklid\n");
return 0;
}
void main()
{
printf("enter variable name\n");
yyparse();
}
