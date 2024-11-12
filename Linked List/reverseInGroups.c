/*
Reverse a doubly linked list in groups of K size
Given a Doubly linked list containing n nodes. The task is to reverse every group of k nodes in the list. 
If the number of nodes is not a multiple of k then left-out nodes, in the end, 
should be considered as a group and must be reversed.
*/

/*
Name : Sumeet Sambhaji Bhosale
Roll NO : 2021
URN : 23031024
Class : SY-A
Batch : S2
*/

#include <stdio.h>  // standard input/output library
#include <stdlib.h>  // library to use malloc and free functions to dynamically allocate and deallocate memory

struct node   // structure for node in the linked list
{
    int data;  //data
    struct node *next;  // pointer to next node
    struct node *prev;  // pointer to previous node
};

typedef struct node NODE;  // type defining 

void input(NODE **p)   // this is the function to allocate memory and take input for the data in the node
{
    *p = (NODE *)malloc(sizeof(NODE));
    if (*p == NULL)   // if the memmory allocation is failed by any chance
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    printf("Enter Data for the Node: ");
    scanf("%d", &(*p)->data);
    (*p)->next = NULL;
}

void createAtStart(NODE **start)   // function to create and add a node to beginning of the list
{
    NODE *p;
    input(&p);   // input function is called to allocate memory and take input for the data
    if (*start == NULL)   // case 1 : if the list is empty
    {
        *start = p;
        p->next = NULL;
        p->prev = NULL;
    }
    else  // case 2 : if the list is not empty
    {
        p->next = *start;
        (*start)->prev = p;
        *start = p;
        p->prev = NULL;  // previous is pointed to null
    }
}

void createAtEnd(NODE **start)  // function to create a node at ending of the list
{
    if (*start == NULL)  // case : if the list is empty it is similar to create at start function
    {
        createAtStart(start);
    }
    else  // case : if list is not empty
    {
        NODE *p;
        input(&p);
        NODE *q = *start;
        while (q->next != NULL)   // reaching to the final node of the list
        {
            q = q->next;
        }
        q->next = p;  // assigning the newly created node to existing last node's next
        p->prev = q;  // assigning the newly created node's prev to exsting node
        p->next = NULL;
    }
}

void createAtLoc(NODE **start)   // this is function to create a node at desired location
{
    int loc;  
    printf("Enter the location you want to add the element: ");
    scanf("%d", &loc);  // ask the user to enter the location

    if (*start == NULL && loc == 1)   // when list is empty the only valid location is first
    {
        createAtStart(start);
    }
    else if (*start != NULL && loc == 1)  // when user enter location as 1
    {
        createAtStart(start);
    }
    else
    {
        NODE *p;
        input(&p);
        NODE *q = *start;
        int i = 1;
        while (i < loc - 1 && q != NULL)  // to get the previous node
        {
            q = q->next;
            i++;
        }
        if (q != NULL)
        {
            p->next = q->next;
            if (q->next != NULL)  
            {
                q->next->prev = p;
            }
            q->next = p;
            p->prev = q;
        }
        else
        {
            printf("\nInvalid Location!\n");  // invalid location
            createAtLoc(start);
        }
    }
}

void create(NODE **start)    // this function asks the user where he want to create the location and calls the respective function 
{
    printf("\nChoose where you want to create a node \n1. At Start \n2. At End \n3. At Desired Location \n\n");
    int n;
    scanf("%d", &n);
    switch (n)
    {
        case 1:
            createAtStart(start);
            break;
        case 2:
            createAtEnd(start);
            break;
        case 3:
            createAtLoc(start);
            break;
        default:
            printf("\nEnter valid option!\n");
            create(start);
            break;
    }
}

void deleteAtStart(NODE **start)  // function to delete the node at the beginning of the list
{
    NODE *p = *start;
    *start = p->next;
    if (*start != NULL)   
    {
        (*start)->prev = NULL;  // if there is only one node in the then after deleting start becomes null, then there is nothing like null's previous
    }
    printf("%d is deleted!\n", p->data);
    free(p);
}

