//============================================================================
// LESSON 10 EXERCISES: New and Delete Operators
// Author      : M'Barek Benraiss
// Description : Practice dynamic memory allocation, object management,
//               and proper cleanup with new and delete operators.
//
// INSTRUCTIONS:
// - Solve each exercise by writing code that satisfies the requirements
// - Test your code to ensure it works correctly
// - Pay attention to memory cleanup with delete
// - Hints are provided for more challenging exercises
//============================================================================

#include <iostream>
#include <string>
#include <vector>
using namespace std;

//============================================================================
// EXERCISE 1: Basic Object Allocation
//
// Create a simple Person class with:
//   - Constructor that takes name and age
//   - Method to display person info
// In main, allocate a Person object with 'new', display info, and delete it.
//
// HINT: Remember to use the arrow operator (->) with pointers
//============================================================================

class Person
{
    // TODO: Add private members for name and age

public:
    // TODO: Add constructor
    // TODO: Add display() method
};

void exercise_1()
{
    cout << "\n=== EXERCISE 1: Basic Object Allocation ===" << endl;

    // TODO: Allocate a Person object
    // TODO: Set/display information
    // TODO: Delete the object

    // SOLUTION:
    // Person *p = new Person("Alice", 30);
    // p->display();  // Output: Alice is 30 years old
    // delete p;
    // p = nullptr;
}

//============================================================================
// EXERCISE 2: Multiple Objects
//
// Create three Dog objects on the heap with different names.
// Call a bark() method on each, then delete all of them.
//
// HINT: You can create the Dog class or use your own
//============================================================================

class Dog
{
private:
    string name;

public:
    Dog(string name) : name(name) {}
    void bark() const { cout << name << " says: Woof!" << endl; }
};

void exercise_2()
{
    cout << "\n=== EXERCISE 2: Multiple Objects ===" << endl;

    // TODO: Create three Dog objects with new
    // TODO: Call bark() on each
    // TODO: Delete all three

    // SOLUTION:
    // Dog *p1 = new Dog("Rex");
    // Dog *p2 = new Dog("Buddy");
    // Dog *p3 = new Dog("Max");
    // p1->bark();
    // p2->bark();
    // p3->bark();
    // delete p1;
    // delete p2;
    // delete p3;
}

//============================================================================
// EXERCISE 3: Primitive Types with New
//
// Allocate dynamic memory for:
//   - An integer
//   - A double
//   - A string
// Initialize them with values, display them, and delete them.
//
// HINT: Use the dereference operator (*) to access the value
//============================================================================

void exercise_3()
{
    cout << "\n=== EXERCISE 3: Primitive Types with New ===" << endl;

    // TODO: Allocate int, double, and string with new
    // TODO: Initialize with values
    // TODO: Display values using dereference operator
    // TODO: Delete each one

    // SOLUTION:
    // int *p_int = new int(42);
    // double *p_double = new double(3.14);
    // string *p_string = new string("Hello!");
    // cout << *p_int << " " << *p_double << " " << *p_string << endl;
    // delete p_int;
    // delete p_double;
    // delete p_string;
}

//============================================================================
// EXERCISE 4: Dynamic Array Allocation
//
// Allocate an array of integers with size 5.
// Fill it with values 10, 20, 30, 40, 50.
// Display all elements.
// Delete the array (remember the brackets!).
//
// HINT: Use new[] and delete[] for arrays
//============================================================================

void exercise_4()
{
    cout << "\n=== EXERCISE 4: Dynamic Array Allocation ===" << endl;

    // TODO: Allocate array with new[]
    // TODO: Fill with values
    // TODO: Display values
    // TODO: Delete with delete[]

    // SOLUTION:
    // int *arr = new int[5]{10, 20, 30, 40, 50};
    // for (int i = 0; i < 5; i++) {
    //     cout << arr[i] << " ";
    // }
    // cout << endl;
    // delete[] arr;
}

//============================================================================
// EXERCISE 5: Dynamic Array with User Input
//
// Ask the user for an array size.
// Allocate an integer array of that size.
// Ask user to input values for each element.
// Display the array.
// Delete the array.
//
// HINT: Size is determined at runtime, not compile time
//============================================================================

void exercise_5()
{
    cout << "\n=== EXERCISE 5: Dynamic Array with User Input ===" << endl;

    // TODO: Get size from user
    // TODO: Allocate array
    // TODO: Get values from user
    // TODO: Display array
    // TODO: Delete array

    // SOLUTION:
    // int size;
    // cout << "Enter array size: ";
    // cin >> size;
    // int *arr = new int[size];
    // for (int i = 0; i < size; i++) {
    //     cout << "Enter value " << i << ": ";
    //     cin >> arr[i];
    // }
    // cout << "Array: ";
    // for (int i = 0; i < size; i++) {
    //     cout << arr[i] << " ";
    // }
    // cout << endl;
    // delete[] arr;
}

