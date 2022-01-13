

#include <iostream>

using namespace std;

class HashTable
{
    int *arr;
    int size;

public:
    HashTable()
    {

        size = 10;
        arr = new int[size]{0};
    }
    HashTable(int s)
    {

        size = s;
        arr = new int[size]{0};
    }
    void increaseTablesize(int s)
    {
        if (size < s)
        {
            int *temp = arr;
            int oldsize = size;
            size = s;
            arr = new int[size]{0};
            for (int i = 0; i < oldsize; i++)
            {
                arr[i] = temp[i];
            }
        }
        else
            cout << "Entered size is less than current table size " << endl;
    }
    int hashfunc(int key)
    {
        return (key * 7) % this->size;
    }
    void insert(int key)
    {

        int index, i;
        bool inserted = false;
        for (i = 0; i < this->size; i++)
        {
            index = (hashfunc(key) + i) % this->size;
            if (arr[index] == 0 || arr[index] == -999)
            {
                inserted = true;
                arr[index] = key;
                break;
            }
        }
        if (i == size)
        {
            cout << "No element can insert hash table full" << endl;
        }
    }
    void del_key(int key)
    {
        int i, index;
        for (i = 0; i < size; i++)
        {
            index = (hashfunc(key) + i) % this->size;
            if (arr[index] == 0)
            {

                cout << "Key Not found" << endl;
                break;
            }
            // cout << arr[index] << " " << index << endl;
            if (arr[index] == key)
            {
                arr[index] = -999;
                break;
            }
        }
        if (i == size)
        {
            cout << "Key not found" << endl;
        }
    }
    int search(int key)
    {
        int i, index;
        for (i = 0; i < size; i++)
        {
            index = (hashfunc(key) + i) % this->size;
            if (arr[index] == 0)
            {
                cout << "Key Not found" << endl;
                return -999;
            }
            if (arr[index] == key)
            {
                return index;
            }
        }
        if (i == size)
        {
            cout << "Key not found" << endl;
            return -999;
        }
    }
    void printtable()
    {
        for (int i = 0; i < size; i++)
        {
            if (arr[i] != 0 && arr[i] != -999)
            {
                cout << arr[i] << " ";
            }
            else
                cout << "- ";
        }
        cout << endl
             << endl;
    }
};

int main()
{
    HashTable h;
    int n;
    do
    {
        cout << "Press 1 to insert key" << endl
             << "Press 2 to delete key" << endl
             << "Press 3 to search key" << endl
             << "Press 4 to increase table size" << endl
             << "Press 5 to print table " << endl
             << "Press 0 to exit" << endl;
        cin >> n;
        if (!n)
            break;
        switch (n)
        {
        case 1:
            cout << "Enter key to insert : ";
            cin >> n;
            h.insert(n);
            break;
        case 2:
            cout << "Enter key to delete : ";
            cin >> n;
            h.del_key(n);
            break;
        case 3:
            cout << "Enter key to search : ";
            cin >> n;
            if (h.search(n) != -999)
            {
                cout << "Key found at index : " << h.search(n) << endl;
            }
            break;
        case 4:
            cout << "Enter increased  table size : ";
            cin >> n;
            h.increaseTablesize(n);
            break;
        case 5:
            h.printtable();
            break;
        default:
            cout << "Enter valid input " << endl
                 << endl;
            break;
        }

    } while (n != 0);

    return 0;
}
