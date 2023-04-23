#pragma once
#include <GameEngineConsole/ConsoleGameObject.h>
#include <GameEngineConsole/ConsoleGameScreen.h>
#include <vector>
// ¼³¸í :
class Parts : public ConsoleGameObject
{
	
public:
	// constructor destructor
	Parts();
	~Parts();

	// delete Function
	Parts(const Parts& _Other) = delete;
	Parts(Parts&& _Other) noexcept = delete;
	Parts& operator=(const Parts& _Other) = delete;
	Parts& operator=(Parts&& _Other) noexcept = delete;

	Parts* GetLast();

	inline void SetPos(const int2& _Value) override
	{
		PrevPos = GetPos();
		ConsoleGameObject::SetPos(_Value);
	}

	inline Parts* GetNext()
	{
		return Next;
	}

	inline void SetNext(Parts* _Next)
	{
		Next = _Next;
	}

	void SetNextDir()
	{
		if (Next == nullptr)
		{
			return;
		}
		int2 NextPos = Next->GetPos();
		Next->Dir = Pos - NextPos;
	}

	int2 GetPrevPos()
	{
		return PrevPos;
	}
	
	void SetRenderChar()
	{
		if (int2::Up == Dir)
		{
			RenderChar = L'¡ã';
		}
		else if (int2::Down == Dir)
		{
			RenderChar = L'¡å';
		}
		else if (int2::Left == Dir)
		{
			RenderChar = L'¢¸';
		}
		else if (int2::Right == Dir)
		{
			RenderChar = L'¢º';
		}
	}

	void NextMove();

	inline bool IsAcquired()
	{
		return Acquired;
	}

	inline void Acquire()
	{
		Acquired = true;
	}


protected:
	void Update() override;
	int2 Dir = int2::Right;

	

private:
	static int2 ScreenSize;
	static std::vector<std::vector<int>> EmptyCheckArr;

	int2 PrevPos = int2::Zero;
	
	Parts* Next = nullptr;
	Parts* Prev = nullptr;
	
	bool Acquired = false;
};
