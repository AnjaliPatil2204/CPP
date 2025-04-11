#include <iostream>
using namespace std;

int main() {
    int arr[5] = {1, 2, 3, 4, 5};

    cout << "Array elements: ";
    for (int elem : arr) {
        cout << elem << " ";
    }
    cout << endl;

    return 0;
}


