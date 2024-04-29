#include <iostream>
#include <cstdlib> // Include this for malloc

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *root = nullptr;

// Function declarations
struct node *insert(struct node *n, int data);
struct node *createnewNode(int data);

int main()
{
    root = insert(root, 50);
    insert(root, 20);
    insert(root, 70);
    insert(root, 80);
    insert(root, 10);

    return 0; 
}

struct node *insert(struct node *n, int data)
{
    if (n == nullptr) 
    {
        n = createnewNode(data);
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

struct node *createnewNode(int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = nullptr; 
    temp->right = nullptr; 
    return temp; 
}
