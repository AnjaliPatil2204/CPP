#include <iostream>
using namespace std;

template <typename T>
class Box {
public:
    T value;

    Box(T val) {
        value = val;
    }

    void print() {
        cout << "Value: " << value << endl;
    }
};

int main() {
    Box<int> intBox(10);
    intBox.print();

    Box<string> stringBox("Hello");
    stringBox.print();

    return 0;
}

