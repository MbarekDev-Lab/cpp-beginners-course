//============================================================================
// Copy Constructors Exercises - Practice Problems
// Master copy constructors and object copying!
//============================================================================

#include <iostream>
#include <cstring>
using namespace std;

//============================================================================
// EXERCISE 1: Basic Copy Constructor
//============================================================================
class SimpleClass
{
public:
    int value;

    SimpleClass() : value(0)
    {
        cout << "  Default constructor" << endl;
    }

    SimpleClass(const SimpleClass &other) : value(other.value)
    {
        cout << "  Copy constructor (copying value: " << other.value << ")" << endl;
    }

    void setValue(int v) { value = v; }
    void display() const { cout << "  Value: " << value << endl; }
};

void exercise1()
{
    cout << "\n========== EXERCISE 1: Basic Copy Constructor ==========" << endl;

    SimpleClass obj1;
    obj1.setValue(42);
    cout << "obj1 after setValue(42):" << endl;
    obj1.display();

    cout << "\nCreating obj2 = obj1:" << endl;
    SimpleClass obj2 = obj1;

    cout << "obj2:" << endl;
    obj2.display();

    cout << "\nBoth are independent copies" << endl;
}

//============================================================================
// EXERCISE 2: Copy Constructor Not Called with Default
//============================================================================
class NoExplicitCopy
{
public:
    int x;
    string text;

    NoExplicitCopy() : x(0), text("")
    {
        cout << "  Default constructor (no explicit copy constructor)" << endl;
    }

    void setData(int val, string txt)
    {
        x = val;
        text = txt;
    }

    void display() const
    {
        cout << "  x = " << x << ", text = \"" << text << "\"" << endl;
    }
};

void exercise2()
{
    cout << "\n========== EXERCISE 2: Default Memberwise Copy ==========" << endl;

    NoExplicitCopy obj1;
    obj1.setData(100, "Hello");

    cout << "Creating obj2 = obj1 (uses compiler-generated copy):" << endl;
    NoExplicitCopy obj2 = obj1;

    cout << "obj1: ";
    obj1.display();
    cout << "obj2: ";
    obj2.display();

    cout << "\nC++ automatically copies all member variables" << endl;
}

//============================================================================
// EXERCISE 3: Explicit Constructor Call
//============================================================================
class Animal
{
private:
    string name;
    int age;

public:
    Animal() : name(""), age(0)
    {
        cout << "  Default constructor" << endl;
    }

    Animal(const Animal &other) : name(other.name), age(other.age)
    {
        cout << "  Copy constructor (copying: " << other.name << ")" << endl;
    }

    void setInfo(string n, int a)
    {
        name = n;
        age = a;
    }

    void display() const
    {
        cout << "  Name: " << name << ", Age: " << age << endl;
    }
};

void exercise3()
{
    cout << "\n========== EXERCISE 3: Explicit Constructor Call ==========" << endl;

    Animal dog1;
    dog1.setInfo("Buddy", 3);

    cout << "Method 1 - Assignment: Animal dog2 = dog1;" << endl;
    Animal dog2 = dog1;

    cout << "\nMethod 2 - Parentheses: Animal dog3(dog1);" << endl;
    Animal dog3(dog1);

    cout << "\nBoth call the copy constructor" << endl;
}

//============================================================================
// EXERCISE 4: Copy Constructor with Function Parameters
//============================================================================
void processAnimal(Animal a)
{
    cout << "  Inside function:" << endl;
    a.display();
}

void exercise4()
{
    cout << "\n========== EXERCISE 4: Copy Constructor with Function Parameters ==========" << endl;

    Animal cat;
    cat.setInfo("Whiskers", 2);

    cout << "Passing cat by value to function:" << endl;
    cout << "processAnimal(cat);  <- calls copy constructor!" << endl;
    processAnimal(cat);

    cout << "\nOriginal cat (unchanged):" << endl;
    cat.display();

    cout << "\nPassing by value creates a copy for the function" << endl;
}

//============================================================================
// EXERCISE 5: Multiple Copies
//============================================================================
void exercise5()
{
    cout << "\n========== EXERCISE 5: Creating Multiple Copies ==========" << endl;

    Animal original;
    original.setInfo("Max", 5);

    cout << "Original: ";
    original.display();

    cout << "\nCreating copies from original:" << endl;
    Animal copy1 = original;
    cout << "copy1: ";
    copy1.display();

    Animal copy2 = original;
    cout << "copy2: ";
    copy2.display();

    cout << "\nModifying copies:" << endl;
    copy1.setInfo("Max Jr", 1);
    copy2.setInfo("Max Sr", 10);

    cout << "original: ";
    original.display();
    cout << "copy1: ";
    copy1.display();
    cout << "copy2: ";
    copy2.display();

    cout << "\nAll three are independent" << endl;
}

//============================================================================
// EXERCISE 6: Deep Copy with Dynamic Memory
//============================================================================
class DynamicArray
{
private:
    int *data;
    int size;

public:
    DynamicArray(int sz) : size(sz)
    {
        data = new int[size];
        cout << "  Allocated memory (" << size << " ints)" << endl;
    }

