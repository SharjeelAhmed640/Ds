#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

class Node
{
    int data;
    Node *next;

public:
    Node()
    {
        data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
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
    void MergeSort(Node **head)
    {
        Node *newhead = *head;
        Node *a;
        Node *b;

        if ((newhead == NULL) || (newhead->next == NULL))
        {
            return;
        }
        // newhead->triversal(newhead);
        MidNode(newhead, &a, &b);
        MergeSort(&a);
        MergeSort(&b);
        // cout << "a : ";
        // a->triversal(a);
        // cout << "b : ";
        // b->triversal(b);

        *head = Mergell(a, b);
    }

    Node *Mergell(Node *a, Node *b)
    {
        Node *p1 = a;
        Node *p2 = b;
        Node *dummy = new Node(-1);
        Node *p3 = dummy;

        while (p1 != NULL && p2 != NULL)
        {
            if (p1->data < p2->data)
            {
                p3->next = p1;
                p1 = p1->next;
            }
            else
            {
                p3->next = p2;
                p2 = p2->next;
            }
            p3 = p3->next;
        }
        while (p1 != NULL)
        {
            p3->next = p1;
            p1 = p1->next;
            p3 = p3->next;
        }
        while (p2 != NULL)
        {
            p3->next = p2;
            p2 = p1->next;
            p3 = p3->next;
        }
        return dummy->next;
    }

    void MidNode(Node *head, Node **sTOm, Node **mTOe)
    {
        Node *fast;
        Node *slow;
        slow = head;
        fast = head->next;

        while (fast != NULL && fast->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
        }

        *sTOm = head;
        *mTOe = slow->next;
        slow->next = NULL;
    }
};

int main()
{
    Node *head, *second, *third;
    head = new Node(10);
    head = head->insertAtBeginning(4);
    head = head->insertAtBeginning(14);
    head = head->insertAtBeginning(2);
    head = head->insertAtBeginning(0);
    head = head->insertAtBeginning(49);
    head->triversal(head);
    head->MergeSort(&head);
    head->triversal(head);
}