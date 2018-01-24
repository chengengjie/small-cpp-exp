#include <iostream>

using namespace std;

int main() {
    int a = -1;
    unsigned unsignedZero = 0;
    cout << boolalpha << (a < unsignedZero) << endl;    // false
    cout << (unsignedZero - 1) << endl;     // 4294967295
}