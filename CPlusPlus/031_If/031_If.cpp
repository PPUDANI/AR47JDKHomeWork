
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

    // else if, \\\else
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


}
