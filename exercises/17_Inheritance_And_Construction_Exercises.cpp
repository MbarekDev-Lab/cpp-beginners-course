//============================================================================
// Lesson 17: Inheritance and Construction - Exercises
// Author      : M'Barek Benraiss
// Description : Progressive exercises for understanding constructors in
//               inheritance, constructor chaining, and initialization order
//============================================================================

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// ============================================================================
// EXERCISE 1: Basic Parent Constructor Call
// ============================================================================
/*
EXERCISE 1: Call parent constructor from child
- Create "Vehicle" class with string model
- Constructor takes model parameter
- Create "Bike" class that calls parent constructor
- Verify parent is initialized properly

Solution provided below
*/

class Vehicle
{
protected:
    string model;

public:
    Vehicle(string m) : model(m)
    {
        cout << "Vehicle initialized: " << model << endl;
    }
};

class Bike : public Vehicle
{
private:
    int wheels;

public:
    Bike(string m, int w) : Vehicle(m), wheels(w)
    {
        cout << "Bike initialized: " << wheels << " wheels" << endl;
    }

    void info() const
    {
        cout << "Bike: " << model << " with " << wheels << " wheels" << endl;
    }
};

void exercise1()
{
    cout << "\n--- Exercise 1: Parent Constructor Call ---" << endl;
    Bike bike("Honda", 2);
    bike.info();
    cout << "SUCCESS: Parent constructor called and initialized" << endl;
}

// ============================================================================
// EXERCISE 2: Constructor Execution Order
// ============================================================================
/*
EXERCISE 2: Observe constructor execution order
- Create base class with constructor output
- Create derived class with constructor output
- Create object and see which runs first
- Verify parent constructor runs first

Solution provided below
*/

class Base
{
public:
    Base()
    {
        cout << "1. Base constructor" << endl;
    }
};

class Derived : public Base
{
public:
    Derived() : Base()
    {
        cout << "2. Derived constructor" << endl;
    }
};

void exercise2()
{
    cout << "\n--- Exercise 2: Constructor Order ---" << endl;
    cout << "Creating Derived object:" << endl;
    Derived d;
    cout << "SUCCESS: Base constructor ran first, then Derived" << endl;
}

// ============================================================================
// EXERCISE 3: Multi-Level Inheritance Constructor Chain
// ============================================================================
/*
EXERCISE 3: Constructor chaining through 3 levels
- Level 1: Animal (name)
- Level 2: Mammal (temp control)
- Level 3: Dog (breed)
- Each initializes parent correctly
- Show all three constructors execute in order

Solution provided below
*/

class Animal
{
protected:
    string name;

public:
    Animal(string n) : name(n)
    {
        cout << "1. Animal: " << name << endl;
    }
};

class Mammal : public Animal
{
protected:
    bool warmBlooded;

public:
    Mammal(string n) : Animal(n), warmBlooded(true)
    {
        cout << "2. Mammal: warm-blooded" << endl;
    }
};

class Dog : public Mammal
{
private:
    string breed;

public:
    Dog(string n, string b) : Mammal(n), breed(b)
    {
        cout << "3. Dog: " << breed << endl;
    }

    void info() const
    {
        cout << "Dog " << name << " is a " << breed << endl;
    }
};

void exercise3()
{
    cout << "\n--- Exercise 3: Multi-Level Constructor Chain ---" << endl;
    Dog dog("Rex", "Labrador");
    dog.info();
    cout << "SUCCESS: Three-level constructor chain completed" << endl;
}

// ============================================================================
// EXERCISE 4: Destructor Execution Order (Reverse)
// ============================================================================
/*
EXERCISE 4: Show destructor order (reverse of constructor)
- Create base and derived with output in destructors
- Verify derived destructor runs first
- Then base destructor runs

Solution provided below
*/

class BaseD
{
public:
    BaseD() { cout << "BaseD constructor" << endl; }
    ~BaseD() { cout << "3. BaseD destructor" << endl; }
};

