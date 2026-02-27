//============================================================================
// LESSON 10: New and Delete Operators - Dynamic Memory Allocation
// Author      : M'Barek Benraiss
// Description : Learn how to dynamically allocate memory at runtime using
//               the 'new' and 'delete' operators for objects and arrays.
//============================================================================

#include <iostream>
using namespace std;

//============================================================================
// SECTION 1: Basic New Operator - Allocating Single Objects
//
// The 'new' operator allocates memory on the heap at runtime and returns
// a pointer to the allocated memory. Unlike stack allocation, heap memory
// persists until explicitly deallocated with 'delete'.
//
// Syntax: PointerType *ptr = new ClassName();
//
// Key differences from stack allocation:
//   Stack: int x = 5;        (memory freed automatically when out of scope)
//   Heap:  int *p = new int(5); (memory persists until delete is called)
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
        cout << "Destructor called" << endl;
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

// Example 1.1: Basic new and delete
void example_1_1_basic_new_delete()
{
    cout << "\n=== Example 1.1: Basic New and Delete ===" << endl;

    // Allocate memory for an Animal object on the heap
    Animal *pCat1 = new Animal();

    // Use the pointer to call member functions with -> operator
    pCat1->setName("Freddy");
    pCat1->speak();

    // MUST delete to free memory - prevents memory leak
    delete pCat1;
    pCat1 = nullptr; // Best practice: set to nullptr after delete
}

// Example 1.2: Multiple objects
void example_1_2_multiple_objects()
{
    cout << "\n=== Example 1.2: Multiple Heap Objects ===" << endl;

    Animal *pDog = new Animal();
    pDog->setName("Rex");
    pDog->speak();
    delete pDog;

    Animal *pBird = new Animal();
    pBird->setName("Tweety");
    pBird->speak();
    delete pBird;
}

//============================================================================
// SECTION 2: Pointer Size vs Object Size
//
// Important distinction: The pointer itself has a fixed size (typically 8 bytes
// on 64-bit systems), but it points to an object that may be much larger.
//
// Example: sizeof(pCat1) // Returns size of pointer, not the Animal object!
//          sizeof(*pCat1) // Returns size of the Animal object itself
//============================================================================

void example_2_1_pointer_size()
{
    cout << "\n=== Example 2.1: Pointer Size ===" << endl;

    Animal *pAnimal = new Animal();

    // Size of the pointer itself (address storage)
    cout << "sizeof(pAnimal): " << sizeof(pAnimal) << " bytes" << endl;

    // Size of what the pointer points to would need reflection or custom size method
    cout << "All pointers on 64-bit system are typically 8 bytes" << endl;

    delete pAnimal;
}

//============================================================================
// SECTION 3: New with Primitive Types
//
// You can use 'new' with primitive types (int, double, char, etc.) as well.
// This is useful for dynamic array allocation or when you need heap storage.
//============================================================================

void example_3_1_primitive_new()
{
    cout << "\n=== Example 3.1: New with Primitive Types ===" << endl;

    // Allocate a single integer on the heap
    int *pValue = new int(42);
    cout << "Heap integer value: " << *pValue << endl;
    delete pValue;

    // Allocate a double
    double *pPrice = new double(19.99);
    cout << "Heap double value: " << *pPrice << endl;
    delete pPrice;

    // Allocate a string
    string *pStr = new string("Hello from heap!");
    cout << "Heap string: " << *pStr << endl;
    delete pStr;
}

//============================================================================
// SECTION 4: New Array Operator - Allocating Multiple Objects
//
// Use 'new[]' (note the brackets) to allocate arrays on the heap.
// Use 'delete[]' (with brackets) to deallocate - critical distinction!
//
// Mistake: new[] without delete[] or delete[] without [] causes undefined behavior
//============================================================================

void example_4_1_new_array()
{
    cout << "\n=== Example 4.1: New Array ===" << endl;

    // Allocate array of 5 integers on heap
    int *pArray = new int[5];

    // Initialize and access array elements
    for (int i = 0; i < 5; i++)
    {
        pArray[i] = (i + 1) * 10;
    }

    // Print array
    for (int i = 0; i < 5; i++)
    {
        cout << pArray[i] << " ";
    }
    cout << endl;

    // MUST use delete[] for arrays, not delete!
    delete[] pArray;
    pArray = nullptr;
}

void example_4_2_dynamic_size_array()
{
    cout << "\n=== Example 4.2: Dynamic Size Array ===" << endl;

    int size;
    cout << "Enter array size: ";
    cin >> size;

    // Size determined at runtime, not compile time
    int *pNumbers = new int[size];

    // Fill with user input
    for (int i = 0; i < size; i++)
    {
        cout << "Enter number " << (i + 1) << ": ";
        cin >> pNumbers[i];
    }

    // Display array
    cout << "Array contents: ";
    for (int i = 0; i < size; i++)
    {
        cout << pNumbers[i] << " ";
    }
    cout << endl;

    delete[] pNumbers;
}

//============================================================================
// SECTION 5: Memory Leaks - The Critical Problem
//
// A memory leak occurs when you allocate memory with 'new' but forget to
// call 'delete'. The memory is wasted and becomes inaccessible.
//
// Example of a leak:
//   Animal *pCat = new Animal();  // Memory allocated
//   pCat = new Animal();          // NEW ALLOCATION - FIRST MEMORY LEAKED!
//   delete pCat;                  // Only second allocation is freed
//============================================================================

// WRONG - This creates a memory leak!
void example_5_1_memory_leak_WRONG()
{
    cout << "\n=== Example 5.1: Memory Leak WRONG ===" << endl;

    Animal *pCat = new Animal(); // First allocation
    pCat->setName("Tom");

    // OOPS! Without deleting first, we lose the pointer:
    pCat = new Animal(); // MEMORY LEAK - Tom's memory is lost!
    pCat->setName("Jerry");

    delete pCat; // Only Jerry is deleted
    // Tom's memory is leaked!
}

