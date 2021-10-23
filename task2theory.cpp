#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

int maxSubArray(int *arr, int n, int *x, int *y)
{
    int lsum = arr[0], sum = arr[0], i, j, k;
    for (i = 0; i < n; i++)
    {
        if (sum < arr[i])
            lsum = arr[i];
    }
    sum = lsum;
    for (i = 0; i < n; i++)
    {
        for (j = i; j < n; j++)
        {
            lsum = 0;
            for (k = i; k <= j; k++)
            {
                lsum += arr[k];
                if (sum < lsum)
                {
                    sum = lsum;
                    *x = i;
                    *y = k;
                }
            }
        }
    }
    return sum;
}
void print(int arr[], int n, int row, int col)
{
    for (int i = row; i <= col; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main()
{
    int n=1, row, col;
    cin >> n;
    if (n <= 0)
        return 0;
    int *arr;
    arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int max = maxSubArray(arr, n, &row, &col);
    print(arr, n, row, col);
    cout << max;

    return 0;
}