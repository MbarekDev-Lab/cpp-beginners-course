# Lesson 19: Static - Comprehensive Guide

## Overview

The `static` keyword in C++ has different meanings depending on context. In the context of classes, static members are shared across all instances, creating class-level (not instance-level) variables and methods.

**Key Concepts:**

- Static member variables are shared by all objects of a class
- Static member functions can be called without creating an object
- Static local variables persist across function calls
- Static provides scope at class level, not instance level

---

## Static Member Variables

### Declaration and Initialization

Static member variables must be:

1. **Declared** inside the class with `static` keyword
2. **Defined and initialized** outside the class in the source file

```cpp
// In header (.h)
class Test {
private:
    static int count;  // Declaration only
};

// In source (.cpp)
int Test::count = 0;   // Definition and initialization
```

**Why separate declaration and initialization?**

- Ensures single definition (avoids linker errors)
- Memory allocated once, not per object
- Initialization happens before any objects created

### Key Characteristics

| Aspect        | Static Member           | Instance Member                |
| ------------- | ----------------------- | ------------------------------ |
| Declaration   | In class                | In class                       |
| Definition    | Outside class           | Part of object                 |
| Memory        | One copy per class      | One copy per object            |
| Lifetime      | Program start to end    | Object creation to destruction |
| Access        | ClassName::varName      | object.varName                 |
| Exists before | Objects don't exist yet | Only when object exists        |

### Example: Object Counter

```cpp
class Student {
private:
    string name;
    static int count;  // Shared by all Student objects

public:
    Student(string n) : name(n) {
        count++;
    }

    static int getCount() {
        return count;
    }
};

int Student::count = 0;  // Initialize to 0

int main() {
    cout << Student::getCount() << endl;  // 0

    Student s1("Alice");
    cout << Student::getCount() << endl;  // 1

    Student s2("Bob");
    cout << Student::getCount() << endl;  // 2
}
```

---

## Static Member Functions

### Characteristics

Static member functions:

- Called directly on class: `ClassName::functionName()`
- Can be called WITHOUT creating an object
- Cannot access non-static (instance) members
- No implicit `this` pointer
- Can access static variables and call other static functions

### Syntax

```cpp
class Test {
public:
    // Non-static function
    void normalFunction() { }

    // Static function
    static void staticFunction() {
        // Can access static members
        // Cannot access instance members
    }
};

// Call static function
Test::staticFunction();  // Without object
Test t;
t.staticFunction();      // Through object (allowed but confusing)
```

### Valid vs Invalid Operations

```cpp
class BankAccount {
private:
    double balance;           // Instance variable
    static double totalFunds; // Static variable

public:
    // ✓ Valid: Accesses only static data
    static double getTotalFunds() {
        return totalFunds;
    }

    // ✗ Invalid: Tries to access instance variable
    // static double getBalance() {
    //     return balance;  // Error!
    // }

    // ✗ Invalid: Can't call instance methods
    // static void printInfo() {
    //     cout << getBalance();  // Error!
    // }
};
```

---

## Static Const Members

### Initialization in Class

```cpp
class Circle {
public:
    // Static const can be initialized in class declaration
    static const double PI = 3.14159;
    static const int MAX_RADIUS = 1000;
};

// May still need definition in C++98 (older standard)
// const double Circle::PI;
```

**Note:** In C++17 and later, `inline static` is preferred:

```cpp
class Circle {
public:
    static inline const double PI = 3.14159265;
};
```

### Compile-Time vs Runtime Constants

```cpp
class Test {
    // Compile-time constant: can be used in array size
    static const int SIZE = 100;
    int arr[SIZE];  // OK

    // This would NOT work without const:
    // static int value = 10;  // Error in older C++
    // int arr[value];         // Not compile-time constant
};
```

---

## Static Local Variables

### Function-Level Static

Static variables inside functions:

- Initialized once, on first call
- Retain value between function calls
- Scope limited to the function
- Useful for counters, caches, state

```cpp
void getNextID() {
    static int id = 1000;  // Initialized once
    return id++;           // Increments each call
}

int main() {
    cout << getNextID() << endl;  // 1000
    cout << getNextID() << endl;  // 1001
    cout << getNextID() << endl;  // 1002
}
```

