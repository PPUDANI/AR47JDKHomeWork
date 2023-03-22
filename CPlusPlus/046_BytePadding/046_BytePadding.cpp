
#include <iostream>

class Player
{
private:
    
    int Hp;
    short a2;
    int Att;
    short a;
    
    // std::vector와 같듯이 제일 큰 변수 기준으로 패딩된다.

};

int main()
{
    Player NewPlayer;
    int Size = sizeof(NewPlayer);

    printf_s("%d", Size);
}
