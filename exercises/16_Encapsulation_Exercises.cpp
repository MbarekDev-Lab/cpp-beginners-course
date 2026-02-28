//============================================================================
// Lesson 16: Encapsulation - Exercises
// Author      : M'Barek Benraiss
// Description : Progressive exercises for understanding encapsulation,
//               access control, getters/setters, and data validation
//============================================================================

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

// ============================================================================
// EXERCISE 1: Basic Private and Public Members
// ============================================================================
/*
EXERCISE 1: Create a class with private and public members
- Create "Dog" class with private members (name, breed)
- Create public method getInfo() that displays info
- Outside code cannot directly access private members
- Verify error when trying to access private data directly

Solution provided below
*/

class Dog
{
private:
    string name;
    string breed;

public:
    Dog(string n, string b) : name(n), breed(b) {}

    void getInfo() const
    {
        cout << "Dog: " << name << ", Breed: " << breed << endl;
    }
};

void exercise1()
{
    cout << "\n--- Exercise 1: Private and Public Members ---" << endl;
    Dog dog("Buddy", "Golden Retriever");
    dog.getInfo();

    // This would cause error:
    // dog.name = "Spot";  // ERROR: private member

    cout << "SUCCESS: Private members protected from direct access" << endl;
}

// ============================================================================
// EXERCISE 2: Getters and Setters
// ============================================================================
/*
EXERCISE 2: Implement getters and setters
- Create "Person" class with private name and age
- Implement getName(), getAge(), setName(), setAge()
- Demonstrate getting and setting values through methods

Solution provided below
*/

class Person
{
private:
    string name;
    int age;

public:
    Person(string n, int a) : name(n), age(a) {}

    string getName() const
    {
        return name;
    }

    int getAge() const
    {
        return age;
    }

    void setName(string n)
    {
        if (!n.empty())
        {
            name = n;
        }
    }

    void setAge(int a)
    {
        if (a > 0 && a < 150)
        {
            age = a;
        }
    }
};

void exercise2()
{
    cout << "\n--- Exercise 2: Getters and Setters ---" << endl;
    Person person("Alice", 30);
    cout << "Name: " << person.getName() << ", Age: " << person.getAge() << endl;

    person.setName("Alicia");
    person.setAge(31);
    cout << "Name: " << person.getName() << ", Age: " << person.getAge() << endl;

    cout << "SUCCESS: Data accessed and modified through methods" << endl;
}

// ============================================================================
// EXERCISE 3: Input Validation in Setters
// ============================================================================
/*
EXERCISE 3: Add validation to setters
- Create "BankAccount" class with private balance
- deposit() and withdraw() validate before modifying balance
- Show that invalid operations are rejected

Solution provided below
*/

class BankAccount
{
private:
    double balance;

public:
    BankAccount(double initial) : balance(initial) {}

    bool deposit(double amount)
    {
        if (amount > 0)
        {
            balance += amount;
            return true;
        }
        return false;
    }

    bool withdraw(double amount)
    {
        if (amount > 0 && amount <= balance)
        {
            balance -= amount;
            return true;
        }
        return false;
    }

    double getBalance() const
    {
        return balance;
    }
};

void exercise3()
{
    cout << "\n--- Exercise 3: Input Validation ---" << endl;
    BankAccount account(1000);
    cout << "Initial balance: $" << account.getBalance() << endl;

    if (account.deposit(500))
    {
        cout << "Deposit successful, new balance: $" << account.getBalance() << endl;
    }

    if (!account.withdraw(2000))
    {
        cout << "Withdrawal failed (insufficient funds)" << endl;
    }

    if (account.withdraw(400))
    {
        cout << "Withdrawal successful, new balance: $" << account.getBalance() << endl;
    }

    cout << "SUCCESS: Validation prevents invalid operations" << endl;
}

// ============================================================================
// EXERCISE 4: Read-Only Properties (Getter Only)
// ============================================================================
/*
EXERCISE 4: Create read-only properties
- Create "Book" class with private title and author
- Provide getters but NO setters (read-only)
- Verify that these values can be read but not changed

Solution provided below
*/

class Book
{
private:
    string title;
    string author;
    int yearPublished;

public:
    Book(string t, string a, int y) : title(t), author(a), yearPublished(y) {}

    string getTitle() const
    {
        return title;
    }

    string getAuthor() const
    {
        return author;
    }

    int getYearPublished() const
    {
        return yearPublished;
    }

    void displayInfo() const
    {
        cout << "Title: " << title << ", Author: " << author
             << ", Year: " << yearPublished << endl;
    }
};

