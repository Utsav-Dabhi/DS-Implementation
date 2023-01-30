#include<iostream>
using namespace std;

void displayArr(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void merge(int* arr, int* L, int lLen, int* R, int rLen) {
    int i = 0, j = 0, k = 0;

    while (i < lLen && j < rLen) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    while (i < lLen) {
        arr[k++] = L[i++];
    }

    while (j < rLen) {
        arr[k++] = R[j++];
    }
}

void mergeSort(int* arr, int n) {
    if (n < 2) {
        return;
    }

    int mid = n / 2;

    int* left = new int[mid];
    int* right = new int[n - mid];

    for (int i = 0; i < mid; i++) {
        left[i] = arr[i];
    }

    for (int i = mid; i < n; i++) {
        right[i - mid] = arr[i];
    }

    mergeSort(left, mid);
    mergeSort(right, n - mid);
    merge(arr, left, mid, right, n - mid);

    free(left);
    free(right);
}

int main() {
    int arr[] = {50, 20, 3, 12, 99, 106, 48, 36, 2};
    // int arr[] = {100, 90, 80, 70, 60, 50, 40, 30, 20};
    int size = 9;

    cout << "\nElements of array in unsorted order are: ";
    displayArr(arr, size);

    mergeSort(arr, size);

    cout << "\nElements of array in sorted order are: ";
    displayArr(arr, size);
    
    return 0;
}