#include "Bomb.h"
#include <GameEngineConsole/ConsoleGameScreen.h>
Bomb::Bomb()
{
}

Bomb::~Bomb()
{
}

void Bomb::Init()
{
	RenderChar = '@';
}

void Bomb::Update()
{
	ConsoleGameObject::Update();

	if (0 == --BoomCount)
	{
		RenderChar = '#';
		BoomState = BoomState::Frame1;
	}

}

void Bomb::Render()
{
	ConsoleGameObject::Render();

	// Update 후에 Render가 되서 초기화되므로 여기서 함.. 
	switch (BoomState)
	{
	case BoomState::Idle:
		break;

	case BoomState::Frame2: // Frame2때도 Frame1이 실행되어야 해서 break를 걸지 않았음.
		for (int i = -2; i <= 2; i += 4)
		{
			int2 SidePosX = Pos;
			int2 SidePosY = Pos;
			SidePosX.X += i;
			SidePosY.Y += i;
			ConsoleGameScreen::GetMainScreen().SetScreenCharacter(SidePosX, '#');
			ConsoleGameScreen::GetMainScreen().SetScreenCharacter(SidePosY, '#');
		}

	case BoomState::Frame1:
		
		for (int i = -1; i <= 1; i += 2)
		{
			int2 SidePosX = Pos;
			int2 SidePosY = Pos;
			SidePosX.X += i;
			SidePosY.Y += i;
			ConsoleGameScreen::GetMainScreen().SetScreenCharacter(SidePosX, '#');
			ConsoleGameScreen::GetMainScreen().SetScreenCharacter(SidePosY, '#');
		}

		if (BoomState::Frame2 == BoomState)
		{
			BoomState = BoomState::Idle;
			Off();
		}
		else if (BoomState::Frame1 == BoomState)
		{
			BoomState = BoomState::Frame2;
		}

	    break;
	default:
		break;
	}
}


