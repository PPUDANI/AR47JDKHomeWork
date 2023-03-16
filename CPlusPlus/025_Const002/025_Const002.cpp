
#include <iostream>

int main()
{
    // 
    int Value0 = 10;
    int Value1 = 10;
    const int* cPtr = &Value0;
    
    // const int*
    // Ptr == const int*
    // *Ptr == const int
    {
        int Value = 1;
        const int* cPtr0 = &Value1; // 해당 주소에 저장된 값을 const화 시킨다.
        int* const cPtr1 = &Value1; // 포인터가 바뀌지 않는다는 의미이다. (Reference '&'와 같다고 볼 수 있음)

        *cPtr1 = 3; // 값은 바꿀 수 있지만 주소는 바꿀 수 없다.
        // *cPtr0 = 3; (값을 바꿀 수 없다.)
        

        // *을 기점으로 앞은 가리킬 주소에 저장된 변수의 자료형
        // 뒤는 주소값을 바꾸지않겠다는 의미
    }
    

    // const 변수는 고칠 수 없다.
    // 아래 코드와 완전히 동일하다.
    // const 만든 놈이 잘못 만들었다.
    // 앞 뒤에 붙인다고 의미가 달라지지 않는다.
    const int Value1 = 30; 
    int const Value2 = 30;
    const int const Value3 = 30;
}

