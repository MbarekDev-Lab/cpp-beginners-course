//============================================================================
// Lesson: Character Arrays and Strings in C++ - Basics
// Author: M'Barek Benraiss
// Date: February 25, 2026
// Topic: Working with Strings Using Character Arrays and Pointers
//============================================================================
/*
 * CHARACTER ARRAYS AND STRINGS
 * =============================
 * C-style strings are arrays of characters terminated by a null character.
 *
 * KEY CONCEPTS:
 * =============
 * 1. char array = sequence of characters
 * 2. C-string = char array with null terminator ('\0')
 * 3. String literal = "text" (automatically null-terminated)
 * 4. NULL TERMINATOR = '\0' (ASCII value 0)
 * 5. Pointer to char = efficient string manipulation
 *
 * IMPORTANT:
 * ==========
 * char text[] = "hello";  // Size is 6 (h,e,l,l,o,\0)
 * The null terminator marks the END of the string!
 * Functions that work with C-strings rely on finding '\0'
 *
 * WHY THIS MATTERS:
 * =================
 * - Understanding how strings work internally
 * - Manual string manipulation
 * - Working with legacy C code
 * - Understanding string memory layout
 */

#include <iostream>
#include <cstring> // For string functions like strlen
using namespace std;

int main()
{

    cout << "========== CHARACTER ARRAYS AND STRINGS ==========" << endl;

    //=========================================================================
    // SECTION 1: Creating and Displaying Character Arrays
    //=========================================================================
    cout << "\n--- SECTION 1: Character Array Creation ---" << endl;

    // Method 1: C-style string (automatically null-terminated)
    char texts[] = "hello";

    cout << "String: " << texts << endl;
    cout << "Explanation: When you use a string literal, C++ automatically" << endl;
    cout << "adds a null terminator (\\0) at the end" << endl;

    //=========================================================================
    // SECTION 2: Understanding String Memory Layout
    //=========================================================================
    cout << "\n--- SECTION 2: String Memory and ASCII Values ---" << endl;

    cout << "Character array: \"hello\"" << endl;
    cout << "Memory layout (with ASCII values):" << endl;

    for (int i = 0; i < sizeof(texts); i++)
    {
        cout << "  [" << i << "]: ";

        // Cast to int to show ASCII value
        int ascii = (int)texts[i];

        if (texts[i] == '\0')
        {
            cout << "\'\\0\' (Null Terminator) - ASCII: " << ascii << endl;
        }
        else
        {
            cout << "\'" << texts[i] << "\' - ASCII: " << ascii << endl;
        }
    }

    cout << "\nTotal size: " << sizeof(texts) << " bytes" << endl;
    cout << "  5 characters + 1 null terminator = 6 bytes" << endl;

    //=========================================================================
    // SECTION 3: The Null Terminator - The End of String Marker
    //=========================================================================
    cout << "\n--- SECTION 3: Why the Null Terminator Matters ---" << endl;

    char word[] = "cat";

    cout << "String: \"cat\"" << endl;
    cout << "Size: " << sizeof(word) << " bytes" << endl;
    cout << "\nWhat if we didn't have the null terminator?" << endl;
    cout << "Functions wouldn't know where the string ends!" << endl;
    cout << "They rely on finding '\\0' to stop reading" << endl;

    //=========================================================================
    // SECTION 4: Using Pointers with Strings
    //=========================================================================
    cout << "\n--- SECTION 4: Pointers to Character Arrays ---" << endl;

    char message[] = "world";
    char *pMessage = message; // Point to first character

    cout << "String: " << message << endl;
    cout << "Using pointer: " << pMessage << endl;
    cout << "First char via pointer: " << *pMessage << endl;

    cout << "\nIterating with pointer:" << endl;
    while (*pMessage != '\0')
    {
        cout << "  " << *pMessage << endl;
        pMessage++;
    }

    //=========================================================================
    // SECTION 5: Iterating Through Strings
    //=========================================================================
    cout << "\n--- SECTION 5: Different Iteration Methods ---" << endl;

    char str[] = "hello";

    // Method 1: Index-based
    cout << "Method 1 (Index-based): ";
    for (int i = 0; i < sizeof(str); i++)
    {
        if (str[i] != '\0')
        {
            cout << str[i];
        }
    }
    cout << endl;

    // Method 2: Pointer-based with null check
    cout << "Method 2 (Pointer-based): ";
    char *ptr = str;
    while (*ptr != '\0')
    {
        cout << *ptr;
        ptr++;
    }
    cout << endl;

    // Method 3: Using string length
    cout << "Method 3 (Using strlen): ";
    int len = strlen(str);
    for (int i = 0; i < len; i++)
    {
        cout << str[i];
    }
    cout << endl;

    //=========================================================================
    // SECTION 6: String vs Character Array vs Pointer
    //=========================================================================
    cout << "\n--- SECTION 6: Different String Representations ---" << endl;

    // Array of characters with null terminator
    char arr[] = "array";
    cout << "char arr[] = \"array\";    Size: " << sizeof(arr) << endl;

    // Pointer to string literal
    char *ptr2 = "literal";
    cout << "char *ptr = \"literal\";  Size of pointer: " << sizeof(ptr2) << endl;
    cout << "  (pointer points to read-only string in memory)" << endl;

    //=========================================================================
    // SECTION 7: Character Casting and ASCII
    //=========================================================================
    cout << "\n--- SECTION 7: ASCII Values ---" << endl;

    char c1 = 'A';
    char c2 = 'a';
    char c3 = '0';
    char c4 = ' ';

    cout << "Character -> ASCII value:" << endl;
    cout << "  'A' = " << (int)c1 << endl;
    cout << "  'a' = " << (int)c2 << endl;
    cout << "  '0' = " << (int)c3 << " (digit zero, not empty)" << endl;
    cout << "  ' ' = " << (int)c4 << " (space character)" << endl;
    cout << "  '\\0' = " << (int)'\0' << " (null terminator)" << endl;

    cout << "\nNote: Character '0' (digit) has ASCII 48" << endl;
    cout << "      Null terminator '\\0' has ASCII 0" << endl;

    //=========================================================================
    // SECTION 8: Common String Length Calculation
    //=========================================================================
    cout << "\n--- SECTION 8: Calculating String Length ---" << endl;

    char test[] = "length";

    // Method 1: Using strlen()
    int len1 = strlen(test);
    cout << "Using strlen(): " << len1 << " characters" << endl;

    // Method 2: Counting manually
    int len2 = 0;
    while (test[len2] != '\0')
    {
        len2++;
    }
    cout << "Counting manually: " << len2 << " characters" << endl;

    // Method 3: Using sizeof (remember: includes null terminator!)
    int len3 = sizeof(test) - 1; // Subtract 1 for null terminator
    cout << "Using sizeof-1: " << len3 << " characters" << endl;

    return 0;
}

//============================================================================
// KEY LEARNING POINTS:
// ====================
// 1. C-strings are char arrays with null terminator ('\0')
// 2. String literals "text" are automatically null-terminated
// 3. sizeof(str) includes the null terminator in the count
// 4. strlen(str) returns length WITHOUT null terminator
// 5. Pointers can efficiently iterate through strings
// 6. Functions detect end of string by finding '\0'
// 7. ASCII values let you work with characters as numbers
//
// COMMON MISTAKES:
// ================
// - Forgetting the null terminator exists
// - Using sizeof() instead of strlen()
// - Writing past the end of a char array (buffer overflow!)
// - Modifying string literals (they're read-only!)
// - Not initializing char arrays properly
//
// WHEN TO USE:
// ============
// char array:  When you need to modify strings, fixed size
// const char*: When pointing to string literals
// string:      When you want high-level string operations (modern C++)
//============================================================================