void exercise4()
{
    cout << "\n--- Exercise 4: Read-Only Properties ---" << endl;
    Book book("The Hobbit", "J.R.R. Tolkien", 1937);
    book.displayInfo();

    cout << "Title: " << book.getTitle() << endl;
    // book.setTitle("New Title");  // ERROR: no setter exists

    cout << "SUCCESS: Read-only properties prevent modification" << endl;
}

// ============================================================================
// EXERCISE 5: Const Correctness with Getters
// ============================================================================
/*
EXERCISE 5: Mark getters as const
- Create "Temperature" class with private celsius
- Getters marked const
- Show that getters can be called on const objects
- Non-const methods cannot

Solution provided below
*/

class Temperature
{
private:
    double celsius;

public:
    Temperature(double c) : celsius(c) {}

    double getCelsius() const
    { // const method
        return celsius;
    }

    double getFahrenheit() const
    {
        return (celsius * 9.0 / 5.0) + 32.0;
    }

    void setCelsius(double c)
    { // Non-const method
        celsius = c;
    }

    void displayInfo() const
    {
        cout << "Temperature: " << getCelsius() << "C / " << getFahrenheit() << "F" << endl;
    }
};

void exercise5()
{
    cout << "\n--- Exercise 5: Const Correctness ---" << endl;

    const Temperature temp(25);
    cout << "Celsius: " << temp.getCelsius() << endl; // OK - const method
    cout << "Fahrenheit: " << temp.getFahrenheit() << endl;
    temp.displayInfo();

    // temp.setCelsius(30);  // ERROR: can't call non-const on const object

    Temperature mutableTemp(20);
    mutableTemp.setCelsius(30);
    cout << "New temperature: " << mutableTemp.getCelsius() << "C" << endl;

    cout << "SUCCESS: Const methods enforce immutability" << endl;
}

// ============================================================================
// EXERCISE 6: Email Validation with Setters
// ============================================================================
/*
EXERCISE 6: Complex validation in setter
- Create "Email" class with private email string
- Validation: must contain @ and .
- Implement getEmail() and setEmail()
- Show invalid emails being rejected

Solution provided below
*/

class Email
{
private:
    string email;

    bool isValidEmail(const string &e)
    {
        size_t atPos = e.find('@');
        size_t dotPos = e.find('.');

        return atPos != string::npos && dotPos != string::npos &&
               atPos < dotPos && atPos > 0 && dotPos < e.length() - 1;
    }

public:
    Email(string e) : email(e) {}

    bool setEmail(const string &e)
    {
        if (isValidEmail(e))
        {
            email = e;
            cout << "Email set successfully" << endl;
            return true;
        }
        else
        {
            cout << "Invalid email format" << endl;
            return false;
        }
    }

    string getEmail() const
    {
        return email;
    }
};

void exercise6()
{
    cout << "\n--- Exercise 6: Email Validation ---" << endl;
    Email emailObj("user@example.com");
    cout << "Email: " << emailObj.getEmail() << endl;

    emailObj.setEmail("invalid.email");      // Failed
    emailObj.setEmail("newuser@domain.com"); // Success
    cout << "Email: " << emailObj.getEmail() << endl;

    cout << "SUCCESS: Complex validation enforced in setter" << endl;
}

// ============================================================================
// EXERCISE 7: Private Helper Methods
// ============================================================================
/*
EXERCISE 7: Use private methods for internal logic
- Create "Password" class
- Private method validatePassword()
- Public method setPassword() uses internal validation
- Private method encryptPassword()
- Show that password strength is validated

Solution provided below
*/

class Password
{
private:
    string password;

    bool isStrongPassword(const string &pwd)
    {
        return pwd.length() >= 6;
    }

    string hashPassword(const string &pwd)
    {
        // Simplified hashing
        return string((pwd.length() * 2), '*');
    }

public:
    Password() : password("") {}

    bool setPassword(const string &newPwd)
    {
        if (isStrongPassword(newPwd))
        {
            password = hashPassword(newPwd);
            cout << "Password set: " << password << endl;
            return true;
        }
        else
        {
            cout << "Password too weak (min 6 characters)" << endl;
            return false;
        }
    }

    bool verifyPassword(const string &attempt)
    {
        return hashPassword(attempt) == password;
    }
};

void exercise7()
{
    cout << "\n--- Exercise 7: Private Helper Methods ---" << endl;
    Password pwd;

    pwd.setPassword("weak");      // Failed
    pwd.setPassword("secure123"); // Success

    if (pwd.verifyPassword("secure123"))
    {
        cout << "Password verified!" << endl;
    }

    cout << "SUCCESS: Private methods support public interface" << endl;
}

