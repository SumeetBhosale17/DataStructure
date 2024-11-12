//Program to implement Insertion Sort

/*
Name : Sumeet Sambhaji Bhosale 
Roll NO : 2021
Class : SY - A
Batch : S2
*/

#include <stdio.h>

void arrayInput(int* arr, int size)
{
    for (int i = 0; i<size; i++)
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

void insertionSort(int *arr, int n)
{
    for (int i = 1; i < n; i++)
    {
        int temp = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > temp)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = temp;
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
    insertionSort(arr, size);
    arrayPrint(arr, size);
    return 0;
}