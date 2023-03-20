
#include <iostream>
#include <conio.h>


int main()
{
    // 컴퓨터가 랜덤으로 변수를 저장하므로 랜덤 seed값을 반환할 수 있음.
    unsigned int Val = 0;
    srand((unsigned int)&Val);


    // srand((unsigned int)time(NULL));

    // time은 정수형의 초를 반환해주는데 1초에 100번 반환을 한다면 100번은 똑같은 출력이 나온다.
    // 그래서 기본적으로 자주 사용되는 seed 값이지만 랜덤 seed 값으로는 적합하지는 않다.
    while (true)
    {
        printf_s("%d\n",rand() % 30);
        _getch();
    }
}
