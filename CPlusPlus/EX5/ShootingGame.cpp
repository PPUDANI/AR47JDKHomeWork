#include "ShootingGame.h"
#include "ConsoleScreen.h"

ShootingGame::ShootingGame()
{
	
}

ShootingGame::~ShootingGame()
{

}

void ShootingGame::GameRender()
{
	ConsoleScreen::GetMap().ConsolePrint();
}

void ShootingGame::GameProgress()
{
	GameRender();
}