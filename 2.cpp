#include <iostream>
using namespace std;

int main() {
    // Part 1: Print all even numbers from 1 to 50
    cout << "Even numbers from 1 to 50:" << endl;
    for (int i = 1; i <= 50; ++i) {
        if (i % 2 == 0) {
            cout << i << " ";
        }
    }
    cout << endl;

    // Part 2: Create and populate an array with user input
    const int SIZE = 10;
    int numbers[SIZE];
    int index = 0;

    cout << "Enter 10 integers:" << endl;
    while (index < SIZE) {
        cout << "Number " << (index + 1) << ": ";
        cin >> numbers[index];
        ++index;
    }

    // Print the array
    cout << "You entered:" << endl;
    for (int i = 0; i < SIZE; ++i) {
        cout << numbers[i] << " ";
    }
    cout << endl;

    return 0;
}
