

#include <iostream>

int main()
{

    // 문자열 상수 표현식 : 문자열은 '\0'(NULL)문자가 포함이 되어야함.
    // NULL문자 '\0'는 NULL값, 숫자 0, false로 대체 가능함.

    char Arr[6] = "12345"; // 알아서 NULL문자가 포함되는 초기화 방식
    char Arr2[6] = { '1', '1', '1' , '1' , '1'}; // NULL문자가 포함되지 않는 초기화 방식
    

    char Arr2[6] = { '1', '1', '1' , '1' , '1', }; // index의 0, 1, 2, 3, 4 에 문자 '1'을 넣고 나머지는 0이 들어가서 NULL문자로 인식한다.

    // 제로 베이스 기반인덱스 표현
    char ch = Arr[0];
    ch = Arr[1];
    ch = Arr[2];

    // printf_s() : NULL값, 숫자 0, NULL문자 '\0', false가 나올 때 까지 출력하는 함수
    printf_s(Arr2); // Arr2의 배열 초기화는 Null값이 포함 되어있지 않아서 오류가 난다.
}

