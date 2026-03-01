//============================================================================
// Lesson 16: Encapsulation - Information Hiding and Access Control
// Author      : M'Barek Benraiss
// Description : Comprehensive guide to encapsulation, access levels,
//               getters/setters, and data protection strategies
//============================================================================

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

// ============================================================================
// SECTION 1: Basic Encapsulation - Private vs Public
// ============================================================================

class BankAccount
{
private:
    string accountHolder;
    double balance;

public:
    BankAccount(string holder, double initialBalance)
        : accountHolder(holder), balance(initialBalance)
    {
        cout << "Account created for " << holder << endl;
    }

    void deposit(double amount)
    {
        if (amount > 0)
        {
            balance += amount;
            cout << "Deposited: EURO" << amount << ", New balance: EURO" << balance << endl;
        }
        else
        {
            cout << "Invalid deposit amount" << endl;
        }
    }

    void withdraw(double amount)
    {
        if (amount > 0 && amount <= balance)
        {
            balance -= amount;
            cout << "Withdrawn: EURO" << amount << ", New balance: EURO" << balance << endl;
        }
        else
        {
            cout << "Invalid withdrawal amount or insufficient balance" << endl;
        }
    }

    double getBalance() const
    {
        return balance;
    }

    string getHolder() const
    {
        return accountHolder;
    }
};

void demonstrateBasicEncapsulation()
{
    cout << "\n--- Basic Encapsulation ---" << endl;

    BankAccount account("John Doe", 1000);
    account.deposit(500);
    account.withdraw(200);
    cout << "Current balance: EURO" << account.getBalance() << endl;

    // These would cause compile errors (good!):
    // account.balance = -5000;      // ERROR: can't access private
    // account.accountHolder = "Bad";  // ERROR: can't modify
}

// ============================================================================
// SECTION 2: Getter and Setter Methods
// ============================================================================

class Student
{
private:
    string name;
    int age;
    double gpa;

public:
    Student(string n, int a, double g) : name(n), age(a), gpa(g) {}

    // Getters - read-only access
    string getName() const
    {
        return name;
    }

    int getAge() const
    {
        return age;
    }

    double getGPA() const
    {
        return gpa;
    }

    // Setters - controlled write access with validation
    void setName(string n)
    {
        if (!n.empty())
        {
            name = n;
        }
    }

    void setAge(int a)
    {
        if (a > 0 && a < 120)
        {
            age = a;
        }
        else
        {
            cout << "Invalid age" << endl;
        }
    }

    void setGPA(double g)
    {
        if (g >= 0.0 && g <= 4.0)
        {
            gpa = g;
        }
        else
        {
            cout << "GPA must be between 0.0 and 4.0" << endl;
        }
    }

    void displayInfo() const
    {
        cout << "Name: " << name << ", Age: " << age << ", GPA: " << gpa << endl;
    }
};

void demonstrateGettersSetters()
{
    cout << "\n--- Getter and Setter Methods ---" << endl;

    Student student("Alice", 20, 3.8);
    student.displayInfo();

    student.setAge(21);
    student.setGPA(3.9);
    student.displayInfo();

    student.setGPA(5.0); // Invalid - will be rejected
    student.displayInfo();
}

// ============================================================================
// SECTION 3: Input Validation in Setters
// ============================================================================

class Temperature
{
private:
    double celsius;

    bool isValidTemperature(double temp)
    {
        // Most practical temperatures are between -273 (absolute zero) and 200 C
        return temp >= -273.15;
    }

public:
    Temperature(double c) : celsius(c) {}

    void setCelsius(double c)
    {
        if (isValidTemperature(c))
        {
            celsius = c;
            cout << "Temperature set to " << c << "°C" << endl;
        }
        else
        {
            cout << "Invalid temperature (below absolute zero)" << endl;
        }
    }

    double getCelsius() const
    {
        return celsius;
    }

    double getFahrenheit() const
    {
        return (celsius * 9.0 / 5.0) + 32.0;
    }

    void displayTemperature() const
    {
        cout << "Temperature: " << celsius << "°C / " << getFahrenheit() << "°F" << endl;
    }
};

void demonstrateValidation()
{
    cout << "\n--- Input Validation in Setters ---" << endl;

    Temperature temp(25);
    temp.displayTemperature();

    temp.setCelsius(100);
    temp.displayTemperature();

    temp.setCelsius(-300); // Invalid - rejected
    temp.displayTemperature();
}

// ============================================================================
// SECTION 4: Const Correctness with Getters
// ============================================================================

