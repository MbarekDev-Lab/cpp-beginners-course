//============================================================================
// Lesson 14: Namespaces - Organizing Code and Avoiding Name Collisions
// Author      : M'Barek Benraiss
// Description : Comprehensive guide to C++ namespaces, scope resolution,
//               and organizing large codebases
//============================================================================

#include <iostream>
#include <string>
using namespace std;

// ============================================================================
// SECTION 1: Basic Namespace Declaration
// ============================================================================

// Define a namespace to group related classes and functions
namespace graphics
{

    class Shape
    {
    protected:
        string name;

    public:
        Shape(string n) : name(n) {}
        virtual void draw() const
        {
            cout << "Drawing shape: " << name << endl;
        }
        string getName() const { return name; }
    };

    void printDetails()
    {
        cout << "Graphics namespace  shape utilities" << endl;
    }
}

// Different namespace with potentially same class names
namespace audio
{

    class Shape
    { // Different Shape class in different namespace
    private:
        string soundFile;

    public:
        Shape(string file) : soundFile(file) {}
        void play() const
        {
            cout << "Playing sound: " << soundFile << endl;
        }
    };

    void printDetails()
    {
        cout << "Audio namespace - sound utilities" << endl;
    }
}

// ============================================================================
// SECTION 2: Accessing Namespace Members with Scope Resolution Operator
// ============================================================================

void demonstrateScopeResolution()
{
    cout << "\n--- Scope Resolution (::) ---" << endl;

    // Accessing Shape from graphics namespace using :: operator
    graphics::Shape square("Square");
    square.draw();

    // Accessing Shape from audio namespace
    audio::Shape soundShape("music.wav");
    soundShape.play();

    // Accessing functions from different namespaces
    graphics::printDetails();
    audio::printDetails();
}

// ============================================================================
// SECTION 3: Using Declarations (using namespace)
// ============================================================================

namespace math
{
    const double PI = 3.14159265359;
    const double E = 2.71828182846;

    double circleArea(double radius)
    {
        return PI * radius * radius;
    }

    double sphereVolume(double radius)
    {
        return (4.0 / 3.0) * PI * radius * radius * radius;
    }
}

void demonstrateUsingNamespace()
{
    cout << "\n--- Using Namespace Declaration ---" << endl;

    // Without using namespace - must use scope resolution for each access
    cout << "PI value: " << math::PI << endl;
    cout << "Circle area (r=5): " << math::circleArea(5) << endl;

    // Now use the entire namespace
    using namespace math;

    // After 'using namespace math', can access directly
    cout << "E value: " << E << endl;
    cout << "Sphere volume (r=3): " << sphereVolume(3) << endl;
}

// ============================================================================
// SECTION 4: Using Declarations (using specific members)
// ============================================================================

namespace geometry
{
    struct Point
    {
        double x, y;
        Point(double x = 0, double y = 0) : x(x), y(y) {}
    };

    double distance(const Point &p1, const Point &p2)
    {
        double dx = p1.x - p2.x;
        double dy = p1.y - p2.y;
        return sqrt(dx * dx + dy * dy);
    }
}

void demonstrateUsingDeclaration()
{
    cout << "\n--- Using Declaration (Specific Members) ---" << endl;

    // Import only specific members from a namespace
    using geometry::distance;
    using geometry::Point;

    Point p1(0, 0);
    Point p2(3, 4);

    // Can use Point and distance without geometry:: prefix
    cout << "Distance between points: " << distance(p1, p2) << endl;

    // But other namespace members still require qualification
    // geometry::distance(...) would still work
}

// ============================================================================
// SECTION 5: Nested Namespaces
// ============================================================================

namespace company
{
    namespace engineering
    {
        namespace software
        {
            class Developer
            {
            private:
                string name;
                string language;

            public:
                Developer(string n, string l) : name(n), language(l) {}
                void work() const
                {
                    cout << name << " coding in " << language << endl;
                }
            };
        }

