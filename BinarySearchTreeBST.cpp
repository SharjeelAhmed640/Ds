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
                cout << "Duplicate value" << endl; // c++
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
    Node *inordersuc(Node *r)
    {
        Node *temp = r;
        temp = temp->left;
        while (temp->right->right != NULL)
            temp = temp->right;
        return temp;
    }
    void del(int r)
    {
        if (root == NULL)
            return;
        if (root->data == r && root->left == NULL && root->right == NULL)
        {
            root = NULL;
        }
        Node *key_node = NULL;
        Node *temp;
        Node *last;
        queue<Node *> q;
        q.push(root);
        while (!q.empty())
        {
            temp = q.front();
            q.pop();
            if (r == temp->data)
                key_node = temp;
            if (temp->left)
            {
                last = temp;
                q.push(temp->left);
            }
            if (temp->right)
            {
                last = temp;
                q.push(temp->right);
            }
        }
        if (key_node != NULL)
        {
            key_node->data = temp->data;
            if (last->right == temp)
                last->right = NULL;
            else
                last->left = NULL;
            delete (temp);
        }
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
};

int main()
{
    int n, val, min, max;
    BST tree;
    while (1)
    {
        cout << "Press 1 to add Node" << endl
             << "Press 2 to delete Node" << endl
             << "Press 3 to search Node" << endl
             << "Press 4 to truncate" << endl
             << "Press 5 to print preorder triversal" << endl
             << "Press 5 to print inorder triversal" << endl
             << "Press 6 to print postorder triversal" << endl
             << "Press 7 if a tree is BST?" << endl
             << "Press 8 for tree height" << endl
             << "press 0 to exit" << endl;
        cin >> n;
        if (n == 0)
            break;
        switch (n)
        {
        case 1:
        {
            cout << "Enter node data to delete Node : ";
            cin >> val;
            tree.AddNode(val);
            break;
        }
        case 2:
        {
            cout << "Enter node data to delete Node : ";
            cin >> val;
            tree.del(val);
            break;
        }
        case 3:
        {
            cout << "Enter node data to search Node : ";
            cin >> val;
            Node *temp = tree.search(val);
            if (temp != NULL)
            {
                cout << "Node found" << endl;
            }
            break;
        }
        case 4:
        {
            cout << "Enter min limit for truncate : ";
            cin >> min;
            cout << "Enter max limit for truncate : ";
            cin >> max;
            tree.truncate(min, max);
            break;
        }
        case 5:
        {
            tree.Preordertriversal();
            break;
        }
        case 6:
        {
            tree.inOrderTriversal();
            break;
        }
        case 7:
        {
            tree.Postordertriversal();
            break;
        }
        case 8:
        {
            cout << tree.TreeHeight();
            break;
        }
        case 0:
        {
            break;
        }
        default:
        {
            cout << "Invalid input" << endl;
            break;
        }
        }
    }

    return 0;
}
