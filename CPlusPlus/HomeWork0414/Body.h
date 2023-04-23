#pragma once
#include <GameEngineConsole/ConsoleGameObject.h>
#include "Parts.h"

class Body : public Parts
{
public:
	// constructor destructor
	Body();
	~Body();

	// delete Function
	Body(const Body& _Other) = delete;
	Body(Body&& _Other) noexcept = delete;
	Body& operator=(const Body& _Other) = delete;
	Body& operator=(Body&& _Other) noexcept = delete;

	inline static bool GetMaxUnitCount()
	{
		int2 ScreenSize = ConsoleGameScreen::GetMainScreen().GetScreenSize();
		return UnitCount == ScreenSize.X * ScreenSize.Y;
	}
	
	
protected:

	

private:
	std::vector<std::vector<int>> EmptyCheck();
	static int UnitCount;
	
};

