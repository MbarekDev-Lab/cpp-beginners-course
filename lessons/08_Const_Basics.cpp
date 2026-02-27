//============================================================================
// Lesson: Const Keyword in C++
// Author: M'Barek Benraiss
// Date: February 26, 2026
// Topic: Understanding const - Making Variables and Pointers Immutable
//============================================================================
/*
 * CONST KEYWORD
 * =============
 * const is used to declare variables, pointers, and methods as immutable
 * (cannot be changed after initialization).
 *
 * THREE MAIN USES:
 * ================
 * 1. const variables - Cannot modify the variable
 * 2. const pointers - Pointer cannot change (address remains fixed)
 * 3. pointers to const - Data being pointed to cannot be modified
 * 4. const methods - Method cannot modify object's state
 *
 * SYNTAX:
 * =======
 * const double PI = 3.14159;           // const variable
 * int * const ptr = &value;            // const pointer
 * const int *ptr = &value;             // pointer to const
 * void method() const { ... }          // const method
 *
 * KEY PRINCIPLE:
 * ==============
 * "const" applies to whatever is on its left.
 * If nothing on left, it applies to the right.
 * Read pointer declarations right-to-left!
 */

#include <iostream>
using namespace std;

//============================================================================
// Section 1: Const Variables
//============================================================================
int section1()
{
    cout << "\n========== SECTION 1: Const Variables ==========" << endl;
    cout << "Variables that cannot be changed after initialization" << endl;

    const double PI = 3.141592653589793;

    cout << "const double PI = " << PI << ";" << endl;
    cout << "PI value: " << PI << endl;

    // Cannot modify:
    // PI = 3.14;  // ERROR - const variable!

    cout << "\nAdvantages of const variables:" << endl;
    cout << "  ✓ Prevents accidental modification" << endl;
    cout << "  ✓ Documents intent (this value doesn't change)" << endl;
    cout << "  ✓ Compiler can optimize" << endl;
    cout << "  ✓ Used for constants and magic numbers" << endl;

    return 0;
}

//============================================================================
// Section 2: Const Pointers vs Pointers to Const
//============================================================================
int section2()
{
    cout << "\n========== SECTION 2: Const Pointers vs Pointers to Const ==========" << endl;

    int value = 8;
    int number = 11;

    cout << "CASE 1: Const Pointer (int * const)" << endl;
    cout << "Pointer CANNOT CHANGE, but data CAN change" << endl;

    int *const pValue = &value;
    cout << "int * const pValue = &value;" << endl;
    cout << "*pValue = " << *pValue << endl;

    // CAN modify data:
    *pValue = 100;
    cout << "After *pValue = 100: " << *pValue << endl;

    // CANNOT change pointer:
    // pValue = &number;  // ERROR - const pointer cannot change!

    cout << "\nCASE 2: Pointer to Const (const int *)" << endl;
    cout << "Pointer CAN CHANGE, but data CANNOT change" << endl;

    const int *pNumber = &value;
    cout << "const int *pNumber = &value;" << endl;
    cout << "*pNumber = " << *pNumber << endl;

    // CAN change pointer:
    pNumber = &number;
    cout << "After pNumber = &number: " << *pNumber << endl;

    // CANNOT modify data:
    // *pNumber = 200;  // ERROR - data is const!

    cout << "\nCASE 3: Const Pointer to Const (const int * const)" << endl;
    cout << "NEITHER pointer NOR data can change" << endl;

    const int *const pBoth = &value;
    cout << "const int * const pBoth = &value;" << endl;
    cout << "*pBoth = " << *pBoth << endl;

    // CANNOT change pointer:
    // pBoth = &number;  // ERROR!

    // CANNOT modify data:
    // *pBoth = 300;  // ERROR!

    return 0;
}

//============================================================================
// Section 3: Reading Pointer Declarations
//============================================================================
int section3()
{
    cout << "\n========== SECTION 3: Reading Pointer Declarations ==========" << endl;
    cout << "Read pointer declarations RIGHT-TO-LEFT!" << endl;

    cout << "\n1. 'int *ptr':" << endl;
    cout << "   Right-to-left: ptr is a pointer to int" << endl;
    cout << "   Can change pointer ✓, Can change data ✓" << endl;

    cout << "\n2. 'int * const ptr':" << endl;
    cout << "   Right-to-left: ptr is a const pointer to int" << endl;
    cout << "   Can change pointer ✗, Can change data ✓" << endl;

    cout << "\n3. 'const int *ptr':" << endl;
    cout << "   Right-to-left: ptr is a pointer to const int" << endl;
    cout << "   Can change pointer ✓, Can change data ✗" << endl;

    cout << "\n4. 'const int * const ptr':" << endl;
    cout << "   Right-to-left: ptr is a const pointer to const int" << endl;
    cout << "   Can change pointer ✗, Can change data ✗" << endl;

    cout << "\nMnemonic: Read from right to left, 'const' applies to left word" << endl;

    return 0;
}

