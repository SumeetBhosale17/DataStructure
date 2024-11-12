//Program to implement Binary Search

/*
Name : Sumeet Sambhaji Bhosale 
Roll NO : 2021
Class : SY - A
Batch : S2
*/

#include <stdio.h>
// #include "linearSearch.c"

void arrayInput(int* arr, int size)
{
    printf("Enter Elements in Sorted Manner!\n");
    for (int i = 0; i<size; i++)
    {
        printf("Enter the element %d : ", i+1);
        scanf("%d", &arr[i]);
    }
}

int binarySearch(int* arr, int size, int key)
{
    int low = 0;
    int high = size-1;

    while(low<=high)
    {
        int mid = (low+high)/2;
        if (key == arr[mid])
        {
            return mid + 1;
        }
        else if (key < arr[mid])
        {
            high = mid - 1;
        }
        else 
        {
            low = mid + 1;
        }
    }

    return 0;
}

int main()
{
    printf("Enter number of elements : ");
    int size;
    scanf("%d", &size);
    int arr[size];
    arrayInput(arr, size);
    printf("Enter the element to search : ");
    int key;
    scanf("%d", &key);
    if (binarySearch(arr, size, key) >= 1)
    {
        printf("%d is found at %d location!", key, binarySearch(arr, size, key));
    }
    else 
    {
        printf("%d is not found!", key);
    }
    return 0;
}