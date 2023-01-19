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

    for (int i = 0; i < bt->size; i++) {
        bt->arr[i] = -2147483648;
    }
}

void insertLeftChild(BinTree* bt, int ele, int pIndex) {
    if (bt->arr[pIndex] == -2147483648) {
        cout << "\nParent not found, cannot set it's child!" << endl;
    } else {
        bt->arr[(pIndex * 2) + 1] = ele;
    }
}

void insertRightChild(BinTree* bt, int ele, int pIndex) {
    if (bt->arr[pIndex] == -2147483648) {
        cout << "\nParent not found, cannot set it's child!" << endl;
    } else {
        bt->arr[(pIndex * 2) + 2] = ele;
    }
}

void deleteLeftChild(BinTree* bt, int pIndex) {
    if (bt->arr[pIndex] == -2147483648) {
        cout << "\nParent not found, cannot delete it's child!" << endl;
    } else {
        bt->arr[(pIndex * 2) + 1] = -2147483648;
    }
}

void deleteRightChild(BinTree* bt, int pIndex) {
    if (bt->arr[pIndex] == -2147483648) {
        cout << "\nParent not found, cannot delete it's child!" << endl;
    } else {
        bt->arr[(pIndex * 2) + 2] = -2147483648;
    }
}

void printBT(BinTree* bt) {
    cout << "\nThe elements of binary tree are: ";
    for (int i = 0; i < bt->size; i++) {
        cout << bt->arr[i];
        if (i == 0) {
            cout << "(-1) ";
        } else {
            cout << "(" << (i - 1) / 2 << ") ";
        }
    }
    cout << endl;
}

int main() {
    BinTree byT;

    int i = 0;
    while (i != 6) {
        cout << "\nWhat operation do you want to perform?\n1. Create a binary tree\n2. Insert left child\n3. Insert right child\n4. Delete left child\n5. Delete right child\n6. Exit\nChoice: ";
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
                cout << "\nParent's index: \n";
                cout << "    A(0)\n";
                cout << "   / \\\n";
                cout << "  /   \\\n";
                cout << "B(1)   C(2)";

                int ele, pIndex;
                cout << "\nEnter the element and parent's index: ";
                cin >> ele >> pIndex;

                insertLeftChild(&byT, ele, pIndex);
                printBT(&byT);

                break;
            
            case 3:
                cout << "\nParent's index: \n";
                cout << "    A(0)\n";
                cout << "   / \\\n";
                cout << "  /   \\\n";
                cout << "B(1)   C(2)";

                cout << "\nEnter the element and parent's index: ";
                cin >> ele >> pIndex;

                insertRightChild(&byT, ele, pIndex);
                printBT(&byT);

                break;

            case 4:
                cout << "\nParent's index: \n";
                cout << "    A(0)\n";
                cout << "   / \\\n";
                cout << "  /   \\\n";
                cout << "B(1)   C(2)";

                cout << "\nEnter parent's index: ";
                cin >> pIndex;

                deleteLeftChild(&byT, pIndex);
                printBT(&byT);

                break;
            
            case 5:
                cout << "\nParent's index: \n";
                cout << "    A(0)\n";
                cout << "   / \\\n";
                cout << "  /   \\\n";
                cout << "B(1)   C(2)";

                cout << "\nEnter parent's index: ";
                cin >> pIndex;

                deleteRightChild(&byT, pIndex);
                printBT(&byT);

                break;

            case 6:
                cout << "\nExited successfully";
        }
    }
    
    return 0;
}