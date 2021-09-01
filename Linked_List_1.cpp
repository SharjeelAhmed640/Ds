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
    while(ptr != NULL)
    {
        cout<<" "<<ptr->data;
        ptr=ptr->next;
    }
}
};

int main()
{
    Node *head, *second, *third;
    head = new Node();
    second = new Node();
    third = new Node();

    head->data=1;
    head->next=second;

    second->data=2;
    second->next=third;

    third->data=3;
    third->next=NULL;

    head->triversal(head);
    return 0;
}