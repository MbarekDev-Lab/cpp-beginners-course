//============================================================================
// Lesson: References in C++
// Author: M'Barek Benraiss
// Date: February 26, 2026
// Topic: Understanding References - Aliases for Variables
//============================================================================
/*
 * REFERENCES IN C++
 * =================
 * A reference is an alias (another name) for an existing variable.
 *
 * KEY POINTS:
 * ===========
 * - Reference is NOT a copy - it aliases the original variable
 * - Changes through reference affect the original
 * - Must be initialized when declared
 * - Cannot be changed to refer to something else
 * - No null references (unlike pointers)
 *
 * SYNTAX:
 * =======
 * DataType &refName = originalVariable;
 *
 * DIFFERENCE FROM POINTERS:
 * =========================
 * Pointers:        Variables that STORE addresses
 * References:      ALIASES for existing variables
 *
 * WHY USE REFERENCES?
 * ====================
 * - Pass variables to functions efficiently
 * - Avoid copies of large objects
 * - Modify original variable in function
 * - Cleaner syntax than pointers
 */

#include <iostream>
using namespace std;

//============================================================================
// Section 1: Reference Basics - Creating an Alias
//============================================================================
int section1()
{
    cout << "\n========== SECTION 1: Reference Basics ==========" << endl;
    cout << "Creating an alias for a variable" << endl;

    int value1 = 8;
    cout << "\nOriginal variable: value1 = " << value1 << endl;

    // Create a reference to value1
    // Think: "value2 is another name for value1"
    int &value2 = value1;

    cout << "Created reference: int &value2 = value1;" << endl;
    cout << "\nNow value2 refers to the same memory as value1:" << endl;
    cout << "  value1 = " << value1 << endl;
    cout << "  value2 = " << value2 << endl;
    cout << "  &value1 = " << &value1 << endl;
    cout << "  &value2 = " << &value2 << endl;
    cout << "  (^ Same address!)" << endl;

    return 0;
}

//============================================================================
// Section 2: Modifying Through Reference
//============================================================================
int section2()
{
    cout << "\n========== SECTION 2: Modifying Through Reference ==========" << endl;
    cout << "Changes through reference affect the original" << endl;

    int value1 = 8;
    int &value2 = value1;

    cout << "\nInitial: value1 = " << value1 << ", value2 = " << value2 << endl;

    // Modify through reference
    value2 = 10;

    cout << "After value2 = 10:" << endl;
    cout << "  value1 = " << value1 << " (changed!)" << endl;
    cout << "  value2 = " << value2 << endl;

    cout << "\nThe reference is just another name for same variable" << endl;
    cout << "They point to the SAME MEMORY LOCATION" << endl;

    return 0;
}

//============================================================================
// Section 3: References vs Pointers
//============================================================================
int section3()
{
    cout << "\n========== SECTION 3: References vs Pointers ==========" << endl;

    int value = 42;

    // Reference
    int &ref = value;

    // Pointer
    int *ptr = &value;

    cout << "Original value: " << value << endl;
    cout << "\nREFERENCE:" << endl;
    cout << "  Syntax: int &ref = value;" << endl;
    cout << "  Access: ref = " << ref << endl;
    cout << "  No dereferencing needed!" << endl;

    cout << "\nPOINTER:" << endl;
    cout << "  Syntax: int *ptr = &value;" << endl;
    cout << "  Access: *ptr = " << *ptr << " (need deref operator)" << endl;
    cout << "  Address: ptr = " << ptr << endl;

    cout << "\nKEY DIFFERENCES:" << endl;
    cout << "  Reference          | Pointer" << endl;
    cout << "  ================== | ==================" << endl;
    cout << "  Must initialize    | Can be null" << endl;
    cout << "  Cannot reassign    | Can point elsewhere" << endl;
    cout << "  Automatic deref    | Needs dereferencing (*)" << endl;
    cout << "  Safer, cleaner     | More flexible" << endl;

    return 0;
}

//============================================================================
// Section 4: Passing References to Functions
//============================================================================
void modifyByReference(int &value)
{
    cout << "    Inside function: value = " << value << endl;
    value = 100;
    cout << "    After modification: value = " << value << endl;
}

int section4()
{
    cout << "\n========== SECTION 4: Passing References to Functions ==========" << endl;
    cout << "Functions can modify original variable through reference" << endl;

    int x = 5;
    cout << "\nBefore function call: x = " << x << endl;

    cout << "Calling modifyByReference(x):" << endl;
    modifyByReference(x);

    cout << "After function call: x = " << x << " (modified!)" << endl;
    cout << "\nThe function parameter is a reference, so it modifies original" << endl;

    return 0;
}

