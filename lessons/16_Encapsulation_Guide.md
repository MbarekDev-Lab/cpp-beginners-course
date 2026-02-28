# Lesson 16: Encapsulation - Information Hiding and Access Control

## Overview

Encapsulation is one of the fundamental principles of object-oriented programming. It involves bundling data (attributes) and methods (functions) that operate on that data within a single unit (class), while hiding the internal details from the outside world. Encapsulation protects data integrity and provides controlled access to an object's internal state.

## Core Concepts

### What is Encapsulation?

Encapsulation is the practice of hiding the internal details of an object and exposing only what's necessary through a well-defined public interface. It combines data and behavior into a cohesive unit while controlling access to that data.

```cpp
class BankAccount {
private:            // Data hidden
    double balance;

public:             // Controlled access
    void deposit(double amount) {
        balance += amount;  // Business logic validates
    }
};
```

### Why Use Encapsulation?

1. **Data Protection**: Prevent invalid states (negative balance, invalid age)
2. **Control Access**: Data changes only through validated methods
3. **Implementation Flexibility**: Change internals without affecting external code
4. **Maintainability**: Easier to debug and modify when interfaces are clear
5. **Security**: Hide sensitive implementation details

## Access Levels: public, private, protected

C++ provides three access specifiers to control visibility:

| Level         | Inside Class | Derived Classes | Outside Code |
| ------------- | ------------ | --------------- | ------------ |
| **public**    | Yes          | Yes             | Yes          |
| **private**   | Yes          | No              | No           |
| **protected** | Yes          | Yes             | No           |

### Private

Private members are accessible only within the class. They are completely hidden from outside code and even derived classes.

```cpp
class Account {
private:
    double balance;    // Can only be accessed within Account
};

Account acc;
// acc.balance = 100;  // ERROR: can't access private member
```

**Use private for**:

- Internal data that should never be accessed directly
- Helper methods only used internally
- Implementation details

### Public

Public members are accessible from anywhere - inside the class, in derived classes, and from outside code.

```cpp
class Account {
public:
    void deposit(double amount) { }  // Accessible everywhere
};

Account acc;
acc.deposit(100);  // OK
```

**Use public for**:

- Methods that form the object's interface
- Data that's safe to modify directly (rarely)

### Protected

Protected members are accessible within the class and in derived classes, but not from outside code. They're useful for inheritance hierarchies.

```cpp
class Animal {
protected:
    int age;  // Accessible in derived classes
};

class Dog : public Animal {
public:
    void setAge(int a) {
        age = a;  // OK in derived class
    }
};

Dog dog;
// dog.age = 5;  // ERROR: can't access protected member
```

**Use protected for**:

- Data that derived classes need to access
- Helper methods for derived classes

## Getters and Setters

### Getter Methods

A getter (accessor) is a public method that returns the value of a private member. It provides read-only access.

```cpp
class Car {
private:
    int speed;

public:
    int getSpeed() const {  // const: won't modify state
        return speed;
    }
};

Car car;
int currentSpeed = car.getSpeed();  // Read the value
// car.getSpeed() = 100;  // ERROR: can't assign to function return
```

**Getter best practices**:

- Mark as `const`: `int getSpeed() const { }`
- Return by value for primitives: `int getSpeed()`
- Return by const reference for objects: `const string& getName() const`
- Keep names consistent: `getName()`, `getValue()`, etc.

### Setter Methods

A setter (mutator) is a public method that changes the value of a private member. It allows controlled write access.

```cpp
class Temperature {
private:
    double celsius;

public:
    void setCelsius(double c) {
        if (c >= -273.15) {  // Validate before setting
            celsius = c;
        } else {
            cout << "Invalid temperature" << endl;
        }
    }
};

Temperature temp;
temp.setCelsius(-300);  // Invalid - rejected by validation
```

**Setter best practices**:

