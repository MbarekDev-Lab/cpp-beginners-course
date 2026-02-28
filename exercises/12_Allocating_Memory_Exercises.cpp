//============================================================================
// LESSON 12 EXERCISES: Allocating Memory
// Author      : M'Barek Benraiss
// Description : Practice allocating and managing arrays of objects,
//               raw memory buffers, and understanding memory layout.
//
// INSTRUCTIONS:
// - Solve each exercise by writing/completing code
// - Pay attention to matching new[] with delete[]
// - Understand constructor/destructor behavior
// - Test memory allocation and cleanup
//============================================================================

#include <iostream>
#include <string>
using namespace std;

//============================================================================
// EXERCISE 1: Basic Array Allocation
//
// Create an array of Person objects (size 3) on the heap:
// 1. Allocate with new[]
// 2. Store names: "Alice", "Bob", "Charlie"
// 3. Display all using a loop
// 4. Delete with delete[]
//
// HINT: Person *pPeople = new Person[3];
//       pPeople[i].method();
//       delete[] pPeople;
//============================================================================

class Person {
private:
    string name;
    int age;
    
public:
    Person(string n = "Unknown", int a = 0) : name(n), age(a) {
        cout << "Person created: " << name << endl;
    }
    
    ~Person() {
        cout << "Person destroyed: " << name << endl;
    }
    
    void setName(string n) { name = n; }
    void setAge(int a) { age = a; }
    
    void display() const {
        cout << name << " (" << age << ")" << endl;
    }
};

void exercise_1() {
    cout << "\n=== EXERCISE 1: Basic Array Allocation ===" << endl;
    
    // TODO: Allocate Person array of size 3
    // TODO: Set names for each
    // TODO: Display all in loop
    // TODO: Delete array
    
    // SOLUTION:
    Person *pPeople = new Person[3];
    
    pPeople[0].setName("Alice");
    pPeople[1].setName("Bob");
    pPeople[2].setName("Charlie");
    
    cout << "All people:" << endl;
    for (int i = 0; i < 3; i++) {
        pPeople[i].display();
    }
    
    delete[] pPeople;
}

//============================================================================
// EXERCISE 2: Dynamic Size Array
//
// Create an array where:
// 1. User enters desired size
// 2. Allocate that many Person objects
// 3. Name them: "Person0", "Person1", etc.
// 4. Display all
// 5. Delete array
//
// HINT: This shows runtime flexibility of heap allocation
//       Stack array would require compile-time constant size
//============================================================================

void exercise_2_with_input() {
    cout << "\n=== EXERCISE 2: Dynamic Size Array ===" << endl;
    
    int size;
    cout << "How many people? ";
    cin >> size;
    cin.ignore();  // Clear input buffer
    
    Person *pPeople = new Person[size];
    
    // Name them
    for (int i = 0; i < size; i++) {
        pPeople[i].setName("Person" + to_string(i));
    }
    
    // Display
    cout << "\nAll people:" << endl;
    for (int i = 0; i < size; i++) {
        pPeople[i].display();
    }
    
    delete[] pPeople;
}

void exercise_2() {
    cout << "\n=== EXERCISE 2: Dynamic Size Array ===" << endl;
    
    // For automated testing, use fixed size
    int size = 4;
    
    Person *pPeople = new Person[size];
    
    // Name them
    for (int i = 0; i < size; i++) {
        pPeople[i].setName("Person" + to_string(i));
    }
    
    // Display
    cout << "Allocated " << size << " people" << endl;
    
    delete[] pPeople;
}

//============================================================================
// EXERCISE 3: Counting Constructors and Destructors
//
// Observe constructor and destructor calls:
// 1. Allocate array of 5 Person objects
// 2. Watch how many times constructor is called (should be 5)
// 3. Delete array
// 4. Watch how many times destructor is called (should be 5)
// 5. Report the counts
//
// HINT: Look at cout statements in constructor/destructor
//       Count how many "created" and "destroyed" messages appear
//============================================================================

