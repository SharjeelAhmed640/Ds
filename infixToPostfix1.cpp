#include <iostream>
#include <iomanip>
#include <cstring>
#include <stack>
using namespace std;

int prec(char c)
{
    if (c == '^')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}
string infixToPostfix(string input)
{
    stack<char> st;
    string result;
    for (int i = 0; i < input.length(); i++)
    {
        if ((input[i] >= 'a' && input[i] <= 'z') || (input[i] >= 'A' && input[i] <= 'Z') || (input[i] >= '0' && input[i] <= '9'))
            result += input[i];
        else if (input[i] == '(')
            st.push(input[i]);

        else if (input[i] == ')')
        {
            while (st.top() != '(')
            {
                result += st.top();
                st.pop();
            }
            st.pop();
        }
        else
        {
            while (!st.empty() && prec(input[i]) <= prec(st.top()))
            {
                result += st.top();
                st.pop();
            }
            st.push(input[i]);
        }
    }
    while (!st.empty())
    {
        result += st.top();
        st.pop();
    }
    cout<<result;
    return result;
}
int main()
{
    string input;
    cout<<"enter a expression : ";
    cin>>input;
    cout<<"Infix to postfix expression : ";
    infixToPostfix(input);
    return 0;
}