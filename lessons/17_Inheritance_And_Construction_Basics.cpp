//============================================================================
// Lesson 17: Inheritance and Construction - Constructor Chaining
// Author      : M'Barek Benraiss
// Description : Comprehensive guide to constructors in inheritance,
//               constructor chaining, and initialization order
//============================================================================

#include <iostream>
#include <string>
using namespace std;

// ============================================================================
// SECTION 1: Basic Constructor in Inheritance
// ============================================================================

class Animal
{
protected:
    string name;
    int age;

public:
    // Default constructor
    Animal() : age(0)
    {
        cout << "Animal default constructor called" << endl;
    }

    // Parameterized constructor
    Animal(string n, int a) : name(n), age(a)
    {
        cout << "Animal parameterized constructor called: " << name << endl;
    }

    ~Animal()
    {
        cout << "Animal destructor called: " << name << endl;
    }

    void speak() const
    {
        cout << name << " (" << age << " years old) speaks" << endl;
    }
};

class Dog : public Animal
{
private:
    string breed;

public:
    // Default constructor - must call parent default constructor
    Dog() : Animal()
    {
        breed = "Unknown";
        cout << "Dog default constructor called" << endl;
    }

    // Parameterized constructor - calls parent parameterized constructor
    Dog(string n, int a, string b) : Animal(n, a), breed(b)
    {
        cout << "Dog parameterized constructor called: " << breed << endl;
    }

    void bark() const
    {
        cout << name << " (" << breed << ") barks: Woof!" << endl;
    }
};

void demonstrateBasicConstructorInheritance()
{
    cout << "\n--- Basic Constructor in Inheritance ---" << endl;

    Dog dog1; // Calls default constructors
    cout << endl;

    Dog dog2("Buddy", 3, "Golden Retriever"); // Calls parameterized constructors
    dog2.bark();
    dog2.speak();
}

// ============================================================================
// SECTION 2: Multi-Level Inheritance Constructor Chain
// ============================================================================

class Vehicle
{
protected:
    string model;
    int year;

public:
    Vehicle() : year(0)
    {
        cout << "Vehicle default constructor" << endl;
    }

    Vehicle(string m, int y) : model(m), year(y)
    {
        cout << "Vehicle parameterized constructor: " << model << endl;
    }

    ~Vehicle()
    {
        cout << "Vehicle destructor: " << model << endl;
    }

    void info() const
    {
        cout << "Vehicle: " << model << " (" << year << ")" << endl;
    }
};

class Car : public Vehicle
{
protected:
    int doors;

public:
    Car() : Vehicle(), doors(0)
    {
        cout << "Car default constructor" << endl;
    }

    Car(string m, int y, int d) : Vehicle(m, y), doors(d)
    {
        cout << "Car parameterized constructor: " << doors << " doors" << endl;
    }

    ~Car()
    {
        cout << "Car destructor" << endl;
    }

    void displayInfo() const
    {
        info();
        cout << "Doors: " << doors << endl;
    }
};

class SportsCar : public Car
{
private:
    int topSpeed;

public:
    SportsCar() : Car(), topSpeed(0)
    {
        cout << "SportsCar default constructor" << endl;
    }

    SportsCar(string m, int y, int d, int speed)
        : Car(m, y, d), topSpeed(speed)
    {
        cout << "SportsCar parameterized constructor: " << speed << " mph" << endl;
    }

    ~SportsCar()
    {
        cout << "SportsCar destructor" << endl;
    }

    void showPerformance() const
    {
        displayInfo();
        cout << "Top speed: " << topSpeed << " mph" << endl;
    }
};

void demonstrateMultiLevelConstructorChain()
{
    cout << "\n--- Multi-Level Constructor Chain (3 levels) ---" << endl;

    cout << "Creating SportsCar with parameterized constructors:" << endl;
    SportsCar myCar("Ferrari", 2023, 2, 200);
    myCar.showPerformance();

    cout << "\nDestroying SportsCar (notice reverse order):" << endl;
}

// ============================================================================
// SECTION 3: Constructor Order and Initialization
// ============================================================================

