#include <iostream>
#include <fstream>

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
    void serialize(const BinaryTreeNode* pRoot, ostream& stream)
    {
        if (pRoot == nullptr)
        {
            stream << "$,";
            return;
        }
        //ǰ������������������л�
        stream << pRoot->nValue << ",";
        serialize(pRoot->pLeft, stream);
        serialize(pRoot->pRight, stream);
    }

    string serialize(const BinaryTreeNode* pRoot)
    {
        if (pRoot == nullptr)
        {

        }
    }

    void deserialize(BinaryTreeNode** pRoot, istream& stream)  //����ָ��
    {
        int number;
        if (readStream(stream, &number))
        {
            *pRoot = new BinaryTreeNode();
            (*pRoot)->nValue = number;
            deserialize(&((*pRoot)->pLeft), stream);
            deserialize(&((*pRoot)->pRight), stream);
        }

    }

    //�����ݶ�ȡ��������Ϊ����ʱ����true
    bool readStream(istream& stream, int* number)
    {
        if (stream.eof())
            return false;
        char buffer[32];
        char tmpChar;
        stream >> tmpChar;
        int i = 0;
        while (!stream.eof() && tmpChar != ',')  //����֮ǰ�����ֶ���Ҫ��ȡ
        {
            buffer[i++] = tmpChar;
            stream >> tmpChar;
        }
        bool isNumber = false;
        if (i > 0 && buffer[0] != '$')
        {
            *number = atoi(buffer);
            isNumber = true;
        }

        return isNumber;
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

void printBinaryTree(const BinaryTreeNode* pRoot)
{
    if (pRoot == nullptr)
    {
        cout << "null ";
        return;
    }
    else
        cout << pRoot->nValue << " ";
    printBinaryTree(pRoot->pLeft);
    printBinaryTree(pRoot->pRight);
}

void test(const BinaryTreeNode* pRoot)
{
    Solution solution;
    char* fileName = "serialize.txt";
    //��ӡԭʼ������
    printBinaryTree(pRoot);
    cout << endl;
    //���л�������
    ofstream fileout;
    fileout.open(fileName);
    solution.serialize(pRoot, fileout);
    fileout.close();

    //��ӡserialize.txt������
    ifstream fileIn1;
    fileIn1.open(fileName);
    char tmpChar;
    while (!fileIn1.eof())
    {
        fileIn1 >> tmpChar;
        cout << tmpChar;
    }
    fileIn1.close();
    cout << endl;

    //�����л�������
    ifstream fileIn2;
    fileIn2.open(fileName);
    BinaryTreeNode* pRootNew = nullptr;
    solution.deserialize(&pRootNew, fileIn2);
    fileIn2.close();
    //��ӡ�����л��ؽ�������
    printBinaryTree(pRootNew);
    cout << endl;
}

void test1()
{
    BinaryTreeNode* pRoot = new BinaryTreeNode(1);
    BinaryTreeNode* pNode1 = new BinaryTreeNode(2);
    BinaryTreeNode* pNode2 = new BinaryTreeNode(3);
    BinaryTreeNode* pNode3 = new BinaryTreeNode(4);
    BinaryTreeNode* pNode4 = new BinaryTreeNode(5);
    BinaryTreeNode* pNode5 = new BinaryTreeNode(6);
    ConnectBinaryTreeNode(pRoot, pNode1, pNode2);
    ConnectBinaryTreeNode(pNode1, pNode3, nullptr);
    ConnectBinaryTreeNode(pNode2, pNode4, pNode5);

    test(pRoot);
}

int main(int argc, char** argv)
{
    test1();
    getchar();
    return 0;
}