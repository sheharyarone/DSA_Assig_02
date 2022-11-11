#include <iostream>
#include <string>
#include <time.h>
using namespace std;

bool findPath(int x, int y, int endX, int endY, int **arr, int size)
{
        arr[x][y] = -1;
        
        if (x == endX && y == endY)
        {
            return true;
        }
        if (x + 1 < size)
        {
            if (arr[x + 1][y] == 1)
                findPath(x + 1, y, endX, endY, arr, size);
        }
        if (y + 1 < size)
        {
            if (arr[x][y + 1] == 1)
                findPath(x, y + 1, endX, endY, arr, size);
        }
        if (y - 1 >= 0)
        {
            if (arr[x][y - 1] == 1)
                findPath(x, y - 1, endX, endY, arr, size);
        }
        if (x - 1 >= 0)
        {
            if (arr[x - 1][y] == 1)
                findPath(x - 1, y, endX, endY, arr, size);
        }
        if (arr[endX][endY] == -1)
            return true;
        return false;
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
        cout << "MATRIX WHICH IS FORMED : " << endl;
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

        cout << x << y << " " << endl;
        cout << endX << endY << endl;
        cout << findPath(x, y, endX, endY, &arr, 4) << endl;

        cout << "AFTER TRAVERSING" << endl;
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                cout << *(arr + i * 4 + j) << " ";
            }
            cout << endl;
        }
        return 0;
    }