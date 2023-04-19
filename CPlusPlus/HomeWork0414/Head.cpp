#include "Head.h"

#include <conio.h>
#include <list>
#include <GameEngineConsole/ConsoleGameScreen.h>
#include <GameEngineConsole/ConsoleObjectManager.h>
#include "GameEnum.h"


bool Head::IsPlay = true;
int Head::EmptyCount = 0;

Head::Head()
{
	RenderChar = L'▶';
	SetPos(ConsoleGameScreen::GetMainScreen().GetScreenSize().Half());

	int2 ScreenSize = ConsoleGameScreen::GetMainScreen().GetScreenSize();
	EmptyCount = (ScreenSize.X * ScreenSize.Y) - 1; // 빈 공간 개수, 첫 Body와 'Head'개수도 제거
}

Head::~Head()
{
}

void Head::BodyUpdate()
{
	std::list<ConsoleGameObject*>& BodyGroup =
		ConsoleObjectManager::GetGroup(ObjectOrder::Body);

	std::list<ConsoleGameObject*>::reverse_iterator ReverseBegin = BodyGroup.rbegin();
	std::list<ConsoleGameObject*>::reverse_iterator ReverseEnd = BodyGroup.rend();
	std::list<ConsoleGameObject*>::reverse_iterator PrevReverseEnd = std::prev(ReverseEnd);

	
	for (; ReverseBegin != PrevReverseEnd; ++ReverseBegin)
	{
		if (nullptr == (*ReverseBegin))
		{
			continue;
		}

		if ( (*ReverseBegin)->IsAcquired() )
		{
			std::list<ConsoleGameObject*>::reverse_iterator PrevBody = std::next(ReverseBegin);
			(*ReverseBegin)->SetPos((*PrevBody)->GetPos());
			(*ReverseBegin)->SetRenderChar((*PrevBody)->GetRenderChar());
		}
	}

	if ((*PrevReverseEnd)->IsAcquired())
	{
		(*PrevReverseEnd)->SetPos(PrevPos);
		(*PrevReverseEnd)->SetRenderChar(GetRenderChar());
	}
	if (a == true)
	{
		--EmptyCount; // 바디가 생기면 빈 공간 개수 감소
		Body* NewBody = ConsoleObjectManager::CreateConsoleObject<Body>(ObjectOrder::Body);
		a = false;
	}
}

void Head::IsBodyCheck()
{
	std::list<ConsoleGameObject*>& BodyGroup =
		ConsoleObjectManager::GetGroup(ObjectOrder::Body);

	std::list<ConsoleGameObject*>::iterator Begin = BodyGroup.begin();
	std::list<ConsoleGameObject*>::iterator End = BodyGroup.end();
	for (; Begin != End; ++Begin)
	{
		if (nullptr == (*Begin))
		{
			continue;
		}
		if ((*Begin)->GetPos() == Pos)
		{
			
			if ( false == (*Begin)->IsAcquired())
			{
				a = true;
				(*Begin)->Acquire();
			}
			else
			{
				IsPlay = false;
			}
			
		}
	}
}


void Head::NewBodyCreateCheck()
{

}

// 화면바깥으로 못나가게 하세요. 
void Head::Update()
{
	if (true == ConsoleGameScreen::GetMainScreen().IsScreenOver(GetPos()))
	{
		IsPlay = false;
	}

	if (0 == _kbhit())
	{
		PrevPos = Pos;
		SetPos(GetPos() + Dir);
		IsBodyCheck();
		BodyUpdate();
		//NewBodyCreateCheck();
		return;
	}

	char Ch = _getch();

	int2 NextPos = { 0, 0 };

	switch (Ch)
	{
	case 'a':
	case 'A':
		Dir = int2::Left;
		SetRenderChar(L'◀');
		break;
	case 'd':
	case 'D':
		Dir = int2::Right;
		SetRenderChar(L'▶');
		break;
	case 'w':
	case 'W':
		Dir = int2::Up;
		SetRenderChar(L'▲');
		break;
	case 's':
	case 'S':
		Dir = int2::Down;
		SetRenderChar(L'▼');
		break;
	case 'q':
	case 'Q':
		IsPlay = false;
		return;
	default:
		return;
	}

	PrevPos = Pos;
	SetPos(GetPos() + Dir);
	IsBodyCheck();
	BodyUpdate();
	//NewBodyCreateCheck();

	if (true == ConsoleGameScreen::GetMainScreen().IsScreenOver(GetPos()))
	{
		IsPlay = false;
	}
}
