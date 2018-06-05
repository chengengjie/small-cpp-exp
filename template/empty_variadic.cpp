#include <iostream>
#include <vector>

using namespace std;

template<typename T, typename... Args>
vector<T> GetVector(Args... args) {
    return vector<T>(args...);
}

template<typename T>
void PrintVector(const vector<T>& vec) {
    cout << "[";
    for (auto element : vec) {
        cout << element << " ";
    }
    cout << "]" << endl;
}

int main() {
    auto res = GetVector<int>(10, 10);
    PrintVector(res);
    auto res2 = GetVector<int>(10);
    PrintVector(res2);
    auto res3 = GetVector<int>();   // empty variadic works
    PrintVector(res3);
    return 0;
}
