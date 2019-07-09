#include <iostream>

using namespace std;


//递归解法
long long Fibonacci_Recursive(int n)
{
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;

    return Fibonacci_Recursive(n - 1) + Fibonacci_Recursive(n - 2);
}

//循环解法
long long Fibonacci_Loop(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    long long numMinusOne = 1;
    long long numMinusTwo = 0;
    long long fibonValue = 0;

    for (int i = 2; i <= n; i++)
    {
        fibonValue = numMinusOne + numMinusTwo;
        numMinusTwo = numMinusOne;
        numMinusOne = fibonValue;
    }

    return fibonValue;
}

//青蛙跳台阶问题
long long FrogJumpStairProblem(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    if (n == 2)
        return 2;

    long long numMinusOne = 2;
    long long numMinusTwo = 1;
    long long fibonValue = 0;
    for (int i = 3; i <= n; i++)
    {
        fibonValue = numMinusOne + numMinusTwo;
        numMinusTwo = numMinusOne;
        numMinusOne = fibonValue;
    }

    return fibonValue;
}

void test(int n, long long expectedValue)
{
    long long retValue = 0;
    retValue = Fibonacci_Recursive(n);
    if (retValue == expectedValue)
        cout << "Fibonacci_Recursive result is: " << retValue << endl;
    else
        cout << "number "<< n << " test using Fibonacci_Recursive() failed!!!"<< endl;

    retValue = Fibonacci_Loop(n);
    if (retValue == expectedValue)
        cout << "Fibonacci_Loop result is: " << retValue << endl;
    else
        cout << "number " << n << " test using Fibonacci_Loop()failed!!!" << endl;
}

void test2(int n, long long expectedValue)
{
    long long retValue = 0;
    retValue = FrogJumpStairProblem(n);
    if (retValue == expectedValue)
        cout << "FrogJumpStairProblem result is: " << retValue << endl;
    else
        cout << "number " << n << " test using FrogJumpStairProblem() failed!!!" << endl;
}



int main(int argc, char** argv)
{
    //测试Fibonacci
    test(0, 0);
    test(1, 1);
    test(2, 1);
    test(3, 2);
    test(4, 3);
    test(5, 5);
    test(6, 8);
    test(7, 13);
    test(8, 21);
    test(9, 34);
    test(10, 55);

    //test(40, 102334155);

    //测试青蛙跳台阶问题
    test2(0, 0);
    test2(1, 1);
    test2(2, 2);
    test2(3, 3);
    test2(4, 5);
    test2(5, 8);
    test2(6, 13);
    test2(7, 21);
    test2(8, 34);
    test2(9, 55);
    test2(10, 89);
    test2(39, 102334155);

    getchar();
    return 0;
}