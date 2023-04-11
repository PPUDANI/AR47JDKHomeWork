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

	// Update �Ŀ� Render�� �Ǽ� �ʱ�ȭ�ǹǷ� ���⼭ ��.. 
	switch (BoomState)
	{
	case BoomState::Idle:
		break;

	case BoomState::Frame2: // Frame2���� Frame1�� ����Ǿ�� �ؼ� break�� ���� �ʾ���.
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


