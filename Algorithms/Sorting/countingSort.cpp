#include<iostream>
using namespace std;

void displayArr(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void countingSort(int* arr, int size) {
    // maximum element
    int maxi = INT_MIN;
    for (int i = 0; i < size; i++) {
        if (maxi < arr[i]) {
            maxi = arr[i];
        }
    }

    // storing count of occurrences of each element
    int count[maxi + 1];
    for (int i = 0; i < maxi + 1; i++) {
        count[i] = 0;
    }

    for (int i = 0; i < size; i++) {
        count[arr[i]]++;
    }

    // cumulative count
    for (int i = 1; i < maxi + 1; i++) {
        count[i] += count[i - 1];
    }

    // sorting the array using cumulative count
    int output[size];
    for (int i = size - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // copying the sorted elements back to the original array
    for (int i = 0; i < size; i++) {
        arr[i] = output[i];
    }
}

int main() {
    // int arr[] = {100, 90, 80, 70, 60, 50, 40, 30, 20};
    int arr[] = {50, 20, 3, 12, 99, 106, 48, 36, 2};
    int size = 9;
    
    cout << "\nElements of array in unsorted order are: ";
    displayArr(arr, size);

    countingSort(arr, size);

    cout << "\nElements of array in sorted order are: ";
    displayArr(arr, size);
    
    return 0;
}