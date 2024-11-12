/*
Given a number n, write a function that generates and prints all binary numbers with decimal values from 1 to n.

Examples:

Input: n = 2

Output: 1, 10

Input: n = 5

Output: 1, 10, 11, 100, 101
*/

#include <stdio.h>

int generateBinary(int n)
{
    int binary = 0;
    int multiplier = 1;
    while(n)
    {
        int rem = n%2;
        binary = (rem * multiplier) + binary;
        n /= 2;
        multiplier *= 10;
    }
    return binary;
}

void enqueue(int* queue, int* front, int* rear, int size, int data)
{
    if(*front == ((*rear)+1) % size)
    {
        printf("Queue Overflow!");
        return;
    }
    if (*front == -1)
    {
        (*front)++;
    }
    (*rear) = ((*rear)+1) % size;
    queue[*rear] = data;
}

int dequeue(int* queue, int* front, int* rear, int size)
{
    if (*front == -1)
    {
        printf("Queue Underflow!");
    }
    else
    {
        int data =  queue[*front];
        *front =  ((*front)+1) % size;
        if (*front == ((*rear)+1) % size)
        {
            *front =  -1;
            *rear = -1;
        }
        return data;
    }
}

void binaryQueue(int* queue, int* front, int* rear, int size, int n)
{
    for (int i = 1; i<=n; i++)
    {
        enqueue(queue, front, rear, size, generateBinary(i));
    }
}

void printBinary(int*  queue, int* front, int* rear, int size, int n)
{
    for (int i = 0; i<n; i++)
    {
        printf("%d", dequeue(queue, front, rear, size));
        if(i < n-1)
            printf(", ");
    }
    printf("\n");
}

int main()
{
    int queue[20];
    int front = -1, rear = -1;
    printf("Enter the number : ");
    int n;
    scanf("%d", &n);
    binaryQueue(queue, &front, &rear, n, n);
    printf("Binary Queue : ");
    printBinary(queue, &front, &rear, n, n);
    return 0;
}