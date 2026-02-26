//============================================================================
// Const Exercises - Practice Problems
// Master the const keyword and pointer const-ness!
//============================================================================

#include <iostream>
using namespace std;

//============================================================================
// EXERCISE 1: Const Variables
//============================================================================
void exercise1()
{
    cout << "\n========== EXERCISE 1: Const Variables ==========" << endl;

    const double PI = 3.141592;
    const int MAX_STUDENTS = 100;
    const string SCHOOL_NAME = "Tech Academy";

    cout << "Const variables:" << endl;
    cout << "  PI = " << PI << endl;
    cout << "  MAX_STUDENTS = " << MAX_STUDENTS << endl;
    cout << "  SCHOOL_NAME = " << SCHOOL_NAME << endl;

    // Cannot modify:
    // PI = 3.14;  // ERROR
    // MAX_STUDENTS = 50;  // ERROR

    cout << "\nConst variables prevent accidental modification" << endl;
}

//============================================================================
// EXERCISE 2: Regular Pointer
//============================================================================
void exercise2()
{
    cout << "\n========== EXERCISE 2: Regular Pointer ==========" << endl;

    int x = 10;
    int y = 20;

    int *ptr = &x;

    cout << "int *ptr = &x;" << endl;
    cout << "*ptr = " << *ptr << endl;

    // Can modify data
    *ptr = 50;
    cout << "After *ptr = 50: x = " << x << endl;

    // Can change pointer
    ptr = &y;
    cout << "After ptr = &y: *ptr = " << *ptr << endl;

    cout << "\nBoth pointer AND data can change" << endl;
}

//============================================================================
// EXERCISE 3: Const Pointer
//============================================================================
void exercise3()
{
    cout << "\n========== EXERCISE 3: Const Pointer ==========" << endl;

    int x = 10;
    int y = 20;

    int *const ptr = &x;

    cout << "int * const ptr = &x;" << endl;
    cout << "*ptr = " << *ptr << endl;

    // CAN modify data
    *ptr = 100;
    cout << "After *ptr = 100: x = " << x << endl;

    // CANNOT change pointer
    // ptr = &y;  // ERROR - const pointer!
    cout << "\nCannot reassign const pointer: ptr = &y;" << endl;
    cout << "\nConst pointer: pointer is FIXED, data can change" << endl;
}

//============================================================================
// EXERCISE 4: Pointer to Const
//============================================================================
void exercise4()
{
    cout << "\n========== EXERCISE 4: Pointer to Const ==========" << endl;

    int x = 10;
    int y = 20;

    const int *ptr = &x;

    cout << "const int *ptr = &x;" << endl;
    cout << "*ptr = " << *ptr << endl;

    // CANNOT modify data
    // *ptr = 100;  // ERROR - data is const!
    cout << "Cannot modify: *ptr = 100; (error)" << endl;

    // CAN change pointer
    ptr = &y;
    cout << "After ptr = &y: *ptr = " << *ptr << endl;

    cout << "\nPointer to const: pointer can CHANGE, data is FIXED" << endl;
}

//============================================================================
// EXERCISE 5: Reading Pointer Declarations
//============================================================================
void exercise5()
{
    cout << "\n========== EXERCISE 5: Reading Declarations ==========" << endl;

    cout << "Read from RIGHT-TO-LEFT:" << endl;

    cout << "\n1. 'int *ptr'" << endl;
    cout << "   Right->Left: ptr is a pointer to int" << endl;
    cout << "   Both changeable: YES" << endl;

    cout << "\n2. 'int * const ptr'" << endl;
    cout << "   Right->Left: ptr is a CONST pointer to int" << endl;
    cout << "   Pointer changeable: NO, Data changeable: YES" << endl;

    cout << "\n3. 'const int *ptr'" << endl;
    cout << "   Right->Left: ptr is a pointer to CONST int" << endl;
    cout << "   Pointer changeable: YES, Data changeable: NO" << endl;

    cout << "\n4. 'const int * const ptr'" << endl;
    cout << "   Right->Left: ptr is a CONST pointer to CONST int" << endl;
    cout << "   Both changeable: NO" << endl;
}

//============================================================================
// EXERCISE 6: Four Const Cases
//============================================================================
void exercise6()
{
    cout << "\n========== EXERCISE 6: Four Const Cases ==========" << endl;

    int a = 1, b = 2, c = 3, d = 4;

    // Case 1: Regular
    int *p1 = &a;
    p1 = &b;  // OK
    *p1 = 10; // OK
    cout << "Case 1 - int *p1: Can change pointer ✓, Can change data ✓" << endl;

    // Case 2: Const pointer
    int *const p2 = &c;
    // p2 = &d;  // ERROR
    *p2 = 30; // OK
    cout << "Case 2 - int * const p2: Can change pointer ✗, Can change data ✓" << endl;

    // Case 3: Pointer to const
    const int *p3 = &a;
    p3 = &b; // OK
    // *p3 = 100; // ERROR
    cout << "Case 3 - const int *p3: Can change pointer ✓, Can change data ✗" << endl;

    // Case 4: Const pointer to const
    const int *const p4 = &c;
    // p4 = &d;   // ERROR
    // *p4 = 100; // ERROR
    cout << "Case 4 - const int * const p4: Can change pointer ✗, Can change data ✗" << endl;
}

