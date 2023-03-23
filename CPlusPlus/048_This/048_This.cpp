
#include <iostream>

class Player
{
private:
    int Hp = 10;

public:


    inline int GetHp()
    {
        return Hp;
    }

    void SetHp(Player* NewPlayer, int Value)
    {
        NewPlayer -> Hp = Value;
    }

    // 아래 함수는 포인터를 받는다.
    // 하지만 객체의 함수를 사용하기 때문에 기본적으로 자기자신의 포인터가 매개변수로 암묵적으로 들어가게 된다.
    void SetHp2(/*Player* const this,*/ int Value)
    {
        // this는 * const이므로 주소를 바꿀 수 없다.
        // this = nullptr;
        this->Hp = Value;
    }
};
int main()
{
    // .연산자는 포인터로 사용할 경우 ->를 사용해야 한다.
    Player NewPlayer = Player();



    NewPlayer.SetHp(&NewPlayer, 30);

    NewPlayer.SetHp2(40);
}
