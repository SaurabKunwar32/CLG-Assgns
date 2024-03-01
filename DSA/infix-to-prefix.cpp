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

string infixToPrefix(string infix)
{
    stack<char> st;
    string prefix;

    // Manually reverse the infix string
    string reversedInfix = "";
    for (int i = infix.length() - 1; i >= 0; --i)
    {
        reversedInfix += infix[i];
    }

    for (int i = 0; i < reversedInfix.length(); i++)
    {
        if (reversedInfix[i] == '(')
        {
            reversedInfix[i] = ')';
            i++;
        }
        else if (reversedInfix[i] == ')')
        {
            reversedInfix[i] = '(';
            i++;
        }
    }

    for (int i = 0; i < reversedInfix.length(); i++)
    {
        if (isOperatorOrNot(reversedInfix[i]))
        {
            prefix += reversedInfix[i];
        }
        else if (reversedInfix[i] == '(')
        {
            st.push('(');
        }
        else if (reversedInfix[i] == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                prefix += st.top();
                st.pop();
            }
            st.pop(); // Pop the '('
        }
        else
        {
            while (!st.empty() && (precedenceLevel(reversedInfix[i]) < precedenceLevel(st.top()) ||
                   (precedenceLevel(reversedInfix[i]) == precedenceLevel(st.top()) && associativity(reversedInfix[i]) == "RTL")))
            {
                prefix += st.top();
                st.pop();
            }
            st.push(reversedInfix[i]);
        }
    }

    while (!st.empty())
    {
        prefix += st.top();
        st.pop();
    }

    // Manually reverse the final prefix string
    string finalPrefix = "";
    for (int i = prefix.length() - 1; i >= 0; --i)
    {
        finalPrefix += prefix[i];
    }

    return finalPrefix;
}

int main()
{
    string exp = "A+B*(C-D)/E";
    cout << "Prefix operation before conversion : \n" << exp << endl;
    string prefix = infixToPrefix(exp);
    cout << "Prefix operation after conversion : \n" << prefix << endl;

    return 0;
}
