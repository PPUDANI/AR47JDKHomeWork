#include "Bullet.h"
#include "ConsoleGameScreen.h"
#include <conio.h>
#include <Windows.h>
#include "Player.h"

Bullet Bullet::ArrBulletLeft[Bullet::MaxBulletNum];
Bullet Bullet::ArrBulletMid[Bullet::MaxBulletNum];
Bullet Bullet::ArrBulletRight[Bullet::MaxBulletNum];

int Bullet::BulletCount = 0;

void Bullet::AllRender()
{
	for (size_t i = 0; i < Bullet::MaxBulletNum; i++)
	{
		if (false == ArrBulletMid[i].IsFire())
		{
			continue;
		}

		ArrBulletMid[i].Render();
		ArrBulletLeft[i].Render();
		ArrBulletRight[i].Render();
	}
}

void Bullet::AllUpdate()
{
	for (size_t i = 0; i < Bullet::MaxBulletNum; i++)
	{
		if (false == ArrBulletMid[i].IsFire())
		{
			continue;
		}

		ArrBulletMid[i].UpdateMid();
		ArrBulletLeft[i].UpdateLeft();
		ArrBulletRight[i].UpdateRight();
	}
}

Bullet::Bullet()
{

}

void Bullet::Render()
{
	if (true == Fire)
	{
		ConsoleGameScreen::GetMainScreen().SetScreenCharacter(Pos, '^');
	}
}

void Bullet::UpdateMid()
{
	if (true == Fire)
	{
		--Pos.Y;
	}
}

void Bullet::UpdateLeft()
{
	if (true == Fire)
	{
		--Pos.Y;
		--Pos.X;
	}
}

void Bullet::UpdateRight()
{
	if (true == Fire)
	{
		--Pos.Y;
		++Pos.X;
	}
}
