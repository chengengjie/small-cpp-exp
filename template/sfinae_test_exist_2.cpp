// SFINAE (Substitution Failure Is Not An Error) for testing existance of function / member variable
// 1. well wrapped

#include <iostream>
#include <type_traits>
#include <vector>
#include <utility>

using namespace std;

template <class T> struct has_begin
{
    template <typename C> static constexpr decltype(begin(std::declval<C>()), bool()) test(int)
    {
        return true;
    }

    template <typename C> static constexpr bool test(...)
    {
        return false;
    }

    static constexpr bool value = test<T>(int());
};

int main()
{
    cout << boolalpha;
    cout << has_begin<vector<int>>::value << endl;
    cout << has_begin<pair<int, int>>::value << endl;
}