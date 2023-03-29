#pragma once

#include "ConsoleGameMath.h"

// 이게 1단계
// 근본오브 근본 수학 물리 
class ConsoleGameScreen
{

public:

	// 메모리 영역 자체가 달라졌다고 봐야합니다.
	// 클래스 내부에 전역변수를 선언할수가 있습니다.
	static const int ScreenYSize = 10;
	static const int ScreenXSize = 20;

	inline static ConsoleGameScreen& GetMainScreen()
	{
		return MainScreen;
	}
	static int2 GetScreenSize();

	void ScreenClear();

	void ScreenPrint() const;

	bool IsScreenOver(const int2& _Pos) const;

	void SetScreenCharacter(const int2& _Pos, char _Ch);

	void SetScreenBullet(int2& _Pos, char _Ch);
private:
	char Arr[ScreenYSize][ScreenXSize] = { 0, };

	ConsoleGameScreen();

	static ConsoleGameScreen MainScreen;
};
