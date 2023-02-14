#include <iostream>
#include <vector>
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

void insertAtEnd(MyArray* a, int num) {
    a->ptr[a->used_size] = num;
    a->used_size++;
}

void deleteAtEnd(MyArray* a) {
    a->used_size--;
    cout << "\nLast element deleted Successfully" << endl;
}

void insertInBetween(MyArray* a, int num, int pos) {
    a->used_size++;

    for (int i = a->used_size - 1; i >= pos; i--) {
        a->ptr[i] = a->ptr[i - 1];
    }

    a->ptr[pos - 1] = num;
}

void deleteFromBetween(MyArray* a, int pos) {
    for (int i = pos - 1; i < a->used_size; i++) {
        a->ptr[i] = a->ptr[i + 1];
    }

    a->used_size--;
}

void searchArray(MyArray* a, int ele, char ch = 'n') {
    vector<int> v;

    int ifExist = 0, firstOcc = -1, noOfOccurs = 0;
    for (int i = 0; i < a->used_size; i++) {
        if (a->ptr[i] == ele) {
            ifExist = 1;
            if (firstOcc == -1) {
                firstOcc = i + 1;
            }

            v.push_back(i + 1);

            noOfOccurs++;
        }
    }

    if (ch == 'n') {
        if (ifExist) {
            cout << "\nElement found at position: " << firstOcc << endl;
        } else {
            cout << "\nThe given element is not present!" << endl;
        }
    } else if (ch == 'y') {
        if (ifExist) {
            cout << "\nFirst occurrence of element '" << ele << "' is at position: " << firstOcc;
            cout << "\nNumber of occurrences of element '" << ele << "': " << noOfOccurs;
            cout << "\nThe given element was found at positons: [ ";
            for (auto u: v) {
                cout << u << " ";
            }
            cout << "]" << endl;
        } else {
            cout << "\nThe given element is not present!" << endl;
        }
    }
}

void replace(MyArray* a, int ele, int pos) {
    if (a->used_size == 0) {
        cout << "\nNo elements in Array to replace!" << endl;
        return;
    }

    a->ptr[pos - 1] = ele;
}

// functions related to sorting
int Partition(MyArray* a, int start, int end) {
    int pivot = a->ptr[end];

    int partitionIndex = start;
    for (int i = start; i < end; i++) {
        if (a->ptr[i] <= pivot) {
            swap(a->ptr[i], a->ptr[partitionIndex]);
            partitionIndex++;
        }
    }

    swap(a->ptr[partitionIndex], a->ptr[end]);
    return partitionIndex;
}

void QuickSort(MyArray* a, int start, int end) {
    if (start < end) {
        int pIndex = Partition(a, start, end);
        QuickSort(a, start, pIndex - 1);
        QuickSort(a, pIndex + 1, end);
    }
}

void sort(MyArray* a) {
    QuickSort(a, 0, a->used_size - 1);
}
// sorting functions end

void showArray(MyArray* a) {
    if (a->used_size == 0) {
        cout << "\nNo elements in Array to print!" << endl;
        return;
    }

    cout << "\nThe elements of array are -> ";
    for (int i = 0; i < a->used_size; i++) {
        cout << a->ptr[i] << " ";
    }
    cout << endl;
}

void menu() {
    cout << "\nWhat operation do you want to perform?";
    cout << "\n1. Create an array";
    cout << "\n2. Insert element (at end)";
    cout << "\n3. Delete element (from end)";
    cout << "\n4. Insert element (in between)";
    cout << "\n5. Delete element (from between)";
    cout << "\n6. Search an element";
    cout << "\n7. Replace element";
    cout << "\n8. Sort array";
    cout << "\n9. Print array";
    cout << "\n10. Exit";
    cout << "\nChoice: ";
}

int main() {
    MyArray newArray;

    int i = 0;
    while (i != 10) {
        menu();
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

                continue;

            case 2:
                int num;
                cout << "\nEnter the element to be inserted: ";
                cin >> num;

                if (newArray.used_size == newArray.total_size) {
                    cout << "\nFull Capacity reached! Cannot input new elements" << endl;
                    cout << "Total size: " << newArray.total_size << " Used size: " << newArray.used_size << endl;
                } else {
                    insertAtEnd(&newArray, num);
                    showArray(&newArray);
                }

                continue;

            case 3:
                if (newArray.used_size == 0) {
                    cout << "\nEmpty Array! Cannot delete element" << endl;
                } else {
                    deleteAtEnd(&newArray);
                }

                continue;

            case 4:
                int ele, pos;

                if (newArray.used_size == newArray.total_size) {
                    cout << "\nArray is full. Cannot enter new element" << endl;
                } else {
                    cout << "\nEnter the element and position seperated by space: ";
                    cin >> ele >> pos;

                    while (pos > newArray.total_size) {
                        cout << "\nPosition greater than size of Array! Cannot enter element";
                        cout << "\nRe-enter position: ";
                        cin >> pos;
                    }

                    while (pos <= 0) {
                        cout << "\nPosition cannot be less than 1";
                        cout << "\nRe-enter position: ";
                        cin >> pos;
                    }

                    insertInBetween(&newArray, ele, pos);
                    showArray(&newArray);
                }

                continue;

            case 5:
                if (newArray.used_size == 0) {
                    cout << "\nNo elements to delete" << endl;
                } else {
                    int ind;
                    cout << "\nEnter the element index's to be deleted: ";
                    cin >> ind;

                    while (ind > newArray.total_size || ind <= 0) {
                        cout << "\nYou have entered index greater than total size or less than 1";
                        cout << "\nRe-enter position: ";
                        cin >> ind;
                    }

                    deleteFromBetween(&newArray, ind);
                    showArray(&newArray);
                }

                continue;

            case 6:
                if (newArray.used_size == 0) {
                    cout << "\nNo elements in array to search" << endl;
                } else {
                    int searchEle;
                    cout << "\nEnter the element to be searched: ";
                    cin >> searchEle;

                    while (searchEle > INT_MAX || searchEle < INT_MIN) {
                        cout << "\nOnly 32-bit integers are allowed";
                        cout << "\nRe-enter element: ";
                        cin >> searchEle;
                    }

                    char ch;
                    cout << "\nDo you want to find no of occurrences? (Y/N): ";
                    cin >> ch;

                    ch = char(tolower(ch));
                    if (ch == 'y') {
                        searchArray(&newArray, searchEle, 'y');
                    } else {
                        searchArray(&newArray, searchEle);
                    }
                }

                continue;

            case 7:
                if (newArray.used_size == 0) {
                    cout << "\nNo elements in array to replace" << endl;
                } else {
                    cout << "\nEnter the element and position seperated by space: ";
                    cin >> ele >> pos;

                    while (pos > newArray.total_size) {
                        cout << "\nPosition greater than size of Array! Cannot enter element";
                        cout << "\nRe-enter position: ";
                        cin >> pos;
                    }

                    while (pos <= 0) {
                        cout << "\nPosition cannot be less than 1";
                        cout << "\nRe-enter position: ";
                        cin >> pos;
                    }

                    replace(&newArray, ele, pos);
                    showArray(&newArray);
                }
                
                continue;

            case 8:
                if (newArray.used_size == 0) {
                    cout << "\nNo elements in array to sort" << endl;
                } else {
                    sort(&newArray);
                    cout << "\nArray after sorting:";
                    showArray(&newArray);
                }

                continue;
            
            case 9:
                showArray(&newArray);
                continue;
            
            case 10:
                cout << "\nExited successfully";
                break;
        }
    }

    return 0;
}
