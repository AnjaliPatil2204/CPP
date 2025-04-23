#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Create a vector of integers
    vector<int> numbers;

    // Add elements to the vector
    numbers.push_back(10);
    numbers.push_back(20);
    numbers.push_back(30);

    // Display the elements
    cout << "Vector elements: ";
    for (int i = 0; i < numbers.size(); i++) {
        cout << numbers[i] << " ";
    }
    cout << endl;

    // Accessing the first element
    cout << "First element: " << numbers[0] << endl;

    // Display size
    cout << "Size of vector: " << numbers.size() << endl;

    // Remove last element
    numbers.pop_back();

    // Display elements after removal
    cout << "After pop_back, elements: ";
    for (int i = 0; i < numbers.size(); i++) {
        cout << numbers[i] << " ";
    }
    cout << endl;

    return 0;
}

