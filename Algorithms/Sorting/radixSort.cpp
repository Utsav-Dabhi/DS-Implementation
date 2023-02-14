#include<iostream>
using namespace std;

void displayArr(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int getMax(int* arr, int size) {
    int maxi = INT_MIN;
    for (int i = 0; i < size; i++) {
        if (maxi < arr[i]) {
            maxi = arr[i];
        }
    }

    return maxi;
}

void countingSort(int* arr, int size, int place) {
    int maxi = getMax(arr, size);

    int* count = new int[maxi + 1];
    for (int i = 0; i < maxi + 1; i++) {
        count[i] = 0;
    }

    for (int i = 0; i < size; i++) {
        count[(arr[i] / place) % 10]++;
    }

    for (int i = 1; i < maxi + 1; i++) {
        count[i] += count[i - 1];
    }

    int* output = new int[size];
    for (int i = size - 1; i >= 0; i--) {
        output[count[(arr[i] / place) % 10] - 1] = arr[i];
        count[(arr[i] / place) % 10]--;
    }

    for (int i = 0; i < size; i++) {
        arr[i] = output[i];
    }

    free(output);
    free(count);
}

void radixSort(int* arr, int size) {
    int maxi = getMax(arr, size);

    for (int place = 1; maxi / place > 0; place *= 10) {
        countingSort(arr, size, place);
    }
}

int main() {
    int arr[] = {100, 90, 80, 70, 60, 50, 40, 30, 20};
    // int arr[] = {50, 20, 3, 12, 99, 106, 48, 36, 2};
    int size = 9;
    
    cout << "\nElements of array in unsorted order are: ";
    displayArr(arr, size);

    radixSort(arr, size);

    cout << "\nElements of array in sorted order are: ";
    displayArr(arr, size);
    
    return 0;
}