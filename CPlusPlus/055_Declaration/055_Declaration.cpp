
#include <iostream>

// 함수 선언부
void Function()
// 구현부
{

}

void Function0();
void Function1();
void Function2();

// 클래스는 2개를 선언할 수 없다.
class Player
{
public:
    // 멤버변수는 이미 그 자체로 선언이면서 구현이다
    // 따로 실체를 둘 수 없다.
    Player();
    void Print() const;
    Player GetPlayer();
};

Player::Player()
{

}
void Player::Print() const
{

}
Player Player::GetPlayer()
{

}

int main()
{
}
    std::cout << "Hello World!\n";

void Function0()
{

}
void Function1()
{

}
void Function2()
{

}