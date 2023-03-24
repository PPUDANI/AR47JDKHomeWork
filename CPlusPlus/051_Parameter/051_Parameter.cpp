
#include <iostream>

class Player
{
public:
    int Value1;
    int Value2;
    int Value3;
    int Value4;
    int Value5;
    int Value6;
    int Value7;
    int Value8;
};

// 매개변수를 객체 그대로 넣으면 메모리를 너무 사용하게 된다.
void StatusRender(const Player _Player)
{

}

// 아래와 같이 참조 혹은 포인터로 받아오면 함수호출 시 8byte로 호출이 가능하다.
void StatusRender(const Player& _Player)
{

}


// 매개변수를 포인터로 썼다면 null 체크를 무조건 해주어야 한다.
void PlayerRender(const Player* _Player) 
{
    if (nullptr == _Player) // 방어코드
    {
        return;
    }

}



int main()
{
    int Value = sizeof(Player);

}
