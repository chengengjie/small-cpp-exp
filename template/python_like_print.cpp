// Try Python-like print

#include <iostream>
#include <type_traits>
#include <vector>
#include <array>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <string>

using namespace std;

// SFINAE has_begin_end
template <typename T, typename = void>
struct has_begin_end
  : std::false_type {};
template <typename T>
struct has_begin_end<T, decltype((void)begin(std::declval<T>()), (void)end(std::declval<T>()))>
  : std::true_type {};

// is container (warpper is necessary for basic_string, why?)
template <typename T>
struct is_container : integral_constant<bool, has_begin_end<T>::value> {};

template <typename ...T>
struct is_container<basic_string<T...>> : false_type { };

// for container
template<typename T>
enable_if_t<is_container<T>::value, ostream&>
operator<<(ostream& os, const T& container)
{
    os << '[';
    auto it = begin(container);
    const auto theEnd = end(container);
    if (it != theEnd)
    {
        for ( ; ; )
        {
            os << *it;
            if (++it == theEnd) break;
            os << ", ";
        }
    }
    os << ']';
}

// for pair
template<typename ...T>
ostream& operator<<(ostream& os, const pair<T...>& p)
{
    cout << "(" << p.first << ", " << p.second << ")";
}

// print
void print()
{
    cout << endl;
}
template<typename T, typename ...TAIL>
void print(const T& t, TAIL... tail)
{
    cout << t << ' ';
    print(tail...);
}

// main
int main()
{
    // containers
    array<int, 3> a = {100, 200, 300};
    vector<int> v;
    vector<vector<int>> vv;
    set<int> s;
    unordered_set<int> us;
    map<int, int> m;
    unordered_map<int, int> um;
    for (unsigned i = 0; i < a.size(); ++i)
    {
        const auto& val = a[i];
        v.emplace_back(val);
        vv.emplace_back(v);
        s.emplace(val);
        us.emplace(val);
        m.emplace(i, val);
        um.emplace(i, val);
    }
    cout << a << endl;
    cout << v << endl;
    cout << vv << endl;
    cout << s << endl;
    cout << us << endl;
    cout << m << endl;
    cout << um << endl;
    
    // strings
    cout << "good" << endl;
    char c_str[] = "good";
    string str = "good";
    cout << c_str << endl;
    cout << str << endl;

    // print
    int id = 2;
    double val = 3.14;
    string name = "PI";
    print("No.", id, ":", name, "is", val);
    print("a:", a);

    return 0;
}