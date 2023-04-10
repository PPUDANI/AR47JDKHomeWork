
#include <iostream>
enum GameJobType
{
    Fightrt,
    Mage,
    Archer,
    Paladin,
};

class FightUnit
{
    GameJobType JobType;

public:
    void SetJobType(GameJobType _Type)
    {

    }
    // 게임에서 보통 직업을 표현한다면 직업이 더 많아질 수도 있기 때문에 이런식으로 표현한다.
    // 0 전사
    // 1 마법사
    // 2 궁수
};
int main()
{
    FightUnit NewUnit;
    
    NewUnit.SetJobType(GameJobType::Archer);

    int Val = Archer;
    int Val2 = GameJobType::Archer;

    
    std::cout << "Hello World!\n";
}
