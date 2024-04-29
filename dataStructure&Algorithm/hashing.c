#include <stdio.h>
#include <stdlib.h>

// Define the size of the hash table
#define TABLE_SIZE 10

// Define a structure for each node in the hash table
struct Node {
    int data;
    struct Node *next;
};

// Define the hash table
struct Node *hashTable[TABLE_SIZE] = {NULL};

// Hash function to map integers to indices in the hash table
int hashFunction(int key) {
    return key % TABLE_SIZE;
}

// Function to insert a value into the hash table
void insert(int value) {
    // Calculate the index for the given value
    int index = hashFunction(value);

    // Create a new node
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;

    // Insert the new node at the beginning of the linked list at the calculated index
    if (hashTable[index] == NULL) {
        hashTable[index] = newNode;
    } else {
        newNode->next = hashTable[index];
        hashTable[index] = newNode;
    }
}

// Function to display the contents of the hash table
void display() {
    printf("Hash Table:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("[%d]: ", i);
        struct Node *temp = hashTable[i];
        while (temp != NULL) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    // Insert some values into the hash table
    insert(50);
    insert(80);
    insert(20);
    insert(95);
    insert(15);

    // Display the hash table
    display();

    return 0;
}