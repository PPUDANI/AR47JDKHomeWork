#pragma once


template<typename DataType>
class Temp
{
public:
	Temp();
	~Temp();

	Temp(const Temp& _Other) = delete;
	Temp(Temp&& _Other) noexcept = delete;
	Temp& operator=(const Temp& _Other) = delete;
	Temp& operator=(Temp&& _Other) noexcept = delete;
protected:

private:
	void function(DataType _Data);
};

