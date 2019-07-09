#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    void PrintOneToNDigits(int n)
    {
        if (n <= 0)
            return;
        string numStr(n, '0');
        while (!IncreaseOne(numStr))
        {
            PrintNumber(numStr);
        }
    }

    //使用递归进行全排列所有数字
    void PrintOneToNDigits2(int n)
    {
        if (n <= 0)
            return;
        string numStr(n, '0');
        int length = numStr.length();
        for (int i = 0; i < 10; ++i)
        {
            numStr[0] = i + '0';
            PrintOneToNDigitsRecursive(numStr, length, 0);
        }
    }

    void PrintOneToNDigitsRecursive(string& numStr, int length, int index)
    {
        if (index == length - 1)
        {
            PrintNumber(numStr);
            return;
        }
        for (int i = 0; i < 10; ++i)
        {
            numStr[index + 1] = i + '0';
            PrintOneToNDigitsRecursive(numStr, length, index + 1);
        }
    }

    bool IncreaseOne(string& num)
    {
        bool isOverFlow = false;
        int nTakeOver = 0; //是否有进位
        int length = num.length();
        for (int i = length - 1; i >= 0; --i)  //从最低位数字开始处理
        {
            int sum = num[i] - '0' + nTakeOver;
            if (i == (length - 1))  //只在个位加1
            {
                sum++;
            }
            if (sum >= 10)  //判断此时是正常进位还是数字溢出
            {
                if (i == 0)  //此时为溢出
                    isOverFlow = true;
                else   //此时为正常进位
                {
                    sum -= 10;
                    nTakeOver = 1;
                    num[i] = sum + '0';
                }
            }
            else
            {
                num[i] = sum + '0';
                break;
            }
        }

        return isOverFlow;
    }

    void PrintNumber(string num)
    {
        bool isFirstCharEqualsZero = true;
        int length = num.length();

        for (int i = 0; i < length; ++i)
        {
            if (isFirstCharEqualsZero && num[i] != '0')
            {
                isFirstCharEqualsZero = false;
            }

            if (!isFirstCharEqualsZero)
            {
                cout << num[i];
            }
        }
        cout << endl;
    }
protected:
private:
};

void test(int n)
{
    Solution solution;
    //solution.PrintOneToNDigits(n);
    solution.PrintOneToNDigits2(n);
}

void test1()
{
    cout << "test1 is running......" << endl;
    test(1);
}

void test2()
{
    cout << "test2 is running......" << endl;
    test(2);
}

void test3()
{
    cout << "test3 is running......" << endl;
    test(3);
}

void test4()
{
    cout << "test4 is running......" << endl;
    test(4);
}

int main(int argc, char** argv)
{
    test1();
    //test2();
    //test3();
    //test4();

    getchar();
    return 0;
}