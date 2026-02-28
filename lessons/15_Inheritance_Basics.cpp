//============================================================================
// Lesson 15: Inheritance - Object-Oriented Programming Fundamentals
// Author      : M'Barek Benraiss
// Description : Comprehensive guide to C++ inheritance, code reuse,
//               and creating class hierarchies
//============================================================================

#include <iostream>
#include <string>
using namespace std;

// ============================================================================
// SECTION 1: Basic Inheritance Parent and Child Classes
// ============================================================================

class Animal
{
protected: // Protected: accessible in derived classes
    string name;
    int age;

public:
    Animal() : age(0)
    {
        cout << "Animal constructor called" << endl;
    }

    Animal(string n, int a) : name(n), age(a)
    {
        cout << "Animal parameterized constructor: " << name << endl;
    }

    void setName(string n)
    {
        name = n;
    }

    void speak() const
    {
        cout << name << " makes a sound" << endl;
    }

    void showInfo() const
    {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

class Dog : public Animal
{ // Inherits from Animal
public:
    Dog()
    {
        cout << "Dog constructor called" << endl;
    }

    Dog(string n, int a) : Animal(n, a)
    { // Call parent constructor
        cout << "Dog parameterized constructor" << endl;
    }

    void bark()
    {
        cout << name << " barks: Woof! Woof!" << endl;
    }

    void speak() const
    { // Override parent's speak()
        cout << name << " barks: WOOF WOOF!" << endl;
    }
};

void demonstrateBasicInheritance()
{
    cout << "\n--- Basic Inheritance ---" << endl;

    Dog dog("Buddy", 3);
    dog.speak();    // Calls Dog's speak()
    dog.bark();     // Dog-specific method
    dog.showInfo(); // Inherited from Animal
}

// ============================================================================
// SECTION 2: Multi-Level Inheritance
// ============================================================================

class Cat : public Animal
{
public:
    Cat(string n) : Animal(n, 2) {}

    void meow()
    {
        cout << name << " meows: Meow!" << endl;
    }

    void speak() const
    {
        cout << name << " meows softly" << endl;
    }
};

class Tiger : public Cat
{ // Inherits from Cat, which inherits from Animal
public:
    Tiger(string n) : Cat(n) {}

    void roar()
    {
        cout << name << " roars: ROOOOAR!" << endl;
    }

    void speak() const
    { // Override speak() again
        cout << name << " roars powerfully" << endl;
    }
};

void demonstrateMultiLevelInheritance()
{
    cout << "\n--- Multi-Level Inheritance ---" << endl;

    Tiger tiger("Shere Khan");
    tiger.speak();    // Tiger's speak()
    tiger.roar();     // Tiger-specific
    tiger.meow();     // Inherited from Cat
    tiger.showInfo(); // Inherited from Animal (grandparent)
}

// ============================================================================
// SECTION 3: Protected Members and Access Control
// ============================================================================

class Vehicle
{
private:
    int serialNumber; // Not accessible in derived classes

protected:
    string model; // Accessible in derived classes
    int year;

public:
    Vehicle(string m, int y) : model(m), year(y), serialNumber(0) {}

    void showModel()
    {
        cout << "Model: " << model << endl;
    }
};

class Car : public Vehicle
{
public:
    Car(string m, int y) : Vehicle(m, y) {}

    void carInfo()
    {
        cout << "Car: " << model << ", Year: " << year << endl;
        // cout << serialNumber;  // ERROR: private in parent
    }
};

void demonstrateAccessControl()
{
    cout << "\n--- Protected Members and Access Control ---" << endl;

    Car car("Toyota Camry", 2023);
    car.showModel(); // Public method
    car.carInfo();   // Can access protected members from derived class
}

// ============================================================================
// SECTION 4: Constructor and Destructor Chain
// ============================================================================

class Base
{
private:
    int baseValue;

public:
    Base() : baseValue(10)
    {
        cout << "Base default constructor" << endl;
    }

    Base(int val) : baseValue(val)
    {
        cout << "Base parameterized constructor: " << val << endl;
    }

    ~Base()
    {
        cout << "Base destructor" << endl;
    }

    void showBase()
    {
        cout << "Base value: " << baseValue << endl;
    }
};

class Derived : public Base
{
private:
    int derivedValue;

public:
    Derived() : Base(), derivedValue(20)
    {
        cout << "Derived default constructor" << endl;
    }

    Derived(int b, int d) : Base(b), derivedValue(d)
    {
        cout << "Derived parameterized constructor" << endl;
    }

    ~Derived()
    {
        cout << "Derived destructor" << endl;
    }

    void showDerived()
    {
        cout << "Derived value: " << derivedValue << endl;
    }
};

void demonstrateConstructorChain()
{
    cout << "\n--- Constructor and Destructor Chain ---" << endl;

    cout << "Creating Derived object:" << endl;
    Derived d(100, 200);
    d.showBase();
    d.showDerived();

    cout << "Destructor called when object goes out of scope:" << endl;
}

// ============================================================================
// SECTION 5: Method Overriding and Polymorphic Behavior
// ============================================================================

class Shape
{
protected:
    string shapeName;

public:
    Shape(string name) : shapeName(name) {}

    // Virtual function - can be overridden
    virtual void calculateArea() const
    {
        cout << shapeName << ": Base area calculation (not implemented)" << endl;
    }

    virtual void display() const
    {
        cout << "Shape: " << shapeName << endl;
    }

    virtual ~Shape() {} // Virtual destructor
};

class Circle : public Shape
{
private:
    double radius;

public:
    Circle(double r) : Shape("Circle"), radius(r) {}

    void calculateArea() const override
    { // Override keyword (C++11)
        cout << "Circle area: " << 3.14159 * radius * radius << endl;
    }
};

class Rectangle : public Shape
{
private:
    double length, width;

public:
    Rectangle(double l, double w) : Shape("Rectangle"), length(l), width(w) {}

    void calculateArea() const override
    {
        cout << "Rectangle area: " << length * width << endl;
    }
};

void demonstratePolymorphism()
{
    cout << "\n--- Method Overriding and Polymorphism ---" << endl;

    Circle circle(5);
    Rectangle rect(4, 6);

    circle.calculateArea();
    rect.calculateArea();

    // Pointers to base class can point to derived objects
    Shape *shapes[2] = {&circle, &rect};
    for (int i = 0; i < 2; i++)
    {
        shapes[i]->calculateArea();
    }
}

// ============================================================================
// SECTION 6: Is-A Relationship and Substitution Principle
// ============================================================================

class Employee
{
protected:
    string name;
    double salary;

public:
    Employee(string n, double s) : name(n), salary(s) {}

    virtual void work()
    {
        cout << name << " is working" << endl;
    }

    virtual double getSalary() const
    {
        return salary;
    }

    virtual ~Employee() {}
};

class Manager : public Employee
{
private:
    int teamSize;

public:
    Manager(string n, double s, int t) : Employee(n, s), teamSize(t) {}

    void work() override
    {
        cout << name << " is managing a team of " << teamSize << endl;
    }

    void conductMeeting()
    {
        cout << name << " conducting team meeting" << endl;
    }
};

class Developer : public Employee
{
private:
    string language;

public:
    Developer(string n, double s, string l) : Employee(n, s), language(l) {}

    void work() override
    {
        cout << name << " is coding in " << language << endl;
    }

    void debug()
    {
        cout << name << " debugging code" << endl;
    }
};

void demonstrateIsARelationship()
{
    cout << "\n--- Is-A Relationship and Polymorphism ---" << endl;

    Manager manager("Alice", 100000, 5);
    Developer dev("Bob", 90000, "C++");

    // Both are Employees, so can be treated as such
    Employee *employees[2] = {&manager, &dev};

    for (int i = 0; i < 2; i++)
    {
        employees[i]->work();
    }

    // But can still call derived-specific methods
    manager.conductMeeting();
    dev.debug();
}

// ============================================================================
// SECTION 7: Inheritance Types - Public, Protected, Private
// ============================================================================

class Base2
{
public:
    int publicData = 1;

protected:
    int protectedData = 2;

private:
    int privateData = 3;
};

class PublicDerived : public Base2
{
    // publicData: public (can access from outside)
    // protectedData: protected (only in derived classes)
    // privateData: not accessible
};

class ProtectedDerived : protected Base2
{
    // publicData: protected (limited access)
    // protectedData: protected
    // privateData: not accessible
};

class PrivateDerived : private Base2
{
    // publicData: private (not accessible from outside)
    // protectedData: private
    // privateData: not accessible
};

void demonstrateInheritanceTypes()
{
    cout << "\n--- Different Inheritance Types ---" << endl;

    PublicDerived pub;
    pub.publicData = 10; // OK with public inheritance

    // ProtectedDerived prot;
    // prot.publicData = 20;  // ERROR: protected inheritance makes it protected

    // PrivateDerived priv;
    // priv.publicData = 30;  // ERROR: private inheritance makes it private

    cout << "Public inheritance allows public base members to remain public" << endl;
}

// ============================================================================
// SECTION 8: The "super" Pattern and Parent Access
// ============================================================================

class Parent
{
public:
    virtual void work()
    {
        cout << "Parent working" << endl;
    }

    void describe()
    {
        cout << "I am a parent class" << endl;
    }
};

class Child : public Parent
{
public:
    void work() override
    {
        cout << "Child working" << endl;
        // In C++, there's no "super" keyword, but can explicitly call parent
        Parent::work(); // Call parent's version
    }

    void describe()
    {
        cout << "I am a child class" << endl;
        Parent::describe(); // Call parent's method
    }
};

void demonstrateParentAccess()
{
    cout << "\n--- Calling Parent Methods ---" << endl;

    Child child;
    child.work();     // Calls child, which calls parent
    child.describe(); // Demonstrates explicit parent method access
}

// ============================================================================
// MAIN: Run all demonstrations
// ============================================================================

int main()
{
    cout << "========== C++ Inheritance Fundamentals ==========" << endl;

    demonstrateBasicInheritance();
    demonstrateMultiLevelInheritance();
    demonstrateAccessControl();
    demonstrateConstructorChain();
    demonstratePolymorphism();
    demonstrateIsARelationship();
    demonstrateInheritanceTypes();
    demonstrateParentAccess();

    cout << "\n========== End of Inheritance Demonstrations ==========" << endl;

    return 0;
}

/*
/Users/benraiss/CLionProjects/learnCpp/cmake-build-debug/learnCpp
========== C++ Inheritance Fundamentals ==========

--- Basic Inheritance ---
Animal parameterized constructor: Buddy
Dog parameterized constructor
Buddy barks: WOOF WOOF!
Buddy barks: Woof! Woof!
Name: Buddy, Age: 3

--- Multi-Level Inheritance ---
Animal parameterized constructor: Shere Khan
Shere Khan roars powerfully
Shere Khan roars: ROOOOAR!
Shere Khan meows: Meow!
Name: Shere Khan, Age: 2

--- Protected Members and Access Control ---
Model: Toyota Camry
Car: Toyota Camry, Year: 2023

--- Constructor and Destructor Chain ---
Creating Derived object:
Base parameterized constructor: 100
Derived parameterized constructor
Base value: 100
Derived value: 200
Destructor called when object goes out of scope:
Derived destructor
Base destructor

--- Method Overriding and Polymorphism ---
Circle area: 78.5397
Rectangle area: 24
Circle area: 78.5397
Rectangle area: 24

--- Is-A Relationship and Polymorphism ---
Alice is managing a team of 5
Bob is coding in C++
Alice conducting team meeting
Bob debugging code

--- Different Inheritance Types ---
Public inheritance allows public base members to remain public

--- Calling Parent Methods ---
Child working
Parent working
I am a child class
I am a parent class

========== End of Inheritance Demonstrations ==========

Process finished with exit code 0

*/
