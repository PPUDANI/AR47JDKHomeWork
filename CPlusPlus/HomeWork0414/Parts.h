#pragma once
#include <GameEngineConsole/ConsoleGameObject.h>
#include <GameEngineConsole/ConsoleGameScreen.h>
#include <vector>
// Ό³Έν :
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

	inline Parts* SetNext()
	{
		return Next;
	}

	inline void SetNext(Parts* _Next)
	{
		Next = _Next;
	}

	void SetCurVector()
	{
		if (Next == nullptr)
		{
			CurVector = ;
		}

		CurVector = Next->GetPos() - Pos;
		return Next->SetCurVector();
	}
	int2 GetPrevPos()
	{
		return PrevPos;
	}

	void NextMove();

protected:
	void Update() override;
	
private:
	static int2 ScreenSize;
	static std::vector<std::vector<int>> EmptyCheckArr;

	int2 PrevPos = int2::Zero;
	int2 CurVector = int2::Zero;
	Parts* Next = nullptr;
	Parts* Prev = nullptr;
	
	
};
