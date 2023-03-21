
#include <iostream>
#include <conio.h>

void Damage(
    const char* AttName,
    const char* const DefName,
    const int& Att,
    int& Hp)
{
    printf_s("%s가 %s에게 공격을 시작합니다.\n", AttName, DefName);
    printf_s("%s가 %d의 데미지를 입었습니다.\n", DefName, Att);
    Hp -= Att;
}

void StatusRender(const char* const name,
    const int& Att,
    const int& Hp)
{
    printf_s("%s의 Status -----\n", name);
    printf_s("    Hp : %d\n", Hp);
    printf_s("   Att : %d\n", Att);
    printf_s("-----------------\n");
}
int main()
{
    int PlayerHp = 100;
    int PlayerAtt = 10;
    int MonsterHp = 50;
    int MonsterAtt = 10;

    while (true)
    {
        if (PlayerHp < 0)
        {
            printf_s("Player의 승리입니다.");
            break;
        }
        else if (MonsterHp < 0)
        {
            printf_s("Monster의 승리입니다.");
            break;
        }

        system("cls"); // 콘솔화면을 지운다.

        StatusRender("Player", PlayerAtt, PlayerHp);
        StatusRender("Monster", MonsterAtt, MonsterHp);

        Damage("Player", "Monster", PlayerAtt, MonsterHp);
        Damage("Monster", "Player", MonsterAtt, PlayerHp);
        _getch();


    }
    return 0;
}
