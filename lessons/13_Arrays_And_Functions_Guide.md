# LESSON 13: Arrays and Functions

## Passing Arrays to Functions, Array Decay, and Effective Patterns

---

## Table of Contents

1. [Introduction](#introduction)
2. [Array Decay](#array-decay)
3. [Passing Arrays with Size](#passing-arrays-with-size)
4. [Array Decay Rules](#array-decay-rules)
5. [Modifying Arrays in Functions](#modifying-arrays-in-functions)
6. [Reference Parameters](#reference-parameters)
7. [Objects in Arrays](#objects-in-arrays)
8. [Pointer Equivalence](#pointer-equivalence)
9. [Heap Arrays and Functions](#heap-arrays-and-functions)
10. [Practical Patterns](#practical-patterns)
11. [Common Mistakes](#common-mistakes)

---

## Introduction

When you pass an array to a function, C++ does something special: the **array decays into a pointer**. This is one of the most important concepts in C++ for understanding how arrays work with functions.

### Why This Matters

1. **Efficiency**: Arrays don't get copied; only address is passed
2. **Flexibility**: Same function works with arrays of any size
3. **Semantics**: Understanding decay is crucial for proper programming

---

## Array Decay

### The Decay Mechanism

When an array is passed to a function, it **decays automatically** into a pointer to its first element:

```cpp
int arr[10];           // Array of 10 ints

// When passed to function:
printArray(arr);       // arr DECAYS to int*
```

### What Happens

```
Original:  int arr[10] = {1, 2, 3, ...};
           ↓
Passed to function as: int *p (pointer to first element)
```

### Code Example

```cpp
void printArray(int arr[]) {
    // arr LOOKS LIKE an array here
    cout << arr[0] << endl;  // Works - array notation
}

int main() {
    int numbers[5] = {10, 20, 30, 40, 50};
    printArray(numbers);  // numbers decays to int*
}
```

### Key Point: arr[] is Actually a Pointer

```cpp
// These three are IDENTICAL:
void func1(int arr[]) { }
void func2(int *arr) { }
void func3(int arr[10]) { }  // Size ignored!

// All receive: int* (pointer to int)
// All are equivalent!
```

---

## Passing Arrays with Size

### The Critical Problem

Since arrays decay to pointers, **size information is lost**:

```cpp
void processArray(int arr[]) {
    // How do we know how many elements?
    // sizeof(arr) gives size of pointer (8 bytes), not array!
    int size = sizeof(arr) / sizeof(int);  // WRONG!
}
```

### The Solution: Explicit Size Parameter

Always pass the size as a separate parameter:

```cpp
void processArray(int arr[], int size) {
    // Now we know the bounds
    for (int i = 0; i < size; i++) {
        cout << arr[i] << endl;
    }
}

int main() {
    int numbers[5] = {1, 2, 3, 4, 5};
    processArray(numbers, 5);  // Pass both array and size
}
```

### Example: Multiple Operations

```cpp
void printArray(int arr[], int size) {
    cout << "Array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void sumArray(int arr[], int size) {
    int total = 0;
    for (int i = 0; i < size; i++) {
        total += arr[i];
    }
    cout << "Sum: " << total << endl;
}

int main() {
    int nums[4] = {10, 20, 30, 40};

    printArray(nums, 4);
    sumArray(nums, 4);
}
```

---

## Array Decay Rules

### Rule 1: Arrays → Pointers

```cpp
int arr[10];
func(arr);        // arr becomes int*
```

### Rule 2: Size Information Lost

```cpp
void func(int arr[]) {
    // arr is int*, not int[10]
    // Can't determine original size
}
```

### Rule 3: No Implicit Copy

```cpp
// Array elements are NOT copied
// Only the address is passed
// Original array can be modified
```

### Rule 4: Multi-Dimensional Arrays

```cpp
int matrix[3][4];

// func1 receives pointer to (array of 4 ints)
void func1(int (*p)[4]) { }

// Must specify all but first dimension!
void func2(int [][4]) { }

func1(matrix);  // Works - decay to int (*)[4]
```

### Rule 5: Array Parameters Decay, Pointer Parameters Don't

```cpp
// These look different but are functionally equivalent:
void f1(int arr[]) { }      // int arr[] → int*
void f2(int *arr) { }       // int *arr → int* (no decay needed)

int arr[10];
f1(arr);  // arr decays to int* then passes
f2(arr);  // arr already is int*, passes as-is
```

---

## Modifying Arrays in Functions

### Arrays Pass by Reference Implicitly

When you pass an array, you're passing a pointer to the original array. **Modifications affect the original**:

```cpp
void increment_all(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i]++;  // Modifies original array!
    }
}

int main() {
    int nums[3] = {1, 2, 3};
    increment_all(nums, 3);
    cout << nums[0] << endl;  // Output: 2 (modified!)
}
```

### Why?

Because arrays decay to pointers pointing to the original elements.

### Const Arrays to Prevent Modification

```cpp
// Prevent modifications
void readOnly(const int arr[], int size) {
    // arr[0] = 5;  // COMPILE ERROR!
    cout << arr[0] << endl;  // OK
}

// Allow modifications
void canModify(int arr[], int size) {
    arr[0] = 5;  // OK
}
```

---

## Reference Parameters

### Array References (Advanced)

You can pass arrays by reference with an awkward syntax:

```cpp
// Reference to array of exactly 5 ints
void processFixed(int (&arr)[5]) {
    for (int i = 0; i < 5; i++) {
        arr[i] *= 2;
    }
}

int main() {
    int numbers[5] = {1, 2, 3, 4, 5};
    processFixed(numbers);  // Works - exactly matches [5]

    int wrong[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    processFixed(wrong);  // COMPILE ERROR - size mismatch
}
```

### When to Use

- Very rare in practice
- Ensures compile-time size checking
- More readable intent but awkward syntax
- **Pointers more common** for array parameters

---

## Objects in Arrays

### Same Decay Rules Apply

```cpp
class Animal {
public:
    void speak() { cout << "Sound" << endl; }
};

void displayAnimals(Animal arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i].speak();  // Array notation
    }
}

int main() {
    Animal animals[3];  // 3 animals created
    displayAnimals(animals, 3);
}
```

### Constructor and Destructor Calls

```cpp
class Dog {
public:
    Dog() { cout << "Dog born" << endl; }
    ~Dog() { cout << "Dog dies" << endl; }
};

int main() {
    Dog dogs[3];  // Constructors called 3 times
}  // Destructors called 3 times as scope exits
```

---

## Pointer Equivalence

### The Three Forms

```cpp
// All three are IDENTICAL to the compiler:
void func1(int arr[]) { }
void func2(int *arr) { }
void func3(int arr[10]) { }  // [10] is ignored!

// Compiler treats all as: void func(int *arr)
```

### Why Size in Brackets Doesn't Work

```cpp
void func(int arr[100]) {
    // You might think: only arrays of 100 ints are accepted
    // NOT TRUE! Compiler ignores the 100

    int small[5] = {1, 2, 3, 4, 5};
    func(small);  // Works fine - size hint ignored!
}
```

### Choosing Between Notations

**Pointer notation - for clarity about pointers:**

```cpp
void func(int *p, int size) { }
```

**Array notation - for clarity about arrays:**

```cpp
void func(int arr[], int size) { }
```

**In practice:** Both are identical; choose for readability

---

## Heap Arrays and Functions

### Passing Heap Arrays

```cpp
int* allocateArray(int size) {
    return new int[size];  // Caller owns!
}

void fillArray(int arr[], int size, int value) {
    for (int i = 0; i < size; i++) {
        arr[i] = value;
    }
}

int main() {
    int *pArray = allocateArray(5);  // Allocate
    fillArray(pArray, 5, 42);         // Fill
    delete[] pArray;                  // Caller must delete!
}
```

### Important Conventions

- **Function allocates**: Must document caller owns memory

  ```cpp
  // Allocates heap memory. CALLER RESPONSIBLE FOR DELETE!
  int* createArray(int size);
  ```

- **Function receives pointer**: Caller retains ownership
  ```cpp
  // Function just uses the array, doesn't own it
  void processArray(int arr[], int size);
  ```

---

## Practical Patterns

### Pattern 1: Search

```cpp
int findIndex(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) return i;
    }
    return -1;  // Not found
}

int idx = findIndex(numbers, 5, 30);
```

### Pattern 2: Count/Filter

```cpp
int countEven(int arr[], int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0) count++;
    }
    return count;
}
```

### Pattern 3: Find Min/Max

```cpp
int findMax(int arr[], int size) {
    int maxVal = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > maxVal) maxVal = arr[i];
    }
    return maxVal;
}
```

### Pattern 4: Aggregate (Sum, Average)

```cpp
double calculateAverage(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return (double)sum / size;
}
```

### Pattern 5: Transform (Modify All)

```cpp
void doubleAll(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] *= 2;  // Modifies original!
    }
}
```

---

## Common Mistakes

### Mistake 1: Forgetting Size Parameter

```cpp
// WRONG - How many elements?
void process(int arr[]) {
    for (int i = 0; i < ???; i++) {  // What value?
        cout << arr[i] << endl;
    }
}

// CORRECT
void process(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << endl;
    }
}
```

### Mistake 2: Assuming sizeof Works

```cpp
void process(int arr[], int size) {
    // WRONG - sizeof(arr) is size of pointer (8 bytes)
    int count = sizeof(arr) / sizeof(int);  // Wrong!

    // CORRECT - use parameter
    for (int i = 0; i < size; i++) {  // Use parameter
        cout << arr[i] << endl;
    }
}
```

### Mistake 3: Array Size in Function Signature

```cpp
// These are all the same - size is IGNORED:
void func(int arr[10]) { }
void func(int arr[100]) { }
void func(int arr[]) { }

// Don't rely on size in brackets!
```

### Mistake 4: Not Documenting Ownership

```cpp
// Which is this? Does caller own it?
int* getArray();  // Unclear!

// BETTER - document clearly
// Returns newly allocated array. CALLER MUST DELETE!
int* getArray();

// Receives pointer. Caller retains ownership.
void processArray(int arr[], int size);
```

### Mistake 5: Forgetting delete for Heap Arrays

```cpp
// WRONG
int *p = allocateArray(10);
useArray(p, 10);
// Forgot delete!  Memory leak!

// CORRECT
int *p = allocateArray(10);
useArray(p, 10);
delete[] p;  // Must delete heap memory
p = nullptr;
```

---

## Summary

### Key Concepts

1. **Array Decay**: Arrays automatically convert to pointers when passed
2. **Size Lost**: Function doesn't know original array size
3. **Always Pass Size**: Explicitly pass array length as parameter
4. **Modifications Persist**: Changes in function affect original array
5. **Pointer Equivalence**: `arr[]` and `*arr` are identical in parameters
6. **Documentation**: Clearly document ownership and expectations

### Best Practices

```cpp
// Good: Clear intent and size
void processArray(int arr[], int size);

// Good: Const prevents accidental modification
void readArray(const int arr[], int size);

// Good: Document ownership
// Returns newly allocated array. CALLER RESPONSIBLE FOR DELETE!
int* createArray(int size);

// Bad: No size parameter
void process(int arr[]);

// Bad: Assuming size
void process(int arr[100]);  // Size hint ignored!
```

---

## Next Steps

- Study **2D array parameters** and multi-dimensional arrays
- Learn **function pointers** and callback patterns
- Explore **Standard Library containers** (vector, array) which handle sizing automatically
- Practice **sorting and searching** with array functions
