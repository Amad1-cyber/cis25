#include <iostream>
using namespace std;

int main() {
    // --- Part 1: Find the largest of three numbers ---
    int a, b, c;
    cout << "Enter three numbers:\n";
    cin >> a >> b >> c;

    int largest;

    if (a >= b) {
        if (a >= c) {
            largest = a;
        }
        else {
            largest = c;
        }
    }
    else {
        if (b >= c) {
            largest = b;
        }
        else {
            largest = c;
        }
    }

    cout << "The largest number is: " << largest << endl;

    // --- Part 2: Leap year check ---
    int year;
    cout << "\nEnter a year to check if it's a leap year: ";
    cin >> year;

    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        cout << year << " is a leap year." << endl;
    }
    else {
        cout << year << " is not a leap year." << endl;
    }

    return 0;
}
