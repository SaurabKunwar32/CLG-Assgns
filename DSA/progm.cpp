
// Q.NO.2
// #include <iostream>
// #include <stack>
// using namespace std;

// bool isOperatorOrNot(char c)
// {
//     if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
//     {
//         return true;
//     }
//         return false;
// }

// int precedenceLevel(char c)
// {
//     if (c == '^')
//     {
//         return 3;
//     }
//     else if (c == '/' || c == '*')
//     {
//         return 2;
//     }
//     else if (c == '+' || c == '-')
//     {
//         return 1;
//     }
//     else
//     {
//         return -1;
//     }
// }

// string associativity(char c)
// {
//     if (c == '^')
//     {
//         return "RTL";
//     }
//         return "LTR";
// }

// int main()
// {
//     string exp = "A+B*C/(E-F)";
//     cout<<"Before postfix operation expression is : \n "<< exp << endl;
//     stack<char> st;
//     string postfix;
//     for (int i = 0; i < exp.length(); i++)
//     {
//         if (isOperatorOrNot(exp[i]))
//         {
//             postfix += exp[i];
//         }
//         else if (exp[i] == '(')
//         {
//             st.push('(');
//         }
//         else if (exp[i] == ')')
//         {
//             while (st.top() != '(')
//             {
//                 postfix += st.top();
//             st.pop();
//             }
//             st.pop();
//         }
//         else
//         {
//             while (
//                 (!st.empty() && precedenceLevel(exp[i]) < precedenceLevel(st.top())) ||
//                 ((!st.empty() && precedenceLevel(exp[i]) == precedenceLevel(st.top())) && (!st.empty() && associativity(exp[i]) == "LTR"))
//                 )
//             {
//                 postfix += st.top();
//                 st.pop();
//             }
//             st.push(exp[i]);
//         }
//     }
//     while (!st.empty())
//     {
//         postfix += st.top();
//         st.pop();
//     }
//     cout << "\nAfter conversion postfix operation expression is :\n " << postfix << endl;
// }








// Q.NO.3

//  #include <iostream>
//  #include <stack>
//  using namespace std;

// bool isOperatorOrNot(char c)
// {
//     if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
//     {
//         return true;
//     }
//     return false;
// }

// int precedenceLevel(char c)
// {
//     if (c == '^')
//     {
//         return 3;
//     }
//     else if (c == '/' || c == '*')
//     {
//         return 2;
//     }
//     else if (c == '+' || c == '-')
//     {
//         return 1;
//     }
//     else
//     {
//         return -1;
//     }
// }

// string associativity(char c)
// {
//     if (c == '^')
//     {
//         return "RTL";
//     }
//     return "LTR";
// }

// string infixToPrefix(string infix)
// {
//     stack<char> st;
//     string prefix;

//     // Manually reverse the infix string
//     string reversedInfix = "";
//     for (int i = infix.length() - 1; i >= 0; --i)
//     {
//         reversedInfix += infix[i];
//     }

//     for (int i = 0; i < reversedInfix.length(); i++)
//     {
//         if (reversedInfix[i] == '(')
//         {
//             reversedInfix[i] = ')';
//             i++;
//         }
//         else if (reversedInfix[i] == ')')
//         {
//             reversedInfix[i] = '(';
//             i++;
//         }
//     }

//     for (int i = 0; i < reversedInfix.length(); i++)
//     {
//         if (isOperatorOrNot(reversedInfix[i]))
//         {
//             prefix += reversedInfix[i];
//         }
//         else if (reversedInfix[i] == '(')
//         {
//             st.push('(');
//         }
//         else if (reversedInfix[i] == ')')
//         {
//             while (!st.empty() && st.top() != '(')
//             {
//                 prefix += st.top();
//                 st.pop();
//             }
//             st.pop(); // Pop the '('
//         }
//         else
//         {
//             while (!st.empty() && (precedenceLevel(reversedInfix[i]) < precedenceLevel(st.top()) ||
//                    (precedenceLevel(reversedInfix[i]) == precedenceLevel(st.top()) && associativity(reversedInfix[i]) == "RTL")))
//             {
//                 prefix += st.top();
//                 st.pop();
//             }
//             st.push(reversedInfix[i]);
//         }
//     }

//     while (!st.empty())
//     {
//         prefix += st.top();
//         st.pop();
//     }

//     // Manually reverse the final prefix string
//     string finalPrefix = "";
//     for (int i = prefix.length() - 1; i >= 0; --i)
//     {
//         finalPrefix += prefix[i];
//     }

//     return finalPrefix;
// }

// int main()
// {
//     string exp = "A+B*(C-D)/E";
//     cout << "Prefix operation before conversion : \n" << exp << endl;
//     string prefix = infixToPrefix(exp);
//     cout << "Prefix operation after conversion : \n" << prefix << endl;

//     return 0;
// }


 


// //Stack implementation
// #include <iostream>
// #include <stack>
// using namespace std;

// class Stack
// {
// public:
//     int size;
//     int top;
//     int *arr;
//     void initStack()
//     {
//         cout << "Enter the size of the stack:" << endl;
//         cin >> this->size;
//         this->arr = new int[this->size];
//         this->top = -1;
//     }

//     void push(int n)
//     {
//         if (this->isFull())
//         {
//             cout << "Stack overflow \n"<< endl;
//             exit(0);
//         }
//         this->arr[++this->top] = n;
//     }

//     int pop()
//     {
//         if (this->isempty())
//         {
//             cout << "Stack underflow \n"
//                  << endl;
//             exit(0);
//         }
//         return this->arr[this->top--];
//     }

//     int peek()
//     {
//         return this->arr[this->top];
//     }

//     int getSize()
//     {
//         return this->size;
//     }

//     bool isempty()
//     {
//         return this->top == -1;
//     }
//     bool isFull()
//     {
//         return (this->top == (this->size - 1));
//     }

//     void StackValues()
//     {
//         if (this->isempty())
//         {
//             cout << "Stack is empty" << endl;
//             return;
//         }
//         cout << "Stack elements are : " << endl;
//         for (int i = 0; i < this->top; i++)
//         {
//             cout << this->arr[i] << endl;
//         }
//     }
//     void checkStatus()
//     {
//         if (this->isempty())
//         {
//             cout << "Stack is empty" << endl;
//         }
//         else if (this->isFull())
//         {
//             cout << "Stack is full" << endl;
//         }
//         else
//         {
//             cout << "The stack is neither empty nor full " << endl;
//         }
//     }
// };
// int main()
// {
//     Stack st;
//     st.initStack();
//     st.push(10);
//     st.push(20);
//     st.push(30);
//     st.push(40);
//     st.push(50);
//     st.StackValues();

//     cout << "Top element is : " << st.peek() << endl;
//     cout << "Popped element is : " << st.pop() << endl;
//     cout << "Size of stack is : " << st.getSize() << endl;

//     st.checkStatus();
// }


