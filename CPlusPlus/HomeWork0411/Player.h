#pragma once
#include <GameEngineConsole/ConsoleGameObject.h>


class ConsoleGameScreen;
class Player : public ConsoleGameObject
{
public:
	static bool IsGameUpdate;

public:
	Player();
	void Update() override;
	bool IsMoveAble(const int2 _NextPos);
	bool IsBomb(int2 _NextPos);

protected:

private:
	int BombPower = 3;
	
	
};

