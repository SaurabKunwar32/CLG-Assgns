#include <stdio.h>

void ShellSort(int arr[], int size) {
    int gap, i, j, temp;
    for (gap = size / 2; gap > 0; gap /= 2) {
        for (i = gap; i < size; ++i) {
            temp = arr[i];
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

int main() {
    int size = 6;
    int arr[] = {3, 7, 9, 6, 1, 0};

    ShellSort(arr, size);

    printf("Array after sorting:\n");
    for (int i = 0; i < size; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}