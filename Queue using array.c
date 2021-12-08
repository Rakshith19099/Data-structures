//Queue using array
#include<stdio.h>
#include<stdlib.h>

int queue, rear=0, front=0;

void dlt()
{
	if(rear==0)
	{
		printf("The queue is empty.");
	}
	
	if(rear==front+1)
	{
		rear=front=0;
		printf("The queue is empty.");
		
    }
    
	else
	{
		front++;
		printf("The front element has been removed.");
	}
}

int insert(int num)
{
	if(rear==queue)
	{
		printf("The queue is full.");
		return 0;
	}
	rear++;
	return num;

}

main()
{
	int operation, num, i;
	printf("Enter the size of the queue required.\n");
	scanf("%d", &queue);
	int s[queue];
	for(;;)
	{
		//loop:
		printf("\nEnter the operation to be done to the queue - 1: Insert 2: Delete 3: Display stack items 4: Exit\n");
		scanf("%d", &operation);
		switch(operation)
		{
			case 1:
				
				printf("Enter the integer to be stored\n");
				scanf("%d", &num);
				s[rear]=insert(num);
				break;
			case 2:
				dlt();	
				break;
			case 3:
				if(rear==0)
				{
					printf("The queue is empty.");
				}
				else
				{
				printf("The queue is:\n");
				printf("|");
				for(i=front; i<rear; i++)
				{
					printf(" %d |", s[i]);
				}
				break;
			default:
				exit(0);	
					
		}
		
	}
	
	
}
}


