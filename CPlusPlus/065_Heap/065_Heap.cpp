

#include <iostream>
#include <crtdbg.h>
int main()
{
	// 동적 메모리는 new라는 연산자를 사용한다.
	// 연산자 자료형 생성자
	//  new   int   ();   // 이렇게 쓰면 해당 메모리를 찾을 수 없다. 릭 발생
	int; // 위는 이것과 같은 개념

	// 힙은 가장 자유롭게 매모리를 할당할 수 있는 영역이다.
	// 동적(Dynamic)메모리는 힙 영역에 저장된다.

	int* Ptr = new int();

	delete Ptr;
	// 아래 코드를 실행하면 메모리가 터진다. 
	//while (true)
	//{
	//	new int();
	//}
}