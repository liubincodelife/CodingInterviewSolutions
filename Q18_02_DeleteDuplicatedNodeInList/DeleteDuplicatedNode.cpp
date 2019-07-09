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
    void DeleteDuplicatedNode(ListNode** pHead)
    {
        if (pHead == nullptr || *pHead == nullptr)
            return;
        ListNode* pNode = *pHead;
        ListNode* pPrevNode = nullptr;
        while (pNode != nullptr)
        {
            ListNode* pNextNode = pNode->pNext;
            bool isNeedDelete = false;
            if (pNextNode != nullptr && pNextNode->nValue == pNode->nValue)
            {
                isNeedDelete = true;
            }

            if (!isNeedDelete)
            {
                pPrevNode = pNode;
                pNode = pNode->pNext;
            } 
            else
            {
                //pNode为要删除的节点，现在判断pNode之后的节点是否需要删除
                int value = pNode->nValue;
                ListNode* pDeleteNode = pNode;
                while (pDeleteNode != nullptr && pDeleteNode->nValue == value)
                {
                    pNextNode = pDeleteNode->pNext;
                    delete pDeleteNode;
                    pDeleteNode = nullptr;
                    pDeleteNode = pNextNode;
                }

                if (pPrevNode == nullptr)
                    *pHead = pNextNode;
                else
                    pPrevNode->pNext = pNextNode;
                pNode = pNextNode;
            }
        }
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

void test(ListNode* pHead)
{
    printList(pHead);
    Solution solution;
    solution.DeleteDuplicatedNode(&pHead);
    printList(pHead);
}

void test1()
{
    int numbers[] = { 1, 2, 3, 3, 4, 4, 5};
    int length = sizeof(numbers) / sizeof(int);
    ListNode* pHead = new ListNode(numbers[0]);
    ListNode* pNode1 = new ListNode(numbers[1]);
    ListNode* pNode2 = new ListNode(numbers[2]);
    ListNode* pNode3 = new ListNode(numbers[3]);
    ListNode* pNode4 = new ListNode(numbers[4]);
    ListNode* pNode5 = new ListNode(numbers[5]);
    ListNode* pNode6 = new ListNode(numbers[6]);
    pHead->pNext = pNode1;
    pNode1->pNext = pNode2;
    pNode2->pNext = pNode3;
    pNode3->pNext = pNode4;
    pNode4->pNext = pNode5;
    pNode5->pNext = pNode6;
    test(pHead);
}

void test2()
{
    int numbers[] = { 1, 1, 2, 3, 4, 5, 5 };
    int length = sizeof(numbers) / sizeof(int);
    ListNode* pHead = new ListNode(numbers[0]);
    ListNode* pNode1 = new ListNode(numbers[1]);
    ListNode* pNode2 = new ListNode(numbers[2]);
    ListNode* pNode3 = new ListNode(numbers[3]);
    ListNode* pNode4 = new ListNode(numbers[4]);
    ListNode* pNode5 = new ListNode(numbers[5]);
    ListNode* pNode6 = new ListNode(numbers[6]);
    pHead->pNext = pNode1;
    pNode1->pNext = pNode2;
    pNode2->pNext = pNode3;
    pNode3->pNext = pNode4;
    pNode4->pNext = pNode5;
    pNode5->pNext = pNode6;
    test(pHead);
}

int main(int argc, char** argv)
{
    test1();
    test2();
    getchar();
    return 0;
}