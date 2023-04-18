#include <iostream>

int main()
{
    // 문자는 굉장히 많이 사용된다.
    // 파일 입출력이나 경로를 표현할 때 문자를 잘 편집할 수 있어야 한다.
    // 그래서 문자열을 편집하는 기술이나 알고리즘 함수들에 대해서 많이 알면 알수록 편해진다.

    // 인코딩
    // 1Byte 인코딩 : 아스키 혹은 ANSI
    
    // 1 ~ 2Byte 멀티바이트 인코딩 < == 65,536자로 국가마다의 문자를 표현할 수 있게 되었다.

    // 2Byte 와이트바이트
    // 2Byte 인코딩 까지는 국가별로 달라지는 매칭형식이다.

    // 우리나라에서 저장한 텍스트파일이 다른 나라에서 열면 깨짐.
    // "가"가 만약 5001이라면
    // 다른 나라에서는 "┐"이런 문자일 수도 있다.

    //그래서 3~4Byte 문자형이 나왔는데 그것이 UTF인코딩 시리즈
    // 프로그래밍은 국가 코드를 따릅니다.

    // 국가코드에 

    char Arr[6] = "abcde";
    char Arr1[7] = "가나다";

    // std::string은 vector의 자료구조 이다.
    // 
    {
        std::string a = "abc가나다123";
        std::wstring a1 = L"abc가나다123";
        std::cout << a.size() << " " << a1.size();
    }

    

    {
        // 국가코드를 변경해주는 함수를 사용해야 출력이 가능하다.
        setlocale(LC_ALL, "KOR");

        std::wstring Text0 = L"안녕하세요";
        std::wstring Text1 = L"반갑습니다";
        std::wstring Result = Text0 + Text1;

    }

    
}

