

#include <iostream>

int main()
{
    // int Value = 1
    int Value = 0b00000000000000000000000000000001;

    int* Ptr = &Value;

    char* ChPtr = reinterpret_cast<char*>(Ptr);
    //    Test0    Test1    Test2    Test3     
    // 0b 00000000 00000000 00000000 00000001

    

    // Intel CPU는 아래와 같이 나온다고 한다.
    //    Test0    Test1    Test2    Test3     
    // 0b 00000001 00000000 00000000 00000000

    // 이는 CPU에 따라 다르게 나타나는 현상이다.
    // 이 현상의 이름을 알아와라.
    char Test0 = ChPtr[0];
    char Test1 = ChPtr[1];
    char Test2 = ChPtr[2];
    char Test3 = ChPtr[3];

    int a = 0;
    // 바이트오더 (Byte Order)
    // 리틀 엔디안 (Little-endian)
    // a  a+1 a+2 a+3
    // 0   0   0   1

    // 빅 엔디안 (Big-endian)
    // a  a+1 a+2 a+3
    // 1   0   0   0
}
