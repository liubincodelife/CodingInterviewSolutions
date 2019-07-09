#include <iostream>

using namespace std;

struct BinaryTreeNode
{
    int nValue;
    BinaryTreeNode* pLeft;
    BinaryTreeNode* pRight;
    BinaryTreeNode(int x = 0) :nValue(x), pLeft(nullptr), pRight(nullptr) {}
};

class Solution
{
public:
    int depthOfBinaryTree(BinaryTreeNode* pRoot)
    {
        if (pRoot == nullptr)
            return 0;
        int dLeft = depthOfBinaryTree(pRoot->pLeft);
        int dRight = depthOfBinaryTree(pRoot->pRight);
        int num = (dLeft > dRight) ? (dLeft + 1) : (dRight + 1);
        return num;
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
    int number = solution.depthOfBinaryTree(pRoot);
    cout << "the depth of binsry tree is: " << number << endl;
}

void test1()
{
    BinaryTreeNode* pRoot = new BinaryTreeNode(1);
    BinaryTreeNode* pNode1 = new BinaryTreeNode(2);
    BinaryTreeNode* pNode2 = new BinaryTreeNode(3);
    BinaryTreeNode* pNode3 = new BinaryTreeNode(4);
    BinaryTreeNode* pNode4 = new BinaryTreeNode(5);
    BinaryTreeNode* pNode5 = new BinaryTreeNode(6);
    BinaryTreeNode* pNode6 = new BinaryTreeNode(7);
    ConnectBinaryTreeNode(pRoot, pNode1, pNode2);
    ConnectBinaryTreeNode(pNode1, pNode3, pNode4);
    ConnectBinaryTreeNode(pNode2, nullptr, pNode5);
    ConnectBinaryTreeNode(pNode4, pNode6, nullptr);

    test(pRoot);
}

int main(int argc, char** argv)
{
    test1();
    getchar();
    return 0;
}