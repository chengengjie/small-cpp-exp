// Check how to call the operator of base class from derived class

#include <iostream>
#include <vector>

using namespace std;

class Base
{
public:
    Base(int x) : _x(x) {}
    
    bool operator ==(const Base& rhs)
    {
        return _x == rhs._x;
    }

private:
    int _x;
};

class Derived : public Base
{
public:
    Derived(int x, int y) : Base(x), _y(y) {}

    bool operator ==(const Derived& rhs)
    {
        return Base::operator==(rhs) && _y == rhs._y;
    }

private:
    int _y;
};

int main()
{
    Derived a(1, 1), b(1, 1), c(1, 2), d(2, 2);
    cout << (a==b) << endl; // true
    cout << (a==c) << endl; // false
    cout << (a==d) << endl; // false

    return 0;
}