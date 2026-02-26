//============================================================================
// String Reversal Exercises - Practice Problems
// Master the two-pointer string reversal technique!
//============================================================================

#include <iostream>
#include <cstring>
using namespace std;

//============================================================================
// EXERCISE 1: Basic String Reversal
//============================================================================
void exercise1()
{
    cout << "\n========== EXERCISE 1: Basic String Reversal ==========" << endl;

    char text[] = "abc";

    cout << "Original string: \"" << text << "\"" << endl;

    // Calculate positions
    int nChars = sizeof(text) - 1;
    char *pStart = &text[0];
    char *pEnd = &text[nChars - 1];

    // Reverse
    while (pStart < pEnd)
    {
        char temp = *pStart;
        *pStart = *pEnd;
        *pEnd = temp;
        pStart++;
        pEnd--;
    }

    cout << "Reversed string: \"" << text << "\"" << endl;
}

//============================================================================
// EXERCISE 2: Understand Pointer Positions
//============================================================================
void exercise2()
{
    cout << "\n========== EXERCISE 2: Pointer Positions ==========" << endl;

    char text[] = "hello";

    int nCharsAll = sizeof(text);  // Includes null terminator
    int nChars = sizeof(text) - 1; // Just the string

    cout << "String: \"" << text << "\"" << endl;
    cout << "Total array size: " << nCharsAll << " bytes" << endl;
    cout << "String length: " << nChars << " characters" << endl;

    char *pStart = text;
    char *pEnd = text + nChars - 1;

    cout << "\npStart points to: '" << *pStart << "' (position 0)" << endl;
    cout << "pEnd points to: '" << *pEnd << "' (position " << (nChars - 1) << ")" << endl;

    // TODO: Calculate and print middle character position
}

//============================================================================
// EXERCISE 3: Manual Swap Operation
//============================================================================
void exercise3()
{
    cout << "\n========== EXERCISE 3: Manual Swap ==========" << endl;

    char a = 'X';
    char b = 'Y';

    cout << "Before swap: a='" << a << "', b='" << b << "'" << endl;

    // TODO: Swap a and b using a temporary variable
    char temp = a;
    a = b;
    b = temp;

    cout << "After swap: a='" << a << "', b='" << b << "'" << endl;
}

//============================================================================
// EXERCISE 4: Reverse Longer String
//============================================================================
void exercise4()
{
    cout << "\n========== EXERCISE 4: Reverse Longer String ==========" << endl;

    char text[] = "programming";

    cout << "Original: \"" << text << "\"" << endl;

    int nChars = strlen(text);
    char *pStart = &text[0];
    char *pEnd = &text[nChars - 1];

    // TODO: Implement reversal
    while (pStart < pEnd)
    {
        char temp = *pStart;
        *pStart = *pEnd;
        *pEnd = temp;
        pStart++;
        pEnd--;
    }

    cout << "Reversed: \"" << text << "\"" << endl;
}

//============================================================================
// EXERCISE 5: Reverse Odd vs Even Length
//============================================================================
void exercise5()
{
    cout << "\n========== EXERCISE 5: Odd vs Even Length ==========" << endl;

    // Odd length
    char odd[] = "hello"; // 5 characters
    cout << "Odd length string: \"" << odd << "\"" << endl;

    int len = strlen(odd);
    char *pStart = &odd[0];
    char *pEnd = &odd[len - 1];

    while (pStart < pEnd)
    {
        char temp = *pStart;
        *pStart = *pEnd;
        *pEnd = temp;
        pStart++;
        pEnd--;
    }

    cout << "Reversed: \"" << odd << "\"" << endl;

    // Even length
    char even[] = "world!"; // 6 characters
    cout << "\nEven length string: \"" << even << "\"" << endl;

    len = strlen(even);
    pStart = &even[0];
    pEnd = &even[len - 1];

    // TODO: Reverse the even string
    while (pStart < pEnd)
    {
        char temp = *pStart;
        *pStart = *pEnd;
        *pEnd = temp;
        pStart++;
        pEnd--;
    }

    cout << "Reversed: \"" << even << "\"" << endl;
}

