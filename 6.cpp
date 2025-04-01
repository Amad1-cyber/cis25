#include <iostream>
using namespace std;

int main() {
    int number = 10;

    // ❌ Error: assignment operator (=) used instead of comparison operator (==)
    // ✅ Fix: Use == to compare values
    if (number == 20) {
        cout << "Number is 20" << endl;
    }
    else {
        cout << "Number is not 20" << endl;
    }

    // ❌ Error: semicolon (;) at the end of the for loop causes it to do nothing
    // ✅ Fix: Remove semicolon so the loop controls the following block
    for (int i = 0; i <= 5; i++) {
        cout << i << endl; // ✅ Move inside loop block
    }

    return 0;
}
