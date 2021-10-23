#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

class Node
{
    int data;
    Node *next;

public:
    Node(int data)
    {
        this->next = NULL;
        this->data = data;
    }
    Node()
    {

        this->next = NULL;
        this->data = 0;
    }

    void triversal()
    {
        Node *ptr = this;
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

    Node *DeleteHead()
    {
        if (this != NULL)
        {
            Node *head = this;
            Node *ptr = this;
            head = head->next;
            free(ptr);
            return head;
        }
        return this;
    }
    Node *DeleteAtIndex(int index)
    {
        if (this == NULL)
            return this;
        Node *ptr = this;
        Node *temp;
        bool flag = false;
        int counter = 0;
        Node *t = this;
        if (index == 0)
        {
            return this->DeleteHead();
        }
        while (t != NULL)
        {
            if (counter == index)
            {
                flag = true;
                break;
            }
            counter++;
        }
        if (flag != true)
        {
            cout << "Out of index" << endl;
            return this;
        }
        for (int i = 0; i < index - 1; i++)
        {
            ptr = ptr->next;
        }
        if (ptr->next == NULL)
        {
            return this->DeleteLastNode();
        }
        temp = ptr->next;
        ptr->next = temp->next;
        free(temp);
        return this;
    }

    Node *DeleteLastNode()
    {
        if (this == NULL)
            return this;
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
        if (this == NULL)
            return this;
        Node *ptr = this;
        Node *temp = this->next;
        if (ptr->data == value)
            return this->DeleteHead();
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

    Node *sortEvenOdd()
    {
        Node *e = NULL, *o = NULL, *R = NULL;
        Node *temp = this;
        Node *head = this;
        Node *next = NULL;
        while (temp != NULL)
        {
            if (temp->data % 2 == 0)
            {
                e = e->insertAtBeginning(temp->data);
            }
            else
            {
                o = o->insertAtBeginning(temp->data);
            }
            temp = temp->next;
        }
        Node *oh = o;
        Node *eh = e;
        while (o != NULL)
        {
            R = R->insertAtBeginning(o->data);
            o = o->next;
        }
        while (e != NULL)
        {
            R = R->insertAtBeginning(e->data);
            e = e->next;
        }
        while (oh != NULL)
        {
            next = oh->next;
            delete oh;
            oh = next;
        }
        while (eh != NULL)
        {
            next = eh->next;
            delete eh;
            eh = next;
        }
        while (head != NULL)
        {
            next = head->next;
            delete head;
            head = next;
        }
        return R;
    }
};

int main()
{
    int data, Index;
    Node *List;
    cout << "List created enter head node data : ";
    cin >> data;
    List = new Node(data);

    int choice;
    while (choice != 0)
    {
        cout << "Press 1 for inserting a node at Beginning"
             << endl

             << "Press 4 for deleting head node"
             << endl
             << "Press 5 for delete at index"
             << endl
             << "Press 6 for delete last node"
             << endl
             << "Press 7 for delete with key"
             << endl
             << "Press 8 for printing list"
             << endl
             << "Press 9 for even odd sorting" << endl

             << "Press 0 for end " << endl
             << endl;
        cin >> choice;
        switch ((choice))
        {
        case 1:
            cout << "Enter Data : ";
            cin >> data;
            List = List->insertAtBeginning(data);
            break;

        case 4:
            List = List->DeleteHead();
            break;
        case 5:
            cout << "Enter Index : ";
            cin >> Index;
            List = List->DeleteAtIndex(Index);
            break;
        case 6:
            List = List->DeleteLastNode();
            break;
        case 7:
            cout << "Enter Data : ";
            cin >> data;
            List = List->DeleteWithKey(data);
            break;
        case 8:
            List->triversal();
            break;
        case 9:
            List = List->sortEvenOdd();

        case 0:
            break;
        default:
            cout << "Enter valid input" << endl;
            break;
        }
    }

    return 0;
}