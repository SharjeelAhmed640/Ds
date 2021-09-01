#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

class Stack
{
    int top;
    int size;
    int *arr;

public:
    Stack(int size)
    {
        arr = new int[size];
        top = -1;
    }
    bool isEmpty()
    {
        if (top == -1)
            return true;

        return false;
    }
    bool isFull()
    {
        if (top == size - 1)
            return true;

        return false;
    }
    int pop()
    {
        if (this->isEmpty())
        {
            cout << "Stack is empty" << endl;
        }
        else
        {
            int val = arr[top--];
            return val;
        }
    }
    void push(int data)
    {
        if (this->isFull())
        {
            cout << "Can not pop, Stack is already full(Stack overflow)" << endl;
        }
        else
        {
            arr[++top] = data;
        }
    }
    int peak(int index)
    {
        if (top - index + 1 < 0)
        {
            cout << "Invalid peek index" << endl;
        }
        else
            return (arr[top - index + 1]);
    }
    void showStack()
    {

        for (int i = 0; i <= top; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    int StackTop()
    {
        if (this->isEmpty())
            cout << "Stack is empty" << endl;
        else
            return arr[this->top];
    }
    int StackBottom()
    {
        if (this->isEmpty())
            cout << "Stack is empty" << endl;
        else
            return arr[0];
    }
};

int main()
{
    Stack s(5);
    if (s.isEmpty())
        cout << "Stack is empty" << endl;
    else
        cout << "Stack is not empty" << endl;

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.showStack();
    cout << s.peak(3);
    if (s.isEmpty())
        cout << "Stack is empty" << endl;
    else
        cout << "Stack is not empty" << endl;

    return 0;
}