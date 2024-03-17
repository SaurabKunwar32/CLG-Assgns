#include <iostream>
#include <stack>
using namespace std;

bool isOperatorOrNot(char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
    {
        return true;
    }
        return false;
}

int precedenceLevel(char c)
{
    if (c == '^')
    {
        return 3;
    }
    else if (c == '/' || c == '*')
    {
        return 2;
    }
    else if (c == '+' || c == '-')
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

string associativity(char c)
{
    if (c == '^')
    {
        return "RTL";
    }
        return "LTR";
}

int main()
{
    string exp = "A+B*C/(E-F)";
    cout<<"Before postfix operation expression is : \n "<< exp << endl;
    stack<char> st;
    string postfix;
    for (int i = 0; i < exp.length(); i++)
    {
        if (isOperatorOrNot(exp[i]))
        {
            postfix += exp[i];
        }
        else if (exp[i] == '(')
        {
            st.push('(');
        }
        else if (exp[i] == ')')
        {
            while (st.top() != '(')
            {
                postfix += st.top();
            st.pop();
            }
            st.pop();
        }
        else
        {
            while (
                (!st.empty() && precedenceLevel(exp[i]) < precedenceLevel(st.top())) ||
                ((!st.empty() && precedenceLevel(exp[i]) == precedenceLevel(st.top())) && (!st.empty() && associativity(exp[i]) == "LTR"))
                )
            {
                postfix += st.top();
                st.pop();
            }
            st.push(exp[i]);
        }
    }
    while (!st.empty())
    {
        postfix += st.top();
        st.pop();
    }
    cout << "\nAfter conversion postfix operation expression is :\n " << postfix << endl;
}