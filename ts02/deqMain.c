#include <stdio.h>
#include <stdlib.h>
#include "dequeue.h"

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