
#include <iostream>

int main()
{
    int Left = 3;
    int Right = 7;
    int Result = 0;
    // 연산자의 종류는 아래와 같이 나뉜다.
    // 1. 단항 연산자 : 메모리 영역이 한 개만 필요한 연산자 (ex. &, *, ^)
    // 2. 이항 연산자 : 메모리 영역이 두 개만 필요한 연산자 (ex. =, +, -. *, /, &&, || .etc)
    // 3. 삼항 연산자 : 메모리 영역이 세 개만 필요한 연산자 (ex. ? A:B 맞나..)
    
    // RAM에서 CPU에게 Left와 + 연산자와 Right을 전달해준다.
    // CPU는 해당 프로세스를 연산하여 결과값을 RAM에게 리턴해준다. 
    Result = Left + Right;
    Result = Left - Right;
    Result = Left * Right;
    Result = Left / Right;

}