void deleteAtEnd(NODE **start)  // function to delete the node at ending of the list
{
    NODE *p = *start;
    if (p->next == NULL)  // if there is only one node
    {
        deleteAtStart(start);  // it is similar to deleting the node at start
    }
    else
    {
        while (p->next != NULL)  // to get the last node
        {
            p = p->next;
        }
        if (p->prev != NULL)
            p->prev->next = NULL;
        printf("%d is deleted!\n", p->data);
        free(p);
    }
}

void deleteAtLoc(NODE **start)   // function to delete the node specified by the user
{
    printf("Enter the location you want to perform the delete operation : ");
    int loc;
    scanf("%d", &loc);
    if ((*start)->next == NULL && loc == 1)  // if there is only one node then valid location is only 1
    {
        deleteAtStart(start);
    }
    else if (loc == 1)
    {
        deleteAtStart(start);
    }
    else
    {
        NODE *p = *start;
        int i = 1;
        while (i < loc && p != NULL) // to get the node
        {
            p = p->next;
            i++;
        }
        if (p != NULL)
        {
            p->prev->next = p->next;
            if (p->next != NULL)
            {
                p->next->prev = p->prev;
            }
            printf("%d is deleted!\n", p->data);
            free(p);
        }
        else
        {
            printf("Enter valid location!\n");
            deleteAtLoc(start);
        }
    }
}

void deleteNode(NODE **start)   // this function asks the user where he want to perform the delete operation and calls the respective function
{
    if (*start == NULL)  // if the list is empty, there is nothing to delete
    {
        printf("\nList is Empty!\n");
    }
    else
    {
        printf("Enter where you want to perform delete operation \n1. At Start \n2. At End \n3. At Desired Location\n\n");
        int n;
        scanf("%d", &n);
        switch (n)
        {
            case 1:
                deleteAtStart(start);
                break;
            case 2:
                deleteAtEnd(start);
                break;
            case 3:
                deleteAtLoc(start);
                break;
            default:
                printf("Enter valid location!\n");
                deleteNode(start);
                break;
        }
    }
}

void traverse(NODE *start)  // function to traverse the list
{
    if (start == NULL)  // case : if list is empty
    {
        printf("List is Empty!\n");
        return;
    }
    printf("\nElements in the List : ");
    while (start != NULL)
    {
        printf("%d\t", start->data);
        start = start->next;
    }
    printf("\n");
}


//function to reverse the list in groups of k
NODE *reverseInGroups(NODE *start, int k)
{
    NODE *temp = start;
    NODE *rev = NULL;
    NODE* last;  // pointer to keep track of the last node of the list

    if (start == NULL || k <= 1)  // if the list is empty or k is less than or equal to 1 it will return the same list
    {
        return start;
    }
    if (start->next == NULL)  // if there is only node in the list
        return start;
    int i = 1;
    last = temp; // assigning to temp node to keep track of the last node in the list as initial temp becomes the last node
    while (i <= k && temp != NULL)  // this will reverse the list for k nodes
    {
        NODE *next = temp->next;  // temporary node that is assigned by next node of the temp node
        // logic for reversing the node
        temp->next = rev;
        if (rev != NULL)
            rev->prev = temp;  // to link the prev pointer
        rev = temp;  // to keep the rev pointer to point the head of the list so that i can return it
        temp = next;  // jumping temp to its next node
        i++;  // increasing the counter
    }

    if (temp != NULL)
    {
        last->next = reverseInGroups(temp, k);  // recursively calls the function until temp node becomes null 
		if (last->next != NULL)
		{
			last->next->prev = last;  // linking the newly revered list to final list
		}
    }
    return rev;  // returning the final list
}

void freeList(NODE **start)  // this is function to free the dynamically allocated memory for the nodes of the list to avoid memory leak
{
    if (start == NULL || *start == NULL)  // if the list is empty, there is nothing to deallocate
    {
        return;
    }

    NODE *temp;
    while (*start != NULL)
    {
        temp = *start;
        *start = (*start)->next;
        free(temp);
    }
    *start = NULL;
}

