//============================================================================
// Lesson: Arithmetic Operations in C++ - Basics
// Author: John Purcell (Modified and Enhanced)
// Date: February 25, 2026
// Topic: Operators, Type Casting, and Precedence
//============================================================================
/*
 * ARITHMETIC OPERATORS IN C++
 * ============================
 * +    : Addition
 * -    : Subtraction
 * *    : Multiplication
 * /    : Division
 * %    : Modulo (remainder after division)
 *
 * COMPOUND ASSIGNMENT OPERATORS
 * ==============================
 * +=   : Add and assign (a += b is same as a = a + b)
 * -=   : Subtract and assign
 * *=   : Multiply and assign
 * /=   : Divide and assign
 * %=   : Modulo and assign
 *
 * OTHER OPERATORS
 * ================
 * ++   : Increment by 1
 * --   : Decrement by 1
 *
 * OPERATOR PRECEDENCE
 * ====================
 * 1. Parentheses ()
 * 2. Multiplication, Division, Modulo (*, /, %)
 * 3. Addition, Subtraction (+, -)
 * 4. Assignment (=, +=, -=, etc.)
 *
 * Remember: PEMDAS/BODMAS applies!
 * (P/B - Parentheses/Brackets first)
 */

#include <iostream>
using namespace std;

int main()
{

    cout << "========== BASIC ARITHMETIC OPERATORS ==========" << endl;

    //=========================================================================
    // SECTION 1: Type Casting - Converting Between Data Types
    //=========================================================================
    cout << "\n--- SECTION 1: Type Casting ---" << endl;

    // When dividing integers, the result is an integer (truncation)
    // Integer division: 7 / 2 = 3 (not 3.5!)
    cout << "Integer division 7/2 = " << 7 / 2 << endl;

    // To get a decimal result, cast to double
    // (double)7 tells the compiler: treat 7 as a double first
    double value1 = (double)7 / 2;
    cout << "Double division (double)7/2 = " << value1 << endl;

    // Casting a double to int truncates (removes) decimal part
    int value2 = (int)7.3;
    cout << "Cast 7.3 to int: " << value2 << endl;

    //=========================================================================
    // SECTION 2: Compound Assignment Operators
    //=========================================================================
    cout << "\n--- SECTION 2: Compound Assignment Operators ---" << endl;

    // += means: add to the variable
    int value3 = 8;
    cout << "Before +=: value3 = " << value3 << endl;
    value3 += 1; // Same as: value3 = value3 + 1  or  value3++
    cout << "After += 1: value3 = " << value3 << endl;

    // /= means: divide the variable
    int value4 = 10;
    cout << "\nBefore /=: value4 = " << value4 << endl;
    value4 /= 5; // Same as: value4 = value4 / 5
    cout << "After /= 5: value4 = " << value4 << endl;

    //=========================================================================
    // SECTION 3: Modulo Operator (%)
    //=========================================================================
    cout << "\n--- SECTION 3: Modulo Operator (%) ---" << endl;

    // Modulo gives the REMAINDER after division
    int value5 = 13 % 5;
    cout << "13 % 5 = " << value5 << endl;
    cout << "Explanation: 13 ÷ 5 = 2 remainder 3" << endl;

    // Modulo is useful for:
    // - Finding if a number is even or odd
    // - Creating repeating patterns
    // - Cycling through array indices

    cout << "\nMore modulo examples:" << endl;
    cout << "10 % 3 = " << 10 % 3 << endl;
    cout << "20 % 4 = " << 20 % 4 << endl;
    cout << "7 % 2 = " << 7 % 2 << " (odd number)" << endl;
    cout << "8 % 2 = " << 8 % 2 << " (even number)" << endl;

    //=========================================================================
    // SECTION 4: Operator Precedence
    //=========================================================================
    cout << "\n--- SECTION 4: Operator Precedence ---" << endl;

    // Without parentheses, follow standard math rules: multiply/divide before add/subtract
    double equation = ((5 / 4) % 2) + (2.3 * 6);

    cout << "Equation: ((5/4) % 2) + (2.3 * 6)" << endl;
    cout << "Step 1: 5/4 = " << (5 / 4) << " (integer division)" << endl;
    cout << "Step 2: 1 % 2 = " << (1 % 2) << endl;
    cout << "Step 3: 2.3 * 6 = " << (2.3 * 6) << endl;
    cout << "Step 4: 1 + 13.8 = " << equation << endl;
    cout << "\nFinal result: " << equation << endl;

    // Without parentheses, the order of operations matters!
    cout << "\n--- Comparison ---" << endl;
    cout << "5 / 4 % 2 + 2.3 * 6 (left to right where precedence is equal) = "
         << (5 / 4 % 2 + 2.3 * 6) << endl;

    //=========================================================================
    // SECTION 5: Practical Example - Progress Indicator
    //=========================================================================
    cout << "\n--- SECTION 5: Using Modulo for Progress Indicator ---" << endl;
    cout << "Loop output (dot every 100 iterations):" << endl;

    for (int i = 1; i <= 1000; i++)
    {
        if (i % 100 == 0)
        { // Every 100 iterations
            cout << ".";
        }
    }
    cout << endl;

    cout << "\nDone! (Printed 10 dots for 1000 iterations)" << endl;

    return 0;
}

//============================================================================
// KEY LEARNING POINTS:
// ====================
// 1. Integer division truncates (7/2 = 3, not 3.5)
// 2. Cast to double for decimal results: (double)7/2
// 3. Compound operators (+=, -=, etc.) modify variables in place
// 4. Modulo (%) returns the remainder, useful for patterns
// 5. Operator precedence: parentheses > * / % > + -
// 6. Always use parentheses if unsure about precedence!
//
// OPERATOR QUICK REFERENCE:
// =========================
// a + b    : Addition
// a - b    : Subtraction
// a * b    : Multiplication
// a / b    : Division (truncates if both integers)
// a % b    : Modulo (remainder)
// a += b   : a = a + b
// a -= b   : a = a - b
// a *= b   : a = a * b
// a /= b   : a = a / b
// a %= b   : a = a % b
// a++      : Increment (a = a + 1)
// a--      : Decrement (a = a - 1)
//============================================================================
