
#include <iostream>

void ValueChange(int* Ptr)
{
    *Ptr = 0;
}
int main()
{
    {
        int Value = 10;

        int* Ptr = &Value;

        // 그 위치의 메모리르 사용하겠다.
        // 포인터 변수의 앞에 *을 붙이는 연산자는
        // *Ptr 주소에 있는 값을 20으로 바꿔라
        *Ptr = 20;

        // 해당 스코프 안의 변수의 값을 함수를 통해 바꾸기 위해선
        // 바꾸고싶은 변수의 주소값을 매개변수로 주면 된다.

        ValueChange(&Value);
        ValueChange(Ptr);
    }

    {
        // 포인터도 선언하면 그 값이 또 다른 주소에 저장한다.
        // 아래와 같이 주소가 저장된 주소를 또 주소로 저장할 수도 있다.
        int Value = 10;

        int* Ptr = &Value;

        int** PtrPtr = &Ptr;

        // 게임에서 포인터를 쓰는 용도를 간단히 설명하면 아래와 같다.
        // 몬스터가 데미지를 받을 땐 단순히 변수에 -를 하는것이 아니라 함수를 사용한다.
        // 이때 함수를 사용할 때 지역변수값을 함수가 바꿀 수 없으니 포인터를 사용한다.

    }
}
