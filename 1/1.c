#include<stdio.h>
#include<string.h>

void main()
{
	FILE *f1,*f2,*f3;
	f1=fopen("input1.txt","r");
	f2=fopen("symtab.txt","w");
	f3=fopen("output1.txt","w");
	int lc,sa;
	char label[20],instruction[20],operand[20];
	fscanf(f1,"%s %s %s",label,instruction,operand);

	if(strcmp(instruction,"START")==0)
	{
		sa=strtol(operand,NULL,16);
		fprintf(f3,"%X\t%s\t%s\t%s\n",sa,label,instruction,operand);
	}
	else
		sa=0;
	lc=sa;

	fscanf(f1,"%s %s %s",label,instruction,operand);
	while(strcmp(instruction,"END")!=0)
	{
		fprintf(f3,"%X\t%s\t%s\t%s\n",lc,label,instruction,operand);

		if(strcmp(label,"-")!=0)
		{
			fprintf(f2,"%s\t%X\n",label,lc);
		}

		if(strcmp(instruction,"WORD")==0)
		{
			lc+=3;
		}

		else if(strcmp(instruction,"RESW")==0)
		{
			lc=lc+(3*(strtol(operand,NULL,10)));
		}

		else if(strcmp(instruction,"RESB")==0)
		{
			lc=lc+strtol(operand,NULL,10);
		}

		else if(strcmp(instruction,"BYTE")==0)
		{
			if(operand[0]=='X')
				lc=lc+(strlen(operand)-3)/2;
			else
				lc=lc+strlen(operand)-3;
		}

		else
        {
            lc+=3;
        }

		fscanf(f1,"%s %s %s",label,instruction,operand);
	}
	fprintf(f3,"%X\t%s\t%s\t%s\n",lc,label,instruction,operand);

	fclose(f1);
	fclose(f2);
	fclose(f3);
}
