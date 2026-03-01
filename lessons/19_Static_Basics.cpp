//============================================================================
// Lesson 19: Static - Basics
// Author      : M'Barek Benraiss
// Description : Understanding static variables and static methods in C++
//               including class-level variables, initialization, and usage
//============================================================================

#include <iostream>
#include <vector>
using namespace std;

// ============================================================================
// SECTION 1: Static Member Variables - Shared Across All Objects
// ============================================================================
/*
Static member variables are shared among ALL instances of a class.
- Declared with 'static' keyword in class
- Must be initialized OUTSIDE the class (in .cpp file)
- All objects see the same value
- Memory allocated once, not per object

Example: Counter shared by all objects
*/

class Counter
{
private:
    int instanceID;
    static int totalCount; // Declaration (shared among all)

public:
    Counter()
    {
        instanceID = totalCount++;
    }

    int getID() const
    {
        return instanceID;
    }

    static int getTotalCount()
    {
        return totalCount;
    }
};

// IMPORTANT: Must define outside class
int Counter::totalCount = 0;

void section1_StaticMemberVariables()
{
    cout << "\n=== SECTION 1: Static Member Variables ===" << endl;

    cout << "Creating Counter objects:" << endl;

    Counter c1;
    cout << "After c1: Total count = " << Counter::getTotalCount() << endl;
    cout << "c1 ID = " << c1.getID() << endl;

    Counter c2;
    cout << "After c2: Total count = " << Counter::getTotalCount() << endl;
    cout << "c2 ID = " << c2.getID() << endl;

    Counter c3;
    cout << "After c3: Total count = " << Counter::getTotalCount() << endl;
    cout << "c3 ID = " << c3.getID() << endl;

    cout << "\nKey observation:" << endl;
    cout << "  Each object has unique instanceID" << endl;
    cout << "  But all share same totalCount variable" << endl;
    cout << "  totalCount persists across object lifetime" << endl;
}

// ============================================================================
// SECTION 2: Static Member Functions - Can Be Called Without Object
// ============================================================================
/*
Static member functions:
- Can be called directly on class (ClassName::functionName())
- Cannot access instance variables (no this pointer)
- Can access static variables
- Useful for utility functions related to class
*/

class BankAccount
{
private:
    double balance;
    static double totalFundsInBank;

public:
    BankAccount(double initialBalance) : balance(initialBalance)
    {
        totalFundsInBank += initialBalance;
    }

    void deposit(double amount)
    {
        balance += amount;
        totalFundsInBank += amount;
    }

    double getBalance() const
    {
        return balance;
    }

    // Static member function - can be called without object
    static double getTotalFunds()
    {
        return totalFundsInBank;
    }

    static void printBankInfo()
    {
        cout << "Total funds in bank: $" << totalFundsInBank << endl;
    }
};

double BankAccount::totalFundsInBank = 0.0;

void section2_StaticMemberFunctions()
{
    cout << "\n=== SECTION 2: Static Member Functions ===" << endl;

    cout << "Calling static function before creating objects:" << endl;
    cout << "Bank info: ";
    BankAccount::printBankInfo();

    cout << "\nCreating accounts:" << endl;
    BankAccount account1(1000.0);
    BankAccount account2(2500.0);

    cout << "Account 1 balance: $" << account1.getBalance() << endl;
    cout << "Account 2 balance: $" << account2.getBalance() << endl;

    cout << "\nCalling static function with objects existing:" << endl;
    BankAccount::printBankInfo();

    cout << "\nCan also call through object (discouraged):" << endl;
    account1.deposit(500);
    cout << "After deposit through account1: ";
    account1.printBankInfo(); // Works, but confusing
}

// ============================================================================
// SECTION 3: Static Const - Compile-Time Constants in Class
// ============================================================================
/*
Static const member variables can be initialized in the class declaration.
Often used for class-level constants that don't change.

Note: Requires constant expression at compile time
*/

class Circle
{
public:
    // Static const can be initialized in class
    static const double PI;
    static const int MAX_RADIUS;

private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    double getArea() const
    {
        return PI * radius * radius;
    }

    double getCircumference() const
    {
        return 2 * PI * radius;
    }

