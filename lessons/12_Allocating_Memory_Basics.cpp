//============================================================================
// LESSON 12: Allocating Memory
// Author      : M'Barek Benraiss
// Description : Learn advanced memory allocation techniques, including
//               allocating arrays of objects, raw memory blocks,
//               and understanding memory management patterns.
//============================================================================

#include <iostream>
#include <string>
using namespace std;

//============================================================================
// SECTION 1: Allocating Arrays of Objects
//
// When allocating an array of objects with 'new[]':
// - Constructor is called for EACH object in the array
// - You can access elements using array notation with pointer
// - Must use 'delete[]' (with brackets) to deallocate
// - Destructor is called for EACH object
//
// Syntax: ClassName *ptr = new ClassName[size];
//         ptr[index].method();  // Access element
//         delete[] ptr;         // Deallocate all
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

// Example 1.1: Basic array allocation
void example_1_1_array_allocation()
{
    cout << "\n=== Example 1.1: Array Allocation ===" << endl;

    // Allocate array of 5 Animals on heap
    Animal *pAnimals = new Animal[5];
    cout << "\nNow setting names..." << endl;

    // Access elements using array notation
    pAnimals[0].setName("Rex");
    pAnimals[1].setName("Buddy");
    pAnimals[2].setName("Max");
    pAnimals[3].setName("Charlie");
    pAnimals[4].setName("George");

    // Print all
    cout << "\nAll animals:" << endl;
    for (int i = 0; i < 5; i++)
    {
        pAnimals[i].speak();
    }

    // CRITICAL: Use delete[] not delete!
    cout << "\nDeleting array..." << endl;
    delete[] pAnimals; // Each destructor called
}

// Example 1.2: Accessing specific elements
void example_1_2_array_access()
{
    cout << "\n=== Example 1.2: Array Access Patterns ===" << endl;

    // Allocate 10 animals
    Animal *pAnimals = new Animal[10];

    // Set one specific element
    pAnimals[5].setName("George");
    pAnimals[5].speak();

    // You can also use pointer arithmetic
    Animal *pGeorge = pAnimals + 5; // Pointer to element 5
    pGeorge->speak();

    delete[] pAnimals;
}

//============================================================================
// SECTION 2: Allocation Size Determined at Runtime
//
// Unlike stack arrays which require compile-time constant size,
// heap arrays can have size determined at runtime.
//
// Stack: int arr[10];      // Size must be known at compile time
// Heap:  int *p = new int[size];  // Size at runtime

// This is powerful for dynamic sizing based on user input
//============================================================================

void example_2_1_dynamic_size()
{
    cout << "\n=== Example 2.1: Dynamic Size at Runtime ===" << endl;

    // Get size from user
    int size;
    cout << "How many animals? ";
    cin >> size;
    cin.ignore(); // Clear input buffer

    // Allocate array of that size
    Animal *pAnimals = new Animal[size];

    // Initialize and display
    for (int i = 0; i < size; i++)
    {
        string name = "Animal" + to_string(i);
        pAnimals[i].setName(name);
    }

    cout << "\nYour animals:" << endl;
    for (int i = 0; i < size; i++)
    {
        pAnimals[i].speak();
    }

    delete[] pAnimals;
}

void example_2_1_dynamic_size_auto()
{
    cout << "\n=== Example 2.1: Dynamic Size (Auto) ===" << endl;

    // For this example, use fixed size
    int size = 3;

    // Allocate array of that size
    Animal *pAnimals = new Animal[size];

    // Initialize and display
    for (int i = 0; i < size; i++)
    {
        string name = "Animal" + to_string(i);
        pAnimals[i].setName(name);
    }

    cout << "\nAllocated " << size << " animals" << endl;

    delete[] pAnimals;
}

//============================================================================
// SECTION 3: Allocating Raw Memory Blocks
//
// Beyond objects, you can allocate raw memory for any data:
// - char arrays for buffers
// - int arrays for data
// - Any primitive type
//
// This gives direct control over memory without object overhead.
//
// Syntax: Type *ptr = new Type[size];
//         delete[] ptr;  // MUST use [] for arrays
//============================================================================

