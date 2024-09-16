// Construct a linked list by merging alternate nodes of two linked list
// For example, if given linked list are 1,9,3 and 6,11,5 then output list shall be 1,6,9,11,3,5

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;

NODE* start1 = NULL;
NODE* start2 = NULL;

void createAtEnd(NODE** start)
{
    NODE *p = (NODE*)malloc(sizeof(NODE));
    scanf("%d", &p->data);
    if (*start == NULL)
    {
        *start = p;
        p->next = NULL;
    }
    else
    {
        NODE* q = *start;
        while(q->next != NULL)
        {
            q = q->next;
        }
        q->next = p;
        p->next = NULL;
    }
}

NODE* alternateNodes(NODE* start1, NODE* start2)
{
    NODE* mergedList = NULL;
    NODE** current = &mergedList;
    while(start1 !=NULL || start2 !=NULL)
    {
       if (start1 != NULL)
       {
            *current = start1;
            start1 = start1->next;
            current = &((*current)->next);
       }
       if (start2 != NULL)
       {
            *current = start2;
            start2 = start2->next;
            current = &((*current)->next);
       }
       
    }
    return mergedList;
}

void printList(NODE* start)
{
    while(start != NULL)
    {
        printf("%d\t", start->data);
        start = start->next;
    }
    printf("\n");
}


int main()
{
    printf("Enter how many elements in the first list : ");
    int n1;
    scanf("%d", &n1);
    for (int i = 0; i<n1; i++)
    {
        printf("Enter the Data into the list : ");
        createAtEnd(&start1);
    }
    printf("Enter how many elements in the second list : ");
    int n2;
    scanf("%d", &n2);
    for (int i = 0; i<n2; i++)
    {
        printf("Enter the Data into the list : ");
        createAtEnd(&start2);
    }

    printf("\nElements in first list : \n");
    printList(start1);
    printf("\nElements in the second list : \n");
    printList(start2);

    NODE* mergedlist = alternateNodes(start1, start2);
    printf("\nMerged List : \n");
    printList(mergedlist);
    return 0;
}

/*
------------------0UTPUT--------------------

Enter how many elements in the first list : 3
Enter the Data into the list : 1
Enter the Data into the list : 9
Enter the Data into the list : 3
Enter how many elements in the second list : 3
Enter the Data into the list : 6
Enter the Data into the list : 11
Enter the Data into the list : 5

Elements in first list : 
1	9	3	

Elements in the second list : 
6	11	5	

Merged List : 
1	6	9	11	3	5

------------------------------------------

Enter how many elements in the first list : 5
Enter the Data into the list : 1
Enter the Data into the list : 2
Enter the Data into the list : 3
Enter the Data into the list : 4
Enter the Data into the list : 5
Enter how many elements in the second list : 3
Enter the Data into the list : 6
Enter the Data into the list : 7
Enter the Data into the list : 8

Elements in first list : 
1	2	3	4	5	

Elements in the second list : 
6	7	8	

Merged List : 
1	6	2	7	3	8	4	5	


*/