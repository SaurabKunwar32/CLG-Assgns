#include <iostream>
#include <conio.h>
using namespace std;

class Node
{
public:
    int data;
    Node *link;

    Node(int value)
    {
        data = value;
        link = nullptr;
    }
};

class LinkListStack
{
private:
    Node *top;

public:

    LinkListStack()
    {
        top = nullptr;
    }
    void push(int value)
    {
        Node *newnode = new Node(value);
        newnode->link = top;
        top = newnode;
    }

    void pop()
    {
        if (isEmpty())
        {
         cout << "List is Empty"<< endl;
         return;
        }
        
        cout << "Element poped:" << top->data << endl;
        Node *temp = top;
        top = top->link;
        free(temp);
    }

    void topElement()
    {
       if(isEmpty()){
         cout << "List is Empty"<< endl;
         return;
        }
        cout << "Top element is :" << top->data << endl;
    }

    bool isEmpty()
    {
        if (top == nullptr)
        {
            return true;
        }

        return false;
    }

    void displayList()
    {
         if (isEmpty())
        {
         cout << "List is Empty"<< endl;
        }
        cout << "List Element is :" << endl;

        Node* temp=top;

        while(temp!=nullptr){
           cout << temp->data << "\t";
           temp=temp->link;
        }

        cout << endl;
    }
};

int main()
{
    LinkListStack LL;
    LL.push(8);
    LL.push(1);
    LL.push(3);
    LL.push(9);
    LL.push(5);
    LL.displayList();
    LL.topElement();
    LL.pop();
    LL.topElement();
    LL.pop();
    LL.displayList();
    LL.topElement();
    LL.pop();
    LL.displayList();
}