- Always validate input before accepting
- Return `bool` to indicate success/failure
- Or use exception handling for invalid data
- Keep names consistent with getters

### Typical Getter/Setter Pattern

```cpp
class Student {
private:
    double gpa;

public:
    // Getter
    double getGPA() const {
        return gpa;
    }

    // Setter with validation
    bool setGPA(double g) {
        if (g >= 0.0 && g <= 4.0) {
            gpa = g;
            return true;
        }
        return false;
    }
};

Student student;
if (student.setGPA(3.5)) {
    cout << "GPA updated: " << student.getGPA() << endl;
}
```

## Input Validation

A key purpose of setters is input validation - ensuring data is always in a valid state.

```cpp
class BankAccount {
private:
    double balance;

public:
    bool withdraw(double amount) {
        // Validate: positive amount and sufficient balance
        if (amount <= 0) return false;
        if (amount > balance) return false;

        balance -= amount;
        return true;
    }

    bool deposit(double amount) {
        // Validate: positive amount
        if (amount <= 0) return false;

        balance += amount;
        return true;
    }
};
```

### Common Validation Patterns

| Data Type   | Validation          | Example                           |
| ----------- | ------------------- | --------------------------------- |
| Age         | 0 < age < 150       | `if (age > 0 && age < 150)`       |
| Email       | Contains @ and .    | `if (email.find('@') != npos)`    |
| Percentage  | 0 ≤ value ≤ 100     | `if (value >= 0 && value <= 100)` |
| Name        | Not empty           | `if (!name.empty())`              |
| Temperature | Above absolute zero | `if (celsius >= -273.15)`         |

## Read-Only Properties

A read-only property is a member with a getter but no setter. This prevents external modification while allowing reading.

```cpp
class Book {
private:
    string title;           // Read-only
    string author;          // Read-only
    int currentPage;        // Readable and writable

public:
    string getTitle() const { return title; }
    string getAuthor() const { return author; }

    int getCurrentPage() const { return currentPage; }
    void setCurrentPage(int page) { currentPage = page; }

    // No setter for title and author - they can't be changed
};
```

## Const Correctness

Always mark getter methods as `const`. This promises that calling the method won't modify the object's state.

```cpp
class Rectangle {
private:
    double width, height;

public:
    // Const methods - promise not to modify state
    double getWidth() const { return width; }
    double getArea() const { return width * height; }

    // Mutable method - can modify state
    void setDimensions(double w, double h) { width = w; height = h; }
};

const Rectangle rect(5, 10);
cout << rect.getWidth();      // OK - const method
cout << rect.getArea();       // OK - const method
// rect.setDimensions(6, 11);  // ERROR - can't call mutable method on const object
```

## Private Methods (Helper Methods)

Not all methods need to be public. Private methods are internal helpers that support public methods.

```cpp
class Password {
private:
    string encrypted;

    // Private helper method
    bool isStrongPassword(const string& pwd) {
        return pwd.length() >= 8;
    }

    string encryptPassword(const string& pwd) {
        // Complex encryption logic
        return pwd;  // Simplified
    }

public:
    bool setPassword(const string& newPwd) {
        if (isStrongPassword(newPwd)) {
            encrypted = encryptPassword(newPwd);
            return true;
        }
        return false;
    }
};

Password pwd;
pwd.setPassword("secure123");
// pwd.isStrongPassword("test");  // ERROR: private, can't call
```

## Practical Patterns

### Pattern 1: Simple value wrapper

```cpp
class IntProperty {
private:
    int value;

public:
    IntProperty(int v = 0) : value(v) { }

    int get() const { return value; }
    void set(int v) { value = v; }
};
```

### Pattern 2: Value with constraints

```cpp
class Percentage {
private:
    int value;

public:
    bool set(int v) {
        if (v >= 0 && v <= 100) {
            value = v;
            return true;
        }
        return false;
    }

    int get() const { return value; }
};
```

