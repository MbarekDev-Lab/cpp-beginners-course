//============================================================================
// Lesson: Pointers and Arrays - Working with Arrays Using Pointers
// Author: M'Barek Benraiss
// Date: February 25, 2026
// Topic: Array Pointer Manipulation and Iteration Techniques
//============================================================================
/*
 * POINTERS AND ARRAYS
 * ===================
 * In C++, arrays and pointers are closely related:
 * - An array name decays to a pointer to its first element
 * - You can use pointers to access and iterate through array elements
 * - Pointer arithmetic (++, +1, etc.) moves through array memory
 *
 * THREE WAYS TO LOOP THROUGH ARRAYS:
 * ==================================
 * 1. Traditional for loop with index
 * 2. Pointer with array syntax (pArray[i])
 * 3. Pointer arithmetic (pArray++)
 * 4. Two pointers (start and end)
 *
 * KEY CONCEPTS:
 * =============
 * - arrays[] = pointer to first element
 * - *pArray = first element
 * - *(pArray+i) = element at index i
 * - pArray[i] = element at index i (same as above)
 * - pArray++ = move to next element
 */

#include <iostream>
#include <string>
using namespace std;

int main()
{

    cout << "========== POINTERS AND ARRAYS ==========" << endl;

    //=========================================================================
    // SECTION 1: Creating an Array and Pointer
    //=========================================================================
    cout << "\n--- SECTION 1: Array and Pointer Setup ---" << endl;

    // Create an array of strings
    string texts[] = {"one", "two", "three"};

    // Create a pointer to the first element
    // texts (without []) is equivalent to &texts[0]
    string *pTexts = texts;

    cout << "Array created: one, two, three" << endl;
    cout << "Pointer pointing to: " << *pTexts << endl;

    //=========================================================================
    // SECTION 2: Method 1 - Traditional For Loop with Index
    //=========================================================================
    cout << "\n--- SECTION 2: Traditional For Loop (Index-Based) ---" << endl;

    for (int i = 0; i < sizeof(texts) / sizeof(string); i++)
    {
        cout << texts[i] << " ";
    }
    cout << endl;

    cout << "Explanation:" << endl;
    cout << "- sizeof(texts) = total memory size of array" << endl;
    cout << "- sizeof(string) = size of one element" << endl;
    cout << "- Division gives the number of elements" << endl;

    //=========================================================================
    // SECTION 3: Method 2 - Pointer with Array Syntax and Pointer Arithmetic
    //=========================================================================
    cout << "\n--- SECTION 3: Pointer with Arithmetic ---" << endl;

    // Reset pointer to beginning
    pTexts = texts;

    for (int i = 0; i < sizeof(texts) / sizeof(string); i++, pTexts++)
    {
        cout << *pTexts << " " << flush;
    }
    cout << endl;

    cout << "How it works:" << endl;
    cout << "- *pTexts dereferences the pointer (gets the value)" << endl;
    cout << "- pTexts++ moves the pointer to the next element" << endl;
    cout << "- This happens in the for loop's increment section" << endl;

    //=========================================================================
    // SECTION 4: Method 3 - Two Pointers (Start and End Comparison)
    //=========================================================================
    cout << "\n--- SECTION 4: Two Pointers (Start and End) ---" << endl;

    // Create pointers to first and last elements
    string *pElement = &texts[0]; // Point to "one"
    string *pEnd = &texts[2];     // Point to "three" (last element)

    cout << "Looping from pElement to pEnd:" << endl;

    while (true)
    {
        cout << *pElement << " " << flush;

        // Check if we've reached the end
        if (pElement == pEnd)
        {
            break;
        }

        // Move to next element
        pElement++;
    }
    cout << endl;

    cout << "Important: This loop includes the end pointer!" << endl;

    //=========================================================================
    // SECTION 5: Understanding Pointer Arithmetic
    //=========================================================================
    cout << "\n--- SECTION 5: Pointer Arithmetic Deep Dive ---" << endl;

    cout << "Address and Pointer Arithmetic:" << endl;
    pTexts = texts;

    for (int i = 0; i < 3; i++)
    {
        cout << "texts[" << i << "]: address=" << &texts[i]
             << ", value=\"" << texts[i] << "\"" << endl;
    }

    cout << "\nNote: (pTexts + 1) doesn't add 1 byte!" << endl;
    cout << "It adds 1 * sizeof(string) bytes" << endl;
    cout << "So pointers 'know' the size of what they point to" << endl;

    //=========================================================================
    // SECTION 6: Different Array Types
    //=========================================================================
    cout << "\n--- SECTION 6: Pointers with Different Array Types ---" << endl;

    // Integer array
    int numbers[] = {10, 20, 30, 40, 50};
    int *pNum = numbers;

    cout << "Integer array iteration:" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << *(pNum + i) << " "; // Equivalent to pNum[i]
    }
    cout << endl;

    // Double array
    double values[] = {1.1, 2.2, 3.3};
    double *pVal = values;

    cout << "Double array iteration:" << endl;
    for (int i = 0; i < 3; i++, pVal++)
    {
        cout << *pVal << " ";
    }
    cout << endl;

    //=========================================================================
    // SECTION 7: Array Names vs Pointers
    //=========================================================================
    cout << "\n--- SECTION 7: Array Names Decay to Pointers ---" << endl;

    string cities[] = {"NYC", "LA", "Chicago"};

    cout << "cities (array name) = " << cities << endl;
    cout << "&cities[0] (address of first element) = " << &cities[0] << endl;
    cout << "They point to the same memory location!" << endl;

    return 0;
}

//============================================================================
// KEY LEARNING POINTS:
// ====================
// 1. Array names decay to pointers to their first element
// 2. Pointer arithmetic (++) moves by element size, not by 1 byte
// 3. pArray[i] is equivalent to *(pArray + i)
// 4. Calculate array size: sizeof(array) / sizeof(array[0])
// 5. Can iterate using index, pointer++, or pointer comparison
// 6. Pointers allow flexible and efficient array manipulation
//
// COMMON MISTAKES:
// ================
// - Forgetting array size: use sizeof trick or pass size to function
// - Going past array bounds: always check conditions
// - Comparing uninitialized pointers
// - Forgetting that pArray++ happens AFTER use in loops
//
// POINTER VS INDEX:
// =================
// Index-based:  for (int i = 0; i < size; i++) { arr[i]... }
// Pointer-based: for (int i = 0; i < size; i++, ptr++) { *ptr... }
// Two-pointer:   while (ptr <= endPtr) { *ptr++... }
//============================================================================