//============================================================================
// EXERCISE 7: Const Methods
//============================================================================
class Book
{
private:
    string title;
    int pages;

public:
    Book(string t, int p) : title(t), pages(p) {}

    // Non-const method (can modify)
    void setPages(int p)
    {
        pages = p;
    }

    // Const method (cannot modify)
    void display() const
    {
        cout << "Title: " << title << ", Pages: " << pages << endl;
    }

    string getTitle() const
    {
        return title;
    }
};

void exercise7()
{
    cout << "\n========== EXERCISE 7: Const Methods ==========" << endl;

    Book book("C++ Guide", 500);

    cout << "Calling const method display():" << endl;
    book.display();

    cout << "\nModifying with non-const method setPages():" << endl;
    book.setPages(600);

    cout << "Displaying again:" << endl;
    book.display();

    cout << "\nConst methods:" << endl;
    cout << "  ✓ Can read member variables" << endl;
    cout << "  ✗ Cannot modify member variables" << endl;
    cout << "  ✓ Safe to call on any object" << endl;
}

//============================================================================
// EXERCISE 8: Const Function Parameters
//============================================================================
void readData(const int *ptr)
{
    cout << "  Reading: " << *ptr << endl;
    // Cannot modify: *ptr = 100;  // ERROR
}

void writeData(int *ptr)
{
    cout << "  Before: " << *ptr << endl;
    *ptr = 555;
    cout << "  After: " << *ptr << endl;
}

void exercise8()
{
    cout << "\n========== EXERCISE 8: Const Function Parameters ==========" << endl;

    int value = 42;

    cout << "Calling readData(const int *ptr):" << endl;
    readData(&value);
    cout << "value unchanged: " << value << endl;

    cout << "\nCalling writeData(int *ptr):" << endl;
    writeData(&value);
    cout << "value possibly changed: " << value << endl;

    cout << "\nUsing const in parameters:" << endl;
    cout << "  • Signals intent (will/won't modify)" << endl;
    cout << "  • Compiler enforces const-ness" << endl;
    cout << "  • Documents code for readers" << endl;
}

//============================================================================
// EXERCISE 9: Const Reference Parameters
//============================================================================
void processValue(const int &val)
{
    cout << "  Value: " << val << endl;
    // Cannot modify: val = 100;  // ERROR
}

void processLargeString(const string &str)
{
    cout << "  Processing: \"" << str << "\"" << endl;
    cout << "  Length: " << str.length() << endl;
}

void exercise9()
{
    cout << "\n========== EXERCISE 9: Const Reference Parameters ==========" << endl;

    int num = 99;
    cout << "Calling processValue with const reference:" << endl;
    processValue(num);

    string text = "Hello World";
    cout << "\nCalling processLargeString with const reference:" << endl;
    processLargeString(text);

    cout << "\nAdvantages of const references:" << endl;
    cout << "  ✓ No copy is made (efficient)" << endl;
    cout << "  ✓ Function cannot modify original" << endl;
    cout << "  ✓ Cleaner syntax than const pointers" << endl;
}

//============================================================================
// EXERCISE 10: Fixed Pointer Iteration
//============================================================================
void exercise10()
{
    cout << "\n========== EXERCISE 10: Fixed Pointer Iteration ==========" << endl;

    string texts[] = {"one", "two", "three", "four", "five"};
    int size = 5;

    // Using const pointer (end is fixed)
    string *const pEnd = &texts[size];
    string *pCurrent = &texts[0];

    cout << "Iterating with const pointer (fixed end):" << endl;
    while (pCurrent != pEnd)
    {
        cout << "  " << *pCurrent << endl;
        pCurrent++;
    }

    cout << "\nUsing const pointer for bounds:" << endl;
    cout << "  pEnd points to past-the-last element (fixed)" << endl;
    cout << "  pCurrent can be incremented" << endl;
    cout << "  Loop continues while pCurrent != pEnd" << endl;
}

//============================================================================
// EXERCISE 11: Const Collections
//============================================================================
void exercise11()
{
    cout << "\n========== EXERCISE 11: Const Collections ==========" << endl;

    const int arr[] = {10, 20, 30, 40, 50};
    int size = 5;

    cout << "const int arr[] = {10, 20, 30, 40, 50};" << endl;
    cout << "Contents: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Cannot modify:
    // arr[0] = 100;  // ERROR - array is const!

    cout << "\nCannot modify const array elements" << endl;
    cout << "\nIterating with const pointer:" << endl;
    const int *const pEnd = &arr[size];
    const int *pCurrent = &arr[0];

    while (pCurrent != pEnd)
    {
        cout << "  " << *pCurrent << endl;
        pCurrent++;
    }
}

