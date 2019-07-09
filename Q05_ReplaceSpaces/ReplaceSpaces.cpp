#include<iostream>

using namespace std;

class Solution
{
public:
	bool replaceSpaces(char string[], int length)
	{
		if (string == nullptr || length <= 0)
			return false;
		int originalLength = 0;
		int newLength = 0;
		int numberOfSpaces = 0;
		int index = 0;
		while (string[index] != '\0')
		{
			++originalLength;
			if (string[index] == ' ')
				++numberOfSpaces;
			++index;
		}
		newLength = originalLength + numberOfSpaces * 2;
		if (newLength > length)
			return false;
		int indexOfOriginal = originalLength;
		int indexOfNew = newLength;
		while (indexOfOriginal >= 0 && indexOfNew > indexOfOriginal)
		{
			if (string[indexOfOriginal] == ' ')
			{
				string[indexOfNew--] = '0';
				string[indexOfNew--] = '2';
				string[indexOfNew--] = '%';
			}
			else
			{
				string[indexOfNew--] = string[indexOfOriginal];
			}
			indexOfOriginal--;
		}

		return true;
	}

};


bool test(char string[], int length, char expectedString[])
{
	Solution soluton;
	soluton.replaceSpaces(string, length);
	
	if (expectedString == nullptr && string == nullptr)
	{
		cout << "   Passed......" << endl;
		return true;
	}
	else if (expectedString == nullptr && string != nullptr)
	{
		cout << "   Failed!!!" << endl;
		return false;
	}
	else if(strcmp(string, expectedString) == 0)
	{
		cout << "   Passed......" << endl;
		return true;
	}
	else
	{
		cout << "   Failed!!!" << endl;
		return false;
	}

	return false;
}

//空格在字符串中间
void test1()
{
	const int length = 100;
	char str[length] = "hello world";
	cout << "test1 starting......"<< endl;
	test(str, length, "hello%20world");
}

//空格在字符串开头
void test2()
{
	const int length = 100;
	char str[length] = " helloworld";
	cout << "test2 starting......" << endl;
	test(str, length, "%20helloworld");
}

//空格在字符串末尾
void test3()
{
	const int length = 100;
	char str[length] = "helloworld ";
	cout << "test3 starting......" << endl;
	test(str, length, "helloworld%20");
}

//在字符串中间有连续两个空格
void test4()
{
	const int length = 100;
	char str[length] = "hello  world ";
	cout << "test4 starting......" << endl;
	test(str, length, "hello%20%20world");
}

//传入空指针
void test5()
{
	const int length = 100;

	cout << "test5 starting......" << endl;
	test(nullptr, 0, nullptr);
}


int main(int argc, char** argv)
{
	test1();
	test2();
	test3();
	test4();
	test5();

	while (1)
	{
	}
	return 0;
}