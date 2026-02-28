//============================================================================
// LESSON 13: Arrays and Functions
// Author      : M'Barek Benraiss
// Description : Learn how to pass arrays to functions, understand array
//               decay, pointer parameters, and effective array manipulation
//               through function calls.
//============================================================================

#include <iostream>
#include <cmath>
using namespace std;

//============================================================================
// SECTION 1: Array Decay - Arrays Become Pointers
//
// When passing an array to a function:
// - The array DECAYS into a pointer to its first element
// - Only the address is passed, not the entire array
// - The function receives a pointer, not the original array
// - This is efficient - no copy of all array elements
// - But: Size information is lost!
//
// Important: Arrays decay to pointers automatically
// int arr[10];
// After passing: function receives int*, not int[10]
//============================================================================

void printArray_v1(int arr[])
{
    // arr looks like an array but is actually int*
    // Can use array notation inside function
    cout << "Element 0: " << arr[0] << endl;
    cout << "Element 2: " << arr[2] << endl;

    // But we don't know the size! Can't do bounds checking
    // cout << "Size: " << sizeof(arr) << endl;  // WRONG!
}

void printArray_v2(int *arr)
{
    // This is the same as above! arr[] is really a pointer
    cout << "Element 0: " << arr[0] << endl;
    cout << "Element 2: " << arr[2] << endl;
}

// Example 1.1: Array decay demonstration
void example_1_1_array_decay()
{
    cout << "\n=== Example 1.1: Array Decay ===" << endl;

    int values[5] = {10, 20, 30, 40, 50};

    cout << "Stack array size: " << sizeof(values) << endl; // 20 bytes (5 ints)

    printArray_v1(values); // Array decays to pointer

    // Inside function: arr is pointer, sizeof(arr) wouldn't give 20
}

//============================================================================
// SECTION 2: Passing Array Size as Parameter
//
// Since the function doesn't know array size automatically,
// you must pass it explicitly as a parameter.
//
// Two common approaches:
// 1. Pass size as separate parameter
// 2. Use sentinel values (like '\0' in strings)
//
// Best practice: Always pass size with arrays
//============================================================================

