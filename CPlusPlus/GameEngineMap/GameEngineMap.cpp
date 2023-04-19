
#include <iostream>
#include <map>

template<typename DataType0, typename DataType1>
void TestValue(DataType0 _Data0, DataType1 _Data1)
{

}

void TestValue(int _Data0, int _Data1)
{

}

int main()
{
    TestValue<int, int>(10, 10);
    std::map<int, int> NewMap;

}