    // Deep copy constructor
    DynamicArray(const DynamicArray &other) : size(other.size)
    {
        data = new int[size]; // Allocate new memory
        for (int i = 0; i < size; i++)
        {
            data[i] = other.data[i]; // Copy values
        }
        cout << "  Deep copied (" << size << " ints)" << endl;
    }

    ~DynamicArray()
    {
        delete[] data;
        cout << "  Deallocated memory" << endl;
    }

    void setValue(int index, int value)
    {
        if (index >= 0 && index < size)
        {
            data[index] = value;
        }
    }

    int getValue(int index) const
    {
        return (index >= 0 && index < size) ? data[index] : 0;
    }

    void display() const
    {
        cout << "  ";
        for (int i = 0; i < size; i++)
        {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};

void exercise6()
{
    cout << "\n========== EXERCISE 6: Deep Copy with Dynamic Memory ==========" << endl;

    cout << "Creating arr1:" << endl;
    DynamicArray arr1(5);
    arr1.setValue(0, 10);
    arr1.setValue(1, 20);
    arr1.setValue(2, 30);

    cout << "arr1: ";
    arr1.display();

    cout << "Creating arr2 = arr1 (deep copy):" << endl;
    DynamicArray arr2 = arr1;

    cout << "arr2: ";
    arr2.display();

    cout << "\nModifying arr2:" << endl;
    arr2.setValue(1, 999);
    cout << "arr2: ";
    arr2.display();

    cout << "arr1 (unchanged): ";
    arr1.display();

    cout << "\nEach has separate memory (safe deletions)" << endl;
}

//============================================================================
// EXERCISE 7: Constructor Initialization
//============================================================================
class Rectangle
{
private:
    double width;
    double height;

public:
    Rectangle() : width(0), height(0)
    {
        cout << "  Default constructor" << endl;
    }

    // Using initializer list
    Rectangle(const Rectangle &other) : width(other.width), height(other.height)
    {
        cout << "  Copy constructor (initializer list)" << endl;
    }

    void setDimensions(double w, double h)
    {
        width = w;
        height = h;
    }

    double area() const { return width * height; }
};

void exercise7()
{
    cout << "\n========== EXERCISE 7: Member Initializer List ==========" << endl;

    Rectangle rect1;
    rect1.setDimensions(5.0, 10.0);
    cout << "rect1 area: " << rect1.area() << endl;

    cout << "\nCopying rect1 to rect2:" << endl;
    Rectangle rect2 = rect1;
    cout << "rect2 area: " << rect2.area() << endl;

    cout << "\nInitializer list:" << endl;
    cout << "  More efficient than assignment in body" << endl;
    cout << "  Required for const members" << endl;
    cout << "  Required for reference members" << endl;
}

//============================================================================
// EXERCISE 8: Cost Reference Parameter
//============================================================================
void exercise8()
{
    cout << "\n========== EXERCISE 8: Const Reference Parameter ==========" << endl;

    cout << "Why use const reference?" << endl;
    cout << "\nSignature: ClassName(const ClassName& other)" << endl;
    cout << endl;
    cout << "const - Promises not to modify original" << endl;
    cout << "& - Pass by reference (efficient, no copy)" << endl;

    cout << "\nWithout const:" << endl;
    cout << "ClassName(ClassName& other)  // WRONG" << endl;
    cout << "  - Cannot copy const objects" << endl;
    cout << "  - Cannot copy temporary objects" << endl;

    cout << "\nCorrect usage:" << endl;
    Animal a1;
    a1.setInfo("Testing", 1);
    Animal a2 = a1; // Works because copy constructor uses const&
}

//============================================================================
// EXERCISE 9: Comparing Copies
//============================================================================
void exercise9()
{
    cout << "\n========== EXERCISE 9: Comparing Copies ==========" << endl;

    Animal original;
    original.setInfo("Original", 7);

    Animal copy = original;
    copy.setInfo("Copy", 7);

    cout << "Original: ";
    original.display();
    cout << "Copy: ";
    copy.display();

    cout << "\nBoth have same data but separate storage" << endl;
    cout << "Modifying one doesn't affect the other" << endl;
}

//============================================================================
// EXERCISE 10: Copy in Collections
//============================================================================
void exercise10()
{
    cout << "\n========== EXERCISE 10: Copy Constructor in Use Cases ==========" << endl;

    cout << "Array of objects:" << endl;
    cout << "Animal animals[3];" << endl;
    Animal animals[3];

    animals[0].setInfo("Dog", 3);
    animals[1].setInfo("Cat", 2);
    animals[2].setInfo("Bird", 1);

    cout << "Array contents:" << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << "animals[" << i << "]: ";
        animals[i].display();
    }

    cout << "\nCopy from array:" << endl;
    cout << "Animal copy = animals[0];" << endl;
    Animal copy = animals[0];

    cout << "Copy: ";
    copy.display();
}

//============================================================================
// EXERCISE 11: Copy Constructor vs Assignment
//============================================================================
void exercise11()
{
    cout << "\n========== EXERCISE 11: Copy Constructor vs Assignment ==========" << endl;

    cout << "Copy Constructor (initialization):" << endl;
    cout << "Animal a1;" << endl;
    Animal a1;
    a1.setInfo("First", 1);
    cout << "Animal a2 = a1;  <- Copy constructor" << endl;
    Animal a2 = a1;

    cout << "\nAssignment Operator (existing object):" << endl;
    cout << "Animal a3;" << endl;
    Animal a3;
    a3.setInfo("Original", 3);
    cout << "a3 = a1;  <- Assignment operator" << endl;
    a3 = a1;

    cout << "\nDifference:" << endl;
    cout << "  Copy: NEW object created" << endl;
    cout << "  Assignment: EXISTING object updated" << endl;
}

//============================================================================
// EXERCISE 12: Shallow Copy Problem
//============================================================================
class StringHolder
{
private:
    char *str;

public:
    StringHolder(const char *s = "")
    {
        str = new char[strlen(s) + 1];
        strcpy(str, s);
        cout << "  Created: \"" << str << "\"" << endl;
    }

