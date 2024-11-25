#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int top;
    int items[MAX];
} Stack;

// Initialize the stack
void initialize(Stack* s) {
    s->top = -1;
}

// Check if the stack is empty
int isEmpty(Stack* s) {
    return s->top == -1;
}

// Push an element onto the stack
void push(Stack* s, int x) {
    if (s->top == MAX - 1) {
        printf("Stack Overflow!\n");
        exit(1);
    }
    s->items[++(s->top)] = x;
}

// Pop an element from the stack
int pop(Stack* s) {
    if (isEmpty(s)) {
        return -1; // Indicates stack is empty
    }
    return s->items[(s->top)--];
}

// Peek the top element of the stack
int peek(Stack* s) {
    if (!isEmpty(s)) {
        return s->items[s->top];
    }
    return -1; // Indicates stack is empty
}

// Function to find the Next Greater Element for each element in the array
void nextGreaterElements(int arr[], int nge[], int n) {
    Stack s;
    initialize(&s);
    
    // Traverse the array from right to left
    for(int i = n - 1; i >= 0; i--) {
        // Pop elements from the stack that are less than or equal to arr[i]
        while(!isEmpty(&s) && peek(&s) <= arr[i]) {
            pop(&s);
        }
        
        // If stack is not empty, the top element is the NGE
        if(!isEmpty(&s)) {
            nge[i] = peek(&s);
        }
        else {
            nge[i] = -1;
        }
        
        // Push the current element onto the stack
        push(&s, arr[i]);
    }
}

int main() {
    int arr[MAX];
    int nge[MAX];
    int n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    if(n <= 0 || n > MAX) {
        printf("Invalid number of elements. Must be between 1 and %d.\n", MAX);
        return 1;
    }

    printf("Enter %d elements: ", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    nextGreaterElements(arr, nge, n);

    printf("Next Greater Elements: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", nge[i]);
    }
    printf("\n");

    return 0;
}