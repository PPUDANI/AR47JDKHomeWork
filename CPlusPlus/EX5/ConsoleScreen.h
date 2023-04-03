#pragma once

#include <string>
class ConsoleScreen
{
public:

	static ConsoleScreen& GetMap();

	void ConsolePrint();
	
	ConsoleScreen(const ConsoleScreen& _Other) = delete;
	ConsoleScreen(ConsoleScreen&& _Other) noexcept = delete;
	ConsoleScreen& operator=(const ConsoleScreen& _Other) = delete;
	ConsoleScreen& operator=(ConsoleScreen&& _Other) noexcept = delete;

protected:

private:
	ConsoleScreen();
	~ConsoleScreen();
	static const int MapSizeY = 20;
	static const int MapSizeX = 40;

	char MapArr[MapSizeY][MapSizeX] = {0,};

	static ConsoleScreen Map;
};

