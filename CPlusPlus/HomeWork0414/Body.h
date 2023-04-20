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

protected:

private:
	std::vector<std::vector<int>> EmptyCheck();
	static int UnitCount;
};

