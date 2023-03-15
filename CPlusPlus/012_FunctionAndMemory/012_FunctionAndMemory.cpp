﻿
// RAM에서 프로세스가 저장되는 구조
// 4가지 영역으로나뉨.
// 1. 코드 영역 (상수, 코드)
// 2. Memory 영역
// 3. Heap 영역 (전역변수, 동적 메모리)
// 4. Stack 영역 (지역 변수, 배열)

#include <iostream>


// 내가 나만의 실행흐름을 만들고
// 해당 실행흐름에 이름을 붙일 수도 있다.
void Function()
{
    return;
}


// main scope(범위), 메인 실행흐름
int main()
{
// 함수의 시작
// 실행 흐름의 시작
    
    // 스코프
    // 실행 흐름의 시작과 끝을표현하는 기호. '{', '}'
    // 이름이 있는 실행흐름 안에서만 만들 수 있다.

    //Unname scope(범위) , 이름없는 실행흐름, 
    {
        int Value = 100; // 지역변수라 하며 해당 실행흐름 밖에선 쓸 수 없다.
    }
    {
        int Value = 100; // 지역변수라 하며 해당 실행흐름 밖에선 쓸 수 없다.
    }
    // 위 실행흐름은 처음 Value가 사라지고 다시 Value를 생성하기 때문에 


    // 함수를 실행하는 방법은 아래와 같다.
    Function();


    // 'F11'은 실행흐름 내부로 들어갈 수 있다.
    // 'F10'은 그 실행흐름을 한번에 다 실행 해버리는 용도이다.

}
// 함수의 끝
// 실행 흐름의 끝