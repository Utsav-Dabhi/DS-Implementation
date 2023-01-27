#include<iostream>
using namespace std;

void displayArr(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void bubbleSort(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 1; j < size - i; j++) {
            if (arr[j - 1] > arr[j]) {
                swap(arr[j - 1], arr[j]);
            }
        }
    }
}

int main() {
    // int arr[] = {50, 20, 3, 12, 99, 106, 48, 36, 2};
    int arr[] = {100, 90, 80, 70, 60, 50, 40, 30, 20};
    int size = 9;
    
    cout << "\nElements of array in unsorted order are: ";
    displayArr(arr, size);

    bubbleSort(arr, size);

    cout << "\nElements of array in sorted order are: ";
    displayArr(arr, size);

    return 0;
}