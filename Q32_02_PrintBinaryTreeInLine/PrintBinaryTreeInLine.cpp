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
    void printBinaryTreeInLine(BinaryTreeNode* pRoot)
    {
        if (pRoot == nullptr)
            return;
        queue<BinaryTreeNode*> queueBinaryTree;
        queueBinaryTree.push(pRoot);
        int toBePrint = 1;
        int nextLevel = 0;
        while (queueBinaryTree.size())
        {
            BinaryTreeNode* pNode = queueBinaryTree.front();
            queueBinaryTree.pop();
            if (pNode->pLeft != nullptr)
            {
                queueBinaryTree.push(pNode->pLeft);
                nextLevel++;
            }
            if (pNode->pRight != nullptr)
            {
                queueBinaryTree.push(pNode->pRight);
                nextLevel++;
            }
            cout << pNode->nValue << " ";
            --toBePrint;
            if (toBePrint == 0)
            {
                cout << endl;
                toBePrint = nextLevel;  //当前层打印完了，开始打印下一层
                nextLevel = 0;   //下一层打印数目清0
            }
                
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
    solution.printBinaryTreeInLine(pRoot);
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