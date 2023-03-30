
#include <iostream>
#include "ConsoleGameScreen.h"
#include "Bullet.h"
ConsoleGameScreen ConsoleGameScreen::MainScreen;

ConsoleGameScreen::ConsoleGameScreen()
{
}

void ConsoleGameScreen::ScreenClear()
{
	for (size_t y = 0; y < ScreenYSize; y++)
	{
		for (size_t x = 0; x < ScreenXSize; x++)
		{
			Arr[y][x] = 'o';
		}
	}
}

void ConsoleGameScreen::ScreenPrint() const
{
	for (size_t y = 0; y < ScreenYSize; y++)
	{
		for (size_t x = 0; x < ScreenXSize; x++)
		{
			// Arr[y][x] = 'b';
			printf_s("%c", Arr[y][x]);
		}
		printf_s("\n");
	}
}

// 이녀석을 무조건 사용해서 플레이어가 바깥으로 못나가게 만드세요.
bool ConsoleGameScreen::IsScreenOver(const int2& _Pos) const
{
	if (0 > _Pos.X)
	{
		return true;
	}

	if (0 > _Pos.Y)
	{
		return true;
	}

	if (ScreenXSize <= _Pos.X)
	{
		return true;
	}

	if (ScreenYSize <= _Pos.Y)
	{
		return true;
	}

	return false;
}

void ConsoleGameScreen::SetScreenCharacter(const int2& _Pos, char _Ch)
{
	if (true == IsScreenOver(_Pos))
	{
		return;
	}

	Arr[_Pos.Y][_Pos.X] = _Ch;
}

void ConsoleGameScreen::SetScreenBullet(int2& _Pos, char _Ch)
{
	int2 TempPos = _Pos;
	--TempPos.Y;

	if (false == IsScreenOver(TempPos))
	{
		--_Pos.Y;
	}
	else
	{
		Bullet::StopBullet();
	}

	if (Bullet::IsBulletFired() == true)
	{
		Arr[_Pos.Y][_Pos.X] = _Ch;
	}
}

int2 ConsoleGameScreen::GetScreenSize()
{
	return int2{ ScreenXSize, ScreenYSize };
}
