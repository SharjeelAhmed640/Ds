#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

bool issafe(int **arr, int row, int col, int num)
{
    int i = 0, j = 0;
    for (i = 0; i < 9; i++)
    { //cout<<"int safe row"<<endl;
        if (arr[i][col] == num)
            return false;
    }
    for (j = 0; j < 9; j++)
    { //cout<<"int safe col"<<endl;
        if (arr[row][j] == num)
            return false;
    }
    // 0 1 2   3 4 5   6 7 8
    // 1 2 3   4 5 6   7 8 9
    // 1 2 3   4 5 6   7 8 9
    // 1 2 3   4 5 6   7 8 9
    // 1 2 3   4 5 6   7 8 9
    // 1 2 3   4 5 6   7 8 9
    // 1 2 3   4 5 6   7 8 9
    // 1 2 3   4 5 6   7 8 9
    // 1 2 3   4 5 6   7 8 9
    int r = row - row % 3;
    int c = col - col % 3;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        { //cout<<"int nested"<<endl;
            if (arr[r + i][j + c] == num)
                return false;
        }
    }
    return true;
}
bool suduko(int **arr, int row, int col)
{
    //cout<<"in sudoko"<<endl;
    if (row == 8 && col == 9)
        return true;
    if(col==9)
    {
        row++;
        col=0;
    }
    if (arr[row][col] > 0)
        return suduko(arr, row, col + 1);
    for (int num = 1; num <= 9; num++)
    { //cout<<"in for loop"<<endl;
        if (issafe(arr, row, col, num))
        {
            arr[row][col] = num;
        
        if (suduko(arr, row, col + 1))
            return true;}
        arr[row][col] = 0;
    }
    return false;
}
void print(int **arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}
void input(int **arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            // cout << "[" << i << "][" << j << "]  :  ";
            cin >> arr[i][j];
        }
    }
}
int main()
{
    int **arr = new int *[9];
    for (int i = 0; i < 9; i++)
    {
        arr[i] = new int[9]{};
    }
   input(arr, 9);

    suduko(arr, 0, 0);
    print(arr, 9);
    return 0;
}