
#include <iostream>

class Test
{
public:
    int a = 0;

    class PublicClass
    {
    public:
        static int Geta()
        {
            return a;
        }
    private:
        static int a;
    };
    int PublicClass::a = 3;

    //int Geta()
    //{
    //    return a;
    //}
};
int main()
{
    Test newObject{};
    printf("Test: %d\n PublicClass: %d", newObject.a, Test::PublicClass::Geta());
}
