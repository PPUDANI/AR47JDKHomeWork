#pragma once
class int2
{
public:
	int2();
	int2(int _Y, int _X);
	~int2();

	int2(const int2& _Other) = delete;
	int2(int2&& _Other) noexcept = delete;
	int2& operator=(const int2& _Other) = delete;
	int2& operator=(int2&& _Other) noexcept = delete;
protected:

private:
	int Y;
	int X;
};

