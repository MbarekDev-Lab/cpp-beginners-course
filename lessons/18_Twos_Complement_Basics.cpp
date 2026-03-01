//============================================================================
// Lesson 18: Two's Complement - Basics
// Author      : M'Barek Benraiss
// Description : Understanding binary representation and two's complement
//               encoding for signed integers in C++
//============================================================================

#include <iostream>
#include <bitset>
#include <climits>
#include <iomanip>
using namespace std;

// ============================================================================
// SECTION 1: Basic Sign and Magnitude vs Two's Complement
// ============================================================================
/*
Modern systems use TWO'S COMPLEMENT to represent negative numbers.
This allows a single representation of zero and simplifies arithmetic.

Sign and Magnitude (older method):
  Positive:  0b01111111 = 127
  Negative:  0b11111111 = -127 (flip sign bit, problem: two zeros)

Two's Complement (modern method):
  Positive:  0b01111111 = 127
  Negative:  0b10000001 = -127 (flip bits AND add 1)
*/

void section1_BasicConcept()
{
    cout << "\n=== SECTION 1: Two's Complement Basics ===" << endl;

    // For a char (8 bits):
    // Range: -128 to 127
    // Positive: 0 to 127
    // Negative: -1 to -128

    cout << "8-bit signed integer range: " << (int)SCHAR_MIN << " to "
         << (int)SCHAR_MAX << endl;

    cout << "\nPositive numbers (MSB = 0):" << endl;
    char positive = 42;
    cout << "Value: " << (int)positive << endl;
    cout << "Binary: " << bitset<8>(positive) << endl;

    cout << "\nNegative numbers (MSB = 1):" << endl;
    char negative = -42;
    cout << "Value: " << (int)negative << endl;
    cout << "Binary: " << bitset<8>((unsigned char)negative) << endl;

    cout << "\nZero has single representation:" << endl;
    cout << "Zero: " << bitset<8>(0) << endl;
}

// ============================================================================
// SECTION 2: Creating Negative Numbers (Bit Flip and Add One)
// ============================================================================
/*
To find -X from X in two's complement:
1. Flip all bits (one's complement)
2. Add 1 to the result

Example: Find -5 from 5
  5:        0b00000101
  Flip:     0b11111010 (one's complement)
  Add 1:    0b11111011 = -5
*/

void section2_CreatingNegatives()
{
    cout << "\n=== SECTION 2: Creating Negative Numbers ===" << endl;

    char value = 5;
    cout << "Original positive value: " << (int)value << endl;
    cout << "Binary: " << bitset<8>(value) << endl;

    // Method 1: Direct negation
    char negated = -value;
    cout << "\nNegated value: " << (int)negated << endl;
    cout << "Binary: " << bitset<8>((unsigned char)negated) << endl;

    // Method 2: Manual two's complement (flip bits, add 1)
    cout << "\nManual two's complement process:" << endl;
    unsigned char flipped = ~value;
    cout << "Step 1 - Flip bits: " << bitset<8>(flipped) << endl;
    unsigned char plusOne = flipped + 1;
    cout << "Step 2 - Add 1: " << bitset<8>(plusOne) << endl;
    cout << "Interpreted as signed: " << (int)(char)plusOne << endl;
}

// ============================================================================
// SECTION 3: Integer Overflow Behavior
// ============================================================================
/*
When you exceed the maximum value in two's complement, it wraps around:
  127 + 1 = -128 (wraps to minimum)
  -128 - 1 = 127 (wraps to maximum)

This is the essence of modular arithmetic in binary.
*/

void section3_OverflowBehavior()
{
    cout << "\n=== SECTION 3: Integer Overflow ===" << endl;

    char value = 127; // Maximum for signed char
    cout << "Starting value: " << (int)value << endl;
    cout << "Binary: " << bitset<8>(value) << endl;

    value++;
    cout << "\nAfter increment:" << endl;
    cout << "New value: " << (int)value << endl;
    cout << "Binary: " << bitset<8>((unsigned char)value) << endl;
    cout << "Result: 127 + 1 = -128 (overflow wraps around)" << endl;

    cout << "\n--- Underflow Example ---" << endl;
    value = -128; // Minimum for signed char
    cout << "Starting value: " << (int)value << endl;
    cout << "Binary: " << bitset<8>((unsigned char)value) << endl;

    value--;
    cout << "\nAfter decrement:" << endl;
    cout << "New value: " << (int)value << endl;
    cout << "Binary: " << bitset<8>(value) << endl;
    cout << "Result: -128 - 1 = 127 (underflow wraps around)" << endl;
}

