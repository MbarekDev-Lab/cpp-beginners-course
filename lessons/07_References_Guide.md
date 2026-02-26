# References in C++

## What is a Reference?

A **reference** is an **alias** for an existing variable. It's another name for the same variable, not a copy.

```cpp
int value1 = 8;
int &value2 = value1;  // value2 is another name for value1

value2 = 10;  // This modifies value1!

cout << value1 << endl;  // Prints: 10
cout << value2 << endl;  // Prints: 10
```

**Key insight**: `value1` and `value2` refer to the **same memory location**.

## Reference Syntax

```cpp
data_type &reference_name = original_variable;
```

Examples:

```cpp
int &ref = x;                    // Reference to int
double &ref = pi;                // Reference to double
string &ref = myString;           // Reference to string
```

## References vs Pointers

While both references and pointers allow indirect access, they work differently:

### Reference

```cpp
int x = 5;
int &ref = x;

cout << ref;    // 5 (automatic dereferencing)
ref = 10;       // Modifies x
```

### Pointer

```cpp
int x = 5;
int *ptr = &x;

cout << *ptr;   // 5 (needs dereferencing with *)
*ptr = 10;      // Modifies x
```

## Key Differences

| Aspect             | Reference             | Pointer              |
| ------------------ | --------------------- | -------------------- |
| **Syntax**         | `int &ref = var;`     | `int *ptr = &var;`   |
| **Initialization** | Must initialize       | Can be uninitialized |
| **Null value**     | Never null            | Can be null          |
| **Reassignment**   | Cannot change binding | Can point elsewhere  |
| **Dereferencing**  | Automatic             | Manual with `*`      |
| **Array of refs**  | Not allowed           | Allowed              |
| **Syntax clarity** | Cleaner               | More explicit        |

## Creating References

### Basic Reference

```cpp
int value1 = 8;
int &value2 = value1;  // value2 is an alias for value1
```

Both variables now occupy the **same memory**:

```cpp
&value1 == &value2  // True - same address!
```

### Modifying Through Reference

```cpp
int value1 = 8;
int &value2 = value1;

value2 = 10;    // Changes value1 too!

cout << value1;  // 10
cout << value2;  // 10
```

## References as Function Parameters

### Modifying Original Arguments

Without references (pointer style):

```cpp
void increment(int *val) {
    (*val)++;
}

int x = 5;
increment(&x);  // Pass address
cout << x;      // 6
```

With references (cleaner):

```cpp
void increment(int &val) {
    val++;  // No dereferencing needed!
}

int x = 5;
increment(x);   // Pass by reference
cout << x;      // 6
```

### Const References

For read-only access without copying:

```cpp
void printValue(const double &val) {
    cout << val << endl;  // Can read but not modify
}

double pi = 3.14159;
printValue(pi);  // Efficient - no copy made!
```

**Benefits**:

- ✓ No copy (efficient for large objects)
- ✓ Cannot accidentally modify
- ✓ Clear intent: read-only

## Returning References

You can return references from functions, but be **very careful**:

### Safe - Returning Parameter Reference

```cpp
int &getMax(int &a, int &b) {
    return (a > b) ? a : b;
}

int x = 5, y = 10;
int &maxRef = getMax(x, y);
maxRef = 100;  // Modifies y
```

### Dangerous - Returning Local Variable Reference

```cpp
int &dangerousRef() {
    int local = 5;
    return local;  // UNDEFINED BEHAVIOR! local is destroyed
}
```

**Rule**: Never return reference to local variable!

## Important Properties of References

### 1. Must Be Initialized

```cpp
int &ref;           // ERROR - must initialize!
int &ref = x;       // OK
```

### 2. Cannot Be Reassigned

```cpp
int x = 10, y = 20;

int &ref = x;   // ref refers to x
ref = y;        // This copies y's value to x
                // Does NOT make ref refer to y!

cout << x;      // 20 (not 10!)
cout << ref;    // 20 (still refers to x)
```

### 3. No Null References

```cpp
int *ptr = nullptr;    // OK - pointer can be null
int &ref = nullptr;    // ERROR - reference cannot be null!
```

