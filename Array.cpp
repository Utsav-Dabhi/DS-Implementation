#include <iostream>
using namespace std;

struct MyArray {
    int total_size;
    int used_size;
    int* ptr;
};

void createArray(MyArray* a, int tSize, int uSize) {
    // a->total_size = tSize;
    (*a).total_size = tSize;
    (*a).used_size = uSize;
    (*a).ptr = (int*) new int(tSize);
}

void setValue(MyArray* a) {
    int n;
    cout << "\nEnter the elements of array ->\n";
    for (int i = 0; i < a->used_size; i++) {
        cout << "Enter element " << i << ": ";
        cin >> a->ptr[i];
    }

    cout << "\nYou have entered -> ";
    for (int i = 0; i < a->used_size; i++) {
        cout << a->ptr[i] << " ";
    }
    cout << endl;
}

void showArray(MyArray* a) {
    cout << "\nThe elements of array are -> ";
    for (int i = 0; i < a->used_size; i++) {
        cout << a->ptr[i] << " ";
    }
    cout << endl;
}

int main() {
    MyArray newArray;

    int i = 0;
    int arrayFlag = 0;
    while (i != 8) {
        cout << "\nWhat operation do you want to perform?\n1. Create an array\n2. Insert element (at end)\n3. Delete element (from end)\n4. Insert element (in between)\n5. Delete element (from between)\n6. Search an element\n7. Print array\n8. Exit\nChoice: ";
        cin >> i;

        switch(i) {
            case 1:
                int t, n;
                cout << "\nEnter the total size (t) and use size (n) for array seperated by space: ";
                cin >> t >> n;

                while ( t < n) {
                    cout << "\nUse size cannot be greater than total size\n";
                    cout << "Re-enter values: ";
                    cin >> t >> n;
                }
                createArray(&newArray, t, n);
                setValue(&newArray);
                arrayFlag = 1;
                continue;

            case 7:
                if (arrayFlag == 0) {
                    cout << "\nNo array to print" << endl;
                } else {
                    showArray(&newArray);
                }
                continue;
            
            case 8:
                cout << "\nExited successfully";
                break;
        }

    }

    return 0;
}
