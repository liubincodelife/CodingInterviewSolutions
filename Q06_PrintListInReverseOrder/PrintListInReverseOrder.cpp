#include<iostream>
#include <stack>

using namespace std;

struct ListNode 
{
	int m_nValue;
	ListNode* m_pNext;
};

void addDataToTail(ListNode** pHead, int value)
{
	ListNode* pNew = new ListNode();
	pNew->m_nValue = value;
	pNew->m_pNext = nullptr;

	if (*pHead == nullptr)
	{
		*pHead = pNew;
	}
	else
	{
		ListNode* pNode = *pHead;
		while (pNode->m_pNext != nullptr)
		{
			pNode = pNode->m_pNext;
		}
		pNode->m_pNext = pNew;
	}
}

void removeNode(ListNode** pHead, int value)
{
	if (pHead == nullptr || *pHead == nullptr)
	{
		return;
	}

	ListNode* pToBeDelete = nullptr;
	if ((*pHead)->m_nValue == value)
	{
		pToBeDelete = *pHead;
		*pHead = (*pHead)->m_pNext;
	}
	else
	{
		ListNode* pNode = *pHead;
		while (pNode->m_pNext != nullptr && pNode->m_pNext->m_nValue != value)
		{
			pNode = pNode->m_pNext;
		}
		
		if (pNode->m_pNext != nullptr && pNode->m_pNext->m_nValue == value)
		{
			pToBeDelete = pNode->m_pNext;
			pNode->m_pNext = pNode->m_pNext->m_pNext;
		}
	}

	if (pToBeDelete != nullptr)
	{
		delete pToBeDelete;
		pToBeDelete = nullptr;
	}
}

void releaseList(ListNode* pHead)
{
	ListNode* pNode = pHead;
	while (pNode != nullptr)
	{
		pHead = pHead->m_pNext;
		delete pNode;
		pNode = pHead;
	}
}

void printList(ListNode* pHead)
{
	cout << endl << "link list in order:"<< endl;
	ListNode* pNode = pHead;
	while (pNode != nullptr)
	{
		cout << pNode->m_nValue;
		pNode = pNode->m_pNext;
		if (pNode != nullptr)
		{
			cout << " -> ";
		}
		else
		{
			cout << " -> null" << endl;
		}
	}
}

ListNode* createSingleList(int number[], int length)
{
	ListNode* pNode = nullptr;
	for (int i = 0; i < length; i++)
	{
		addDataToTail(&pNode, number[i]);
	}
	
	return pNode;
}

class Solutoin
{
public:
	void printListInReverseOrder_Recursive(ListNode* pHead)
	{
		if (pHead != nullptr)
		{
			if (pHead->m_pNext != nullptr)
			{
				printListInReverseOrder_Recursive(pHead->m_pNext);
			}
			cout << pHead->m_nValue;
			cout << " -> ";
		}
	}

	void printListInReverseOrder_Iterative(ListNode* pHead)
	{
		stack<ListNode*> nodeStack;
		ListNode* pNode = pHead;
		while (pNode != nullptr)
		{
			nodeStack.push(pNode);
			pNode = pNode->m_pNext;
		}

		while (!nodeStack.empty())
		{
			pNode = nodeStack.top();
			cout << pNode->m_nValue;
			cout << " -> ";
			nodeStack.pop();
		}
		cout << endl;
	}
protected:
private:
};

void test(ListNode* pHead)
{
	Solutoin solution;
	cout << "list in reverse order using recursive: " << endl;
	solution.printListInReverseOrder_Recursive(pHead);
	cout << endl << "list in reverse order using iterative: " << endl;
	solution.printListInReverseOrder_Iterative(pHead);
}

void test1()
{
	int numbers[] = { 1, 2, 3, 4, 5, 6 };
	int length = sizeof(numbers) / sizeof(int);
	ListNode* pHead = createSingleList(numbers, length);
	printList(pHead);
	test(pHead);
}

//只有一个结点的链表
void test2()
{
	int numbers[] = { 1};
	int length = sizeof(numbers) / sizeof(int);
	ListNode* pHead = createSingleList(numbers, length);
	printList(pHead);
	test(pHead);
}

//空链表
void test3()
{
	test(nullptr);
}

int main(int argc, char** argv)
{
	test1();
	test2();
	test3();
	while (1)
	{
	}
	return 0;
}