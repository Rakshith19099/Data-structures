//Stack using linked list
#include<stdio.h>
#include<stdlib.h>

#define MALLOC(p, n, type)\
p=(type *)malloc(n*sizeof(type));\
if(p==NULL)\
{\
	printf("Memory allocation failed\n");\
	exit(0);\
}

struct stack{
	int info;
	struct node *rlink;
};

typedef struct stack* STACK;

STACK add(int num, STACK top)
{
	STACK temp;
	MALLOC(temp, 1, struct stack);
	temp->info=num;
	temp->rlink=top;
	top=temp;
	return temp;
}

void display(STACK top)
{
	STACK temp;
	temp=top;
	if(top==NULL)
	{
		printf("The list is empty\n");
		return;
	}
	printf("The stack is:\n");
	while(temp!=NULL)
	{
	printf("%d\n", temp->info);
	temp=temp->rlink;
    } 
	
}

STACK dlt(STACK top)
{
	top=top->rlink;
	printf("The top element has been popped\n");
	return top;
}

main()
{
	int option, num;
	STACK top=NULL;
	for(;;)
	{
	printf("Choose an option:\n1: Push   2: Pop  3: Display stack  4: Quit\n");
	scanf("%d", &option);
	switch(option)
	{
		case 1:			
			printf("Enter the number\n");
			scanf("%d", &num);
			top=add(num, top);
			break;
				
		case 2:
			top=dlt(top);
		//	break;
		
		case 3:
			display(top);
			break;
			
		case 4:
			exit(0);	
						
	}
    }
}
