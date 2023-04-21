
#include <iostream>
#include <map>

typedef int KeyType;
typedef int ValueType;
class GameEnginePair
{

    KeyType first;
    ValueType second;
};
class GameEngineMap
{
public:
    class MapNode
    {
    public:
        MapNode* LeftChild = nullptr;
        MapNode* RightChild = nullptr;
    };

};
template<typename DataType0, typename DataType1>
void TestValue(DataType0 _Data0, DataType1 _Data1)
{

}

void TestValue(int _Data0, int _Data1)
{

}

int main()
{

    {
        TestValue<int, int>(10, 10);
        std::map<int, int> NewMap;
    }
    {
        std::map<int, int> Test;
        Test.insert(std::pair<int, int>(5, 1));
        Test.insert(std::pair<int, int>(2, 1));
        Test.insert(std::pair<int, int>(3, 1));
        Test.insert(std::pair<int, int>(7, 1));
        Test.insert(std::pair<int, int>(15, 1));
        Test.find(15);
    }
    

}

