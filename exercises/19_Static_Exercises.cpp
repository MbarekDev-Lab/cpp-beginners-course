//============================================================================
// Lesson 19: Static - Exercises
// Author      : M'Barek Benraiss
// Description : Progressive exercises for understanding static member
//               variables, static methods, and static local variables
//============================================================================

#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

// ============================================================================
// EXERCISE 1: Basic Static Member Variable and Counter
// ============================================================================
/*
EXERCISE 1: Create a simple counter using static
- Each object increments static count in constructor
- Static function returns total count
- Demonstrate shared variable across objects
*/

class IdCard
{
private:
    int id;
    static int cardCount;

public:
    IdCard()
    {
        id = cardCount++;
    }

    int getID() const
    {
        return id;
    }

    static int getTotalCards()
    {
        return cardCount;
    }
};

int IdCard::cardCount = 0;

void exercise1()
{
    cout << "\n--- Exercise 1: Static Counter ---" << endl;

    cout << "Initial card count: " << IdCard::getTotalCards() << endl;

    IdCard card1;
    cout << "Card 1 ID: " << card1.getID() << ", Total: " << IdCard::getTotalCards() << endl;

    IdCard card2;
    cout << "Card 2 ID: " << card2.getID() << ", Total: " << IdCard::getTotalCards() << endl;

    IdCard card3;
    cout << "Card 3 ID: " << card3.getID() << ", Total: " << IdCard::getTotalCards() << endl;

    cout << "SUCCESS: Static variable shared and updated correctly" << endl;
}

// ============================================================================
// EXERCISE 2: Static Member Function Called Without Object
// ============================================================================
/*
EXERCISE 2: Call static function without creating object
- Define static method
- Call through class name (ClassName::methodName)
- Show that no object is needed
*/

class MathHelper
{
public:
    static int add(int a, int b)
    {
        return a + b;
    }

    static int multiply(int a, int b)
    {
        return a * b;
    }

    static void printInfo()
    {
        cout << "Math Helper utility class" << endl;
    }
};

void exercise2()
{
    cout << "\n--- Exercise 2: Static Functions Without Objects ---" << endl;

    cout << "Calling static functions without creating MathHelper object:" << endl;

    cout << "3 + 5 = " << MathHelper::add(3, 5) << endl;
    cout << "3 * 5 = " << MathHelper::multiply(3, 5) << endl;

    MathHelper::printInfo();

    cout << "SUCCESS: Static functions work without objects" << endl;
}

// ============================================================================
// EXERCISE 3: Static Const Member
// ============================================================================
/*
EXERCISE 3: Use static const for class constants
- Define static const in class
- Initialize outside class
- Access without creating object
- Use in calculations
*/

class Rectangle
{
public:
    static const double MIN_WIDTH;
    static const double MAX_WIDTH;

private:
    double width;
    double height;

public:
    Rectangle(double w, double h) : width(w), height(h) {}

    double getArea() const
    {
        return width * height;
    }

    double getPerimeter() const
    {
        return 2 * (width + height);
    }

    static void printConstraints()
    {
        cout << "Width must be between " << MIN_WIDTH
             << " and " << MAX_WIDTH << endl;
    }
};

const double Rectangle::MIN_WIDTH = 1.0;
const double Rectangle::MAX_WIDTH = 1000.0;

void exercise3()
{
    cout << "\n--- Exercise 3: Static Const Members ---" << endl;

    cout << "Class constraints:" << endl;
    Rectangle::printConstraints();

    cout << "\nMin width: " << Rectangle::MIN_WIDTH << endl;
    cout << "Max width: " << Rectangle::MAX_WIDTH << endl;

    Rectangle rect(10, 20);
    cout << "\nRectangle (10 x 20):" << endl;
    cout << "  Area: " << rect.getArea() << endl;
    cout << "  Perimeter: " << rect.getPerimeter() << endl;

    cout << "SUCCESS: Static const provides class-level constants" << endl;
}

// ============================================================================
// EXERCISE 4: Static Local Variables in Function
// ============================================================================
/*
EXERCISE 4: Create static variable inside function
- Declare static int in function
- Call function multiple times
- Show that value persists across calls
*/

int getNextNumber()
{
    static int next = 100;
    return next++;
}

