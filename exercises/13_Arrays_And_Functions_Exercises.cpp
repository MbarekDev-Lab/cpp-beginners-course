//============================================================================
// LESSON 13 EXERCISES: Arrays and Functions
// Author      : M'Barek Benraiss
// Description : Practice passing arrays to functions, understanding array
//               decay, and working with practical array manipulation patterns.
//
// INSTRUCTIONS:
// - Solve each exercise by writing/completing code
// - Pay attention to array decay and size parameters
// - Test with different array sizes
// - Verify that modifications affect original arrays
//============================================================================

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

//============================================================================
// EXERCISE 1: Basic Array Printing
//
// Create a function that:
// 1. Takes int array and size as parameters
// 2. Prints all elements in format: "10 20 30 40 50"
// 3. Call from main with different arrays
//
// HINT: Function signature: void printArray(int arr[], int size)
//       Use a for loop with size parameter
//============================================================================

void printArray(int arr[], int size) {
    // TODO: Print all elements with spaces
    for (int i = 0; i < size; i++) {
        cout << arr[i];
        if (i < size - 1) cout << " ";
    }
    cout << endl;
}

void exercise_1() {
    cout << "\n=== EXERCISE 1: Basic Array Printing ===" << endl;
    
    int arr1[5] = {10, 20, 30, 40, 50};
    int arr2[3] = {1, 2, 3};
    
    cout << "Array 1: ";
    printArray(arr1, 5);
    
    cout << "Array 2: ";
    printArray(arr2, 3);
}

//============================================================================
// EXERCISE 2: Array Summation
//
// Create a function that:
// 1. Takes int array and size
// 2. Calculates and returns the sum of all elements
// 3. Test with multiple arrays
//
// HINT: Return type: int
//       Initialize sum to 0, add each element
//============================================================================

int sumArray(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

void exercise_2() {
    cout << "\n=== EXERCISE 2: Array Summation ===" << endl;
    
    int arr1[4] = {5, 10, 15, 20};
    int arr2[5] = {1, 2, 3, 4, 5};
    
    cout << "Sum of arr1: " << sumArray(arr1, 4) << endl;
    cout << "Sum of arr2: " << sumArray(arr2, 5) << endl;
}

//============================================================================
// EXERCISE 3: Array Modification
//
// Create a function that:
// 1. Takes int array and size
// 2. Multiplies each element by a given factor
// 3. Demonstrate that original array is modified
// 4. Print before and after
//
// HINT: Original array WILL be modified (array decay)
//       Use printArray from exercise 1
//============================================================================

void multiplyBy(int arr[], int size, int factor) {
    for (int i = 0; i < size; i++) {
        arr[i] *= factor;
    }
}

void exercise_3() {
    cout << "\n=== EXERCISE 3: Array Modification ===" << endl;
    
    int numbers[4] = {2, 4, 6, 8};
    
    cout << "Before: ";
    printArray(numbers, 4);
    
    multiplyBy(numbers, 4, 3);
    
    cout << "After:  ";
    printArray(numbers, 4);
}

//============================================================================
// EXERCISE 4: Finding Values
//
// Create a function that:
// 1. Takes int array, size, and target value
// 2. Returns the index if found, -1 if not found
// 3. Test with values that exist and don't exist
//
// HINT: Loop through array, return i when found
//       Return -1 after loop if not found
//============================================================================

int findIndex(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

void exercise_4() {
    cout << "\n=== EXERCISE 4: Finding Values ===" << endl;
    
    int arr[6] = {12, 25, 38, 45, 52, 67};
    
    cout << "Find 38: index " << findIndex(arr, 6, 38) << endl;
    cout << "Find 50: index " << findIndex(arr, 6, 50) << endl;
    cout << "Find 12: index " << findIndex(arr, 6, 12) << endl;
}

//============================================================================
// EXERCISE 5: Counting Elements
//
// Create a function that:
// 1. Takes int array and size
// 2. Counts how many even numbers exist
// 3. Returns the count
//
// HINT: Even numbers: num % 2 == 0
//       Count matches in a loop
//============================================================================

int countEven(int arr[], int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0) {
            count++;
        }
    }
    return count;
}

void exercise_5() {
    cout << "\n=== EXERCISE 5: Counting Elements ===" << endl;
    
    int arr[7] = {5, 12, 8, 23, 16, 9, 4};
    
    cout << "Even numbers: " << countEven(arr, 7) << endl;
}

