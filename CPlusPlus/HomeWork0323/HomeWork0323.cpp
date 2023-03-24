
#include <iostream>

// 자신이 논리적으로 이 연산자를 이렇게 만들면 되겠다 할 수 있는 함수 다 만들기

class Number
{
private:
    int Value;
public:
    Number(int Val) : Value(Val) {}

    // 산술연산자
    int operator + (int _Value) // +
    {
        return Value + _Value;
    }
    int operator - (int _Value) // -
    {
        return Value - _Value;
    }
    int operator * (int _Value) // *
    {
        return Value * _Value;
    }
    int operator / (int _Value) // /
    {
        return Value / _Value;
    }
    int operator % (int _Value) // %
    {
        return Value % _Value;
    }

    // 비트단위 연산자
    int operator ~ () // ~
    {
        return ~Value;
    }
    int operator & (int _Value) // AND
    {
        return Value & _Value;
    }
    int operator | (int _Value) // OR
    {
        return Value | _Value;
    }
    int operator ^ (int _Value) // XOR
    {
        return Value ^ _Value;
    }
    int operator >> (int _Value) // >> Shift
    {
        return Value >> _Value;
    }
    int operator << (int _Value) // >> Shift
    {
        return Value << _Value;
    }

    // 증감 연산자 ('전위'만 구현했고 '후위'는 구현하지 못했음)
    void operator ++ () // ++Value
    {
        ++(this->Value); 
    }
    void operator -- () // --Value
    {
        --(this->Value);
    }


    // 비교연산자
    bool operator == (int _Value) // ==
    {
        return  Value == _Value;
    }
    bool operator != (int _Value) // !=
    {
        return Value != _Value;
    }
    bool operator < (int _Value) // <
    {
        return Value < _Value;
    }
    bool operator > (int _Value) // >
    {
        return Value > _Value;
    }
    bool operator <= (int _Value) // <=
    {
        return Value <= _Value;
    }
    bool operator >= (int _Value) // >=
    {
        return Value >= _Value;
    }
};
int main()
{
    Number Object = 2;

    Object + 10; // 12
    Object - 10; // -8
    Object * 10; // 20
    Object / 10; // 0
    Object % 10; // 2

    
    ~Object; // 0010 -> 1101 : -3

             //  [-3인지 확인 과정]   1101
             //  [2의 보수 제거]      1100 (1101 - 1) 
             //  [1의 보수 제거]      0011 (1100 -> 0011) = '3'

    Object & 1;  // 0010 AND 0001 = 0000(0)
    Object | 1;  // 0010 OR  0001 = 0011(3)
    Object ^ 1;  // 0010 XOR 0001 = 0011(3)
    Object << 1; //         0010 -> 0100(4)
    Object >> 1; //         0010 -> 0001(1)


    ++Object; // 3 실제 값 변경
    --Object; // 2 실제 값 변경

    Object == 10;  // false
    Object != 10;  // true
    Object < 10;   // true
    Object > 10;   // false
    Object <= 10;  // true
    Object >= 10;  // false

    int a = 0;
}
