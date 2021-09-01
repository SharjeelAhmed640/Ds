#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;
class Node
{
public:
    int data;
    Node *next;

    void triversal(Node *ptr)
    {
        while (ptr != NULL)
        {
            cout << " " << ptr->data;
            ptr = ptr->next;
        }
        cout << endl;
    }
    Node *insertAtBeginning(int data)
    {
        Node *ptr;
        ptr = new Node();
        ptr->next = this;
        ptr->data = data;
        return ptr;
    }
    Node *insertAtEnd(int data)
    {
        Node *ptr = new Node();
        Node *temp = new Node();
        temp = this;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = ptr;
        ptr->next = NULL;
        ptr->data = data;
        return this;
    }
    Node *insertAtAfter(Node *prevNode, int data)
    {
        Node *ptr = new Node();
        Node *temp = new Node();
        temp = this;
        ptr->data = data;
        ptr->next = prevNode->next;
        prevNode->next = ptr;
        return this;
    }
    Node *insertAtIndex(int data, int index)
    {
        Node *ptr;
        Node *Temp;
        ptr = new Node();
        Temp = this;

        int i = 0;
        while (i != index - 1)
        {
            Temp = Temp->next;
            i++;
        }
        ptr->next = Temp->next;
        Temp->next = ptr;
        ptr->data = data;
        return this;
    }
    Node *DeleteHead()
    {
        Node *head = this;
        Node *ptr = this;
        head = head->next;
        free(ptr);
        return head;
    }
    Node *DeleteAtIndex(int index)
    {
        Node *ptr = this;
        Node *temp;
        for (int i = 0; i < index - 1; i++)
        {
            ptr = ptr->next;
        }
        temp = ptr->next;
        ptr->next = temp->next;
        free(temp);
        return this;
    }
    Node *DeleteLastNode()
    {
        Node *ptr = this;
        Node *temp = this->next;
        while (temp->next != NULL)
        {
            ptr = ptr->next;
            temp = temp->next;
        }
        ptr->next = NULL;
        free(temp);
        return this;
    }

    Node *DeleteWithKey(int value)
    {
        Node *ptr = this;
        Node *temp = this->next;
        while (temp->data != value && temp->next != NULL)
        {
            ptr = ptr->next;
            temp = temp->next;
        }
        if (temp->data == value)
        {
            ptr->next = temp->next;
            free(temp);
        }
        return this;
    }
};
class Queue
{
    Node *r;
    Node *f;

public:
    Queue()
    {
        r = NULL;
        f = NULL;
    }
    void enqueue(int data)
    {
        Node *n = new Node();
        if (this->isFull())
            cout << "Queue is full" << endl;
        else
        {
            n->data = data;
            n->next = NULL;
            if (this->isEmpty())
            {
                this->f = n;
                this->r = n;
            }
            else
            {
                this->r->next = n;
                this->r = n;
            }
        }
    }
    int dequeue()
    {
        Node *n = new Node();
        int val = -1;
        if (this->isEmpty())
            cout << "Queue is Empty" << endl;
        else
        {
            n = this->f;
            this->f = this->f->next;
            val = n->data;
            free(n);
        }
        return val;
    }
    bool isEmpty()
    {
        if (this->f == NULL)
            return true;
        return false;
    }
    bool isFull()
    {
        Node *n = new Node();
        if (n == NULL)
            return true;
        else
        {
            free(n);
            return false;
        }
    }
    void triversal()
    {
        Node *ptr = this->f;
        cout << "Queue Elements are : ";
        while (ptr != NULL)
        {
            cout << " " << ptr->data;
            ptr = ptr->next;
        }
    }
};
int main()
{
    Queue q;
    q.enqueue(10);
    q.enqueue(10);
    q.enqueue(10);
    q.enqueue(10);
    cout<<q.dequeue()<<endl;
    q.triversal();
    return 0;
}