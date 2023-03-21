
#include <iostream>


//{
//    해덩 스코프(지역) 안에 만들어지는 변수는 지역 내에서만 쓸 수 있다.
//}


int GlobalValue = 0; // 전역변수 : 스코프 밖에서 선언한 변수는 모든 영역에서 사용이 가능하다.

int Function()
{
    return GlobalValue++;
}

int main()
{ // 지역의 시작

    Function();
    int Value = 0; // 지역변수

} // 지역의 끝
