#include "ConsoleGameObject.h"
#include "ConsoleGameScreen.h"

void ConsoleGameObject::Render()
{
	if (false == IsUpdate())
	{
		return;
	}

	ConsoleGameScreen::GetMainScreen().SetScreenCharacter(Pos, RenderChar);
}

bool ConsoleGameObject::IsAcquired()
{
	return false;
}

void ConsoleGameObject::Acquire() {}

void ConsoleGameObject::Update() {}