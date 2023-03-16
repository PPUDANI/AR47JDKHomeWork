
#include <iostream>

int main()
{

    // 반복문
    // 가장 오른쪽에 있는 메모리영역의 값만을 조건으로 친다. (조건문)
    // 조건문이 참이면 반복하고 거짓이면 실행하지 않고 넘어간다.

    int Value = 10;
    while (printf_s("조건문"), true) // while(메모리영역, 조건문)
    {
        // 실행코드
        --Value;
        printf_s("실행코드");
    }
     
    Value = 10;
    do
    {
        --Value;
        printf_s("실행코드");
    } while (printf_s("조건문"), Value);

}
