#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

bool valid(int x, int y, int N, int **sol)
{
  if (x >= 0 && x < N && y >= 0 && y < N && sol[x][y] == -1)
    return true;
  return false;
}

bool kp(int **sol, int x, int y, int n, int move, int const *xmov, int const *ymov)
{
  if (move == n * n)
  {
    return 1;
  }
  int next_i, next_j;
  for (int k = 0; k < 8; k++)
  {
    next_i = x + xmov[k];
    next_j = y + ymov[k];
    if (valid(next_i, next_j, n, sol))
    {
      sol[next_i][next_j] = move;
      if (kp(sol, next_i, next_j, n, move + 1, xmov, ymov))
        return 1;

      sol[next_i][next_j] = -1; // backtracking
    }
  }
  return false;
}
void printChess(int **arr, int n)
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
  int xMove[8] = {-2, -2, 2, 2, -1, -1, 1, 1};
  int yMove[8] = {1, -1, 1, -1, 2, -2, 2, -2};
  int n;
  cout << "Enter size of chess : ";
  cin >> n;
  int **arr = new int *[n];
  for (int i = 0; i < n; i++)
  {
    arr[i] = new int[n];
  }
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      arr[i][j] = -1;
    }
  }
  printChess(arr, n);
  if (kp(arr, 0, 0, n, 0, xMove, yMove))
  {
    printChess(arr, n);
  }
  else
    cout << "No solution" << endl;

  return 0;
}