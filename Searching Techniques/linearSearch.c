//Program to implement Linear Search

/*
Name : Sumeet Sambhaji Bhosale 
Roll NO : 2021
Class : SY - A
Batch : S2
*/

#include <stdio.h>

int linearSearch(int* arr, int size, int key)
{
    for (int i = 0; i<size; i++)
    {
        if (key == arr[i]) return i+1;
    }
    return 0;
}

void arrayInput(int* arr, int size)
{
    for (int i = 0; i<size; i++)
    {
        printf("Enter the element %d : ", i+1);
        scanf("%d", &arr[i]);
    }
}

int main()
{
    // int arr[20];
    printf("Enter number of elements : ");
    int n;
    scanf("%d", &n);
    int arr[n];
    arrayInput(arr, n);
    printf("Enter the element you want to search : ");
    int key;
    scanf("%d", &key);
    if (linearSearch(arr, n, key) >= 1) 
    {
        printf("%d is found in the array in the location %d!", key, linearSearch(arr, n, key));
    }
    else 
        printf("%d not found in the array!", key);
    return 0;
}