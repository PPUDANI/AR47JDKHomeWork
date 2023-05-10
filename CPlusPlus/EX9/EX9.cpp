
#include <iostream>
#include <map>
#include <GameEngineBase/GameEngineDebug.h>
class A
{
    int a;
public:
    A() : a(3)
    {
    }
    
};

int main()
{
    GameEngineDebug::LeckCheck();
    std::map<int, A*> MapA;
    
    for (int i = 0; i < 10; i++)
    {
        A* newA = new A();
        MapA.insert(std::make_pair(i, newA));
    }

    for (const std::pair<int, A*> Pair : MapA)
    {
        A* ObjA = Pair.second;
        if (nullptr != ObjA)
        {
            delete ObjA;
            ObjA = nullptr;
        }
    }

    for (int i = 10; i < 20; i++)
    {
        A* newA = new A();
        MapA.insert(std::make_pair(i, newA));
    }

    for (const std::pair<int, A*> Pair : MapA)
    {
        A* ObjA = Pair.second;
        if (nullptr != ObjA)
        {
            delete ObjA;
            ObjA = nullptr;
        }
    }

}