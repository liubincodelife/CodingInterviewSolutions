#include <iostream>
#include "QueueWithTwoStacks.h"

using namespace std;

template <typename T> void CQueue<T>::appendItemToTail(const T& item)
{
    stack1.push(item);
}

template <typename T> T CQueue<T>::deleteItemFromHead()
{
    if (stack2.empty())
    {
        while (!stack1.empty())
        {
            T item = stack1.top();
            stack1.pop();
            stack2.push(item);
        }
    }

    T head = stack2.top();
    stack2.pop();

    return head;
}

void test(char actualValue, char expectedValue)
{
    if (actualValue == expectedValue)
        cout << "Passed......" << endl;
    else
        cout << "Failed!!!!!!" << endl;
}

int main(int argc, char** argv)
{
    CQueue<char> cqueue;
    cqueue.appendItemToTail('a');
    cqueue.appendItemToTail('b');
    cqueue.appendItemToTail('c');

    char retValue = cqueue.deleteItemFromHead();
    test(retValue, 'a');

    retValue = cqueue.deleteItemFromHead();
    test(retValue, 'b');

    retValue = cqueue.deleteItemFromHead();
    test(retValue, 'c');
    while (1)
    {
    }
    return 0;
}