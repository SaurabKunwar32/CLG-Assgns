#include <stdio.h>
#include <stdlib.h>

// Structure for BST node
struct BSTNode {
    int data;
    struct BSTNode* left;
    struct BSTNode* right;
};

// Function to create a new BST node
struct BSTNode* createNode(int value) {
    struct BSTNode* newNode = (struct BSTNode*)malloc(sizeof(struct BSTNode));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node into BST
struct BSTNode* insertNode(struct BSTNode* root, int value) {
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insertNode(root->left, value);
    else if (value > root->data)
        root->right = insertNode(root->right, value);

    return root;
}

// Function to search for a value in BST
struct BSTNode* search(struct BSTNode* root, int value) {
    if (root == NULL || root->data == value)
        return root;

    if (value < root->data)
        return search(root->left, value);
    else
        return search(root->right, value);
}

// Function to find the minimum value node in a BST
struct BSTNode* minValueNode(struct BSTNode* node) {
    struct BSTNode* current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

// Function to find the maximum value node in a BST
struct BSTNode* maxValueNode(struct BSTNode* node) {
    struct BSTNode* current = node;
    while (current && current->right != NULL)
        current = current->right;
    return current;
}
// Function for in-order traversal of BST to display every element
void inOrderTraversal(struct BSTNode* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}

// Main function for BST
int main() {
    struct BSTNode* root = NULL;

    // Inserting nodes into BST
    root = insertNode(root, 50);
    root = insertNode(root, 30);
    root = insertNode(root, 20);
    root = insertNode(root, 40);
    root = insertNode(root, 70);
    root = insertNode(root, 60);
    root = insertNode(root, 80);

    // Displaying every element in BST
    printf("Elements in BST: ");
    inOrderTraversal(root);
    printf("\n");

    // Searching for a value in BST
    int searchValue = 60;
    struct BSTNode* result = search(root, searchValue);
    if (result != NULL)
        printf("%d found in BST.\n", searchValue);
    else
        printf("%d not found in BST.\n", searchValue);

    // Finding the minimum value in BST
    struct BSTNode* minNode = minValueNode(root);
    printf("Minimum value in BST: %d\n", minNode->data);

    // Finding the maximum value in BST
    struct BSTNode* maxNode = maxValueNode(root);
    printf("Maximum value in BST: %d\n", maxNode->data);

    return 0;
}