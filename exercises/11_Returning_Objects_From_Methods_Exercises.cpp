//============================================================================
// LESSON 11 EXERCISES: Returning Objects From Methods
// Author      : M'Barek Benraiss
// Description : Practice returning objects by value, reference, and pointer.
//               Understand ownership and lifetime of returned objects.
//
// INSTRUCTIONS:
// - Solve each exercise by writing code that satisfies the requirements
// - Pay attention to object lifetime and ownership
// - Test to ensure constructors/destructors are called appropriately
// - Always document ownership when returning pointers
//============================================================================

#include <iostream>
#include <string>
#include <memory>
using namespace std;

//============================================================================
// EXERCISE 1: Return Object By Value
//
// Create a function that:
// - Returns a Person object by value
// - Person should have name and age
// - Constructor should print "Person created"
// - Copy constructor should print "Person copied"
// - Destructor should print "Person destroyed"
// Use this to observe the copy operation.
//
// HINT: Use constructors/destructors with cout statements
//============================================================================

class Person
{
private:
    string name;
    int age;

public:
    Person(string n = "Unknown", int a = 0) : name(n), age(a)
    {
        cout << "Person created: " << name << endl;
    }

    Person(const Person &other) : name(other.name), age(other.age)
    {
        cout << "Person copied: " << name << endl;
    }

    ~Person()
    {
        cout << "Person destroyed: " << name << endl;
    }

    void display() const
    {
        cout << name << " is " << age << " years old" << endl;
    }
};

// TODO: Create function that returns Person by value
// Person returnPersonByValue(string name, int age) {
//     Person p(name, age);
//     return p;  // Watch copy constructor!
// }

void exercise_1()
{
    cout << "\n=== EXERCISE 1: Return Object By Value ===" << endl;

    // TODO: Call the function and observe output
    // Person p = returnPersonByValue("Alice", 30);
    // p.display();
    // TODO: Explain why copy constructor was called

    // SOLUTION:
    // TODO: See hints above
}

//============================================================================
// EXERCISE 2: Return Multiple Objects
//
// Create functions that return various types:
//   - Return a simple value (int)
//   - Return a Person object by value
//   - Return a string by value
// For each, create and return new objects.
//
// HINT: All return by value - caller gets independent copies
//============================================================================

int returnIntValue()
{
    int x = 42;
    return x;
}

// TODO: Add returnPersonValue() function
// TODO: Add returnStringValue() function

void exercise_2()
{
    cout << "\n=== EXERCISE 2: Return Multiple Objects ===" << endl;

    // TODO: Call all three functions
    // int x = returnIntValue();
    // Person p = returnPersonValue();
    // string s = returnStringValue();

    // SOLUTION:
    // See exercise 1 for Person example
}

//============================================================================
// EXERCISE 3: Return by Pointer - Heap Objects
//
// Create a function that:
// - Returns a pointer to a new Person (allocated with new)
// - Print "Person allocated" in a custom message
// - In main, use the pointer and DELETE it
// - Remember: New memory requires delete!
//
// HINT: Use new inside function, delete in main
//       Document that caller owns the pointer!
//============================================================================

// TODO: Create allocatePerson function
// Person* allocatePerson(string name, int age) {
//     Person *p = new Person(name, age);
//     return p;  // Caller owns this!
// }

void exercise_3()
{
    cout << "\n=== EXERCISE 3: Return by Pointer - Heap Objects ===" << endl;

    // TODO: Allocate person
    // TODO: Use person
    // TODO: Delete person
    // TODO: Set to nullptr

    // SOLUTION:
    // Person *p = allocatePerson("Bob", 25);
    // p->display();
    // delete p;
    // p = nullptr;

    // TODO: Explain when constructor and destructor were called
}

