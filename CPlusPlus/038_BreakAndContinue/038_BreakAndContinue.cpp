
#include <iostream>

int main()
{
    for (int i = 0; i < 100; i++)
    {
        if (0 == i % 2)
        {
            // 반복문에서의 break는 가장 가까운 반복문을 탈출한다.
            // break; 
            continue; // 가장 가까운 반복문의 조건문으로 바로 이동한다.
        }
        std::cout << i << '\n';
    }
}

