// EX6.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include "A.h"

template <typename Datatype>
class Ptr
{
	Datatype* Ptr1= nullptr;
};


class B
{
public:
	int a = 3;
	B* Ptr = nullptr;

	int GetA()
	{
		return a;
	}

	void SetPtr(B* _Ptr)
	{
		Ptr = _Ptr;
	}
	int PtrGetA()
	{
		return Ptr->GetA();
	}

};

B* Ptr = new B;

int main()
{
	A Obj(10);

	std::cout << Obj.GetVal();

	B ObjB{};

	ObjB.SetPtr(&ObjB);
	int a = ObjB.PtrGetA();

	std::cout << a;
}

