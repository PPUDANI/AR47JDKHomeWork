
#include <iostream>

int count = 0;
void Test()
{
    std::cout << count++ << std::endl;

    if (count > 20)
    {
        return;
    }

    // 리턴에다가 재귀를 거는 경우에는 꼬리재귀라는 것이 된다.
    // 컴파일러의 재량에 따라 for문 형태로 바꿔줄 수 있다.
    // 하여 함수 메모리를 새로 만들지 않는다..?
    return Test();
}
int main()
{
    Test();
}