### Pattern 3: Computed property

```cpp
class Circle {
private:
    double radius;

public:
    double getRadius() const { return radius; }
    void setRadius(double r) { radius = r; }

    // Computed property - calculated on demand
    double getArea() const { return 3.14159 * radius * radius; }
};
```

## Best Practices

1. **Make All Data Private**

   ```cpp
   class Good {
   private:
       double balance;      // Always private
   public:
       double getBalance() const { }
   };
   ```

2. **Public Interface, Private Implementation**

   ```cpp
   class BankAccount {
   public:
       void deposit(double amount);   // What to do
   private:
       void updateLedger();           // How to do it
       double balance;
   };
   ```

3. **Validate in Setters**

   ```cpp
   void setAge(int a) {
       if (a > 0 && a < 150) {
           age = a;
       }
   }
   ```

4. **Use const Correctly**

   ```cpp
   double getBalance() const { }  // Promise: won't modify state
   ```

5. **Return by const reference for objects**

   ```cpp
   const string& getName() const { return name; }
   ```

6. **Clear naming conventions**
   ```cpp
   getData()          // Not get_data()
   setData()          // Not set_data()
   isValid() or is Valid()   // For boolean getters
   ```

## Common Mistakes to Avoid

### Mistake 1: Unnecessary Getters/Setters

```cpp
// BAD: Every getter/setter for public data is unnecessary
class Point {
private:
    int x, y;
public:
    int getX() const { return x; }
    void setX(int val) { x = val; }  // No validation?
    int getY() const { return y; }
    void setY(int val) { y = val; }
};

// BETTER: If no validation, just make it public or use simpler approach
class Point {
public:
    int x, y;  // Simple data - public is fine
};
```

### Mistake 2: No Validation in Setters

```cpp
// BAD: Setter without validation
void setAge(int a) {
    age = a;  // What if a is -5?
}

// GOOD: Validate
void setAge(int a) {
    if (a > 0 && a < 150) {
        age = a;
    }
}
```

### Mistake 3: Const Correctness Issues

```cpp
// BAD: Getter not const
double getBalance() {  // Can modify state!
    balance = 0;       // Oops
    return balance;
}

// GOOD: Mark as const
double getBalance() const {  // Can't modify state
    return balance;
}
```

### Mistake 4: Exposing Implementation Details

```cpp
// BAD: Users learn about internal vector
vector<int> getData() { return data; }

// BETTER: Hide implementation
int getElement(int index) const { return data[index]; }
int getSize() const { return data.size(); }
```

## Encapsulation and Inheritance

Encapsulation works together with inheritance:

```cpp
class Animal {
protected:         // Accessible in derived classes
    string name;
private:          // Hidden from derived classes
    int id;
public:
    string getName() const { return name; }
};

class Dog : public Animal {
public:
    void setName(string n) {
        name = n;  // OK - protected member
    }
};
```

## Modern C++ Considerations

### C++11 and Later

In modern C++, you might use property-like behavior with getters/setters, but the language doesn't have true properties like C# or Python.

```cpp
class Value {
private:
    int val;
public:
    int getValue() const { return val; }
    void setValue(int v) { val = v; }
};

// Usage
Value v;
v.setValue(10);
cout << v.getValue();  // Not v.value or v.value = 10
```

## Summary

- **Encapsulation** hides implementation details and provides controlled access
- **Access levels**: `private` (hidden), `public` (exposed), `protected` (for inheritance)
- **Getters** provide read-only access to private data
- **Setters** provide controlled write access with validation
- **Const correctness** ensures getters don't modify state
- **Read-only properties** have getters but no setters
- **Private methods** support public methods and hide implementation
- **Validation** ensures data stays in valid states
- **Best practice**: Make all data private, expose through public methods

Encapsulation is essential for writing robust, maintainable object-oriented code. It protects data integrity and makes classes safer and easier to use correctly.
