// Program to find factorial of a number using recursion in C.
/*
Name : Sumeet Bhosale
Roll No. : 2021
Class : SY - A
Batch : S2
*/

#include <stdio.h>
int fact(int n)
{
    if (n == 1 || n == 0)
    {
        return 1;
    }
    else
    {
        return n*fact(n-1);
    }
}
int main()
{
    printf("Enter the number to find factorial : ");
    int n;
    scanf("%d", &n);
    printf("%d! = %d", n, fact(n));
    return 0;
}

/*
---------------------------------OUTPUT-------------------------------

Enter the number to find factorial : 5
5! = 120

*/