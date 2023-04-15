#pragma once
#include <GameEngineConsole/ConsoleGameObject.h>

// Ό³Έν :
class Parts : public ConsoleGameObject
{
public:
	// constructor destructor
	Parts();
	~Parts();

	// delete Function
	Parts(const Parts& _Other) = delete;
	Parts(Parts&& _Other) noexcept = delete;
	Parts& operator=(const Parts& _Other) = delete;
	Parts& operator=(Parts&& _Other) noexcept = delete;

protected:
	void Update() override;

	Parts* Next = nullptr;
	Parts* Prev = nullptr;

private:
	
};
