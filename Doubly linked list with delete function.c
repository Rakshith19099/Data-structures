#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

#define MALLOC(p, n, type)\
p=(type*)malloc(n*sizeof(type));\
if(p==NULL)\
{\
	printf("Memory allocation failed\n");\
}

typedef struct node{
	int info;
	struct node* rlink;
	struct node* llink;
} *NODE;

NODE dlt(int num, NODE head)
{
	NODE cur, prev, next;
	next=head->rlink;
	if(head->rlink==head)
	{
		printf("The list is empty\n");
		return head;
	}
	while(next!=head)
	{
		if(next->info==num)
		{
			cur=next->rlink;
			prev->rlink=cur;
			cur->llink=prev;
			return head;
			break;
		}
		prev=next;
		next=next->rlink;	
	}
	
}

NODE add(int num, NODE head)
{
	NODE cur, temp;
	temp=MALLOC(temp, 1, struct node);
	temp->info=num;
	cur=head->llink;
	
	cur->rlink=temp;
	temp->llink=cur;
	head->llink=temp;
	temp->rlink=head;
	return head;
}

void display(NODE head)
{
	NODE temp;
	if(head->rlink==head)
	{
		printf("The list is empty\n");
		return;
	}
	printf("The elements of the list are:\n");
	temp=head->rlink;
	while(temp!=head)
	{
	printf("%d\n", temp->info);
	temp=temp->rlink;
    } 	
	
}

main()
{
	int option, num;
	NODE head;
	
	MALLOC(head, 1, struct node);
	head->rlink=head;
	head->llink=head;
	for(;;)
	{
	printf("Choose an option:\n1: Insert new node  2: Display Linked list    3: Delete element    4: Quit\n");
	scanf("%d", &option);
	switch(option)
	{
		case 1:			
			printf("Enter the number\n");
			scanf("%d", &num);
			head=add(num, head);
			break;
		
		case 2:
			display(head);
			break;
			
		case 3:
			printf("Enter the number to be deleted\n");
			scanf("%d", &num);
			head=dlt(num, head);
		
		default:
			exit(0);
	}
	
    }
}
