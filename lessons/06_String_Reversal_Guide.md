# String Reversal - Two-Pointer Technique

## The Problem

Given a string, reverse it **in-place** (without creating a new array).

Example:

```
Input:  "hello"
Output: "olleh"
```

## The Solution: Two-Pointer Technique

The elegant approach uses two pointers starting from opposite ends, swapping characters as they move toward the middle.

```cpp
char text[] = "hello";

// Setup pointers
char *pStart = &text[0];           // Point to first char: 'h'
char *pEnd = &text[4];             // Point to last char: 'o'

// Swap and move
while (pStart < pEnd) {
    // Swap characters
    char temp = *pStart;
    *pStart = *pEnd;
    *pEnd = temp;

    // Move pointers toward middle
    pStart++;
    pEnd--;
}

// Result: text now contains "olleh"
```

## Step-by-Step Example: Reversing "hello"

### Initial Setup

```
Array:    [h][e][l][l][o][null]
Index:     0  1  2  3  4   5

pStart ──→ h
pEnd ────→ o
```

### Iteration 1: Swap 'h' and 'o'

```
Array:    [o][e][l][l][h][null]

          pStart ──→ e
          pEnd ────→ l
```

### Iteration 2: Swap 'e' and 'l'

```
Array:    [o][l][l][e][h][null]

               pStart ──→ l (position 2)
               pEnd ────→ l (position 2)
```

