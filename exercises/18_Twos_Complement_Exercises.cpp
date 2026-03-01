//============================================================================
// Lesson 18: Two's Complement - Exercises
// Author      : M'Barek Benraiss
// Description : Progressive exercises for understanding two's complement,
//               binary representation, and signed integer behavior
//============================================================================

#include <iostream>
#include <bitset>
#include <climits>
#include <iomanip>
using namespace std;

// ============================================================================
// EXERCISE 1: Understand Basic Binary Representation
// ============================================================================
/*
EXERCISE 1: Print binary representation of positive and negative numbers
- Use bitset to display 8-bit binary representation
- Show positive value 50
- Show negative value -50
- Explain the pattern: MSB determines sign
*/

void exercise1()
{
    cout << "\n--- Exercise 1: Binary Representation ---" << endl;

    char positive = 50;
    char negative = -50;

    cout << "Positive 50:" << endl;
    cout << "  Decimal: " << (int)positive << endl;
    cout << "  Binary:  " << bitset<8>(positive) << endl;

    cout << "\nNegative -50:" << endl;
    cout << "  Decimal: " << (int)negative << endl;
    cout << "  Binary:  " << bitset<8>((unsigned char)negative) << endl;

    cout << "\nAnalysis:" << endl;
    cout << "  Positive 50: MSB = 0 (first bit is 0)" << endl;
    cout << "  Negative -50: MSB = 1 (first bit is 1)" << endl;
    cout << "SUCCESS: Positive numbers have MSB=0, negative have MSB=1" << endl;
}

// ============================================================================
// EXERCISE 2: Calculate Two's Complement Manually
// ============================================================================
/*
EXERCISE 2: Manually convert number to its negative using two's complement
- Start with positive value
- Flip all bits
- Add 1
- Verify result matches direct negation
*/

void exercise2()
{
    cout << "\n--- Exercise 2: Two's Complement Calculation ---" << endl;

    unsigned char positive = 42;
    cout << "Starting value: " << (int)positive << endl;
    cout << "Binary: " << bitset<8>(positive) << endl;

    cout << "\nStep 1 - Flip all bits:" << endl;
    unsigned char flipped = ~positive;
    cout << "Result: " << bitset<8>(flipped) << endl;

    cout << "\nStep 2 - Add 1:" << endl;
    unsigned char result = flipped + 1;
    cout << "Result: " << bitset<8>(result) << endl;
    cout << "As signed: " << (int)(char)result << endl;

    cout << "\nVerification:" << endl;
    char direct_negate = -42;
    cout << "Direct -42: " << bitset<8>((unsigned char)direct_negate) << endl;
    cout << "Match: " << (result == (unsigned char)direct_negate ? "YES" : "NO") << endl;

    cout << "SUCCESS: Two's complement calculation verified" << endl;
}

// ============================================================================
// EXERCISE 3: Integer Overflow Behavior
// ============================================================================
/*
EXERCISE 3: Observe how overflow wraps around in two's complement
- Start at maximum positive value
- Increment and show wraparound
- Demonstrate with char (127 → -128)
*/

void exercise3()
{
    cout << "\n--- Exercise 3: Integer Overflow ---" << endl;

    cout << "Demonstrating overflow with char (8-bit):" << endl;

    char value = 126;
    cout << "\nStarting at 126:" << endl;
    cout << "  Value: " << (int)value << endl;
    cout << "  Binary: " << bitset<8>(value) << endl;

    value++;
    cout << "\nAfter increment (126 + 1):" << endl;
    cout << "  Value: " << (int)value << " (still positive)" << endl;
    cout << "  Binary: " << bitset<8>(value) << endl;

    value++;
    cout << "\nAfter another increment (127 + 1):" << endl;
    cout << "  Value: " << (int)value << " (OVERFLOW! wrapped to negative)" << endl;
    cout << "  Binary: " << bitset<8>((unsigned char)value) << endl;

    cout << "\nExplanation:" << endl;
    cout << "  127 is maximum for 8-bit signed" << endl;
    cout << "  127 + 1 wraps to -128 (two's complement behavior)" << endl;

    cout << "SUCCESS: Overflow behavior demonstrated" << endl;
}