class Rectangle
{
private:
    double length;
    double width;

public:
    Rectangle(double l, double w) : length(l), width(w) {}

    double getLength() const
    { // const method - won't modify state
        return length;
    }

    double getWidth() const
    {
        return width;
    }

    double getArea() const
    { // Can call other const methods
        return length * width;
    }

    double getPerimeter() const
    {
        return 2 * (length + width);
    }

    void setDimensions(double l, double w)
    { // Non-const - can modify
        if (l > 0 && w > 0)
        {
            length = l;
            width = w;
        }
    }

    void displayInfo() const
    {
        cout << "Rectangle: " << length << " x " << width
             << ", Area: " << getArea()
             << ", Perimeter: " << getPerimeter() << endl;
    }
};

void demonstrateConstCorrectness()
{
    cout << "\n--- Const Correctness with Getters ---" << endl;

    const Rectangle rect(5, 10);
    cout << "Length: " << rect.getLength() << endl;
    cout << "Area: " << rect.getArea() << endl;
    // rect.setDimensions(6, 11);  // ERROR: can't call non-const method on const object

    Rectangle mutableRect(3, 4);
    mutableRect.setDimensions(6, 8);
    mutableRect.displayInfo();
}

// ============================================================================
// SECTION 5: Read-Only Properties
// ============================================================================

class Book
{
private:
    string title;
    string author;
    int pageCount;
    bool isAvailable;

public:
    Book(string t, string a, int p)
        : title(t), author(a), pageCount(p), isAvailable(true) {}

    // Read-only properties (getters only, no setters)
    string getTitle() const
    {
        return title;
    }

    string getAuthor() const
    {
        return author;
    }

    int getPageCount() const
    {
        return pageCount;
    }

    bool getAvailability() const
    {
        return isAvailable;
    }

    // Methods that control state changes
    void checkOut()
    {
        if (isAvailable)
        {
            isAvailable = false;
            cout << "Book checked out: " << title << endl;
        }
        else
        {
            cout << "Book is not available" << endl;
        }
    }

    void returnBook()
    {
        if (!isAvailable)
        {
            isAvailable = true;
            cout << "Book returned: " << title << endl;
        }
        else
        {
            cout << "Book was not checked out" << endl;
        }
    }
};

void demonstrateReadOnlyProperties()
{
    cout << "\n--- Read-Only Properties ---" << endl;

    Book book("The Hobbit", "J.R.R. Tolkien", 310);
    cout << "Title: " << book.getTitle()
         << ", Author: " << book.getAuthor()
         << ", Available: " << (book.getAvailability() ? "Yes" : "No") << endl;

    book.checkOut();
    cout << "Available: " << (book.getAvailability() ? "Yes" : "No") << endl;

    book.returnBook();
    cout << "Available: " << (book.getAvailability() ? "Yes" : "No") << endl;
}

// ============================================================================
// SECTION 6: Internal Helper Methods (Private Methods)
// ============================================================================

class Password
{
private:
    string password;

    bool isStrongPassword(const string &pwd)
    {
        if (pwd.length() < 8)
            return false;

        bool hasUpper = false, hasLower = false, hasDigit = false;
        for (char c : pwd)
        {
            if (isupper(c))
                hasUpper = true;
            if (islower(c))
                hasLower = true;
            if (isdigit(c))
                hasDigit = true;
        }
        return hasUpper && hasLower && hasDigit;
    }

    string encryptPassword(const string &pwd)
    {
        // Simple example (real encryption would be more complex)
        string encrypted = "";
        for (char c : pwd)
        {
            encrypted += (char)(c + 1); // Caesar cipher
        }
        return encrypted;
    }

public:
    Password() : password("") {}

    bool setPassword(const string &newPassword)
    {
        if (isStrongPassword(newPassword))
        {
            password = encryptPassword(newPassword);
            cout << "Password set successfully" << endl;
            return true;
        }
        else
        {
            cout << "Password must be at least 8 characters with upper, lower, and digit" << endl;
            return false;
        }
    }

    bool verifyPassword(const string &attempt) const
    {
        return encryptPassword(attempt) == password;
    }
};

void demonstratePrivateMethods()
{
    cout << "\n--- Private Helper Methods ---" << endl;

    Password pwd;
    pwd.setPassword("weak");      // Failed
    pwd.setPassword("Strong123"); // Success

    if (pwd.verifyPassword("Strong123"))
    {
        cout << "Password verified!" << endl;
    }
    else
    {
        cout << "Incorrect password" << endl;
    }
}

// ============================================================================
// SECTION 7: Encapsulation with Data Validation
// ============================================================================

