//============================================================================
// LESSON 11: Returning Objects From Methods
// Author      : M'Barek Benraiss
// Description : Learn how to return objects from functions and methods,
//               including stack objects, references, and heap pointers.
//============================================================================

#include <iostream>
using namespace std;

//============================================================================
// SECTION 1: Returning Stack Objects (By Value)
//
// When you return an object created on the stack from a function:
// - The object is copied before return (copy constructor called)
// - The original object is destroyed when function exits
// - The caller receives an independent copy
//
// This is safe but can be inefficient for large objects.
//============================================================================

class Animal
{
private:
    string name;

public:
    Animal()
    {
        cout << "Animal created." << endl;
    }

    Animal(const Animal &other) : name(other.name)
    {
        cout << "Animal created by copying." << endl;
    }

    ~Animal()
    {
        cout << "Destructor called for: " << name << endl;
    }

    void setName(string name)
    {
        this->name = name;
    }

    void speak() const
    {
        cout << "My name is: " << name << endl;
    }
};

// Example 1.1: Return object by value
Animal createAnimalByValue()
{
    cout << "\n--- Inside createAnimalByValue ---" << endl;
    Animal animal; // Created on stack
    animal.setName("Freddy");
    cout << "Returning animal..." << endl;
    return animal; // Copy constructor called, object copied
} // Original animal destroyed

void example_1_1_return_by_value()
{
    cout << "\n=== Example 1.1: Return Object By Value ===" << endl;

    cout << "Calling function..." << endl;
    Animal myCat = createAnimalByValue(); // Copy received here
    cout << "\nAfter function call:" << endl;
    myCat.speak();
    // myCat destroyed when function exits
}

// Example 1.2: Return by value - efficiency issue
class LargeObject
{
private:
    int data[10000]; // Large array

public:
    LargeObject()
    {
        cout << "LargeObject created (10KB)" << endl;
    }

    LargeObject(const LargeObject &other)
    {
        cout << "LargeObject copied (10KB)" << endl;
    }

    ~LargeObject()
    {
        cout << "LargeObject destroyed" << endl;
    }
};

LargeObject createLargeByValue()
{
    LargeObject obj; // Created
    return obj;      // Copied during return (inefficient!)
}

void example_1_2_copy_overhead()
{
    cout << "\n=== Example 1.2: Copy Overhead ===" << endl;

    cout << "Calling function that returns by value..." << endl;
    LargeObject obj = createLargeByValue(); // Notice the copy!
    cout << "Object received by caller" << endl;
}

//============================================================================
// SECTION 2: Returning References
//
// DANGEROUS: Never return references to local (stack) objects!
// The reference points to memory that's been freed.
//
// SAFE: Return references to:
// - Parameters passed by reference
// - Static objects
// - Objects passed by reference to the function
//
// This is an advanced technique - use with caution!
//============================================================================

// WRONG - DO NOT DO THIS!
const Animal &createDangerousReference()
{
    Animal animal; // Local object on stack
    animal.setName("Danger");
    return animal; // WRONG! Returning reference to local object
                   // The reference is dangling after function exits
}

// CORRECT - Return reference to parameter
const Animal &getAnimalReference(const Animal &animal)
{
    // Safe: Just forwarding the reference back
    return animal;
}

void example_2_1_reference_safety()
{
    cout << "\n=== Example 2.1: Reference Safety ===" << endl;

    Animal cat;
    cat.setName("Whiskers");

    // Safe: Reference to object that exists in this scope
    const Animal &ref = getAnimalReference(cat);
    ref.speak();

    // Note: Never use createDangerousReference() - it causes undefined behavior!
}

//============================================================================
// SECTION 3: Returning Pointers (Heap Objects)
//
// Return a pointer to a newly allocated object on the heap.
// The caller becomes responsible for deleting the returned pointer!
//
// Advantages:
// - No copy overhead
// - Object persists beyond function scope
// - Caller controls lifetime
//
// Disadvantages:
// - Caller MUST remember to delete
// - Risk of memory leaks if caller forgets
// - Requires careful ownership documentation
//============================================================================

// Example 3.1: Return pointer to heap object
Animal *createAnimalPointer()
{
    cout << "\n--- Inside createAnimalPointer ---" << endl;
    Animal *pAnimal = new Animal(); // Allocated on heap
    pAnimal->setName("Bertie");
    cout << "Returning pointer..." << endl;
    return pAnimal; // Return the pointer
} // Pointer returned, object persists

