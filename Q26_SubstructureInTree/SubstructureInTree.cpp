#include <iostream>

using namespace std;

struct BinaryTreeNode
{
    double dbValue;
    BinaryTreeNode* pLeft;
    BinaryTreeNode* pRight;
    BinaryTreeNode(double x) : dbValue(x), pLeft(nullptr), pRight(nullptr) {}
};

class Solution
{
public:
    bool HasRootNode(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2)
    {
        bool result = false;

        if(pRoot1 != nullptr && pRoot2 != nullptr)
        {
            bool flag = Equal(pRoot1->dbValue, pRoot2->dbValue);
            if (flag)
                result = HasSubstructure(pRoot1, pRoot2);
            if (!result)  //如果之前没有查找到子结构则从左子树开始重新查找
                result = HasRootNode(pRoot1->pLeft, pRoot2);
            if (!result)
                result = HasRootNode(pRoot1->pRight, pRoot2);
        }

        return result;
    }

    bool HasSubstructure(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2)
    {
        //此处需要先判断子树的节点，否则当遇到相同的叶子节点时将返回false,实际上节点是相等的
        if (pRoot2 == nullptr)
            return true;

        if (pRoot1 == nullptr)
            return false;
        
        bool flag = Equal(pRoot1->dbValue, pRoot2->dbValue);
        if (!flag)
            return false;

        return HasSubstructure(pRoot1->pLeft, pRoot2->pLeft) && HasSubstructure(pRoot1->pRight, pRoot2->pRight);
    }
protected:
private:
    bool Equal(double num1, double num2)
    {
        if (num1 - num2 > -0.0000001 && num1 - num2 < 0.0000001)
            return true;
        else
            return false;
    }
};

void ConnectBinaryTreeNode(BinaryTreeNode* pRoot1, BinaryTreeNode* pLeft, BinaryTreeNode* pRight)
{
    if (pRoot1 != nullptr)
    {
        pRoot1->pLeft = pLeft;
        pRoot1->pRight = pRight;
    }
}

void test(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2, bool expected)
{
    Solution soluiton;
    bool result = soluiton.HasRootNode(pRoot1, pRoot2);
    if (result == expected)
    {
        cout << "Passed......" << endl;
    } 
    else
    {
        cout << "Failed!!!" << endl;
    }
}

// 树中结点含有分叉，树B是树A的子结构
//                  8                8
//              /       \           / \
//             8         7         9   2
//           /   \
//          9     2
//               / \
//              4   7
void test1()
{
    BinaryTreeNode* pRootA1 = new BinaryTreeNode(8);
    BinaryTreeNode* pNodeA2 = new BinaryTreeNode(8);
    BinaryTreeNode* pNodeA3 = new BinaryTreeNode(7);
    BinaryTreeNode* pNodeA4 = new BinaryTreeNode(9);
    BinaryTreeNode* pNodeA5 = new BinaryTreeNode(2);
    BinaryTreeNode* pNodeA6 = new BinaryTreeNode(4);
    BinaryTreeNode* pNodeA7 = new BinaryTreeNode(7);

    ConnectBinaryTreeNode(pRootA1, pNodeA2, pNodeA3);
    ConnectBinaryTreeNode(pNodeA2, pNodeA4, pNodeA5);
    ConnectBinaryTreeNode(pNodeA5, pNodeA6, pNodeA7);


    BinaryTreeNode* pRootB1 = new BinaryTreeNode(8);
    BinaryTreeNode* pNodeB2 = new BinaryTreeNode(9);
    BinaryTreeNode* pNodeB3 = new BinaryTreeNode(2);

    ConnectBinaryTreeNode(pRootB1, pNodeB2, pNodeB3);
    test(pRootA1, pRootB1, true);
}



int main(int argc, char** argv)
{
    test1();
    getchar();
    return 0;
}