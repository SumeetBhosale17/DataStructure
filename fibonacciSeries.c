//Program to print fibonacci series using Recursion
/*
Name : Sumeet Bhosale
Roll No. : 2021
Class : SY - A
Batch : S2
*/

#include <stdio.h>
int fibo(int n)
{
	if (n == 1)
	{
		return 1;
	}
	else if (n == 2)
	{
		return 2;
	}
	else 
	{
		return fibo(n-1) + fibo(n-2);
	}
}
int main()
{
	printf("Enter the range of fibonacci series : ");
	int n;
	scanf("%d", &n);
	int i = 1;
	while(i <= n)
	{
		printf("%d\t", fibo(i));
		i++;
	}
	return 0;
}

/*
------------------------------------OUTPUT----------------------------------

Enter the range of fibonacci series : 7
1       2       3       5       8       13      21

*/