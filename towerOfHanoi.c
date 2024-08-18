//Program to print the steps involved in tower of Hanoi.
/*
Name : Sumeet Bhosale
Roll No. : 2021
Class : SY - A
Batch : S2
*/

#include <stdio.h>
void toh(int n, char src, char dest, char temp)
{
	if (n == 1)
	{
		printf("Move disk 1 from tower %c to %c \n", src, dest);
		return;
	}
	toh(n-1, src, temp, dest);
	printf("move disk %d from tower %c to %c\n", n, src, dest);
	toh(n-1, temp, dest, src);
}
int main()
{
	printf("Rules\n");
	printf("1. Only one disk can be moved at a time.\n");
	printf("2. Smaller disk should be placed above larger disk\n");
	printf("It contains three towers one source and one destination and one temperary\n");
	printf("The disk are to be transferred as it is to the destination \n");
	int n;
	printf("\nEnter number of disk : ");
	scanf("%d", &n);
	toh(n, 'A', 'C', 'B');
	return 0;
}

/*
----------------------------OUTPUT-----------------------------

Rules
1. Only one disk can be moved at a time.
2. Smaller disk should be placed above larger disk
It contains three towers one source and one destination and one temperary
The disk are to be transferred as it is to the destination 

Enter number of disk : 5
Move disk 1 from tower A to C 
move disk 2 from tower A to B
Move disk 1 from tower C to B 
move disk 3 from tower A to C
Move disk 1 from tower B to A 
move disk 2 from tower B to C
Move disk 1 from tower A to C
move disk 4 from tower A to B
Move disk 1 from tower C to B
move disk 2 from tower C to A
Move disk 1 from tower B to A
move disk 3 from tower C to B
Move disk 1 from tower A to C
move disk 2 from tower A to B
Move disk 1 from tower C to B
move disk 5 from tower A to C
Move disk 1 from tower B to A
move disk 2 from tower B to C
Move disk 1 from tower A to C
move disk 3 from tower B to A
Move disk 1 from tower C to B
move disk 2 from tower C to A
Move disk 1 from tower B to A
move disk 4 from tower B to C
Move disk 1 from tower A to C
move disk 2 from tower A to B
Move disk 1 from tower C to B
move disk 3 from tower A to C
Move disk 1 from tower B to A
move disk 2 from tower B to C
Move disk 1 from tower A to C

*/