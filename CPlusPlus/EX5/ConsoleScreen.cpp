#include "ConsoleScreen.h"
#include <iostream>

ConsoleScreen ConsoleScreen::Map;

ConsoleScreen::ConsoleScreen()
{
	for (int y = 0; y  < MapSizeY; y++)
	{
		for (int x = 0; x < MapSizeX; x++)
		{
			if (y == 0 || y == MapSizeY - 1 || x == 0 || x == MapSizeX - 1)
			{
				MapArr[y][x] = 'O';
			}
			else
			{
				MapArr[y][x] = ' ';
			}
			
		}
	}
}

ConsoleScreen::~ConsoleScreen()
{

}

ConsoleScreen& ConsoleScreen::GetMap()
{
	return Map;
}

void ConsoleScreen::ConsolePrint()
{
	for (int y = 0; y < MapSizeY; y++)
	{
		for (int x = 0; x < MapSizeX; x++)
		{
			printf_s("%c", MapArr[y][x]);
		}
		std::cout << std::endl;
	}
	
}
