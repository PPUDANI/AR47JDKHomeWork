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
	bool IsBomb(const int2 _NextPos) const;
	 
protected:

private:
	int BombPower = 3;
	
	
};