//============================================================================
// Section 4: Const Methods
//============================================================================
class Animal
{
private:
    string name;

public:
    // Non-const method (can modify state)
    void setName(string name)
    {
        this->name = name;
    }

    // Const method (cannot modify state)
    void speak() const
    {
        cout << "My name is: " << name << endl;
    }

    string getName() const
    {
        return name;
    }
};

int section4()
{
    cout << "\n========== SECTION 4: Const Methods ==========" << endl;
    cout << "Methods marked const cannot modify object state" << endl;

    Animal animal;
    animal.setName("Freddy");

    cout << "Animal created and named 'Freddy'" << endl;
    cout << "Calling const method speak():" << endl;
    animal.speak();

    cout << "\nConst method 'speak()':" << endl;
    cout << "  ✓ Can read member variables" << endl;
    cout << "  ✗ Cannot modify member variables" << endl;
    cout << "  ✓ Signals to users: this doesn't change state" << endl;
    cout << "  ✓ Can be called on const objects" << endl;

    cout << "\nWhy use const methods?" << endl;
    cout << "  - Documents intent (read-only)" << endl;
    cout << "  - Prevents accidental modifications" << endl;
    cout << "  - Works with const objects" << endl;
    cout << "  - Compiler enforces constraints" << endl;

    return 0;
}

//============================================================================
// Section 5: Practical Const Pointer Usage
//============================================================================
int section5()
{
    cout << "\n========== SECTION 5: Practical Const Pointer Usage ==========" << endl;

    int value = 8;
    int number = 11;

    cout << "Creating pointers for different purposes:" << endl;

    // Regular pointer - most flexible
    int *ptr1 = &value;
    cout << "\nint *ptr1 = &value;" << endl;
    cout << "  Purpose: General use, can change pointer and data" << endl;
    ptr1 = &number;
    *ptr1 = 50;
    cout << "  ✓ Can reassign pointer: ptr1 = &number" << endl;
    cout << "  ✓ Can modify data: *ptr1 = 50" << endl;

    // Pointer to const data
    const int *ptr2 = &value;
    cout << "\nconst int *ptr2 = &value;" << endl;
    cout << "  Purpose: Read-only access to data" << endl;
    ptr2 = &number;
    cout << "  ✓ Can reassign pointer: ptr2 = &number" << endl;
    // *ptr2 = 50;  // ERROR
    cout << "  ✗ Cannot modify data" << endl;

    // Const pointer
    int *const ptr3 = &value;
    cout << "\nint * const ptr3 = &value;" << endl;
    cout << "  Purpose: Fixed address, but modifiable data" << endl;
    *ptr3 = 100;
    cout << "  ✓ Can modify data: *ptr3 = 100" << endl;
    // ptr3 = &number;  // ERROR
    cout << "  ✗ Cannot reassign pointer" << endl;

    return 0;
}

//============================================================================
// Section 6: Const in Function Parameters
//============================================================================
void readValue(const int *ptr)
{
    cout << "  Reading: " << *ptr << endl;
    // Cannot modify: *ptr = 100;  // ERROR
}

void modifyValue(int *ptr)
{
    cout << "  Before: " << *ptr << endl;
    *ptr = 999;
    cout << "  After: " << *ptr << endl;
}

int section6()
{
    cout << "\n========== SECTION 6: Const in Function Parameters ==========" << endl;

    int value = 42;

    cout << "Function: void readValue(const int *ptr)" << endl;
    cout << "  Signals: This function will not modify data" << endl;
    readValue(&value);
    cout << "  value is still: " << value << endl;

    cout << "\nFunction: void modifyValue(int *ptr)" << endl;
    cout << "  Signals: This function may modify data" << endl;
    modifyValue(&value);
    cout << "  value is now: " << value << endl;

    cout << "\nBest Practice:" << endl;
    cout << "  • Use const int *ptr for read-only" << endl;
    cout << "  • Use int *ptr only when you need to modify" << endl;
    cout << "  • This documents intent to callers" << endl;

    return 0;
}

