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
void selectionSort(int *A, int n)
{
    int indexOfMin, temp;
    for (int i = 0; i < n - 1; i++) // For number of pass
    {
        indexOfMin=i;
        for (int j =  i+1 ; j < n-1; j++)
        {
            if(A[j]<A[indexOfMin])
            {
                indexOfMin=j;
            }
        }
        temp=A[i];
        A[i]=A[indexOfMin];
        A[indexOfMin]=temp;
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
    selectionSort(arr,n);
    cout << "After sorting : ";
    print(arr, n);
    return 0;
}