#include <iostream>
#include <string>
using namespace std;

int main() {
    string name;
    float balance = 500.0; // Initial balance
    int choice;

    // Ask for user's name
    cout << "What is your name? ";
    getline(cin, name);

    // Display welcome message and balance
    cout << name << ", Welcome to your account" << endl;
    cout << "Balance: $" << balance << endl;

    // Display menu
    cout << "1) Make a Deposit" << endl;
    cout << "2) Make a Withdrawal" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    // Handle menu choice
    if (choice == 1) {
        float deposit;
        cout << "Enter deposit amount: ";
        cin >> deposit;
        if (deposit > 0) {
            balance += deposit;
            cout << "Deposit amount: $" << deposit << endl;
            cout << "New balance: $" << balance << endl;
        }
        else {
            cout << "Invalid deposit amount. Please enter a positive number." << endl;
        }
    }
    else if (choice == 2) {
        float withdrawal;
        cout << "Enter withdrawal amount: ";
        cin >> withdrawal;
        if (withdrawal > balance) {
            cout << "Insufficient balance!" << endl;
        }
        else if (withdrawal > 0) {
            balance -= withdrawal;
            cout << "Withdrawal amount: $" << withdrawal << endl;
            cout << "Final balance: $" << balance << endl;
        }
        else {
            cout << "Invalid withdrawal amount. Please enter a positive number." << endl;
        }
    }
    else {
        cout << "Invalid choice" << endl;
    }

    return 0;
}
