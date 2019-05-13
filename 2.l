%{
int sc=0,mc=0,id=0,op=0;
%}
%%
[a-zA-Z0-9]+ {id++;}
[\+\-\*\/] {op++;}
"/*"[^"*/"]*"*/" {mc++;}
\/\/.* {sc++;}
. {;}
[\n] {;}
%%

int yywrap(void){
return 1;
}

void main(int argc, char*argv[])
{
    yyin=fopen(argv[1],"r");
    yylex();
    printf("The number of comments is : %d\n%d\n%d\n%d",sc,mc,id,op); 
}
