
#include <iostream>


//이러면 누굴 먼저 호출해야할까?

// 클래스 전방선언
class Monster;
class Player
{
public:
    int Att = 10;
    int Hp = 100;

    void Attack(Monster* _Monster);

    // 전방선언을 해도 안되는 경우
    // 내부 기능을 알아야 할 때가 있다.
};

class Monster
{
public:
    int Att = 10;
    int Hp = 100;

    void Attack(Player* _Player);
};

// 순환참조라고 한다.
// 이는 조심해야한다.
int main()
{
    
}

void Player::Attack(Monster* _Monster)
{
    _Monster->Hp -= Att;
}

void Monster::Attack(Player* _Player)
{
    _Player->Hp -= Att;
}