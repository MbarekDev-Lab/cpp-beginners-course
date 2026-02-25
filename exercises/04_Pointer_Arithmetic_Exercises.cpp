//============================================================================
// Pointer Arithmetic Exercises - Practice Problems
// Master pointer arithmetic techniques!
//============================================================================

#include <iostream>
#include <string>
using namespace std;

//============================================================================
// EXERCISE 1: Moving Pointer Forward and Backward
//============================================================================
void exercise1()
{
    cout << "\n========== EXERCISE 1: Moving Pointer ==========" << endl;

    int arr[] = {10, 20, 30, 40, 50};
    int *ptr = arr;

    cout << "Starting position (0): " << *ptr << endl;

    // Move forward 2 positions
    ptr += 2;
    cout << "After += 2: " << *ptr << endl;

    // Move backward 1 position
    ptr -= 1;
    cout << "After -= 1: " << *ptr << endl;

    // TODO: Move forward 3 positions again
    // ptr += 3;
    // cout << "After += 3: " << *ptr << endl;
}

//============================================================================
// EXERCISE 2: Using One-Past-End Pattern
//============================================================================
void exercise2()
{
    cout << "\n========== EXERCISE 2: One-Past-End Loop ==========" << endl;

    int arr[] = {5, 10, 15, 20, 25};
    int *start = &arr[0];
    int *end = &arr[5]; // One past the last element

    cout << "Elements using one-past-end pattern: ";

    while (start != end)
    {
        cout << *start << " ";
        start++;
    }
    cout << endl;
}

//============================================================================
// EXERCISE 3: Pointer Subtraction - Finding Distance
//============================================================================
void exercise3()
{
    cout << "\n========== EXERCISE 3: Pointer Subtraction ==========" << endl;

    int arr[] = {100, 200, 300, 400, 500};
    int *ptr1 = &arr[0];
    int *ptr2 = &arr[4];

    cout << "ptr1 points to: arr[0] = " << *ptr1 << endl;
    cout << "ptr2 points to: arr[4] = " << *ptr2 << endl;

    int distance = ptr2 - ptr1;
    cout << "Distance (ptr2 - ptr1): " << distance << " elements" << endl;

    // TODO: Calculate distance between other pointers
    // int *ptr3 = &arr[2];
    // cout << "Distance (ptr3 - ptr1): " << (ptr3 - ptr1) << endl;
}

//============================================================================
// EXERCISE 4: Finding Element Position
//============================================================================
void exercise4()
{
    cout << "\n========== EXERCISE 4: Find Position ==========" << endl;

    string texts[] = {"apple", "banana", "cherry", "date", "elderberry"};
    string *start = &texts[0];
    string *end = &texts[5];

    string target = "cherry";
    string *ptr = start;
    int position = -1;

    cout << "Searching for: " << target << endl;

    // TODO: Loop through and find the target
    while (ptr != end)
    {
        if (*ptr == target)
        {
            position = ptr - start;
            break;
        }
        ptr++;
    }

    if (position != -1)
    {
        cout << "Found at position: " << position << endl;
    }
}

//============================================================================
// EXERCISE 5: Backward Iteration with Pointer Arithmetic
//============================================================================
void exercise5()
{
    cout << "\n========== EXERCISE 5: Backward Iteration ==========" << endl;

    int arr[] = {1, 2, 3, 4, 5};
    int *start = &arr[0];
    int *end = &arr[5];

    cout << "Forward: ";
    int *ptr = start;
    while (ptr != end)
    {
        cout << *ptr << " ";
        ptr++;
    }
    cout << endl;

    cout << "Backward: ";

    // TODO: Print array backward using pointer arithmetic
    // ptr = end - 1;  // Start at last element
    // while (ptr >= start) {
    //     cout << *ptr << " ";
    //     ptr--;
    // }
    // cout << endl;
}

