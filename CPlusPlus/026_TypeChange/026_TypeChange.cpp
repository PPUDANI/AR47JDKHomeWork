
#include <iostream>

int main()
{
    {
        // 모든 자료형은 특정한 상황이 아니거나 방법을 가리지 않는다면 언제나 바꿀 수있다.
        // 형변환은 눈에 보이지 않지만 단순히 메모리를 복사하는 것이 아니라 연산을 한다.
        // 잘라야 하면 자르고, 늘려야 하면 늘려서 비트를 변경하는 일이 된다.
        // 이를 암시적 형변환이라고 한다.
        bool bValue = true;
        int AValue = 1231564;

        AValue = bValue;
        int a = 0;
    }

    {
        // 아래와 같이 현변환이 안되느 것도 존재한다,
        int Value = 0;
        int* Ptr = nullptr;
        // Value = Ptr;
        // Ptr = Value;

        int Arr[10];
        // 아래는 자료형이 다른데 형변환이 된다/
        // 이를 암시적 형변환이라고 한다.
        //   int*     int[10]
        int* PtrArr = Arr;
        int a = 0;
    }

    {
        "aaaaa"; // const char*
        printf_s("aaaaaa"); // const char * const로 형변환이 되서 들어간다.
    }
}