//============================================================================
// EXERCISE 12: Pointer-to-Const vs Const-Pointer
//============================================================================
void exercise12()
{
    cout << "\n========== EXERCISE 12: Comparing Const Cases ==========" << endl;

    int x = 100;
    int y = 200;

    cout << "Scenario: Two variables" << endl;
    cout << "  int x = " << x << ";" << endl;
    cout << "  int y = " << y << ";" << endl;

    cout << "\nUsing pointer-to-const:" << endl;
    {
        const int *ptr = &x;
        cout << "  const int *ptr = &x;" << endl;
        cout << "  *ptr = " << *ptr << endl;
        ptr = &y;
        cout << "  ptr = &y;  (allowed)" << endl;
        cout << "  *ptr = " << *ptr << endl;
    }

    cout << "\nUsing const-pointer:" << endl;
    {
        int *const ptr = &x;
        cout << "  int * const ptr = &x;" << endl;
        cout << "  *ptr = " << *ptr << endl;
        *ptr = 150;
        cout << "  *ptr = 150;  (allowed)" << endl;
        cout << "  x = " << x << endl;
        // ptr = &y;  would be ERROR
    }

    cout << "\nKey Difference:" << endl;
    cout << "  pointer-to-const: Controls access to DATA" << endl;
    cout << "  const-pointer: Controls access to ADDRESS" << endl;
}

//============================================================================
// EXERCISE 13: Const Correctness
//============================================================================
void exercise13()
{
    cout << "\n========== EXERCISE 13: Const Correctness ==========" << endl;

    cout << "Best Practice: Use const everywhere possible" << endl;
    cout << "\nGood const correctness:" << endl;

    const double PI = 3.14159;
    cout << "  const double PI = " << PI << ";" << endl;

    const int MAX = 100;
    cout << "  const int MAX = " << MAX << ";" << endl;

    cout << "\nConst function parameter:" << endl;
    cout << "  void display(const string &msg) {" << endl;
    cout << "      cout << msg << endl;" << endl;
    cout << "  }" << endl;

    cout << "\nConst method:" << endl;
    cout << "  int getValue() const { return value; }" << endl;

    cout << "\nBenefits:" << endl;
    cout << "  ✓ Self-documenting code" << endl;
    cout << "  ✓ Compiler catches mistakes" << endl;
    cout << "  ✓ Prevents accidental modifications" << endl;
    cout << "  ✓ Enables compiler optimizations" << endl;
}

//============================================================================
// MAIN FUNCTION - Run All Exercises
//============================================================================
int main()
{
    cout << "============================================" << endl;
    cout << "C++ CONST KEYWORD - PRACTICE EXERCISES" << endl;
    cout << "============================================" << endl;

    exercise1();
    // Uncomment the exercises below as you solve them:
    // exercise2();
    // exercise3();
    // exercise4();
    // exercise5();
    // exercise6();
    // exercise7();
    // exercise8();
    // exercise9();
    // exercise10();
    // exercise11();
    // exercise12();
    // exercise13();

    cout << "\n============================================" << endl;
    cout << "Great job practicing const keyword!" << endl;
    cout << "============================================" << endl;

    return 0;
}

//============================================================================
// SOLUTIONS REFERENCE
//============================================================================
/*
 * EXERCISE 3 SOLUTION - Const Pointer:
 * int * const ptr = &x;
 * *ptr = 100;  // OK - changing data
 * ptr = &y;    // ERROR - cannot change pointer
 *
 * EXERCISE 4 SOLUTION - Pointer to Const:
 * const int *ptr = &x;
 * *ptr = 100;  // ERROR - cannot change data
 * ptr = &y;    // OK - can change pointer
 *
 * EXERCISE 6 SOLUTION - Four Cases:
 * int *p1 = &a;              // Can change both
 * int * const p2 = &c;       // Can change data only
 * const int *p3 = &a;        // Can change pointer only
 * const int * const p4 = &c; // Cannot change either
 *
 * EXERCISE 7 SOLUTION - Const Methods:
 * void display() const {
 *     cout << title << ", " << pages << endl;
 *     // Cannot modify: pages = 0;  // ERROR
 * }
 *
 * EXERCISE 10 SOLUTION - Fixed Pointer Iteration:
 * string * const pEnd = &texts[size];
 * string *pCurrent = &texts[0];
 * while (pCurrent != pEnd) {
 *     cout << *pCurrent << endl;
 *     pCurrent++;
 * }
 */
