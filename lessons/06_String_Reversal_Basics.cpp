//============================================================================
// Lesson: Reversing a String - Two-Pointer Technique
// Author: M'Barek Benraiss
// Date: February 26, 2026
// Topic: String Reversal Using Pointer Manipulation and Swapping
//============================================================================
/*
 * REVERSING A STRING
 * ==================
 * One of the most common string operations using the two-pointer technique.
 *
 * ALGORITHM:
 * ==========
 * 1. Create pointer to start of string
 * 2. Create pointer to end of string
 * 3. Swap characters
 * 4. Move pointers toward each other
 * 5. Stop when pointers meet
 *
 * KEY CONCEPTS:
 * =============
 * - Two-pointer technique (start and end)
 * - Character swapping logic
 * - Pointer movement (++ and --)
 * - Loop termination condition (pStart < pEnd)
 * - In-place modification (no extra memory needed)
 *
 * WHY THIS WORKS:
 * ===============
 * - Start from both ends and work toward middle
 * - Swap characters as you go
 * - When pointers cross or meet, entire string is reversed
 * - Time: O(n), Space: O(1) - very efficient!
 */

#include <iostream>
using namespace std;

int main()
{

    cout << "========== STRING REVERSAL - TWO POINTER TECHNIQUE ==========" << endl;

    //=========================================================================
    // SETUP: Create String and Calculate Positions
    //=========================================================================
    cout << "\n--- SETUP: String and Pointer Positions ---" << endl;

    char text[] = "hello"; // h e l l o \0

    // Calculate total size (includes null terminator)
    int nCharsAll = sizeof(text);
    cout << "Total array size (including \\0): " << nCharsAll << " bytes" << endl;

    // Calculate actual string length (without null terminator)
    int nChars = sizeof(text) - 1;
    cout << "String length (without \\0): " << nChars << " characters" << endl;

    cout << "\nOriginal string: \"" << text << "\"" << endl;
    cout << "Memory visualization:" << endl;
    cout << "  [h][e][l][l][o][\\0]" << endl;
    cout << "   0  1  2  3  4   5" << endl;

    //=========================================================================
    // SECTION 1: Setting Up Pointers
    //=========================================================================
    cout << "\n--- SECTION 1: Setting Up Pointers ---" << endl;

    // Pointer to the start of the string
    char *pStart = text; // Same as: char *pStart = &text[0];

    // Pointer to the end (last character, not null terminator!)
    char *pEnd = text + nChars - 1; // text + 5 - 1 = text + 4 (points to 'o')

    cout << "pStart points to: '" << *pStart << "' (address: " << (void *)pStart << ")" << endl;
    cout << "pEnd points to: '" << *pEnd << "' (address: " << (void *)pEnd << ")" << endl;

    //=========================================================================
    // SECTION 2: Understanding the Swap Logic
    //=========================================================================
    cout << "\n--- SECTION 2: The Swap Operation ---" << endl;

    cout << "To swap two characters, we need a temporary variable:" << endl;
    cout << "\n  Pseudocode:" << endl;
    cout << "    temp = *pStart    // Save first character" << endl;
    cout << "    *pStart = *pEnd   // Move last to first" << endl;
    cout << "    *pEnd = temp      // Move saved first to last" << endl;

    cout << "\nExample swap:" << endl;
    cout << "  Before: *pStart = 'h', *pEnd = 'o'" << endl;
    cout << "  After:  *pStart = 'o', *pEnd = 'h'" << endl;

    //=========================================================================
    // SECTION 3: The Reversal Loop
    //=========================================================================
    cout << "\n--- SECTION 3: Reversing the String ---" << endl;

    cout << "Starting reversal:" << endl;

    int iteration = 0;
    while (pStart < pEnd)
    {
        iteration++;

        cout << "\n  Iteration " << iteration << ":" << endl;
        cout << "    Before: pStart='" << *pStart << "' pEnd='" << *pEnd << "'" << endl;

        // Swap characters
        char ch = *pStart;
        *pStart = *pEnd;
        *pEnd = ch;

        cout << "    After:  pStart='" << *pStart << "' pEnd='" << *pEnd << "'" << endl;

        // Move pointers toward middle
        pStart++;
        pEnd--;

        cout << "    String so far: \"" << text << "\"" << endl;
    }

    cout << "\nReversal complete!" << endl;

    //=========================================================================
    // SECTION 4: The Final Result
    //=========================================================================
    cout << "\n--- SECTION 4: Final Result ---" << endl;

    cout << "Original: " << "hello" << endl;
    cout << "Reversed: " << text << endl;

    //=========================================================================
    // SECTION 5: Why pStart < pEnd is Correct
    //=========================================================================
    cout << "\n--- SECTION 5: Understanding the Loop Condition ---" << endl;

    cout << "We use 'pStart < pEnd' because:" << endl;
    cout << "1. When pointers point to same character (odd length), we're done" << endl;
    cout << "2. When pointers cross (even length), we're done" << endl;
    cout << "3. No need to swap a character with itself (middle character)" << endl;

    cout << "\nFor 'hello' (odd length=5):" << endl;
    cout << "  Start: pStart=h(0), pEnd=o(4)" << endl;
    cout << "  After iteration 1: pStart=e(1), pEnd=l(3)" << endl;
    cout << "  After iteration 2: pStart=l(2), pEnd=l(2)" << endl;
    cout << "  Loop stops (pStart NOT < pEnd), middle 'l' stays" << endl;

    //=========================================================================
    // SECTION 6: Alternative Approach - From Ends Outward
    //=========================================================================
    cout << "\n--- SECTION 6: Visualization of Algorithm ---" << endl;

    cout << "Step-by-step for \"hello\":" << endl;
    cout << "  Start:  [h][e][l][l][o]" << endl;
    cout << "           ^           ^" << endl;
    cout << "           |           |" << endl;
    cout << "          start       end" << endl;

    cout << "\n  Swap(h,o):  [o][e][l][l][h]" << endl;
    cout << "              ^           ^" << endl;
    cout << "              |           |" << endl;
    cout << "             move        move" << endl;

    cout << "\n  Swap(e,l):  [o][l][l][e][h]" << endl;
    cout << "                ^       ^" << endl;
    cout << "                |       |" << endl;
    cout << "               meet/pass - STOP!" << endl;

    cout << "\n  Final: [o][l][l][e][h] = \"olleh\"" << endl;

    return 0;
}

//============================================================================
// KEY LEARNING POINTS:
// ====================
// 1. Two-pointer technique works from both ends toward middle
// 2. Swap using temporary variable: temp=a; a=b; b=temp;
// 3. pStart++ moves pointer forward, pEnd-- moves backward
// 4. Loop stops when pStart >= pEnd (pointers meet or cross)
// 5. Works for any length string (odd or even)
// 6. Time complexity: O(n), Space complexity: O(1)
// 7. Modifies string in-place (no extra array needed)
//
// THE COMPLETE ALGORITHM:
// =======================
// 1. Set pStart = &text[0] (first char)
// 2. Set pEnd = &text[length-1] (last char)
// 3. While pStart < pEnd:
//    a. Swap *pStart and *pEnd
//    b. pStart++
//    c. pEnd--
// 4. String is now reversed
//
// POINTER ARITHMETIC USED:
// ========================
// text + nChars - 1  = Address of last character
// pStart++           = Move to next character
// pEnd--             = Move to previous character
// pStart < pEnd      = Check if pointers haven't crossed
//============================================================================
