// Implementing recursivly bubble sort

#include <iostream>
using namespace std;

void bubbleSortRecursive(int arr[], int n) {
    if (n == 1) {
        return;
    }

    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            int temp = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = temp;
        }
    }

    bubbleSortRecursive(arr, n - 1);
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {10, 30, 20, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Array before sorting: ";
    printArray(arr, n);

    bubbleSortRecursive(arr, n);

    cout << "Array after sorting: ";
    printArray(arr, n);

    return 0;
}