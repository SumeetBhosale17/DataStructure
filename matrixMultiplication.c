//Program to perform matrix multiplicaton
/*
Name : Sumeet Bhosale
Roll No. : 2021
Class : SY - A
Batch : S2
*/

#include <stdio.h>
#define mr 10
#define mc 10

void matInput(int m[mr][mc], int r, int c)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("Enter Element [%d][%d] : ", i + 1, j + 1);
            scanf("%d", &m[i][j]);
        }
    }
}

void matPrint(int m[mr][mc], int r, int c)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("%d\t", m[i][j]);
        }
        printf("\n");
    }
}

void matMulti(int m1[mr][mc], int m2[mr][mc], int r[mr][mc], int r1, int c1, int c2)
{
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            r[i][j] = 0;
            for (int k = 0; k < c1; k++)
            {
                r[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }
}
int main()
{
    int r1, c1, r2, c2;
    int m1[mr][mc], m2[mr][mc];
    int result[mr][mc];
    printf("Enter number of rows for matrix 1 : ");
	scanf("%d", &r1);
	printf("Enter number of columns for matrix 1 : ");
	scanf("%d", &c1);
	printf("Enter elements for matrix 1\n");
	matInput(m1, r1, c1);
	printf("\nMatrix 1: \n");
	matPrint(m1, r1, c1);
	printf("\nEnter number of rows for matrix 2 : ");
	scanf("%d", &r2);
	printf("Enter number of columns for matrix 2 : ");
	scanf("%d", &c2);
	printf("Enter elements for Matrix 2\n");
	matInput(m2, r2, c2);
	printf("\nMatrix 2 : \n");
	matPrint(m2, r2, c2);
    if (c1 == r2)
    {
        matMulti(m1, m2, result, r1, c1, c2);
        printf("\nResult : \n");
        matPrint(result, r1, c2);
    }
    else
    {
        printf("\nThe matrices cannot be multiplied!\n");
    }
    return 0;
}

/*

-----------------------------OUTPUT---------------------------

Enter number of rows for matrix 1 : 3
Enter number of columns for matrix 1 : 3
Enter elements for matrix 1
Enter Element [1][1] : 3
Enter Element [1][2] : 2
Enter Element [1][3] : 4
Enter Element [2][1] : 2
Enter Element [2][2] : 3
Enter Element [2][3] : 1
Enter Element [3][1] : 2
Enter Element [3][2] : 3
Enter Element [3][3] : 1

Matrix 1:
3       2       4
2       3       1
2       3       1

Enter number of rows for matrix 2 : 3
Enter number of columns for matrix 2 : 3
Enter elements for Matrix 2
Enter Element [1][1] : 2
Enter Element [1][2] : 3
Enter Element [1][3] : 2
Enter Element [2][1] : 2
Enter Element [2][2] : 4
Enter Element [2][3] : 5
Enter Element [3][1] : 4
Enter Element [3][2] : 5
Enter Element [3][3] : 5

Matrix 2 :
2       3       2
2       4       5
4       5       5

Result :
26      37      36
14      23      24
14      23      24

*/