
#include <iostream>
#include <vector>
class MyVector
{

};

int main()
{
    std::vector<int> Test;

    // push_back은 좋지않다.
    // resize로 재할당을 하기 때문이다.
    // 
    Test.push_back(10);
    Test.push_back(10);
    Test.push_back(10);
    Test.pop_back();
    Test.size();
    // 원소 자체되 넣어주는걸 resize라고 한다.

    Test.resize(10); // 원소 개수 설정
    Test.reserve(20); // padding 크기 설정

    //언리얼은 벡터 안쓰고 자체 자료구조 사용함
    // 만약 자료구조를 따로 관리하면 보통 랩핑하면서 사용한다
    // 
    // 랩핑의 예)
    //class PArr
    //{
    //    std::vector<int> a;
    //};
    
}
