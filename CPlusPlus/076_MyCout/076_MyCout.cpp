
#include <iostream>

class MyEndl
{

};
class MyCout
{
public:
    void operator<<(const MyEndl& Value)
    {
        printf_s("\n");
    }

    void operator<<(const char* _Text)
    {
        printf_s(_Text);
    }

};

MyCout MCout;
MyEndl MEndl;

namespace std
{
    MyCout MCout;
    MyEndl MEndl;
}

int main()
{
    
    MCout << "Hello world" << MEndl;
    MCout.operator<<("Hello world") << MEndl;
}
