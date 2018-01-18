// Class with pure virtual function(s) is abstract type and cannot be instantiated

#include<iostream>
#include<string>

using namespace std;

class Base
{
public:
    virtual void Print() = 0;
};

class Derived1 : public Base
{
public:
    void Print()
    {
        cout << "Derived1::Print" << endl;
    }
};

class Derived2 : public Base
{
public:
    void AnotherPrint()
    {
        cout << "Derived2::AnotherPrint()" << endl;
    }
};

int main()
{
    // Base base;
    Derived1 derived1;
    // Derived2 derived2;

    return 1;
}