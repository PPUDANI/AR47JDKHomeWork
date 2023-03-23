
#include <iostream>

class Player
{
public:
    // 이곳에서 초기화를 하면 리터럴 초기화라고 한다.
    // C++ 11 이전에는 없었던 방식이고 회사에서 사용하지 않을 수도 있다.
    int Hp = 10;
    int MaxAtt;
    int MinAtt;
    int PDef;
    int MDef;
    int Crit;

    // 무조건 클래스 이름과 완전히 동일해야 한다.
    // 리턴값이 그 클래스의 객체이기 떄문에 리턴값이 없다.
    // 일반적인 함수와는 다른 예외함수이다.
    // 일반적인 클래스의 함수는 무조건 객체가 팰오하는데
    // 객체를 만들어내는 함수가 객체를 필요로 하면 모순이 생긴다.
    // 객체없이 호출이 가능하다.
    // 생성자는 객체가 생성될 때 실행되는 것이다.
    // 멤버 이니셜라이저가 변수 초기화 이후에 실행되기 때문에 객체를 생성하면 최종값이 된다.
    // 리터럴초기화로 Hp = 10으로 설정했지만 아래 멤버 이니셜라이저가 실행되어 Hp의 값이 20으로 변경된다.
    /*Player*/ Player() : Hp(20), MaxAtt(30), MinAtt(40), PDef(50), MDef(60), Crit(70) // 멤버 이니셜라이저 라는 문법 (MFC도 가능)
    {

    }
    /*Player*/ Player(int Value) : Hp(20), MaxAtt(30), MinAtt(40), PDef(50), MDef(60), Crit(70) // 멤버 이니셜라이저 라는 문법 (MFC도 가능)
    {

    }
    /*Player*/ Player(int Value, int Val) : Hp(20), MaxAtt(30), MinAtt(40), PDef(50), MDef(60), Crit(70) // 멤버 이니셜라이저 라는 문법 (MFC도 가능)
    {

    }

    ~Player() 
    {

    }

    void TestFunction()
    {

    }
};

int main()
{
    Player NewPlayero = Player(); // 생성자는 객체을 만들어내는 지역함수이다.
    Player New; //이것과 차이점은?

    // int도 int의 생성자가 호출된 것이다.
    // 아래와 같이 클래스와 자료형은 완벽히 똑같다. 용도가 다를 뿐
    Player NewPlayer = Player(20);
    int i = int(20);


    // 리스트 이니셜라이저 문법
    Player NewPlayerL = { 20 ,30 };
    Player NewPlayerL1 = Player(30, 20);

    // Player::TestFunction();
    // 멤버함수는 위와 같이 사용할 수 없다.

    NewPlayer.TestFunction();
    // 위와 같이 클래스의 멤버함수는 무조건 객체를 필요로 한다.

    // 하지만 
    
}

