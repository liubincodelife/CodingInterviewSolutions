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
        //��pNode����������ʱ
        if (pNode->pRight != nullptr)
        {
            BinaryTreeNode* pRight = pNode->pRight;
            while (pRight->pLeft != nullptr)
            {
                pRight->pLeft = pRight->pLeft;
            }
            pNextNode = pRight;
        }
        else if (pNode->pParent != nullptr)  //�����ڸ��ڵ�ʱ
        {
            BinaryTreeNode* pParentNode = pNode->pParent;
            BinaryTreeNode* pCurrentNode = pNode;
            //�ж��Ƿ�Ϊ�丸�ڵ�����ӽڵ㣬ֱ���ҵ�ĳ�ڵ�Ϊ�丸�ڵ�����ӽڵ�
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