//============================================================================
// EXERCISE 4: Compare Value vs Pointer Returns
//
// Create two versions of a function:
//   1. returnPersonByValue() - returns by value
//   2. allocatePersonPointer() - returns pointer to heap
//
// Call both and observe:
// - How many times constructor is called?
// - How many times copy constructor is called?
// - How many times destructor is called?
// - When does cleanup happen?
//
// HINT: Pay attention to the console output order
//============================================================================

Person returnPersonByValue(string name, int age)
{
    // TODO: Implement
    return Person(name, age);
}

// TODO: Implement allocatePersonPointer
// Person* allocatePersonPointer(string name, int age) {
//     return new Person(name, age);
// }

void exercise_4()
{
    cout << "\n=== EXERCISE 4: Compare Value vs Pointer Returns ===" << endl;

    cout << "\n--- Return by Value ---" << endl;
    // TODO: Call returnPersonByValue and observe output
    // Person p1 = returnPersonByValue("Alice", 30);
    // p1.display();

    cout << "\n--- Return by Pointer ---" << endl;
    // TODO: Call allocatePersonPointer, use, and delete
    // Person *p2 = allocatePersonPointer("Bob", 25);
    // p2->display();
    // delete p2;

    cout << "\n--- End of exercise ---" << endl;
    // TODO: Explain the differences in output
}

//============================================================================
// EXERCISE 5: Factory Function Pattern
//
// Create a factory function that:
// - Takes a type string ("student", "teacher", "admin")
// - Creates appropriate Person object on heap
// - Sets name to the type
// - Returns pointer to caller
//
// In main, create multiple objects using factory.
//
// HINT: Use if/else or switch to create different types
//       All are returned as Person* pointers
//============================================================================

// TODO: Implement factory function
// Person* createPersonByRole(string role, string name) {
//     Person *p = new Person(name, 0);
//     return p;
// }

void exercise_5()
{
    cout << "\n=== EXERCISE 5: Factory Function Pattern ===" << endl;

    // TODO: Create multiple people using factory
    // Person *student = createPersonByRole("student", "Tom");
    // Person *teacher = createPersonByRole("teacher", "Jane");
    // Person *admin = createPersonByRole("admin", "Bob");

    // TODO: Use all three
    // student->display();
    // teacher->display();
    // admin->display();

    // TODO: Delete all three
    // delete student;
    // delete teacher;
    // delete admin;
}

//============================================================================
// EXERCISE 6: Return Reference - Safe Pattern
//
// Create a function that:
// - Takes a Person reference as parameter
// - Returns the same reference
// This is safe because object exists in caller's scope.
//
// HINT: Never return reference to local objects!
//       Only safe with parameters or static objects
//============================================================================

const Person &returnParameterReference(const Person &p)
{
    // TODO: Return the parameter
    return p;
}

void exercise_6()
{
    cout << "\n=== EXERCISE 6: Return Reference ===" << endl;

    Person person("Charlie", 35);

    // TODO: Call function and get reference
    // const Person& ref = returnParameterReference(person);
    // ref.display();

    // TODO: Note: No copy made! Same object accessed through reference
    // person.display();  // Same person
    // ref.display();     // Same person
}

//============================================================================
// EXERCISE 7: Memory Leak Detection
//
// The following code has a memory leak. Find and fix it.
//
// WRONG:
//   Person *p = allocatePerson("Tom", 25);
//   // Use person...
//   // Forgot delete!
//
// Fix by adding proper cleanup.
//
// HINT: Always match new with delete
//       Set to nullptr after delete
//============================================================================

void exercise_7_wrong()
{
    Person *p = new Person("Tom", 25);
    p->display();
    // TODO: Add delete here!
    // TODO: Add p = nullptr;
}

void exercise_7()
{
    cout << "\n=== EXERCISE 7: Memory Leak Detection ===" << endl;

    Person *p = new Person("Tom", 25);
    p->display();
    delete p;    // Fix: Add delete
    p = nullptr; // Fix: Set to nullptr
}

