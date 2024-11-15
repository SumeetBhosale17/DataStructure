//Find Transition point in a sorted array containing only 0s and 1s

/*
Name : Sumeet Sambhaji Bhosale
Roll No : 2021
URN : 23031024
Class : SY - A
Batch : S2
*/

#include <stdio.h>

// Function to take input of array of integers
void arrInput(int* arr, int size)
{
    printf("Enter elements in the array (0 and 1 only)\n");
    for (int i = 0; i<size; i++)
    {
        int valid = 0;
        // If the user enters invalid input it prompts a message stating it the input is invalid and asks to re-enter
        while(!valid)
        {
            printf("Enter element %d : ", i+1);
            scanf("%d", &arr[i]);
            // Checking if the input is valid (0 or 1)
            if (arr[i] != 0 && arr[i] != 1)
            {
                printf("Invalid Input!\nOnly 0 and 1 is allowed!\nPlease Re-enter the value\n");
                continue;
            }
            // Checking if the array is sorted or not
            if (i > 0 && arr[i-1] > arr[i])
            {
                printf("Invalid Input!\nThe Array should be sorted!\nPlease Re-Enter the value\n");
                continue;
            }
            valid = 1; // Input will be valid, Thus breaks the while loop and continuing the same process for next index
        }
    }
}
/*
The User may input which may be invalid in this case. 
Rather than working on a wrong input, Checking the conditions before hand would be a safer approach, 
The above function which takes input into the array checks those conditions.
If the user inputs enters a invalid input, this functions informs the user that the enterred input is invalid
and User gets the opportunity to re-enter the input.
*/

// Function to print the elements in the array
void arrPrint(int* arr, int size)
{
    printf("Elements in the array : ");
    for (int i = 0; i<size; i++)
    {
        printf("%d ", arr[i]);
    }
}

// Function to find the transition points in the array (The point where 1 is first observed)
int transitionPoint(int* arr, int low, int high)
{
    if (low > high) return -1; // invalid low and high
    if (arr[high] == 0) return -1; // if the array contains only 0s
    if (arr[low] == 1) return low;  // if the array contains only 1s

    int mid = low + (high - low) / 2; // Middle index of the array
    if (arr[mid] == 1 && (arr[mid-1] == 0 || mid == 0)) return mid; // Returns middle index
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
    printf("Enter size of the array (1 - 105) : ");
    int size;
    scanf("%d", &size);
    if (size <= 0 || size > 105)  // Checks if the size is valid or invalid
    {
        printf("Invalid array size!\nPlease Re-Enter\n");
        main();
    }
    /*
    We have been given the constaints that size can be from 1 to 105,
    So anything other than that will be invalid
    And the user may enter invalid size
    This Condition checks if it is valid or not
    If it is valid the programs execute as it is
    If it is invalid, The user is asked to re-enter the value
    By calling main() recursively
    Thus Ensuring valid size
    */
    int arr[size]; // declaration of integer array of size given by the user
    arrInput(arr, size); // taking input for the array
    arrPrint(arr, size); // printing the array
    printf("\nThe Transition Point in the array is : %d\n", transitionPoint(arr, 0, size-1)); // prints the transition point
    return 0;
}    