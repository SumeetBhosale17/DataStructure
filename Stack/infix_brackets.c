#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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

void push(Stack* s, char c) 
{
    if (s->top == MAX - 1) 
    {
        printf("Stack Overflow!\n");
        return;
    }
    s->items[++(s->top)] = c;
}

char pop(Stack* s) 
{
    if (isEmpty(s)) 
    {
        printf("Stack Underflow!\n");
        exit(1); // Exit or handle underflow differently
    }
    return s->items[(s->top)--];
}

char peek(Stack* s) 
{
    if (!isEmpty(s)) 
    {
        return s->items[s->top];
    }
    return '\0'; // Consider another way to indicate empty
}

int precedence(char op) 
{
    switch (op) 
    {
        case '+': 
        case '-': 
            return 1;
        case '*': 
        case '/': 
            return 2;
        default: 
            return 0;
    }
}

int isOperator(char op) 
{
    return op == '+' || op == '-' || op == '*' || op == '/';
}

void infixToPostfix(char* infix, char* postfix) 
{
    Stack s;
    initialize(&s);

    int i = 0, k = 0;

    while (infix[i] != '\0') 
    {
        if (isspace(infix[i])) 
        {
            i++;
            continue;
        }
        if (isalnum(infix[i])) 
        {
            postfix[k++] = infix[i++];
        } 
        else if (infix[i] == '(') 
        {
            push(&s, infix[i++]);
        } 
        else if (infix[i] == ')') 
        {
            while (!isEmpty(&s) && peek(&s) != '(') 
            {
                postfix[k++] = pop(&s);
            }
            if (!isEmpty(&s)) pop(&s); // Pop '('
            i++;
        } 
        else if (isOperator(infix[i])) 
        {
            while (!isEmpty(&s) && precedence(peek(&s)) >= precedence(infix[i])) 
            {
                postfix[k++] = pop(&s);
            }
            push(&s, infix[i++]);
        } 
        else 
        {
            printf("Invalid Input at '%c'!\n", infix[i]);
            exit(1);
        }
    }
    while (!isEmpty(&s)) 
    {
        if (peek(&s) == '(' || peek(&s) == ')') 
        {
            printf("Error: Mismatched parentheses!\n");
            exit(1);
        }
        postfix[k++] = pop(&s);
    }
    postfix[k] = '\0';
}

void infixToPrefix(char* infix, char* prefix) 
{
    int len = strlen(infix);
    char reversedInfix[MAX];
    int j = 0;

    for (int i = len - 1; i >= 0; i--) 
    {
        if (infix[i] == '(') 
        {
            reversedInfix[j++] = ')';
        } 
        else if (infix[i] == ')') 
        {
            reversedInfix[j++] = '(';
        } 
        else 
        {
            reversedInfix[j++] = infix[i];
        }
    }
    reversedInfix[j] = '\0';

    char postfix[MAX];
    infixToPostfix(reversedInfix, postfix);
    int postfixlen = strlen(postfix);
    j = 0;
    for (int i = postfixlen - 1; i >= 0; i--) 
    {
        prefix[j++] = postfix[i];
    }
    prefix[j] = '\0';
}

int main() 
{
    printf("Enter infix expression: ");
    char infix[MAX];
    fgets(infix, MAX, stdin);
    char postfix[MAX];
    char prefix[MAX];
    infixToPostfix(infix, postfix);
    infixToPrefix(infix, prefix);
    printf("\nPostfix Expression : %s", postfix);
    printf("\nPrefix Expression : %s", prefix);
    return 0;
}
