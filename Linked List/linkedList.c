/*Write a program to perform create at start, create at end, create at given location, delete at start, 
delete at end, delete at given location and traverse for a singly linked list 
with one external reference pointer start.*/
/*
Name : Sumeet Bhosale
Roll No. : 2021
URN : 23031024
Class : SY-A
Batch : S2
*/

#include <stdio.h>
#include <stdlib.h>  //library to use malloc and free

struct node //Node for the  linked list
{
    int data; // data in the node 
    struct node *next; // pointer to the next node
};
typedef struct node NODE; // we no longer need to write struct node as we have type defined it as NODE

NODE *start = NULL;
NODE *p, *q;

void input()     // function to allocate memory for the node and take data 
{
    printf("Enter Data for the node : ");
    p = (NODE *)malloc(sizeof(NODE));
    scanf("%d", &p->data);
}
void createAtStart()    // function that create node at the start of the list
{
    if (start == NULL)  //if the list is empty
    {
        p->next = NULL;
        start = p;
    }
    else  // if the list is already containing some elements
    {
        p->next = start;
        start = p;
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
    	printf("Elements in the List : "); 
    	while (q != NULL)
    	{
        	printf("%d\t", q->data);
        	q = q->next;
    	}
	}
}

void createAtEnd()  //function for creating a node at end of the list
{
    if (start == NULL)  // if the list is empty
    {
        createAtStart();
    }
    else
    {
        q = start;
        while(q->next != NULL) //traversing to the last node of the list
        {
            q = q->next;
        }
        p->next = q->next;
        q->next = p;
    }
}


void createAtGivenLocation()  //function for creating node at certain location 
{
	printf("Enter the Location you want to add the element : ");
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
			printf("Invalid Location! \nEnter Valid Location!\n");
			createAtGivenLocation(); //calls the function until the location is 1  also no need to free p
		}
	}
	else if (loc == 1) //if location is 1 then it is create at start
	{
		createAtStart();
	}
	else
	{
		q = start;
		int i = 1;
		while (i<loc-1 && q!=NULL) // to get the 1 location less than enterred by the user 
		{
			q=q->next;
			i++;
		}
		if (q != NULL)  // if the location is invalid it will be null
		{
			p->next = q->next;
			q->next = p;
		}
		else 
		{
			printf("Invalid Location!\nEnter Valid Location!\n");
			createAtGivenLocation(); 
		}
	}
}


void create() // it contains all create functions
{
	//input();
        printf("Choose Where you want to create a node \n1. At Start \n2. At End \n3. At Desired Location \n\n");
        int n;
        scanf("%d", &n);
        switch(n)
        {
            	case 1 : createAtStart();
            		break;
            	case 2 : createAtEnd();
            		break;
            	case 3 : createAtGivenLocation();
            		break;
            	default : printf("Enter Valid Location!\n");
            		create();
            		break; 
        }
}


void deleteAtStart() // function to delete the node in 1st location
{
		p = start;
		start = start->next;
		printf("%d is deleted!\n", p->data);
		free(p);
}


void deleteAtEnd()  // function to delete the node at the last location
{
	if (start->next == NULL)  // if there is only 1 element in list
	{
		deleteAtStart();
	}
	else 
	{
		p = start;
		while (p->next != NULL) // to get last and second last node
		{
			q = p; // to get second last node
			p = p->next;
		}
		q->next = NULL;
		printf("%d is deleted!\n", p->data);
		free(p);
		
	}
	
}

void deleteAtGivenLocation()  // function to delete the node at certain location as wish by the user
{
	printf("Enter the location you want to perform the delete operation : ");
	int loc;
	scanf("%d", &loc);
	if (loc == 1)  
	{
		deleteAtStart();  // if the location is 1 then it will be delete at start
	}
	else
	{
		p = start;
		int i =1;
		while (i < loc && p!=NULL)
		{
			q = p; // previous node
			p = p->next;
			i++;
		}
		if (p!=NULL)
		{
			q->next = p->next;
			printf("%d is deleted!\n", p->data);
			free(p);
		}
		else
		{
			printf("Enter Valid Location!\n");
			deleteAtGivenLocation();
		}
	}
}


void delete() // this function contains all delete functions 
{
	if (start == NULL)  // if the list is empty there is nothing to delete
	{
		printf("The linked list is empty!\n");
	}
	else
	{
		printf("\nChoose where you want to perform delete operation \n1. At Start \n2. At End \n3. At Desired Location\n\n");
	int n;
	scanf("%d", &n);
	switch(n)
	{
		case 1 : deleteAtStart();
			break;
		case 2 : deleteAtEnd();
			break;
		case 3 : deleteAtGivenLocation();
			break;
		default : printf("Enter valid location!\n");
			delete();
			break;
	}
	}	
}



int main()   // Main function
{
    int ch;
    do
    {
    printf("\nChoose Operation you want to perform : ");
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
            delete();
            break;
        case 4 : printf("Thank You!");
            break;
        default : 
        	printf("Choose Valid Option!\n");
        	break;
    }
	
	}while(ch != 4);  // the program execution will exit the loop only if the enterred option is 4
    return 0;
}
