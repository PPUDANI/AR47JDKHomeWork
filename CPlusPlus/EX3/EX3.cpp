
#include <iostream>
#include <conio.h>
#include <Windows.h>

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
    
    ConsoleMap(const int2& Size)
    {

    }

    void PrintMap() const
    {
        for (int y = 0; y < MapSize.Y; y++)
        {
            for (int x = 0; x < MapSize.X; x++)
            {

            }
        }
    }
private:
    char Arr[MapX][Mapy];
};

class Player
{
private:
    int2 Pos = {0, 0};

public:


};

int main()
{
    const int2 MapSize = { (const int)10, (const int)20 };
    ConsoleMap NewMap(MapSize);
    Player NewPlayer;
}

