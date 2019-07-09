#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int movingCount(int threshold, int rows, int cols)
    {
        if (threshold < 0 || rows <= 0 || cols <= 0)
        {
            return 0;
        }

        vector<bool> visited(rows*cols, false);
        int count = movingCountCore(threshold, rows, cols, 0, 0, visited);
        return count;
    }
protected:
private:
    int movingCountCore(int threshold, int rows, int cols, int row, int col, vector<bool>& visited)
    {
        int count = 0;
        if (checkValid(threshold, rows, cols, row, col, visited))
        {
            visited[row*cols + col] = true;
            count = 1 + movingCountCore(threshold, rows, cols, row, col + 1, visited)
                + movingCountCore(threshold, rows, cols, row, col - 1, visited)
                + movingCountCore(threshold, rows, cols, row - 1, col, visited)
                + movingCountCore(threshold, rows, cols, row + 1, col, visited);
        }

        return count;
    }

    bool checkValid(int threshold, int rows, int cols, int row, int col, vector<bool>& visited)
    {
        if (row >= 0 && row <= rows && col >= 0 && col <= cols 
            && getDigitSum(row) + getDigitSum(col) <= threshold && !visited[row*cols+col])
        {
            return true;
        }
        return false;
    }

    int getDigitSum(int num)
    {
        int sum = 0;
        while (num > 0)
        {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }
};

void test(int threshold, int rows, int cols, int expected)
{
    Solution solution;
    int count = solution.movingCount(threshold, rows, cols);
    if (count == expected)
    {
        cout << "Passed......" << endl;
    }
    else
    {
        cout << "Failed!!!" << endl;
    }
}

//多行多列
void test1()
{
    cout << "test1 is running......" << endl;
    test(5, 10, 10, 21);
}

//只有一行
void test2()
{
    cout << "test2 is running......" << endl;
    /*test(10, 1, 100, 29);*/
    test(10, 1, 10, 10);
}

//只有一列
void test3()
{
    cout << "test3 is running......" << endl;
    test(15, 100, 1, 79);
}

//只有一行一列
void test4()
{
    cout << "test4 is running......" << endl;
    test(15, 1, 1, 1);
}

//阈值为负
void test5()
{
    cout << "test5 is running......" << endl;
    test(-10, 10, 10, 0);
}

int main(int argc, char** argv)
{
    test1();
    test2();
    test3();
    test4();
    test5();
    getchar();
    return 0;
}