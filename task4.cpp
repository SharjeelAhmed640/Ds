#include <iostream>
#include <stack>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        left = 0;
        right = 0;
    }
    Node()
    {
        data = 0;
        left = 0;
        right = 0;
    }
};
class BST
{
    Node *root;
    void preOrderTri(Node *r)
    {
        if (r != NULL)
        {
            {
                cout << r->data << "\t";
                preOrderTri(r->left);
                //				cout<<"\t/";
                preOrderTri(r->right);
                //				cout<<"\t\t";
            }
        }
    }
    void inOrderTri(Node *r)
    {
        if (r != NULL)
        {

            inOrderTri(r->left);
            //				cout<<"\t";
            cout << r->data << "\t";
            inOrderTri(r->right);
            //				cout<<"\t\t";
        }
    }
    void postOrderTri(Node *r)
    {
        if (r != NULL)
        {

            postOrderTri(r->left);
            //			cout<<"\t";
            postOrderTri(r->right);
            //			cout<<"\t\t";
            cout << r->data << "\t";
        }
    }
    bool ifBST(Node *r, Node *left, Node *right)
    {

        if (root == NULL)
            return true;
        if (left != NULL and root->data <= left->data)
            return false;

        if (right != NULL && root->data >= right->data)
            return false;

        if (ifBST(root->left, left, root))
            return true;
        if (ifBST(root->right, root, right))
            return true;
    }

    Node *inordersucessor(Node *r)
    {
        Node *c = r;
        while (c && c->left != NULL)
        {
            c = c->left;
        }
        return c;
    }
    Node *delInBST(Node *r, int v)
    {
        // base case
        Node *temp;
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

                temp = inordersucessor(r->right);

                r->data = temp->data;

                r->right = delInBST(r->right, temp->data);
            }
        }
        return r;
    }

public:
    BST()
    {
        root = 0;
    }
    BST(Node *n)
    {
        root = n;
    }
    void AddNode(int data)
    {
        Node *temp = root;
        Node *ptr = new Node(data); // 5
                                    //   3     6
        if (root == 0)
        {
            root = ptr;
            cout << "added as Root" << endl;
            return;
        }
        while (temp != 0)
        {
            if (data == temp->data)
            {
                cout << "Duplicate value" << endl;
                return;
            }
            else if (temp->data > data && temp->left == 0)
            {
                temp->left = ptr;
                cout << "Inserted at left of : " << temp->data << endl;
                return;
            }
            else if (temp->data < data && temp->right == 0)
            {
                temp->right = ptr;
                cout << "Inserted at right of : " << temp->data << endl;
                return;
            }
            else if (temp->data > data && temp->left != 0)
            {
                temp = temp->left;
            }
            else if (temp->data < data && temp->right != 0)
            {
                temp = temp->right;
            }
        }
    }
    void Preordertriversal()
    {
        Node *temp = root;
        this->preOrderTri(temp);
        cout << endl;
    }
    void Postordertriversal()
    {
        Node *temp = root;
        this->postOrderTri(temp);
        cout << endl;
    }
    void inOrderTriversal()
    {
        Node *temp = root;
        this->inOrderTri(temp);
        cout << endl;
    }
    void iterativePreorder()
    {
        if (root == NULL)
            return;
        Node *temp;
        stack<Node *> st;
        st.push(root);
        while (!st.empty())
        {
            temp = st.top();
            cout << temp->data << "\t";
            st.pop();

            if (temp->left)
                st.push(temp->left);

            if (temp->right)
                st.push(temp->right);
        }
    }

    bool isBst()
    {
        Node *r = this->root;
        if (this->ifBST(r, 0, 0))
            cout << "FAs";
        return true;
        return false;
    }
    void deleteNode(int data)
    {
        Node *temp = root;
        this->root = this->delInBST(temp, data);
    }
    void truncate(int ll, int ul)
    {
        Node *r = root;
        if (root == NULL)
            return;
        Node *temp;
        stack<Node *> st;
        st.push(root);
        stack<int> stval;
        while (!st.empty())
        {
            temp = st.top();
            if (temp->data > ul || temp->data < ll)
                stval.push(temp->data);
            // cout << temp->data << "\t";

            st.pop();

            if (temp->left)
                st.push(temp->left);

            if (temp->right)
                st.push(temp->right);
        }
        int d;
        while (!stval.empty())
        {
            d = stval.top();
            stval.pop();
            this->deleteNode(d);
        }
    }
};

int main()
{
    int arr[] = {15, 10, 20, 8, 12, 16, 25};
    BST tree;
    //       15
    //     /   \
    //    /     \
    //   10     20
    //  /  \   /  \
    // 8   12 16   25
    for (size_t i = 0; i < 7; i++)
    {
        tree.AddNode(arr[i]);
    }

    cout << "pre order triversal(recurssive)" << endl;
    tree.inOrderTriversal();
    cout << "After truncate" << endl;
    tree.truncate(9, 12);
    cout << endl
         << "result" << endl;

    tree.inOrderTriversal();
}