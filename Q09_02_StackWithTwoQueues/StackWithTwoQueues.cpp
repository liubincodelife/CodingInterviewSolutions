#include <iostream>
#include <exception>
#include "StackWithTwoQueues.h"


template <typename T> void CStack<T>::pushItemToHead(T item)
{  
    if (!queue1.empty() && !queue2.empty())
    {
        throw new exception("no stack is empty when push data!!!");
    }
    //将元素插入非空队列中
    if (queue2.empty())
    {
        queue1.push(item);
    }
    else
    {
        queue2.push(item);
    }
}

template <typename T> T CStack<T>::deleteItemFromHead()
{
    if (queue1.empty() && queue2.empty())
    {
        throw new exception("stack is empty when delete item!!!");
    }
    T top;
    if (queue1.empty())
    {
        while (queue2.size() > 1)
        {
            T item = queue2.front();
            queue2.pop();
            queue1.push(item);
        }
        top = queue2.front();
        queue2.pop();
    } 
    else
    {
        while (queue1.size() > 1)
        {
            T item = queue1.front();
            queue1.pop();
            queue2.push(item);
        }
        top = queue1.front();
        queue1.pop();
    }
    return top;
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
    CStack<char> cstack;
    cstack.pushItemToHead('a');
    cstack.pushItemToHead('b');
    cstack.pushItemToHead('c');

    char retValue = cstack.deleteItemFromHead();
    test(retValue, 'c');

    retValue = cstack.deleteItemFromHead();
    test(retValue, 'b');

    cstack.pushItemToHead('d');
    retValue = cstack.deleteItemFromHead();
    test(retValue, 'd');

    cstack.pushItemToHead('e');
    retValue = cstack.deleteItemFromHead();
    test(retValue, 'e');

    retValue = cstack.deleteItemFromHead();
    test(retValue, 'a');

    retValue = cstack.deleteItemFromHead();

    while (1)
    {
    }
    return 0;
}