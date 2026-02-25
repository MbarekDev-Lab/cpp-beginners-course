//============================================================================
// Lesson: Pointer Arithmetic in C++ - Advanced Techniques
// Author: M'Barek Benraiss
// Date: February 25, 2026
// Topic: Advanced Pointer Manipulation and Techniques
//============================================================================
/*
 * POINTER ARITHMETIC
 * ==================
 * Pointers support arithmetic operations that move through memory.
 *
 * SUPPORTED OPERATIONS:
 * ====================
 * ++ptr or ptr++    : Move to next element
 * --ptr or ptr--    : Move to previous element
 * ptr += n          : Move forward n elements
 * ptr -= n          : Move backward n elements
 * ptr + n           : Create pointer n elements ahead (doesn't modify ptr)
 * ptr - n           : Create pointer n elements behind
 * ptr2 - ptr1       : Distance between two pointers (in elements)
 * ptr[i]            : Access element i (same as *(ptr + i))
 *
 * KEY INSIGHT:
 * ============
 * When you add/subtract from a pointer, it moves by sizeof(type) bytes!
 * ptr += 3 doesn't add 3 bytes, it adds 3 * sizeof(type) bytes!
 */

#include <iostream>
#include <string>
using namespace std;

int main()
{

    cout << "========== POINTER ARITHMETIC ==========" << endl;

    //=========================================================================
    // SECTION 1: Setting Up Array and Pointer
    //=========================================================================
    cout << "\n--- SECTION 1: Array Setup ---" << endl;

    const int NSTRINGS = 5;

    string texts[NSTRINGS] = {"one", "two", "three", "four", "five"};

    string *pTexts = texts; // Pointer to first element

    cout << "Array: one, two, three, four, five" << endl;
    cout << "Current pointer: pTexts = " << *pTexts << endl;

    //=========================================================================
    // SECTION 2: Adding to Pointer (+=)
    //=========================================================================
    cout << "\n--- SECTION 2: Moving Forward with += ---" << endl;

    // Move 3 elements forward
    cout << "Before: *pTexts = " << *pTexts << endl;
    pTexts += 3;
    cout << "After (pTexts += 3): *pTexts = " << *pTexts << endl;
    cout << "Explanation: Moved from position 0 to position 3" << endl;

    //=========================================================================
    // SECTION 3: Subtracting from Pointer (-=)
    //=========================================================================
    cout << "\n--- SECTION 3: Moving Backward with -= ---" << endl;

    // Move 2 elements backward
    cout << "Before: *pTexts = " << *pTexts << endl;
    pTexts -= 2;
    cout << "After (pTexts -= 2): *pTexts = " << *pTexts << endl;
    cout << "Explanation: Moved from position 3 to position 1" << endl;

    //=========================================================================
    // SECTION 4: Loop Using Pointer Comparison
    //=========================================================================
    cout << "\n--- SECTION 4: Loop with Pointer Comparison ---" << endl;

    // Create a pointer to the "end" (one past the last element)
    // This is similar to STL iterators
    string *pEnd = &texts[NSTRINGS]; // One past the last element
    pTexts = &texts[0];              // Reset to beginning

    cout << "Iterating from start to end:" << endl;

    while (pTexts != pEnd)
    {
        cout << "  " << *pTexts << endl;
        pTexts++;
    }

    cout << "Loop stopped when pointers are equal" << endl;

    //=========================================================================
    // SECTION 5: Pointer Subtraction (Distance Between Pointers)
    //=========================================================================
    cout << "\n--- SECTION 5: Distance Between Pointers ---" << endl;

    // Reset pointers
    pEnd = &texts[NSTRINGS];
    pTexts = &texts[0];

    // Calculate the number of elements between pointers
    long elements = (long)(pEnd - pTexts);

    cout << "pEnd points to: position " << NSTRINGS << " (past the end)" << endl;
    cout << "pTexts points to: position 0 (beginning)" << endl;
    cout << "Distance (pEnd - pTexts) = " << elements << " elements" << endl;
    cout << "This equals the array size!" << endl;

    //=========================================================================
    // SECTION 6: Combined Operations
    //=========================================================================
    cout << "\n--- SECTION 6: Moving to Middle ---" << endl;

    pTexts = &texts[0]; // Reset to start

    // Move to the middle of the array
    pTexts += NSTRINGS / 2; // NSTRINGS/2 = 5/2 = 2

    cout << "Moving to middle: pTexts += (NSTRINGS/2)" << endl;
    cout << "Element at middle position: " << *pTexts << endl;

    //=========================================================================
    // SECTION 7: Understanding Pointer Arithmetic Memory
    //=========================================================================
    cout << "\n--- SECTION 7: How Pointer Arithmetic Works ---" << endl;

    pTexts = &texts[0];

    cout << "Memory visualization:" << endl;
    cout << "\nBefore arithmetic:" << endl;
    cout << "  pTexts = &texts[0] (address: " << pTexts << ")" << endl;
    cout << "  *pTexts = " << *pTexts << endl;

    cout << "\nAfter pTexts += 3:" << endl;
    cout << "  pTexts = address of texts[3] (address: " << (pTexts + 3) << ")" << endl;
    cout << "  *(pTexts + 3) = " << *(pTexts + 3) << endl;

    cout << "\nNote: pTexts += 3 moves by 3 * sizeof(string) bytes!" << endl;
    cout << "      Not just 3 bytes!" << endl;

    //=========================================================================
    // SECTION 8: Practical Example - Finding Position
    //=========================================================================
    cout << "\n--- SECTION 8: Finding Element Position ---" << endl;

    string target = "three";
    string *pStart = &texts[0];
    string *pCurrent = pStart;
    int position = -1;

    while (pCurrent != pEnd)
    {
        if (*pCurrent == target)
        {
            position = pCurrent - pStart; // Calculate position
            break;
        }
        pCurrent++;
    }

    if (position != -1)
    {
        cout << "Found \"" << target << "\" at position: " << position << endl;
    }

    return 0;
}

//============================================================================
// KEY LEARNING POINTS:
// ====================
// 1. Pointers support +=, -=, ++, -- operations
// 2. ptr += n moves by n * sizeof(type) bytes, NOT n bytes
// 3. ptr2 - ptr1 gives distance in elements (useful!)
// 4. One-past-end pattern: pEnd = &arr[size] for loop conditions
// 5. Pointer comparison (!=, ==, <, >) works for iteration
// 6. This is the foundation of STL iterators!
//
// COMMON PATTERNS:
// ================
// Forward loop:  while (ptr != end) { use(*ptr); ptr++; }
// Backward loop: while (ptr >= start) { use(*ptr); ptr--; }
// Distance:      int dist = (int)(ptr2 - ptr1);
// Position:      int pos = (int)(ptr - start);
//
// POINTER ARITHMETIC RULES:
// =========================
// Valid:   ptr + int, ptr - int, ptr1 - ptr2, ptr++, ptr--
// Invalid: ptr + ptr, ptr * int, ptr / int, ptr % int
// Note:    (ptr1 - ptr2) only makes sense for same array!
//============================================================================
