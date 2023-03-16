
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
        int Value0 = 10;
        int Value1 = 20;

        // 참조형(Reference)
        // 선언 시 무조건 누군가를 가리켜야 한다. (null값을 가질 수 없음. 즉 무조건 갚이 있어야 함.)

        // ex) int& Ref; (선언 시 가리키지 않아서 오류가 난다)

        // 한번 초기화 시 다른 참조하는 메모리를 변경할 수 없다.
        int& Ref = Value0;

        // 래퍼런스의 특징은 아래와 같다.
        // Ref를 고쳐도 Value0가 고쳐지고 Value0를 고쳐도 Ref가 고쳐진다.
        // 결론적으로 Value0에 Ref라는 이름으로도 부른다는 뜻이 된다.
        Ref = 100; // Ref == 100, Value0 == 100


        // 포인터는 언제든지 자신이 참조하는(가리키는) 대상을 바꿀 수 있다.
        // 포인터는 null값을 가질 수 있다.
        int* Ptr = &Value0;
        Ptr = &Value1;

        int a = 0;
    }


    {
        int Value0 = 10;
        int Value1 = 20;

        // 아래 코드는 어셈블리어로 보면 정확히 같은 연산이란 것을 볼 수 있다.
        // 단순히 컴파일러가 문법으로 구분했을 뿐이다.
        // 'Ref'는 '*Ptr'과 연산까지 완벽히 같다.

        // 포인터
        int* Ptr = &Value0;
        *Ptr = 100;
        *Ptr = Value1;

        // 참조형
        int& Ref = Value0;
        Ref = 100;
        Ref = Value1;

        int a = 0;
    }



    {
        // 참조형은 가리킬 변수의 자료형과 같아야 한다.
        int Value0 = 0;
        __int64 Value1 = 0;

        int& Ref = Value0;
        __int64& Ref64 = Value1;

        int RefSize = sizeof(Ref); // 4byte이다.
        int RefSize64 = sizeof(Ref64); // 8byte이다.

        int a = 0;
    }

    
    int ItemEquip = 0;
    EquipPtr(&ItemEquip);
    EquipRef(ItemEquip); // 상수는 넣을 수 없고 무조건 변수를 매개변수로 넣어주어야 한다.

    constEquipRef(2000); // const를 래퍼런스값으로 사용하기 때문에 값이 바뀌지 않는다.

    // 참조형은 인수의 값을 수정하려는 경우나 인수의 비싼 복사본을 만들지 않으려는 경우 함수 매개변수로 자주 사용된다.
    // 래퍼런스값으로 프로그래머들에게 값이 바뀌는 함수인지 명시하여 가독성도 높아진다.

}
