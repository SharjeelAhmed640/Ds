#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;
template <class T = int>
class circularQueue
{
    int size, f, r;
    T *arr;

public:
    circularQueue()
    {
    }
    circularQueue(int s)
    {
        this->size = s;
        f = 0;
        r = 0;
        arr = new T[s];
    }
    void enQueue(int val)
    {
        if (this->isFull())
            cout << "Queue is full" << endl;
        else
        {
            this->r=(this->r+1)%this->size;
            this->arr[this->r] = val;
        }
    }
    T deQueue()
    {
        T a = -1;
        if (this->isEmpty())
            cout << "Queue is Empty" << endl;
        else
        {
            this->f=(this->f+1)%this->size;
            a = this->arr[this->f];
            this->f=(this->f-1)%this->size;
            for (int i = 0; i < size - 1; i++)
            {
                this->arr[i] = this->arr[i + 1];
            }
            this->r=(this->r-1)%this->size;
        }
        return a;
    }
    bool isFull()
    {
        if (((this->r + 1) % this->size) == (this->f))
            return true;
        return false;
    }
    bool isEmpty()
    {
        if (this->r == this->f)
            return true;
        return false;
    }
    void print()
    {
        for (int i = f + 1; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
int main()
{
    circularQueue<int> *Q = new circularQueue<int>(2);
    //cout << Q->isEmpty();
    Q->enQueue(1);
    Q->enQueue(10);
    Q->enQueue(10);
    Q->enQueue(100);
   // cout << Q->deQueue() << endl;
    Q->enQueue(100);
    Q->print();
    cout << Q->deQueue() << endl;
    cout << Q->isFull();
    return 0;
}