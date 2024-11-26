#include <stdio.h>
#include <stdlib.h>

void firstNegativeInteger(int* arr, int n, int k)
{
    int * result = (int*)malloc((n-k+1)* sizeof(int));
    if (result == NULL)
    {
        printf("Memory error\n");
        return;
    }

    int* queue = (int*) malloc(n*sizeof(int));
    if (queue == NULL)
    {
        printf("Memory error\n");
        free(result);
        return;
    }

    int front = 0, rear = -1;

    for (int i = 0; i<k; i++)
    {
        if (arr[i] < 0)
        {
            queue[++rear] = i;
        }
    }
    for (int i = k; i<n; i++)
    {
        if (front <= rear)
        {
            result[i-k] = arr[queue[front]];
        }
        else 
        {
            result[i-k] = 0;
        }

        while (front <= rear && queue[front] < (i-k+1))
        {
            front++;
        }

        if (arr[i] < 0)
        {
            queue[++rear] = i;
        }
    }

    if (front <= rear)
    {
        result[n-k] = arr[queue[front]];
    }
    else 
    {
        result[n-k] = 0;
    }

    printf("First negative integers : ");
    for (int i = 0; i<(n-k+1) ; i++)
    {
        printf("%d ", result[i]);
    }
    printf("\n");

    free(result);
    free(queue);
}

int main()
{
    int n, k;

    printf("Enter the number of elements : ");
    scanf("%d", &n);

    if (n <= 0)
    {
        printf("Numbers of elements must be greater than zero!");
        return 1;
    }

    int* arr = (int*) malloc(n * sizeof(int));
    if (arr == NULL)
    {
        printf("Memory allocation failed!");
        return 1;
    }

    printf("Enter the elements in the array : ");
    for (int i = 0; i<n; i++)
    {
        printf("Element %d : ", i+1);
        scanf("%d", &arr[i]);
    }

    printf("Enter window size : ");
    scanf("%d", &k);

    if (k<= 0 || k > n)
    {
        printf("Window size must be greater than zero and less than or equal to the number of elements");
        free(arr);
        return 1;
    }

    firstNegativeInteger(arr, n, k);

    return 0;
}

/*
void firstNegative(int arr[], int n, int k)
{
    printf("First negative integers in every window of size %d are:\n", k);
    
    for(int i = 0; i <= n - k; i++)
    {
        int firstNegative = 0;
        for(int j = i; j < i + k; j++)
        {
            if(arr[j] < 0)
            {
                firstNegative = arr[j];
                break;
            }
        }
        printf("%d ", firstNegative);
    }
    printf("\n");
}
*/