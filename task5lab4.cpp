#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

void unsortedSub(int *a, int n)
{
    int i, j, u, d; //0 1 2 3   4 5 6    7   8 9 10
    bool check = false; //[10, 12, 20, 30, 25, 40, 32, 31, 35, 50, 60],
    for (i = 0; i < n - 1; i++) //[0, 1, 15, 25, 6, 7, 30, 40, 50],
    {
        for (j = 0; j < n - 1 - i; j++)
        {
            if (a[i] > a[j])
            {

                check = true;
            }
        }
        if (check)
            break;
    }
    u = i + 1;
    check = false;
    for (i = n - 1; i > u; i--)
    {
        for (j = n - 2; j > u; j--)

        {
            if (a[i] < a[j])
            {
                check = true;
            }
        }
        if (check)
            break;
    }
    d = i - 1;
    cout << "Unsorted array is from index " << u << " to " << d << endl;
}

int main()
{
    int n ;
    cout << "Enter array size : ";
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cout << "-> ";
        cin >> arr[i];
    }
    unsortedSub(arr, n);
    return 0;
}