// ============================================================================
// EXERCISE 4: Detect Negative Numbers Using Bitwise Operations
// ============================================================================
/*
EXERCISE 4: Use bitwise operations to check if number is negative
- Method 1: Simple comparison (num < 0)
- Method 2: Check MSB with bitwise AND (num & 0x80)
- Show both methods produce same result
*/

void exercise4()
{
    cout << "\n--- Exercise 4: Detecting Negative Numbers ---" << endl;

    char test_values[] = {-50, -1, 0, 1, 50, 127, -128};

    cout << "Value | < 0 | MSB Check | Match" << endl;
    cout << "------|-----|-----------|-------" << endl;

    for (char val : test_values)
    {
        bool method1 = (val < 0);
        bool method2 = ((unsigned char)val & 0x80) != 0;

        cout << setw(5) << (int)val << " | "
             << (method1 ? "T" : "F") << "   | "
             << (method2 ? "T" : "F") << "       | "
             << (method1 == method2 ? "YES" : "NO") << endl;
    }

    cout << "\nVerification:" << endl;
    cout << "Both methods always match!" << endl;
    cout << "SUCCESS: Multiple detection methods confirmed" << endl;
}

// ============================================================================
// EXERCISE 5: Sign Extension During Type Promotion
// ============================================================================
/*
EXERCISE 5: Show how sign extension works when converting to larger type
- char -1 to int: should remain -1
- Show binary representation in both sizes
- Explain why all high-order bits become 1
*/

void exercise5()
{
    cout << "\n--- Exercise 5: Sign Extension ---" << endl;

    cout << "Converting char to int:" << endl;

    char small = -1;
    int large = small; // Sign extension happens

    cout << "\nchar -1 (8-bit):" << endl;
    cout << "  Value: " << (int)small << endl;
    cout << "  Binary: " << bitset<8>((unsigned char)small) << endl;

    cout << "\nint -1 (32-bit):" << endl;
    cout << "  Value: " << large << endl;
    cout << "  Binary: " << bitset<32>((unsigned int)large) << endl;

    cout << "\nObservation:" << endl;
    cout << "  Value preserved: -1 remains -1" << endl;
    cout << "  Sign bit (1) extended to all higher-order bits" << endl;
    cout << "  All 32 bits are 1: 0xFFFFFFFF" << endl;

    cout << "\nCompare with unsigned:" << endl;
    unsigned char usmall = 255;
    int ularge = usmall; // Zero extension
    cout << "  unsigned char 255 to int: " << ularge << endl;
    cout << "  High bits filled with zeros (0x000000FF)" << endl;

    cout << "SUCCESS: Sign extension vs zero extension demonstrated" << endl;
}

// ============================================================================
// EXERCISE 6: Understand Two's Complement Number Properties
// ============================================================================
/*
EXERCISE 6: Analyze mathematical properties of two's complement
- Show that -X = ~X + 1
- Show that ~X = -(X+1)
- Demonstrate with multiple values
*/

void exercise6()
{
    cout << "\n--- Exercise 6: Two's Complement Properties ---" << endl;

    cout << "Property: -X = ~X + 1" << endl;
    cout << "\nValue | -Value | ~Value+1 | Match" << endl;
    cout << "------|--------|----------|-------" << endl;

    for (int x = -50; x <= 50; x += 25)
    {
        char val = x;
        char neg_val = -val;
        char calc_neg = (char)(~(unsigned char)val + 1);

        cout << setw(5) << x << " | "
             << setw(6) << (int)neg_val << " | "
             << setw(8) << (int)calc_neg << " | "
             << (neg_val == calc_neg ? "YES" : "NO") << endl;
    }

    cout << "\nProperty: ~X = -(X+1)" << endl;
    cout << "Value | ~Value | -(Value+1) | Match" << endl;
    cout << "------|--------|------------|-------" << endl;

    for (int x = -50; x <= 50; x += 25)
    {
        char val = x;
        char not_val = ~val;
        char calc = -(val + 1);

        cout << setw(5) << x << " | "
             << setw(6) << (int)not_val << " | "
             << setw(10) << (int)calc << " | "
             << (not_val == calc ? "YES" : "NO") << endl;
    }

    cout << "SUCCESS: Two's complement properties verified" << endl;
}

