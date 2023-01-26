#include<iostream>
using namespace std;

void displayArr(int* arr, int size) {
    cout << "\nThe elements of array are: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void linearSearch(int* arr, int size, int ele) {
    bool isPresent = 0;

    for (int i = 0; i < size; i++) {
        if (arr[i] == ele) {
            isPresent = 1;
            break;
        }
    }

    if (isPresent) {
        cout << "\nElement is present in array!" << endl;
    } else {
        cout << "\nElement is not present in array!" << endl;
    }
}

int main() {
    int arr[] = {10, 40, 30, 60, 20, 90, 50};
    int size = 7;

    displayArr(arr, size);

    int ele;
    cout << "\nEnter element to be searched: ";
    cin >> ele;

    linearSearch(arr, size, ele);
    
    return 0;
}