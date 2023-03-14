﻿
#include <iostream>

// 함수의 스택에서의 메모리 크기는 컴파일 시 고정되어야 하기 때문이다,
// ex) C++의 함수의 실행흐름을 만들기 위한 스택 크기는
// exe 파일에 이미 다 정의되어 있어야 한다.
int main()
{
    int ArrSize = 20;
    // 그 메모리의 비트적 상수화를 시킨다.
    // 말 그대로 상수이므로 값을 바꿀 수 없는 변수이다.
    // const는 코드영역에 존재한다.

    const int ci = 30;
    const bool cb = true;
    const char cc = 'a';

    "skrr"; // 이것도 const로 만들어짐, 이딴 코드는 컴파일러 최적화가 된다.


    // 배열 크기는 상수만 넣을 수 있다.
    // VS에서 컴파일 시 배열의 최대 크기는 2MB이다.
    // JAVA나 파이썬은 구성이 달라서 가능함. (팩트체크)
    // int Valuep[ArrSize] = {}; <- 오류남
    int Valuep[ci] = {}; // const는 가능

}
