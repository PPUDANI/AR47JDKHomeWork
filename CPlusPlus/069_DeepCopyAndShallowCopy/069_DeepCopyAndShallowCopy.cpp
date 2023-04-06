
#include <iostream>

int main()
{
    int* Newint0 = new int();
    int* Newint1 = Newint0;

    if (nullptr != Newint0)
    {
        delete Newint0;
        Newint0 = nullptr;
    }
    std::cout << "Hello World!\n";
}