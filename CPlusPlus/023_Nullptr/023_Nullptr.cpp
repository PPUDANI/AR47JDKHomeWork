
#include <iostream>

int main()
{
    int Value = 10;

    // 아래 코드에서 nullptr은 0이라고 부른다.
    // C++에서는 이것이 nullptr 사용한다.
    // 아직 아무 주소도 가리키고 있지 않다는 의미이다.
    int* Ptr = nullptr; // 와 이거 언리얼에서 봄
    *Ptr = 20;

    // C 스타일로는 아래와 같다.
    // int* Ptr = 0;

}
