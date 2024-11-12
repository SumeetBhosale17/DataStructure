#include <stdio.h>

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b  = t;
}

int partition(int* arr, int low, int high)
{
    int pivot = arr[low];
    int i = low + 1, j = high;
    while (i <= j) {
        while (i <= j && arr[i] <= pivot)
        {
            i++;
        }
        while(i<=j &&  arr[j]>pivot)
        {
            j--;
        }
        if(i<j) swap(&arr[i], &arr[j]);
    }
    swap(&arr[low], &arr[j]);
    return j;
}

void quickSort(int* arr, int low, int high)
{
    if (low<high)
    {
        int mid = partition(arr, low, high);
        
        quickSort(arr, low, mid-1);
        quickSort(arr, mid+1, high);
    }
}

void arrInput(int* arr, int size)
{
    for (int i = 0; i<size; i++)
    {
        printf("Enter element %d : ", i+1);
        scanf("%d", &arr[i]);
    }
}

void arrPrint(int* arr, int size)
{
    for (int i = 0; i<size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int n;
    printf("Enter number of elements : ");
    scanf("%d", &n);
    int arr[n];

    printf("Enter Array Elements\n");
    arrInput(arr, n);

    printf("Entered Array : ");
    arrPrint(arr, n);

    quickSort(arr, 0, n-1);

    printf("Array after sorting : ");
    arrPrint(arr, n);
    return 0;
}