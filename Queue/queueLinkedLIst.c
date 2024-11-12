#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node* next;
} NODE;

void enqueue(NODE** front, NODE** rear)
{
    NODE* newNode =  (NODE*)malloc(sizeof(NODE));
    printf("Enter the data of the node to be enqueued : ");
    scanf("%d", &newNode->data);

    if (*front == NULL)
    {
        *front = newNode;
        *rear = newNode;
        newNode->next = NULL;
    }
    else
    {
        newNode->next = NULL;
        (*rear)->next = newNode;
        *rear = newNode;
    }
}

void dequeue(NODE** front, NODE** rear)
{
    if (*front == NULL)
    {
        printf("Queue Underflow!");
        return;
    }
    printf("%d is dequeued!", (*front)->data);
    NODE* temp = *front;
    *front = (*front)->next;
    free(temp);
}

void traverse(NODE* front)
{
    if (front == NULL)
    {
        printf("Queue is Empty!");
        return;
    }
    while(front != NULL)
    {
        printf("%d\t", front->data);
        front = front->next;
    }
}

int main()
{
    NODE* front = NULL;
    NODE* rear = NULL;
    int choice;
    do 
    {
        printf("Menu\n");
        printf("1. Enqueue\n2. Dequeue\n3. Traverse\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1 : enqueue(&front, &rear); break;
            case 2 : dequeue(&front, &rear); break;
            case 3 : traverse(front); break;
            case 4 : printf("Exiting.."); break;
            default : printf("Invalid choice\n");
        }
    }while(choice != 4);

    while(front != NULL)
    {
        NODE* temp = front;
        front = front->next;
        free(temp);
    }
    return 0;
}