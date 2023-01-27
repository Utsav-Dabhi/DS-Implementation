#include<iostream>
using namespace std;

void displayArr(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void insertionSort(int* arr, int size) {
    for (int i = 1; i < size; i++) {
        int curr = arr[i];

        int j = i - 1;
        while (curr < arr[j] && j >= 0) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = curr;
    }
}

int main() {
    // int arr[] = {50, 20, 3, 12, 99, 106, 48, 36, 2};
    int arr[] = {100, 90, 80, 70, 60, 50, 40, 30, 20};
    int size = 9;
    
    cout << "\nElements of array in unsorted order are: ";
    displayArr(arr, size);

    insertionSort(arr, size);

    cout << "\nElements of array in sorted order are: ";
    displayArr(arr, size);
    
    return 0;
}