// RIGHT - Proper cleanup
void example_5_2_proper_cleanup()
{
    cout << "\n=== Example 5.2: Proper Cleanup ===" << endl;

    Animal *pCat = new Animal();
    pCat->setName("Tom");
    delete pCat; // Always clean up!

    pCat = new Animal();
    pCat->setName("Jerry");
    delete pCat;
}

//============================================================================
// SECTION 6: Constructor and Destructor Calls with New/Delete
//
// When using 'new':
//   - Constructor is called automatically
//   - Object is initialized as specified
//
// When using 'delete':
//   - Destructor is called automatically
//   - Resources are cleaned up
//   - Memory is freed
//
// This is one of the key benefits of new/delete - automatic initialization!
//============================================================================

class Dog
{
private:
    string name;

public:
    Dog(string name = "Unknown")
    {
        this->name = name;
        cout << "Dog constructor called for: " << name << endl;
    }

    ~Dog()
    {
        cout << "Dog destructor called for: " << name << endl;
    }

    void bark()
    {
        cout << name << " says: Woof! Woof!" << endl;
    }
};

void example_6_1_constructor_destructor()
{
    cout << "\n=== Example 6.1: Constructor and Destructor Calls ===" << endl;

    cout << "Creating dog with new..." << endl;
    Dog *pDog = new Dog("Buddy"); // Constructor called

    pDog->bark();

    cout << "Deleting dog..." << endl;
    delete pDog; // Destructor called
}

//============================================================================
// SECTION 7: New vs Malloc (C-style memory allocation)
//
// Both allocate memory, but new/delete are preferred for objects:
//
// malloc/free:
//   - C-style, older approach
//   - Do NOT call constructors or destructors
//   - Return void*, requires casting
//   - Used for simple memory blocks
//
// new/delete:
//   - C++ style, modern approach
//   - Call constructors and destructors
//   - Type-safe, return correct pointer type
//   - Integrate with C++ classes and objects
//
// USE new/delete for C++ code!
//============================================================================

void example_7_1_new_vs_malloc()
{
    cout << "\n=== Example 7.1: new vs malloc ===" << endl;

    // With new - constructor is called
    Dog *p1 = new Dog("Max"); // Constructor called
    p1->bark();
    delete p1; // Destructor called

    // With malloc - NO constructor call (dangerous for objects!)
    // Dog *p2 = (Dog*)malloc(sizeof(Dog)); // DON'T DO THIS!
    // No constructor called - object not properly initialized!
    // free(p2); // Destructor not called - resource leak!

    cout << "Always use new/delete for C++ objects!" << endl;
}

//============================================================================
// SECTION 8: Best Practices and Common Mistakes
//
// BEST PRACTICES:
//   1. Always match new with delete and new[] with delete[]
//   2. Delete in the same scope where you new (or use smart pointers)
//   3. Set pointer to nullptr after delete
//   4. Check for null before dereferencing
//   5. Use RAII pattern or smart pointers for automatic cleanup
//   6. Never delete stack-allocated objects
//
// COMMON MISTAKES:
//   1. Forgetting delete - memory leak
//   2. Using delete[] for single objects or vice versa - undefined behavior
//   3. Dereferencing null pointers - crash
//   4. Accessing deleted objects - undefined behavior
//   5. Using stack pointers after function returns - dangling pointer
//============================================================================

void example_8_1_best_practices()
{
    cout << "\n=== Example 8.1: Best Practices ===" << endl;

    // Good: Allocate
    Dog *pDog = new Dog("Luna");

    // Good: Check before use
    if (pDog != nullptr)
    {
        pDog->bark();
    }

    // Good: Clean up
    delete pDog;
    pDog = nullptr; // Prevent use-after-delete bugs

    // Good: Check before use after delete
    if (pDog == nullptr)
    {
        cout << "Dog pointer is null - object was deleted" << endl;
    }
}

//============================================================================
// MAIN FUNCTION - Run all examples
//============================================================================

int main()
{
    cout << "=====================================================" << endl;
    cout << "LESSON 10: New and Delete Operators" << endl;
    cout << "Dynamic Memory Allocation in C++" << endl;
    cout << "=====================================================" << endl;

    // Section 1: Basic new and delete
    example_1_1_basic_new_delete();
    example_1_2_multiple_objects();

    // Section 2: Pointer size
    example_2_1_pointer_size();

    // Section 3: Primitive types
    example_3_1_primitive_new();

    // Section 4: Arrays
    example_4_1_new_array();
    // Note: Example 4.2 requires user input, commented
    // example_4_2_dynamic_size_array();

    // Section 5: Memory leaks (showing wrong approach briefly)
    // Note: example_5_1_memory_leak_WRONG() is intentionally not called
    //       as it would leak memory. See the code for explanation.
    example_5_2_proper_cleanup();

    // Section 6: Constructor/Destructor
    example_6_1_constructor_destructor();

    // Section 7: new vs malloc
    example_7_1_new_vs_malloc();

    // Section 8: Best practices
    example_8_1_best_practices();

    cout << "\n=====================================================" << endl;
    cout << "KEY TAKEAWAYS:" << endl;
    cout << "1. Use 'new' to allocate memory, 'delete' to free it" << endl;
    cout << "2. Always match new with delete, new[] with delete[]" << endl;
    cout << "3. Constructors are called with new, destructors with delete" << endl;
    cout << "4. Forgetting delete causes memory leaks" << endl;
    cout << "5. Prefer new/delete over malloc/free for C++ objects" << endl;
    cout << "=====================================================" << endl;

    return 0;
}
