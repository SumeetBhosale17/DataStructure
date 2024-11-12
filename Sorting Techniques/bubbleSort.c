//Program to implement Bubble Sort

/*
Name : Sumeet Sambhaji Bhosale 
Roll NO : 2021
Class : SY - A
Batch : S2
*/

#include <stdio.h>

void arrayInput(int* arr, int size)
{
    for(int i = 0; i<size; i++)
    {
        printf("Enter element %d : ", i+1);
        scanf("%d", &arr[i]);
    }
}

void bubbleSort(int* arr, int size)
{
    for (int i = 0; i<size-1; i++)
    {
        for(int j = 0; j<size-i-1; j++)
        {
            if (arr[j]>arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void arrayPrint(int* arr, int size)
{
    for (int i = 0; i<size; i++)
    {
        printf("%d ", arr[i]);
    }
}

int main()
{
    printf("Enter Number of Elements : ");
    int size;
    scanf("%d", &size);
    int arr[size];
    arrayInput(arr, size);
    printf("\nElements before Sorting : ");
    arrayPrint(arr, size);
    printf("\nAfter Sorting : ");
    bubbleSort(arr, size);
    arrayPrint(arr, size);
    return 0;
}