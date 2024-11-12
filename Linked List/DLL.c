#include <stdio.h>
#include <stdlib.h>

struct node  // structure of node for linked list
{
	int data;
	struct node *next; // ptr to next node
	struct node *prev;  // ptr to previous node
};

typedef struct node NODE;

NODE *start = NULL, *p, *q;


void input()  // function to allocate memory for the node and take input
{
	p = (NODE*)malloc(sizeof(NODE));
	printf("Enter the data for the node : ");
	scanf("%d", &p->data);
}


void createAtStart()  // function that create node at start of the list
{
	if (start == NULL)  // if the list is empty
	{
		start = p;
		p->next = NULL;
		p->prev = NULL;
	}
	else   // if the list contains some elements
	{
		p->next = start;
		start->prev = p;
		start = p;
		p->prev = NULL;
	}
}

void createAtEnd()  // function to add node at end of the list
{
	if (start == NULL)  // if the list is empty
	{
		createAtStart(); // it is similar to create at start
	}
	else 
	{
		q = start;
		while(q->next != NULL)
		{
			q=q->next;
		}
		q->next = p;
		p->prev = q;
		p->next = NULL;
	}
}

void createAtLoc()
{
	int loc;
	printf("Enter the location you want to create the node : ");
	scanf("%d", &loc);
	if (start == NULL)
	{
		if (loc == 1)
		{
			createAtStart();
		}
		else
		{
			printf("\nList is Empty!");
			printf("\nInvalid location!");
			createAtLoc();
		}
	}
	else if (loc == 1)
	{
		createAtStart();
	}
	else
	{
		int i = 1;
		q = start;
		while (i<loc-1 && q!=NULL)
		{
			q = q->next;
			i++;
		}
		if (q != NULL)
		{
			p->next = q->next;
			if (q->next != NULL)
				q->next->prev = p;
			q->next = p;
			p->prev = q;
		}
		else
		{
			printf("\nInvalid Location!\nEnter valid location!");
			createAtLoc();
		}
	}
}

void create()
{
	printf("Choose where you want to create the node \n1. At Start\n2. At End\n3. At Prefered location\n");
	int ch;
	scanf("%d", &ch);
	switch(ch)
	{
		case 1 : createAtStart();
			break;
		case 2 : createAtEnd();
			break;
		case 3 : createAtLoc();
			break;
		default : printf("\nInvalid option!\nEnter Valid Option!\n");
			create();
			break;
	}
}

void deleteAtStart()
{
	p = start;
	start = start->next;
	if (start != NULL)
	{
		start->prev = NULL;
	}
	printf("\n%d is Deleted!", p->data);
	free(p);
}


void deleteAtEnd()
{
	p = start;
	while(p->next != NULL)
	{
		p = p->next;
	}
	if (p->prev != NULL)
	{
		p->prev->next = NULL;
	}
	else 
	{
		start = NULL;
	}
	printf("\n%d is deleted", p->data);
	free(p);
}

void deleteAtLoc()
{
	printf("Enter where you want to add the node : ");
	int loc;
	scanf("%d", &loc);
	if (loc == 1)
	{
		deleteAtStart();	
		return;	
	}
	else
	{
		int i = 1;
		p = start;
		while(i<loc && p!=NULL)
		{
			p = p->next;
			i++;
		}
		if (p!= NULL)
		{
			p->prev->next = p->next;
			if (p->next != NULL)
			{
				p->next->prev = p->prev;
			}
			printf("\n%d is deleted", p->data);
			free(p);
		}
		else
		{
			printf("\nInvalid Location!\nEnter Valid Location!");
			deleteAtLoc();
		}
	}
}

void deleteNode()
{
	if (start == NULL)
	{
		printf("\nThe List is empty!");
	}
	else
	{
		printf("Choose where you want to perform delete operation \n1. At Start\n2. At End\n3. At Prefered location\n");
		int ch;
		scanf("%d", &ch);
		switch(ch)
		{
			case 1 : deleteAtStart();
				break;
			case 2 : deleteAtEnd();
				break;
			case 3 : deleteAtLoc();
				break;
			default : printf("Invalid Choice!\n");
				deleteNode();
				break;
		}
	}
}

void traverse()
{
	if (start == NULL)
	{
		printf("\nList is Empty!");
	}
	else
	{
		q = start;
		printf("\nElements in the list : \n");
		while (q != NULL)
		{
			printf("%d\t", q->data);
			q = q->next;
		}
	}
}

int main()
{
	int o;
	do
	{
		printf("\nChooose what operation you want to perform \n1. Create\n2. Delete\n3. Traverse\n");
		scanf("%d", &o);
		switch(o)
		{
			case 1 :input(); 
				create();
				break;
			case 2 : deleteNode();
				break;
			case 3 : traverse();
				break;
			case 4 : printf("Thank You!");
				break;
			default : printf("\nChoose valid option!");
				break;
		}
	}while(o!=4);
	return 0;
}
