#include<iostream>
using namespace std;

void displayArr(int* arr, int size) {
    cout << "\nThe elements of array are: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int binarySearchIterative(int* arr, int size, int ele) {
    int start = 0, end = size - 1;
    int mid;

    while (start <= end) {
        mid = start + (end - start) / 2;

        if (arr[mid] == ele) {
            return mid;
        } else if (arr[mid] < ele) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    return -1;
}

int binarySearchRecursive(int* arr, int start, int end, int ele) {
    int mid = start + (end - start) / 2;

    if (start <= end) {
        if (arr[mid] == ele) {
            return mid;
        } else if (arr[mid] < ele) {
            return binarySearchRecursive(arr, mid + 1, end, ele);
        } else {
            return binarySearchRecursive(arr, start, mid - 1, ele);
        }
    }

    return -1;
}

int main() {
    int arr[] = {10, 20, 30, 40, 50, 60, 70, 80};
    int size = 8, ele;

    displayArr(arr, size);

    cout << "\nIterative Binary Search ->";
    cout << "\nEnter element to be searched: ";
    cin >> ele;

    int res1 = binarySearchIterative(arr, size, ele);
    if (res1 == -1) {
        cout << "Element is not present in array!" << endl;
    } else {
        cout << "Element is present in array!" << endl;
    }

    cout << "\nRecursive Binary Search ->";
    cout << "\nEnter element to be searched: ";
    cin >> ele;

    int start = 0, end = size - 1;
    int res2 = binarySearchRecursive(arr, start, end, ele);
    if (res2 == -1) {
        cout << "Element is not present in array!" << endl;
    } else {
        cout << "Element is present in array!" << endl;
    }
    
    return 0;
}