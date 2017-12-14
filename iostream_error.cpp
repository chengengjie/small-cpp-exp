#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main()
{
    {
        stringstream iss("This does not begin with an integer number");
        int number = 0;
        string str;
        iss >> number >> str;
        cout << "The number is now " << number << endl; // still 0
        cout << "The string is now " << str << endl;    // empty (i.e., iss becomes "bad")
    }

    {
        stringstream iss("This does not begin with an integer number");
        int number = 0;
        string str;
        auto pos = iss.tellg();
        iss >> number;
        iss.seekg(pos); // does not help
        iss >> str;
        cout << "The number is now " << number << endl; // still 0
        cout << "The string is now " << str << endl;    // empty (i.e., iss becomes "bad")
    }

    string str;
    istringstream iss("start");
    iss >> str;
    cout << str << endl;
    iss.str("goodgood");
    cout << iss.str() << endl;
    iss >> str; // does not work
    cout << str << endl;

    return 0;
}