// ============================================================================
// SECTION 4: Sign Extension
// ============================================================================
/*
When converting from smaller to larger integer types, sign extension copies
the sign bit (MSB) to all new higher-order bits.

char -5 (8 bits):   0b11111011
int -5 (32 bits):   0xFFFFFFFB

This preserves the sign and value during promotion.
*/

void section4_SignExtension()
{
    cout << "\n=== SECTION 4: Sign Extension ===" << endl;

    char small = -42;
    int large = small; // Sign extension happens here

    cout << "char value: " << (int)small << endl;
    cout << "char binary (8-bit): " << bitset<8>((unsigned char)small) << endl;

    cout << "\nint value: " << large << endl;
    cout << "int binary (32-bit): " << bitset<32>(large) << endl;

    cout << "\nNotice value is preserved (-42)" << endl;
    cout << "But sign bit extended to all higher bits (highlighted pattern)" << endl;
}

// ============================================================================
// SECTION 5: Arithmetic Operations in Two's Complement
// ============================================================================
/*
Two's complement makes arithmetic simple:
- Addition: just add normally, overflow is fine
- Subtraction: use the same hardware as addition
- Both positive and negative work the same way

This is why computers use two's complement!
*/

void section5_Arithmetic()
{
    cout << "\n=== SECTION 5: Arithmetic in Two's Complement ===" << endl;

    cout << "--- Addition Example ---" << endl;
    char a = 50, b = 30;
    char sum = a + b;
    cout << "50 + 30 = " << (int)sum << endl;
    cout << "Binary: " << bitset<8>(a) << " + " << bitset<8>(b)
         << " = " << bitset<8>(sum) << endl;

    cout << "\n--- Mixed Sign Addition ---" << endl;
    a = -20;
    b = 50;
    sum = a + b;
    cout << "-20 + 50 = " << (int)sum << endl;
    cout << "Binary: " << bitset<8>((unsigned char)a) << " + "
         << bitset<8>(b) << " = " << bitset<8>(sum) << endl;

    cout << "\n--- Negative Addition ---" << endl;
    a = -30;
    b = -40;
    sum = a + b;
    cout << "-30 + -40 = " << (int)sum << endl;
    cout << "Binary: " << bitset<8>((unsigned char)a) << " + "
         << bitset<8>((unsigned char)b) << " = "
         << bitset<8>((unsigned char)sum) << endl;
}

// ============================================================================
// SECTION 6: Bitwise Operations
// ============================================================================
/*
Bitwise operations (AND, OR, XOR, NOT, shifts) work directly on the
binary representation. Two's complement affects how we interpret results.

Common patterns:
- Check sign: (value < 0) or (value & 0x80000000) for 32-bit int
- Flip sign: use bitwise NOT and add 1
*/

void section6_BitwiseOps()
{
    cout << "\n=== SECTION 6: Bitwise Operations ===" << endl;

    char value = 42;
    cout << "Original value: " << (int)value << endl;
    cout << "Binary: " << bitset<8>(value) << endl;

    cout << "\n--- Bitwise NOT ---" << endl;
    char flipped = ~value;
    cout << "NOT value: " << bitset<8>((unsigned char)flipped) << endl;
    cout << "As signed: " << (int)flipped << endl;

    cout << "\n--- Left Shift (multiply by 2) ---" << endl;
    value = 10;
    cout << "Original: " << (int)value << " = " << bitset<8>(value) << endl;
    value = value << 1;
    cout << "After << 1: " << (int)value << " = " << bitset<8>(value) << endl;

    cout << "\n--- Right Shift (arithmetic, preserves sign) ---" << endl;
    value = -16;
    cout << "Original: " << (int)value << " = "
         << bitset<8>((unsigned char)value) << endl;
    value = value >> 2;
    cout << "After >> 2: " << (int)value << " = "
         << bitset<8>((unsigned char)value) << endl;
    cout << "Note: Sign bit extended (arithmetic shift)" << endl;
}

// ============================================================================
// SECTION 7: Sign and Zero Extension with Type Conversion
// ============================================================================
/*
Different conversions produce different results:

Signed to Larger: Sign extension (MSB copied)
Unsigned to Larger: Zero extension (zeros added)

This can cause subtle bugs if not careful!
*/

