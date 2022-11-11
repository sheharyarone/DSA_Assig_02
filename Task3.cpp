#include <iostream>
#include <string>
#include <time.h>
using namespace std;

bool findPath(int x, int y, int endX, int endY, int **&arr, int size)
{
    arr[x][y] = -1;
    if (x == endX && y == endY)
    {
        return true;
    }
    if (x + 1 < size && arr[x + 1][y] == 1 && arr[endX][endY] != -1)
    {

        findPath(x + 1, y, endX, endY, arr, size);
    }
    if (y + 1 < size && arr[x][y + 1] == 1 && arr[endX][endY] != -1)
    {

        findPath(x, y + 1, endX, endY, arr, size);
    }
    if (y - 1 >= 0 && arr[x][y - 1] == 1 && arr[endX][endY] != -1)
    {

        findPath(x, y - 1, endX, endY, arr, size);
    }
    if (x - 1 >= 0 && arr[x - 1][y] == 1 && arr[endX][endY] != -1)
    {

        findPath(x - 1, y, endX, endY, arr, size);
    }
    if (arr[endX][endY] == -1)
        return true;
    return false;
}
void generateMaze(int **arr, int size)
{
    srand(time(NULL));
    for (int i = 0; i < 4; i++)
    {
        arr[i] = new int[4];
    }
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            arr[i][j] = rand() % 2;
        }
    }
}
void printMaze(int **arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int size = 4;
    int **arr = new int *[size];
    generateMaze(arr, size);
    cout << "MATRIX WHICH IS FORMED : " << endl;
    printMaze(arr, size);

    // PICKING TWO RANDOM POINTS HAVING NO WALL
    int x, y, endX, endY;

    x = rand() % 4;
    y = rand() % 4;
    while (arr[x][y] != 1)
    {
        x = rand() % 4;
        y = rand() % 4;
    }
    endX = rand() % 4;
    endY = rand() % 4;
    while (arr[endX][endY] != 1)

    {
        endX = rand() % 4;
        endY = rand() % 4;
    }
    // RANDOM POINTS SELECTED

    cout << "FIRST POINT : " << x << y << " " << endl;
    cout << "SECOND POINT : " << endX << endY << endl;
    cout << "RESULT OF OUR FUNCTION : " << findPath(x, y, endX, endY, arr, 4) << endl;

    cout << "AFTER TRAVERSING" << endl;
    printMaze(arr, size);
    return 0;
}