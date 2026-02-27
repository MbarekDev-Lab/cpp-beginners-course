# LESSON 11: Returning Objects From Methods

## Stack vs Heap, References vs Pointers

---

## Table of Contents

1. [Introduction](#introduction)
2. [Return by Value (Stack Objects)](#return-by-value-stack-objects)
3. [Return by Reference](#return-by-reference)
4. [Return by Pointer (Heap Objects)](#return-by-pointer-heap-objects)
5. [Comparing All Methods](#comparing-all-methods)
6. [Ownership and Responsibility](#ownership-and-responsibility)
7. [Common Mistakes](#common-mistakes)
8. [Best Practices](#best-practices)
9. [Modern C++ Approach](#modern-c-approach)

---

## Introduction

When writing functions and methods that return objects, you have several choices:

1. **Return by Value** - Return a copy of the object
2. **Return by Reference** - Return a reference to an existing object
3. **Return by Pointer** - Return a pointer to an object

Each approach has different implications for:

- **Memory efficiency**: Copy overhead vs no overhead
- **Object lifetime**: How long the object persists
- **Safety**: Risk of errors and undefined behavior
- **Complexity**: Who owns and manages the object

---

## Return by Value (Stack Objects)

### Basic Concept

When you return an object by value:

```cpp
Animal createAnimalByValue() {
    Animal animal;              // Created on stack
    animal.setName("Freddy");
    return animal;              // Copy constructor called
}                               // Original destroyed

int main() {
    Animal cat = createAnimalByValue();  // Caller receives copy
    cat.speak();
}
```

### What Happens

1. **Object created** inside function on stack
2. **Copy constructor called** before return
3. **Original object destroyed** when function exits
4. **Caller receives independent copy**

### Execution Flow

```
createAnimalByValue called
  -> Animal created on stack
  -> Constructor called
Copy before return
  -> Copy constructor called (creates copy)
Function exits
  -> Destructor called for original
Caller receives copy
  -> Copy now owned by caller
  -> Copy destroyed when caller goes out of scope
```

### Example with Output

```cpp
class Animal {
public:
    Animal() {
        cout << "Constructor called" << endl;
    }

    Animal(const Animal& other) {
        cout << "Copy constructor called" << endl;
    }

    ~Animal() {
        cout << "Destructor called" << endl;
    }
};

Animal createAnimalByValue() {
    cout << "1. Inside function:" << endl;
    Animal animal;
    cout << "2. About to return:" << endl;
    return animal;
}

int main() {
    cout << "Calling function:" << endl;
    Animal cat = createAnimalByValue();
    cout << "Returned from function" << endl;
}

// Output:
// Calling function:
// 1. Inside function:
// Constructor called
// 2. About to return:
// Copy constructor called
// Returned from function
// Destructor called (original destroyed in function)
// Destructor called (copy destroyed at end of main)
```

### Advantages

- **Safe**: No dangling pointers or references
- **Simple**: Straightforward ownership - caller owns the copy
- **Exception safe**: Destructor called automatically
- **No manual cleanup**: Automatic destruction

### Disadvantages

- **Copy overhead**: Entire object copied, inefficient for large objects
- **Performance**: Slower for large or complex objects
- **Memory**: Doubles memory usage temporarily during copy

### When to Use

- Objects are small (primitives, simple classes)
- You want the caller to have an independent copy
- Safety is more important than performance
- Most common return method for simple objects

---

## Return by Reference

### Basic Concept

```cpp
const Animal& getAnimalReference(const Animal& animal) {
    return animal;  // Return reference to parameter
}

int main() {
    Animal cat;
    const Animal& ref = getAnimalReference(cat);  // No copy!
    ref.speak();
}
```

### How References Work

- Reference is an alias to an existing object
- No copy is made
- No copy constructor called
- Direct access to the original object

### DANGER: Returning Reference to Local Object

```cpp
// DO NOT DO THIS!
const Animal& createDangerousReference() {
    Animal animal;  // Local object on stack
    return animal;  // WRONG! Reference to local object
}                   // animal destroyed here!

int main() {
    const Animal& ref = createDangerousReference();
    ref.speak();  // CRASH! Referencing destroyed object
                  // Undefined behavior!
}
```

### Safe Uses of Reference Return

### 1. Return Reference to Parameter

```cpp
const Animal& createAnimalSafe(const Animal& original) {
    // Safe: Just returning the parameter
    return original;  // Original still exists in caller's scope
}

int main() {
    Animal cat;
    const Animal& ref = createAnimalSafe(cat);
    ref.speak();  // Safe! cat still exists
}
```

### 2. Return Reference to Static Object

```cpp
Animal& getStaticAnimal() {
    static Animal animal;  // Persistent, not destroyed
    return animal;
}

int main() {
    Animal& ref = getStaticAnimal();  // Safe! Static persists
    ref.speak();
}
```

### 3. Method Chaining

```cpp
class Builder {
public:
    Builder& setName(string name) {
        this->name = name;
        return *this;  // Return reference for chaining
    }
};

int main() {
    Builder b;
    b.setName("Alice").setName("Bob");  // Chaining works
}
```

### Advantages

- **No copy overhead**: Direct access to object
- **Memory efficient**: No duplication
- **Fast**: Just a reference (address)

### Disadvantages

- **Dangerous**: Risk of dangling references
- **Lifetime issues**: Caller must manage lifetime
- **Limited scope**: Can only return references to existing objects
- **Advanced**: Requires deep understanding

### When to Use

- Advanced technique for experienced programmers
- Method chaining patterns
- Return reference to parameter or static object
- **AVOID** returning reference to local variables!

---

## Return by Pointer (Heap Objects)

### Basic Concept

```cpp
Animal* createAnimalPointer() {
    Animal *pAnimal = new Animal();     // Heap allocation
    pAnimal->setName("Bertie");
    return pAnimal;                     // Return pointer
}                                       // Object persists!

int main() {
    Animal *pFrog = createAnimalPointer();
    pFrog->speak();
    delete pFrog;                       // Caller must delete!
    pFrog = nullptr;
}
```

### What Happens

1. **Object allocated** on heap with `new`
2. **Pointer returned** to caller
3. **Object persists** after function exits
4. **Caller owns** the pointer - must delete it

### Execution Flow

```
createAnimalPointer called
  -> Animal allocated on heap
  -> Constructor called
Return pointer
  -> Memory address returned
Function exits
  -> Object NOT destroyed (on heap, not stack)
Caller receives pointer
  -> Caller owns the memory
  -> Caller responsible for deletion
Caller calls delete
  -> Destructor called
  -> Memory freed
```

### Example

```cpp
Animal* createAnimalPointer() {
    cout << "Creating Animal..." << endl;
    Animal *pAnimal = new Animal();
    pAnimal->setName("Bertie");
    cout << "Returning pointer..." << endl;
    return pAnimal;
}

int main() {
    cout << "Calling function..." << endl;
    Animal *pFrog = createAnimalPointer();

    cout << "Using object:" << endl;
    pFrog->speak();

    cout << "Deleting object:" << endl;
    delete pFrog;
    pFrog = nullptr;

    cout << "Done" << endl;
}

// Output:
// Calling function...
// Creating Animal...
// Returning pointer...
// Using object:
// My name is: Bertie
// Deleting object:
// Destructor called
// Done
```

### Factory Pattern

A common use of returning pointers:

```cpp
Animal* createAnimalFactory(string type, string name) {
    Animal *pAnimal = new Animal();
    pAnimal->setName(name);
    cout << "Factory created " << type << endl;
    return pAnimal;
}

int main() {
    Animal *pDog = createAnimalFactory("Dog", "Buddy");
    Animal *pCat = createAnimalFactory("Cat", "Mittens");

    pDog->speak();
    pCat->speak();

    delete pDog;
    delete pCat;
    pDog = nullptr;
    pCat = nullptr;
}
```

### Advantages

- **No copy overhead**: Efficient for large objects
- **Persistent**: Object lives as long as needed
- **Flexible lifetime**: Caller controls when to delete
- **Factory pattern**: Easy to create various objects

### Disadvantages

- **Manual cleanup**: Caller MUST delete
- **Ownership unclear**: Who owns the pointer?
- **Memory leaks**: Easy to forget delete
- **Dangling pointers**: Risky if pointer used after delete
- **Complex**: More opportunities for errors

### When to Use

- Object must outlive the function
- Object lifetime controlled by caller
- Large objects (copy overhead is significant)
- Factory functions creating various objects
- Returning different object types polymorphically

---

## Comparing All Methods

| Aspect                      | By Value      | By Reference        | By Pointer       |
| --------------------------- | ------------- | ------------------- | ---------------- |
| **Copy Made**               | Yes           | No                  | No               |
| **Copy Constructor Called** | Yes           | No                  | No               |
| **Object Lifetime**         | Until exit    | Must outlive return | Until delete     |
| **Manual Cleanup**          | No            | No                  | Yes, must delete |
| **Safety**                  | Very Safe     | Risky               | Risk of leaks    |
| **Performance**             | Copy overhead | Very fast           | Very fast        |
| **Usage**                   | Most common   | Advanced            | When needed      |

### Quick Decision Guide

```
Does object need to outlive the function?
├─ NO → Return by value (safe, default)
└─ YES → Can return reference to existing?
    ├─ YES (parameter, static) → Return reference (advanced)
    └─ NO → Return pointer to heap (factory pattern)
```

---

## Ownership and Responsibility

### What is Ownership?

**Ownership** = Who is responsible for deleting the object?

### Ownership Transfer

When returning a pointer, the caller assumes ownership:

```cpp
Animal* createAnimal() {
    return new Animal();  // Creator doesn't own result
}

int main() {
    Animal *p = createAnimal();  // Caller owns it
    p->speak();
    delete p;  // Caller must delete
}
```

### Documenting Ownership

Always document in comments:

```cpp
// Creates a new Animal.
// OWNERSHIP: Caller takes ownership and must call delete!
// RETURNS: Pointer to new Animal, or nullptr if creation fails
Animal* createNewAnimal(string name) {
    Animal *p = new Animal();
    p->setName(name);
    return p;  // Ownership transfers to caller
}

// Returns reference to a managed Animal.
// OWNERSHIP: Reference is borrowed, caller does not own
// Returned reference is valid only while the original Animal exists
const Animal& getSharedAnimal(const Animal& animal) {
    return animal;
}
```

### Common Ownership Patterns

**Pattern 1: Caller Owns**

```cpp
Animal *p = createNewAnimal("Buddy");
// ... use p ...
delete p;  // Caller deletes
```

**Pattern 2: Object Owns (container)**

```cpp
vector<Animal> animals;
animals.push_back(Animal("Buddy"));
// Vector owns the objects, deletes automatically
```

**Pattern 3: Shared Ownership (shared_ptr)**

```cpp
shared_ptr<Animal> p1 = make_shared<Animal>("Buddy");
shared_ptr<Animal> p2 = p1;
// Multiple owners, last one deletes
```

---

## Common Mistakes

### Mistake 1: Forgetting to Delete Returned Pointer

```cpp
// WRONG - Memory leak!
Animal *p = createAnimalPointer();
p->speak();
// Forgot delete!
```

**Fix:**

```cpp
Animal *p = createAnimalPointer();
p->speak();
delete p;
p = nullptr;
```

### Mistake 2: Returning Reference to Local

```cpp
// WRONG - Dangling reference!
const Animal& createReference() {
    Animal animal;
    return animal;  // Reference to local!
}
```

**Fix:**

```cpp
const Animal& createReference(const Animal& animal) {
    return animal;  // Reference to parameter (safe)
}
```

### Mistake 3: Overwriting Pointer Without Delete

```cpp
// WRONG - Leak first object!
Animal *p = createAnimalPointer();
p = createAnimalPointer();  // First object leaked!
delete p;
```

**Fix:**

```cpp
Animal *p = createAnimalPointer();
delete p;
p = createAnimalPointer();
delete p;
```

### Mistake 4: Using Dangling Pointer

```cpp
// WRONG - Use-after-delete!
Animal *p = createAnimalPointer();
delete p;
p->speak();  // CRASH! p points to freed memory
```

**Fix:**

```cpp
Animal *p = createAnimalPointer();
delete p;
p = nullptr;
if (p != nullptr) {
    p->speak();  // Safe check
}
```

---

## Best Practices

### 1. Prefer Return by Value

```cpp
// Default choice for simple objects
Animal createCat() {
    return Animal("Whiskers");
}
```

### 2. Document Ownership Clearly

```cpp
// Caller assumes ownership and must delete
Animal* createNewAnimal(string name);

// Borrowed reference, caller does not own
const Animal& getExistingAnimal(const Animal& animal);
```

### 3. Check for Null

```cpp
Animal *p = createAnimalPointer();
if (p != nullptr) {
    p->speak();
    delete p;
}
```

### 4. Never Leak Resources

```cpp
// Good: RAII pattern
{
    Animal *p = createAnimalPointer();
    p->speak();
    delete p;  // Always paired
}
```

### 5. Modern C++: Use Smart Pointers

```cpp
#include <memory>

// Automatic cleanup, no manual delete needed
unique_ptr<Animal> p = make_unique<Animal>("Max");
p->speak();
// Automatic deletion when p goes out of scope!
```

### 6. Consider Return by Const Reference

```cpp
// If object lifetime is guaranteed:
const Animal& getAnimal(const Animal& animal) {
    return animal;
}
```

---

## Modern C++ Approach

### Smart Pointers

C++11 and later provide smart pointers for automatic memory management:

### unique_ptr - Single Owner

```cpp
#include <memory>

unique_ptr<Animal> createAnimalUnique() {
    return make_unique<Animal>("Max");
}

int main() {
    unique_ptr<Animal> p = createAnimalUnique();
    p->speak();
    // Automatic deletion when p goes out of scope
}
```

### shared_ptr - Multiple Owners

```cpp
#include <memory>

shared_ptr<Animal> createAnimalShared() {
    return make_shared<Animal>("Max");
}

int main() {
    shared_ptr<Animal> p1 = createAnimalShared();
    shared_ptr<Animal> p2 = p1;  // Both own it
    // Deleted when last owner destroys it
}
```

### Advantages of Smart Pointers

- **Automatic cleanup**: No manual delete needed
- **Exception safe**: Destructor called even if exception thrown
- **RAII compliant**: Resource Acquisition Is Initialization
- **No leaks**: Impossible to forget delete
- **Modern C++**: Standard approach in new code

---

## Summary

| Method            | When to Use               | Key Point               |
| ----------------- | ------------------------- | ----------------------- |
| **by Value**      | Default, small objects    | Safe, copy overhead     |
| **by Reference**  | Advanced, borrowed access | Fast, risky with locals |
| **by Pointer**    | Object must persist       | Caller must delete      |
| **Smart Pointer** | Modern C++                | Auto-deletes, safest    |

### Golden Rules

1. **Return by value by default** - It's safe and simple
2. **Never return reference to local** - Undefined behavior
3. **If returning pointer, document who owns it** - Prevent leaks
4. **Use smart pointers in modern C++** - Automate cleanup
5. **Always match new with delete** - No leaks!

---

## Next Steps

- Deep dive into **smart pointers** for automatic memory management
- Study **RAII pattern** for resource management
- Learn **exception safety** when managing returned objects
- Explore **modern C++11/14/17** features for object handling