void exercise_3() {
    cout << "\n=== EXERCISE 3: Tracking Constructor/Destructor ===" << endl;
    
    cout << "Creating array..." << endl;
    Person *pPeople = new Person[5];  // Notice output: 5 constructors
    
    cout << "\nDeleting array..." << endl;
    delete[] pPeople;  // Notice output: 5 destructors
}

//============================================================================
// EXERCISE 4: Array Indexing vs Pointer Arithmetic
//
// Demonstrate both ways to access array elements:
// 1. Create array of 5 integers
// 2. Fill using index notation: arr[i]
// 3. Display using pointer arithmetic: *(arr + i)
// 4. Verify same results
//
// HINT: arr[i] is exactly the same as *(arr + i)
//============================================================================

void exercise_4() {
    cout << "\n=== EXERCISE 4: Index vs Pointer Arithmetic ===" << endl;
    
    int *pArray = new int[5];
    
    cout << "Filling with index notation:" << endl;
    for (int i = 0; i < 5; i++) {
        pArray[i] = (i + 1) * 10;
        cout << "pArray[" << i << "] = " << pArray[i] << endl;
    }
    
    cout << "\nDisplaying with pointer arithmetic:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "*(pArray + " << i << ") = " << *(pArray + i) << endl;
    }
    
    delete[] pArray;
}

//============================================================================
// EXERCISE 5: Character Buffer Allocation
//
// Allocate and use a character buffer:
// 1. Create char array of size 100
// 2. Fill first 26 elements with 'a' through 'z'
// 3. Add null terminator at position 26
// 4. Print as string
// 5. Delete buffer
//
// HINT: char *pBuffer = new char[100];
//       pBuffer[26] = '\0';  // Null terminator
//       cout << pBuffer << endl;
//============================================================================

void exercise_5() {
    cout << "\n=== EXERCISE 5: Character Buffer ===" << endl;
    
    char *pBuffer = new char[100];
    
    // Fill with alphabet
    for (int i = 0; i < 26; i++) {
        pBuffer[i] = 'a' + i;
    }
    pBuffer[26] = '\0';  // Null terminator
    
    cout << "Buffer contents: " << pBuffer << endl;
    
    delete[] pBuffer;
}

//============================================================================
// EXERCISE 6: Integer Array Buffer
//
// Allocate array for integer data:
// 1. Create int array of size 10
// 2. Fill with squares: 1^2, 2^2, 3^2, ... 10^2
// 3. Sum all elements
// 4. Display sum
// 5. Delete array
//
// HINT: pArray[i] = (i+1) * (i+1);
//       or: pArray[i] = pow(i+1, 2);
//============================================================================

void exercise_6() {
    cout << "\n=== EXERCISE 6: Integer Array Buffer ===" << endl;
    
    int *pArray = new int[10];
    
    // Fill with squares
    for (int i = 0; i < 10; i++) {
        pArray[i] = (i + 1) * (i + 1);
    }
    
    // Sum all
    int sum = 0;
    for (int i = 0; i < 10; i++) {
        sum += pArray[i];
    }
    
    cout << "Sum of squares 1-10: " << sum << endl;  // Should be 385
    
    delete[] pArray;
}

//============================================================================
// EXERCISE 7: String Array (Creating Strings with Repeated Chars)
//
// Practice string creation with repeated characters:
// 1. Start with character 'a'
// 2. Increment to 'b'
// 3. Create string with 5 'b's: "bbbbb"
// 4. Display the string
//
// HINT: char c = 'a';
//       c++;  // Now 'b'
//       string s(5, c);  // Creates "bbbbb"
//============================================================================

void exercise_7() {
    cout << "\n=== EXERCISE 7: Repeated Character Strings ===" << endl;
    
    char c = 'a';
    c++;  // Now 'b'
    
    string repeated(5, c);  // Create "bbbbb"
    cout << "Repeated character string: " << repeated << endl;
}

//============================================================================
// EXERCISE 8: Wrong delete (Don't Run - Just Study)
//
// This exercise shows the WRONG way - do NOT execute!
// Study the code to understand the mistake:
//
//   Animal *p = new Animal[10];
//   delete p;  // WRONG! Should be delete[]
//
// Fix: Change to delete[] p;
//
// The mistake: Mismatch between new[] and delete
// Result: Undefined behavior, memory corruption, crashes
//
// HINT: The commented code shows the wrong approach
//============================================================================