### 4. Cannot Have Array of References

```cpp
int &arr[3] = {a, b, c};  // ERROR!
int *arr[3] = {&a, &b, &c};  // OK - array of pointers
```

## Practical Examples

### Example 1: Swapping Values

```cpp
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int x = 5, y = 10;
swap(x, y);
cout << x << " " << y;  // 10 5
```

### Example 2: Modifying Function Arguments

```cpp
void changeValue(double &val) {
    val = 111.111;
}

double value = 3.14;
changeValue(value);
cout << value;  // 111.111
```

### Example 3: Range-Based For Loop

```cpp
int arr[] = {1, 2, 3, 4, 5};

// With reference - modifies array
for (int &x : arr) {
    x = x * 2;
}

// Without reference - doesn't modify
for (int x : arr) {  // x is a copy
    x = x * 2;
}
```

### Example 4: Avoiding Copies

```cpp
// Without reference - expensive copy
void processString(string str) {
    // str is a copy of argument
    cout << str.length();
}

// With const reference - no copy
void processString(const string &str) {
    // str is reference to original
    cout << str.length();  // More efficient!
}
```

## When to Use References

### Use References When:

✓ Passing parameters that need modification
✓ Avoiding copies of large objects
✓ Read-only access to objects (const reference)
✓ Return multiple values through parameters
✓ Implementing operators like `operator[]`

### Use Pointers When:

✓ Need null value
✓ Need to change what it points to
✓ Working with dynamic memory (new/delete)
✓ Array of addresses needed
✓ Using C libraries

### Use Pass by Value When:

✓ Parameter is small (int, double, char)
✓ Don't need to modify original
✓ Creating a copy is intentional

## Common Mistakes

### Mistake 1: Returning Reference to Local

```cpp
// WRONG
int &getBad() {
    int local = 5;
    return local;  // local is destroyed!
}

// CORRECT
int getBad() {
    int local = 5;
    return local;  // Returns copy (safe)
}
```

### Mistake 2: Forgetting Initialization

```cpp
// WRONG
int &ref;           // ERROR

// CORRECT
int x = 5;
int &ref = x;       // Must initialize
```

### Mistake 3: Expecting Reassignment

```cpp
int x = 10, y = 20;
int &ref = x;
ref = y;            // Assigns y's value to x, not rebinding!

cout << x;          // 20, not 10
cout << (ref == x);  // true - ref still refers to x
```

### Mistake 4: Reference to Temporary

```cpp
// WRONG
const int &ref = getValue() + 5;  // Undefined behavior

// SAFER
int temp = getValue() + 5;
const int &ref = temp;            // More explicit
```

## Reference Best Practices

1. **Use const references** for read-only parameters:

   ```cpp
   void printArray(const vector<int> &arr)
   ```

2. **Use references** for parameters that modify:

   ```cpp
   void reverseArray(int *arr, int size)  // or vector &arr
   ```

3. **Prefer value** for small types:

   ```cpp
   void process(int x)  // int is small, no need for reference
   ```

4. **Document intent clearly**:

   ```cpp
   // function will modify x
   void update(int &x)

   // function will not modify x
   void read(const int &x)
   ```

5. **Never return local references**:
   ```cpp
   int &getBadRef() { return local; }      // NO!
   const int &getConstRef() { return 5; }  // NO!
   ```

## Summary

| Concept           | Key Point                                |
| ----------------- | ---------------------------------------- |
| **What**          | Reference is an alias for a variable     |
| **How**           | `int &ref = var;`                        |
| **Purpose**       | Modify original variables, avoid copies  |
| **Advantages**    | Cleaner than pointers, safer             |
| **Disadvantages** | Cannot be reassigned, no null            |
| **Parameters**    | Use references to modify or avoid copies |
| **Returns**       | Careful! Never return local reference    |

## Next Steps

1. ✓ Understand reference basics
2. ✓ Use references as function parameters
3. ✓ Use const references efficiently
4. ✓ Compare with pointers
5. Learn advanced reference use in classes
