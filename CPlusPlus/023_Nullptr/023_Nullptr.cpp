
#include <iostream>

int main()
{
    int Value = 10;

    // 아래 코드에서 nullptr은 0이라고 부른다.
    // C++에서는 이것이 nullptr 사용한다.
    // 아직 아무 주소도 가리키고 있지 않다는 의미이다.
    // 포인터를 초기화할 때 쓰인다.

    int* Ptr = nullptr;

    // C 스타일로는 아래와 같다.
    // int* Ptr = 0;
    
    // 포인터는 0을 쓰지 않기로 약속했다.
    // 아래 코드는 예외가 발생하는 것을 볼 수 있다.
    *Ptr = 20;

}
