#pragma once
#include "ConsoleGameMath.h"

// Screen에서 움직이는 오브젝트들의 기본기능을 제공한다.
class ConsoleGameObject
{
public:
	inline void SetPos(const int2& _Value)
	{
		Pos = _Value;
	}

	inline void SetRenderChar(const wchar_t _Value)
	{
		RenderChar = _Value;
	}

	inline wchar_t GetRenderChar()
	{
		return RenderChar;
	}

	inline int2 GetPos() const
	{
		return Pos;
	}

	bool IsDeath()
	{
		return DeathValue;
	}

	void Death()
	{
		DeathValue = true;
	}

	bool IsUpdate()
	{
		return UpdateValue;
	}

	void On()
	{
		UpdateValue = true;
	}

	void Off()
	{
		UpdateValue = false;
	}

	virtual bool IsAcquired();
	virtual void Acquire();

	virtual void Update();
	virtual void Render();

protected:
	int2 Pos;
	wchar_t RenderChar = L'＠';
	
private:
	bool UpdateValue = true;
	bool DeathValue = false;
};

