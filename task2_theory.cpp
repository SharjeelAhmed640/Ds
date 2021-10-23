#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

int largestSubarr(int arr[], int n, int *s, int *e)
{
    int i, j, k, max = arr[0], lmax = arr[0];
    for ( i = 0; i < n; i++)
    {
        if(max<arr[i])
        max=arr[i];

    }
    lmax=max;
    for (i = 0; i < n; i++)
    {
        for (j = i; j < n; j++)
        {
            max = 0;
            for (k = i; k <= j; k++)
            {
               // cout << "max : " << max << "  lmax : " << lmax << " i : " << i << " j : " << j << " k : " << k << endl;
                max += arr[k];
                if (max > lmax)
                {
                    lmax = max;
                    *s = i;
                    *e = k;
                }
            }
        }
    }
    return lmax;
}

int main()
{
    int n = 8;
    cin >> n;
    int *arr = new int[n];
    int s, e, i;
    for (i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int max = largestSubarr(arr, n, &s, &e);
  //  cout << "s : " << s << " e:" << e << endl;
    for (i = s; i <= e; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl
         << max;

    return 0;
}