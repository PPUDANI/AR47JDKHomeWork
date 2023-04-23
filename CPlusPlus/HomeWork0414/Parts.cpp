#include "Parts.h"

int2 Parts::ScreenSize;
std::vector<std::vector<int>> Parts::EmptyCheckArr;

Parts::Parts()
{
	ScreenSize = ConsoleGameScreen::GetMainScreen().GetScreenSize();

	EmptyCheckArr.resize(ScreenSize.Y);
	for (int i = 0; i < ScreenSize.Y; i++)
	{
		EmptyCheckArr[i].resize(ScreenSize.X);
	}
}

Parts::~Parts()
{
}


void Parts::Update()
{
	ConsoleGameObject::Update();
}

Parts* Parts::GetLast()
{
	if (Next == nullptr)
	{
		return this;
	}

	return Next->GetLast();
}

void Parts::NextMove()
{
	if (nullptr == Next)
	{
		return;
	}

	Parts::EmptyCheckArr[GetPos().Y][GetPos().X] = 1;
	Parts::EmptyCheckArr[GetPrevPos().Y][GetPrevPos().X] = 0;

	
	Next->SetPos(PrevPos);
	SetNextDir();
	Next->SetRenderChar();
	

	return Next->NextMove();
}