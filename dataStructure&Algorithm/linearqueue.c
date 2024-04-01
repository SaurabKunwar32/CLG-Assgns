#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node
struct Node {
    int data;
    struct Node* next;
};

// Define a structure for the queue
struct Queue {
    struct Node *front, *rear;
};

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

// Function to create an empty queue
struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = queue->rear = NULL;
    return queue;
}

// Function to enqueue an element into the queue
void enqueue(struct Queue* queue, int data) {
    struct Node* temp = newNode(data);

    // If the queue is empty, then new node is both front and rear
    if (queue->rear == NULL) {
        queue->front = queue->rear = temp;
        return;
    }

    // Add the new node at the end of queue and change rear
    queue->rear->next = temp;
    queue->rear = temp;
}

// Function to dequeue an element from the queue
int dequeue(struct Queue* queue) {
    // If queue is empty, return -1
    if (queue->front == NULL)
        return -1;

    // Store previous front and move front one node ahead
    struct Node* temp = queue->front;
    int data = temp->data;
    queue->front = queue->front->next;

    // If front becomes NULL, then change rear also as NULL
    if (queue->front == NULL)
        queue->rear = NULL;

    free(temp);

    return data;
}

// Function to check if the queue is empty
int isEmpty(struct Queue* queue) {
    return queue->front == NULL;
}

// Function to print the queue
void printQueue(struct Queue* queue) {
    struct Node* temp = queue->front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function
int main() {
    struct Queue* queue = createQueue();

    // Enqueue some elements
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);

    // Print the queue
    printf("Queue: ");
    printQueue(queue);

    // Dequeue an element
    printf("Dequeued element: %d\n", dequeue(queue));

    // Print the queue after dequeue operation
    printf("Queue after dequeue: ");
    printQueue(queue);

    return 0;
}