void printArrayWithSize(int arr[], int size)
{
    cout << "Array contents: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void sumArray(int arr[], int size)
{
    int total = 0;
    for (int i = 0; i < size; i++)
    {
        total += arr[i];
    }
    cout << "Sum: " << total << endl;
}

// Example 2.1: Passing size parameter
void example_2_1_array_with_size()
{
    cout << "\n=== Example 2.1: Array with Size Parameter ===" << endl;

    int numbers[4] = {5, 10, 15, 20};

    printArrayWithSize(numbers, 4);
    sumArray(numbers, 4);
}

// Example 2.2: Modifying array in function
void increment_all(int arr[], int size)
{
    // Changes affect original array!
    for (int i = 0; i < size; i++)
    {
        arr[i]++;
    }
}

void example_2_2_array_modification()
{
    cout << "\n=== Example 2.2: Modifying Array in Function ===" << endl;

    int numbers[3] = {1, 2, 3};

    cout << "Before: ";
    printArrayWithSize(numbers, 3);

    increment_all(numbers, 3);

    cout << "After:  ";
    printArrayWithSize(numbers, 3);
}

//============================================================================
// SECTION 3: Reference Parameters for Arrays
//
// You can pass arrays by reference to ensure you're modifying
// the original, and sometimes for clarity.
//
// Syntax: void function(int (&arr)[size])
//
// Reference syntax is awkward but ensures:
// - You know the exact size at compile time
// - True reference (not just a pointer)
// - Can't accidentally pass array of wrong size
//
// Note: Rarely used in practice, pointers more common
//============================================================================

// Function expecting exactly 5 integers
void processFixedArray(int (&arr)[5])
{
    cout << "Processing array of exactly 5 elements:" << endl;
    for (int i = 0; i < 5; i++)
    {
        arr[i] *= 2;
    }
}

void example_3_1_reference_arrays()
{
    cout << "\n=== Example 3.1: Array References ===" << endl;

    int arr[5] = {1, 2, 3, 4, 5};

    cout << "Before: ";
    printArrayWithSize(arr, 5);

    processFixedArray(arr);

    cout << "After:  ";
    printArrayWithSize(arr, 5);
}

//============================================================================
// SECTION 4: Arrays of Objects and Functions
//
// Same principles apply to arrays of custom objects:
// - Array decays to pointer
// - Pass size parameter
// - Can iterate and modify objects
// - Constructors/destructors work normally
//============================================================================

class Animal
{
private:
    string name;

public:
    Animal(string n = "Unknown") : name(n)
    {
        cout << "Animal created: " << name << endl;
    }

    ~Animal()
    {
        cout << "Animal destroyed: " << name << endl;
    }

    void setName(string n) { name = n; }
    void speak() const { cout << "I am: " << name << endl; }
};

void displayAnimals(Animal arr[], int size)
{
    cout << "All animals:" << endl;
    for (int i = 0; i < size; i++)
    {
        arr[i].speak();
    }
}

void example_4_1_object_arrays()
{
    cout << "\n=== Example 4.1: Arrays of Objects ===" << endl;

    Animal animals[3] = {
        Animal("Dog"),
        Animal("Cat"),
        Animal("Bird")};

    displayAnimals(animals, 3);
}

//============================================================================
// SECTION 5: Pointer Parameters vs Array Parameters
//
// In C++, these are IDENTICAL at the function level:
//
//   void func(int arr[])    // Array parameter
//   void func(int *arr)     // Pointer parameter
//   void func(int arr[10])  // Size is ignored!
//
// The compiler treats all three the same way:
//   - Receives a pointer to int
//   - Doesn't know the original array size
//
// The size hint in brackets is for human readers only!
// It doesn't create bounds checking.
//
// Best practice:
// - Use pointer notation for clarity: int *p
// - Or use array notation with size: int arr[], int size
//============================================================================

// All three functions are identical to the compiler:
void func1(int arr[])
{
    cout << "Using arr[] notation" << endl;
}

void func2(int *arr)
{
    cout << "Using *arr notation" << endl;
}

void func3(int arr[10])
{
    // Size hint is ignored by compiler!
    cout << "Size hint ignored" << endl;
}

void example_5_1_parameter_equivalence()
{
    cout << "\n=== Example 5.1: Parameter Equivalence ===" << endl;

    int arr[5] = {1, 2, 3, 4, 5};

    func1(arr); // Works
    func2(arr); // Works - same as func1
    func3(arr); // Works - size hint ignored
}

//============================================================================
// SECTION 6: Heap Arrays and Functions
//
// When passing heap-allocated arrays to functions:
// - Same principles: pointers, size parameter
// - Function can modify the heap array
// - Function doesn't own the memory
// - Original caller responsible for delete
//
// Important: Function that allocates should document
// that caller must delete the returned pointer
//============================================================================

int *allocateArray(int size)
{
    int *pArray = new int[size];
    return pArray; // Caller owns this!
}

void fillArray(int arr[], int size, int value)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = value * (i + 1);
    }
}

void example_6_1_heap_arrays()
{
    cout << "\n=== Example 6.1: Heap Arrays and Functions ===" << endl;

    int *pNumbers = allocateArray(5);

    fillArray(pNumbers, 5, 10);

    cout << "Heap array: ";
    printArrayWithSize(pNumbers, 5);

    delete[] pNumbers;
}

//============================================================================
// SECTION 7: Pointer Arithmetic in Functions
//
// You can use pointer arithmetic inside functions:
// - Increment/decrement pointers
// - Calculate array ranges
// - Use start and end pointers
//
// Useful for iterating over ranges or subsets
//============================================================================

void printRange(int *pStart, int *pEnd)
{
    cout << "Range: ";
    for (int *p = pStart; p != pEnd; p++)
    {
        cout << *p << " ";
    }
    cout << endl;
}

void example_7_1_pointer_arithmetic()
{
    cout << "\n=== Example 7.1: Pointer Arithmetic in Functions ===" << endl;

    int arr[5] = {10, 20, 30, 40, 50};

    printRange(arr, arr + 5);     // All elements
    printRange(arr + 1, arr + 4); // Middle elements
}

//============================================================================
// SECTION 8: Practical Patterns
//
// Common function patterns for arrays:
// 1. Search - find element
// 2. Filter - count matching elements
// 3. Transform - modify all elements
// 4. Aggregate - sum, average, min, max
//============================================================================

// Pattern 1: Search
int findValue(int arr[], int size, int target)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == target)
        {
            return i; // Found at index i
        }
    }
    return -1; // Not found
}

