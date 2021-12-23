#include <iostream>
#include <cmath>
using namespace std;

class HashTable
{
protected:
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
    int virtual hashfunc(int key) = 0;
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
class divHashtable : public HashTable
{
public:
    int hashfunc(int key)
    {
        return key % size;
    }
};
class mulHashtable : public HashTable
{
public:
    int hashfunc(int key)
    {
        return floor(size * key);
    }
};
class middsqrHashtable : public HashTable
{
public:
    int middleDigit(int n)
    {

        int digits = (int)log10(n) + 1;

        n = (int)(n / pow(10, digits / 2)) % 10;

        return n;
    }
    int hashfunc(int key)
    {
        int value = key * key;
        int middle_value = middleDigit(value);
        return middle_value;
    }
};
class foldingHashtable : public HashTable
{

    int hashfunc(int k)
    {
        return k;
    }
public:
    int hashfunc(int value1, int value2, int value3)
    {
        return value1 + value2 + value3;
    }
};
class radixHashtable : public HashTable
{
public:
    int base_number(int key)
    {
        int n = 0;
        for (int i = 0; i < 4; i++)
        {
            n += key / 10;
            key /= 10;
        }
        return n;
    }
    int hashfunc(int value)
    {
        int result = base_number(value);
        return result;
        // return last4 digit of result;
    }
};
int main()
{
    divHashtable dh;
    dh.insert(1);
    dh.insert(22);
    dh.insert(41);
    cout << "Printing division hash table :  ";
    dh.printtable();

    mulHashtable mulh;
    mulh.insert(1);
    mulh.insert(22);
    mulh.insert(41);
    cout << "Printing multiply hash table :  ";
    mulh.printtable();

    middsqrHashtable msh;
    msh.insert(1);
    msh.insert(22);
    msh.insert(41);
    cout << "Printing mid square hash table :  ";
    msh.printtable();

    foldingHashtable fh;
    fh.insert(1);
    fh.insert(22);
    fh.insert(41);
    cout << "Printing folding hash table :  ";
    fh.printtable();

    radixHashtable rh;
    rh.insert(1);
    rh.insert(22);
    rh.insert(41);
    cout << "Printing radix hash table :  ";
    rh.printtable();
    return 0;
}