void exercise4()
{
    cout << "\n--- Exercise 4: Static Local Variables ---" << endl;

    cout << "Calling getNextNumber multiple times:" << endl;

    cout << "Call 1: " << getNextNumber() << endl;
    cout << "Call 2: " << getNextNumber() << endl;
    cout << "Call 3: " << getNextNumber() << endl;
    cout << "Call 4: " << getNextNumber() << endl;
    cout << "Call 5: " << getNextNumber() << endl;

    cout << "Note: Number increments across calls (static persists)" << endl;

    cout << "SUCCESS: Static local variables maintain state" << endl;
}

// ============================================================================
// EXERCISE 5: Track All Objects Created
// ============================================================================
/*
EXERCISE 5: Count live objects (increment in constructor, decrement in destructor)
- Constructor increments static counter
- Destructor decrements static counter
- Shows object lifecycle
*/

class Widget
{
private:
    string name;
    static int activeWidgets;

public:
    Widget(string n) : name(n)
    {
        activeWidgets++;
        cout << "Widget '" << name << "' created (Active: " << activeWidgets << ")" << endl;
    }

    ~Widget()
    {
        activeWidgets--;
        cout << "Widget '" << name << "' deleted (Active: " << activeWidgets << ")" << endl;
    }

    static int getActiveCount()
    {
        return activeWidgets;
    }
};

int Widget::activeWidgets = 0;

void exercise5()
{
    cout << "\n--- Exercise 5: Track Objects ---" << endl;

    cout << "Initial active widgets: " << Widget::getActiveCount() << endl;

    {
        cout << "\nCreating widgets in scope:" << endl;
        Widget w1("Red");
        Widget w2("Blue");
        Widget w3("Green");

        cout << "Inside scope - active: " << Widget::getActiveCount() << endl;
    }

    cout << "After scope (destructors called):" << endl;
    cout << "Active widgets: " << Widget::getActiveCount() << endl;

    cout << "SUCCESS: Object lifecycle tracked with static counter" << endl;
}

// ============================================================================
// EXERCISE 6: Private Static Variables and Methods
// ============================================================================
/*
EXERCISE 6: Use private static for internal class state
- Private static variable only class accesses
- Private static function for internal operations
- Public static accessor to read value
*/

class SafeCounter
{
private:
    static int internalCount;

    static void incrementInternal()
    {
        internalCount++;
    }

public:
    SafeCounter()
    {
        incrementInternal();
    }

    static int getCount()
    {
        return internalCount;
    }

    static void reset()
    {
        internalCount = 0;
    }
};

int SafeCounter::internalCount = 0;

void exercise6()
{
    cout << "\n--- Exercise 6: Private Static Members ---" << endl;

    cout << "Creating SafeCounter objects:" << endl;

    SafeCounter c1;
    cout << "After c1: count = " << SafeCounter::getCount() << endl;

    SafeCounter c2;
    cout << "After c2: count = " << SafeCounter::getCount() << endl;

    SafeCounter c3;
    cout << "After c3: count = " << SafeCounter::getCount() << endl;

    cout << "\nResetting counter:" << endl;
    SafeCounter::reset();
    cout << "After reset: count = " << SafeCounter::getCount() << endl;

    cout << "SUCCESS: Private static encapsulates internal state" << endl;
}

// ============================================================================
// EXERCISE 7: Static in Inheritance
// ============================================================================
/*
EXERCISE 7: Show that static members are shared in inheritance
- Base class has static
- Derived classes inherit and share same static
- Derived cannot override static
*/

class Animal
{
public:
    static int totalAnimals;

    static int getTotal()
    {
        return totalAnimals;
    }
};

int Animal::totalAnimals = 0;

class Dog : public Animal
{
public:
    Dog()
    {
        totalAnimals++;
    }
};

class Cat : public Animal
{
public:
    Cat()
    {
        totalAnimals++;
    }
};

void exercise7()
{
    cout << "\n--- Exercise 7: Static in Inheritance ---" << endl;

    cout << "Initial total: " << Animal::getTotal() << endl;

    Dog d1;
    cout << "After Dog: " << Animal::getTotal() << endl;

    Dog d2;
    cout << "After Dog: " << Animal::getTotal() << endl;

    Cat c1;
    cout << "After Cat: " << Animal::getTotal() << endl;

    cout << "\nAll derived classes share same static variable" << endl;

    cout << "SUCCESS: Static inheritance demonstrated" << endl;
}

// ============================================================================
// EXERCISE 8: Static Registry - Vector of All Objects
// ============================================================================
/*
EXERCISE 8: Keep container of all created objects
- Static vector holds pointers to all instances
- Print all objects at end
- Useful for global access to all instances
*/

class Book
{
private:
    string title;
    static vector<Book *> allBooks;

public:
    Book(string t) : title(t)
    {
        allBooks.push_back(this);
    }