class DerivedD : public BaseD
{
public:
    DerivedD() { cout << "DerivedD constructor" << endl; }
    ~DerivedD() { cout << "2. DerivedD destructor" << endl; }
};

void exercise4()
{
    cout << "\n--- Exercise 4: Destructor Order ---" << endl;
    {
        cout << "Creating DerivedD:" << endl;
        DerivedD d;
        cout << "Scope ending, destructors called:" << endl;
    }
    cout << "SUCCESS: Destructors called in reverse order" << endl;
}

// ============================================================================
// EXERCISE 5: Default and Parameterized Constructor
// ============================================================================
/*
EXERCISE 5: Multiple constructors with different parameters
- Parent class with default and parameterized
- Derived class with default and parameterized
- Show both constructors work correctly

Solution provided below
*/

class Person
{
protected:
    string name;
    int age;

public:
    Person() : age(0)
    {
        cout << "Person default constructor" << endl;
    }

    Person(string n, int a) : name(n), age(a)
    {
        cout << "Person parameterized constructor" << endl;
    }

    void display() const
    {
        cout << name << " is " << age << " years old" << endl;
    }
};

class Employee : public Person
{
private:
    string employeeID;

public:
    Employee() : Person(), employeeID("")
    {
        cout << "Employee default constructor" << endl;
    }

    Employee(string n, int a, string id)
        : Person(n, a), employeeID(id)
    {
        cout << "Employee parameterized constructor" << endl;
    }

    void displayEmployee() const
    {
        display();
        cout << "Employee ID: " << employeeID << endl;
    }
};

void exercise5()
{
    cout << "\n--- Exercise 5: Multiple Constructors ---" << endl;

    Employee e1; // Default constructors
    e1.display();

    cout << endl;

    Employee e2("Alice", 30, "E001"); // Parameterized constructors
    e2.displayEmployee();

    cout << "SUCCESS: Both default and parameterized constructors work" << endl;
}

// ============================================================================
// EXERCISE 6: Copy Constructor in Inheritance
// ============================================================================
/*
EXERCISE 6: Copy constructor copies both parent and derived
- Create parent and derived classes
- Implement copy constructor in derived
- Copy constructor calls parent copy constructor
- Verify both parts are copied

Solution provided below
*/

class Shape
{
protected:
    string color;

public:
    Shape(string c = "Red") : color(c) {}

    Shape(const Shape &other) : color(other.color)
    {
        cout << "Shape copy constructor" << endl;
    }
};

class Circle : public Shape
{
private:
    double radius;

public:
    Circle(double r = 0, string c = "Red") : Shape(c), radius(r) {}

    Circle(const Circle &other) : Shape(other), radius(other.radius)
    {
        cout << "Circle copy constructor" << endl;
    }

    void info() const
    {
        cout << "Circle: color=" << color << ", radius=" << radius << endl;
    }
};

void exercise6()
{
    cout << "\n--- Exercise 6: Copy Constructor ---" << endl;
    Circle c1(5, "Blue");
    Circle c2 = c1; // Calls copy constructor
    c2.info();
    cout << "SUCCESS: Copy constructor copies parent and child members" << endl;
}

// ============================================================================
// EXERCISE 7: Parent Constructor with Default Parameters
// ============================================================================
/*
EXERCISE 7: Parent has default parameters
- Parent constructor with default color parameter
- Derived can use parent's default
- Derived can override parent's default
- Verify flexibility

Solution provided below
*/

class House
{
protected:
    string style;

public:
    House(string s = "Colonial") : style(s) {}

    void showStyle() const
    {
        cout << "House style: " << style << endl;
    }
};

class Mansion : public House
{
private:
    int rooms;

public:
    Mansion(int r) : House(), rooms(r)
    { // Uses parent default
        cout << "Mansion with default style" << endl;
    }

    Mansion(int r, string s) : House(s), rooms(r)
    { // Custom style
        cout << "Mansion with custom style" << endl;
    }

    void show() const
    {
        showStyle();
        cout << "Rooms: " << rooms << endl;
    }
};

