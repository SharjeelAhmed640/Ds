#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

int largestSubarr(int arr[], int n, int *s, int *e)
{
    *s=0;
    int maximum=0,max=0;
    for (int i = 0; i < n; i++)
    {
       // cout<<"max:"<<max<<"     maximun:"<<maximum<<"   s:"<<*s<<"   e:"<<*e<<"    i:"<<i<<endl;
        max+=arr[i];
        if(max<arr[i])
        {
            max=arr[i];
            *s=i;
        }
        if(maximum<max)
        {
            maximum=max;
            *e=i;
        }
    }
    return maximum;
    
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