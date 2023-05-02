// 083_TemplateEx.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include "Temp.h"

int main()
{
    Temp<int> NewTemp;

    NewTemp.Function(10);

    TestFunction<int>(2000);

    std::cout << "Hello World!\n";
}
