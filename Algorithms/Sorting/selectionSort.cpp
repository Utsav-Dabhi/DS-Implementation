#include<iostream>
using namespace std;

void displayArr(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void selectionSort(int* arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;

        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        swap(arr[i], arr[minIndex]);
    }
}

int main() {
    // int arr[] = {50, 20, 3, 12, 99, 106, 48, 36, 2};
    int arr[] = {100, 90, 80, 70, 60, 50, 40, 30, 20};
    int size = 9;
    
    cout << "\nElements of array in unsorted order are: ";
    displayArr(arr, size);

    selectionSort(arr, size);

    cout << "\nElements of array in sorted order are: ";
    displayArr(arr, size);
    
    return 0;
}