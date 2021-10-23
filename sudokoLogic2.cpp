#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;
#define UNASSIGNED 0
int row;
int col;
bool isSafe(int grid[][9], int x, int y, int num);
bool unassignedval(int grid[][9], int &x, int &y)
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (grid[i][j] == UNASSIGNED)
            {
                x = i;
                y = j;
                return true;
            }
        }
    }
    return false;
}
bool sudokosolve(int grid[9][9])
{
    if (!unassignedval(grid, row, col))
        return true;
    for (int num = 1; num < 10; num++)
    {
        if (isSafe(grid, row, col, num))
        {
            grid[row][col] = num;

            if (sudokosolve(grid))
                return true;

            grid[row][col] = UNASSIGNED;
        }
    }
    return false;
}
bool safeInCol(int grid[][9], int num, int y)
{
    for (int i = 0; i < 9; i++)
    {
        if (grid[i][y] == num)
            return false;
    }
    return true;
}
bool safeInRow(int grid[][9], int x, int num)
{
    for (int j = 0; j < 9; j++)
    {
        if (grid[x][j] == num)
            return false;
    }
    return true;
}
bool safeInBox(int grid[][9], int r, int c, int num)
{
    int sr = r - r % 3, sc = c - c % 3;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (grid[i + sr][j + sc] == num)
                return false;
        }
    }
    return true;
}
bool isSafe(int grid[][9], int x, int y, int num)
{
    if (safeInCol(grid, num, y) && safeInRow(grid, x, num) && safeInBox(grid, x, y, num))return true;
    return false;
}
int main()
{
    int grid[9][9]{};
    for (int i = 0; i < 8; i++)
    {
       for(int j=0;j<8;j++)
       cin>>grid[i][j];
    }
    if(sudokosolve(grid))
    {
        for (int i = 0; i < 9; i++)
    {
       for(int j=0;j<9;j++)
       cout<<grid[i][j]<<" ";
       cout<<endl;
    }
    }
    
    return 0;
}