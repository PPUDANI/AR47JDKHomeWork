#include "Body.h"
#include "list"
#include "Head.h"
#include "GameEnum.h"
#include <GameEngineBase/GameEngineRandom.h>
#include <GameEngineConsole/ConsoleGameScreen.h>
#include <GameEngineConsole/ConsoleObjectManager.h>

Body::Body()
{
	RenderChar = L'бс';

	int2 ScreenSize = ConsoleGameScreen::GetMainScreen().GetScreenSize();

	int EmptyCount = Head::GetEmptyCount();
	int Index = GameEngineRandom::MainRandom.RandomInt(0, EmptyCount - 1);
	int Count = 0;
	for (int y = 0; y < ScreenSize.Y; y++)
	{
		for (int x = 0; x < ScreenSize.X; x++)
		{
			if (true == IsEmptySpace(x, y))
			{
				if (Count == Index)
				{
					int2 NewPos = { x, y };
					SetPos(NewPos);
					break;
				}
				else
				{
					++Count;
				}
			}
		}
		if (Count == Index)
		{
			break;
		}
	}
}

bool Body::IsEmptySpace(const int _X, const int _Y)
{
	std::list<ConsoleGameObject*>& BodyArr = ConsoleObjectManager::GetGroup(ObjectOrder::Body);
	std::list<ConsoleGameObject*>& HeadArr = ConsoleObjectManager::GetGroup(ObjectOrder::Head);

	int2 BodyPos{ _X, _Y };
	for (ConsoleGameObject* Ptr : BodyArr)
	{
		if (BodyPos == Ptr->GetPos())
		{
			return false;
		}
	}
	for (ConsoleGameObject* Ptr : HeadArr)
	{
		if (BodyPos == Ptr->GetPos())
		{
			return false;
		}
	}
	return true;
}

Body::~Body()
{
}

