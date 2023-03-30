#pragma once
#include "ConsoleGameMath.h"

class ConsoleGameScreen;
class Player
{
public:
	Player();

	inline void SetPos(const int2& _Value)
	{
		Pos = _Value;
	}

	inline int2 GetPos() const
	{
		return Pos;
	}

	void Input();

	void Render();

	// ���漱���� �̷��� �ص� �ȴ�.
	void SetBulletLeftArr(class Bullet* _BulletPtr)
	{
		BulletLeftPtr = _BulletPtr;
	}

	void SetBulletMidArr(class Bullet* _BulletPtr)
	{
		BulletMidPtr = _BulletPtr;
	}

	void SetBulletRightArr(class Bullet* _BulletPtr)
	{
		BulletRightPtr = _BulletPtr;
	}

protected:

private:
	static const int InterFrame = 200;

	int2 Pos = int2(0, 0);

	Bullet* BulletLeftPtr;
	Bullet* BulletRightPtr;
	Bullet* BulletMidPtr;

	// �̷� ������ Has a��� �Ѵ�. Player Has a Bullet
	// Bullet NewBullet; // �÷��̾��� ��ü ���ο� �Ѿ� �ѹ��� �ִ�.
	// Bullet* NewBullet; // �ٱ��� �ִ� �Ѿ��� �����Ҽ� �ִ�.
};

