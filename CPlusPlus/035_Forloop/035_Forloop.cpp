
#include <iostream>

int printinit()
{
    printf_s("초기화문\n");
    return 0;
}
void printTrue()
{
    printf_s("조건문\n");
}
void printPlus()
{
    printf_s("증감문\n");
}

int main()
{
    int count = 0;
    
    //while (count <= 10)
    //{
    //    count++;
    //}

    for ( int i = printinit(); i < 10; i++ )
    {
        count++;
    }

    std::cout << count;


}