// ============================================================================
// EXERCISE 8: Circle Class with Validation
// ============================================================================
/*
EXERCISE 8: Implement numeric validation
- Create "Circle" class with private radius
- Getter for radius
- Setter validates radius > 0
- Calculate area, circumference, diameter

Solution provided below
*/

class Circle
{
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    bool setRadius(double r)
    {
        if (r > 0)
        {
            radius = r;
            return true;
        }
        return false;
    }

    double getRadius() const
    {
        return radius;
    }

    double getArea() const
    {
        return 3.14159 * radius * radius;
    }

    double getCircumference() const
    {
        return 2 * 3.14159 * radius;
    }

    double getDiameter() const
    {
        return 2 * radius;
    }
};

void exercise8()
{
    cout << "\n--- Exercise 8: Circle with Calculation ---" << endl;
    Circle circle(5);
    cout << "Radius: " << circle.getRadius()
         << ", Area: " << circle.getArea()
         << ", Circumference: " << circle.getCircumference() << endl;

    circle.setRadius(7);
    cout << "New radius: " << circle.getRadius()
         << ", New area: " << circle.getArea() << endl;

    circle.setRadius(-3); // Failed
    cout << "Radius unchanged: " << circle.getRadius() << endl;

    cout << "SUCCESS: Validation and calculations work correctly" << endl;
}

// ============================================================================
// EXERCISE 9: Student Grade Management with Validation
// ============================================================================
/*
EXERCISE 9: Multiple private members with related validation
- Create "Student" class with name, ID, GPA
- Getters for all
- Setters with validation (GPA 0-4, ID > 0)
- Method to addGrade() that updates GPA

Solution provided below
*/

class Student
{
private:
    string name;
    int studentID;
    double gpa;
    int gradeCount;

public:
    Student(string n, int id) : name(n), studentID(id), gpa(0), gradeCount(0) {}

    string getName() const { return name; }
    int getID() const { return studentID; }
    double getGPA() const { return gpa; }

    bool setGPA(double g)
    {
        if (g >= 0.0 && g <= 4.0)
        {
            gpa = g;
            return true;
        }
        return false;
    }

    void displayInfo() const
    {
        cout << "Student: " << name << ", ID: " << studentID
             << ", GPA: " << gpa << endl;
    }
};

void exercise9()
{
    cout << "\n--- Exercise 9: Student with Validation ---" << endl;
    Student student("Bob", 12345);
    student.displayInfo();

    student.setGPA(3.8);
    student.displayInfo();

    student.setGPA(5.0); // Invalid
    student.displayInfo();

    cout << "SUCCESS: Multiple members with validation" << endl;
}

// ============================================================================
// EXERCISE 10: Counter with Range Limits
// ============================================================================
/*
EXERCISE 10: Encapsulation with state enforcement
- Create "Counter" class with private count
- Methods: increment(), decrement(), reset()
- Limit count between 0 and 100
- Getter for current value

Solution provided below
*/

class Counter
{
private:
    int count;
    static const int MIN_VALUE = 0;
    static const int MAX_VALUE = 100;

public:
    Counter() : count(0) {}

    void increment()
    {
        if (count < MAX_VALUE)
        {
            count++;
        }
    }

    void decrement()
    {
        if (count > MIN_VALUE)
        {
            count--;
        }
    }

    void reset()
    {
        count = 0;
    }

    int getValue() const
    {
        return count;
    }
};

void exercise10()
{
    cout << "\n--- Exercise 10: Counter with Limits ---" << endl;
    Counter counter;
    cout << "Initial: " << counter.getValue() << endl;

    for (int i = 0; i < 105; i++)
    {
        counter.increment();
    }
    cout << "After 105 increments: " << counter.getValue() << endl;

    counter.reset();
    cout << "After reset: " << counter.getValue() << endl;

    cout << "SUCCESS: Boundaries enforced automatically" << endl;
}

// ============================================================================
// EXERCISE 11: Array Wrapper with Bounds Checking
// ============================================================================
/*
EXERCISE 11: Encapsulation of collection with safety
- Create "IntArray" class with private vector
- Provide getElement(index), setElement(index, value) with bounds checking
- getSize() returns current size
- Cannot access raw internal vector

Solution provided below
*/

class IntArray
{
private:
    vector<int> data;

    bool isValidIndex(int index) const
    {
        return index >= 0 && index < (int)data.size();
    }

public:
    IntArray(int size) : data(size, 0) {}

    bool setElement(int index, int value)
    {
        if (isValidIndex(index))
        {
            data[index] = value;
            return true;
        }
        return false;
    }

    int getElement(int index) const
    {
        if (isValidIndex(index))
        {
            return data[index];
        }
        return -1; // Error value
    }