    static void printClassInfo()
    {
        cout << "Circle class - PI = " << PI << ", Max radius = " << MAX_RADIUS << endl;
    }
};

// Initialize outside class
const double Circle::PI = 3.14159265;
const int Circle::MAX_RADIUS = 1000;

void section3_StaticConst()
{
    cout << "\n=== SECTION 3: Static Const Members ===" << endl;

    cout << "Accessing class constants without object:" << endl;
    cout << "Circle::PI = " << Circle::PI << endl;
    cout << "Circle::MAX_RADIUS = " << Circle::MAX_RADIUS << endl;

    cout << "\nUsing with objects:" << endl;
    Circle circle1(5.0);
    cout << "Circle with radius 5:" << endl;
    cout << "  Area = " << circle1.getArea() << endl;
    cout << "  Circumference = " << circle1.getCircumference() << endl;

    Circle circle2(10.0);
    cout << "\nCircle with radius 10:" << endl;
    cout << "  Area = " << circle2.getArea() << endl;
    cout << "  Circumference = " << circle2.getCircumference() << endl;
}

// ============================================================================
// SECTION 4: Private Static Variables and Functions
// ============================================================================
/*
Static variables and functions can be private.
- Private static: hidden from outside, only class methods access
- Used for internal class state and utilities
- Promotes encapsulation
*/

class Logger
{
private:
    static int logLevel; // Private: only Logger accesses
    static int messageCount;

    // Private static function
    static string getCurrentTime()
    {
        return "[TIME]";
    }

public:
    Logger() {}

    static void setLogLevel(int level)
    {
        logLevel = level;
    }

    static void logMessage(string message)
    {
        if (logLevel >= 1)
        {
            cout << getCurrentTime() << " Message #" << messageCount++
                 << ": " << message << endl;
        }
    }

    static void logWarning(string warning)
    {
        if (logLevel >= 2)
        {
            cout << getCurrentTime() << " WARNING #" << messageCount++
                 << ": " << warning << endl;
        }
    }

    static int getMessageCount()
    {
        return messageCount;
    }
};

int Logger::logLevel = 1;
int Logger::messageCount = 0;

void section4_PrivateStatic()
{
    cout << "\n=== SECTION 4: Private Static Members ===" << endl;

    cout << "Using Logger with private static variables:" << endl;

    Logger::logMessage("System started");
    Logger::logMessage("User logged in");
    Logger::logWarning("Low memory");
    Logger::logMessage("File saved");

    cout << "\nTotal messages logged: " << Logger::getMessageCount() << endl;

    cout << "\nChanging log level:" << endl;
    Logger::setLogLevel(3);
    Logger::logMessage("New message");
}

// ============================================================================
// SECTION 5: Static Local Variables - Function Scope
// ============================================================================
/*
Static local variables (inside functions):
- Initialized once, retains value between calls
- Scope limited to function
- Useful for counters, caches, state within function
*/

void incrementCounter()
{
    static int callCount = 0; // Initialized once, persists
    callCount++;
    cout << "incrementCounter called " << callCount << " time(s)" << endl;
}

void section5_StaticLocalVariables()
{
    cout << "\n=== SECTION 5: Static Local Variables ===" << endl;

    cout << "Calling incrementCounter multiple times:" << endl;

    incrementCounter(); // callCount = 1
    incrementCounter(); // callCount = 2
    incrementCounter(); // callCount = 3
    incrementCounter(); // callCount = 4

    cout << "\nNote: Static local variable persists across function calls" << endl;
}

// ============================================================================
// SECTION 6: Object Tracking with Static Variables
// ============================================================================
/*
Real-world use: Track how many objects of a class exist
- Increment in constructor
- Decrement in destructor
- Useful for resource management
*/

class Student
{
private:
    string name;
    static int totalStudents;

public:
    Student(string n) : name(n)
    {
        totalStudents++;
        cout << "Student " << name << " created (Total: " << totalStudents << ")" << endl;
    }

    ~Student()
    {
        totalStudents--;
        cout << "Student " << name << " destroyed (Total: " << totalStudents << ")" << endl;
    }

    string getName() const
    {
        return name;
    }

    static int getTotalStudents()
    {
        return totalStudents;
    }

    static void printRoster()
    {
        cout << "Total students in class: " << totalStudents << endl;
    }
};