//============================================================================
// EXERCISE 6: Pointer Size vs Object Size
//
// Create an object of some class and allocate it with new.
// Print the size of the pointer itself: sizeof(pointer)
// Explain why the pointer size is small even for large objects.
//
// HINT: Pointers store memory addresses, always a fixed size
//============================================================================

void exercise_6()
{
    cout << "\n=== EXERCISE 6: Pointer Size vs Object Size ===" << endl;

    // TODO: Allocate any object with new
    // TODO: Print size of the pointer
    // TODO: Explain the result

    // SOLUTION:
    // Dog *p = new Dog("Buddy");
    // cout << "Size of pointer: " << sizeof(p) << " bytes" << endl;
    // cout << "All pointers are same size: typically 8 bytes on 64-bit system" << endl;
    // cout << "The size of what it points to is separate!" << endl;
    // delete p;
}

//============================================================================
// EXERCISE 7: Memory Leak Detection
//
// The following function has a memory leak. Find and fix it.
//
// ORIGINAL (WRONG):
//   void leaky() {
//       Animal *p = new Animal("Tom");
//       p->speak();
//   } // LEAK!
//
// Fix the leak by:
//   A) Adding proper delete statement
//   B) Explain why this is a leak
//
// HINT: Memory is allocated but never freed
//============================================================================

void exercise_7_wrong()
{
    // Animal *p = new Animal("Tom");
    // p->speak();
    // TODO: Add delete p; here
    // TODO: Add p = nullptr;
}

void exercise_7()
{
    cout << "\n=== EXERCISE 7: Memory Leak Detection ===" << endl;

    // TODO: Fix the memory leak in exercise_7_wrong()
    // The fix is to add:
    // delete p;
    // p = nullptr;
}

//============================================================================
// EXERCISE 8: Overwriting Pointer Without Delete
//
// What's wrong with this code? Fix it.
//
// WRONG:
//   Animal *p = new Animal("Tom");
//   p = new Animal("Jerry");  // LEAK! Tom is lost
//   delete p;
//
// This is a leak because:
//   - First Animal allocated but pointer overwritten
//   - Memory for "Tom" is lost
//   - Only "Jerry" is deleted
//
// HINT: Delete before overwriting the pointer
//============================================================================

void exercise_8()
{
    cout << "\n=== EXERCISE 8: Overwriting Pointer Without Delete ===" << endl;

    // WRONG:
    // Dog *p = new Dog("Tom");
    // p = new Dog("Jerry");  // LEAK!
    // delete p;

    // CORRECT:
    // Dog *p = new Dog("Tom");
    // delete p;              // Delete Tom first
    // p = new Dog("Jerry");
    // delete p;              // Then delete Jerry

    // EVEN BETTER - Use separate pointers:
    Dog *p1 = new Dog("Tom");
    Dog *p2 = new Dog("Jerry");
    p1->bark();
    p2->bark();
    delete p1;
    delete p2;
    p1 = nullptr;
    p2 = nullptr;
}

//============================================================================
// EXERCISE 9: Constructors and Destructors
//
// Create a class that prints messages when:
//   - Constructor is called
//   - Destructor is called
// Allocate objects and notice when these methods are called.
//
// HINT: Place cout statements in constructor and destructor
//============================================================================

class TrackedObject
{
private:
    string name;

public:
    TrackedObject(string n) : name(n)
    {
        cout << "Creating: " << name << endl;
    }

    ~TrackedObject()
    {
        cout << "Destroying: " << name << endl;
    }
};

void exercise_9()
{
    cout << "\n=== EXERCISE 9: Constructors and Destructors ===" << endl;

    // TODO: Allocate TrackedObject with new
    // TODO: Notice constructor message
    // TODO: Delete it
    // TODO: Notice destructor message

    // SOLUTION:
    TrackedObject *p = new TrackedObject("Object1");
    delete p; // Notice destructor message
}

//============================================================================
// EXERCISE 10: Dynamic Array of Objects
//
// Create an array of Dog objects on the heap.
// Initialize each with a different name.
// Call bark() on each dog.
// Delete the entire array.
//
// HINT: Remember new[] and delete[] for arrays
//============================================================================

void exercise_10()
{
    cout << "\n=== EXERCISE 10: Dynamic Array of Objects ===" << endl;

    // TODO: Allocate array of Dog objects with new[]
    // TODO: Initialize each dog
    // TODO: Call bark() on each
    // TODO: Delete with delete[]

    // SOLUTION:
    // Dog *dogs = new Dog[3]{Dog("Rex"), Dog("Buddy"), Dog("Max")};
    // for (int i = 0; i < 3; i++) {
    //     dogs[i].bark();
    // }
    // delete[] dogs;
}

//============================================================================
// EXERCISE 11: Returning New Objects
//
// Create a function that:
//   - Takes a name as parameter
//   - Returns a newly allocated Dog object
//   - The caller is responsible for deletion
//
// Create and delete multiple objects returned from this function.
//
// IMPORTANT: Document that caller must delete the returned object!
//============================================================================

