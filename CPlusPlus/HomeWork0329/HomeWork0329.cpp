
#include <iostream>

#include "Player.h"
#include "ConsoleGameScreen.h"
#include "Bullet.h"

int main()
{
	Player NewPlayer = Player();
	int2 ScreenSize = ConsoleGameScreen::GetMainScreen().GetScreenSize();
	NewPlayer.SetPos(ScreenSize.Half());

	while (true)
	{
		system("cls");

		ConsoleGameScreen::GetMainScreen().ScreenClear();

		ConsoleGameScreen::GetMainScreen().SetScreenCharacter(NewPlayer.GetPos(), '*');

		ConsoleGameScreen::GetMainScreen().SetScreenBullet(Bullet::Pos, '^');

		ConsoleGameScreen::GetMainScreen().ScreenPrint();
		

		NewPlayer.Input();

	}

}
