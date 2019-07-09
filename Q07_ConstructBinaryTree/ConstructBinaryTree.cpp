#include <iostream>
#include <vector>

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
    BinaryTreeNode* ConstructBinaryTree(vector<int>& preOrder, vector<int>& inOrder)
    {
        if (preOrder.size() == 0 || inOrder.size() == 0)
            return nullptr;

        return ConstructBinaryTreeCore(preOrder, 0, preOrder.size()-1, inOrder, 0, inOrder.size()-1);
    }

    BinaryTreeNode* ConstructBinaryTreeCore(vector<int>& preOrder, int startPreOrder, int endPreOrder, vector<int>& inOrder, int startInOrder, int endInOrder)
    {
        int rootValue = preOrder[startPreOrder];
        BinaryTreeNode* pRootNode = new BinaryTreeNode(rootValue);
        //判断只有一个节点的情况
        if (startPreOrder == endPreOrder && startInOrder == endInOrder && preOrder[startPreOrder] == inOrder[startInOrder])
            return pRootNode;
        //大于一个节点则先在中序遍历中查找根节点的位置
        int indexOfRoot = startInOrder;
        while (indexOfRoot <= endInOrder && inOrder[indexOfRoot] != rootValue)
            ++indexOfRoot;
        int lengthOfLeftTree = indexOfRoot - startInOrder;
        int leftPreOrderEnd = startPreOrder + lengthOfLeftTree;
        //当左子树存在时，开始构建左子树
        if (lengthOfLeftTree > 0)
        {
            pRootNode->pLeft = ConstructBinaryTreeCore(preOrder, startPreOrder + 1, leftPreOrderEnd, inOrder, startInOrder, indexOfRoot - 1);
        }

        //当右子树存在时，开始构建右子树
        if (lengthOfLeftTree < endPreOrder - startPreOrder)
        {
            pRootNode->pRight = ConstructBinaryTreeCore(preOrder, leftPreOrderEnd + 1, endPreOrder, inOrder, indexOfRoot + 1, endInOrder);
        }

        return pRootNode;
    }
protected:
private:
};

void test(vector<int> preOrder, vector<int> inOrder)
{
    Solution solution;
    BinaryTreeNode* pRootNode = solution.ConstructBinaryTree(preOrder, inOrder);
}

void test1()
{
    vector<int> preOrder = { 1, 2, 4, 7, 3, 5, 6, 8 };
    vector<int> inOrder = { 4, 7, 2, 1, 5, 3, 8, 6 };
    test(preOrder, inOrder);
}

int main(int argc, char** argv)
{
    test1();
    getchar();
    return 0;
}