void example_3_1_return_pointer()
{
    cout << "\n=== Example 3.1: Return Pointer To Heap Object ===" << endl;

    cout << "Calling function..." << endl;
    Animal *pFrog = createAnimalPointer(); // Receive pointer

    cout << "\nUsing the object:" << endl;
    pFrog->speak();

    cout << "\nCaller must delete:" << endl;
    delete pFrog; // CRITICAL: Caller must delete!
    pFrog = nullptr;
}

// Example 3.2: Factory function pattern
Animal *createAnimalFactory(string type, string name)
{
    Animal *pAnimal = new Animal();
    pAnimal->setName(name);
    cout << "Factory created " << type << endl;
    return pAnimal;
}

void example_3_2_factory_pattern()
{
    cout << "\n=== Example 3.2: Factory Pattern ===" << endl;

    Animal *pDog = createAnimalFactory("Dog", "Buddy");
    Animal *pCat = createAnimalFactory("Cat", "Mittens");

    pDog->speak();
    pCat->speak();

    delete pDog;
    delete pCat;
    pDog = nullptr;
    pCat = nullptr;
}

//============================================================================
// SECTION 4: Comparing Return Methods
//
// Stack Return:    Return by value (copy made)
//   Pros: Safe, no manual cleanup, no dangling pointers
//   Cons: Copy overhead for large objects
//   Use: Simple, small objects, when you want independent copy
//
// Reference Return: Return reference (reference to existing object)
//   Pros: No copy overhead, direct access
//   Cons: Must ensure object lives long enough, dangerous with locals
//   Use: Advanced, rarely needed, expert only
//
// Pointer Return:   Return pointer to heap (caller owns memory)
//   Pros: No copy, object persists, caller controls lifetime
//   Cons: Manual cleanup required, risk of leaks, ownership unclear
//   Use: When object must persist beyond function scope
//============================================================================

void example_4_1_comparison()
{
    cout << "\n=== Example 4.1: Comparing Return Methods ===" << endl;

    cout << "METHOD 1: Return by value (copy)" << endl;
    Animal cat1 = createAnimalByValue(); // Safe, copy overhead

    cout << "\nMETHOD 2: Return pointer (heap)" << endl;
    Animal *pCat2 = createAnimalPointer(); // No copy, manual cleanup
    delete pCat2;
    pCat2 = nullptr;

    cout << "\nMETHOD 3: Return reference (dangerous)" << endl;
    cout << "Not demonstrated - too risky!" << endl;
}

//============================================================================
// SECTION 5: Ownership and Responsibility
//
// When a function returns a pointer, it transfers ownership to the caller.
// The caller becomes responsible for:
// - Checking if pointer is not null
// - Using the object appropriately
// - Deleting the object when done
// - Not using the pointer after deletion
//
// CRITICAL: Document ownership clearly in function documentation!
//============================================================================

// Bad documentation
Animal *createAnimal1()
{
    return new Animal();
}

// Good documentation
// Creates a new Animal object on the heap.
// OWNERSHIP: Caller is responsible for deleting the returned pointer!
// RETURNS: Pointer to newly created Animal, or nullptr if creation fails
Animal *createAnimal2()
{
    return new Animal();
}

void example_5_1_ownership()
{
    cout << "\n=== Example 5.1: Ownership and Documentation ===" << endl;

    // When you see a function returning a pointer, documentation
    // should clarify: WHO owns this pointer?

    Animal *pAnimal = createAnimal2();

    if (pAnimal != nullptr)
    {
        pAnimal->setName("Max");
        pAnimal->speak();
        delete pAnimal; // I own it, so I delete it
        pAnimal = nullptr;
    }
}

//============================================================================
// SECTION 6: Return Type Variations
//
// Different ways to return objects from methods:
//
// 1. Return by value:           ClassName function()
// 2. Return const by value:     const ClassName function()
// 3. Return by reference:       ClassName& function()
// 4. Return const reference:    const ClassName& function()
// 5. Return pointer:            ClassName* function()
// 6. Return const pointer:      const ClassName* const function()
//
// Each has different implications for mutability and lifetime!
//============================================================================

class Counter
{
private:
    int count = 0;

public:
    void increment() { count++; }
    int getValue() const { return count; }
};

// Return by value - caller gets independent copy
Counter getCounterByValue()
{
    Counter c;
    return c;
}

// Return pointer - caller owns the object
Counter *getCounterPointer()
{
    return new Counter();
}