// ============================================================================
// EXERCISE 7: Arithmetic with Negative Numbers
// ============================================================================
/*
EXERCISE 7: Perform arithmetic with two's complement numbers
- Add positive + negative
- Add negative + negative
- Show that binary addition works correctly
- Verify results match decimal expectations
*/

void exercise7()
{
    cout << "\n--- Exercise 7: Arithmetic Operations ---" << endl;

    cout << "Addition Examples:" << endl;

    cout << "\nPositive + Negative:" << endl;
    char a = 50;
    char b = -30;
    char result = a + b;
    cout << "  50 + (-30) = " << (int)result << endl;
    cout << "  Check: 50 - 30 = " << (50 - 30) << " ✓" << endl;

    cout << "\nNegative + Negative:" << endl;
    a = -40;
    b = -35;
    result = a + b;
    cout << "  (-40) + (-35) = " << (int)result << endl;
    cout << "  Check: -(40 + 35) = " << -(40 + 35) << " ✓" << endl;

    cout << "\nWith Overflow:" << endl;
    a = 100;
    b = 50;
    result = a + b; // Overflow: 150 > 127
    cout << "  100 + 50 = " << (int)result << " (overflow)" << endl;
    cout << "  Expected: wraps to negative due to MSB" << endl;

    cout << "SUCCESS: Arithmetic operations work consistently" << endl;
}

// ============================================================================
// EXERCISE 8: Bitwise Operations on Signed Integers
// ============================================================================
/*
EXERCISE 8: Practice bitwise AND, OR, XOR, NOT operations
- Show how each operation affects the bits
- Demonstrate with signed values
- Use both positive and negative
*/

void exercise8()
{
    cout << "\n--- Exercise 8: Bitwise Operations ---" << endl;

    char a = 42;  // 0b00101010
    char b = -42; // 0b11010110

    cout << "a = 42:  " << bitset<8>(a) << " (positive)" << endl;
    cout << "b = -42: " << bitset<8>((unsigned char)b) << " (negative)" << endl;

    cout << "\nBitwise NOT:" << endl;
    char not_a = ~a;
    cout << "~a: " << bitset<8>((unsigned char)not_a)
         << " = " << (int)not_a << " (which is -43)" << endl;

    cout << "\nBitwise AND:" << endl;
    char and_result = a & -a; // Isolates the lowest set bit
    cout << "a & (-a): " << bitset<8>((unsigned char)and_result)
         << " = " << (int)and_result << endl;

    cout << "\nBitwise OR:" << endl;
    char or_result = a | b;
    cout << "a | b: " << bitset<8>((unsigned char)or_result)
         << " = " << (int)or_result << endl;

    cout << "\nBitwise XOR:" << endl;
    char xor_result = a ^ b;
    cout << "a ^ b: " << bitset<8>((unsigned char)xor_result)
         << " = " << (int)xor_result << endl;

    cout << "SUCCESS: Bitwise operations on signed integers demonstrated" << endl;
}

// ============================================================================
// EXERCISE 9: Bit Shifting with Signed Integers
// ============================================================================
/*
EXERCISE 9: Understand arithmetic shift behavior
- Left shift multiplies by 2^n
- Right shift on negative divides but extends sign bit
- Show difference between signed and unsigned shifts
*/

