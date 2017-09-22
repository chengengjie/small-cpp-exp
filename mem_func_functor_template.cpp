// Functor/template to class member functions

#include <iostream>
#include <functional>
#include <unordered_map>
#include <typeinfo>

using namespace std;

class CalculatorBase
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

    virtual void VerboseAdd(int val) = 0;

    virtual void VerboseSub(int val) = 0;

protected:
    int _base = 0;
};

class Calculator : public CalculatorBase
{
public:
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
};

class Calculator2 : public CalculatorBase
{
public:
    template<typename FuncType>
    void VerboseOp(int val, FuncType op)
    {
        cout << "executing with " << val << endl;
        cout << "before " << _base << endl;
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
};

int main()
{
    cout << "Test " << typeid(Calculator).name() << endl << endl;
    Calculator calc;
    calc.VerboseAdd(1);
    calc.VerboseAdd(2);
    calc.VerboseSub(3);

    cout << "******************************************" << endl;
    cout << "Test " << typeid(Calculator2).name() << endl << endl;
    Calculator2 calc2;
    calc.VerboseAdd(1);
    calc.VerboseAdd(2);
    calc.VerboseSub(3);
}