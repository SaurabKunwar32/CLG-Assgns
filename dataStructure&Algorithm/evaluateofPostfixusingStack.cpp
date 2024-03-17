#include <iostream>
#include <math.h>
//#include <cctype>
#include <stack>
using namespace std;
 stack<int> st;

int postfixEvaluation(string exp)
{
   
    for (int i = 0; i < exp.length(); i++)
    {
        if (isdigit(exp[i]))
        {
            st.push(exp[i] - '0');
        }
        else
        {
            int op2 = st.top();
            st.pop();
            int op1 = st.top();
            st.pop();

            switch (exp[i])
            {

            case '+':
                st.push(op1 + op2);
                break;
            case '-':
                st.push(op1 - op2);
                break;
            case '*':
                st.push(op1 * op2);
                break;
            case '/':
                st.push(op1 / op2);
                break;
            case '^':
                st.push(pow(op1, op2));
                break;

            default:
                cout << "Invalid" << endl;
                return -1;
            }
        }
    }

    return st.top();
}

int main()
{
    string exp="5437-*+";
    cout << "Postfix Expression to be evaluate :" << exp << endl;
    postfixEvaluation(exp);
    cout << "The final Result is:" << st.top() << endl;
}