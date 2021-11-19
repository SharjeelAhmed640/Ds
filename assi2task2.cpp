#include <iostream>
#include <vector>
#include <sstream>
#include <unordered_set>
#include <set>
#include <algorithm>
using namespace std;

class node
{
public:
    string str;
    node *next;
    node()
    {
        next = NULL;
    }
};

class LinkedList
{
    node *head;

public:
    LinkedList()
    {
        head = NULL;
    }

    void insert_at_beginning(string str)
    {
        node *temp = new node();
        temp->str = str;
        temp->next = head;
        head = temp;
    }

    void insert_at_end(string str)
    {
        node *temp = new node();
        temp->str = str;
        if (head == NULL)
        {
            // if linked list is empty
            // make temp the new head
            head = temp;
        }
        else
        {
            // if linked list is not empty
            // go to the last node of the linked list
            node *ptr = head;
            // the loop sets ptr to last node of the linked list
            while (ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            // ptr now points to the last node of the linked list
            // store temp in the next of ptr
            ptr->next = temp;
        }
    }

    void insert_at_given_position(string str, int p)
    {
        node *temp = new node();
        temp->str = str;
        if (p == 0)
        {
            // if p==0 then insert temp at beginning
            temp->next = head;
            head = temp;
        }
        else
        {
            node *ptr = head;
            // the loop sets ptr to (p-1)th node
            while (p > 1)
            {
                ptr = ptr->next;
                --p;
            }
            // ptr now points to (p-1)th node
            // insert temp between (p-1)th and pth node
            temp->next = ptr->next;
            ptr->next = temp;
        }
    }

    void delete_at_beginning()
    {
        if (head == NULL)
        {
            cout << "List is Empty" << endl;
        }
        else
        {
            cout << "Element Deleted: " << head->str << endl;
            // if linked list is not empty
            // store address of first node of the linked list in temp
            node *temp = head;
            // set second node as the new head of the linked list
            head = head->next;
            // free the old head
            delete (temp);
        }
    }

    void delete_at_end()
    {
        if (head == NULL)
        {
            cout << "List is Empty" << endl;
        }
        else if (head->next == NULL)
        {
            // if there's only 1 node in the linked list
            // free head and set it to NULL
            cout << "Element Deleted: " << head->str << endl;
            delete (head);
            head = NULL;
        }
        else
        {
            // if there's more than 1 node in the linked
            // traverse to 2nd last node of the linked list
            node *temp = head;
            // the loop sets temp to 2nd last node of the linked list
            while (temp->next->next != NULL)
            {
                temp = temp->next;
            }
            // temp now points to the 2nd last node of the linked list
            cout << "Element Deleted: " << temp->next->str << endl;
            // delete last node
            delete (temp->next);
            // set the next of 2nd last node to NULL
            temp->next = NULL;
        }
    }

    void delete_at_given_position(int p)
    {
        if (head == NULL)
        {
            // if list is empty do nothing
            cout << "List is Empty" << endl;
        }
        else
        {
            node *temp, *ptr;
            if (p == 0)
            {
                // if p==0, perform delete at beginning
                cout << "Element Deleted: " << head->str << endl;
                ptr = head;
                head = head->next;
                delete (ptr);
            }
            else
            {
                // if p > 0
                // set ptr to pth node and temp to (p-1)th node
                temp = ptr = head;
                while (p > 0)
                {
                    --p;
                    temp = ptr;
                    ptr = ptr->next;
                }
                cout << "Element Deleted: " << ptr->str << endl;
                // set next of (p-1)th node to next of pth node
                temp->next = ptr->next;
                // free pth node
                free(ptr);
            }
        }
    }

    void print()
    {
        if (head == NULL)
        {
           // cout << "List is empty" << endl;
        }
        else
        {
            node *temp = head;
           // cout << "Linked List: ";
            while (temp != NULL)
            {
                cout << temp->str << endl;
                temp = temp->next;
            }
           // cout << "NULL" << endl;
        }
    }
};
void CaseInsensitiveSort(vector<string> &strs)
{
    sort(
        begin(strs),
        end(strs),
        [](const string &str1, const string &str2)
        {
            return lexicographical_compare(
                begin(str1), end(str1),
                begin(str2), end(str1),
                [](const char &char1, const char &char2)
                {
                    return tolower(char1) > tolower(char2);
                });
        });
}
int main()
{
    LinkedList l;
    string line;
    getline(cin, line);

    istringstream iss{line};

    set<string> uniqueWords{};
    vector<string> vt;
    string word{};
    while (iss >> word)
    {
        uniqueWords.insert(word);
    }
    for (const string &word : uniqueWords)
    {
        // cout << word << '\n';
        vt.push_back(word);
       // l.insert_at_beginning(word);
    }
    CaseInsensitiveSort(vt);
    for (int i = 0; i < vt.size(); i++)
    {
        l.insert_at_beginning(vt.at(i));
    }
    l.print();
    //  return 0;
}