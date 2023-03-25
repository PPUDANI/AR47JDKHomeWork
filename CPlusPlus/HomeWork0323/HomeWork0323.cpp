
#include <iostream>

// 자신이 논리적으로 이 연산자를 이렇게 만들면 되겠다 할 수 있는 함수 다 만들기

class Number
{
private:
    int Value;
public:
    Number(int Val) : Value(Val) 
    {

    }
#pragma region 단항 연산자 & 증감 연산자

    int operator + ()
    {
        return Value;
    }

    int operator - ()
    {
        return -Value;
    }

    Number& operator ++ () // ++Value
    {
        ++Value;
        return *this;
    }
    Number& operator -- () // --Value
    {
        --Value;
        return *this;
    }
    // ++을 뒤에 써야하니까 인자가 필요하지만 이것은 인자가 필요한 연산자가 아니기 때문에 쓸 수 없는 인자를 넣어준다.
    int operator ++ (int) // Value++
    {
        int Temp = Value;
        ++Value; // Value는 ++해주고 이전값을 리턴한다.
        return Temp;
    }
    int operator -- (int) // Value--
    {
        int Temp = Value;
        --Value;
        return Temp;
    }

#pragma endregion

#pragma region 산술 연산자

    int operator + (const int _Value) // +
    {
        return Value + _Value;
    }
    int operator - (const int _Value) // -
    {
        return Value - _Value;
    }
    int operator * (const int _Value) // *
    {
        return Value * _Value;
    }
    int operator / (const int _Value) // /
    {
        return Value / _Value;
    }
    int operator % (const int _Value) // %
    {
        return Value % _Value;
    }

#pragma endregion

#pragma region 비트 연산자

    int operator ~ () // ~
    {
        return ~Value;
    }
    int operator & (const int _Value) // AND
    {
        return Value & _Value;
    }
    int operator | (const int _Value) // OR
    {
        return Value | _Value;
    }
    int operator ^ (const int _Value) // XOR
    {
        return Value ^ _Value;
    }
    int operator >> (const int _Value) // >> Shift
    {
        return Value >> _Value;
    }
    int operator << (const int _Value) // >> Shift
    {
        return Value << _Value;
    }

#pragma endregion

#pragma region 논리 연산자

    bool operator && (const int _Value) // AND
    {
        return  Value && _Value;
    }
    bool operator || (const int _Value) // OR
    {
        return  Value || _Value;
    }
    bool operator ! () // NOT
    {
        return  !Value;
    }

#pragma endregion

#pragma region 비교 연산자

    bool operator == (const int _Value) // ==
    {
        return  Value == _Value;
    }
    bool operator != (const int _Value) // !=
    {
        return Value != _Value;
    }
    bool operator < (const int _Value) // <
    {
        return Value < _Value;
    }
    bool operator > (const int _Value) // >
    {
        return Value > _Value;
    }
    bool operator <= (const int _Value) // <=
    {
        return Value <= _Value;
    }
    bool operator >= (const int _Value) // >=
    {
        return Value >= _Value;
    }
#pragma endregion

#pragma region 대입 연산자

    int operator = (const int _Value)
    {
        return _Value;
    }
    Number& operator +=(const int _Value) // 기존값에 + 결과 대입
    {
        Value += _Value;
        return *this;
    }
    Number& operator -=(const int _Value) // 기존값에 - 결과 대입
    {
        Value -= _Value;
        return *this;
    }
    Number& operator *=(const int _Value) // 기존값에 * 결과 대입
    {
        Value *= _Value;
        return *this;
    }
    Number& operator /=(const int _Value) // 기존값에 / 결과 대입
    {
        Value /= _Value;
        return *this;
    }
    Number& operator %=(const int _Value) // 기존값에 % 결과 대입
    {
        Value %= _Value;
        return *this;
    }
    Number& operator <<= (const int _Value) // 기존값에 Right Shift 결과 대입
    {
        Value <<= _Value;
        return *this;
    }
    Number& operator >>=(const int _Value) // 기존값에 Left Shift 결과 대입 
    {
        Value >>= _Value;
        return *this;
    }
    Number& operator &=(const int _Value) // 기존값에 AND 결과 대입
    {
        Value &= _Value;
        return *this;
    }
    Number& operator |=(const int _Value) // 기존값에 OR 결과 대입
    {
        Value |= _Value;
        return *this;
    }
    Number& operator ^=(const int _Value) // 기존값에 XOR 결과 대입
    {
        Value ^= _Value;
        return *this;
    }

#pragma endregion

#pragma region 멤버 & 포인터 연산자 . & * [] ->
    
    // 주소가 반환이 되어야 하고 입력값은 객체이다. 
    // 메모리 최적화를 위해 call by reference
    int* operator & ()
    {
        return &(this->Value);
    }
    int operator * ()
    {
        return Value;
    }
    int operator -> () // 진짜 모르겠음
    {
        return Value;
    }
    int operator [] (int _Value)
    {
        return 
    }

#pragma endregion 
    
#pragma region 삼항 연산자
    //int operator a?b: (int a, int b)
    //{
    //     안되는듯
    //}
#pragma endregion 

};
int main()
{
    Number Object = 2;

    int num = Object + 10; // 12
    Object - 10; // -8
    Object * 10; // 20
    Object / 10; // 0
    Object % 10; // 2


    int ObjPtr = *Object;
    ObjPtr = (int) & Object;
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
