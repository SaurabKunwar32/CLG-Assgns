#include <stdio.h>

int binary_search(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid; // Return index of the element
        } else if (arr[mid] < target) {
            left = mid + 1; // Target is in the right subarray
        } else {
            right = mid - 1; // Target is in the left subarray
        }
    }

    return -1; // Element not found
}

int main() {
    int n;
    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements in sorted order: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int x;
    printf("Enter element to search: ");
    scanf("%d", &x);

    int result = binary_search(arr, n, x);
    if (result == -1) {
        printf("Element is not present in array.\n");
    } else {
        printf("Element is present at index: %d\n", result);
    }

    return 0;
}