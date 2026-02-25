//============================================================================
// Arithmetic Operations Exercises - Practice Problems
// Solve these exercises to master arithmetic operations!
//============================================================================

#include <iostream>
using namespace std;

//============================================================================
// EXERCISE 1: Basic Arithmetic Operations
//============================================================================
void exercise1()
{
    cout << "\n========== EXERCISE 1: Basic Arithmetic ==========" << endl;

    int a = 10;
    int b = 3;

    cout << a << " + " << b << " = " << (a + b) << endl;
    cout << a << " - " << b << " = " << (a - b) << endl;
    cout << a << " * " << b << " = " << (a * b) << endl;
    cout << a << " / " << b << " = " << (a / b) << endl;
    cout << a << " % " << b << " = " << (a % b) << endl;

    // TODO: Perform the same operations with a = 20, b = 4
}

//============================================================================
// EXERCISE 2: Integer vs. Double Division
//============================================================================
void exercise2()
{
    cout << "\n========== EXERCISE 2: Integer vs Double Division ==========" << endl;

    // Integer division
    cout << "Integer division: 7 / 2 = " << 7 / 2 << endl;

    // Double division
    cout << "Double division: 7.0 / 2.0 = " << 7.0 / 2.0 << endl;

    // TODO: Show the difference between these divisions
    // cout << "Cast to double: (double)7 / 2 = " << ...

    cout << "\nWhy the difference?" << endl;
    cout << "Integer arithmetic truncates (removes) decimals." << endl;
}

//============================================================================
// EXERCISE 3: Type Casting
//============================================================================
void exercise3()
{
    cout << "\n========== EXERCISE 3: Type Casting ==========" << endl;

    // Cast double to int (truncates decimal)
    double num1 = 7.9;
    int result1 = (int)num1;
    cout << "Cast " << num1 << " to int: " << result1 << endl;

    // Cast int to double
    int num2 = 5;
    double result2 = (double)num2;
    cout << "Cast " << num2 << " to double: " << result2 << endl;

    // TODO: Perform more casting examples
    // Cast 15.7 to int
    // Cast 100 to double
    // Cast 3.14 to int and see what happens
}

//============================================================================
// EXERCISE 4: Compound Assignment Operators
//============================================================================
void exercise4()
{
    cout << "\n========== EXERCISE 4: Compound Assignment ==========" << endl;

    int x = 10;

    cout << "Starting value: x = " << x << endl;

    x += 5;
    cout << "After x += 5: " << x << endl;

    x -= 3;
    cout << "After x -= 3: " << x << endl;

    x *= 2;
    cout << "After x *= 2: " << x << endl;

    x /= 4;
    cout << "After x /= 4: " << x << endl;

    // TODO: Continue with x %= value
}

//============================================================================
// EXERCISE 5: Increment and Decrement
//============================================================================
void exercise5()
{
    cout << "\n========== EXERCISE 5: Increment and Decrement ==========" << endl;

    int count = 5;
    cout << "Starting: count = " << count << endl;

    count++;
    cout << "After count++: " << count << endl;

    count--;
    cout << "After count--: " << count << endl;

    // TODO: Show the difference between pre and post increment
    // int a = 5;
    // int b = a++;  // Post-increment: b = 5, then a = 6
    // int c = ++a;  // Pre-increment: a = 7, then c = 7
}

//============================================================================
// EXERCISE 6: Modulo Operator - Finding Remainder
//============================================================================
void exercise6()
{
    cout << "\n========== EXERCISE 6: Modulo Operator ==========" << endl;

    cout << "Finding remainders:" << endl;
    cout << "17 % 5 = " << 17 % 5 << " (17 ÷ 5 = 3 remainder 2)" << endl;
    cout << "20 % 3 = " << 20 % 3 << endl;
    cout << "10 % 2 = " << 10 % 2 << endl;

    // TODO: Calculate remainder for your own numbers
}

//============================================================================
// EXERCISE 7: Even or Odd
//============================================================================
void exercise7()
{
    cout << "\n========== EXERCISE 7: Check Even or Odd ==========" << endl;

    int num = 7;

    if (num % 2 == 0)
    {
        cout << num << " is EVEN" << endl;
    }
    else
    {
        cout << num << " is ODD" << endl;
    }

    // TODO: Check several numbers (5, 10, 15, 20)
    // TODO: Use a loop to check numbers 1-10
}

//============================================================================
// EXERCISE 8: Operator Precedence
//============================================================================
void exercise8()
{
    cout << "\n========== EXERCISE 8: Operator Precedence ==========" << endl;

    // Calculate: 2 + 3 * 4
    cout << "2 + 3 * 4 = " << (2 + 3 * 4) << endl;
    cout << "Explanation: Multiply first (3*4=12), then add (2+12=14)" << endl;

    // Compare with:
    cout << "(2 + 3) * 4 = " << ((2 + 3) * 4) << endl;
    cout << "Explanation: Add first (2+3=5), then multiply (5*4=20)" << endl;

    // TODO: Solve these expressions and verify
    // 5 + 2 * 3 - 1
    // (5 + 2) * (3 - 1)
    // 10 / 2 + 3 * 4
}

