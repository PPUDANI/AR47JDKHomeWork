#pragma once

#include "ConsoleGameMath.h"

class Player
{
public:

	Player();

	inline int2 GetPos() const
	{
		return Pos;
	}

	inline void SetPos(const int2& _Value)
	{
		Pos = _Value;
	}

	// ȭ��ٱ����� �������� �ϼ���. 
	void Input();
	
	//void SetScreen(ConsoleGameScreen* _Screen)
	//{
	//	Screen = _Screen;
	//}

protected:

private:


	static const int InterFrame = 200;

	int2 Pos = int2(0, 0);

};