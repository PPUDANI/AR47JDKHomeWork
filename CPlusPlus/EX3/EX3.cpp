﻿
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <vector>
class int2
{
public:
    int Y = 0;
    int X = 0;
};

class ConsoleMap
{
private:

public:

    void PrintMap() const
    {

    }
private:

};

class Player
{
private:
    int2 Pos = {0, 0};

public:


};

int main()
{
    /*const int2 MapSize = { (const int)10, (const int)20 };
    ConsoleMap NewMap();
    ConsoleMap NewMap1;
    Player NewPlayer;*/

    std::vector<std::vector<int>> EmptyCheckArr(10, std::vector<int>(10, 0));

    std::cout << EmptyCheckArr[3][4];
}

