#include<stdio.h>

void main(int argn, char *args[]) 
{
	int i; 
	FILE *fp; 
	fp = fopen("note.txt", "a"); 
	if(argn>2)
	{
		fprintf(fp, "**** %s ****\n", args[1]); 
		for(i=2; i<argn; i++)
		{
			if(i%10==0)
				{
				fprintf(fp, "\n"); 
			    }
			fprintf(fp, "%s", args[i]); 
		}
		fprintf(fp, "\n----------------------------------\n");
	}
	fclose(fp); 
}
