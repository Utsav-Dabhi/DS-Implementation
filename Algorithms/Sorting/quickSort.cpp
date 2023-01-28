#include<iostream>
using namespace std;

void displayArr(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int randomizedPartition(int* arr, int start, int end) {
    int randIndex = start + (rand() % (end - start + 1));
    swap(arr[randIndex], arr[end]);

    int pivot = arr[end];
    int pIndex = start;
    for (int i = start; i < end; i++) {
        if (arr[i] <= pivot) {
            swap(arr[i], arr[pIndex]);
            pIndex++;
        }
    }

    swap(arr[pIndex], arr[end]);

    return pIndex;
}

void quickSort(int* arr, int start, int end) {
    if (start >= end)
        return;

    int partitionIndex = randomizedPartition(arr, start, end);
    quickSort(arr, start, partitionIndex - 1);
    quickSort(arr, partitionIndex + 1, end);
}

void Sort(int* arr, int size) {
    int start = 0, end = size - 1;

    quickSort(arr, start, end);
}

int main() {
    // int arr[] = {50, 20, 3, 12, 99, 106, 48, 36, 2};
    int arr[] = {100, 90, 80, 70, 60, 50, 40, 30, 20};
    int size = 9;

    cout << "\nElements of array in unsorted order are: ";
    displayArr(arr, size);

    Sort(arr, size);

    cout << "\nElements of array in sorted order are: ";
    displayArr(arr, size);
    
    return 0;
}