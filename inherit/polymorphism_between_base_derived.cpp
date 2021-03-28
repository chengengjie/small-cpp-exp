#include <iostream>

using namespace std;

class Base {
public:
    void Proc() {
        cout << "Base::Proc calls virtual Print" << endl;
        Print();
    }

    virtual void Print() {
        cout << "Base::Print" << endl;
    }
};

class Derived : public Base {
public:
    void Print() {
        cout << "Derived::Print" << endl;
    }
};

int main() {
    Base base;
    Derived derived;
    base.Proc();  // Base::Print
    derived.Proc();  // Derived::Print
    return 0;
}