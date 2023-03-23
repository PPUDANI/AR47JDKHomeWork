
#include <iostream>

// 자신이 논리적으로 이 연산자를 이렇게 만들면 되겠다 할 수 있는 함수 다 만들기

class Number
{
private:
    int Value = 2;
public:
    Number(int Val) : Value(Val)
    {

    }

    int operator + (int _Value)
    {
        return _Value + Value;
    }

    int operator - (int _Value)
    {
        return _Value - Value;
    }

    int operator * (int _Value)
    {
        return _Value * Value;
    }

    int operator / (int _Value)
    {
        return _Value / Value;
    }

    int operator % (int _Value)
    {
        return _Value % Value;
    }

    int operator [] (size_t Val)
    {

    }
};
int main()
{
    {
        Number Value = 10;

        Value + 10;
        Value.operator+(10); // operator 연산자 겹지정 함수라 부른다.
        Value[30];
    }
}
