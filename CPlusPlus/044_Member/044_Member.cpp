
#include <iostream>

// C++ 에서 영역에 대한 구분은 전역, 지역, 멤버 가 있다.
// 어느 영역(스코프) 에도 속하지 않는 곳을 '전역'이라고 한다.

// 전역변수 : GlobalValue
int GlobalValue = 0;

// 전역함수 : main(), GlobalFunction()
int GlobalFunction()
{
    return 0;
}

// 사용자의 정의로 만들어진 자료형 내부의 공간을 멤버공간이라고 한다.
class Player
{
public:
    void Damage() 
    {
        // 지역
        int Value = 0; // 지역변수
    }
private: // default가 private이지만 명시적으로 선언하는게 가독성에 좋다.
    int Hp;
     // 멤버변수

};
int main()
{
    int Value = 0; // 지역변수
}