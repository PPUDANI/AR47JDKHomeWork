
#include <iostream>

int main()
{
    {

        // signed int 는 그냥 int와 같이 부호bit로 음수 양수를 구분한 정수 자료형이다.
        // '~'는 bit not 연산자로 0이라고 쓰면 컴파일러는 이를 0의 왼쪽 나머지 비트를 전부 0으로 추가함.
        // 이후 bit not 연산자로 0 32개를 1 32개로 만든다.
        // 고로 아래 Value의 값은 -1이 된다.
        signed int Value = ~0;
        int a = 0;
    }

    {
        // 그냥 int라면 -1 이였겠지만, unsigned는 음수 사용을 하지않고 양수를 두 배로 쓰겠다는 의미이다.
        // 고로 위 연산과 같이 전부 1로 바뀌므로 4,294,967,295의 값이 된다.
        unsigned int Value = ~0;
        
    }
}
