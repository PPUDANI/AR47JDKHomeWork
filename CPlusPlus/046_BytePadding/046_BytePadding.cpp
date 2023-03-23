
#include <iostream>

class Player
{
public:
    
    int Hp = 10;       // 4
    short MP = 20;     // 4
    int Att = 40;      // 4
    short Def = 50;    // 4
    
    //int Hp = 10;       // 8
    //short MP = 20;     // 0
    //int Att = 40;      // 8
    //__int64 Def = 50;  // 8

    // std::vector와 같듯이 제일 큰 변수 기준으로 패딩된다.

};

int main()
{
    Player NewPlayer;
    int Size = sizeof(NewPlayer);

    // 자료형 size
    int intsize = sizeof(int);
    __int64 int64size = sizeof(__int64);

    // 주소 형변환
    __int64 AddressHp = (__int64) & NewPlayer.Hp;
    int* PtrHp = (int*)AddressHp;
    short* PtrMP = (short*)(AddressHp + intsize); // + 4
    int* PtrAtt = (int*)(AddressHp + intsize * 2); // + 8
    short* PtrDef = (short*)(AddressHp + intsize * 3); // + 12

    // 결과적으로 패딩된 공간에 처음 주소부터 차례대로 저장이 된다.
    printf_s("  Hp : %d\n", *PtrHp);
    printf_s("  Mp : %d\n", *PtrMP);
    printf_s(" Att : %d\n", *PtrAtt);
    printf_s(" Def : %d\n\n", *PtrDef);

    printf_s("Size : %d\n", Size);
}