int Student::totalStudents = 0;

void section6_ObjectTracking()
{
    cout << "\n=== SECTION 6: Object Tracking with Static ===" << endl;

    cout << "Initial student count: " << Student::getTotalStudents() << endl;

    {
        cout << "\nCreating students in scope:" << endl;
        Student s1("Alice");
        Student s2("Bob");
        Student s3("Charlie");

        Student::printRoster();
    }

    cout << "\nAfter scope (destructors called):" << endl;
    Student::printRoster();
}

// ============================================================================
// SECTION 7: Static in Inheritance
// ============================================================================
/*
Static members are inherited but shared at base class level.
- Derived classes share same static as base
- Not overridable (static is not virtual)
- All derived classes see same static value
*/

class Vehicle
{
protected:
    static int totalVehicles;

public:
    Vehicle()
    {
        totalVehicles++;
    }

    static int getTotalVehicles()
    {
        return totalVehicles;
    }
};

int Vehicle::totalVehicles = 0;

class Car : public Vehicle
{
public:
    Car() : Vehicle() {}
};

class Motorcycle : public Vehicle
{
public:
    Motorcycle() : Vehicle() {}
};

void section7_StaticInheritance()
{
    cout << "\n=== SECTION 7: Static in Inheritance ===" << endl;

    cout << "Creating vehicles:" << endl;

    Car car1;
    cout << "After Car: Total vehicles = " << Vehicle::getTotalVehicles() << endl;

    Motorcycle moto1;
    cout << "After Motorcycle: Total vehicles = " << Vehicle::getTotalVehicles() << endl;

    Car car2;
    cout << "After another Car: Total vehicles = " << Vehicle::getTotalVehicles() << endl;

    cout << "\nAll derived classes share base class static variable" << endl;
}

// ============================================================================
// SECTION 8: Container of All Objects (using Static Vector)
// ============================================================================
/*
Advanced pattern: Keep static vector of all objects created
- Useful for managing all instances
- Can iterate through all objects
- Registry pattern
*/

class Employee
{
private:
    string id;
    string name;
    static vector<Employee *> allEmployees;

public:
    Employee(string empID, string empName) : id(empID), name(empName)
    {
        allEmployees.push_back(this);
    }

    ~Employee()
    {
        // In practice, would safely remove from vector
    }

    string getID() const { return id; }
    string getName() const { return name; }

    static void printAllEmployees()
    {
        cout << "Employee Roster (" << allEmployees.size() << " total):" << endl;
        for (Employee *emp : allEmployees)
        {
            cout << "  " << emp->getID() << ": " << emp->getName() << endl;
        }
    }

    static int getTotalEmployees()
    {
        return allEmployees.size();
    }
};

vector<Employee *> Employee::allEmployees;

void section8_ContainerPattern()
{
    cout << "\n=== SECTION 8: Static Container Pattern ===" << endl;

    cout << "Creating employees:" << endl;
    Employee e1("E001", "Alice Johnson");
    Employee e2("E002", "Bob Smith");
    Employee e3("E003", "Charlie Brown");

    cout << "\nTotal employees: " << Employee::getTotalEmployees() << endl;

    Employee::printAllEmployees();
}

// ============================================================================
// SECTION 9: Practical Example - Game Settings
// ============================================================================
/*
Real-world scenario: Global game settings accessed throughout code
- All game objects use same settings
- Changed once, affects everywhere
- No need to pass settings to every function
*/

class GameSettings
{
public:
    static const int SCREEN_WIDTH;
    static const int SCREEN_HEIGHT;
    static const float DEFAULT_VOLUME;

    static bool soundEnabled;
    static int difficulty;

    static void printSettings()
    {
        cout << "Game Settings:" << endl;
        cout << "  Resolution: " << SCREEN_WIDTH << "x" << SCREEN_HEIGHT << endl;
        cout << "  Volume: " << DEFAULT_VOLUME << endl;
        cout << "  Sound: " << (soundEnabled ? "ON" : "OFF") << endl;
        cout << "  Difficulty: " << difficulty << endl;
    }

    static void setDifficulty(int level)
    {
        difficulty = level;
    }

