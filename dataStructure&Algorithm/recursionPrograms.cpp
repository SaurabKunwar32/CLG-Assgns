// BUBBLE SORTING***************************************************************************************************************

// #include <iostream>
// using namespace std;



// void bubbleSort(int arr[], int n) {
//     for (int i = 0; i < n - 1; i++) {
//         for (int j = 0; j < n - i - 1; j++) {
//             if (arr[j] > arr[j + 1]) {
//                 // Swap arr[j] and arr[j + 1]
//                 int temp = arr[j];
//                 arr[j] = arr[j + 1];
//                 arr[j + 1] = temp;
//             }
//         }
//     }
// }

// int main() {
//     int n;
//     cout << "Enter the number of elements: ";
//     cin >> n;

//     int arr[n];
//     cout << "Enter " << n << " elements:\n";
//     for (int i = 0; i < n; i++) {
//         cin >> arr[i];
//     }

//     bubbleSort(arr, n);

//     cout << "Sorted array:\n";
//     for (int i = 0; i < n; i++) {
//         cout << arr[i] << " ";
//     }
//    cout << endl;

//     return 0;
// }




// SELECTION SORT       *************************************************************************************************************
// #include <iostream>
// using namespace std;

// void selectionSort(int arr[], int n) {
//     for (int i = 0; i < n - 1; i++) {
//         int minIndex = i;
//         for (int j = i + 1; j < n; j++) {
//             if (arr[j] < arr[minIndex]) {
//                 minIndex = j;
//             }
//         }
//         // Swap arr[i] with the minimum element
//         int temp = arr[i];
//         arr[i] = arr[minIndex];
//         arr[minIndex] = temp;
//     }
// }

// int main() {
//     int n;
//     cout << "Enter the number of elements: ";
//   cin >> n;

//     int arr[n];
//    cout << "Enter " << n << " elements:\n";
//     for (int i = 0; i < n; i++) {
//         cin >> arr[i];
//     }

//     selectionSort(arr, n);

//    cout << "Sorted array:\n";
//     for (int i = 0; i < n; i++) {
//       cout << arr[i] << " ";
//     }
//     cout <<endl;

//     return 0;
// }






// INSERTION SORT        *************************************************************************************************************
// #include <iostream>
// using namespace std;

// void insertionSort(int arr[], int n) {
//     for (int i = 1; i < n; i++) {
//         int key = arr[i];
//         int j = i - 1;
        
//         // Move elements of arr[0..i-1], that are greater than key,
//         // to one position ahead of their current position
//         while (j >= 0 && arr[j] > key) {
//             arr[j + 1] = arr[j];
//             j--;
//         }
//         arr[j + 1] = key;
//     }
// }

// int main() {
//     int n;
//     cout << "Enter the number of elements: ";
//     cin >> n;

//     int arr[n];
//     cout << "Enter " << n << " elements:\n";
//     for (int i = 0; i < n; i++) {
//         cin >> arr[i];
//     }

//     insertionSort(arr, n);

//     cout << "Sorted array:\n";
//     for (int i = 0; i < n; i++) {
//         cout << arr[i] << " ";
//     }
//     cout << endl;

//     return 0;
// }




// Heap SORT        *************************************************************************************************************

