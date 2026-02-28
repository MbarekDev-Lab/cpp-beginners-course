//============================================================================
// Lesson 14: Namespaces - Exercises
// Author      : M'Barek Benraiss
// Description : Progressive exercises for understanding namespaces,
//               scope resolution, and code organization
//============================================================================

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

// ============================================================================
// EXERCISE 1: Basic Namespace Creation
// ============================================================================
/*
EXERCISE 1: Create a namespace called "vehicles"
- Add a class "Car" with a function drive() that prints "Car is driving"
- In main, create a Car object and call drive()
- Use the fully qualified name (scope resolution operator)

Solution provided below - uncomment to test
*/

namespace vehicles {
    class Car {
    public:
        void drive() const {
            cout << "Car is driving" << endl;
        }
    };
}

void exercise1() {
    cout << "\n--- Exercise 1: Basic Namespace Creation ---" << endl;
    vehicles::Car myCar;
    myCar.drive();
    cout << "SUCCESS: Basic namespace created and used" << endl;
}


// ============================================================================
// EXERCISE 2: Multiple Namespaces with Same Class Names
// ============================================================================
/*
EXERCISE 2: Create two namespaces with classes of same name
- Create namespace "sports" with class "Ball"
- Create namespace "shapes" with class "Ball"
- sports::Ball should have roll()
- shapes::Ball should have draw()
- In main, create objects from both and call their respective methods

Solution provided below
*/

namespace sports {
    class Ball {
    public:
        void roll() const {
            cout << "Sports ball rolling" << endl;
        }
    };
}

namespace shapes {
    class Ball {
    public:
        void draw() const {
            cout << "Drawing geometric ball" << endl;
        }
    };
}

void exercise2() {
    cout << "\n--- Exercise 2: Multiple Namespaces, Same Names ---" << endl;
    sports::Ball sportsBall;
    sportsBall.roll();
    
    shapes::Ball geometricBall;
    geometricBall.draw();
    
    cout << "SUCCESS: No name collision with different namespaces" << endl;
}


// ============================================================================
// EXERCISE 3: Scope Resolution with Variables and Constants
// ============================================================================
/*
EXERCISE 3: Namespace with constants and variables
- Create namespace "colors" with constants RED, GREEN, BLUE (as strings)
- Create namespace "numbers" with constants RED = 1, GREEN = 2, BLUE = 3
- In main, access and print all values using scope resolution
- Verify they don't conflict

Solution provided below
*/

namespace colors {
    const string RED = "Red";
    const string GREEN = "Green";
    const string BLUE = "Blue";
}

namespace numbers {
    const int RED = 1;
    const int GREEN = 2;
    const int BLUE = 3;
}

void exercise3() {
    cout << "\n--- Exercise 3: Constants in Different Namespaces ---" << endl;
    cout << "colors::RED = " << colors::RED << endl;
    cout << "numbers::RED = " << numbers::RED << endl;
    cout << "colors::GREEN = " << colors::GREEN << endl;
    cout << "numbers::GREEN = " << numbers::GREEN << endl;
    cout << "SUCCESS: Constants with same names don't conflict" << endl;
}


// ============================================================================
// EXERCISE 4: Using Namespace Directive
// ============================================================================
/*
EXERCISE 4: Using namespace directive
- Create namespace "math" with function add(int a, int b) that returns sum
- Create namespace "math2" with function add(int a, int b, int c) that returns sum of 3
- Use "using namespace math;" and call add(5, 3)
- Then call math2::add(5, 3, 2) with full qualification
- Print both results

Solution provided below
*/

namespace math {
    int add(int a, int b) {
        return a + b;
    }
}

namespace math2 {
    int add(int a, int b, int c) {
        return a + b + c;
    }
}

void exercise4() {
    cout << "\n--- Exercise 4: Using Namespace Directive ---" << endl;
    
    using namespace math;
    cout << "add(5, 3) = " << add(5, 3) << endl;
    
    // Still need qualification for different namespace
    cout << "math2::add(5, 3, 2) = " << math2::add(5, 3, 2) << endl;
    
    cout << "SUCCESS: Using directive allows unqualified access" << endl;
}


// ============================================================================
// EXERCISE 5: Using Declaration for Specific Members
// ============================================================================
/*
EXERCISE 5: Using declaration for specific members
- Create namespace "logging" with functions log(), error(), warning()
- Use "using logging::log;" (import only log function)
- Call log() directly
- Call error() and warning() with qualification
- Show that only log() is imported

Solution provided below
*/

namespace logging {
    void log() {
        cout << "[LOG] This is a log message" << endl;
    }
    void error() {
        cout << "[ERROR] This is an error message" << endl;
    }
    void warning() {
        cout << "[WARNING] This is a warning message" << endl;
    }
}

void exercise5() {
    cout << "\n--- Exercise 5: Using Declaration (Specific Members) ---" << endl;
    
    using logging::log;
    log();
    
    // These still need qualification because they're not imported
    logging::error();
    logging::warning();
    
    cout << "SUCCESS: Can import specific members from namespace" << endl;
}


