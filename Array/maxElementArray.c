//Given an array of integers arr that is first strictly increasing and then maybe strictly decreasing, find the maximum element in the array. 

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
    printf("Enter elements in the array\n");
    for (int i = 0; i<size; i++)
    {
        printf("Enter element %d : ", i+1);
        scanf("%d", &arr[i]);
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

// Function to find the maximum element in the array
int maxElement(int *arr, int low, int high)
{
    if (low > high) return -1;

    // If only one element is present in the array
    if (low == high) return arr[low];

    // Check if the array is strictly increasing
    if (arr[low] < arr[low + 1] && arr[high - 1] < arr[high]) return arr[high];

    // Check if the array is strictly decreasing
    if (arr[low] > arr[low + 1] && arr[high - 1] > arr[high]) return arr[low];

    int mid = low + (high - low) / 2;

    // Check if middle element is the maximum element
    if ((mid == 0 || arr[mid - 1] <= arr[mid]) && (mid == high || arr[mid + 1] <= arr[mid]))
        return arr[mid];

    // If the element at middle is not the maximum and the element on the left is greater than the middle element then the maximum lies on the left side
    if (mid > 0 && arr[mid - 1] > arr[mid])
        return maxElement(arr, low, mid - 1);

    // If the element on the right is greater than the middle element then the maximum lies on the right side
    return maxElement(arr, mid + 1, high);
}
/*
Complexity:
    -> Time Complexity: O(logn)
        Best Case: O(1) --- Constant -> {When the array has only one element or the when the array is strictly increasing or decreasing or the maximum element is at middle}
        Worst Case: O(logn) --- Logarithmic -> {General Case}
    -> Space Complexity: O(logn)
        Best Case : O(1) --- Constant -> {When the array has only one element or the when the array is strictly increasing or decreasing}
        Worst Case : O(logn) --- Logarithmic -> {General Case}

Description:
    ->  - If the array has only one element, return that element as it is the maximum.
        - When the array is strictly increasing or decreasing, the maximum element is at the beginning or end of the array.
            The function returns respective values -> Thus giving a constant complexity
        - If the maximum element is present in the middle of the array, It returns the element without any recursive calls. -> Constant complexity
        - If all elements are equal, then also the complexity is constant as it satisfies the condition of middle element as maximum

    -> For general case, If the middle element is greater than the elements on both sides, then it is the maximum element.
        Otherwise the array is divided into two halves and the maximum element is found recursively in the half where the maximum element is present.
        If the middle element is less than the element in the left, then the greatest element is in the left side
        Otherwise it is in the right side of the middle element -> Thus giving a logarithmic complexity

    We use divide and conquer approach for solving the problem by dividing the array into two halves and finding the maximum element in each half recursively.
    It is similar to Binary Search algorithm but instead of finding an element, we are finding the maximum element in the array.    
*/

// Main Function
int main()
{
    printf("Enter Size of the array (3 - 105) : ");
    int size;
    scanf("%d", &size);
    if (size < 3 || size > 105)  // checks if the size is valid or invalid
    {
        printf("Invalid array size!\nPlease Re-Enter\n");
        main();
    }
    /*
    We have been given the constaints that size can be from 3 to 105,
    So anything other than that will be invalid
    And the user may enter invalid size
    This Condition checks if it is valid or not
    If it is valid the programs execute as it is
    If it is invalid, The user is asked to re-enter the value
    By calling main() recursively
    Thus Ensuring valid size
    */
    int arr[size]; // declaring integer array of size entered by the user
    arrInput(arr, size); // taking input of array 
    arrPrint(arr, size); // printing the array
    printf("\nThe maximum element in the array is : %d\n", maxElement(arr, 0, size - 1)); // Finding the maximum element the array
    return 0;
}