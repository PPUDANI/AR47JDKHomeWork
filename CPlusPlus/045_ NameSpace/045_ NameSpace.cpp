
#include <iostream>



// 실제적으로 플레이어의 스펙이나 
// Player라는 객체가 생성되면 int Hp라는 것을 가지고 있어야 한다는 의미
class Player
{
    int Hp;
};

class Monster
{
    int Hp; // 위 Player Class의 Hp와 겹치지 않는 이유는 영역을 나누었기 떄문이다.
    // Player::HP
    // Monster::HP
    // 처럼 컴파일러는 헷갈려하지 않는다.
};

// 아래처럼 namespace를 사용하면 영역 구분으로 클래스명이 겺치지 않는다.
// 하지만 이런식으로 사용하진 않는다.
// Item이란 포괄적인 이름으로 명시하면 안된다.

namespace AProgram
{
    class Item
    {

    };
}

namespace BProgram
{
    namespace Use
    {
        class Item
        {

        };
    }
}

class Item
{

};

// 이런 짓은 하지말자.
//namespace std
//{
//
//}


// using namespace std;
// 이런 코드는 사용하지 말자.
// 영역 구분이 안됨.
// using namespace AProgram;
// using namespace BProgram;

int main()
{

    // std란 standard의 약어
    // c++ 공인이다.
    std::cout << "Hello World!\n";

    Item NewItem;
    AProgram::Item NewItemA;
    BProgram::Use::Item NewItemB;
}