### Use Cases for Static Local Variables

```cpp
// 1. Function call counter
void logFunction() {
    static int callCount = 0;
    cout << "Call #" << ++callCount << endl;
}

// 2. One-time initialization
void initialize() {
    static bool initialized = false;
    if (!initialized) {
        cout << "Initializing..." << endl;
        // Complex initialization code runs once
        initialized = true;
    }
}

// 3. Lazy singleton
Object& getSingleton() {
    static Object instance;  // Created on first call
    return instance;
}
```

---

## Access Levels with Static

### Public Static

```cpp
class Config {
public:
    static int maxConnections = 100;  // Accessible globally

    static void printConfig() {
        cout << maxConnections << endl;
    }
};

// Outside class
cout << Config::maxConnections << endl;      // OK
Config::printConfig();                        // OK
```

### Private Static

```cpp
class Secret {
private:
    static int password;  // Hidden from outside

    static void authenticate() {
        // Used internally only
    }

public:
    static bool login(int guess) {
        return guess == password;
    }
};

// Outside class
cout << Secret::password << endl;    // Error: private!
Secret::authenticate();               // Error: private!
Secret::login(1234);                  // OK
```

---

## Static in Inheritance

### Inheritance Behavior

```cpp
class Base {
public:
    static int value;
};

class Derived : public Base {
    // Derived inherits Base::value, doesn't get its own copy
};

int Base::value = 0;

int main() {
    Base::value = 10;
    cout << Derived::value << endl;  // 10 (same variable!)
}
```

### Important: Static is Not Virtual

Static members cannot be overridden:

```cpp
class Base {
public:
    static void display() {
        cout << "Base" << endl;
    }
};

class Derived : public Base {
public:
    static void display() {  // Doesn't override, hides Base version
        cout << "Derived" << endl;
    }
};

Base* ptr = new Derived();
ptr->display();  // Prints "Base" (not virtual, uses Base version)

Derived* dptr = new Derived();
dptr->display(); // Prints "Derived" (through Derived pointer)
```

---

## Common Patterns and Uses

### 1. Object Registry

Track all objects created:

```cpp
class Employee {
private:
    static vector<Employee*> all_employees;

public:
    Employee(string name) {
        all_employees.push_back(this);
    }

    static void printAllEmployees() {
        for (Employee* emp : all_employees) {
            // Process all employees
        }
    }
};

vector<Employee*> Employee::all_employees;
```

### 2. Counters and Identifiers

Auto-generate unique IDs:

```cpp
class Item {
private:
    static int nextID;
    int id;

public:
    Item() {
        id = nextID++;
    }

    int getID() const { return id; }
};

int Item::nextID = 1;
```

### 3. Global Configuration

Centralized settings:

```cpp
class AppConfig {
public:
    static string appName;
    static int logLevel;
    static bool debugMode;

    static void loadDefaults() {
        appName = "MyApp";
        logLevel = 1;
        debugMode = false;
    }
};

string AppConfig::appName = "";
int AppConfig::logLevel = 0;
bool AppConfig::debugMode = false;
```

### 4. Factory Methods

Create objects of class type:

```cpp
class Database {
private:
    static Database* instance;

    Database() { }  // Private constructor

public:
    static Database* getInstance() {
        if (instance == nullptr) {
            instance = new Database();
        }
        return instance;
    }
};

Database* Database::instance = nullptr;
```

---

## Lifetime and Initialization Order

### Static Initialization Order

```cpp
// file1.cpp
class A {
public:
    static B b;  // B must be initialized
};

B A::b;  // Initialized here

// file2.cpp
class B { };
```

**Warning:** Static initialization order is undefined across translation units. Use initialization functions to avoid:

```cpp
class LazyInit {
private:
    static int* data;

public:
    static int& getData() {
        if (data == nullptr) {
            data = new int(42);  // Lazy initialization
        }
        return *data;
    }
};
```

---

## Best Practices

### 1. Use Static for Class-Level Data

