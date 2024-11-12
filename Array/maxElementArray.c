#include <stdio.h>

void arrInput(int* arr, int size)
{
    for (int i = 0; i<size; i++)
    {
        printf("Enter element %d : ", i+1);
        scanf("%d", arr[i]);
    }
}

void arrPrint(int* arr, int size)
{
    printf("Elements in the array : ");
    for (int i = 0; i<size; i++)
    {
        printf("%d ", arr[i]);
    }
}

int maxElement(int* arr, int size)
{
    if (arr[size-1] > arr[size-2])
    {
        return arr[size-1];
    }
    
    int i = 0; 
    int j = 1;
    while(arr[i])
}

int main()
{
    printf("Enter Size of the array : ");
    int size;
    scanf("%d", &size);

    int arr[size];

    arrInput(arr, size);
    arrPrint(arr, size);



    return 0;
}