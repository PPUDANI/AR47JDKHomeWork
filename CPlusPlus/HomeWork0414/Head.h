#pragma once
#include "Parts.h"
#include "Body.h"

// Ό³Έν :
class Head : public Parts
{
public:
	// constructor destructor
	Head();
	~Head();

	// delete Function
	Head(const Head& _Other) = delete;
	Head(Head&& _Other) noexcept = delete;
	Head& operator=(const Head& _Other) = delete;
	Head& operator=(Head&& _Other) noexcept = delete;

	static bool IsPlay;
	static int GetEmptyCount()
	{
		return EmptyCount;
	}

protected:
	void Update() override;
	void BodyUpdate();
	void IsBodyCheck();
	void NewBodyCreateCheck();

private:
	static int EmptyCount;
	int2 Dir = int2::Right;
	int2 PrevPos;
	bool a = false;
};

