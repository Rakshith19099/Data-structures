#include<stdio.h>
#include<stdlib.h>
 
#define MALLOC(p, n, type)\
p=(type *)malloc(n*sizeof(type));\
if(p==NULL)\
{\
	printf("Memory allocation failed\n");\
	exit(0);\
}

int count=0;

typedef struct tree{
	int info;
	struct node *rlink;
	struct node *llink;
} *NODE;



NODE insert(NODE root, int num)
{
	if(root==NULL)
	{
		MALLOC(root, 1, struct tree);
		root->llink=root->rlink=NULL;
		root->info=num;
		count=count+1;
	}
	
	else
	{
		if(count%2==0)
		{
			root->llink=insert(root->llink, num);
			
		}
		else
		{
			root->rlink=insert(root->rlink, num);
		}
	}
	return root;
}

void display(NODE root)
{
	if(root->llink!=NULL)
	display(root->llink);
	printf("%d\n", root->info);
	if(root->rlink!=NULL) 
	display(root->rlink);
}

main()
{
	int option, num;
	NODE root;
	MALLOC(root, 1, struct tree);
	root->rlink=NULL;
	root->llink=NULL;
	for(;;)
	{
	printf("Choose an option:\n1: Insert new node  2: Display binary tree  3: Quit\n");
	scanf("%d", &option);
	switch(option)
	{
		case 1:			
			printf("Enter the value to be inserted\n");
			scanf("%d", &num);
			root=insert(root, num);
			break;
		
		case 2:
			display(root);
			break;
			
		case 3:
			exit(0);
	}
    }
}
