#include <iostream>
#include <stack>
#include <queue>
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
    Node *recursiveSearch(Node *r, int val)
    {
        if (r == NULL)
        {
            cout << "Not found" << endl;
            return NULL;
        }
        if (r->data == val)
            return r;

        else if (val < r->data)
            return recursiveSearch(r->left, val);

        else
            return recursiveSearch(r->right, val);
    }
    bool ifBST(Node *r, Node *left, Node *right)
    {

        if (root == NULL)
            return true;
        if (left != NULL && root->data <= left->data)
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

    int height(Node *r)
    {
        if (r == NULL)
            return 0;
        else
        {
            int left_height = height(r->left);
            int right_height = height(r->right);
            if (left_height >= right_height)
                return left_height + 1;
            else
                return right_height + 1;
        }
    }

public:
    Node *root;
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
            // cout << "added as Root" << endl;
            return;
        }
        while (temp != 0)
        {
            if (data == temp->data)
            {
                // cout << "Duplicate value" << endl;
                return;
            }
            else if (temp->data > data && temp->left == 0)
            {
                temp->left = ptr;
                // cout << "Inserted at left of : " << temp->data << endl;
                return;
            }
            else if (temp->data < data && temp->right == 0)
            {
                temp->right = ptr;
                // cout << "Inserted at right of : " << temp->data << endl;
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
    Node *search(int val)
    {
        Node *temp = root;
        return recursiveSearch(temp, val);
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
    int TreeHeight()
    {
        Node *temp = root;
        return height(temp);
    }
    void breadthFirst()
    {
        queue<Node *> q;
        Node *temp = root;
        if (temp != NULL)
        {
            q.push(temp);
            while (!q.empty())
            {
                temp = q.front();
                q.pop();
                cout << temp->data << "->";
                if (temp->left != 0)
                    q.push(temp->left);
                if (temp->right != 0)
                    q.push(temp->right);
            }
        }
    }
    void printminmaxatLevel(Node *r, int level, int &min, int &max, int i = 0)
    {
        if (r != NULL && i <= level)
        {
            printminmaxatLevel(r->left, level, min, max, i + 1);
            printminmaxatLevel(r->right, level, min, max, i + 1);

            if (r->data > max && this->getLevelUtil(root, r->data) - 1 == level)
            {
                max = r->data;
                // cout << i << " max " << this->getLevelUtil(root, r->data) - 1 << endl;
            }
            if (r->data < min && this->getLevelUtil(root, r->data) - 1 == level)
            {
                min = r->data;
                // cout << i << " min " << this->getLevelUtil(root, r->data) - 1 << endl;
            }
        }
    }
    

    int getLevelUtil(Node *node, int data, int level = 1)
    {
        if (node == NULL)
            return 0;

        if (node->data == data)
            return level;

        int downlevel = getLevelUtil(node->left,
                                     data, level + 1);
        if (downlevel != 0)
            return downlevel;

        downlevel = getLevelUtil(node->right,
                                 data, level + 1);
        return downlevel;
    }
};

int main()
{
    int n, val, min, max;
    BST tree;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> val;
        tree.AddNode(val);
    }
    // cout<<tree.getLevelUtil(tree.root,val)<<endl<<endl;
    for (int i = 0; i < tree.getLevelUtil(tree.root, val); i++)
    {
        min = 9999999;
        max = 0;
        tree.printminmaxatLevel(tree.root, i, min, max);
        cout << min << " " << max << endl;
    }
    // min = 9999999;
    // max = 0;
    // tree.printminmaxatLevel(tree.root, min, max);
    // cout << min << " " << max << endl;
    // tree.inOrderTriversal();
    return 0;
}
