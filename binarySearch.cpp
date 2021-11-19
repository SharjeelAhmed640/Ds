#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

int binarySearch(int arr[], int low, int key, int high)
{
    if (high >= low)
    {
        int mid = low + (high - low) / 2;
        if (key == arr[mid])
            return mid;
        if (key == arr[low])
            return low;
        if (key == arr[high - 1])
            return high;
        if (key < arr[mid])
            binarySearch(arr, low, key, mid - 1);
        if (key > arr[mid])
            binarySearch(arr, mid + 1, key, high);
    }
    else
        return -1;
}

int main()
{
    int arr[] = {2, 3, 4, 10, 40};
    int x = 10;
    int n = sizeof(arr) / sizeof(arr[0]);
    int foundindex = binarySearch(arr, 0, 2, n - 1);
    (foundindex == -1) ? cout << "Not found" << endl : cout << "Found at index : "<<foundindex << endl;
    return 0;
}