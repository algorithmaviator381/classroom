// 1: Account Information
// Data members – Name of depositor, Account number, Type of account, Balance in account.
// Members function - To deposit amount, to withdraw amount, to display name and balance.
// Sol.:


#include <iostream>
#include <string>

using namespace std;

class BankAccount {
private:
    string depositorName;
    int accountNumber;
    string accountType;
    double balance;

public:
    BankAccount(const string& name, int accNumber, const string& accType, double initialBalance) {
        depositorName = name;
        accountNumber = accNumber;
        accountType = accType;
        balance = initialBalance;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposit successful. New balance: $" << balance << endl;
        } else {
            cout << "Invalid deposit amount." << endl;
        }
    }


    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawal successful. New balance: $" << balance << endl;
        } else {
            cout << "Invalid withdrawal amount or insufficient funds." << endl;
        }
    }

    void display() const {
        cout << "Depositor Name: " << depositorName << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Type: " << accountType << endl;
        cout << "Balance: $" << balance << endl;
    }
};

int main() {
    BankAccount myAccount("John Doe", 123456, "Savings", 1000.0);

    myAccount.display();  // Display initial account information
    myAccount.deposit(500.0);  // Deposit $500
    myAccount.withdraw(200.0); // Withdraw $200
    myAccount.display();  // Display updated account information

    return 0;
}