//============================================================================
// EXERCISE 6: Finding Min and Max
//
// Create two functions:
// 1. findMin - returns smallest element
// 2. findMax - returns largest element
// 3. Test with various arrays
//
// HINT: Start with first element as min/max
//       Compare each element and update if needed
//============================================================================

int findMin(int arr[], int size) {
    int minVal = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < minVal) {
            minVal = arr[i];
        }
    }
    return minVal;
}

int findMax(int arr[], int size) {
    int maxVal = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
    return maxVal;
}

void exercise_6() {
    cout << "\n=== EXERCISE 6: Finding Min and Max ===" << endl;
    
    int arr[5] = {23, 5, 89, 12, 34};
    
    cout << "Minimum: " << findMin(arr, 5) << endl;
    cout << "Maximum: " << findMax(arr, 5) << endl;
}

//============================================================================
// EXERCISE 7: Average Calculation
//
// Create a function that:
// 1. Takes int array and size
// 2. Calculates and returns average as double
// 3. Test with different arrays
// 4. Cast to double for accurate division
//
// HINT: Sum all elements, divide by size as double
//       Return type: double
//============================================================================

double calculateAverage(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return (double)sum / size;
}

void exercise_7() {
    cout << "\n=== EXERCISE 7: Average Calculation ===" << endl;
    
    int arr1[4] = {10, 20, 30, 40};
    int arr2[5] = {15, 25, 35, 45, 55};
    
    cout << "Average of arr1: " << calculateAverage(arr1, 4) << endl;
    cout << "Average of arr2: " << calculateAverage(arr2, 5) << endl;
}

//============================================================================
// EXERCISE 8: Array Reversal
//
// Create a function that:
// 1. Takes int array and size
// 2. Reverses the array in place
// 3. Modifies original array
// 4. Print before and after
//
// HINT: Swap first with last, second with second-last, etc.
//       Use two pointers from start and end
//============================================================================

void reverseArray(int arr[], int size) {
    for (int i = 0; i < size / 2; i++) {
        // Swap
        int temp = arr[i];
        arr[i] = arr[size - 1 - i];
        arr[size - 1 - i] = temp;
    }
}

void exercise_8() {
    cout << "\n=== EXERCISE 8: Array Reversal ===" << endl;
    
    int arr[5] = {1, 2, 3, 4, 5};
    
    cout << "Before: ";
    printArray(arr, 5);
    
    reverseArray(arr, 5);
    
    cout << "After:  ";
    printArray(arr, 5);
}

//============================================================================
// EXERCISE 9: String Array Operations
//
// Create a function that:
// 1. Takes string array and size
// 2. Prints all strings
// 3. Test with different string arrays
//
// HINT: string arr[] parameters work same as int[]
//       Array decays to pointer, pass size parameter
//============================================================================

void printStringArray(string arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << i << ": " << arr[i] << endl;
    }
}

void exercise_9() {
    cout << "\n=== EXERCISE 9: String Array Operations ===" << endl;
    
    string names[3] = {"Alice", "Bob", "Charlie"};
    
    cout << "Names:" << endl;
    printStringArray(names, 3);
}

//============================================================================
// EXERCISE 10: Filtering Arrays
//
// Create a function that:
// 1. Takes int array and size
// 2. Prints only elements greater than a threshold
// 3. Test with different thresholds
//
// HINT: Loop through array, print if element > threshold
//============================================================================

void printGreaterThan(int arr[], int size, int threshold) {
    cout << "Elements > " << threshold << ": ";
    for (int i = 0; i < size; i++) {
        if (arr[i] > threshold) {
            cout << arr[i] << " ";
        }
    }
    cout << endl;
}

void exercise_10() {
    cout << "\n=== EXERCISE 10: Filtering Arrays ===" << endl;
    
    int arr[7] = {5, 15, 8, 22, 12, 30, 9};
    
    printGreaterThan(arr, 7, 10);
    printGreaterThan(arr, 7, 20);
}

//============================================================================
// EXERCISE 11: Copying Arrays
//
// Create a function that:
// 1. Takes source array, destination array, and size
// 2. Copies all elements from source to destination
// 3. Verify copy with printing
//
// HINT: Copy each element: dest[i] = src[i]
//       Both arrays must be allocated
//============================================================================

