#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> vecA = {0, 1};
    for (auto val : vecA) {
        cout << val << " ";
    }
    cout << endl;

    vecA = {2, 3};
    for (auto val : vecA) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}