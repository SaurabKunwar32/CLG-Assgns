#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Structure for binary tree node
struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Function to create a new binary tree node
struct TreeNode* createNode(int value) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to create a binary tree from an array
struct TreeNode* createBinaryTree(int arr[], int start, int end) {
    if (start > end)
        return NULL;

    int mid = (start + end) / 2;
    struct TreeNode* root = createNode(arr[mid]);

    root->left = createBinaryTree(arr, start, mid - 1);
    root->right = createBinaryTree(arr, mid + 1, end);

    return root;
}

// Function to calculate height of a binary tree
int heightOfBinaryTree(struct TreeNode* root) {
    if (root == NULL)
        return 0;

    int leftHeight = heightOfBinaryTree(root->left);
    int rightHeight = heightOfBinaryTree(root->right);

    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

// Function to find maximum element in a binary tree
int findMax(struct TreeNode* root) {
    if (root == NULL)
        return INT_MIN;

    int max = root->data;
    int leftMax = findMax(root->left);
    int rightMax = findMax(root->right);

    if (leftMax > max)
        max = leftMax;
    if (rightMax > max)
        max = rightMax;

    return max;
}

// Function to check if a binary tree is balanced or not
int isBalanced(struct TreeNode* root) {
    if (root == NULL)
        return 1;

    int leftHeight = heightOfBinaryTree(root->left);
    int rightHeight = heightOfBinaryTree(root->right);

    if (abs(leftHeight - rightHeight) <= 1 && isBalanced(root->left) && isBalanced(root->right))
        return 1;

    return 0;

    
}

// Main function
int main() {
    // Sample array to create binary tree
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    // Creating binary tree from the array
    struct TreeNode* root = createBinaryTree(arr, 0, n - 1);

    // Calculating height of the binary tree
    printf("Height of the binary tree: %d\n", heightOfBinaryTree(root));

    // Finding maximum element in the binary tree
    printf("Maximum element in the binary tree: %d\n", findMax(root));

    // Checking if the binary tree is balanced
    if (isBalanced(root))
        printf("Binary tree is balanced.\n");
    else
        printf("Binary tree is not balanced.\n");

    return 0;
}