**Loop stops** because `pStart < pEnd` is now false (they're pointing to the same character)

### Final Result: "olleh"

## Key Concepts

### 1. The Temporary Variable for Swapping

You **cannot** swap two values without a temporary variable when working directly with memory:

```cpp
// WRONG - loses data!
*pStart = *pEnd;  // *pStart now has end value
*pEnd = *pStart;  // Both have same value now!

// RIGHT - use temporary
char temp = *pStart;  // Save original start value
*pStart = *pEnd;      // Put end value at start
*pEnd = temp;         // Put original start at end
```

### 2. Pointer Arithmetic for Boundaries

```cpp
int nChars = sizeof(text) - 1;      // String length (without \0)
char *pEnd = text + nChars - 1;     // Last character (not \0)

// Why nChars - 1?
// sizeof("hello") = 6 (includes \0)
// nChars = 6 - 1 = 5 (string length)
// text + 5 - 1 = text + 4 = index 4 = 'o' (last char)
```

### 3. Loop Termination Condition

**Why `pStart < pEnd`?**

- When pointers point to the same position (odd-length string), we're done
- The middle character swaps with itself (no change needed)
- When pointers cross (even-length string), we're done
- Prevents unnecessary swaps and extra iterations

```cpp
// Odd length: "hello" (5 chars)
// Pointers eventually both point to 'l' (middle)
// Loop stops, 'l' stays in middle

// Even length: "test" (4 chars)
// Pointers eventually cross (pStart > pEnd)
// Loop stops, all characters swapped
```

## Algorithm Complexity

- **Time Complexity**: O(n) - visit each character once
- **Space Complexity**: O(1) - no extra arrays needed!
- **In-place**: Modifies original string directly

## Variations

### Reverse and Store in Different Array

```cpp
char source[] = "hello";
char dest[6];

char *src = source;
char *d = dest + strlen(source) - 1;  // Start at end of dest

while (*src != '\0') {
    *d = *src;
    src++;
    d--;
}
*d = '\0';  // Add null terminator
```

### Reverse from Index to Index

```cpp
void reverseRange(char *start, char *end) {
    while (start < end) {
        char temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

// Usage
char text[] = "programming";
reverseRange(&text[0], &text[10]);  // Reverse specific portion
```

### Reverse Word in Sentence

```cpp
char sentence[] = "hello world";
char *start = sentence;
char *current = sentence;

// Reverse each word
while (*current != '\0') {
    if (*current == ' ') {
        // Reverse from start to current-1
        char *end = current - 1;
        while (start < end) {
            char temp = *start;
            *start = *end;
            *end = temp;
            start++;
            end--;
        }
        start = current + 1;  // Skip space
    }
    current++;
}
```

## Common Mistakes

### Mistake 1: Not Using Temporary Variable

```cpp
// WRONG
*pStart = *pEnd;
*pEnd = *pStart;  // Both now have same value!

// CORRECT
char temp = *pStart;
*pStart = *pEnd;
*pEnd = temp;
```

### Mistake 2: Wrong Loop Condition

```cpp
// WRONG - processes middle character
while (pStart <= pEnd) { ... }

// CORRECT - stops before middle
while (pStart < pEnd) { ... }
```

### Mistake 3: Off-by-One Errors

```cpp
// WRONG - starts at null terminator
char *pEnd = text + nChars;  // Points to \0!

// CORRECT - points to last char
char *pEnd = text + nChars - 1;  // Points to actual last char
```

### Mistake 4: Forgetting String Length

```cpp
// WRONG - what's the length?
char *pEnd = /* how to calculate? */;

// CORRECT - calculate first
int length = strlen(text);
char *pEnd = text + length - 1;
```

## Implementation Styles

There are multiple ways to implement the string reversal algorithm. Each style has its own advantages depending on context.

### Style 1: Basic While Loop (Best for Learning)

```cpp
char text[] = "hello";
int nChars = strlen(text);

char *pStart = text;
char *pEnd = text + nChars - 1;

while (pStart < pEnd) {
    char ch = *pStart;
    *pStart = *pEnd;
    *pEnd = ch;

    pStart++;
    pEnd--;
}
```

**Advantages**:

- Most explicit and easy to understand
- Clear separation of setup and loop logic
- Best for beginners

### Style 2: For Loop with Pointer Updates (Compact)

```cpp
char *pStart = text;
char *pEnd = text + nChars - 1;

for (; pStart < pEnd; pStart++, pEnd--) {
    char ch = *pStart;
    *pStart = *pEnd;
    *pEnd = ch;
}
```

**Advantages**:

- Loop updates in one line
- More compact than while loop
- Still readable

### Style 3: For Loop with Initialization (Self-Contained)

```cpp
int nChars = strlen(text);

for (char *pStart = text, *pEnd = text + nChars - 1;
     pStart < pEnd;
     pStart++, pEnd--) {
    char ch = *pStart;
    *pStart = *pEnd;
    *pEnd = ch;
}
```

**Advantages**:

- All initialization in loop header
- No need for setup code before loop
- Self-contained and clean
- Common in interviews

### Style 4: Modern C++ with std::swap (Most Idiomatic)

```cpp
#include <algorithm>

int nChars = strlen(text);

for (char *left = text, *right = text + nChars - 1;
     left < right;
     left++, right--) {
    std::swap(*left, *right);
}
```

**Advantages**:

- Uses standard library function
- Clearer intent (swap vs manual assignment)
- Modern C++ style
- Preferred in production code
- More efficient (compiler optimizations)

## Comparison Table

| Style            | Clarity   | Compactness | Best Use          |
| ---------------- | --------- | ----------- | ----------------- |
| While            | Excellent | Low         | Learning          |
| For with updates | Good      | Medium      | Interviews        |
| For with init    | Good      | High        | Professional code |
| std::swap        | Excellent | High        | Production        |

**All four approaches**:

- Have O(n) time complexity
- Have O(1) space complexity
- Produce identical results

## Choosing the Right Style

- **Learning phase**: Use Style 1 (while loop)
- **Interviews**: Use Style 2 or 3 (shows good C++ syntax knowledge)
- **Production code**: Use Style 4 (standard library, maintainable)
- **Teaching others**: Use Style 1 or 3 (clear logic flow)

## Real-World Applications

1. **String validation**: Check if string is palindrome
2. **Text processing**: Reverse lines in a file
3. **Algorithm practice**: Common interview question
4. **Data manipulation**: Reverse arrays, linked lists
5. **Encryption**: Some simple ciphers use reversal

## Palindrome Check Using Reversal

```cpp
bool isPalindrome(char *str) {
    int len = strlen(str);
    char *start = str;
    char *end = str + len - 1;

    while (start < end) {
        if (*start != *end) {
            return false;
        }
        start++;
        end--;
    }
    return true;
}
```

## Summary Table

| Aspect                      | Detail                                              |
| --------------------------- | --------------------------------------------------- |
| Algorithm                   | Two pointers from ends, swap and move toward middle |
| Time                        | O(n)                                                |
| Space                       | O(1)                                                |
| In-place                    | Yes                                                 |
| Handles odd-length          | Yes                                                 |
| Handles even-length         | Yes                                                 |
| Requires temporary variable | Yes                                                 |
| Loop condition              | `pStart < pEnd`                                     |

## Next Steps

1. Master string reversal ✓
2. Implement palindrome checking
3. Reverse specific ranges
4. Reverse multiple strings
5. Build algorithms using two-pointer technique
6. Apply to array reversal
