#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10

// Define a structure for each slot in the hash table
struct Slot {
    int key;
    int data; // Assuming integer data for simplicity
    int status; // 0 for empty, 1 for filled, -1 for deleted
};

// Define the hash table
struct Slot hashTable[TABLE_SIZE];

// Function to initialize the hash table
void initializeHashTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i].key = -1;
        hashTable[i].status = 0; // Marking all slots as empty
    }
}

// Hash function to map keys to indices in the hash table
int hashFunction(int key) {
    return key % TABLE_SIZE;
}

// Function to insert a key-value pair into the hash table
void insert(int key, int data) {
    int index = hashFunction(key);
    int i = index;
    do {
        if (hashTable[i].status == 0 || hashTable[i].status == -1) {
            hashTable[i].key = key;
            hashTable[i].data = data;
            hashTable[i].status = 1; // Marking slot as filled
            printf("Key %d inserted at index %d\n", key, i);
            return;
        }
        i = (i + 1) % TABLE_SIZE; // Linear probing
    } while (i != index);
    printf("Hash table is full. Cannot insert key %d.\n", key);
}

// Function to search for a key in the hash table
int search(int key) {
    int index = hashFunction(key);
    int i = index;
    do {
        if (hashTable[i].status == 1 && hashTable[i].key == key) {
            printf("Key %d found at index %d\n", key, i);
            return hashTable[i].data;
        }
        i = (i + 1) % TABLE_SIZE; // Linear probing
    } while (i != index);
    printf("Key %d not found in the hash table\n", key);
    return -1; // Return -1 if key not found
}

int main() {
    initializeHashTable();

    // Insert some key-value pairs into the hash table
    insert(20, 200);
    insert(10, 500);
    insert(90, 300);
    insert(11, 150);

    // Search for keys in the hash table
    printf("Searching for keys:\n");
    search(10);
    search(11);

    return 0;
}