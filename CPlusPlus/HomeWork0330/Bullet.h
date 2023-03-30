#pragma once
#include "ConsoleGameMath.h"
#include "ShootingGame.h"

class Player;
class ConsoleGameScreen;
class Bullet
{
public:
	static const int MaxBulletNum = 20;
	static int BulletCount;

	static Bullet* GetArrBulletLeft()
	{
		return ArrBulletLeft;
	}

	static Bullet* GetArrBulletMid()
	{
		return ArrBulletMid;
	}

	static Bullet* GetArrBulletRight()
	{
		return ArrBulletRight;
	}

	static void AllRender();
	static void AllUpdate();

	inline void SetPos(const int2& _Value)
	{
		Pos = _Value;
	}

	inline int2 GetPos() const
	{
		return Pos;
	}

	inline bool IsFire() const
	{
		return Fire;
	}

	inline void FireOn()
	{
		Fire = true;
	}

	void UpdateMid();
	void UpdateLeft();
	void UpdateRight();
	void Render();

protected:

private:
	static Bullet ArrBulletLeft[Bullet::MaxBulletNum];
	static Bullet ArrBulletMid[Bullet::MaxBulletNum];
	static Bullet ArrBulletRight[Bullet::MaxBulletNum];
	Bullet();

	bool Fire = false;

	int2 Pos = int2(0, 0);
};

