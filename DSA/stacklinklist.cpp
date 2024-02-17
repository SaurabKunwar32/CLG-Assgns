#include <iostream>
using namespace std;

class Node
{

public:
    char data;
    Node *next;

    Node(char value)
    {
        data = value;
        next = nullptr;
    }
};

class LinkedListStack
{
private:
    Node *top;

public:
    LinkedListStack()
    {
        top = nullptr;
    }

    void push(char value)
    {
        Node *newNode = new Node(value);
        newNode->next = top;
        top = newNode;
    }

    char pop()
    {
        if (isEmpty())
        {
            cout << "Stack underflow" << endl;
            exit(EXIT_FAILURE);
        }

        char poppedValue = top->data;
        Node *temp = top;
        top = top->next;
        delete temp;

        return poppedValue;
    }

    bool isEmpty() const
    {
        return (top == nullptr);
    }

    ~LinkedListStack()
    {
        while (!isEmpty())
        {
            pop();
        }
    }
};

int main()
{

    LinkedListStack stack;

    // Push elements onto the stack
    stack.push('A');
    stack.push('B');
    stack.push('F');
    stack.push('5');

    // pop elements from the stack and print
    while (!stack.isEmpty())
    {
        cout << "Popped:" << stack.pop() << endl;
    }

    return 0;
}