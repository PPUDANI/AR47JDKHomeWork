
// Debug 활용법

// 라인마다 값을 확인하려면 라인에 커서를 놓고 'F9' 키다운 or 원하는 줄의 줄 번호 왼쪽에 있는 바를 클릭하면 빨간색 원이 생김.
// 'F5'를 눌러 Debuging하면 줄마다 바뀌는 변수의 값을 확인할 수 있음.
// Debuging하면 빨간색 원에 화살표가 생기는데 해당 줄을 실행하기 전의 상태를 알 수 있음.
// 줄바꿈은 'F10'을 누르면 된다.

// 처음부터 'F10'을 누르면 똑같이 Debuging이 되는데 F5는 빨간 원부터 Debuging 하고, F10은 코드의 첫 줄 부터 Debuging 한다.

#include <iostream>

int main()
{
    int Left = 7;
    int Right = 3;
    int Result = 0;
    // 연산자의 종류는 아래와 같이 나뉜다.
    // 1. 단항 연산자 : 메모리 영역이 한 개만 필요한 연산자 (ex. +, -, ++, --, &, *, ^)
    // 2. 이항 연산자 : 메모리 영역이 두 개만 필요한 연산자 (ex. =, +, -. *, /, %, +=, -=, *=, /=, &&, || .etc)
    // 3. 삼항 연산자 : 메모리 영역이 세 개만 필요한 연산자 (ex. 조건연산자 ()? A:B)

    // RAM에서 CPU에게 'Left'와 '+' 연산자와 'Right'을 전달해준다.
    // CPU는 해당 프로세스를 연산하여 결과값을 RAM에게 리턴해준다. 

    // 1. 단항 연산자
    Result = -Left;
    Result = +Left;
    //전위 or 전치 연산자
    Result = ++Left;
    Result = --Left;
    //후위 or 후치 연산자
    Result = Left++;
    Result = Left--;


    // 2. 이항연산자
    // 산술연산자
    Result = Left + Right;
    Result = Left - Right;
    Result = Left * Right;
    Result = Left / Right;

    // 연산자 순서도 고려해야한다. (기본적인 사칙연산은 *, / 가 먼저 연산되고 +, - 가 연산된다.)
    Result = 1 + 2 * 3;

    // 연산자는 많고 모두 순서가 복잡하게 지정되어 있다.
    // 아래처럼 가로 연산자로 구분하면 편하다.(가독성도 높아짐)
    Result = (1 + 2) * 3;

    // bool이라는 자료형논리형이라고 부른다.
    // 논리형은 true, false의 값만가질 수 있다.
    bool bResult = true;
    bResult = false;

    // 비교연산자
    // 비교한 값은 참과 거짓으로 나뉨.
    bResult = Left == Right;  // same?
    bResult = Left != Right;  // not same?
    bResult = Left < Right;   // bigger?
    bResult = Left > Right;   // saller?
    bResult = Left <= Right;  // bigger or same?
    bResult = Left >= Right;  // smaller or same?

    // 논리연산자.
    // AND
    bResult = true && true;   // true
    bResult = true && false;  // false
    bResult = false && false; // false

    // OR
    bResult = true || true;   // true
    bResult = true || false;  // true
    bResult = false || false; // false

    // NOT
    bResult = !true;
}