    // Deep copy constructor
    StringHolder(const StringHolder &other)
    {
        str = new char[strlen(other.str) + 1];
        strcpy(str, other.str);
        cout << "  Deep copied: \"" << str << "\"" << endl;
    }

    ~StringHolder()
    {
        cout << "  Deleted: \"" << str << "\"" << endl;
        delete[] str;
    }

    void display() const { cout << "  \"" << str << "\"" << endl; }
};

void exercise12()
{
    cout << "\n========== EXERCISE 12: Shallow vs Deep Copy ==========" << endl;

    cout << "Creating str1:" << endl;
    StringHolder str1("Hello");

    cout << "Creating str2 = str1 (deep copy):" << endl;
    StringHolder str2 = str1;

    cout << "\nBoth strings:" << endl;
    cout << "str1: ";
    str1.display();
    cout << "str2: ";
    str2.display();

    cout << "\nWith deep copy, each has own memory" << endl;
    cout << "With shallow copy: DISASTER (double delete)" << endl;
}

//============================================================================
// EXERCISE 13: Rule of Three
//============================================================================
void exercise13()
{
    cout << "\n========== EXERCISE 13: Rule of Three ==========" << endl;

    cout << "If you define any of these, define all three:" << endl;
    cout << endl;
    cout << "1. Destructor ~Class()" << endl;
    cout << "   - Manages cleanup of resources" << endl;
    cout << endl;
    cout << "2. Copy Constructor Class(const Class&)" << endl;
    cout << "   - Controls how objects are copied" << endl;
    cout << endl;
    cout << "3. Assignment Operator Class& operator=(const Class&)" << endl;
    cout << "   - Controls how objects are assigned" << endl;
    cout << endl;
    cout << "Why?" << endl;
    cout << "  If destructor needed -> managing resources" << endl;
    cout << "  If copying resources -> need copy constructor" << endl;
    cout << "  If copying -> need assignment operator" << endl;
}

//============================================================================
// MAIN FUNCTION - Run All Exercises
//============================================================================
int main()
{
    cout << "============================================" << endl;
    cout << "C++ COPY CONSTRUCTORS - PRACTICE EXERCISES" << endl;
    cout << "============================================" << endl;

    exercise1();
    // Uncomment the exercises below as you solve them:
    // exercise2();
    // exercise3();
    // exercise4();
    // exercise5();
    // exercise6();
    // exercise7();
    // exercise8();
    // exercise9();
    // exercise10();
    // exercise11();
    // exercise12();
    // exercise13();

    cout << "\n============================================" << endl;
    cout << "Great job practicing copy constructors!" << endl;
    cout << "============================================" << endl;

    return 0;
}

//============================================================================
// SOLUTIONS REFERENCE
//============================================================================
/*
 * EXERCISE 1 SOLUTION:
 * SimpleClass obj2 = obj1;  // Calls copy constructor
 *
 * EXERCISE 3 SOLUTION:
 * Animal dog2 = dog1;  // Assignment syntax
 * Animal dog3(dog1);   // Parentheses syntax
 * Both call copy constructor
 *
 * EXERCISE 6 SOLUTION - Deep Copy:
 * DynamicArray(const DynamicArray& other) : size(other.size) {
 *     data = new int[size];
 *     for (int i = 0; i < size; i++) {
 *         data[i] = other.data[i];
 *     }
 * }
 *
 * EXERCISE 7 SOLUTION - Initializer List:
 * Rectangle(const Rectangle& other) : width(other.width), height(other.height) {
 * }
 *
 * EXERCISE 12 SOLUTION - Deep Copy String:
 * StringHolder(const StringHolder& other) {
 *     str = new char[strlen(other.str) + 1];
 *     strcpy(str, other.str);
 * }
 */
