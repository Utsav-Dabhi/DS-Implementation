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
        bt->arr[i] = -999;
    }
}

void insertLeftChild(BinTree* bt, int ele, int pIndex) {
    if (bt->arr[pIndex] == -999) {
        cout << "\nParent not found, cannot set it's child!" << endl;
    } else {
        bt->arr[(pIndex * 2) + 1] = ele;
        bt->used++;
    }
}

void insertRightChild(BinTree* bt, int ele, int pIndex) {
    if (bt->arr[pIndex] == -999) {
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
    } else if (bt->arr[pIndex] == -999) {
        cout << "\nParent not found, cannot delete it's child!" << endl;
    } else {
        bt->arr[(pIndex * 2) + 1] = -999;
        bt->used--;
    }
}

void deleteRightChild(BinTree* bt, int pIndex) {
    int noOfLastLevelEle = pow(2, bt->level - 1);
    if (pIndex < 0 || pIndex >= (bt->size - noOfLastLevelEle)) {
        cout << "\nInvalid index!";
    } else if (bt->arr[pIndex] == -999) {
        cout << "\nParent not found, cannot delete it's child!" << endl;
    } else {
        bt->arr[(pIndex * 2) + 2] = -999;
        bt->used--;
    }
}

// functions related to traversals
int getLeftChild(BinTree* bt, int pIndex) {
    if (bt->arr[pIndex] != -999 && ((2 * pIndex) + 1) < bt->size) {
        return (2 * pIndex) + 1;
    }

    return -1;
}

int getRightChild(BinTree* bt, int pIndex) {
    if (bt->arr[pIndex] != -999 && ((2 * pIndex) + 2) < bt->size) {
        return (2 * pIndex) + 2;
    }

    return -1;
}

void preorder(BinTree* bt, int index) {
    if (index >= 0 && bt->arr[index] != -999) {
        cout << bt->arr[index] << " ";
        preorder(bt, getLeftChild(bt, index));
        preorder(bt, getRightChild(bt, index));
    }
}

void postorder(BinTree* bt, int index) {
    if (index >= 0 && bt->arr[index] != -999) {
        postorder(bt, getLeftChild(bt, index));
        postorder(bt, getRightChild(bt, index));
        cout << bt->arr[index] << " ";
    }
}

void inorder(BinTree* bt, int index) {
    if (index >= 0 && bt->arr[index] != -999) {
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

int isLeaf(BinTree* bt, int index) {
    if (getLeftChild(bt, index) == -1 && getRightChild(bt, index) == -1) {
        return 1;
    }

    if (bt->arr[getLeftChild(bt, index)] == -999 && bt->arr[getRightChild(bt, index)] == -999) {
        return 1;
    }

    return 0;
}

int getHeight(BinTree* bt, int index) {
    if (isLeaf(bt, index) || index < 0 || bt->arr[index] == -999) {
        return 0;
    } else {
        return max(getHeight(bt, getLeftChild(bt, index)), getHeight(bt, getRightChild(bt, index))) + 1;
    }
}

// functions related to printing
void printSpace(int count) {
    for (int x = 0; x < count; x++) {
        cout << " ";
    }
}

void printBT(int arr[], int size){
    int height = ceil(log(size) + 1);   //+1 handle the last leaves
    int width = pow(2, height) * height;
    int index = 0;

    cout << "\nBinary Tree: \n";
    for (int x = 0; x <= height; x++) { //for each level of the tree
        for (int z = 0; z < pow(2, x); z++) {   // for each node on that tree level
            int digitWidth = 1;
            if (arr[index] != 0) {
                digitWidth = floor(log10(abs(arr[index]))) + 1;
            }
            printSpace(width/(pow(2, x)) - digitWidth);
            if (index<size) {
                cout<<arr[index++];
            } else {
                cout<<" ";
            }
            printSpace(width/(pow(2, x)));
        }
        cout << endl;
    }
}
// printing functions end

int main() {
    BinTree byT;

    int i = 0;
    while (i != 12) {
        cout << "\nWhat operation do you want to perform?\n1. Create a binary tree\n2. Insert left child\n3. Insert right child\n4. Delete left child\n5. Delete right child\n6. Preorder traversal\n7. Postorder traversal\n8. Inorder traversal\n9. BFS/Level Order Traversal\n10. Height of a node\n11. Print Binary Tree\n12. Exit\nChoice: ";
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

                printBT(byT.arr, byT.size);

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
                printBT(byT.arr, byT.size);

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
                printBT(byT.arr, byT.size);

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
                printBT(byT.arr, byT.size);
                
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
                printBT(byT.arr, byT.size);

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

            case 10: {
                int nodeIndex;
                cout << "\nEnter node's index: ";
                cin >> nodeIndex;
                int nodeHeight = getHeight(&byT, nodeIndex);
                cout << "\nHeight of node "<< byT.arr[nodeIndex] << " is: " << nodeHeight << endl;
                break;
            }

            case 11:
                printBT(byT.arr, byT.size);
                break;

            case 12:
                cout << "\nExited successfully";
                break;

            default:
                cout << "\nInvalid choice";
                break;
        }
    }
    
    return 0;
}