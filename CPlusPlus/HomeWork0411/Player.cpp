#include "Player.h"
#include <conio.h>
#include <Windows.h>
#include <GameEngineConsole/ConsoleGameScreen.h>
#include "ConsoleObjectManager.h"
#include "Bomb.h"
#include "GameEnum.h"
#include "ConsoleObjectManager.h"

bool Player::IsGameUpdate = true;
Player::Player()
{
	RenderChar = '*';
	SetPos(ConsoleGameScreen::GetMainScreen().GetScreenSize().Half());

}

bool Player::IsBomb(const int2 _NextPos) const
{
	// 폭탄이 설치되었다면 못통과하게 만들어놓으세요.
	GameEngineArray<ConsoleGameObject*>& BombGroup = ConsoleObjectManager::GetGroup(ObjectOrder::Bomb);

	int BombGroupCount = BombGroup.Count();

	for (int i = 0; i < BombGroupCount; i++)
	{
		ConsoleGameObject* Ptr = BombGroup[i];
		if (nullptr == Ptr)
		{
			continue;
		}

		if (_NextPos == Ptr->GetPos())
		{
			return true;
		}
	}

	return false;
}

bool Player::IsMoveAble(const int2 _NextPos)
{
	if (false == ConsoleGameScreen::GetMainScreen().IsScreenOver(_NextPos))
	{
		if (false == IsBomb(_NextPos))
		{
			return true;
		}
	}

	return false;
}

// 화면바깥으로 못나가게 하세요. 
void Player::Update()
{
	if (0 == _kbhit())
	{
		return;
	}

	char Ch = _getch();

	int2 NextPos = { 0, 0 };

	switch (Ch)
	{
	case 'a':
	case 'A':
		NextPos = Pos;
		NextPos.X -= 1;
		if (true == IsMoveAble(NextPos))
		{
			Pos.X -= 1;
		}
		break;
	case 'd':
	case 'D':
		NextPos = Pos;
		NextPos.X += 1;
		if (true == IsMoveAble(NextPos))
		{
			Pos.X += 1;
		}
		break;
	case 'w':
	case 'W':
		NextPos = Pos;
		NextPos.Y -= 1;
		if (true == IsMoveAble(NextPos))
		{
			Pos.Y -= 1;
		}
		break;
	case 's':
	case 'S':
		NextPos = Pos;
		NextPos.Y += 1;
		if (true == IsMoveAble(NextPos))
		{
			Pos.Y += 1;
		}
		break;
	case 'f':
	case 'F':
	{
		// 여기 이상황에서 보면
		// ConsoleObjectManager 있고
		// Player 
		Bomb* NewBomb = ConsoleObjectManager::CreateConsoleObject<Bomb>(ObjectOrder::Bomb);
		NewBomb->Init(BombPower);
		NewBomb->SetPos(GetPos());
		// 폭탄설치 
		break;
	}
	case 'q':
	case 'Q':
	{
		IsGameUpdate = false;
		break;
	}
	default:
		break;
	}
}
