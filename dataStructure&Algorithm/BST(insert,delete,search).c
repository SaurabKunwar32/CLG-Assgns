#include <stdio.h>
#include <stdlib.h>

// Structure for BST node
struct BSTNode
{
    int data;
    struct BSTNode *left;
    struct BSTNode *right;
};

// Function to create a new BST node
struct BSTNode *createNode(int value)
{
    struct BSTNode *newNode = (struct BSTNode *)malloc(sizeof(struct BSTNode));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert an element in BST tree
struct BSTNode *insertNode(struct BSTNode *root, int value)
{

    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insertNode(root->left, value);

    else if (value > root->data)
        root->right = insertNode(root->right, value);

    return root;
}

// Function to search the required element int the BST tree

struct BSTNode *search(struct BSTNode *root, int value)
{
    if (root == NULL || root->data == value)
        return root;

    if (value < root->data)
        return search(root->left, value);
    else
        return search(root->right, value);
}

void inOrderTraversal(struct BSTNode *root)
{
    if (root != NULL)
    {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}

// Functio to find the minmum value in the BST

struct BSTNode *minValue(struct BSTNode *node)
{
    struct BSTNode *current = node;
    while (current && current->left == NULL)
        current = current->left;
    return current;
}

// To delete the node from the BST tree

struct BSTNode *delete(struct BSTNode *root, int value)
{

    if (root == NULL)
        return root;

    if (value < root->data)
        root->left = delete (root->left, value);

    else if (value > root->data)
        root->right = delete (root->right, value);

    else
    {
        if (root->left == NULL)
        {
            struct BSTNode *temp = root->right;
            free(root);
            return temp;
        }

        else if (root->right == NULL)
        {
            struct BSTNode *temp = root->left;
            free(root);
            return temp;
        }
        struct BSTNode *temp = minValue(root->right);
        root->data = temp->data;
        root->right = delete (root->right, temp->data);
    }
    return root;
}

int main()
{
    struct BSTNode *root = NULL;

    root = insertNode(root, 10);
    root = insertNode(root, 200);
    root = insertNode(root, 300);


    printf("The elements in BST node;\n");
    inOrderTraversal(root);
    printf("\n");

    int searchValue = 10;
    struct BSTNode *result = search(root, searchValue);
    if (result != NULL)
        printf("%d found in BST", searchValue);
    else
        printf("%d found in BST", searchValue);

    printf("\n");
    root = delete (root, 10);
    printf("inOrderTraversal after deletation:\n");
    inOrderTraversal(root);
    printf("\n");

    return 0;
}