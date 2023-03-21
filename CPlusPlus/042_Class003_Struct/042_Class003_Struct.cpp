
#include <iostream>

// struct와 class의 차이는 접근제한 지정자 말고는 없다.
class Player
{
    // default 접근제한 지정자  : private
    int Att = 10;
    int Def = 2;
    int Hp = 100;
    int Speed = 3;
};
struct Monster
{
    // default 접근제한 지정자  : public
    int Att = 10;
    int Def = 2;
    int Hp = 100;
    int Speed = 3;
};

int main()
{
    std::cout << "Hello World!\n";
}