#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int findMinNumber(vector<int>& nums)
    {
        int length = nums.size();
        if (length == 0)
            throw exception("invalid parameter!!!\n");
        int index1 = 0;
        int index2 = length - 1;
        int midIndex = index1;   
        while (nums[index1] >= nums[index2]) //如果输入数组是已排序数组，只旋转了0个元素，直接返回第一个元素的值
        {
            if (index2 - index1 == 1)
            {
                midIndex = index2;
                break;
            }

            midIndex = (index1 + index2) / 2;
            //当nums[index1] == nums[index2] == nums[midIndex]用顺序查找法
            if (nums[index1] == nums[index2] && nums[index1] == nums[midIndex])
            {
                int result = nums[index1];
                for (int i = index1 +1; i <= index2; ++i)
                {
                    if (result > nums[i])
                    {
                        result = nums[i];
                    }
                }
                return result;
            }
            //二分查找方法
            if (nums[midIndex] >= nums[index1])
            {
                index1 = midIndex;
            }
            else if (nums[midIndex] <= nums[index2])
            {
                index2 = midIndex;
            }
        }

        return nums[midIndex];
    }
protected:
private:
};

void test(vector<int> nums, int expected)
{
    int length = nums.size();
    Solution solution;
    int retValue = solution.findMinNumber(nums);
    if (retValue == expected)
    {
        cout << "Passed......" << endl;
    }
    else
    {
        cout << "Failed!!!!!!" << endl;
    }
}

void test1()
{
    cout << "test1 is running...... " <<endl;
    vector<int> nums = { 3, 4, 5, 1, 2 };
    int expectedNum = 1;
    test(nums, expectedNum);
}

void test2()
{
    cout << "test2 is running...... " << endl;
    vector<int> nums = { 3, 4, 5, 1, 1, 2 };
    int expectedNum = 1;
    test(nums, expectedNum);
}

void test3()
{
    cout << "test3 is running...... " << endl;
    vector<int> nums = { 3, 4, 5, 1, 2, 2 };
    int expectedNum = 1;
    test(nums, expectedNum);
}

void test4()
{
    cout << "test4 is running...... " << endl;
    vector<int> nums = { 1, 0, 1, 1, 1};
    int expectedNum = 0;
    test(nums, expectedNum);
}

void test5()
{
    cout << "test5 is running...... " << endl;
    vector<int> nums = { 1, 2, 3, 4, 5 };
    int expectedNum = 1;
    test(nums, expectedNum);
}

void test6()
{
    cout << "test6 is running...... " << endl;
    vector<int> nums = { 2 };
    int expectedNum = 2;
    test(nums, expectedNum);
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