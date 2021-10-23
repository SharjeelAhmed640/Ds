#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;
template <class T>
class Node
{
public:
    T data;
    Node *next;
    Node *extra;

    int key;
    Node()
    {
        data = 0;
        next = NULL;
        extra = NULL;
    }
    Node(T data)
    {
        this->data = data;
    }
};
template <class T>
class list
{
    static int count;

    Node<T> *head;

public:
    list(Node<T> *n)
    {
        n->key = count;
        head = n;
        count++;
        //head->key = count;
    }
    list(T data)
    {
        head = new Node<T>();
        head->data = data;
        count++;
        head->key = count;
    }
    list()
    {
        head = NULL;
        count++;
        head->key = count;
    }
    void triversal()
    {
        Node<T> *ptr = head;
        while (ptr != NULL)
        {
            cout << " " << ptr->data;
            ptr = ptr->next;
        }
        cout << endl;
    }
    void triversalkeyprint()
    {
         Node<T> *ptr = head;
        while (ptr != NULL)
        {
            cout << " " << ptr->key;
            ptr = ptr->next;
        }
        cout << endl;
    }
    void chainTriversal()
    {
        Node<T> *ptr = head;
        while (ptr != NULL)
        {
            cout << ptr->data << " ";
            if (ptr->extra != NULL)
                cout << ptr->extra->data << " ";
            ptr = ptr->next;
        }
        cout << endl;
    }
    void chainTriversalkeyprint()
    {
        Node<T> *ptr = head;
        while (ptr != NULL)
        {
            cout << ptr->key << " ";
            if (ptr->extra != NULL)
                cout << ptr->extra->key << " ";
            ptr = ptr->next;
        }
        cout << endl;
    }
    Node<T> *insertAtBeginning(T data)
    {
        Node<T> *ptr = new Node<T>();
        ptr->next = head;
        ptr->data = data;
        ptr->key = count;
        count++;
        head = ptr;
        set();
        return ptr;
    }
    void set()
    {
        Node<T> *head = this->head, *next = head->next;
        while (next != NULL)
        {
            if (next->key % 3 == 0)
            {
                next->extra = head;
            }
            head = head->next;
            next = next->next;
        }
    }
};
template <typename T>
int list<T>::count=1;
int main()
{
    Node<char> n;
    n.data = 'a';
    list<char> l1(&n);
    l1.insertAtBeginning('b');
    l1.insertAtBeginning('c');
    l1.insertAtBeginning('d');
    l1.insertAtBeginning('e');
    cout<<"Normal triversal"<<endl;
    l1.triversal();
    cout<<"Their key"<<endl;
    l1.triversalkeyprint();
    cout<<"Triversal of every next and extra pointer"<<endl;
    l1.chainTriversal();
    cout<<"Their key"<<endl;
    l1.chainTriversalkeyprint();

    return 0;
}