void exercise9()
{
    cout << "\n--- Exercise 9: Bit Shifting ---" << endl;

    cout << "Left Shift (Multiply by 2^n):" << endl;
    char value = 10;
    cout << "10 << 1 = " << (int)(value << 1) << " (10 * 2)" << endl;
    cout << "10 << 2 = " << (int)(value << 2) << " (10 * 4)" << endl;
    cout << "10 << 3 = " << (int)(value << 3) << " (10 * 8)" << endl;

    cout << "\nRight Shift (Divide by 2^n, arithmetic):" << endl;
    value = -32;
    cout << "-32 >> 1 = " << (int)(value >> 1) << " (-32 / 2)" << endl;
    cout << "Binary: " << bitset<8>((unsigned char)value) << " >> 1" << endl;
    cout << "Result: " << bitset<8>((unsigned char)(value >> 1)) << endl;
    cout << "Note: Sign bit (1) is extended to new MSB" << endl;

    cout << "\nVisual Arithmetic Shift:" << endl;
    cout << "-16 before: " << bitset<8>((unsigned char)(char)-16) << endl;
    cout << "-16 >> 2:   " << bitset<8>((unsigned char)((char)-16 >> 2)) << endl;
    cout << "Result: " << (int)((char)-16 >> 2) << " (-16 / 4 = -4)" << endl;

    cout << "SUCCESS: Shift operations understood" << endl;
}

// ============================================================================
// EXERCISE 10: Type Conversion and Sign Issues
// ============================================================================
/*
EXERCISE 10: Show problems with signed/unsigned conversion
- Convert signed to unsigned: value changes
- Convert unsigned to signed: may become negative
- Show comparison problems with signed/unsigned mix
*/

void exercise10()
{
    cout << "\n--- Exercise 10: Type Conversion Issues ---" << endl;

    cout << "Signed to Unsigned Conversion:" << endl;
    int signed_val = -1;
    unsigned int unsigned_val = (unsigned int)signed_val;
    cout << "  int -1 to unsigned: " << unsigned_val << endl;
    cout << "  (On 32-bit: 4294967295)" << endl;
    cout << "  Binary same, interpretation changes!" << endl;

    cout << "\nUnsigned to Signed Conversion:" << endl;
    unsigned char u = 200;
    char s = (char)u;
    cout << "  unsigned char 200 to char: " << (int)s << endl;
    cout << "  200's bit pattern (0b11001000) interpreted as -56" << endl;

    cout << "\nMixed Comparison Problem:" << endl;
    int s2 = -5;
    unsigned u2 = 10;
    cout << "  if (int -5 < unsigned 10):" << endl;
    cout << "    int promoted to unsigned → becomes huge positive" << endl;
    cout << "    Result: -5 NOT less than 10" << endl;

    cout << "  Safe: if ((long)s2 < (long)u2):" << endl;
    cout << "    Both promoted to same signed type" << endl;

    cout << "SUCCESS: Type conversion dangers demonstrated" << endl;
}

// ============================================================================
// EXERCISE 11: Calculate Range for Different Integer Types
// ============================================================================
/*
EXERCISE 11: Display range for various integer types
- Use SCHAR_MIN/MAX, INT_MIN/MAX, LLONG_MIN/MAX
- Verify formula: -2^(n-1) to 2^(n-1) - 1
- Show the gap between max and min
*/

void exercise11()
{
    cout << "\n--- Exercise 11: Integer Type Ranges ---" << endl;

    cout << "char (8-bit):" << endl;
    cout << "  Min: " << (int)SCHAR_MIN << endl;
    cout << "  Max: " << (int)SCHAR_MAX << endl;
    cout << "  Range: " << (int)SCHAR_MAX - (int)SCHAR_MIN << endl;
    cout << "  Formula check: -2^7 = " << -(1 << 7)
         << ", 2^7 - 1 = " << ((1 << 7) - 1) << endl;

    cout << "\nshort (16-bit):" << endl;
    cout << "  Min: " << SHRT_MIN << endl;
    cout << "  Max: " << SHRT_MAX << endl;

    cout << "\nint (32-bit):" << endl;
    cout << "  Min: " << INT_MIN << endl;
    cout << "  Max: " << INT_MAX << endl;

    cout << "\nlong long (64-bit):" << endl;
    cout << "  Min: " << LLONG_MIN << endl;
    cout << "  Max: " << LLONG_MAX << endl;

    cout << "\nAsymmetry Note:" << endl;
    cout << "  |Min| = 2^(n-1), |Max| = 2^(n-1) - 1" << endl;
    cout << "  -128 exists, but 128 doesn't in 8-bit signed!" << endl;

    cout << "SUCCESS: Type ranges verified" << endl;
}

