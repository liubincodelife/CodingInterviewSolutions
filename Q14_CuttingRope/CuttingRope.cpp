#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    //动态规划解法
    int maxProductAfterCutting_DP(int length)
    {
        if (length < 2)
            return 0;
        if (length == 2)
            return 1;
        if (length == 3)
            return 2;

        vector<int> product(length + 1, 0);
        product[0] = 0;
        product[1] = 1;
        product[2] = 2;
        product[3] = 3;
        int maxProduct = 0;
        for (int i = 4; i <= length; ++i)
        {
            maxProduct = 0;
            for (int j = 1; j <= i/2; ++j)
            {
                int curProduct = product[j] * product[i - j];
                if (maxProduct < curProduct)
                {
                    maxProduct = curProduct;
                }
                product[i] = maxProduct;
            }
        }

        maxProduct = product[length];

        return maxProduct;
    }

    int maxProductAfterCutting_Greedy(int length)
    {
        if (length < 2)
            return 0;
        if (length == 2)
            return 1;
        if (length == 3)
            return 2;

        int timesOfThree = length / 3;
        //判断最后一段绳子长度是否为4
        if ((length - timesOfThree * 3) == 1)
            timesOfThree -= 1;

        int timesOfTwo = (length - timesOfThree * 3) / 2;
        int result = pow(3, timesOfThree) * pow(2, timesOfTwo);

        return result;
    }
protected:
private:
};

void test(int length, int expected)
{
    Solution solution;
    //int retValue = solution.maxProductAfterCutting_DP(length);
    int retValue = solution.maxProductAfterCutting_Greedy(length);
    if (retValue == expected)
    {
        cout << "Passed......" << endl;
    }
    else
    {
        cout << "Failed!!!" << endl;
    }
}

void test1()
{
    cout << "test1 is running......" << endl;
    int length = 1;
    int expected = 0;
    test(length, expected);
}

void test2()
{
    cout << "test2 is running......" << endl;
    int length = 2;
    int expected = 1;
    test(length, expected);
}

void test3()
{
    cout << "test3 is running......" << endl;
    int length = 3;
    int expected = 2;
    test(length, expected);
}

void test4()
{
    cout << "test4 is running......" << endl;
    int length = 4;
    int expected = 4;
    test(length, expected);
}

void test5()
{
    cout << "test5 is running......" << endl;
    int length = 8;
    int expected = 18;
    test(length, expected);
}

void test6()
{
    cout << "test6 is running......" << endl;
    int length = 50;
    int expected = 86093442;
    test(length, expected);
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