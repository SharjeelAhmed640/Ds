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
        data = 0;
        next = NULL;
    }
    Node(int d)
    {
        data = d;
        next = NULL;
    }
};
class List
{
    Node *head;

public:
    List()
    {
        head = NULL;
    }
    void insert(int d)
    {
        if (head == NULL)
        {
            head = new Node(d);
            return;
        }
        Node *temp = new Node(d);
        temp->next = head;
        head = temp;
    }
    void DelKey(int k)
    { // 1 2 3 4 5 6
        Node *temp;
        if (head == NULL)
            return;
        if (head->next == NULL && head->data == k)
        {
            temp = head;
            head = NULL;
            delete temp;
            return;
        }
        Node *tr = head;
        while (tr != NULL)
        {
            if (tr->data == k)
                break;
            temp = tr;
            tr = tr->next;
        }
        if (tr == head)
        {
            temp = head;
            tr = tr->next;
            delete temp;
            head = tr;
            return;
        }
        temp = tr->next;
        delete tr;
    }
    bool search(int k)
    {
        Node *temp = head;
        while (temp != NULL)
        {
            if (temp->data == k)
                return true;
            temp = temp->next;
        }
        return false;
    }
    void triversal()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};
class HashTable
{
    List *arr;
    int size;

public:
    HashTable()
    {
        size = 10;
        arr = new List[size];
    }
    int HashFunction(int key)
    {
        return key * 7;
    }
    void Insert(int k)
    {
        arr[HashFunction(k) % size].insert(k);
    }
    void Delete(int k)
    {
        arr[HashFunction(k) % size].DelKey(k);
    }
    void printTable()
    {
        for (int i = 0; i < size; i++)
        {
            arr[i].triversal();
        }
    }
    bool search(int k)
    {
        return arr[HashFunction(k) % size].search(k);
    }
};
int main()
{
    HashTable table;
    for (int i = 0; i < 15; i++)
    {
        table.Insert(i);
    }
    table.printTable();
    cout << endl;
    table.Delete(5);
    table.Insert(16);
    table.printTable();
    cout<<table.search(16);
    return 0;
}