void example_3_1_raw_memory()
{
    cout << "\n=== Example 3.1: Raw Memory Allocation ===" << endl;

    // Allocate 1000 bytes (chars) for a buffer
    char *pBuffer = new char[1000];
    cout << "Allocated 1000 bytes of memory" << endl;

    // Use the buffer
    for (int i = 0; i < 10; i++)
    {
        pBuffer[i] = 'A' + i; // First 10: A, B, C, ..., J
    }

    // Print first 10 bytes
    cout << "First 10 bytes: ";
    for (int i = 0; i < 10; i++)
    {
        cout << pBuffer[i];
    }
    cout << endl;

    // Clean up
    delete[] pBuffer;
}

// Example 3.2: Integer array allocation
void example_3_2_int_array()
{
    cout << "\n=== Example 3.2: Integer Array Allocation ===" << endl;

    int size = 5;
    int *pNumbers = new int[size];

    // Fill with values
    for (int i = 0; i < size; i++)
    {
        pNumbers[i] = (i + 1) * 10;
    }

    // Display
    cout << "Numbers: ";
    for (int i = 0; i < size; i++)
    {
        cout << pNumbers[i] << " ";
    }
    cout << endl;

    delete[] pNumbers;
}

//============================================================================
// SECTION 4: Understanding Memory Layout
//
// When allocate an array, memory is contiguous:
//
//   Animal *pAnimals = new Animal[3];
//
//   Memory layout:
//   [Animal 0] [Animal 1] [Animal 2]
//     pAnimals   pAnimals+1  pAnimals+2
//
// You can access:
// - pAnimals[0]  (index notation)
// - pAnimals[1]
// - *(pAnimals + 2)  (pointer arithmetic)
//
// This contiguous memory is efficient and cache-friendly.
//============================================================================

void example_4_1_memory_layout()
{
    cout << "\n=== Example 4.1: Memory Layout ===" << endl;

    int *pArray = new int[5]{10, 20, 30, 40, 50};

    cout << "Using index notation:" << endl;
    cout << "pArray[0] = " << pArray[0] << endl;
    cout << "pArray[2] = " << pArray[2] << endl;

    cout << "\nUsing pointer arithmetic:" << endl;
    cout << "*(pArray + 0) = " << *(pArray + 0) << endl;
    cout << "*(pArray + 2) = " << *(pArray + 2) << endl;

    cout << "\nPointer addresses:" << endl;
    cout << "pArray:   " << pArray << endl;
    cout << "pArray+1: " << (pArray + 1) << endl;
    cout << "pArray+2: " << (pArray + 2) << endl;
    cout << "Memory is contiguous!" << endl;

    delete[] pArray;
}

//============================================================================
// SECTION 5: Mixed Stack and Heap Arrays
//
// You can use both:
// - Stack arrays: Fast, automatic cleanup, size fixed at compile time
// - Heap arrays: Flexible size, manual cleanup, larger possible size
//
// Choose based on:
// - Size: Small/known → stack; Large/unknown → heap
// - Lifetime: Scope → stack; Persistent → heap
// - Complexity: Simple → stack; Dynamic → heap
//============================================================================

void example_5_1_mixed_allocation()
{
    cout << "\n=== Example 5.1: Stack vs Heap ===" << endl;

    cout << "Stack array:" << endl;
    int stackArray[3] = {1, 2, 3}; // Automatic, fast, fixed size
    cout << "Stack[0] = " << stackArray[0] << endl;
    // Automatic cleanup

    cout << "\nHeap array:" << endl;
    int *heapArray = new int[3]{4, 5, 6}; // Flexible size, manual cleanup
    cout << "Heap[0] = " << heapArray[0] << endl;
    delete[] heapArray; // Manual cleanup required
}

//============================================================================
// SECTION 6: Character Arrays and Strings
//
// Working with character arrays:
// - char array can hold strings
// - Null terminator '\0' marks end
// - string class provides higher-level abstraction
// - Can create string with repeated character
//
// Example: string name(5, 'a');  // "aaaaa"
//          char *p = new char[5];  // Raw memory
//============================================================================

void example_6_1_char_arrays()
{
    cout << "\n=== Example 6.1: Character Arrays ===" << endl;

    // Create string with repeated character
    char firstChar = 'a';
    firstChar++; // Now 'b'

    string repeatedChars(5, firstChar); // "bbbbb"
    cout << "Repeated chars: " << repeatedChars << endl;

    // Raw character array
    char *pChars = new char[10];
    pChars[0] = 'H';
    pChars[1] = 'i';
    pChars[2] = '\0'; // Null terminator
    cout << "String from char array: " << pChars << endl;

    delete[] pChars;
}

