#include <iostream>
using namespace std;

class Node
{
public:
    string name;
    Node *left;
    Node *right;
    Node(string name)
    {
        this->name = name;
        left = 0;
        right = 0;
    }
    Node()
    {
        name = "-";
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
                cout << r->name << "\t";
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
            cout << r->name << "\t";
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
            cout << r->name << "\t";
        }
    }
    bool ifBST(Node *r, Node *left, Node *right)
    {

        if (root == NULL)
            return true;
        if (left != NULL and root->name <= left->name)
            return false;


        if (right != NULL && root->name >= right->name)
            return false;

        if (ifBST(root->left, left, root))
            return true;
        if (ifBST(root->right, root, right))
            return true;
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
    void AddNode(string name)
    {
        Node *temp = root;
        Node *ptr = new Node(name); // 5
                                    //   3     6
        if (root == 0)
        {
            root = ptr;
            cout << "added as Root" << endl;
            return;
        }
        while (temp != 0)
        {
            if (name == temp->name)
            {
                cout << "Duplicate value" << endl;
                return;
            }
            else if (temp->name > name && temp->left == 0)
            {
                temp->left = ptr;
                cout << "Inserted at left of : " << temp->name << endl;
                return;
            }
            else if (temp->name < name && temp->right == 0)
            {
                temp->right = ptr;
                cout << "Inserted at right of : " << temp->name << endl;
                return;
            }
            else if (temp->name > name && temp->left != 0)
            {
                temp = temp->left;
            }
            else if (temp->name < name && temp->right != 0)
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
    bool isBst()
    {
        Node *r = this->root;
        if (this->ifBST(r, 0, 0))
            cout << "FAs";
        return true;
        return false;
    }
};

int main()
{
  string arr[]={ "15", "10", "20", "8", "12", "16", "25" };
  BST tree;
  for (size_t i = 0; i < 7; i++)
  {
     tree.AddNode(arr[i]);
  }
  cout<<"In order triversal"<<endl;
  tree.inOrderTriversal();
  
}