// Functor to class member functions

#include <iostream>
#include <functional>
#include <unordered_map>

using namespace std;

class Calculator
{
public:
    void Add(int val)
    {
        cout << __PRETTY_FUNCTION__ << endl;
        _base += val;
    }

    void Sub(int val)
    {
        cout << __PRETTY_FUNCTION__<< endl;
        _base -= val;
    }

    // void VerboseOp(int val, decltype(&Add) op)    // old style
    void VerboseOp(int val, decltype(mem_fn(&Add)) op)
    {
        cout << "executing with " << val << endl;
        cout << "before " << _base << endl;
        // (this->*op) (val);    // old style
        op(*this, val);
        cout << "after " << _base << endl << endl;
    }

    void VerboseAdd(int val)
    {
        // VerboseOp(val, &Add);    // old style
        VerboseOp(val, mem_fn(&Add));
    }

    void VerboseSub(int val)
    {
        // VerboseOp(val, &Sub);    // old style
        VerboseOp(val, mem_fn(&Sub));
    }

private:

    int _base = 0;
};

int main()
{
    Calculator calc;
    calc.VerboseAdd(1);
    calc.VerboseAdd(2);
    calc.VerboseSub(3);
}