// ============================================================================
// EXERCISE 6: Nested Namespaces
// ============================================================================
/*
EXERCISE 6: Create nested namespace structure
- Create namespace "company"
  - Inside: namespace "hr" with Employee class
  - Inside: namespace "sales" with SalesRep class
- Both classes should have getName() method
- In main, create objects from both nested namespaces
- Access using fully qualified names

Solution provided below
*/

namespace company {
    namespace hr {
        class Employee {
        private:
            string name;
        public:
            Employee(string n) : name(n) { }
            string getName() const { return name; }
        };
    }
    
    namespace sales {
        class SalesRep {
        private:
            string name;
        public:
            SalesRep(string n) : name(n) { }
            string getName() const { return name; }
        };
    }
}

void exercise6() {
    cout << "\n--- Exercise 6: Nested Namespaces ---" << endl;
    
    company::hr::Employee emp("Alice");
    company::sales::SalesRep rep("Bob");
    
    cout << "HR Employee: " << emp.getName() << endl;
    cout << "Sales Rep: " << rep.getName() << endl;
    
    cout << "SUCCESS: Nested namespaces organize hierarchically" << endl;
}


// ============================================================================
// EXERCISE 7: Namespace Aliases
// ============================================================================
/*
EXERCISE 7: Create and use namespace aliases
- Create namespace "very_long_company_name::department::subdepartment"
- Create an alias "dept = very_long_company_name::department::subdepartment"
- Use the alias for easier access

For simplicity showing simplified version:
*/

namespace very_long_company_name {
    namespace department {
        namespace subdepartment {
            class Tool {
            public:
                void use() {
                    cout << "Using tool" << endl;
                }
            };
        }
    }
}

void exercise7() {
    cout << "\n--- Exercise 7: Namespace Aliases ---" << endl;
    
    // Create alias for long namespace path
    namespace dept = very_long_company_name::department::subdepartment;
    
    dept::Tool tool;
    tool.use();
    
    cout << "SUCCESS: Namespace aliases simplify access" << endl;
}


// ============================================================================
// EXERCISE 8: Anonymous Namespace (File-Scope Symbols)
// ============================================================================
/*
EXERCISE 8: Use anonymous namespace for internal helpers
- Create an anonymous namespace with a helper function helperCalculate()
- Create a public function calculate() that uses the helper
- The helper should not be directly accessible outside

Solution provided below
*/

namespace {
    // Internal linkage - not visible outside this file
    int helperMultiply(int a, int b) {
        return a * b;
    }
}

int calculate(int a, int b) {
    return helperMultiply(a, b) + 10;
}

void exercise8() {
    cout << "\n--- Exercise 8: Anonymous Namespace ---" << endl;
    
    int result = calculate(5, 3);
    cout << "calculate(5, 3) = " << result << endl;
    
    // This would fail to compile:
    // helperMultiply(5, 3);  // ERROR: not visible outside namespace
    
    cout << "SUCCESS: Anonymous namespace hides internal helpers" << endl;
}


// ============================================================================
// EXERCISE 9: Namespace with Multiple Classes and Functions
// ============================================================================
/*
EXERCISE 9: Create a complete namespace module
- Create namespace "database" with:
  * class Record with setData() and getData()
  * function connect() that returns connection status
  * function query() that processes data
- In main, use all features of the database namespace

Solution provided below
*/

namespace database {
    class Record {
    private:
        string data;
    public:
        void setData(string d) { data = d; }
        string getData() const { return data; }
    };
    
    bool connect() {
        cout << "Connected to database" << endl;
        return true;
    }
    
    void query(const string& sql) {
        cout << "Executing query: " << sql << endl;
    }
}

void exercise9() {
    cout << "\n--- Exercise 9: Complete Namespace Module ---" << endl;
    
    if (database::connect()) {
        database::query("SELECT * FROM users");
        
        database::Record rec;
        rec.setData("User123");
        cout << "Record data: " << rec.getData() << endl;
    }
    
    cout << "SUCCESS: Complete namespace module with classes and functions" << endl;
}


// ============================================================================
// EXERCISE 10: Organizing a Multi-Module Application
// ============================================================================
/*
EXERCISE 10: Organize a simple application with namespaces
- Create namespace "FileModule" with Reader and Writer classes
- Create namespace "DataModule" with Processor and Analyzer classes
- Create namespace "UIModule" with Display class
- In main, simulate application workflow:
  * Read file (FileModule)
  * Process data (DataModule)
  * Display results (UIModule)

Solution provided below
*/

namespace FileModule {
    class Reader {
    public:
        void read(const string& file) {
            cout << "Reading file: " << file << endl;
        }
    };
}

namespace DataModule {
    class Processor {
    public:
        void process() {
            cout << "Processing data" << endl;
        }
    };
}

