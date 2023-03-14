﻿
#include <iostream>

int main()
{
    int Left = 0b00000000000000000000000000000010;
    int Right = 0b00000000000000000000000000000001;
    int Result = 0b00000000000000000000000000000000;


    // 비트단위 연산자.
    // NOT : 비트를 전부 반전시킴
    Result = ~0; // 1
    // AND : 둘 다 1이여야 참
    Result = Left & Right; // 00000000000000000000000000000000 = 0
    // OR : 둘 중 하나만 1이면 참
    Result = Left | Right; // 00000000000000000000000000000011 = 3
    // XOR : 같으면 거짓이고 서로 다르면 참
    Result = Left ^ Right; // 00000000000000000000000000000011 = 3


    // true와 false 참과 거짓
    // 특정 메모리 영역의 비트가 전부 '0'이라면 false
    // 특정 메모리 영역의 비트 중 다 1개라도 '1'이 있다면 true
    bool bResult = 0; // false
    bResult = 1; // true
    bResult = 2; // true


    // Shift 연산자
    // ex) 0001 -> 1000 
    bResult = 1 << 3; // 1을 bit로 나타냈을 때 피연산자만큼 왼쪽으로 밀어버린다.
    bResult = 1 >> 3; // 1을 bit로 나타냈을 때 피연산자만큼 오른쪽으로 밀어버린다.

    // 이 Shift 연산자는 위험요소가 크다. 
    // ex) bResult = 1 << 4 연산은 아래와 같다.
    // 0001 -> 0000 (??)
    // 이 연산은 컴퓨터 자원마다 상태가 다르기 때문에 bit가 넘어가지 않게 쓰거나, 차라리 쓰지 않는것이 좋다.


    // 축약 연산자
    Left = Left + Right;
    // 위 연산은 아래 연산과 같다. 
    Left += Right;
    Left -= Right; // etc.. 이전에 배운 연산자가 거의 다 축약이 가능하다.





}