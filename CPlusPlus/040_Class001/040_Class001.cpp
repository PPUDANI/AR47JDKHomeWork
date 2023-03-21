
#include <iostream>

// 클래스는 모든것을 만들 수 있는 문법이다.

class Player
{
    // 속성 : 수치
    // 멤버변수
public:
    const char* const Name;
    int Att; // 공격력
    int Hp; // 방어력

    Player(const char* const t) : Name(t)
    {
        Att = 200;
        Hp = 10;
    }
    ~Player() {}

    // 행동 : 함수
    //멤버함수

    void Damage ()
    {
        printf_s("%s가 %s에게 공격을 시작합니다.\n", Att, Name);
        printf_s("%s가 %d의 데미지를 입었습니다.\n", Name, Att);
        Hp -= Att;
    }

    void StatusRender ()
    {
        printf_s("%s의 Status -----\n", Name);
        printf_s("    Hp : %d\n", Hp);
        printf_s("   Att : %d\n", Att);
        printf_s("-----------------\n");
    }

};

int main()
{
    Player Player1("광전사");

}
