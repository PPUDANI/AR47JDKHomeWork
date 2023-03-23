
#include <iostream>

class Player
{
public:
    int Hp;
    int Att;
    void Damage() // 매개변수가 없는 멤버함수는 없다.  : Player* const this
    {

    }
};
int main()
{
    int Value = int();
    Player NewPlayer = Player();

    int* ValuePtr = nullptr;
    Player* NewPlayerPTr = &NewPlayer;

    ValuePtr = nullptr;

    *ValuePtr = 20; // 익셉션

}
