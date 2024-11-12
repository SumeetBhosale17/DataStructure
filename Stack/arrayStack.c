#include <stdio.h>

int top = -1;

void push(int arr[], int n)
{
	if (top == n-1)
	{
		printf("\nStack Overflow!");
	}
	else
	{
		top++;
		printf("Enter the data to be pushed into the stack : ");
		scanf("%d", &arr[top]);
		printf("%d is pushed to stack at position %d\n", arr[top], top+1);
	}
}

void pop(int arr[])
{
	if (top == -1)
	{
		printf("\nStack Underflow!");
	}
	else
	{
		printf("%d is popped!", arr[top]);
		top--;
	}
}

void tos(int arr[])
{
	if (top == -1)
	{
		printf("\nStack is Empty!");
	}
	else
	{
		printf("%d is at Top of the Stack!", arr[top]);
	}
}

void traverse(int arr[])
{
	if (top == -1)
	{
		printf("\nStack is Empty!");
	}
	else
	{
		printf("Elements in the Stack : \n");
		for (int i = 0; i<=top; i++)
		{
			printf("%d\t", arr[i]);
		}
	}
}

int main()
{
	printf("Enter the size of the queue : ");
	int n;
	int ch;
	scanf("%d", &n);
	
	int arr[n];
	do
	{
		printf("\n\nEnter what operation you want to perform : ");
		printf("\n1. Push\n2. Pop\n3. Print Top of Stack\n4. Traverse\n5. Exit\n");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1 : push(arr, n);
				break;
			case 2 : pop(arr);
				break;
			case 3 : tos(arr);
				break;
			case 4 : traverse(arr);
				break;
			case 5 : printf("\nThank You For Using the Stack!\n\nExiting...!\n");
				break;
			default : printf("\nEnter valid option!");
				break;
		}
	}while(ch != 5);
	
	return 0;
}