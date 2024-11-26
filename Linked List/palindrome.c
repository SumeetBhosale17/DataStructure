#include <stdio.h>
#include <stdlib.h>

typedef struct node 
{
    int data;
    struct Node *next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert node at the end
void insertNode(Node** head_ref, int data) {
    Node* newNode = createNode(data);
    if (*head_ref == NULL) {
        *head_ref = newNode;
        return;
    }
    Node* temp = *head_ref;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

// Function to print the linked list
void printList(Node* head) {
    Node* temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void freeList(Node* head) {
    Node* temp;
    while(head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

Node* reverse(Node* head)
{
    Node* rev = NULL;
    Node* temp = head;;
    while(temp != NULL)
    {
        Node* next = temp->next;
        temp->next = rev;
        rev = temp;
        temp = next;
    }
    return rev;
}

int isPalindrome(Node* head)
{
    Node* slow = head;
    Node* fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node* rev = reverse(slow);

    Node* first_half = head;
    Node* second_half = rev;

    int result = 1;

    while (second_half != NULL)
    {
        if (first_half->data != second_half->data) {
            result = 0;
            break;
        }
        first_half = first_half->next;
        second_half = second_half->next;
    }

    reverse(rev);

    return result;
}