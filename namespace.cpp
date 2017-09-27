namespace A
{
    class Wheel
    {
    public:
        int size = 10;
    };
}

namespace B
{
    using namespace A;
    class Car
    {
    public:
        Wheel wheel;
    };
}

// namespace C
// {
//     class Car
//     {
//     public:
//         using namespace A;
//         Wheel wheel;
//     };
// }

int main()
{
    B::Car myCar;
    B::Wheel myWheel; // Wheel in namespace A is propagated to B

    return 0;
}