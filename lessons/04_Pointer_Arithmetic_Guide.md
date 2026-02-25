# Pointer Arithmetic - Complete Guide

## What is Pointer Arithmetic?

Pointer arithmetic allows you to perform mathematical operations on pointers to navigate through arrays and memory efficiently.

## Supported Pointer Operations

| Operation            | Syntax             | Effect                              |
| -------------------- | ------------------ | ----------------------------------- |
| Increment            | `ptr++` or `++ptr` | Move to next element                |
| Decrement            | `ptr--` or `--ptr` | Move to previous element            |
| Add                  | `ptr += n`         | Move forward n elements             |
| Subtract             | `ptr -= n`         | Move backward n elements            |
| Add (no modify)      | `ptr + n`          | Create pointer n ahead (temporary)  |
| Subtract (no modify) | `ptr - n`          | Create pointer n behind (temporary) |
| Difference           | `ptr2 - ptr1`      | Calculate distance (in elements)    |
| Array access         | `ptr[i]`           | Access element i                    |

## The Critical Concept: Size-Aware Arithmetic

When you add to a pointer, it doesn't add literal bytes—it adds **one unit of the pointed-to type**:

```cpp
int intArr[5] = {10, 20, 30, 40, 50};
int *pInt = intArr;

pInt += 1;  // Moves by sizeof(int) bytes (usually 4 bytes)

string stringArr[3] = {"a", "b", "c"};
string *pStr = stringArr;

pStr += 1;  // Moves by sizeof(string) bytes (much larger!)
```

**This is the magic**: pointers "know" their type and adjust automatically!

## Detailed Examples

### Moving Forward with +=

```cpp
string texts[5] = {"one", "two", "three", "four", "five"};
string *ptr = texts;

cout << *ptr;  // Prints: one (position 0)

ptr += 3;      // Move 3 positions forward

cout << *ptr;  // Prints: four (position 3)
```

### Moving Backward with -=

```cpp
string *ptr = &texts[3];  // Point to "four"

cout << *ptr;  // Prints: four

ptr -= 2;      // Move 2 positions back

cout << *ptr;  // Prints: two (position 1)
```

### Pre and Post Increment

```cpp
int arr[5] = {1, 2, 3, 4, 5};
int *ptr = arr;

// Post-increment (use first, then increment)
int val = *ptr++;  // val = 1, then ptr moves to arr[1]
cout << val;       // Prints: 1

// Pre-increment (increment first, then use)
int val = *++ptr;  // ptr moves to arr[2], then val = 3
cout << val;       // Prints: 3
```

## The One-Past-End Pattern

A common and elegant pattern in C++:

```cpp
int arr[5] = {1, 2, 3, 4, 5};
int *start = &arr[0];
int *end = &arr[5];    // One PAST the last element!

while (start != end) {
    cout << *start << " ";
    start++;
}
```

**Why one-past-end?** It makes the loop condition natural: `ptr != end` is clear and doesn't include a separate size parameter.

## Pointer Subtraction: Finding Distance

One of the most useful operations:

```cpp
int arr[10] = {...};
int *ptr1 = &arr[2];
int *ptr2 = &arr[7];

int distance = ptr2 - ptr1;  // Result: 5 (elements, not bytes!)

// Finding position in array
int *start = &arr[0];
int *current = &arr[3];

int position = current - start;  // Result: 3
```

**Remember**: The result is the distance in **elements**, not bytes!

## Array Indexing vs Pointer Arithmetic

These are equivalent:

```cpp
string arr[5] = {"a", "b", "c", "d", "e"};
string *ptr = arr;

// These all access element at index 2:
arr[2]       // Array indexing
ptr[2]       // Pointer with array syntax
*(ptr + 2)   // Pointer arithmetic
*(arr + 2)   // Same as arr[2]
```

## Combining Operations

```cpp
string arr[5] = {"one", "two", "three", "four", "five"};
string *ptr = arr;

// Move to middle
ptr += arr.size() / 2;  // Most of way through

// Check if valid
if (ptr - arr < 5) {
    cout << *ptr << endl;
}

// Reset to start
ptr = arr;
```