// ============================================================================
// EXERCISE 12: Overflow Detection
// ============================================================================
/*
EXERCISE 12: Detect possible overflow before it happens
- Check if a + b would overflow
- Check if a * b would overflow
- Use larger type to capture actual result
*/

void exercise12()
{
    cout << "\n--- Exercise 12: Overflow Detection ---" << endl;

    cout << "Addition Overflow Detection:" << endl;

    int a = INT_MAX;
    int b = 10;

    cout << "a = " << a << " (INT_MAX)" << endl;
    cout << "b = " << b << endl;

    bool would_overflow = (b > 0 && a > INT_MAX - b);
    cout << "Would a + b overflow? " << (would_overflow ? "YES" : "NO") << endl;

    if (would_overflow)
    {
        cout << "Safe calculation using larger type:" << endl;
        long long result = (long long)a + b;
        cout << "  (long long)a + b = " << result << endl;
    }

    cout << "\nMultiplication Overflow Detection:" << endl;
    int x = 100;
    int y = 30000;

    cout << "x = " << x << endl;
    cout << "y = " << y << endl;

    bool mult_overflow = (x > 0 && y > INT_MAX / x);
    cout << "Would x * y overflow? " << (mult_overflow ? "YES" : "NO") << endl;

    if (mult_overflow)
    {
        long long result = (long long)x * y;
        cout << "Safe: (long long)x * y = " << result << endl;
    }

    cout << "SUCCESS: Overflow detection methods verified" << endl;
}

// ============================================================================
// EXERCISE 13: Practical Two's Complement Example - Temperature
// ============================================================================
/*
EXERCISE 13: Real-world scenario using signed integers
- Temperature can be positive or negative
- Store temperatures in array
- Find min, max, average
- Demonstrate practical use of two's complement
*/

void exercise13()
{
    cout << "\n--- Exercise 13: Practical Example - Temperature Data ---" << endl;

    // Temperature readings (in Celsius)
    char temperatures[] = {5, -3, 15, -10, 0, 8, -2, 20, -15, 12};
    int count = sizeof(temperatures) / sizeof(char);

    cout << "Temperature readings (°C):" << endl;
    for (int i = 0; i < count; i++)
    {
        cout << setw(3) << (int)temperatures[i] << "° ";
        if ((i + 1) % 5 == 0)
            cout << endl;
    }
    cout << endl;

    // Find min and max
    char min_temp = temperatures[0];
    char max_temp = temperatures[0];
    int sum = 0;

    for (int i = 0; i < count; i++)
    {
        if (temperatures[i] < min_temp)
            min_temp = temperatures[i];
        if (temperatures[i] > max_temp)
            max_temp = temperatures[i];
        sum += temperatures[i];
    }

    double average = (double)sum / count;

    cout << "Analysis:" << endl;
    cout << "  Minimum: " << (int)min_temp << "°C" << endl;
    cout << "  Maximum: " << (int)max_temp << "°C" << endl;
    cout << "  Average: " << fixed << setprecision(1) << average << "°C" << endl;
    cout << "  Range:   " << (int)(max_temp - min_temp) << "°C" << endl;

    cout << "\nWhy Two's Complement matters:" << endl;
    cout << "  Negative temperatures handled naturally" << endl;
    cout << "  One representation of -0 (and 0)" << endl;
    cout << "  Arithmetic just works (no special negative handling)" << endl;

    cout << "SUCCESS: Real-world application demonstrated" << endl;
}

// ============================================================================
// MAIN
// ============================================================================

int main()
{
    cout << "========== Two's Complement Exercises ==========" << endl;

    exercise1();
    exercise2();
    exercise3();
    exercise4();
    exercise5();
    exercise6();
    exercise7();
    exercise8();
    exercise9();
    exercise10();
    exercise11();
    exercise12();
    exercise13();

    cout << "\n========== All Exercises Completed Successfully ==========" << endl;

    return 0;
}
