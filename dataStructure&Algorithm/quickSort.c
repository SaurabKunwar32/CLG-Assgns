#include<stdio.h>

void QuickSort(int arr[], int start, int end);
int partition(int arr[], int start, int end);
void swap(int *a, int *b);

int main() {
    int arr[] = {6, 3, 9, 5, 2, 8};
    int size = sizeof(arr) / sizeof(int);
    QuickSort(arr, 0, size - 1);

    printf("Sorted array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}

void QuickSort(int arr[], int start, int end) {
    if (start < end) {
        int pivot = partition(arr, start, end);
        QuickSort(arr, start, pivot);
        QuickSort(arr, pivot + 1, end);
    }
}

int partition(int arr[], int start, int end) {
    int pivot = arr[start];
    int i = start - 1;
    int j = end + 1;
    while (1) {
        do {
            i++;
        } while (arr[i] < pivot);

        do {
            j--;
        } while (arr[j] > pivot);

        if (i >= j)
            return j;

        swap(&arr[i], &arr[j]);
    }
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}