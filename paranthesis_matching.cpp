#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;
class Node
{
public:
    char data;
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
    char pop()
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
    char peak(int index)
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
bool paranthesisMatching(string str)
{
    stack *st = new stack();
    for (int i = 0; i<str.length(); i++)
    {
        if (str[i] == '(')
        {
            st->push('(');
        }
        else if (str[i] == ')')
        {
            if (st->isEmpty())
                return false;
            st->pop();
        }
    }
    return st->isEmpty();
}
int main()
{
    string expres = "(8*6+((5/9))";
    if (paranthesisMatching(expres))
        cout << "paranthesis matching" << endl;
    else
        cout << "paranthesis not matching" << endl;
    return 0;
}