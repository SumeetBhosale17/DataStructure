//Find Transition point in a sorted array containing only 0s and 1s
/*
Name : Sumeet Sambhaji Bhosale
Roll No : 2021
URN : 23031024
Class : SY - A
Batch : S2
*/
#include <stdio.h>
#include <stdlib.h>

// Function to take input of array of integers
void arrInput(int* arr, int size)
{
    printf("Enter elements in the array (0 and 1 only)\n");
    for (int i = 0; i<size; i++)
    {
        printf("Enter element %d : ", i+1);
        scanf("%d", &arr[i]);
        // Checking input
        if (arr[i] != 0 && arr[i] != 1) 
        {
            printf("Invalid Element!\nOnly 1 and 0 is allowed!");
            exit(1); // Exit if invalid input
        }
        // Checking if the array is sorted
        if (i > 0 && arr[i-1] > arr[i])
        {
            printf("Invalid Input! \nThe array must be sorted");
            exit(1);
        }
    }
}

// Function to print the elements in the array
void arrPrint(int* arr, int size)
{
    printf("Elements in the array : ");
    for (int i = 0; i<size; i++)
    {
        printf("%d ", arr[i]);
    }
}

// Function to find the transition points in the array
int transitionPoint(int* arr, int low, int high)
{
    if (low > high) return -1; // invalid low and high
    if (arr[high] == 0) return -1; // if the array contains only 0s
    if (arr[low] == 1) return low;  // if the array contains only 1s

    int mid = low + (high - low) / 2;
    if (arr[mid] == 1 && (arr[mid-1] == 0 || mid == 0)) return mid;
    if (arr[mid] == 1) return transitionPoint(arr, low, mid-1);
    return transitionPoint(arr, mid+1, high);
}
/*
Complexity:
    -> Time Complexity: O(logn)
        Best Case: O(1) --- Constant
        Worst Case: O(logn) --- Logarithmic

    -> Space Complexity : O(logn)
        Best Case: O(1) --- Constant
        Worst Case: O(logn) --- Logarithmic

Description:
    -> This function uses Binary Search approach to find the transition point in the array.
    -> If it contains only 0s, it returns -1. This condition is checked initially and thus it gives a constant time complexity
    -> If it contains only 1s, it returns the low index. This condition is also checked initially and thus giving a constant time complexity
    -> If the middle element is 1 and the previous element is 0, it returns the index of middle element
    -> If the middle element is 1, it recursively calls the function in the left side with the high index as mid -1 
    -> If the middle element is 0, it recursively calls the function in the right side with the low index as mid + 1
    -> Since it Uses Binary Search Approach, the time complexity is O(logn) and the space complexity is also O(logn)
*/

//Main Function
int main()
{
    printf("Enter size of the array : ");
    int size;
    scanf("%d", &size);
    if (size <= 0)  // checks if the size is valid or invalid
    {
        printf("Invalid array size!\n");
        return -1;
    }
    int arr[size];
    arrInput(arr, size);
    arrPrint(arr, size);
    printf("\nThe Transition Point in the array is : %d\n", transitionPoint(arr, 0, size-1));
    return 0;
}