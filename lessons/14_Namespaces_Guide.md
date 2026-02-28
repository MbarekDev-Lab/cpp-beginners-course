# Lesson 14: Namespaces - Organizing Code and Avoiding Name Collisions

## Overview

Namespaces are a mechanism to organize code and avoid naming conflicts in C++. They provide a scope for identifiers (classes, functions, variables) and allow you to group related code together. As programs grow larger, namespaces become essential for maintaining code organization and preventing name collisions.

## Core Concepts

### What is a Namespace?

A namespace is a declarative region that provides a scope to the identifiers (names) inside it. Think of it as a container that groups related functionality together.

```cpp
namespace MyNamespace {
    class MyClass { };
    void myFunction() { }
    int myVariable = 0;
}
```

### Why Use Namespaces?

1. **Prevent Name Collisions**: Two libraries can define a `Shape` class without conflict
2. **Organize Code**: Group related functionality together logically
3. **Improve Readability**: Clear module boundaries and relationships
4. **Manage Scope**: Control visibility and accessibility of identifiers

## Basic Namespace Declaration

### Simple Namespace

```cpp
namespace graphics {
    class Shape {
    public:
        void draw() { cout << "Drawing shape" << endl; }
    };

    void printInfo() { cout << "Graphics module" << endl; }
}
```

### Accessing Namespace Members

You must use the scope resolution operator `::` to access members:

```cpp
graphics::Shape shape;
shape.draw();

graphics::printInfo();
```

## Scope Resolution Operator (::)

The `::` operator (scope resolution) allows you to access namespace members without importing the entire namespace.

| Pattern               | Usage                       | Example           |
| --------------------- | --------------------------- | ----------------- |
| `namespace::member`   | Access any namespace member | `std::cout << x;` |
| `::global`            | Access global scope         | `::globalVar`     |
| `Class::staticMember` | Access static members       | `Math::PI`        |
| `Class::method`       | Access methods              | `obj.method()`    |

### Fully Qualified Names

```cpp
int value = foo::bar::baz::getValue();  // Fully qualified path
```

## Using Declarations and Directives

### Using Namespace Directive

`using namespace xyz;` imports all members of a namespace into the current scope.

```cpp
// Before: must use full qualification
cout << math::PI << endl;
cout << math::circleArea(5) << endl;

// Import entire namespace
using namespace math;

// Now can use directly (names are imported into current scope)
cout << PI << endl;
cout << circleArea(5) << endl;
```

**Important**: Using `using namespace std;` in global scope is common in small programs, but in large projects it can cause name collisions. Best practice: used in limited scopes or prefer explicit naming.

### Using Declaration (Specific Members)

Import only specific members - safer than `using namespace`:

```cpp
using std::cout;      // Import specific function
using std::endl;      // Import specific manipulator
using math::PI;       // Import specific constant

// Now can use without qualification
cout << PI << endl;

// But other namespace members still require qualification
cout << math::circleArea(5) << endl;
```

## Nested Namespaces

Namespaces can contain other namespaces for hierarchical organization:

```cpp
namespace company {
    namespace engineering {
        namespace software {
            class Developer { };
        }
        namespace hardware {
            class Engineer { };
        }
    }
}

// Access deeply nested members
company::engineering::software::Developer dev;
company::engineering::hardware::Engineer eng;
```

### Namespace Aliases

Create convenient aliases for long nested namespace paths:

```cpp
// Define an alias
namespace cb = company::engineering::hardware;

// Use the shorter alias
cb::Engineer engineer;
```

## Anonymous Namespaces

Anonymous namespaces provide internal linkage (file-scope symbols). Members are not accessible outside the file:

```cpp
namespace {
    void helperFunction() { }      // Only visible in this file
    int internalCounter = 0;       // Only visible in this file

    class PrivateClass { };        // Only visible in this file
}
```

This is equivalent to the old `static` keyword approach for file-scope symbols. Internally, the compiler creates a unique namespace name for each anonymous namespace.

## Practical Comparison: Namespace vs. Global Scope

### Without Namespaces (Name Collision)

```cpp
class Shape { };           // Graphics shape
class Shape { };           // ERROR: redefinition!
```

### With Namespaces (No Collision)

```cpp
namespace graphics {
    class Shape { };       // Graphics shape
}

namespace audio {
    class Shape { };       // Audio shape (no conflict!)
}

graphics::Shape g_shape;
audio::Shape a_shape;
```

## Real-World Organization Pattern

Namespaces are excellent for organizing large applications:

