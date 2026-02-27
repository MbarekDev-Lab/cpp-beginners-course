# Copy Constructors in C++

## What is a Copy Constructor?

A **copy constructor** is a special constructor that creates a new object as a copy of an existing object of the same class.

```cpp
class Animal {
public:
    Animal(const Animal& other) {
        // Copy logic here
    }
};
```

## Copy Constructor Syntax

```cpp
ClassName(const ClassName& other) {
    // Copy member variables from other
}
```

**Key points:**

- `const` - promises not to modify the original
- `&` - parameter is a reference (efficient, avoids recursion)
- `other` - the object being copied from

## When is Copy Constructor Called?

### 1. Direct Assignment

```cpp
Animal animal1;
Animal animal2 = animal1;  // Copy constructor called
```

### 2. Explicit Constructor Call

```cpp
Animal animal1;
Animal animal2(animal1);  // Copy constructor called
```

### 3. Function Parameters (By Value)

```cpp
void process(Animal a) {  // Calls copy constructor
    // a is a copy of the argument
}

Animal animal1;
process(animal1);  // Copy constructor called here
```

### 4. Return Values

```cpp
Animal getAnimal(Animal original) {
    return original;  // May call copy constructor
}
```

## Example: Simple Copy Constructor

```cpp
class Animal {
private:
    string name;

public:
    // Default constructor
    Animal() {
        cout << "Animal created." << endl;
    }

    // Copy constructor
    Animal(const Animal& other) : name(other.name) {
        cout << "Animal created by copying." << endl;
    }

    void setName(string n) { name = n; }
    void speak() const { cout << name << endl; }
};
```

Usage:

```cpp
Animal animal1;
animal1.setName("Freddy");

Animal animal2 = animal1;  // Calls copy constructor
animal2.speak();           // Prints: Freddy
```

## Default Copy Constructor

If you don't define a copy constructor, **C++ automatically generates one** that performs **memberwise copy**.

```cpp
class Simple {
public:
    int x;
    string name;
    // Implicit copy constructor created by compiler
};

Simple obj1;
obj1.x = 5;
obj1.name = "Alice";

Simple obj2 = obj1;  // Memberwise copy
// obj2.x = 5, obj2.name = "Alice"
```

## Shallow vs Deep Copy

### Shallow Copy (Default)

Both objects point to the **same memory**.

```cpp
class Dangerous {
public:
    int *data;

    Dangerous(int size) {
        data = new int[size];
    }
    // No copy constructor - uses default shallow copy
};

Dangerous obj1(5);
Dangerous obj2 = obj1;  // Shallow copy - both point to same memory!

// DANGER: When destructors run, delete[] called twice!
```

### Deep Copy (Custom)

Each object has its **own copy of data**.

```cpp
class Safe {
public:
    int *data;
    int size;

    Safe(int sz) : size(sz) {
        data = new int[size];
    }

    // Deep copy constructor
    Safe(const Safe& other) : size(other.size) {
        data = new int[size];  // Allocate new memory
        for (int i = 0; i < size; i++) {
            data[i] = other.data[i];  // Copy data
        }
    }

    ~Safe() {
        delete[] data;
    }
};

Safe obj1(5);
Safe obj2 = obj1;  // Deep copy - separate memory
// Safe: Each has own memory, delete[] called correctly
```

**When to use:**

- Shallow copy: Simple objects with value members only
- Deep copy: Objects managing dynamic memory (pointers)

## Copy Constructor vs Assignment Operator

These are different operations:

### Copy Constructor (Initialization)

```cpp
Person p1;
p1.name = "Alice";

Person p2 = p1;  // NEW object created - calls copy constructor
```

### Assignment Operator

```cpp
Person p1;
p1.name = "Alice";

Person p2;
p2 = p1;  // EXISTING object updated - calls assignment operator
```

| Aspect          | Copy Constructor              | Assignment Operator                      |
| --------------- | ----------------------------- | ---------------------------------------- |
| **When**        | During object creation        | After object exists                      |
| **Call**        | `ClassName obj2 = obj1;`      | `obj2 = obj1;`                           |
| **Initializes** | Member variables              | Existing members                         |
| **Signature**   | `ClassName(const ClassName&)` | `ClassName& operator=(const ClassName&)` |

