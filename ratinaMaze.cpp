#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

bool isSafe(int **maze, int x, int y, int n)
{
    if ((x < n && x >= 0) && (y < n && y >= 0) && maze[x][y] == 1)
        return true;
    return false;
}
bool ratinMaze(int **maze, int x, int y, int n, int **sol)
{
    if (x == n - 1 && y == n - 1)
    {
        sol[x][y] = 1;
        return true;
    }

    if (isSafe(maze, x, y, n))
    {
        sol[x][y] = 1;
        if (ratinMaze(maze, x + 1, y, n, sol))
        {
            return true;
        }
        if (ratinMaze(maze, x, y + 1, n, sol))
        {
            return true;
        }
        else
        {
            sol[x][y] = 0; //back tracking
            return false;
        }
    }
    return false;
}
void printmaze(int **arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl
         << endl;
}
int main()
{
    int n;
    cout << "Enter size : ";
    cin >> n;
    int **maze = new int *[n];
    int **sol = new int *[n];
    for (int i = 0; i < n; i++)
    {
        maze[i] = new int[n]{};
        sol[i] = new int[n]{};
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "index [" << i << "][" << j << "] : ";
            cin >> maze[i][j];
        }
    }
    cout << "Orignal maze" << endl;
    printmaze(maze, n);
    if (ratinMaze(maze, 0, 0, n, sol))
    {
        cout << "Solved maze" << endl;
        printmaze(sol, n);
    }
    return 0;
}

/*Test case
1 0 1 0 1
1 1 1 1 1
0 1 0 1 0
1 0 0 1 1
1 1 1 0 1
*/