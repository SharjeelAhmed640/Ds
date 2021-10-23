#include <iostream>
#include <iomanip>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node()
    {
        next = NULL;
        prev = NULL;
        data = 0;
    }
    Node(int data)
    {
        next = NULL;
        prev = NULL;
        this->data = data;
    }
    // ~Node()
    // {
    //     delete next;
    //     delete prev;
    // }
};
class DoubleList
{
    Node *head;

public:
    DoubleList(Node *n)
    {
        head = n;
    }
    DoubleList()
    {
        head = NULL;
    }
    void insertAtEnd(int data)
    {
        Node *temp = head;
        Node *ptr = new Node(data);
        if(head==NULL)
        {
            head=ptr;
            return;
        }
        while (temp->next != NULL)
            temp = temp->next;

        temp->next = ptr;
        ptr->next = NULL;
        ptr->prev = temp;
    }
    void insertAtBeg(int data)
    {
        Node *temp = head;
        Node *ptr = new Node(data);
        if(head==NULL)
        {
            head=ptr;
            return;
        }
        temp->prev = ptr;
        ptr->next = temp;
        ptr->prev = NULL;
        head = ptr;
    }
    void insertAtKey(int data, int key)
    {
        Node *temp = head;
        Node *ptr = new Node(data);
        if(head==NULL)
        {
            head=ptr;
            return;
        }
        int i = 0;
        if (key == 0)
        {
            this->insertAtBeg(data);
            return;
        }
        while (temp != NULL)
        {
            if ((i + 1) == key)
                break;

            temp = temp->next;
            i++;
        }
        if (temp->next == NULL)
        {
            this->insertAtEnd(data);
            return;
        }
        ptr->next = temp->next;
        temp->next->prev = ptr;
        temp->next = ptr;
        ptr->prev = temp;
    }
    void delHead()
    {
        Node *temp = head;
        Node *ptr = head;
        temp = temp->next;
        temp->prev = NULL;
        delete (ptr);
        head = temp;
    }
    void delTail()
    {
        Node *temp = head;
        Node *ptr = head;
        temp = temp->next;

        while (temp->next != NULL)
        {
            temp = temp->next;
            ptr = ptr->next;
        }
        ptr->next = NULL;
        delete temp;
    }
    void delAtindex(int index)
    {
        if (head == NULL)
            return;
        if (index == 0)
        {
            this->delHead();
            return;
        }
        Node *temp = head;
        Node *ptr = head;
        temp = temp->next;
        int i = 0;
        while (temp != NULL)
        {
            if ((i + 1) == index)
                break;
            temp = temp->next;
            ptr = ptr->next;
            i++;
        }
        if (temp->next == NULL)
        {
            this->delTail();
            return;
        }
        if ((i + 1) == index)
        {
            temp->next->prev = ptr;
            ptr->next = temp->next;
            delete (temp);
            return;
        }

        {
            cout << "Unvalid index" << endl;
        }
    }
    void triversal()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void printrev()
    {
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        while (temp != NULL)
        {
            cout << temp->data<<" ";
            temp = temp->prev;
        }
        cout<<endl;
    }
    DoubleList &concatinate(DoubleList *l)
    {
        Node *l1=head;
        Node *l2=l->head;
        while(l1->next!=NULL)
        l1=l1->next;

        l1->next=l2;
        l2->prev=l1;
        while(l1->prev!=NULL)
        l1=l1->prev;
        return *this;
    }
};

int main()
{
    Node n(1);
    DoubleList l1,l2,l3;
    l1.insertAtEnd(1);
    l1.insertAtEnd(2);
    l1.insertAtEnd(3);
    l1.insertAtEnd(4);
    l1.insertAtEnd(5);
    cout<<"list l1 : ";
    l1.triversal();

    l2.insertAtEnd(6);
    l2.insertAtEnd(7);
    l2.insertAtEnd(8);
    l2.insertAtEnd(9);
    l2.insertAtEnd(10);
    cout<<"list l2 : ";
    l2.triversal();

    cout<<"After concatinating l1 and l2 in l3 : ";
    l3=l1.concatinate(&l2);
    l3.triversal();

    return 0;
}