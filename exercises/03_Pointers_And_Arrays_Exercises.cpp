//============================================================================
// Pointers and Arrays Exercises - Practice Problems
// Master iterating through arrays using pointers!
//============================================================================

#include <iostream>
#include <string>
using namespace std;

//============================================================================
// EXERCISE 1: Basic Array and Pointer Setup
//============================================================================
void exercise1()
{
    cout << "\n========== EXERCISE 1: Array and Pointer Setup ==========" << endl;

    int arr[] = {10, 20, 30, 40, 50};
    int *ptr = arr; // Pointer to first element

    cout << "Array: 10, 20, 30, 40, 50" << endl;
    cout << "Pointer points to: " << *ptr << endl;

    // TODO: Print all elements using array index notation
    cout << "Elements using arr[i]: ";
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // TODO: Print all elements using pointer dereference
    cout << "Elements using *(ptr+i): ";
    // for (int i = 0; i < 5; i++) {
    //     cout << *(ptr + i) << " ";
    // }
}

//============================================================================
// EXERCISE 2: Calculate Array Size
//============================================================================
void exercise2()
{
    cout << "\n========== EXERCISE 2: Calculate Array Size ==========" << endl;

    int arr[] = {5, 10, 15, 20, 25};

    // Calculate number of elements
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "sizeof(arr) = " << sizeof(arr) << " bytes" << endl;
    cout << "sizeof(arr[0]) = " << sizeof(arr[0]) << " bytes" << endl;
    cout << "Array size = " << size << " elements" << endl;

    // TODO: Do the same for a string array
    // string texts[] = {"one", "two", "three"};
    // int stringSize = sizeof(texts) / sizeof(string);
    // cout << "String array size = " << stringSize << endl;
}

//============================================================================
// EXERCISE 3: Method 1 - Traditional For Loop with Index
//============================================================================
void exercise3()
{
    cout << "\n========== EXERCISE 3: Traditional For Loop ==========" << endl;

    int numbers[] = {100, 200, 300, 400, 500};
    int size = sizeof(numbers) / sizeof(int);

    cout << "Elements using traditional loop: ";

    // TODO: Complete the loop
    for (int i = 0; i < size; i++)
    {
        cout << numbers[i] << " ";
    }
    cout << endl;
}

