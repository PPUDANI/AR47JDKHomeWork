
#include <iostream>

int main()
{
    // 모든 자료형은 모두 다 배열이 될 수 있다.
    {
        int ArrValue[5] = {};
        int ArrValue2[5] = { 0, }; // 0에 0을넣고 나머지는 0으로 채움
        int ArrValue3[5] = { 1, }; // 0에 2을넣고 나머지는 0으로 채움
        int ArrValue4[5] = { 1, 2, }; // 0에 1, 1에 2를 넣고 나머지는 0으로 채움

        //          index =  0   1   2   3   4
        //    ex) address = 100 104 108 112 116

        int ArrValue5[5] = { 1,  2,  3,  4,  5 };
        // ArrValue5[i]
        // ArrValue5의 100 + sizeof(자료형) * i 번지와 같다.
        // ArrValue5[4] = 100 + 4 * 4 = 116번지

        // Java같은 경우는 즉각접근을 최대한 막고
        // C#은 UnSafe존이 있어 위험함을 알리기도 한다.
        // 위 언어들과 같은 경우는 프로그래밍의 위혐 요소를 막아준다.
        // 그런데 C++은 RAM에 즉각 접근이 가능해서 빠르다.
        // 반대로 위험한 언어이기도 하다.
        // 예로 RAM에 운영체제가 올라가있는데 운영체제가 사용하는 공간에 C++로 접근하면 크러쉬가 날 수도 있다.
        // 즉 어디를 건들지 알 수 없다는 것이다.

        // int c = ArrValue5[-15915243451]; // 이 코드를 컴파일 해보면 예외가 발생한다.
    }

    {
        char ArrValue[11] = "0123456789";
        
        // ArrValue[0]
        // ArrValue[1]
        // ...
        // ArrValue[10]
    }

    // 문자의 배열은 축약형 표현을사용할 수 있다.
    {
        char ArrValue[3] = { 'A', 'B', 'C' };
        char ArrValue2[4] = "ABC"; // NULL문자 포함(\0)

    }
}
