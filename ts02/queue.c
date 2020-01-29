#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

void joinQ(int data)
{
    insertRight(data);
}

int leaveQ()
{
    removeLeft();
}

int main()
{
    int i, s;
    init(); // Start deque

    for (i = 1; i <= 10; i++)
    {
        joinQ(i * i);
        s = size();
        printf("Size = %d Data = %d\n", s, leaveQ());
        joinQ(i * i * i);
    }

    while (size() > 0)
    {
        printf("Emptying deque %d\n", leaveQ());
    }
    return 0;
}