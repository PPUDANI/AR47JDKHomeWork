
#include <iostream>

int main()
{
    int Value = 0.1f;
    Value = 0.3f; // 0
    Value = 0.5f; // 0
    Value = 0.9f; // 0

    // 위와 같이 float을 int로 바꾸면 버림 연산이 적용된다.

    float Valuef = 1.00001f;
    Valuef += 1.00001f;

    // 연산ㅇ
    if (Valuef == 2.00002f)
    {
        int a = 0;
    }

    
}

