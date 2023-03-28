
#include <iostream>

// 다형성

// 매개변수값에 따라 함수는 같은 이름을 가질 수 있다.
// 하지만 반환형이 다른 같은 이름을 가진 함수는 쓸 수 없다.
// Function
void Function()
{
    printf_s("void Function()\n");
}

// Functionint
void Function(int _Value)
{
    printf_s("void Function(int _Value)\n");
}

void Function(short _Value)
{
    printf_s("void Function(short _Value)\n");
}

int main()
{
    Function();
    Function(10);
    Function((short)10);
}
