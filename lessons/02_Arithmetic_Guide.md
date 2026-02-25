# Arithmetic Operations Lesson - Complete Guide

## Arithmetic Operators

C++ provides five basic arithmetic operators:

| Operator | Name               | Example  | Result |
| -------- | ------------------ | -------- | ------ |
| `+`      | Addition           | `5 + 3`  | `8`    |
| `-`      | Subtraction        | `5 - 3`  | `2`    |
| `*`      | Multiplication     | `5 * 3`  | `15`   |
| `/`      | Division           | `15 / 3` | `5`    |
| `%`      | Modulo (remainder) | `17 % 5` | `2`    |

## Important: Integer vs. Double Division

```cpp
int result1 = 7 / 2;           // Result: 3 (truncated!)
double result2 = 7.0 / 2.0;    // Result: 3.5
double result3 = (double)7 / 2; // Result: 3.5 (cast to double)
```

**Key Point**: When dividing two integers, the result is always an integer. Any decimal part is lost!

## Type Casting

Casting converts one data type to another:

```cpp
int a = (int)7.9;      // Convert double to int: 7
double b = (double)7;  // Convert int to double: 7.0
double c = 7 / 2.0;    // Automatic conversion: 3.5
```

### Common Casts

- `(int)` - Convert to integer
- `(double)` - Convert to double
- `(float)` - Convert to float
- `(char)` - Convert to character

## Compound Assignment Operators

Instead of writing `a = a + 5`, you can use `a += 5`:

| Operator | Example  | Equivalent  |
| -------- | -------- | ----------- |
| `+=`     | `a += 5` | `a = a + 5` |
| `-=`     | `a -= 3` | `a = a - 3` |
| `*=`     | `a *= 2` | `a = a * 2` |
| `/=`     | `a /= 4` | `a = a / 4` |
| `%=`     | `a %= 3` | `a = a % 3` |

## Increment and Decrement

```cpp
int x = 5;
x++;   // x becomes 6 (increment by 1)
x--;   // x becomes 5 (decrement by 1)

// Pre vs Post increment
int a = 5;
int b = a++;  // b = 5, then a = 6 (post-increment)
int c = ++a;  // a = 7, then c = 7 (pre-increment)
```

## The Modulo Operator (%)

Modulo returns the **remainder** after division:

```cpp
17 % 5 = 2    // 17 ÷ 5 = 3 remainder 2
10 % 3 = 1    // 10 ÷ 3 = 3 remainder 1
20 % 4 = 0    // 20 ÷ 4 = 5 remainder 0 (evenly divisible)
```

### Uses of Modulo

1. **Check if number is even or odd**

   ```cpp
   if (num % 2 == 0) cout << "Even";
   else cout << "Odd";
   ```

2. **Create repeating patterns**

   ```cpp
   for (int i = 0; i < 100; i++) {
       if (i % 10 == 0) cout << "\n";  // New line every 10
   }
   ```

3. **Cycle through indices**
   ```cpp
   int arr[5] = {1, 2, 3, 4, 5};
   int index = i % 5;  // Always between 0-4
   ```

## Operator Precedence

Operations follow this order (like in math):

```
1. Parentheses ()
2. Multiplication (*), Division (/), Modulo (%)
3. Addition (+), Subtraction (-)
4. Assignment (=, +=, -=, etc.)
```

### Examples

```cpp
// Without parentheses:
5 + 3 * 2 = 5 + 6 = 11  (NOT 16)

// With parentheses:
(5 + 3) * 2 = 8 * 2 = 16

// Complex expression:
2 + 3 * 4 / 2 - 1
= 2 + 12 / 2 - 1   (multiply first)
= 2 + 6 - 1        (divide next)
= 8 - 1            (add/subtract left to right)
= 7
```

### Best Practice

**Always use parentheses when in doubt!** It makes code clearer and prevents bugs.

## Practical Example: Converting Seconds

Convert a large number of seconds into hours, minutes, and remaining seconds:

```cpp
int totalSeconds = 3661;  // 1 hour, 1 minute, 1 second

int hours = totalSeconds / 3600;        // 3661 / 3600 = 1
int remaining = totalSeconds % 3600;    // 3661 % 3600 = 61

int minutes = remaining / 60;           // 61 / 60 = 1
int seconds = remaining % 60;           // 61 % 60 = 1

cout << hours << "h " << minutes << "m " << seconds << "s";
// Output: 1h 1m 1s
```

## Progress Indicator with Modulo

Print a dot every 100 iterations:

```cpp
for (int i = 1; i <= 1000; i++) {
    if (i % 100 == 0) {
        cout << ".";
    }
}
// Output: ..........  (10 dots)
```

## Summary Table

| Concept          | Example        | Result         |
| ---------------- | -------------- | -------------- |
| Integer division | `7 / 2`        | `3`            |
| Double division  | `7.0 / 2.0`    | `3.5`          |
| Modulo           | `17 % 5`       | `2`            |
| Compound add     | `a += 5`       | `a = a + 5`    |
| Increment        | `a++`          | `a = a + 1`    |
| Even check       | `num % 2 == 0` | `true` if even |

## Next Steps

1. Master arithmetic operations ✓
2. Learn about type casting and precision
3. Understand operator precedence
4. Practice with loops and conditions
5. Build mathematical applications
