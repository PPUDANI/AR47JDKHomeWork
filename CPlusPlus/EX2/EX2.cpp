
#include <iostream>

int main()
{
    int a[2] = { 0b0000000000000000000000000000000001, 0b0000000000000000000000000000000001 };

    int* Ptr = &a[0];
    __int64 Address = (__int64)Ptr;
    
    int* Ptra0 = (int*)Address;

    int* Ptra1 = (int*)(Address + 1);

    int aa = 00000000000000000000000100000000;

    printf_s("주소0 : %d\n", *Ptra0);
    printf_s("주소1 : %d\n", *Ptra1);
    printf_s("주소2 : %d\n", aa);
}