    int getSize() const
    {
        return data.size();
    }
};

void exercise11()
{
    cout << "\n--- Exercise 11: Safe Array Wrapper ---" << endl;
    IntArray arr(5);

    arr.setElement(0, 10);
    arr.setElement(2, 20);
    arr.setElement(4, 30);

    cout << "Element at 2: " << arr.getElement(2) << endl;
    cout << "Array size: " << arr.getSize() << endl;

    if (!arr.setElement(10, 99))
    {
        cout << "Out of bounds access prevented" << endl;
    }

    cout << "SUCCESS: Array bounds safety enforced" << endl;
}

// ============================================================================
// EXERCISE 12: Complete Encapsulated Class - User Account
// ============================================================================
/*
EXERCISE 12: Real-world encapsulation pattern
- Create "UserAccount" class
- Private: username, password, email, accountActive
- Public interface: login, logout, changePassword, updateEmail
- All with proper validation and state management

Solution provided below
*/

class UserAccount
{
private:
    string username;
    string password;
    string email;
    bool isActive;

    bool isValidPassword(const string &pwd)
    {
        return pwd.length() >= 6;
    }

    bool isValidEmail(const string &e)
    {
        return e.find('@') != string::npos;
    }

public:
    UserAccount(string user, string pwd, string mail)
        : username(user), password(pwd), email(mail), isActive(false) {}

    bool login(const string &pwd)
    {
        if (password == pwd)
        {
            isActive = true;
            cout << "Login successful" << endl;
            return true;
        }
        cout << "Login failed" << endl;
        return false;
    }

    void logout()
    {
        isActive = false;
        cout << "Logged out" << endl;
    }

    bool changePassword(const string &oldPwd, const string &newPwd)
    {
        if (password != oldPwd)
        {
            cout << "Incorrect current password" << endl;
            return false;
        }
        if (!isValidPassword(newPwd))
        {
            cout << "New password too weak" << endl;
            return false;
        }
        password = newPwd;
        cout << "Password changed successfully" << endl;
        return true;
    }

    bool updateEmail(const string &newEmail)
    {
        if (isValidEmail(newEmail))
        {
            email = newEmail;
            return true;
        }
        return false;
    }

    string getUsername() const { return username; }
    bool getIsActive() const { return isActive; }
};

void exercise12()
{
    cout << "\n--- Exercise 12: Complete User Account ---" << endl;
    UserAccount account("john", "password123", "john@example.com");

    account.login("wrongpwd");
    account.login("password123");

    account.changePassword("password123", "newpass456");
    account.updateEmail("john.doe@example.com");

    account.logout();

    cout << "SUCCESS: Complete encapsulated system working" << endl;
}

// ============================================================================
// EXERCISE 13: Library Book with Complex State
// ============================================================================
/*
EXERCISE 13: Encapsulation with multiple related states
- Create "LibraryBook" class
- Private: title, author, ISBN, available, checkedOutBy, dueDate
- Methods: checkOut(), returnBook(), renew()
- Show state consistency maintained

Solution provided below
*/

class LibraryBook
{
private:
    string title;
    string author;
    string isbn;
    bool available;
    string checkedOutBy;

public:
    LibraryBook(string t, string a, string isbn)
        : title(t), author(a), isbn(isbn), available(true), checkedOutBy("") {}

    bool checkOut(const string &borrower)
    {
        if (!available)
        {
            cout << "Book not available (checked out by " << checkedOutBy << ")" << endl;
            return false;
        }
        available = false;
        checkedOutBy = borrower;
        cout << "Book checked out to " << borrower << endl;
        return true;
    }

    bool returnBook()
    {
        if (!available)
        {
            available = true;
            checkedOutBy = "";
            cout << "Book returned successfully" << endl;
            return true;
        }
        cout << "Book was not checked out" << endl;
        return false;
    }

    void displayStatus() const
    {
        cout << "Title: " << title << ", Available: " << (available ? "Yes" : "No");
        if (!available)
            cout << " (by " << checkedOutBy << ")";
        cout << endl;
    }
};

void exercise13()
{
    cout << "\n--- Exercise 13: Library Book Management ---" << endl;
    LibraryBook book("1984", "George Orwell", "978-0451524935");

    book.displayStatus();
    book.checkOut("Alice");
    book.displayStatus();
    book.checkOut("Bob"); // Fails
    book.returnBook();
    book.displayStatus();

    cout << "SUCCESS: System state consistency maintained" << endl;
}

// ============================================================================
// MAIN: Execute all exercises
// ============================================================================

int main()
{
    cout << "========== C++ Encapsulation Exercises ==========" << endl;

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
