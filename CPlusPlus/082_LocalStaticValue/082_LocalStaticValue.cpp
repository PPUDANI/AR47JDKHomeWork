
#include <iostream>
void TestFunction()
{
	static int Value = 0; // 지역 static은 전역변수가 생성되는것과 같지만 이 함수에서만 쓸 수 있는 변수이다.
	std::cout << Value << std::endl;
	++Value;
}
int main()
{
	for (size_t i = 0; i < 10; i++)
	{
		TestFunction();
	}

    std::cout << "Hello World!\n";
}