//Main Program
int main()
{
    NODE *start = NULL;  // head pointer declaration
    int ch;  // choice variable 

    //menu driven approach
    do
    {
        printf("\nChoose operation you want to perform:");
        printf("\n1. Create Node\n2. Traverse\n3. Reverse nodes in groups\n4. Delete Node\n5. Exit\n");
        scanf("%d", &ch);  // asking the user what operation he wants to perform

        switch (ch)
        {
            case 1:
                create(&start);
                break;
            case 2:
                traverse(start);
                break;
            case 3:
                printf("Enter Group number (k) : ");  // asking the user to enter the number of elements in the group to reverse the list
                int k;
                scanf("%d", &k);
                // calling the function and storing the returned list in the start
                // we can also use another pointer to store the list but the existing list is modified
                // But we can create list using dynamic memory allocation, So that the existing list is not modified
                start = reverseInGroups(start, k);  
                traverse(start);
                break;
            case 4:
                deleteNode(&start);
                break;
            case 5:
                printf("\nThank You!\n");
                break;
            default:
                printf("\nChoose Valid Option!\n");
                break;
        }
    } while (ch != 5);  // this loop will keep on iterating until the user enter 5

    freeList(&start);

    return 0;
}

/*
Choose operation you want to perform:
1. Create Node
2. Traverse
3. Reverse nodes in groups
4. Delete Node
5. Exit
1

Choose where you want to create a node
1. At Start
2. At End
3. At Desired Location

2
Enter Data for the Node: 1

Choose operation you want to perform:
1. Create Node
2. Traverse
3. Reverse nodes in groups
4. Delete Node
5. Exit
1

Choose where you want to create a node
1. At Start
2. At End
3. At Desired Location

2
Enter Data for the Node: 2

Choose operation you want to perform:
1. Create Node
2. Traverse
3. Reverse nodes in groups
4. Delete Node
5. Exit
1

Choose where you want to create a node
1. At Start
2. At End
3. At Desired Location

2
Enter Data for the Node: 3

Choose operation you want to perform:
1. Create Node
2. Traverse
3. Reverse nodes in groups
4. Delete Node
5. Exit
1

Choose where you want to create a node
1. At Start
2. At End
3. At Desired Location

2
Enter Data for the Node: 4

Choose operation you want to perform:
1. Create Node
2. Traverse
3. Reverse nodes in groups
4. Delete Node
5. Exit
1

Choose where you want to create a node
1. At Start
2. At End
3. At Desired Location

2
Enter Data for the Node: 5

Choose operation you want to perform:
1. Create Node
2. Traverse
3. Reverse nodes in groups
4. Delete Node
5. Exit
1

Choose where you want to create a node
1. At Start
2. At End
3. At Desired Location

2
Enter Data for the Node: 6

Choose operation you want to perform:
1. Create Node
2. Traverse
3. Reverse nodes in groups
4. Delete Node
5. Exit
2

Elements in the List : 1        2       3       4       5       6

Choose operation you want to perform:
1. Create Node
2. Traverse
3. Reverse nodes in groups
4. Delete Node
5. Exit
3
Enter Group number (k) : 2

Elements in the List : 2        1       4       3       6       5

Choose operation you want to perform:
1. Create Node
2. Traverse
3. Reverse nodes in groups
4. Delete Node
5. Exit
2

Elements in the List : 2        1       4       3       6       5

Choose operation you want to perform:
1. Create Node
2. Traverse
3. Reverse nodes in groups
4. Delete Node
5. Exit
3
Enter Group number (k) : 2

Elements in the List : 1        2       3       4       5       6

Choose operation you want to perform:
1. Create Node
2. Traverse
3. Reverse nodes in groups
4. Delete Node
5. Exit
3
Enter Group number (k) : 3

Elements in the List : 3        2       1       6       5       4

Choose operation you want to perform:
1. Create Node
2. Traverse
3. Reverse nodes in groups
4. Delete Node
5. Exit
3
Enter Group number (k) : 3

Elements in the List : 1        2       3       4       5       6

Choose operation you want to perform:
1. Create Node
2. Traverse
3. Reverse nodes in groups
4. Delete Node
5. Exit
3
Enter Group number (k) : 4

Elements in the List : 4        3       2       1       6       5

Choose operation you want to perform:
1. Create Node
2. Traverse
3. Reverse nodes in groups
4. Delete Node
5. Exit
5

Thank You!
*/