//============================================================================
// SECTION 7: Important Rules for Array Allocation
//
// RULE 1: Match new[] with delete[]
//   ✓ new[] Animal[10];  delete[] pAnimals;
//   ✗ new[] int[5];      delete ptr;  // WRONG!
//
// RULE 2: Size is determined at runtime for heap arrays
//   ✓ int *p = new int[userSize];
//   ✗ int stackArray[userSize];  // COMPILE ERROR
//
// RULE 3: Constructor/Destructor called for each element
//   new[] calls constructor size times
//   delete[] calls destructor size times
//
// RULE 4: Check bounds yourself (arrays don't bounds-check)
//   int *p = new int[5];
//   p[100] = 5;  // No error, undefined behavior!
//============================================================================

void example_7_1_allocation_rules()
{
    cout << "\n=== Example 7.1: Allocation Rules ===" << endl;

    // Rule 1: Match new[] with delete[]
    Animal *pAnimals = new Animal[3];
    delete[] pAnimals; // Correct

    // Rule 2: Size at runtime
    int size = 10;
    int *pNums = new int[size]; // Runtime size
    delete[] pNums;

    // Rule 4: No bounds checking
    int *p = new int[5];
    // p[100] = 5;  // Undefined behavior! Don't do this
    delete[] p;

    cout << "All allocation rules followed!" << endl;
}

//============================================================================
// SECTION 8: Practical Examples - Complete Programs
//
// Real-world patterns for memory allocation:
// 1. Dynamically sized data structures
// 2. Buffers for I/O operations
// 3. Arrays of objects that outlive scope
// 4. Efficient memory usage based on runtime needs
//============================================================================

void example_8_1_practical_buffer()
{
    cout << "\n=== Example 8.1: Practical Buffer Allocation ===" << endl;

    // Simulate reading a file of unknown size
    int fileSize = 256; // Would come from file
    char *pBuffer = new char[fileSize];

    // Simulate reading data
    cout << "Allocating buffer for " << fileSize << " bytes" << endl;
    for (int i = 0; i < fileSize; i++)
    {
        pBuffer[i] = 'X';
    }

    cout << "Buffer usage complete" << endl;
    delete[] pBuffer;
}

void example_8_2_practical_objects()
{
    cout << "\n=== Example 8.2: Practical Object Array ===" << endl;

    // Factory simulation - unknown number of objects
    int numAnimals = 3;
    Animal *pPets = new Animal[numAnimals];

    // Name them
    pPets[0].setName("Dog");
    pPets[1].setName("Cat");
    pPets[2].setName("Bird");

    // Use them
    cout << "Our pets:" << endl;
    for (int i = 0; i < numAnimals; i++)
    {
        pPets[i].speak();
    }

    delete[] pPets;
}

//============================================================================
// MAIN FUNCTION - Run all examples
//============================================================================

int main()
{
    cout << "=====================================================" << endl;
    cout << "LESSON 12: Allocating Memory" << endl;
    cout << "Arrays, Buffers, and Dynamic Sizing" << endl;
    cout << "=====================================================" << endl;

    // Section 1: Array allocation
    example_1_1_array_allocation();
    example_1_2_array_access();

    // Section 2: Runtime sizing
    example_2_1_dynamic_size_auto();

    // Section 3: Raw memory
    example_3_1_raw_memory();
    example_3_2_int_array();

    // Section 4: Memory layout
    example_4_1_memory_layout();

    // Section 5: Stack vs heap
    example_5_1_mixed_allocation();

    // Section 6: Character arrays
    example_6_1_char_arrays();

    // Section 7: Rules
    example_7_1_allocation_rules();

    // Section 8: Practical examples
    example_8_1_practical_buffer();
    example_8_2_practical_objects();

    cout << "\n=====================================================" << endl;
    cout << "KEY TAKEAWAYS:" << endl;
    cout << "1. Use new[] to allocate arrays, delete[] to free them" << endl;
    cout << "2. Array size can be determined at runtime (heap only)" << endl;
    cout << "3. Constructor/destructor called for each array element" << endl;
    cout << "4. Access array elements using index notation: ptr[i]" << endl;
    cout << "5. Memory is contiguous and cache-friendly" << endl;
    cout << "6. Choose stack arrays for fixed, small sizes" << endl;
    cout << "7. Choose heap arrays for dynamic, large sizes" << endl;
    cout << "=====================================================" << endl;

    return 0;
}
