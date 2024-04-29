#include <stdio.h>
#include <stdlib.h>

// Structure for AVL tree node
struct AVLNode {
    int data;
    struct AVLNode* left;
    struct AVLNode* right;
    int height;
};

// Function to calculate height of a node
int height(struct AVLNode* node) {
    if (node == NULL)
        return 0;
    return node->height;
}

// Function to perform left rotation on a given node
struct AVLNode* performLeftRotation(struct AVLNode* node) {
    if (node == NULL || node->right == NULL)
        return node;

    // Save the pivot (right child of the current node)
    struct AVLNode* pivot = node->right;

    // Perform rotation
    node->right = pivot->left;
    pivot->left = node;

    // Update heights
    node->height = (height(node->left) > height(node->right) ? height(node->left) : height(node->right)) + 1;
    pivot->height = (height(pivot->left) > height(pivot->right) ? height(pivot->left) : height(pivot->right)) + 1;
    
    // Return the new root of the subtree
    return pivot;
}

// Function to create a new AVL tree node
struct AVLNode* createNode(int value) {
    struct AVLNode* newNode = (struct AVLNode*)malloc(sizeof(struct AVLNode));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 1; // New node is initially added at leaf level
    return newNode;
}

// Main function
int main() {
    // Creating a sample AVL tree
    struct AVLNode* root = createNode(20);
    root->left = createNode(15);
    root->right = createNode(10);
    root->right->left = createNode(15);
    root->right->right = createNode(35);

    // Performing left rotation on the root
    printf("Before left rotation:\n");
    printf("Root data: %d\n", root->data);
    printf("Right child of root before rotation: %d\n", root->right->data);
    printf("Height of root before rotation: %d\n", root->height);
    printf("Height of right child of root before rotation: %d\n", root->right->height);
    printf("\n");

    root = performLeftRotation(root);

    printf("After left rotation:\n");
    printf("Root data: %d\n", root->data);
    printf("Left child of root after rotation: %d\n", root->left->data);
    printf("Height of root after rotation: %d\n", root->height);
    printf("Height of right child of root after rotation: %d\n", root->right->height);

    return 0;
}