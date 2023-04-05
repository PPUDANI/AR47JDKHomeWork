
#include <iostream>

// 함수를 마법처럼 오버로딩 해주는 것이 아니라
// 
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

int main()
{
    Function/*<int>*/(100);
    Function/*<bool>*/(true);
    Function/*<char>*/('c');
    Function<int>('c');

}