void section7_TypeConversions()
{
    cout << "\n=== SECTION 7: Type Conversion Effects ===" << endl;

    cout << "--- Signed to Larger Type (Sign Extension) ---" << endl;
    char c = -1;
    int i = c; // Sign extension: -1 becomes 0xFFFFFFFF
    cout << "char -1 to int:" << i << endl;
    cout << "If cast to unsigned: " << (unsigned int)i << endl;

    cout << "\n--- Unsigned to Larger Type (Zero Extension) ---" << endl;
    unsigned char uc = 255;
    int si = uc; // Zero extension: 255 becomes 0x000000FF
    cout << "unsigned char 255 to int: " << si << endl;

    cout << "\n--- Same bits, different interpretation ---" << endl;
    char signed_val = -1;
    unsigned char unsigned_val = (unsigned char)signed_val;
    cout << "char -1 as unsigned char: " << (int)unsigned_val << endl;
    cout << "Binary is same, but interpretation differs" << endl;
}

// ============================================================================
// SECTION 8: Range Analysis for Different Integer Types
// ============================================================================
/*
Two's complement determines the range for each integer type.
The most significant bit is the sign bit.

8-bit:  -128 to 127
16-bit: -32768 to 32767
32-bit: -2147483648 to 2147483647
64-bit: -9223372036854775808 to 9223372036854775807
*/

void section8_TypeRanges()
{
    cout << "\n=== SECTION 8: Integer Type Ranges ===" << endl;

    cout << "8-bit (char):" << endl;
    cout << "  Min: " << (int)SCHAR_MIN << endl;
    cout << "  Max: " << (int)SCHAR_MAX << endl;

    cout << "\n16-bit (short):" << endl;
    cout << "  Min: " << SHRT_MIN << endl;
    cout << "  Max: " << SHRT_MAX << endl;

    cout << "\n32-bit (int):" << endl;
    cout << "  Min: " << INT_MIN << endl;
    cout << "  Max: " << INT_MAX << endl;

    cout << "\n64-bit (long long):" << endl;
    cout << "  Min: " << LLONG_MIN << endl;
    cout << "  Max: " << LLONG_MAX << endl;

    cout << "\nFormula: Range = -2^(n-1) to 2^(n-1) - 1" << endl;
}

// ============================================================================
// SECTION 9: Practical Examples and Edge Cases
// ============================================================================
/*
Real-world scenarios where two's complement matters:
1. Detecting overflow (sign changed unexpectedly)
2. Bit manipulation for flags and masks
3. Converting between signed and unsigned
4. Understanding undefined behavior
*/

void section9_PracticalExamples()
{
    cout << "\n=== SECTION 9: Practical Examples ===" << endl;

    cout << "--- Example 1: Check if number is negative ---" << endl;
    int num = -5;
    if (num < 0)
    {
        cout << num << " is negative" << endl;
    }
    cout << "Also true: " << ((num & 0x80000000) != 0) << " (sign bit check)" << endl;

    cout << "\n--- Example 2: Absolute value implementation ---" << endl;
    int value = -42;
    int absValue = (value < 0) ? -value : value;
    cout << "Absolute value of " << value << " = " << absValue << endl;

    cout << "\n--- Example 3: Toggle sign bit ---" << endl;
    short sh = 100;
    short negated = -sh;
    cout << "100 negated: " << negated << endl;
    cout << "Binary before: " << bitset<16>(sh) << endl;
    cout << "Binary after:  " << bitset<16>((unsigned short)negated) << endl;

    cout << "\n--- Example 4: Overflow detection ---" << endl;
    int a = INT_MAX;
    cout << "INT_MAX: " << a << endl;
    cout << "After +1: " << (a + 1) << " (overflow, wraparound to negative)" << endl;
}

// ============================================================================
// MAIN
// ============================================================================

int main()
{
    cout << "============= Two's Complement - Complete Basics =============" << endl;

    section1_BasicConcept();
    section2_CreatingNegatives();
    section3_OverflowBehavior();
    section4_SignExtension();
    section5_Arithmetic();
    section6_BitwiseOps();
    section7_TypeConversions();
    section8_TypeRanges();
    section9_PracticalExamples();

    cout << "\n============= All Sections Completed =============" << endl;

    return 0;
}
