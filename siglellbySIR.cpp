#include <iostream>

using namespace std;

class Node
{
public:
    int info;
    Node *next;

    Node()
    {
        next = 0;
    }

    Node(int value, Node *ptr = 0)
    {
        info = value;
        next = ptr;
    }
};

class SingleLinkList
{
private:
    Node *head, *tail;

public:
    SingleLinkList()
    {
        head = tail = 0;
    }

    void AddToHead(int value)
    {
        head = new Node(value, head);
        if (tail == 0)
        {
            tail = head;
        }
    }

    void AddAfter(int info, int val = 0)
    {
        if (isEmpty())
        {
            AddToHead(val);
        }
        else if (head->info == info)
        {
            Node *temp = new Node(val);
            temp->next = head->next;
            head->next = temp;
        }
        else
        {
            Node *temp;
            for (temp = head; temp != 0 && !(temp->info == info); temp = temp->next)
                ;
            if (temp != 0)
            {
                Node *n = new Node(val);
                n->next = temp->next;
                temp->next = n;
            }
            else
            {
                AddToTail(val);
            }
        }
    }

    void AddToTail(int value)
    {
        if (tail != 0)
        {
            tail->next = new Node(value);
            tail = tail->next;
        }
        else
        {
            head = tail = new Node(value);
        }
    }

    int DeleteFromHead()
    {
        int val = head->info;

        Node *temp = head;

        // Only One Item in the List
        if (head == tail)
        {
            head = tail = 0;
        }
        else
        {
            head = head->next;
        }

        delete temp;
        return val;
    }

    int DeleteFromTail()
    {
        int value = tail->info;
        if (head == tail)
        {
            delete head;
            head = tail = 0;
        }
        else
        {
            Node *temp;
            for (temp = head; temp->next != tail; temp = temp->next)
                ;
            delete tail;
            tail = temp;
            tail->next = 0;
        }

        return value;
    }

    void DeleteNode(int val)
    {
        if (head != 0)
        {
            if (head == tail && val == head->info)
            {
                delete head;
                head = tail = 0;
            }
            else if (val == head->info)
            {
                Node *temp = head;
                head = head->next;
                delete temp;
            }
            else
            {
                Node *pred, *temp;
                for (pred = head, temp = head->next;
                     temp != 0 && !(temp->info == val);
                     pred = pred->next, temp = temp->next)
                    ;
                if (temp != 0)
                {
                    pred->next = temp->next;

                    if (temp == tail)
                        tail = pred;

                    delete temp;
                }
            }
        }
        else
        {
            cout << "\nlist is Empty...!" << endl;
        }
    }

    void PrintList()
    {
        if (isEmpty())
        {
            cout << "List is Empty..." << endl;
        }
        else
        {
            Node *temp;
            cout << endl;
            for (temp = head; temp != 0; temp = temp->next)
                cout << temp->info << "\t";
        }
    }

    void ReverseList()
    {
        reverse(head);
    }

    void reverse(Node *node)
    {
        if (node == NULL)
        {
            head = 0;
            tail = 0;
        }

        else
        {
            reverse(node->next);
            AddToTail(node->info);
        }
    }

    bool ValueExist(int val) const
    {
        Node *temp;
        for (temp = head; temp != 0 && !(temp->info == val); temp = temp->next)
            ;

        return temp != 0;
    }

    ~SingleLinkList()
    {
        for (Node *p; !isEmpty();)
        {
            p = head->next;
            delete head;
            head = p;
        }
    }

    int isEmpty()
    {
        return head == 0;
    }
};

int main()
{
    SingleLinkList list;
    list.AddToHead(1);
    list.AddToHead(2);
    list.AddToHead(3);
    list.AddToHead(4);
    list.AddToHead(5);
    list.AddToHead(6);
    list.AddToHead(7);

    list.PrintList();

    list.AddAfter(4, 12);
    list.AddAfter(7, 9);

    list.PrintList();
    cout << endl
         << "REVERSE is belwo" << endl;

    list.ReverseList();

    list.PrintList();
    return 0;
}