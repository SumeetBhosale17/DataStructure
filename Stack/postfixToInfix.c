//Program to convert the postfix notation to infix notation using the concept of stack

/*
Name : Sumeet Sambhaji Bhosale
Roll No : 2021
Class : SY-A
Batch : S2
*/

/*
Algorithm :
1. Read the string elements left to right
2. If the character is an operand push it onto the stack
3. If the character is an operator then pop the stack twice, 
    the first popped operand will be the second operand
    and the second popped operand will be the first operand
4. Perform the calculation and push the result onto the stack
5. Continue the set of instructions
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to convert postfix notation to infix notation
void postfixToInfix(char *postfix)
{
    char stack[10][30];  // Stack to store the infix notation
    int index = 0;
    int postfixIndex = 0;

    while (postfix[postfixIndex] != '\0')
    {
        if (postfix[postfixIndex] == ' ')  // ignore spaces
        {
            postfixIndex++;
            continue;  // by continuing
        }
        if (isalnum(postfix[postfixIndex]))  // to check if the character is alphanumeric
        {
            char operand[2];  // used string because stack is also string
            operand[0] = postfix[postfixIndex++];
            operand[1] = '\0';  // to convert it into string
            strcpy(stack[index++], operand);
        }
        else if (index < 2)  // if there is only one operand in the stack the we cannot evaluate the operator
        {
            printf("Invalid Postfix Expression!\n");
            return;
        }
        else
        {
            char exp[30], op1[30], op2[30];  
            strcpy(op2, stack[--index]);  // popping
            strcpy(op1, stack[--index]); // popping
            sprintf(exp, "(%s %c %s)", op1, postfix[postfixIndex++], op2); 
            strcpy(stack[index++], exp);
        }
    }

    if (index != 1)  // to check whether it is valid or not
    {
        printf("Invalid Postfix Expression!\n");
        return;
    }

    printf("\nInfix Notation : %s\n", stack[0]);  
}

// Function give to result of the expression
int infixResult(char *postfix)
{
    int result = 0;  // Result initialisation
    char stack[10];  // Stack to store the operands
    int index = 0;
    int i = 0;
    while (postfix[i] != '\0')
    {
        if (isdigit(postfix[i]))
        {
            stack[index++] = postfix[i++]; // pushing operand onto the stack
        }
        else if (index < 2)
        {
            printf("Invalid Postfix Expression!\n");
            return 0;
        }
        else
        {
            int operand2 = stack[--index] - '0';  // popping
            int operand1 = stack[--index] - '0';  // popping
            switch (postfix[i++])  // performing the calculations
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
                return 0;
                break;
            }
            stack[index++] = result + '0';
        }
    }
    return result;  // returning the result
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

/*

---------------------Sample-0utput-----------------------

Enter a postfix expression: 1234*+-

Infix Notation : (1 - (2 + (3 * 4)))

Evaluation Result : -13

---------------------------------------------------------

Enter a postfix expression: 12*3+4-

Infix Notation : (((1 * 2) + 3) - 4)

Evaluation Result : 1

*/