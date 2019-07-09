#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> spiralMatrix(vector<vector<int>>& matrix)
    {
        int rows = matrix.size();
        int cols = matrix[0].size();
        if (rows == 0 && cols == 0)
        {
            return{};
        }

        vector<int> retVector;
        int start = 0;
        while (rows > start * 2 && cols > start * 2)
        {
            int endX = cols - 1 - start;
            int endY = rows - 1 - start;
            //��һ���������Ҵ�ӡ
            for (int i = start; i <= endX; ++i)
            {
                retVector.push_back(matrix[start][i]);
            }

            if (start < endY) //��ʼλ���к�С����ֹλ���к�
            {
                //�ڶ��������ϵ��´�ӡ
                for (int i = start + 1; i <= endY; ++i)
                {
                    retVector.push_back(matrix[i][endX]);
                }
            }

            if (start < endX && start < endY)
            {
                //�����������ҵ����ӡ
                for (int i = endX - 1; i >= start; --i)
                {
                    retVector.push_back(matrix[endY][i]);
                }
            }
            
            if (start < endX && start < endY - 1) //��ʼλ���к�С���յ�λ���кţ��кű���ֹ�к�С2
            {
                //���Ĳ������µ��ϴ�ӡ
                for (int i = endY - 1; i >= start + 1; --i)
                {
                    retVector.push_back(matrix[i][start]);
                }
            }

            ++start;
        }

        return retVector;
    }
protected:
private:
};

void test1()
{
    cout << "test1 is running......" <<endl;
    vector<vector<int>> matrix = { {1} };
    Solution solution;
    vector<int> retVector = solution.spiralMatrix(matrix);
    for (auto it = retVector.begin(); it != retVector.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;
}

void test2()
{
    cout << "test2 is running......" << endl;
    vector<vector<int>> matrix = { { 1, 2}, {3, 4} };
    Solution solution;
    vector<int> retVector = solution.spiralMatrix(matrix);
    for (auto it = retVector.begin(); it != retVector.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;
}

void test3()
{
    cout << "test3 is running......" << endl;
    vector<vector<int>> matrix = { { 1, 2, 3, 4},{ 5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16} };
    Solution solution;
    vector<int> retVector = solution.spiralMatrix(matrix);
    for (auto it = retVector.begin(); it != retVector.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;
}

void test4()
{
    cout << "test4 is running......" << endl;
    vector<vector<int>> matrix = { { 1 },{ 2 },{ 3 },{ 4 },{ 5 } };
    Solution solution;
    vector<int> retVector = solution.spiralMatrix(matrix);
    for (auto it = retVector.begin(); it != retVector.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;
}

void test5()
{
    cout << "test5 is running......" << endl;
    vector<vector<int>> matrix = { { 1, 2, 3, 4, 5 }};
    Solution solution;
    vector<int> retVector = solution.spiralMatrix(matrix);
    for (auto it = retVector.begin(); it != retVector.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;
}

void test6()
{
    cout << "test6 is running......" << endl;
    vector<vector<int>> matrix = { { 1, 2, 3, 4, 5 }, {6, 7, 8, 9, 10} };
    Solution solution;
    vector<int> retVector = solution.spiralMatrix(matrix);
    for (auto it = retVector.begin(); it != retVector.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;
}

int main(int argc, char** argv)
{
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    getchar();
    return 0;
}