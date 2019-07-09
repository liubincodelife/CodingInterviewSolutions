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
    bool VerifySquenceOfBST(vector<int> sequence)
    {
        return VerifySquenceOfBSTCore(sequence, 0, sequence.size());
    }
    bool VerifySquenceOfBSTCore(vector<int> sequence, int startIndex, int endIndex)
    {
        if (sequence.empty() || startIndex > endIndex)
            return false;
        //首先找到序列中的根节点
        int rootValue = sequence[endIndex - 1];  //最后一个节点即为根节点
        //找出左子树和右子树的分界点
        int i = startIndex;
        for (;i < endIndex - 1; ++i)
        {
            if(sequence[i] > rootValue)  //由于左子树的节点小于根节点，右子树的节点大于根节点
                break;
        }

        int j = i;  //i即为左子树和右子树的分界点
        for (;j < endIndex - 1; ++j)
        {
            if (sequence[j] < rootValue)
                return false;
        }

        bool left = true;
        if(i > startIndex)  //证明左子树不止一个节点
            left = VerifySquenceOfBSTCore(sequence, startIndex, i);
        bool right = true;
        if (i < endIndex - 1)  //证明右子树不止一个节点
            right = VerifySquenceOfBSTCore(sequence, i, endIndex - 1);
        return (left && right);
    }

protected:
private:
};

void test(vector<int> sequence)
{
    Solution solution;
    solution.VerifySquenceOfBST(sequence);
}

void test1()
{
    vector<int> sequence = { 5, 7, 6, 9, 11, 10, 8 };
    test(sequence);
}

int main(int argc, char** argv)
{
    test1();
    getchar();
    return 0;
}