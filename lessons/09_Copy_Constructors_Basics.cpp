//============================================================================
// Lesson: Copy Constructors in C++
// Author: M'Barek Benraiss
// Date: February 27, 2026
// Topic: Understanding Copy Constructors and Object Copying
//============================================================================
/*
 * COPY CONSTRUCTORS
 * =================
 * A copy constructor creates a new object as a copy of an existing object.
 *
 * KEY POINTS:
 * ===========
 * - Copy constructor takes const reference to same class
 * - Called when object is initialized with another object
 * - Automatically generated if not defined
 * - Performs memberwise copy by default
 * - Important for objects managing resources
 *
 * SYNTAX:
 * =======
 * ClassName(const ClassName& other) {
 *     // Copy logic here
 * }
 *
 * WHEN IT'S CALLED:
 * =================
 * 1. Object assignment: ClassName obj2 = obj1;
 * 2. Function parameters: func(ClassName obj)
 * 3. Return values: return ClassName obj;
 * 4. Explicit call: ClassName obj2(obj1);
 */

#include <iostream>
#include <cstring>
using namespace std;

//============================================================================
// Section 1: What is a Copy Constructor?
//============================================================================
int section1()
{
    cout << "\n========== SECTION 1: What is a Copy Constructor? ==========" << endl;
    cout << "A copy constructor creates a new object from an existing one" << endl;

    cout << "\nDefault copy constructor created by C++:" << endl;
    cout << "  ClassName(const ClassName& other)" << endl;
    cout << "  {" << endl;
    cout << "    // Default: copies all member variables" << endl;
    cout << "  }" << endl;

    cout << "\nWhy use copy constructors?" << endl;
    cout << "  ✓ Control how objects are copied" << endl;
    cout << "  ✓ Manage resources (memory, files, connections)" << endl;
    cout << "  ✓ Deep copy vs shallow copy" << endl;
    cout << "  ✓ Prevent unintended modifications" << endl;

    return 0;
}

//============================================================================
// Section 2: Simple Class Without Copy Constructor
//============================================================================
class SimpleAnimal
{
private:
    string name;

public:
    SimpleAnimal()
    {
        cout << "  SimpleAnimal default constructor called" << endl;
    }

    void setName(string n)
    {
        name = n;
    }

    void display() const
    {
        cout << "  Name: " << name << endl;
    }
};

int section2()
{
    cout << "\n========== SECTION 2: Default Copying Behavior ==========" << endl;
    cout << "Without explicit copy constructor, C++ uses memberwise copy" << endl;

    cout << "\nCreating animal1:" << endl;
    SimpleAnimal animal1;
    animal1.setName("Freddy");

    cout << "\nCopying: SimpleAnimal animal2 = animal1;" << endl;
    SimpleAnimal animal2 = animal1;

    cout << "\nDisplaying both:" << endl;
    cout << "animal1: ";
    animal1.display();
    cout << "animal2: ";
    animal2.display();

    cout << "\nBoth have independent copies of 'name'" << endl;

    return 0;
}

//============================================================================
// Section 3: Explicit Copy Constructor
//============================================================================
class Animal
{
private:
    string name;

public:
    // Default constructor
    Animal()
    {
        cout << "  Animal default constructor called" << endl;
    }

    // Copy constructor
    Animal(const Animal &other) : name(other.name)
    {
        cout << "  Animal copy constructor called (copying: " << other.name << ")" << endl;
    }

    void setName(string n)
    {
        name = n;
    }

    void display() const
    {
        cout << "  Name: " << name << endl;
    }
};

int section3()
{
    cout << "\n========== SECTION 3: Explicit Copy Constructor ==========" << endl;
    cout << "Defining a copy constructor with custom logic" << endl;

    cout << "\nAnimal(const Animal& other) : name(other.name) {" << endl;
    cout << "    cout << \"Animal copy constructor called\" << endl;" << endl;
    cout << "}" << endl;

    cout << "\nCreating animal1:" << endl;
    Animal animal1;
    animal1.setName("Freddy");

    cout << "\nCopying: Animal animal2 = animal1;" << endl;
    Animal animal2 = animal1;

    cout << "\nDisplaying animals:" << endl;
    cout << "animal1: ";
    animal1.display();
    cout << "animal2: ";
    animal2.display();

    return 0;
}

