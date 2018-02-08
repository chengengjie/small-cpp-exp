#include <iostream>
#include <memory>

using namespace std;

class MyClass {
public:
    int id;
    MyClass() {
        static int globalId = 0;
        id = globalId++;
        cout << "construct MyClass " << id << " ..." << endl;
    }
    ~MyClass() {
        cout << "destruct MyClass " << id << " ..." << endl;
    }
};

int main() {
    shared_ptr<MyClass> MyEmptyPtr;
    cout << MyEmptyPtr << endl;
    MyClass MyObject;
    {
        shared_ptr<MyClass> MyPtr1(&MyObject);
        cout << MyPtr1 << endl;
        shared_ptr<MyClass> MyPtr2 = MyPtr1;
        cout << MyPtr2 << endl;
    }
    cout << MyObject.id << endl;    // already destructed
    shared_ptr<MyClass> MyPtr3(new MyClass());
    return 0;
}