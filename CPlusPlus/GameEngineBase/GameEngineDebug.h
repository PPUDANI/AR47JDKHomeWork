#pragma once

#include <assert.h>
#include <windows.h>

//class GameEngineDebug
//{
//public:
//	GameEngineDebug();
//	~GameEngineDebug();
//
//	GameEngineDebug(const GameEngineDebug& _Other) = delete;
//	GameEngineDebug(GameEngineDebug&& _Other) noexcept = delete;
//	GameEngineDebug& operator=(const GameEngineDebug& _Other) = delete;
//	GameEngineDebug& operator=(GameEngineDebug&& _Other) noexcept = delete;
//protected:
//
//private:
//
//};

#define MessageBoxA(Value) MessageBoxA(nullptr, Value, "ERROR", MB_OK); assert(false)

