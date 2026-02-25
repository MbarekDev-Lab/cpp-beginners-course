# Character Arrays and Strings - Complete Guide

## What Are Character Arrays?

A **character array** is an array of `char` values. When it ends with a special null terminator character (`\0`), it becomes a **C-string**.

## The Null Terminator - The Key Concept

The null terminator (`\0`) is a character with ASCII value 0. It marks the **END of a string**:

```cpp
char str[] = "hello";

// In memory, this looks like:
// [h][e][l][l][o][\0]
//  0  1  2  3  4   5

// Array size: 6 bytes
// String length: 5 characters
```

**Why important?** Functions that work with strings (like `strlen`, `printf`, `cout`) read characters until they find `\0`. Without it, they'd read past the intended string!

## String Literals vs Char Arrays

### String Literal (const char\*)

```cpp
const char *str = "hello";  // Points to read-only string in memory
sizeof(str);                // Size of pointer (4 or 8 bytes), NOT string!
```

### Char Array

```cpp
char str[] = "hello";       // Array of 6 bytes (5 chars + \0)
sizeof(str);                // 6 bytes (includes null terminator)
```

### Modern C++ String Class

```cpp
#include <string>
string str = "hello";       // Easiest, most flexible option
str.length();               // Built-in length tracking
```

## Important Size Differences

```cpp
char arr[] = "hi";          // sizeof(arr) = 3 (h, i, \0)
char *ptr = "hi";           // sizeof(ptr) = 4 or 8 (pointer size only!)

strlen("hi");               // Returns 2 (not counting \0)
sizeof("hi");               // Returns 3 (with \0)
```

**Rule of thumb**:

- `sizeof()` = includes null terminator
- `strlen()` = does NOT include null terminator

## ASCII Values

Every character has an ASCII (American Standard Code for Information Interchange) value:

| Character   | ASCII  | Usage           |
| ----------- | ------ | --------------- |
| '0' to '9'  | 48-57  | Digits          |
| 'A' to 'Z'  | 65-90  | Uppercase       |
| 'a' to 'z'  | 97-122 | Lowercase       |
| ' ' (space) | 32     | Space           |
| '\0'        | 0      | Null terminator |
| '\n'        | 10     | Newline         |
| '\t'        | 9      | Tab             |

You can cast a char to int to see its ASCII value:

```cpp
char c = 'A';
cout << (int)c;     // Prints: 65

// Reverse - create char from ASCII
char d = 65;
cout << d;          // Prints: A
```

## Iterating Through Strings

### Method 1: Index-Based Loop

```cpp
char str[] = "hello";

for (int i = 0; i < strlen(str); i++) {
    cout << str[i];  // Print each character
}
```

### Method 2: Pointer with Null Check

```cpp
char *ptr = str;

while (*ptr != '\0') {
    cout << *ptr;
    ptr++;
}
```

### Method 3: Built-in Functions

```cpp
strlen(str);        // Get length
strcpy(dest, src);  // Copy string
strcat(dest, src);  // Concatenate
strcmp(str1, str2); // Compare
```

## String Length Calculation

### Using strlen()

```cpp
char str[] = "hello";
int len = strlen(str);  // Returns 5 (not counting \0)
```

### Manual Counting

```cpp
int count = 0;
while (str[count] != '\0') {
    count++;
}
// count now = 5
```

### Using sizeof() - Be Careful!

```cpp
char str[] = "hello";
int len = sizeof(str) - 1;  // 6 - 1 = 5
// Must subtract 1 for the null terminator!

char *ptr = "hello";
int len = sizeof(ptr);  // WRONG! Gets pointer size (4-8), not string!
```

## Common String Operations

### Copy a String

```cpp
char source[] = "hello";
char dest[10];

// Option 1: Manual with pointers
char *src = source;
char *d = dest;
while (*src != '\0') {
    *d = *src;
    src++;
    d++;
}
*d = '\0';  // Add null terminator!

// Option 2: Using strcpy
strcpy(dest, source);  // Be careful of buffer overflow!
```

### Check if Character is Letter

```cpp
char c = 'A';

if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
    cout << "It's a letter";
}

// Or using ASCII values:
if ((int)c >= 65 && (int)c <= 90) {  // 'A' to 'Z'
    cout << "It's uppercase";
}
```

### Count Characters

```cpp
char str[] = "hello world";
int count = 0;

for (int i = 0; str[i] != '\0'; i++) {
    count++;
}
cout << count;  // Prints: 11 (including space)
```

## Char Array vs String Class

| Aspect          | char[]                  | string             |
| --------------- | ----------------------- | ------------------ |
| Fixed size      | Usually yes             | No (dynamic)       |
| Null terminator | Required                | Handled internally |
| Easy to modify  | Risky (buffer overflow) | Safe               |
| Memory          | Stack                   | Can be heap        |
| Functions       | Use `cstring` functions | Built-in methods   |
| Modern C++?     | Legacy                  | Recommended        |

```cpp
// C-style (dangerous)
char arr[10] = "hi";
strcpy(arr, "This is too long!");  // BUFFER OVERFLOW!

// Modern C++ (safe)
string str = "hi";
str = "This is fine";  // Safe - automatic resizing
```

## Memory Safety - Buffer Overflow

One of the biggest dangers with char arrays:

```cpp
char name[5] = "hello";  // Only 5 chars!
strcpy(name, "Alexander");  // CRASH! 9 chars (+ \0)

// Safe alternative:
string name = "hello";
name = "Alexander";  // Safe!
```

**Always be careful with:**

- `strcpy()` - can overflow
- `strcat()` - can overflow
- `gets()` - never use (always overflows)
- `scanf()` - be careful with format strings

**Use safer alternatives:**

- `strncpy()` - limited copy
- `snprintf()` - formatted string with size limit
- Modern `string` class - automatic safety

## Special Characters in Strings

```cpp
char str[20] = "Line 1\nLine 2";
// \n = newline
// \t = tab
// \\ = backslash (escape)
// \" = quote mark (escape)
// \0 = null terminator
```

## Pointers to Characters vs Strings

```cpp
// Single character
char c = 'A';
char *pc = &c;      // Pointer to single char
cout << *pc;        // Prints: A
cout << pc;         // Prints: garbage (not a string!)

// String (array of chars)
char str[] = "hello";
char *ps = str;     // Pointer to char array
cout << ps;         // Prints: hello (treats as string)
```

## Summary Table

| Operation       | Code                  | Purpose                |
| --------------- | --------------------- | ---------------------- |
| Declare string  | `char str[10];`       | Create char array      |
| String literal  | `"hello"`             | Create string constant |
| Null terminator | `\0` or `'\0'`        | Mark string end        |
| Get length      | `strlen(str)`         | Count characters       |
| Get size        | `sizeof(str)`         | Get memory size        |
| Copy            | `strcpy(dest, src)`   | Copy string            |
| Compare         | `strcmp(s1, s2)`      | Compare strings        |
| Iterate         | `while(*ptr != '\0')` | Go through chars       |

## Next Steps

1. Master character arrays ✓
2. Learn string manipulation functions
3. Understand buffer overflow risks
4. Migrate to modern `string` class
5. Work with file I/O using strings
6. Parse and process text data
