//============================================================================
// Character Arrays and Strings Exercises - Practice Problems
// Master working with character arrays and C-strings!
//============================================================================

#include <iostream>
#include <cstring> // For string functions like strlen, strcpy
using namespace std;

//============================================================================
// EXERCISE 1: Understanding String Memory Layout
//============================================================================
void exercise1()
{
    cout << "\n========== EXERCISE 1: String Memory Layout ==========" << endl;

    char str[] = "abc";

    cout << "String: \"abc\"" << endl;
    cout << "Array structure:" << endl;

    for (int i = 0; i < sizeof(str); i++)
    {
        if (str[i] == '\0')
        {
            cout << "  [" << i << "]: '\\0' (Null Terminator)" << endl;
        }
        else
        {
            cout << "  [" << i << "]: '" << str[i] << "'" << endl;
        }
    }

    cout << "\nArray size: " << sizeof(str) << " bytes" << endl;
    cout << "String length: " << strlen(str) << " characters" << endl;

    // TODO: Try with your own string
    // char yourStr[] = "hello";
    // Calculate and print its layout
}

//============================================================================
// EXERCISE 2: ASCII Values of Characters
//============================================================================
void exercise2()
{
    cout << "\n========== EXERCISE 2: ASCII Values ==========" << endl;

    char characters[] = "Hello";

    cout << "String: \"Hello\"" << endl;
    cout << "Character -> ASCII value:" << endl;

    for (int i = 0; i < strlen(characters); i++)
    {
        char c = characters[i];
        int ascii = (int)c;
        cout << "  '" << c << "' = " << ascii << endl;
    }

    // TODO: Show ASCII values for numbers and special characters
    // char symbols[] = "0 !@";
    // Print ASCII values for each
}

//============================================================================
// EXERCISE 3: Finding String Length
//============================================================================
void exercise3()
{
    cout << "\n========== EXERCISE 3: Calculate String Length ==========" << endl;

    char str[] = "programming";

    // Method 1: Using strlen()
    int len1 = strlen(str);
    cout << "Method 1 (strlen): " << len1 << endl;

    // Method 2: Manual counting
    int len2 = 0;
    while (str[len2] != '\0')
    {
        len2++;
    }
    cout << "Method 2 (counting): " << len2 << endl;

    // Method 3: Using sizeof
    int len3 = sizeof(str) - 1; // Subtract null terminator
    cout << "Method 3 (sizeof-1): " << len3 << endl;

    // TODO: Calculate length for different strings
}

//============================================================================
// EXERCISE 4: Iterate Through String with Pointer
//============================================================================
void exercise4()
{
    cout << "\n========== EXERCISE 4: Pointer Iteration ==========" << endl;

    char str[] = "code";
    char *ptr = str;

    cout << "String: \"code\"" << endl;
    cout << "Characters using pointer:" << endl;

    // TODO: Print each character using pointer
    while (*ptr != '\0')
    {
        cout << "  " << *ptr << endl;
        ptr++;
    }
}

//============================================================================
// EXERCISE 5: Count Specific Characters
//============================================================================
void exercise5()
{
    cout << "\n========== EXERCISE 5: Count Character Occurrences ==========" << endl;

    char str[] = "hello";
    char target = 'l';
    int count = 0;

    cout << "String: \"" << str << "\"" << endl;
    cout << "Looking for: '" << target << "'" << endl;

    // TODO: Count how many times 'l' appears
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] == target)
        {
            count++;
        }
    }

    cout << "Count: " << count << endl;
}

//============================================================================
// EXERCISE 6: Find Character Position
//============================================================================
void exercise6()
{
    cout << "\n========== EXERCISE 6: Find Character Position ==========" << endl;

    char str[] = "alphabet";
    char target = 'h';
    int position = -1;

    cout << "String: \"" << str << "\"" << endl;
    cout << "Looking for: '" << target << "'" << endl;

    // TODO: Find the position of the target character
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] == target)
        {
            position = i;
            break;
        }
    }

    if (position != -1)
    {
        cout << "Found at position: " << position << endl;
    }
    else
    {
        cout << "Character not found" << endl;
    }
}

//============================================================================
// EXERCISE 7: Copy String Manually
//============================================================================
void exercise7()
{
    cout << "\n========== EXERCISE 7: Copy String with Pointer ==========" << endl;

    char source[] = "copy";
    char dest[10];

    cout << "Source: \"" << source << "\"" << endl;

    // TODO: Copy using pointers
    char *src = source;
    char *d = dest;

    while (*src != '\0')
    {
        *d = *src;
        src++;
        d++;
    }
    *d = '\0'; // Don't forget the null terminator!

    cout << "Destination: \"" << dest << "\"" << endl;
}

//============================================================================
// EXERCISE 8: Reverse a String
//============================================================================
void exercise8()
{
    cout << "\n========== EXERCISE 8: Print String Backward ==========" << endl;

    char str[] = "reverse";

    cout << "Original: \"" << str << "\"" << endl;
    cout << "Reversed: \"";

    // TODO: Print the string backward
    for (int i = strlen(str) - 1; i >= 0; i--)
    {
        cout << str[i];
    }
    cout << "\"" << endl;
}

