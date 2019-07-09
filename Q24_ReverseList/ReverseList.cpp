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
    ListNode* ReverseList(ListNode* pHead)
    {
        if (pHead == nullptr)
            return nullptr;
        ListNode* pPrevNode = nullptr;
        ListNode* pCurrentNode = pHead;
        while (pCurrentNode != nullptr)
        {
            ListNode* pNextNode = pCurrentNode->pNext;
            pCurrentNode->pNext = pPrevNode;
            pPrevNode = pCurrentNode;
            pCurrentNode = pNextNode;
        }

        return pPrevNode;
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
    ListNode* reverseList = solution.ReverseList(pHead);
    printList(reverseList);
}

void test1()
{
    cout << "test1 is running......" << endl;
    int numbers[] = { 1, 2, 3, 4, 5, 6 };
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
    test(pHead);
}

void test2()
{
    cout << "test2 is running......" << endl;
    int numbers[] = { 1};
    int length = sizeof(numbers) / sizeof(int);
    ListNode* pHead = new ListNode(numbers[0]);
    test(pHead);
}

void test3()
{
    cout << "test3 is running......" << endl;
    ListNode* pHead = nullptr;
    test(pHead);
}

int main(int argc, char** argv)
{
    test1();
    test2();
    test3();

    getchar();
    return 0;
}