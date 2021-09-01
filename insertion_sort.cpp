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
void insertionSort(int *A, int n)
{
    int key, j;
    for (int i = 1; i <= n - 1; i++) // For number of pass
    {
        key = A[i];
        j = i - 1;
        while (j >= 0 && A[j] > key)
        {
            A[j + 1] = A[j];
            j--;
        }
        A[j+1]=key;
    }
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
    insertionSort(arr,n);
    cout << "After sorting : ";
    print(arr, n);
    return 0;
}