//============================================================================
// EXERCISE 8: Ownership Documentation
//
// You receive this function - who owns the returned pointer?
//
//   Person* getPerson() {
//       return new Person("Unknown", 0);
//   }
//
// Rewrite with clear documentation comments that explain:
// - What does it create?
// - Who owns the returned pointer?
// - What is caller's responsibility?
//
// HINT: Good documentation prevents leaks!
//============================================================================

// BAD: No documentation
Person *getPerson_Bad()
{
    return new Person("Unknown", 0);
}

// GOOD: Clear documentation
// Creates a new Person object on the heap.
// OWNERSHIP: Caller assumes ownership and MUST call delete!
// RETURNS: Pointer to newly allocated Person, never nullptr
// EXAMPLE: Person *p = getPerson_Good();
//          p->display();
//          delete p;
//          p = nullptr;
Person *getPerson_Good()
{
    return new Person("Unknown", 0);
}

void exercise_8()
{
    cout << "\n=== EXERCISE 8: Ownership Documentation ===" << endl;

    // Use the well-documented version
    Person *p = getPerson_Good();
    p->display();
    delete p;
    p = nullptr;

    cout << "Good documentation helps prevent mistakes!" << endl;
}

//============================================================================
// EXERCISE 9: Pointer vs Copy Performance
//
// Compare performance of returning by value vs by pointer:
//
// SCENARIO: Need to return a large object from function
//
// Method 1: By value (copy)
//   Dog createDog() { return Dog(); }
//
// Method 2: By pointer (no copy)
//   Dog* allocateDog() { return new Dog(); }
//
// Which is more efficient for large objects?
//
// HINT: By pointer avoids copy overhead (new/copy constructor)
//============================================================================

class LargeObject
{
private:
    int data[10000]; // Large array - 40KB

public:
    LargeObject()
    {
        cout << "LargeObject created (40KB)" << endl;
    }

    LargeObject(const LargeObject &other)
    {
        cout << "LargeObject copied - 40KB copied!" << endl;
    }

    ~LargeObject()
    {
        cout << "LargeObject destroyed" << endl;
    }
};

LargeObject createLargeByValue()
{
    return LargeObject(); // Copy happens here!
}

LargeObject *allocateLargePointer()
{
    return new LargeObject(); // No copy!
}

void exercise_9()
{
    cout << "\n=== EXERCISE 9: Pointer vs Copy Performance ===" << endl;

    cout << "\nBy value (copy):" << endl;
    // LargeObject obj1 = createLargeByValue();

    cout << "\nBy pointer (no copy):" << endl;
    // LargeObject *p = allocateLargePointer();
    // delete p;

    cout << "\nFor large objects, pointer is more efficient!" << endl;
}

//============================================================================
// EXERCISE 10: Multiple Returns from Same Function
//
// Create a function that:
// - Can return different objects based on a condition
// - Returns pointer to avoid copy overhead
// - All objects are heap-allocated
//
// Example:
//   Person* createPerson(string type) {
//       if (type == "student") {
//           return new Person("Student", 20);
//       } else {
//           return new Person("Teacher", 40);
//       }
//   }
//
// Call multiple times with different types.
//
// HINT: All paths should allocate with new
//       Caller must delete each one
//============================================================================

Person *createPersonByType(string type)
{
    // TODO: Implement based on type
    if (type == "student")
    {
        return new Person("Student", 20);
    }
    else if (type == "teacher")
    {
        return new Person("Teacher", 40);
    }
    else
    {
        return new Person("Unknown", 0);
    }
}

void exercise_10()
{
    cout << "\n=== EXERCISE 10: Multiple Returns from Same Function ===" << endl;

    // TODO: Create multiple objects with different types
    Person *p1 = createPersonByType("student");
    Person *p2 = createPersonByType("teacher");
    Person *p3 = createPersonByType("admin");

    // TODO: Use them
    p1->display();
    p2->display();
    p3->display();

    // TODO: Delete all
    delete p1;
    delete p2;
    delete p3;
    p1 = p2 = p3 = nullptr;
}

