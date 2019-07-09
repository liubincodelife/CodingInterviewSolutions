#include <iostream>

using namespace std;

struct ListNode
{
    int nValue;
    ListNode* pNext;
    ListNode(int x) : nValue(x), pNext(nullptr) {}
};

class Solution
{
public:
    ListNode* MeetNode(ListNode* pHead)
    {
        if (pHead == nullptr)
            return nullptr;
        
        ListNode* pSlowNode = pHead->pNext;
        if (pSlowNode == nullptr)
            return nullptr;
        ListNode* pFastNode = pSlowNode->pNext;  //pFastNode��pSlowNode����һ��
        while (pFastNode != nullptr && pSlowNode != nullptr)
        {
            if (pSlowNode == pFastNode)
                return pFastNode;
            pSlowNode = pSlowNode->pNext;
            pFastNode = pFastNode->pNext;
            if (pFastNode != nullptr)
                pFastNode = pFastNode->pNext;
        }
        return nullptr;
    }

    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        //1.��ȷ�������Ƿ��л��������������ڵ�
        ListNode* pMeetNode = MeetNode(pHead);
        if (pMeetNode == nullptr)
            return nullptr;
        //2.�õ����еĽڵ���Ŀn
        int nodesCountInLoop = 1;
        ListNode* pNode1 = pMeetNode;
        while (pNode1->pNext != pMeetNode)
        {
            ++nodesCountInLoop;
            pNode1 = pNode1->pNext;
        }

        //3.����ָ���ƶ�n��
        pNode1 = pHead;
        for (int i = 0; i < nodesCountInLoop; ++i)
        {
            pNode1 = pNode1->pNext;
        }

        //4.һ���ƶ�����ָ�룬����ʱ��Ϊ������ڽڵ�
        ListNode* pNode2 = pHead;
        while (pNode1 != pNode2)
        {
            pNode1 = pNode1->pNext;
            pNode2 = pNode2->pNext;
        }
        return pNode1;
    }
protected:
private:
};

void printList(ListNode* pHead)
{
    ListNode* pNode = pHead;
    while (pNode != nullptr)
    {
        cout << pNode->nValue;
        pNode = pNode->pNext;
        if (pNode != nullptr)
            cout << " -> ";
        else
            cout << " -> null" << endl;
    }
}

void test(ListNode* pHead, ListNode* pEntryNode)
{
    Solution solution;
    ListNode* pNode = solution.EntryNodeOfLoop(pHead);
    if (pNode == pEntryNode)
    {
        cout << "Passed......" << endl;
    } 
    else
    {
        cout << "Failed!!!" << endl;
    }
}

void test1()
{
    cout << "test1 is running......" << endl;
    int numbers[] = { 1, 2, 3, 4, 5};
    int length = sizeof(numbers) / sizeof(int);
    ListNode* pHead = new ListNode(numbers[0]);
    ListNode* pNode1 = new ListNode(numbers[1]);
    ListNode* pNode2 = new ListNode(numbers[2]);
    ListNode* pNode3 = new ListNode(numbers[3]);
    ListNode* pNode4 = new ListNode(numbers[4]);
    pHead->pNext = pNode1;
    pNode1->pNext = pNode2;
    pNode2->pNext = pNode3;
    pNode3->pNext = pNode4;
    pNode4->pNext = pNode2;
    test(pHead, pNode2);
}

//ֻ��һ���ڵ㣬û�л�
void test2()
{
    cout << "test2 is running......" << endl;
    int numbers[] = { 1 };
    int length = sizeof(numbers) / sizeof(int);
    ListNode* pHead = new ListNode(numbers[0]);

    test(pHead, nullptr);
}

//ֻ��һ���ڵ㣬�л�
void test3()
{
    cout << "test3 is running......" << endl;
    int numbers[] = { 1 };
    int length = sizeof(numbers) / sizeof(int);
    ListNode* pHead = new ListNode(numbers[0]);
    pHead->pNext = pHead;

    test(pHead, pHead);
}

//����Ϊ��
void test4()
{
    cout << "test4 is running......" << endl;
    ListNode* pHead = nullptr;

    test(pHead, nullptr);
}

int main(int argc, char** argv)
{
    test1();
    test2();
    test3();
    test4();

    getchar();
    return 0;
}