#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int precedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
}

void infixToPostfix(char *infix)
{
    char stack[20][20];
    int stackIndex = 0;
    char operator[20];
    int operatorIndex = 0;
    int i = 0;

    while (infix[i] != '\0')
    {
        if (infix[i] == ' ')
            continue;
        if (infix[i] >= '0' && infix[i] <= '9')
        {
            char num[20];
            int j = 0;
            while (isdigit(infix[i]))
            {
                num[j++] = infix[i++];
            }
            num[j] = '\0';
            strcpy(stack[stackIndex++], num);
        }
        else if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/')
        {
            while (operatorIndex > 0 && precedence(operator[operatorIndex - 1]) >= precedence(infix[i]))
            {
                char op2[20], op1[20];
                strcpy(op2, stack[--stackIndex]);
                strcpy(op1, stack[--stackIndex]);
                sprintf(stack[stackIndex++], "%s %s %c", op1, op2, operator[--operatorIndex]);
            }
            operator[operatorIndex++] = infix[i++];
        }
        else
        {
            printf("Invalid Expression!\n");
            return;
        }
    }

    while (operatorIndex > 0)
    {
        char op2[20], op1[20];
        strcpy(op2, stack[--stackIndex]);
        strcpy(op1, stack[--stackIndex]);
        sprintf(stack[stackIndex++], "%s %s %c", op1, op2, operator[--operatorIndex]);
    }

    printf("Postfix Expression: %s\n", stack[0]);
}

void infixToPrefix(char *infix)
{
    char stack[20][20];
    int stackIndex = 0;
    char operator[20];
    int operatorIndex = 0;
    int i = 0;

    while (infix[i] != '\0')
    {
        if (infix[i] == ' ')
            continue;
        if (infix[i] >= '0' && infix[i] <= '9')
        {
            char num[20];
            int j = 0;
            while (isdigit(infix[i]))
            {
                num[j++] = infix[i++];
            }
            num[j] = '\0';
            strcpy(stack[stackIndex++], num);
        }
        else if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/')
        {
            while (operatorIndex > 0 && precedence(operator[operatorIndex - 1]) >= precedence(infix[i]))
            {
                char op2[20], op1[20];
                strcpy(op2, stack[--stackIndex]);
                strcpy(op1, stack[--stackIndex]);
                sprintf(stack[stackIndex++], "%c %s %s", operator[--operatorIndex], op1, op2);
            }
            operator[operatorIndex++] = infix[i++];
        }
        else
        {
            printf("Invalid Expression!\n");
            return;
        }
    }

    while (operatorIndex > 0)
    {
        char op2[20], op1[20];
        strcpy(op2, stack[--stackIndex]);
        strcpy(op1, stack[--stackIndex]);
        sprintf(stack[stackIndex++], "%c %s %s", operator[--operatorIndex], op1, op2);
    }

    printf("Prefix Expression: %s\n", stack[0]);
}

int cal(int op1, char op, int op2)
{
    switch (op)
    {
    case '+':
        return op1 + op2;
        break;
    case '-':
        return op1 - op2;
        break;
    case '*':
        return op1 * op2;
        break;
    case '/':
        if (op2 == 0)
        {
            printf("Division by Zero!");
        }
        return op1 / op2;
        break;
    }
}

int evaluationResult(char *infix) {
    char stack[50][10]; // Stack for operands
    int stackIndex = 0;
    char operator[50];
    int operatorIndex = 0;

    for (int i = 0; infix[i] != '\0'; i++) {
        if (isspace(infix[i])) continue;
        if (isdigit(infix[i])) {
            char num[10];
            int j = 0;
            while (isdigit(infix[i])) {
                num[j++] = infix[i++];
            }
            num[j] = '\0';
            strcpy(stack[stackIndex++], num);
            i--; // Adjust for loop increment
        } else if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/') {
            while (operatorIndex > 0 && 
                   precedence(operator[operatorIndex - 1]) >= precedence(infix[i])) {
                // Evaluate operators of the same precedence in left-to-right order
                int op2 = atoi(stack[--stackIndex]);
                int op1 = atoi(stack[--stackIndex]);
                int result = cal(op1, operator[--operatorIndex], op2);
                sprintf(stack[stackIndex++], "%d", result);
            }
            operator[operatorIndex++] = infix[i];
        }
    }
    
    // Evaluate remaining operators in the stack
    while (operatorIndex > 0) {
        // For left-to-right evaluation, we will always take the first operator
        int op2 = atoi(stack[--stackIndex]);
        int op1 = atoi(stack[--stackIndex]);
        int result = cal(op1, operator[--operatorIndex], op2);
        sprintf(stack[stackIndex++], "%d", result);
    }

    return atoi(stack[0]);
}


int main()
{
    printf("Enter Infix Expression: ");
    char infix[50];
    scanf("%s", infix);
    infixToPostfix(infix);
    infixToPrefix(infix);
    int result = evaluationResult(infix);
    printf("\nEvaluation Result : %d", result);
    return 0;
}