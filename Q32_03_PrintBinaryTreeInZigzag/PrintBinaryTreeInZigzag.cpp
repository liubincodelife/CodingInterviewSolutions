#include <iostream>
#include <stack>

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
    void printBinaryTreeInZigzag(BinaryTreeNode* pRoot)
    {
        if (pRoot == nullptr)
            return;
        int currentLevel = 0;  //初始化为奇数层
        int nextLevel = 1;     //初始化为偶数层
        stack<BinaryTreeNode*> levelStacks[2];
        levelStacks[currentLevel].push(pRoot);
        while (!levelStacks[0].empty() || !levelStacks[1].empty())
        {
            BinaryTreeNode* pNode = levelStacks[currentLevel].top();  //取栈顶元素打印
            levelStacks[currentLevel].pop();
            cout << pNode->nValue<< " ";
            if (currentLevel == 0)  //当前层为奇数层，先存左子节点，再存右子节点
            {
                if (pNode->pLeft != nullptr)
                    levelStacks[nextLevel].push(pNode->pLeft);
                if (pNode->pRight != nullptr)
                    levelStacks[nextLevel].push(pNode->pRight);
            } 
            else
            {
                if (pNode->pRight != nullptr)
                    levelStacks[nextLevel].push(pNode->pRight);
                if (pNode->pLeft != nullptr)
                    levelStacks[nextLevel].push(pNode->pLeft);
            }

            if (levelStacks[currentLevel].empty())  //当前层打印完了，开始交换层打印
            {
                cout << endl;  //打印换行
                currentLevel = 1 - currentLevel;
                nextLevel = 1 - nextLevel;
            }
        }
        
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
    solution.printBinaryTreeInZigzag(pRoot);
}

void test1()
{
    BinaryTreeNode* pRoot = new BinaryTreeNode(1);
    BinaryTreeNode* pTreeNode1 = new BinaryTreeNode(2);
    BinaryTreeNode* pTreeNode2 = new BinaryTreeNode(3);
    BinaryTreeNode* pTreeNode3 = new BinaryTreeNode(4);
    BinaryTreeNode* pTreeNode4 = new BinaryTreeNode(5);
    BinaryTreeNode* pTreeNode5 = new BinaryTreeNode(6);
    BinaryTreeNode* pTreeNode6 = new BinaryTreeNode(7);
    BinaryTreeNode* pTreeNode7 = new BinaryTreeNode(8);
    BinaryTreeNode* pTreeNode8 = new BinaryTreeNode(9);
    BinaryTreeNode* pTreeNode9 = new BinaryTreeNode(10);
    BinaryTreeNode* pTreeNode10 = new BinaryTreeNode(11);
    BinaryTreeNode* pTreeNode11 = new BinaryTreeNode(12);
    BinaryTreeNode* pTreeNode12 = new BinaryTreeNode(13);
    BinaryTreeNode* pTreeNode13 = new BinaryTreeNode(14);
    BinaryTreeNode* pTreeNode14 = new BinaryTreeNode(15);

    ConnectBinaryTreeNode(pRoot, pTreeNode1, pTreeNode2);  //1--2--3
    ConnectBinaryTreeNode(pTreeNode1, pTreeNode3, pTreeNode4);  //2--4--5
    ConnectBinaryTreeNode(pTreeNode2, pTreeNode5, pTreeNode6);  //3--6--7
    ConnectBinaryTreeNode(pTreeNode3, pTreeNode7, pTreeNode8);  //4--8--9
    ConnectBinaryTreeNode(pTreeNode4, pTreeNode9, pTreeNode10);  //5--10--11
    ConnectBinaryTreeNode(pTreeNode5, pTreeNode11, pTreeNode12);  //6--12--13
    ConnectBinaryTreeNode(pTreeNode6, pTreeNode13, pTreeNode14);  //7--14--15
    test(pRoot);
}

int main(int argc, char** argv)
{
    test1();
    getchar();
    return 0;
}