
#include <iostream>

//  <생성자>
// 생성자는 객체가 생성될 때 자동으로 한번 호출된다. 
// 생성자가 호출될 때 객체의 메모리가 생기며, 생성자에서 값을 초기화할 수도 있다.

//  <소멸자>
// 소멸자는 프로그램이 종료될 때 자동으로 객체가 소멸할때 호출된다.
// 매개변수(인자)를 넣어줄 수 없다.
class A
{
public:
    __int64 Test;

    // 생성자
    A()
    {
        printf_s("A 생성자\n");
    }

    // 소멸자
    ~A()
    {
        printf_s("A 소멸자\n");
    }
};

class B : public A
{
public:
    char Value;

    // 생성자
    B()
    {
        printf_s("B 생성자\n");
    }

    // 소멸자
    ~B()
    {
        printf_s("B 소멸자\n");
    }

};
int main()
{
    B NewB;
    int Value = sizeof(B);

    //NewB.~B(); 호출이 가능하긴 한데 의미도 없으니 하지마셈

    int a = 0;

}

