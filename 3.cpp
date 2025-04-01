#include <iostream>
#include <string> // Required for string type
using namespace std;

int main() {
    // User input section
    string name;
    int age;
    float favoriteNumber;

    cout << "Enter your name: ";
    getline(cin, name); // Allows spaces in name

    cout << "Enter your age: ";
    cin >> age;

    cout << "Enter your favorite number: ";
    cin >> favoriteNumber;

    // Formatted output
    cout << "\n--- User Info ---" << endl;
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
    cout << "Favorite Number: " << favoriteNumber << endl;

    // Variable declaration and initialization
    int myInt = 100;
    float myFloat = 3.14f;
    char myChar = 'A';
    string myString = "Hello";

    // Print values of different data types
    cout << "\n--- Variable Values ---" << endl;
    cout << "Integer: " << myInt << endl;
    cout << "Float: " << myFloat << endl;
    cout << "Character: " << myChar << endl;
    cout << "String: " << myString << endl;

    return 0;
}
