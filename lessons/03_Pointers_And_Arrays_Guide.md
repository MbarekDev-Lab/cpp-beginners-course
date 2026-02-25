# Pointers and Arrays - Complete Guide

## Relationship Between Arrays and Pointers

In C++, **arrays and pointers are deeply connected**:

- An array name is essentially a pointer to its first element
- `arrays` is the same as `&arrays[0]`
- You can use pointers to access and manipulate arrays efficiently

## Array Decay

When an array is used in most contexts, it "decays" to a pointer:

```cpp
int arr[5] = {1, 2, 3, 4, 5};
int *ptr = arr;  // arr decays to pointer to first element

// These are equivalent:
arr[0]    ↔    *arr      ↔    *ptr
arr[1]    ↔    *(arr+1)  ↔    *(ptr+1)
```

## Pointer Arithmetic

When you add to a pointer, it moves by the **size of the type**:

```cpp
int arr[5] = {10, 20, 30, 40, 50};
int *ptr = arr;  // Points to 10 (address 0x100)

ptr++;     // Moves by sizeof(int) bytes, NOT 1 byte!
           // ptr now points to 20 (address 0x104)

ptr + 2;   // Moves 2 * sizeof(int) bytes
           // Points to 30

*(ptr + 3); // Points to 40 (same as arr[3])
```

## Three Ways to Iterate Arrays

### Method 1: Traditional For Loop (Index-Based)

```cpp
string texts[] = {"one", "two", "three"};

for (int i = 0; i < 3; i++) {
    cout << texts[i];  // Access by index
}
```

**Advantages**:

- Familiar and readable
- Easy to understand
- Can access random elements easily

### Method 2: Pointer Arithmetic

```cpp
string texts[] = {"one", "two", "three"};
string *ptr = texts;

for (int i = 0; i < 3; i++, ptr++) {
    cout << *ptr;  // Dereference pointer
}
```

**How it works**:

- `*ptr` dereferences the pointer (gets the value)
- `ptr++` moves to the next element
- The `ptr++` happens AFTER each loop iteration

### Method 3: Two Pointers (Start and End)

```cpp
string texts[] = {"one", "two", "three"};
string *start = &texts[0];
string *end = &texts[2];

while (start <= end) {
    cout << *start;
    start++;
}
```

**Advantages**:

- Elegant for range-based operations
- Commonly used in algorithms
- Clear intent: process from start to end

## Calculating Array Size

Since you often don't know array size at runtime, use this formula:

```cpp
int arr[] = {1, 2, 3, 4, 5};

// Number of elements:
int size = sizeof(arr) / sizeof(arr[0]);

// Or for arrays of strings:
string arr[] = {"a", "b", "c"};
int size = sizeof(arr) / sizeof(string);
```

**Important**: This only works for **statically-allocated arrays**! For dynamic arrays or pointers, you must pass the size separately.

## Pointer vs Array Syntax

These are **equivalent**:

```cpp
int arr[5] = {1, 2, 3, 4, 5};
int *ptr = arr;

// All these are the same:
arr[2]        // Traditional array syntax
ptr[2]        // Pointer with array syntax
*(arr + 2)    // Pointer dereference
*(ptr + 2)    // Pointer arithmetic
```

## Pointer Arithmetic with Different Types

The magic of pointer arithmetic: **it knows the size**!

```cpp
int intArr[3] = {1, 2, 3};
int *pInt = intArr;
pInt++;  // Moves by 4 bytes (size of int)

double doubleArr[3] = {1.1, 2.2, 3.3};
double *pDouble = doubleArr;
pDouble++;  // Moves by 8 bytes (size of double)

char charArr[3] = {'a', 'b', 'c'};
char *pChar = charArr;
pChar++;  // Moves by 1 byte (size of char)
```

## Virtual "End" Pointer

A common pattern is using an "end" pointer:

```cpp
int arr[5] = {10, 20, 30, 40, 50};
int *current = arr;
int *end = arr + 5;  // One past the last element

while (current != end) {
    cout << *current << " ";
    current++;
}
```

This is how modern C++ STL iterators work!

## Multi-Dimensional Arrays and Pointers

For 2D arrays, use pointer to pointer:

```cpp
int matrix[2][3] = {
    {1, 2, 3},
    {4, 5, 6}
};

int (*ptr)[3] = matrix;  // Pointer to array of 3 ints
cout << ptr[0][1];       // Access element: 2
```

## Common Mistakes to Avoid

### Mistake 1: Wrong Size Calculation

```cpp
int *arr = new int[10];
int size = sizeof(arr) / sizeof(int);  // WRONG! sizeof(arr) is pointer size
```

### Mistake 2: Going Past Array Bounds

```cpp
string texts[3] = {"a", "b", "c"};
string *ptr = texts;
ptr += 5;  // DANGER! Now points past array
```

### Mistake 3: Forgetting Element Size

```cpp
double arr[10];
double *ptr = arr;
ptr += 4;  // Correctly moves 4 elements (32 bytes)
           // NOT 4 bytes!
```

## Performance Notes

- Pointers are faster for sequential access (cache-friendly)
- Array indexing may be optimized better by compilers
- Modern CPUs favor sequential memory access
- For most cases, use whichever is clearer to read

## Summary Table

| Operation    | Index    | Pointer  | Pointer Arithmetic |
| ------------ | -------- | -------- | ------------------ |
| Access first | `arr[0]` | `*ptr`   | `*ptr`             |
| Access nth   | `arr[n]` | `ptr[n]` | `*(ptr+n)`         |
| Increment    | `i++`    | `ptr++`  | `++ptr`            |
| Move by n    | `arr+n`  | `ptr+n`  | `ptr += n`         |

## Practice Topics

1. Iterate arrays using all three methods
2. Calculate array sizes dynamically
3. Use pointer arithmetic for searching
4. Implement pointer-based sorting
5. Work with multi-dimensional arrays
6. Create generic functions using pointers

## Next Steps

1. Master pointer and array iteration ✓
2. Learn about dynamic arrays (`new` and `delete`)
3. Understand pointer to pointer
4. Explore string manipulation with pointers
5. Build algorithms using pointer techniques
6. Study STL iterators (they're pointers!)
