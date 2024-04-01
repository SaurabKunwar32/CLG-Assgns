#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}

// Function to insert a new node at the beginning of a circular doubly linked list
void insertAtBeginning(struct Node** head_ref, int data) {
    struct Node* new_node = newNode(data);

    // If the list is empty, set the new node as the only node
    if (*head_ref == NULL) {
        new_node->next = new_node->prev = new_node;
        *head_ref = new_node;
        return;
    }

    // Otherwise, find the last node and make it the next of the new node
    struct Node* last = (*head_ref)->prev;

    // Make the new node the previous of the last node
    last->next = new_node;
    new_node->prev = last;

    // Make the new node the next of the head
    new_node->next = *head_ref;

    // Make the head's previous the new node
    (*head_ref)->prev = new_node;

    // Update the head_ref to point to the new node
    *head_ref = new_node;
}

// Function to insert a new node at the end of a circular doubly linked list
void insertAtEnd(struct Node** head_ref, int data) {
    struct Node* new_node = newNode(data);

    // If the list is empty, set the new node as the only node
    if (*head_ref == NULL) {
        new_node->next = new_node->prev = new_node;
        *head_ref = new_node;
        return;
    }

    // Otherwise, find the last node and insert the new node after it
    struct Node* last = (*head_ref)->prev;

    // Make the new node the next of the last node
    last->next = new_node;
    new_node->prev = last;

    // Make the next of the new node as head and previous as last
    new_node->next = *head_ref;
    (*head_ref)->prev = new_node;
}

// Function to print a circular doubly linked list starting from the given node
void printList(struct Node* head) {
    struct Node* temp = head;
    if (head != NULL) {
        do {
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp != head);
    }
    printf("\n");
}

// Main function
int main() {
    struct Node* head = NULL;

    // Insert some elements at the beginning
    insertAtBeginning(&head, 10);
    insertAtBeginning(&head, 20);
    insertAtBeginning(&head, 30);

    printf("Circular Doubly Linked List after inserting at beginning: ");
    printList(head);

    // Insert some elements at the end
    insertAtEnd(&head, 40);
    insertAtEnd(&head, 50);

    printf("Circular Doubly Linked List after inserting at end: ");
    printList(head);

    return 0;
}