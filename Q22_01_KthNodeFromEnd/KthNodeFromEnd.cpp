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
    ListNode* FindKthNodeFromEnd(ListNode* pHead, unsigned int k)
    {
        if (pHead == nullptr || k == 0)
            return nullptr;
        ListNode* pAheadNode = pHead;
        ListNode* pBehindNode = nullptr;

        for (int i = 0; i < k-1; ++i)
        {
            //判断链表中节点个数是否大于k
            if (pAheadNode->pNext != nullptr)
            {
                pAheadNode = pAheadNode->pNext;
            }
            else
            {
                return nullptr;
            }
        }

        pBehindNode = pHead;
        while (pAheadNode->pNext != nullptr)
        {
            pAheadNode = pAheadNode->pNext;
            pBehindNode = pBehindNode->pNext;
        }

        return pBehindNode;
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

void test(ListNode* pHead, unsigned int k)
{
    printList(pHead);
    Solution solution;
    ListNode* pNode = solution.FindKthNodeFromEnd(pHead, k);
    if (pNode != nullptr)
    {
        cout << "kth node is: " << pNode->nValue << endl;
    }
    else
    {
        cout << "kth node is null " << endl;
    }
    
}
//倒数kth节点为中间节点
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
    test(pHead, 3);
}

//倒数kth节点为头节点
void test2()
{
    cout << "test2 is running......" << endl;
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
    test(pHead, 6);
}

//倒数kth节点为尾节点
void test3()
{
    cout << "test3 is running......" << endl;
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
    test(pHead, 1);
}

//输入链表为空
void test4()
{
    cout << "test4 is running......" << endl;
    ListNode* pHead = nullptr;
    test(pHead, 1);
}

//k大于链表节点总数
void test5()
{
    cout << "test5 is running......" << endl;
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
    test(pHead, 10);
}

//k为0
void test6()
{
    cout << "test6 is running......" << endl;
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
    test(pHead, 0);
}

int main(int argc, char** argv)
{
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();

    getchar();
    return 0;
}