//============================================================================
// EXERCISE 9: Convert Seconds to Hours, Minutes, Seconds
//============================================================================
void exercise9()
{
    cout << "\n========== EXERCISE 9: Convert Seconds ==========" << endl;

    int totalSeconds = 3661; // 1 hour, 1 minute, 1 second

    // TODO: Calculate and display hours, minutes, remaining seconds
    // Hints:
    // - One hour = 3600 seconds
    // - One minute = 60 seconds
    // - Use division (/) for quotient and modulo (%) for remainder

    // Example output:
    // 3661 seconds = 1 hour, 1 minute, 1 second

    cout << "Total seconds: " << totalSeconds << endl;

    // Solution:
    // int hours = totalSeconds / 3600;
    // int remaining = totalSeconds % 3600;
    // int minutes = remaining / 60;
    // int seconds = remaining % 60;
}

//============================================================================
// EXERCISE 10: Progress Indicator Loop
//============================================================================
void exercise10()
{
    cout << "\n========== EXERCISE 10: Progress Indicator ==========" << endl;

    cout << "Loop with output every 100 iterations:" << endl;

    for (int i = 1; i <= 1000; i++)
    {
        if (i % 100 == 0)
        {
            cout << ".";
        }
    }
    cout << endl;
    cout << "Done! (1000 iterations)" << endl;

    // TODO: Modify the loop to print output every 250 iterations
    // TODO: Print the iteration number when printing the dot
    // Example output: 100. 200. 300. ...
}

//============================================================================
// EXERCISE 11: Multiplication Table (Using Modulo for Formatting)
//============================================================================
void exercise11()
{
    cout << "\n========== EXERCISE 11: Multiplication Table ==========" << endl;

    cout << "Times table for 7:" << endl;
    for (int i = 1; i <= 12; i++)
    {
        cout << "7 × " << i << " = " << (7 * i) << endl;
    }

    // TODO: Create a multiplication table with newlines every 4 entries
    // Hint: Use modulo to determine when to print newline
    // if (i % 4 == 0) cout << "\n";
}

//============================================================================
// EXERCISE 12: Mini Calculator
//============================================================================
void exercise12()
{
    cout << "\n========== EXERCISE 12: Mini Calculator ==========" << endl;

    // Create a simple calculator
    int x = 50;
    int y = 15;

    cout << "Calculator with x = " << x << " and y = " << y << endl;
    cout << "x + y = " << (x + y) << endl;
    cout << "x - y = " << (x - y) << endl;
    cout << "x * y = " << (x * y) << endl;
    cout << "x / y = " << (x / y) << " remainder " << (x % y) << endl;

    // TODO: Create functions that perform these operations
    // TODO: Add more complex operations like: (x + y) * 2 / (x - y)
}

//============================================================================
// MAIN FUNCTION - Run All Exercises
//============================================================================
int main()
{
    cout << "============================================" << endl;
    cout << "C++ ARITHMETIC OPERATIONS - PRACTICE EXERCISES" << endl;
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

    cout << "\n============================================" << endl;
    cout << "Great job practicing arithmetic operations!" << endl;
    cout << "============================================" << endl;

    return 0;
}

//============================================================================
// SOLUTIONS REFERENCE
//============================================================================
/*
 * EXERCISE 2 SOLUTION:
 * cout << "Cast to double: (double)7 / 2 = " << (double)7 / 2 << endl;
 *
 * EXERCISE 4 SOLUTION:
 * x %= 7;
 * cout << "After x %= 7: " << x << endl;
 *
 * EXERCISE 5 SOLUTION:
 * int a = 5;
 * int b = a++;  // b = 5, then a = 6
 * cout << "Post-increment: b = " << b << ", a = " << a << endl;
 *
 * EXERCISE 7 SOLUTION:
 * for (int i = 1; i <= 10; i++) {
 *     cout << i << " is " << (i % 2 == 0 ? "EVEN" : "ODD") << endl;
 * }
 *
 * EXERCISE 9 SOLUTION:
 * int hours = totalSeconds / 3600;
 * int remaining = totalSeconds % 3600;
 * int minutes = remaining / 60;
 * int seconds = remaining % 60;
 * cout << totalSeconds << " seconds = " << hours << " hour, "
 *       << minutes << " minute, " << seconds << " second" << endl;
 *
 * EXERCISE 10 SOLUTION:
 * for (int i = 1; i <= 1000; i += 250) {
 *     cout << i << ". ";
 * }
 *
 * EXERCISE 11 SOLUTION:
 * for (int i = 1; i <= 12; i++) {
 *     cout << "7 × " << i << " = " << (7 * i);
 *     if (i % 4 == 0) cout << "\n";
 *     else cout << " | ";
 * }
 */