## Common Patterns

### Pattern 1: Forward Iteration

```cpp
int *ptr = start;
while (ptr != end) {
    // Use *ptr
    ptr++;  // or ++ptr
}
```

### Pattern 2: Backward Iteration

```cpp
int *ptr = end - 1;  // Start at last element
while (ptr >= start) {
    // Use *ptr
    ptr--;  // or --ptr
}
```

### Pattern 3: Find Element

```cpp
int *ptr = start;
while (ptr != end) {
    if (*ptr == target) {
        int position = ptr - start;
        break;
    }
    ptr++;
}
```

### Pattern 4: Skip Elements

```cpp
int *ptr = start;
while (ptr != end) {
    // Use *ptr
    ptr += 2;  // Move by 2 elements each time
}
```

## Pointer Arithmetic Rules

### Valid Operations

```cpp
ptr1 + 5       // OK: pointer + integer
ptr1 - 5       // OK: pointer - integer
ptr1 - ptr2    // OK: pointer - pointer (same array)
ptr1 < ptr2    // OK: pointer comparison
ptr1++         // OK: increment pointer
```

### Invalid Operations

```cpp
ptr1 + ptr2    // ERROR: can't add two pointers
ptr1 * 5       // ERROR: can't multiply pointer
ptr1 / 5       // ERROR: can't divide pointer
ptr1 % 5       // ERROR: can't modulo pointer
```

## Memory Safety Warnings

### Danger 1: Going Out of Bounds

```cpp
int arr[5] = {1, 2, 3, 4, 5};
int *ptr = &arr[0];
ptr += 10;  // DANGER! Now points past the array
cout << *ptr;  // Undefined behavior!
```

### Danger 2: Invalid Pointer Subtraction

```cpp
int arr1[5] = {1, 2, 3, 4, 5};
int arr2[5] = {6, 7, 8, 9, 10};
int *ptr1 = &arr1[0];
int *ptr2 = &arr2[0];

int dist = ptr2 - ptr1;  // DANGEROUS! Different arrays!
```

### Danger 3: Pointer After Delete

```cpp
int *ptr = new int[10];
delete[] ptr;
ptr += 5;  // DANGER! ptr is now invalid
```

## Performance Considerations

- **Pointer arithmetic is fast** - Modern CPUs optimize sequential access
- **Cache-friendly** - Linear traversal with pointers is memory-efficient
- **STL uses this** - Standard Library iterators are based on pointer arithmetic
- **Compiler optimization** - Modern compilers optimize pointer arithmetic well

## Real-World Examples

### Example 1: Implementing memcpy-like Function

```cpp
void copyElements(int *dest, int *src, int count) {
    int *srcEnd = src + count;
    while (src != srcEnd) {
        *dest++ = *src++;  // Copy and increment both
    }
}
```

### Example 2: Finding Maximum

```cpp
int* findMax(int *start, int *end) {
    int *max = start;
    while (start != end) {
        if (*start > *max) {
            max = start;
        }
        start++;
    }
    return max;
}
```

## Summary

| Concept       | Code                | Result                |
| ------------- | ------------------- | --------------------- |
| Move forward  | `ptr += 3`          | Move 3 elements ahead |
| Move backward | `ptr -= 2`          | Move 2 elements back  |
| Get position  | `ptr - start`       | Position in array     |
| Loop pattern  | `while(ptr != end)` | Elegant iteration     |
| Byte size     | `ptr + 1`           | Moves by sizeof(type) |

## Next Steps

1. Master pointer arithmetic ✓
2. Learn about dynamic arrays with pointers
3. Understand pointer to pointer
4. Explore function pointers
5. Study STL iterators (built on pointers!)
6. Build linked lists and complex structures

## Practice Topics

- Reverse an array using pointer arithmetic
- Find elements with pointers
- Skip elements in an array
- Implement sorting with pointers
- Create two-pointer algorithms