void exercise_8_WRONG() {
    // DO NOT UNCOMMENT - Shows incorrect usage
    // Person *p = new Person[5];
    // delete p;  // WRONG! Missing []
    // This causes undefined behavior!
}

void exercise_8_CORRECT() {
    cout << "\n=== EXERCISE 8: Correct delete[] Usage ===" << endl;
    
    Person *p = new Person[5];
    cout << "Using array..." << endl;
    delete[] p;  // CORRECT - with []
}

//============================================================================
// EXERCISE 9: Pointer Arithmetic
//
// Demonstrate pointer arithmetic on arrays:
// 1. Create int array of 5 elements
// 2. Access each element using pointer + offset
// 3. Display addresses and values
// 4. Show that memory is contiguous
//
// HINT: pArray, pArray+1, pArray+2, etc.
//       Addresses should differ by size of int (4 bytes typically)
//============================================================================

void exercise_9() {
    cout << "\n=== EXERCISE 9: Pointer Arithmetic ===" << endl;
    
    int *pArray = new int[5]{10, 20, 30, 40, 50};
    
    cout << "Pointer addresses and values:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "pArray+" << i << " = " << (pArray + i);
        cout << ", value = " << *(pArray + i) << endl;
    }
    
    cout << "\nMemory is contiguous!" << endl;
    
    delete[] pArray;
}

//============================================================================
// EXERCISE 10: Multiple Arrays
//
// Manage multiple separate arrays:
// 1. Create two int arrays (size 5 each)
// 2. Fill with different values
// 3. Display both arrays
// 4. Delete both arrays separately
// 5. Set both to nullptr
//
// HINT: Each new[] needs its own delete[]
//       Each is independent memory block
//============================================================================

void exercise_10() {
    cout << "\n=== EXERCISE 10: Multiple Arrays ===" << endl;
    
    // Create two arrays
    int *pArray1 = new int[5]{1, 2, 3, 4, 5};
    int *pArray2 = new int[5]{10, 20, 30, 40, 50};
    
    // Display
    cout << "Array 1: ";
    for (int i = 0; i < 5; i++) cout << pArray1[i] << " ";
    cout << endl;
    
    cout << "Array 2: ";
    for (int i = 0; i < 5; i++) cout << pArray2[i] << " ";
    cout << endl;
    
    // Delete both
    delete[] pArray1;
    delete[] pArray2;
    pArray1 = nullptr;
    pArray2 = nullptr;
}

//============================================================================
// EXERCISE 11: Array of Objects with Initialization
//
// Create and initialize object array:
// 1. Allocate array of 3 Person objects
// 2. Use setAge() to set ages: 25, 30, 35
// 3. Display persons with their ages
// 4. Find and display oldest person
// 5. Delete array
//
// HINT: Keep track of max age while iterating
//============================================================================

void exercise_11() {
    cout << "\n=== EXERCISE 11: Object Array with Multiple Operations ===" << endl;
    
    Person *pPeople = new Person[3];
    
    // Set names and ages
    pPeople[0].setName("Alice");
    pPeople[0].setAge(25);
    
    pPeople[1].setName("Bob");
    pPeople[1].setAge(30);
    
    pPeople[2].setName("Charlie");
    pPeople[2].setAge(35);
    
    // Display all
    cout << "All persons:" << endl;
    for (int i = 0; i < 3; i++) {
        pPeople[i].display();
    }
    
    delete[] pPeople;
}

//============================================================================
// EXERCISE 12: Large Array Allocation
//
// Allocate and work with larger array:
// 1. Create array of 100 integers
// 2. Fill with random-like values: i * i (i squared)
// 3. Find sum of all elements
// 4. Find average
// 5. Find max value
// 6. Display statistics
// 7. Delete array
//
// HINT: Track sum, count, and max while iterating
//============================================================================

