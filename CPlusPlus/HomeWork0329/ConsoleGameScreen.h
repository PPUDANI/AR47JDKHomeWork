#pragma once

#include "ConsoleGameMath.h"

// �̰� 1�ܰ�
// �ٺ����� �ٺ� ���� ���� 
class ConsoleGameScreen
{

public:

	// �޸� ���� ��ü�� �޶����ٰ� �����մϴ�.
	// Ŭ���� ���ο� ���������� �����Ҽ��� �ֽ��ϴ�.
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
