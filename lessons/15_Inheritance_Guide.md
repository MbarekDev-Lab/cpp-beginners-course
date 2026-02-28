# Lesson 15: Inheritance - Object-Oriented Programming Fundamentals

## Overview

Inheritance is one of the core pillars of object-oriented programming. It allows you to create new classes based on existing classes, enabling code reuse and establishing a hierarchical relationship between classes. Inheritance represents an "is-a" relationship: a Dog "is-a" Animal, an Employee "is-an" Animal, etc.

## Core Concepts

### What is Inheritance?

Inheritance is a mechanism to derive a new class from an existing class. The new class (derived or child class) inherits attributes and methods from the existing class (base or parent class).

```cpp
class Animal {          // Base class
public:
    void speak() { cout << "Generic sound" << endl; }
};

class Dog : public Animal {  // Derived class inherits from Animal
public:
    void bark() { cout << "Woof!" << endl; }
};
```

### Why Use Inheritance?

1. **Code Reuse**: Don't repeat common functionality in multiple classes
2. **Logical Hierarchy**: Represent real-world relationships between concepts
3. **Polymorphism**: Treat derived objects as base objects for flexible code
4. **Maintainability**: Changes to shared functionality are made in one place

## Basic Inheritance Syntax

### Declaring a Derived Class

```cpp
class DerivedClass : public BaseClass {
    // New and overridden methods
    // New member variables
};
```

The `: public` indicates **public inheritance** (most common).

### Example

```cpp
class Animal {
public:
    void speak() { cout << "Sound" << endl; }
};

class Cat : public Animal {  // Cat inherits from Animal
public:
    void meow() { cout << "Meow" << endl; }
};

Cat cat;
cat.speak();  // Inherited method
cat.meow();   // Cat-specific method
```

## Inheritance Types

| Type          | Base Public Members | Base Protected Members | Base Private Members |
| ------------- | ------------------- | ---------------------- | -------------------- |
| **public**    | Remain public       | Remain protected       | Not accessible       |
| **protected** | Become protected    | Remain protected       | Not accessible       |
| **private**   | Become private      | Become private         | Not accessible       |

### Public Inheritance (Most Common)

```cpp
class Derived : public Base {
    // Base's public is public in Derived
    // Base's protected is protected in Derived
};

Derived d;
d.publicMember = 5;  // OK
```

### Protected Inheritance

```cpp
class Derived : protected Base {
    // Base's public becomes protected
};

Derived d;
d.publicMember = 5;  // ERROR: now protected
```

### Private Inheritance

```cpp
class Derived : private Base {
    // All base members become private
};

Derived d;
d.publicMember = 5;  // ERROR: now private
```

## Access Levels: public, protected, private

Three levels of access control in inheritance:

| Level         | Access from Member Functions | Access from Derived Classes | Access from Outside |
| ------------- | ---------------------------- | --------------------------- | ------------------- |
| **public**    | Yes                          | Yes                         | Yes                 |
| **protected** | Yes                          | Yes                         | No                  |
| **private**   | Yes                          | No                          | No                  |

### Example

```cpp
class Base {
public:
    int publicVar = 1;     // Accessible everywhere
protected:
    int protectedVar = 2;  // Accessible in derived classes
private:
    int privateVar = 3;    // Only in Base
};

class Derived : public Base {
    void show() {
        cout << publicVar << endl;      // OK
        cout << protectedVar << endl;   // OK
        // cout << privateVar << endl;  // ERROR
    }
};
```

## Constructor and Destructor in Inheritance

### Constructor Execution Order

When a derived object is created:

1. Base class constructor executes first
2. Derived class constructor executes second

```cpp
class Base {
public:
    Base() { cout << "Base constructor" << endl; }
};

class Derived : public Base {
public:
    Derived() { cout << "Derived constructor" << endl; }
};

Derived d;
// Output:
// Base constructor
// Derived constructor
```

### Calling Parent Constructor Explicitly

```cpp
class Animal {
public:
    Animal(string name) : name(name) { }
};

class Dog : public Animal {
public:
    Dog(string name) : Animal(name) {  // Call parent constructor
        cout << "Dog created" << endl;
    }
};
```

### Destructor Execution Order

Destructors execute in reverse order (derived first, then base):

```cpp
class Base {
public:
    ~Base() { cout << "Base destructor" << endl; }
};

class Derived : public Base {
public:
    ~Derived() { cout << "Derived destructor" << endl; }
};

Derived d;
// When d goes out of scope:
// Derived destructor
// Base destructor
```

## Multi-Level Inheritance

Classes can form inheritance chains:

```cpp
class Animal { };              // Base
class Cat : public Animal { }; // Derived from Animal
class Tiger : public Cat { };  // Derived from Cat (and Animal)

Tiger tiger;
tiger.speak();    // From Animal
tiger.meow();     // From Cat
tiger.roar();     // Tiger-specific
```

**Important**: Tiger inherits from Cat, and Cat inherits from Animal, so Tiger has all features from both ancestors.

## Method Overriding

A derived class can provide a different implementation of a base class method:

```cpp
class Animal {
public:
    void speak() { cout << "Generic sound" << endl; }
};

class Dog : public Animal {
public:
    void speak() override {  // override keyword (C++11+)
        cout << "Woof!" << endl;
    }
};

Dog dog;
dog.speak();  // Calls Dog's version
```

## Virtual Functions and Polymorphism

Virtual functions enable true polymorphic behavior - the actual method called depends on the object's real type, not the pointer/reference type.

