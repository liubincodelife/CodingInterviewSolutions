#include <iostream>

using namespace std;

class Solution
{
public:
	bool findNumber(const int* matrix, int rows, int columns, int number)
	{
		if (matrix == nullptr || rows < 0 || columns < 0)
		{
			return false;
		}
		int row = 0;
		int column = columns - 1;
		while (row < rows && column >= 0)
		{
			if (matrix[row * columns + column] == number)
			{
				return true;
			}
			else if (matrix[row * columns + column] > number)
			{
				column--;
			}
			else
			{
				row++;
			}
		}

		return false;
	}
};

void test(const int* matrix, int rows, int columns, int number, bool expectReturn)
{
	Solution solution;
	bool returnValue = solution.findNumber(matrix, rows, columns, number);
	if (returnValue == expectReturn)
	{
		cout << "Passed..."<< endl;
	}
	else
	{
		cout << "Failed!!!"<< endl;
	}
}

//  1   2   8   9
//  2   4   9   12
//  4   7   10  13
//  6   8   11  15

//number is in the matrix
void test1()
{
	int matrix[][4] = { { 1, 2, 8, 9 },{ 2, 4, 9, 12 },{ 4, 7, 10, 13 },{ 6, 8, 11, 15 } };
	cout << "test1 starting......"<< endl;
	test((const int *)matrix, 4, 4, 7, true);
}

//number is not in the matrix
void test2()
{
	int matrix[][4] = { { 1, 2, 8, 9 },{ 2, 4, 9, 12 },{ 4, 7, 10, 13 },{ 6, 8, 11, 15 } };
	cout << "test2 starting......" << endl;
	test((const int *)matrix, 4, 4, 5, false);
}

//number is equals to the smallest number in the matrix
void test3()
{
	int matrix[][4] = { { 1, 2, 8, 9 },{ 2, 4, 9, 12 },{ 4, 7, 10, 13 },{ 6, 8, 11, 15 } };
	cout << "test3 starting......" << endl;
	test((const int *)matrix, 4, 4, 1, true);
}

//number is equals to the biggest number in the matrix
void test4()
{
	int matrix[][4] = { { 1, 2, 8, 9 },{ 2, 4, 9, 12 },{ 4, 7, 10, 13 },{ 6, 8, 11, 15 } };
	cout << "test4 starting......" << endl;
	test((const int *)matrix, 4, 4, 15, true);
}

//number is smaller than the smallest number in the matrix
void test5()
{
	int matrix[][4] = { { 1, 2, 8, 9 },{ 2, 4, 9, 12 },{ 4, 7, 10, 13 },{ 6, 8, 11, 15 } };
	cout << "test5 starting......" << endl;
	test((const int *)matrix, 4, 4, 0, false);
}

//number is bigger than the biggest number in the matrix
void test6()
{
	int matrix[][4] = { { 1, 2, 8, 9 },{ 2, 4, 9, 12 },{ 4, 7, 10, 13 },{ 6, 8, 11, 15 } };
	cout << "test6 starting......" << endl;
	test((const int *)matrix, 4, 4, 16, false);
}

//invalid input matrix
void test7()
{
	int matrix[][4] = { { 1, 2, 8, 9 },{ 2, 4, 9, 12 },{ 4, 7, 10, 13 },{ 6, 8, 11, 15 } };
	cout << "test7 starting......" << endl;
	test(nullptr, 0, 0, 16, false);
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
	while (true)
	{

	}
	return 0;
}