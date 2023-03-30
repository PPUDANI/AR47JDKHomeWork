#include "Bullet.h"
#include "ConsoleGameScreen.h"
#include <conio.h>
#include <Windows.h>
#include "Player.h"

Bullet Bullet::ArrBulletMid[Bullet::MaxBulletNum];

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