// Pattern 2: Count matching condition
int countEven(int arr[], int size)
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] % 2 == 0)
        {
            count++;
        }
    }
    return count;
}

// Pattern 3: Find maximum
int findMax(int arr[], int size)
{
    int maxVal = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] > maxVal)
        {
            maxVal = arr[i];
        }
    }
    return maxVal;
}

// Pattern 4: Calculate average
double calculateAverage(int arr[], int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }
    return (double)sum / size;
}

void example_8_1_practical_patterns()
{
    cout << "\n=== Example 8.1: Practical Patterns ===" << endl;

    int numbers[6] = {15, 22, 8, 45, 12, 33};

    cout << "Finding 45: index " << findValue(numbers, 6, 45) << endl;
    cout << "Even count: " << countEven(numbers, 6) << endl;
    cout << "Maximum: " << findMax(numbers, 6) << endl;
    cout << "Average: " << calculateAverage(numbers, 6) << endl;
}

//============================================================================
// MAIN FUNCTION - Run all examples
//============================================================================

int main()
{
    cout << "=====================================================" << endl;
    cout << "LESSON 13: Arrays and Functions" << endl;
    cout << "Passing, Modifying, and Working with Arrays" << endl;
    cout << "=====================================================" << endl;

    // Section 1: Array decay
    example_1_1_array_decay();

    // Section 2: Array with size
    example_2_1_array_with_size();
    example_2_2_array_modification();

    // Section 3: References
    example_3_1_reference_arrays();

    // Section 4: Object arrays
    example_4_1_object_arrays();

    // Section 5: Parameter equivalence
    example_5_1_parameter_equivalence();

    // Section 6: Heap arrays
    example_6_1_heap_arrays();

    // Section 7: Pointer arithmetic
    example_7_1_pointer_arithmetic();

    // Section 8: Practical patterns
    example_8_1_practical_patterns();

    cout << "\n=====================================================" << endl;
    cout << "KEY TAKEAWAYS:" << endl;
    cout << "1. Arrays decay to pointers when passed to functions" << endl;
    cout << "2. Always pass array size as a parameter" << endl;
    cout << "3. Array notation arr[] is identical to pointer *arr" << endl;
    cout << "4. Functions can modify arrays (passing by reference)" << endl;
    cout << "5. Size information is lost - you control bounds" << endl;
    cout << "6. Same rules apply to heap and stack arrays" << endl;
    cout << "7. Common patterns: search, filter, transform, aggregate" << endl;
    cout << "=====================================================" << endl;

    return 0;
}
/*

/Users/benraiss/CLionProjects/learnCpp/cmake-build-debug/learnCpp
=====================================================
LESSON 13: Arrays and Functions
Passing, Modifying, and Working with Arrays
=====================================================

=== Example 1.1: Array Decay ===
Stack array size: 20
Element 0: 10
Element 2: 30

=== Example 2.1: Array with Size Parameter ===
Array contents: 5 10 15 20
Sum: 50

=== Example 2.2: Modifying Array in Function ===
Before: Array contents: 1 2 3
After:  Array contents: 2 3 4

=== Example 3.1: Array References ===
Before: Array contents: 1 2 3 4 5
Processing array of exactly 5 elements:
After:  Array contents: 2 4 6 8 10

=== Example 4.1: Arrays of Objects ===
Animal created: Dog
Animal created: Cat
Animal created: Bird
All animals:
I am: Dog
I am: Cat
I am: Bird
Animal destroyed: Bird
Animal destroyed: Cat
Animal destroyed: Dog

=== Example 5.1: Parameter Equivalence ===
Using arr[] notation
Using *arr notation
Size hint ignored

=== Example 6.1: Heap Arrays and Functions ===
Heap array: Array contents: 10 20 30 40 50

=== Example 7.1: Pointer Arithmetic in Functions ===
Range: 10 20 30 40 50
Range: 20 30 40

=== Example 8.1: Practical Patterns ===
Finding 45: index 3
Even count: 3
Maximum: 45
Average: 22.5

=====================================================
KEY TAKEAWAYS:
1. Arrays decay to pointers when passed to functions
2. Always pass array size as a parameter
3. Array notation arr[] is identical to pointer *arr
4. Functions can modify arrays (passing by reference)
5. Size information is lost - you control bounds
6. Same rules apply to heap and stack arrays
7. Common patterns: search, filter, transform, aggregate
=====================================================

Process finished with exit code 0


*/