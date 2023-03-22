
#include <iostream>

int main()
{

    // n차원 배열은 가독성이 좋게, 사람이 생각하기 쉽게 만든 것이다.
    // 결국 모든 배열은 궁극적으로 1차원 배열이다.

    int Arr[3][2] = { {1, 2}, {3, 4}, {5, 6} };
    __int64 Address00 = (__int64)&Arr[0][0]; // 100
    __int64 Address01 = (__int64)&Arr[0][1]; // 104

    __int64 Address10 = (__int64)&Arr[1][0]; // 108
    __int64 Address11 = (__int64)&Arr[1][1]; // 112

    __int64 Address20 = (__int64)&Arr[2][0]; // 116
    __int64 Address21 = (__int64)&Arr[2][1]; // 120

}
