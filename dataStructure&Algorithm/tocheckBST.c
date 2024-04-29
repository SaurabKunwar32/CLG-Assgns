#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

// Structure for tree node
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to create a new tree node
struct TreeNode* createNode(int value) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to check if the tree is a BST or not
bool isBSTUtil(struct TreeNode* root, int min, int max) {
    if (root == NULL)
        return true;

    if (root->data < min || root->data > max)
        return false;

    return isBSTUtil(root->left, min, root->data - 1) && isBSTUtil(root->right, root->data + 1, max);
}

bool isBST(struct TreeNode* root) {
    return isBSTUtil(root, INT_MIN, INT_MAX);
}

// Main function
int main() {
    // Constructing a binary tree
    struct TreeNode* root = createNode(4);
    root->left = createNode(2);
    root->right = createNode(5);
    root->left->left = createNode(1);
    root->left->right = createNode(3);

    // Checking if the tree is a BST
    if (isBST(root))
        printf("The tree is a Binary Search Tree (BST).\n");
    else
        printf("The tree is not a Binary Search Tree (BST).\n");

    return 0;
}