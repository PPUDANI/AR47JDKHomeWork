#pragma once
#include "Parts.h"
#include "Body.h"

// ���� :
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

protected:
	void Update() override;
	void IsBodyCheck();

private:
};

