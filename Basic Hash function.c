//Basic hash function
#include<stdio.h>
#include<conio.h>

int hash(int num)
{
	return num-((num/1000)*1000);

}

main()
{
	int num;
	printf("Enter your IISER BPR role number\n");
	scanf("%d", &num);
	printf("The hash key generated for your role number is %d\n", hash(num));
}
	
