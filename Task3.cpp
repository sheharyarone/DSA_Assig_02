#include <iostream>
#include <string>
#include <time.h>

using namespace std;

bool findPath(int x, int y, int endX, int endY, int *arr, int size)
{
    if (*(arr + x * 4 + y) && endX != x)
    {
        return findPath(++x, ++y, endX, endY, arr, size);
    }
}

int main()
{
    srand(time(NULL));
    int *arr = new int[4 * 4];
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            *(arr + i * 4 + j) = rand() % 2;
        }
    }

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << *(arr + i * 4 + j) << " ";
        }
        cout << endl;
    }

    int x, y, endX, endY;

    x = rand() % 4;
    y = rand() % 4;
    while (*(arr + x * 4 + y) != 1)
    {
        x = rand() % 4;
        y = rand() % 4;
    }
    endX = rand() % 4;
    endY = rand() % 4;
    while (*(arr + endX * 4 + endY) != 1)
    {
        endX = rand() % 4;
        endY = rand() % 4;
    }

    if (x < endX)
    {
        findPath(x, y, endX, endY, arr, 4);
    }
    else
    {
        findPath(endX, endY, x, y, arr, 4);
    }

    return 0;
}