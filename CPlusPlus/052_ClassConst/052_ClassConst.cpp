
#include <iostream>

class Palyer
{
private:
	int Att;
	int Hp;
	int Def;

public:

	// 함수 뒤에 const가 붙을 수 있다.
	// 이 함수를 호출해도 이 클래스를 통해 만들어진 객체는 변화하지 않는다.
	void PrintStatus(/*const Player* this*/) const
	{
		this; // this가 const로 생성된다.
		// Att += 100;
		printf_s("플레이어의 능력치 -------------");
		printf_s("  공격력: %d", Att);
		printf_s("  방어력: %d", Def);
		printf_s("------------------------------");
	}
	int SetHp(int _Value)
	{
		return Hp++;
	}
	int GetHp() const // 함수가 값을 변경시키지 않는다는 것을 명시해준다. 이런 습관을 들이자.
	{
		return Hp;
	}

};
int main()
{

}

// 전역 변수 저장공간은 데이터영역
// class의 전역변수로는 static