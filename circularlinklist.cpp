#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

class Node
{

public:
    int data;
    Node *next;
    Node()
    {
        next = NULL;

        data = 0;
    }
    Node(int data)
    {
        next = NULL;

        this->data = data;
    }
};
class list
{
    Node *head;

public:
    list(Node *n)
    {
        head = n;
        n->next = head;
    }
    list()
    {
        head = NULL;
    }
    void triversal()
    {
        Node *ptr = head;
        do
        {
            cout << ptr->data << " ";
            ptr = ptr->next;
        } while (ptr != head);
        cout << endl;
    }
    void InsertAtBeg(int data)
    {
        Node *ptr = new Node(data);
        Node *p = head;
        if(head==NULL)
        {
            head=ptr;
            ptr->next=head;
            return;
        }
        if(head==NULL)
        {
            head=ptr;
            return;
        }
        do
        {
            p = p->next;
        } while (p->next != head);
        p->next = ptr;
        ptr->next = head;
        head = ptr;
    }
    void insertAtEnd(int data)
    {
        Node *ptr = new Node(data);
        Node *p = head;
        if(head==NULL)
        {
            head=ptr;
            ptr->next=head;
            return;
        }
        if(head==NULL)
        {
            head=ptr;
            return;
        }
        do
        {
            p = p->next;
        } while (p->next != head);
        p->next = ptr;
        ptr->next = head;
    }
    void insertAtINdex(int data, int index)
    {
        int i = 0;
        Node *temp = head;
        Node *ptr = new Node(data);
      if(head==NULL)
        {
            head=ptr;
            ptr->next=head;
            return;
        }
        if(head==NULL)
        {
            head=ptr;
            return;
        }
        if (index == 0)
        {
            this->InsertAtBeg(data);
            return;
        }
        do
        {
            if (index == (i + 1))
                break;
            i++;
            temp = temp->next;
        } while (temp->next != head);
        if (index != (i + 1))
            return;
        ptr->next = temp->next;
        temp->next = ptr;
    }
    void delhead()
    {
        Node *temp = head;
        Node *ptr = head->next;
        do
        {
            temp = temp->next;
            ptr = ptr->next;
        } while (temp->next != head);
        temp->next=ptr->next;
        head=ptr->next;
        delete ptr;
    }
    void delNode(int index)
    {
        int i = 0;
        Node *temp = head;
        Node *ptr = head->next;
        if (index == 0)
        {
            delhead();
            return;
        }
        do
        {
            if (index == (i + 1))
                break;
            i++;
            temp = temp->next;
            ptr = ptr->next;
        } while (temp->next != head);
        if (index != (i + 1))
            return;
        temp->next = ptr->next;
        delete (ptr);
    }
};
int main()
{

    Node n(4);
    cout<<"List created"<<endl;
    list l(&n);
    l.triversal();

    cout<<"insert 5 at begining"<<endl;
    l.InsertAtBeg(5);
    l.triversal();

    cout<<"insert 0 at begining"<<endl;
    l.InsertAtBeg(0);
    l.triversal();

    cout<<"insert 100 at end"<<endl;
    l.insertAtEnd(100);
    l.triversal();

    cout<<"insert 99 at index 4"<<endl;
    l.insertAtINdex(99, 4);
    l.triversal();

    cout<<"deleting Node at index 4"<<endl;
    l.delNode(3);
    l.triversal();
    return 0;
}