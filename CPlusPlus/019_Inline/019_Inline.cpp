
#include <iostream>


inline void Test()
{
    printf_s("Function");
}
int main()
{
    Test();
    // 'inlien'은 Test();자리에 Test()함수의 내용을 복붙한다.
    // 함수를 사용할 수록 프로그램이 느려지기 때문에 사용하는 기능이다.
    // 함수를 복붙하는 느낌으로 스택을 만들지 않도록
    // 최적화할 수 있다면 해달라는 코드이다.
    //Tests
}
