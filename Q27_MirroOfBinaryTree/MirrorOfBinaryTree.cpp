#include <iostream>

using namespace std;

struct BinaryTreeNode
{
    int nValue;
    BinaryTreeNode* pLeft;
    BinaryTreeNode* pRight;
    BinaryTreeNode(int x) : nValue(x), pLeft(nullptr), pRight(nullptr) {}
};

class Solution
{
public:
    //µÝ¹éÊµÏÖ
    void MirrorRecursive(BinaryTreeNode* pNode)
    {
        if (pNode == nullptr)
            return;

        if (pNode->pLeft == nullptr  && pNode->pRight == nullptr)
            return;
        BinaryTreeNode* pTemp = pNode->pLeft;
        pNode->pLeft = pNode->pRight;
        pNode->pRight = pTemp;
        if (pNode->pLeft)
            MirrorRecursive(pNode->pLeft);
        if (pNode->pRight)
            MirrorRecursive(pNode->pRight);
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

void PrintBinaryTree(BinaryTreeNode* pNode)
{
    if (pNode == nullptr)
        return;
    cout << pNode->nValue << "->";
    PrintBinaryTree(pNode->pLeft);
    PrintBinaryTree(pNode->pRight);
}

void test(BinaryTreeNode* pNode)
{
    Solution solution;
    cout << "the src binary tree is: " << endl;
    PrintBinaryTree(pNode);
    cout << endl;
    solution.MirrorRecursive(pNode);
    cout << "the mirror binary tree is: " << endl;
    PrintBinaryTree(pNode);
    cout << endl;
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