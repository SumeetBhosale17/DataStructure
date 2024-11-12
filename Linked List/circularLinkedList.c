
/*
Name : Sumeet Bhosale
Roll No. : 2021
URN : 23031024
Class : SY-A
Batch : S2
*/

#include <stdio.h>
#include <stdlib.h>  // library use malloc and free

struct node  // structure of node
{
	int data;
	struct node *next;
};

typedef struct node NODE;

NODE *start = NULL;
NODE *last = NULL;
NODE *p, *q;



void input()  // function to allocate memory for the node and take data
{
	p = (NODE*)malloc(sizeof(NODE));
	printf("Enter the data for the node : ");
	scanf("%d", &p->data);
}

void createAtStart()  // function that create node at the start of the list
{
	if (start == NULL)  //if the list is empty
	{
		p->next = p;
		start = p;
		last = p;
	}
	else   // if the list is already containing some elements
	{
		p->next = start;
		start = p;
		last->next = start;
	}
	printf("\n%d is Added at the start of the list!\n", p->data);
}

void createAtEnd()    //function for creating a node at end of the list
{
	if (start == NULL)    // if the list is empty
	{
		createAtStart();
	}
	else
	{
		p->next = start;
		last->next = p;
		last = p;
	}
	printf("\n%d is Added at the end of the list!\n", p->data);
}

void createAtLoc()  //function for creating node at certain location 
{
	printf("\nEnter location you want to add the node : ");
	int loc;
	scanf("%d", &loc);
	if (start == NULL)  //if list is empty then only first location is valid
	{
		if (loc == 1)
		{
			createAtStart();
		}
		else 
		{
			printf("\nInvalid location!\nEnter valid location!");
			createAtLoc();
		}
	}
	else 
	{
		if (loc == 1)  //if location is 1 then it is create at start
		{
			createAtStart();
		}
		else
		{
			int i = 1;
			q = start;
			do
			{
				q = q->next;
				i++;
			}while(i<loc-1 && q!=start);  // to get the 1 location less than enterred by the user 
			if (q!=start)   // if the location is invalid it will be null
			{
				p->next = q->next;
				q->next = p;
				if (last == q)  // (p->next == NULL)
				{
					last = last->next; // last = p;
				}
			}
			else
			{
				printf("Invalid location!\nEnter valid location!\n");
				createAtLoc();
			}
		}
	}
	printf("\n%d is Added at the location %d\n", p->data, loc);
}

void deleteAtStart()  // function to delete the node in 1st location
{
	p = start;
	if (start->next == start) // if there is only one element
	{
		printf("\n%d is deleted!", p->data);
		start = NULL;
		last = NULL;
		free(p);
	}
	else 
	{
		printf("\n%d is deleted!", p->data);
		start = start->next;
		last->next = start;
		free(p);
	}
}

void deleteAtEnd()   // function to delete the node at the last location
{
	if (start->next == NULL)  // if there is only one element
	{
		deleteAtStart();
	}
	else
	{
		p = last;
		q = start;
		while (q->next != p) // to get second last node
		{
			q = q->next;
		}
		printf("\n%d is deleted!", p->data);
		last = q;
		q->next = start;
		free(p);
	}
}

void deleteAtLoc()  // function to delete the node at certain location as wish by the user
{
    p = start;
	printf("Enter where you want to perform delete operation : ");
	int loc;
	scanf("%d", &loc);
	if (start->next == NULL)  // if there is only 1 element
	{
		if (loc == 1)
		{
			deleteAtStart();
		}
		else
		{
			printf("\nInvalid location\nEnter valid location!\n");
			deleteAtLoc();
		}
	}
	else if (loc == 1)
	{
		deleteAtStart();
	}
	else
	{
		int i = 1;
		p = start;
		q = start;
		do
		{
			q = p; // previous node
			p = p->next;
			i++;
		}while(i<loc && p!=start);
		if (p != start) // if the location is valid 
		{
			q->next = p->next;
			if(p->next == start)
			{
				last = q;
			}
			printf("\n%d is deleted!", p->data);
			free(p);
		}
		else
		{
			printf("\nInvalid location\nEnter valid location!\n");
			deleteAtLoc();
		}
	}
}

void create()  // combined function of create operation
{
	printf("Enter where you want to create the node \n1. At Start\n2. At End\n3. At Certain Location\n\n");
	int o;
	scanf("%d", &o);
	switch(o)
	{
		case 1 : createAtStart();
			break;
		case 2 : createAtEnd();
			break;
		case 3 : createAtLoc();
			break;
		default : printf("Enter valid option!");
			create();
			break;
	}
}


void deleteNode()  // combined function of delete operations
{
	if (start == NULL)
	{
		printf("\nList is empty!");
	}
	else 
	{
		printf("Choose where you want to perform delete operation \n1. At Start\n2. At End\n3. At certain location\n\n");
		int o;
		scanf("%d", &o);
		switch(o)
		{
			case 1 : deleteAtStart();
				break;
			case 2 : deleteAtEnd();
				break;
			case 3 : deleteAtLoc();
				break;
			default : printf("Enter valid option!");
				deleteNode();
				break; 
		}
	}
}

void traverse()  // function for traversing in the list
{
	if (start == NULL) // if list is empty 
	{
		printf("\nList is empty!");
	}
	else
	{
		q = start;
		printf("\nElements in the list : \n");
		do
		{
			printf("%d\t", q->data);
			q = q->next;
		}while(q!=start);
	}
}


int main()
{
	int ch;
    do
    {
    printf("\n\nChoose Operation you want to perform : ");
    printf("\n1. Create Node \n2. Traverse\n3. Delete\n4. Exit\n");
    scanf("%d", &ch);
    switch (ch)
    {
        case 1 : 
            input();
            create();
            break;
        case 2 : 
            traverse();
            break;
        case 3 : 
            deleteNode();
            break;
        case 4 : printf("\nThank You!");
            break;
        default : 
        	printf("Choose Valid Option!\n");
        	break;
    }
	
	}while(ch != 4);  // the program execution will exit the loop only if the enterred option is 4
    return 0;
}