namespace UIModule {
    class Display {
    public:
        void show(const string& result) {
            cout << "Displaying: " << result << endl;
        }
    };
}

void exercise10() {
    cout << "\n--- Exercise 10: Multi-Module Application ---" << endl;
    
    FileModule::Reader reader;
    reader.read("data.txt");
    
    DataModule::Processor processor;
    processor.process();
    
    UIModule::Display display;
    display.show("Processing complete");
    
    cout << "SUCCESS: Modular application organized with namespaces" << endl;
}


// ============================================================================
// EXERCISE 11: Namespace Scope Resolution with Inheritance
// ============================================================================
/*
EXERCISE 11: Namespace with inheritance
- Create namespace "animals"
- Create class Animal with virtual function speak()
- Create class Dog and Cat that inherit from Animal
- Override speak() in each
- Create objects and call speak() using namespace qualification

Solution provided below
*/

namespace animals {
    class Animal {
    public:
        virtual void speak() const = 0;
        virtual ~Animal() { }
    };
    
    class Dog : public Animal {
    public:
        void speak() const override {
            cout << "Woof!" << endl;
        }
    };
    
    class Cat : public Animal {
    public:
        void speak() const override {
            cout << "Meow!" << endl;
        }
    };
}

void exercise11() {
    cout << "\n--- Exercise 11: Namespace with Inheritance ---" << endl;
    
    animals::Dog dog;
    animals::Cat cat;
    
    const animals::Animal& a1 = dog;
    const animals::Animal& a2 = cat;
    
    a1.speak();
    a2.speak();
    
    cout << "SUCCESS: Namespaces work with inheritance" << endl;
}


// ============================================================================
// EXERCISE 12: Practical Pattern - Three-Tier Application
// ============================================================================
/*
EXERCISE 12: Organize a three-tier application with namespaces
- Tier 1: DataLayer - classes for data storage
- Tier 2: BusinessLayer - classes for business logic
- Tier 3: PresentationLayer - classes for UI
- Each tier uses and depends on lower tiers
- Demonstrate a complete workflow

Solution provided below
*/

namespace DataLayer {
    class User {
    private:
        string name;
        int id;
    public:
        User(int id, string n) : id(id), name(n) { }
        int getID() const { return id; }
        string getName() const { return name; }
    };
}

namespace BusinessLayer {
    class UserManager {
    public:
        void processUser(const DataLayer::User& user) {
            cout << "Processing user: " << user.getName() << endl;
        }
    };
}

namespace PresentationLayer {
    class UserUI {
    public:
        void displayUser(const DataLayer::User& user) {
            cout << "Display: ID=" << user.getID() 
                 << ", Name=" << user.getName() << endl;
        }
    };
}

void exercise12() {
    cout << "\n--- Exercise 12: Three-Tier Application ---" << endl;
    
    // Create user (Data Layer)
    DataLayer::User user(101, "John Doe");
    
    // Process user (Business Layer)
    BusinessLayer::UserManager manager;
    manager.processUser(user);
    
    // Display user (Presentation Layer)
    PresentationLayer::UserUI ui;
    ui.displayUser(user);
    
    cout << "SUCCESS: Three-tier application with namespace organization" << endl;
}


// ============================================================================
// EXERCISE 13: Resolving Name Conflicts with Namespaces
// ============================================================================
/*
EXERCISE 13: Comprehensive example of avoiding conflicts
Problem: Two libraries (LibA and LibB) both define Shape and Circle classes
Solution: Use namespaces to organize and access correctly

Create:
- namespace LibA with Shape and Circle classes
- namespace LibB with Shape and Circle classes (different implementation)
- In main, create 4 objects and show no conflicts occur
- Use both using namespace and fully qualified names
*/

namespace LibA {
    class Shape {
    public:
        void draw() const {
            cout << "LibA::Shape drawing" << endl;
        }
    };
    
    class Circle {
    public:
        void draw() const {
            cout << "LibA::Circle drawing" << endl;
        }
    };
}

namespace LibB {
    class Shape {
    public:
        void render() const {
            cout << "LibB::Shape rendering" << endl;
        }
    };
    
    class Circle {
    public:
        void render() const {
            cout << "LibB::Circle rendering" << endl;
        }
    };
}

void exercise13() {
    cout << "\n--- Exercise 13: Conflict Resolution with Namespaces ---" << endl;
    
    // Create objects from LibA
    LibA::Shape shapeA;
    LibA::Circle circleA;
    
    // Create objects from LibB
    LibB::Shape shapeB;
    LibB::Circle circleB;
    
    // Call methods without any confusion
    shapeA.draw();
    circleA.draw();
    shapeB.render();
    circleB.render();
    
    cout << "SUCCESS: Namespaces prevent naming conflicts between libraries" << endl;
}


// ============================================================================
// MAIN: Execute all exercises
// ============================================================================

int main() {
    cout << "========== C++ Namespaces Exercises ==========" << endl;
    
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
