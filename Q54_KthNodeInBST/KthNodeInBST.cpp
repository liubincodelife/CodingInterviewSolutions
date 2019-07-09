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
    //二叉搜索树的中序遍历序列即为排序后的序列，所以返回中序遍历序列的第k-1个元素即可
    int kthNodeInBST(const BinaryTreeNode* pRoot, int k)
    {
        if (pRoot == nullptr || k <= 0)
            return -1;
        vector<int> nums;
        inOrderTraverse(pRoot, nums, k);
        return nums[k - 1];
    }

    void inOrderTraverse(const BinaryTreeNode* pRoot, vector<int>& nums, int k)
    {
        if (pRoot == nullptr || nums.size() >= k)
        {
            return;
        }
        inOrderTraverse(pRoot->pLeft, nums, k);
        nums.push_back(pRoot->nValue);
        inOrderTraverse(pRoot->pRight, nums, k);
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

void test(const BinaryTreeNode* pRoot, int k)
{
    Solution solution;
    int number = solution.kthNodeInBST(pRoot, k);
    cout << "the kth node in bst is: " << number << endl;
}

void test1()
{
    BinaryTreeNode* pRoot = new BinaryTreeNode(5);
    BinaryTreeNode* pNode1 = new BinaryTreeNode(3);
    BinaryTreeNode* pNode2 = new BinaryTreeNode(7);
    BinaryTreeNode* pNode3 = new BinaryTreeNode(2);
    BinaryTreeNode* pNode4 = new BinaryTreeNode(4);
    BinaryTreeNode* pNode5 = new BinaryTreeNode(6);
    BinaryTreeNode* pNode6 = new BinaryTreeNode(8);
    ConnectBinaryTreeNode(pRoot, pNode1, pNode2);
    ConnectBinaryTreeNode(pNode1, pNode3, pNode4);
    ConnectBinaryTreeNode(pNode2, pNode5, pNode6);

    int k = 3;
    test(pRoot, k);
}

int main(int argc, char** argv)
{
    test1();
    getchar();
    return 0;
}