    string getTitle() const
    {
        return title;
    }

    static void printAllBooks()
    {
        cout << "Books in Library (" << allBooks.size() << " total):" << endl;
        for (int i = 0; i < allBooks.size(); i++)
        {
            cout << "  " << (i + 1) << ". " << allBooks[i]->getTitle() << endl;
        }
    }
};

vector<Book *> Book::allBooks;

void exercise8()
{
    cout << "\n--- Exercise 8: Static Registry Pattern ---" << endl;

    cout << "Creating books:" << endl;
    Book b1("1984");
    Book b2("The Great Gatsby");
    Book b3("To Kill a Mockingbird");
    Book b4("Pride and Prejudice");

    Book::printAllBooks();

    cout << "SUCCESS: All objects stored in static container" << endl;
}

// ============================================================================
// EXERCISE 9: Static ID Generation
// ============================================================================
/*
EXERCISE 9: Use static to auto-generate unique IDs
- Each object gets unique ID from static counter
- IDs never repeat even for different types
- Practical for databases and systems
*/

class Account
{
private:
    int accountID;
    string owner;
    static int nextID;

public:
    Account(string name) : owner(name)
    {
        accountID = nextID++;
    }

    int getID() const { return accountID; }
    string getOwner() const { return owner; }

    static void printNextID()
    {
        cout << "Next available ID: " << nextID << endl;
    }
};

int Account::nextID = 1001;

void exercise9()
{
    cout << "\n--- Exercise 9: Static ID Generation ---" << endl;

    cout << "Current state: ";
    Account::printNextID();

    cout << "\nCreating accounts:" << endl;
    Account a1("Alice");
    cout << setw(15) << "Alice" << " -> ID: " << a1.getID() << endl;

    Account a2("Bob");
    cout << setw(15) << "Bob" << " -> ID: " << a2.getID() << endl;

    Account a3("Charlie");
    cout << setw(15) << "Charlie" << " -> ID: " << a3.getID() << endl;

    cout << "\nFinal state: ";
    Account::printNextID();

    cout << "SUCCESS: Unique IDs generated automatically" << endl;
}

// ============================================================================
// EXERCISE 10: Static With Multiple Instances Sharing State
// ============================================================================
/*
EXERCISE 10: Multiple objects share non-static work data through static
- Queue of tasks all objects can access
- Objects add/remove from shared queue
- Show coordination through static data
*/

class ThreadPool
{
private:
    int threadID;
    static int taskQueue;

public:
    ThreadPool(int id) : threadID(id) {}

    void addTask(int workLoad)
    {
        taskQueue += workLoad;
        cout << "Thread " << threadID << " added " << workLoad
             << " tasks (Queue: " << taskQueue << ")" << endl;
    }

    void doWork(int workLoad)
    {
        if (taskQueue >= workLoad)
        {
            taskQueue -= workLoad;
            cout << "Thread " << threadID << " processed " << workLoad
                 << " tasks (Queue: " << taskQueue << ")" << endl;
        }
        else
        {
            cout << "Thread " << threadID << " - not enough tasks!" << endl;
        }
    }

    static int getQueueSize()
    {
        return taskQueue;
    }
};

int ThreadPool::taskQueue = 0;

void exercise10()
{
    cout << "\n--- Exercise 10: Shared State Among Objects ---" << endl;

    cout << "Creating thread pool:" << endl;
    ThreadPool t1(1);
    ThreadPool t2(2);
    ThreadPool t3(3);

    cout << "\nAdding tasks:" << endl;
    t1.addTask(10);
    t2.addTask(15);
    t3.addTask(20);

    cout << "\nProcessing work:" << endl;
    t1.doWork(5);
    t2.doWork(8);
    t3.doWork(12);

    cout << "Final queue size: " << ThreadPool::getQueueSize() << endl;

    cout << "SUCCESS: Multiple objects coordinate via static state" << endl;
}

// ============================================================================
// EXERCISE 11: Games using Static Settings
// ============================================================================
/*
EXERCISE 11: Game configuration using static
- Player class uses static difficulty setting
- Change difficulty once, affects all players
- Show global configuration pattern
*/

class GameConfig
{
public:
    static int difficulty;
    static int lives;
    static int score_multiplier;

    static void setDifficulty(int d)
    {
        difficulty = d;
        cout << "Game difficulty set to " << difficulty << endl;
    }

