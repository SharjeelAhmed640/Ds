#include <iostream>
#include <iomanip>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <sstream>
using namespace std;

class Node
{
public:
    string word;
    Node *next;
    Node *prev;
    Node()
    {
        next = NULL;
        prev = NULL;
        this->word = '-';
    }
    Node(string w)
    {
        next = NULL;
        prev = NULL;

        this->word = w;
    }
};
class List
{

public:
    Node *head;
    List(Node *n)
    {
        head = n;
    }
    List()
    {
        head = NULL;
    }
    void insertAtEnd(string w)
    {
        Node *temp = head;
        Node *ptr = new Node(w);
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
    void insertAtBeg(string w)
    {
        Node *temp = head;
        Node *ptr = new Node(w);
        if (head == NULL)
        {
            head = ptr;
        }
        else
        {
            temp->prev = ptr;
            ptr->next = temp;
            ptr->prev = NULL;
            head = ptr;
        }
    }
    void insertAtKey(string w, int key)
    {
        Node *temp = head;
        Node *ptr = new Node(w);
        if (head == NULL)
        {
            head = ptr;
            return;
        }
        int i = 0;
        if (key == 0)
        {
            this->insertAtBeg(w);
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
            this->insertAtEnd(w);
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
    void delAtindex(int index)
    {
        if (head == NULL)
            return;
        if (index == 0)
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
            if ((i + 1) == index)
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
        if ((i + 1) == index)
        {
            temp->next->prev = ptr;
            ptr->next = temp->next;
            delete (temp);
            return;
        }

        {
            cout << "Invalid index" << endl;
        }
    }
    void triversal()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->word << endl;
            temp = temp->next;
        }
        //  cout << endl;
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
            cout << temp->word << endl;
            temp = temp->prev;
        }
        cout << endl;
    }
    void swap(Node *n1, Node *n2)
    {
        string tw;
        tw = n1->word;
        n1->word = n2->word;
        n2->word = tw;
    }
    int NodeCount()
    {
        Node *temp = head;
        int i = 0;
        while (temp != NULL)
        {
            temp = temp->next;
            i++;
        }
        return i;
    }
    void bubblesortAscending()
    {
        Node *p1;
        Node *p2;
        bool swaped = false;
        string s1, s2;
        for (int i = 0; i < this->NodeCount(); i++)
        {
            p1 = head;

            for (int j = 0; j < this->NodeCount() - i - 1; j++)
            {
                // cout<<(i*this->NodeCount()+j)<<endl;
                // p1 = head;
                p2 = p1->next;
                s1 = p1->word;
                s2 = p2->word;
                transform(s1.begin(), s1.end(), s1.begin(), ::toupper);
                transform(s2.begin(), s2.end(), s2.begin(), ::toupper);

                //  cout<<p1->data<<" "<<p2->data<<endl;
                if (s1 > s2)
                {
                    // cout<<"swaped"<<endl;
                    this->swap(p1, p2);
                    swaped = true;
                }
                p1 = p1->next;
            }
            if (swaped = false)
                break;
        }
    }

    void bubblesortDescending()
    {
        Node *p1;
        Node *p2;
        bool swaped = false;
        for (int i = 0; i < this->NodeCount(); i++)
        {
            p1 = head;

            for (int j = 0; j < this->NodeCount() - i - 1; j++)
            {
                // cout<<(i*this->NodeCount()+j)<<endl;
                // p1 = head;
                p2 = p1->next;
                //  cout<<p1->data<<" "<<p2->data<<endl;
                if (p1->word < p2->word)
                {
                    // cout<<"swaped"<<endl;
                    this->swap(p1, p2);
                    swaped = true;
                }
                p1 = p1->next;
            }
            if (swaped = false)
                break;
        }
    }
    void removeDublicate()
    {
        this->bubblesortAscending();
        Node *h = head;
        Node *temp = head->next;
        int i = 0, track = 0;
        while (h != NULL)
        {
            temp = h->next;
            while (temp != NULL)
            {
                if (h->word == temp->word)
                {
                    //   cout<<h->word<<" "<<temp->word<<" "<<i<<" "<<track<<endl;
                    // cout << "in if" << endl;
                    this->delAtindex(i);
                }
                i++;
                // cout << "inner" << endl;
                temp = temp->next;
            }
            track++;
            i = track + 1;
            // i=0;
            h = h->next;
        }
    }
    void findter(List sent)
    {
        Node *find, *dest;
        string s1, s2, result;
        for (find = this->head; find != NULL; find = find->next)
        {
            s1 = find->word;
            result = s1;
            for (dest = sent.head; dest != NULL; dest = dest->next)
            {
                s2 = dest->word;
                if (s2.find(s1) != std::string::npos)
                {
                    result += " ";
                    stringstream check1(s2);

                    string intermediate;
                    getline(check1, intermediate, ' ');
                    result += intermediate;
                    // cout<<"in find"<<result<<endl;
                }
            }
            cout << result << endl;
        }
    }
};
string input()
{
    string s;
    char ch;
    // infinite loop
    // printf("Enter any character: ");
    while (1)
    {
        // read a single character
        ch = getchar();

        if (ch == 0x0A)
        {

            break;
        }
        else
        {
            s += ch;
        }
        // read dummy character to clear
        // input buffer, which inserts after character input
    }
    return s;
}
int main()
{
    List words, terminologies;
    string s, str;
    int n, m = 2;
    cin >> n;
    getchar();
    for (int i = 0; i < n; i++)
    {

        s = input();
        words.insertAtBeg(s);

        // getline(cin, s);
        // cout << "\t\t" << s;
    }
   cin>>m;
    for (int i = 0; i <= m; i++)
    {
        s = input();
        terminologies.insertAtEnd(s);
    }
    // l.triversal();
    words.bubblesortAscending();
    words.findter(terminologies);

    return 0;
}