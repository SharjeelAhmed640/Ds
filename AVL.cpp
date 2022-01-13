
#include <iostream>
#include <cstdio>
#include <sstream>
#include <algorithm>
//#define pow2(n) (1 << (n))
using namespace std;
class Node
{
public:
    int d;
    Node *l;
    Node *r;
} * r;
class avl_tree
{
public:
    int height(Node *);
    int difference(Node *);
    Node *rr_rotat(Node *);
    Node *ll_rotat(Node *);
    Node *lr_rotat(Node *);
    Node *rl_rotat(Node *);
    Node *balance(Node *);
    Node *insert(Node *, int);
    void show(Node *, int);
    void inorder(Node *);
    void preorder(Node *);
    void postorder(Node *);
    avl_tree()
    {
        r = NULL;
    }
};
int avl_tree::height(Node *t)
{

    if (t != NULL)
    {
        int l_height = height(t->l);
        int r_height = height(t->r);
        return max(l_height, r_height) + 1;
    }
}
Node *search(int key, Node *ptr = r)
{
    if (ptr != NULL)
    {
        if (key == ptr->d)
            return ptr;
        if (key > ptr->d)
            search(key, ptr->r);
        else
            search(key, ptr->l);
    }
}
Node *inordersuccessor(Node *temp)
{
    temp = temp->l;
    while (temp->r != NULL)
        temp = temp->r;
    return temp;
}
void deleteNode(int key)
{


    Node *source=search(key);
    Node* dest=inordersuccessor(source);
    int data=source->d;
    source->d=dest->d;
    dest->d=data;

}
int avl_tree::difference(Node *t)
{
    int l_height = height(t->l);
    int r_height = height(t->r);
    return l_height - r_height;
    ;
}
Node *avl_tree::rr_rotat(Node *parent)
{
    Node *t;
    t = parent->r;
    parent->r = t->l;
    t->l = parent;
    cout << "Right-Right Rotation";
    return t;
}
Node *avl_tree::ll_rotat(Node *parent)
{
    Node *t;
    t = parent->l;
    parent->l = t->r;
    t->r = parent;
    cout << "Left-Left Rotation";
    return t;
}
Node *avl_tree::lr_rotat(Node *parent)
{
    Node *t;
    t = parent->l;
    parent->l = rr_rotat(t);
    cout << "Left-Right Rotation";
    return ll_rotat(parent);
}
Node *avl_tree::rl_rotat(Node *parent)
{
    Node *t;
    t = parent->r;
    parent->r = ll_rotat(t);
    cout << "Right-Left Rotation";
    return rr_rotat(parent);
}
Node *avl_tree::balance(Node *t)
{
    int bal_factor = difference(t);
    if (bal_factor > 1)
    {
        if (difference(t->l) > 0)
            t = ll_rotat(t);
        else
            t = lr_rotat(t);
    }
    else if (bal_factor < -1)
    {
        if (difference(t->r) > 0)
            t = rl_rotat(t);
        else
            t = rr_rotat(t);
    }
    return t;
}
Node *avl_tree::insert(Node *r, int v)
{
    if (r == NULL)
    {
        r = new Node;
        r->d = v;
        r->l = NULL;
        r->r = NULL;
        return r;
    }
    else if (v < r->d)
    {
        r->l = insert(r->l, v);
        r = balance(r);
    }
    else if (v >= r->d)
    {
        r->r = insert(r->r, v);
        r = balance(r);
    }
    return r;
}
void avl_tree::show(Node *p, int l)
{
    int i;
    if (p != NULL)
    {
        show(p->r, l + 1);
        cout << " ";
        if (p == r)
            cout << "Root -> ";
        for (i = 0; i < l && p != r; i++)
            cout << " ";
        cout << p->d;
        show(p->l, l + 1);
    }
}
void avl_tree::inorder(Node *t)
{
    if (t == NULL)
        return;
    inorder(t->l);
    cout << t->d << " ";
    inorder(t->r);
}
void avl_tree::preorder(Node *t)
{
    if (t == NULL)
        return;
    cout << t->d << " ";
    preorder(t->l);
    preorder(t->r);
}
void avl_tree::postorder(Node *t)
{
    if (t == NULL)
        return;
    postorder(t->l);
    postorder(t->r);
    cout << t->d << " ";
}
int main()
{
    int c, i;
    avl_tree Node;
    while (1)
    {
        cout << "1.Insert Element into the tree" << endl;
        cout << "2.show Balanced Node Tree" << endl;
        cout << "3.InOrder traversal" << endl;
        cout << "4.PreOrder traversal" << endl;
        cout << "5.PostOrder traversal" << endl;
        cout << "6.Exit" << endl;
        cout << "Enter your Choice: ";
        cin >> c;
        switch (c)
        {
        case 1:
            cout << "Enter value to be inserted: ";
            cin >> i;
            r = Node.insert(r, i);
            break;
        case 2:
            if (r == NULL)
            {
                cout << "Tree is Empty" << endl;
                continue;
            }
            cout << "Balanced Node Tree:" << endl;
            Node.show(r, 1);
            cout << endl;
            break;
        case 3:
            cout << "Inorder Traversal:" << endl;
            Node.inorder(r);
            cout << endl;
            break;
        case 4:
            cout << "Preorder Traversal:" << endl;
            Node.preorder(r);
            cout << endl;
            break;
        case 5:
            cout << "Postorder Traversal:" << endl;
            Node.postorder(r);
            cout << endl;
            break;
        case 6:
            exit(1);
            break;
        default:
            cout << "Wrong Choice" << endl;
        }
    }
    return 0;
    
}