```cpp
// ✓ Good: Shared counter
class Document {
    static int documentCount;
};

// ✗ Bad: Global variable (poor design)
int documentCount = 0;
```

### 2. Keep Static Members Private When Possible

```cpp
// ✓ Good: Encapsulated with accessor
class Test {
private:
    static int count;
public:
    static int getCount() { return count; }
};

// ✗ Bad: Public direct access
class Test {
public:
    static int count;  // Can be changed from anywhere
};
```

### 3. Use Static Const for Constants

```cpp
// ✓ Good: Type-safe constant
class Config {
    static const int MAX_SIZE = 100;
};

// ✗ Bad: Prone to accidental modification
class Config {
    static int MAX_SIZE = 100;  // Can be changed!
};
```

### 4. Document Static Member Initialization Required

```cpp
// .h
class Test {
    static int count;  // ← Note: Must initialize in .cpp!
};

// .cpp
int Test::count = 0;  // ← Required! Missing this is linker error
```

### 5. Avoid Static During Object Initialization

```cpp
// ✗ Dangerous: Using static in constructor
class Bad {
private:
    static int nextID;
public:
    Bad() {
        // Modifying shared state during construction
        // Can cause issues with multiple threads
        id = nextID++;
    }
};

// ✓ Better: Use after construction
class Good {
    static vector<int> ids;
public:
    static int registerID(int id) {
        ids.push_back(id);
        return id;
    }
};
```

---

## Common Mistakes

### Mistake 1: Forgetting to Initialize Static Outside Class

```cpp
// ✗ Error: Linker error
class Test {
public:
    static int count = 0;  // Modern C++17 OK, but old style needs:
};

// Must add to source file:
// int Test::count;

// ✓ Correct (C++17+)
class Test {
public:
    static inline int count = 0;
};
```

### Mistake 2: Accessing Instance Members in Static Function

```cpp
// ✗ Error: No 'this' in static context
class Test {
    int value;
public:
    static void print() {
        cout << value << endl;  // Error!
    }
};

// ✓ Correct: Pass instance as parameter
class Test {
    int value;
public:
    static void print(Test& t) {
        cout << t.value << endl;  // OK
    }
};
```

### Mistake 3: Modifying Static in Destructor

```cpp
// ✗ Problematic: Multiple objects can affect shared state
class Resource {
    static int count;
public:
    ~Resource() {
        count--;  // What if count is accessed while other
    }               // destructors are running?
};
```

### Mistake 4: Static Initialization in Header Files

```cpp
// ✗ Error: Multiple definitions in multiple .cpp files
// test.h
class Test {
public:
    static int count = 10;  // Defined in every file that includes!
};

// ✓ Correct: Initialize in only one .cpp file
// test.h
class Test {
public:
    static int count;  // Declaration
};

// test.cpp
int Test::count = 10;  // Initialization in only one place
```

---

## Modern C++ Features

### C++17: Inline Static

```cpp
class Test {
public:
    static inline int count = 0;  // Initialized in header
};
```

Advantages:

- No need for separate .cpp definition
- Cleaner code
- Still one copy per class

### C++11/14: constexpr Static

```cpp
class Math {
public:
    static constexpr double PI = 3.14159265;  // Compile-time constant
    static constexpr int factorial(int n) {
        return n <= 1 ? 1 : n * factorial(n-1);
    }
};

// Can be used in compile time contexts
int arr[Math::factorial(5)];
```

---

## Summary

**Static Member Variables**

- Shared among all instances
- One copy per class, exists for program lifetime
- Must be initialized outside class (or use inline in C++17+)

**Static Member Functions**

- Called directly on class without object
- Cannot access instance members
- Useful for utilities and class-level operations

**Static Local Variables**

- Function-scoped, persist across calls
- Initialized once
- Useful for counters, caches, singletons

**Key Pattern Uses:**

- Object counting and identification
- Global configuration
- Registry and factory patterns
- Lazy initialization
- Singleton pattern

**Remember:**

- Static provides class-level (not instance-level) scope
- Separate declaration from initialization
- Use private static to encapsulate class internals
- Static is powerful but can hide dependencies—use carefully