//============================================================================
// Section 5: Const References
//============================================================================
void printDouble(const double &val)
{
    cout << "  Value: " << val << endl;
}

int section5()
{
    cout << "\n========== SECTION 5: Const References ==========" << endl;
    cout << "Use const references to read without modification" << endl;

    double value3 = 3.14159;

    cout << "double value3 = " << value3 << endl;
    cout << "Passing const reference to function:" << endl;

    printDouble(value3);

    cout << "\nWith const reference:" << endl;
    cout << "  ✓ No copy is made (efficient)" << endl;
    cout << "  ✓ Function cannot modify value" << endl;
    cout << "  ✓ Perfect for reading large objects" << endl;

    return 0;
}

//============================================================================
// Section 6: Reference Cannot Be Reassigned
//============================================================================
int section6()
{
    cout << "\n========== SECTION 6: Reference Cannot Be Reassigned ==========" << endl;
    cout << "Once a reference is bound, it cannot be changed" << endl;

    int x = 10;
    int y = 20;
    int z = 30;

    int &ref = x; // ref refers to x
    cout << "int &ref = x;  (ref now refers to x)" << endl;
    cout << "ref = " << ref << endl;

    // This REASSIGNS ref to y, NOT to refer to y
    ref = y; // This sets x = y, not ref to y!

    cout << "\nref = y;  (This copies y's value to x, NOT rebinding!)" << endl;
    cout << "x = " << x << " (now 20, not 10!)" << endl;
    cout << "y = " << y << endl;
    cout << "ref still refers to x: " << ref << endl;

    cout << "\nKey Point: References cannot be reassigned to different variables" << endl;

    return 0;
}

//============================================================================
// Section 7: Practical Example - Swapping Values
//============================================================================
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int section7()
{
    cout << "\n========== SECTION 7: Practical Example - Swapping ==========" << endl;
    cout << "Using references to swap two variables" << endl;

    int num1 = 100;
    int num2 = 200;

    cout << "Before swap: num1 = " << num1 << ", num2 = " << num2 << endl;

    swap(num1, num2);

    cout << "After swap: num1 = " << num1 << ", num2 = " << num2 << endl;

    cout << "\nFunction signature: void swap(int &a, int &b)" << endl;
    cout << "References allow modification of original arguments" << endl;

    return 0;
}

//============================================================================
// Section 8: References in Data Structures
//============================================================================
int section8()
{
    cout << "\n========== SECTION 8: When to Use References ==========" << endl;

    cout << "\n1. Returning References (CARE REQUIRED!):" << endl;
    cout << "   int &getRef() { return x; }  // Returns reference to x" << endl;
    cout << "   WARNING: Don't return reference to local variable!" << endl;

    cout << "\n2. Modifying Function Parameters:" << endl;
    cout << "   void update(int &value) { value = 10; }" << endl;
    cout << "   - Cleaner than void update(int *value)" << endl;
    cout << "   - No need for dereferencing" << endl;

    cout << "\n3. Default Parameters:" << endl;
    cout << "   void process(const int &x = 0)" << endl;
    cout << "   - Efficient for large objects" << endl;
    cout << "   - Prevents unnecessary copies" << endl;

    cout << "\n4. Range-Based For Loops:" << endl;
    cout << "   for (int &x : array) { x = x * 2; }" << endl;
    cout << "   - Modifies original array elements" << endl;

    return 0;
}

//============================================================================
// MAIN FUNCTION
//============================================================================
int main()
{
    cout << "============================================" << endl;
    cout << "C++ REFERENCES - COMPLETE GUIDE" << endl;
    cout << "============================================" << endl;

    section1();
    section2();
    section3();
    section4();
    section5();
    section6();
    section7();
    section8();

    cout << "\n============================================" << endl;
    cout << "References Learned!" << endl;
    cout << "============================================" << endl;

    return 0;
}

//============================================================================
// KEY LEARNING POINTS:
// ====================
// 1. Reference is an ALIAS for an existing variable
// 2. Changes through reference affect the original
// 3. Must be initialized when declared (int &ref = var;)
// 4. Cannot be reassigned to another variable
// 5. No null references (unlike pointers)
// 6. Safer and cleaner than pointers
// 7. Automatic dereferencing (no * operator needed)
// 8. Perfect for function parameters to avoid copies
//
// REFERENCE vs POINTER:
// =====================
// Reference: Alias, must init, no null, automatic deref
// Pointer:   Stores address, can be null, needs deref
//
// WHEN TO USE REFERENCES:
// =======================
// • Function parameters that need modification
// • Const references for read-only efficiency
// • Returning objects from functions
// • Range-based for loops
// • Any time you want pointer semantics but cleaner syntax
//============================================================================
