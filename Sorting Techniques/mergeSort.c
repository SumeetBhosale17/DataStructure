#include <stdio.h>

void merge(int *arr, int low, int high)
{
    int mid = (low + high) / 2;

    int i = low, j = mid + 1, k = low;
    int b[high];

    while (i <= mid && j <= high)
    {
        if (arr[i] < arr[j])
        {
            b[k++] = arr[i++];
            // i++;
        }
        else
        {
            b[k++] = arr[j++];
            // j++;
        }
        // k++;
    }
    if (i > mid)
    {
        for (int z = j; z <= high; z++)
        {
            b[k++] = arr[z];
        }
    }
    else
    {
        for (int z = i; z <= mid; z++)
        {
            b[k++] = arr[z];
        }
    }

    for (int z = low; z<=high; z++)
    {
        arr[z] = b[z];
    }
}

void mergeSort(int *arr, int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;

        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);

        merge(arr, low, high);
    }
}

void arrayInput(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("Enter element %d : ", i + 1);
        scanf("%d", &arr[i]);
    }
}

void arrayPrint(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    printf("Enter number of elements : ");
    int n;
    scanf("%d", &n);
    int arr[n];
    printf("Enter array elements\n");
    arrayInput(arr, n);
    printf("\nEnterred elements in the array : ");
    arrayPrint(arr, n);
    printf("\nSorted Array : ");
    mergeSort(arr, 0, n-1);
    arrayPrint(arr, n);
    return 0;
}