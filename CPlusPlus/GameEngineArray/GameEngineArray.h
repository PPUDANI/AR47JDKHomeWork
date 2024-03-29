#pragma once

typedef int DataType;
// 설명 :
class GameEngineArray
{
public:
	// delete Function
	GameEngineArray(const GameEngineArray& _Other) = delete;
	GameEngineArray(GameEngineArray&& _Other) noexcept = delete;
	GameEngineArray& operator=(GameEngineArray&& _Other) noexcept = delete;


	// constrcuter destructer
	GameEngineArray(size_t _Value)
		: ArrPtr(new DataType[_Value])
		, ArrCount(_Value)
	{
		// ArrPtr = new int[100];
		if (0 >= ArrCount)
		{
			// MessageBoxA("메모리의 크기가 0 이상이어야 합니다.");
		}
	}

	~GameEngineArray()
	{
		if (nullptr != ArrPtr)
		{
			delete[] ArrPtr;
			ArrPtr = nullptr;
		}
	}

	GameEngineArray& operator=(const GameEngineArray& _Other)
	{
		this->ReSize(_Other.ArrCount);

		// ArrPtr = _Other.ArrPtr;
		for (int i = 0; i < _Other.ArrCount; i++)
		{
			ArrPtr[i] = _Other.ArrPtr[i];
		}

		return *this;
	}

	size_t Count()
	{
		return ArrCount;
	}

	DataType& operator[](size_t _Index)
	{
		return ArrPtr[_Index];
	}

	void ReSize(int _Value)
	{
		// 20줄 안팍.
		// 삼항 연산자 써보시면 좋을겁니다.

		// 기존의 할당된 배열을 알고 있는것은 
		// 섣불리 지우면 안된다.

		// 기존의 있던 값에서 현재의 배열이 복사한다음 삭제해야 한다.

		if (nullptr != ArrPtr)
		{
			DataType* TempPtr = ArrPtr;

			ArrPtr = new DataType[_Value];

			for (int i = 0; i < _Value; i++)
			{
				ArrPtr[i] = TempPtr[i];
			}

			delete[] TempPtr;

			ArrCount = _Value;
		}
	}

protected:

private:
	size_t ArrCount;
	DataType* ArrPtr = nullptr;

};

