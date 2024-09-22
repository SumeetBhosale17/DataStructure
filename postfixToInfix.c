#include <stdio.h>
#include <string.h>
#include <ctype.h>

void postfixToInfix(char *postfix)
{
    char stack[10][30];
    int index = 0;
    int postfixIndex = 0;
    // char operand[10];
    int i = 0;
    while (postfix[postfixIndex] != '\0')
    {
        if (postfix[postfixIndex] == ' ')
        {
            postfixIndex++;
            continue;
        }
        if (isalnum(postfix[postfixIndex]))
        {
            char operand[2];
            operand[0] = postfix[postfixIndex++];
            operand[1] = '\0';
            strcpy(stack[index++], operand);
        }
        else if (index < 2)
        {
            printf("Invalid Postfix Expression!\n");
            return;
        }
        else
        {
            char exp[30], op1[10], op2[10];
            strcpy(op2, stack[--index]);
            strcpy(op1, stack[--index]);
            sprintf(exp, "(%s %c %s)", op1, postfix[postfixIndex], op2);
            postfixIndex++;
            strcpy(stack[index++], exp);
        }
    }

    printf("\nInfix Notation : ");
    for (int i = 0; i < index; i++)
    {
        printf("%s", stack[i]);
    }
}

int infixResult(char *postfix)
{
    int result = 0;
    char stack[5];
    int index = 0;
    int i = 0;
    while (postfix[i] != '\0')
    {
        if (isdigit(postfix[i]))
        {
            stack[index++] = postfix[i++];
        }
        else if (index < 2)
        {
            printf("Invalid Postfix Expression!\n");
            return 0;
        }
        else
        {
            int operand2 = stack[--index] - '0';
            int operand1 = stack[--index] - '0';
            switch (postfix[i++])
            {
            case '+':
                result = operand1 + operand2;
                break;
            case '-':
                result = operand1 - operand2;
                break;
            case '*':
                result = operand1 * operand2;
                break;
            case '/':
                if (operand2 == 0)
                {
                    printf("Division by Zero!\n");
                    return 0;
                }
                result = operand1 / operand2;
                break;
            default:
                printf("Invalid Operator/Characters!\n");
                return -1;
                break;
            }
            stack[index++] = result + '0';
        }
    }
    return result;
}
int main()
{
    char postfix[20];
    printf("Enter a postfix expression: ");
    scanf("%s", postfix);
    postfixToInfix(postfix);
    int result = infixResult(postfix);
    printf("\nEvaluation Result : %d\n", result);
    return 0;
}