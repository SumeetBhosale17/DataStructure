#include <stdio.h>

int front = -1;
int rear = -1;

void enqueue(int queue[], int size)
{
	if (front == (rear+1)%size)
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
			rear = (rear+1)%size;
		}
		printf("Enter the Data to the Queue : ");
		scanf("%d", &queue[rear]);
		printf("%d is Queued at %d", queue[rear], rear);
	}
}

void dequeue(int queue[], int size)
{
	if (front == -1)
	{
		printf("\nQueue Underflow!");
	}
	else
	{
		printf("%d is Dequeued!", queue[front]);
		front = (front+1)%size;
		if (front == (rear+1)%size)
		{
			front = -1;
			rear = -1;
		}
	}
}

void traverse(int queue[], int size)
{
	if (front == -1)
	{
		printf("\nQueue is Empty!");
	}
	else
	{
		printf("Elements in the Queue : \n");
		int i = front;
		do
		{
			printf("%d\t", queue[i]);
			i = (i+1)%size;
		}while(i != rear+1);
	}
}

int main()
{
	int ch;
	printf("Enter the Size of the Circular Queue : ");
	int size;
	scanf("%d", &size);
	int cq[size];
	do
	{
		printf("\n\nEnter what operation you want to perform \n");
		printf("1. Enqueue\n2. Dequeue\n3. Traverse\n4. Exit\n");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1 : enqueue(cq, size);
				break;
			case 2 : dequeue(cq, size);
				break;
			case 3 : traverse(cq, size);
				break;
			case 4 : printf("\nThank You For using the Queue!\n\nExiting.....!\n");
				break;
			default : printf("\nEnter valid option!");
				break;
		}
	}while(ch != 4);
	return 0;
}