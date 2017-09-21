// Try Python-like print

#include <iostream>
#include <vector>
#include <string>

using namespace std;

template<typename T>
ostream& operator<<(ostream& os, const vector<T>& vec)
{
    os << '[';
    auto it = begin(vec);
    const auto theEnd = end(vec);
    if (it != theEnd)
    {
        for ( ; ; )
        {
            os << *it;
            if (++it == theEnd) break;
            os << ", ";
        }
    }
    os << ']';
}

void print()
{
    cout << endl;
}

template<typename T, typename ...TAIL>
void print(const T& t, TAIL... tail)
{
    cout << t << ' ';
    print(tail...);
}

int main()
{
    int id = 2;
    double val = 3.14;
    string name = "pi";

    print("No.", id, ":", name, "is", val);

    vector<double> vals = {1.2, 2.3, 3.4};
    print("vals: ", vals);

    return 0;
}