#include "Body.h"
#include "list"
#include "Head.h"
#include "GameEnum.h"
#include <GameEngineBase/GameEngineRandom.h>
#include <GameEngineConsole/ConsoleGameScreen.h>
#include <GameEngineConsole/ConsoleObjectManager.h>

int Body::UnitCount = 0;

Body::Body()
{
	RenderChar = L'¢Â';
	++UnitCount;
	int2 ScreenSize = ConsoleGameScreen::GetMainScreen().GetScreenSize();
	
	std::vector<std::vector<int>> EmptyCheckArr(EmptyCheck());

	int EmptySpaceNum = (ScreenSize.X * ScreenSize.Y) - UnitCount;
	int IndexNum = GameEngineRandom::MainRandom.RandomInt(1, EmptySpaceNum);

	int Count = IndexNum;
	for (int y = 0; y < ScreenSize.Y; y++)
	{
		for (int x = 0; x < ScreenSize.X; x++)
		{
			if (0 < Count)
			{
				if (0 == EmptyCheckArr[y][x])
				{
					--Count;
				}
			}
			
			if(0 == Count)
			{
				SetPos({ x, y });
				break;
			}
		}
		if (0 == Count)
		{
			break;
		}
	}
}

Body::~Body()
{
}

std::vector<std::vector<int>> Body::EmptyCheck()
{
	std::list<ConsoleGameObject*> HeadList = ConsoleObjectManager::GetGroup(ObjectOrder::Head);
	std::list<ConsoleGameObject*> BodyList = ConsoleObjectManager::GetGroup(ObjectOrder::Body);

	int2 ScreenSize = ConsoleGameScreen::GetMainScreen().GetScreenSize();
	std::vector<std::vector<int>> Vec(ScreenSize.Y, std::vector<int>(ScreenSize.X, 0));

	for (ConsoleGameObject* HeadPtr : HeadList)
	{
		if (nullptr == HeadPtr)
		{
			continue;
		}
		Parts* HeadPart = dynamic_cast<Parts*>(HeadPtr);
		int2 HeadPos = HeadPart->GetPos();
		int2 HeadPrevPos = HeadPart->GetPrevPos();
		Vec[HeadPos.Y][HeadPos.X] = 1;
		Vec[HeadPrevPos.Y][HeadPrevPos.X] = 1;
	}

	for (ConsoleGameObject* BodyPtr : BodyList)
	{
		if (nullptr == BodyPtr)
		{
			continue;
		}

		int2 BodyPos = BodyPtr->GetPos();
		Vec[BodyPos.Y][BodyPos.X] = 1;
	}
	
	return Vec;
}