void exercise_12() {
    cout << "\n=== EXERCISE 12: Large Array Operations ===" << endl;
    
    int size = 100;
    int *pArray = new int[size];
    
    // Fill with squares
    for (int i = 0; i < size; i++) {
        pArray[i] = i * i;
    }
    
    // Calculate statistics
    int sum = 0;
    int maxVal = pArray[0];
    
    for (int i = 0; i < size; i++) {
        sum += pArray[i];
        if (pArray[i] > maxVal) {
            maxVal = pArray[i];
        }
    }
    
    double average = (double)sum / size;
    
    cout << "Array of " << size << " elements" << endl;
    cout << "Sum: " << sum << endl;
    cout << "Average: " << average << endl;
    cout << "Maximum: " << maxVal << endl;
    
    delete[] pArray;
}

//============================================================================
// EXERCISE 13: Complete Program - Data Analysis
//
// Write complete program that:
// 1. Allocate array of 10 integers
// 2. Fill with sample data
// 3. Calculate: sum, average, min, max
// 4. Display results
// 5. Delete and cleanup
//
// This combines all concepts from lesson 12.
//
// HINT: Use a loop for statistics calculation
//       Track min/max carefully
//============================================================================

void exercise_13() {
    cout << "\n=== EXERCISE 13: Complete Data Analysis Program ===" << endl;
    
    const int ARRAY_SIZE = 10;
    int *pData = new int[ARRAY_SIZE]{15, 23, 8, 42, 17, 39, 6, 51, 28, 14};
    
    // Calculate statistics
    int sum = 0;
    int minVal = pData[0];
    int maxVal = pData[0];
    
    for (int i = 0; i < ARRAY_SIZE; i++) {
        sum += pData[i];
        if (pData[i] < minVal) minVal = pData[i];
        if (pData[i] > maxVal) maxVal = pData[i];
    }
    
    double average = (double)sum / ARRAY_SIZE;
    
    // Display results
    cout << "\n=== STATISTICS ===" << endl;
    cout << "Count: " << ARRAY_SIZE << endl;
    cout << "Sum: " << sum << endl;
    cout << "Average: " << average << endl;
    cout << "Minimum: " << minVal << endl;
    cout << "Maximum: " << maxVal << endl;
    cout << "Range: " << (maxVal - minVal) << endl;
    
    // Cleanup
    delete[] pData;
    pData = nullptr;
}

//============================================================================
// MAIN FUNCTION - Run Selected Exercises
//============================================================================

int main() {
    cout << "=====================================================" << endl;
    cout << "LESSON 12 EXERCISES: Allocating Memory" << endl;
    cout << "=====================================================" << endl;

    // Uncomment exercises to test:
    
    exercise_1();
    exercise_2();
    exercise_3();
    exercise_4();
    exercise_5();
    exercise_6();
    exercise_7();
    exercise_8_CORRECT();
    exercise_9();
    exercise_10();
    exercise_11();
    exercise_12();
    exercise_13();

    cout << "\n=====================================================" << endl;
    cout << "EXERCISE SUMMARY" << endl;
    cout << "=====================================================" << endl;
    cout << "1. Basic Array Allocation - new[]/delete[] basics" << endl;
    cout << "2. Dynamic Size Array - Runtime sizing" << endl;
    cout << "3. Constructor/Destructor - Tracking initialization" << endl;
    cout << "4. Index vs Pointer - Two ways to access" << endl;
    cout << "5. Character Buffer - Raw char memory" << endl;
    cout << "6. Integer Buffer - Integer array operations" << endl;
    cout << "7. Repeated Characters - String construction" << endl;
    cout << "8. Delete Correctness - Using delete[] properly" << endl;
    cout << "9. Pointer Arithmetic - Address calculations" << endl;
    cout << "10. Multiple Arrays - Multiple allocations" << endl;
    cout << "11. Object Array - Complex object arrays" << endl;
    cout << "12. Large Array - Statistics and operations" << endl;
    cout << "13. Complete Program - Bring everything together" << endl;
    cout << "=====================================================" << endl;

    return 0;
}
