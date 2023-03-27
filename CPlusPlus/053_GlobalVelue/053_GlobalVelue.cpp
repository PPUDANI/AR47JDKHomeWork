
#include <iostream>
// C++은 객체지향 언어가 아니다,
// 전역의 존재 때문이다.
// 객체지향은 클래스와 객체로만 코딩을 해야하는데 전역변수를 사용할 시 객체지향이 아니게 된다.

// 객체지향을 간단히 말하면 객체와 클래스로만 코딩해야하며 다른건 사용하지 마라.
// 하지만 C++은 C에서 파생이 되어왔기 때문에 C의 잔재가 남아있어 절차와 객체가 섞여있다.

class Monster
{

    int Print();

public:
    // 퍼포먼스 확인 ex) 60프레임으로 돌아가려면 몇마리가 최대인지 확인하기 위해
    // 현재까지 만들어진 모든 몬스터의 수
    int MonsterCount = 0;
    static int MonCount0;

    Monster()
    {   // 하지만 이러면 각자가 MonsterCount를 가지고 있기 때문에 원하는 기능을 구현할 수 없다.
        ++MonsterCount;

        // 아래와 같이 static 변수를 선언하면 이 변수를 모든 객체가 공유할 수 있다.
        ++MonCount0;
    }
private:
    static const int MonCount1 = 3;
    int Arr[MonCount1][MonCount1] = {0,};
    static int MonCount2;
};

const int MonCount1 = 3;
// 실체를 둔다.
int Monster::MonCount2 = 0;

int main()
{
    Monster NewMonster0;
    Monster NewMonster1;
    Monster NewMonster2;
    Monster NewMonster3;

    // static은 일반적인 멤버변수가 아니다.
    // 밖에서도 변경이 가능하다.
    // 이런것들은 여기서 쓰지 말라고 주석을 달아놓았다면
    
    Monster::MonCount0 = 20; 

    // 이를 접근제한지정자 private으로 변경하고 Monster 내부에서만 사용 가능하게 해준다.
    // Monster::MonCount2 = 30;
}
