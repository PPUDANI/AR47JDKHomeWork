
#include <iostream>

int ReturnValue()
{
    return 10;
}
int main()
{
    // if(메모리 영역)
    //{
    //    실행코드
    //}
    // 참이면 실행코드가 실행됨.
    // 거짓으면 실행되지 않음.

    int Value = 0;

    if (ReturnValue())
    {
        printf_s("asd");
    }

    // 한줄치기 극혐(ㅇㅈ)
    if (ReturnValue()) 
        printf_s("으아앙");

    // else if : 위에 조건이 만족하지 않으면 
    // else : 모든 조건이 만족하지 않을 때
    if (Value == 1)
    {
        printf_s("으아앙");
    }
    else if(Value == 2)
    {
        printf_s("그어엉");
    }
    else if (Value == 3)
    {
        printf_s("크아앙");
    }
    else
    {
        printf_s("끄어얽");
    }


    if (ReturnValue(), 0) // 코드가 실행되긴 하는데 맨 오른쪽 코드를 사용함.
    {
        printf_s("asd");
    }

    // 단축키
    // if를 치고 tap을 누르면 함수가 자동으로 완성된다.
    // 다른 문도 마찬가지
    // swi
    // whi
    // for


}
