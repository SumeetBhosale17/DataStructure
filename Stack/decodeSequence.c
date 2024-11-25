#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct 
{
    int top;
    int items[MAX];
} Stack;

void initialize(Stack* s)
{
    s->top = 1;
}

int isEmpty(Stack* s)
{
    return s->top == 1;
}

void push(Stack* s, int data)
{
    if (s->top == MAX-1)
    {
        printf("Stack Overflow!\n");
        return;
    }
    s->items[++(s->top)] = data;
}

int pop(Stack* s)
{
    if (s->top == -1)
    {
        printf("Stack Underflow!\n");
        return -1;
    }
    return s->items[(s->top)--];
}

void decodeSequence(char* sequence, char* decode)
{
    Stack s;
    initialize(&s);

    int len = strlen(sequence);
    int num = 1;
    int resIndex = 0;

    for (int i = 0; i<=len; i++)
    {
        push(&s, num++);

        if (sequence[i] == 'I' || sequence[i] == '\0')
        {
            while (!isEmpty(&s))
            {
                int val = pop(&s);
                decode[resIndex++] = '0' + val;
            }
        }
    }
    decode[resIndex] = '\0';
}

int main()
{
    char sequence[MAX];
    char decode[MAX];

    printf("Enter the sequence : ");
    scanf("%s", sequence);

    for (int i = 0; i<strlen(sequence); i++)
    {
        if (sequence[i] != 'I' && sequence[i] != 'D')
        {
            printf("Invalid character!\n");
        }
    }
    decodeSequence(sequence, decode);
    printf("Decoded sequence : %s\n", decode);
    return 0;
}