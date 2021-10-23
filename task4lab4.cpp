#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;
int ItemToPer(int *arr, int n, int spending)
{
    int key, i, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }

    int sum=0,last=0,count=0;
    for(i=0;i<n;i++)
    {
        last=arr[i];
        sum+=last;
        count++;
        if(sum>spending)
        {
            sum-=last;
            count--;
            break;
        }
    }
    return count;
}
int main()
{
    int n, budget;
    cout << "Enter number of items : ";
    cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter price of item " << i + 1 << " : ";
        cin >> a[i];
    }
    cout << "Enter total budget : ";
    cin >> budget;
    cout << "Number of can be bought : " << ItemToPer(a, n, budget) << endl;

    return 0;
}