```cpp
class Shape {
public:
    virtual void draw() {  // Virtual function
        cout << "Drawing shape" << endl;
    }
};

class Circle : public Shape {
public:
    void draw() override {
        cout << "Drawing circle" << endl;
    }
};

Shape* shape = new Circle();  // Points to Circle
shape->draw();  // Calls Circle::draw(), not Shape::draw()
delete shape;
```

### Without Virtual (Static Dispatch)

```cpp
Shape* shape = new Circle();
shape->draw();  // Calls Shape::draw() (wrong!)
```

### With Virtual (Dynamic Dispatch)

```cpp
class Shape {
public:
    virtual void draw() { }  // Virtual keyword
};

Shape* shape = new Circle();
shape->draw();  // Calls Circle::draw() (correct!)
```

## Virtual Destructors

Always make destructors virtual in base classes that will be deleted polymorphically:

```cpp
class Base {
public:
    virtual ~Base() { }  // Virtual destructor
};

class Derived : public Base { };

Base* ptr = new Derived();
delete ptr;  // Calls both Derived and Base destructors correctly
```

## The "Is-A" Relationship

Inheritance models the "is-a" relationship:

- A Dog **is-an** Animal
- A Manager **is-an** Employee
- A Circle **is-a** Shape

This relationship allows substitution:

```cpp
void processAnimal(Animal* animal) {  // Accepts Animal or any derived class
    animal->speak();
}

Dog dog;
Cat cat;

processAnimal(&dog);  // Works!
processAnimal(&cat);  // Works!
```

## Practical Comparison: Inheritance vs. Composition

### Inheritance (Is-A)

```cpp
class Pet : public Animal {  // Pet IS-A Animal
};
```

### Composition (Has-A)

```cpp
class Pet {
    Animal animal;  // Pet HAS-A Animal (member variable)
};
```

Use inheritance for true "is-a" relationships. Use composition for "has-a" relationships.

## Real-World Organization Pattern

### Employee Hierarchy Example

```cpp
class Employee {              // Base class
    string name;
    double salary;
public:
    virtual void work() { }
};

class Manager : public Employee {      // Specific employee type
    int teamSize;
public:
    void work() override { }
    void conductMeeting() { }
};

class Developer : public Employee {    // Another employee type
    string language;
public:
    void work() override { }
    void debug() { }
};
```

## Best Practices

1. **Use Virtual for Polymorphism**

   ```cpp
   virtual void method() { }  // Enable dynamic dispatch
   ```

2. **Virtual Destructors for Base Classes**

   ```cpp
   class Base {
   public:
       virtual ~Base() { }  // Always virtual in base classes
   };
   ```

3. **Use override Keyword (C++11+)**

   ```cpp
   void method() override { }  // Explicit intent
   ```

4. **Prefer Shallow Inheritance Hierarchies**
   - Keep inheritance chains short (usually 2-3 levels max)
   - Deep hierarchies are harder to understand and maintain

5. **Consider Composition for Complex Relationships**

   ```cpp
   // Better than deep inheritance
   class Car {
       Engine engine;
       Transmission transmission;
   };
   ```

6. **Call Parent Methods When Needed**
   ```cpp
   void Child::work() {
       Parent::work();  // Explicitly call parent implementation
       // Additional child-specific work
   }
   ```

## Common Mistakes to Avoid

### Mistake 1: Forgetting Virtual Destructors

```cpp
class Base {
public:
    ~Base() { }  // ERROR: Not virtual!
};

Base* ptr = new Derived();
delete ptr;  // Derived destructor not called!
```

**Solution**: Always make destructors virtual in base classes.

### Mistake 2: Not Understanding Constructor Order

```cpp
Derived d;  // Constructor order: Base -> Derived (not Derived -> Base)
```

### Mistake 3: Ineffective Private Inheritance

```cpp
class Derived : private Base { };  // Usually not what you want
Derived d;
d.publicMethod();  // ERROR: now private
```

**Solution**: Use `public` inheritance unless you have a specific reason.

### Mistake 4: Hiding Non-Virtual Methods

```cpp
class Base {
public:
    void method() { }  // Not virtual
};

class Derived : public Base {
public:
    void method() { }  // Hides, doesn't override!
};

Base* ptr = new Derived();
ptr->method();  // Calls Base::method(), not Derived::method()!
```

**Solution**: Make methods virtual for true overriding.

## Modern C++ Considerations

### C++11 override and final Keywords

```cpp
class Shape {
public:
    virtual void draw() = 0;
};

class Circle : public Shape {
public:
    void draw() override { }    // Declares intent to override
    // If no draw() exists in Shape, compiler error!
};

class Final : public Circle {
    void draw() final { }       // No further overriding allowed
};
```

### Abstract Base Classes (Pure Virtual)

```cpp
class Animal {
public:
    virtual void speak() = 0;   // Pure virtual - must override
    virtual ~Animal() { }
};

// class Animal a;  // ERROR: can't instantiate abstract class
class Dog : public Animal {
    void speak() override { }   // Must provide implementation
};
```

## Summary

- **Inheritance** creates hierarchical relationships: derived classes inherit from base classes
- **Access levels**: public (remains), protected (limited), private (not inherited)
- **Constructors/Destructors**: Base executed first, destroyed last
- **Method overriding**: Derived classes can override base methods
- **Virtual functions**: Enable polymorphism - actual method depends on object type
- **Virtual destructors**: Essential for proper cleanup in polymorphic hierarchies
- **Is-a relationship**: Inheritance models true specialization relationships
- **Multi-level**: Inheritance chains possible but keep them shallow
- **Best practice**: Use virtual destructors, override keyword, shallow hierarchies

Inheritance is fundamental to object-oriented design and enables building flexible, maintainable class hierarchies.
