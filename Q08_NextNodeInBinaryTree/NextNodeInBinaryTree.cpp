#include <iostream>
#include <vector>

using namespace std;

struct BinaryTreeNode
{
    int nValue;
    BinaryTreeNode* pLeft;
    BinaryTreeNode* pRight;
    BinaryTreeNode* pParent;
    BinaryTreeNode(int x = 0) : nValue(x), pLeft(nullptr), pRight(nullptr), pParent(nullptr){}
};

class Solution
{
public:
    BinaryTreeNode* getNextNodeInOrder(BinaryTreeNode* pNode)
    {
        if (pNode == nullptr)
            return nullptr;
        BinaryTreeNode* pNextNode = nullptr;
        //当pNode存在右子树时
        if (pNode->pRight != nullptr)
        {
            BinaryTreeNode* pRight = pNode->pRight;
            while (pRight->pLeft != nullptr)
            {
                pRight->pLeft = pRight->pLeft;
            }
            pNextNode = pRight;
        }
        else if (pNode->pParent != nullptr)  //当存在父节点时
        {
            BinaryTreeNode* pParentNode = pNode->pParent;
            BinaryTreeNode* pCurrentNode = pNode;
            //判断是否为其父节点的右子节点，直到找到某节点为其父节点的左子节点
            while (pParentNode != nullptr && pCurrentNode == pParentNode->pRight)
            {
                pCurrentNode = pParentNode;
                pParentNode = pParentNode->pParent;
            }
            pNextNode = pParentNode;
        }

        return pNextNode;
    }
protected:
private:
};

int main(int argc, char** argv)
{

    getchar();
    return 0;
}