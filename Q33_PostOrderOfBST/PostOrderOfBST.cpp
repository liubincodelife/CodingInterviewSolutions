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
        //�����ҵ������еĸ��ڵ�
        int rootValue = sequence[endIndex - 1];  //���һ���ڵ㼴Ϊ���ڵ�
        //�ҳ����������������ķֽ��
        int i = startIndex;
        for (;i < endIndex - 1; ++i)
        {
            if(sequence[i] > rootValue)  //�����������Ľڵ�С�ڸ��ڵ㣬�������Ľڵ���ڸ��ڵ�
                break;
        }

        int j = i;  //i��Ϊ���������������ķֽ��
        for (;j < endIndex - 1; ++j)
        {
            if (sequence[j] < rootValue)
                return false;
        }

        bool left = true;
        if(i > startIndex)  //֤����������ֹһ���ڵ�
            left = VerifySquenceOfBSTCore(sequence, startIndex, i);
        bool right = true;
        if (i < endIndex - 1)  //֤����������ֹһ���ڵ�
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