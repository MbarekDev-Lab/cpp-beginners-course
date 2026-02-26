//============================================================================
// References Exercises - Practice Problems
// Master references and when to use them!
//============================================================================

#include <iostream>
#include <cstring>
using namespace std;

//============================================================================
// EXERCISE 1: Create and Use Basic References
//============================================================================
void exercise1()
{
    cout << "\n========== EXERCISE 1: Basic Reference ==========" << endl;

    int value1 = 8;
    cout << "Original: value1 = " << value1 << endl;

    // TODO: Create a reference to value1
    int &value2 = value1;

    cout << "Created reference: int &value2 = value1;" << endl;
    cout << "value2 = " << value2 << endl;
    cout << "Address of value1: " << &value1 << endl;
    cout << "Address of value2: " << &value2 << endl;
    cout << "(Both addresses are the same!)" << endl;
}

//============================================================================
// EXERCISE 2: Modify Through Reference
//============================================================================
void exercise2()
{
    cout << "\n========== EXERCISE 2: Modifying Through Reference ==========" << endl;

    int value1 = 8;
    int &value2 = value1;

    cout << "Before: value1 = " << value1 << ", value2 = " << value2 << endl;

    // TODO: Modify value2
    value2 = 10;

    cout << "After value2 = 10:" << endl;
    cout << "value1 = " << value1 << " (also changed!)" << endl;
    cout << "value2 = " << value2 << endl;
}

//============================================================================
// EXERCISE 3: Reference vs Pointer
//============================================================================
void exercise3()
{
    cout << "\n========== EXERCISE 3: Reference vs Pointer ==========" << endl;

    int value = 42;

    // Reference
    int &ref = value;

    // Pointer
    int *ptr = &value;

    cout << "Using REFERENCE:" << endl;
    cout << "  int &ref = value;" << endl;
    cout << "  Access: ref = " << ref << endl;

    cout << "\nUsing POINTER:" << endl;
    cout << "  int *ptr = &value;" << endl;
    cout << "  Access: *ptr = " << *ptr << endl;

    cout << "\nBoth modify the original:" << endl;
    ref = 100;
    cout << "  After ref = 100: value = " << value << endl;

    *ptr = 200;
    cout << "  After *ptr = 200: value = " << value << endl;
}

//============================================================================
// EXERCISE 4: Function Parameter - Modify Original
//============================================================================
void modifyValue(int &val)
{
    cout << "  Inside function: val = " << val << endl;
    val = 999;
    cout << "  After modification: val = " << val << endl;
}

void exercise4()
{
    cout << "\n========== EXERCISE 4: Reference Parameters ==========" << endl;

    int x = 50;
    cout << "Before function call: x = " << x << endl;

    cout << "Calling modifyValue(x):" << endl;
    modifyValue(x);

    cout << "After function call: x = " << x << " (modified!)" << endl;
}

//============================================================================
// EXERCISE 5: Const References - Read Only
//============================================================================
void printValue(const double &val)
{
    cout << "  Value: " << val << endl;
}

void exercise5()
{
    cout << "\n========== EXERCISE 5: Const References ==========" << endl;

    double value = 3.14159;
    cout << "Original double value: " << value << endl;

    cout << "Passing const reference to function:" << endl;
    printValue(value);

    cout << "\nWith const reference:" << endl;
    cout << "  ✓ No copy made (efficient)" << endl;
    cout << "  ✓ Function cannot modify value" << endl;
}

//============================================================================
// EXERCISE 6: Swapping Values
//============================================================================
void swap(int &a, int &b)
{
    cout << "  Before swap in function: a = " << a << ", b = " << b << endl;

    // TODO: Implement swap
    int temp = a;
    a = b;
    b = temp;

    cout << "  After swap in function: a = " << a << ", b = " << b << endl;
}

void exercise6()
{
    cout << "\n========== EXERCISE 6: Swapping Through References ==========" << endl;

    int x = 10, y = 20;
    cout << "Before swap: x = " << x << ", y = " << y << endl;

    swap(x, y);

    cout << "After swap: x = " << x << ", y = " << y << endl;
}

//============================================================================
// EXERCISE 7: Reference Cannot Be Reassigned
//============================================================================
void exercise7()
{
    cout << "\n========== EXERCISE 7: Reference Binding ==========" << endl;

    int x = 10;
    int y = 20;
    int z = 30;

    int &ref = x; // ref refers to x
    cout << "int &ref = x;  (ref now refers to x)" << endl;
    cout << "ref = " << ref << ", x = " << x << endl;

    // IMPORTANT: This does NOT make ref refer to y!
    ref = y; // This copies y's value to x!

    cout << "\nref = y;  (This copies y's value to x!)" << endl;
    cout << "x = " << x << " (now 20, not 10!)" << endl;
    cout << "y = " << y << endl;
    cout << "ref = " << ref << " (still refers to x)" << endl;

    cout << "\nKey Point: References cannot change what they refer to!" << endl;
}

//============================================================================
// EXERCISE 8: Multiple References to Same Variable
//============================================================================
void exercise8()
{
    cout << "\n========== EXERCISE 8: Multiple References ==========" << endl;

    int value = 100;
    int &ref1 = value;
    int &ref2 = value;
    int &ref3 = value;

    cout << "Created three references to same variable" << endl;
    cout << "value = " << value << endl;
    cout << "ref1 = " << ref1 << endl;
    cout << "ref2 = " << ref2 << endl;
    cout << "ref3 = " << ref3 << endl;

    cout << "\nModifying through ref2:" << endl;
    ref2 = 250;

    cout << "value = " << value << " (changed!)" << endl;
    cout << "ref1 = " << ref1 << endl;
    cout << "ref2 = " << ref2 << endl;
    cout << "ref3 = " << ref3 << endl;
}

