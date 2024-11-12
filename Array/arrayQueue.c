#include <stdio.h>

int front = -1;
int rear = -1;

void enqueue(int queue[], int size)
{
	if (rear == size - 1)
	{
		printf("\nQueue Overflow!");
	}
	else
	{
		if (front == -1)
		{
			front++;
			rear++;
		}
		else
		{
			rear++;
		}
		printf("Enter the Data to be Queued : ");
		scanf("%d", &queue[rear]);
		printf("%d is queued at %d", queue[rear], rear+1);
	}
}

void dequeue(int queue[])
{
	if (front == -1)
	{
		printf("\nQueue Underflow!");
	}
	else
	{
		printf("%d is Dequeued!", queue[front]);
		front++;
		if (front > rear)
		{
			front = -1;
			rear = -1;
		}
	}
}

void traverse(int queue[])
{
	if (front == -1)
	{
		printf("\nQueue is Empty!");
	}
	else
	{
		printf("Elements in the queue : \n");
		for (int i = front; i<= rear; i++)
		{
			printf("%d\t", queue[i]);
		}
	}
}

int main()
{
	int ch;
	printf("Enter the size of the Queue : ");
	int size;
	scanf("%d", &size);
	int queue[size];
	do
	{
		printf("\n\nEnter what operation you want to perform \n");
		printf("1. Enqueue\n2. Dequeue\n3. Traverse\n4. Exit\n");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1 : enqueue(queue, size);
				break;
			case 2 : dequeue(queue);
				break;
			case 3 : traverse(queue);
				break;
			case 4 : printf("\nThank You For using the Queue!\n\nExiting.....!\n");
				break;
			default : printf("\nEnter valid option!");
				break;
		}
	}while(ch != 4);
	return 0;
}