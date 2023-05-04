
#include <iostream>
#include <windows.h>

int main()
{
    LARGE_INTEGER Count;
    LARGE_INTEGER Start;
    LARGE_INTEGER End;

    QueryPerformanceFrequency(&Count);
    QueryPerformanceCounter(&Start);
    

    for (int i = 0; i < 5000; i++)
    {
        std::cout << i;
        system("cls");
    }

    QueryPerformanceCounter(&End);

    double Tick = static_cast<double>(End.QuadPart - Start.QuadPart) / static_cast<double>(Count.QuadPart);

    float floatTick = static_cast<float>(Tick);
    printf("%.4f초 걸렸습니다.", floatTick);

}
