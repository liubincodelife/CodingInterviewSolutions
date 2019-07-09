#include <iostream>

using namespace std;

class Solution1
{
public:
    bool gIsInvalidInput = false;  //全局变量，返回状态
    double Power(double base, int exponent)
    {
        double result = 0.0;
        if (MyEqual(base, 0.0) && exponent < 0)  //底数为0，且指数为负数时。
        {
            gIsInvalidInput = true;
            return 0.0;
        }

        unsigned int absExponent = (unsigned int)exponent;  //将指数强转型为无符号类型
        if (exponent < 0)
        {
            absExponent = -exponent;
        }

        result = PowerWithUnsignedExponent2(base, absExponent);
        if (exponent < 0)
        {
            result = 1.0 / result;
        }

        return result;
    }

    double PowerWithUnsignedExponent(double base, int exponent)
    {
        double result = 1.0;
        for (int i = 1; i <= exponent; ++i)  //指数从1开始
        {
            result *= base;
        }
        return result;
    }

    //使用递归的方法计算Power
    double PowerWithUnsignedExponent2(double base, int exponent)
    {
        if (exponent == 0)
            return 1.0;
        if (exponent == 1)
            return base;
        double result = PowerWithUnsignedExponent2(base, exponent >> 1);
        result *= result;
        if (exponent & 0x01)  //判断指数是奇数还是偶数
        {
            result *= base;
        }
        return result;
    }

    bool MyEqual(double num1, double num2)
    {
        if ((num1 - num2) > -0.0000001 && (num1 - num2 < 0.0000001))
            return true;
        else
            return false;
    }
protected:
private:
};

void test(double base, int exponent, double expectedResult, bool expectedStatus)
{
    Solution1 solution1;
    double result = solution1.Power(base, exponent);
    bool status = solution1.gIsInvalidInput;
    if (solution1.MyEqual(result, expectedResult) && status == expectedStatus)
    {
        cout << "Passed......" << endl;
    }
    else
    {
        cout << "Failed!!!" << endl;
    }

}

//底数和指数都是正数
void test1()
{
    cout << "test1 is running......" << endl;
    test(2, 3, 8, false);
}

//底数为负数，指数为正数
void test2()
{
    cout << "test2 is running......" << endl;
    test(-2, 3, -8, false);
}

//指数为负数
void test3()
{
    cout << "test3 is running......" << endl;
    test(2, -3, 0.125, false);
}

//指数为0
void test4()
{
    cout << "test4 is running......" << endl;
    test(2, 0, 1, false);
}

//底数和指数都为0
void test5()
{
    cout << "test5 is running......" << endl;
    test(0, 0, 1, false);
}

//底数为0，指数为正数
void test6()
{
    cout << "test6 is running......" << endl;
    test(0, 4, 0, false);
}

//底数为0，指数为负数
void test7()
{
    cout << "test7 is running......" << endl;
    test(0, -4, 0, true);
}

int main(int argc, char** argv)
{
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();

    getchar();
    return 0;
}