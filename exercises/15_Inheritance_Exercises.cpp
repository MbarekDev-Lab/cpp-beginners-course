//============================================================================
// Lesson 15: Inheritance - Exercises
// Author      : M'Barek Benraiss
// Description : Progressive exercises for understanding inheritance,
//               polymorphism, and class hierarchies
//============================================================================

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// ============================================================================
// EXERCISE 1: Basic Inheritance Parent and Child Classes
// ============================================================================
/*
EXERCISE 1: Create a simple inheritance hierarchy
- Create class "Vehicle" with drive() method
- Create class "Car" that inherits from Vehicle
- Car should have an additional honk() method
- In main, create a Car object and call both methods
- Verify parent method works in child class

Solution provided below
*/

class Vehicle
{
public:
    void drive() const
    {
        cout << "Vehicle is driving" << endl;
    }
};

class Car : public Vehicle
{
public:
    void honk() const
    {
        cout << "Car honks: HONK HONK!" << endl;
    }
};

void exercise1()
{
    cout << "\n--- Exercise 1: Basic Inheritance ---" << endl;
    Car car;
    car.drive(); // Inherited method
    car.honk();  // Car-specific method
    cout << "SUCCESS: Child class has parent methods" << endl;
}

// ============================================================================
// EXERCISE 2: Constructor Chaining in Inheritance
// ============================================================================
/*
EXERCISE 2: Use parent constructor from child class
- Create "Animal" class with name and age
- Constructor takes name and age parameters
- Create "Dog" class that inherits and passes parameters to parent
- Show constructor execution order

Solution provided below
*/

class Animal
{
protected:
    string name;
    int age;

public:
    Animal(string n, int a) : name(n), age(a)
    {
        cout << "Animal constructor: " << name << ", age " << age << endl;
    }
};

class Dog : public Animal
{
public:
    Dog(string n, int a) : Animal(n, a)
    {
        cout << "Dog constructor" << endl;
    }

    void bark()
    {
        cout << name << " barks!" << endl;
    }
};

void exercise2()
{
    cout << "\n--- Exercise 2: Constructor Chaining ---" << endl;
    Dog dog("Buddy", 3);
    dog.bark();
    cout << "SUCCESS: Constructors execute in order (parent first)" << endl;
}

// ============================================================================
// EXERCISE 3: Multiple Levels - Multi-Level Inheritance
// ============================================================================
/*
EXERCISE 3: Create inheritance chain with 3 levels
- Create "Animal" (base)
- Create "Mammal" inheriting from Animal
- Create "Dog" inheriting from Mammal
- Each level adds features
- Verify all methods accessible through inheritance chain

Solution provided below
*/

class Mammal : public Animal
{
public:
    Mammal(string n, int a) : Animal(n, a)
    {
        cout << "Mammal constructor" << endl;
    }

    void nurse()
    {
        cout << name << " nursing offspring" << endl;
    }
};

class Puppy : public Mammal
{
public:
    Puppy(string n, int a) : Mammal(n, a)
    {
        cout << "Puppy constructor" << endl;
    }

    void play()
    {
        cout << name << " playing!" << endl;
    }
};

void exercise3()
{
    cout << "\n--- Exercise 3: Multi-Level Inheritance (3 levels) ---" << endl;
    Puppy puppy("Max", 1);
    puppy.play();  // Puppy-specific
    puppy.nurse(); // From Mammal
    // Can access Animal methods too, shown by protected members
    cout << "SUCCESS: Chain of 3 inheritance levels works" << endl;
}

// ============================================================================
// EXERCISE 4: Protected Members and Access Control
// ============================================================================
/*
EXERCISE 4: Understand protected access in inheritance
- Create "Base" class with public, protected, private members
- Create "Derived" class
- Show that Derived can access protected but not private
- Show that outside code can't access protected

Solution provided below
*/

class Base
{
public:
    int publicMember = 1;

protected:
    int protectedMember = 2;

private:
    int privateMember = 3;
};

class Derived : public Base
{
public:
    void showMembers()
    {
        cout << "Public: " << publicMember << endl;       // OK
        cout << "Protected: " << protectedMember << endl; // OK
        // cout << "Private: " << privateMember << endl;  // ERROR
    }
};

void exercise4()
{
    cout << "\n--- Exercise 4: Protected Access Control ---" << endl;
    Derived d;
    d.publicMember = 10; // OK - public
    d.showMembers();     // Shows all accessible members
    // d.protectedMember = 5;  // ERROR - protected from outside
    cout << "SUCCESS: Protected members accessible in derived, not outside" << endl;
}

// ============================================================================
// EXERCISE 5: Method Overriding
// ============================================================================
/*
EXERCISE 5: Override parent method with different implementation
- Create "Shape" with getInfo() method
- Create "Circle" and "Square" with different getInfo() implementations
- Create objects and show each calls correct version

Solution provided below
*/

class Shape
{
protected:
    string name;

public:
    Shape(string n) : name(n) {} // Constructor to set name

    virtual void getInfo()
    { // Virtual allows overriding
        cout << "Shape: " << name << endl;
    }

    virtual ~Shape() {}
};

