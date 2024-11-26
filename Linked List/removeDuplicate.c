#include <stdio.h>
#include <stdlib.h>

typedef struct NODE
{
    int data;
    struct NODE* next;
} node;

node* createNode(int data)
{
    node* newNode = (node*)malloc(sizeof(node));
    if (newNode == NULL)
    {
        printf("Memory error\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertNode(node** start, int data)
{
    if (*start == NULL)
    {
        *start = createNode(data);
        return;
    }
    node* temp = *start;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = createNode(data);
}

void removeDuplicates(node* start)
{
    if (start == NULL)
    {
        return;
    }
    
    node* current = start;

    while (current->next != NULL)
    {
        if (current->data == current->next->data)
        {
            node* dup = current->next;
            current->next = dup->next;
            free(dup);
        }
        else 
        {
            current = current->next;
        }
    }
}

void printList(node* start)
{
    node* temp = start;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void freeList(node* start)
{
    while (start != NULL)
    {
        node* temp = start;
        start = start->next;
        free(temp);
    }
}

int main()
{
    node* start = NULL;
    int n, data;

    printf("Enter the number of element in the list : ");
    scanf("%d", &n);

    printf("Enter elements in sorted manner\n");
    for (int i = 0; i<n; i++)
    {
        printf("Element %d : ", i+1);
        scanf("%d", &data);
        insertNode(&start, data);
    }

    printf("Initial List : ");
    printList(start);

    removeDuplicates(start);

    printf("List after removing duplicates : ");
    printList(start);

    freeList(start);

    return 0;
}