#pragma once

#include "ConsoleGameMath.h"
#include "ConsoleGameScreen.h"

class Bullet
{
public:

	inline static int2& GetPos()
	{
		return Pos;
	}

	inline static void SetPos(int2 _Pos)
	{
		Pos = _Pos;
	}

	inline static bool IsBulletFired()
	{
		return BulletFired;
	}

	inline static void FireBullet()
	{
		BulletFired = true;
	}

	inline static void StopBullet()
	{
		BulletFired = false;
	}

private:
	static Bullet MainBullet;
	static bool BulletFired;
	static int2 Pos;
	
	Bullet();
};

