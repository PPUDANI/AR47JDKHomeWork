

#include <iostream>

class A
{
// private: 디폴트 접근제한 지정자
    int a;


//public:
// 
// A& opertaor = (const A& _Order); 디폴트 대입 연산자
// A& opertaor = (const A&& _Order); RVaiue 대입 연산자
// 
//    A(); 디폴트 생성자
//    A(const A& _Order); 디폴트 복사(대입) 생성자 
//    A(const A&& _Order); RVaiue 복사(대입) 생성자
// 
//   ~A(); 디폴트 소멸자



public:
    // delete; -> 쓰지 않겟다.
    // A(const A&& _Order) = delete;  delete로 바꾸면 대입을 할 수 없게 된다.
};

int main()
{
    A NewA0 = A();
    A NewA1 = A();
    std::cout << "Hello World!\n";
}

