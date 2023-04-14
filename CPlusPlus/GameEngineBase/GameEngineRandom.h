#pragma once
class GameEngineRandom
{
public:
	GameEngineRandom();
	GameEngineRandom(int _Seed);
	~GameEngineRandom();

	GameEngineRandom(const GameEngineRandom& _Other) = delete;
	GameEngineRandom(GameEngineRandom&& _Other) noexcept = delete;
	GameEngineRandom& operator=(const GameEngineRandom& _Other) = delete;
	GameEngineRandom& operator=(GameEngineRandom&& _Other) noexcept = delete;

	int RandomInt(int _Min, int _Max)
	{
		return (rand() % (_Max - _Min + 1)) + _Min;
	}
protected:

private:
	int Seed;
};

