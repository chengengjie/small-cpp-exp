#include<iostream>
#include<string>
#include<typeinfo>

using namespace std;

class Module
{
public:
    static constexpr auto name = "Module";
};

class Module1 : public Module
{
public:
    static constexpr auto name = "Module1";
};

int main()
{
    Module mod_a, mod_b;
    Module1 mod1_a, mod1_b;
    cout << mod_a.name << " " << mod_b.name << endl;
    cout << mod1_a.name << " " << mod1_b.name << endl;

    // compiler-dependant solution (suitable for debugging but not UI)
    cout << typeid(Module).name() << endl;
    cout << typeid(Module1).name() << endl;
    cout << typeid(decltype(mod_a)).name() << endl;
    cout << typeid(decltype(mod1_a)).name() << endl;

    return 0;
}