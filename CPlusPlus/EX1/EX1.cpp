
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector <int> vec= {1, 2, 3};

    vec.push_back(4);
    vec.push_back(5);
    vec.pop_back();

    for ( auto i : vec)
    {
        cout << i << endl;
    }


}