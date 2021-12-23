#include <iostream>
#include <iomanip>
#include <cstring>
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
        if (head == NULL)
        {
            head = ptr;
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
        if (head == NULL)
        {
            head = ptr;
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
        if (head == NULL)
        {
            head = ptr;
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
    void delatkey(int key)
    {
        if (head == NULL)
            return;
        if (key == head->data)
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
            if (ptr->data = key)
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
        if (ptr->data = key)
        {
            temp->next->prev = ptr;
            ptr->next = temp->next;
            delete (temp);
            return;
        }

        {
            cout << "Not found" << endl;
        }
    }
    void search(int key)
    {
        Node *temp = head;
        while (temp != NULL)
        {
            if (key == temp->data)
            {
                cout << "Found" << endl;
                return;
            }

            temp = temp->next;
        }
        cout << "Not found" << endl;
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
            cout << temp->data << " ";
            temp = temp->prev;
        }
        cout << endl;
    }
    void triversal()
    {
        Node *temp = head;
        if (temp == 0)
            cout << "-";
        while (temp != NULL)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << endl;
    }
};
class HashTable
{
    int noofelements;
    DoubleList l[10];

public:
    HashTable()
    {
        noofelements = 0;
        for (int i = 0; i < 10; i++)
        {
            l[i] = NULL;
        }
    }
    int hashfunc(int key)
    {
        return (key * 7) % 10;
    }
    void insert(int key)
    {
        int index = hashfunc(key);
        l[index].insertAtBeg(key);
        noofelements++;
    }
    void delkey(int key)
    {
        int index = hashfunc(key);
        l[index].delatkey(key);
        noofelements--;
    }
    void search(int key)
    {
        int index = hashfunc(key);
        l[index].search(key);
    }
    void printtable()
    {
        for (int i = 0; i < 9; i++)
        {

            l[i].triversal();
        }
        cout << endl
             << endl;
    }
};
int main()
{
    HashTable h;
    int n;
    do
    {
        cout << "Press 1 to insert key" << endl
             << "Press 2 to delete key" << endl
             << "Press 3 to search key" << endl

             << "Press 5 to print table " << endl
             << "Press 0 to exit" << endl;
        cin >> n;
        if (!n)
            break;
        switch (n)
        {
        case 1:
            cout << "Enter key to insert : ";
            cin >> n;
            h.insert(n);
            break;
        case 2:
            cout << "Enter key to delete : ";
            cin >> n;
            h.delkey(n);
            break;
        case 3:
            cout << "Enter key to search : ";
            cin >> n;
            h.search(n);
            break;
        case 5:
            h.printtable();
            break;
        default:
            cout << "Enter valid input " << endl
                 << endl;
            break;
        }

    } while (n != 0);

    return 0;
}