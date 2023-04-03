
#include <iostream>

// 이 함수도 프로세서로 메모리에 올라가기 때문에 위치가 있다.
// 이 위치는 정해져 있다.
void PlayerAttack()
{
    printf_s("플레이어가 공격합니다.");
}
void PlayerMove()
{
    printf_s("플레이어가 움직입니다.");
}
// 많이 어려운 개념
// 행동을 변수로 만드는 것

int main()
{
    // 리턴값 (함수포인터명)(인자)
    void(*Ptr)() = PlayerAttack;
    Ptr();

    Ptr = PlayerMove;

    Ptr();
}

