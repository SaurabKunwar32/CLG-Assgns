#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *root = nullptr;

struct node *insert(struct node *n, int data); // Function declaration

void inorder(struct node *root);

int main()
{
    root = insert(root, 50);
    insert(root, 20);
    insert(root, 30);
    insert(root, 40);
    insert(root, 60);
    insert(root, 70);
    insert(root, 80);
    insert(root, 10);
    inorder(root);
    return 0; // Added return statement
}

struct node *insert(struct node *n, int data)
{
    if (n == nullptr)
    {
        n = new node;
        n->data = data;
        n->left = nullptr;
        n->right = nullptr;
    }
    else if (data < n->data)
    {
        n->left = insert(n->left, data);
    }
    else if (data > n->data)
    {
        n->right = insert(n->right, data);
    }
    return n;
}

void inorder(struct node *root)
{
    if (root != nullptr)
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

