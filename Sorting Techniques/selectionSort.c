//Program to implement Selection Sort

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

void arrayPrint(int* arr, int size)
{
    for (int i = 0; i<size; i++)
    {
        printf("%d ", arr[i]);
    }
}

void selectionSort(int* arr, int size)
{
    for (int i = 0; i < size-1; i++)
    {
        int min = i;
        for (int j = i+1; j < size; j++)
        {
            if (arr[j] < arr[min]) 
            {
                min = j;
            }
        }
        if (min != i)
        {
            int temp = arr[min];
            arr[min] = arr[i];
            arr[i] = temp;
        }
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
    selectionSort(arr, size);
    arrayPrint(arr, size);
    return 0;
}