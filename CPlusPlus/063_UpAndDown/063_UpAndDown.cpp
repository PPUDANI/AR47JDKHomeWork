// 063_UpAndDown.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

// virtual이 붙어있는 클래스가 존재하면 이 클래스의 객체가 생성될 때 함수포인터의 배열을 만들어내고 그걸 함수포인터의 포인터로 저장한다.
// void(*__Vfptr[??])() <- 가상함수 테이블
class FightUnit
{
public:
    virtual int GetAtt()
    {
        return Att;
    }
private:
    int Hp = 0;
    int Att = 10;

};

class Player : FightUnit
{
public:
    int GetAtt() override
    {
        return FightUnit::GetAtt();
    }

};

class Monster
{

};

void Fight(FightUnit* _Left, FightUnit* _Right)
{
    // 다운캐스팅 : 부모 클래스포인터인 인자를 자식 클래스포인터로 바꿀 수 있다.
    // 부모형을 자식형으로 바꾼다
    // 이 경우 최악의 방법이다. 몬스터의 부모클래스포인터를 플레이어의 클래스포인터로 바꾸는게 가능하다.
    // 무슨 일이 벌어질지 알 수 없다.
}

int main()
{
    Player NewPlayer0;
    Player NewPlayer1;

    Player* Ptr0 = &NewPlayer0;
    FightUnit* Ptr1 = &Ptr0;
    Fight(NewPlayer0, NewPlayer1);

}
