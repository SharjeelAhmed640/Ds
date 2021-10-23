#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

bool valid(int x, int y, int n, int **sol)
{
    int i, j;
    for (i = 0; i < x; i++)
    {
        if (sol[i][y] == 1)
            return false;
    }
    for (i = x, j = y; i >= 0 && j >= 0; i--, j--)
    {
        if (sol[i][j] == 1)
            return false;
    }
    for (i = x, j = y; i < n && j >= 0; i++, j--)
    {
        if (sol[i][j] == 1)
            return false;
    }
}

bool nQueen(int **board, int n, int x)
{
    if (x >= n - 1)
        return true;

    for (int i = 0; i < n; i++)
    { //board[0][1]=1;
        if (valid(x, i, n, board))
        {
            board[x][i] = 1;
            if (nQueen(board, n, x + 1))
                return true;
            board[x][i] = 0;
        }
    }
    return false;
}
void printMaze(int **arr, int n)
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
    cout << "Enter n : ";
    cin >> n;
    int **maze;
    maze = new int *[n];
    for (int i = 0; i < n; i++)
        maze[i] = new int[n]{};
    printMaze(maze, n);
    if (nQueen(maze, n, 0))
        printMaze(maze, n);
    else
        cout << "No Solution" << endl;

    return 0;
}