class Base
{
private:
    int baseValue;

public:
    Base() : baseValue(10)
    {
        cout << "1. Base default constructor (baseValue = 10)" << endl;
    }

    Base(int val) : baseValue(val)
    {
        cout << "1. Base parameterized constructor (baseValue = " << val << ")" << endl;
    }

    ~Base()
    {
        cout << "3. Base destructor" << endl;
    }

    int getValue() const { return baseValue; }
};

class Derived : public Base
{
private:
    int derivedValue;

public:
    Derived() : Base(), derivedValue(20)
    {
        cout << "2. Derived default constructor (derivedValue = 20)" << endl;
    }

    Derived(int b, int d) : Base(b), derivedValue(d)
    {
        cout << "2. Derived parameterized constructor (derivedValue = " << d << ")" << endl;
    }

    ~Derived()
    {
        cout << "2. Derived destructor" << endl;
    }

    int getDerivedValue() const { return derivedValue; }
};

void demonstrateConstructorOrder()
{
    cout << "\n--- Constructor Execution Order ---" << endl;

    cout << "Creating Derived object:" << endl;
    Derived d(100, 200);
    cout << "Base value: " << d.getValue() << ", Derived value: " << d.getDerivedValue() << endl;

    cout << "\nDestructor order (reverse):" << endl;
}

// ============================================================================
// SECTION 4: Calling Parent Constructors Explicitly
// ============================================================================

class Engine
{
protected:
    string type;
    int power;

public:
    Engine(string t = "Unknown", int p = 0) : type(t), power(p)
    {
        cout << "Engine constructor: " << type << " (" << power << " hp)" << endl;
    }

    ~Engine()
    {
        cout << "Engine destructor" << endl;
    }

    void engineInfo() const
    {
        cout << "Engine: " << type << ", Power: " << power << " hp" << endl;
    }
};

class Motorcycle : public Engine
{
private:
    int wheels;

public:
    // Explicitly call parent constructor with specific parameters
    Motorcycle() : Engine("V-Twin", 80), wheels(2)
    {
        cout << "Motorcycle default constructor" << endl;
    }

    Motorcycle(string engineType, int power, int w)
        : Engine(engineType, power), wheels(w)
    {
        cout << "Motorcycle parameterized constructor: " << w << " wheels" << endl;
    }

    void displayInfo() const
    {
        engineInfo();
        cout << "Wheels: " << wheels << endl;
    }
};

void demonstrateParentConstructorCalls()
{
    cout << "\n--- Calling Parent Constructors ---" << endl;

    Motorcycle bike1; // Uses default parent constructor call
    bike1.displayInfo();

    cout << endl;

    Motorcycle bike2("Inline-4", 130, 2); // Custom parent constructor
    bike2.displayInfo();
}

// ============================================================================
// SECTION 5: Member Initialization Order
// ============================================================================

class Component
{
private:
    int id;

public:
    Component(int i) : id(i)
    {
        cout << "Component constructor: id = " << id << endl;
    }

    int getID() const { return id; }
};

class System : public Component
{
private:
    string name;
    int systemID;

public:
    // Initialization order: Component (parent), then System members
    // Even though we initialize in different order in initializer list,
    // actual order is: id (parent), name, systemID
    System(string n, int cid, int sid)
        : Component(cid), name(n), systemID(sid)
    {
        cout << "System constructor: name = " << name << ", systemID = " << systemID << endl;
    }

    void info() const
    {
        cout << "System: " << name << ", Component ID: " << getID()
             << ", System ID: " << systemID << endl;
    }
};

void demonstrateMemberInitializationOrder()
{
    cout << "\n--- Member Initialization Order ---" << endl;

    System sys("MainSystem", 101, 1001);
    sys.info();

    cout << "\nNote: Parent initialized first, then derived members in declaration order" << endl;
}

// ============================================================================
// SECTION 6: Default Parameters in Constructors
// ============================================================================

class Shape
{
protected:
    string color;

public:
    Shape(string c = "Red") : color(c)
    {
        cout << "Shape constructor: color = " << color << endl;
    }

    virtual ~Shape() {}

    string getColor() const { return color; }
};

