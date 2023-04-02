#pragma once
#include "ConsoleGameObject.h"

class Monster : public ConsoleGameObject
{
public:
	Monster();
	void Update();

	inline static int GetDir()
	{
		return Dir;
	}

	inline static void TransDir()
	{
		Dir *= -1;
	}


private:
	static int Dir;
};

