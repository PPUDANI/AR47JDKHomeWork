
#include <iostream>

#define TEN 10;
#define TEN1 10

// 메크로함수
// 일반 함수는 자료형에 의한 컴파일 체크를 하지만
// 메크로함수는 해당 코드 복붙이다.
#define PLUS(_Value) _Value + _Value

#define PLUS2(_Value, _Value2) _Value + _Value2

int Plus(int _Value)
{
    return _Value + _Value;
}

int main()
{

    
    // TEN* TEN;
    // 10; * 10;

    TEN1* TEN1;
    // 10 * 10;
    Plus(10);

    std::cout << "Hello World!\n";
}