class Triangle : public Shape
{
private:
    double base, height;

public:
    // Parent constructor can use default parameter
    Triangle() : Shape(), base(0), height(0)
    {
        cout << "Triangle default constructor" << endl;
    }

    Triangle(double b, double h, string c = "Blue")
        : Shape(c), base(b), height(h)
    {
        cout << "Triangle parameterized constructor" << endl;
    }

    double getArea() const { return (base * height) / 2.0; }
};

void demonstrateDefaultParameters()
{
    cout << "\n--- Default Parameters in Constructors ---" << endl;

    Triangle t1; // Uses all defaults
    cout << "Triangle 1 color: " << t1.getColor() << endl;

    Triangle t2(5, 8); // Uses default color
    cout << "Triangle 2 color: " << t2.getColor() << endl;

    Triangle t3(5, 8, "Green"); // All explicit
    cout << "Triangle 3 color: " << t3.getColor() << endl;
}

// ============================================================================
// SECTION 7: Copy Constructors in Inheritance
// ============================================================================

class Product
{
protected:
    string name;
    double price;

public:
    Product(string n, double p) : name(n), price(p)
    {
        cout << "Product constructor: " << name << endl;
    }

    // Copy constructor
    Product(const Product &other) : name(other.name), price(other.price)
    {
        cout << "Product copy constructor" << endl;
    }

    virtual ~Product() {}

    string getName() const { return name; }
};

class Book : public Product
{
private:
    string author;

public:
    Book(string n, double p, string a) : Product(n, p), author(a)
    {
        cout << "Book constructor: " << author << endl;
    }

    // Must explicitly define copy constructor for derived class
    Book(const Book &other) : Product(other), author(other.author)
    {
        cout << "Book copy constructor" << endl;
    }

    string getAuthor() const { return author; }
};

void demonstrateCopyConstructors()
{
    cout << "\n--- Copy Constructors in Inheritance ---" << endl;

    Book book1("1984", 15.99, "George Orwell");
    Book book2 = book1; // Calls copy constructor

    cout << "Book 2: " << book2.getName() << " by " << book2.getAuthor() << endl;
}

// ============================================================================
// SECTION 8: Constructor Delegation (C++11)
// ============================================================================

class Point
{
private:
    int x, y;

public:
    // Constructor delegation (C++11 feature)
    Point() : Point(0, 0)
    { // Delegates to the 2-parameter constructor
        cout << "Point default constructor (via delegation)" << endl;
    }

    Point(int a, int b) : x(a), y(b)
    {
        cout << "Point parameterized constructor: (" << x << ", " << y << ")" << endl;
    }

    void display() const
    {
        cout << "Point: (" << x << ", " << y << ")" << endl;
    }
};

class Line
{
private:
    Point start, end;

public:
    Line() : start(0, 0), end(10, 10)
    {
        cout << "Line default constructor" << endl;
    }

    Line(int x1, int y1, int x2, int y2) : start(x1, y1), end(x2, y2)
    {
        cout << "Line parameterized constructor" << endl;
    }

    void displayLine() const
    {
        cout << "Line from ";
        start.display();
        cout << " to ";
        end.display();
    }
};

void demonstrateConstructorDelegation()
{
    cout << "\n--- Constructor Delegation (C++11) ---" << endl;

    Point p1; // Delegates to Point(0, 0)
    Point p2(5, 5);

    Line line(0, 0, 10, 10);
    line.displayLine();
}

// ============================================================================
// SECTION 9: Destructors in Inheritance
// ============================================================================

class Resource
{
private:
    string resourceName;

public:
    Resource(string name) : resourceName(name)
    {
        cout << "Resource acquired: " << resourceName << endl;
    }

    virtual ~Resource()
    { // Virtual destructor!
        cout << "Resource released: " << resourceName << endl;
    }
};

class SpecialResource : public Resource
{
private:
    string specialData;

public:
    SpecialResource(string name, string data)
        : Resource(name), specialData(data)
    {
        cout << "SpecialResource created with data: " << specialData << endl;
    }

    ~SpecialResource()
    {
        cout << "SpecialResource destructor cleaning up: " << specialData << endl;
    }
};