//============================================================================
// EXERCISE 9: Check if Character is Vowel
//============================================================================
void exercise9()
{
    cout << "\n========== EXERCISE 9: Find Vowels ==========" << endl;

    char str[] = "Hello World";

    cout << "String: \"" << str << "\"" << endl;
    cout << "Vowels found: ";

    // TODO: Find and print all vowels
    for (int i = 0; i < strlen(str); i++)
    {
        char c = tolower(str[i]); // Convert to lowercase
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        {
            cout << str[i] << " ";
        }
    }
    cout << endl;
}

//============================================================================
// EXERCISE 10: Compare Two Strings
//============================================================================
void exercise10()
{
    cout << "\n========== EXERCISE 10: Compare Strings ==========" << endl;

    char str1[] = "hello";
    char str2[] = "hello";
    char str3[] = "world";

    // Manual comparison
    cout << "Comparing \"" << str1 << "\" and \"" << str2 << "\":" << endl;

    bool equal = true;
    int len = strlen(str1);

    // TODO: Compare character by character
    if (strlen(str1) == strlen(str2))
    {
        for (int i = 0; i < len; i++)
        {
            if (str1[i] != str2[i])
            {
                equal = false;
                break;
            }
        }
    }
    else
    {
        equal = false;
    }

    cout << (equal ? "EQUAL" : "NOT EQUAL") << endl;

    // Using strcmp()
    cout << "\nUsing strcmp:" << endl;
    cout << "strcmp(str1, str2) = " << strcmp(str1, str2) << " (0 = equal)" << endl;
    cout << "strcmp(str1, str3) = " << strcmp(str1, str3) << " (non-zero = not equal)" << endl;
}

//============================================================================
// EXERCISE 11: Count Words in String
//============================================================================
void exercise11()
{
    cout << "\n========== EXERCISE 11: Count Words ==========" << endl;

    char str[] = "hello world this is fun";
    int wordCount = 1; // Start at 1 for first word

    cout << "String: \"" << str << "\"" << endl;

    // TODO: Count words (separated by spaces)
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] == ' ')
        {
            wordCount++;
        }
    }

    cout << "Word count: " << wordCount << endl;
}

//============================================================================
// EXERCISE 12: Remove Spaces from String
//============================================================================
void exercise12()
{
    cout << "\n========== EXERCISE 12: Remove Spaces ==========" << endl;

    char str[] = "hello world";
    char result[20];

    cout << "Original: \"" << str << "\"" << endl;

    // TODO: Copy string without spaces
    int j = 0;
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] != ' ')
        {
            result[j] = str[i];
            j++;
        }
    }
    result[j] = '\0';

    cout << "Without spaces: \"" << result << "\"" << endl;
}

//============================================================================
// EXERCISE 13: Count Different Character Types
//============================================================================
void exercise13()
{
    cout << "\n========== EXERCISE 13: Analyze String ==========" << endl;

    char str[] = "Hello123!";

    int letters = 0, digits = 0, others = 0;

    cout << "String: \"" << str << "\"" << endl;

    // TODO: Count letters, digits, and other characters
    for (int i = 0; i < strlen(str); i++)
    {
        if ((str[i] >= 'A' && str[i] <= 'Z') ||
            (str[i] >= 'a' && str[i] <= 'z'))
        {
            letters++;
        }
        else if (str[i] >= '0' && str[i] <= '9')
        {
            digits++;
        }
        else
        {
            others++;
        }
    }

    cout << "Letters: " << letters << endl;
    cout << "Digits: " << digits << endl;
    cout << "Other: " << others << endl;
}

//============================================================================
// MAIN FUNCTION - Run All Exercises
//============================================================================
int main()
{
    cout << "============================================" << endl;
    cout << "C++ CHARACTER ARRAYS AND STRINGS - PRACTICE" << endl;
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
    cout << "Great job practicing character arrays!" << endl;
    cout << "============================================" << endl;

    return 0;
}

//============================================================================
// SOLUTIONS REFERENCE
//============================================================================
/*
 * EXERCISE 4 SOLUTION:
 * while (*ptr != '\0') {
 *     cout << "  " << *ptr << endl;
 *     ptr++;
 * }
 *
 * EXERCISE 5 SOLUTION:
 * for (int i = 0; i < strlen(str); i++) {
 *     if (str[i] == target) {
 *         count++;
 *     }
 * }
 *
 * EXERCISE 6 SOLUTION:
 * for (int i = 0; i < strlen(str); i++) {
 *     if (str[i] == target) {
 *         position = i;
 *         break;
 *     }
 * }
 *
 * EXERCISE 7 SOLUTION:
 * while (*src != '\0') {
 *     *d = *src;
 *     src++;
 *     d++;
 * }
 * *d = '\0';
 *
 * EXERCISE 8 SOLUTION:
 * for (int i = strlen(str) - 1; i >= 0; i--) {
 *     cout << str[i];
 * }
 *
 * EXERCISE 11 SOLUTION:
 * for (int i = 0; i < strlen(str); i++) {
 *     if (str[i] == ' ') {
 *         wordCount++;
 *     }
 * }
 *
 * EXERCISE 13 SOLUTION:
 * for (int i = 0; i < strlen(str); i++) {
 *     if ((str[i] >= 'A' && str[i] <= 'Z') ||
 *         (str[i] >= 'a' && str[i] <= 'z')) {
 *         letters++;
 *     } else if (str[i] >= '0' && str[i] <= '9') {
 *         digits++;
 *     } else {
 *         others++;
 *     }
 * }
 */
