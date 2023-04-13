

#include <iostream>
class B;
class A
{
    //특정 클래스에게 자신의 접근제한 지정자를 취소시키는 문법
    // 이걸 쓰면 객체지향을 깨는 문법이다.
    // C#, JAVA는 이 문법이 존재하지 않는다.
    // C++은 멀티 패러다임 언어이다.
    // C++은 객체지향 언어가 아님. 그러니 필요하면 쓰자.
    // 대신 최소한으로 쓰자

    friend B;
private:
    int Value;
};

class B
{
public:
    void Function(A& _Other)
    {
        _Other.Value = 20;
    }
};
int main()
{
    A NewA;
    B NewB;

    std::cout << "Hello World!\n";
}
