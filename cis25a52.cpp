#include <iostream>
using namespace std;

class addition {
public:
    int addMethod(int x, int y) {
        return x + y;
    }
    int addMethod(int x, int y, int z) {
        return x + y + z;
    }
};

int main() {
    addition add;
    cout << add.addMethod(2, 3) << endl;       // prints 5
    cout << add.addMethod(2, 3, 6) << endl;    // prints 11
    return 0;
}
