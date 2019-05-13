%{
int vc=0,cc=0,nc=0,lc=0,sc=0;
%}
%%
[ ] {;}
[aeiouAEIOU] {vc++;}
[a-zA-Z] {cc++;}
[0-9]+ {nc++;}
\n {lc++;}
. {sc++;}
%%

int yywrap(void){
return 1;
}

void main(int argc, char*argv[])
{
    yyin=fopen(argv[1],"r");
    yylex();
    printf("The number of comments is : %d\n%d\n%d\n%d\n%d\n",vc,cc,nc,lc,sc); 
}
