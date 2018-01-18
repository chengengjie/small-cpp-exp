#include <iostream>

using namespace std;

class Base {
public:
    int x;
    Base() {
        x = 1;
        cout << "Base::Base()" << endl;
    }
    ~Base() {
        cout << "Base::~Base()" << endl;
    }
    void Print() {
        cout << "Base::Print()" << endl;
    }
};

class Derived : public Base {
public:
    Derived() {
        x = 2;
        cout << "Derived::Derived()" << endl;
    }
    ~Derived() {
        cout << "Derived::~Derived()" << endl;
    }
    void Print() {
        cout << "Derived::Print()" << endl;
    }
};

int main() {
    Derived derived;
    cout << "Construction done!" << endl;
    derived.Print();

    cout << endl << "Start casting a derived class to a base one" << endl;
    {
        Base trulyBase = derived; 
        derived.x = 3;
        cout << trulyBase.x << endl;    // is truly a base class
        trulyBase.Print();
    }

    cout << endl << "Start referencing a derived class to a base one" << endl;
    {
        Base& stillDerived = derived; 
        derived.x = 3;
        cout << stillDerived.x << endl; // is still a derived class
        stillDerived.Print();           // but appears as base class
    }
}