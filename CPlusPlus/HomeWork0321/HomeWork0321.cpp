
#include <iostream>
#include <conio.h>

void StatusRender ( const char* const name, const int& Att, const int& Hp )
{
    printf_s("%s의 Status -----\n", name);
    printf_s("    Hp : %d\n", Hp);
    printf_s("   Att : %d\n", Att);
    printf_s("-----------------\n");
}

void Damage(int& Att, int& Hp)
{
    Hp -= Att;
}

void DamageLog(const char* const AttName, const char* const DefName, int& Att)
{
    printf_s("%s가 공격을 시작합니다\n", AttName);
    printf_s("%s가 %d의 데미지를 입었습니다.\n", DefName, Att);
}

int main()
{
    int PlayerHp = 100;
    int PlayerAtt = 10;
    int MonsterHp = 50;
    int MonsterAtt = 10;

    while (true)
    {

        system("cls");
        StatusRender("Player", PlayerAtt, PlayerHp);
        StatusRender("Monster", MonsterAtt, MonsterHp);

        _getch();

        system("cls");
        Damage(PlayerAtt, MonsterHp);
        StatusRender("Player", PlayerAtt, PlayerHp);
        StatusRender("Monster", MonsterAtt, MonsterHp);
        DamageLog("Player", "Monster", PlayerAtt);
        
        _getch();

        system("cls");
        Damage(MonsterAtt, PlayerHp);
        StatusRender("Player", PlayerAtt, PlayerHp);
        StatusRender("Monster", MonsterAtt, MonsterHp);
        DamageLog("Player", "Monster", PlayerAtt);
        DamageLog("Monster", "Player", MonsterAtt);

        _getch();

        if (PlayerHp <= 0)
        {
            printf_s("Player의 승리입니다.");
            break;
        }
        else if (MonsterHp <= 0)
        {
            printf_s("Monster의 승리입니다.");
            break;
        }
    }

    return 0;
}
