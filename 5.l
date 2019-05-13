%{
int ic=0,fc=0;
%}
%%
-?[0-9]+ {ic++;}
-?[0-9]*\.[0-9]+ {fc++;}
%%

int yywrap(void){
return 1;
}

void main(int argc, char*argv[])
{
    yyin=fopen(argv[1],"r");
    yylex();
    printf("The number of comments is : %d\n%d\n",ic,fc); 
}
