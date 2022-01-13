#include <iostream>
#include <iomanip>
#include <cstring>
#include <stack>
using namespace std;
class Node
{

public:
    Node *left, *right;
    char data;
    Node()
    {
        data = '-';
        left = NULL;
        right = NULL;
    }
    Node(char c)
    {
        data = c;
        left = NULL;
        right = NULL;
    }
    void addLeftRight(Node *l, Node *r)
    {
        this->left = l;
        this->right = r;
    }
    void inorder(Node *root)
    {
        if (root != NULL)
        {
            inorder(root->left);
            cout << root->data << " ";
            inorder(root->right);
        }
    }
    void postOrder(Node *root)
    {
        if (root != NULL)
        {
            inorder(root->left);
            inorder(root->right);
            cout << root->data << " ";
        }
    }
    void preOrder(Node *root)
    {
        if (root != NULL)
        {
            cout << root->data << " ";
            inorder(root->left);
            inorder(root->right);
        }
    }
};
Node *createExpTreePostfix(string s)
{
    stack<Node *> st;
    for (int i = 0; i < s.length(); i++)
    {
        char c = s[i];
        if (c == '-' || c == '+' || c == '/' || c == '*')
        {
            Node *op1, *op2;
            if (st.empty())
                return NULL;
            op2 = st.top();
            st.pop();
            if (st.empty())
                return NULL;
            op1 = st.top();
            st.pop();
            Node *ptr = new Node(c);
            ptr->addLeftRight(op1, op2);
            st.push(ptr);
        }
        else
        {
            Node *ptr = new Node(c);
            st.push(ptr);
        }
    }
    return st.top();
}
Node *createExpTreePrefix(string s)
{
    stack<Node *> st;
    for (int i = s.length(); i >= 0; i--)
    {
        char c = s[i];
        if (c == '-' || c == '+' || c == '/' || c == '*')
        {
            Node *op1, *op2;
            if (st.empty())
                return NULL;
            op2 = st.top();
            st.pop();
            if (st.empty())
                return NULL;
            op1 = st.top();
            st.pop();
            Node *ptr = new Node(c);
            ptr->addLeftRight(op1, op2);
            st.push(ptr);
        }
        else
        {
            Node *ptr = new Node(c);
            st.push(ptr);
        }
    }
    return st.top();
}
int precedence(char c)
{
    if (c == '/' || c == '*')
        return 3;
    if (c == '+' || c == '=')
        return 2;
    return -1;
}
Node *createExpTreeInfix(string s)
{
    stack<Node *> charst;
    stack<Node *> nodest;
    for (int i = 0; i < s.length(); i++)
    {
        char c = s[i];
        if (c == '(')
            charst.push(new Node(c));
        else if (c == ')')
        {
            Node *temp = charst.top();
            while (temp->data != '(')
            {
                temp = charst.top();
                charst.pop();
                if(temp->data=='(' || temp->data==')')
                break;
                Node *op1, *op2;
                op2 = nodest.top();
                nodest.pop();
                op1 = nodest.top();
                nodest.pop();
                
                temp->addLeftRight(op1, op2);
                nodest.push(temp);
            }
        }
        else if (c == '-' || c == '+' || c == '/' || c == '*')
        {
            if (charst.empty())
                charst.push(new Node(c));
            else
            {
                Node *temp = charst.top();
                while (precedence(temp->data) > c)
                {
                    Node *op1, *op2;
                    op2 = nodest.top();
                    nodest.pop();
                    op1 = nodest.top();
                    nodest.pop();
                    temp = charst.top();
                    charst.pop();
                    temp->addLeftRight(op1, op2);
                    nodest.push(temp);
                }
                charst.push(new Node(c));
            }
        }
        else
        {
            Node *ptr = new Node(c);
            nodest.push(ptr);
        }
    }
    while (!charst.empty())
    {
        Node *op1, *op2, *op;
        op = charst.top();
        charst.pop();
        op2 = nodest.top();
        nodest.pop();
        op1 = nodest.top();
        nodest.pop();
        op->addLeftRight(op1, op2);
        nodest.push(op);
    }
    return nodest.top();
}
bool CheckifPostfix(string s)
{
    if (s[s.length() - 1] == '*' || s[s.length() - 1] == '/' || s[s.length() - 1] == '+' || s[s.length() - 1] == '-')
        return true;
    return false;
}
bool CheckifPrefix(string s)
{
    if (s[0] == '*' || s[0] == '/' || s[0] == '+' || s[0] == '-')
        return true;
    return false;
}

int main()
{
    Node *root;
    string s;
    cout << "Enter any expression(Valid) : ";
    cin >> s;
    if (CheckifPostfix(s))
    {
        cout << "Its a postfix expression" << endl;
        root = createExpTreePostfix(s);
    }
    else if (CheckifPrefix(s))
        root = createExpTreePrefix(s);
    else
        root = createExpTreeInfix(s);
    cout << endl
         << "Preorder    :   ";
    root->preOrder(root);
    cout << endl
         << "Inorder     :   ";
    root->inorder(root);
    cout << endl
         << "Postorder   :   ";
    root->postOrder(root);
    return 0;
}