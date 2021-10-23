#include <iostream>
#include <cstring>
#include <cmath>

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
    Node *insertAtAfter(Node *prevNode,int data)
    {
        Node *ptr = new Node();
        Node *temp = new Node();
        temp = this;
        ptr->data=data;
        ptr->next=prevNode->next;
        prevNode->next=ptr;
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
};

int main()
{
    Node *head, *second, *third;
    head = new Node();
    second = new Node();
    third = new Node();

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = NULL;

    head->triversal(head);

    //insert 99 at beginning
    head = head->insertAtBeginning(99);
    head->triversal(head);

    //insert after index 4
    head = head->insertAtIndex(66, 2);
    head->triversal(head);

    //insert at the end
    head = head->insertAtEnd(100);
    head->triversal(head);

    //inseter after 2nd node
    head=head->insertAtAfter(second,55);
    head->triversal(head);
    return 0;
}