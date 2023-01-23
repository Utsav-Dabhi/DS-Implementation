#include<iostream>
#include<string>
using namespace std;

struct BSTNode {
    int key;
    BSTNode* left;
    BSTNode* right;
};

BSTNode* createNode(int data) {
    BSTNode* new_node = new BSTNode;
    (*new_node).key = data;
    (*new_node).left = (*new_node).right = NULL;

    return new_node;
}

BSTNode* insertNode(BSTNode* root, int data) {
    if (root == NULL) {
        root = createNode(data);
    } else if (data < root->key) {
        root->left = insertNode(root->left, data);
    } else if (data > root->key) {
        root->right = insertNode(root->right, data);
    }

    return root;
}

void searchKey(BSTNode* root, int key) {
    if (root == NULL) {
        cout << "\nKey not found" << endl;
        return;
    }

    if (root->key == key) {
        cout << "\nKey is present" << endl;
    } else if (key < root->key) {
        searchKey(root->left, key);
    } else {
        searchKey(root->right, key);
    }
}

// functions related to deletions
bool isLeaf(BSTNode* node) {
    if (node->left == NULL && node->right == NULL) {
        return true;
    }

    return false;
}

BSTNode* minValueNode(BSTNode* node) {
    BSTNode* current = node;

    while (current && current->left != NULL) {
        current = current->left;
    }

    return current;
}

BSTNode* deleteKey(BSTNode* root, int key) {
    if (root == NULL) {
        return root;
    }

    if (key < root->key) {
        root->left = deleteKey(root->left, key);
    } else if (key > root->key) {
        root->right = deleteKey(root->right, key);
    } else {
        // if node is a leaf node
        if (isLeaf(root)) {
            return NULL;
        }

        // if node has one child
        else if (root->left == NULL) {
            BSTNode* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            BSTNode* temp = root->left;
            free(root);
            return temp;
        } 
        // if node has two children
        else {
            BSTNode* temp = minValueNode(root->right);

            root->key = temp->key;

            root->right = deleteKey(root->right, temp->key);
        }
    }

    return root;
}

void inorder(BSTNode* root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}

void printBT(const string& prefix, const BSTNode* node, bool isLeft, bool isRoot) {
    if (node != nullptr) {
        if (isRoot) {
            cout << "----";
        } else {
            cout << prefix << (isLeft ? "R|--" : "L+--");
        }

        // print the value of the node
        std::cout << node->key << std::endl;
        // enter the next tree level - left and right branch
        printBT(prefix + (isLeft ? "|   " : "    "), node->right, true, false);
        printBT(prefix + (isLeft ? "|   " : "    "), node->left, false, false);
    }
}

void printBT(const BSTNode* node) {
    printBT("", node, false, true);
}

int main() {
    struct BSTNode* root = NULL;

    int i = 0;
    while (i != 5) {
        cout << "\nWhat operation do you want to perform?\n1. Create a binary search tree\n2. Insert a element\n3. Search an element\n4. Delete an element\n5. Exit\nChoice: ";
        cin >> i;

        switch(i) {
            case 1:
                int ele;
                cout << "\nEnter root element: ";
                cin >> ele;

                root = insertNode(root, ele);
                printBT(root);

                break;

            case 2:
                cout << "\nEnter element to be inserted: ";
                cin >> ele;

                root = insertNode(root, ele);
                printBT(root);

                break;

            case 3:
                cout << "\nEnter the element to be searched: ";
                cin >> ele;

                searchKey(root, ele);

                break;

            case 4:
                cout << "\nEnter the element to be deleted: ";
                cin >> ele;

                root = deleteKey(root, ele);
                printBT(root);

                break;
        }
    }
    
    return 0;
}