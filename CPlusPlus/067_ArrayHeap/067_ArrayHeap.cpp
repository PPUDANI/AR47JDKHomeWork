

#include <iostream>

int main()
{
    {
        // 정적 바인딩
        int Arr[10];
        int* Ptr = Arr;
        Ptr[0];
    }

    {
        // 동적 바인딩

        // new를 사용해서 배열을 만들 수도 있다.
        int* Ptr = new int[100];

        // delete로 지울수도 있지만 상황에 따라서 배열할당은 delete로는 삭제가 안될 때가 있다.
        // delete Ptr;
        
        // 배열은 아래와 같이 지워야 한다.
        delete[] Ptr;
        Ptr = nullptr;
        

    }
}

