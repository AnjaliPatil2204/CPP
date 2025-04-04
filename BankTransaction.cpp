#include <iostream>
using namespace std;

class Account {
private:
    double balance;

public:
    Account(double balance) {
        this->balance = balance;
    }

    void deposit(double amount) {
        balance += amount;
        cout << "Deposited: " << amount << endl;
    }

    void deposit(int amount) {
        balance += amount;
        cout << "Deposited: " << amount << endl;
    }

    Account operator+(Account& other) {
        double newBalance = balance + other.balance;
        cout << "Transferred: " << other.balance << endl;
        balance = newBalance;
        return *this;
    }

    void displayBalance() {
        cout << "Balance: " << balance << endl;
    }
};

int main() {
    Account account(1000);
    account.displayBalance();

    account.deposit(500);
    account.displayBalance();

    account.deposit(200.50);
    account.displayBalance();

    Account account2(500);
    account2.displayBalance();

    account = account + account2;
    account.displayBalance();

  
}

