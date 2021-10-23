#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;
void insertionSort(int *arr, int n)
{
    int key, i, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (arr[j] > key && j >= 0)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
void print(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
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
    insertionSort(arr, n);
    cout << "After sorting : ";
    print(arr, n);
    return 0;
    return 0;
}