void exercise7()
{
    cout << "\n--- Exercise 7: Default Parameters ---" << endl;

    Mansion m1(10); // Uses parent default
    m1.show();

    cout << endl;

    Mansion m2(15, "Modern"); // Custom style
    m2.show();

    cout << "SUCCESS: Can use parent defaults or override them" << endl;
}

// ============================================================================
// EXERCISE 8: Member Initialization Order
// ============================================================================
/*
EXERCISE 8: Understand initialization order
- Create class with multiple members
- Initialize in different order than declaration
- Show that declaration order is used, not initializer list order
- (Advanced: shows importance of correct ordering)

Solution provided below
*/

class OrderExample
{
private:
    int a;
    int b;
    int c;

public:
    OrderExample(int x, int y, int z) : c(z), b(y), a(x)
    {
        // Initialization order is based on declaration (a, b, c)
        // NOT the order in initializer list (c, b, a)
        cout << "a=" << a << ", b=" << b << ", c=" << c << endl;
    }
};

void exercise8()
{
    cout << "\n--- Exercise 8: Member Initialization Order ---" << endl;
    OrderExample obj(1, 2, 3);
    cout << "Members initialized in declaration order, not initializer list order" << endl;
    cout << "SUCCESS: Order matters for efficiency and correctness" << endl;
}

// ============================================================================
// EXERCISE 9: Calling Different Parent Constructor Overloads
// ============================================================================
/*
EXERCISE 9: Parent has multiple constructors
- Parent with default, one parameter, two parameters
- Derived chooses which parent constructor to call
- Different derived constructors call different parent constructors

Solution provided below
*/

class Calculator
{
protected:
    int memory;

public:
    Calculator() : memory(0)
    {
        cout << "Calculator default: memory=0" << endl;
    }

    Calculator(int m) : memory(m)
    {
        cout << "Calculator with memory=" << m << endl;
    }
};

class ScientificCalc : public Calculator
{
private:
    bool hasGraphics;

public:
    ScientificCalc() : Calculator()
    { // Calls default
        hasGraphics = false;
        cout << "ScientificCalc without graphics" << endl;
    }

    ScientificCalc(int m) : Calculator(m)
    { // Calls parameterized
        hasGraphics = true;
        cout << "ScientificCalc with memory " << m << " and graphics" << endl;
    }
};

void exercise9()
{
    cout << "\n--- Exercise 9: Multiple Parent Constructors ---" << endl;
    ScientificCalc c1; // Calls default parent constructor
    cout << endl;
    ScientificCalc c2(256); // Calls parameterized parent constructor
    cout << "SUCCESS: Can choose which parent constructor to call" << endl;
}

// ============================================================================
// EXERCISE 10: Complete Initialization Example
// ============================================================================
/*
EXERCISE 10: Full workflow example
- Create realistic 3-level hierarchy
- All classes with proper constructors
- Create objects with various parameter combinations
- Show full initialization workflow

Solution provided below
*/

class Creature
{
protected:
    string name;
    int health;

public:
    Creature(string n, int h) : name(n), health(h)
    {
        cout << "Creature: " << name << " (health=" << health << ")" << endl;
    }

    virtual ~Creature() {}
};

class Monster : public Creature
{
protected:
    string type;

public:
    Monster(string n, int h, string t) : Creature(n, h), type(t)
    {
        cout << "Monster type: " << type << endl;
    }

    virtual ~Monster() {}
};

class Dragon : public Monster
{
private:
    int firepower;

public:
    Dragon(string n, int h, int f) : Monster(n, h, "Dragon"), firepower(f)
    {
        cout << "Dragon firepower: " << firepower << endl;
    }

    ~Dragon()
    {
        cout << "Dragon destructor" << endl;
    }

    void info() const
    {
        cout << "Name: " << name << ", Health: " << health
             << ", Type: " << type << ", Firepower: " << firepower << endl;
    }
};

