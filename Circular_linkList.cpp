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
        do
        {
            cout << " " << ptr->data;
            ptr = ptr->next;
        }while (ptr != this);
        cout << endl;
    }
    Node *insertAtBeginning(int data)
    {
        Node *ptr;
        ptr = new Node();
        ptr->data = data;
        Node *p = this->next;
        while(p->next!=this)
        {
            p=p->next;
        }// at this point p points to last node of circular ll
        p->next=ptr;
        ptr->next=this;
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
        Node *temp=this->next;
        while(temp->next!=NULL)
        {
            ptr=ptr->next;
            temp=temp->next;
        }
        ptr->next=NULL;
        free(temp);
        return this;
    }

    Node *DeleteWithKey(int value)
    {
        Node *ptr = this;
        Node *temp=this->next;
        while(temp->data!=value && temp->next != NULL)
        {
            ptr=ptr->next;
            temp=temp->next;
        }
        if(temp->data==value)
        {
            ptr->next=temp->next;
            free(temp);
        }
        return this;
    }
};

int main()
{
    Node *head, *second, *third, *fourth;
    head = new Node();
    second = new Node();
    third = new Node();
    fourth = new Node();

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = fourth;

    fourth->data = 4;
    fourth->next = head;

    head->triversal(head);

    //insert 99 at beginning
    head = head->insertAtBeginning(99);
    head->triversal(head);


    // //del head
    // head = head->DeleteHead();
    // head->triversal(head);

    // //del node at index 2
    // head = head->DeleteAtIndex(2);
    // head->triversal(head);

    // //del last node
    // head = head->DeleteLastNode();
    // head->triversal(head);

    // //del node having value 2
    // head=head->DeleteWithKey(2);
    // head->triversal(head);

   return 0;
}