//============================================================================
// Section 4: How Copy Constructor is Called
//============================================================================
class Dog
{
private:
    string name;

public:
    Dog()
    {
        cout << "    Default constructor" << endl;
    }

    Dog(const Dog &other) : name(other.name)
    {
        cout << "    Copy constructor (copying: " << other.name << ")" << endl;
    }

    void setName(string n) { name = n; }
    void display() const { cout << "Dog: " << name << endl; }
};

void takeDogByValue(Dog d)
{
    cout << "  Inside function:" << endl;
    d.display();
}

int section4()
{
    cout << "\n========== SECTION 4: When Copy Constructor is Called ==========" << endl;

    cout << "\nCase 1: Direct assignment" << endl;
    cout << "Dog dog1;" << endl;
    Dog dog1;
    dog1.setName("Buddy");

    cout << "Dog dog2 = dog1;  (calls copy constructor)" << endl;
    Dog dog2 = dog1;

    cout << "\nCase 2: Parentheses initialization" << endl;
    cout << "Dog dog3(dog1);  (calls copy constructor)" << endl;
    Dog dog3(dog1);

    cout << "\nCase 3: Passing by value (calls copy constructor)" << endl;
    cout << "takeDogByValue(dog1);  (copies into function parameter)" << endl;
    takeDogByValue(dog1);

    cout << "\nCase 4: Implicit in expressions" << endl;
    cout << "Dog dog4 = dog1;  (calls copy constructor)" << endl;
    Dog dog4 = dog1;

    return 0;
}

//============================================================================
// Section 5: Deep vs Shallow Copy
//============================================================================
class ShallowCopy
{
public:
    int *data;

    ShallowCopy(int size)
    {
        data = new int[size];
        cout << "  Allocated memory at " << (void *)data << endl;
    }

    ~ShallowCopy()
    {
        delete[] data;
        cout << "  Deallocated memory at " << (void *)data << endl;
    }
};

class DeepCopy
{
public:
    int *data;
    int size;

    DeepCopy(int sz) : size(sz)
    {
        data = new int[size];
        cout << "  Allocated memory at " << (void *)data << endl;
    }

    // Deep copy constructor
    DeepCopy(const DeepCopy &other) : size(other.size)
    {
        data = new int[size]; // Allocate new memory
        for (int i = 0; i < size; i++)
        {
            data[i] = other.data[i]; // Copy values
        }
        cout << "  Deep copied to new memory at " << (void *)data << endl;
    }

    ~DeepCopy()
    {
        delete[] data;
        cout << "  Deallocated memory at " << (void *)data << endl;
    }
};

int section5()
{
    cout << "\n========== SECTION 5: Deep Copy vs Shallow Copy ==========" << endl;

    cout << "\nSHALLOW COPY (default): Both point to same memory" << endl;
    cout << "(This is DANGEROUS with dynamic memory!)" << endl;
    cout << "ShallowCopy obj1(5):" << endl;
    ShallowCopy obj1(5);

    cout << "ShallowCopy obj2 = obj1;  (shallow copy - both point to same memory!)" << endl;
    ShallowCopy obj2 = obj1;
    cout << "obj1.data = " << (void *)obj1.data << endl;
    cout << "obj2.data = " << (void *)obj2.data << endl;
    cout << "WARNING: Both point to SAME memory - delete called twice!" << endl;

    // This would cause double-delete error if destructors run
    // Instead, let's show deep copy

    cout << "\nDEEP COPY (custom): Each has own memory" << endl;
    cout << "DeepCopy obj3(5):" << endl;
    DeepCopy obj3(5);

    cout << "DeepCopy obj4(obj3);  (deep copy - separate memory)" << endl;
    DeepCopy obj4(obj3);
    cout << "obj3.data = " << (void *)obj3.data << endl;
    cout << "obj4.data = " << (void *)obj4.data << endl;
    cout << "SAFE: Each has own memory - safe to delete separately" << endl;

    return 0;
}

//============================================================================
// Section 6: Copy Constructor vs Assignment Operator
//============================================================================
class Person
{
private:
    string name;

public:
    Person() : name("")
    {
        cout << "  Default constructor" << endl;
    }

    // Copy constructor
    Person(const Person &other) : name(other.name)
    {
        cout << "  Copy constructor" << endl;
    }

    // Assignment operator (different!)
    Person &operator=(const Person &other)
    {
        if (this != &other)
        {
            name = other.name;
        }
        cout << "  Assignment operator" << endl;
        return *this;
    }

