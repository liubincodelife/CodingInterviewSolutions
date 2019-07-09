#pragma once
#include <queue>

using namespace std;

template <typename T> class CStack
{
public:
    void pushItemToHead(T item);
    T deleteItemFromHead();
private:
    queue<T> queue1;
    queue<T> queue2;

};