//============================================================================
// EXERCISE 6: Sum Array Using Pointer Arithmetic
//============================================================================
void exercise6()
{
    cout << "\n========== EXERCISE 6: Sum Array ==========" << endl;

    int arr[] = {10, 20, 30, 40, 50};
    int *ptr = &arr[0];
    int *end = &arr[5];

    int sum = 0;

    // TODO: Calculate sum using pointer arithmetic
    // while (ptr != end) {
    //     sum += *ptr;
    //     ptr++;
    // }

    cout << "Sum of array: " << sum << endl;
}

//============================================================================
// EXERCISE 7: Skip Elements with Pointer Arithmetic
//============================================================================
void exercise7()
{
    cout << "\n========== EXERCISE 7: Skip Elements ==========" << endl;

    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int *ptr = &arr[0];
    int *end = &arr[10];

    cout << "Every other element (skip by 2): ";

    // TODO: Print every other element
    // while (ptr != end) {
    //     cout << *ptr << " ";
    //     ptr += 2;  // Skip one element
    // }
    // cout << endl;
}

//============================================================================
// EXERCISE 8: Move to Middle of Array
//============================================================================
void exercise8()
{
    cout << "\n========== EXERCISE 8: Move to Middle ==========" << endl;

    int arr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int size = 10;
    int *ptr = &arr[0];

    cout << "Array size: " << size << endl;
    cout << "Element at start: " << *ptr << endl;

    // TODO: Move to middle and print
    // ptr += size / 2;
    // cout << "Element at middle: " << *ptr << endl;
}

//============================================================================
// EXERCISE 9: Count Occurrences Using Pointers
//============================================================================
void exercise9()
{
    cout << "\n========== EXERCISE 9: Count Occurrences ==========" << endl;

    int arr[] = {5, 2, 5, 3, 5, 1, 5, 4};
    int *ptr = &arr[0];
    int *end = &arr[8];
    int target = 5;
    int count = 0;

    cout << "Array: 5, 2, 5, 3, 5, 1, 5, 4" << endl;
    cout << "Looking for: " << target << endl;

    // TODO: Count how many times target appears
    // while (ptr != end) {
    //     if (*ptr == target) {
    //         count++;
    //     }
    //     ptr++;
    // }

    cout << "Count: " << count << endl;
}

//============================================================================
// EXERCISE 10: Copy Array with Pointers
//============================================================================
void exercise10()
{
    cout << "\n========== EXERCISE 10: Copy Array ==========" << endl;

    int source[] = {11, 22, 33, 44, 55};
    int dest[5];

    int *srcPtr = &source[0];
    int *srcEnd = &source[5];
    int *destPtr = &dest[0];

    cout << "Source: ";
    for (int i = 0; i < 5; i++)
        cout << source[i] << " ";
    cout << endl;

    // TODO: Copy using pointers
    // while (srcPtr != srcEnd) {
    //     *destPtr = *srcPtr;
    //     srcPtr++;
    //     destPtr++;
    // }

    cout << "Destination: ";
    for (int i = 0; i < 5; i++)
        cout << dest[i] << " ";
    cout << endl;
}

//============================================================================
// EXERCISE 11: Find Minimum Value
//============================================================================
void exercise11()
{
    cout << "\n========== EXERCISE 11: Find Minimum ==========" << endl;

    int arr[] = {50, 30, 80, 20, 60, 10, 90};
    int *ptr = &arr[0];
    int *end = &arr[7];
    int *minPtr = ptr;

    cout << "Array: 50, 30, 80, 20, 60, 10, 90" << endl;

    // TODO: Find minimum value using pointers
    // while (ptr != end) {
    //     if (*ptr < *minPtr) {
    //         minPtr = ptr;
    //     }
    //     ptr++;
    // }

    cout << "Minimum value: " << *minPtr << endl;
    cout << "Position: " << (minPtr - &arr[0]) << endl;
}

