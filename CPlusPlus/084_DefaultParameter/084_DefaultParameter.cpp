// 084_DefaultParameter.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

// 매개변수 디폴트로 매개변수가 들어가지 않을 경우 0으로 초기화
void Function(int _Value = 0)
{
    std::cout << _Value << std::endl;
}

// 이처럼 디폴트 인수는 가장 오른쪽에 만들어야 한다.
// 하지만 위 Function()의 오버로딩 문제가 발생
// void Function(int _Value = 0, int _Test)
void Function(int _Test, int _Value = 0)
{
    std::cout << _Value << std::endl;
}

int main()
{
    Function(10); // <- 무엇을 오버로딩 해야할지 모른다.
    Function();
    Function();
    Function();
    Function();
}
