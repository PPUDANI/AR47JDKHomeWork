#include "ShootingGame.h"

#include <iostream>
// 내가 만든건 ""
#include "Player.h"
#include "Bullet.h"
#include "Monster.h"
#include "ConsoleGameScreen.h"

Player ShootingGame::NewPlayer;
Monster ShootingGame::ArrMonster[ShootingGame::ArrMonsterCount];

void ShootingGame::Loading()
{
	// 게임이 시작하기 전에 준비한다.
	// 총알이 여러발 나가게 만드세요.

	// 시작하면 어차피 모든 총알은 발사되지 않았을것이므로 다 끈다.
	Bullet::AllOff();

	// 플레이어가 총알의 포인터를 알게 한다.
	NewPlayer.SetBulletArr(Bullet::GetArrBullet());

	// 플레이어를 화면의 중앙에 위치시킨다.
	int2 ScreenSize = ConsoleGameScreen::GetMainScreen().GetScreenSize();
	NewPlayer.SetPos(ScreenSize.Half());

	for (int i = 0; i < ArrMonsterCount; i++)
	{
		ArrMonster[i].SetPos({ i + 3, 1 });
	}

}

void ShootingGame::Collision()
{

	Bullet* BulletArr = Bullet::GetArrBullet();

	// 모든 총알과
	for (size_t BulletIndex = 0; BulletIndex < Bullet::ArrBulletCount; BulletIndex++)
	{
		Bullet& CurBullet = BulletArr[BulletIndex];

		if (false == CurBullet.IsUpdate())
		{
			continue;
		}

		for (size_t MonsterIndex = 0; MonsterIndex < ShootingGame::ArrMonsterCount; MonsterIndex++)
		{
			Monster& CurMonster = ArrMonster[MonsterIndex];

			if (false == CurMonster.IsUpdate())
			{
				continue;
			}

			if (CurMonster.GetPos() == CurBullet.GetPos())
			{
				CurMonster.Off();
				CurBullet.Off();
			}
		}
	}

}

void ShootingGame::MonsterDown()
{
	for (int i = 0; i < ArrMonsterCount; i++)
	{
		int2 UpdatePos = ArrMonster[i].GetPos();
		UpdatePos.Y += 1;
		ArrMonster[i].SetPos(UpdatePos);
	}
}
void ShootingGame::MonsterEndCheck()
{

	// 1. 움직이게 한다.
	if (Monster::GetDir() > 0)
	{
		for (int i = ArrMonsterCount - 1; i >= 0; i--)
		{
			if (ArrMonster[i].IsUpdate() == true)
			{
				int2 UpdatePos = ArrMonster[i].GetPos();
				UpdatePos.X += Monster::GetDir();
				if (true == ConsoleGameScreen::GetMainScreen().IsMonScreenOver(UpdatePos, Monster::GetDir()))
				{
					Monster::TransDir();
					ShootingGame::MonsterDown();
					break;
				}
				else
				{
					ArrMonster[i].SetPos(UpdatePos);
				}
			}
		}
	}
	else if (Monster::GetDir() < 0)
	{
		for (int i = 0; i < ArrMonsterCount; i++)
		{
			if (ArrMonster[i].IsUpdate() == true)
			{
				int2 UpdatePos = ArrMonster[i].GetPos();
				UpdatePos.X += Monster::GetDir();
				if (true == ConsoleGameScreen::GetMainScreen().IsMonScreenOver(UpdatePos, Monster::GetDir()))
				{
					Monster::TransDir();
					ShootingGame::MonsterDown();
					break;
				}
				else
				{
					ArrMonster[i].SetPos(UpdatePos);
				}
			}
		}
	}

	// 4. 내려도 본다.
}

void ShootingGame::GameUpdate()
{
	while (true)
	{
		system("cls");

		ConsoleGameScreen::GetMainScreen().ScreenClear();

		// 캐릭터 위치에 글자를 하나 띄운다.
		NewPlayer.Render();
		Bullet::AllRender();
		for (size_t i = 0; i < ArrMonsterCount; i++)
		{
			ArrMonster[i].Render();
		}

		MonsterEndCheck();
		Collision();

		ConsoleGameScreen::GetMainScreen().ScreenPrint();

		NewPlayer.Input();
		Bullet::AllUpdate();
		for (size_t i = 0; i < ArrMonsterCount; i++)
		{
			ArrMonster[i].Update();
		}

	}
}

void ShootingGame::GameProgress()
{
	Loading();
	GameUpdate();
}