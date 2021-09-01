#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;
void print(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int MAX(int A[], int n)
{
    int max = INT8_MIN;
    for (auto i = 0; i < n; i++)
    {
        if (A[i] > max)
        {
            max = A[i];
        }
    }
    return max;
}
void countSort(int A[], int n)
{
    int i, j;
    int max = MAX(A, n);
    int *B = new int[max + 1];
    for (i = 0; i < max + 1; i++)
    {
        B[i] = 0;
    }
    for (i = 0; i < n; i++)
    {
        B[A[i]] += 1;
    }
    i=0;j=0;
    while (i<max+1)
    {
        if(B[i]>0)
        {
            A[j++]=i;
            B[i]--;
        }
        else i++;
    }
    free (B);
    
}
int main()
{
    int n;
    cout << "Enter array size : ";
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cout << "-> ";
        cin >> arr[i];
    }
    cout << "Before sorting : ";
    print(arr, n);
    countSort(arr, n);
    cout << "After sorting : ";
    print(arr, n);
    return 0;
    return 0;
}