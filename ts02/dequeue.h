/* Header File for deque */
#define SIZE 100
#define ERR_DATA (-302031)

int insertLeft(int d);
void insertRight(int d);
int removeLeft();
int removeRight();
int canWelcome();
int isEmpty();
void init();
int size();

// #include "dequeue.c"

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