// Check whether the expression is balanced or not

/*
1. Initialize an empty stack.
2. Traverse the given expression.
3. For each opening bracket, push it onto the stack.
4. For each closing bracket, check if the stack is empty. If it is, the expression is not balanced. Otherwise, pop the stack and check if the popped bracket matches the closing bracket.
5. After traversing the expression, if the stack is empty, the expression is balanced. Otherwise, it is not.
*/
#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct 
{
    int top;
    char items[MAX];
} Stack;

void initialize(Stack* s)
{
    s->top = -1;
}

int isEmpty(Stack* s)
{
    return s->top == -1;
}

void push(Stack* s, char item)
{
    if (s->top == MAX - 1)
    {
        printf("Stack overflow!\n");
        return;
    }
    s->items[++(s->top)] = item;
}

char pop(Stack* s)
{
    if (isEmpty(s))
    {
        printf("Stack Underflow!\n");
    }
    else
    {
        return s->items[(s->top)--];
    }  
}

int isBalanced(char* exp)
{
    Stack s;
    initialize(&s);

    for (int i = 0; i<strlen(exp); i++)
    {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
        {
            push(&s, exp[i]);
        }
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            if (isEmpty(&s))
            {
                return 0;
            }
            char top = pop(&s);
            if ((exp[i] == ')' && top != '(') || (exp[i] == '}' && top != '{') || (exp[i] == ']' && top != '['))
            {
                return 0;
            }
        }
    }
    return isEmpty(&s);
}

int main()
{
    char exp[MAX];
    printf("Enter an Expression to check whether it is balanced or not : ");
    scanf("%s", exp);
    if (isBalanced(exp))
    {
        printf("The expression is balanced.\n");
    }
    else
    {
        printf("The expression is unbalanced.\n");
    }
    return 0;
}