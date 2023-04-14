#include "GameEngineRandom.h"
#include <iostream>
GameEngineRandom::GameEngineRandom()
{
	Seed = time(nullptr);
	srand(Seed);
}

GameEngineRandom::GameEngineRandom(int _Seed)
{
	Seed = _Seed;
	srand(Seed);
}


GameEngineRandom::~GameEngineRandom()
{

}