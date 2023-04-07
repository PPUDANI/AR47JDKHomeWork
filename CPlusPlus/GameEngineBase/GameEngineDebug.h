#pragma once

#include <assert.h>
#include <windows.h>

//class GameEngineDebug
//{
//public:
// // Constrcuter destructer
//	GameEngineDebug();
//	~GameEngineDebug();
//
//  // Delete Function
//	GameEngineDebug(const GameEngineDebug& _Other) = delete;
//	GameEngineDebug(GameEngineDebug&& _Other) noexcept = delete;
//	GameEngineDebug& operator=(const GameEngineDebug& _Other) = delete;
//	GameEngineDebug& operator=(GameEngineDebug&& _Other) noexcept = delete;
// 
//protected:
//
//private:
//
//};

#define MessageBoxA(Value) MessageBoxA(nullptr, Value, "ERROR", MB_OK); assert(false)