    static void showConfig()
    {
        cout << "Configuration: Difficulty=" << difficulty
             << ", Lives=" << lives
             << ", Multiplier=" << score_multiplier << endl;
    }
};

int GameConfig::difficulty = 1;
int GameConfig::lives = 3;
int GameConfig::score_multiplier = 1;

class Player
{
private:
    string name;
    int score;

public:
    Player(string n) : name(n), score(0) {}

    void addScore(int points)
    {
        score += points * GameConfig::score_multiplier;
        cout << "Player " << name << " scored " << points
             << " (multiplied by " << GameConfig::score_multiplier
             << ")" << endl;
    }

    int getScore() const { return score; }
};

void exercise11()
{
    cout << "\n--- Exercise 11: Static Game Configuration ---" << endl;

    cout << "Initial: ";
    GameConfig::showConfig();

    Player p1("Alice");
    Player p2("Bob");

    cout << "\nNormal difficulty gameplay:" << endl;
    p1.addScore(100);
    p2.addScore(100);

    cout << "\nIncreasing difficulty:" << endl;
    GameConfig::setDifficulty(3);
    GameConfig::score_multiplier = 3;

    cout << "\nHigh difficulty gameplay:" << endl;
    p1.addScore(100);
    p2.addScore(100);

    cout << "\nFinal scores:" << endl;
    cout << "Alice: " << p1.getScore() << endl;
    cout << "Bob: " << p2.getScore() << endl;

    cout << "SUCCESS: Static config changes affect all objects" << endl;
}

// ============================================================================
// EXERCISE 12: Call Counter Using Static Local Variable
// ============================================================================
/*
EXERCISE 12: Count function calls with static local
- Static int inside function tracks calls
- Each call increments
- Useful for profiling and debugging
*/

void processingFunction(int value)
{
    static int callCount = 0;
    callCount++;

    cout << "Call #" << callCount << ": Processing value " << value << endl;
}

void exercise12()
{
    cout << "\n--- Exercise 12: Call Counter ---" << endl;

    cout << "Calling processingFunction multiple times:" << endl;

    processingFunction(10);
    processingFunction(20);
    processingFunction(30);
    processingFunction(40);
    processingFunction(50);

    cout << "\nNote: Each call increments static counter" << endl;

    cout << "SUCCESS: Function calls tracked with static local variable" << endl;
}

// ============================================================================
// EXERCISE 13: Practical - Bank with Static Interest Rate
// ============================================================================
/*
EXERCISE 13: Real-world scenario with static data
- Bank class has static interest rate
- Account objects use shared interest rate
- Change rate once, all accounts affected
- Calculate interest for all accounts
*/

class Bank
{
public:
    static double interestRate;

    static void setInterestRate(double rate)
    {
        interestRate = rate;
        cout << "Interest rate changed to " << (interestRate * 100) << "%" << endl;
    }
};

double Bank::interestRate = 0.02; // 2%

class BankAccount
{
private:
    string accountName;
    double balance;

public:
    BankAccount(string name, double initial)
        : accountName(name), balance(initial) {}

    void applyInterest()
    {
        double interest = balance * Bank::interestRate;
        balance += interest;
        cout << accountName << ": " << interest
             << " interest added (new balance: $" << balance << ")" << endl;
    }

    double getBalance() const
    {
        return balance;
    }

    string getName() const
    {
        return accountName;
    }
};

void exercise13()
{
    cout << "\n--- Exercise 13: Practical Bank System ---" << endl;

    cout << "Creating accounts with " << (Bank::interestRate * 100) << "% interest:" << endl;
    BankAccount acc1("Alice", 1000);
    BankAccount acc2("Bob", 2000);
    BankAccount acc3("Charlie", 1500);

    cout << "\nApplying interest:" << endl;
    acc1.applyInterest();
    acc2.applyInterest();
    acc3.applyInterest();

    cout << "\nChanging interest rate to 3%:" << endl;
    Bank::setInterestRate(0.03);

    cout << "\nApplying new interest:" << endl;
    acc1.applyInterest();
    acc2.applyInterest();
    acc3.applyInterest();

    cout << "\nFinal balances:" << endl;
    cout << acc1.getName() << ": $" << acc1.getBalance() << endl;
    cout << acc2.getName() << ": $" << acc2.getBalance() << endl;
    cout << acc3.getName() << ": $" << acc3.getBalance() << endl;

    cout << "SUCCESS: Static interest rate affects all accounts" << endl;
}

// ============================================================================
// MAIN
// ============================================================================

int main()
{
    cout << "========== Static Variables and Methods Exercises ==========" << endl;

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
