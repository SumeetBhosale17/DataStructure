#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node* next;
} NODE;

void push(NODE** top)
{
    NODE* new_node = (NODE*)malloc(sizeof(NODE));
    printf("Enter Data : ");
    scanf("%d", &new_node->data);
    if (*top == NULL)
    {
        *top = new_node;
        (*top)->next = NULL;
    }
    else
    {
        new_node->next = *top;
        (*top) = new_node;
    }
}

void pop(NODE** top)
{
    if (*top == NULL)
    {
        printf("Stack is Empty\n"); return;
    }
    printf("%d is popped", (*top)->data);
    NODE* temp = *top;
    *top = (*top)->next;
    free(temp);
}

void topOfStack(NODE* top)
{
    if (top == NULL)
    {
        printf("Stack is Empty\n"); return;
    }
    printf("Top of the Stack : %d", top->data);
}

void traverse(NODE* stack)
{
    if (stack == NULL)
    {
        printf("Stack is Empty\n"); return;
    }
    while(stack != NULL)
    {
        printf("%d\t", stack->data);
        stack = stack->next;
    }
}

int main()
{
    NODE* top = NULL;
    int ch;
    do
    {
        printf("\n1. Push\n2. Pop\n3. Top of Stack\n4. Traverse\n5. Exit\n");
        printf("Choose Option : ");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1 : push(&top);break;
            case 2 : pop(&top);break;
            case 3 : topOfStack(top); break;
            case 4 : traverse(top); break;
            case 5 : printf("Exiting....."); break;
            default : printf("Enter Valid Option!");
        }
    }while(ch != 5);

    while(top != NULL)
    {
        NODE* temp = top;
        top = top->next;
        free(temp);
    }
    return 0;
}