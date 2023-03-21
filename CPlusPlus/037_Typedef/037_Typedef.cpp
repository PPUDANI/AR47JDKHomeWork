
#include <iostream>

// typedef : 기존 자료형의 이름을 바꿔서 사용하는 기능
//         (자료형)  (이름)
typedef unsigned int uint;

// using : typedef와 같은 기능
//   (자료형)  (이름)
using newint = int;

// 컴파일러는 우리가 이렇게 자료형의 별명을 지어도
// 컴파일 시 해당 자료형은 원 자료형으로 바꾼다.

// 선언부를 보고싶으면 커서를 해당 코드 줄에 두고 F12
// 헤더파일 내부를 보고싶으면 커서를 해당 코드 줄에 두고  Ctrl + Shift + G

int main()
{
	newint newVel = 0;
	uint iVal = 0;
	for (size_t i = 0; i < 10; i++)
	{

	}
}
