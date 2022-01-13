#include <iostream>
using namespace std;

class node
{

public:
    int data;
    node *left;
    node *right;
};

node *createnode(int value)
{
    node *n = new node();
    n->data = value;
    n->left = NULL;
    n->right = NULL;

    return n;
}

void insert(node *root, int key)
{
    node *prev;
    while (root != NULL)
    {
        prev = root;
        if (root->data == key)
        {
            return;
        }
        else if (root->data < key)
        {
            root = root->right;
        }
        else
        {
            root = root->left;
        }
    }
    node *ptr = createnode(key);
    {
        if (key > prev->data)
        {
            prev->right = ptr;
        }
        else
        {
            prev->left = ptr;
        }
    }
}

node *inorderPredecessor(node *root)
{
    root = root->right;
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root;
}

node *delInBST(node *r, int v)
{
    // base case
    node *temp;
    if (r == NULL)
    {
        return NULL;
    }
    else if (v < r->data)
    {
        r->left = delInBST(r->left, v);
    }

    else if (v > r->data)
    {
        r->right = delInBST(r->right, v);
    }

    else
    {
        if (r->left == NULL && r->right == NULL)
        {
            delete (r); // wipe out the memory, in C, use free function
            r = NULL;
        }

        else if (r->left == NULL)
        {
            temp = r->right;
            delete r;
            return temp;
        }
        else if (r->right == NULL)
        {
            temp = r->left;
            delete r;
            return temp;
        }
        else
        {

            temp = inorderPredecessor(r);

            r->data = temp->data;

            r->right = delInBST(r->right, temp->data);
        }
    }
    return r;
}
void preorder(node *root)
{
    if (root != NULL)
    {
        cout << root->data << "->";
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << "->";
    }
}

void inorder(node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->data << "->";
        inorder(root->right);
    }
}

bool isBST(node *root, node *left, node *right)
{
    if (root == NULL)
    {
        return true;
    }
    if (left != NULL && root->data <= left->data)
    {
        return false;
    }
    if (right != NULL && root->data >= right->data)
    {
        return false;
    }
    if (isBST(root->left, left, root))
    {
        return true;
    }
    if (isBST(root->right, root, right))
    {
        return true;
    }
}

node *recursiveSearch(node *root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == key)
    {
        return root;
    }
    else if (root->data < key)
    {
        recursiveSearch(root->right, key);
    }
    else
    {
        recursiveSearch(root->left, key);
    }
}

node *iterativeSearch(node *root, int key)
{
    while (root != NULL)
    {
        if (root->data == key)
        {
            return root;
        }
        else if (root->data < key)
        {
            root = root->right;
        }
        else
        {
            root = root->left;
        }
    }
    return NULL;
}
int main()
{
    node *n = createnode(8);
    insert(n, 10);
    insert(n, 1);
    insert(n, 4);
    insert(n, 14);
    insert(n, 7);
    insert(n, 6);
    insert(n, 13);
    insert(n, 3);
    inorder(n);
    n = delInBST(n, 8);
    cout << endl;
    inorder(n);
    cout << "ASdsa";
    return 0;
}