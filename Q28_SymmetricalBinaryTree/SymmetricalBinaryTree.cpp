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
    bool isSymmetricalBinaryTree(BinaryTreeNode* pRoot)
    {
        return isSymmetricalBinaryTree(pRoot, pRoot);
    }

    bool isSymmetricalBinaryTree(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2)
    {
        if (pRoot1 == nullptr && pRoot2 == nullptr)
            return true;
        if (pRoot1 == nullptr || pRoot2 == nullptr)
            return false;
        if (pRoot1->nValue != pRoot2->nValue)
            return false;
        return isSymmetricalBinaryTree(pRoot1->pLeft, pRoot2->pRight) && isSymmetricalBinaryTree(pRoot1->pRight, pRoot2->pLeft);
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
    bool retState = solution.isSymmetricalBinaryTree(pRoot);
    if (retState)
        cout << "the binary tree is symmetrical......" << endl;
    else
        cout << "the binary tree is not symmetrical......" << endl;
}

void test1()
{
    BinaryTreeNode* pRoot = new BinaryTreeNode(8);
    BinaryTreeNode* pTreeNode1 = new BinaryTreeNode(6);
    BinaryTreeNode* pTreeNode2 = new BinaryTreeNode(6);
    BinaryTreeNode* pTreeNode3 = new BinaryTreeNode(5);
    BinaryTreeNode* pTreeNode4 = new BinaryTreeNode(7);
    BinaryTreeNode* pTreeNode5 = new BinaryTreeNode(7);
    BinaryTreeNode* pTreeNode6 = new BinaryTreeNode(5);

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