/*Josephus Circle implementation
There are n people standing in a circle waiting to be executed. 
The counting out begins at some point in the circle and proceeds around the circle in a fixed direction. 
In each step, a certain number of people are skipped and the next person is executed. 
The elimination proceeds around the circle (which is becoming smaller and smaller as the executed people are removed), 
until only the last person remains, who is given freedom. 
Given the total number of person n and a number k which indicates that k-1 persons are skipped and the kth person is killed in the circle. 
The task is to choose the place in the initial circle so that you are the last one remaining and so survive. (0-based indexing) .
*/


/*
Name : Ritesh D Ambhore
Roll No : 2011
Batch : S1
Class : SY-A
*/

#include <stdio.h>
#include <stdlib.h>  // library to use malloc and free (dynamic memory allocation and deallocation)

struct node // structure to define the node of the linked list
{
    int data;  // data
    struct node *next;  // pointer to next node
};

typedef struct node NODE;  // type definition

NODE *create(NODE* start, int n) // function to create a circular linked list with n nodes
{
    NODE *last = start;  // pointer to keep track of the last node
    for (int i = 0; i < n; i++)
    {
        NODE *p = (NODE *)malloc(sizeof(NODE));
        p->data = i;
        p->next = NULL;
        if (start == NULL)
        {
            start = p;
        }
        else
        {
            last->next = p;
        }
        last = p;
    }
    last->next = start;  // this statement is used to convert the linked list into circular linked list
    return start;  // returning the list
}


//Josephus Number Implementation
int josephusNumber(NODE *start, int n, int k)
{
    if (k == 1)
        return n - 1;

    NODE *temp = start;

    while (temp->next != temp)  // this loop will continue until there is only one node left in the list
    {
        for (int i = 1; i < k - 1; i++) // to skip k-1 nodes
        {
            temp = temp->next; 
        }
        NODE *next = temp->next;
        temp->next = temp->next->next;  // assigning k-1 nodes's next to k+1 node
        printf("%d is eliminated\n", next->data);
        free(next);  // eliminating kth node
        temp = temp->next;  // changing the temp to its next and performing the loop
    }
    return temp->data;  // returning the data of the last remaining node
}

void freeList(NODE *start)  // this function is used to free dynamically allocated memory
{
    if (start == NULL)
        return;

    NODE *temp = start;
    do
    {
        NODE *next = temp->next;
        free(temp);
        temp = next;
    } while (temp != start);
}

void traverse(NODE *start)  // function to traverse the circular list
{
    printf("\nTraverse : \n");
    NODE *curr = start;
    do
    {
        printf("%d\t", curr->data);
        curr = curr->next;
    }while (curr != start);
    printf("\n\n");
}

int main()  // Main Function
{
    NODE* start = NULL; // initially start is NULL
    printf("Enter number of peoples : ");
    int n;  // taking input from the user for number peoples to be executed
    scanf("%d", &n);
    int k;  
    printf("Enter count to choose next : ");
    scanf("%d", &k); // taking input to choose the next person to eliminate
    start = create(start, n);
    traverse(start);
    printf("\nJosephus Number Implementation\n");
    printf("\n%d is the last one remaining!\n",josephusNumber(start, n, k));  // calling Josephus Number function
    freeList(start);
    return 0;
}

/*
            OUTPUT RESULT
---------------------------------------

Enter number of peoples : 4
Enter count to choose next : 2

Traverse : 
0       1       2       3


Josephus Number Implementation
1 is eliminated
3 is eliminated
2 is eliminated

0 is the last one remaining!
--------------------------------------

Enter number of peoples : 5
Enter count to choose next : 3

Traverse :
0       1       2       3       4


Josephus Number Implementation
2 is eliminated
0 is eliminated
4 is eliminated
1 is eliminated

3 is the last one remaining!

*/