```cpp
namespace MyApp {
    namespace FileIO {
        class Reader { };
        class Writer { };
    }

    namespace DataProcessing {
        class Analyzer { };
        class Validator { };
    }

    namespace UI {
        class Window { };
        class Button { };
    }
}

// Usage
MyApp::FileIO::Reader reader;
MyApp::DataProcessing::Analyzer analyzer;
MyApp::UI::Window window;
```

## Common Namespace Patterns

### Pattern 1: Module Organization

```cpp
namespace database {
    // Database connection functions
    // Database query functions
}

namespace security {
    // Authentication functions
    // Encryption functions
}
```

### Pattern 2: Version Management

```cpp
namespace LibraryV1 {
    class OldAPI { };
}

namespace LibraryV2 {
    class NewAPI { };
}
```

### Pattern 3: Third-Party Code

```cpp
namespace external {
    namespace vendor1 {
        class Tool { };
    }

    namespace vendor2 {
        class Utility { };
    }
}
```

## Best Practices

1. **Avoid `using namespace` in Header Files**

   ```cpp
   // header.h
   namespace::Type myFunction();  // OK - explicit

   using namespace std;           // BAD - affects all includers
   ```

2. **Keep Namespaces Focused**
   - One logical module per namespace
   - Don't create excessive nesting (2-3 levels usually sufficient)

3. **Use Meaningful Names**

   ```cpp
   namespace math { }           // Clear
   namespace m { }              // Unclear
   ```

4. **Consistent Naming Convention**
   - All lowercase or PascalCase consistently
   - Match your project's style guide

5. **Prefer Using Declarations Over Directives**

   ```cpp
   using std::cout;             // Specific, safe
   using namespace std;         // Global, risky
   ```

6. **Document Namespace Organization**
   ```cpp
   // Explain what each namespace contains
   // List exported public interfaces
   ```

## Common Mistakes to Avoid

### Mistake 1: Creating Conflicts with Using Directives

```cpp
using namespace std;
using namespace mylib;

vector<int> v;  // ERROR: which vector? std::vector or mylib::vector?
```

**Solution**: Use explicit qualification or specific `using` declarations.

### Mistake 2: Excessive Nesting

```cpp
app::module::submodule::nested::deep::Class obj;  // Too deep!
```

**Solution**: Keep nesting to 2-3 levels maximum.

### Mistake 3: Forgetting Scope Resolution

```cpp
namespace graphics {
    class Shape { };
}

Shape s;  // ERROR: Shape not found (must use graphics::Shape)
```

**Solution**: Always use `::` when accessing namespace members, or use `using declaration`.

### Mistake 4: Mixing Global and Namespace Classes

```cpp
class Animal { };  // Global

namespace zoo {
    class Animal { };  // Same name in namespace
}

Animal a1;          // Which Animal?
zoo::Animal a2;    // Clear
```

**Solution**: Keep one logical entity in one namespace.

## Namespace vs. Class - Which to Use?

| Feature       | Namespace                 | Class                            |
| ------------- | ------------------------- | -------------------------------- |
| Purpose       | Group related code        | Model object with state/behavior |
| Data          | Usually constants/globals | Instance data                    |
| Functions     | Free functions            | Member functions                 |
| Encapsulation | Files/includes            | Private/public/protected         |
| Inheritance   | No                        | Yes                              |

Use **namespaces** for module organization. Use **classes** for data abstraction and object modeling.

## Modern C++ Considerations

### C++17+ Inline Namespace

```cpp
namespace llvm {
    inline namespace v10 {
        class API { };
    }
}

llvm::API api;          // Accessible (inline namespace)
llvm::v10::API api;     // Also accessible
```

### std Namespace

The C++ Standard Library uses the `std` namespace extensively:

```cpp
std::cout      // Output stream
std::string    // String class
std::vector    // Dynamic array
std::map       // Key-value map
std::unique_ptr  // Smart pointer
```

## Summary

- **Namespaces** organize code and prevent naming conflicts
- **Scope resolution** (`::`): Access namespace members
- **Using directives**: Import entire namespace (`using namespace std;`)
- **Using declarations**: Import specific members (`using std::cout;`)
- **Nested namespaces**: Organize hierarchically for large projects
- **Anonymous namespaces**: Create file-scope symbols with internal linkage
- **Best practice**: Use explicit qualification in headers, `using` declarations in implementations

Namespaces are fundamental to professional C++ development and are used extensively in the standard library and modern frameworks.
