
#include <iostream>

void TestFunction(int _1, ...)
{
    int* Ptr = &_1;
    int count = 0;
    int arg = 0;
    while (_1--)
    {
        *Ptr += 2;
        arg = *Ptr;
    }
}

int main()
{
    int Value = 0;
    int* Ptr = &Value;
    __int64 Address = 0;
    // Ptr이 가리키는 자료형이 int이므로 Ptr에 1을 더해주면 아래와 같다.
    // 100 -> 104
    Ptr += 1;
    Address = (__int64)Ptr; // 100
    Ptr += 1;
    Address = (__int64)Ptr; // 104
    Ptr += 1;
    Address = (__int64)Ptr; // 108
    Ptr += 1;
    Address = (__int64)Ptr; // 112
    int a = 0;

    TestFunction(5, 2, 3, 4, 5, 6);
}
