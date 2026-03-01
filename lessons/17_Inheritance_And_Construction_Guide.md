# Lesson 17: Inheritance and Construction - Constructor Chaining

## Overview

When inheritance is involved, constructors become more complex. A derived class object must construct not only its own members but also the base class members. This lesson explores how constructors work in inheritance hierarchies, constructor chaining, initialization order, and the relationship between parent and child constructors.

## Core Concepts

### Constructor Execution in Inheritance

When a derived class object is created, constructors execute in a specific order:

1. **Base class constructor executes first** - Initializes parent members
2. **Derived class constructor executes second** - Initializes child members

```cpp
class Animal {
public:
    Animal() { cout << "Animal constructor" << endl; }
};

class Dog : public Animal {
public:
    Dog() { cout << "Dog constructor" << endl; }
};

Dog d;
// Output:
// Animal constructor  (runs first)
// Dog constructor     (runs second)
```

### Destructor Execution

Destructors execute in **reverse order** (derived first, base last):

```cpp
// Continuing from above example:
// When d goes out of scope:
// Dog destructor      (runs first)
// Animal destructor   (runs second)
```

## Calling Parent Constructors

### Initializer List Syntax

The derived class must explicitly call the parent constructor using the initializer list:

```cpp
class Animal {
protected:
    string name;

public:
    Animal(string n) : name(n) { }
};

class Dog : public Animal {
public:
    // Must call parent constructor
    Dog(string n) : Animal(n) {  // Pass to parent
        // Dog-specific initialization
    }
};

Dog dog("Buddy");
```

### Parent Constructor Without Arguments

```cpp
class Base {
public:
    Base() { cout << "Base" << endl; }
};

class Derived : public Base {
public:
    Derived() : Base() {  // Explicitly call
        cout << "Derived" << endl;
    }
};
```

### Parent Constructor With Arguments

```cpp
class Employee {
protected:
    string name;
    double salary;

public:
    Employee(string n, double s) : name(n), salary(s) { }
};

class Manager : public Employee {
public:
    Manager(string n, double s) : Employee(n, s) {  // Pass parameters
        // Manager-specific code
    }
};

Manager m("Alice", 100000);
```

## Multi-Level Inheritance Constructor Chain

With multiple inheritance levels, each level must properly initialize its parent:

```cpp
class Vehicle {
protected:
    string model;

public:
    Vehicle(string m) : model(m) {
        cout << "Vehicle: " << model << endl;
    }
};

class Car : public Vehicle {
protected:
    int doors;

public:
    Car(string m, int d) : Vehicle(m), doors(d) {
        cout << "Car: " << doors << " doors" << endl;
    }
};

class SportsCar : public Car {
private:
    int topSpeed;

public:
    SportsCar(string m, int d, int s) : Car(m, d), topSpeed(s) {
        cout << "SportsCar: " << s << " mph" << endl;
    }
};

SportsCar sc("Ferrari", 2, 200);
// Output:
// Vehicle: Ferrari
// Car: 2 doors
// SportsCar: 200 mph
```

## Constructor Initialization Order

Members are initialized in **declaration order**, not in the order they appear in the initializer list:

```cpp
class Example {
private:
    int a, b, c;

public:
    // Initialization order: a, then b, then c (declaration order)
    // NOT c, b, a (initializer list order)
    Example(int x, int y, int z) : c(z), b(y), a(x) {
        cout << "Order: a=" << a << ", b=" << b << ", c=" << c << endl;
    }
};
```

**Best practice**: Order initializer list members the same way they're declared.

## Default Parameters in Constructors

Parent constructors can have default parameters:

```cpp
class Shape {
protected:
    string color;

public:
    Shape(string c = "Red") : color(c) { }
};

class Circle : public Shape {
private:
    double radius;

public:
    // Can use parent's default
    Circle() : Shape() { }

    // Can override parent's default
    Circle(double r) : Shape("Blue"), radius(r) { }

    // Can pass custom value
    Circle(double r, string c) : Shape(c), radius(r) { }
};

Circle c1;              // color = "Red" (parent default)
Circle c2(5);           // color = "Blue" (overridden default)
Circle c3(5, "Green");  // color = "Green" (explicit)
```

## Copy Constructors in Inheritance

Derived classes should define copy constructors that also copy the parent part:

```cpp
class Product {
protected:
    string name;

public:
    Product(string n) : name(n) { }

    Product(const Product& other) : name(other.name) { }
};

class Book : public Product {
private:
    string author;

public:
    Book(string n, string a) : Product(n), author(a) { }

    // Copy constructor must copy both parent and derived
    Book(const Book& other) : Product(other), author(other.author) { }
};

Book b1("1984", "Orwell");
Book b2 = b1;  // Calls copy constructor
```

## Comparison: Direct Member Initialization vs Constructor

| Approach            | Usage                            | Advantage                             |
| ------------------- | -------------------------------- | ------------------------------------- |
| `Parent()` call     | `Derived() : Parent() { }`       | Calls parent constructor normally     |
| Default parent      | Omit `: Parent()`                | If parent has default or no parameter |
| Explicit parameters | `Derived(int x) : Parent(x) { }` | Pass specific values to parent        |

## Real-World Pattern: Employee Hierarchy

