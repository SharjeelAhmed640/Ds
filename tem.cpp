#include <iostream>

using namespace std;

class node
{
public:
    int power, constant;
    char variable;
    node *next;
    node()
    {
        next = 0;
        power = 0;
        constant = 0;
        variable = '-';
    }
    node(int c, char v, int p)
    {
        next = 0;
        power = p;
        constant = c;
        variable = v;
    }
};
class list
{
    node *head;

public:
    list()
    {
        head = 0;
    }
    void addtohead(int c, char v, int p)
    {
        node *ptr = new node(c, v, p);
        if (head == 0)
        {
            head = ptr;
            return;
        }
        ptr->next = head;
        head = ptr;
    }
    void triversal()
    {
        node *temp = head;
        while (temp != NULL)
        {
            cout << temp->constant << " " << temp->variable << " " << temp->power << endl;
            temp = temp->next;
        }
        cout << endl;
    }
    int count()
    {
        node *temp = head;
        int counter = 0;
        while (temp != NULL)
        {
            temp = temp->next;
            counter++;
        }
        return counter;
    }
    void swap(node *p1, node *p2)
    {
        int tempconst, temppower;
        char tempvar;
        tempconst = p1->constant;
        temppower = p1->power;
        tempvar = p1->variable;
        p1->constant = p2->constant;
        p1->variable = p2->variable;
        p1->power = p2->power;

        p2->constant = tempconst;
        p2->variable = tempvar;
        p2->power = temppower;
    }
    int powersort()
    {
        node *h = head;
        int i, j, swapped;

        for (i = 0; i <= this->count(); i++)
        {

            h = head;
            swapped = 0;

            for (j = 0; j < this->count() - i - 1; j++)
            {

                node *p1 = h;
                node *p2 = p1->next;

                if (p1->power > p2->power)
                {
                    swap(p1, p2);
                    swapped = 1;
                }

                h = h->next;
            }
            if (swapped == 0)
                break;
        }
    }
    void varsort()
    {
        node *h = head;
        int i, j, swapped;

        for (i = 0; i <= this->count(); i++)
        {

            h = head;
            swapped = 0;

            for (j = 0; j < this->count() - i - 1; j++)
            {

                node *p1 = h;
                node *p2 = p1->next;

                if (p1->variable > p2->variable)
                {
                    swap(p1, p2);
                    swapped = 1;
                }

                h = h->next;
            }
            if (swapped == 0)
                break;
        }
    }
    void Addpoly(list *l2, list *result)
    {
        this->powersort();
        this->varsort();
        l2->powersort();
        l2->varsort();
        node *h1 = this->head;
        node *h2 = l2->head;
        while (h1 != NULL && h2 != NULL)
        {
            if ((h1->power == h2->power) && (h1->variable == h2->variable))
            {
                result->addtohead(h1->constant + h2->constant, h1->variable, h1->power);
                h1 = h1->next;
                h2 = h2->next;
            }
            else if (h1->power >= h2->power)
            {
                result->addtohead(h2->constant, h2->variable, h2->power);
                h2 = h2->next;
            }
            else if (h1->power < h2->power)
            {
                result->addtohead(h1->constant, h1->variable, h1->power);
                h1 = h1->next;
            }
        }
        while (h2 != NULL)
        {
            result->addtohead(h2->constant, h2->variable, h2->power);
            h2 = h2->next;
        }
        while (h1 != NULL)
        {
            result->addtohead(h1->constant, h1->variable, h1->power);
            h1 = h1->next;
        }
        result->powersort();
        result->varsort();
    }
};
int main()
{
    int n, constant, power;
    char variable;
    list l[2];
    for (int i = 0; i < 2; i++)
    {
        cin >> n;
        for (int j = 0; j < n; j++)
        {
            cin >> constant >> variable >> power;
            l[i].addtohead(constant, variable, power);
        }
    }
    list result;
    l[0].Addpoly(&l[1], &result);
    cout << result.count() << endl;
    result.triversal();

    return 0;
}