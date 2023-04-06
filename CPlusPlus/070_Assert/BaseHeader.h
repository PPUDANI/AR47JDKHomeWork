#pragma once
#include <assert.h>
#include <windows.h>

#define MessageBoxA(Value) MessageBoxA(nullptr, Value, "오류입니다.", MB_OK); assert(false)