    void setName(string n) { name = n; }
    string getName() const { return name; }
};

int section6()
{
    cout << "\n========== SECTION 6: Copy Constructor vs Assignment ==========" << endl;

    cout << "\nCopy Constructor:" << endl;
    cout << "Person p1;" << endl;
    Person p1;
    p1.setName("Alice");

    cout << "Person p2 = p1;  (calls COPY CONSTRUCTOR - new object)" << endl;
    Person p2 = p1;

    cout << "\nAssignment Operator:" << endl;
    cout << "Person p3;" << endl;
    Person p3;
    p3.setName("Charlie");

    cout << "p3 = p1;  (calls ASSIGNMENT OPERATOR - existing object)" << endl;
    p3 = p1;

    cout << "\nDifference:" << endl;
    cout << "  Copy constructor: Creates NEW object during initialization" << endl;
    cout << "  Assignment: Assigns to EXISTING object" << endl;

    return 0;
}

//============================================================================
// Section 7: Const Reference Parameter
//============================================================================
int section7()
{
    cout << "\n========== SECTION 7: Const Reference in Copy Constructor ==========" << endl;

    cout << "\nWhy const reference?" << endl;
    cout << "ClassName(const ClassName& other)" << endl;
    cout << endl;
    cout << "const: Promises we won't modify the original" << endl;
    cout << "&: Passes by reference (efficient, avoids copy)" << endl;

    cout << "\nWithout const:" << endl;
    cout << "ClassName(ClassName& other)  // Wrong!" << endl;
    cout << "  - Cannot pass temporary objects" << endl;
    cout << "  - Cannot pass const objects" << endl;

    cout << "\nRules:" << endl;
    cout << "  ✓ Use const reference" << endl;
    cout << "  ✓ This allows copying from any Animal object" << endl;
    cout << "  ✓ Signals: We read, don't modify" << endl;

    return 0;
}

//============================================================================
// Section 8: Member Initializer List
//============================================================================
class Book
{
private:
    string title;
    string author;
    int pages;

public:
    Book() : title(""), author(""), pages(0)
    {
        cout << "  Default constructor (using initializer list)" << endl;
    }

    // Copy constructor using initializer list
    Book(const Book &other) : title(other.title), author(other.author), pages(other.pages)
    {
        cout << "  Copy constructor (copying: " << other.title << ")" << endl;
    }

    void setInfo(string t, string a, int p)
    {
        title = t;
        author = a;
        pages = p;
    }

    void display() const
    {
        cout << "  Title: " << title << ", Author: " << author << ", Pages: " << pages << endl;
    }
};

int section8()
{
    cout << "\n========== SECTION 8: Member Initializer List ==========" << endl;

    cout << "\nUsing initializer list in copy constructor:" << endl;
    cout << "Book(const Book& other) : title(other.title), author(other.author), pages(other.pages) {" << endl;
    cout << "    // Member variables initialized before body" << endl;
    cout << "}" << endl;

    cout << "\nAdvantages:" << endl;
    cout << "  ✓ More efficient" << endl;
    cout << "  ✓ Works for const members" << endl;
    cout << "  ✓ Works for references" << endl;
    cout << "  ✓ Can call constructors" << endl;

    cout << "\nCreating book1:" << endl;
    Book book1;
    book1.setInfo("C++ Primer", "Stanley Lippman", 600);

    cout << "\nCopying: Book book2 = book1;" << endl;
    Book book2 = book1;

    cout << "book1: ";
    book1.display();
    cout << "book2: ";
    book2.display();

    return 0;
}

//============================================================================
// MAIN FUNCTION
//============================================================================
int main()
{
    cout << "============================================" << endl;
    cout << "C++ COPY CONSTRUCTORS - COMPLETE GUIDE" << endl;
    cout << "============================================" << endl;

    section1();
    section2();
    section3();
    section4();
    section5();
    section6();
    section7();
    section8();

    cout << "\n============================================" << endl;
    cout << "Copy Constructors Learned!" << endl;
    cout << "============================================" << endl;

    return 0;
}

