/* An implementation of Deque  */
#include <stdio.h>
#include <stdlib.h>
#include "dequeue.h"

int data[SIZE];
int left = -1;
int right = -1;

int insertLeft(int d)
{
    if (size() == SIZE - 1)
        return;
    if (left == -1)
    {
        left = right = 0;
        data[left] = d;
        return;
    }
    left = (left - 1 + SIZE) % SIZE;
    data[left] = d;
}

void insertRight(int d)
{
    // Not implemented
    if (size() == SIZE - 1)
        return;
    if (right == -1)
    {
        left = right = 0;
        data[right] = d;
        return;
    }
    right = (right + 1 + SIZE) % SIZE;
    data[right] = d;
}

int removeLeft()
{
    int d, s;

    s = size();

    if (s == 0)
        return ERR_DATA; // Error value
    d = data[left];
    left = (left + 1 + SIZE) % SIZE;
    if (s == 1)
        init();
    return d;
    // Not implemented
}

int removeRight()
{
    int d, s;

    s = size();

    if (s == 0)
        return ERR_DATA; // Error value
    d = data[right];
    right = (right - 1 + SIZE) % SIZE;
    if (s == 1)
        init();
    return d;
}

int hasWelcome()
{
    return size() < SIZE;
}

int isEmpty()
{
    return size() == 0;
}

void init()
{
    left = right = -1;
}

int size()
{
    if (left == -1)
        return 0;
    return (right + SIZE - left) % SIZE + 1;
}

int main(void)
{
    int i, s;
    init(); // Start deque

    for (i = 1; i <= 10; i++)
    {
        insertRight(i * i);
        s = size();
        printf("Size = %d Data = %d\n", s, removeLeft());
        insertRight(i * i * i);
    }

    while (size() > 0)
    {
        printf("Emptying deque %d\n", removeLeft());
    }

    return 0;
}