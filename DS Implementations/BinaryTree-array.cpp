#include<iostream>
#include <cstring>
#include<math.h>
using namespace std;

struct BinTree {
    int level;
    int size;
    int* arr;
};

void createBT(BinTree* bt, int level) {
    bt->level = level;
    bt->size = pow(2, level) - 1;
    bt->arr = new int[bt->size];
    // bt->arr[0] = -2147483648;

    for (int i = 0; i < bt->size; i++) {
        bt->arr[i] = -2147483648;
    }
}

void leftChild(BinTree* bt, int ele, int pIndex) {
    if (bt->arr[pIndex] == -2147483648) {
        cout << "\nParent not found, cannot set it's child" << endl;
    } else {
        bt->arr[(pIndex * 2) + 1] = ele;
    }
}

void rightChild(BinTree* bt, int ele, int pIndex) {
    if (bt->arr[pIndex] == -2147483648) {
        cout << "\nParent not found, cannot set it's child" << endl;
    } else {
        bt->arr[(pIndex * 2) + 2] = ele;
    }
}

void printBT(BinTree* bt) {
    cout << "\nThe elements of binary tree are: ";
    for (int i = 0; i < bt->size; i++) {
        cout << bt->arr[i] << " ";
    }
    cout << endl;
}

int main() {
    BinTree byT;

    int i = 0;
    while (i != 4) {
        cout << "\nWhat operation do you want to perform?\n1. Create a binary tree\n2. Insert left child\n3. Insert right child\n4. Exit\nChoice: ";
        cin >> i;

        switch(i) {
            case 1:
                int level;
                cout << "\nEnter the max level of binary tree: ";
                cin >> level;

                createBT(&byT, level);

                int root;
                cout << "\nEnter root element: ";
                cin >> root;
                byT.arr[0] = root;

                printBT(&byT);

                break;
            
            case 2:
                int ele, pIndex;
                cout << "\nEnter the element and parent's index: ";
                cin >> ele >> pIndex;

                leftChild(&byT, ele, pIndex);
                printBT(&byT);

                break;
            
            case 3:
                cout << "\nEnter the element and parent's index: ";
                cin >> ele >> pIndex;

                rightChild(&byT, ele, pIndex);
                printBT(&byT);

                break;

            case 4:
                cout << "Exited successfully";
        }
    }
    
    return 0;
}