class Person
{
private:
    string name;
    int age;
    string email;

    bool isValidEmail(const string &email)
    {
        return email.find('@') != string::npos && email.find('.') != string::npos;
    }

public:
    Person(string n, int a, string e) : name(n), age(a), email(e) {}

    void setName(const string &n)
    {
        if (!n.empty())
        {
            name = n;
        }
    }

    void setAge(int a)
    {
        if (a >= 0 && a <= 150)
        {
            age = a;
        }
    }

    void setEmail(const string &e)
    {
        if (isValidEmail(e))
        {
            email = e;
        }
    }

    string getName() const { return name; }
    int getAge() const { return age; }
    string getEmail() const { return email; }

    void displayInfo() const
    {
        cout << "Name: " << name << ", Age: " << age << ", Email: " << email << endl;
    }
};

void demonstrateDataValidation()
{
    cout << "\n--- Data Validation ---" << endl;

    Person person("Bob", 30, "bob@example.com");
    person.displayInfo();

    person.setName("Robert");
    person.setEmail("robert@newmail.com");
    person.displayInfo();

    person.setAge(200); // Invalid - rejected
    person.displayInfo();
}

// ============================================================================
// SECTION 8: Encapsulation Benefits and Best Practices
// ============================================================================

class Counter
{
private:
    int count;

    void validateCount()
    {
        if (count < 0)
            count = 0;
        if (count > 1000)
            count = 1000;
    }

public:
    Counter() : count(0) {}

    void increment()
    {
        count++;
        validateCount();
    }

    void decrement()
    {
        count--;
        validateCount();
    }

    void reset()
    {
        count = 0;
    }

    int getValue() const
    {
        return count;
    }

    void setValue(int value)
    {
        count = value;
        validateCount();
    }
};

void demonstrateEncapsulationBenefits()
{
    cout << "\n--- Encapsulation Benefits ---" << endl;

    Counter counter;
    cout << "Initial count: " << counter.getValue() << endl;

    for (int i = 0; i < 5; i++)
    {
        counter.increment();
    }
    cout << "After 5 increments: " << counter.getValue() << endl;

    counter.setValue(1500); // Will be clamped to 1000
    cout << "After setting to 1500: " << counter.getValue() << endl;

    cout << "All access controlled and validated internally" << endl;
}

// ============================================================================
// MAIN: Run all demonstrations
// ============================================================================

int main()
{
    cout << "========== C++ Encapsulation Fundamentals ==========" << endl;

    demonstrateBasicEncapsulation();
    demonstrateGettersSetters();
    demonstrateValidation();
    demonstrateConstCorrectness();
    demonstrateReadOnlyProperties();
    demonstratePrivateMethods();
    demonstrateDataValidation();
    demonstrateEncapsulationBenefits();

    cout << "\n========== End of Encapsulation Demonstrations ==========" << endl;

    return 0;
}

/*
/Users/benraiss/CLionProjects/learnCpp/cmake-build-debug/learnCpp
========== C++ Encapsulation Fundamentals ==========

--- Basic Encapsulation ---
Account created for John Doe
Deposited: $500, New balance: $1500
Withdrawn: $200, New balance: $1300
Current balance: $1300

--- Getter and Setter Methods ---
Name: Alice, Age: 20, GPA: 3.8 
Name: Alice, Age: 21, GPA: 3.9
GPA must be between 0.0 and 4.0
Name: Alice, Age: 21, GPA: 3.9

--- Input Validation in Setters ---
Temperature: 25°C / 77°F
Temperature set to 100°C
Temperature: 100°C / 212°F
Invalid temperature (below absolute zero)
Temperature: 100°C / 212°F

--- Const Correctness with Getters ---
Length: 5
Area: 50
Rectangle: 6 x 8, Area: 48, Perimeter: 28

--- Read-Only Properties ---
Title: The Hobbit, Author: J.R.R. Tolkien, Available: Yes
Book checked out: The Hobbit
Available: No
Book returned: The Hobbit
Available: Yes

--- Private Helper Methods ---
Password must be at least 8 characters with upper, lower, and digit
Password set successfully
Incorrect password

--- Data Validation ---
Name: Bob, Age: 30, Email: bob@example.com
Name: Robert, Age: 30, Email: robert@newmail.com
Name: Robert, Age: 30, Email: robert@newmail.com

--- Encapsulation Benefits ---
Initial count: 0
After 5 increments: 5
After setting to 1500: 1000
All access controlled and validated internally

========== End of Encapsulation Demonstrations ==========

Process finished with exit code 0

*/
