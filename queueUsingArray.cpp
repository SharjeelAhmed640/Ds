#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;
template <class T = int>
class queue
{
    int size, f, b;
    T *arr;

public:
    queue()
    {
    }
    queue(int s)
    {
        this->size = s;
        f = -1;
        b = -1;
        arr = new T[s];
    }
    void enQueue(int val)
    {
        if (this->isFull())
            cout << "Queue is full" << endl;
        else
        {
            this->b++;
            this->arr[this->b] = val;
        }
    }
    T deQueue()
    {
        T a = -1;
        if (this->isEmpty())
            cout << "Queue is Empty" << endl;
        else
        {
            this->f++;
            a = this->arr[this->f];
            f--;
            for (int i = 0; i < size-1; i++)
            {
                this->arr[i]=this->arr[i+1];
            }
            b--;
            
        }
        return a;
    }
    bool isFull()
    {
        if (this->b == this->size - 1)
            return true;
        return false;
    }
    bool isEmpty()
    {
        if (this->b == this->f)
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
    queue<int> *Q = new queue<int>(4);
    //cout << Q->isEmpty();
    Q->enQueue(1);
    Q->enQueue(10);
    Q->enQueue(10);
    Q->enQueue(100);
    cout << Q->deQueue()<<endl;
    Q->enQueue(100);
    Q->print();
    cout << Q->deQueue()<<endl;
    cout << Q->isFull();
    return 0;
}