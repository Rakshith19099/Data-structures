//Stacks using arrays
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int stack, top=-1;

void pop()
{
	if(top==-1)
	{
		printf("The stack is empty.\n");
	}
	else
	{
		top--;
		printf("The top element has been popped.\n");
	}
}

int push(int num)
{
		top++;
		return num;

}

main()
{
	int operation, num, i;
	printf("Enter the size of the stack required.\n");
	scanf("%d", &stack);
	int s[stack];
	for(;;)
	{
		loop:
		printf("Enter the operation to be done to the stack - 1: Push 2: Pop 3: Display stack items 4: Exit\n");
		scanf("%d", &operation);
		switch(operation)
		{
			case 1:
				if(top==stack-1)
				{
					printf("The stack is full.\n");
					break;
				}
				printf("Enter the integer to be stored.\n");
				scanf("%d", &num);
				s[top+1]=push(num);
				break;
			case 2:
				pop();	
				break;
			case 3:
				if(top==-1)
				{
					printf("The stack is empty.\n");
				}
				else
				{
				printf("The stack is:\n");
				for(i=top; i>=0; i--)
				{
					printf("  %d\n", s[i]);
				}
				break;
			default:
				exit(0);	
					
		}
		
	}
	
	
}
}
