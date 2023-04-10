#pragma once

class A
{
public:
	A(int _Val) : Value(_Val)
	{

	}
	int GetVal() const
	{
		return Value;
	}

private:
	int Value;
};