//============================================================================
// Section 7: Const vs #define
//============================================================================
int section7()
{
    cout << "\n========== SECTION 7: Const vs #define ==========" << endl;

    // Using const (preferred)
    const double PI = 3.141592653589793;

    cout << "Using const (PREFERRED):" << endl;
    cout << "  const double PI = " << PI << ";" << endl;
    cout << "  ✓ Has type (double)" << endl;
    cout << "  ✓ Has scope (local or global)" << endl;
    cout << "  ✓ Debuggable" << endl;
    cout << "  ✓ Memory efficient" << endl;
    cout << "  ✓ Can use with pointers" << endl;

    cout << "\nUsing #define (old C style):" << endl;
    cout << "  #define PI 3.141592653589793" << endl;
    cout << "  ✗ No type" << endl;
    cout << "  ✗ No scope" << endl;
    cout << "  ✗ Harder to debug" << endl;
    cout << "  ✓ No memory cost (preprocessor replacement)" << endl;

    cout << "\nModern C++ Recommendation:" << endl;
    cout << "  Use 'const' instead of '#define'" << endl;
    cout << "  Type safety and scoping are important!" << endl;

    return 0;
}

//============================================================================
// Section 8: Summary of Const Usage
//============================================================================
int section8()
{
    cout << "\n========== SECTION 8: Const Usage Summary ==========" << endl;

    cout << "1. CONST VARIABLES:" << endl;
    cout << "   const double PI = 3.14;" << endl;
    cout << "   Use: For values that don't change" << endl;

    cout << "\n2. CONST POINTERS:" << endl;
    cout << "   int * const ptr = &value;" << endl;
    cout << "   Use: Pointer remains fixed, data can change" << endl;
    cout << "   Common in: Array iteration (fixed bounds)" << endl;

    cout << "\n3. POINTERS TO CONST:" << endl;
    cout << "   const int *ptr = &value;" << endl;
    cout << "   Use: Pointer can change, data is read-only" << endl;
    cout << "   Common in: Function parameters (no modification)" << endl;

    cout << "\n4. CONST METHODS:" << endl;
    cout << "   void display() const { ... }" << endl;
    cout << "   Use: Method doesn't modify object" << endl;
    cout << "   Common in: Getters, display functions" << endl;

    cout << "\n5. READING DECLARATIONS:" << endl;
    cout << "   Always read right-to-left:" << endl;
    cout << "   int * const => const pointer to int" << endl;
    cout << "   const int * => pointer to const int" << endl;

    cout << "\nBenefits of const:" << endl;
    cout << "  • Self-documenting code (intent)" << endl;
    cout << "  • Compiler catches mistakes" << endl;
    cout << "  • Enables optimizations" << endl;
    cout << "  • Safer, more maintainable code" << endl;

    return 0;
}

//============================================================================
// MAIN FUNCTION
//============================================================================
int main()
{
    cout << "============================================" << endl;
    cout << "C++ CONST KEYWORD - COMPLETE GUIDE" << endl;
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
    cout << "Const Keyword Mastered!" << endl;
    cout << "============================================" << endl;

    return 0;
}

//============================================================================
// KEY LEARNING POINTS:
// ====================
// 1. const variable = immutable value
// 2. const pointer (int * const) = fixed address, changeable data
// 3. pointer to const (const int *) = changeable pointer, fixed data
// 4. const method = doesn't modify object state
// 5. Read pointer declarations RIGHT-TO-LEFT
// 6. const applies to what's on its left (or right if nothing on left)
// 7. Use const to document and enforce intent
// 8. Compiler enforces const rules
//
// CONST MEANINGS:
// ===============
// const double PI = 3.14;          → Can't change PI
// int * const ptr = &x;             → Can't change ptr (but can change *ptr)
// const int *ptr = &x;              → Can't change *ptr (but can change ptr)
// const int * const ptr = &x;       → Can't change either
// void method() const { ... }        → Method can't modify member variables
//
// WHEN TO USE CONST:
// ==================
// • Declare all variables that won't change as const
// • Use const pointers for fixed bounds
// • Use pointer-to-const for read-only data
// • Mark methods const if they don't modify state
// • Use const references in parameters for efficiency
//============================================================================

