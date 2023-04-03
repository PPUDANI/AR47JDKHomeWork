#pragma once

class ShootingGame
{
public:
	ShootingGame();
	~ShootingGame();

	static void GameRender();
	static void GameProgress();

	ShootingGame(const ShootingGame& _Other) = delete;
	ShootingGame(ShootingGame&& _Other) noexcept = delete;
	ShootingGame& operator=(const ShootingGame& _Other) = delete;
	ShootingGame& operator=(ShootingGame&& _Other) noexcept = delete;
protected:

private:
	
};

