

#include <iostream>

int main()
{
    // 삼항 연산자
    // a ? b : c

    // 조건연산 ? 참일때 메모리 : 거짓일 때 메모리

    int Left = 7;
    int Right = 3;
    int Result = 0;

    Result = (Left != Right) ? 100 : 200; // 100
    Result = true ? 100 : 200; // 100
    Result = false ? 100 : 200; // 200
    // RAM에 올라간다면 삼항 전부 올라가야된다.
    // 100도 있어야 연산이 가능하다.
    // 메모리 어딘가에 저장되어 있다.

    // sizeof연산자 단항 연산자
    // () 안에 있는 메모리영역의 바이트 크기를 리턴합니다.
    // sizeof(메모리영역)
    // sizeof(int 영역)
    Result = sizeof(int); // 4
    Result = sizeof(bool); // 1
    Result = sizeof(Left); // 4
}
