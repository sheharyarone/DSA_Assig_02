#include <iostream>
#include <string>
#include <time.h>
using namespace std;

int arrCheck[4][4] = {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
int arr[4][4] = {{1, 0, 0, 0}, {1, 1, 1, 1}, {1, 0, 0, 1}, {1, 1, 0, 1}};

bool findPath(int x, int y, int endX, int endY, int size)
{
    arrCheck[x][y] = 1;

    if (x == endX && y == endY)
    {
        return true;
    }
    if (x + 1 < size && arr[x + 1][y] == 1 && !arrCheck[x + 1][y])
    {
        findPath(x + 1, y, endX, endY, size);
    }
    if (y + 1 < size && arr[x][y + 1] == 1 && !arrCheck[x][y + 1])
    {
        findPath(x, y + 1, endX, endY, size);
    }
    if (y - 1 >= 0 && arr[x][y - 1] == 1 && !arrCheck[x][y - 1])
    {
        findPath(x, y - 1, endX, endY, size);
    }
    if (x - 1 >= 0 && arr[x - 1][y] == 1 && !arrCheck[x - 1][y])
    {
        findPath(x - 1, y, endX, endY, size);
    }
   
}

int main()
{
    findPath(0, 0, 3, 3, 4);
    if(arrCheck[3][3])
    {
        cout << "U GoT PATH." << endl;
    }
    else
    {
        cout << "YOU DON'T." << endl;
    }

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << arrCheck[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}