#include<stdio.h>
#include<string.h>

main()
{
	int i;
	char name[] = "rakshith";
	
	printf("The given string is: ");
	for(i=0; i<strlen(name); i++)
	{
		printf("%c", name[i]);
	}
	
	printf("\nThe reverse of this string is: ");
	for(i=strlen(name)-1; i>=0 ; i--)
	{
		printf("%c", name[i]);
	}
}
