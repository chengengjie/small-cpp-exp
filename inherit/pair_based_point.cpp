#include <iostream>
#include <utility>
#include <chrono>

using namespace std;

class Point : public pair<int, int>
{
public:
    using pair<int, int>::pair;

    int x() { return first; }
    int y() { return second; }
    inline int x_inline() { return first; }
};

class PointRaw
{
public:
    int x, y;

    PointRaw(int xx, int yy) : x(xx), y(yy) {}
};

int main()
{
    {
        Point ptA(10, 8), ptB(10, 8), ptC(10, 10);

        // use get<index>(pair)
        cout << ptA.x() << endl;
        cout << get<0>(ptA) << endl;

        // use pair::operator==
        cout << boolalpha;
        cout << (ptA == ptB) << endl;
        cout << (ptB == ptC) << endl;

        // auto ptD = ptA + ptB;    // invalid

        // no runtime diff between x() and x_inline()
        using namespace chrono;
        const long long times = 1e9;
        using clock = high_resolution_clock ;
        Point pt(1, 1);
        {
            auto start = clock::now();
            int totX = 0;
            for (long long i = 0; i < times; ++i)
            {
                totX += pt.x();
                totX -= pt.x();
            }
            duration<double> dur = clock::now() - start;
            cout << dur.count() << endl;
        }
        {
            auto start = clock::now();
            int totX = 0;
            for (long long i = 0; i < times; ++i)
            {
                totX += pt.x_inline();
                totX -= pt.x_inline();
            }
            duration<double> dur = clock::now() - start;
            cout << dur.count() << endl;
        }
    }

    // No default operator== and operator!= ...
    // {
    //     PointRaw ptA(10, 8), ptB(10, 8), ptC(10, 10);

    //     // use operator==
    //     cout << boolalpha;
    //     cout << (ptA == ptB) << endl;
    //     cout << (ptA != ptB) << endl;
    //     cout << (ptB == ptC) << endl;
    //     cout << (ptB != ptC) << endl;
    // }
}