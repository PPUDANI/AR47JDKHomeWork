
#include <iostream>


void VarFunction(...) // 가변인자, 8byte씩 떨어져 있는것만 알면..~
{
}

void TestFunction1(int _1, int _2, int _3)
{
    int* ptr = &_1; 
    
}

// 이름을 넣지 않아도 인자로 사용할 수 있다.

void TestFunction2(int _1, ...) // 숙제
// 위 코드는 아래 코드와 같은 의미이다. 
// void TestFunction2(int _1, int, int, int, int, ...)
{
    int* Ptr = &_1;
    int count = 1;
    int arg = 0;
    while (count <= _1)
    {
        arg = Ptr[count * 2];
        count++;
    } 
}

int main()
{
    // 매개변수에 ...을 적어주면 인자를 무한으로 넣을 수 있다.
    VarFunction(1, 2, 3, 4, 5, 6, 7, 8);
    VarFunction("1", '1', 1);

    TestFunction2(5, 123, 412, 43, 6, 15);

    // %를 사용하게 되면 이는 포멧팅 문자
    // 숫자난 다양한 다른 변수들을 사용해서 출력을 요청하는 것이다.
    //printf_s("%d %d %d", 1); (출력은 되지만 잘못된 사용이다.)

    printf_s("%d %s", 1, "으아아");


}
