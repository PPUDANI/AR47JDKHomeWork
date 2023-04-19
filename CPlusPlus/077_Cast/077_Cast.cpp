
#include <iostream>

class A
{
    virtual void Test()
    {

    }
};

class B : public A
{
    virtual void Test()
    {

    }
};

class C : public A
{
    virtual void Test()
    {

    }
};
int main()
{
    {
        // 암시적 형변환
        short Test;
        int Value = Test;
    }

    // static_cast : 기본적인 형변환
    {
        // 메모리 크기만 다를 뿐 서로 값 형태이다.
        // C++에서는 별로 권장하지 않는 방식이다.
        short Test;
        int Value;
        
        Value = (int)Test; // C스타일 형변환
        Value = static_cast<int>(Test); // C++스타일 형변환
        // C스타일 형변환을 하면 C++스타일 형변환으로 바꾼다.
        // 더 작업을 많이 하므로 후자를 사용하는게 좋다.
        Value = Test;
    }

    // reinterpret_cast : 포인터 형변환
    {
        int Value = 3;
        int* Ptr = &Value;

        __int64 Address = reinterpret_cast<__int64>(&Value);
        Address = reinterpret_cast<__int64>(Ptr);
        Address = (__int64)Ptr; // C스타일이고 이것도 마찬가지로 C++에 적합한 형변환 코드로 바꿈.

        int* Ptr2 = reinterpret_cast<int*>(Address);

    }

    // dynamic_cast : 다운캐스팅 형변환으로 안전하게 형변환 되도록 도와준다.
    // 업 캐스팅도 가능하다. 근데 업캐스팅은 위험하지 않기 때문에 안전검사가 필요하지 않으므로  dynamic_cast를 사용하지 않는다.
    {
        
        A NewA;
        B NewB;
        A* PtrA = &NewA;
        B* PtrB = &NewB;

    }
    {
        A* PtrB = new B();
        B* Test = dynamic_cast<B*>(PtrB);
        B* Test1 = (B*)PtrB;
    }
    {
        A* PtrC = new C();
        // 형이 맞지 않아서 null이 저장된다.
        B* Test = dynamic_cast<B*>(PtrC);

        // 그냥 저장된다. 논리적으로 말이 안되며 무슨일이 벌어질지 모른다.
        B* Test1 = (B*)PtrC;
    }

    // const_cast 존재만 한다.
    // 선생님은 한번도 쓰지 않았으니 알아서 찾아보라 함.
    {
       
    }
}