//============================================================================
// EXERCISE 11: Chaining Returns
//
// Demonstrate returning and using the result in sequence:
//
//   Person *p = createPerson();
//   p->display();
//   delete p;
//
// Expand to:
// 1. Create persons in loop
// 2. Store pointers in array
// 3. Display all
// 4. Delete all
//
// HINT: Array of pointers: Person* people[5];
//============================================================================

void exercise_11()
{
    cout << "\n=== EXERCISE 11: Chaining Returns ===" << endl;

    // TODO: Create array of 3 people
    Person *people[3];

    // TODO: Allocate each one
    people[0] = createPersonByType("student");
    people[1] = createPersonByType("teacher");
    people[2] = createPersonByType("admin");

    // TODO: Display all
    for (int i = 0; i < 3; i++)
    {
        people[i]->display();
    }

    // TODO: Delete all and set to nullptr
    for (int i = 0; i < 3; i++)
    {
        delete people[i];
        people[i] = nullptr;
    }
}

//============================================================================
// EXERCISE 12: Smart Pointer Introduction
//
// Modern C++ uses smart pointers for automatic cleanup:
//
//   unique_ptr<Person> p = make_unique<Person>("Max", 25);
//   p->display();
//   // Automatic deletion when p goes out of scope!
//
// Rewrite existing exercises using unique_ptr instead of manual delete.
//
// HINT: No need for manual delete!
//       Automatic cleanup prevents leaks
//============================================================================

void exercise_12()
{
    cout << "\n=== EXERCISE 12: Smart Pointer Introduction ===" << endl;

    // TODO: Use unique_ptr instead of new/delete
    // unique_ptr<Person> p = make_unique<Person>("Bob", 30);
    // p->display();
    // // No delete needed! Automatic cleanup

    // TODO: Create multiple pointers
    // unique_ptr<Person> p1 = make_unique<Person>("A", 20);
    // unique_ptr<Person> p2 = make_unique<Person>("B", 30);
    // p1->display();
    // p2->display();
    // // Both deleted automatically at end of scope

    cout << "Smart pointers eliminate manual cleanup!" << endl;
    cout << "Use unique_ptr in modern C++" << endl;
}

//============================================================================
// EXERCISE 13: Complete Program - Object Management
//
// Write a complete program that:
// 1. Creates a factory function for Person objects
// 2. Allocates 5 people of various types
// 3. Stores all in an array
// 4. Displays all information
// 5. Properly deletes all allocated memory
// 6. Sets all pointers to nullptr
//
// This exercises all concepts from lesson 11.
//
// HINT: Combine exercises 5, 10, 11 into one complete program
//============================================================================

void exercise_13()
{
    cout << "\n=== EXERCISE 13: Complete Program - Object Management ===" << endl;

    const int COUNT = 5;
    Person *people[COUNT];

    // Create various people
    people[0] = createPersonByType("student");
    people[1] = createPersonByType("teacher");
    people[2] = createPersonByType("student");
    people[3] = createPersonByType("admin");
    people[4] = createPersonByType("teacher");

    // Display all
    cout << "\nAll people:" << endl;
    for (int i = 0; i < COUNT; i++)
    {
        cout << (i + 1) << ". ";
        people[i]->display();
    }

    // Clean up all
    cout << "\nCleaning up..." << endl;
    for (int i = 0; i < COUNT; i++)
    {
        delete people[i];
        people[i] = nullptr;
    }

    cout << "All objects deleted successfully!" << endl;
}

//============================================================================
// MAIN FUNCTION - Run Selected Exercises
//============================================================================

