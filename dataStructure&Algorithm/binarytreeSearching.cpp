#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *root = nullptr;

// Function declarations
struct node *insert(struct node *n, int data);
struct node *search(struct node *root, int key);

int main()
{
    root = insert(root, 50);
    insert(root, 20);
    insert(root, 70);
    insert(root, 80);
    insert(root, 10);

    if (search(root, 20) != nullptr)
    {
        cout << "20 found" << endl;
    }
    else
    {
        cout << "20 not found" << endl;
    }
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
    else
    {
        n->right = insert(n->right, data);
    }
    return n;
}

struct node *search(struct node *root, int key)
{
    if (root == nullptr || root->data == key)
    {
        return root;
    }

    if (key < root->data)
    {
        return search(root->left, key); // Change 'data' to 'key'
    }
    return search(root->right, key); // Change 'data' to 'key'
}
