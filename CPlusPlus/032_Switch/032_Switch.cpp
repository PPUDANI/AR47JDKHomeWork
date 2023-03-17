
#include <iostream>

int main()
{
	int Value = 0;
	// switch문은 메모리 영역과 같은 상수 메모리인지 비교하는 조건문이다.
	// switch문 안에서는 스코프를 생성하지 않는 이상 변수를 생성할 수 없다.
	// break가 있으면 switch문을 종료한다.
	// break가 없으면 break가 나올 때 까지 그 아래 case의 실행함수를 전부 실행하게 된다.

	const int cValue = 1;

	switch (Value)
	{
	case 0:
		printf_s("Value not");
		break;
	case cValue: // 상수 만 넣을 수 있고, 당연하게 상수인 변수도 들어갈 수 있다. (MFC KeyDown()도 Key로 들어가는데 상수인가 봄.)
		printf_s("Value not");
		break;
	case 2:
		printf_s("Value not");
		break;
	case 3:
		printf_s("Value not");
		break;
	default:
		printf_s("Value not");
		break;
	}

	
}