//============================================================================
// KEY LEARNING POINTS:
// ====================
// 1. Copy constructor is called when creating object from existing one
// 2. Syntax: ClassName(const ClassName& other)
// 3. Must use const reference as parameter
// 4. Default copy is memberwise (shallow) copy
// 5. Deep copy needed for dynamic memory management
// 6. Copy constructor differs from assignment operator
// 7. Called for assignment, function parameters, returns
// 8. Use member initializer list for efficiency
//
// COPY CONSTRUCTOR SIGNATURE:
// ===========================
// ClassName(const ClassName& other) {
//     // Copy member variables from other
// }
//
// WHEN IT'S CALLED:
// =================
// - Object initialization: ClassName obj2 = obj1;
// - Explicit call: ClassName obj2(obj1);
// - Function parameters: func(ClassName obj)
// - Return values: return ClassName();
//
// SHALLOW vs DEEP COPY:
// =====================
// Shallow: Point to same memory location (default)
// Deep: Create new copy of data (required for pointers)
//
// BEST PRACTICES:
// ===============
// • Use const reference parameter
// • Use member initializer list
// • Define if managing dynamic memory
// • Copy assignment operator too
// • Follow rule of three/five
//============================================================================

/*
    * COPY CONSTRUCTORS - PRACTICE EXERCISES
    * =======================================
    * 1. Create a simple class and demonstrate default copying behavior.
    * 2. Define a copy constructor and show when it's called.
    * 3. Create a class with dynamic memory and implement deep copy.
    * 4. Compare copy constructor vs assignment operator.
    * 5. Use member initializer list in copy constructor.
    * 6. Show copy constructor in function parameters and return values.
    * 7. Create an array of objects and demonstrate copying.

============================================
C++ COPY CONSTRUCTORS - COMPLETE GUIDE
============================================

========== SECTION 1: What is a Copy Constructor? ==========
A copy constructor creates a new object from an existing one

Default copy constructor created by C++:
  ClassName(const ClassName& other)
  {
    // Default: copies all member variables
  }

Why use copy constructors?
  ✓ Control how objects are copied
  ✓ Manage resources (memory, files, connections)
  ✓ Deep copy vs shallow copy
  ✓ Prevent unintended modifications

========== SECTION 2: Default Copying Behavior ==========
Without explicit copy constructor, C++ uses memberwise copy

Creating animal1:
  SimpleAnimal default constructor called

Copying: SimpleAnimal animal2 = animal1;

Displaying both:
animal1:   Name: Freddy
animal2:   Name: Freddy

Both have independent copies of 'name'

========== SECTION 3: Explicit Copy Constructor ==========
Defining a copy constructor with custom logic

Animal(const Animal& other) : name(other.name) {
    cout << "Animal copy constructor called" << endl;
}

Creating animal1:
  Animal default constructor called

Copying: Animal animal2 = animal1;
  Animal copy constructor called (copying: Freddy)

Displaying animals:
animal1:   Name: Freddy
animal2:   Name: Freddy

========== SECTION 4: When Copy Constructor is Called ==========

Case 1: Direct assignment
Dog dog1;
    Default constructor
Dog dog2 = dog1;  (calls copy constructor)
    Copy constructor (copying: Buddy)

Case 2: Parentheses initialization
Dog dog3(dog1);  (calls copy constructor)
    Copy constructor (copying: Buddy)

Case 3: Passing by value (calls copy constructor)
takeDogByValue(dog1);  (copies into function parameter)
    Copy constructor (copying: Buddy)
  Inside function:
Dog: Buddy

Case 4: Implicit in expressions
Dog dog4 = dog1;  (calls copy constructor)
    Copy constructor (copying: Buddy)

========== SECTION 5: Deep Copy vs Shallow Copy ==========

SHALLOW COPY (default): Both point to same memory
(This is DANGEROUS with dynamic memory!)
ShallowCopy obj1(5):
  Allocated memory at 0x1012e5b70
ShallowCopy obj2 = obj1;  (shallow copy - both point to same memory!)
obj1.data = 0x1012e5b70
obj2.data = 0x1012e5b70
WARNING: Both point to SAME memory - delete called twice!

DEEP COPY (custom): Each has own memory
DeepCopy obj3(5):
  Allocated memory at 0x1012e5b90
DeepCopy obj4(obj3);  (deep copy - separate memory)
  Deep copied to new memory at 0x1012e59c0
obj3.data = 0x1012e5b90
obj4.data = 0x1012e59c0
SAFE: Each has own memory - safe to delete separately
  Deallocated memory at 0x1012e59c0
  Deallocated memory at 0x1012e5b90
  Deallocated memory at 0x1012e5b70


*/