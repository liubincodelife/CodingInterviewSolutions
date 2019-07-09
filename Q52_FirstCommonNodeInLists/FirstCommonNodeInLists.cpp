#include <iostream>

using namespace std;

struct ListNode
{
    int nValue;
    ListNode* pNext;
    ListNode(int x = 0) :nValue(x), pNext(nullptr) {}
};

class Solution
{
public:
    bool isIntersection(ListNode* pHead1, ListNode* pHead2)
    {
        if (pHead1 == nullptr || pHead2 == nullptr)
            return false;
        ListNode* pNode1 = pHead1;
        ListNode* pNode2 = pHead2;
        bool isIntersection = false;
        while (pNode1->pNext != nullptr)
        {
            pNode1 = pNode1->pNext;
        }

        while (pNode2->pNext != nullptr)
        {
            pNode2 = pNode2->pNext;
        }

        if (pNode1 == pNode2)
            isIntersection = true;
        return isIntersection;
    }

    ListNode* firstCommonNode(ListNode* pHead1, ListNode* pHead2)
    {
        if (isIntersection(pHead1, pHead2))
        {
            ListNode* pNode1 = pHead1;
            ListNode* pNode2 = pHead2;
            while (pNode1 != pNode2)
            {
                pNode1 = (pNode1 == nullptr) ? pHead2 : pNode1->pNext;
                pNode2 = (pNode2 == nullptr) ? pHead1 : pNode2->pNext;
            }
            return pNode1;
        }

        return nullptr;
    }
protected:
private:
};

void test(ListNode* pHead1, ListNode* pHead2)
{
    Solution solution;
    ListNode* pNode = solution.firstCommonNode(pHead1, pHead2);
    cout << "the first common node is: " << pNode->nValue << endl;
}

void test1()
{
    ListNode* pHead1 = new ListNode(1);
    ListNode* pHead2 = new ListNode(4);
    ListNode* pNode3 = new ListNode(2);
    ListNode* pNode4 = new ListNode(3);
    ListNode* pNode5 = new ListNode(5);
    ListNode* pNode6 = new ListNode(6);
    ListNode* pNode7 = new ListNode(7);

    pHead1->pNext = pNode3;
    pNode3->pNext = pNode4;
    pNode4->pNext = pNode6;
    pNode6->pNext = pNode7;

    pHead2->pNext = pNode5;
    pNode5->pNext = pNode6;

    test(pHead1, pHead2);
}

int main(int argc, char** argv)
{
    test1();
    getchar();
    return 0;
}