//============================================================================
// EXERCISE 4: Method 2 - Pointer with Array Syntax
//============================================================================
void exercise4()
{
    cout << "\n========== EXERCISE 4: Pointer with Array Syntax ==========" << endl;

    double values[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    double *ptr = values;
    int size = sizeof(values) / sizeof(double);

    cout << "Elements using ptr[i] syntax: ";

    // TODO: Loop using ptr[i] to access elements
    // for (int i = 0; i < size; i++) {
    //     cout << ptr[i] << " ";
    // }
}

//============================================================================
// EXERCISE 5: Method 3 - Pointer Arithmetic (ptr++)
//============================================================================
void exercise5()
{
    cout << "\n========== EXERCISE 5: Pointer Arithmetic ==========" << endl;

    string texts[] = {"one", "two", "three", "four"};
    string *ptr = texts;
    int size = sizeof(texts) / sizeof(string);

    cout << "Elements using pointer arithmetic: ";

    // TODO: Loop by incrementing the pointer
    // for (int i = 0; i < size; i++, ptr++) {
    //     cout << *ptr << " ";
    // }
    // cout << endl;
}

//============================================================================
// EXERCISE 6: Two Pointers - Start and End
//============================================================================
void exercise6()
{
    cout << "\n========== EXERCISE 6: Two Pointers (Start and End) ==========" << endl;

    int arr[] = {10, 20, 30, 40, 50};

    int *start = &arr[0]; // Point to first element
    int *end = &arr[4];   // Point to last element

    cout << "Elements using two pointers: ";

    // TODO: Loop while start <= end
    while (start <= end)
    {
        cout << *start << " ";
        start++;
    }
    cout << endl;
}

//============================================================================
// EXERCISE 7: Pointer Arithmetic with Offsets
//============================================================================
void exercise7()
{
    cout << "\n========== EXERCISE 7: Pointer Arithmetic with Offsets ==========" << endl;

    int arr[] = {100, 200, 300, 400, 500};
    int *ptr = arr;

    cout << "Direct access using (ptr + offset):" << endl;
    cout << "*(ptr + 0) = " << *(ptr + 0) << endl;
    cout << "*(ptr + 2) = " << *(ptr + 2) << endl;
    cout << "*(ptr + 4) = " << *(ptr + 4) << endl;

    // TODO: Access elements using different offsets
    cout << "\nUsing += operator:" << endl;
    // ptr += 3;
    // cout << "*ptr = " << *ptr << endl;  // Should be 400
}

//============================================================================
// EXERCISE 8: Finding Elements with Pointers
//============================================================================
void exercise8()
{
    cout << "\n========== EXERCISE 8: Find Element with Pointer ==========" << endl;

    int arr[] = {5, 15, 25, 35, 45, 55};
    int *ptr = arr;
    int size = sizeof(arr) / sizeof(int);
    int target = 35;

    cout << "Array: ";
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << "\nSearching for: " << target << endl;

    // TODO: Find the target value and print its index
    // for (int i = 0; i < size; i++, ptr++) {
    //     if (*ptr == target) {
    //         cout << "Found at index: " << i << endl;
    //         break;
    //     }
    // }
}

//============================================================================
// EXERCISE 9: Sum Array Elements with Pointer
//============================================================================
void exercise9()
{
    cout << "\n========== EXERCISE 9: Sum Array Elements ==========" << endl;

    int arr[] = {10, 20, 30, 40, 50};
    int *ptr = arr;
    int size = sizeof(arr) / sizeof(int);

    cout << "Array: 10, 20, 30, 40, 50" << endl;

    // TODO: Calculate the sum using pointer arithmetic
    // int sum = 0;
    // for (int i = 0; i < size; i++, ptr++) {
    //     sum += *ptr;
    // }
    // cout << "Sum = " << sum << endl;
}

//============================================================================
// EXERCISE 10: Reverse Array Using Pointers
//============================================================================
void exercise10()
{
    cout << "\n========== EXERCISE 10: Print in Reverse ==========" << endl;

    string arr[] = {"first", "second", "third", "fourth", "fifth"};
    int size = sizeof(arr) / sizeof(string);

    cout << "Forward: ";
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;

    cout << "Reverse: ";

    // TODO: Print array in reverse using pointers
    // string *ptr = &arr[size - 1];  // Point to last element
    // while (ptr >= arr) {
    //     cout << *ptr << " ";
    //     ptr--;
    // }
    // cout << endl;
}

//============================================================================
// EXERCISE 11: Copy Array Using Pointers
//============================================================================
void exercise11()
{
    cout << "\n========== EXERCISE 11: Copy Array ==========" << endl;

    int source[] = {11, 22, 33, 44, 55};
    int dest[5];

    int *srcPtr = source;
    int *destPtr = dest;
    int size = sizeof(source) / sizeof(int);

    cout << "Source: ";
    for (int i = 0; i < size; i++)
        cout << source[i] << " ";
    cout << endl;

    // TODO: Copy source to dest using pointers
    // for (int i = 0; i < size; i++, srcPtr++, destPtr++) {
    //     *destPtr = *srcPtr;
    // }

    cout << "Destination: ";
    for (int i = 0; i < size; i++)
        cout << dest[i] << " ";
    cout << endl;
}

//============================================================================
// EXERCISE 12: Pointer to Different Array Types
//============================================================================
void exercise12()
{
    cout << "\n========== EXERCISE 12: Pointers to Different Types ==========" << endl;

    // Integer array
    int intArr[] = {1, 2, 3, 4, 5};
    int *pInt = intArr;

    cout << "Integer array: ";
    for (int i = 0; i < 5; i++)
    {
        cout << *(pInt + i) << " ";
    }
    cout << endl;

    // Double array
    double doubleArr[] = {1.5, 2.5, 3.5};
    double *pDouble = doubleArr;

    cout << "Double array: ";
    for (int i = 0; i < 3; i++)
    {
        cout << *(pDouble + i) << " ";
    }
    cout << endl;

    // TODO: Create a character array and use pointer to print it
    // char charArr[] = {'a', 'b', 'c', 'd'};
    // char *pChar = charArr;
}

//============================================================================
// EXERCISE 13: Advanced - Compare Pointers
//============================================================================
void exercise13()
{
    cout << "\n========== EXERCISE 13: Compare Pointers ==========" << endl;

    int arr[] = {10, 20, 30, 40, 50};
    int *ptr1 = &arr[0];
    int *ptr2 = &arr[4];
    int *ptr3 = arr;

    cout << "ptr1 points to: " << *ptr1 << " (address: " << ptr1 << ")" << endl;
    cout << "ptr2 points to: " << *ptr2 << " (address: " << ptr2 << ")" << endl;
    cout << "ptr3 points to: " << *ptr3 << " (address: " << ptr3 << ")" << endl;

    cout << "\nComparisons:" << endl;
    cout << "ptr1 == ptr3? " << (ptr1 == ptr3 ? "YES" : "NO") << endl;
    cout << "ptr1 < ptr2? " << (ptr1 < ptr2 ? "YES" : "NO") << endl;

    // TODO: Calculate how many elements are between ptr1 and ptr2
    // cout << "Distance: " << (ptr2 - ptr1) << " elements" << endl;
}

//============================================================================
// MAIN FUNCTION - Run All Exercises
//============================================================================
int main()
{
    cout << "============================================" << endl;
    cout << "C++ POINTERS AND ARRAYS - PRACTICE EXERCISES" << endl;
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
    cout << "Great job practicing pointers and arrays!" << endl;
    cout << "============================================" << endl;

    return 0;
}

//============================================================================
// SOLUTIONS REFERENCE
//============================================================================
/*
 * EXERCISE 3 SOLUTION:
 * for (int i = 0; i < size; i++) {
 *     cout << numbers[i] << " ";
 * }
 *
 * EXERCISE 4 SOLUTION:
 * for (int i = 0; i < size; i++) {
 *     cout << ptr[i] << " ";
 * }
 *
 * EXERCISE 5 SOLUTION:
 * for (int i = 0; i < size; i++, ptr++) {
 *     cout << *ptr << " ";
 * }
 *
 * EXERCISE 8 SOLUTION:
 * for (int i = 0; i < size; i++, ptr++) {
 *     if (*ptr == target) {
 *         cout << "Found at index: " << i << endl;
 *         break;
 *     }
 * }
 *
 * EXERCISE 9 SOLUTION:
 * int sum = 0;
 * for (int i = 0; i < size; i++, ptr++) {
 *     sum += *ptr;
 * }
 * cout << "Sum = " << sum << endl;
 *
 * EXERCISE 10 SOLUTION:
 * string *ptr = &arr[size - 1];
 * while (ptr >= arr) {
 *     cout << *ptr << " ";
 *     ptr--;
 * }
 *
 * EXERCISE 11 SOLUTION:
 * for (int i = 0; i < size; i++, srcPtr++, destPtr++) {
 *     *destPtr = *srcPtr;
 * }
 *
 * EXERCISE 13 SOLUTION:
 * cout << "Distance: " << (ptr2 - ptr1) << " elements" << endl;
 */
