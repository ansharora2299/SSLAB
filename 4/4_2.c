#include<stdio.h>
#include<string.h>
void main()
{
	FILE *f1;
	f1=fopen("input4.txt","r");
	char type,objcode[20],progname[20],input[20];
	int sa,addr,len;
	fscanf(f1,"%c %s %x %x",&type,progname,&sa,&len);

	printf("Loading Program %s of length %06X starting at Address %06X :-\n",progname,len,sa);

	fscanf(f1,"%s",input);

	while(strcmp(input,"E")!=0)
	{
		if(strcmp(input,"T")==0)
		{
			fscanf(f1,"%X",&addr);
			fscanf(f1,"%X",&len);
			fscanf(f1,"%s",input);
		}
        printf("%06X\t%s\n",addr,input);
		addr+=strlen(input)/2;

		fscanf(f1,"%s",input);
	}
	fclose(f1);
}