//============================================================================
// EXERCISE 12: Reverse Array Using Pointers
//============================================================================
void exercise12()
{
    cout << "\n========== EXERCISE 12: Reverse Array ==========" << endl;

    int arr[] = {1, 2, 3, 4, 5};
    int *start = &arr[0];
    int *end = &arr[4]; // Point to last element (not one past!)

    cout << "Original: ";
    for (int i = 0; i < 5; i++)
        cout << arr[i] << " ";
    cout << endl;

    // TODO: Reverse by swapping elements from both ends
    // while (start < end) {
    //     int temp = *start;
    //     *start = *end;
    //     *end = temp;
    //     start++;
    //     end--;
    // }

    cout << "Reversed: ";
    for (int i = 0; i < 5; i++)
        cout << arr[i] << " ";
    cout << endl;
}

//============================================================================
// EXERCISE 13: Advanced - Two Pointer Algorithm
//============================================================================
void exercise13()
{
    cout << "\n========== EXERCISE 13: Two Pointer Algorithm ==========" << endl;

    // Find two numbers that sum to a target
    int arr[] = {2, 4, 6, 8, 10};
    int *left = &arr[0];
    int *right = &arr[4];
    int target = 12;

    cout << "Array: 2, 4, 6, 8, 10" << endl;
    cout << "Find two numbers that sum to: " << target << endl;

    // TODO: Use two pointers to find pair
    // while (left < right) {
    //     int sum = *left + *right;
    //     if (sum == target) {
    //         cout << "Found: " << *left << " + " << *right << " = " << target << endl;
    //         break;
    //     } else if (sum < target) {
    //         left++;
    //     } else {
    //         right--;
    //     }
    // }
}

//============================================================================
// MAIN FUNCTION - Run All Exercises
//============================================================================
int main()
{
    cout << "============================================" << endl;
    cout << "C++ POINTER ARITHMETIC - PRACTICE EXERCISES" << endl;
    cout << "============================================" << endl;

    exercise1();
    // Uncomment the exercises below as you solve them:
    // exercise2();
    // exercise3();
    // exercise4();
    // exercise5();
    // exercise6();
    // exercise7();
    // exercise8();
    // exercise9();
    // exercise10();
    // exercise11();
    // exercise12();
    // exercise13();

    cout << "\n============================================" << endl;
    cout << "Great job practicing pointer arithmetic!" << endl;
    cout << "============================================" << endl;

    return 0;
}

//============================================================================
// SOLUTIONS REFERENCE
//============================================================================
/*
 * EXERCISE 4 SOLUTION:
 * while (ptr != end) {
 *     if (*ptr == target) {
 *         position = ptr - start;
 *         break;
 *     }
 *     ptr++;
 * }
 *
 * EXERCISE 5 SOLUTION:
 * ptr = end - 1;
 * while (ptr >= start) {
 *     cout << *ptr << " ";
 *     ptr--;
 * }
 *
 * EXERCISE 6 SOLUTION:
 * while (ptr != end) {
 *     sum += *ptr;
 *     ptr++;
 * }
 *
 * EXERCISE 7 SOLUTION:
 * while (ptr != end) {
 *     cout << *ptr << " ";
 *     ptr += 2;
 * }
 *
 * EXERCISE 9 SOLUTION:
 * while (ptr != end) {
 *     if (*ptr == target) {
 *         count++;
 *     }
 *     ptr++;
 * }
 *
 * EXERCISE 10 SOLUTION:
 * while (srcPtr != srcEnd) {
 *     *destPtr = *srcPtr;
 *     srcPtr++;
 *     destPtr++;
 * }
 *
 * EXERCISE 11 SOLUTION:
 * while (ptr != end) {
 *     if (*ptr < *minPtr) {
 *         minPtr = ptr;
 *     }
 *     ptr++;
 * }
 *
 * EXERCISE 12 SOLUTION:
 * while (start < end) {
 *     int temp = *start;
 *     *start = *end;
 *     *end = temp;
 *     start++;
 *     end--;
 * }
 *
 * EXERCISE 13 SOLUTION:
 * while (left < right) {
 *     int sum = *left + *right;
 *     if (sum == target) {
 *         cout << "Found: " << *left << " + " << *right << endl;
 *         break;
 *     } else if (sum < target) {
 *         left++;
 *     } else {
 *         right--;
 *     }
 * }
 */
