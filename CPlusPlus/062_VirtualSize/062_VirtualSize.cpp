
#include <iostream>

// 다형성을 표현하는 문법인 virtual은 보통 상속과 함꼐한다,
// 다형성 == 상속 ( X )
class FightUnit
{
public:
    int GetAtt()
    {
        return Att;
    }

private:

    int Att = 10;
    int Hp = 10;
};

class Monster : public FightUnit
{

};

class Player : public FightUnit
{

};
int main()
{
    
}
