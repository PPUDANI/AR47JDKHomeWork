
#include <iostream>

void EquipPtr ( int* Ptr )
{
    *Ptr = 100;
}

void EquipRef ( int& Ref )
{
    Ref = 200;
}

void constEquipRef(const int& Ref)
{
    // Ref = 200;
}

int main()
{
    {
        // Reference
        // 대부분의 언어에서 참조라는 것은 특정 메모리 영역의 위치를 가리킨다는 의미이다.

        int Value0 = 10;
        int Value1 = 20;

        // 포인터형
        // 포인터는 언제든지 자신이 참조하는(가리키는) 대상을 바꿀 수 있다.
        int* Ptr = &Value0;
        Ptr = &Value1;

        // 포인터 연산자를 통해서 다양한 행위를 할 수 있다.
        *Ptr;


        // 참조형(Reference)
        // 선언 시 무조건 누군가를 가리켜야 한다.
        // ex) int& Ref; (선언시 가리키지않아서 오류가 난다)
        // 한번 초기화 시 다른 참조하는 메모리를 변경할 수 없다. (시도해보면 문법 구조상 안된다는 걸 알 수 있음.)

        // 이는 다르게 말하면 *Ptr; <- 항상 이걸 쓰는 포인터이다.

        int& Ref = Value0;
        Ref = 100; // Ref == 100, Value0 == 100

        // Ref를 고쳐도 Value0가 고쳐지고 Value0를 고쳐도 Ref가 고쳐진다.
        // 결론적으로 Value0에 Ref라는 이름으로도 부른다는 뜻이 된다.

    }


    {
        int Value0 = 10;
        int Value1 = 20;

        // 아래 코드는 어셈블리어로 보면 정확히 같은 연산이란 것을 볼 수 있다.

        // 포인터
        int* Ptr = &Value0;
        *Ptr = 100;
        *Ptr = Value1;

        // 참조형
        int& Ref = Value0;
        Ref = 100;
        Ref = Value1;

    }


        EquipPtr(nullptr);
        int ItemEquip = 0;
        EquipRef(ItemEquip); // 상수는 넣을 수 없고 무조건 변수를 매개변수로 넣어주어야 한다.

        constEquipRef(2000); // const를 래퍼런스값으로 사용하기 때문에 값이 바뀌지 않는다.

        // 참조형은 인수의 값을 수정하려는 경우나 인수의 비싼 복사본을 만들지 않으려는 경우 함수 매개변수로 자주 사용된다.
        // 래퍼런스값으로 프로그래머들에게 값이 바뀌는 함수인지 명시하여 가독성도 높아진다.

    {
        int Value = 0;
        int& Ref = Value;
        int RefSize = sizeof(Ref); // 4byte이다
        int a = 0;
    }
    
}