void demonstrateDestructorOrder()
{
    cout << "\n--- Destructor Order in Inheritance ---" << endl;

    cout << "Creating SpecialResource:" << endl;
    SpecialResource *res = new SpecialResource("Database", "Critical data");

    cout << "\nDeleting SpecialResource:" << endl;
    delete res; // Calls destructors in reverse order
}

// ============================================================================
// MAIN: Run all demonstrations
// ============================================================================

int main()
{
    cout << "========== C++ Inheritance and Construction ==========" << endl;

    demonstrateBasicConstructorInheritance();
    demonstrateMultiLevelConstructorChain();
    demonstrateConstructorOrder();
    demonstrateParentConstructorCalls();
    demonstrateMemberInitializationOrder();
    demonstrateDefaultParameters();
    demonstrateCopyConstructors();
    demonstrateConstructorDelegation();
    demonstrateDestructorOrder();

    cout << "\n========== End of Inheritance and Construction ==========" << endl;

    return 0;
}

/*
    /Users/benraiss/CLionProjects/learnCpp/cmake-build-debug/learnCpp
    ========== C++ Inheritance and Construction ==========

    --- Basic Constructor in Inheritance ---
    Animal default constructor called
    Dog default constructor called

    Animal parameterized constructor called: Buddy
    Dog parameterized constructor called: Golden Retriever
    Buddy (Golden Retriever) barks: Woof!
    Buddy (3 years old) speaks
    Animal destructor called: Buddy
    Animal destructor called:

    --- Multi-Level Constructor Chain (3 levels) ---
    Creating SportsCar with parameterized constructors:
    Vehicle parameterized constructor: Ferrari
    Car parameterized constructor: 2 doors
    SportsCar parameterized constructor: 200 mph
    Vehicle: Ferrari (2023)
    Doors: 2
    Top speed: 200 mph

    Destroying SportsCar (notice reverse order):
    SportsCar destructor
    Car destructor
    Vehicle destructor: Ferrari

    --- Constructor Execution Order ---
    Creating Derived object:
    1. Base parameterized constructor (baseValue = 100)
    2. Derived parameterized constructor (derivedValue = 200)
    Base value: 100, Derived value: 200

    Destructor order (reverse):
    2. Derived destructor
    3. Base destructor

    --- Calling Parent Constructors ---
    Engine constructor: V-Twin (80 hp)
    Motorcycle default constructor
    Engine: V-Twin, Power: 80 hp
    Wheels: 2

    Engine constructor: Inline-4 (130 hp)
    Motorcycle parameterized constructor: 2 wheels
    Engine: Inline-4, Power: 130 hp
    Wheels: 2
    Engine destructor
    Engine destructor

    --- Member Initialization Order ---
    Component constructor: id = 101
    System constructor: name = MainSystem, systemID = 1001
    System: MainSystem, Component ID: 101, System ID: 1001

    Note: Parent initialized first, then derived members in declaration order

    --- Default Parameters in Constructors ---
    Shape constructor: color = Red
    Triangle default constructor
    Triangle 1 color: Red
    Shape constructor: color = Blue
    Triangle parameterized constructor
    Triangle 2 color: Blue
    Shape constructor: color = Green
    Triangle parameterized constructor
    Triangle 3 color: Green

    --- Copy Constructors in Inheritance ---
    Product constructor: 1984
    Book constructor: George Orwell
    Product copy constructor
    Book copy constructor
    Book 2: 1984 by George Orwell

    --- Constructor Delegation (C++11) ---
    Point parameterized constructor: (0, 0)
    Point default constructor (via delegation)
    Point parameterized constructor: (5, 5)
    Point parameterized constructor: (0, 0)
    Point parameterized constructor: (10, 10)
    Line parameterized constructor
    Line from Point: (0, 0)
    to Point: (10, 10)

    --- Destructor Order in Inheritance ---
    Creating SpecialResource:
    Resource acquired: Database
    SpecialResource created with data: Critical data

    Deleting SpecialResource:
    SpecialResource destructor cleaning up: Critical data
    Resource released: Database

    ========== End of Inheritance and Construction ==========

    Process finished with exit code 0
*/