    static void toggleSound()
    {
        soundEnabled = !soundEnabled;
    }
};

const int GameSettings::SCREEN_WIDTH = 1920;
const int GameSettings::SCREEN_HEIGHT = 1080;
const float GameSettings::DEFAULT_VOLUME = 0.8f;

bool GameSettings::soundEnabled = true;
int GameSettings::difficulty = 1;

void section9_GameSettings()
{
    cout << "\n=== SECTION 9: Practical Example - Game Settings ===" << endl;

    cout << "Initial settings:" << endl;
    GameSettings::printSettings();

    cout << "\nChanging settings:" << endl;
    GameSettings::setDifficulty(3);
    GameSettings::toggleSound();

    cout << "\nAfter changes:" << endl;
    GameSettings::printSettings();
}

// ============================================================================
// MAIN
// ============================================================================

int main()
{
    cout << "============= Static Variables and Methods - Complete Basics =============" << endl;

    section1_StaticMemberVariables();
    section2_StaticMemberFunctions();
    section3_StaticConst();
    section4_PrivateStatic();
    section5_StaticLocalVariables();
    section6_ObjectTracking();
    section7_StaticInheritance();
    section8_ContainerPattern();
    section9_GameSettings();

    cout << "\n============= All Sections Completed =============" << endl;

    return 0;
}

/*
/Users/benraiss/CLionProjects/learnCpp/cmake-build-debug/learnCpp
============= Static Variables and Methods - Complete Basics =============

=== SECTION 1: Static Member Variables ===
Creating Counter objects:
After c1: Total count = 1
c1 ID = 0
After c2: Total count = 2
c2 ID = 1
After c3: Total count = 3
c3 ID = 2

Key observation:
  Each object has unique instanceID
  But all share same totalCount variable
  totalCount persists across object lifetime

=== SECTION 2: Static Member Functions ===
Calling static function before creating objects:
Bank info: Total funds in bank: $0

Creating accounts:
Account 1 balance: $1000
Account 2 balance: $2500

Calling static function with objects existing:
Total funds in bank: $3500

Can also call through object (discouraged):
After deposit through account1: Total funds in bank: $4000

=== SECTION 3: Static Const Members ===
Accessing class constants without object:
Circle::PI = 3.14159
Circle::MAX_RADIUS = 1000

Using with objects:
Circle with radius 5:
  Area = 78.5398
  Circumference = 31.4159

Circle with radius 10:
  Area = 314.159
  Circumference = 62.8319

=== SECTION 4: Private Static Members ===
Using Logger with private static variables:
[TIME] Message #0: System started
[TIME] Message #1: User logged in
[TIME] Message #2: File saved

Total messages logged: 3

Changing log level:
[TIME] Message #3: New message

=== SECTION 5: Static Local Variables ===
Calling incrementCounter multiple times:
incrementCounter called 1 time(s)
incrementCounter called 2 time(s)
incrementCounter called 3 time(s)
incrementCounter called 4 time(s)

Note: Static local variable persists across function calls

=== SECTION 6: Object Tracking with Static ===
Initial student count: 0

Creating students in scope:
Student Alice created (Total: 1)
Student Bob created (Total: 2)
Student Charlie created (Total: 3)
Total students in class: 3
Student Charlie destroyed (Total: 2)
Student Bob destroyed (Total: 1)
Student Alice destroyed (Total: 0)

After scope (destructors called):
Total students in class: 0

=== SECTION 7: Static in Inheritance ===
Creating vehicles:
After Car: Total vehicles = 1
After Motorcycle: Total vehicles = 2
After another Car: Total vehicles = 3

All derived classes share base class static variable

=== SECTION 8: Static Container Pattern ===
Creating employees:

Total employees: 3
Employee Roster (3 total):
  E001: Alice Johnson
  E002: Bob Smith
  E003: Charlie Brown

=== SECTION 9: Practical Example - Game Settings ===
Initial settings:
Game Settings:
  Resolution: 1920x1080
  Volume: 0.8
  Sound: ON
  Difficulty: 1

Changing settings:

After changes:
Game Settings:
  Resolution: 1920x1080
  Volume: 0.8
  Sound: OFF
  Difficulty: 3

============= All Sections Completed =============

Process finished with exit code 0


*/