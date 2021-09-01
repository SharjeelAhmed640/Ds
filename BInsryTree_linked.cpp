#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;
class root
{
    int data;
    root *left;
    root *right;

public:
    root()
    {
        data = 0;
        left = NULL;
        right = NULL;
    }
    root(int key)
    {
        data = key;
        left = NULL;
        right = NULL;
    }
    void ToRight(root *p)
    {
        this->right = p;
    }
    void ToLeft(root *p)
    {
        this->left = p;
    }
    void SetData(int data)
    {
        this->data = data;
    }
    int getData()
    {
        return this->data;
    }
    void preOrderTriversal(root *r)
    {
        if (r != NULL)
        {
            cout << r->data << "  ";
            preOrderTriversal(r->left);
            preOrderTriversal(r->right);
        }
    }
    void postOrderTriversal(root *r)
    {
        if (r != NULL)
        {
            postOrderTriversal(r->left);
            postOrderTriversal(r->right);
            cout << r->data << "  ";
        }
    }
    void inOrderTriversal(root *r)
    {
        if (r != NULL)
        {
            inOrderTriversal(r->left);
            cout << r->data << "  ";
            inOrderTriversal(r->right);
        }
    }
    bool isBST(root *r)
    {
        root *prev = NULL;
        if (r != NULL)
        {
            if (!isBST(r->left))
            {
                return 0;
            }
            if (prev != NULL && r->data <= prev->data)
            {
                return 0;
            }
            prev = r;
            return isBST(r->right);
        }
        else
        {
            return 1;
        }
    }
    root *SearchRec(root *r, int key)
    {
        if (this == NULL)
            return NULL;
        if (r->data == key)
            return r;
        else if (r->data > key)
            return SearchRec(r->left, key);
        else
            return SearchRec(r->right, key);
    }
    root *searchIter(root *r, int key)
    {
        while (r != NULL)
        {
            if (r->data == key)
                return r;
            else if (r->data > key)
                r = r->left;
            else
                r = r->right;
        }
    }
    void insert(root *r, int key)
    {
        root *prev = NULL;
        while (r != NULL)
        {
            prev = r;
            if (key == r->data)
            {
                cout << "duplicate key, cannot insert " << endl;
                break;
            }
            else if (key < r->data)
                r = r->left;
            else
                r = r->right;
        }
        root *newRoot = new root(key);
        if (key < prev->data)
            prev->left = newRoot;

        else
            prev->right = newRoot;
    }
    root *inOederPredecessor(root *r)
    {
        r = r->left;
        while (r->right != NULL)
            r = r->right;
    }
    root *deleteNode(root *r, int value)
    {
        root *ipre;
        if (r == NULL)
            return NULL;
        if (r->left == NULL && r->right == NULL)
        {
            free(r);
            return NULL;
        }
        if (value < r->data)
        {
            deleteNode(r->left, value);
        }
        else if (value > r->data)
        {
            deleteNode(r->right, value);
        }
        else
        {
            ipre = inOederPredecessor(r);
            r->data = ipre->data;
            r->left=deleteNode(r->left, ipre->data);
        }
        return r;
    }
};

int main()
{
    root p1, p2, p3;
    int key;
    p1.ToLeft(&p2);
    p1.ToRight(&p3);
    p1.SetData(2);
    p2.SetData(1);
    p3.SetData(0);
    p1.preOrderTriversal(&p1);
    cout << endl;
    p1.postOrderTriversal(&p1);
    cout << endl;
    p1.inOrderTriversal(&p1);
    if (p1.isBST(&p1))
        cout << endl
             << "Perfect binary searh tree" << endl;
    else
        cout << endl
             << "Not a perfect binary searh tree" << endl;

    cout << "Enter any number you want to searach in tree : ";
    cin >> key;
    if (p1.isBST(&p1))
    {
        if (p1.searchIter(&p1, key) == NULL)
        {
            cout << "Not Found" << endl;
        }
        else
        {
            root *r;
            r = p1.searchIter(&p1, key);
            cout << "Found  : " << r->getData();
        }
    }
    else
    {
        cout << "Not a binary search tree" << endl;
    }
    p1.insert(&p1, 5);
     cout<<endl;
    p1.inOrderTriversal(&p1);
    cout<<endl;
    p1.deleteNode(&p1,1);
    p1.inOrderTriversal(&p1);
    return 0;
}