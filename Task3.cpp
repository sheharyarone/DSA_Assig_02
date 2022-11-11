#include <iostream>
#include <string>
#include <time.h>
using namespace std;

bool range(int x, int y, int *arr, int size)
{
    return (*(arr + x + 1 * size + y) == 1) ||
           (*(arr + x * size + y + 1) == 1) ||
           (*(arr + x * size + y - 1) == 1) ||
           (*(arr + x - 1 * size + y) == 1);
}

bool findPath(int x, int y, int endX, int endY, int *arr, int size)
{
    bool valid = false;

    if (x == endX && y == endY)
    {
        return true;
    }
    if (x + 1 < size && (*(arr + x + 1 * size + y) == 1) && range(x + 1, y, arr, size))
    {
        return findPath(x + 1, y, endX, endY, arr, size);
    }
    else if (y + 1 < size && (*(arr + x * size + y + 1) == 1) && range(x, y + 1, arr, size))
    {

        return findPath(x, y + 1, endX, endY, arr, size);
    }
    else if (y - 1 >= 0 && (*(arr + x * size + y - 1) == 1) && range(x, y - 1, arr, size))
    {

        return findPath(x, y - 1, endX, endY, arr, size);
    }
    else if (x - 1 >= 0 && (*(arr + x - 1 * size + y) == 1) && range(x - 1, y, arr, size))
    {

        return findPath(x - 1, y, endX, endY, arr, size);
    }

    else
    {
        return false;
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
    cout << x << y << " " << *(arr + endX * 4 + endY) << endl;
    cout << endX << endY << " " << *(arr + x * 4 + y) << endl;

    if (x < endX)
    {
        cout << findPath(x, y, endX, endY, arr, 4);
    }
    else
    {
        cout << findPath(endX, endY, x, y, arr, 4);
    }

    return 0;
}