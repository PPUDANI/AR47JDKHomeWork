﻿
// 컴파일이란 .exe 파일을 만드는 것이다.
// 컴파일 과정은 아래와 같다

// 전처리기 -> 컴파일러 > 어셈블러 -> 링커 -> .exe파일 제작

// 전처리기란 말 그대로 컴파일 전에 처리해야 할 것을 처리하는 역할을 한다.
// 주석을 제거하고 참조하는 헤더파일의 실제 코드를 불러온다.('#'이 붙으면 웬만하면 전처리문이다.)

// 파일의 개념은 확장자라는 개념이 없이 만들어진 개념이다.
// 파일 확장자(.txt, .wav, .jpeg 등등)가 존재하는 이유는 운영체제가 확장명을 보고 적합한 확장 프로그램으로 연결시켜주기 위함이다.

// 'C' 에서는 전처리문인 참조 선언문을 작성할 때 파일에 '.h' 같은 파일 확장명을 붙인다. (예 : #include <stdio.h>)
// 하지만 'C'이후 개발된 'C++'에서는 편의성을 부여하여 확장명을 안붙여도 되도록 만들었다.

// 아래 코드는 전처리기에서 실행되는 코드로 "iostream.h" 파일의 코드를 불러온다는 의미의 전처리문이다.
// 해당 코드파일을 보고싶다면 해당 전처리문에 커서를 두고 'Ctrl' + 'Shift'와 G를 누르면 해당 파일을 열 수 있다.
#include <iostream>

// .exe 파일은 프로그램이라고 하며 보조 기억장치에 적재된다(HDD, SSD)
// 이 파일은 실행되기를 기다리는 명령어(코드)와 정적인 데이터의 묶음이다.
// 프로그램을 더블클릭하면 'RAM'으로 올라가는데 'RAM'으로 올라가면서 프로그램인 .exe 파일은 프로세스의 개념이 된다.
// RAM에 올라간 프로세스들은 'CPU'에게 전달된다. (CPU: 프로세서)
// CPU는 프로세스를 받아서 처리하고 값을 RAM으로 반환해준다.

// 가시화된 과정은 아래와 같다.
//   1. .exe 파일을 실행하면 RAM에 올라간다.
//   2. RAM에서 .exe 파일이 프로세스가 되며 해당 프로세스들이 CPU로 전달된다.
//   3. CPU에서 처리된 데이터값을 RAM에 반환해준다.

int main()
{
    std::cout << "Hello World!\n";
}