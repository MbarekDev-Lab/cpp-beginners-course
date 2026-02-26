# The Const Keyword in C++

## What is Const?

The **const** keyword makes variables, pointers, and methods **immutable** (unchangeable after initialization).

```cpp
const double PI = 3.14159;
PI = 3.14;  // ERROR - cannot change!
```

## Three Main Uses of Const

### 1. Const Variables

Variables whose value cannot be changed after initialization.

```cpp
const double PI = 3.141592653589793;
const int MAX_STUDENTS = 100;

// PI = 3.14;  // ERROR
// MAX_STUDENTS = 50;  // ERROR
```

### 2. Const Pointers

The **pointer itself** is constant (address cannot change), but the **data** it points to can change.

```cpp
int value = 5;
int * const ptr = &value;  // Const pointer

*ptr = 10;           // OK - changing data
// ptr = &other;    // ERROR - cannot change pointer
```

### 3. Pointers to Const

The **pointer** can change, but the **data** it points to is constant.

```cpp
int value = 5;
const int *ptr = &value;  // Pointer to const

ptr = &other;      // OK - can change pointer
// *ptr = 10;     // ERROR - cannot change data
```

## Reading Pointer Declarations

**Rule: Read pointer declarations RIGHT-TO-LEFT**

```cpp
int *ptr              → "ptr is a pointer to int"
int * const ptr       → "ptr is a CONST pointer to int"
const int *ptr        → "ptr is a pointer to CONST int"
const int * const ptr → "ptr is a CONST pointer to CONST int"
```

## The Four Cases

### Case 1: Regular Pointer - `int *ptr`

```cpp
int x = 5;
int y = 10;

int *ptr = &x;

*ptr = 20;     // ✓ Can modify data
ptr = &y;      // ✓ Can change pointer
```

Both pointer and data can change.

### Case 2: Const Pointer - `int * const ptr`

```cpp
int x = 5;
int y = 10;

int * const ptr = &x;

*ptr = 20;     // ✓ Can modify data
// ptr = &y;  // ✗ ERROR - pointer is const
```

**Pointer is fixed, data can change.**

### Case 3: Pointer to Const - `const int *ptr`

```cpp
int x = 5;
int y = 10;

const int *ptr = &x;

// *ptr = 20; // ✗ ERROR - data is const
ptr = &y;     // ✓ Can change pointer
```

**Pointer can change, data is fixed.**

### Case 4: Const Pointer to Const - `const int * const ptr`

```cpp
int x = 5;

const int * const ptr = &x;

// *ptr = 20; // ✗ ERROR - data is const
// ptr = ...  // ✗ ERROR - pointer is const
```

**Both pointer and data are fixed.**

## Const Methods

Methods marked `const` cannot modify the object's member variables.

```cpp
class Animal {
private:
    string name;

public:
    // Non-const method - can modify state
    void setName(string n) {
        name = n;  // OK
    }

    // Const method - cannot modify state
    void display() const {
        cout << name << endl;      // OK - reading
        // name = "new";           // ERROR - modifying
    }
};
```

**Use const methods for getters and display functions.**

## Const in Function Parameters

### Read-Only Parameters

```cpp
// Function promises not to modify
void printValue(const int *ptr) {
    cout << *ptr << endl;
    // *ptr = 100;  // ERROR - compiler prevents this
}

int x = 42;
printValue(&x);  // x is safe from modification
```

### Modifying Parameters

```cpp
// Function may modify the value
void writeValue(int *ptr) {
    *ptr = 100;  // OK
}

int x = 42;
writeValue(&x);  // x might be changed
```

### Const References (Preferred Style)

```cpp
// More natural with references
void printValue(const int &val) {
    cout << val << endl;
}

void writeValue(int &val) {
    val = 100;
}
```

## Memory Location Table

To understand pointer const-ness, think about what's at each memory location:

```cpp
int x = 10, y = 20;

// Regular pointer
int *p1 = &x;
// p1 can change:  p1 = &y;
// *p1 can change: *p1 = 50;

// Const pointer
int * const p2 = &x;
// p2 cannot change: p2 = &y;  // ERROR
// *p2 can change:   *p2 = 50; // OK

// Pointer to const
const int *p3 = &x;
// p3 can change:    p3 = &y;   // OK
// *p3 cannot change: *p3 = 50; // ERROR

// Const pointer to const
const int * const p4 = &x;
// p4 cannot change:  p4 = &y;   // ERROR
// *p4 cannot change: *p4 = 50;  // ERROR
```

## Practical Examples

### Example 1: Protecting Data from Modification

```cpp
void processArray(const int *arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << endl;  // Can read
        // arr[i] = 0;           // Cannot modify
    }
}
```

### Example 2: Const Getter

```cpp
class Account {
private:
    double balance;

public:
    // Const method - safe to call anytime
    double getBalance() const {
        return balance;
    }

    // Non-const method - modifies state
    void deposit(double amount) {
        balance += amount;
    }
};
```

### Example 3: Fixed Array Iteration

```cpp
string texts[] = {"one", "two", "three"};
int size = 3;

// Using const pointer (end point fixed)
string * const pEnd = &texts[size];
string *pCurrent = &texts[0];

while (pCurrent != pEnd) {
    cout << *pCurrent << endl;
    pCurrent++;
}
```

## Const vs Non-Const

### Non-Const Issues

```cpp
void process(int *val) {
    // Caller doesn't know if this modifies val
    // Intent is unclear
}
```

### Const Clarity

```cpp
void read(const int *val) {
    // Clear: This doesn't modify
}

void write(int *val) {
    // Clear: This might modify
}
```

## Const Correctness

**Best Practice: Use const everywhere possible**

Benefits:

- Documents intent clearly
- Compiler catches mistakes
- Prevents accidental modifications
- Makes code safer and maintainable
- Enables compiler optimizations

```cpp
// Good const correctness
const double PI = 3.14159;
void printMessage(const string &msg) {
    cout << msg << endl;
}

void updateValue(int &value) {
    value = 100;
}
```

## Quick Reference

| Declaration           | Pointer Changeable | Data Changeable | Use Case         |
| --------------------- | ------------------ | --------------- | ---------------- |
| `int *p`              | ✓                  | ✓               | General use      |
| `int * const p`       | ✗                  | ✓               | Fixed reference  |
| `const int *p`        | ✓                  | ✗               | Read-only access |
| `const int * const p` | ✗                  | ✗               | Fully fixed      |

## Common Mistakes

### Mistake 1: Confusing Declaration Order

```cpp
// Pointer to const (RIGHT)
const int *ptr;

// Const pointer (WRONG for this intent)
int * const ptr;
```

### Mistake 2: Trying to Modify Const Data

```cpp
const int x = 5;
x = 10;  // ERROR - x is const!

const int *ptr = &x;
*ptr = 10;  // ERROR - data is const!
```

### Mistake 3: Const Method Modifying Data

```cpp
class MyClass {
    int value;

    void setValue(int v) const {
        value = v;  // ERROR - const method!
    }
};
```

### Mistake 4: Not Using Const Parameters

```cpp
// Unclear intent
void process(string str) {
    cout << str << endl;
    // Does this modify str?
}

// Clear intent
void process(const string &str) {
    cout << str << endl;
    // Obviously doesn't modify
}
```

## Key Principles

1. **const is a promise**: "I won't modify this"
2. **Read right-to-left**: Makes pointer declarations clear
3. **Use it everywhere**: Make intent explicit
4. **Compiler enforces**: Breaking const causes errors
5. **Document behavior**: Callers see what's safe

## Summary

| Concept          | Example                | Means                     |
| ---------------- | ---------------------- | ------------------------- |
| Const variable   | `const int x = 5;`     | x cannot change           |
| Const pointer    | `int * const p = &x;`  | p cannot change, \*p can  |
| Pointer to const | `const int *p = &x;`   | p can change, \*p cannot  |
| Const method     | `void show() const {}` | Method won't modify state |

Use const liberally to write safer, more maintainable code!