void example_6_1_return_variations()
{
    cout << "\n=== Example 6.1: Return Type Variations ===" << endl;

    // By value: Safe, independent copy
    Counter c1 = getCounterByValue();
    c1.increment();
    cout << "Value: " << c1.getValue() << endl;
    // c1 destroyed automatically

    // By pointer: Fast, but requires manual cleanup
    Counter *pC2 = getCounterPointer();
    pC2->increment();
    cout << "Pointer value: " << pC2->getValue() << endl;
    delete pC2; // Must delete!
    pC2 = nullptr;
}

//============================================================================
// SECTION 7: Memory Leaks With Returned Pointers
//
// Common mistake: Forgetting to delete returned pointers
//
// Example of leak:
//   Animal *p = createAnimalPointer();  // Allocate
//   p->speak();
//   p = new Animal();                   // LEAK! Original not deleted!
//   delete p;

// Another example:
//   Animal *p = createAnimalPointer();  // Allocate
//   if (someCondition) {
//       return;                         // LEAK! Not deleted before return!
//   }
//   delete p;
//============================================================================

void example_7_1_pointer_leak()
{
    cout << "\n=== Example 7.1: Pointer Memory Leak ===" << endl;

    // WRONG - Memory leak!
    // Animal *p1 = createAnimalPointer();
    // p1 = createAnimalPointer();  // First object leaked!
    // delete p1;

    // CORRECT - No leak
    Animal *p1 = createAnimalPointer();
    delete p1; // Delete first

    p1 = createAnimalPointer();
    delete p1; // Delete second
    p1 = nullptr;
}

//============================================================================
// SECTION 8: Modern C++ - Smart Pointers (Brief Introduction)
//
// C++11 and later provide smart pointers that automatically manage memory:
// - std::unique_ptr: Single owner
// - std::shared_ptr: Multiple owners
//
// Smart pointers automatically delete the object when the pointer is destroyed.
// This eliminates many memory leak risks!
//
// Example:
//   unique_ptr<Animal> pAnimal = make_unique<Animal>();
//   pAnimal->speak();
//   // Automatic deletion when pAnimal goes out of scope!
//============================================================================

#include <memory>

Animal *createAnimalModern()
{
    return new Animal();
}

void example_8_1_smart_pointer_intro()
{
    cout << "\n=== Example 8.1: Smart Pointer Introduction ===" << endl;

    // Old way: Manual management
    Animal *pAnimal = new Animal();
    pAnimal->setName("OldStyle");
    delete pAnimal;

    // Modern way: Automatic management
    // unique_ptr<Animal> pCat = make_unique<Animal>();
    // pCat->setName("ModernStyle");
    // // Automatic deletion when pCat goes out of scope!

    cout << "Smart pointers eliminate manual cleanup!" << endl;
    cout << "Use unique_ptr or shared_ptr in modern C++" << endl;
}

//============================================================================
// MAIN FUNCTION - Run all examples
//============================================================================

int main()
{
    cout << "=====================================================" << endl;
    cout << "LESSON 11: Returning Objects From Methods" << endl;
    cout << "Stack, References, and Heap Objects" << endl;
    cout << "=====================================================" << endl;

    // Section 1: Return by value
    example_1_1_return_by_value();
    example_1_2_copy_overhead();

    // Section 2: Return references (safe ways)
    example_2_1_reference_safety();

    // Section 3: Return pointers
    example_3_1_return_pointer();
    example_3_2_factory_pattern();

    // Section 4: Comparisons
    example_4_1_comparison();

    // Section 5: Ownership
    example_5_1_ownership();

    // Section 6: Return type variations
    example_6_1_return_variations();

    // Section 7: Memory leaks
    example_7_1_pointer_leak();

    // Section 8: Smart pointers
    example_8_1_smart_pointer_intro();

    cout << "\n=====================================================" << endl;
    cout << "KEY TAKEAWAYS:" << endl;
    cout << "1. Return by value is safe but has copy overhead" << endl;
    cout << "2. Never return reference to local (stack) objects" << endl;
    cout << "3. Return pointer to heap for persistent objects" << endl;
    cout << "4. Caller MUST delete returned pointers to prevent leaks" << endl;
    cout << "5. Document ownership clearly in function documentation" << endl;
    cout << "6. Prefer smart pointers in modern C++ code" << endl;
    cout << "=====================================================" << endl;

    return 0;
}
