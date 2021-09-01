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
    void enQueueB(int val)
    {
        if (this->isFull())
            cout << "Queue is full" << endl;
        else
        {
            this->b++;
            this->arr[this->b] = val;
        }
    }
    void enQueueF(int val)
    {
        if (this->isFull())
            cout << "Queue is full" << endl;
        else
        {
            if (this->f == this->b)
            {
                this->b++;
                this->arr[this->b] = val;
                cout << b << "else's if " << endl;
            }
            else
            {
                int i;
                for (i = b; i >= 0; i--)
                {
                    this->arr[i + 1] = this->arr[i];
                    // cout <<i<<" "<< arr[i + 1] << " " << arr[i] << endl;
                    // if(i==0)
                    // break;
                }
                b++;
                this->arr[0] = val;
            }
        }
    }
    T deQueueF()
    {
        T a = -1;
        if (this->isEmpty())
            cout << "Queue is Empty" << endl;
        else
        {
            this->f++;
            a = this->arr[this->f];
            f--;
            for (int i = 0; i < size - 1; i++)
            {
                this->arr[i] = this->arr[i + 1];
            }
            b--;
        }
        return a;
    }
    T deQueueB()
    {
        T a = -1;
        if (this->isEmpty())
            cout << "Queue is Empty" << endl;
        else
        {
            a = this->arr[this->b];
            this->b--;
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
        for (int i = f + 1; i < b + 1; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
int main()
{
    queue<int> *Q = new queue<int>(6);
    //cout << Q->isEmpty();
    Q->enQueueF(1);
    Q->enQueueF(2);
    Q->enQueueF(3);
    Q->print();
    Q->enQueueB(4);
    Q->enQueueB(5);
    // Q->enQueueB(2);
    // Q->enQueueB(3);
    Q->print();
    // Q->enQueueB(4);
    // Q->enQueueB(5);
    // Q->print();
     cout << Q->deQueueF()<<endl;
    // Q->enQueueB(100);
     Q->print();
     cout << Q->deQueueB()<<endl;
     Q->print();
    cout << Q->isFull();
    return 0;
}