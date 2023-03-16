
#include <iostream>


void VarFunction(...) // 가변인자, 8byte씩 떨어져 있는것만 알면..~
{

}

void TestFunction1(int _1, int _2, int _3)
{
    int* ptr = &_1;

    Arr[10];
    
}
void TestFunction2(int _1)
{

}
int main()
{
    // 매개변수에 ...을 적어주면 인자를 무한으로 넣을 수 있다.
    VarFunction(1, 2, 3, 4, 5, 6, 7, 8);
    VarFunction("1", '1', 1);
    printf_s("123");

    TestFunction1(10, 20, 30);
}
