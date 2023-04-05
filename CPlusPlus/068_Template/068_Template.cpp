
#include <iostream>

// 함수를 마법처럼 오버로딩 해주는 것이 아니라
// 개발자의 귀찮음을 덜어주기위해 똑같이 오버로딩 해주게 되는 것이다.
// 물리적으로 오버로딩을 해주게 되어 컴파일이 느려질 수 있다.
template <typename DataType>
void Function(DataType _Value)
{
    printf_s("%d\n", _Value);
}

// 탬플릿으로 만든 함수가 있는데 이게 char일때만 이렇게 동작해줘 라는
// 템플릿 특수화문법
// 안적어도 되지만 명시적으로 적어주자.
template <>
void Function(char _Value)
{
    printf_s("%c\n", _Value);
}

template <typename DataType>
class Test
{
public:
    DataType Val;

    Test() : Val((DataType)10)
    {

    }
};

int main()
{
    // 정석 코드는 아래와 같지만 붙여주지 않아도 된다.
    Function/*<int>*/(100);
    Function/*<bool>*/(true);
    Function/*<char>*/('c');
    Function<int>('c');

    Test <int> NewTest0;
}
