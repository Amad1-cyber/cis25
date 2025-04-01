#include <iostream>
using namespace std;

// Function to calculate the area of a rectangle
float calculateArea(float length, float width) {
    return length * width;
}

// Function to check if a number is prime
bool isPrime(int number) {
    if (number <= 1) return false;
    for (int i = 2; i * i <= number; ++i) {
        if (number % i == 0) return false;
    }
    return true;
}

// Main function to demonstrate usage
int main() {
    // Example usage of calculateArea
    float length = 5.0, width = 3.0;
    cout << "Area of rectangle: " << calculateArea(length, width) << endl;

    // Example usage of isPrime
    int number = 7;
    if (isPrime(number))
        cout << number << " is a prime number." << endl;
    else
        cout << number << " is not a prime number." << endl;

    return 0;
}
