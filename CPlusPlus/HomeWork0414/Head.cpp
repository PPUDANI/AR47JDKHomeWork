#include "Head.h"

#include <conio.h>
#include <list>
#include <GameEngineConsole/ConsoleGameScreen.h>
#include <GameEngineConsole/ConsoleObjectManager.h>
#include "GameEnum.h"


bool Head::IsPlay = true;

Head::Head()
{
	RenderChar = L'▶';
	SetPos(ConsoleGameScreen::GetMainScreen().GetScreenSize().Half());
}

Head::~Head()
{
}


void Head::IsBodyCheck()
{
	std::list<ConsoleGameObject*>& BodyList =
		ConsoleObjectManager::GetGroup(ObjectOrder::Body);

	for (ConsoleGameObject* BodyPtr : BodyList)
	{
		if (nullptr == BodyPtr)
		{
			continue;
		}

		Parts* BodyPart = dynamic_cast<Parts*>(BodyPtr);
		int2 BodyPos = BodyPart->GetPos();

		if (Pos == BodyPos)
		{

			if (true == BodyPart->IsAcquired())
			{
				MsgBoxAssert("바디그룹 쪽에 바디가 아닌 객체가 들어있었습니다.");
				return;
			}

			Parts* Last = GetLast();
			Last->SetNext(BodyPart);
			Last->Acquire();
			ConsoleObjectManager::CreateConsoleObject<Body>(ObjectOrder::Body);
			break;
		}
	}
}


// 화면바깥으로 못나가게 하세요.
void Head::Update()
{

	if (0 == _kbhit())
	{
		

		/*SetPos(GetPos() + Dir);

		if (true == ConsoleGameScreen::GetMainScreen().IsScreenOver(GetPos()))
		{
			IsPlay = false;
			return;
		}

		IsBodyCheck();
		
		NextMove();*/

		return;
	}

	char Ch = _getch();

	switch (Ch)
	{
	case 'a':
	case 'A':
		Dir = int2::Left;
		RenderChar = L'◀';
		break;

	case 'd':
	case 'D':
		Dir = int2::Right;
		RenderChar = L'▶';
		break;

	case 'w':
	case 'W':
		Dir = int2::Up;
		RenderChar = L'▲';
		break;

	case 's':
	case 'S':
		Dir = int2::Down;
		RenderChar = L'▼';
		break;

	case 'q':
	case 'Q':
		IsPlay = false;
		return;

	default:
		return;
	}

	

	SetPos(GetPos() + Dir);
	
	if (true == ConsoleGameScreen::GetMainScreen().IsScreenOver(GetPos()))
	{
		IsPlay = false;
		return;
	}

	IsBodyCheck();
	NextMove();
}
