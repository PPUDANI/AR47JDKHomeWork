#pragma once

typedef int DataType;
// ���� :
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
			//MessageBoxA("�޸��� ũ�Ⱑ 0 �̻��̾�� �մϴ�.");
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
		// 20�� ����.
		// ���� ������ �Ẹ�ø� �����̴ϴ�.

		// ������ �Ҵ�� �迭�� �˰� �ִ°��� 
		// ���Ҹ� ����� �ȵȴ�.

		// ������ �ִ� ������ ������ �迭�� �����Ѵ��� �����ؾ� �Ѵ�.

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

