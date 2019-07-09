#pragma once
#include <stack>

using namespace std;

template <typename T> class CQueue
{
public:
    void appendItemToTail(const T& item);
    T deleteItemFromHead();
private:
    stack<T> stack1;
    stack<T> stack2;
};
