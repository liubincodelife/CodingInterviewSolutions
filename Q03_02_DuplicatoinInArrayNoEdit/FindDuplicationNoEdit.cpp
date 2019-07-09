#include <iostream>

using namespace std;

class Solution
{
public:

	int countNumbersInRange(const int* numbers, int length, int start, int end)
	{
		if (numbers == nullptr)
		{
			return 0;
		}

		int count = 0;
		for (int i = 0; i < length; i++)
		{
			if (numbers[i] >= start && numbers[i] <= end)
			{
				count++;
			}
		}

		return count;

	}

	// Parameters:
	//        numbers:     an array of integers
	//        length:      the length of array numbers
	// Return value:       return the duplicate number
	int getDuplication(const int* numbers, int length)
	{
		if (numbers == nullptr || length <= 0)
		{
			return -1;
		}

		for (int i = 0; i < length; i++)
		{
			if (numbers[i] < 0 || numbers[i] > length - 1)
			{
				return -1;
			}
		}

		int start = 1;
		int end = length - 1;
		while (end >= start)
		{
			int middle = ((end - start) >> 1) + start;
			int count = countNumbersInRange(numbers, length, start, middle);
			if (count > (middle - start + 1))
			{
				end = middle;
			}
			else
			{
				start = middle + 1;
			}
			if (end == start)
			{
				if (count > 1)
				{
					return start;
				}
				else
				{
					break;
				}
			}
		}

		return -1;
	}
};

Solution solution;

void test1()
{
	cout << "test1 starting..........." << endl;
	int numbers[] = { 2, 3, 5, 4, 3, 2, 6, 7};
	int duplicateNumber = solution.getDuplication(numbers, sizeof(numbers) / sizeof(int));
	if (duplicateNumber != -1)
	{
		cout << "test1-->the duplicate number is: "<< duplicateNumber << endl;
	}
	else
	{
		cout << "test1-->no duplicate number!!!" << endl;
	}
}

int main(int argc, char** argv)
{
	test1();
	while (true)
	{

	}
	return 0;
}