//============================================================================
// EXERCISE 6: Trace Through Reversal
//============================================================================
void exercise6()
{
    cout << "\n========== EXERCISE 6: Trace Reversal Steps ==========" << endl;

    char text[] = "code"; // 4 characters (even)

    cout << "Original: \"" << text << "\"" << endl;
    cout << "Let's trace each swap:" << endl;

    int nChars = strlen(text);
    char *pStart = &text[0];
    char *pEnd = &text[nChars - 1];

    int step = 0;
    while (pStart < pEnd)
    {
        step++;
        cout << "\n  Step " << step << ":" << endl;
        cout << "    Swap '" << *pStart << "' with '" << *pEnd << "'" << endl;

        char temp = *pStart;
        *pStart = *pEnd;
        *pEnd = temp;

        cout << "    String: \"" << text << "\"" << endl;

        pStart++;
        pEnd--;
    }

    cout << "\nFinal: \"" << text << "\"" << endl;
}

//============================================================================
// EXERCISE 7: Reverse and Store in Different Array
//============================================================================
void exercise7()
{
    cout << "\n========== EXERCISE 7: Reverse to Different Array ==========" << endl;

    char source[] = "hello";
    char dest[6]; // Need space for string + null terminator

    cout << "Source: \"" << source << "\"" << endl;

    // TODO: Copy in reverse order
    char *src = source;
    char *d = dest + strlen(source) - 1; // Start at end of dest

    while (*src != '\0')
    {
        *d = *src;
        src++;
        d--;
    }
    *d = '\0'; // Add null terminator at start

    cout << "Destination (reversed): \"" << dest << "\"" << endl;
}

//============================================================================
// EXERCISE 8: Check if Palindrome
//============================================================================
void exercise8()
{
    cout << "\n========== EXERCISE 8: Check Palindrome ==========" << endl;

    char str[] = "racecar";

    cout << "String: \"" << str << "\"" << endl;

    char *pStart = &str[0];
    char *pEnd = &str[strlen(str) - 1];

    bool isPalin = true;

    // TODO: Check if palindrome by comparing letters
    while (pStart < pEnd)
    {
        if (*pStart != *pEnd)
        {
            isPalin = false;
            break;
        }
        pStart++;
        pEnd--;
    }

    if (isPalin)
    {
        cout << "This is a PALINDROME!" << endl;
    }
    else
    {
        cout << "This is NOT a palindrome." << endl;
    }
}

//============================================================================
// EXERCISE 9: Reverse Specific Range
//============================================================================
void exercise9()
{
    cout << "\n========== EXERCISE 9: Reverse Specific Range ==========" << endl;

    char text[] = "abcdefgh";

    cout << "Original: \"" << text << "\"" << endl;
    cout << "Reversing characters from index 2 to 5 (cdef)" << endl;

    char *pStart = &text[2]; // Point to 'c'
    char *pEnd = &text[5];   // Point to 'f'

    // TODO: Reverse only this range
    while (pStart < pEnd)
    {
        char temp = *pStart;
        *pStart = *pEnd;
        *pEnd = temp;
        pStart++;
        pEnd--;
    }

    cout << "Result: \"" << text << "\"" << endl;
}

//============================================================================
// EXERCISE 10: Reverse Each Word
//============================================================================
void exercise10()
{
    cout << "\n========== EXERCISE 10: Reverse Each Word ==========" << endl;

    char sentence[] = "hello world";

    cout << "Original: \"" << sentence << "\"" << endl;

    char *start = sentence;
    char *current = sentence;

    // TODO: Reverse each word individually
    while (*current != '\0')
    {
        if (*current == ' ' || *(current + 1) == '\0')
        {
            char *end = (*(current + 1) == '\0') ? current : current - 1;

            while (start < end)
            {
                char temp = *start;
                *start = *end;
                *end = temp;
                start++;
                end--;
            }

            start = current + 1; // Skip space or move to end
        }
        current++;
    }

    cout << "Each word reversed: \"" << sentence << "\"" << endl;
}

