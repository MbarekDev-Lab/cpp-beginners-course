//============================================================================
// Pointer Exercises - Practice Problems
// Solve these exercises to master pointers!
//============================================================================

#include <iostream>
using namespace std;

//============================================================================
// EXERCISE 1: Simple Pointer Operations
//============================================================================
void exercise1()
{
    cout << "\n========== EXERCISE 1: Simple Pointer Operations ==========" << endl;

    int value = 42;
    int *ptr = &value;

    cout << "Original value: " << value << endl;
    cout << "Pointer address: " << ptr << endl;
    cout << "Dereferenced pointer: " << *ptr << endl;

    // TODO: Change the value to 100 using the pointer and print it
    // Solution:
    // *ptr = 100;
    // cout << "Modified value: " << *ptr << endl;
}

//============================================================================
// EXERCISE 2: Modify Values Through Pointers
//============================================================================
void modifyValue(int *ptr, int newValue)
{
    // TODO: Modify the value that ptr points to
    // Hint: Use the dereference operator *
}

void exercise2()
{
    cout << "\n========== EXERCISE 2: Modify Through Function ==========" << endl;

    int score = 50;
    cout << "Before: " << score << endl;

    modifyValue(&score, 75);

    cout << "After: " << score << endl;
    // Expected output: 75
}

//============================================================================
// EXERCISE 3: Swap Two Values
//============================================================================
void swap(int *a, int *b)
{
    // TODO: Swap the values that a and b point to
    // Hint: You'll need a temporary variable
    // Solution:
    // int temp = *a;
    // *a = *b;
    // *b = temp;
}

void exercise3()
{
    cout << "\n========== EXERCISE 3: Swap Two Values ==========" << endl;

    int x = 10;
    int y = 20;

    cout << "Before swap - x: " << x << ", y: " << y << endl;

    swap(&x, &y);

    cout << "After swap - x: " << x << ", y: " << y << endl;
    // Expected output: x: 20, y: 10
}

//============================================================================
// EXERCISE 4: Pointer Arithmetic
//============================================================================
void exercise4()
{
    cout << "\n========== EXERCISE 4: Pointer Arithmetic ==========" << endl;

    int arr[5] = {10, 20, 30, 40, 50};
    int *ptr = arr; // ptr points to first element

    cout << "Array elements using pointer arithmetic:" << endl;

    // TODO: Print all array elements using pointer arithmetic
    // Hint: Use ptr++, ptr+1, *(ptr+i), etc.
    // Solution:
    // for (int i = 0; i < 5; i++) {
    //     cout << "arr[" << i << "] = " << *(ptr + i) << endl;
    // }
}

//============================================================================
// EXERCISE 5: Pointer to Pointer
//============================================================================
void exercise5()
{
    cout << "\n========== EXERCISE 5: Pointer to Pointer ==========" << endl;

    int value = 100;
    int *ptr = &value;   // Pointer to int
    int **ptrPtr = &ptr; // Pointer to pointer to int

    cout << "Value: " << value << endl;
    cout << "Via ptr: " << *ptr << endl;
    cout << "Via ptrPtr: " << **ptrPtr << endl; // Double dereference!

    // TODO: Modify value using ptrPtr and print the result
    // Hint: **ptrPtr = newValue;
}

//============================================================================
// EXERCISE 6: Pointers and Strings
//============================================================================
void exercise6()
{
    cout << "\n========== EXERCISE 6: Pointers and Strings ==========" << endl;

    const char *str = "Hello";

    // TODO: Print each character of the string using a pointer
    // Hint: The string is null-terminated, use a loop
    // Solution:
    // for (int i = 0; str[i] != '\0'; i++) {
    //     cout << str[i] << " ";
    // }
}

//============================================================================
// EXERCISE 7: Function Returning Pointer (Advanced)
//============================================================================
// WARNING: This is a common mistake - don't return pointer to local variable!
int *dangerousFunction()
{
    int local = 42;
    return &local; // DANGEROUS! local goes out of scope
}

void exercise7()
{
    cout << "\n========== EXERCISE 7: Pointer Safety ==========" << endl;

    cout << "This exercise shows a COMMON MISTAKE!" << endl;
    cout << "Never return a pointer to a local variable!" << endl;

    // int *ptr = dangerousFunction();
    // cout << *ptr;  // UNDEFINED BEHAVIOR!
}

//============================================================================
// EXERCISE 8: Dynamic Memory Allocation
//============================================================================
void exercise8()
{
    cout << "\n========== EXERCISE 8: Dynamic Memory ==========" << endl;

    // Allocate memory for a single integer
    int *ptr = new int;
    *ptr = 999;

    cout << "Dynamically allocated value: " << *ptr << endl;

    // TODO: Allocate an array of 5 integers
    // Solution:
    // int *arr = new int[5];
    // for (int i = 0; i < 5; i++) {
    //     arr[i] = i * 10;
    //     cout << arr[i] << " ";
    // }
    // delete[] arr;  // Don't forget to free memory!

    delete ptr;    // Free the single integer
    ptr = nullptr; // Good practice: set to nullptr after delete
}

//============================================================================
// MAIN FUNCTION - Run All Exercises
//============================================================================
int main()
{
    cout << "============================================" << endl;
    cout << "C++ POINTERS - PRACTICE EXERCISES" << endl;
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

    cout << "\n============================================" << endl;
    cout << "Great job practicing pointers!" << endl;
    cout << "============================================" << endl;

    return 0;
}

//============================================================================
// SOLUTIONS REFERENCE
//============================================================================
/*
 * EXERCISE 1 SOLUTION:
 * *ptr = 100;
 * cout << "Modified value: " << *ptr << endl;
 *
 * EXERCISE 2 SOLUTION:
 * void modifyValue(int *ptr, int newValue) {
 *     *ptr = newValue;
 * }
 *
 * EXERCISE 3 SOLUTION:
 * void swap(int *a, int *b) {
 *     int temp = *a;
 *     *a = *b;
 *     *b = temp;
 * }
 *
 * EXERCISE 4 SOLUTION:
 * for (int i = 0; i < 5; i++) {
 *     cout << "arr[" << i << "] = " << *(ptr + i) << endl;
 * }
 *
 * EXERCISE 5 SOLUTION:
 * **ptrPtr = 200;
 * cout << "Modified via ptrPtr: " << **ptrPtr << endl;
 *
 * EXERCISE 6 SOLUTION:
 * for (const char *p = str; *p != '\0'; p++) {
 *     cout << *p << " ";
 * }
 *
 * EXERCISE 8 SOLUTION:
 * int *arr = new int[5];
 * for (int i = 0; i < 5; i++) {
 *     arr[i] = i * 10;
 * }
 * delete[] arr;
 */
