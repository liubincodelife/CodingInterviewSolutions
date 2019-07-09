#include <iostream>
#include <vector>

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
    void findPath(BinaryTreeNode* pRoot, int expectedSum)
    {
        if (pRoot == nullptr)
            return;
        vector<int> pathVec;
        int currentSum = 0;
        findPathCore(pRoot, expectedSum, pathVec, currentSum);
    }

    void findPathCore(BinaryTreeNode* pRoot, int expectedSum, vector<int> pathVec, int currentSum)
    {
        currentSum += pRoot->nValue;
        pathVec.push_back(pRoot->nValue);
        //判断是否是叶子节点
        bool isLeafNode = pRoot->pLeft == nullptr && pRoot->pRight == nullptr;
        //当路径和满足输入条件并且到了叶子节点，否则删除最后一个节点，继续遍历
        if (currentSum == expectedSum && isLeafNode) 
        {
            auto iter = pathVec.begin();
            cout << "find a valid path: " << endl;
            for (; iter != pathVec.end(); ++iter)
            {
                cout << *iter << " ";
            }
            cout << endl;
        }

        //如果不是叶子节点，则继续遍历其左右子节点
        if (pRoot->pLeft != nullptr)
            findPathCore(pRoot->pLeft, expectedSum, pathVec, currentSum);
        if (pRoot->pRight != nullptr)
            findPathCore(pRoot->pRight, expectedSum, pathVec, currentSum);

        //到了这里证明到了叶子节点，删除最后一个节点并继续遍历其父节点的下一个子节点
        pathVec.pop_back();
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

void test(BinaryTreeNode* pRoot, int expectedSum)
{
    Solution solution;
    solution.findPath(pRoot, expectedSum);
}

void test1()
{
    BinaryTreeNode* pRoot = new BinaryTreeNode(10);
    BinaryTreeNode* pNode1 = new BinaryTreeNode(5);
    BinaryTreeNode* pNode2 = new BinaryTreeNode(12);
    BinaryTreeNode* pNode3 = new BinaryTreeNode(4);
    BinaryTreeNode* pNode4 = new BinaryTreeNode(7);
    ConnectBinaryTreeNode(pRoot, pNode1, pNode2);
    ConnectBinaryTreeNode(pNode1, pNode3, pNode4);

    int expectedSum = 22;
    test(pRoot, expectedSum);
}

int main(int argc, char** argv)
{
    test1();
    getchar();
    return 0;
}