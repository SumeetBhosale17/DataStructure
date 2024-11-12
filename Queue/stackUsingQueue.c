/*
Implement Stack using Queues
Given a Queue data structure that supports standard operations like enqueue() and dequeue(). 
The task is to implement a Stack data structure using Queue.
*/

/*
Name : Sumeet Sambhaji Bhosale
Roll No : 2021
URN : 23031024
Class : SY-A
Batch : S2
*/

#include <stdio.h>  // standard input/output library
#include <stdlib.h> // include this library to the malloc and free functions which is used for dynamic allocation and deallocation

struct node  // structure definition for node 
{
    int data;   // data 
    struct node* next;  // pointer to next node
};

typedef struct node queue;  // type defined struct node as queue

queue* createNode()  // this function will create a node and allocate memory for the node
{
    queue* node = (queue*)malloc(sizeof(queue));
    return node;
}

void inputData(queue* node)  // this function will take input for the data and store it in the data member of the node
{
    printf("Enter the Data : ");
    scanf("%d", &node->data);
}

void enqueue(queue** front, queue** rear, queue* node)  // This the basic enqueue function that will add the node to end of the list as in the queue
{
    node->next = NULL;
    if (*front == NULL)  // if the stack is empty
    {
        *front = node;
        *rear = node;
    }
    else
    {
        (*rear)->next = node;
        *rear = node;
    }
}

void push(queue** front, queue** rear)  // This function will perform push operation, it will create a node, take input and add to the stack/queue/list
{
    queue* node = createNode(); // to create a node
    inputData(node); // to take input
    enqueue(front, rear, node); // this function is called to add the node to stack
}

// the below function is similiar to dequeue operation of the queue
queue* dequeue(queue** front, queue** rear)  // This is the function to perform dequeue operation that will delete the node at the start of the List as queue works on FIFO principle
{
    if (*front == NULL) // if the list is empty it will print as stack is empty
    {
        printf("Stack Underflow!\n");
        return NULL;
    }
    queue* temp = *front;
    if (*front == *rear) 
    {
        *rear = NULL;
    }
    *front = (*front)->next;  // this will shift the front to the next node
    return temp;  // this will return the initial first node in the list
}

void traverse(queue* front)  // this is the function to traverse the stack/queue
{
    if (front == NULL)  // if the list is empty
    {
        printf("Stack is Empty!");
        return;
    }
    queue* temp = front;
    printf("\nStack Elements : ");
    while(temp != NULL)
    {
        printf("%d\t", temp->data);   // printing the stack elements one by one
        temp = temp->next;
    }
    printf("\n");
}


//The below function is to perform pop operation of the stack
// What I intented to do was to perform dequeue and enqueue until the last node comes to first position and delete it from the list this way the last element is deleted following the principle of LIFO
void pop(queue** front, queue** rear)  
{
    if (*front == NULL)   // popping if the stack is empty will result into stack underflow
    {
        printf("Stack Underflow!");
        return;
    }
    queue* last = *rear;
    while(last != *front)  // the repeated cycle of dequeue and enqueue until the last node reaches to first
    {
        queue* temp = dequeue(front, rear);
        enqueue(front, rear, temp);
    }
    queue* temp = dequeue(front, rear);  // now the last node has come to the first position, I will remove it from the list using dequeue
    printf("\n%d is popped!\n", temp->data); // to print the popping data
    free(temp); // finally deallocate the memory used for it
}

void freeNodes(queue* front)  // this function frees the dynamically allocated memory used for nodes
{
    while(front != NULL)
    {
        queue* temp = front;
        front = front->next;
        free(temp);
    }
}

void tos(queue* rear)  // function to print the top of the stack
{
    if (rear == NULL)
    {
        printf("Stack is Empty!");
        return;
    }
    printf("\nTop of the Stack : ");
    printf("%d\n", rear->data);  
}

int main()   // Main Function of the Program
{
    int x;
    queue* front = NULL;   // front pointer declaration
    queue* rear = NULL;    // rear pointer declaration
    // Menu driven Program
    do  
    {
        printf("\n\nChoose Operation\n1. Push\n2. Pop\n3. TOS\n4. Traverse\n5. Exit\n");
        scanf("%d", &x);
        switch(x)
        {
            case 1 : push(&front, &rear);   // calling push function
                break;
            case 2 : pop(&front, &rear);    // calling pop function
                break;
            case 3 : tos(rear);    // calling tos 
                break;
            case 4 : traverse(front);  // traversing
                break;
            case 5 : printf("\nExiting..!");
                break;
            default : printf("Choose Valid Option!");  // this will be executed if the user didnot enter valid option
                break;
        }
    } while (x != 5);  // this loop will run until the user input 5 
    freeNodes(front);  // calling freeNodes() to free all dynamically allocated memory
    return 0;
}

/*
---------------------------SAMPLE OUTPUT---------------------------

Choose Operation
1. Push
2. Pop
3. TOS
4. Traverse
5. Exit
4
Stack is Empty!

Choose Operation
1. Push
2. Pop
3. TOS
4. Traverse
5. Exit
2
Stack Underflow!

Choose Operation
1. Push
2. Pop
3. TOS
4. Traverse
5. Exit
3
Stack is Empty!

Choose Operation
1. Push
2. Pop
3. TOS
4. Traverse
5. Exit
1
Enter the Data : 10


Choose Operation
1. Push
2. Pop
3. TOS
4. Traverse
5. Exit
3

Top of the Stack : 10


Choose Operation
1. Push
2. Pop
3. TOS
4. Traverse
5. Exit
4

Stack Elements : 10


Choose Operation
1. Push
2. Pop
3. TOS
4. Traverse
5. Exit
2

10 is popped!


Choose Operation
1. Push
2. Pop
3. TOS
4. Traverse
5. Exit
1
Enter the Data : 10


Choose Operation
1. Push
2. Pop
3. TOS
4. Traverse
5. Exit
1
Enter the Data : 20


Choose Operation
1. Push
2. Pop
3. TOS
4. Traverse
5. Exit
3

Top of the Stack : 20


Choose Operation
1. Push
2. Pop
3. TOS
4. Traverse
5. Exit
4

Stack Elements : 10     20


Choose Operation
1. Push
2. Pop
3. TOS
4. Traverse
5. Exit
2

20 is popped!


Choose Operation
1. Push
2. Pop
3. TOS
4. Traverse
5. Exit
3

Top of the Stack : 10


Choose Operation
1. Push
2. Pop
3. TOS
4. Traverse
5. Exit
2

10 is popped!


Choose Operation
1. Push
2. Pop
3. TOS
4. Traverse
5. Exit
5

Exiting..!

*/