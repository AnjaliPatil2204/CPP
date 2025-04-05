#include <iostream>
using namespace std;

// Function to check if a number is prime
bool isPrime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

// Function to display prime numbers up to a given limit
void displayPrimes(int limit) {
    cout << "Prime numbers up to " << limit << " are:" << endl;
    for (int i = 2; i <= limit; i++) {
        if (isPrime(i)) cout << i << " ";
    }
    cout << endl;
}

int main() {
    int limit;
    cout << "Enter a limit: ";
    cin >> limit;
    displayPrimes(limit);
    return 0;
}

