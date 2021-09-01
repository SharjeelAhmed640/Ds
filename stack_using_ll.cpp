#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
};
class stack
{
    Node *top = new Node();

public:
    stack()
    {
        top = NULL;
    }
    stack *push(int data)
    {
        if (this->isFull())
            cout << "Stack overflow" << endl;

        else
        {
            Node *n = new Node();

            n->data = data;
            n->next = this->top;
            this->top = n;
            return this;
        }
    }
    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack underflow" << endl;
        }
        else
        {
            Node *n = this->top;
            this->top = this->top->next;
            int data = n->data;
            free(n);
            return data;
        }
    }
    bool isEmpty()
    {
        if (this->top == NULL)
            return true;

        return false;
    }
    bool isFull()
    {
        Node *p = new Node();
        if (p == NULL)
            return true;

        free(p);
        return false;
    }
    void triversal()
    {
        Node *ptr = new Node();
        ptr = top;
        while (ptr != NULL)
        {
            cout << ptr->data << " ";
            ptr = ptr->next;
        }
        cout << endl;
    }
    int peak(int index)
    {
        Node *t = top;
        for (int i = 0; (i < index - 1 && t != NULL); i++)
        {
            t = t->next;
        }
        if (t != NULL)
        {
            return t->data;
        }
        return -1;
    }
};
int main()
{
    stack S;
    S.push(10);
    S.push(20);
    S.push(30);
    S.push(40);
    S.push(50);
    S.triversal();
    if (S.isEmpty())
        cout << "Stack list is empty" << endl;
    else
    {
        cout << "Stack is not empty" << endl;
    }
    if (S.isFull())
        cout << "Stack list is full" << endl;
    else
    {
        cout << "Stack is not full" << endl;
    }
    cout << "popped element is : " << S.pop() << endl;
    cout << "popped element is : " << S.pop() << endl;
    cout << "popped element is : " << S.pop() << endl;
    // cout << "popped element is : " << S.pop() << endl;
    // cout << "popped element is : " << S.pop() << endl;

    if (S.isEmpty())
        cout << "Stack list is empty" << endl;
    else
    {
        cout << "Stack is not empty" << endl;
    }
    if (S.isFull())
        cout << "Stack list is full" << endl;
    else
    {
        cout << "Stack is not full" << endl;
    }
    cout<<"Peak element : "<<S.peak(02)<<endl;
    S.triversal();
    return 0;
}