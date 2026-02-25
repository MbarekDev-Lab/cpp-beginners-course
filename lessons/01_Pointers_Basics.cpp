//============================================================================
// Lesson: Pointers in C++ - Basics
// Author: John Purcell (Modified and Enhanced)
// Date: February 25, 2026
// Topic: Understanding Pointers and Memory Addresses
//============================================================================
/*
 * WHAT ARE POINTERS?
 * ==================
 * A pointer is a variable that stores a memory address of another variable.
 *
 * WHY USE POINTERS?
 * =================
 * 1. Dynamic memory allocation
 * 2. Passing variables by reference to functions
 * 3. Working with arrays and strings efficiently
 * 4. Creating complex data structures (linked lists, trees, etc.)
 *
 * POINTER SYNTAX:
 * ===============
 * int *pValue;      // Declare a pointer to an integer
 * int &ref = var;   // Declare a reference to an integer
 * &nValue;          // Address-of operator: gets address of nValue
 * *pValue;          // Dereference operator: gets value at address
 */

#include <iostream>
using namespace std;

//============================================================================
// FUNCTION: manipulate
// PURPOSE: Demonstrates passing pointers to functions and modifying values
// PARAMETER: pValue - A pointer to a double
//============================================================================
void manipulate(double *pValue)
{
    // Step 2: Display the value that the pointer points to
    cout << "2. Value of double in manipulate(): " << *pValue << endl;

    // Step 3: Modify the value through the pointer
    // This changes the original variable in main()
    *pValue = 10.0;

    cout << "3. Value of double in manipulate(): " << *pValue << endl;
}

int main()
{

    // =======================================================================
    // SECTION 1: POINTERS AND INTEGERS
    // =======================================================================
    cout << "========== SECTION 1: POINTERS TO INTEGERS ==========" << endl;

    // Step 1: Declare an integer variable
    int nValue = 8;

    // Step 2: Declare a pointer to an integer
    // &nValue gets the memory address of nValue
    int *pnValue = &nValue;

    // Note: The line below is commented out, but shows how to modify
    // an integer value through a pointer
    // *pnValue = 6;

    // Step 3: Display the original value
    cout << "Int value: " << nValue << endl;

    // Step 4: Display the memory address stored in the pointer
    cout << "Pointer to int address: " << pnValue << endl;

    // Step 5: Dereference the pointer to get the value it points to
    cout << "Int value via pointer: " << *pnValue << endl;

    // =======================================================================
    // SECTION 2: POINTERS AND FUNCTIONS
    // =======================================================================
    cout << "\n========== SECTION 2: POINTERS AND FUNCTIONS ==========" << endl;

    // Step 1: Create a double variable
    double dValue = 123.4;

    cout << "1. dValue: " << dValue << endl;

    // Step 2: Pass the ADDRESS of dValue to the manipulate function
    // This allows manipulate() to modify the original dValue
    manipulate(&dValue);

    // Step 3: Display the modified value
    // Notice that dValue was changed by the manipulate function
    cout << "4. dValue: " << dValue << " (Modified by manipulate function)" << endl;

    cout << "\n========== END OF LESSON ==========" << endl;

    return 0;
}

//============================================================================
// KEY LEARNING POINTS:
// ====================
// 1. & (Address-of operator): Gets the memory address of a variable
// 2. * (Dereference operator): Accesses the value at an address
// 3. Pointers allow functions to modify variables in the caller's scope
// 4. Pointers are powerful tools for:
//    - Returning multiple values from functions
//    - Creating dynamic data structures
//    - Efficient data manipulation
//
// COMMON MISTAKES TO AVOID:
// =========================
// - Using * without declaring a pointer (e.g., int *p vs int p)
// - Dereferencing a null or uninitialized pointer (CRASH!)
// - Confusing & (address-of) with * (dereference)
// - Not passing the address (&) to a function expecting a pointer
//============================================================================
