
#include <iostream>
#include <list>
#include <crtdbg.h>
// vector는 상황에 따라 너무나도 커질 수 있는재할당과 복사연산의 위험성 문제점이 있다.

// 그 단점을 보완한 것이 list이다.
// 대신 list는 대부분의 연산에서 느리다.
// list의 장점은 편의성이다.

// 메모리는 연속되어 있을 때 가장 빠르다.
// 컴퓨터 친화적 코딩이라고 한다.
// 할 수 있다면 최대한 벡터로 짜는게 좋다.

typedef int DataType;

class GameEngineList
{
private:
    class ListNode
    {
    public:
        ListNode* Prev = nullptr;
        ListNode* Next = nullptr;
        DataType Value;

    public:
        ~ListNode()
        {
            if (nullptr != Next)
            {
                delete Next;
                Next = nullptr;
            }
        }
    };

public:
    class iterator
    {
        friend GameEngineList;

    public:
        iterator()
        {

        }

        iterator(ListNode* _CurNode)
            : CurNode(_CurNode)
        {

        }

        bool operator !=(const iterator& _Other)
        {
            return CurNode != _Other.CurNode;
        }

        iterator& operator ++()
        {
            CurNode = CurNode->Next;

            return *this;
        }

        DataType& operator*()
        {
            return CurNode->Value;
        }

    private:
        ListNode* CurNode = nullptr;
    };

    GameEngineList()
    {
        StartNode->Next = EndNode;
        EndNode->Prev = StartNode;
    }

    ~GameEngineList()
    {
        if (nullptr != StartNode)
        {
            delete StartNode;
            StartNode = nullptr;
        }
    }

    iterator begin()
    {
        return iterator(StartNode->Next);
    }

    iterator end()
    {
        return iterator(EndNode);
    }

    iterator erase(iterator& _DeleteNode)
    {
        ListNode* DeleteNode = _DeleteNode.CurNode;

        ListNode* PrevNode = DeleteNode->Prev;
        ListNode* NextNode = DeleteNode->Next;

        DeleteNode->Prev = nullptr;
        DeleteNode->Next = nullptr;

        if (nullptr != DeleteNode)
        {
            delete DeleteNode;
            DeleteNode = nullptr;
        }

        PrevNode->Next = NextNode;
        NextNode->Prev = PrevNode;

        return iterator(NextNode);

        // 절대로 Node존재를 외부에 공개하고 싶지 않아.
        // _DeleteNode
    }

    void push_back(const DataType& _Data)
    {
        ListNode* NewListNode = new ListNode();
        NewListNode->Value = _Data;

        ListNode* PrevNode = EndNode->Prev;

        // 연결을 끊고.
        //PrevNode->Next = nullptr;
        //EndNode->Prev = nullptr;

        PrevNode->Next = NewListNode;
        EndNode->Prev = NewListNode;
        NewListNode->Next = EndNode;
        NewListNode->Prev = PrevNode;
    }

    void push_front(const DataType& _Data)
    {
        ListNode* NewListNode = new ListNode();
        NewListNode->Value = _Data;

        ListNode* NextNode = StartNode->Next;

        NewListNode->Next = NextNode;
        NextNode->Prev = NewListNode;

        StartNode->Next = NewListNode;
        NewListNode->Prev = StartNode;
    }

private:


    // 더미노트
    ListNode* StartNode = new ListNode();
    ListNode* EndNode = new ListNode();


};

int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    {

        GameEngineList NewList;
        

        NewList.push_back(999);
        NewList.push_back(888);
        NewList.push_back(777);
        NewList.push_back(123156456);
        NewList.push_front(10);

        GameEngineList::iterator Start = NewList.begin();
        GameEngineList::iterator End = NewList.end();

        for (; Start != End; ++Start)
        {
            printf_s("%d\n", *Start);
        }
        return 0;
    }
    
    {

        GameEngineList NewList;

        NewList.push_back(999);
        NewList.push_back(888);
        NewList.push_back(777);
        NewList.push_back(123156456);

        {
            //                    999
            GameEngineList::iterator Delete = NewList.begin();
            ++Delete; // 888

            NewList.erase(Delete);

        }


        //// Node들을 기억해보면
        //// Node형태의 자료들을 순회를 돌려면
        //// 그중 한 지점의 노드의 주소를 알아야만 돌수 있다.
        //// 그걸 Node를 직접 외부에 공개하지 않습니다.

        GameEngineList::iterator Start = NewList.begin();
        GameEngineList::iterator End = NewList.end();

        // NewList[1]

        for (; Start != End; ++Start)
        {
            printf_s("%d\n", *Start);
        }

    }

    return 1;

    {
        std::list<int> NewList;

        NewList.push_back(999);
        NewList.push_back(888);
        NewList.push_back(777);
        NewList.push_back(123156456);
        NewList.push_front(2000);

        {
            //                    999
            std::list<int>::iterator Delete = NewList.begin();
            ++Delete; // 888

            NewList.erase(Delete);

        }


        // Node들을 기억해보면
        // Node형태의 자료들을 순회를 돌려면
        // 그중 한 지점의 노드의 주소를 알아야만 돌수 있다.
        // 그걸 Node를 직접 외부에 공개하지 않습니다.

        std::list<int>::iterator Start = NewList.begin();
        std::list<int>::iterator End = NewList.end();

        // NewList[1]

        for (; Start != End; ++Start)
        {
            printf_s("%d\n", *Start);
        }

    }



}
