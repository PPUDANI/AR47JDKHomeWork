
#include <iostream>

void MyPrintfArr(const char* const Ptr)
{
    putchar(Ptr[0]); // 문자 하나를 출력하는 함수
    putchar(Ptr[1]);
    putchar(Ptr[2]);
    putchar(Ptr[3]);
    putchar(Ptr[4]);
    putchar(Ptr[5]);
    putchar(Ptr[6]);
    putchar(Ptr[7]);
    putchar(Ptr[8]);

}

void MyPrintfPtr(const char* const Ptr)
{
    putchar(Ptr[0]);
    putchar(Ptr[1]);
    putchar(Ptr[2]);
    putchar(Ptr[3]);
    putchar(Ptr[4]);
}

void MyPrintf_s(const char* const Ptr, ...)// 가변인자, %d 사용하고 가변인자에 추가하는듯?
{
    int count = 0;
    while (Ptr[count] != 0)
    {
        putchar(Ptr[count]);
        count++;
    }
}
int main()
{
    char Arr[6] = "Hello";
    MyPrintfArr(Arr);
    putchar('\n');

    const char* Ptr0 = "test";
    MyPrintfPtr(Ptr0);
    putchar('\n');

    const char* Ptr1 = "asdasdasdasdddsss";
    MyPrintf_s(Ptr1);
}    

