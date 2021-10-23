#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

class Node
{
    int data;
    Node *next;

public:
    Node()
    {
        this->data = 0;
        this->next = NULL;
    }
    void setdata(int data)
    {
        this->data = data;
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
    Node *reverse(Node *head, Node *rev)
    {

        Node *prev = NULL, *next = NULL, *current = head;
        while (current != NULL) // 1 2 3 4
        {
            next = current->next; // temp has 2
            current->next = prev; // current>next (1)->Null
            prev = current;
            current = next;
        }
        return prev;
    }

    bool checkPalindrome(Node *S, Node *E)
    {
        while (S != NULL && E != NULL)
        {
            if (S->data != E->data)
                return false;
            S = S->next;
            E = E->next;
        }
        return true;
    }
};

int main()
{
    int data, choose = 1, index;
    Node *head = new Node();
    cout << "enter head data : ";
    cin >> data;
    head->setdata(data);
    cout << "Press -1 for exit" << endl
         << "Press 1 for insterting node at begining" << endl
         << "Press 2 for insterting node at end" << endl
         << "Press 3 for insterting node at index" << endl
         << "Press 4 to check palindrome" << endl
         << "Press 5 for triversal" << endl
         << endl;
    cout << "Enter option : ";
    cin >> choose;
    while (choose != -1)
    {

        if (choose == -1)
            break;

        else if (choose == 1)
        {
            cout << "enter data : ";
            cin >> data;
            head = head->insertAtBeginning(data);
        }
        else if (choose == 2)
        {
            cout << "enter data : ";

            cin >> data;
            head = head->insertAtEnd(data);
        }
        else if (choose == 3)
        {
            cout << "enter data : ";
            cin >> data;
            cout << "enter index : ";
            cin >> index;
            head = head->insertAtIndex(index, data);
        }
        else if (choose == 4)
        {
            // if (head->checkPalindrome(&head, head))
            //     cout << "palindrome" << endl;
            // else
            //     cout << "Not a aplindrome" << endl;
        }
        else if (choose == 5)
        {
            head->triversal(head);
        }
        cout << "Enter option : ";
        cin >> choose;
    }
    Node *rev;
    rev = head->reverse(head, rev);
    rev->triversal(rev);
    if (rev->checkPalindrome(head, rev))
        cout << "Palindrome" << endl;
    else
        cout << "Not a palindrome" << endl;
    return 0;
}