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
bool isOperator(char ch)
{
    if (ch == '/' || ch == '*' || ch == '-' || ch == '+')
        return true;
    return false;
}
int precidence(char ch)
{
    if (ch == '*' || ch == '/')
        return 3;
    else if (ch == '+' || ch == '-')
        return 2;
    else
        return 0;
}
string InfixToPostFix(string infix)
{
    stack s;
    string postfix;
    int i = 0, j = 0;
    for (i = 0; i < infix.length(); i++)
    {
        if (!isOperator(infix[i]))
        {
            postfix += infix[i];
            
            cout<<postfix[j];
        }
        else
        {
            if (precidence(infix[i]) > precidence(s.StackTop()))
            {
                s.push(infix[i]);
            }
            else
            {
                postfix += s.pop();
               
            }
            
        }
        
    }
    while (s.isEmpty())
    {
        postfix += s.pop();
    }
    cout<<postfix;
    return postfix;
}
int main()
{
    string infix="a+bc+f";
    cout<<"Infix is : "<<infix<<" After converting it to postfix : "<<InfixToPostFix(infix)<<endl;
}