```cpp
class Person {
protected:
    string name;
    int age;

public:
    Person(string n, int a) : name(n), age(a) {
        cout << "Person: " << name << endl;
    }
};

class Employee : public Person {
protected:
    string employeeID;

public:
    Employee(string n, int a, string id)
        : Person(n, a), employeeID(id) {
        cout << "Employee ID: " << employeeID << endl;
    }
};

class Manager : public Employee {
private:
    int teamSize;

public:
    Manager(string n, int a, string id, int t)
        : Employee(n, a, id), teamSize(t) {
        cout << "Manager with team size: " << teamSize << endl;
    }
};

Manager mgr("Alice", 40, "E001", 5);
// Output:
// Person: Alice
// Employee ID: E001
// Manager with team size: 5
```

## Constructor Delegation (C++11)

Modern C++ allows constructors to delegate to other constructors in the same class:

```cpp
class Point {
private:
    int x, y;

public:
    // Default delegates to parameterized
    Point() : Point(0, 0) { }

    // Parameterized constructor
    Point(int a, int b) : x(a), y(b) { }
};

Point p1;        // Calls Point(0, 0)
Point p2(5, 5);  // Calls Point(int, int)
```

This reduces code duplication when multiple constructors share initialization logic.

## Virtual Destructors in Inheritance

**Always make destructors virtual in base classes** that will be inherited:

```cpp
class Resource {
public:
    virtual ~Resource() {  // Virtual!
        cout << "Resource destructor" << endl;
    }
};

class SpecialResource : public Resource {
public:
    ~SpecialResource() {
        cout << "SpecialResource destructor" << endl;
    }
};

Resource* ptr = new SpecialResource();
delete ptr;
// Output:
// SpecialResource destructor
// Resource destructor
```

**Without virtual:**

```cpp
delete ptr;
// Output:
// Resource destructor    (WRONG! SpecialResource not cleaned up)
```

## Best Practices

1. **Always explicitly call parent constructors**

   ```cpp
   Derived::Derived() : Base() { }
   ```

2. **Mark destructors virtual in base classes**

   ```cpp
   class Base {
   public:
       virtual ~Base() { }
   };
   ```

3. **Use initializer list for parent calls**

   ```cpp
   Derived(int x) : Base(x) { }  // Not Base(x) in function body
   ```

4. **Order initializer list by declaration order**

   ```cpp
   class C {
   private:
       int a, b;
   public:
       C(int x, int y) : a(x), b(y) { }  // Match declaration order
   };
   ```

5. **Define copy constructors for derived classes**

   ```cpp
   Derived::Derived(const Derived& other)
       : Base(other), memberVar(other.memberVar) { }
   ```

6. **Use constructor delegation to avoid duplication (C++11+)**
   ```cpp
   Class() : Class(defaultValue) { }  // Delegates
   ```

## Common Mistakes to Avoid

### Mistake 1: Forgetting to Call Parent Constructor

```cpp
// BAD: parent constructor not called
class Dog : public Animal {
public:
    Dog(string n) {  // Animal not initialized!
        name = n;    // ERROR: name is parent's private member
    }
};

// GOOD: call parent constructor
class Dog : public Animal {
public:
    Dog(string n) : Animal(n) { }
};
```

### Mistake 2: Initializing Parent Members Directly

```cpp
class Animal {
private:
    string name;
};

class Dog : public Animal {
public:
    Dog(string n) : name(n) { }  // ERROR: can't initialize parent's private member
};

// GOOD: call parent constructor
class Dog : public Animal {
public:
    Dog(string n) : Animal(n) { }
};
```

### Mistake 3: Non-Virtual Destructor in Base Class

```cpp
// BAD: destructor not virtual
class Base {
public:
    ~Base() { }  // Potential memory leak
};

class Derived : public Base {
private:
    int* data;
public:
    Derived() { data = new int[100]; }
    ~Derived() { delete[] data; }  // Won't be called!
};

Base* ptr = new Derived();
delete ptr;  // Only Base destructor called!

// GOOD: virtual destructor
class Base {
public:
    virtual ~Base() { }
};
```

### Mistake 4: Initializer List Order Mismatch

```cpp
// BAD: initializer order differs from declaration order
class Bad {
private:
    int x, y;
public:
    Bad(int a, int b) : y(b), x(a) { }  // Order matters!
};

// GOOD: match declaration order
class Good {
private:
    int x, y;
public:
    Good(int a, int b) : x(a), y(b) { }  // Matches declaration
};
```

## Modern C++ Features

### C++11: In-Class Initialization + Constructors

```cpp
class Modern {
private:
    int x = 10;     // Default value
    string name;

public:
    Modern() { }                          // x = 10 (default)
    Modern(string n) : name(n) { }        // x = 10, name = n
};
```

### C++11: Constructor Delegation

```cpp
class Delegating {
public:
    Delegating() : Delegating(0) { }              // Delegates
    Delegating(int x) { }
};
```

## Summary

- **Constructor order**: Parent constructor runs first, then derived
- **Destructor order**: Reverse - derived destructor runs first
- **Parent calls**: Use initializer list `: Base(args)`
- **Multi-level**: Each level initializes its parent
- **Initialization order**: Members initialized in declaration order, not initializer list order
- **Copy constructors**: Must call parent copy constructor
- **Virtual destructors**: Essential in inheritance hierarchies
- **Constructor delegation**: C++11 feature to reduce code duplication

Proper constructor handling in inheritance is critical for correct object initialization and cleanup. Understanding these concepts ensures robust, maintainable class hierarchies.
