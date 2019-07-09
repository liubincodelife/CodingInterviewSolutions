#include <iostream>

using namespace std;

class Solution 
{
public:
	// Parameters:
	//        numbers:     an array of integers
	//        length:      the length of array numbers
	//        duplication: (Output) the duplicated number in the array number
	// Return value:       true if the input is valid, and there are some duplications in the array number
	//                     otherwise false
	bool duplicate(int numbers[], int length, int* duplication) 
	{
		if (numbers == nullptr || length <= 0)
		{
			cout << "invalid input numbers!!!"<< endl;
			return false;
		}

		for (int i = 0; i < length; i++)
		{
			if (numbers[i] < 0 || numbers[i] > length - 1)
			{
				cout << "invalid input numbers!!!" << endl;
				return false;
			}
		}

		for (int i = 0; i < length; i++)
		{
			while (numbers[i] != i)
			{
				if (numbers[i] == numbers[numbers[i]])
				{
					*duplication = numbers[i];
					return true;
				}
				swap(numbers[i], numbers[numbers[i]]);
			}
		}

		return false;
	}
};

Solution solution;

// ====================测试代码====================
bool contains(int array[], int length, int number)
{
	for (int i = 0; i < length; ++i)
	{
		if (array[i] == number)
			return true;
	}

	return false;
}

bool test(int numbers[], int lengthNumbers, int expected[], int lengthExpected, bool validResult)
{
	int duplications;
	bool testResult = solution.duplicate(numbers, lengthNumbers, &duplications);
	if (testResult == validResult)
	{
		if (validResult)
		{
			bool testArgument = contains(expected, lengthExpected, duplications);
			if (testArgument)
				return true;
			else
				return false;
		}
		else
		{
			return true;
		}
	}
	else
	{
		return false;
	}

	return false;
}

//数组中包含一个重复的数字
void test1()
{
	cout << "test1 starting..........." << endl;
	int numbers[] = { 2, 1, 3, 1, 4 };
	int duplications[] = { 1 };
	bool result = test(numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int), true);
	if (result)
		cout << "   Passed......" << endl;
	else
		cout << "   Failed!!!!!!"<< endl;
}

//数组中不包含重复的数字
void test2()
{
	cout << "test2 starting..........." << endl;
	int numbers[] = { 2, 0, 3, 1, 4 };
	int duplications[] = { 1 };
	bool result = test(numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int), false);
	if (result)
		cout << "   Passed......" << endl;
	else
		cout << "   Failed!!!!!!" << endl;
}

//无效输入数据测试
void test3()
{
	cout << "test3 starting..........." << endl;
	int numbers[] = { 2, -1, 3, 1, 4 };
	int duplications[] = { 1 };
	bool result = test(numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int), true);
	if (result)
		cout << "   Passed......" << endl;
	else
		cout << "   Failed!!!!!!" << endl;
}

int main(int argc, char** argv)
{
	test1();
	test2();
	test3();
	while (true)
	{

	}
	return 0;
}