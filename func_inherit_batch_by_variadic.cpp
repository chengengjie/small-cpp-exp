#include <iostream>

using namespace std;

class Point2d {
public:
    int x, y;
    Point2d(int xx, int yy) : x(xx), y(yy) {}
    Point2d(int diag_val) : x(diag_val), y(diag_val) {}
};

class Point3d : public Point2d {
public:
    int z;
    template<typename... Args>
    Point3d(int zz, Args... params) : z(zz), Point2d(params...) {}
};

int main() {
    Point2d ptA(10, 12);
    Point2d ptB(10);
    cout << ptA.x << " " << ptA.y << endl;
    cout << ptB.x << " " << ptB.y << endl;

    Point3d ptC(1, 10, 12);
    Point3d ptD(1, 10);
    cout << ptC.x << " " << ptC.y << " " << ptC.z << endl;
    cout << ptD.x << " " << ptD.y << " " << ptD.z << endl;
}