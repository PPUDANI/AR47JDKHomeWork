#pragma once
#include <GameEngineConsole/ConsoleGameObject.h>

class ConsoleGameScreen;
class Body : public ConsoleGameObject
{
public:
	// constructor destructor
	Body();
	~Body();

	bool IsAcquired () override
	{
		return Acquired;
	}

	void Acquire () override
	{
		Acquired = true;
	}

	// delete Function
	Body(const Body& _Other) = delete;
	Body(Body&& _Other) noexcept = delete;
	Body& operator=(const Body& _Other) = delete;
	Body& operator=(Body&& _Other) noexcept = delete;

protected:

private:
	bool IsEmptySpace(const int _X, const int _Y);
	bool Acquired = false;
};

