#include<iostream>
using namespace std;

void displayArr(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void shellSort(int* arr, int size) {
    for (int interval = size / 2; interval > 0; interval /= 2) {
        for (int i = interval; i < size; i++) {
            int temp = arr[i];

            int j;
            for (j = i; j >= interval && arr[j - interval] > temp; j -= interval) {
                arr[j] = arr[j - interval];
            }

            arr[j] = temp;
        }
    }
}

int main() {
    int arr[] = {100, 90, 80, 70, 60, 50, 40, 30, 20};
    // int arr[] = {50, 20, 3, 12, 99, 106, 48, 36, 2};
    int size = 9;
    
    cout << "\nElements of array in unsorted order are: ";
    displayArr(arr, size);

    shellSort(arr, size);

    cout << "\nElements of array in sorted order are: ";
    displayArr(arr, size);
    
    return 0;
}