## Member Initializer List

Use member initializer list in copy constructor for efficiency:

```cpp
// GOOD - Initializer list
Book(const Book& other) : title(other.title), author(other.author), pages(other.pages) {
    cout << "Copy constructor" << endl;
}

// LESS EFFICIENT - Assignment in body
Book(const Book& other) {
    title = other.title;
    author = other.author;
    pages = other.pages;
}
```

**Benefits:**

- ✓ More efficient (direct initialization vs copy)
- ✓ Required for const members
- ✓ Required for reference members
- ✓ Better for large objects

## Important: Const Reference Parameter

Always use **const reference**:

```cpp
// CORRECT
Animal(const Animal& other) { ... }

// WRONG
Animal(Animal& other) { ... }  // Cannot copy const objects!
```

Why const?

- Allows copying from constant objects
- Promises we won't modify the original
- Allows temporary objects to be copied

## Complete Example

```cpp
#include <iostream>
using namespace std;

class Animal {
private:
    string name;

public:
    Animal() { cout << "Animal created" << endl; }

    Animal(const Animal& other) : name(other.name) {
        cout << "Animal copied" << endl;
    }

    void setName(string n) { name = n; }
    void display() const { cout << "Name: " << name << endl; }
};

int main() {
    Animal a1;
    a1.setName("Freddy");

    cout << "Creating a2 from a1:" << endl;
    Animal a2 = a1;  // Copy constructor called

    a2.setName("Bob");

    cout << "\nBoth animals:" << endl;
    a1.display();  // Freddy
    a2.display();  // Bob

    return 0;
}
```

Output:

```
Animal created
Creating a2 from a1:
Animal copied
Both animals:
Name: Freddy
Name: Bob
```

## Common Mistakes

### Mistake 1: Non-Const Reference

```cpp
// WRONG
Animal(Animal& other) { ... }  // Cannot accept const

Animal a1;
const Animal& a2 = a1;
Animal a3 = a2;  // ERROR - cannot call non-const copy constructor
```

### Mistake 2: Pass by Value (Infinite Recursion)

```cpp
// WRONG - infinite recursion!
Animal(Animal other) {
    // Calling copy constructor to pass parameter!
}

// CORRECT - use reference
Animal(const Animal& other) { ... }
```

### Mistake 3: Forgetting Deep Copy

```cpp
// WRONG for dynamic memory
class Array {
public:
    int *data;
    // Default copy = shallow, DANGEROUS!
};

Array a1(10);
Array a2 = a1;  // Both point to same memory!

// CORRECT - deep copy
class Array {
public:
    int *data;

    Array(const Array& other) {
        data = new int[10];  // New memory
        memcpy(data, other.data, 10);  // Copy values
    }
};
```

### Mistake 4: Modifying Original in Copy

```cpp
// WRONG
string name;
Animal(const Animal& other) {
    other.name = "modified";  // ERROR - other is const!
}
```

## Rule of Three/Five/Zero

**Rule of Three** (or Five in modern C++):
If you define:

1. Destructor
2. Copy constructor
3. Assignment operator

You should typically define all three (or let compiler generate all).

```cpp
class Resource {
private:
    int *data;

public:
    // Constructor
    Resource(int size) { data = new int[size]; }

    // Destructor (1)
    ~Resource() { delete[] data; }

    // Copy constructor (2)
    Resource(const Resource& other) { /* ... */ }

    // Assignment operator (3)
    Resource& operator=(const Resource& other) { /* ... */ }
};
```

## Quick Reference

| Scenario                 | Code               | Constructor Called        |
| ------------------------ | ------------------ | ------------------------- |
| Initialize from existing | `Animal a2 = a1;`  | Copy                      |
| Explicit call            | `Animal a2(a1);`   | Copy                      |
| Function parameter       | `void f(Animal a)` | Copy                      |
| Return value             | `return a;`        | Copy (possibly optimized) |
| Assignment               | `a2 = a1;`         | Assignment operator       |

## Summary

- **Copy constructor** creates new object from existing one
- **Called** during initialization with another object
- **Signature**: `ClassName(const ClassName& other)`
- **Deep copy** for objects managing dynamic memory
- **Shallow copy** sufficient for simple objects
- **Member initializer list** for efficiency
- **Different from** assignment operator