// TODO: Create this function
// Dog* createDog(string name) {
//     return new Dog(name);
// }

void exercise_11()
{
    cout << "\n=== EXERCISE 11: Returning New Objects ===" << endl;

    // TODO: Create function above
    // Dog *d1 = createDog("Buddy");
    // Dog *d2 = createDog("Max");
    // d1->bark();
    // d2->bark();
    // delete d1;
    // delete d2;
    // d1 = nullptr;
    // d2 = nullptr;
}

//============================================================================
// EXERCISE 12: Correcting Mismatched New/Delete
//
// Identify and fix the problems in these code snippets:
//
// WRONG 1:
//   int *arr = new int[5];
//   delete arr;  // WRONG! Should be delete[]
//
// WRONG 2:
//   int *p = new int(42);
//   delete[] p;  // WRONG! Should be delete (not [])
//
// Fix both by matching operators correctly.
//
// HINT: new[] pairs with delete[], new pairs with delete
//============================================================================

void exercise_12()
{
    cout << "\n=== EXERCISE 12: Correcting Mismatched New/Delete ===" << endl;

    // CORRECT 1:
    int *arr = new int[5];
    for (int i = 0; i < 5; i++)
        arr[i] = i;
    delete[] arr; // Correct[] for array
    arr = nullptr;

    // CORRECT 2:
    int *p = new int(42);
    cout << "Value: " << *p << endl;
    delete p; // Correct - no [] for single object
    p = nullptr;
}

//============================================================================
// EXERCISE 13: Complete Program - Managing a Collection
//
// Write a program that:
//   1. Allocates an array of 3 Person objects dynamically
//   2. Fills them with sample data (name, age)
//   3. Displays all persons
//   4. Properly deletes all allocated memory
//
// BONUS: Create a function that increases all ages by 1
//
// HINT: This combines most concepts from this lesson
//============================================================================

class Person2
{
private:
    string name;
    int age;

public:
    Person2(string n, int a) : name(n), age(a) {}

    void display() const
    {
        cout << name << " is " << age << " years old" << endl;
    }

    void increaseAge()
    {
        age++;
    }
};

void exercise_13()
{
    cout << "\n=== EXERCISE 13: Complete Program - Managing a Collection ===" << endl;

    // TODO: Allocate array of 3 Person2 objects
    // TODO: Initialize each with name and age
    // TODO: Display all persons
    // TODO: Increase all ages
    // TODO: Display again
    // TODO: Delete array properly

    // SOLUTION:
    Person2 *people = new Person2[3]{
        Person2("Alice", 25),
        Person2("Bob", 30),
        Person2("Charlie", 35)};

    cout << "Before:" << endl;
    for (int i = 0; i < 3; i++)
    {
        people[i].display();
    }

    cout << "\nIncreasing ages..." << endl;
    for (int i = 0; i < 3; i++)
    {
        people[i].increaseAge();
    }

    cout << "\nAfter:" << endl;
    for (int i = 0; i < 3; i++)
    {
        people[i].display();
    }

    delete[] people;
    people = nullptr;
}

//============================================================================
// MAIN FUNCTION - Run Selected Exercises
//============================================================================

int main()
{
    cout << "=====================================================" << endl;
    cout << "LESSON 10 EXERCISES: New and Delete Operators" << endl;
    cout << "=====================================================" << endl;

    // Uncomment the exercises you want to test:

    // exercise_1();
    exercise_2();
    // exercise_3();
    exercise_4();
    // exercise_5();  // Requires user input
    // exercise_6();
    exercise_7();
    exercise_8();
    exercise_9();
    // exercise_10();
    // exercise_11();
    exercise_12();
    exercise_13();

    cout << "\n=====================================================" << endl;
    cout << "EXERCISE SUMMARY" << endl;
    cout << "=====================================================" << endl;
    cout << "1. Basic Object Allocation - Allocate and delete objects" << endl;
    cout << "2. Multiple Objects - Manage several objects" << endl;
    cout << "3. Primitive Types - Allocate int, double, string" << endl;
    cout << "4. Dynamic Array - Use new[] and delete[]" << endl;
    cout << "5. User Input Array - Size determined at runtime" << endl;
    cout << "6. Pointer Size - Understanding pointer memory" << endl;
    cout << "7. Memory Leak Detection - Identify and fix leaks" << endl;
    cout << "8. Overwriting Pointers - Proper pointer management" << endl;
    cout << "9. Constructor/Destructor - See when they're called" << endl;
    cout << "10. Array of Objects - Manage multiple objects" << endl;
    cout << "11. Returning Objects - Functions returning new objects" << endl;
    cout << "12. Mismatched Operators - Correct new[]/delete[] pairing" << endl;
    cout << "13. Complete Program - Bring it all together" << endl;
    cout << "=====================================================" << endl;

    return 0;
}
