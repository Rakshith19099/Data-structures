// Circular linked list
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

typedef struct node{
	int info;
	struct node *link;
} *NODE;

NODE first=NULL;
NODE last=NULL;

void add(int);
void display(void);

void main()
{
	int option, num;
	for(;;)
	{
	printf("Choose an option:\n1: Insert new node  2: Display Linked list    3: Quit\n");
	scanf("%d", &option);
	switch(option)
	{
		case 1:			
			printf("Enter the number\n");
			scanf("%d", &num);
			add(num);
			getch();
			break;
		
		case 2:
			display();
			getch();
			break;
			
		default:
			printf("In circular linked lists, we need to link the first node with the last node by storing the address of the first node in the last node. \nAdvantages of circularly linked list: \n1. For problems which requires circular data structures, circular linked lists would fit in very naturally. \n2. We can traverse through the entire list starting from any node. \nDisadvantages: \n1. Inserting a node at the beginning is harder. \n2. Finding the last node is harder because there is not NULL marking.");	
			exit(1);
			break;				
	}
	}
}

void add(int value)
{
	NODE temp;
	MALLOC(temp, 1, struct node);
	temp->info=value;
	if (first==NULL)
	{
		first=last=temp;
		temp->link=first;
	}
	else
	{
		last->link=temp;
		temp->link=first;
		last=temp;
	}
	
}

void display()
{
	NODE temp;
	if (first==NULL)
	{
		printf("The list is empty\n");
		return;
	}
	
	printf("The elements of the list are:\n");
	if (first==last)
	{
		printf("\t%d", first->info);
		return;
	}
	for(temp=first; temp!=last; temp=temp->link)
	printf("\t%d", temp->info);
	printf("\t%d", last->info);
}
