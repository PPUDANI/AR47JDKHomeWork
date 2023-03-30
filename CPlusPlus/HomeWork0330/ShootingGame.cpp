#include "ShootingGame.h"

void ShootingGame::Progress()
{
	NewPlayer.SetPos(ScreenSize.Half());

	while (true)
	{
		system("cls");

		ConsoleGameScreen::GetMainScreen().ScreenClear();

		ConsoleGameScreen::GetMainScreen().SetScreenCharacter(NewPlayer.GetPos(), '*');

		ConsoleGameScreen::GetMainScreen().SetScreenBullet(Bullet::GetPos(), '^');

		ConsoleGameScreen::GetMainScreen().ScreenPrint();


		NewPlayer.Input();
	}
}