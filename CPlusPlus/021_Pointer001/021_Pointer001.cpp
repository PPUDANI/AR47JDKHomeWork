
#include <iostream>

int main()
{
    {
        int Value0 = 10;
        int Value1 = 10;

        int* ValuePtr0 = &Value0;
        int* ValuePtr1 = &Value1;
        __int64 Address0 = (__int64)ValuePtr0; // 주소가 32byte씩 차이가 난다.
        __int64 Address1 = (__int64)ValuePtr1; // 
        int Debug = 3;
        // 해당 스코프가 같은 스택 영역에 저장되므로 메모리 주소가 멀지 않게 저장된다.

    }

    {
        int Arr[3] = {};

        int* ValuePtr0 = &Arr[0];
        int* ValuePtr1 = &Arr[1];
        int* ValuePtr2 = &Arr[2];

        __int64 Address0 = (__int64)ValuePtr0; // 배열은 메모리에 붙어서 저장된다. 
        __int64 Address1 = (__int64)ValuePtr1;
        __int64 Address2 = (__int64)ValuePtr2;
        int a = 3;
    }


}
