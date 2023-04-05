

#include <iostream>
// #include <crtdbg.h> iostream에 내장되어있음.

int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    {
        // 
        int* Newint = new int();
        Newint = new int();
        delete Newint;
    }

    // 한계에 다다르면 new를 해도 null이 나온다.
    // 그럼 운영체제가 할등을 못하면 null을 반환한다.
    {
        
        int* Newint = new int();
        
        if (nullptr == Newint)
        {
            return;
        }

        delete Newint;
    }

    // 지운거 또지우기. 댕글링포인터라고 한다.
    //
    {
        int* Newint = new int();
        delete Newint;
        // 메모리 크러쉬
        delete Newint;
    }

    //해결책
    {
        int* Newint = new int();

        if (nullptr != Newint)
        {
            delete Newint;
            Newint = nullptr;
        }

        if (nullptr != Newint)
        {
            delete Newint;
            Newint = nullptr;
        }
    }
}

