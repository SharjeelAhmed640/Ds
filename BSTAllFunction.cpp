#include <iostream>
#include <iomanip>
#include <stack>
#include <queue>
#include <cstring>
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
    void inorder(Node *r)
    {
        if (r != NULL)
        {
            inorder(r->left);
            cout << r->data << " ";
            inorder(r->right);
        }
    }
    void preorder(Node *r)
    {
        if (r != NULL)
        {
            cout << r->data << " ";
            inorder(r->left);
            inorder(r->right);
        }
    }
    void postorder(Node *r)
    {
        if (r != NULL)
        {
            inorder(r->left);
            inorder(r->right);
            cout << r->data << " ";
        }
    }
    bool isbst(Node *r, Node *left, Node *right)
    {
        if (r == NULL)
            return true;
        if (left != NULL && r->data <= left->data)
            return false;
        if (right != NULL && r->data >= right->data)
            return false;
        if (isbst(r->left, r, right))
            return true;
        if (isbst(r->right, left, r))
            return true;
    }
    void printGivenLevel(Node *r, int level)
    {
        if (r == NULL)
            return;
        if (level == 0)
            cout << r->data << " ";

        printGivenLevel(r->left, level - 1);
        printGivenLevel(r->right, level - 1);
    }
    int height(Node *r)
    {
        if (r == NULL)
            return 0;
        {
            int left = height(r->left);
            int right = height(r->right);
            return max(left, right) + 1;
        }
    }
    int LevelOfGivenNode(Node *r, int key, int level = 1)
    {
        if (r == NULL)
            return 0;
        else
        {
            if (r->data == key)
                return level;
            int downlevel = LevelOfGivenNode(r->left, key, level + 1);
            if (downlevel != 0)
                return downlevel;
            downlevel = LevelOfGivenNode(r->right, key, level + 1);
            return downlevel;
        }
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
        root = NULL;
    }
    void insert(int data)
    {
        Node *temp = root;
        Node *ptr = new Node(data);
        while (temp != NULL)
        {

            if (temp->data == data)
            {
                cout << "Duplicate" << endl;
                return;
            }
            if (data > temp->data && temp->right != NULL)
                temp = temp->right;
            if (data < temp->data && temp->left != NULL)
                temp = temp->left;
            if (data > temp->data && temp->right == NULL)
            {
                temp->right = ptr;
                cout << "Inserted at right " << endl;
                return;
            }
            if (data < temp->data && temp->left == NULL)
            {
                temp->left = ptr;
                cout << "Inserted at left " << endl;
                return;
            }
        }
        if (root == NULL)
            root = ptr;
    }
    void DELETE(int k)
    {
        Node *temp = root;
        root=this->delInBST(temp, k);
    }
    bool search(int key)
    {
        cout << endl;
        Node *temp = root;
        if (root == NULL)
            return false;
        while (temp != NULL)
        {
            if (key == temp->data)
            {
                return temp;
            }
            else if (key < temp->data)
            {
                temp = temp->left;
            }
            else
            {
                temp = temp->right;
            }
        }
        return false;
    }
    void PREORDER()
    {
        Node *temp = root;
        this->preorder(temp);
    }
    void POSTORDER()
    {
        Node *temp = root;
        this->postorder(temp);
    }
    void INORDER()
    {
        Node *temp = root;
        this->inorder(temp);
    }
    void DFS()
    {
        stack<Node *> track;
        Node *temp = root;
        track.push(temp);
        if (temp == NULL)
            return;
        while (!track.empty())
        {
            temp = track.top();
            track.pop();
            cout << temp->data << " ";
            if (temp->left != NULL)
                track.push(temp->left);
            if (temp->right != NULL)
                track.push(temp->right);
        }
    }
    void BFS()
    {
        queue<Node *> track;
        Node *temp = root;
        track.push(temp);
        if (temp == NULL)
            return;
        while (!track.empty())
        {
            temp = track.front();
            track.pop();
            cout << temp->data << " ";
            if (temp->left != NULL)
                track.push(temp->left);
            if (temp->right != NULL)
                track.push(temp->right);
        }
    }
    void PRINTGIVENLEVEL(int level)
    {
        Node *temp = root;
        this->printGivenLevel(temp, level);
    }
    bool ISBST()
    {
        Node *temp = root;
        this->isbst(temp, 0, 0);
    }
    int HEIGHT()
    {
        Node *temp = root;
        this->height(temp);
    }
    int LEVELOFGIVENNODE(int key)
    {
        Node *temp = root;
        this->LevelOfGivenNode(temp, key);
    }
};
int main()
{
    BST tree;

    tree.insert(8);
    tree.insert(3);
    tree.insert(10);
    tree.insert(1);
    tree.insert(6);
    tree.insert(14);
    tree.insert(15);
    tree.insert(4);
    tree.insert(7);
    tree.insert(13);
    (tree.ISBST()) ? cout << endl
                          << "BST : YES" << endl
                   : cout << endl
                          << "BST : NO" << endl;
    cout << endl
         << "PREORDER    :    ";
    tree.PREORDER();
    tree.DELETE(6);
    cout << endl
         << "INORDER     :    ";
    tree.INORDER();
    cout << endl
         << "POSTORDER   :    ";
    tree.POSTORDER();
    cout << endl
         << "DFS         :    ";
    tree.DFS();
    cout << endl
         << "BFS         :    ";
    tree.BFS();
    cout << endl
         << "PRINTING LEVEL 1   : ";
    tree.PRINTGIVENLEVEL(1);

    cout << endl
         << "HEIGHT   :    " << tree.HEIGHT();
    cout << endl
         << "LEVEL OF 6    :  " << tree.LEVELOFGIVENNODE(6);
    (tree.search(8)) ? cout << "\nFOUND" << endl : cout << "\nNOTFOUND" << endl;
    return 0;
}