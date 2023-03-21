

#include <iostream>

class Player
{ 
    // 클래스 내부
        //         내부코드   자식코드   외부
public: //           공개      공개     공개
    int Att = 10;
    int Def = 2;
    int Hp = 100;
    int Speed = 3;
protected: //        공개      공개     비공개
    
private: //          공개     비공개    비공개

    void StatuRender()
    {
        printf_s("공격 : %d");
    }
};
class Monster
{
    // default 접근제한 지정자는 private 이다.
    int Att = 10;
    int Def = 2;
    int Hp = 100;
    int Speed = 3;
};
// 클래스 외부
int main()
{
    Player NewPlayer = Player();

    NewPlayer.Hp = 30;
}
