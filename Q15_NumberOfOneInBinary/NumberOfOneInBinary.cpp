#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    //循环+移位
    int numberOfOne_1(int n)
    {
        int count = 0;
        int flag = 1;
        while (flag)
        {
            if (n & flag)
            {
                ++count;
            }

            flag <<= 1;
        }
        return count;
    }

    //先减一在和原数与
    int numberOfOne_2(int n)
    {
        int count = 0;
        while (n)
        {
            ++count;
            n = (n - 1) & n;
        }

        return count;
    }
protected:
private:
};

void test(int n, int expected)
{
    Solution solution;
    //int retValue = solution.numberOfOne_1(n);
    int retValue = solution.numberOfOne_2(n);
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
    int num = 0;
    test(num, 0);
}

void test2()
{
    cout << "test2 is running......" << endl;
    int num = 1;
    test(num, 1);
}

void test3()
{
    cout << "test3 is running......" << endl;
    int num = 0xFFFFFFFF;
    test(num, 32);
}

void test4()
{
    cout << "test4 is running......" << endl;
    int num = 0x80000000;
    test(num, 1);
}

int main(int argc, char** argv)
{
    test1();
    test2();
    test3();
    test4();

    getchar();
    return 0;
}