/*

/Users/benraiss/CLionProjects/learnCpp/cmake-build-debug/learnCpp

============================================
C++ CONST KEYWORD - COMPLETE GUIDE
============================================

========== SECTION 1: Const Variables ==========
Variables that cannot be changed after initialization
const double PI = 3.14159;
PI value: 3.14159

Advantages of const variables:
  ✓ Prevents accidental modification
  ✓ Documents intent (this value doesn't change)
  ✓ Compiler can optimize
  ✓ Used for constants and magic numbers

========== SECTION 2: Const Pointers vs Pointers to Const ==========
CASE 1: Const Pointer (int * const)
Pointer CANNOT CHANGE, but data CAN change
int * const pValue = &value;
*pValue = 8
After *pValue = 100: 100

CASE 2: Pointer to Const (const int *)
Pointer CAN CHANGE, but data CANNOT change
const int *pNumber = &value;
*pNumber = 100
After pNumber = &number: 11

CASE 3: Const Pointer to Const (const int * const)
NEITHER pointer NOR data can change
const int * const pBoth = &value;
*pBoth = 100

========== SECTION 3: Reading Pointer Declarations ==========
Read pointer declarations RIGHT-TO-LEFT!

1. 'int *ptr':
   Right-to-left: ptr is a pointer to int
   Can change pointer ✓, Can change data ✓

2. 'int * const ptr':
   Right-to-left: ptr is a const pointer to int
   Can change pointer ✗, Can change data ✓

3. 'const int *ptr':
   Right-to-left: ptr is a pointer to const int
   Can change pointer ✓, Can change data ✗

4. 'const int * const ptr':
   Right-to-left: ptr is a const pointer to const int
   Can change pointer ✗, Can change data ✗

Mnemonic: Read from right to left, 'const' applies to left word

========== SECTION 4: Const Methods ==========
Methods marked const cannot modify object state
Animal created and named 'Freddy'
Calling const method speak():
My name is: Freddy

Const method 'speak()':
  ✓ Can read member variables
  ✗ Cannot modify member variables
  ✓ Signals to users: this doesn't change state
  ✓ Can be called on const objects

Why use const methods?
  - Documents intent (read-only)
  - Prevents accidental modifications
  - Works with const objects
  - Compiler enforces constraints

========== SECTION 5: Practical Const Pointer Usage ==========
Creating pointers for different purposes:

int *ptr1 = &value;
  Purpose: General use, can change pointer and data
  ✓ Can reassign pointer: ptr1 = &number
  ✓ Can modify data: *ptr1 = 50

const int *ptr2 = &value;
  Purpose: Read-only access to data
  ✓ Can reassign pointer: ptr2 = &number
  ✗ Cannot modify data

int * const ptr3 = &value;
  Purpose: Fixed address, but modifiable data
  ✓ Can modify data: *ptr3 = 100
  ✗ Cannot reassign pointer

========== SECTION 6: Const in Function Parameters ==========
Function: void readValue(const int *ptr)
  Signals: This function will not modify data
  Reading: 42
  value is still: 42

Function: void modifyValue(int *ptr)
  Signals: This function may modify data
  Before: 42
  After: 999
  value is now: 999

Best Practice:
  • Use const int *ptr for read-only
  • Use int *ptr only when you need to modify
  • This documents intent to callers

========== SECTION 7: Const vs #define ==========
Using const (PREFERRED):
  const double PI = 3.14159;
  ✓ Has type (double)
  ✓ Has scope (local or global)
  ✓ Debuggable
  ✓ Memory efficient
  ✓ Can use with pointers

Using #define (old C style):
  #define PI 3.141592653589793
  ✗ No type
  ✗ No scope
  ✗ Harder to debug
  ✓ No memory cost (preprocessor replacement)

Modern C++ Recommendation:
  Use 'const' instead of '#define'
  Type safety and scoping are important!

========== SECTION 8: Const Usage Summary ==========
1. CONST VARIABLES:
   const double PI = 3.14;
   Use: For values that don't change

2. CONST POINTERS:
   int * const ptr = &value;
   Use: Pointer remains fixed, data can change
   Common in: Array iteration (fixed bounds)

3. POINTERS TO CONST:
   const int *ptr = &value;
   Use: Pointer can change, data is read-only
   Common in: Function parameters (no modification)

4. CONST METHODS:
   void display() const { ... }
   Use: Method doesn't modify object
   Common in: Getters, display functions

5. READING DECLARATIONS:
   Always read right-to-left:
   int * const => const pointer to int
   const int * => pointer to const int

Benefits of const:
  • Self-documenting code (intent)
  • Compiler catches mistakes
  • Enables optimizations
  • Safer, more maintainable code

============================================
Const Keyword Mastered!
============================================


*/
