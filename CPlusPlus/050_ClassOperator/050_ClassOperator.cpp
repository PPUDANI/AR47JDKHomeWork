
#include <iostream>

class Number
{
private:
    int Value;
public:
    Number(int Val) : Value(Val)
    {

    }

    int operator + (int Val)
    {
        return Val + Value;
    }

    bool operator == (int Val)
    {
        return Value == Val;
    }

    int operator [] (size_t Val)
    {

    }
};
int main()
{
    {
        int Value = 10;
        Value + 10;
    }

    // 자신이 논리적으로 이 연산자를 이렇게 만들면 되겠다 할 수 있는 함수 다만들기
    {
        Number Value = 10;

        Value + 10;
        Value.operator+(10); // operator 연산자 겹지정 함수라 부른다.
        Value[30];
    }
}