class Circle : public Shape
{
private:
    double radius;

public:
    Circle(double r) : Shape("Circle"), radius(r) {}

    void getInfo() override
    {
        cout << "Circle with radius " << radius << endl;
    }
};

class Square : public Shape
{
private:
    double side;

public:
    Square(double s) : Shape("Square"), side(s) {}

    void getInfo() override
    {
        cout << "Square with side " << side << endl;
    }
};

void exercise5()
{
    cout << "\n--- Exercise 5: Method Overriding ---" << endl;
    Circle circle(5);
    Square square(10);

    circle.getInfo();
    square.getInfo();

    cout << "SUCCESS: Each derived class overrides with its own version" << endl;
}

// ============================================================================
// EXERCISE 6: Polymorphism with Pointers
// ============================================================================
/*
EXERCISE 6: Use base pointers to point to derived objects
- Create array of Shape* pointers
- Store Circle and Square objects
- Iterate and call getInfo() on each
- Show polymorphic behavior (right method called)

Solution provided below
*/

void exercise6()
{
    cout << "\n--- Exercise 6: Polymorphism with Base Pointers ---" << endl;

    Shape *shapes[3];
    shapes[0] = new Circle(5);
    shapes[1] = new Square(4);
    shapes[2] = new Circle(3);

    for (int i = 0; i < 3; i++)
    {
        shapes[i]->getInfo(); // Calls correct derived method
    }

    for (int i = 0; i < 3; i++)
    {
        delete shapes[i]; // Virtual destructor called
    }

    cout << "SUCCESS: Polymorphic calls work correctly" << endl;
}

// ============================================================================
// EXERCISE 7: Virtual Functions vs Non-Virtual
// ============================================================================
/*
EXERCISE 7: Compare virtual vs non-virtual method behavior
- Create two base/derived pairs: one virtual, one non-virtual
- Show the difference in behavior when called through base pointer
- Demonstrate why virtual is important

Solution provided below
*/

class NonVirtualBase
{
public:
    void method()
    {
        cout << "NonVirtualBase::method" << endl;
    }
};

class NonVirtualDerived : public NonVirtualBase
{
public:
    void method()
    { // Overrides but doesn't override (hides)
        cout << "NonVirtualDerived::method" << endl;
    }
};

class VirtualBase
{
public:
    virtual void method()
    {
        cout << "VirtualBase::method" << endl;
    }
};

class VirtualDerived : public VirtualBase
{
public:
    void method() override
    { // True override
        cout << "VirtualDerived::method" << endl;
    }
};

void exercise7()
{
    cout << "\n--- Exercise 7: Virtual vs Non-Virtual ---" << endl;

    NonVirtualBase *nvBase = new NonVirtualDerived();
    nvBase->method(); // Calls NonVirtualBase::method (wrong!)

    VirtualBase *vBase = new VirtualDerived();
    vBase->method(); // Calls VirtualDerived::method (correct!)

    delete nvBase;
    delete vBase;

    cout << "SUCCESS: Virtual functions ensure correct method is called" << endl;
}

// ============================================================================
// EXERCISE 8: Abstract Base Classes (Pure Virtual)
// ============================================================================
/*
EXERCISE 8: Create abstract base class with pure virtual methods
- Create "Employee" with pure virtual work() method
- Can't instantiate Employee
- Create "Manager" and "Developer" implementing work()
- Show that subclasses must implement pure virtual

Solution provided below
*/

class Employee
{
protected:
    string name;

public:
    Employee(string n) : name(n) {}

    virtual void work() = 0; // Pure virtual - must override

    virtual ~Employee() {}
};

class Manager : public Employee
{
public:
    Manager(string n) : Employee(n) {}

    void work() override
    {
        cout << name << " managing team" << endl;
    }
};

class Developer : public Employee
{
public:
    Developer(string n) : Employee(n) {}

    void work() override
    {
        cout << name << " coding" << endl;
    }
};

void exercise8()
{
    cout << "\n--- Exercise 8: Abstract Base Classes ---" << endl;

    // Employee e("test");  // ERROR: can't instantiate abstract class

    Manager manager("Alice");
    Developer dev("Bob");

    Employee *workers[2] = {&manager, &dev};
    for (int i = 0; i < 2; i++)
    {
        workers[i]->work(); // Polymorphic call
    }

    cout << "SUCCESS: Abstract classes enforce implementation in derived" << endl;
}

// ============================================================================
// EXERCISE 9: Calling Parent Methods Explicitly
// ============================================================================
/*
EXERCISE 9: Override method but still use parent implementation
- Create parent method
- Override in child but extend (call parent version + more)
- Show syntax for calling parent::method()

Solution provided below
*/

class Parent
{
public:
    virtual void display()
    {
        cout << "Parent display" << endl;
    }
};

class Child : public Parent
{
public:
    void display() override
    {
        Parent::display(); // Call parent version
        cout << "Child display" << endl;
    }
};

void exercise9()
{
    cout << "\n--- Exercise 9: Calling Parent Methods ---" << endl;

    Child child;
    child.display(); // Shows both parent and child output

    cout << "SUCCESS: Can explicitly call parent implementation" << endl;
}

