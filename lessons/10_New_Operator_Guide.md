# LESSON 10: The New and Delete Operators

## Dynamic Memory Allocation in C++

---

## Table of Contents

1. [Introduction](#introduction)
2. [Stack vs Heap Memory](#stack-vs-heap-memory)
3. [The New Operator](#the-new-operator)
4. [The Delete Operator](#the-delete-operator)
5. [Arrays on the Heap](#arrays-on-the-heap)
6. [Memory Leaks](#memory-leaks)
7. [Constructors and Destructors](#constructors-and-destructors)
8. [Practical Examples](#practical-examples)
9. [Common Mistakes](#common-mistakes)
10. [Best Practices](#best-practices)

---

## Introduction

The **`new`** and **`delete`** operators provide a way to allocate and deallocate memory on the **heap** at runtime. This differs from declaring variables on the **stack**, which are automatically freed when they go out of scope.

### Why Use `new` and `delete`?

- **Dynamic Size**: Determine array and object sizes at runtime (not compile time)
- **Persistence**: Memory persists until explicitly deleted (not tied to scope)
- **Flexibility**: Pass ownership of memory between functions and objects
- **Integration**: Properly initialize objects through constructors

---

## Stack vs Heap Memory

### Stack Memory

```cpp
{
    int x = 5;           // Stack allocation
    string name = "Bob"; // Stack allocation
} // Automatic cleanup - x and name freed here
```

**Characteristics:**

- Size must be known at compile time
- Automatically freed when out of scope
- Limited size (typically a few MB)
- Very fast access
- What you've been using so far

### Heap Memory

```cpp
{
    int *p = new int(5);           // Heap allocation
    string *pName = new string("Bob"); // Heap allocation
} // NO automatic cleanup - memory is leaked!
// Must call delete to free memory
```

**Characteristics:**

- Size can be determined at runtime
- Must be manually freed with `delete`
- Large available size (RAM dependent)
- Slightly slower access than stack
- Persists beyond scope

---

## The New Operator

### Basic Syntax

```cpp
PointerType *ptr = new ClassName();
PointerType *ptr = new ClassName(constructor_args);
PointerType *ptr = new PrimitiveType(initial_value);
```

### What Happens When You Call `new`?

1. **Memory Allocation**: Allocates memory on the heap
2. **Constructor Call**: Calls the constructor if it's an object
3. **Pointer Return**: Returns a pointer to the allocated memory

### Example: Single Object

```cpp
// Stack allocation (automatic cleanup)
Animal cat;            // Constructor called, lives on stack
cat.setName("Fluffy"); // Use with dot operator

// Heap allocation (manual cleanup required)
Animal *pCat = new Animal();              // Constructor called, lives on heap
pCat->setName("Fluffy");                  // Use with arrow operator
delete pCat;                              // Constructor NOT called
```

### Example: Primitive Types

```cpp
int *p = new int(42);              // Allocate int with value 42
double *pd = new double(3.14);     // Allocate double
string *ps = new string("Hello");  // Allocate string

cout << *p << endl;  // Access with dereference operator
delete p;
delete pd;
delete ps;
```

### Example: Without Initial Value

```cpp
// Default initialization (uninitialized for primitives)
int *p = new int;              // int on heap, uninitialized value
cout << *p << endl;            // Undefined!
delete p;

// Better - initialize explicitly
int *p = new int(0);           // Initialize to 0
cout << *p << endl;            // Safe
delete p;
```

---

## The Delete Operator

### Basic Syntax

```cpp
delete ptr;              // Deallocate single object
delete[] ptr;            // Deallocate array
ptr = nullptr;           // Best practice: set to nullptr
```

### What Happens When You Call `delete`?

1. **Destructor Call**: Calls the destructor (if defined)
2. **Memory Deallocation**: Returns memory to the heap
3. **Pointer Invalidation**: Pointer becomes dangling (points to freed memory)

### Critical Rule: Match `new` with `delete`

```cpp
// CORRECT
int *p = new int(5);
delete p;              // Single object

int *pArray = new int[5];
delete[] pArray;       // Array

// WRONG - Undefined Behavior!
int *p = new int(5);
delete[] p;            // WRONG: Used [] for single object

int *pArray = new int[5];
delete pArray;         // WRONG: Didn't use [] for array
```

### Best Practice: Set to nullptr

```cpp
int *p = new int(42);
cout << *p << endl;    // 42
delete p;

// Now p is a dangling pointer - points to freed memory!
// This is dangerous if you use p again:
// cout << *p << endl; // CRASH! Undefined behavior!

// Solution: Set to nullptr
p = nullptr;           // Now it's safe to check
if (p == nullptr) {
    cout << "Pointer is null" << endl; // Safe
}
```

---

## Arrays on the Heap

### Allocating Arrays

```cpp
// Stack array - size must be compile-time constant
int arr[5] = {1, 2, 3, 4, 5};

// Heap array - size can be runtime variable
int *pArr = new int[5];     // Array of 5 integers
pArr[0] = 10;
pArr[1] = 20;
// ... and so on

delete[] pArr;              // Must use delete[], not delete!
```

### Dynamic Size Arrays

```cpp
int size;
cout << "Enter array size: ";
cin >> size;

// Size determined at runtime
int *pArray = new int[size];

for (int i = 0; i < size; i++) {
    pArray[i] = i * 10;
}

delete[] pArray;
pArray = nullptr;
```

### Example: String Array

```cpp
string *pStrings = new string[3];
pStrings[0] = "Hello";
pStrings[1] = "World";
pStrings[2] = "!";

// Print
for (int i = 0; i < 3; i++) {
    cout << pStrings[i] << " ";
}

delete[] pStrings;  // Must use []
pStrings = nullptr;
```

---

## Memory Leaks

A **memory leak** occurs when you allocate memory with `new` but forget to call `delete`. The memory is wasted and permanently inaccessible.

### Example of a Leak

```cpp
// MEMORY LEAK!
void leaky_function() {
    Animal *pCat = new Animal("Whiskers");
    pCat->speak();
    // Forgot delete! Function exits, pCat goes out of scope
    // But the Animal object memory remains allocated!
    // This memory is leaked - lost forever!
}
```

### Overwriting Pointers

```cpp
// MEMORY LEAK!
Animal *pAnimal = new Animal("Tom");      // Allocate Tom
pAnimal->speak();

pAnimal = new Animal("Jerry");            // LEAK! Tom's memory is lost
pAnimal->speak();

delete pAnimal;                           // Only Jerry is deleted
// Tom's memory is leaked!
```

### Multiple Returns

```cpp
// MEMORY LEAK!
Animal* createAnimal(string name) {
    Animal *pAnimal = new Animal(name);   // Allocate
    if (name.empty()) {
        return nullptr;                   // LEAK! Memory allocated but not freed!
    }
    return pAnimal;
}

// Call it
Animal *pCat = createAnimal("");          // Returns nullptr
// Memory was allocated then leaked!
```

### Safe Version

```cpp
// CORRECT - No leak
Animal* createAnimal(string name) {
    if (name.empty()) {
        return nullptr;                   // Return nullptr immediately
    }
    return new Animal(name);              // Only allocate if valid
}
```

---

## Constructors and Destructors

### Automatic Constructor Call

When you use `new`, the constructor is automatically called with the arguments you provide.

```cpp
class Animal {
public:
    Animal() {
        cout << "Default constructor" << endl;
    }

    Animal(string name) {
        cout << "Constructor with name: " << name << endl;
    }
};

// Calls default constructor
Animal *p1 = new Animal();           // Output: "Default constructor"

// Calls parameterized constructor
Animal *p2 = new Animal("Fluffy");   // Output: "Constructor with name: Fluffy"
```

### Automatic Destructor Call

When you call `delete`, the destructor is automatically called.

```cpp
class Animal {
public:
    ~Animal() {
        cout << "Destructor called" << endl;
    }
};

Animal *pCat = new Animal();
delete pCat;                         // Output: "Destructor called"
```

### Why Destructors Matter

Destructors are critical for cleanup:

```cpp
class FileHandler {
private:
    FILE *file;

public:
    FileHandler(const char *filename) {
        file = fopen(filename, "r");
    }

    ~FileHandler() {
        if (file != nullptr) {
            fclose(file);            // Properly close file
            cout << "File closed" << endl;
        }
    }
};

FileHandler *handler = new FileHandler("data.txt");
// ... use the file ...
delete handler;                      // Destructor called - file closed!
```

---

## Practical Examples

### Example 1: Simple Class

```cpp
class Person {
private:
    string name;
    int age;

public:
    Person(string n, int a) : name(n), age(a) {}

    void display() {
        cout << name << " is " << age << " years old" << endl;
    }
};

int main() {
    Person *p = new Person("Alice", 30);
    p->display();
    delete p;

    return 0;
}
```

### Example 2: Returning Heap Objects

```cpp
Animal* createCat(string name) {
    return new Animal(name);          // Caller responsible for delete
}

int main() {
    Animal *myCat = createCat("Tom");
    myCat->speak();
    delete myCat;                     // Caller must remember this!

    return 0;
}
```

### Example 3: Dynamic Vector Simulation

```cpp
int main() {
    int capacity = 10;
    int *arr = new int[capacity];
    int size = 0;

    // Add elements
    for (int i = 0; i < 5; i++) {
        arr[size++] = i * 10;
    }

    // Print
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr;

    return 0;
}
```

---

## Common Mistakes

| Mistake                            | Problem                | Fix                             |
| ---------------------------------- | ---------------------- | ------------------------------- |
| Forgetting `delete`                | Memory leak            | Always call delete after new    |
| `delete` without `[]` for arrays   | Undefined behavior     | Use `delete[]` for arrays       |
| `delete[]` for single objects      | Undefined behavior     | Use `delete` for single objects |
| Using deleted pointer              | Crash (use-after-free) | Set to nullptr after delete     |
| Allocating in new, deleting in old | Memory corruption      | Track allocation properly       |
| Not matching scopes                | Dangling pointers      | Delete where you new            |

### Wrong: Forgetting Delete

```cpp
void leak1() {
    int *p = new int(5);  // LEAK - never deleted
}
```

### Right: Proper Cleanup

```cpp
void noleak() {
    int *p = new int(5);
    // ... use p ...
    delete p;
    p = nullptr;
}
```

### Wrong: Mismatched New/Delete

```cpp
void wrong() {
    int *pArray = new int[5];
    delete pArray;           // WRONG! Should be delete[]
}
```

### Right: Matching Operators

```cpp
void right() {
    int *pArray = new int[5];
    delete[] pArray;         // Correct!
    pArray = nullptr;
}
```

---

## Best Practices

### 1. Always Delete What You New

```cpp
// Follow this pattern:
ClassName *ptr = new ClassName();
// ... use ptr ...
delete ptr;
ptr = nullptr;
```

### 2. Use RAII (Resource Acquisition Is Initialization)

Instead of manual new/delete, use container classes or smart pointers that manage cleanup automatically.

```cpp
// Modern C++ - STL containers handle allocation
vector<Animal> animals;
animals.push_back(Animal("Fluffy"));
// Automatic cleanup when vector is destroyed
```

### 3. Prefer std::unique_ptr (Modern C++)

```cpp
#include <memory>

// Automatic cleanup - no manual delete needed!
unique_ptr<Animal> pCat(new Animal("Fluffy"));
pCat->speak();
// Destructor called automatically when pCat goes out of scope
```

### 4. Check for nullptr

```cpp
Animal *p = new Animal("Spot");
if (p != nullptr) {
    p->speak();
}
delete p;
p = nullptr;
```

### 5. Exception Safety

```cpp
// If an exception is thrown, who deletes the memory?
void function() {
    Animal *p = new Animal("Fluffy");

    if (someCondition) {
        throw runtime_error("Error!");  // LEAK! p not deleted
    }

    delete p;
}
```

**Solution**: Use smart pointers or RAII

```cpp
void function() {
    unique_ptr<Animal> p(new Animal("Fluffy"));

    if (someCondition) {
        throw runtime_error("Error!");  // Safe! p deleted automatically
    }
}
```

### 6. Document Ownership

```cpp
// Who is responsible for deleting this?
Animal* createAnimal(string name) {
    return new Animal(name);  // Caller owns the memory!
    // Must document this!
}

// Or prefer returning value/smart pointer
unique_ptr<Animal> createAnimal(string name) {
    return make_unique<Animal>(name);
}
```

---

## Summary

- **`new`** allocates memory on the heap and calls constructors
- **`delete`** deallocates memory and calls destructors
- Always **match `new` with `delete`** and **`new[]` with `delete[]`**
- **Memory leaks** occur when you forget to delete
- **Set pointers to nullptr** after deletion
- **Constructors and destructors** are called automatically
- **Prefer modern C++** with smart pointers or containers for automatic cleanup

---

## Next Steps

- Learn about **smart pointers** (`unique_ptr`, `shared_ptr`) for automatic memory management
- Study **exception safety** and RAII principles
- Understand **memory management best practices** in large projects
