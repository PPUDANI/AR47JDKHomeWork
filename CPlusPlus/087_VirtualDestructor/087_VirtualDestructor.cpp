
#include <iostream>
class A
{
public:
    A() 
    {

    }

    // 소멸자의 특수성
    // ~컴파일러는 소멸자의 이름을 ~로 생각한다. (~A 도 ~, A를 상속받은 ~B도 ~ 임)
    // virtual을 붙이지 않으면 일반적인 함수와 동일하게 판단한다.
    // this 인자로 인한 문제이다.
    // 부모의 virtual을 붙인다.
    virtual ~A()
    {

    }
};
class B : public A
{
public:
    B()
    {

    }
    ~B()
    {

    }
};

int main()
{
    std::cout << "Hello World!\n";
}
