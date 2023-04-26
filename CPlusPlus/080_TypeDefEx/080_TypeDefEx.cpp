
#include <iostream>

typedef int MYINT, * MYTEST;

// c++은 C의 문법을 거의 다 사용할 수 있다.
// C++은 C를 포함한다? -> 완 전 개소리이다.
// C++은 C가 개발되는 도중 다른 길로 샌 언어라서 완전히 다른 언어라고 생각해야한다.

// C와 C++의 차이는 
// C의 구조체는 멤버함수를 넣을 수 없다.
struct MyStruct0
{
    int a;
};

typedef struct MyStruct0 Player0;

// 위 코드의 축약형이다.
struct MyStruct1
{
    int a;
} Player1, Test, * PPlayer1;

int main()
{
    MYINT a = 0;
    MYTEST ptr = &a;

    // C 는 struct를 무조건 붙여야 한다.
    struct MyStruct0 NewStruct;

    // 이를 없애는 방법은 typedef를 사용할 수 있다.
    Player0 NewStruct0;

    // C++은 struct를 붙이지 않아도 된다.
    MyStruct0 NewStruct;
}

