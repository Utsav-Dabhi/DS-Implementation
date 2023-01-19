#include<iostream>
#include<cstring>
#include<math.h>
#include<queue>
using namespace std;

struct BinTree {
    int level;
    int size;
    int* arr;
    int used;
};

void createBT(BinTree* bt, int level) {
    bt->level = level;
    bt->size = pow(2, level) - 1;
    bt->used = 0;
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
        bt->used++;
    }
}

void insertRightChild(BinTree* bt, int ele, int pIndex) {
    if (bt->arr[pIndex] == -2147483648) {
        cout << "\nParent not found, cannot set it's child!" << endl;
    } else {
        bt->arr[(pIndex * 2) + 2] = ele;
        bt->used++;
    }
}

void deleteLeftChild(BinTree* bt, int pIndex) {
    int noOfLastLevelEle = pow(2, bt->level - 1);
    if (pIndex < 0 || pIndex >= (bt->size - noOfLastLevelEle)) {
        cout << "\nInvalid index!";
    } else if (bt->arr[pIndex] == -2147483648) {
        cout << "\nParent not found, cannot delete it's child!" << endl;
    } else {
        bt->arr[(pIndex * 2) + 1] = -2147483648;
        bt->used--;
    }
}

void deleteRightChild(BinTree* bt, int pIndex) {
    int noOfLastLevelEle = pow(2, bt->level - 1);
    if (pIndex < 0 || pIndex >= (bt->size - noOfLastLevelEle)) {
        cout << "\nInvalid index!";
    } else if (bt->arr[pIndex] == -2147483648) {
        cout << "\nParent not found, cannot delete it's child!" << endl;
    } else {
        bt->arr[(pIndex * 2) + 2] = -2147483648;
        bt->used--;
    }
}

// functions related to traversals
int getLeftChild(BinTree* bt, int pIndex) {
    if (bt->arr[pIndex] != -2147483648 && ((2 * pIndex) + 1) < bt->used) {
        return (2 * pIndex) + 1;
    }

    return -1;
}

int getRightChild(BinTree* bt, int pIndex) {
    if (bt->arr[pIndex] != -2147483648 && ((2 * pIndex) + 2) < bt->used) {
        return (2 * pIndex) + 2;
    }

    return -1;
}

void preorder(BinTree* bt, int index) {
    if (index >= 0 && bt->arr[index] != -2147483648) {
        cout << bt->arr[index] << " ";
        preorder(bt, getLeftChild(bt, index));
        preorder(bt, getRightChild(bt, index));
    }
}

void postorder(BinTree* bt, int index) {
    if (index >= 0 && bt->arr[index] != -2147483648) {
        postorder(bt, getLeftChild(bt, index));
        postorder(bt, getRightChild(bt, index));
        cout << bt->arr[index] << " ";
    }
}

void inorder(BinTree* bt, int index) {
    if (index >= 0 && bt->arr[index] != -2147483648) {
        postorder(bt, getLeftChild(bt, index));
        cout << bt->arr[index] << " ";
        postorder(bt, getRightChild(bt, index));
    }
}

void BFS(BinTree* bt) {
    queue<pair<int, int>> que;

    que.push(pair(bt->arr[0], 0));

    while (que.empty() == false) {
        cout << que.front().first << " ";

        int leftIndex = getLeftChild(bt, que.front().second);
        if (leftIndex != -1) {
            que.push(pair(bt->arr[leftIndex], leftIndex));
        }

        int rightIndex = getRightChild(bt, que.front().second);
        if (rightIndex != -1) {
            que.push(pair(bt->arr[rightIndex], rightIndex));
        }

        que.pop();
    }
}
// traversal functions end

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
    while (i != 10) {
        cout << "\nWhat operation do you want to perform?\n1. Create a binary tree\n2. Insert left child\n3. Insert right child\n4. Delete left child\n5. Delete right child\n6. Preorder traversal\n7. Postorder traversal\n8. Inorder traversal\n9. BFS/Level Order Traversal\n10. Exit\nChoice: ";
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
                byT.used++;

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
                cout << "\nPreorder traversal: ";
                preorder(&byT, 0);
                cout << endl;
                break;

            case 7:
                cout << "\nPostorder traversal: ";
                postorder(&byT, 0);
                cout << endl;
                break;
            
            case 8:
                cout << "\nInorder traversal: ";
                inorder(&byT, 0);
                cout << endl;
                break;

            case 9:
                cout << "\nLevel Order traversal: ";
                BFS(&byT);
                cout << endl;
                break;

            case 10:
                cout << "\nExited successfully";
        }
    }
    
    return 0;
}