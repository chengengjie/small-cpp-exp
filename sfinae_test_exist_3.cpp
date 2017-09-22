// SFINAE (Substitution Failure Is Not An Error) for testing existance of function / member variable
// 1. easy to reuse

#include <iostream>
#include <type_traits>
#include <vector>
#include <utility>

using namespace std;

template <typename UnnamedType> struct container
{
// Let's put the test in private.
private:
    // We use std::declval to 'recreate' an object of 'UnnamedType'.
    // We use std::declval to also 'recreate' an object of type 'Param'.
    // We can use both of these recreated objects to test the validity!
    template <typename Param> constexpr auto testValidity(int /* unused */)
    -> decltype(std::declval<UnnamedType>()(std::declval<Param>()), std::true_type())
    {
        // If substitution didn't fail, we can return a true_type.
        return std::true_type();
    }

    template <typename Param> constexpr std::false_type testValidity(...)
    {
        // Our sink-hole returns a false_type.
        return std::false_type();
    }

public:
    // A public operator() that accept the argument we wish to test onto the UnnamedType.
    template <typename Param> constexpr auto operator()(const Param& p)
    {
        // The argument is forwarded to one of the two overloads.
        // The SFINAE on the 'true_type' will come into play to dispatch.
        return testValidity<Param>(int());
    }
};

template <typename UnnamedType> constexpr auto is_valid(const UnnamedType& t) 
{
    return container<UnnamedType>();
}

auto has_begin = is_valid([](auto&& x) -> decltype(begin(x)) { });

int main()
{
    vector<int> vecInts;

    // on instances (dynamic)
    pair<int, int> pairInts;
    cout << boolalpha;
    cout << decltype(has_begin(vecInts))::value << endl;
    cout << decltype(has_begin(pairInts))::value << endl;

    // on types (static)
    cout << decltype(has_begin(vector<int>()))::value << endl;
    cout << decltype(has_begin(pair<int, int>()))::value << endl;
    return 1;
}