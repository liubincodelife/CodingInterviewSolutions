#include <iostream>
#include <queue>

using namespace std;

struct BinaryTreeNode
{
    int nValue;
    BinaryTreeNode* pLeft;
    BinaryTreeNode* pRight;
    BinaryTreeNode(int x = 0) : nValue(x), pLeft(nullptr), pRight(nullptr) {}
};

class Solution
{
public:
    void printBinaryTreeFromUpToDown(BinaryTreeNode* pRoot)
    {
        if (pRoot == nullptr)
            return;
        queue<BinaryTreeNode*> queueBinaryTree;
        queueBinaryTree.push(pRoot);
        while (queueBinaryTree.size())
        {
            BinaryTreeNode* pNode = queueBinaryTree.front();
            queueBinaryTree.pop();
            cout << pNode->nValue << " ";
            if (pNode->pLeft != nullptr)
                queueBinaryTree.push(pNode->pLeft);
            if (pNode->pRight != nullptr)
                queueBinaryTree.push(pNode->pRight);
        }
    }
protected:
private:
};

void ConnectBinaryTreeNode(BinaryTreeNode* pRoot1, BinaryTreeNode* pLeft, BinaryTreeNode* pRight)
{
    if (pRoot1 != nullptr)
    {
        pRoot1->pLeft = pLeft;
        pRoot1->pRight = pRight;
    }
}

void test(BinaryTreeNode* pRoot)
{
    Solution solution;
    solution.printBinaryTreeFromUpToDown(pRoot);
}

void test1()
{
    BinaryTreeNode* pRoot = new BinaryTreeNode(8);
    BinaryTreeNode* pTreeNode1 = new BinaryTreeNode(6);
    BinaryTreeNode* pTreeNode2 = new BinaryTreeNode(10);
    BinaryTreeNode* pTreeNode3 = new BinaryTreeNode(5);
    BinaryTreeNode* pTreeNode4 = new BinaryTreeNode(7);
    BinaryTreeNode* pTreeNode5 = new BinaryTreeNode(9);
    BinaryTreeNode* pTreeNode6 = new BinaryTreeNode(11);

    ConnectBinaryTreeNode(pRoot, pTreeNode1, pTreeNode2);
    ConnectBinaryTreeNode(pTreeNode1, pTreeNode3, pTreeNode4);
    ConnectBinaryTreeNode(pTreeNode2, pTreeNode5, pTreeNode6);
    test(pRoot);
}

int main(int argc, char** argv)
{
    test1();
    getchar();
    return 0;
}