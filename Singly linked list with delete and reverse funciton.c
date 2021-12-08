#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

// Let us define a macro MALLOC to make the job of dynamic memory allocation using the malloc() function easier
#define MALLOC(p, n, type)\
p=(type *)malloc(n*sizeof(type));\
if(p==NULL)\
{\
	printf("Memory allocation failed\n");\
	exit(0);\
}

struct node{
	int info;
	struct node *link;
};

typedef struct node* NODE;

NODE add(int num, NODE first)
{
	NODE temp;
	MALLOC(temp, 1, struct node);
	temp->info=num;
	temp->link=first;
	return temp;
}

void display(NODE first)
{
	NODE temp;
	temp=first;
	if(first==NULL)
	{
		printf("The list is empty\n");
		return;
	}
	printf("The elements of the list are:\n");
	while(temp!=NULL)
	{
	printf("%d\n", temp->info);
	temp=temp->link;
    } 
	
}

void dlt(int num, NODE first)
{
	NODE prev;
	NODE temp;
	prev=first;
	temp=first->link;
	if(first->info==num)
	{
		free(first);
		first=temp;
		return;
		
	}
	
	
	while(1)
	{
		if(temp->info==num)
		{
			prev->link=temp->link;	
			break;
		}
		temp=temp->link;
		prev=prev->link;
		
	}
	
}

main()
{
	int option, num;
	NODE first=NULL;
	for(;;)
	{
	printf("Choose an option:\n1: Insert   2: Delete  3: Display  4: Reverse linked list  5: Quit\n");
	scanf("%d", &option);
	switch(option)
	{
		case 1:			
			printf("Enter the number\n");
			scanf("%d", &num);
			first=add(num, first);
			break;
				
		case 2:
			printf("Enter the number\n");
			scanf("%d", &num);
			dlt(num, first);
		//	break;
		
		case 3:
			display(first);
			break;
			
		case 4:
			goto reverse;
			
		case 5:
			exit(0);	
				
			
			
	}
	
    }
    reverse:
    	{
    	NODE prev, temp, newfirst=NULL, criteria;
    	criteria=NULL; 	
    	for(;;)
    	{
    		prev=first;
    		temp=first->link;
    		
    		for(;;)
    		{
    			if(temp==criteria)
    			{
    				newfirst=add(prev->info, newfirst);
    				criteria=prev;
					break;	
    			}
    			prev=prev->link;
    			temp=temp->link;
    		}	
    		if(prev==first)
    		{
    			display(newfirst);
    			exit(0);
    		}
    	}
   		}
}
