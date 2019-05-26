#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char a[10],b[10],c[10],k_sym[10][10],k_op[10][10];
unsigned int v_sym[10],v_op[10],loc;
int find_op(char x[])
{
	int i=0;
	for(i=0;i<10;i++)
	{
		if(strcmp(k_op[i],x)==0)
		{
			return v_op[i];
		}
	}
	return -1;
}

int find_sym(char x[])
{
	int i=0;
	for(i=0;i<10;i++)
	{
		if(strcmp(k_sym[i],x)==0)
		{
		    if(x[strlen(x)-1]=='X')
            {
                v_sym[i] = v_sym[i] + 0x8000;
            }
			return v_sym[i];
		}
	}
	return -1;
}

void main()
{
    FILE *fp1,*fp2,*fp3,*fp4;
    fp1=fopen("output1.txt","r");
    fp2=fopen("optab.txt","r");
    fp3=fopen("symtab.txt","r");
    fp4=fopen("output2.txt","w");

    int i=0;

    fscanf(fp2,"%s\t%X\n",k_op[i],&v_op[i]);
    while(!feof(fp2))
    {
    i++;
    fscanf(fp2,"%s\t%X\n",k_op[i],&v_op[i]);
    }
    fclose(fp2);

    i=0;
    fscanf(fp3,"%s\t%X\n",k_sym[i],&v_sym[i]);
    while(!feof(fp3))
    {
    i++;
    fscanf(fp3,"%s\t%X\n",k_sym[i],&v_sym[i]);
    }
    fclose(fp3);

    fscanf(fp1,"%X\t%s\t%s\t%s",&loc,a,b,c);
    fprintf(fp4,"%X\t%s\t%s\t%s\n",loc,a,b,c);

    while(strcmp(b,"END")!=0)
    {
        fscanf(fp1,"%X\t%s\t%s\t%s",&loc,a,b,c);
        if(strcmp(b,"RESB")==0 || strcmp(b,"RESW")==0 || strcmp(b,"END")==0)
        {
            fprintf(fp4,"%X\t%s\t%s\t%s\n",loc,a,b,c);
        }
        else if(strcmp(b,"WORD")==0)
        {
            unsigned int l=atoi(c);
            fprintf(fp4,"%X\t%s\t%s\t%s\t%06X\n",loc,a,b,c,l);
        }
        else if(strcmp(b,"BYTE")==0)
        {
            fprintf(fp4,"%X\t%s\t%s\t%s\t",loc,a,b,c);
            int j,k=0;
            for(j=2;j<strlen(c)-1;j++,k++)
            {
                fprintf(fp4,"%X",c[j]);
            }
            fprintf(fp4,"\n");
        }
        else if(strcmp(b,"RSUB")==0)
        {
            fprintf(fp4,"%X\t%s\t%s\t%s\t4C0000\n",loc,a,b,c);
        }
        else if(find_op(b)!=-1)
        {
            fprintf(fp4,"%X\t%s\t%s\t%s\t%02X%04X\n",loc,a,b,c,find_op(b),find_sym(c));
        }
    }

    fclose(fp4);

}
