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
    void DeleteNode(ListNode** pListHead, ListNode* pToBeDeleted)
    {
        if (!pListHead || !pToBeDeleted)
            return;
        if (pToBeDeleted->pNext != nullptr)
        {
            ListNode* pNextNode = pToBeDeleted->pNext;
            pToBeDeleted->nValue = pNextNode->nValue;
            pToBeDeleted->pNext = pNextNode->pNext;

            delete pNextNode;  //此处注意是将pToBeDeleted的下一个节点删除
            pNextNode = nullptr;
        } 
        else if(*pListHead == pToBeDeleted)
        {
            delete pToBeDeleted;
            pToBeDeleted = nullptr;
            *pListHead = nullptr;
        }
        else
        {
            ListNode* pNode = *pListHead;
            while (pNode->pNext != pToBeDeleted)
            {
                pNode = pNode->pNext;
            }

            pNode->pNext = nullptr;
            delete pToBeDeleted;
            pToBeDeleted = nullptr;
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

void test(ListNode* pHead, ListNode* pDeleteNode)
{
    printList(pHead);
    Solution solution;
    solution.DeleteNode(&pHead, pDeleteNode);
    printList(pHead);
}

void test1()
{
    int numbers[] = { 1, 2, 3, 4, 5, 6};
    int length = sizeof(numbers) / sizeof(int);
    ListNode* pHead = new ListNode(numbers[0]);
    ListNode* pNode1 = new ListNode(numbers[1]);
    ListNode* pNode2 = new ListNode(numbers[2]);
    ListNode* pNode3 = new ListNode(numbers[3]);
    ListNode* pNode4 = new ListNode(numbers[4]);
    ListNode* pNode5 = new ListNode(numbers[5]);
    pHead->pNext = pNode1;
    pNode1->pNext = pNode2;
    pNode2->pNext = pNode3;
    pNode3->pNext = pNode4;
    pNode4->pNext = pNode5;
    test(pHead, pNode3);
}

int main(int argc, char** argv)
{
    test1();
    getchar();
    return 0;
}