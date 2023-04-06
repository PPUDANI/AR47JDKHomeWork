﻿// GameEngineArray.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <conio.h>
#include "GameEngineArray.h"

int main()
{
    // 외우셔야 합니다.
// 윈도우 전용 삭제하지 않은 힙 메모리 출력에 표시. 
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    {
        // 컴파일러에서 지원하는 Arr형에는
        // operator = 함수를 구현하지 않았다.
        int Arr0[10] = { 0, 1, 2, 3 ,4, 5,6 };
        int Arr1[10];
        // Arr1 = Arr0;
    }

    {
        //               600번지
        // int* ArrPtr = new int[20]
        GameEngineArray Array0(10);

        
        for (size_t i = 0; i < Array0.Count(); i++)
        {
            Array0[i] = i;
        }

        //          700번지
        // ArrPtr = new int[10]
        // 숙제 1 기존의 데이터를 보존하는것을 말하는것이고
        // 숙제 2 줄어들든 커지든 데이터는 보존되어야 한다.
        // Array0.ReSize(5);

        Array0.ReSize(5);

        // Array0.ReSize(15);
        printf_s("<숙제 3, 4>\n");
        for (size_t i = 0; i < Array0.Count(); i++)
        {
            printf_s("%d ", Array0[i]);
        }

        // GameEngineArray Array1;
        // Array0 = Array1;
    }
    
    {
        GameEngineArray Array0(10);
        GameEngineArray Array1(5);

        // 숙제3 왜 터지는지 이해하고 고쳐라.
        // 같은걸 가리키고 있어서 소멸자가 실행될 때 Array1이 delete 되면 Array는 아무것도 없는 곳을 가리키게 된다.
        // 결국 같은곳을 두 번 지우게 된다.
        // Ptr 값을 전달하는 것이 아니라 배열에 저장되어 있는 값을 복사해서 넣어주게 한다.
        Array1 = Array0;
    }

    {
        GameEngineArray Array0(10);
        GameEngineArray Array1(5);

        for (size_t i = 0; i < Array0.Count(); i++)
        {
            Array0[i] = i;
        }

        // 숙제4 완전히 동일한 배열이 되게 만들어주세요.
        // Array1 10개 짜리 배열이 되고 0 1 2 3 4 5 6 7 8 9
        Array1 = Array0;

        printf_s("\n\n<숙제 3, 4>\n");
        for (size_t i = 0; i < Array1.Count(); i++)
        {
            printf_s("%d ", Array1[i]);
        }

    }


    // std::cout << "Hello World!\n";
}
