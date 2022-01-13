#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

void insertionsort(int *arr, int n)
{
    int key, i, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        for (j = i - 1; arr[j] > key && j >= 0; j--)
        {
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = key;
    }
}
void selectionsort(int *arr, int n)
{
    int indexofmin, i, j, temp;
    for (i = 0; i < n - 1; i++)
    {
        indexofmin = i;
        for (j = i + 1; j < n - 1; j++)
        {
            if (arr[indexofmin] > arr[j])
                indexofmin = j;
        }
        temp = arr[indexofmin];
        arr[indexofmin] = arr[i];
        arr[i] = temp;
    }
}
int partition(int *arr, int low, int high)
{
    int pivot = arr[low];
    int i = low + 1;
    int j = high;
    int temp;
    do
    {
        while (arr[i] <= pivot) // to find no greater than pivot
        {
            i++;
        }
        while (arr[j] > pivot) // to find no smaller than pivot
        {
            j--;
        }
        if (i < j)
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    } while (i < j);
    temp = arr[low]; //swapping pivot with j(smaller no than pivot)
    arr[low] = arr[j];
    arr[j] = temp;
    return j;
}

void quicksort(int *arr, int low, int high)
{
    if (low < high)
    {
        int partitionIndex = partition(arr, low, high);
        quicksort(arr, 0, partitionIndex - 1);
        quicksort(arr, partitionIndex + 1, high);
    }
}
void combsort(int *arr, int n)
{
    int gap = n, temp;
    bool swapped = true;
    while (gap != 1 || swapped == true)
    {
        gap = (gap * 10) / 13;
        if (gap < 1)
            gap = 1;
        swapped = false;
        for (int i = 0; i < n - gap; i++)
        {
            if (arr[i] > arr[gap + i])
            {
                temp = arr[i];
                arr[i] = arr[gap + i];
                arr[gap + i] = temp;
                swapped = true;
            }
        }
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
void merge(int *arr, int mid, int low, int high)
{
    int i, j, k;
    int *brr=new int[high - low + 1];
    i = low;
    j = mid + 1;
    k = low;
    while (i <= mid && j <= high)
    {
        if (arr[i] > arr[j])
            brr[k++] = arr[j++];

        else
            brr[k++] = arr[i++];
    }

    while (i <= mid)
        brr[k++] = arr[i++];

    while (j <= high)
        brr[k++] = arr[j++];

    for (i = low; i <= high; i++)
        arr[i] = brr[i];
}
void mergesort(int *arr, int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        mergesort(arr, low, mid);
        mergesort(arr, mid + 1, high);
        merge(arr, mid, low, high);
    }
}
int maxOfArr(int *arr, int n)
{
    int max = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max)
        max = arr[i];
    }
    return max;
}
void countsort(int *arr, int n)
{
    int max = maxOfArr(arr, n);
    int *brr = new int[max + 1]{};
    for (int i = 0; i < n; i++)
    {
        brr[arr[i]] += 1;
    }
    int i = 0, j = 0;
    while (i<max+1)
    {
        if(brr[i]>0)
        {
            arr[j++]=i;
            brr[i]--;
        }
        else i++;
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
    countsort(arr, n);
    // mergesort(arr, 0, n - 1);
    cout << "After sorting : ";
    print(arr, n);
    return 0;
    return 0;
}