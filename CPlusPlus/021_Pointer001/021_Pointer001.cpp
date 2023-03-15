
#include <iostream>

int main()
{
    {
        int Arr[3] = {};
        int Value0 = 10;
        int Value1 = 10;
        int* ValuePtr0 = &Arr[0];
        int* ValuePtr1 = &Arr[1];
        int* ValuePtr2 = &Arr[2];

        __int64 Address0 = (__int64)ValuePtr0;
        __int64 Address1 = (__int64)ValuePtr1;
        __int64 Address2 = (__int64)ValuePtr2;

    }
}
