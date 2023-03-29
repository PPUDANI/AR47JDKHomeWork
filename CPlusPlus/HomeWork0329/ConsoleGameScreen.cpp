
#include "ConsoleGameScreen.h"
#include "ConsoleGameMath.h"

ConsoleGameScreen ConsoleGameScreen::MainScreen;


class ConsoleGameScreen
{
private:
	ConsoleGameScreen();

	static ConsoleGameScreen MainScreen;

public:
	static ConsoleGameScreen& GetMainScreen();


public:
	static const int ScreenYSize = 10;
	static const int ScreenXSize = 20;

	static int2 GetScreenSize();


	void ScreenClear();

	void ScreenPrint() const;


	// 이녀석을 무조건 사용해서 플레이어가 바깥으로 못나가게 만드세요.
	bool IsScreenOver(const int2& _Pos) const;

	void SetScreenCharacter(const int2& _Pos, char _Ch);

private:
	char Arr[ScreenYSize][ScreenXSize] = { 0, };
};