        namespace hardware
        {
            class Engineer
            {
            private:
                string name;
                string specialty;

            public:
                Engineer(string n, string s) : name(n), specialty(s) {}
                void work() const
                {
                    cout << name << " designing " << specialty << endl;
                }
            };
        }
    }

    namespace marketing
    {
        class Manager
        {
        private:
            string name;

        public:
            Manager(string n) : name(n) {}
            void work() const
            {
                cout << name << " managing campaigns" << endl;
            }
        };
    }
}

void demonstrateNestedNamespaces()
{
    cout << "\n--- Nested Namespaces ---" << endl;

    // Access deeply nested namespaces
    company::engineering::software::Developer dev("Alice", "C++");
    dev.work();

    company::engineering::hardware::Engineer eng("Bob", "Circuit Design");
    eng.work();

    company::marketing::Manager mgr("Charlie");
    mgr.work();

    // Using declaration with nested namespace
    using company::engineering::software::Developer;
    Developer dev2("Diana", "Python");
    dev2.work();
}

// ============================================================================
// SECTION 6: Namespace Aliases
// ============================================================================

namespace db = company::engineering; // Alias for longer namespace path

void demonstrateAliases()
{
    cout << "\n--- Namespace Aliases ---" << endl;

    // Using alias instead of full path
    db::software::Developer coder("Eve", "Java");
    coder.work();

    db::hardware::Engineer designer("Frank", "PCB Design");
    designer.work();
}

// ============================================================================
// SECTION 7: Anonymous Namespace (Internal Linkage)
// ============================================================================

namespace
{
    // Functions here have internal linkage - not visible outside this file
    void internalHelper()
    {
        cout << "This is an internal helper function" << endl;
    }

    int internalCounter = 0;
}

void demonstrateAnonymousNamespace()
{
    cout << "\n--- Anonymous Namespace ---" << endl;

    internalHelper();
    internalCounter++;
    cout << "Internal counter: " << internalCounter << endl;
}

// ============================================================================
// SECTION 8: Namespace Best Practices and Real-World Patterns
// ============================================================================

namespace FileIO
{
    class FileReader
    {
    private:
        string filename;

    public:
        FileReader(string f) : filename(f) {}
        void open() const
        {
            cout << "Opening file: " << filename << endl;
        }
        void read() const
        {
            cout << "Reading from: " << filename << endl;
        }
    };
}

namespace DataProcessing
{
    class DataAnalyzer
    {
    private:
        string dataSource;

    public:
        DataAnalyzer(string src) : dataSource(src) {}
        void analyze() const
        {
            cout << "Analyzing data from: " << dataSource << endl;
        }
    };
}

namespace Visualization
{
    class GraphPlotter
    {
    private:
        string outputFormat;

    public:
        GraphPlotter(string fmt) : outputFormat(fmt) {}
        void plot() const
        {
            cout << "Plotting graph in: " << outputFormat << endl;
        }
    };
}

void demonstrateRealWorldPattern()
{
    cout << "\n--- Real-World Pattern (Modular Application) ---" << endl;

    // Demonstrate how namespaces organize large applications
    FileIO::FileReader reader("data.csv");
    reader.open();
    reader.read();

    DataProcessing::DataAnalyzer analyzer("data.csv");
    analyzer.analyze();

    Visualization::GraphPlotter plotter("PNG");
    plotter.plot();

    cout << "All modules organized in separate namespaces!" << endl;
}

// ============================================================================
// MAIN: Run all demonstrations
// ============================================================================

int main()
{
    cout << "========== C++ Namespaces Fundamentals ==========" << endl;

    demonstrateScopeResolution();
    demonstrateUsingNamespace();
    demonstrateUsingDeclaration();
    demonstrateNestedNamespaces();
    demonstrateAliases();
    demonstrateAnonymousNamespace();
    demonstrateRealWorldPattern();

    cout << "\n========== End of Namespace Demonstrations ==========" << endl;

    return 0;
}
