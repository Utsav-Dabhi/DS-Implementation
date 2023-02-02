#include<iostream>
#include<math.h>
#include<vector>
using namespace std;

vector<int> heapArr;

// helper functions
int getParentIndex(int childIndex) { return (childIndex - 1) / 2; }
int getLeftChildIndex(int index) { return 2 * index + 1; }
int getRightChildIndex(int index) { return 2 * index + 2; }

bool hasParent(int index) { return getParentIndex(index) >= 0; }
bool hasLeftChild(int index) { return getLeftChildIndex(index) < heapArr.size(); }
bool hasRightChild(int index) { return getRightChildIndex(index) < heapArr.size(); }

int getParent(int index) { return heapArr[getParentIndex(index)]; }
int getLeftChild(int index) { return heapArr[getLeftChildIndex(index)]; }
int getRightChild(int index) { return heapArr[getRightChildIndex(index)]; }
//

void heapifyUp() {
    int ind = heapArr.size() - 1;

    while (hasParent(ind) && getParent(ind) > heapArr[ind]) {
        swap(heapArr[getParentIndex(ind)], heapArr[ind]);
        ind = getParentIndex(ind);
    }
}

void heapifyUp(int ind) {
    while (hasParent(ind) && getParent(ind) > heapArr[ind]) {
        swap(heapArr[getParentIndex(ind)], heapArr[ind]);
        ind = getParentIndex(ind);
    }
}

void insertKey(int ele) {
    heapArr.push_back(ele);

    heapifyUp();
}

void heapifyDown() {
    int ind = 0;

    while (hasLeftChild(ind)) {
        int smallestChildIndex = getLeftChildIndex(ind);

        if (hasRightChild(ind) && getRightChild(ind) < getLeftChild(ind)) {
            smallestChildIndex = getRightChildIndex(ind);
        }

        if (heapArr[ind] < heapArr[smallestChildIndex]) {
            break;
        } else {
            swap(heapArr[smallestChildIndex], heapArr[ind]);
            ind = smallestChildIndex;
        }
    }
}

void deleteKey() {
    heapArr[0] = heapArr[heapArr.size() - 1];
    heapArr.pop_back();

    heapifyDown();
}

void getMini() {
    if (heapArr.size() == 0) {
        cout << "\nNo elements in heap!" << endl;
    } else {
        cout << "\nPeek: " << heapArr[0] << endl;
    }
}

void decreaseKey(int ele, int ind) {
    heapArr[ind] = ele;

    heapifyUp(ind);
}

// functions related to printing
void printSpace(int count) {
    for (int x = 0; x < count; x++) {
        cout << " ";
    }
}

void printQueue() {
    int height = ceil(log(heapArr.size()) + 1);   //+1 handle the last leaves
    int width = pow(2, height) * height;
    int index = 0;

    cout << "\nThe elements of heap are: \n";
    for (int x = 0; x <= height; x++) { //for each level of the tree
        for (int z = 0; z < pow(2, x); z++) {   // for each node on that tree level
            int digitWidth = 1;
            if (heapArr[index] != 0) {
                digitWidth = floor(log10(abs(heapArr[index]))) + 1;
            }
            printSpace(width/(pow(2, x)) - digitWidth);
            if (index < heapArr.size()) {
                cout << heapArr[index++];
            } else {
                cout << " ";
            }
            printSpace(width/(pow(2, x)));
        }
        cout << endl;
    }
}
// printing functions end

int main() {
    int i = 0;
    while (i != 5) {
        cout << "\nWhat operation do you want to perform?\n1. Insert \n2. Delete\n3. Get smallest key\n4. Decrease Key\n5. Exit\nChoice: ";
        cin >> i;

        switch(i) {
            case 1:
                int num;
                cout << "\nEnter element to be inserted: ";
                cin >> num;

                insertKey(num);
                printQueue();

                break;

            case 2:
                deleteKey();
                printQueue();

                break;

            case 3:
                getMini();
                break;

            case 4:
                int i;
                cout << "\nEnter new element and index: ";
                cin >> num >> i;

                while (i >= heapArr.size()) {
                    cout << "\nIndex cannot be greater than size of heap\n";
                    cout << "Re-enter value: ";
                    cin >> i;
                }

                decreaseKey(num, i);
                printQueue();

                break;

            case 5:
                cout << "\nExited successfully";
                break;
        }
    }

    return 0;
}