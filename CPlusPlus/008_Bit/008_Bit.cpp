﻿

#include <iostream>

int main()
{
    int IValue = 0;
    unsigned int UValue = 0;

    IValue = 2;

    // 값에 0b를앞에 붙이면 이진수로 변수값을 넣을 수 있다.
    IValue = 0b00000000000000000000000000000001; // 1
    IValue = 0b00000000000000000000000000000000; // 0


    // int는 32bit로 정수 최대 범위는 -2,147,483,648 ~ 2,147,483,647 이다. (2^31 = 2,147,483,647)
    // int는 32bit이지만 음수 표현을 위해 맨 앞의 bit는 부호bit로 사용하여 0은 '+', 1은 '-'가 된다.
    // 그런데 아래를 보면 31개의 숫자bit가 범위를 넘어선 값이 된다면 부호bit가 올라가게된다.
    // 이렇게 되면 음수의 최대값인 -2,147,483,648 로 결과가 나온다.(Overflow issue)
    
    IValue = 0b01111111111111111111111111111111; // +2,147,483,647 (2^31 = 2,147,483,647)
    IValue++;                                    // -2,147,483,648 (Overflow issue)

    // 그 이유는 이진수 연산이 만들어진 과정을 보면 이해할 수 있다.

    // 1. 일단 첫 번째 규칙은 맨 앞 bit는 부호비트로 쓴다는 것이다.

    // 지금부터 4bit로 연산을 해보겠다. (부호bit 제외 최대 수 = (0 111)7)
    // 만약 '1 001(-1)' + '0 010(+2)'를 하면 '0 001(+1)'이 나와야한다.
    // 하지만 '1 011(-3)'이 나오게 되었다.

    // 우리가 원하는 연산을 하기위해 편의성을 부여한 것이 음수의 비트를 반전시키는 방법이다.(1의 보수)
    // -1을 표현한다면 아래와 같이 숫자bit를 반전시켜서 사용한다.
    // 신기하게도 위와 같이 음수는 반전하여 계산하면 계산이 가능하다.

    // 0 001 -> 1 110 (숫자bit 반전)

    // 이제 우리는 1 110을 -1로 생각하기로 했다. 계산해보자

    // 1 110(-1) + 0 010(+2) = [1]0 000
    
    // 실제론 10000이 되는데 5자리이므로 앞자리는 떼주어야 한다.
    // 앞자리를 떼어야 하는 이유는 4자리수 연산을 가정하여 맨 앞자리를 부호bit로 정했기 때문이다.
    // 만약 부호비트 이상으로 자리수가 올라가면 당연히 위 논리의 연산이 불가능하다.
  
    // 위 결과값를 보면 우리가 알고있는 -1 + 2 = 1이 나와야하는데 0000(0)이 나온다.
    // 위 연산 뿐만 아니라 다른 모든 연산에서도 1의 오차가 생겨버리는 문제가 생긴다.
    // 그 이유는 명확하다. 이유는 우리가 알고있는 0은 한 개인데 위 연산규칙 으로 0이 두 개가 생겨버린 것이다. ( 0000(+0), 1111(-0) )
    // 이 문제는 간단하게 해결하였다.
    // 결과에 1을 더해주어 양수를 1씩 밀어버린 것이다. (2의 보수)
    // 그럼 수식은 아래와 같다.
    // 
    // 1111(-1) + 0010(+2) = 0001(1)
    // 그리고 밀어버리고 남은 1111(-0)은 음수를 하나 추가하기로 하여 1111은 -1이 된다.(최대 숫자: 7, 1000 -> -8 )

    // int의 범위가 왜 -2,147,483,648 ~ 2,147,483,647 인지 알았고,
    // '2,147,483,647'에 '1'을 더하면 '-2,147,483,648'가 나오는 현상의 이유를 알았다.(Overflow)
    // 여기서 Overflow의 오류는 막을 수 없다.
    // 그래서 수가 Overflow가 발생하지 않도록 충분한 공간의 자료형을 사용해야한다.


    IValue = 0b00000000000000000000000000000000; //  0
    IValue = 0b11111111111111111111111111111111; // -1
    IValue = 0b11111111111111111111111111111110; // -2
    
}
