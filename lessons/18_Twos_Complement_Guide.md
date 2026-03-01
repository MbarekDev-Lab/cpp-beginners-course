# Lesson 18: Two's Complement - Comprehensive Guide

## Overview

Two's complement is the standard method used by modern computers to represent signed integers (positive, negative, and zero). It's elegant, efficient, and enables simple hardware implementations of arithmetic operations.

**Key Facts:**

- Simplifies arithmetic operations (same hardware for addition and subtraction)
- Provides single zero representation
- Defined range based on bit width: -2^(n-1) to 2^(n-1) - 1
- Most significant bit (MSB) is the sign bit

---

## Core Concept: What is Two's Complement?

### The Problem with Sign-Magnitude

Early computer systems used sign-magnitude representation:

- 1 bit for sign (0 = positive, 1 = negative)
- Remaining bits for magnitude

**Problem:** Two representations of zero!

```
+0: 0b00000000
-0: 0b10000000
```

### The Two's Complement Solution

Two's complement fixes this by using a clever mathematical encoding:

**To represent -X in two's complement:**

1. Start with positive value X
2. Flip all bits (bitwise NOT, also called one's complement)
3. Add 1 to the result

**Example: Represent -5 in 8-bit**

```
Step 1: Start with 5
        Binary: 0b00000101

Step 2: Flip all bits (one's complement)
        Binary: 0b11111010

Step 3: Add 1
        Binary: 0b11111011 = -5
```

### Why Single Zero?

```
To find -0:
Step 1: 0 = 0b00000000
Step 2: Flip = 0b11111111
Step 3: Add 1 = 0b100000000 (overflow, wraps to 0b00000000)

Result: -0 and +0 are identical!
```

---

## Binary Representation Reference

### Signed char (8-bit) Examples

| Value | Binary     | Interpretation |
| ----- | ---------- | -------------- |
| 0     | 0b00000000 | Zero           |
| 1     | 0b00000001 | Positive       |
| 42    | 0b00101010 | Positive       |
| 127   | 0b01111111 | Max positive   |
| -1    | 0b11111111 | All bits set   |
| -42   | 0b11010110 | Negative       |
| -128  | 0b10000000 | Min negative   |

**Pattern Recognition:**

- MSB = 0: Number is positive (0 to 127)
- MSB = 1: Number is negative (-1 to -128)
- All 1s: -1
- MSB only: -128

---

## Integer Ranges by Type

### Signed Integer Ranges (Two's Complement)

```
char (8-bit):
  Minimum: -128
  Maximum: 127
  Range: -2^7 to 2^7 - 1

short (16-bit):
  Minimum: -32,768
  Maximum: 32,767
  Range: -2^15 to 2^15 - 1

int (32-bit):
  Minimum: -2,147,483,648
  Maximum: 2,147,483,647
  Range: -2^31 to 2^31 - 1

long long (64-bit):
  Minimum: -9,223,372,036,854,775,808
  Maximum: 9,223,372,036,854,775,807
  Range: -2^63 to 2^63 - 1
```

**General Formula:**

```
n-bit signed integer range: -2^(n-1) to 2^(n-1) - 1
```

---

## Arithmetic Operations

### Addition

Addition in two's complement works the same for positive and negative numbers:

```cpp
// Positive + Positive
  50 + 30 = 80
  0b00110010 + 0b00011110 = 0b01010000 ✓

// Negative + Positive
  -20 + 50 = 30
  0b11101100 + 0b00110010 = 0b00011110 ✓

// Negative + Negative
  -30 + -40 = -70
  0b11100010 + 0b11011000 = 0b11010010 ✓
```

**Hardware Advantage:** Single adder circuit works for all cases!

### Subtraction

Subtraction using two's complement:

```
A - B = A + (-B)
```

Convert B to its negative, then add. The two's complement negation is built-in!

---

## Sign Extension

When converting from smaller to larger integer type, the sign bit is extended:

```cpp
char small = -42;    // 0b11010110 (8-bit)
int large = small;   // Sign extension happens

// Result in memory:
// 0xFFFFFFD6 (32-bit int)
// 1111 1111 1111 1111 1111 1111 1101 0110
//
// All high-order bits filled with sign bit (1)
```

**Why?** Preserves the value and sign when promoting types.

### Zero Extension (Unsigned)

```cpp
unsigned char usmall = 200;  // 0b11001000 (8-bit)
int large = usmall;          // Zero extension

// Result in memory:
// 0x000000C8 (32-bit int)
// 0000 0000 0000 0000 0000 0000 1100 1000
//
// High-order bits filled with zeros
```

**Danger:** Signed to unsigned conversion loses sign information!

---

## Type Conversions and Pitfalls

### Signed to Unsigned (Careful!)

```cpp
int signed_val = -1;
unsigned int unsigned_val = (unsigned int)signed_val;
// Result: 4294967295 (on 32-bit system)
// Binary is identical, but interpretation changes!
```

### Unsigned to Signed (Also Careful!)

```cpp
unsigned int u = 3000000000;
int s = (int)u;
// Result: Negative number (value wraps)
// If MSB of unsigned is 1, result will be negative
```

### Mixed Arithmetic (Common Bug)

```cpp
int signed_val = -1;
unsigned int unsigned_val = 1;

if (signed_val < unsigned_val) {
    // TRUE? Actually FALSE!
    // signed_val gets promoted to unsigned
    // -1 becomes very large positive number
    cout << "This won't print on most systems" << endl;
}
```

---

## Bitwise Operations

### Bitwise NOT (~)

Inverts all bits (one's complement):

```cpp
char value = 5;           // 0b00000101
char flipped = ~value;    // 0b11111010 = -6

// Note: ~5 = -6 because of two's complement
// To negate: flip bits AND add 1
```

### Left Shift (<<) - Multiply

Shifts bits left, fills with zeros:

```cpp
value << 1    // Multiply by 2
value << 2    // Multiply by 4
value << n    // Multiply by 2^n
```

### Right Shift (>>) - Arithmetic Division

**Signed integer right shift:** Extends sign bit (arithmetic shift)

```cpp
-16 >> 2      // Results in -4
// 0b11110000 >> 2 = 0b11111100 = -4
```

**Unsigned right shift:** Fills with zeros

```cpp
(unsigned char)240 >> 2  // Results in 60
```

### AND, OR, XOR

```cpp
a & b   // AND: 1 only if both bits are 1
a | b   // OR:  1 if either bit is 1
a ^ b   // XOR: 1 if bits differ
```

---

## Overflow and Underflow

### Overflow Behavior

In C++, signed integer overflow is **undefined behavior!** However, in practice:

```cpp
char max_val = 127;
char overflow = max_val + 1;
// Result: -128 (wraps around due to two's complement)

int max_int = 2147483647;
int overflow_int = max_int + 1;
// Result: -2147483648 (wraps, but technically undefined)
```

### Why It Wraps

Two's complement uses modular arithmetic:

```
127 + 1 in 8-bit = 128 = 0b10000000 = -128
256 + 256 = 512 = 512 % 256 = 0
```

### Safe Practices

```cpp
// Check before operating
if (a > INT_MAX - b) {
    // Would overflow!
}

// Or use larger type
long long result = (long long)a + b;

// Or use specialized libraries
#include <limits>  // For numeric_limits<T>::max()
```

---

## Bitwise Techniques

### Check if Negative

```cpp
// Method 1: Simple comparison
if (value < 0) { /* negative */ }

// Method 2: Check sign bit (32-bit)
if (value & 0x80000000) { /* negative */ }

// Method 3: Generic for any width
if (value & (1 << (sizeof(value)*8 - 1))) { /* negative */ }
```

### Get Absolute Value

```cpp
int abs_val = (value < 0) ? -value : value;

// Or bitwise (only works for int)
int mask = value >> 31;  // All 0s if positive, all 1s if negative
int abs_val = (value + mask) ^ mask;
```

### Check Power of 2

```cpp
bool is_power_of_2 = (n > 0) && ((n & (n - 1)) == 0);
// Works because powers of 2 have single 1 bit
```

### Toggle Sign Bit

```cpp
int negated = -value;  // Simple way
int negated = ~value + 1;  // Bit manipulation way
```

---

## Real-World Applications

### 1. Network Protocols

IP addresses, ports, and packet headers often use fixed-width signed integers. Understanding two's complement prevents serialization bugs.

### 2. Graphics and Game Development

Vertex coordinates, pixel values, and physics calculations often require precise signed integer arithmetic.

### 3. Embedded Systems

Microcontrollers have fixed integer sizes. Overflow and range issues are critical in embedded code.

### 4. Cryptography

Bitwise operations on signed integers must account for sign extension.

### 5. Performance Optimization

Recognizing two's complement allows optimization:

```cpp
// Instead of division (slow)
result = value / 2;

// Use right shift (fast)
result = value >> 1;
```

---

## Common Mistakes

### Mistake 1: Assuming Signed to Unsigned Conversion is Safe

```cpp
int neg = -5;
unsigned int u = neg;  // WRONG: 'neg' becomes huge positive!
```

### Mistake 2: Forgetting About Sign Extension

```cpp
char c = -1;
int i = c;  // i = -1 (not 255!)
```

### Mistake 3: Mixing Signed and Unsigned

```cpp
int s = -1;
unsigned int u = 1;
if (s < u) { /* FALSE! s promoted to unsigned */ }
```

### Mistake 4: Integer Overflow

```cpp
int a = INT_MAX;
int b = a + 1;  // UNDEFINED BEHAVIOR!
```

---

## Best Practices

### 1. Understand Your Data Range

```cpp
// If value can be negative, declare as signed
int temperature = -5;  // ✓ Good

// If always positive, use unsigned
unsigned int count = 42;  // ✓ Good
```

### 2. Avoid Mixed Signed/Unsigned Comparisons

```cpp
int s = -5;
unsigned u = 10;

// BAD: mixed comparison
if (s < u) { }

// GOOD: explicit cast
if ((long)s < (long)u) { }
```

### 3. Check for Overflow Before Operating

```cpp
if (a > INT_MAX - b) {
    cerr << "Overflow detected!" << endl;
} else {
    result = a + b;
}
```

### 4. Use Appropriate Types

```cpp
// For values using full range
int count;

// For values that never overflow
char small_value;

// For potentially large accumulations
long long sum;
```

### 5. Document Bitwise Operations

```cpp
// Extract sign bit (32-bit integer)
bool is_negative = (value & 0x80000000) != 0;  // ← Explain bitwise

// Multiply by power of 2
result = value << 3;  // ← Note: multiply by 8
```

---

## Comparison with Alternatives

### Two's Complement vs. Sign-Magnitude

| Feature               | Two's Complement | Sign-Magnitude |
| --------------------- | ---------------- | -------------- |
| Zero representations  | 1                | 2              |
| Arithmetic complexity | Simple           | Complex        |
| Hardware efficiency   | High             | Low            |
| Historical use        | Modern           | Legacy         |
| Standard in C++       | Yes              | No             |

### Signed vs. Unsigned (Range Tradeoff)

| Aspect            | Signed          | Unsigned               |
| ----------------- | --------------- | ---------------------- |
| Negative numbers  | Supported       | Not supported          |
| Range (8-bit)     | -128 to 127     | 0 to 255               |
| Range (32-bit)    | -2^31 to 2^31-1 | 0 to 2^32-1            |
| Overflow behavior | Undefined       | Wraps (defined)        |
| Use case          | General purpose | Counts, indices, flags |

---

## Modern C++ Features

### <climits> Header

```cpp
#include <climits>

cout << INT_MAX << endl;      // 2147483647
cout << INT_MIN << endl;      // -2147483648
cout << SCHAR_MAX << endl;    // 127
cout << SCHAR_MIN << endl;    // -128
```

### <limits> for Generic Programming

```cpp
#include <limits>

template<typename T>
void show_range() {
    cout << "Min: " << numeric_limits<T>::min() << endl;
    cout << "Max: " << numeric_limits<T>::max() << endl;
}

show_range<int>();
```

### Bitset for Binary Representation

```cpp
#include <bitset>

int value = -5;
cout << bitset<8>((unsigned char)value) << endl;  // 11111011
```

---

## Summary

**Two's Complement is:**

- The universal standard for representing signed integers
- Based on simple mathematical algorithm (flip bits, add 1)
- Efficient for hardware arithmetic (same circuits for +/-)
- Essential knowledge for low-level C++ programming

**Key Points:**

- MSB is sign bit: 0 = positive, 1 = negative
- Range: -2^(n-1) to 2^(n-1) - 1 for n-bit integers
- Sign extension on promotion preserves value
- Arithmetic operations work consistently
- Overflow is undefined for signed integers
- Be careful with signed/unsigned mixing

**Practice Focus:**

- Understand the bit patterns
- Recognize overflow conditions
- Predict type promotion behavior
- Use appropriate types for your data
