#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;
bool match(char a, char b);
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
    char StackTop()
    {
        if (this->isEmpty())
            cout << "Stack is empty" << endl;
        else
            return this->top->data;
    }
};
bool paranthesisMatching(string str)
{
    stack *st = new stack();
    char pop_ch;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '(' || str[i] == '{' || str[i] == '[')
        {
            st->push(str[i]);
        }
        else if (str[i] == ')' || str[i] == ']' || str[i] == '}')
        {
            if (st->isEmpty())
                return false;
            pop_ch = st->pop();
            if (!match(pop_ch, str[i]))
                return 0;
        }
    }
    return st->isEmpty();
}
bool match(char a, char b)
{
    if ((a == '(' && b == ')') || (a == '[' && b == ']') || (a == '{' && b == '}'))
        return true;

    return false;
}
int main()
{
    string expres ;
    cout<<"Enter expresstion : ";
    getline(cin,expres);
    if (paranthesisMatching(expres))
        cout << "paranthesis are balanced" << endl;
    else
        cout << "paranthesis are not balanced" << endl;
    return 0;
}