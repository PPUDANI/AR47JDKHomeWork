﻿

#include <iostream>

// 함수의 선언방법
// 1. 다른 함수 내부에서는 함수를 선언하지 못한다.
// 2. 함수는 반환값이 무조건 존재한다.
// 3. 함수는 만들면 만들수록 느려진다. 
//    사실 가장 빠른건 main함수만 쓰는 것이다. 컴퓨터도 main함수로만 사용하려 함(절차지향인 C의 예시이며 C가 빠른 이유)
//    대신 이런 식으로 코딩하면 유지보수가 힘들다.

void Function() // [리턴값] [이름] (매개변수)
{ // 함수의 시작

} // 함수의 끝

// 함수도 변수와 똑같이 그에 대한 내용이있고, 메모리를 써서 그것을 표현하고 있다.
// 메모리가 존재한다면 그에 대한 위치도 무조건 필요하다.
// 위치를 나타낼 이름이 필요하다.
// 실행됬다면 모든건 RAM에서 내 프로그램이 실행된 프로세스 영역 안에 존재해야 한다.
// 이름은 주소(위치)로 해석이 된다.

// 인자(매개변수, 파라메터값, parameter)
// 무조건 적으로 그 실행흐름의 지역변수이다.

int Plus(int _Left, int _Right)
{
    return _Left + _Right;
}

// void
// 함수를 실행하는데 필요한 비용은 언제나 인자(매개변수)크기 + a(알파) 이다.
void Test(int _Value)
{
    // 아래 _Value는 Test스택 영역에서 처리된다.
    // Test::_Value
    _Value = 10;
    _Value *= 10;
    _Value -= 20;
    return;
}

int main()
{
    // return 값 만으로도 그 반환값의 메모리를 사용한 것이다.
    int Result = Plus(20, 30);

    // 이것도 똑같이 4바이트를 사용한 것이다.
    bool bResult = Plus(20, 30);
    
    // 이름이 같은 변수는 선언할 수 없다.
    // 하지만 아래와 같이 이름이 같은 변수가 생성될 수있는데
    // 아래 _Value는 main스택 영역에서 함수에 저장되고 처리된다.
    int _Value = 20;

    // 위 변수는 사실 'main::_Value'의 형태이다.
    // 결론적으로 같은 렘에 같은이름이 존재하지만 다른 stack 영역에 있어서 명확하게 서로 다르다는 것을 판단할 수 있다.

    Test(_Value);

    // 아래 코드는 사용할 수 있다.
    int PlusResultSize = sizeof(Plus(20, 30));

    // 아래 코드는 반환형이 void이기 때문에 반환값 메모리영역을 쓰지 않는다.
    // int TestResultSize = sizeof(Test(_Value));
}