int main()
{
    cout << "=====================================================" << endl;
    cout << "LESSON 11 EXERCISES: Returning Objects From Methods" << endl;
    cout << "=====================================================" << endl;

    // Uncomment the exercises you want to test:

    // exercise_1();
    // exercise_2();
    exercise_3();
    exercise_4();
    exercise_5();
    exercise_6();
    exercise_7();
    exercise_8();
    // exercise_9();
    exercise_10();
    exercise_11();
    // exercise_12();
    exercise_13();

    cout << "\n=====================================================" << endl;
    cout << "EXERCISE SUMMARY" << endl;
    cout << "=====================================================" << endl;
    cout << "1. Return Object By Value - Copy creation" << endl;
    cout << "2. Return Multiple Objects - Different types" << endl;
    cout << "3. Return by Pointer - Heap ownership" << endl;
    cout << "4. Compare Value vs Pointer - Performance difference" << endl;
    cout << "5. Factory Function Pattern - Creating various objects" << endl;
    cout << "6. Return Reference - Safe reference patterns" << endl;
    cout << "7. Memory Leak Detection - Finding and fixing leaks" << endl;
    cout << "8. Ownership Documentation - Clear communication" << endl;
    cout << "9. Performance Comparison - Value vs pointer efficiency" << endl;
    cout << "10. Multiple Returns - Conditional allocation" << endl;
    cout << "11. Chaining Returns - Sequential creation" << endl;
    cout << "12. Smart Pointers - Automatic cleanup" << endl;
    cout << "13. Complete Program - Bring it all together" << endl;
    cout << "=====================================================" << endl;

    return 0;
}

/*

/Users/benraiss/CLionProjects/learnCpp/cmake-build-debug/learnCpp
=====================================================
LESSON 11 EXERCISES: Returning Objects From Methods
=====================================================

=== EXERCISE 3: Return by Pointer - Heap Objects ===

=== EXERCISE 4: Compare Value vs Pointer Returns ===

--- Return by Value ---

--- Return by Pointer ---

--- End of exercise ---

=== EXERCISE 5: Factory Function Pattern ===

=== EXERCISE 6: Return Reference ===
Person created: Charlie
Person destroyed: Charlie

=== EXERCISE 7: Memory Leak Detection ===
Person created: Tom
Tom is 25 years old
Person destroyed: Tom

=== EXERCISE 8: Ownership Documentation ===
Person created: Unknown
Unknown is 0 years old
Person destroyed: Unknown
Good documentation helps prevent mistakes!

=== EXERCISE 10: Multiple Returns from Same Function ===
Person created: Student
Person created: Teacher
Person created: Unknown
Student is 20 years old
Teacher is 40 years old
Unknown is 0 years old
Person destroyed: Student
Person destroyed: Teacher
Person destroyed: Unknown

=== EXERCISE 11: Chaining Returns ===
Person created: Student
Person created: Teacher
Person created: Unknown
Student is 20 years old
Teacher is 40 years old
Unknown is 0 years old
Person destroyed: Student
Person destroyed: Teacher
Person destroyed: Unknown

=== EXERCISE 13: Complete Program - Object Management ===
Person created: Student
Person created: Teacher
Person created: Student
Person created: Unknown
Person created: Teacher

All people:
1. Student is 20 years old
2. Teacher is 40 years old
3. Student is 20 years old
4. Unknown is 0 years old
5. Teacher is 40 years old

Cleaning up...
Person destroyed: Student
Person destroyed: Teacher
Person destroyed: Student
Person destroyed: Unknown
Person destroyed: Teacher
All objects deleted successfully!

=====================================================
EXERCISE SUMMARY
=====================================================
1. Return Object By Value - Copy creation
2. Return Multiple Objects - Different types
3. Return by Pointer - Heap ownership
4. Compare Value vs Pointer - Performance difference
5. Factory Function Pattern - Creating various objects
6. Return Reference - Safe reference patterns
7. Memory Leak Detection - Finding and fixing leaks
8. Ownership Documentation - Clear communication
9. Performance Comparison - Value vs pointer efficiency
10. Multiple Returns - Conditional allocation
11. Chaining Returns - Sequential creation
12. Smart Pointers - Automatic cleanup
13. Complete Program - Bring it all together
=====================================================

Process finished with exit code 0



*/
