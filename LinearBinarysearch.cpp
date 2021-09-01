#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;
int linearSearch(int arr[], int size, int element)
{

    for (int i = 0; i < size; i++)
    {
        if (arr[i] == element)
            return i;
    }
    return -1;
}
void swap(int *xp, int *yp)
{
    // cout<<" chala ";
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// A function to implement bubble sort
void bubbleSort(int arr[], int n)
{
    // for (int i = 0; i < n; i++)
    // {
    //     cout<<" "<<arr[i]<<endl;
    // }

    int i, j;
    for (i = 0; i < n - 1; i++)

        // Last i elements are already in place
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
}
int binarySearch(int arr[], int size, int element)
{

    bubbleSort(arr, size);

    // for (int i = 0; i < size; i++)
    //     {
    //         cout<<" "<<arr[i]<<endl;
    //     }

    int low, mid, high;
    low = 0;
    high = size - 1;
    mid = (low + high) / 2;
    //keep searching until low and mid converges
    while (low <= high)
    {
        if (element == arr[mid])
            return mid;
        else if (element > arr[mid])
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main()
{
    int arr[] = {5, 2, 9, 4, 8, 15}; // 2 4 5 8 9 14
    int size = sizeof(arr) / sizeof(arr[0]);
    int searchIndex = binarySearch(arr, size, 5);

    // bubbleSort(arr,size);
    // for (int i = 0; i < size; i++)
    // {
    //     cout<<arr[i];
    // }

    cout << "5 Found on : " << searchIndex << " index";
    return 0;
}