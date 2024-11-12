#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;

void input(NODE **p)
{
    *p = (NODE *)malloc(sizeof(NODE));
    if (*p == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    printf("Enter Data for the Node: ");
    scanf("%d", &(*p)->data);
    (*p)->next = NULL;
}

void createAtStart(NODE **start)
{
    NODE *p;
    input(&p);
    if (*start == NULL)
    {
        *start = p;
    }
    else
    {
        p->next = *start;
        *start = p;
    }
}

void createAtEnd(NODE **start)
{
    NODE *p;
    input(&p);
    if (*start == NULL)
    {
        *start = p;
    }
    else
    {
        NODE *q = *start;
        while (q->next != NULL)
        {
            q = q->next;
        }
        q->next = p;
    }
}

void createAtLoc(NODE **start)
{
    int loc;
    printf("Enter the location you want to add the element: ");
    scanf("%d", &loc);

    if (*start == NULL && loc == 1)
    {
        createAtStart(start);
    }
    else if (*start != NULL && loc == 1)
    {
        createAtStart(start);
    }
    else
    {
        NODE *p;
        input(&p);
        NODE *q = *start;
        int i = 1;
        while (i < loc - 1 && q != NULL)
        {
            q = q->next;
            i++;
        }
        if (q != NULL)
        {
            p->next = q->next;
            q->next = p;
        }
        else
        {
            printf("\nInvalid Location!\n");
        }
    }
}

NODE *alternateNodes(NODE *start1, NODE *start2)
{
    NODE *mergedList = NULL;
    NODE **current = &mergedList;
    NODE *temp1 = start1;
    NODE *temp2 = start2;

    while (temp1 != NULL || temp2 != NULL)
    {
        if (temp1 != NULL)
        {
            NODE *newNode = (NODE *)malloc(sizeof(NODE));
            newNode->data = temp1->data;
            newNode->next = NULL;
            *current = newNode;
            temp1 = temp1->next;
            current = &((*current)->next);
        }
        if (temp2 != NULL)
        {
            NODE *newNode = (NODE *)malloc(sizeof(NODE));
            newNode->data = temp2->data;
            newNode->next = NULL;
            *current = newNode;
            temp2 = temp2->next;
            current = &((*current)->next);
        }
    }
    *current = NULL; 
    return mergedList;
}

void create(NODE **start)
{
    int n;
    do
    {
        printf("\nChoose where you want to create a node \n1. At Start \n2. At End \n3. At Desired Location \n4. Exit\n\n");

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
        case 4:
            break;
        default:
            printf("\nEnter valid option!\n");
            create(start);
            break;
        }
    } while (n != 4);
}

void deleteAtStart(NODE **start)
{
    NODE *p = *start;
    *start = p->next;
    printf("%d is deleted!\n", p->data);
    free(p);
}

void deleteAtEnd(NODE **start)
{
    NODE *p = *start;
    NODE *q;
    if (p->next == NULL)
    {
        deleteAtStart(start);
    }
    else
    {
        while (p->next != NULL)
        {
            q = p;
            p = p->next;
        }
        q->next = NULL;
        printf("%d is deleted!\n", p->data);
        free(p);
    }
}

void deleteAtLoc(NODE **start)
{
    printf("Enter the location you want to perform the delete operation : ");
    int loc;
    scanf("%d", &loc);
    if (loc == 1)
    {
        deleteAtStart(start);
    }
    else
    {
        NODE *p = *start;
        NODE *q;
        int i = 1;
        while (i < loc && p != NULL)
        {
            q = p;
            p = p->next;
            i++;
        }
        if (p != NULL)
        {
            q->next = p->next;
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

void deleteNode(NODE **start)
{
    if (*start == NULL)
    {
        printf("\nList is Empty!\n");
    }
    else
    {
        int n;
        do
        {
            printf("Enter where you want to perform delete operation \n1. At Start \n2. At End \n3. At Desired Location\n4. Exit\n\n");

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
            case 4:
                break;
            default:
                printf("Enter valid location!\n");
                deleteNode(start);
                break;
            }
        } while (n != 4);
    }
}

void printList(NODE *start)
{
    if (start == NULL)
    {
        printf("List is Empty!\n");
    }
    while (start != NULL)
    {
        printf("%d\t", start->data);
        start = start->next;
    }
    printf("\n");
}

void traverse(NODE *start1, NODE *start2)
{
    printf("\nElements in the first list:\n");
    printList(start1);
    printf("\nElements in the second list:\n");
    printList(start2);
}

void freeList(NODE **start)
{
    if (start == NULL || *start == NULL)
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

int main()
{
    NODE *start1 = NULL;
    NODE *start2 = NULL;
    NODE *mergedList;
    int ch;
    int l;

    do
    {
        printf("\nChoose operation you want to perform:");
        printf("\n1. Create Node\n2. Traverse\n3. MergeList (alternate nodes)\n4. Delete Node\n5. Exit\n");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter the list (1 or 2): ");
            scanf("%d", &l);
            if (l == 1)
            {
                create(&start1);
            }
            else if (l == 2)
            {
                create(&start2);
            }
            else
            {
                printf("\nEnter valid option!\n");
            }
            break;
        case 2:
            traverse(start1, start2);
            break;
        case 3:
            mergedList = alternateNodes(start1, start2);
            printf("\nMerged List:\n");
            printList(mergedList);
            freeList(&mergedList);
            break;
        case 4:
            printf("Enter the list (1 or 2): ");
            scanf("%d", &l);
            int a;
            if (l == 1)
            {
                printf("Do you wanna delete entire list ");
                printf("\nEnter 1 to delete entire list : ");
                scanf("%d", &a);
                if (a==1) freeList(&start1);
                else
                deleteNode(&start1);
            }
            else if (l == 2)
            {
                printf("Do you wanna delete entire list ");
                printf("\nEnter 1 to delete entire list : ");
                scanf("%d", &a);
                if (a==1) freeList(&start2);
                else
                deleteNode(&start2);
            }
            else
            {
                printf("\nEnter valid option!\n");
            }
            break;
        case 5:
            printf("\nThank You!\n");
            break;
        default:
            printf("\nChoose Valid Option!\n");
            break;
        }
    } while (ch != 5);

    freeList(&start1);
    freeList(&start2);

    return 0;
}
