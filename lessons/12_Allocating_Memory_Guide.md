# LESSON 12: Allocating Memory

## Arrays, Buffers, and Dynamic Memory Management

---

## Table of Contents

1. [Introduction](#introduction)
2. [Allocating Arrays of Objects](#allocating-arrays-of-objects)
3. [Dynamic Size Allocation](#dynamic-size-allocation)
4. [Raw Memory Allocation](#raw-memory-allocation)
5. [Memory Layout and Contiguity](#memory-layout-and-contiguity)
6. [Stack vs Heap Arrays](#stack-vs-heap-arrays)
7. [Character Arrays and Strings](#character-arrays-and-strings)
8. [Critical Rules](#critical-rules)
9. [Practical Applications](#practical-applications)
10. [Common Mistakes](#common-mistakes)

---

## Introduction

Memory allocation in C++ involves two main approaches:

1. **Stack Allocation** - Automatic, fixed size, scope-limited
2. **Heap Allocation** - Manual, flexible size, persistent

This lesson focuses on **heap allocation of arrays and blocks** of memory, understanding how to allocate, access, and properly deallocate memory for multiple elements.

---

## Allocating Arrays of Objects

### Basic Syntax

```cpp
ClassName *ptr = new ClassName[size];
```

### What Happens

1. **Memory allocated** for `size` objects on the heap
2. **Constructor called** for each object in the array
3. **Pointer returned** to first element
4. **Memory is contiguous** - all elements next to each other

### Constructor Behavior

When you allocate an array, the constructor is called multiple times:

```cpp
class Animal {
public:
    Animal() {
        cout << "Constructor called" << endl;
    }
};

int main() {
    Animal *pAnimals = new Animal[5];
    // Output: "Constructor called" (5 times)
}
```

### Accessing Array Elements

```cpp
Animal *pAnimals = new Animal[5];

// Method 1: Array notation
pAnimals[0].setName("Rex");
pAnimals[3].speak();

// Method 2: Pointer arithmetic
*(pAnimals + 0);  // Element 0
*(pAnimals + 3);  // Element 3
(pAnimals + 2)->speak();
```

### Complete Example

```cpp
class Animal {
private:
    string name;

public:
    void setName(string n) { name = n; }
    void speak() { cout << "I am " << name << endl; }
};

int main() {
    // Allocate array of 3 Animals
    Animal *pAnimals = new Animal[3];

    // Set names
    pAnimals[0].setName("Rex");
    pAnimals[1].setName("Buddy");
    pAnimals[2].setName("Max");

    // Display all
    for (int i = 0; i < 3; i++) {
        pAnimals[i].speak();
    }

    // Clean up
    delete[] pAnimals;
}
```

### Critical: Use delete[] Not delete

```cpp
// WRONG
Animal *pAnimals = new Animal[5];
delete pAnimals;  // ERROR! Missing []

// CORRECT
Animal *pAnimals = new Animal[5];
delete[] pAnimals;  // Use [] for arrays
```

---

## Dynamic Size Allocation

### Size at Compile Time vs Runtime

**Stack arrays - Size must be compile-time constant:**

```cpp
int size = 5;
int arr[size];  // COMPILE ERROR! Not constant
```

**Heap arrays - Size can be runtime:**

```cpp
int size;
cin >> size;
int *pArr = new int[size];  // OK! Size at runtime
```

### Example: User-Determined Size

```cpp
int main() {
    int numAnimals;
    cout << "How many animals? ";
    cin >> numAnimals;

    // Allocate that many
    Animal *pAnimals = new Animal[numAnimals];

    // Use them
    for (int i = 0; i < numAnimals; i++) {
        pAnimals[i].setName("Animal" + to_string(i));
    }

    delete[] pAnimals;
}
```

### Advantages of Dynamic Sizing

- **Flexibility**: Size determined at runtime
- **Efficiency**: Allocate only what's needed
- **Responsiveness**: React to user input
- **Scalability**: Handle varying workloads

---

## Raw Memory Allocation

### Allocating Primitive Types

```cpp
// Character array (buffer)
char *pBuffer = new char[1000];
pBuffer[0] = 'H';
delete[] pBuffer;

// Integer array
int *pNumbers = new int[100];
pNumbers[0] = 42;
delete[] pNumbers;

// Double array
double *pValues = new double[50];
pValues[0] = 3.14;
delete[] pValues;
```

### Example: Buffer Allocation

```cpp
int main() {
    // Allocate 1000-byte buffer
    char *pBuffer = new char[1000];

    // Fill with data
    for (int i = 0; i < 1000; i++) {
        pBuffer[i] = 'A' + (i % 26);
    }

    // Use the buffer
    cout << "Buffer first 10 chars: ";
    for (int i = 0; i < 10; i++) {
        cout << pBuffer[i];
    }
    cout << endl;

    // Clean up
    delete[] pBuffer;
}
```

---

## Memory Layout and Contiguity

### Array Memory Structure

When you allocate an array, it occupies **contiguous memory**:

```
Allocate: Animal *pAnimals = new Animal[3];

Memory:
┌─────────────┬─────────────┬─────────────┐
│  Animal 0   │  Animal 1   │  Animal 2   │
└─────────────┴─────────────┴─────────────┘
     ↑ pAnimals      ↑ pAnimals+1  ↑ pAnimals+2
```

### Accessing with Pointers

```cpp
Animal *pAnimals = new Animal[3];

// Index notation
pAnimals[0]  // Address: pAnimals
pAnimals[1]  // Address: pAnimals + size_of_Animal
pAnimals[2]  // Address: pAnimals + 2*size_of_Animal

// Pointer arithmetic
*(pAnimals + 0)  // Same as pAnimals[0]
*(pAnimals + 1)  // Same as pAnimals[1]
(pAnimals + 2)->speak();  // Call method on element 2
```

### Benefits of Contiguity

1. **Cache Friendly**: Sequential access is efficient
2. **Predictable**: Know exactly where each element is
3. **Pointer Arithmetic**: Works naturally
4. **Memory Efficient**: No fragmentation overhead

### Example: Demonstrating Layout

```cpp
int *pArray = new int[5]{10, 20, 30, 40, 50};

cout << "Array addresses:" << endl;
cout << "pArray[0] at: " << pArray << endl;
cout << "pArray[1] at: " << (pArray + 1) << endl;
cout << "pArray[2] at: " << (pArray + 2) << endl;

cout << "Values:" << endl;
cout << "pArray[0] = " << *pArray << endl;
cout << "pArray[1] = " << *(pArray + 1) << endl;
cout << "pArray[2] = " << *(pArray + 2) << endl;

delete[] pArray;
```

---

## Stack vs Heap Arrays

### Stack Arrays

```cpp
int stackArray[10];  // Fixed size, compile-time constant
```

**Characteristics:**

- Size known at compile time
- Automatic allocation and deallocation
- Limited to stack size (few MB)
- Fast access
- Scope-limited lifetime

**When to use:**

- Small, fixed-size arrays
- Simple data types
- Short lifetime
- Most stack arrays in practice

### Heap Arrays

```cpp
int *heapArray = new int[size];  // Size at runtime
```

**Characteristics:**

- Size determined at runtime
- Manual allocation and deallocation
- Large available memory (GB range)
- Slightly slower than stack
- Persistent lifetime

**When to use:**

- Large arrays
- Variable size
- Persistent across scopes
- Unknown size at compile time

### Comparison Table

| Aspect       | Stack               | Heap              |
| ------------ | ------------------- | ----------------- |
| **Size**     | Fixed, compile-time | Runtime, flexible |
| **Memory**   | Stack (limited)     | Heap (large)      |
| **Speed**    | Faster              | Slightly slower   |
| **Cleanup**  | Automatic           | Manual            |
| **Lifetime** | Scope-limited       | Until delete      |
| **Safety**   | Safer               | Requires care     |

### Example: Choosing Correctly

```cpp
// Use stack for small, fixed arrays
int smallArray[100];  // Fine - 400 bytes

// Use heap for larger, dynamic arrays
int largeSize;
cin >> largeSize;
int *pLargeArray = new int[largeSize];  // Necessary
delete[] pLargeArray;
```

---

## Character Arrays and Strings

### Character Arrays

```cpp
// Raw character array
char *pStr = new char[20];
pStr[0] = 'H';
pStr[1] = 'i';
pStr[2] = '\0';  // Null terminator required
cout << pStr << endl;  // Output: "Hi"

delete[] pStr;
```

### Creating Strings with Repeated Characters

```cpp
// Create 5 'b's
char c = 'a';
c++;  // Now 'b'
string repeated(5, c);  // "bbbbb"
cout << repeated << endl;
```

### Comparing Approaches

```cpp
// C-style char array
char *pChars = new char[50];
pChars[0] = 'H';
pChars[1] = 'i';
pChars[2] = '\0';
delete[] pChars;

// Modern C++ string
string str("Hi");
// Automatic cleanup, safer
```

### Recommendation

- **Use `std::string`** for text - safer and easier
- **Use `char[]`** for low-level buffers - when needed for performance
- **Remember null terminator** - required for C-style strings

---

## Critical Rules

### Rule 1: Match new[] with delete[]

```cpp
// CORRECT
Animal *p = new Animal[10];
delete[] p;

// WRONG - Will crash or leak
Animal *p = new Animal[10];
delete p;  // Missing []!
```

### Rule 2: Constructor and Destructor

```cpp
// new[] calls constructor for each element
Animal *p = new Animal[3];  // Constructor called 3 times

// delete[] calls destructor for each element
delete[] p;  // Destructor called 3 times
```

### Rule 3: Runtime Size for Heap Only

```cpp
// Stack requires compile-time constant
int size = 10;
int stack[size];  // COMPILE ERROR

// Heap allows runtime size
int *heap = new int[size];  // OK
```

### Rule 4: No Bounds Checking

```cpp
int *p = new int[5];
p[100] = 5;  // No error! But undefined behavior!
// C++ does NOT check array bounds
```

### Rule 5: Each Element Gets Initialized

```cpp
class Animal {
public:
    Animal() { cout << "Created" << endl; }
};

Animal *p = new Animal[5];
// Output: "Created" (5 times)
```

---

## Practical Applications

### 1. Dynamic Buffer for I/O

```cpp
int bufferSize = 4096;
char *pBuffer = new char[bufferSize];

// Read data into buffer
// ... process buffer ...

delete[] pBuffer;
```

### 2. Matrix Allocation

```cpp
int rows = 10;
int cols = 20;

int **pMatrix = new int*[rows];
for (int i = 0; i < rows; i++) {
    pMatrix[i] = new int[cols];
}

// Use matrix...

// Clean up
for (int i = 0; i < rows; i++) {
    delete[] pMatrix[i];
}
delete[] pMatrix;
```

### 3. Object Pool

```cpp
int numObjects = 100;
Animal *pPool = new Animal[numObjects];

// Initialize pool
for (int i = 0; i < numObjects; i++) {
    pPool[i].setName("Object" + to_string(i));
}

// Use pool...

delete[] pPool;
```

### 4. Dynamic String Arrays

```cpp
int numStrings;
cin >> numStrings;

string *pStrings = new string[numStrings];

// Fill strings
for (int i = 0; i < numStrings; i++) {
    cin >> pStrings[i];
}

// Use strings...

delete[] pStrings;
```

---

## Common Mistakes

### Mistake 1: Using delete Instead of delete[]

```cpp
// WRONG
Animal *p = new Animal[10];
delete p;  // WRONG! Missing []

// CORRECT
Animal *p = new Animal[10];
delete[] p;  // Correct
```

### Mistake 2: Returning Deleted Pointer

```cpp
// WRONG
Animal* getAnimals() {
    Animal *p = new Animal[10];
    delete[] p;  // Deleted!
    return p;   // Returning dangling pointer!
}
```

### Mistake 3: Accessing Out of Bounds

```cpp
int *p = new int[5];
p[100] = 5;  // WRONG! Out of bounds
// C++ does not check - undefined behavior
```

### Mistake 4: Forgetting New for Large Arrays

```cpp
// WRONG - Stack overflow!
Animal animals[1000000];  // Too large for stack

// CORRECT
Animal *pAnimals = new Animal[1000000];  // Use heap
delete[] pAnimals;
```

### Mistake 5: Mixing Stack and Heap

```cpp
// WRONG - Confusion
Animal stack_array[10];
Animal *heap_array = new Animal[10];
delete[] stack_array;  // ERROR! Can't delete stack!
```

---

## Summary

### Key Points

1. **Allocate arrays** with `new[]` for runtime-sized allocation
2. **Deallocate arrays** with `delete[]` (with brackets!)
3. **Constructor called** for each element during allocation
4. **Destructor called** for each element during deallocation
5. **Memory is contiguous** - efficient and predictable
6. **Index notation works** - `ptr[i]` is same as `*(ptr + i)`
7. **No bounds checking** - programmer responsible for validity
8. **Choose wisely** - stack for small/fixed, heap for large/dynamic

### When to Use What

| Need               | Choice | Example                  |
| ------------------ | ------ | ------------------------ |
| Fixed, small array | Stack  | `int arr[100]`           |
| Dynamic size       | Heap   | `int *p = new int[size]` |
| Large array        | Heap   | Can't fit on stack       |
| Simple path        | Stack  | If possible              |
| Cross-scope        | Heap   | If needed                |

---

## Next Steps

- Study **2D arrays** and **matrix allocation**
- Learn **memory pools** and **pre-allocation strategies**
- Explore **container classes** (vector) that handle allocation automatically
- Understand **object-oriented memory management patterns**
