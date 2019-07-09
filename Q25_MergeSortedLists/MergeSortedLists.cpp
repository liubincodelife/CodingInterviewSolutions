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
    ListNode* MergeLists(ListNode* pHead1, ListNode* pHead2)
    {
        if (pHead1 == nullptr)
        {
            return pHead2;
        }

        if (pHead2 == nullptr)
        {
            return pHead1;
        }

        ListNode* pMergeHead = nullptr;
        if (pHead1->nValue < pHead2->nValue)
        {
            pMergeHead = pHead1;
            pMergeHead->pNext = MergeLists(pHead1->pNext, pHead2);
        } 
        else
        {
            pMergeHead = pHead2;
            pMergeHead->pNext = MergeLists(pHead1, pHead2->pNext);
        }

        return pMergeHead;
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

void test(ListNode* pHead1, ListNode* pHead2)
{
    printList(pHead1);
    printList(pHead2);
    Solution solution;
    ListNode* mergeList = solution.MergeLists(pHead1, pHead2);
    printList(mergeList);
}

void test1()
{
    cout << "test1 is running......" << endl;
    int numbers1[] = { 1, 3, 5 };
    int numbers2[] = { 2, 4, 6 };

    ListNode* pHead1 = new ListNode(numbers1[0]);
    ListNode* pNode1 = new ListNode(numbers1[1]);
    ListNode* pNode2 = new ListNode(numbers1[2]);
    pHead1->pNext = pNode1;
    pNode1->pNext = pNode2;

    ListNode* pHead2 = new ListNode(numbers2[0]);
    ListNode* pNode3 = new ListNode(numbers2[1]);
    ListNode* pNode4 = new ListNode(numbers2[2]);
    pHead2->pNext = pNode3;
    pNode3->pNext = pNode4;

    test(pHead1, pHead2);
}

//两个链表有重复元素
void test2()
{
    cout << "test2 is running......" << endl;
    int numbers1[] = { 1, 3, 5 };
    int numbers2[] = { 1, 3, 5 };

    ListNode* pHead1 = new ListNode(numbers1[0]);
    ListNode* pNode1 = new ListNode(numbers1[1]);
    ListNode* pNode2 = new ListNode(numbers1[2]);
    pHead1->pNext = pNode1;
    pNode1->pNext = pNode2;

    ListNode* pHead2 = new ListNode(numbers2[0]);
    ListNode* pNode3 = new ListNode(numbers2[1]);
    ListNode* pNode4 = new ListNode(numbers2[2]);
    pHead2->pNext = pNode3;
    pNode3->pNext = pNode4;

    test(pHead1, pHead2);
}

//两个链表均只有一个元素
void test3()
{
    cout << "test3 is running......" << endl;
    int numbers1[] = { 1 };
    int numbers2[] = { 2 };

    ListNode* pHead1 = new ListNode(numbers1[0]);

    ListNode* pHead2 = new ListNode(numbers2[0]);

    test(pHead1, pHead2);
}

//两个链表有一个为空
void test4()
{
    cout << "test4 is running......" << endl;
    int numbers1[] = { 1, 3, 5 };

    ListNode* pHead1 = new ListNode(numbers1[0]);
    ListNode* pNode1 = new ListNode(numbers1[1]);
    ListNode* pNode2 = new ListNode(numbers1[2]);
    pHead1->pNext = pNode1;
    pNode1->pNext = pNode2;

    ListNode* pHead2 = nullptr;

    test(pHead1, pHead2);
}

//两个链表都为空
void test5()
{
    cout << "test5 is running......" << endl;
    ListNode* pHead1 = nullptr;
    ListNode* pHead2 = nullptr;

    test(pHead1, pHead2);
}

int main(int argc, char** argv)
{
    test1();
    test2();
    test3();
    test4();
    test5();
    getchar();
    return 0;
}