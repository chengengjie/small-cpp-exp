// Curiously recurring template pattern

#include<iostream>
#include<string>

using namespace std;

// force static member variable in derived class by template
template<typename Derived>
class ModuleBase
{
public:
    string name() { return _name; }

protected:
    static const string _name;
};

// two derived classes
class Module1 : public ModuleBase<Module1>  // Module1 recurs here
{
};
class Module2 : public ModuleBase<Module2>  // Module2 recurs here
{
};

// name of derived classes (forced: compiler error if no definition)
template<> const string ModuleBase<Module1>::_name = "Module1";
template<> const string ModuleBase<Module2>::_name = "Module2";

int main()
{
    Module1 mod1;
    cout << mod1.name() << endl;
    Module2 mod2;
    cout << mod2.name() << endl;

    return 0;
}