//============================================================================
// EXERCISE 11: Compare Original and Reversed
//============================================================================
void exercise11()
{
    cout << "\n========== EXERCISE 11: Compare Before and After ==========" << endl;

    char text[] = "madam";
    char reversed[6];
    strcpy(reversed, text); // Copy original

    cout << "Original: \"" << text << "\"" << endl;

    // Reverse the copy
    char *pStart = &reversed[0];
    char *pEnd = &reversed[strlen(reversed) - 1];

    while (pStart < pEnd)
    {
        char temp = *pStart;
        *pStart = *pEnd;
        *pEnd = temp;
        pStart++;
        pEnd--;
    }

    cout << "Reversed: \"" << reversed << "\"" << endl;

    // TODO: Compare them and check if palindrome
    if (strcmp(text, reversed) == 0)
    {
        cout << "This is a PALINDROME!" << endl;
    }
    else
    {
        cout << "NOT a palindrome." << endl;
    }
}

//============================================================================
// EXERCISE 12: Reverse Array of Integers
//============================================================================
void exercise12()
{
    cout << "\n========== EXERCISE 12: Reverse Integer Array ==========" << endl;

    int arr[] = {1, 2, 3, 4, 5};
    int size = 5;

    cout << "Original: ";
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;

    // TODO: Reverse using pointer technique
    int *pStart = &arr[0];
    int *pEnd = &arr[size - 1];

    while (pStart < pEnd)
    {
        int temp = *pStart;
        *pStart = *pEnd;
        *pEnd = temp;
        pStart++;
        pEnd--;
    }

    cout << "Reversed: ";
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

//============================================================================
// EXERCISE 13: Algorithm Complexity Analysis
//============================================================================
void exercise13()
{
    cout << "\n========== EXERCISE 13: Complexity Analysis ==========" << endl;

    cout << "String Reversal Algorithm Complexity:" << endl;
    cout << "\nTime Complexity: O(n)" << endl;
    cout << "  - Visit each character once" << endl;
    cout << "  - n = string length" << endl;

    cout << "\nSpace Complexity: O(1)" << endl;
    cout << "  - Only use a temporary character variable" << endl;
    cout << "  - No extra arrays or data structures" << endl;
    cout << "  - In-place modification" << endl;

    cout << "\nWhy this is efficient:" << endl;
    cout << "  - Cannot do better than O(n) for visiting each char" << endl;
    cout << "  - Using O(1) space is optimal" << endl;
    cout << "  - Two-pointer technique is as good as it gets!" << endl;
}

//============================================================================
// MAIN FUNCTION - Run All Exercises
//============================================================================
int main()
{
    cout << "============================================" << endl;
    cout << "C++ STRING REVERSAL - PRACTICE EXERCISES" << endl;
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
    cout << "Great job practicing string reversal!" << endl;
    cout << "============================================" << endl;

    return 0;
}

//============================================================================
// SOLUTIONS REFERENCE
//============================================================================
/*
 * EXERCISE 3 SOLUTION:
 * char temp = a;
 * a = b;
 * b = temp;
 *
 * EXERCISE 4 SOLUTION:
 * while (pStart < pEnd) {
 *     char temp = *pStart;
 *     *pStart = *pEnd;
 *     *pEnd = temp;
 *     pStart++;
 *     pEnd--;
 * }
 *
 * EXERCISE 8 SOLUTION (palindrome check):
 * while (pStart < pEnd) {
 *     if (*pStart != *pEnd) {
 *         isPalin = false;
 *         break;
 *     }
 *     pStart++;
 *     pEnd--;
 * }
 *
 * EXERCISE 10 (reverse each word):
 * while (*current != '\0') {
 *     if (*current == ' ' || *(current + 1) == '\0') {
 *         char *end = (*(current + 1) == '\0') ? current : current - 1;
 *         while (start < end) {
 *             char temp = *start;
 *             *start = *end;
 *             *end = temp;
 *             start++;
 *             end--;
 *         }
 *         start = current + 1;
 *     }
 *     current++;
 * }
 *
 * EXERCISE 12 (integer array reversal):
 * int *pStart = &arr[0];
 * int *pEnd = &arr[size - 1];
 * while (pStart < pEnd) {
 *     int temp = *pStart;
 *     *pStart = *pEnd;
 *     *pEnd = temp;
 *     pStart++;
 *     pEnd--;
 * }
 */
