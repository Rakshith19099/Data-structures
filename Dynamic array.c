//Dynamic array using malloc
#include <stdio.h>
#include <stdlib.h>


int main()
{

	int *ptr=NULL;
	int i,len=0;

	printf("Enter the size of the array required:");	
	scanf("%d",&len);

	ptr=(int*)malloc(len*sizeof(int));

	printf("Enter the elements:");
	for(i=0;i<len;++i)
	{
		scanf("%d", &ptr[i]);
	}
	
	printf("Array elements are \n");
	for(i=0;i<len;++i)
	{		
		printf("%d,", ptr[i]);
	}
	return 0;
}