//============================================================================
// EXERCISE 9: Reference in Loop
//============================================================================
void exercise9()
{
    cout << "\n========== EXERCISE 9: Range-Based Loop with References ==========" << endl;

    int arr[] = {1, 2, 3, 4, 5};

    cout << "Original array: ";
    for (int x : arr)
        cout << x << " ";
    cout << endl;

    cout << "\nDoubling each element using reference:" << endl;
    for (int &x : arr)
    { // Reference allows modification!
        x = x * 2;
    }

    cout << "Modified array: ";
    for (int x : arr)
        cout << x << " ";
    cout << endl;
}

//============================================================================
// EXERCISE 10: Const vs Non-Const Parameters
//============================================================================
void processRead(const int &val)
{
    cout << "  Can read: val = " << val << endl;
    // cout << val = 10;  // ERROR - cannot modify!
}

void processWrite(int &val)
{
    cout << "  Before: val = " << val << endl;
    val = 500;
    cout << "  After: val = " << val << endl;
}

void exercise10()
{
    cout << "\n========== EXERCISE 10: Const vs Non-Const ==========" << endl;

    int x = 100;

    cout << "Calling processRead (const reference):" << endl;
    processRead(x);
    cout << "x = " << x << " (unchanged)" << endl;

    cout << "\nCalling processWrite (non-const reference):" << endl;
    processWrite(x);
    cout << "x = " << x << " (changed!)" << endl;
}

//============================================================================
// EXERCISE 11: Reference to Different Types
//============================================================================
void exercise11()
{
    cout << "\n========== EXERCISE 11: References to Different Types ==========" << endl;

    // Int reference
    int num = 42;
    int &refInt = num;
    cout << "int &refInt = " << refInt << endl;

    // Double reference
    double pi = 3.14159;
    double &refDouble = pi;
    cout << "double &refDouble = " << refDouble << endl;

    // String reference
    string text = "Hello";
    string &refString = text;
    cout << "string &refString = \"" << refString << "\"" << endl;

    // Modify through references
    refInt = 100;
    refDouble = 2.71828;
    refString = "World";

    cout << "\nAfter modification:" << endl;
    cout << "num = " << num << endl;
    cout << "pi = " << pi << endl;
    cout << "text = \"" << text << "\"" << endl;
}

//============================================================================
// EXERCISE 12: Passing Array by Reference
//============================================================================
void doubleArray(int arr[], int size)
{
    cout << "Doubling array elements:" << endl;
    for (int i = 0; i < size; i++)
    {
        arr[i] = arr[i] * 2; // Modifies original array
    }
}

void exercise12()
{
    cout << "\n========== EXERCISE 12: Array Parameters ==========" << endl;

    int arr[] = {10, 20, 30, 40, 50};
    int size = 5;

    cout << "Original array: ";
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;

    doubleArray(arr, size);

    cout << "After function: ";
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;

    cout << "\nNote: Arrays are passed by reference by default!" << endl;
}

//============================================================================
// EXERCISE 13: Efficiency Comparison
//============================================================================
void processByValue(string str)
{
    cout << "  By value: \"" << str << "\"" << endl;
}

void processByReference(const string &str)
{
    cout << "  By reference: \"" << str << "\"" << endl;
}

void exercise13()
{
    cout << "\n========== EXERCISE 13: Pass by Value vs Reference ==========" << endl;

    string longText = "This is a long string that might be expensive to copy";

    cout << "String: \"" << longText << "\"" << endl;

    cout << "\nPass by value (makes a copy):" << endl;
    processByValue(longText);
    cout << "- Slower for large objects" << endl;
    cout << "- Original is safe from modification" << endl;

    cout << "\nPass by const reference (no copy):" << endl;
    processByReference(longText);
    cout << "- Faster - no copy made" << endl;
    cout << "- Function cannot accidentally modify" << endl;
    cout << "- Preferred for reading large objects" << endl;
}

//============================================================================
// MAIN FUNCTION - Run All Exercises
//============================================================================
int main()
{
    cout << "============================================" << endl;
    cout << "C++ REFERENCES - PRACTICE EXERCISES" << endl;
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
    cout << "Great job practicing references!" << endl;
    cout << "============================================" << endl;

    return 0;
}

//============================================================================
// SOLUTIONS REFERENCE
//============================================================================
/*
 * EXERCISE 1 SOLUTION:
 * int &value2 = value1;
 *
 * EXERCISE 2 SOLUTION:
 * value2 = 10;  // Changes both value1 and value2
 *
 * EXERCISE 4 SOLUTION:
 * void modifyValue(int &val) {
 *     val = 999;
 * }
 *
 * EXERCISE 6 SOLUTION:
 * int temp = a;
 * a = b;
 * b = temp;
 *
 * EXERCISE 7 SOLUTION:
 * Shows that ref = y; copies y's value to x, not rebinding
 *
 * EXERCISE 9 SOLUTION:
 * for (int &x : arr) {
 *     x = x * 2;
 * }
 *
 * EXERCISE 12 SOLUTION:
 * Arrays decay to pointers, modifications affect original
 * for (int i = 0; i < size; i++) {
 *     arr[i] = arr[i] * 2;
 * }
 */
