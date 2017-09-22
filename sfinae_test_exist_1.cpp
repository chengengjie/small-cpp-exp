// SFINAE (Substitution Failure Is Not An Error) for testing existance of function / member variable
// 1. concise
// 2. no hacking by int()

#include <iostream>
#include <type_traits>
#include <vector>
#include <utility>

using namespace std;

template <typename T, typename = void>
struct has_begin
  : std::false_type
{ };

template <typename T>
struct has_begin<T, decltype((void)begin(std::declval<T>()))>
  : std::true_type
{ };

int main()
{
    cout << boolalpha;
    cout << has_begin<vector<int>>::value << endl;
    cout << has_begin<pair<int, int>>::value << endl;
}