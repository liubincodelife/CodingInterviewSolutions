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
        //�ж��Ƿ���Ҷ�ӽڵ�
        bool isLeafNode = pRoot->pLeft == nullptr && pRoot->pRight == nullptr;
        //��·�������������������ҵ���Ҷ�ӽڵ㣬����ɾ�����һ���ڵ㣬��������
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

        //�������Ҷ�ӽڵ㣬����������������ӽڵ�
        if (pRoot->pLeft != nullptr)
            findPathCore(pRoot->pLeft, expectedSum, pathVec, currentSum);
        if (pRoot->pRight != nullptr)
            findPathCore(pRoot->pRight, expectedSum, pathVec, currentSum);

        //��������֤������Ҷ�ӽڵ㣬ɾ�����һ���ڵ㲢���������丸�ڵ����һ���ӽڵ�
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