void copyArray(int src[], int dest[], int size) {
    for (int i = 0; i < size; i++) {
        dest[i] = src[i];
    }
}

void exercise_11() {
    cout << "\n=== EXERCISE 11: Copying Arrays ===" << endl;
    
    int source[4] = {10, 20, 30, 40};
    int destination[4];
    
    copyArray(source, destination, 4);
    
    cout << "Source:      ";
    printArray(source, 4);
    
    cout << "Destination: ";
    printArray(destination, 4);
}

//============================================================================
// EXERCISE 12: Searching with Conditions
//
// Create a function that:
// 1. Takes int array and size
// 2. Finds index of first element divisible by a value
// 3. Returns -1 if none found
//
// HINT: Use find logic but check: arr[i] % divisor == 0
//============================================================================

int findDivisibleBy(int arr[], int size, int divisor) {
    for (int i = 0; i < size; i++) {
        if (arr[i] % divisor == 0) {
            return i;
        }
    }
    return -1;
}

void exercise_12() {
    cout << "\n=== EXERCISE 12: Search with Conditions ===" << endl;
    
    int arr[6] = {7, 14, 9, 21, 5, 18};
    
    cout << "First divisible by 7: index " << findDivisibleBy(arr, 6, 7) << endl;
    cout << "First divisible by 5: index " << findDivisibleBy(arr, 6, 5) << endl;
    cout << "First divisible by 11: index " << findDivisibleBy(arr, 6, 11) << endl;
}

//============================================================================
// EXERCISE 13: Complete Program - Array Analysis
//
// Write complete program that:
// 1. Reads an array of integers
// 2. Calls functions to calculate:
//    - Sum
//    - Average
//    - Minimum
//    - Maximum
//    - Count of even numbers
// 3. Displays all statistics
//
// This combines all concepts from lesson 13.
//
// HINT: Use helper functions from previous exercises
//============================================================================

void exercise_13() {
    cout << "\n=== EXERCISE 13: Complete Array Analysis ===" << endl;
    
    int data[10] = {15, 23, 8, 42, 17, 39, 6, 51, 28, 14};
    int size = 10;
    
    cout << "\n=== ARRAY ANALYSIS ===" << endl;
    cout << "Data: ";
    printArray(data, size);
    
    cout << "\nStatistics:" << endl;
    cout << "Sum:     " << sumArray(data, size) << endl;
    cout << "Average: " << calculateAverage(data, size) << endl;
    cout << "Minimum: " << findMin(data, size) << endl;
    cout << "Maximum: " << findMax(data, size) << endl;
    cout << "Even count: " << countEven(data, size) << endl;
}

//============================================================================
// MAIN FUNCTION - Run Selected Exercises
//============================================================================

int main() {
    cout << "=====================================================" << endl;
    cout << "LESSON 13 EXERCISES: Arrays and Functions" << endl;
    cout << "=====================================================" << endl;

    // Uncomment exercises to test:
    
    exercise_1();
    exercise_2();
    exercise_3();
    exercise_4();
    exercise_5();
    exercise_6();
    exercise_7();
    exercise_8();
    exercise_9();
    exercise_10();
    exercise_11();
    exercise_12();
    exercise_13();

    cout << "\n=====================================================" << endl;
    cout << "EXERCISE SUMMARY" << endl;
    cout << "=====================================================" << endl;
    cout << "1. Basic Array Printing - Print elements" << endl;
    cout << "2. Array Summation - Calculate sum" << endl;
    cout << "3. Array Modification - Modify original" << endl;
    cout << "4. Finding Values - Search array" << endl;
    cout << "5. Counting Elements - Count matching" << endl;
    cout << "6. Min and Max - Find extremes" << endl;
    cout << "7. Average Calculation - Calculate average" << endl;
    cout << "8. Array Reversal - Reverse in place" << endl;
    cout << "9. String Arrays - Work with strings" << endl;
    cout << "10. Filtering - Filter by condition" << endl;
    cout << "11. Copying - Copy arrays" << endl;
    cout << "12. Conditional Search - Find by condition" << endl;
    cout << "13. Complete Program - Everything together" << endl;
    cout << "=====================================================" << endl;

    return 0;
}
