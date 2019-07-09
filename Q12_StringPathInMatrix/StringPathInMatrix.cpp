#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    bool hasStringPath(string matrix, int rows, int cols, string str)
    {
        int length = matrix.length();
        if (length == 0 || rows < 1 || cols < 1 || str.length() == 0)
        {
            return false;
        }

        vector<bool> visited(length);
        int curLength = 0;
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                if (hasPathCore(matrix, rows, cols, i, j, str, curLength, visited))
                {
                    return true;
                }
            }
        }
        return false;
    }
protected:
private:
    bool hasPathCore(string matrix, int rows, int cols, int row, int col, string str, int curSearchLength, vector<bool>& visit)
    {
        if (str[curSearchLength] == '\0')
        {
            return true;
        }
        bool hasPath = false;

        if (row >= 0 && row < rows && col >= 0 && col < cols && matrix[row * cols + col] == str[curSearchLength] && !visit[row * cols + col])
        {
            ++curSearchLength;
            visit[row * cols + col] = true;
            hasPath = hasPathCore(matrix, rows, cols, row - 1, col, str, curSearchLength, visit)
                || hasPathCore(matrix, rows, cols, row + 1, col, str, curSearchLength, visit)
                || hasPathCore(matrix, rows, cols, row, col - 1, str, curSearchLength, visit)
                || hasPathCore(matrix, rows, cols, row, col + 1, str, curSearchLength, visit);

            if (!hasPath)
            {
                --curSearchLength;
                visit[row * cols + col] = false;
            }
        }
        return hasPath;
    }

};

void test1()
{
    cout << "test1 is running......" << endl;
    string matrix = "ABTGCFCSJDEH";
    string str = "BFCE";

    Solution solution;
    bool hasPath = solution.hasStringPath(matrix, 3, 4, str);
    if (hasPath)
    {
        cout << "the matrix has the string path......" << endl;
    }
    else
    {
        cout << "the matrix do not has the string path!!!" << endl;
    }
}

void test2()
{
    cout << "test2 is running......" << endl;
    string matrix = "AAAAAAAAAAAA";
    string str = "AAAAAAAAAAAA";

    Solution solution;
    bool hasPath = solution.hasStringPath(matrix, 3, 4, str);
    if (hasPath)
    {
        cout << "the matrix has the string path......" << endl;
    }
    else
    {
        cout << "the matrix do not has the string path!!!" << endl;
    }
}

void test3()
{
    cout << "test3 is running......" << endl;
    string matrix = "ABCEHJIGSFCSLOPQADEEMNOEADIDEJFMVCEIFGGS";
    string str = "SGGFIECVAASABCEHJIGQEM";

    Solution solution;
    bool hasPath = solution.hasStringPath(matrix, 5, 8, str);
    if (hasPath)
    {
        cout << "the matrix has the string path......" << endl;
    }
    else
    {
        cout << "the matrix do not has the string path!!!" << endl;
    }
}


int main(int argc, char** argv)
{
    test1();
    test2();
    test3();
    getchar();
    return 0;
}