void exercise10()
{
    cout << "\n--- Exercise 10: Complete 3-Level Example ---" << endl;
    {
        Dragon dragon("Smaug", 100, 50);
        dragon.info();
    }
    cout << "SUCCESS: Full initialization and cleanup completed" << endl;
}

// ============================================================================
// EXERCISE 11: Virtual Destructor Importance
// ============================================================================
/*
EXERCISE 11: Show importance of virtual destructors
- Create base without virtual destructor
- Create derived with destructor
- Show that derived destructor not called without virtual
- (This demonstrates why virtual is critical)

Solution provided below
*/

class Resource
{
public:
    Resource() { cout << "Resource created" << endl; }
    virtual ~Resource() { cout << "Resource destroyed" << endl; }
};

class SpecialResource : public Resource
{
public:
    SpecialResource() { cout << "SpecialResource created" << endl; }
    ~SpecialResource() { cout << "SpecialResource destroyed" << endl; }
};

void exercise11()
{
    cout << "\n--- Exercise 11: Virtual Destructors ---" << endl;

    Resource *ptr = new SpecialResource();
    cout << "Deleting pointer:" << endl;
    delete ptr; // Calls both destructors because base has virtual ~

    cout << "SUCCESS: Virtual destructor ensures proper cleanup" << endl;
}

// ============================================================================
// EXERCISE 12: Constructor Validation Before Parent Call
// ============================================================================
/*
EXERCISE 12: Validate parameters before calling parent constructor
- Create constructors that validate input
- Show that validation happens before parent init
- Invalid input prevents parent initialization

Solution provided below
*/

class SafeParent
{
protected:
    int value;

public:
    SafeParent(int v) : value(v)
    {
        cout << "SafeParent initialized with value=" << value << endl;
    }

    int getValue() const { return value; }
};

class SafeChild : public SafeParent
{
public:
    SafeChild(int v) : SafeParent(validateValue(v))
    {
        cout << "SafeChild initialized" << endl;
    }

private:
    static int validateValue(int v)
    {
        if (v < 0)
        {
            cout << "Invalid value " << v << " (negative), using 0" << endl;
            return 0;
        }
        return v;
    }
};

void exercise12()
{
    cout << "\n--- Exercise 12: Validation Before Parent Call ---" << endl;
    SafeChild c1(10); // Valid
    SafeChild c2(-5); // Invalid, corrected to 0
    cout << "Value from c2: " << c2.getValue() << endl;
    cout << "SUCCESS: Validation occurred before parent initialization" << endl;
}

// ============================================================================
// EXERCISE 13: Complete Student/Course/Enrollment System
// ============================================================================
/*
EXERCISE 13: Realistic system with proper initialization
- Student class with ID and name
- Course class with code and name (inherits Person concept)
- Enrollment combining both
- Show how hierarchies with multiple inheritance could work

Solution provided below
*/

class Named
{
protected:
    string name;

public:
    Named(string n) : name(n) {}

    string getName() const { return name; }
};

class Student : public Named
{
private:
    int studentID;

public:
    Student(int id, string n) : Named(n), studentID(id)
    {
        cout << "Student: " << name << " (ID=" << studentID << ")" << endl;
    }

    int getID() const { return studentID; }
};

class Course : public Named
{
private:
    string courseCode;

public:
    Course(string code, string n) : Named(n), courseCode(code)
    {
        cout << "Course: " << name << " (" << courseCode << ")" << endl;
    }

    string getCode() const { return courseCode; }
};

void exercise13()
{
    cout << "\n--- Exercise 13: Multi-Class System ---" << endl;
    Student student(12345, "Alice Johnson");
    Course course("CS101", "Introduction to C++");

    cout << "Student: " << student.getName() << endl;
    cout << "Course: " << course.getName() << endl;

    cout << "SUCCESS: Complex system with proper initialization" << endl;
}

// ============================================================================
// MAIN: Execute all exercises
// ============================================================================

int main()
{
    cout << "========== Inheritance and Construction Exercises ==========" << endl;

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
