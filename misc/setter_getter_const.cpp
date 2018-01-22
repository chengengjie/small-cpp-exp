#include <iostream>

using namespace std;

class Point {
public:
    int& x() { 
        cout << "setter" << endl;
        return x_;
    }
    int x() const { 
        cout << "getter" << endl;
        return x_;
    }

private:
    int x_;
};

void PrintPoint(const Point& pt) {
    cout << pt.x() << endl;
}

int main() {
    Point pt;
    pt.x() = 10;  // setter
    PrintPoint(pt);  // getter
    cout << pt.x() << endl;  // setter
    int y = pt.x();  // setter

    return 0;
}