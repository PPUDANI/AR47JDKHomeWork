
#include <iostream>

class A
{

};
class B : public A
{

};
class C
{

};

int main()
{
	A* Ptr0 = new A();
	A* Ptr1 = new B();
	A* Ptr2 = new C();
}