// ============================================================================
// EXERCISE 10: Constructor Order and Initialization
// ============================================================================
/*
EXERCISE 10: Demonstrate full constructor/destructor lifecycle
- Create base and derived classes with output
- Show execution order of constructors
- Show execution order of destructors (reverse)

Solution provided below
*/

class BaseClass
{
public:
    BaseClass() { cout << "1. BaseClass constructor" << endl; }
    ~BaseClass() { cout << "4. BaseClass destructor" << endl; }
};

class DerivedClass : public BaseClass
{
public:
    DerivedClass() { cout << "2. DerivedClass constructor" << endl; }
    ~DerivedClass() { cout << "3. DerivedClass destructor" << endl; }
};

void exercise10()
{
    cout << "\n--- Exercise 10: Constructor/Destructor Order ---" << endl;

    cout << "Creating object:" << endl;
    DerivedClass d;
    cout << "Object going out of scope:" << endl;
}

// ============================================================================
// EXERCISE 11: Inheritance Hierarchy - Company Organization
// ============================================================================
/*
EXERCISE 11: Create realistic company structure
- Base: Person (name, age)
- Derived: Employee (salary, position)
- Further derived: Manager (team size) and Engineer (skills)
- Create multiple objects and display info

Solution provided below
*/

class Person
{
protected:
    string name;
    int age;

public:
    Person(string n, int a) : name(n), age(a) {}
    virtual void display()
    {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
    virtual ~Person() {}
};

class PersonEmployee : public Person
{
protected:
    double salary;
    string position;

public:
    PersonEmployee(string n, int a, string p, double s)
        : Person(n, a), position(p), salary(s) {}

    void display() override
    {
        Person::display();
        cout << "Position: " << position << ", Salary: $" << salary << endl;
    }
};

class PersonManager : public PersonEmployee
{
private:
    int teamSize;

public:
    PersonManager(string n, int a, double s, int t)
        : PersonEmployee(n, a, "Manager", s), teamSize(t) {}

    void display() override
    {
        PersonEmployee::display();
        cout << "Team size: " << teamSize << endl;
    }
};

void exercise11()
{
    cout << "\n--- Exercise 11: Company Hierarchy ---" << endl;

    PersonManager manager("Alice", 40, 120000, 5);
    PersonEmployee engineer("Bob", 30, 90000, "Engineer");

    manager.display();
    cout << endl;
    engineer.display();

    cout << "SUCCESS: Multi-level hierarchy structure" << endl;
}

// ============================================================================
// EXERCISE 12: Private vs Protected Inheritance
// ============================================================================
/*
EXERCISE 12: Explore different inheritance types
- Create base class with public method
- Derived with public inheritance
- Derived with protected inheritance
- Show access differences

Solution provided below
*/

class PublicBase
{
public:
    void publicMethod()
    {
        cout << "Public method" << endl;
    }
};

class PublicIntherited : public PublicBase
{
    // publicMethod remains public
};

class ProtectedInherited : protected PublicBase
{
    // publicMethod becomes protected
};

void exercise12()
{
    cout << "\n--- Exercise 12: Inheritance Types ---" << endl;

    PublicIntherited pub;
    pub.publicMethod(); // OK - remains public

    // ProtectedInherited prot;
    // prot.publicMethod();  // ERROR - now protected

    cout << "SUCCESS: Different inheritance types control access" << endl;
}

// ============================================================================
// EXERCISE 13: Polymorphic Container with Vector
// ============================================================================
/*
EXERCISE 13: Store multiple derived objects in vector of base pointers
- Create Shape hierarchy (Circle, Square, Triangle)
- Store in vector<Shape*>
- Iterate and call polymorphic method on each
- Use dynamic casting or virtual methods

Solution provided below
*/

class Triangle : public Shape
{
private:
    double base, height;

public:
    Triangle(double b, double h) : Shape("Triangle"), base(b), height(h) {}

    void getInfo() override
    {
        cout << "Triangle with base " << base << " height " << height << endl;
    }
};

void exercise13()
{
    cout << "\n--- Exercise 13: Polymorphic Vector Container ---" << endl;

    vector<Shape *> shapes;
    shapes.push_back(new Circle(5));
    shapes.push_back(new Square(4));
    shapes.push_back(new Triangle(3, 6));
    shapes.push_back(new Circle(2));

    cout << "All shapes:" << endl;
    for (Shape *shape : shapes)
    {
        shape->getInfo();
    }

    for (Shape *shape : shapes)
    {
        delete shape; // Virtual destructor
    }
    shapes.clear();

    cout << "SUCCESS: Vector of pointers to base class" << endl;
}

// ============================================================================
// MAIN: Execute all exercises
// ============================================================================

int main()
{
    cout << "========== C++ Inheritance Exercises ==========" << endl;

    exercise1();
    exercise2();
    exercise3();
    exercise4();
    exercise5();
    exercise6();
    exercise7();
    exercise8();
    exercise9();
    exercise10();
    exercise11();
    exercise12();
    exercise13();

    cout << "\n========== All Exercises Completed Successfully ==========" << endl;

    return 0;
}
