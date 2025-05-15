// BankAccountApp.cpp
// Ahmed Othman / [10831418]
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include <string>
#include <iomanip>

using namespace std;

struct Transaction {
    string type;
    double amount;
    string timestamp;
};

class BankAccount {
private:
    double balance;
    vector<Transaction> deposits;
    vector<Transaction> withdrawals;

    string getCurrentTimestamp() {
        time_t now = time(0);
        char buffer[26];
        ctime_s(buffer, sizeof(buffer), &now);
        string timeStr(buffer);
        timeStr.pop_back(); // remove newline
        return timeStr;
    }

    void loadTransactions() {
        ifstream file("bankdata.txt");
        if (!file) return;

        string type, timestamp;
        double amount;
        while (file >> type >> amount) {
            file.ignore();
            getline(file, timestamp);
            Transaction t = { type, amount, timestamp };
            if (type == "Deposit") {
                deposits.push_back(t);
                balance += amount;
            }
            else if (type == "Withdrawal") {
                withdrawals.push_back(t);
                balance -= amount;
            }
        }
        file.close();
    }

    void saveTransactions() {
        ofstream file("bankdata.txt");
        for (const auto& d : deposits) {
            file << d.type << " " << d.amount << " " << d.timestamp << endl;
        }
        for (const auto& w : withdrawals) {
            file << w.type << " " << w.amount << " " << w.timestamp << endl;
        }
        file.close();
    }

public:
    BankAccount() : balance(0.0) {
        loadTransactions();
    }

    void checkBalance() {
        cout << "\nCurrent Balance: $" << fixed << setprecision(2) << balance << endl;
    }

    void makeDeposit(double amount) {
        string ts = getCurrentTimestamp();
        deposits.push_back({ "Deposit", amount, ts });
        balance += amount;
        cout << "$" << amount << " deposited on " << ts << endl;
    }

    void makeWithdrawal(double amount) {
        if (amount > balance) {
            cout << "Insufficient funds." << endl;
            return;
        }
        string ts = getCurrentTimestamp();
        withdrawals.push_back({ "Withdrawal", amount, ts });
        balance -= amount;
        cout << "$" << amount << " withdrawn on " << ts << endl;
    }

    void showDeposits() {
        cout << "\nDeposit History:" << endl;
        for (const auto& d : deposits) {
            cout << "$" << d.amount << " on " << d.timestamp << endl;
        }
    }

    void showWithdrawals() {
        cout << "\nWithdrawal History:" << endl;
        for (const auto& w : withdrawals) {
            cout << "$" << w.amount << " on " << w.timestamp << endl;
        }
    }

    void showAllTransactions() {
        cout << "\nAll Transactions:" << endl;
        for (const auto& d : deposits) {
            cout << "Deposit: $" << d.amount << " on " << d.timestamp << endl;
        }
        for (const auto& w : withdrawals) {
            cout << "Withdrawal: $" << w.amount << " on " << w.timestamp << endl;
        }
    }

    void exitProgram() {
        saveTransactions();
        cout << "\nFinal Balance: $" << fixed << setprecision(2) << balance << endl;
    }
};

int main() {
    BankAccount account;
    int choice;
    double amount;

    do {
        cout << "\nBank Account Menu:";
        cout << "\n1. Check Balance\n2. Make a Deposit\n3. Make a Withdrawal\n4. Deposit History";
        cout << "\n5. Withdrawal History\n6. All Deposits and Withdrawals\n7. Exit" << endl;
        cout << "Select an option: ";
        cin >> choice;

        switch (choice) {
        case 1:
            account.checkBalance();
            break;
        case 2:
            cout << "Enter deposit amount: ";
            cin >> amount;
            account.makeDeposit(amount);
            break;
        case 3:
            cout << "Enter withdrawal amount: ";
            cin >> amount;
            account.makeWithdrawal(amount);
            break;
        case 4:
            account.showDeposits();
            break;
        case 5:
            account.showWithdrawals();
            break;
        case 6:
            account.showAllTransactions();
            break;
        case 7:
            account.exitProgram();
            break;
        default:
            cout << "Invalid choice." << endl;
        }
    } while (choice != 7);

    return 0;
}
