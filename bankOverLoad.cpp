#include <iostream>
#include <string>

using namespace std;

// Class to handle Bank transactions (Function Overloading)
class Bank {
public:
    // Function to deposit an integer amount (Cash deposit)
    void deposit(int amount) {
        cout << "Depositing Rs. " << amount << " in cash." << endl;
    }

    // Function to deposit a floating-point amount (Digital payment)
    void deposit(float amount) {
        cout << "Depositing Rs. " << amount << " via digital payment." << endl;
    }

    // Function to deposit using UPI (by accepting a string UPI ID)
    void deposit(string upi_id, float amount) {
        cout << "Depositing Rs. " << amount << " using UPI (" << upi_id << ")." << endl;   //	
    }
};

// Class to handle Account details and transactions (Operator Overloading)
class Account {
private:
    int account_number;
    float balance;

public:
    // Constructor to initialize Account details
    Account(int acc_num, float initial_balance) : account_number(acc_num), balance(initial_balance) {}

    // Overloaded + operator to transfer funds from one account to another
    void operator+(Account& other) {
        float transfer_amount;
        cout << "Enter the amount to transfer from Account " << account_number << " to Account " << other.account_number << ": Rs. ";
        cin >> transfer_amount;

        if (balance >= transfer_amount) {
            balance -= transfer_amount;
            other.balance += transfer_amount;
            cout << "Transferring Rs. " << transfer_amount << " from Account " << account_number << " to Account " << other.account_number << "..." << endl;
            cout << "New Account " << account_number << " Balance: Rs. " << balance << endl;
            cout << "New Account " << other.account_number << " Balance: Rs. " << other.balance << endl;
        } else {
            cout << "Insufficient funds in Account " << account_number << " for transfer!" << endl;
        }
    }

    // Overloaded - operator to withdraw funds
    void operator-(float amount) {
        if (balance >= amount) {
            balance -= amount;
            cout << "Withdrawing Rs. " << amount << " from Account " << account_number << "..." << endl;
            cout << "Remaining Balance: Rs. " << balance << endl;
        } else {
            cout << "Insufficient funds in Account " << account_number << " for withdrawal!" << endl;
        }
    }

    // Function to display account details
    void displayAccountDetails() {
        cout << "Account " << account_number << " Balance: Rs. " << balance << endl;
    }
};

int main() {
    // Demonstrating function overloading
    Bank bank;
    bank.deposit(5000);          // Cash deposit (integer amount)
    bank.deposit(1500.75f);      // Digital payment (floating-point amount)
    bank.deposit("gpay@upi", 2500);  // UPI deposit

    // Creating two accounts
    Account account1(1, 10000);
    Account account2(2, 5000);

    // Display account details before transaction
    account1.displayAccountDetails();
    account2.displayAccountDetails();

    // Demonstrating operator overloading (fund transfer and withdrawal)
    account1 + account2;   // Transfer funds from Account 1 to Account 2
    account1 - 2000;        // Withdraw ?2000 from Account 1

    return 0;
}

