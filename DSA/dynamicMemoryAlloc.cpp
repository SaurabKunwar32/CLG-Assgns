#include <iostream>
#include <cstdlib> // For malloc, calloc, realloc, and free

using namespace std;

int main() {
    // Example using malloc
    int* arrayMalloc = (int*)malloc(5 * sizeof(int));
    if (arrayMalloc == nullptr) {
        cerr << "Memory allocation failed using malloc.\n";
        return 1;
    }

    // Assign values to the allocated memory
    for (int i = 0; i < 5; ++i) {
        arrayMalloc[i] = i + 1;
    }

    // Print values
    cout << "Values using malloc: ";
    for (int i = 0; i < 5; ++i) {
        cout << arrayMalloc[i] << " ";
    }
    cout << "\n";

    // Example using calloc
    int* arrayCalloc = (int*)calloc(5, sizeof(int));
    if (arrayCalloc == nullptr) {
        cerr << "Memory allocation failed using calloc.\n";
        free(arrayMalloc); // Release previously allocated memory
        return 1;
    }

    // Assign values to the allocated memory
    for (int i = 0; i < 5; ++i) {
        arrayCalloc[i] = i + 10;
    }

    // Print values
    cout << "Values using calloc: ";
    for (int i = 0; i < 5; ++i) {
        cout << arrayCalloc[i] << " ";
    }
    cout << "\n";

    // Example using realloc
    int* arrayRealloc = (int*)realloc(arrayMalloc, 10 * sizeof(int));
    if (arrayRealloc == nullptr) {
        cerr << "Memory reallocation failed using realloc.\n";
        free(arrayMalloc);
        free(arrayCalloc); // Release previously allocated memory
        return 1;
    }

    // Assign values to the reallocated memory
    for (int i = 5; i < 10; ++i) {
        arrayRealloc[i] = i + 20;
    }

    // Print values
    cout << "Values after realloc: ";
    for (int i = 0; i < 10; ++i) {
        cout << arrayRealloc[i] << " ";
    }
    cout << "\n";

    // Release memory
    free(arrayRealloc);
    free(arrayCalloc);

    return 0;
}